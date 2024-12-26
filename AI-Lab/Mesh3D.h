#pragma once

namespace API
{
	class Mesh3D
	{
	public:
		Mesh3D();
		GLuint get_mesh_id();
		void add_vertex(vertex v);
		std::vector<vertex>* get_vertex_list();

		void set_material(Material*& material);
		void set_list_triangle(std::vector<unsigned int>*& list);
		void load_texture(const std::string &file_name);

		Material* get_material();
		std::vector<unsigned int>* get_list_triangle_idx();

		void add_triangle(unsigned int v_id1, unsigned int v_id2, unsigned int v_id3);

	private:
		static GLuint mesh_id;
		GLuint id;
		glm::vec3 color_rgb;
		std::vector<vertex>* list_vertex;

		Material* material;
		std::vector<unsigned int>* v_triangle_idx_list;
	};
}
