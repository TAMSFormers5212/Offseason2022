// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/geometry/Rotation2d.h>

#include "subsystems/DriveSubsystem.h"

#include "Constants.h"

DriveSubsystem::DriveSubsystem() {}

void DriveSubsystem::Periodic() {}

void drive(units::meters_per_second_t xSpeed, units::meters_per_second_t ySpeed, units::radians_per_second_t rotSpeed, bool fieldCentric) {
  frc::ChassisSpeeds speeds;
  if (fieldCentric) {
    speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(xSpeed, ySpeed, rotSpeed, 45_deg);
  } else {
    speeds = frc::ChassisSpeeds{xSpeed, ySpeed, rotSpeed};
  }

  
}

void DriveSubsystem::TankDrive(double lStick, double rStick) {
  m_frontLeftModule.drive(lStick * 0.2);
  m_backLeftModule.drive(lStick * 0.2);
  m_backRightModule.drive(rStick * 0.2);
  m_frontRightModule.drive(rStick * 0.2);
}
