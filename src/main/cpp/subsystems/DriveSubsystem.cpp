// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

#include "Constants.h"

DriveSubsystem::DriveSubsystem() {}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::TankDrive(double lStick, double rStick) {
  m_module1.drive(lStick * m_maxOutput);
  m_module2.drive(lStick * m_maxOutput);
  m_module3.drive(rStick * m_maxOutput);
  m_module4.drive(rStick * m_maxOutput);
}
