//Sets each button on the xBox controller to their respective values. When setting commands to
//buttons on the xBox controller, use the names here instead of the button's value. Example:
//someBtn = new JoystickButton(gamePad, RIGHTSTICK);
//This would set someBtn to the button with value 9 on the controller because RIGHTSTICK=9.

#ifndef JOYMAP
#define JOYMAP 0

//xBox Controller
#define ABUTTON 1 //Set to ClawToggle
#define BBUTTON 2 //Set to PivotDown
#define XBUTTON 3 //Set to PivotUp
#define YBUTTON 4 //Set to SetpointReset
#define STARTBUTTON 8 //Set to PivotNoodle
#define BACKBUTTON 7
#define LEFTXAXIS 0 //X axis on left stick
#define LEFTYAXIS 1 //Y axis on left stick
#define RIGHTXAXIS 4 //X axis on right stick
#define RIGHTYAXIS 5 //Y axis on right stick
#define LEFTTRIGGER 3 //Set to ContainerUp
#define RIGHTTRIGGER 4 //Set to LiftUp
#define LEFTBUMPER 5 //Set to ContainerDown
#define RIGHTBUMPER 6 //Set to LiftDown
#define LEFTSTICK 9 //press in left stick
#define RIGHTSTICK 10 //press in right stick

#endif
