#include "stdafx.h"
#include "GLTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace API
{
	GLTexture::GLTexture()
	{
	}

	void GLTexture::load(const std::string& file_name)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(file_name.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			spdlog::info("Load texture [{}] size: {}x{}", file_name, width, height);
		}
		else
		{
			spdlog::error("Failed to load texture");
		}
		stbi_image_free(data);
	}

	GLuint GLTexture::get_id()
	{
		return id;
	}

	void GLTexture::bind()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, id);
	}
}