#pragma once
#include "stdafx.h"

const std::size_t Engine::Component::type = std::hash<std::string>()(TO_STRING(Component));
CLASS_DEFINITION(Component, Engine::Transform)

int main(int argc, char** argv)
{
	API::FactoryEngine::set_type_graphic(API::RenderType::GL4);
	API::FactoryEngine::set_type_input(API::InputType::GLFW);
	API::FactoryEngine::set_type_texture(API::TextureType::GL);
	API::FactoryEngine::set_type_gui(API::GuiType::IMGUI);
	API::FactoryEngine::set_type_material(API::MaterialType::GLSL);

	API::System::init_system();

	Template::Box3d* box = new Template::Box3d();
	box->set_position({ 0.0f, 0.0f, 0.0f });
	box->transform->position.x = 90;
	//float angle = Math::Vector3::angle(v1, v2);
	box->transform->log();

	API::System::add_object(box);
	API::System::main_loop();

	return 0;
}