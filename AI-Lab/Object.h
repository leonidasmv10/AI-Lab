#pragma once

namespace API
{
	class Object : public Entity
	{
	public:
		Object();
		virtual ~Object() = default;
		void set_meshes(std::vector<Mesh3D*>& meshes);
		std::vector<Mesh3D*> get_meshes();
		void add_mesh(Mesh3D* mesh);
		Mesh3D* get_mesh(const unsigned int &index);
		virtual void load_data_from_file(const std::string& file);
	protected:
		std::vector<Mesh3D*> meshes;
		unsigned int type;
	};
}

