#include "stdafx.h"
#include "InputManager.h"

namespace API
{
	void InputManager::init()
	{
		for (int i = 0; i < 512; i++)
		{
			key_b_event[i] = '0';
		}
		is_key_pressed_flag = false;
		is_mouse_pressed_flag = false;
	}

	bool InputManager::is_pressed(const char& key)
	{
		return key_b_event[key] == '1';
	}

	bool InputManager::is_pressed_down(const char& key)
	{
		return key_b_event[key] == '1';
	}

	void InputManager::buffers_events()
	{
	}

	std::pair<int, int> InputManager::get_mouse_pos()
	{
		return mouse_pos;
	}

	std::pair<float, float> InputManager::get_scrool_offset()
	{
		return scrool_offset;
	}

	bool InputManager::is_button_mouse_pressed(const bool& right)
	{
		return right ? button_mouse_rigth_pressed_manager : button_mouse_left_pressed_manager;
	}

	bool InputManager::is_button_mouse_pressed_down(const bool& right)
	{
		return right ? button_mouse_rigth_pressed_manager : button_mouse_left_pressed_manager;
	}

	void InputManager::set_mouse_cursor(const bool& enabled)
	{
	}

}