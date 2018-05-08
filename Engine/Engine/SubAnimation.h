#pragma once
#include "ExternalInclude.h"
#include "BaseObject.h"
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

	virtual void update(BaseObject* object) = 0;

	void start(bool loop = false);
	void restart();
	void pause();
	void resume();
	void increaseTimeAnimation();

	bool isRunning();
	unsigned int getTime();
	void setUpdateRate(unsigned int updateRate);
protected:
	BezierHandles handles;
	//Updaterate der Animation in Millisekunden
	unsigned int updateRate;
	//Anzahl der Updates die eine Animation braucht, bis sie fertig ist
	float updateCount;
	//Der aktuelle Schritt der Animation
	unsigned int timeCount;
	//Die Länge der kompletten Animation in MS
	unsigned int duration;
	//Bestimmen die Eigenschaften der Subanimation 
	bool running;
	bool loop;
	//Wichtig für die BezierRechnung
	vector<float> factors;
	float median;

	virtual void setupAnimation();
	virtual void setupStepSize();
	// Private Helferfunktionen
	vector<float> getBezierFactors(Vector2f P1, Vector2f P2, unsigned int steps);
	float getMedian(vector<float> scores);
};



