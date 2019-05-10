#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

#include "RobotMap.h"

class TankSubsystem : public frc::Subsystem {
    public:
        TankSubsystem();

        void init();

        void setSpeed(const double& left, const double& right);

    private:

        const int TIMEOUT = 10;

        WPI_TalonSRX m_frontLeft = {TALON_FRONT_LEFT};
        WPI_TalonSRX m_frontRight = {TALON_FRONT_RIGHT};
        WPI_TalonSRX m_backLeft = {TALON_BACK_LEFT};
        WPI_TalonSRX m_backRight = {TALON_BACK_RIGHT};

};