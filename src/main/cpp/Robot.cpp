/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Sourhce Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/RobotDrive.h>
#include "ctre/Phoenix.h"

using namespace frc;
/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 */

class Robot : public frc::TimedRobot {
  Joystick m_stick{0};
  RobotDrive driveSys; // robot drive system
  PWMVictorSPX m_motor{0};
  LiveWindow *lw;
  int autoLoopCounter;
  

  Robot():
    driveSys(0,1), //these must be initialized in the same order stick(1), //as they are declared above.
    lw(NULL),
    autoLoopCounter(0)
    {
      driveSys.SetExpiration(0.1); 
    }
  void RobotInit() override{
      lw = LiveWindow::GetInstance();
  }
  void TeleopInit() override {

  }
  void TeleopPeriodic() override { 
    m_motor.Set(m_stick.GetY());
  }
  void AutonomousInit() override {
    autoLoopCounter = 0;

  }
  void AutonomousPeriodic() override {
    autoLoopCounter=0;
    if(autoLoopCounter<100){
      autoLoopCounter++;
      driveSys.Drive(1,0.5);


    }
  }
  
};


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
