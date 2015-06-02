// Autonomous Functions //

#pragma systemFile	// eliminates warning for "unreferenced" functions

//Error margin calculation
int difference = abs(nMotorEncoder[RD]) - abs(nMotorEncoder[LD]);

//Timed braking for movements
void pause()
{
	wait1Msec(100);
}

//Move Forward (Distance)
void forward_enc(int distanceInDegrees)
{
   //Clear encoders
   nMotorEncoder[RD] = 0;
   nMotorEncoder[LD] = 0;
   wait1Msec(1000);
   while(abs(nMotorEncoder[RD]) < distanceInDegrees)
   {
      difference = abs(nMotorEncoder[RD]) - abs(nMotorEncoder[LD]);
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]))
         //Slow down right side to adjust for error
      {
         motor[RD] = -50;
         motor[LD] = 42;
      }
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]))
         //Slow down left side to adjust for error
      {
         motor[RD] = -50;
         motor[LD] = 38;
      }
      if(abs(difference) < 2)
         //Drive both sides equally
      {
         motor[RD] = -50;
         motor[LD] = 40;
      }
   }
   //Braking motion to minimize drift
   motor[RD] = 40;
   motor[LD] = -30;
   pause();
   motor[RD] = 0;
   motor[LD] = 0;
}

//Move Backward (Distance)
void backward_enc(int distanceInDegrees)
{
   //Clear encoders
   nMotorEncoder[RD] = 0;
   nMotorEncoder[LD] = 0;
   wait1Msec(1000);
   while(abs(nMotorEncoder[RD]) < distanceInDegrees)
   {
      difference = abs(nMotorEncoder[RD]) - abs(nMotorEncoder[LD]);
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]))
         //Slow down right side to adjust for error
      {
         motor[RD] = 50;
         motor[LD] = -42;
      }
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]))
         //Slow down left side to adjust for error
      {
         motor[RD] = 50;
         motor[LD] = -38;
      }
      if(abs(difference) < 2)
         //Drive both sides equally
      {
         motor[RD] = 50;
         motor[LD] = -40;
      }
   }
   //Braking motion to minimize drift
   motor[RD] = -40;
   motor[LD] = 30;
   pause();
   motor[RD] = 0;
   motor[LD] = 0;
}

//Turn Right (Distance)
void right_enc(int distanceInDegrees)
{
   //Clear encoders
   nMotorEncoder[RD] = 0;
   nMotorEncoder[LD] = 0;
   wait1Msec(1000);
   while(abs(nMotorEncoder[RD]) < distanceInDegrees)
   {
      difference = abs(nMotorEncoder[RD]) - abs(nMotorEncoder[LD]);
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]))
         //Slow down right side to adjust for error
      {
         motor[RD] = 50;
         motor[LD] = 42;
      }
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]))
         //Slow down left side to adjust for error
      {
         motor[RD] = 50;
         motor[LD] = 38;
      }
      if(abs(difference) < 2)
         //Drive both sides equally
      {
         motor[RD] = 50;
         motor[LD] = 40;
      }
   }
   //Braking motion to minimize drift
   motor[RD] = -40;
   motor[LD] = -30;
   pause();
   motor[RD] = 0;
   motor[LD] = 0;
}

//Turn Left (Distance)
void left_enc(int distanceInDegrees)
{
   //Clear encoders
   nMotorEncoder[RD] = 0;
   nMotorEncoder[LD] = 0;
   wait1Msec(1000);
   while(abs(nMotorEncoder[RD]) < distanceInDegrees)
   {
      difference = abs(nMotorEncoder[RD]) - abs(nMotorEncoder[LD]);
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]))
         //Slow down right side to adjust for error
      {
         motor[RD] = -50;
         motor[LD] = -42;
      }
      if(abs(difference) >= 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]))
         //Slow down left side to adjust for error
      {
         motor[RD] = -50;
         motor[LD] = -38;
      }
      if(abs(difference) < 2)
         //Drive both sides equally
      {
         motor[RD] = -50;
         motor[LD] = -40;
      }
   }
   //Braking motion to minimize drift
   motor[RD] = 40;
   motor[LD] = 30;
   pause();
   motor[RD] = 0;
   motor[LD] = 0;
}

//Intake
void intake()
{
	motor[B] = 80;
}

//Outtake
void outtake()
{
	motor[B] = -80;
}

//Lift up
void liftup()
{
	motor[LA] = 127;
	motor[RA] = 127;
}

//Lift down
void liftdown()
{
	motor[LA] = -127;
	motor[RA] = -127;
}

//Stop motors
void stopmotors()
{
	motor[LA] = 0;
	motor[RA] = 0;
	motor[B] = 0;
	motor[LD] = 0;
	motor[RD] = 0;
}
