#include "stdafx.h"
#include "GL4Render.h"

namespace API
{
	GL4Render::GL4Render(int width, int height)
	{
		this->set_width(width);
		this->set_height(height);
	}

	void GL4Render::init()
	{
		assert(glfwInit());

#ifdef __APPLE__
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#endif

		this->window = glfwCreateWindow(width, height, "AI Lab",
			nullptr, nullptr);

		glfwMakeContextCurrent(window);
		glEnable(GL_DEPTH_TEST);
	}

	void GL4Render::setup_object(Object*& obj)
	{
		for (int i = 0; i < obj->get_meshes().size(); i++)
		{
			Mesh3D* mesh = obj->get_mesh(i);
			RenderProgram* program = mesh->get_material()->get_program();
			std::vector<vertex>& obj_vertex = *mesh->get_vertex_list();
			std::vector<unsigned int>& obj_indices = *mesh->get_list_triangle_idx();

			bo_ids_t vbo{};
			glGenVertexArrays(1, &vbo.id);

			glGenBuffers(1, &vbo.vbo);
			glGenBuffers(1, &vbo.idxbo);

			glBindVertexArray(vbo.id);

			glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * obj_vertex.size(), obj_vertex.data(), GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo.idxbo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * obj_indices.size(), obj_indices.data(), GL_STATIC_DRAW);

			glVertexAttribPointer(program->get_var_ui("vPos"), 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, position));
			glEnableVertexAttribArray(program->get_var_ui("vPos"));

			glVertexAttribPointer(program->get_var_ui("vTexCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, v_texture));
			glEnableVertexAttribArray(program->get_var_ui("vTexCoord"));

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			buffer_object_list[mesh->get_mesh_id()] = vbo;

			program->use();
			program->set_matrix("mMvp", glm::mat4(1.0f));
			program->set_int("mTexture", 0);
		}
	}

	void GL4Render::remove_object(Object*& obj)
	{
		bo_ids_t vbo;
		for (int i = 0; i < obj->get_meshes().size(); i++)
		{
			vbo = buffer_object_list[obj->get_mesh(i)->get_mesh_id()];
			glDeleteVertexArrays(1, &vbo.id);
			glDeleteBuffers(1, &vbo.vbo);
			glDeleteBuffers(1, &vbo.idxbo);
		}
	}

	void GL4Render::draw_objects(std::vector<Object*> objs)
	{	
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			for (int i = 0; i < objs.size(); i++)
			{
				for (int j = 0; j < objs[i]->get_meshes().size(); j++)
				{
					Mesh3D* mesh = objs[i]->get_mesh(j);
					mesh->get_material()->get_texture()->bind();
					mesh->get_material()->get_program()->use();
					glBindVertexArray(get_id_buffer(objs[i]->get_mesh(j)));
					glDrawElements(GL_TRIANGLES, mesh->get_list_triangle_idx()->size(), GL_UNSIGNED_INT, nullptr);
				}
			}
		}
	}

	bool GL4Render::is_closed()
	{
		return glfwWindowShouldClose(window);
	}

	GLFWwindow* GL4Render::get_window()
	{
		return window;
	}

	GLuint GL4Render::get_id_buffer(Mesh3D* mesh)
	{
		auto it = buffer_object_list.find(mesh->get_mesh_id());
		if (it != buffer_object_list.end())
			return it->second.id;
		return 0;
	}
}