//Sets each button on the xBox controller to their respective values. When setting commands to
//buttons on the xBox controller, use the names here instead of the button's value. Example:
//someBtn = new JoystickButton(gamePad, RIGHTSTICK);
//This would set someBtn to the button with value 9 on the controller because RIGHTSTICK=9.

#ifndef JOYMAP
#define JOYMAP 0

//xBox Controller
#define ABUTTON 0 //Set to ClawToggle
#define BBUTTON 1 //Set to PivotDown
#define XBUTTON 2 //Set to PivotUp
#define YBUTTON 3 //Set to SetpointReset
#define STARTBUTTON 7
#define BACKBUTTON 6
#define LEFTXAXIS 0 //X axis on left stick
#define LEFTYAXIS 1 //Y axis on left stick
#define RIGHTXAXIS 4 //X axis on right stick
#define RIGHTYAXIS 5 //Y axis on right stick
#define LEFTTRIGGER 2 //Set to ContainerUp
#define RIGHTTRIGGER 3 //Set to LiftUp
#define LEFTBUMPER 4 //Set to ContainerDown
#define RIGHTBUMPER 5 //Set to LiftDown
#define LEFTSTICK 8 //press in left stick
#define RIGHTSTICK 9 //press in right stick

#endif
