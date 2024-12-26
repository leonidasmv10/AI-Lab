#pragma once
namespace API
{
	class GLTexture : public Texture
	{
	public:
		GLTexture();
		void load(const std::string& file_name) override;
		GLuint get_id() override;
		void bind() override;

	private:
		GLuint id;
	};
}
