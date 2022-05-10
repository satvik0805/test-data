/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup()
{ 
  Serial.begin(57600);
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
