#pragma once
#include "stdafx.h"

class CubeTex : public API::Object3D
{
public:
	CubeTex();
	void compute_model_matrix() override;
	void step(const float& delta_time) override;
};

int main(int argc, char** argv)
{
	API::FactoryEngine::set_type_graphic(API::RenderType::GL4);
	API::FactoryEngine::set_type_input(API::InputType::GLFW);
	API::FactoryEngine::set_type_texture(API::TextureType::GL);
	API::FactoryEngine::set_type_gui(API::GuiType::IMGUI);
	API::FactoryEngine::set_type_material(API::MaterialType::GLSL);

	API::System::init_system();

	CubeTex* cube = new CubeTex();
	cube->set_position({ 0.0f, 0.0f, 0.0f });

	API::System::add_object(cube);
	API::System::main_loop();

	return 0;
}

CubeTex::CubeTex()
{
	// Create mesh 1

	API::Mesh3D* mesh_1 = new API::Mesh3D();

	mesh_1->add_vertex({ glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
	mesh_1->add_vertex({ glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

	mesh_1->add_triangle(0, 1, 3);
	mesh_1->add_triangle(1, 2, 3);

	mesh_1->add_vertex({ glm::vec4(1.0f, 1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
	mesh_1->add_vertex({ glm::vec4(1.0f, -1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

	mesh_1->add_triangle(4, 5, 7);
	mesh_1->add_triangle(5, 6, 7);

	mesh_1->add_vertex({ glm::vec4(1.0f, 1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
	mesh_1->add_vertex({ glm::vec4(1.0f, -1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

	mesh_1->add_triangle(8, 9, 11);
	mesh_1->add_triangle(9, 10, 11);

	mesh_1->add_vertex({ glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
	mesh_1->add_vertex({ glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

	mesh_1->add_triangle(12, 13, 15);
	mesh_1->add_triangle(13, 14, 15);

	mesh_1->load_texture("resources/textures/front.png");

	// Create mesh 2

	API::Mesh3D* mesh_2 = new API::Mesh3D();

	mesh_2->add_vertex({ glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
	mesh_2->add_vertex({ glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
	mesh_2->add_vertex({ glm::vec4(1.0f, 1.0f, -1.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
	mesh_2->add_vertex({ glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

	mesh_2->add_triangle(0, 1, 3);
	mesh_2->add_triangle(1, 2, 3);

	mesh_2->add_vertex({ glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) });
	mesh_2->add_vertex({ glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 0.0f) });
	mesh_2->add_vertex({ glm::vec4(1.0f, -1.0f, -1.0f, 1.0f), glm::vec2(0.0f, 0.0f) });
	mesh_2->add_vertex({ glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) });

	mesh_2->add_triangle(4, 5, 7);
	mesh_2->add_triangle(5, 6, 7);

	mesh_2->load_texture("resources/textures/top.png");

	// Add Mesh

	this->add_mesh(mesh_1);
	this->add_mesh(mesh_2);
}

void CubeTex::compute_model_matrix()
{
	API::Object3D::compute_model_matrix();
}

void CubeTex::step(const float& delta_time)
{
	this->compute_model_matrix();
	rotation.y += delta_time * 2.0f;
	scale = glm::vec3(0.25f);
}