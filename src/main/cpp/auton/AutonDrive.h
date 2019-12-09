
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

// Standard C++ includes
#include <memory>

// frc includes
#include <frc/BuiltInAccelerometer.h>

// Team 302 include
#include <subsys/Chassis.h>

// CTRE includes 


/*========================================================================================================
 * AutonDrive.h
 *========================================================================================================
 *
 * File Description:  This class controls running the drive wheels.
 *
 *========================================================================================================*/
class AutonDrive 
{
    public:
    
        AutonDrive
        (
            std::shared_ptr<Chassis>     chassis
        );
        AutonDrive() = delete;
        ~AutonDrive() = default;
        
 
        ///-----------------------------------------------------------------------------------------
        /// Method:        DriveToShoot
        /// Description:   Drive to the shoot location
        /// Returns:       bool   - true = at desired location
        ///                         false = not at desired location
        ///-----------------------------------------------------------------------------------------
        bool DriveToShoot();
        
 
        ///-----------------------------------------------------------------------------------------
        /// Method:        DriveToGet
        /// Description:   Drive to the shoot location
        /// Returns:       bool   - true = at desired location
        ///                         false = not at desired location
        ///-----------------------------------------------------------------------------------------
        bool DriveToGet();
        

    private:
        std::shared_ptr<Chassis>     m_chassis;
        std::unique_ptr<frc::BuiltInAccelerometer> m_accel;
        const double m_shootLocation = 92.25;
        const double m_getlocation = -92.25;

};
