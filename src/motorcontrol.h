/*
 * motorcontrol.h
 *
 *  Created on: Jul 27, 2011
 *      Author: astambler
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_


void setMotorVel(int dirPin, int pwmPin, int velocity);

void setLeftMotorSpeed(int velocity);

void setRightMotorSpeed(int velocity);

void initMotorDriver();

#endif /* MOTORCONTROL_H_ */
