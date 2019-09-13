#include "commands/DriveJoystick.h"

#include "subsystems/TankSubsystem.h"
#include "Robot.h"

DriveJoystick::DriveJoystick(){
    Requires(TankSubsystem::getInstance());
}

void DriveJoystick::Initialize(){
    TankSubsystem::getInstance()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Execute(){
    TankSubsystem::getInstance()->setSpeed(m_xboxController.GetRawAxis(1), -m_xboxController.GetRawAxis(5));
}

bool DriveJoystick::IsFinished(){
    return false;
}

void DriveJoystick::End(){
    TankSubsystem::getInstance()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Interrupted(){
    End();
}