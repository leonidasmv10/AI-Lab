#include "stdafx.h"
#include "GLFWImGui.h"
namespace API
{
	GLFWImGui::GLFWImGui()
	{
	}

	GLFWImGui::~GLFWImGui()
	{

	}

	void GLFWImGui::begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void GLFWImGui::end()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		const ImGuiIO& io = ImGui::GetIO();
		(void)io;

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void GLFWImGui::init()
	{
		this->window = API::RenderTypeToGLFWwindow(FactoryEngine::selected_graphics_backend);
		const char* glsl_version = "#version 330";

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.ConfigFlags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;

		ImGui::StyleColorsDark();

		window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
			ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);

		API::setup_style();
	}

	void GLFWImGui::step(const float time_step)
	{

	}

	void GLFWImGui::clear()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	bool GLFWImGui::set_input_int(const char* id, const char* label, int& value, bool new_line, std::string description)
	{
		this->begin_flag_gui(id, new_line, description);

		if (ImGui::InputInt(label, &value)) {
			flag = true;
		}

		return this->end_flag_gui();
	}

	bool GLFWImGui::set_color_3f(const char* id, const char* label, glm::vec3& value, bool new_line, std::string description)
	{
		this->begin_flag_gui(id, new_line, description);

		if (ImGui::ColorEdit3(label, glm::value_ptr(value))) {
			flag = true;
		}

		return this->end_flag_gui();
	}

	bool GLFWImGui::set_drag_float_3f(const char* id, const char* label, glm::vec3& value, bool new_line, std::string description)
	{
		this->begin_flag_gui(id, new_line, description);

		if (ImGui::DragFloat3(label, glm::value_ptr(value))) {
			flag = true;
		}

		return this->end_flag_gui();
	}

	bool GLFWImGui::button(const char* id, const char* label, bool new_line, std::string description)
	{
		this->begin_flag_gui(id, new_line, description);

		if (ImGui::Button(label)) {
			flag = true;
		}

		return this->end_flag_gui();
	}

	void GLFWImGui::debug()
	{
		ImGui::Begin("API");

		ImGui::NewLine();
		static bool change_swqp_interval = true;
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		if (ImGui::Button("Swap Interval")) glfwSwapInterval(change_swqp_interval = !change_swqp_interval);
		ImGui::NewLine();

		if (ImGui::CollapsingHeader("Camera"))
		{
			Camera* camera = System::get_camera();
			const char* items[] = { "PERSPECTIVE", "ORTHO" };
			/*int item_current = camera->get_type();

			if (ImGui::Combo("Projection", &item_current, items, IM_ARRAYSIZE(items)))
			{
				switch (item_current)
				{
				case 0:
					camera->set_type(PERSPECTIVE);
					break;
				case 1:
					camera->set_type(ORTHO);
					break;
				default:
					break;
				}
			}

			ImGui::DragFloat3("Position", glm::value_ptr(camera->get_position()), 0.05f);*/
		}

		if (ImGui::CollapsingHeader("Objects"))
		{
			//std::vector< Object*> objs = *System::get_objects();
			//int objects_size = objs.size();
			//ImGui::Text("Objects: %i", objects_size);

			//for (int i = 0; i < objects_size; i++)
			//{
			//	Object* obj = objs[i];
			//	if (ImGui::TreeNode(("Object[" + std::to_string(i) + "]: " + obj->get_file_name()).c_str()))
			//	{
			//		// Meshes
			//		object_data(obj, i);
			//		ImGui::TreePop();
			//		ImGui::Spacing();
			//	}
			//}
		}

		if (ImGui::CollapsingHeader("Lights"))
		{
			/*std::vector<Light*> lights = *System::get_lights();
			int lights_size = lights.size();

			ImGui::Text("Lights: %i", lights_size);

			int it_light_direction = 0;
			int it_light_point = 0;

			for (int it_light = 0; it_light < lights.size(); it_light++)
			{
				Light* light = System::get_light(it_light);
				if (light->get_type() == LightType::DIRECTIONAL)
				{
					std::string str_light_direction = std::to_string(it_light_direction);
					if (ImGui::TreeNode(("Direction Light " + std::to_string(it_light_direction + 1)).c_str()))
					{
						if (ImGui::Checkbox(("lights.d[" + str_light_direction + "].enabled").c_str(), &light->get_enabled())) { flag = true; }

						if (ImGui::DragFloat3(("lights.d[" + str_light_direction + "].direction").c_str(), glm::value_ptr(light->get_direction()), 0.05f)) { flag = true; }
						if (ImGui::ColorEdit3(("lights.d[" + str_light_direction + "].ambient").c_str(), glm::value_ptr(light->get_ambient()))) { flag = true; }
						if (ImGui::ColorEdit3(("lights.d[" + str_light_direction + "].diffuse").c_str(), glm::value_ptr(light->get_diffuse()))) { flag = true; }
						if (ImGui::ColorEdit3(("lights.d[" + str_light_direction + "].specular").c_str(), glm::value_ptr(light->get_specular()))) { flag = true; }
						ImGui::TreePop();
						ImGui::Spacing();
					}

					it_light_direction++;
				}
				else if (light->get_type() == LightType::POINT)
				{
					std::string str_light_point = std::to_string(it_light_point);

					if (ImGui::TreeNode(("Point Light " + std::to_string(it_light_point + 1)).c_str()))
					{
						if (ImGui::Checkbox(("lights.p[" + str_light_point + "].enabled").c_str(), &light->get_enabled())) { flag = true; }

						if (ImGui::DragFloat3(("lights.p[" + str_light_point + "].position").c_str(), glm::value_ptr(light->get_position()), 0.05f)) { flag = true; }
						if (ImGui::ColorEdit3(("lights.p[" + str_light_point + "].ambient").c_str(), glm::value_ptr(light->get_ambient()))) { flag = true; }
						if (ImGui::ColorEdit3(("lights.p[" + str_light_point + "].diffuse").c_str(), glm::value_ptr(light->get_diffuse()))) { flag = true; }
						if (ImGui::ColorEdit3(("lights.p[" + str_light_point + "].specular").c_str(), glm::value_ptr(light->get_specular()))) { flag = true; }

						if (ImGui::DragFloat(("lights.p[" + str_light_point + "].constant").c_str(), &light->get_constant_attenuation(), 0.001f, 0.0f, 1.0f)) { flag = true; }
						if (ImGui::DragFloat(("lights.p[" + str_light_point + "].linear").c_str(), &light->get_linear_attenuation(), 0.001f, 0.0f, 1.0f)) { flag = true; }
						if (ImGui::DragFloat(("lights.p[" + str_light_point + "].quadratic").c_str(), &light->get_quadratic_attenuation(), 0.001f, 0.0f, 1.0f)) { flag = true; }
						ImGui::TreePop();
						ImGui::Spacing();
					}

					it_light_point++;
				}
			}*/

		}

		if (ImGui::CollapsingHeader("Emitters"))
		{
			/*std::vector<Emitter*> emitters = *System::get_emitters();
			int emitters_size = emitters.size();

			ImGui::Text("Emitters: %i", emitters_size);

			for (int i = 0; i < emitters_size; i++)
			{
				Emitter* emitter = emitters[i];
				Particle* model = emitter->get_model_particle();

				if (ImGui::TreeNode(("Emitter[" + std::to_string(i) + "]: " + model->get_file_name()).c_str()))
				{
					std::list<Particle*> particles = *emitter->get_particles();
					int particles_size = particles.size();
					int it_emitter = 0;

					ImGui::Separator();
					ImGui::Checkbox(("emitters[" + std::to_string(i) + "].enabled").c_str(), &emitter->get_enabled());
					if (ImGui::Checkbox(("emitters[" + std::to_string(i) + "].instanced").c_str(), &emitter->get_instancing()))
					{
						emitter->set_instancing(emitter->get_instancing());
					}
					ImGui::Separator();

					ImGui::DragInt(("emitters[" + std::to_string(i) + "].spawn_rate").c_str(), &emitter->get_spawn_rate(), 0.10f, 0, 100);
					ImGui::Text(("emitters[" + std::to_string(i) + "].particle_accum: %f").c_str(), emitter->get_particle_accum());

					ImGui::Checkbox(("emitters[" + std::to_string(i) + "].is_emit").c_str(), &emitter->is_emitting());
					ImGui::Separator();

					if (ImGui::TreeNode(("Particle")))
					{
						object_data(model, i);

						if (model->is_instance())
							ImGui::Text("particles in scene: %i", model->get_count_instance());
						else
							ImGui::Text("particles in scene: %i", particles_size);

						ImGui::TreePop();
						ImGui::Spacing();
					}

					ImGui::TreePop();
					ImGui::Spacing();
				}
			}*/
		}

		ImGui::End();
	}

	void GLFWImGui::begin_flag_gui(const char* id, bool new_line, std::string description)
	{
		flag = false;
		ImGui::Begin(id);

		if (new_line)
			ImGui::NewLine();

		if (!description.empty()) {
			ImGui::Text(description.c_str());
		}
	}

	bool GLFWImGui::end_flag_gui()
	{
		ImGui::End();
		return flag;
	}

	inline void GLFWImGui::object_data(Object* obj, int index)
	{
		std::vector<Mesh3D*> meshes = obj->get_meshes();
		int meshes_size = meshes.size();

		ImGui::Separator();
		/*ImGui::Checkbox(("objects[" + std::to_string(index) + "].enabled").c_str(), &obj->get_enabled());
		ImGui::Text("Instance: %s", obj->is_instance() ? "true" : "false");*/
		ImGui::Separator();
		ImGui::Text("Meshes: %i", meshes_size);

		for (int it_mesh = 0; it_mesh < meshes_size; it_mesh++)
		{
			Mesh3D* mesh = meshes[it_mesh];
			Material* material = mesh->get_material();
			RenderProgram* program = material->get_program();
			Texture* texture = material->get_texture();

			std::vector<vertex>& obj_vertex = *mesh->get_vertex_list();
			std::vector<unsigned int>& obj_indices = *mesh->get_list_triangle_idx();

			if (ImGui::TreeNode(("Mesh " + std::to_string(it_mesh)).c_str()))
			{
				//ImGui::Separator();
				//ImGui::Checkbox(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].enabled").c_str(), &mesh->get_enabled());
				//ImGui::Separator();
				//ImGui::Text("ID: %i", mesh->get_mesh_id());

				//ImGui::Text("Vertexs: %i", obj_vertex.size());
				//ImGui::Text("Indices: %i", obj_indices.size());

				//bool has_uv = obj_vertex[0].v_texture.x != -2 || obj_vertex[0].v_texture.y != -2;

				//bool has_normals = obj_vertex[0].normal.x != -2 || obj_vertex[0].normal.y != -2
				//	|| obj_vertex[0].normal.z != -2 || obj_vertex[0].normal.w != -2;

				//bool has_tangents = obj_vertex[0].tangent.x != 0 || obj_vertex[0].tangent.y != 0
				//	|| obj_vertex[0].tangent.z != 0 || obj_vertex[0].tangent.w != 0;

				//ImGui::Text("Normals: %s", has_normals ? "true" : "false");
				//ImGui::Text("Tangents: %s", has_tangents ? "true" : "false");
				//ImGui::Separator();

				//// Textures
				//ImGui::Text("Texture UV: %s", has_uv ? "true" : "false");
				//ImGui::Text("Texture Name: %s", texture->get_file_name().c_str());
				//ImGui::Text("Texture Size: %ix%i", texture->get_size().x, texture->get_size().y);
				//ImGui::Separator();

				//// Materials

				//ImGui::Text("Material");

				//const char* items[] = { "SOLID", "ALPHA", "ADD", "MULTIPLY" };
				//int item_current = material->get_blend_type();

				//if (ImGui::Combo(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].material.blend_type").c_str(), &item_current, items, IM_ARRAYSIZE(items)))
				//{
				//	switch (item_current)
				//	{
				//	case 0:
				//		material->set_blend_type(SOLID);
				//		break;
				//	case 1:
				//		material->set_blend_type(ALPHA);
				//		break;
				//	case 2:
				//		material->set_blend_type(ADD);
				//		break;
				//	case 3:
				//		material->set_blend_type(MULTIPLY);
				//		break;
				//	default:
				//		break;
				//	}
				//}

				//glm::vec3 color = material->get_color();
				//if (item_current == 1)
				//	ImGui::DragFloat(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].material.alpha").c_str(), &material->get_alpha(), 0.01f, 0, 1);
				//ImGui::ColorEdit3(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].material.color").c_str(), glm::value_ptr(color));

				//ImGui::Checkbox(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].material.lighting").c_str(), &material->get_lighting());
				//ImGui::Checkbox(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].material.culling").c_str(), &material->get_culling());
				//ImGui::Checkbox(("obj[" + std::to_string(index) + "].mesh[" + std::to_string(it_mesh) + "].material.depth_write").c_str(), &material->get_depth_write());

				//ImGui::Text("Shininess: %i", material->get_shininess());
				//ImGui::TreePop();
				//ImGui::Spacing();
			}
		}
	}

}