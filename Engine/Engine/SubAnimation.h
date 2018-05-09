#pragma once
#include "ExternalInclude.h"
#include "AnimationObject.h"
#include "Vector2f.h"



struct BezierHandles
{
	Vector2f handleOne;
	Vector2f handleTwo;
	BezierHandles(float x1, float y1, float x2, float y2) : handleOne(x1, y1), handleTwo(x2, y2) {}
	BezierHandles() {}
};

class SubAnimation
{
public:
	// Time duration in millisec
	SubAnimation();
	SubAnimation(unsigned int duration, BezierHandles handles = BezierHandles(0.1f, 0.1f, 0.9f, 0.9f));
	~SubAnimation();

	virtual void update(AnimationObject* object) = 0;

	void start(bool loop = false);
	void restart();
	void pause();
	void resume();
	void increaseTimeCounter();

	bool isRunning();
	unsigned int getTime();
	void setUpdateRate(unsigned int updateRate);
protected:
	// The Bezierhandles for calculating the steps of the animation
	BezierHandles handles;

	// Updaterate der Animation in Millisekunden
	unsigned int updateRate;

	// Anzahl der Updates die eine Animation braucht, bis sie fertig ist
	float updateCount;

	// Der aktuelle Schritt der Animation
	unsigned int timeCount;

	// Die Länge der kompletten Animation in Millisekunden
	unsigned int duration;

	// Bestimmen die Eigenschaften der Subanimation 
	bool running;
	bool loop;

	// Wichtig für die BezierRechnung
	vector<float> factors;
	float median;

	// Setup der Animation
	virtual void setupAnimation();
	virtual void setupStepSize();

	// Private Helferfunktionen zur Berechnung der Zwischenfaktoren
	vector<float> getBezierFactors(Vector2f P1, Vector2f P2, unsigned int steps);
	float getMedian(vector<float> scores);
};



