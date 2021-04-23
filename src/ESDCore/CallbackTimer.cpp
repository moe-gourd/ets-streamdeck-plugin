#include "pch.h"
#include "CallbackTimer.h"

CallbackTimer::CallbackTimer() :runningMutex(false)
{
}

CallbackTimer::~CallbackTimer()
{
	if (runningMutex.load(std::memory_order_acquire)) {
		stop();
	}
}

void CallbackTimer::stop()
{
	runningMutex.store(false, std::memory_order_release);
	if (timerThread.joinable()) {
		timerThread.join();
	}
}

void CallbackTimer::start(int interval, std::function<void(void)> callbackFunction)
{
	if (runningMutex.load(std::memory_order_acquire)) {
		stop();
	}

	runningMutex.store(true, std::memory_order_release);

	timerThread = std::thread([this, interval, callbackFunction]() 
		{
			while (runningMutex.load(std::memory_order_acquire)) {
				callbackFunction();
				std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			}
		}
	);
}

bool CallbackTimer::isRunning() const noexcept
{
	return (runningMutex.load(std::memory_order_acquire) && timerThread.joinable());
}
