#include <iostream>
#include <fstream>

// Include this header file to get access to VectorNav sensors.
#include "vn/sensors.h"

// We need this file for our sleep function.
#include "vn/thread.h"
#include "motionVector.h"

using namespace std;
using namespace vn::math;
using namespace vn::sensors;
using namespace vn::protocol::uart;
using namespace vn::xplat;

// Method declarations for future use.
void asciiAsyncMessageReceived(void* userData, Packet& p, size_t index);

motionVector currentMotionVector = motionVector();

int main(int argc, char *argv[])
{
	const string SensorPort = "/dev/ttyUSB0";                  // Linux format for virtual (USB) serial port.
	const uint32_t SensorBaudrate = 115200;

	// Now let's create a VnSensor object and use it to connect to our sensor.
	VnSensor vs;
	vs.connect(SensorPort, SensorBaudrate);

	vs.writeAsyncDataOutputType(VNISL);

  	AsciiAsync asyncType = vs.readAsyncDataOutputType();
	cout << "ASCII Async Type: " << asyncType << endl;

	vs.registerAsyncPacketReceivedHandler(NULL, asciiAsyncMessageReceived);

	// Now sleep for 5 seconds so that our asynchronous callback method can
	// receive and display receive yaw, pitch, roll packets.
	// TODO: remove when production use
	cout << "Starting sleep..." << endl;
	Thread::sleepSec(5);

	// Unregister our callback method.
	// TODO: when running in production, do this only when process stops
	vs.unregisterAsyncPacketReceivedHandler();

	vs.disconnect();

	return 0;
}

void asciiAsyncMessageReceived(void* userData, Packet& p, size_t index)
{
  // Make sure we have an ASCII packet and not a binary packet.
  if(p.type() != Packet::TYPE_ASCII)
    return;

  // Make sure we have a VNISL data packet.
  if (p.determineAsciiAsyncType() == VNISL) {

	vec3f ypr;
	vec3d lla;
	vec3f velocity;
	vec3f acceleration;
	vec3f angularRate;
	
	p.parseVNISL(&ypr, &lla, &velocity, &acceleration, &angularRate);

	// cout << "YPR: " << ypr << endl;
	// cout << "lla: " << lla << endl;
	// cout << "velocity: " << velocity << endl;
	// cout << "acceleration: " << acceleration << endl;
	// cout << "angularRate: " << angularRate << endl;

	currentMotionVector.setLLA(lla);
	currentMotionVector.setSpeed();
	currentMotionVector.setHeading();
	currentMotionVector.setYawRate();
	currentMotionVector.setAcceleration();
	currentMotionVector.setOrientation();

  } else {
    cout << "ASCII Async: Type(" << p.determineAsciiAsyncType() << ")" << endl;
  }
}
