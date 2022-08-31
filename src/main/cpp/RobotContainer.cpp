// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/RunCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"
#include "commands/Auto.h"

RobotContainer::RobotContainer() {
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drive.TankDrive(m_controller.GetRawAxis(OIConstants::LY),
                          -m_controller.GetRawAxis(OIConstants::RY));
      },
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return new Auto();
}
