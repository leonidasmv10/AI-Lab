#pragma once

namespace API
{
	class System
	{
	public:

		// Engine
		static void init_system();
		static void exit();
		static void main_loop();

		// Objects
		static void add_object(Object* obj);
		static std::vector<Object*>* get_objects();

		// Camera
		static Camera* get_camera();
		static void set_camera(Camera*& camera);

		// Gui
		static Gui* get_gui();
		static void set_gui(Gui*& gui);

		// TimeManager
		static TimeManager* get_time_manager();

		// Settings
		static void set_cursor_enabled(const bool& enabled);
		static bool get_cursor_enabled();
		static void change_cursor();

	private:

		static Render* render;
		static InputManager* input_manager;
		static TimeManager* time_manager;
		static Camera* camera;
		static Gui* gui;

		static std::vector<Object*> objects;

		static bool cursor_mouse_enabled;
		static bool end;
	};
}

