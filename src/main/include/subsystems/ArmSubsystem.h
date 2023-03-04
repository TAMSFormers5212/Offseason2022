// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

using namespace ArmConstants;

class ArmSubsystem : public frc2::SubsystemBase {
 public:
  ArmSubsystem();

  void Periodic() override;

  void SetPose(double rotations);
  void Reset();

  bool GetPoseEnabled();
  void SetPoseEnabled(bool enabled);

  void SetSpeed(double speed);
 private:
  double m_pose;
  bool m_poseEnabled = true;

  rev::CANSparkMax m_armMotor;
  rev::SparkMaxRelativeEncoder m_armEncoder = m_armMotor.GetEncoder();
  rev::SparkMaxPIDController m_armController = m_armMotor.GetPIDController();
};
