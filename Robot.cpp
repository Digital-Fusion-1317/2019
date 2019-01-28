/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Talon.h>

#define DriveM_FrontRight = 2
#define DriveM_FrontLeft = 12
#define DriveM_RearRight = 3
#define DriveM_RearLeft = 13

#define LeftJoystick = 0
#define RightJoystick = 1

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::TimedRobot {
  frc::Talon m_leftFrontMotor{DriveM_FrontLeft};
  frc::Talon m_rightFrontMotor{DriveM_FrontRight};
  frc::Talon m_rightRearMotor{DriveM_RearRight};
  frc::Talon m_leftRearMotor{DriveM_RearLeft};
  frc::SpeedControllerGroup m_left{m_leftFrontMotor, m_rightFrontMotor};
  frc::SpeedControllerGroup m_right{m_rightFrontMotor, m_rightRearMotor};



  frc::DifferentialDrive m_robotDrive{m_left, m_right};
  frc::Joystick joy_left{LeftJoystick};
  frc::Joystick joy_right{RightJoystick};

 public:
  void TeleopPeriodic() {
    // Drive with arcade style
    m_robotDrive.ArcadeDrive(joy_left.GetY(), joy_right.GetY());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
