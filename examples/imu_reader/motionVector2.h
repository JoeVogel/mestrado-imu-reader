#ifndef MOTIONVECTOR_H
#define MOTIONVECTOR_H

#include <string>
#include "vn/sensors.h"

using namespace vn::math;

class MotionVector
{
	private:
		
		double time;
		vec3d lla;
		float speed;
		float heading;
		float yawRate;
		float acceleration;
		float orientation;
		
	public:
		
		void setTime(double time)
		void setLLA(vec3d lla);
		void setSpeed(float speed);
		void setHeading(float heading);
		void setYawRate(float yawRate);
		void setAcceleration(float acceleration);
		void setOrientation(float orientation);

		double getTime();
		vec3d getLLA();
		float getSpeed();
		float getHeading();
		float getYawRate();
		float getAcceleration();
		float getOrientation();

		std::string toString() const;

};

#endif // MOTIONVECTOR_H
