#pragma once

namespace API
{
	class GLSLMaterial : public Material
	{
	public:
		GLSLMaterial();
		void load_programs() override;
		void prepare() override;
	};

}