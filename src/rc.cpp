/* 
 * rosserial::std_msgs::String Test
 * Prints "hello world!"
 */

#include <WProgram.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

#include "motorcontrol.h"

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

 char hello[] = "hello world! I am an R/C car!";


void cmd_vel_cb(const  geometry_msgs::Twist& cmd_vel_msg){

	int f = cmd_vel_msg.linear.x *255;
	int diff = cmd_vel_msg.angular.z*255;
	setLeftMotorSpeed(f-diff);
	setRightMotorSpeed(f+diff);
	digitalWrite(13, HIGH-digitalRead(13));
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb);

void setup()
{
  initMotorDriver();
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);

  str_msg.data = hello;
}



long pub_timer= 0;


void loop()
{
  if ( (millis() - pub_timer) > 2000){
	 chatter.publish( &str_msg );
	pub_timer = millis();
}
  nh.spinOnce();
  delay(1);
}
