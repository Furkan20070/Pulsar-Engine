#include "PulsarTimer.h"

using namespace std::chrono;

PulsarTimer::PulsarTimer()
{
	last = steady_clock::now();
}

float PulsarTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float PulsarTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}
