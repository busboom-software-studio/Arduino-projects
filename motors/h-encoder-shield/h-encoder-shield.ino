#include "L298N_MotorDriver.h"

// Make a motor object 
// Arduino Pin 3 ( pin must have PWM capability), 
//   is connected to the driver board pin EN (enable)
// Arduino Pin 2, is connected to the driver board pin IN1 (H-bridge path 1)
// Arduino Pin 4, is connected to the driver board pin IN2 (H-bridge path 2)
// Set the pins for one motor which uses this dual driver board.
L298N_MotorDriver motor1(9,10,11); 
L298N_MotorDriver motor2(6,7,8); 

byte speed   = 0;    

// Switches between counting up and down 
// to make a ramp up and ramp down for the speed
bool countUp = true; 

void setup() {
  motor1.setSpeed(speed);      // Sets the speed for the motor. 0 - 255
  motor1.setDirection(false);  // Sets the direction ( depending on the wiring ) 
  motor1.enable();             // Turns the motor on

  motor2.setSpeed(speed);      // Sets the speed for the motor. 0 - 255
  motor2.setDirection(false);  // Sets the direction ( depending on the wiring ) 
  motor2.enable();             // Turns the motor on
}

void loop() {
  motor1.setSpeed(speed);  // Sets the new speed
  motor2.setSpeed(speed);  // Sets the new speed
  delay(10);              // Wait a bit to make the ramp longer
  
  if(speed == 255)
  {
	// Changed the rising ramp to a falling ramp
	countUp = false;
  }
  if(speed == 0)
  {
	// Changed the falling ramp to a rising ramp
	countUp = true;
  }
  
  if(countUp)
  {
	speed++;
  }
  else
  {
	speed--;
  }
}