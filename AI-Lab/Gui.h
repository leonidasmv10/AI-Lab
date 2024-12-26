#pragma once
namespace API
{
	class Gui
	{
	public:
		virtual void begin();
		virtual void end();
		virtual void init();
		virtual void step(const float time_step);
		virtual void clear();

		virtual bool set_input_int(const char* id, const char* label, int& value, bool new_line = false, std::string description = "");
		virtual bool set_color_3f(const char* id, const char* label, glm::vec3& value, bool new_line = false, std::string description = "");
		virtual bool set_drag_float_3f(const char* id, const char* label, glm::vec3& value, bool new_line = false, std::string description = "");

		virtual bool button(const char* id, const char* label, bool new_line = false, std::string description = "");
		virtual void debug();
	};
}