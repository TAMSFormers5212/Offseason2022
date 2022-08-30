// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "rev/CANSparkMax.h"
#include "subsystems/SwerveModule.h"

using namespace SwerveConstants;

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  void Periodic() override;

  void TankDrive(double lStick, double rStick);

 private:
  double m_maxOutput = 0.2;

  SwerveModule m_module1{Module1::drivingMotorID, Module1::turningMotorID, 0};
  SwerveModule m_module2{Module2::drivingMotorID, Module2::turningMotorID, 1};
  SwerveModule m_module3{Module3::drivingMotorID, Module3::turningMotorID, 2};
  SwerveModule m_module4{Module4::drivingMotorID, Module4::turningMotorID, 3};
};
