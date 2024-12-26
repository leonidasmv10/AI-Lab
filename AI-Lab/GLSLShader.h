#pragma once

namespace API
{
	class GLSLShader : public RenderProgram
	{
	public:

		GLSLShader();
		void set_program(std::string program_src, RenderProgramType type) override;
		void link_programs() override;
		std::string get_error_msg() override;
		void use() override;

		unsigned int get_var_ui(std::string name) override;
		void set_int(std::string location, int value) override;
		void set_float(std::string location, float value) override;
		void set_vec3(std::string location, const glm::vec3& vec) override;
		void set_vec4(std::string location, const glm::vec4& vec) override;
		void set_matrix(std::string location, const glm::mat4& matrix) override;

	private:
		GLint check_shader_error(GLint shader_id);
		std::string read_file(std::string file_name);
		void setup_shader_var_list();
		void compile();
		GLenum get_shader_to_enum(const RenderProgramType& type);

	public:
		std::map<std::string, GLuint> program_var_list;

	private:
		std::string error_msgs;
		GLuint program_id;

		std::map<RenderProgramType, GLuint> programs;
		std::map<RenderProgramType, std::string> shaders_code;
	};

}