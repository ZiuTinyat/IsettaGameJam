#pragma once
#include <IsettaEngine.h>

class PowerCurve {
public:
	PowerCurve(float power, unsigned int segNum);
	~PowerCurve();

private:
	void createSegs();
	float power_ = 1.f;
	unsigned int segmentationNum_ = 10;
	std::vector<float> valueList;
};