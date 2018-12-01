#include <IsettaEngine.h>
#include "PowerCurve.h"

using namespace Isetta;

PowerCurve::PowerCurve(float power, int segNum) :
	power_(power),
	segmentationNum_(segNum),
	segInterval_(1.f / (float)segmentationNum_)
{
	createSegs();
}

PowerCurve::~PowerCurve()
{}

void PowerCurve::createSegs()
{
	for (int i = 0; i < segmentationNum_; i++)
	{
		float value = Math::Util::Pow(segInterval_ * (float)i, power_);
		valueList.push_back(value);
	}
}

float PowerCurve::GetValue(float x)
{
	x = Math::Util::Clamp01(x);
	float floatIndex = x / segInterval_;
	int floor = Math::Util::FloorToInt(floatIndex);
	int ceil = Math::Util::CeilToInt(floatIndex);
	floor = Math::Util::Clamp(0, segmentationNum_ - 1, floor);
	ceil = Math::Util::Clamp(0, segmentationNum_ - 1, ceil);
	if (floor == ceil)
	{
		return (valueList[floor] + valueList[ceil]) * .5f;
	}
	else
	{
		float gradient = (valueList[ceil] - valueList[floor]) / (float)(ceil - floor);
		return (floatIndex - (float)floor) * gradient + valueList[floor];
	}
}
