// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/GenericHID.h>
#include <frc2/command/Command.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/SwerveModule.h"

using namespace SwerveConstants;

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  frc::GenericHID m_controller{0};

  DriveSubsystem m_drive;

  void ConfigureButtonBindings();
};
