#pragma once
#include <IsettaEngine.h>

class PowerCurve {
public:
	PowerCurve(float power, int segNum);
	~PowerCurve();
	float GetValue(float x);
private:
	void createSegs();
	float power_ = 1.f;
	float segInterval_;
	int segmentationNum_ = 10;
	std::vector<float> valueList;
};