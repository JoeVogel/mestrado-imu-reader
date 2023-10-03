#include "vn/sensors.h"

using namespace vn::math;

class motionVector
{
	private:

		vec3d lla;
		float speed;
		float heading;
		float yawRate;
		float acceleration;
		float orientation;
		
	public:

		void setLLA(vec3d lla);
		void setSpeed(float speed);
		void setHeading(float heading);
		void setYawRate(float yawRate);
		void setAcceleration(float acceleration);
		void setOrientation(float orientation);

		vec3d getLLA();
		float getSpeed();
		float getHeading();
		float getYawRate();
		float getAcceleration();
		float getOrientation();
		


};