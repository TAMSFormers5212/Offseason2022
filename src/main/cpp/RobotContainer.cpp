// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "commands/Auto.h"

RobotContainer::RobotContainer() {
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return new Auto();
}
