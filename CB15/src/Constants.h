#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_ 1

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

#endif /* SRC_CONSTANTS_H_ */
