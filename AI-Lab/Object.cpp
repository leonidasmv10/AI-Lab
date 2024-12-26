#include "stdafx.h"
#include "Object.h"

namespace API
{
	Object::Object()
	{
		
	}

	void Object::set_meshes(std::vector<Mesh3D*>& meshes)
	{
		this->meshes = meshes;
	}

	std::vector<Mesh3D*> Object::get_meshes()
	{
		return this->meshes;
	}

	void Object::add_mesh(Mesh3D* mesh)
	{
		this->meshes.push_back(mesh);
	}

	Mesh3D* Object::get_mesh(const unsigned int& index)
	{
		return this->meshes[index];
	}

	void Object::load_data_from_file(const std::string& file)
	{
	}
}

