// Autonomous Functions //

#pragma systemFile	// eliminates warning for "unreferenced" functions

int difference = abs(nMotorEncoder[RD]) - abs(nMotorEncoder[LD]);

//Move Forward (Distance)
void forward_enc(int distanceInDegrees)
{
	nMotorEncoder[RD] = 0;
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down right side to adjust for error
				{
					motor[RD] = -50;
					motor[LD] = 42;
				}
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down left side to adjust for error
				{
					motor[RD] = -50;
					motor[LD] = 38;
				}
			while(abs(difference) <= 2 && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Drive both sides equally
				{
					motor[RD] = -50;
					motor[LD] = 40;
				}
			motor[RD] = 0;
			motor[LD] = 0;
}

//Move Backward (Distance)
void backward_enc(int distanceInDegrees)
{
	nMotorEncoder[RD] = 0;
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down right side to adjust for error
				{
					motor[RD] = 50;
					motor[LD] = -42;
				}
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down left side to adjust for error
				{
					motor[RD] = 50;
					motor[LD] = -38;
				}
			while(abs(difference) <= 2 && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Drive both sides equally
				{
					motor[RD] = 50;
					motor[LD] = -40;
				}
			motor[RD] = 0;
			motor[LD] = 0;
}

//Turn Right (Distance)
void right_enc(int distanceInDegrees)
{
	nMotorEncoder[RD] = 0;
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down right side to adjust for error
				{
					motor[RD] = 50;
					motor[LD] = 42;
				}
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down left side to adjust for error
				{
					motor[RD] = 50;
					motor[LD] = 38;
				}
			while(abs(difference) <= 2 && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Drive both sides equally
				{
					motor[RD] = 50;
					motor[LD] = 40;
				}
			motor[RD] = 0;
			motor[LD] = 0;
}

//Turn left (Distance)
void left_enc(int distanceInDegrees)
{
	nMotorEncoder[RD] = 0;
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) > abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down right side to adjust for error
				{
					motor[RD] = -50;
					motor[LD] = -42;
				}
			while(abs(difference) > 2 && abs(nMotorEncoder[RD]) < abs(nMotorEncoder[LD]) && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Slow down left side to adjust for error
				{
					motor[RD] = -50;
					motor[LD] = -38;
				}
			while(abs(difference) <= 2 && abs(nMotorEncoder[RD]) < distanceInDegrees)
				//Drive both sides equally
				{
					motor[RD] = -50;
					motor[LD] = -40;
				}
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
