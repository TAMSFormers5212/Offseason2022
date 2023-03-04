// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ArmSubsystem.h"

class SetArmPos
    : public frc2::CommandHelper<frc2::CommandBase, SetArmPos> {
 public:
  explicit SetArmPos(ArmSubsystem* arm, double pose);

  void Initialize() override;

  void End(bool interrupted) override;

 private:
  ArmSubsystem* m_arm;
  double m_pose;
};