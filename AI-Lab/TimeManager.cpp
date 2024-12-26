#include "stdafx.h"
#include "TimeManager.h"

namespace API
{
	void TimeManager::init()
	{
		new_time = delta_time = last_time = 0.0f;
	}

	void TimeManager::update()
	{

	}

	float TimeManager::get_delta_time()
	{
		return delta_time;
	}

	float TimeManager::get_time()
	{
		return 0.0f;
	}
}