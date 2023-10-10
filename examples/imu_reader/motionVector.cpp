#include "motionVector.h"

void motionVector::setLLA(vec3d lla){
	this->lla = lla;
}

void motionVector::setSpeed(float speed){
	this->speed = speed;
}

void motionVector::setHeading(float heading){
	this->heading = heading;
}

void motionVector::setYawRate(float yawRate){
	this->yawRate = yawRate;
}

void motionVector::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

void motionVector::setOrientation(float orientation) {
	this->orientation = orientation;
}

vec3d motionVector::getLLA() {
	return this->lla;
}

float motionVector::getSpeed() {
	return this->speed;
}

float motionVector::getHeading() {
	return this->heading;
}

float motionVector::getYawRate() {
	return this->yawRate;
}

float motionVector::getAcceleration() {
	return this->acceleration;
}

float motionVector::getOrientation() {
	return this->orientation;
}

std::string motionVector::toString() const {

    // Use a função std::to_string() para converter os membros para strings
    std::string result = "[" + std::to_string(this->lla[0]) + ",";
	result += std::to_string(this->lla[1]) + ",";
	result += std::to_string(this->lla[2]) + ",";
	result += std::to_string(this->speed) + ",";
	result += std::to_string(this->heading) + ",";
	result += std::to_string(this->yawRate) + ",";
	result += std::to_string(this->acceleration) + ",";
	result += std::to_string(this->orientation) + "]";

    return result;
}