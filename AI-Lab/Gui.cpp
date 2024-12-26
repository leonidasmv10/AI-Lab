#include "stdafx.h"
#include "Gui.h"

namespace API
{
	void Gui::begin()
	{
	}

	void Gui::end()
	{
	}

	void Gui::init()
	{
	}

	void Gui::step(const float time_step)
	{
	}

	void Gui::clear()
	{
	}

	bool Gui::set_input_int(const char* id, const char* label, int& value, bool new_line, std::string description)
	{
		return false;
	}

	bool Gui::set_color_3f(const char* id, const char* label, glm::vec3& value, bool new_line, std::string description)
	{
		return false;
	}

	bool Gui::set_drag_float_3f(const char* id, const char* label, glm::vec3& value, bool new_line, std::string description)
	{
		return false;
	}

	bool Gui::button(const char* id, const char* label, bool new_line, std::string description)
	{
		return false;
	}

	void Gui::debug()
	{
	}

}