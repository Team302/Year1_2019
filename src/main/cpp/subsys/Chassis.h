
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
 
#pragma once

// Standard C++ includes

// Team 302 include

// CTRE includes 
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>


/*========================================================================================================
 * Chassis.h
 *========================================================================================================
 *
 * File Description:  This class controls running the drive wheels.
 *
 *========================================================================================================*/
class Chassis 
{
    public:
    
        Chassis();
        ~Chassis() = default;
        
        
        //-----------------------------------------------------------------------------------------
        // Method:        Drive
        // Description:   Main method for running the drive wheels on the chassis
        // Returns:       void
        //-----------------------------------------------------------------------------------------
        void Drive
        ( 
            double leftPower,         // <I> - power to send to the left motors (between -1.0 and 1.0)
            double rightPower         // <I> - power to send to the right motors (between -1.0 and 1.0)
        );
        
    private:
    
        ctre::phoenix::motorcontrol::can::TalonSRX*   m_frontRightMotor;
        ctre::phoenix::motorcontrol::can::TalonSRX*   m_backRightMotor;
        ctre::phoenix::motorcontrol::can::TalonSRX*   m_frontLeftMotor;
        ctre::phoenix::motorcontrol::can::TalonSRX*   m_backLeftMotor;

};
