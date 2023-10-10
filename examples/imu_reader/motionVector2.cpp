#include "motionVector.h"

void MotionVector::setTime(double time){
	this->time = time;
}

void MotionVector::setLLA(vec3d lla){
	this->lla = lla;
}

void MotionVector::setSpeed(float speed){
	this->speed = speed;
}

void MotionVector::setHeading(float heading){
	this->heading = heading;
}

void MotionVector::setYawRate(float yawRate){
	this->yawRate = yawRate;
}

void MotionVector::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

void MotionVector::setOrientation(float orientation) {
	this->orientation = orientation;
}

double MotionVector::getTime() {
	return this->time;
}

vec3d MotionVector::getLLA() {
	return this->lla;
}

float MotionVector::getSpeed() {
	return this->speed;
}

float MotionVector::getHeading() {
	return this->heading;
}

float MotionVector::getYawRate() {
	return this->yawRate;
}

float MotionVector::getAcceleration() {
	return this->acceleration;
}

float MotionVector::getOrientation() {
	return this->orientation;
}

std::string MotionVector::toString() const {

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
