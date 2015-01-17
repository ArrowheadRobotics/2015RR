import rr
import math

def getDist(pOne, pTwo):
	try:
		return (math.sqrt((pOne - pTwo)**2))/32
	except EnvironmentError:
		return

def setGetDist():
	try:
		return rr.SetVariable("DISTANCE", getDist(getCoorY(0),getCoorY(3)))
	except EnvironmentError:
		return
		
def getCoorY(y):
	try:
		return rr.GetArrayVariable("MEP_COORDINATES")[y]
	except IndexError:
		return
		
def getCoor(x, y):
	try:
		xTerm = rr.GetArrayVariable("MEP_COORDINATES")[x]
		yTerm = rr.GetArrayVariable("MEP_COORDINATES")[y];
		return "(" + str(xTerm) + " , " + str(yTerm) + ")"
	except IndexError:
		return

def setCoorLeftOne():
	try:
		return rr.SetVariable("COOR_LEFT_ONE", getCoor(0,1))
	except SystemError:
		return
	
def setCoorLeftTwo():
	try:
		return rr.SetVariable("COOR_LEFT_TWO", getCoor(2,3))
	except SystemError:
		return

def setCoorLeftThree():
	try:
		return rr.SetVariable("COOR_LEFT_THREE", getCoor(4,5))
	except SystemError:
		return
		
def setCoorLeftFour():
	try:
		return rr.SetVariable("COOR_LEFT_FOUR", getCoor(6,7))
	except SystemError:
		return
		
def setCoorRightOne():
	try:
		return rr.SetVariable ("COOR_RIGHT_ONE", getCoor(8,9))
	except SystemError:
		return

def setCoorRightTwo():
	try:
		return rr.SetVariable ("COOR_RIGHT_TWO", getCoor(10,11))
	except SystemError:
		return
		
def setCoorRightThree():
	try:
		return rr.SetVariable ("COOR_RIGHT_THREE", getCoor(12,13))
	except SystemError:
		return
		
def setCoorRightFour():
	try:
		return rr.SetVariable ("COOR_RIGHT_FOUR", getCoor(14,15))
	except SystemError:
		return
		
def setTerms():
	try:
		return rr.SetVariable("TERMS", len(rr.GetArrayVariable("MEP_COORDINATES")))
	except SyntaxError:
		return


setTerms()

if len(rr.GetArrayVariable("MEP_COORDINATES")):
	setGetDist()
	setCoorLeftOne()
	setCoorLeftTwo()
	setCoorLeftThree()
	setCoorLeftFour()

	setCoorRightOne()
	setCoorRightTwo()
	setCoorRightThree()
	setCoorRightFour()
