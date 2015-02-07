#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_ 1

//OTHER
#define kPOT_LIFT_DIFFERENCE 200 //TODO Find actual difference in pot value when raising things by the height of one tote
#define kPIVOT_HIGH_LIMIT 930 //TODO Find actual limit on the pivot
#define kPIVOT_LOW_LIMIT 2330 //TODO Find actual limit on the pivot
//Tote Elevator PID loop: TODO Tune the PID loop
#define kTOTE_ELEVATOR_KP 0 //Proportional constant
#define kTOTE_ELEVATOR_KI 0 //Integral constant
#define kTOTE_ELEVATOR_KD 0 //Derivative constant
#define kTOTE_ELEVATOR_DT 50 //Change in time (milliseconds)
#define kDEFAULT_SETPOINT 50 //TODO Pick a value for this
#define kTOTETOP 1700
#define kTOTEBOTTOM 3500


//PORTS
#define pLeftDrive 0
#define pRightDrive 1
#define pSideDrive 2

#define pRightEncoderA 4
#define pRightEncoderB 5

#define pLeftEncoderA 2
#define pLeftEncoderB 3

#define pSideEncoderA 6
#define pSideEncoderB 7

#define pGyro 3

#define pToteElevator 3

#define pTotePot 1

#define pClawSolenoidA 2
#define pClawSolenoidB 3

#define pClawPivot 5
#define pContainerElevator 4

#define pContainerElevatorLimitTop 0
#define pContainerElevatorLimitBottom 1

#define pToteElevatorLimitTop 8
#define pToteElevatorLimitBottom 9

#define pElevatorPivotPot 0
#define pElevatorHeightPot 2
//Enter correct values for these constants
#define pStrafeSolenoidA 0
#define pStrafeSolenoidB 1

#endif /* SRC_CONSTANTS_H_ */
