// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutonomousCommand.h"
#include "../Robot.h"



AutonomousCommand::AutonomousCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	counter = 0;
	centerdistance=0;
	startonleft=false;
	autonMode=0;
}

// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {
	potZero = 3000;
	offset = 0;
	Robot::autoMode = true;
	centerdistance=0;
	startonleft=false;
	counter=0;
	autonMode=0;
	if(autonMode==0)
	{
		step = -2;
	}else{
		step = 0;
	}

	Robot::chassis->leftEn->Reset();
	if(Robot::leftZVal<0.0f && Robot::rightZVal>0.0f) {
		autonMode=1;
	}
	else if(Robot::leftZVal>0.0f && Robot::rightZVal<0.0f) {
		autonMode=2;
	}
	else if(Robot::leftZVal<0.0f && Robot::rightZVal<0.0f) {
		autonMode=3;
	}
	printf("Auto Mode: %d\tLeft: %f\tRight: %f\n",autonMode,Robot::leftZVal,Robot::rightZVal);
}

// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {
	//centerdistance=	Robot::table->GetNumber("Midpoint",0);
	switch(autonMode) {
	case 0:
		mode0();
		break;
	case 1:
		mode1();
		break;
	case 2:
		mode2();
		break;
	case 3:
		mode3();
		break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutonomousCommand::End() {
	Robot::autoMode = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted() {

}



//void AutonomousCommand::GoForward() {
//	Robot::chassis->leftDrive->Set(1);
//	Robot::chassis->rightDrive->Set(-1);
//
//	//activate pick up mechanism/function
//	//pickup activates GoBackward() once done
//}
//
//void AutonomousCommand::GoBackward() {
//	Robot::chassis->leftDrive->Set(-1);
//	Robot::chassis->rightDrive->Set(1);
//	counter++;
//	if(startonleft==true) {
//		Robot::chassis->sideEn->Reset();
//		StrafeRight(500);
//	}else{
//		Robot::chassis->sideEn->Reset();
//		StrafeLeft(500);
//	}
//}
//
//void AutonomousCommand::StrafeLeft(int strafeamount) {
//	Robot::chassis->sideDrive->Set(1);
//	if(Robot::chassis->sideEn->Get()>strafeamount||Robot::chassis->sideEn->Get()<-1*strafeamount) {
//		Robot::chassis->sideDrive->Set(0);
//		Angle();
//	}
//}
//
//
//
//void AutonomousCommand::StrafeRight(int strafeamount) {
//	Robot::chassis->sideDrive->Set(-1);
//	if(Robot::chassis->sideEn->Get()>strafeamount||Robot::chassis->sideEn->Get()<-1*strafeamount) {
//		Robot::chassis->sideDrive->Set(0);
//		Angle();
//	}
//}
//
//
//void AutonomousCommand::Angle() {
//	if(Robot::table->GetNumber("Angle",0)>1.01) {
//		Robot::chassis->rightDrive->Set(1);
//		Robot::chassis->leftDrive->Set(-1);
//		Angle();
//		StrafeLeft(20);
//	}
//	if(Robot::table->GetNumber("Angle",0)<.99) {
//		Robot::chassis->rightDrive->Set(-1);
//		Robot::chassis->leftDrive->Set(1);
//		Angle();
//		StrafeRight(20);
//	}
//	if(Robot::table->GetNumber("Angle",0)>.99&&Robot::table->GetNumber("Angle",0)<1.01) {
//		Center();
//	}
//}
//
//void AutonomousCommand::Center() {
//	if(centerdistance<-5) {
//		Robot::chassis->sideDrive->Set(1);
//	}
//	if(centerdistance>5) {
//		Robot::chassis->sideDrive->Set(-1);
//	}
//	if(5>centerdistance&&centerdistance>-5) {
//		GoForward();
//	} else {
//		Center();
//	}
//}

void AutonomousCommand::mode0() {
	printf("LeftEn : %d   RightEn : %d   SideEn : %d\n", Robot::chassis->leftEn->GetRaw(), Robot::chassis->rightEn->GetRaw(), Robot::chassis->sideEn->GetRaw());
	switch (step) {
	case -2:
		Robot::chassis->rightDrive->Set(-0.30);
		Robot::chassis->leftDrive->Set(0.30);
		if (Robot::chassis->leftEn->GetRaw() > 50) {
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case -1:
		Robot::chassis->rightDrive->Set(-0.15);
		Robot::chassis->leftDrive->Set(0.15);
		if (Robot::chassis->leftEn->GetRaw() > 275) {
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 0:
		Robot::toteElevator->toteDrive->Set(0.75);
		if (Robot::toteElevator->totePot->GetValue() < (potZero - 450)) {
			Robot::toteElevator->toteDrive->Set(0);
			step++;
		}
		break;
	case 1:
		Robot::chassis->strafeSol->Set(DoubleSolenoid::kReverse);
		Robot::chassis->rightDrive->Set(0.4);
		Robot::chassis->leftDrive->Set(-0.4);
		if (Robot::chassis->leftEn->GetRaw() < -450) {
			step++;
		}
		break;
	case 2:
		Robot::chassis->rightDrive->Set(0);
		Robot::chassis->leftDrive->Set(0);
		step++;
		break;
	case 3:
		Robot::chassis->strafeSol->Set(DoubleSolenoid::kForward);
		Robot::chassis->sideEn->Reset();
		step++;
		break;
	case 4:
		Robot::chassis->sideDrive->Set(0.45);
		if (Robot::chassis->sideEn->GetRaw() < -2200) {
			step++;
		}
		break;
	case 5:
		Robot::chassis->sideDrive->Set(0);
		Robot::chassis->sideEn->Reset();
		step++;
		break;
	case 6:
		Robot::chassis->strafeSol->Set(DoubleSolenoid::kReverse);
		Robot::chassis->leftEn->Reset();
		step++;
		break;
	case 7:
		Robot::chassis->rightDrive->Set(-0.50);
		Robot::chassis->leftDrive->Set(0.50);
		if (Robot::chassis->leftEn->GetRaw() > 50) {
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 8:
		Robot::chassis->rightDrive->Set(-0.15);
		Robot::chassis->leftDrive->Set(0.15);
		if (Robot::chassis->leftEn->GetRaw() > 900) {
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 9:
		autonMode = 1;
		offset = 300;
		step = 0;
		mode1();
		break;
	}
}

void AutonomousCommand::mode1() {
	printf("LeftEn : %d   RightEn : %d   SideEn : %d\n", Robot::chassis->leftEn->GetRaw(), Robot::chassis->rightEn->GetRaw(), Robot::chassis->sideEn->GetRaw());
	switch (step) {
	case 0:
		Robot::chassis->leftDrive->Set(0.30);
		Robot::chassis->rightDrive->Set(-0.30);
		if (Robot::chassis->leftEn->GetRaw() > 25) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 1:
		Robot::toteElevator->toteDrive->Set(0.4);
		if (Robot::toteElevator->totePot->GetValue() < ((potZero - 300) - offset)) {
			Robot::toteElevator->toteDrive->Set(0);
			step++;
		}
		break;
	case 2:
		Robot::chassis->leftDrive->Set(-0.4);
		Robot::chassis->rightDrive->Set(0.4);
		if (Robot::chassis->leftEn->GetRaw() < -1800) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 3:
//		Robot::toteElevator->toteDrive->Set(-0.75);
//		if (Robot::toteElevator->totePot->GetValue() > potZero) {
//			Robot::toteElevator->toteDrive->Set(0);
//			Robot::chassis->leftEn->Reset();
//			step++;
//		}
//		break;
		Robot::chassis->leftEn->Reset();
		step++;
		break;
	case 4:
		//Robot::chassis->leftDrive->Set(-0.55);
		//Robot::chassis->rightDrive->Set(0.55);
		Robot::chassis->leftDrive->Set(-0.75);
		Robot::chassis->rightDrive->Set(-0.6);
		if (Robot::chassis->leftEn->GetRaw() < -1200) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::toteElevator->toteDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 5:
		Robot::chassis->leftDrive->Set(0);
		Robot::chassis->rightDrive->Set(0);
		Robot::chassis->leftEn->Reset();
		Robot::toteElevator->toteDrive->Set(0);
		step++;
		break;
	case 6:
		//Robot::toteElevator->toteDrive->Set(0);
		//autonMode = 2;
		offset = 600;
		//step = 0;
		break;
	}
}

void AutonomousCommand::mode2() {
	printf("LeftEn : %d   RightEn : %d   SideEn : %d\n", Robot::chassis->leftEn->GetRaw(), Robot::chassis->rightEn->GetRaw(), Robot::chassis->sideEn->GetRaw());
	switch(step)
	{
	case 0:
		Robot::chassis->leftDrive->Set(0.5);
		Robot::chassis->rightDrive->Set(-0.5);
		if(Robot::chassis->leftEn->GetRaw() > 25) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 1:
		Robot::toteElevator->toteDrive->Set(0.4);
		if (Robot::toteElevator->totePot->GetValue() < ((potZero - 300) - offset)) {
			Robot::toteElevator->toteDrive->Set(0);
			step++;
		}
		break;
	case 2:
		Robot::chassis->leftDrive->Set(-0.5);
		Robot::chassis->rightDrive->Set(0.5);
		if(Robot::chassis->leftEn->GetRaw() < -750) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 3:
		Robot::chassis->leftDrive->Set(0.5);
		Robot::chassis->rightDrive->Set(-0.5);
		if(Robot::chassis->leftEn->GetRaw() > 25) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 4:
		Robot::chassis->leftDrive->Set(-0.65);
		Robot::chassis->rightDrive->Set(-0.5);
		if (Robot::chassis->leftEn->GetRaw() < -1150) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::toteElevator->toteDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 5:
		Robot::chassis->leftDrive->Set(-0.5);
		Robot::chassis->rightDrive->Set(0.5);
		if(Robot::chassis->leftEn->GetRaw() < -850) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			Robot::containerElevator->ToggleClaw();
			step++;
		}
		break;
	case 6:
		Robot::chassis->leftDrive->Set(0.5);
		Robot::chassis->rightDrive->Set(-0.5);
		if(Robot::chassis->leftEn->GetRaw() > 25) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	}
}

void AutonomousCommand::mode3() {

}

// new updates

void AutonomousCommand::mode4() {
	switch(step) {
	case 0:
		Robot::toteElevator->toteDrive->Set(0.5);
		if (Robot::toteElevator->totePot->GetValue() > 2750) {
			Robot::toteElevator->toteDrive->Set(0);
			Robot::chassis->sideEn->Reset();
			Robot::chassis->strafeSol->Set(DoubleSolenoid::kForward);
			step++;
		}
		break;
	case 1:
		if (Robot::chassis->sideEn->GetRaw() < 2500) {
			Robot::chassis->sideDrive->Set(0.5);
		}
		else {
			Robot::chassis->sideDrive->Set(0);
		}
		if (Robot::toteElevator->totePot->GetValue() < 2250) {
			Robot::toteElevator->toteDrive->Set(0.5);
		}
		else {
			Robot::toteElevator->toteDrive->Set(0);
		}
		if (Robot::toteElevator->totePot->GetValue() < 2250 && Robot::chassis->sideEn->GetRaw() > 2500) {
			step++;
		}
		break;
	case 2:
		Robot::toteElevator->toteDrive->Set(0.5);
		if (Robot::toteElevator->totePot->GetValue() < 2250) {
			Robot::toteElevator->toteDrive->Set(0);
			Robot::chassis->sideEn->Reset();
			Robot::chassis->strafeSol->Set(DoubleSolenoid::kReverse);
			step++;
		}
		break;
	case 3:
		Robot::chassis->leftDrive->Set(-0.5);
		Robot::chassis->rightDrive->Set(0.5);
		if (Robot::chassis->leftEn->GetRaw() < -2500) {
			Robot::chassis->leftDrive->Set(0);
			Robot::chassis->rightDrive->Set(0);
			Robot::chassis->leftEn->Reset();
			step++;
		}
		break;
	case 4:
		Robot::chassis->leftDrive->Set(0);
		Robot::chassis->rightDrive->Set(0);
		Robot::chassis->sideDrive->Set(0);
		Robot::toteElevator->toteDrive->Set(0);
		Robot::chassis->leftEn->Reset();
		Robot::chassis->rightEn->Reset();
		Robot::chassis->sideEn->Reset();
		step++;
		break;
	}
}
