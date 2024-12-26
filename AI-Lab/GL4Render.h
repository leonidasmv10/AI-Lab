#pragma once

namespace API
{
	typedef struct bo_ids_t
	{
		unsigned int id;
		unsigned int vbo;
		unsigned int idxbo;
	} bo_ids_t;

	class GL4Render : public Render
	{
	public:
		GL4Render(int width, int height);
		void init() override;
		void setup_object(Object*& obj) override;
		void remove_object(Object*& obj) override;
		void draw_objects(std::vector<Object*> objs) override;
		bool is_closed() override;
		GLFWwindow* get_window();
	private:
		GLuint get_id_buffer(Mesh3D* mesh);
	private:
		GLFWwindow* window;
		std::map<GLint, bo_ids_t> buffer_object_list;

	};
}

