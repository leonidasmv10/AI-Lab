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

		this->yaw = 70.0f;
		this->pitch = -20.0f;

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
			projection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 1000.0f);
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
			/*if (System::get_cursor_enabled())
			{
				float time = System::get_time_manager()->get_time();
				float radius = 5.0f;
				float x = static_cast<float>(sin(time) * radius);
				float z = static_cast<float>(cos(time) * radius);
				view = glm::lookAt(glm::vec3(x, 1.0f, z), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			}
			else*/
			{
				view = glm::lookAt(position, position + look_at, up);
			}
			break;
		case API::ORTHO:
			view = glm::lookAt(position, look_at, up);
			break;
		default:
			break;
		}
	}

	void Camera::calculate_look_at()
	{
		glm::vec3 look{};

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
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

	void Camera::set_view(glm::mat4 view)
	{
		this->view = view;
	}

	void Camera::set_projection(glm::mat4 projection)
	{
		this->projection = projection;
	}

	void Camera::set_look_at(glm::vec3 look_at)
	{
		this->look_at = look_at;
	}

	ProjectionType& Camera::get_type()
	{
		return type;
	}

	void Camera::set_type(ProjectionType type)
	{
		this->type = type;
	}
}