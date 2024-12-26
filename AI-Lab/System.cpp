#include "stdafx.h"
#include "System.h"

namespace API
{
	Render* System::render = nullptr;
	InputManager* System::input_manager = nullptr;
	TimeManager* System::time_manager = nullptr;
	Camera* System::camera = nullptr;
	Gui* System::gui = nullptr;

	std::vector<Object*> System::objects;
	bool System::end = false;
	bool System::cursor_mouse_enabled = true;

	void System::init_system()
	{
		render = FactoryEngine::get_new_render();
		input_manager = FactoryEngine::get_new_input_manager();
		time_manager = FactoryEngine::get_new_time_manager();
		gui = FactoryEngine::get_new_gui();

		camera = new CameraKeyboard
		(
			ProjectionType::PERSPECTIVE,
			glm::vec3(0.0f, 1.0f, 3.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, -1.0f),
			{
				45.0f,
				FactoryEngine::app_width,
				FactoryEngine::app_height,
				0.1f,
				1000.0f
			}
		);

		render->init();
		input_manager->init();
		time_manager->init();
		gui->init();

		assert(!glewInit());
		srand(time(NULL));
	}

	void System::exit()
	{
		System::end = true;
	}

	void System::main_loop()
	{
		for (auto& object : objects)
			render->setup_object(object);

		while (!render->is_closed() && !end)
		{
			gui->begin();

			time_manager->update();
			camera->step(time_manager->get_delta_time());

			if (input_manager->is_pressed_down('e'))
				exit();

			if (input_manager->is_button_mouse_pressed_down(true))
				change_cursor();

			// Objects
			for (const auto& object : objects)
			{
				object->step(time_manager->get_delta_time());
				for (int i = 0; i < object->get_meshes().size(); i++)
				{
					Material* material = object->get_mesh(i)->get_material();
					RenderProgram* program = material->get_program();

					glm::mat4 mvp = glm::mat4(1.0f);
					glm::mat4 model = object->get_model();
					glm::mat4 view = camera->get_view();
					glm::mat4 projection = camera->get_projection();

					mvp = projection * view * model;

					program->use();
					program->set_matrix("mMvp", mvp);
				}
			}

			render->draw_objects(objects);

			// Guis
			gui->debug();
			gui->end();

			input_manager->buffers_events();
		}

		for (auto& object : objects)
			render->remove_object(object);

		gui->clear();
	}

	void System::add_object(Object* obj)
	{
		objects.push_back(obj);
	}

	std::vector<Object*>* System::get_objects()
	{
		return &objects;
	}

	Camera* System::get_camera()
	{
		return camera;
	}

	void System::set_camera(Camera*& camera)
	{
		System::camera = camera;
	}

	Gui* System::get_gui()
	{
		return gui;
	}

	void System::set_gui(Gui*& gui)
	{
		System::gui = gui;
	}

	TimeManager* System::get_time_manager()
	{
		return time_manager;
	}

	void System::set_cursor_enabled(const bool& enabled)
	{
		System::cursor_mouse_enabled = enabled;
	}

	bool System::get_cursor_enabled()
	{
		return System::cursor_mouse_enabled;
	}

	void System::change_cursor()
	{
		System::cursor_mouse_enabled = !System::cursor_mouse_enabled;
		input_manager->set_mouse_cursor(System::cursor_mouse_enabled);
		if (System::cursor_mouse_enabled)
			camera->reset();
	}

}