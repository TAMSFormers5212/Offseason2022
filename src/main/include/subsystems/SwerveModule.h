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

  void resetDriveMotor();
  void resetTurningMotor();
  double getDrivePosition();
  double getTurningPosition();
  double getDriveVelocity();
  double getTurningVelocity();
  void resetDriveEncoder();
  void resetTurningEncoder();

  void setState(frc::SwerveModuleState state);
  frc::SwerveModuleState getState();

  void drive(double speed);
  void stop();

 private:
  rev::CANSparkMax m_driveMotor;
  rev::CANSparkMax m_turningMotor;

  rev::SparkMaxRelativeEncoder m_driveEncoder = m_driveMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder m_turningEncoder = m_turningMotor.GetEncoder();

  rev::SparkMaxPIDController m_driveController =
      m_driveMotor.GetPIDController();
  rev::SparkMaxPIDController m_turningController =
      m_turningMotor.GetPIDController();

  frc::AnalogInput m_absoluteEncoder;
};
