// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule(int drivePort, int turningPort, int encoderPort)
    : driveMotor{drivePort, rev::CANSparkMax::MotorType::kBrushless},
      turningMotor{turningPort, rev::CANSparkMax::MotorType::kBrushless},
      absoluteEncoder{encoderPort} {
  driveMotor.RestoreFactoryDefaults();
  turningMotor.RestoreFactoryDefaults();
}

double SwerveModule::getDrivePosition() {
	return driveEncoder.GetPosition();
}

double SwerveModule::getTurningPosition() {
	return turningEncoder.GetPosition();
}

double SwerveModule::getDriveVelocity() {
	return driveEncoder.GetVelocity();
}

double SwerveModule::getTurningVelocity() {
	return turningEncoder.GetVelocity();
}

void SwerveModule::resetDriveEncoder() {
	driveEncoder.SetPosition(0);
}

void SwerveModule::resetTurningEncoder() {
	turningEncoder.SetPosition(0);
}

void SwerveModule::setState(frc::SwerveModuleState state) {
	state = frc::SwerveModuleState::Optimize(state, units::radian_t(getTurningPosition()));
}

frc::SwerveModuleState SwerveModule::getState() {
	return frc::SwerveModuleState{units::velocity::meters_per_second_t(getDriveVelocity()), units::radian_t(getTurningPosition())};
}

void SwerveModule::stop() {
  driveMotor.Set(0);
  turningMotor.Set(0);
}
