// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/GenericHID.h>
#include <frc2/command/Command.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/WristSubsystem.h"
#include "subsystems/ArmSubsystem.h"
#include "subsystems/SwerveModule.h"
#include "ctre/Phoenix.h"

using namespace SwerveConstants;

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  frc::GenericHID m_driveController{0};
  frc::GenericHID m_armController{1};

  DriveSubsystem m_drive;
  WristSubsystem m_wrist;
  ArmSubsystem m_arm;

  void ConfigureButtonBindings();
};
