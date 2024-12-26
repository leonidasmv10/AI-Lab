#pragma once

namespace API
{
	class FactoryEngine
	{
	public:
		static int app_width;
		static int app_height;

		static RenderType selected_graphics_backend;
		static InputType selected_input_backend;
		static MaterialType selected_material_backend;
		static TextureType selected_texture_backend;
		static GuiType selected_gui_backend;

		static Render* create_render_instance();
		static InputManager* create_input_manager_instance();
		static TimeManager* create_time_manager_instance();
		static Material* create_material_instance();
		static Texture* create_texture_instance();
		static Gui* create_gui_instance();

		static void set_type_graphic(const RenderType type);
		static void set_type_input(const InputType type);
		static void set_type_material(const MaterialType type);
		static void set_type_texture(const TextureType type);
		static void set_type_gui(const GuiType type);

		static Render* get_new_render();
		static InputManager* get_new_input_manager();
		static TimeManager* get_new_time_manager();
		static Material* get_new_material();
		static Texture* get_new_texture();
		static Gui* get_new_gui();

		static Render* get_render();
		static InputManager* get_input_manager();
		static TimeManager* get_time_manager();
		static Gui* get_gui();

		static bool is_closed();

	private:
		static Render* render;
		static InputManager* input_manager;
		static TimeManager* time_manager;
		static Gui* gui;
	};
}
