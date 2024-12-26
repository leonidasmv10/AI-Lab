#pragma once

namespace API
{
	typedef enum class RenderProgramType {
		VERTEX = 0,
		FRAGMENT = 1
	} RenderProgramType;

	class RenderProgram
	{
	public:
		virtual ~RenderProgram() = default;
		virtual void set_program(std::string program_src, RenderProgramType type);
		virtual void link_programs();
		virtual std::string get_error_msg();
		virtual void use();

		virtual unsigned int get_var_ui(std::string name);
		virtual void set_int(std::string location, int value);
		virtual void set_float(std::string location, float value);
		virtual void set_vec3(std::string location, const glm::vec3 &vec);
		virtual void set_vec4(std::string location, const glm::vec4 &vec);
		virtual void set_matrix(std::string location, const glm::mat4 &matrix);	
	};
}
