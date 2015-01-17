// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::chassisleftDrive = NULL;
SpeedController* RobotMap::chassisrightDrive = NULL;
SpeedController* RobotMap::chassissideDrive = NULL;
Encoder* RobotMap::chassisrightEn = NULL;
Encoder* RobotMap::chassisleftEn = NULL;
Encoder* RobotMap::chassissideEn = NULL;
Gyro* RobotMap::chassisgyro = NULL;
SpeedController* RobotMap::toteElevatortoteDrive = NULL;
AnalogInput* RobotMap::toteElevatortotePot = NULL;
Solenoid* RobotMap::containerElevatorclawSol1 = NULL;
Solenoid* RobotMap::containerElevatorclawSol2 = NULL;
SpeedController* RobotMap::containerElevatorclawPivot = NULL;
SpeedController* RobotMap::containerElevatorclawElevator = NULL;
//DigitalInput* RobotMap::containerElevatorlimitTop = NULL;
DigitalInput* RobotMap::containerElevatorlimitBottom = NULL;
AnalogInput* RobotMap::containerElevatorpivotPot = NULL;
AnalogInput* RobotMap::containerElevatorelevatePot = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	chassisleftDrive = new Talon(0);
	lw->AddActuator("Chassis", "leftDrive", (Talon*) chassisleftDrive);
	
	chassisrightDrive = new Talon(1);
	lw->AddActuator("Chassis", "rightDrive", (Talon*) chassisrightDrive);
	
	chassissideDrive = new Talon(5);
	lw->AddActuator("Chassis", "sideDrive", (Talon*) chassissideDrive);
	
	chassisrightEn = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Chassis", "rightEn", chassisrightEn);
	chassisrightEn->SetDistancePerPulse(1.0);
        chassisrightEn->SetPIDSourceParameter(Encoder::kRate);
	chassisleftEn = new Encoder(2, 3, false, Encoder::k4X);
	lw->AddSensor("Chassis", "leftEn", chassisleftEn);
	chassisleftEn->SetDistancePerPulse(1.0);
        chassisleftEn->SetPIDSourceParameter(Encoder::kRate);
	chassissideEn = new Encoder(12, 13, false, Encoder::k4X);
	lw->AddSensor("Chassis", "sideEn", chassissideEn);
	chassissideEn->SetDistancePerPulse(1.0);
        chassissideEn->SetPIDSourceParameter(Encoder::kRate);
	chassisgyro = new Gyro(0);
	lw->AddSensor("Chassis", "gyro", chassisgyro);
	chassisgyro->SetSensitivity(0.007);
	toteElevatortoteDrive = new Talon(4);
	lw->AddActuator("ToteElevator", "toteDrive", (Talon*) toteElevatortoteDrive);
	
	toteElevatortotePot = new AnalogInput(3);
	containerElevatorclawSol1 = new Solenoid(0, 0);
	lw->AddActuator("ContainerElevator", "clawSol1", containerElevatorclawSol1);
	
	containerElevatorclawSol2 = new Solenoid(0, 1);
	lw->AddActuator("ContainerElevator", "clawSol2", containerElevatorclawSol2);
	
	containerElevatorclawPivot = new Talon(2);
	lw->AddActuator("ContainerElevator", "clawPivot", (Talon*) containerElevatorclawPivot);
	
	containerElevatorclawElevator = new Talon(3);
	lw->AddActuator("ContainerElevator", "clawElevator", (Talon*) containerElevatorclawElevator);
	
//	containerElevatorlimitTop = new DigitalInput(6);
//	lw->AddSensor("ContainerElevator", "limitTop", containerElevatorlimitTop);
	
	containerElevatorlimitBottom = new DigitalInput(7);
	lw->AddSensor("ContainerElevator", "limitBottom", containerElevatorlimitBottom);
	
	containerElevatorpivotPot = new AnalogInput(1);
	containerElevatorelevatePot = new AnalogInput(2); //TODO Get actual pot channel


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}