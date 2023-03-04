// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"
#include "AHRS.h"

#include "subsystems/SwerveModule.h"
#include "Constants.h"

using namespace SwerveConstants;

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  void Periodic() override;

  void ResetEncoders();
  void ResetHeading();
  void Drive(units::meters_per_second_t xSpeed, units::meters_per_second_t ySpeed, units::radians_per_second_t rot, bool fieldCentric);
  void TankDrive(double lStick, double rStick);

 private:
  frc::Translation2d m_frontLeftLocation{centerDistance, centerDistance};
  frc::Translation2d m_frontRightLocation{centerDistance, -centerDistance};
  frc::Translation2d m_backLeftLocation{-centerDistance, centerDistance};
  frc::Translation2d m_backRightLocation{-centerDistance, -centerDistance};

  frc::SwerveDriveKinematics<4> m_kinematics{
    m_frontLeftLocation, 
    m_frontRightLocation, 
    m_backLeftLocation,
    m_backRightLocation};

  SwerveModule m_frontLeftModule{frontLeftModule::drivingMotorID, frontLeftModule::turningMotorID, frontLeftModule::encoderID, frontLeftModule::offset};
  SwerveModule m_frontRightModule{frontRightModule::drivingMotorID, frontRightModule::turningMotorID, frontRightModule::encoderID, frontRightModule::offset};
  SwerveModule m_backLeftModule{backLeftModule::drivingMotorID, backLeftModule::turningMotorID, backLeftModule::encoderID, backLeftModule::offset};
  SwerveModule m_backRightModule{backRightModule::drivingMotorID, backRightModule::turningMotorID, backRightModule::encoderID, backRightModule::offset};

  AHRS *m_ahrs = new AHRS(frc::SPI::Port::kMXP);
};
