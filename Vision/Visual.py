import rr
import math

def getDist(px):
	try:
		return (2548/px)
	except ZeroDivisionError:
		return

def setGetDistance():
	try:
		return rr.SetVariable("DISTANCE", getDist(findDiff(getCoorY(1), getCoorY(7))))
	except SystemError:
		return
		
def findDiff(x, y):
	try:
		return abs(x-y)
	except TypeError:
		return

def findAngle(x,y):
	try:
		x = float(x)
		y = float(y)
		print float(x/y)
		return float(x/y)
	except ZeroDivisionError:
		return
	except TypeError:
		return
		
def setAngle():
	try:
		print findDiff(getCoorX(0), getCoorX(2))
		print findDiff(getCoorX(10), getCoorX(8))
		return rr.SetVariable("ANGLE", findAngle(findDiff(getCoorX(0),getCoorX(2)), findDiff(getCoorX(10), getCoorX(8))))
	except SystemError:
		print SystemError
		return

def setGetDistLeft():
	try:
		return rr.SetVariable("DISTANCE_LEFT", findDiff(getCoorY(1),getCoorY(7)))
	except EnvironmentError:
		return
		
def setGetDistRight():
	try:
		return rr.SetVariable("DISTANCE_RIGHT", findDiff(getCoorY(11), getCoorY(13)))
	except:
		return
		
def getCoorX(x):
	try:
		return rr.GetArrayVariable("MEP_COORDINATES")[x]
	except IndexError:
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

if len(rr.GetArrayVariable("MEP_COORDINATES")):
	setTerms()
	setAngle()
	setGetDistance()
	setGetDistLeft()
	setGetDistRight()
	setCoorLeftOne()
	setCoorLeftTwo()
	setCoorLeftThree()
	setCoorLeftFour()
	setCoorRightOne()
	setCoorRightTwo()
	setCoorRightThree()
	setCoorRightFour()
