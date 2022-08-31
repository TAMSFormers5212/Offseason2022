// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/velocity.h>

namespace OIConstants {
constexpr int driverController = 0;
constexpr int shooterController = 1;

constexpr int LX = 0;
constexpr int LY = 1;
constexpr int RX = 4;
constexpr int RY = 5;

constexpr int A = 1;
constexpr int B = 2;
constexpr int X = 3;
constexpr int Y = 4;

constexpr int LB = 5;
constexpr int RB = 6;
constexpr int LT = 2;
constexpr int RT = 3;
}  // namespace OIConstants

namespace SwerveConstants {
namespace frontLeftModule {
constexpr int drivingMotorID = 1;
constexpr int turningMotorID = 2;
constexpr int encoderID = 1;
}  // namespace frontLeftModule
namespace backLeftModule {
constexpr int drivingMotorID = 3;
constexpr int turningMotorID = 4;
constexpr int encoderID = 2;
}  // namespace backLeftModule
namespace backRightModule {
constexpr int drivingMotorID = 5;
constexpr int turningMotorID = 6;
constexpr int encoderID = 3;
}  // namespace backRightModule
namespace frontRightModule {
constexpr int drivingMotorID = 7;
constexpr int turningMotorID = 8;
constexpr int encoderID = 4;
}  // namespace frontRightModule

constexpr units::meters_per_second_t maxSpeed{3_mps};
constexpr double turningRatio = 1.0;
constexpr units::inch_t centerDistance = 13.5_in;

constexpr double kP = 0.01;
}  // namespace SwerveConstants
