#include "stdafx.h"
#include "GLSLShader.h"

namespace API
{
	GLSLShader::GLSLShader()
	{
		program_id = glCreateProgram();
	}

	void GLSLShader::set_program(std::string program_src, RenderProgramType type)
	{
		shaders_code[type] = read_file(program_src);
		programs.insert({ type, GLuint{} });
		spdlog::info("Load shader [{}]", program_src);
	}

	void GLSLShader::link_programs()
	{
		use();
		compile();

		for (auto it = programs.begin(); it != programs.end(); ++it)
			glAttachShader(program_id, it->second);

		glLinkProgram(program_id);
		check_shader_error(program_id);
		setup_shader_var_list();

		auto msg = get_error_msg();
		if (!msg.empty())
			spdlog::error("class GLSLShader\n{}\n", msg);

	}

	std::string GLSLShader::get_error_msg()
	{
		return error_msgs;
	}

	void GLSLShader::use()
	{
		glUseProgram(program_id);
	}

	unsigned int GLSLShader::get_var_ui(std::string name)
	{
		return program_var_list[name];
	}

	void GLSLShader::set_int(std::string location, int value)
	{
		glUniform1i(glGetUniformLocation(program_id, location.c_str()), value);
	}

	void GLSLShader::set_float(std::string location, float value)
	{
		glUniform1f(glGetUniformLocation(program_id, location.c_str()), value);
	}

	void GLSLShader::set_vec3(std::string location, const glm::vec3& vec)
	{
		glUniform3fv(glGetUniformLocation(program_id, location.c_str()), 1, &vec[0]);
	}

	void GLSLShader::set_vec4(std::string location, const glm::vec4& vec)
	{
		glUniform4fv(glGetUniformLocation(program_id, location.c_str()), 1, &vec[0]);
	}

	void GLSLShader::set_matrix(std::string location, const glm::mat4& matrix)
	{
		glUniformMatrix4fv(glGetUniformLocation(program_id, location.c_str()), 1, GL_FALSE, &matrix[0][0]);
	}

	GLint GLSLShader::check_shader_error(GLint shader_id)
	{
		GLint success = 1;
		char* info_log = new char[1024];
		info_log[0] = '\0';
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader_id, 1024, nullptr, info_log);
			error_msgs += "\n" + std::string(info_log);
		}

		return success;
	}

	std::string GLSLShader::read_file(std::string file_name)
	{
		std::ifstream in_file;
		in_file.open(file_name);
		std::stringstream str_stream;
		str_stream << in_file.rdbuf();
		std::string str = str_stream.str();
		return str;
	}

	void GLSLShader::setup_shader_var_list()
	{
		int count = 0;
		int bufSize = 100;
		char* name = new char[bufSize];
		GLenum type;
		int size = 0;
		int length = 0;

		glGetProgramiv(program_id, GL_ACTIVE_ATTRIBUTES, &count);
		for (int i = 0; i < count; i++)
		{
			glGetActiveAttrib(program_id, (GLuint)i, bufSize, &length, &size, &type, name);
			program_var_list[std::string(name)] = glGetAttribLocation(program_id, name);
		}

		glGetProgramiv(program_id, GL_ACTIVE_UNIFORMS, &count);
		for (int i = 0; i < count; i++)
		{
			glGetActiveUniform(program_id, (GLuint)i, bufSize, &length, &size, &type, name);
			program_var_list[std::string(name)] = glGetUniformLocation(program_id, name);
		}

		for (auto it = program_var_list.begin(); it != program_var_list.end(); ++it)
			spdlog::info("Shader variable [{} => {}]", it->first, it->second);
	}

	void GLSLShader::compile()
	{
		for (auto it = programs.begin(); it != programs.end(); ++it)
		{
			GLint type = get_shader_to_enum(it->first);
			it->second = glCreateShader(type);
			const char* code = shaders_code[it->first].c_str();
			glShaderSource(it->second, 1, &code, NULL);
			glCompileShader(it->second);
			check_shader_error(it->second);
		}
	}

	GLenum GLSLShader::get_shader_to_enum(const RenderProgramType& type)
	{
		GLenum type_shader = 0;
		switch (type)
		{
		case RenderProgramType::VERTEX:
			type_shader = GL_VERTEX_SHADER;
			break;
		case RenderProgramType::FRAGMENT:
			type_shader = GL_FRAGMENT_SHADER;
			break;
		default:
			break;
		}
		return type_shader;
	}
}