#include "stdafx.h"
#include "Material.h"

namespace API
{
	void Material::load_programs()
	{
	}

	void Material::prepare()
	{
	}

	RenderProgram* Material::get_program()
	{
		return program;
	}

	Texture* Material::get_texture()
	{
		return texture;
	}

	void Material::set_texture(Texture* texture)
	{
		this->texture = texture;
	}
}