#include "commands/DriveJoystick.h"

#include "Robot.h"

DriveJoystick::DriveJoystick(){
    Requires(Robot::getTankDrive());
}

void DriveJoystick::Initialize(){
    Robot::getTankDrive()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Execute(){
    Robot::getTankDrive()->setSpeed(m_xboxController.GetRawAxis(1), -m_xboxController.GetRawAxis(5));
}

bool DriveJoystick::IsFinished(){
    return false;
}

void DriveJoystick::End(){
    Robot::getTankDrive()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Interrupted(){
    End();
}