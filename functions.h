// Autonomous Functions //

#pragma systemFile	// eliminates warning for "unreferenced" functions

//Move Forward (Distance)
void forwardd()
{
		motor[RD] = -127;
		motor[LD] = 127;
}

//Move Backwards (Distance)
void backward()
{
		motor[RD] = 127;
		motor[LD] = -127;
}

//Rotate Clockwise (Distance)
void turnright()
{
		motor[RD] = 127;
		motor[LD] = 127;
}

//Rotate Counter-Clockwise (Distance)
void turnleft()
{
		motor[RD] = -127;
		motor[LD] = -127;
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
