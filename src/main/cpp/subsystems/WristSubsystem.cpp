// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>
#include <math.h>

#include "subsystems/WristSubsystem.h"
#include "Constants.h"

using namespace WristConstants;

WristSubsystem::WristSubsystem()
    : m_wristMotor{wristMotorID, rev::CANSparkMax::MotorType::kBrushless} {}


void WristSubsystem::Periodic() {
    frc::SmartDashboard::PutNumber("Wrist Rotations", m_wristEncoder.GetPosition());
}

void WristSubsystem::Reset() {
    m_wristMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    m_wristController.SetP(kP);
    m_wristController.SetI(kI);
    m_wristController.SetD(kD);
    m_wristController.SetSmartMotionMaxVelocity(maxSpeed);
    m_wristController.SetSmartMotionMinOutputVelocity(minSpeed);
}

void WristSubsystem::SetPose(double rotations) {
    m_wristController.SetReference(rotations, rev::ControlType::kPosition);
}
void WristSubsystem::SetSpeed(double speed) {
    m_wristMotor.Set(speed);
}