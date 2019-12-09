
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

#pragma once

///========================================================================================================
/// Robot.h
///========================================================================================================
///
/// File Description:
///     Top-level robot code that controls the various states of the robot.  It is our specific 
///     implementation of the frc::TimedRobot.
///
///========================================================================================================


#include <frc/TimedRobot.h>
#include <frc/SmartDashboard/SendableChooser.h>

#include <auton/AutonDrive.h>
#include <auton/AutonShoot.h>

#include <controllers/DragonXBox.h>

#include <teleop/ArcadeDrive.h>
#include <teleop/TankDrive.h>
#include <teleop/GTADrive.h>
#include <teleop/TeleopDrive.h>
#include <teleop/ShooterControl.h>

#include <subsys/Chassis.h>
#include <subsys/Shooter.h>

class Robot : public frc::TimedRobot 
{
  public:
      void RobotInit() override;
      void RobotPeriodic() override;
      void AutonomousInit() override;
      void AutonomousPeriodic() override;
      void TeleopInit() override;
      void TeleopPeriodic() override;
      void TestInit() override;
      void TestPeriodic() override;

  private:
       std::shared_ptr<Chassis>       m_chassis;
       std::shared_ptr<Shooter>       m_shooter;
       std::shared_ptr<DragonXBox>    m_driverXbox;
       std::shared_ptr<DragonXBox>    m_copilotXbox;
       std::shared_ptr<ShooterControl> m_shooterControl;
       std::shared_ptr<ArcadeDrive>    m_arcade;
       std::shared_ptr<TankDrive>      m_tank;
       std::shared_ptr<GTADrive>       m_gta;
       std::shared_ptr<TeleopDrive>    m_currentDrive;

       std::unique_ptr<AutonDrive>     m_autonDrive;
       std::unique_ptr<AutonShoot>     m_autonShoot;

      frc::SendableChooser<std::string>   m_driveModeChooser;                    
      const std::string                   m_driveModeArcade = "Arcade";      
      const std::string                   m_driveModeGTA = "GTA";       
      const std::string                   m_driveModeTank = "Tank";       
      std::string                         m_driveModeSelected;       

      enum AUTON_STATE
      {
        DRIVE_TO_SHOOT,
        SHOOTING,
        DRIVE_TO_GET,
        STOP
      };

      AUTON_STATE m_currentState;

};
