// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/AnalogInput.h>
#include <frc/kinematics/SwerveModuleState.h>

#include "rev/CANSparkMax.h"

class SwerveModule {
 public:
  SwerveModule(int drivePort, int turningPort, int encoderPort);

  double getDrivePosition();
  double getTurningPosition();
  double getDriveVelocity();
  double getTurningVelocity();
  void resetDriveEncoder();
  void resetTurningEncoder();

  void setState(frc::SwerveModuleState state);
  frc::SwerveModuleState getState();

	void stop();

 private:
  rev::CANSparkMax driveMotor;
  rev::CANSparkMax turningMotor;

  rev::SparkMaxRelativeEncoder driveEncoder = driveMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder turningEncoder = driveMotor.GetEncoder();

  rev::SparkMaxPIDController turningController = driveMotor.GetPIDController();

  frc::AnalogInput absoluteEncoder;
};
