#pragma once
namespace API
{
	class Texture
	{
	public:
		Texture();
		virtual ~Texture() = default;
		virtual void load(const std::string& file_name);
		virtual GLuint get_id();
		virtual void bind();
		glm::ivec2 get_size();
	protected:
		int width, height;
	};
}
