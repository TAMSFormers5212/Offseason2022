// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetArmPos.h"

#include "Constants.h"

using namespace ArmConstants;

SetArmPos::SetArmPos(ArmSubsystem* arm, double pose)
    : m_arm(arm), m_pose(pose) {
  AddRequirements(arm);
}

void SetArmPos::Initialize() {
  m_arm->SetPose(m_pose);
}

void SetArmPos::End(bool interrupted) {}