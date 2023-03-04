// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"
#include <frc/RobotController.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/geometry/Rotation2d.h>
#include <iostream>
#include <math.h>

#include "Constants.h"

using namespace SwerveConstants;

SwerveModule::SwerveModule(int drivePort, int turningPort, int encoderPort, double offset)
    : m_driveMotor{drivePort, rev::CANSparkMax::MotorType::kBrushless},
      m_turningMotor{turningPort, rev::CANSparkMax::MotorType::kBrushless},
      m_absoluteEncoder{encoderPort},
      m_offset{offset} {
  ResetDriveMotor();
  ResetTurningMotor();
}

void SwerveModule::ResetDriveMotor() {
  m_driveMotor.RestoreFactoryDefaults();
  ResetDriveEncoder();
}

void SwerveModule::ResetTurningMotor() {
  m_turningMotor.RestoreFactoryDefaults();
  m_turningController.SetFF(kFF);
  m_turningController.SetP(kP);
  m_turningController.SetI(kI);
  m_turningController.SetD(kD);
  ResetTurningEncoder();
}

double SwerveModule::GetDrivePosition() {
  return m_driveEncoder.GetPosition();
}

double SwerveModule::GetTurningPosition() {
  return m_turningEncoder.GetPosition();
}

double SwerveModule::GetDriveVelocity() {
  return m_driveEncoder.GetVelocity();
}

double SwerveModule::GetTurningVelocity() {
  return m_turningEncoder.GetVelocity();
}

void SwerveModule::ResetDriveEncoder() {
  m_driveEncoder.SetPosition(0);
}

void SwerveModule::ResetTurningEncoder() {
  double rotations = (m_absoluteEncoder.GetVoltage() / frc::RobotController::GetVoltage5V());
  m_turningEncoder.SetPosition(rotations * -12.8);
}


frc::SwerveModuleState optimize(frc::SwerveModuleState desiredState, frc::Rotation2d currentAngle, bool print) {
  units::degree_t scopeReference = currentAngle.Degrees();
  units::degree_t newAngle = desiredState.angle.Degrees();
  
  units::velocity::meters_per_second_t targetSpeed = desiredState.speed;
  units::degree_t delta = desiredState.angle.Degrees() - currentAngle.Degrees();

  if (units::math::abs(delta) > 90_deg){
      targetSpeed = -targetSpeed;
      newAngle = delta > 90_deg ? (newAngle -= 180_deg) : (newAngle += 180_deg);
  }

  if (print) {
    frc::SmartDashboard::PutNumber("Current Angle", (double) scopeReference);
    frc::SmartDashboard::PutNumber("Desired Angle", (double) newAngle);
  }

  return frc::SwerveModuleState{targetSpeed, frc::Rotation2d{newAngle}};
}

void SwerveModule::SetState(frc::SwerveModuleState state, bool print) {
  frc::SwerveModuleState newState = optimize(state, units::degree_t(((GetTurningPosition() - m_offset) * 360.0) / 12.8), print);
  
  double output = double{newState.speed / maxSpeed};
  //m_driveMotor.Set(output);

  auto angle = (units::math::abs(newState.speed) <= (maxSpeed * 0.01)) ? m_lastState.angle.Degrees() : newState.angle.Degrees();
  double rotations = double{newState.angle.Degrees() / 360.0} * 12.8;
  m_turningController.SetReference(m_offset + rotations, rev::CANSparkMax::ControlType::kPosition);

  if (print) {
    frc::SmartDashboard::PutNumber("Goal Speed", (double) newState.speed);
    frc::SmartDashboard::PutNumber("Goal Rotations", rotations + m_offset);
    frc::SmartDashboard::PutNumber("Actual Rotations", m_turningEncoder.GetPosition());
    frc::SmartDashboard::PutNumber("Offset", (m_turningEncoder.GetPosition() - rotations));
  }

  m_lastState = state;
}

void SwerveModule::Drive(double speed) {
  m_driveMotor.Set(speed);
}

frc::SwerveModuleState SwerveModule::GetState() {
  return frc::SwerveModuleState{
      units::velocity::meters_per_second_t(GetDriveVelocity()),
      units::radian_t(GetTurningPosition())};
}

void SwerveModule::Stop() {
  m_driveMotor.Set(0);
  m_turningMotor.Set(0);
}
