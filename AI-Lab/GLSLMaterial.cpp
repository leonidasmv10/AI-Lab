#include "stdafx.h"
#include "GLSLMaterial.h"

namespace API
{
	GLSLMaterial::GLSLMaterial()
	{
		this->program = new GLSLShader();
		this->texture = FactoryEngine::get_new_texture();
		spdlog::info("Material created");
	}

	void GLSLMaterial::load_programs()
	{
		this->program->set_program("resources/shaders/model.vert", API::RenderProgramType::VERTEX);
		this->program->set_program("resources/shaders/model.frag", API::RenderProgramType::FRAGMENT);
	}

	void GLSLMaterial::prepare()
	{
		this->program->link_programs();
	}
}