#include "stdafx.h"
#include "Mesh3D.h"

namespace API
{
	GLuint Mesh3D::mesh_id = 0;

	Mesh3D::Mesh3D()
	{
		list_vertex = new std::vector<vertex>();
		v_triangle_idx_list = new std::vector<unsigned int>();
		Mesh3D::mesh_id++;
		id = Mesh3D::mesh_id;

		material = FactoryEngine::get_new_material();
		material->load_programs();
		material->prepare();

		spdlog::info("Load mesh ID[{}]", id);
	}

	GLuint Mesh3D::get_mesh_id()
	{
		return id;
	}

	void Mesh3D::add_vertex(vertex v)
	{
		list_vertex->push_back(v);
	}

	std::vector<vertex>* Mesh3D::get_vertex_list()
	{
		return list_vertex;
	}

	void Mesh3D::set_material(Material*& material)
	{
		this->material = material;
	}

	void Mesh3D::set_list_triangle(std::vector<unsigned int>*& list)
	{
		this->v_triangle_idx_list = list;
	}

	void Mesh3D::load_texture(const std::string& file_name)
	{
		material->get_texture()->load(file_name);
	}

	Material* Mesh3D::get_material()
	{
		return material;
	}

	std::vector<unsigned int>* Mesh3D::get_list_triangle_idx()
	{
		return v_triangle_idx_list;
	}

	void Mesh3D::add_triangle(unsigned int v_id1, unsigned int v_id2, unsigned int v_id3)
	{
		v_triangle_idx_list->push_back(v_id1);
		v_triangle_idx_list->push_back(v_id2);
		v_triangle_idx_list->push_back(v_id3);
	}

}