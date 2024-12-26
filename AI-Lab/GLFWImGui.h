#pragma once
namespace API
{
	class GLFWImGui : public Gui
	{
	public:

		GLFWImGui();
		~GLFWImGui();
		void begin() override;
		void end() override;
		void init() override;
		void step(const float time_step) override;
		void clear() override;

		bool set_input_int(const char* id, const char* label, int& value, bool new_line = false, std::string description = "") override;
		bool set_color_3f(const char* id, const char* label, glm::vec3& value, bool new_line = false, std::string description = "") override;
		bool set_drag_float_3f(const char* id, const char* label, glm::vec3& value, bool new_line = false, std::string description = "") override;

		bool button(const char* id, const char* label, bool new_line = false, std::string description = "") override;
		void debug() override;

	private:

		inline void begin_flag_gui(const char* id, bool new_line, std::string description);
		inline bool end_flag_gui();

		inline void object_data(Object* obj, int index);

	private:

		GLFWwindow* window;
		ImGuiWindowFlags window_flags;
		bool flag = false;
	};
}

