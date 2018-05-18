#pragma once
#include "ExternalInclude.h"
#include "Vector2f.h"
#include "BaseAnimation.h"

struct BezierHandles
{
	Vector2f handleOne;
	Vector2f handleTwo;
	BezierHandles(float x1, float y1, float x2, float y2) : handleOne(x1, y1), handleTwo(x2, y2) {}
	BezierHandles() {}
};

class SubAnimation : public BaseAnimation
{
public:
	// Time duration in millisec
	SubAnimation(unsigned int duration, unsigned int updateRate, BezierHandles handles = BezierHandles(0.1f, 0.1f, 0.9f, 0.9f));
	~SubAnimation();

	virtual void setup();
	virtual void setUpdateRate(unsigned int updateRate);
protected:
	// The Bezierhandles for calculating the steps of the animation
	BezierHandles handles;

	// Anzahl der Updates die eine Animation braucht, bis sie fertig ist
	float updateCount;
	
	// Die Länge der kompletten Animation in Millisekunden
	unsigned int duration;

	// Wichtig für die BezierRechnung in setupStepSize
	vector<float> factors;
	float median;

	// Setup der Animation
	virtual void setupStepSize() = 0;
private:
	// Private Helferfunktionen zur Berechnung der Zwischenfaktoren
	vector<float> getBezierFactors(Vector2f P1, Vector2f P2, unsigned int steps);
	float getMedian(vector<float> scores);
};



