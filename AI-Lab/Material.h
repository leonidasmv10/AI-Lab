#pragma once
#include "RenderProgram.h"

namespace API
{
	class Material
	{
	public:
		virtual ~Material() = default;
		virtual void load_programs();
		virtual void prepare();
		RenderProgram* get_program();
		Texture* get_texture();
		void set_texture(Texture* texture);
	protected:
		RenderProgram* program;
		Texture* texture;
	};
}

