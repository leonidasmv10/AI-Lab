#include "stdafx.h"
#include "GLFWInputManager.h"
#include "GL1Render.h"
#include "GL4Render.h"
#include "FactoryEngine.h"

namespace API
{
	GLFWInputManager::GLFWInputManager()
	{
		this->window = nullptr;
	}

	GLFWInputManager::GLFWInputManager(GLFWwindow*& window)
	{
		this->window = window;
	}

	void GLFWInputManager::init()
	{
		InputManager::init();
		this->window = API::RenderTypeToGLFWwindow(FactoryEngine::selected_graphics_backend);

		key_manager = [&](int key, int sancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
					this->key_b_event[key] = '1';
					break;
				case GLFW_RELEASE:
					this->key_b_event[key] = '0';
					if (is_key_pressed_flag) is_key_pressed_flag = false;
					break;
				}
			};

		mouse_manager = [&](double xpos, double ypos)
			{
				mouse_old_pos = mouse_pos;
				mouse_pos = { (int)xpos, (int)ypos };
			};

		mouse_pressed_manager = [&](int button, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
					if (button == GLFW_MOUSE_BUTTON_RIGHT)
						button_mouse_rigth_pressed_manager = true;
					else if (button == GLFW_MOUSE_BUTTON_LEFT)
						button_mouse_left_pressed_manager = true;
					break;
				case GLFW_RELEASE:
					if (button == GLFW_MOUSE_BUTTON_RIGHT)
						button_mouse_rigth_pressed_manager = false;
					else if (button == GLFW_MOUSE_BUTTON_LEFT)
						button_mouse_left_pressed_manager = false;
					if (is_mouse_pressed_flag) is_mouse_pressed_flag = false;
					break;
				}

			};

		scroll_manager = [&](double xoffset, double yoffset)
			{
				scrool_offset = { xoffset, yoffset };
			};

		framebuffer_size = [&](int width, int height)
			{
				glViewport(0, 0, width, height);
			};

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			auto w = (GLFWInputManager*)glfwGetWindowUserPointer(window); if (w->key_manager) w->key_manager(key, scancode, action, mods);
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
			auto w = (GLFWInputManager*)glfwGetWindowUserPointer(window); if (w->mouse_manager) w->mouse_manager(xpos, ypos);
			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			auto w = (GLFWInputManager*)glfwGetWindowUserPointer(window); if (w->mouse_pressed_manager) w->mouse_pressed_manager(button, action, mods);
			});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
			auto w = (GLFWInputManager*)glfwGetWindowUserPointer(window); if (w->scroll_manager) w->scroll_manager(xoffset, yoffset);
			});

		glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			auto w = (GLFWInputManager*)glfwGetWindowUserPointer(window); if (w->framebuffer_size) w->framebuffer_size(width, height);
			});

		glfwSetWindowUserPointer(window, this);
	}

	bool GLFWInputManager::is_pressed(const char& key)
	{
		if (key >= 97 && key <= 122)
			return InputManager::is_pressed(key - 32);
		return InputManager::is_pressed(key);
	}

	bool GLFWInputManager::is_pressed_down(const char& key)
	{
		if (is_key_pressed_flag) return false;
		bool is_pressed = false;

		if (key >= 97 && key <= 122)
			is_pressed = InputManager::is_pressed_down(key - 32);
		else
			is_pressed = InputManager::is_pressed_down(key);

		if (is_pressed && !is_key_pressed_flag)
			is_key_pressed_flag = true;

		return is_pressed;
	}

	bool GLFWInputManager::is_button_mouse_pressed(const bool& right)
	{
		return InputManager::is_button_mouse_pressed(right);
	}

	bool GLFWInputManager::is_button_mouse_pressed_down(const bool& right)
	{
		if (is_mouse_pressed_flag) return false;
		const bool is_pressed = InputManager::is_button_mouse_pressed_down(right);

		if (is_pressed && !is_mouse_pressed_flag)
			is_mouse_pressed_flag = true;

		return is_pressed;
	}

	void GLFWInputManager::set_mouse_cursor(const bool& enabled)
	{
		if (enabled)
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		else
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void GLFWInputManager::buffers_events()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}