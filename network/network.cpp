#include "network.h"

using namespace linz;
using namespace network;

Net::Net()
{

}

Net::~Net()
{

}

bool Net::Listen(const char* ip, uint16_t port, uint16_t backlog)
{

}

uint32_t Net::Send(char* data, uint32_t length)
{

}

bool Net::Disconnect()
{

}

void Net::Run()
{
	event_base_loop(base_, EVLOOP_NONBLOCK);
}