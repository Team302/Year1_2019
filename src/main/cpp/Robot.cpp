
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

///========================================================================================================
/// Robot.cpp
///========================================================================================================
///
/// File Description:
///     The main robot code.  The Init methods get called when that state gets entered and then the 
///     Periodic methods get called every 20 milliseconds.
///
///========================================================================================================

// C++ Includes
#include <memory>

// FRC includes

// Team 302 Includes
#include <Robot.h>
#include <teleop/ShooterControl.h>
#include <controllers/DragonXBox.h>
#include <subsys/Shooter.h>
#include <teleop/ArcadeDrive.h>
#include <teleop/TankDrive.h>
#include <teleop/GTADrive.h>
#include <subsys/Chassis.h>

using namespace std;

///-----------------------------------------------------------------------
/// Method:      RobotInit
/// Description: When the robot gets created this gets called.  It initializes
///              the robot subsystems (hardware).
///-----------------------------------------------------------------------
void Robot::RobotInit() 
{
    // Each of the objects created should be stored in a class attribute
    
    // Create a Chassis object
    m_chassis = make_shared<Chassis>( );
    m_shooter = make_shared<Shooter>();
    
    // Create a DragonXBox Controller object in port 0
    m_driverXbox = make_shared<DragonXBox>(0);
    m_copilotXbox = make_shared<DragonXBox>(1);

    // Create a TeleopDrive Object passing the chasis and controller objects
    m_arcade = make_unique<ArcadeDrive>( m_chassis,  m_driverXbox );
    m_tank = make_unique<TankDrive>( m_chassis,  m_driverXbox );
    m_gta = make_unique<GTADrive>( m_chassis,  m_driverXbox );
    m_shooterControl = make_unique<ShooterControl>( m_shooter,  m_copilotXbox );
    

}

///-----------------------------------------------------------------------
/// Method:      RobotPeriodic
/// Description: This function is called every robot packet, no matter the 
///              mode. This is used for items like diagnostics that run 
///              during disabled, autonomous, teleoperated and test modes
///              (states).  THis runs after the specific state periodic 
///              methods and before the LiveWindow and SmartDashboard updating.
///-----------------------------------------------------------------------
void Robot::RobotPeriodic() 
{

}


///-----------------------------------------------------------------------
/// Method:      AutonomousInit
/// Description: This initializes the autonomous state
///-----------------------------------------------------------------------
void Robot::AutonomousInit() 
{

}


///-----------------------------------------------------------------------
/// Method:      AutonomousPeriodic
/// Description: Runs every 20 milliseconds when the autonomous state is 
///              active.
///-----------------------------------------------------------------------
void Robot::AutonomousPeriodic() 
{

}


///-----------------------------------------------------------------------
/// Method:      TeleopInit
/// Description: This initializes the teleoperated state
///-----------------------------------------------------------------------
void Robot::TeleopInit() 
{
    m_arcade->Drive();
    //m_gta->Drive();
    //m_tank->Drive();
    m_shooterControl->Run();
}


///-----------------------------------------------------------------------
/// Method:      TeleopPeriodic
/// Description: Runs every 20 milliseconds when the teleoperated state is 
///              active.
///-----------------------------------------------------------------------
void Robot::TeleopPeriodic() 
{
   m_arcade->Drive();
    //m_gta->Drive();
    //m_tank->Drive();
   m_shooterControl->Run();
}


///-----------------------------------------------------------------------
/// Method:      TestInit
/// Description: This initializes the test state
///-----------------------------------------------------------------------
void Robot::TestInit() 
{

}


///-----------------------------------------------------------------------
/// Method:      TestPeriodic
/// Description: Runs every 20 milliseconds when the test state is 
///              active.
///-----------------------------------------------------------------------
void Robot::TestPeriodic() 
{

}

#ifndef RUNNING_FRC_TESTS
int main() 
{
    return frc::StartRobot<Robot>(); 
}
#endif
