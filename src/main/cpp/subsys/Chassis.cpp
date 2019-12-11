
/*
 * Copyright 2019 Lake Orion Robotics FIRST Team 302
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
/*========================================================================================================
 * Chassis.cpp
 *========================================================================================================
 *
 * File Description:  This class controls running the drive wheels.
 *
 *========================================================================================================*/

#include <subsys/chassis.h>     // This class definition

// Standard C++ includes
#define _USE_MATH_DEFINES
#include <cmath>                    // std::abs
#include <iostream>                 // std::cout

// Team 302 include
#include <RobotMap.h>

// CTRE includes 
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>

using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;


Chassis::Chassis()
{   
    m_rightMotor = new TalonSRX( RIGHT_DRIVE_MOTOR );
    m_rightMotor->SetInverted( false );
    m_rightMotor->SetNeutralMode( NeutralMode::Brake );

    m_leftMotor = new TalonSRX( LEFT_DRIVE_MOTOR );
    m_leftMotor->SetInverted( true );
    m_leftMotor->SetNeutralMode( NeutralMode::Brake );

    m_rightMotor->ConfigSelectedFeedbackSensor( FeedbackDevice::QuadEncoder, 0, 0 );
    m_rightMotor->SetSensorPhase( false );

    m_leftMotor->ConfigSelectedFeedbackSensor( FeedbackDevice::QuadEncoder, 0, 0 );
    m_rightMotor->SetSensorPhase( false );
   
}


//-----------------------------------------------------------------------------------------
// Method:        Drive
// Description:   Main method for running the drive wheels on the chassis
// Returns:       void
//-----------------------------------------------------------------------------------------
void Chassis::Drive
( 
    double leftPower,         // <I> - power to send to the left motors (between -1.0 and 1.0)
    double rightPower         // <I> - power to send to the right motors (between -1.0 and 1.0)
)
{
    // Make sure it is in range and if not, trim the extra off
    auto left = std::abs( leftPower > 1.0 ) ? leftPower / std::abs( leftPower ) : leftPower;
    auto right = std::abs( rightPower > 1.0 ) ? rightPower / std::abs( rightPower ) : rightPower;

    // Set the output to the motors
    m_leftMotor->Set( ControlMode::PercentOutput, left );
    m_rightMotor->Set( ControlMode::PercentOutput, right );

}

double Chassis::GetLeftDistance() const
{
    auto counts = m_leftMotor->GetSelectedSensorPosition( 0 );
    return ConvertCountsToInches( counts );
}

double Chassis::GetRightDistance() const
{
    auto counts = m_rightMotor->GetSelectedSensorPosition( 0 );
    return ConvertCountsToInches( counts );
}

double Chassis::ConvertCountsToInches
(
    int    counts
) const
{
    double rev = static_cast<double>(counts) / static_cast<double>(m_countsPerRev);
    return ( rev * M_PI * m_wheelDiameter );
}
