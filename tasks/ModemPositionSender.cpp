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
    base::samples::RigidBodyState rbs;
    if (_position_samples.readNewest(rbs) == RTT::NewData){
        //Message Type 0
        if (rbs.position[0] < -16 || rbs.position[0] > 0 || rbs.position[1] < 0 || rbs.position[1] > 64){
            return;
            //Go in Error State
        }
        modemdriver::modem_message out_message;
        std::vector<char> message(2);
        uint8_t message_type = 1; 
        message[0] = 0;
        message[0] = message[0] || message_type<<6;
        message[0] = message[0] || ((int) round(rbs.position[0]*2))<<1;
        message[0] = message[0] || ((int) (rbs.position[1]*2)) >> 7;
        message[1] = 0;
        message[1] = message[1] || ((int) (rbs.position[1]*2)) & 0x7F;
        out_message.time = base::Time::now();
        out_message.message = std::string(message.begin(), message.end());
        _modem_data.write(out_message);
    }
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
