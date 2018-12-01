#include "PowerCurve.h"

PowerCurve::PowerCurve(float power, unsigned int segNum) :
	power_(power),
	segmentationNum_(segNum)
{
	createSegs();
}

PowerCurve::~PowerCurve()
{}



