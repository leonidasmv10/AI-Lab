#include "stdafx.h"
#include "Camera.h"
namespace API
{
	Camera::Camera(ProjectionType projection_type, glm::vec3 position, glm::vec3 up, glm::vec3 look_at, frustrum _frustrum)
	{
		this->position = position;
		this->up = up;
		this->look_at = look_at;
		this->type = projection_type;
		this->_frustrum = _frustrum;
		this->pos_init = position;

		this->yaw = 90.0f;
		this->pitch = 0.0f;

		this->compute_projection_matrix();
		this->compute_view_matrix();
		this->calculate_look_at();
	}

	void Camera::set_frustrum(const frustrum frustrum)
	{
		this->_frustrum = frustrum;
	}

	void Camera::compute_projection_matrix()
	{
		switch (type)
		{
		case API::PERSPECTIVE:
			projection = glm::perspective(glm::radians(_frustrum.fov),
				(float)_frustrum.width / (float)_frustrum.height, _frustrum.z_near,
				_frustrum.z_far);
			break;
		case API::ORTHO:
			projection = glm::ortho(0.0f, (float)_frustrum.width, 0.0f, (float)_frustrum.height, _frustrum.z_near, _frustrum.z_far);
			break;
		default:
			break;
		}
	}

	void Camera::compute_view_matrix()
	{
		switch (type)
		{
		case API::PERSPECTIVE:
			if (!System::get_cursor_enabled())
			{
				view = glm::lookAt(position, position + look_at, up);
			}
			else
			{
				position = pos_init;
				view = glm::lookAt(position, { 0.0f, 0.0f, 0.0f }, up);
				position = { pos_init.x * -1.0f, pos_init.y - 1.0f, pos_init.z * -1.0f };
				this->yaw = 90.0f;
				this->pitch = 0.0f;
				calculate_look_at();
			}
			break;
		case API::ORTHO:
			view = glm::lookAt({ 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, up);
			break;
		default:
			break;
		}
	}

	void Camera::calculate_look_at()
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 look{};
		look.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		look.y = sin(glm::radians(pitch));
		look.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		look = glm::normalize(look);

		this->look_at = look;
	}

	void Camera::step(float time_step)
	{
		this->compute_projection_matrix();
		this->compute_view_matrix();
	}

	void Camera::reset()
	{

	}

	glm::mat4 Camera::get_projection()
	{
		return projection;
	}

	glm::mat4 Camera::get_view()
	{
		return view;
	}

	frustrum Camera::get_frustrum()
	{
		return _frustrum;
	}

	glm::vec3 Camera::get_look_at()
	{
		return look_at;
	}

	glm::vec3 Camera::get_up()
	{
		return up;
	}
}