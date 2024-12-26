#include "stdafx.h"
#include "GL1Render.h"

namespace API
{
	GL1Render::GL1Render(int width, int height)
	{
		this->set_width(width);
		this->set_height(height);
	}

	void GL1Render::init()
	{
		assert(glfwInit());

#ifdef __APPLE__
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#endif

		this->window = glfwCreateWindow(width, height, "API3D",
			nullptr, nullptr);

		glfwMakeContextCurrent(window);
	}

	void GL1Render::setup_object(Object*& obj)
	{

	}

	void GL1Render::remove_object(Object*& obj)
	{
	}

	void GL1Render::draw_objects(std::vector<Object*> objs)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		{
			glColor3f(0.0f, 1.0f, 0.0f);
			for (int i = 0; i < objs.size(); i++)
			{
				for (int j = 0; j < objs[i]->get_meshes().size(); j++)
				{
					std::vector<API::vertex> v = *objs[i]->get_mesh(j)->get_vertex_list();
					for (int k = 0; k < v.size(); k++)
					{
						v[k].position = objs[i]->get_model() * v[k].position;
						glVertex3f(v[k].position.x, v[k].position.y, v[k].position.z);
					}
				}
			}
		}
		glEnd();
	}

	bool GL1Render::is_closed()
	{
		return glfwWindowShouldClose(window);
	}

	GLFWwindow* GL1Render::get_window()
	{
		return window;
	}
}