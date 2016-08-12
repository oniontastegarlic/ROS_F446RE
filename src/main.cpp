#include "mbed.h"
#include <ros.h>
/*
PwmOut led1(LED1);

int main() {
  led1.period_ms(1000);
  led1.write(0.10f);
  while(1);
}
*/

#include <std_msgs/Float32.h>

PwmOut led1(PC_9);
float per;

ros::NodeHandle nh;

void led_cb(const std_msgs::Float32 &cmd_msg){
  /*if(cmd_msg.data == 1){
    period = 100;
  }
  else{
    period = 1000;
  }
  */
  per = cmd_msg.data;
  led1.period(100);
  led1.write(per);
}

ros::Subscriber<std_msgs::Float32> sub("led", led_cb);

int main(){
  nh.initNode();
  nh.subscribe(sub);

  while(1){
  nh.spinOnce();
  wait_ms(1);
  }
}
