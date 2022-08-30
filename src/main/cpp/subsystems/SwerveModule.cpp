// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule(int drivePort, int turningPort, int encoderPort)
    : m_driveMotor{drivePort, rev::CANSparkMax::MotorType::kBrushless},
      m_turningMotor{turningPort, rev::CANSparkMax::MotorType::kBrushless},
      m_absoluteEncoder{encoderPort} {
  m_driveMotor.RestoreFactoryDefaults();
  m_turningMotor.RestoreFactoryDefaults();
  resetTurningEncoder();
  m_turningController.SetP(0.01);
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
	state = frc::SwerveModuleState::Optimize(state, units::radian_t(getTurningPosition()));

	m_turningController.SetReference(double{state.angle.Degrees() / 360}, rev::CANSparkMax::ControlType::kPosition);
}

void SwerveModule::drive(double speed) {
	m_driveMotor.Set(speed);
}

frc::SwerveModuleState SwerveModule::getState() {
	return frc::SwerveModuleState{units::velocity::meters_per_second_t(getDriveVelocity()), units::radian_t(getTurningPosition())};
}

void SwerveModule::stop() {
  m_driveMotor.Set(0);
  m_turningMotor.Set(0);
}
