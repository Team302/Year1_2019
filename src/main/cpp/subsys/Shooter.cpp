
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
 * Shooter.cpp
 *========================================================================================================
 *
 * File Description:  This class controls running the drive wheels.
 *
 *========================================================================================================*/

#include <subsys/Shooter.h>     // This class definition

// Standard C++ includes
#include <cmath>                    // std::abs

// Team 302 include
#include <RobotMap.h>

// CTRE includes 
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>

using namespace frc;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;


Shooter::Shooter()
{
    m_liftMotor = new TalonSRX( LIFT_MOTOR );
    m_liftMotor->SetInverted( true );
    m_liftMotor->SetNeutralMode( NeutralMode::Brake );

   
    m_shooterMotor = new TalonSRX( SHOOTER_MOTOR );
    m_shooterMotor->SetInverted( false );
    m_shooterMotor->SetNeutralMode( NeutralMode::Coast );

    m_ballSensor = new DigitalInput( BALL_SENSOR );
}


//-----------------------------------------------------------------------------------------
// Method:        Drive
// Description:   Main method for running the drive wheels on the Shooter
// Returns:       void
//-----------------------------------------------------------------------------------------
void Shooter::Propel
( 
    double power         // <I> - power to send to the right motors (between -1.0 and 1.0)
)
{
    // Make sure it is in range and if not, trim the extra off
    auto speed = power;
    if ( power > 1.0 )
    {
        speed = 1.0;
    }
    else if ( power < 1.0 )
    {
        speed = -1.0;
    }
     m_shooterMotor->Set( ControlMode::PercentOutput, speed );
}

void Shooter::Lift
(
    bool isLifting
)
{
    double speed = ( isLifting ) ? 1.0 : 0.0;
    m_liftMotor->Set( ControlMode::PercentOutput, speed );

}

bool Shooter::HasBalls() const
{
    return m_ballSensor->Get();
}