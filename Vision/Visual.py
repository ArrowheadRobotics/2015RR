import rr
import math

def getDist(px): # Get distance from camera to container
	try:
		return (2548/px)
	except ZeroDivisionError: # catch if px is 0
		return

def setGetDistance(): # Create variable named "DISTANCE" for roborealm
	try:
		return rr.SetVariable("DISTANCE", getDist(findDiff(getCoorY(1), getCoorY(7))))
	except SystemError: # catch if one of the functions returns None
		return
		
def findDiff(x, y): # Find the length or height of a blob
	try:
		return abs(x-y)
	except TypeError: # catch if x and y are different data types
		return

def findAngle(x,y): # Figure out if container is tilted
	try:
		x = float(x) # make variables floats
		y = float(y) # ^
		return float(x/y)
	except ZeroDivisionError: # catch if y is 0
		return
	except TypeError: # catch if x and y are different data types
		return
		
def setAngle(): # Create "ANGLE" variable for roborealm
	try:
		return rr.SetVariable("ANGLE", findAngle(findDiff(getCoorX(0),getCoorX(2)), findDiff(getCoorX(10), getCoorX(8))))
	except SystemError: # catch any errors
		return

def setGetDistLeft(): # Set "DISTANCE_LEFT" variable for roborealm
	try:
		return rr.SetVariable("DISTANCE_LEFT", findDiff(getCoorY(1),getCoorY(7)))
	except EnvironmentError: # catch any errors
		return
		
def setGetDistRight(): # Set "DISTANCE_RIGHT" variable for roborealm
	try:
		return rr.SetVariable("DISTANCE_RIGHT", findDiff(getCoorY(11), getCoorY(13)))
	except EnvironmentError: # catch any errors
		return
		
def getCoorX(x): # Get the x value from the array
	try:
		return rr.GetArrayVariable("MEP_COORDINATES")[x]
	except IndexError: # catch if x is greater than array length
		return
		
def getCoorY(y): # Get the y value from the array
	try:
		return rr.GetArrayVariable("MEP_COORDINATES")[y]
	except IndexError: # catch if x is greater than array length
		return
		
def getCoor(x, y): # Get coordinates of a point
	try:
		xTerm = rr.GetArrayVariable("MEP_COORDINATES")[x]
		yTerm = rr.GetArrayVariable("MEP_COORDINATES")[y];
		return "(" + str(xTerm) + " , " + str(yTerm) + ")"
	except IndexError: # catch if x or y is greater than array lenght
		return

def setCoorLeftOne(): # Set "COOR_LEFT_ONE" variable for roborealm
	try:
		return rr.SetVariable("COOR_LEFT_ONE", getCoor(0,1))
	except SystemError: # catch any errors
		return
	
def setCoorLeftTwo(): # Set "COOR_LEFT_TWO" variable for roborealm
	try:
		return rr.SetVariable("COOR_LEFT_TWO", getCoor(2,3))
	except SystemError: # catch any errors
		return

def setCoorLeftThree(): # Set "COOR_LEFT_THREE" variable for roborealm
	try:
		return rr.SetVariable("COOR_LEFT_THREE", getCoor(4,5))
	except SystemError: # catch any errors
		return
		
def setCoorLeftFour(): # Set "COOR_LEFT_FOUR" variable for roborealm
	try:
		return rr.SetVariable("COOR_LEFT_FOUR", getCoor(6,7))
	except SystemError: # catch any errors
		return
		
def setCoorRightOne(): # Set "COOR_RIGHT_ONE" variable for roborealm
	try:
		return rr.SetVariable ("COOR_RIGHT_ONE", getCoor(8,9))
	except SystemError: # catch any errors
		return

def setCoorRightTwo(): # Set "COOR_RIGHT_TWO" variable for roborealm
	try:
		return rr.SetVariable ("COOR_RIGHT_TWO", getCoor(10,11))
	except SystemError: # catch any errors
		return
		
def setCoorRightThree(): # Set "COOR_RIGHT_THREE" variable for roborealm
	try:
		return rr.SetVariable ("COOR_RIGHT_THREE", getCoor(12,13))
	except SystemError: # catch any errors
		return
		
def setCoorRightFour(): # Set "COOR_RIGHT_FOUR" variable for roborealm
	try:
		return rr.SetVariable ("COOR_RIGHT_FOUR", getCoor(14,15))
	except SystemError: # catch any errors
		return
		
def setTerms(): # Create "TERMS" variable for roborealm
	try:
		return rr.SetVariable("TERMS", len(rr.GetArrayVariable("MEP_COORDINATES")))
	except SyntaxError: # catch any errors
		return

if len(rr.GetArrayVariable("MEP_COORDINATES")) == 16: # if only two blobs are on the screen
	setTerms() # Set all variables
	setAngle() #^
	setGetDistance() #^
	setGetDistLeft() #^
	setGetDistRight() #^
	setCoorLeftOne() #^
	setCoorLeftTwo() #^
	setCoorLeftThree() #^
	setCoorLeftFour() #^
	setCoorRightOne() #^
	setCoorRightTwo() #^
	setCoorRightThree() #^
	setCoorRightFour() #^
