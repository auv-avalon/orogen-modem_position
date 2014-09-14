/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "ModemPositionSender.hpp"

using namespace modem_position;

ModemPositionSender::ModemPositionSender(std::string const& name)
    : ModemPositionSenderBase(name)
{
}

ModemPositionSender::ModemPositionSender(std::string const& name, RTT::ExecutionEngine* engine)
    : ModemPositionSenderBase(name, engine)
{
}

ModemPositionSender::~ModemPositionSender()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See ModemPositionSender.hpp for more detailed
// documentation about them.

bool ModemPositionSender::configureHook()
{
    if (! ModemPositionSenderBase::configureHook())
        return false;
    return true;
}
bool ModemPositionSender::startHook()
{
    if (! ModemPositionSenderBase::startHook())
        return false;
    return true;
}
void ModemPositionSender::updateHook()
{
    ModemPositionSenderBase::updateHook();
}
void ModemPositionSender::errorHook()
{
    ModemPositionSenderBase::errorHook();
}
void ModemPositionSender::stopHook()
{
    ModemPositionSenderBase::stopHook();
}
void ModemPositionSender::cleanupHook()
{
    ModemPositionSenderBase::cleanupHook();
}
