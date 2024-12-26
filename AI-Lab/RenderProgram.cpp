#include "stdafx.h"
#include "RenderProgram.h"

namespace API
{
	void RenderProgram::set_program(std::string program_src, RenderProgramType type)
	{
	}

	void RenderProgram::link_programs()
	{
	}

	std::string RenderProgram::get_error_msg()
	{
		return std::string();
	}

	void RenderProgram::use()
	{
	}

	unsigned int RenderProgram::get_var_ui(std::string name)
	{
		return 0;
	}

	void RenderProgram::set_int(std::string location, int value)
	{
	}

	void RenderProgram::set_float(std::string location, float value)
	{
	}

	void RenderProgram::set_vec3(std::string location, const glm::vec3& vec)
	{
	}

	void RenderProgram::set_vec4(std::string location, const glm::vec4& vec)
	{
	}

	void RenderProgram::set_matrix(std::string location, const glm::mat4& matrix)
	{
	}
}