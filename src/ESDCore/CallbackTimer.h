#pragma once
#include <functional>
class CallbackTimer
{
private:
	std::atomic<bool> runningMutex;
	std::thread timerThread;

public:
	CallbackTimer();
	virtual ~CallbackTimer();
	void stop();
	void start(int interval, std::function<void(void)> callbackFunction);
	bool isRunning() const noexcept;

};

