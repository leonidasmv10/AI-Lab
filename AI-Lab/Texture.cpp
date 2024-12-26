#include "stdafx.h"
#include "Texture.h"

namespace API
{
	Texture::Texture()
	{
	}

	void Texture::load(const std::string& file_name)
	{
	}

	GLuint Texture::get_id()
	{
		return GLuint();
	}

	void Texture::bind()
	{
	}

	glm::ivec2 Texture::get_size()
	{
		return glm::ivec2(width, height);
	}
}