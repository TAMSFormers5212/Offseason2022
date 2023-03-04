// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

using namespace WristConstants;

class WristSubsystem : public frc2::SubsystemBase {
 public:
  WristSubsystem();

  void Periodic() override;

  void SetPose(double rotations);
  void Reset();

  bool GetPoseEnabled();
  void SetPoseEnabled(bool enabled);

  void SetSpeed(double speed);
 private:
  rev::CANSparkMax m_wristMotor;
  rev::SparkMaxRelativeEncoder m_wristEncoder = m_wristMotor.GetEncoder();
  rev::SparkMaxPIDController m_wristController = m_wristMotor.GetPIDController();
};
