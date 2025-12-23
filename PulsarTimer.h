#pragma once
#include <chrono>

class PulsarTimer
{
public:
	PulsarTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};

