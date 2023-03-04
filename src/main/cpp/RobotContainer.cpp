// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/RunCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/Auto.h"
#include "commands/SetArmPos.h"
#include "Constants.h"

RobotContainer::RobotContainer() {
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drive.Drive(units::meters_per_second_t{m_driveController.GetRawAxis(OIConstants::LY)},
                      units::meters_per_second_t{m_driveController.GetRawAxis(OIConstants::LX)},
                      units::radians_per_second_t{m_driveController.GetRawAxis(OIConstants::RX)}, true);
      },
      {&m_drive}));
  
  /*m_wrist.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_wrist.SetSpeed(m_armController.GetRawAxis(OIConstants::LY));
      }, 
      {&m_wrist}));*/
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::JoystickButton(&m_driveController, OIConstants::A).WhenReleased(
    frc2::InstantCommand(
      [this] {
        m_drive.ResetEncoders();
      }
    )
  );

  frc2::JoystickButton(&m_armController, OIConstants::A).WhileHeld(
    frc2::StartEndCommand(
      [this] {
        m_arm.SetSpeed(-0.2);
      },
      [this] {
        m_arm.SetSpeed(0);
      }
    )
  );

  frc2::JoystickButton(&m_armController, OIConstants::B).WhileHeld(
    frc2::StartEndCommand(
      [this] {
        m_arm.SetSpeed(0.2);
      },
      [this] {
        m_arm.SetSpeed(0);
      }
    )
  );
  
  frc2::JoystickButton(&m_armController, OIConstants::X).WhileHeld(
    frc2::StartEndCommand(
      [this] {
        m_wrist.SetSpeed(-0.6);
      },
      [this] {
        m_wrist.SetSpeed(0);
      }
    )
  );

  frc2::JoystickButton(&m_armController, OIConstants::Y).WhileHeld(
    frc2::StartEndCommand(
      [this] {
        m_wrist.SetSpeed(0.6);
      },
      [this] {
        m_wrist.SetSpeed(0);
      }
    )
  );
  //frc2::JoystickButton(&m_armController, OIConstants::Y).WhenReleased(SetArmPos(&m_arm, 50));
  //frc2::JoystickButton(&m_armController, OIConstants::X).WhenReleased(SetArmPos(&m_arm, 0));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return new Auto();
}
