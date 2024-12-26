#pragma once
#include "InputManager.h"
#include <GLFW/glfw3.h>
#include <functional>

namespace API
{
	class GLFWInputManager : public InputManager
	{
	public:

		GLFWInputManager();
		GLFWInputManager(GLFWwindow*& window);

		void init() override;
		bool is_pressed(const char& key) override;
		bool is_pressed_down(const char& key) override;
		bool is_button_mouse_pressed(const bool& right) override;
		bool is_button_mouse_pressed_down(const bool& right) override;
		void set_mouse_cursor(const bool& enabled) override;
		void buffers_events() override;

	private:
		GLFWwindow* window;
		std::function<void(int key, int scancode, int action, int mods)> key_manager;
		std::function<void(double xpos, double ypos)> mouse_manager;
		std::function<void(int button, int action, int mods)> mouse_pressed_manager;
		std::function<void(double xoffset, double yoffset)> scroll_manager;
		std::function<void(int width, int height)>  framebuffer_size;
	};
}
