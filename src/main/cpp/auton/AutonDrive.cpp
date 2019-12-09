
///====================================================================================================================================================
/// Copyright 2019 Lake Orion Robotics FIRST Team 302
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
/// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
/// OR OTHER DEALINGS IN THE SOFTWARE.
///====================================================================================================================================================

// C++ Includes
#include <memory>

// FRC includes
#include <frc/interfaces/Accelerometer.h>
#include <frc/BuiltInAccelerometer.h>

// Team 302 Includes
#include <auton/AutonDrive.h>
#include <subsys/Chassis.h>

using namespace std;
using namespace frc;

AutonDrive::AutonDrive
(
    shared_ptr<Chassis>     chassis
) : m_chassis( chassis ),
    m_accel( make_unique<BuiltInAccelerometer>( Accelerometer::Range::kRange_8G ))
{
}

bool AutonDrive::DriveToShoot()
{
    bool isDone = false;
    auto leftDist = m_chassis->GetLeftDistance();
    auto rightDist = m_chassis->GetRightDistance();
    auto dist = ( leftDist + rightDist ) / 2.0;
    double power = 0.0;
    isDone = (dist < m_shootLocation );
    if ( !isDone )
    {
        power = ( dist < m_shootLocation * 0.75 ) ? 1.0 : 0.25;
        if ( abs( power )           < 0.5 && 
             abs( m_accel->GetX() ) < 0.1 && 
             abs( m_accel->GetY() ) < 0.1 && 
             abs( m_accel->GetZ() ) < 0.1 )
        {
            power = 0.0;
            isDone = true;
        }
    }
    m_chassis->Drive( power, power );
    return isDone;
}



bool AutonDrive::DriveToGet()
{
    bool isDone = false;
    auto leftDist = m_chassis->GetLeftDistance();
    auto rightDist = m_chassis->GetRightDistance();
    auto dist = ( leftDist + rightDist ) / 2.0;
    double power = 0.0;
    isDone = (dist > m_getlocation );
    if ( !isDone )
    {
        power = ( dist > m_getlocation * 0.75 ) ? -1.0 : -0.25;
        if ( abs( power )           < 0.5 && 
             abs( m_accel->GetX() ) < 0.1 && 
             abs( m_accel->GetY() ) < 0.1 && 
             abs( m_accel->GetZ() ) < 0.1 )
        {
            power = 0.0;
            isDone = true;
        }
    }
    m_chassis->Drive( power, power );
    return isDone;
}

