#include "stdafx.h"
#include "Entity.h"

namespace API
{
	Entity::Entity()
	{
		this->position = glm::vec3(0.0f, 0.0f, 0.0f);
		this->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		this->scale = glm::vec3(1.0f, 1.0f, 1.0f);
		this->model = glm::mat4(1.0f);
		this->enabled = true;
	}

	void Entity::set_position(const glm::vec3& position)
	{
		this->position = position;
	}

	void Entity::set_rotation(const glm::vec3& rotation)
	{
		this->rotation = rotation;
	}

	void Entity::set_scale(const glm::vec3& scale)
	{
		this->scale = scale;
	}

	void Entity::set_model(const glm::mat4& model)
	{
		this->model = model;
	}

	void Entity::set_enabled(const bool& disabled)
	{
		this->enabled = disabled;
	}

	glm::vec3& Entity::get_position()
	{
		return position;
	}

	glm::vec3& Entity::get_rotation()
	{
		return rotation;
	}

	glm::vec3& Entity::get_scale()
	{
		return scale;
	}

	glm::mat4& Entity::get_model()
	{
		return model;
	}

	bool& Entity::get_enabled()
	{
		return enabled;
	}

	void Entity::compute_model_matrix()
	{
	}

	void Entity::step(const float& delta_time)
	{
	}
}