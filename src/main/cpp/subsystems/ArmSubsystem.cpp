// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>
#include <math.h>

#include "subsystems/ArmSubsystem.h"
#include "Constants.h"

using namespace ArmConstants;

ArmSubsystem::ArmSubsystem()
    : m_armMotor{armMotorID, rev::CANSparkMax::MotorType::kBrushless} {
    m_armMotor.RestoreFactoryDefaults();
    m_armEncoder.SetPosition(0);

    Reset();
}

void ArmSubsystem::Periodic() {
    frc::SmartDashboard::PutNumber("Arm Rotations", m_armEncoder.GetPosition());
}

void ArmSubsystem::Reset() {
    m_armMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    m_armController.SetP(kP);
    m_armController.SetI(kI);
    m_armController.SetD(kD);
    m_armController.SetSmartMotionMaxVelocity(maxSpeed);
    m_armController.SetSmartMotionMinOutputVelocity(minSpeed);
}

void ArmSubsystem::SetPose(double rotations) {
    m_armController.SetReference(rotations, rev::ControlType::kPosition);
}

void ArmSubsystem::SetSpeed(double speed) {
    m_armMotor.Set(speed);
}