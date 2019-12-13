#include "commands/DriveJoystick.h"

#include "subsystems/TankSubsystem.h"
#include "Robot.h"
#include "OI.h"
#include "PCMHandler.h"

DriveJoystick::DriveJoystick(){
    Requires(TankSubsystem::getInstance());
}

void DriveJoystick::Initialize(){
    TankSubsystem::getInstance()->setSpeed(0.0, 0.0);
}

void DriveJoystick::Execute(){
    TankSubsystem::getInstance()->setSpeed(m_xboxController.GetRawAxis(1), m_xboxController.GetRawAxis(5));

    if (m_xboxController.GetRawButton(XBOX_BUTTON_LEFT_BUMPER)) {
        PCMHandler::getInstance()->setLowGear();
    }
    else if (m_xboxController.GetRawButton(XBOX_BUTTON_RIGHT_BUMPER)) {
        PCMHandler::getInstance()->setHighGear();
    }
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