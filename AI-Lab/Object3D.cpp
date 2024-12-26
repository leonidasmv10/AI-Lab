#include "stdafx.h"
#include "Object3D.h"

namespace API
{
	Object3D::Object3D()
	{
		spdlog::info("Object3D created");
	}

	void Object3D::load_data_from_file(const std::string& file)
	{
		Object::load_data_from_file(file);
	}

	void Object3D::compute_model_matrix()
	{
		Object::compute_model_matrix();
		glm::mat4 matrix = glm::mat4(1.0f);
		matrix = glm::translate(matrix, position);
		matrix = glm::rotate(matrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		matrix = glm::rotate(matrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		matrix = glm::rotate(matrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		matrix = glm::scale(matrix, scale);
		this->model = matrix;
	}
}