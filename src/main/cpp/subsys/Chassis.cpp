
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
#include <cmath>                    // std::abs
#include <iostream>                 // std::cout

// Team 302 include

// CTRE includes 
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>

using namespace ctre::phoenix::motorcontrol::can;


Chassis::Chassis()
{
    // This is assuming Thing 1
    auto leftMotor1  = 3;
    auto leftMotor2  = 1;
    auto rightMotor1 = 0;
    auto rightMotor2 = 2;
   
    
    m_frontRightMotor = new TalonSRX( rightMotor1 );
    m_backRightMotor = new TalonSRX( rightMotor2 );

    m_backLeftMotor = new TalonSRX( leftMotor1 );
    m_backLeftMotor->SetInverted( true );
    m_frontLeftMotor = new TalonSRX( leftMotor2 );
    m_frontLeftMotor->SetInverted( true );
   
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
    m_frontLeftMotor->Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, left );
    m_backLeftMotor->Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, left );
    m_frontRightMotor->Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, right );
    m_backRightMotor->Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, right );

}
