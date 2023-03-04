// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <iostream>

#include "subsystems/DriveSubsystem.h"

#include "Constants.h"
using namespace SwerveConstants;

DriveSubsystem::DriveSubsystem() {
  ResetHeading();
}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ResetEncoders() {
  m_frontLeftModule.ResetTurningEncoder();
  m_frontRightModule.ResetTurningEncoder();
  m_backLeftModule.ResetTurningEncoder();
  m_backRightModule.ResetTurningEncoder();
}

void DriveSubsystem::ResetHeading() {
  m_ahrs->Reset();
}

void DriveSubsystem::Drive(units::meters_per_second_t xSpeed, units::meters_per_second_t ySpeed, units::radians_per_second_t rot, bool fieldCentric) {
  frc::ChassisSpeeds speeds;
  if (fieldCentric) {
    speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(xSpeed, ySpeed, rot, (units::degree_t) m_ahrs->GetFusedHeading());
  } else {
    speeds = frc::ChassisSpeeds{xSpeed, ySpeed, rot};
  }

  auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

  m_frontLeftModule.SetState(fl, true);
  m_frontRightModule.SetState(fr, false);
  m_backLeftModule.SetState(bl, false);
  m_backRightModule.SetState(br, false);
}

void DriveSubsystem::TankDrive(double lStick, double rStick) {
  m_frontLeftModule.Drive(lStick * 0.2);
  m_backLeftModule.Drive(lStick * 0.2);
  m_backRightModule.Drive(rStick * 0.2);
  m_frontRightModule.Drive(rStick * 0.2);
}
