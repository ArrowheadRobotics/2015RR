#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_ 1

//OTHER
#define POT_LIFT_DIFFERENCE 200 //TODO Find actual difference in pot value when raising things by the height of one tote
#define PIVOT_HIGH_LIMIT 500 //TODO Find actual limit on the pivot
#define PIVOT_LOW_LIMIT 0 //TODO Find actual limit on the pivot
#define PIVOT_NOODLE_POS 250 //TODO Find actual position for loading noodles
//Tote Elevator PID loop: TODO Tune the PID loop
#define TOTE_ELEVATOR_KP 0 //Proportional constant
#define TOTE_ELEVATOR_KI 0 //Integral constant
#define TOTE_ELEVATOR_KD 0 //Derivative constant
#define TOTE_ELEVATOR_DT 10 //Change in time (milliseconds)
#define DEFAULT_SETPOINT 50 //TODO Pick a value for this


//PORTS
#define pLeftDrive 0
#define pRightDrive 1
#define pSideDrive 5
#define pRightEncoderA 0
#define pRightEncoderB 1

#define pLeftEncoderA 2
#define pLeftEncoderB 3

#define pSideEncoderA 12
#define pSideEncoderB 13

#define pGyro 0

#define pToteElevator 4

#define pTotePot 3

#define pClawSolenoid1A 0
#define pClawSolenoid1B 0

#define pClawSolenoid2A 0
#define pClawSolenoid2B 1

#define pClawPivot 2
#define pContainerElevator 3

#define pElevatorLimitTop 6
#define pElevatorLimitBottom 7

#define pElevatorPivotPot 1
#define pElevatorHeightPot 2





#endif /* SRC_CONSTANTS_H_ */
