#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    ,               sensorLineFollower)
#pragma config(Sensor, in8,    Arm,            sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           RD,            tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           LD,            tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           B,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RA,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LA,            tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(100)
#pragma userControlDuration(100)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "functions.h" //Functions header file

//Pre-Autonomous
void pre_auton()
{
	bStopTasksBetweenModes = true;
}

//Autonomous
task autonomous()
{
	forward_enc(965);
	left_enc(350);
	forward_enc(930);
	right_enc(380);
	forward_enc(325);
	intake();
	wait1Msec(1000);
	stopmotors();
	forward_enc(210);
	intake();
	wait1Msec(900);
	stopmotors();
	right_enc(700);
	forward_enc(3100);
	outtake();
	wait1Msec(900);
	stopmotors();
	backward_enc(350);
	outtake();
	wait1Msec(900);
	stopmotors();
	left_enc(800);
	forward_enc(2200);
	right_enc(200);
}

//User Control
task usercontrol()
{

	while (true)
	{
		{
			//Drive
			motor[LD]  = (vexRT[Ch1] + vexRT[Ch3])/2;  // (y + x)/2
			motor[RD] = (vexRT[Ch1] - vexRT[Ch3])/2;  // (y - x)/2

			//Belt
			if(vexRT[Btn5U] == 1)
			{
				motor[B] = 127;
			}
			else if(vexRT[Btn5D] == 1)
			{
				motor[B] = -127;
			}
			else
			{
				motor[B] = 0;
			}

			//Arm
			if(vexRT[Btn6U] == 1)
			{
				motor[RA] = 127;
				motor[LA] = 127;
			}
			else if(vexRT[Btn6D] == 1)
			{
				motor[RA] = -127;
				motor[LA] = -127;
			}
			else
			{
				motor[RA] = 0;
				motor[LA] = 0;
			}
		}
	}
}
