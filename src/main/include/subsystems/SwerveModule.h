// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/AnalogInput.h>
#include <frc/kinematics/SwerveModuleState.h>

#include "rev/CANSparkMax.h"

class SwerveModule {
 public:
  SwerveModule(int drivePort, int turningPort, int encoderPort, double offset);

  void ResetDriveMotor();
  void ResetTurningMotor();
  double GetDrivePosition();
  double GetTurningPosition();
  double GetDriveVelocity();
  double GetTurningVelocity();
  void ResetDriveEncoder();
  void ResetTurningEncoder();

  void SetState(frc::SwerveModuleState state, bool print);
  frc::SwerveModuleState GetState();

  void Drive(double speed);
  void Stop();

 private:
  double m_offset;
  frc::SwerveModuleState m_lastState;

  rev::CANSparkMax m_driveMotor;
  rev::CANSparkMax m_turningMotor;

  rev::SparkMaxRelativeEncoder m_driveEncoder = m_driveMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder m_turningEncoder = m_turningMotor.GetEncoder();

  rev::SparkMaxPIDController m_turningController = m_turningMotor.GetPIDController();

  frc::AnalogInput m_absoluteEncoder;
};
