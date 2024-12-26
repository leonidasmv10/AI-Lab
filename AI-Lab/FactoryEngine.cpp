#include "stdafx.h"
#include "FactoryEngine.h"

namespace API
{
	int FactoryEngine::app_width = 1080;
	int FactoryEngine::app_height = 720;

	RenderType FactoryEngine::selected_graphics_backend = RenderType::GL1;
	InputType FactoryEngine::selected_input_backend = InputType::GLFW;
	MaterialType FactoryEngine::selected_material_backend = MaterialType::GLSL;
	TextureType FactoryEngine::selected_texture_backend = TextureType::GL;
	GuiType FactoryEngine::selected_gui_backend = GuiType::IMGUI;

	Render* FactoryEngine::render;
	InputManager* FactoryEngine::input_manager;
	TimeManager* FactoryEngine::time_manager;
	Gui* FactoryEngine::gui;

	Render* FactoryEngine::create_render_instance()
	{
		switch (FactoryEngine::selected_graphics_backend)
		{
		case GL1:
			return new GL1Render(FactoryEngine::app_width, FactoryEngine::app_height);

		case GL4:
			return new GL4Render(FactoryEngine::app_width, FactoryEngine::app_height);

		default:
			break;
		}
		return nullptr;
	}

	InputManager* FactoryEngine::create_input_manager_instance()
	{
		switch (FactoryEngine::selected_input_backend)
		{
		case GLFW:
			return new GLFWInputManager();

		default:
			break;
		}
		return nullptr;
	}

	TimeManager* FactoryEngine::create_time_manager_instance()
	{
		switch (FactoryEngine::selected_input_backend)
		{
		case GLFW:
			return new GLFWTimeManager();

		default:
			break;
		}
		return nullptr;
	}

	Material* FactoryEngine::create_material_instance()
	{
		switch (FactoryEngine::selected_material_backend)
		{
		case GLSL:
			return new GLSLMaterial();

		default:
			break;
		}
		return nullptr;
	}

	Texture* FactoryEngine::create_texture_instance()
	{
		switch (FactoryEngine::selected_texture_backend)
		{
		case GL:
			return new GLTexture();

		default:
			break;
		}
		return nullptr;
	}

	Gui* FactoryEngine::create_gui_instance()
	{
		switch (FactoryEngine::selected_gui_backend)
		{
		case IMGUI:
			switch (FactoryEngine::selected_input_backend)
			{
			case GLFW:
				return new GLFWImGui();
			default:
				break;
			}
		default:
			break;
		}
		return nullptr;
	}

	void FactoryEngine::set_type_graphic(const RenderType type)
	{
		FactoryEngine::selected_graphics_backend = type;
	}

	void FactoryEngine::set_type_input(const InputType type)
	{
		FactoryEngine::selected_input_backend = type;
	}

	void FactoryEngine::set_type_material(const MaterialType type)
	{
		FactoryEngine::selected_material_backend = type;
	}

	void FactoryEngine::set_type_texture(const TextureType type)
	{
		FactoryEngine::selected_texture_backend = type;
	}

	void FactoryEngine::set_type_gui(const GuiType type)
	{
		FactoryEngine::selected_gui_backend = type;
	}

	Render* FactoryEngine::get_new_render()
	{
		return render = create_render_instance();
	}

	InputManager* FactoryEngine::get_new_input_manager()
	{
		return input_manager = create_input_manager_instance();
	}

	TimeManager* FactoryEngine::get_new_time_manager()
	{
		return time_manager = create_time_manager_instance();
	}

	Material* FactoryEngine::get_new_material()
	{
		return create_material_instance();
	}

	Texture* FactoryEngine::get_new_texture()
	{
		return create_texture_instance();
	}

	Gui* FactoryEngine::get_new_gui()
	{
		return create_gui_instance();
	}

	Render* FactoryEngine::get_render()
	{
		return render;
	}

	InputManager* FactoryEngine::get_input_manager()
	{
		return input_manager;
	}

	TimeManager* FactoryEngine::get_time_manager()
	{
		return time_manager;
	}

	Gui* FactoryEngine::get_gui()
	{
		return gui;
	}

	bool FactoryEngine::is_closed()
	{
		return render->is_closed();
	}
}