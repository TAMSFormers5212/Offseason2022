// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"

#include "Constants.h"

using namespace SwerveConstants;

SwerveModule::SwerveModule(int drivePort, int turningPort, int encoderPort)
    : m_driveMotor{drivePort, rev::CANSparkMax::MotorType::kBrushless},
      m_turningMotor{turningPort, rev::CANSparkMax::MotorType::kBrushless},
      m_absoluteEncoder{encoderPort} {
  resetDriveMotor();
  resetTurningMotor();
}

void SwerveModule::resetDriveMotor() {
  m_driveMotor.RestoreFactoryDefaults();
  resetTurningEncoder();
}

void SwerveModule::resetTurningMotor() {
  m_turningMotor.RestoreFactoryDefaults();
  m_turningController.SetP(kP);
  resetTurningEncoder();
}

double SwerveModule::getDrivePosition() {
  return m_driveEncoder.GetPosition();
}

double SwerveModule::getTurningPosition() {
  return m_turningEncoder.GetPosition();
}

double SwerveModule::getDriveVelocity() {
  return m_driveEncoder.GetVelocity();
}

double SwerveModule::getTurningVelocity() {
  return m_turningEncoder.GetVelocity();
}

void SwerveModule::resetDriveEncoder() {
  m_driveEncoder.SetPosition(0);
}

void SwerveModule::resetTurningEncoder() {
  m_turningEncoder.SetPosition(0);
}

void SwerveModule::setState(frc::SwerveModuleState state) {
  state = frc::SwerveModuleState::Optimize(
      state, units::radian_t(getTurningPosition()));

  double output = units::unit_cast<double>(maxSpeed / state.speed);
  m_driveMotor.Set(output);

  double rotations = (units::unit_cast<double>(state.angle.Degrees()) / 360.0) * turningRatio;
  m_turningController.SetReference(rotations, rev::CANSparkMax::ControlType::kPosition);
}

void SwerveModule::drive(double speed) {
  m_driveMotor.Set(speed);
}

frc::SwerveModuleState SwerveModule::getState() {
  return frc::SwerveModuleState{
      units::velocity::meters_per_second_t(getDriveVelocity()),
      units::radian_t(getTurningPosition())};
}

void SwerveModule::stop() {
  m_driveMotor.Set(0);
  m_turningMotor.Set(0);
}
