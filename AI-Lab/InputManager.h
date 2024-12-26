#pragma once
#include "Render.h"
namespace API
{
	class InputManager
	{
	public:

		virtual void init();
		virtual bool is_pressed(const char& key);
		virtual bool is_pressed_down(const char& key);
		virtual void buffers_events();
		virtual std::pair<int, int> get_mouse_pos();
		virtual std::pair<float, float> get_scrool_offset();
		virtual bool is_button_mouse_pressed(const bool& right);
		virtual bool is_button_mouse_pressed_down(const bool& right);
		virtual void set_mouse_cursor(const bool& enabled);

	protected:
		char key_b_event[512];
		std::pair<int, int> mouse_pos;
		std::pair<int, int> mouse_old_pos;
		std::pair<float, float> scrool_offset;
		bool button_mouse_rigth_pressed_manager;
		bool button_mouse_left_pressed_manager;

		bool is_key_pressed_flag;
		bool is_mouse_pressed_flag;
	};
}

