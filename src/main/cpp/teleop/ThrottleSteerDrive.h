
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

// Team 302 include
#include <subsys/Chassis.h>
#include <controllers/DragonXBox.h>
#include <teleop/TeleopDrive.h>

// CTRE includes 


/*========================================================================================================
 * ThrottleSteerDrive.h
 *========================================================================================================
 *
 * File Description:  This class calculates the drive percents for control strategies that have a 
 *                    throttle and a steer component
 *
 *========================================================================================================*/
class ThrottleSteerDrive : public TeleopDrive
{
    public:
    
        ThrottleSteerDrive
        (
            std::shared_ptr<Chassis>     chassis,
            std::shared_ptr<DragonXBox>  xbox
        );
        ThrottleSteerDrive() = delete;
        ~ThrottleSteerDrive() = default;
               
    protected:
        void CalculateLeftRightPercents() override;
        virtual double GetSteer() = 0;
        virtual double GetThrottle() = 0;

    private:

};
