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