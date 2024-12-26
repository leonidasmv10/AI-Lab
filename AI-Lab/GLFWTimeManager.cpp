#include "stdafx.h"
#include "GLFWTimeManager.h"

namespace API
{
	GLFWTimeManager::GLFWTimeManager()
	{
	}

	void GLFWTimeManager::init()
	{
		TimeManager::init();
	}

	void GLFWTimeManager::update()
	{
		new_time = static_cast<float>(glfwGetTime());
		delta_time = new_time - last_time;
		last_time = new_time;
	}

	float GLFWTimeManager::get_delta_time()
	{
		return TimeManager::get_delta_time();
	}
}