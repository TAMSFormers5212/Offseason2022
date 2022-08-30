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
    namespace Module1 {
        constexpr int drivingMotorID = 1;
        constexpr int turningMotorID = 2;
    }  // namespace Module1
    namespace Module2 {
        constexpr int drivingMotorID = 3;
        constexpr int turningMotorID = 4;
    }  // namespace Module2
    namespace Module3 {
        constexpr int drivingMotorID = 5;
        constexpr int turningMotorID = 6;
    }  // namespace Module3
    namespace Module4 {
        constexpr int drivingMotorID = 7;
        constexpr int turningMotorID = 8;
    }  // namespace Module4

    constexpr units::meters_per_second_t maxSpeed{1_mps};
}  // namespace SwerveConstants
