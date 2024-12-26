#include "stdafx.h"
#include "CameraKeyboard.h"

namespace API
{
	CameraKeyboard::CameraKeyboard(ProjectionType projection_type, glm::vec3 position, glm::vec3 up, glm::vec3 look_at, frustrum _frustrum) :
		Camera(projection_type, position, up, look_at, _frustrum)
	{
		this->input = FactoryEngine::get_input_manager();
		this->flag = true;
		this->speed = 12.5f;
		this->sensitivity = 0.15f;
	}

	void CameraKeyboard::rotation_in_mouse(float xoffset, float yoffset)
	{
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		calculate_look_at();
	}

	void CameraKeyboard::process_mouse()
	{
		const float x_pos = static_cast<float>(input->get_mouse_pos().first);
		const float y_pos = static_cast<float>(input->get_mouse_pos().second);

		if (flag)
		{
			last_x = x_pos;
			last_y = y_pos;
			flag = false;
		}

		const float x_offset = x_pos - last_x;
		const float y_offset = last_y - y_pos;

		last_x = x_pos;
		last_y = y_pos;

		rotation_in_mouse(x_offset, y_offset);
	}

	void CameraKeyboard::process_keyboard(const float& time_step)
	{
		const float camera_speed = speed * time_step;
		if (input->is_pressed('w'))
			set_position(get_position() + camera_speed * get_look_at());
		if (input->is_pressed('s'))
			set_position(get_position() - camera_speed * get_look_at());
		if (input->is_pressed('a'))
			set_position(get_position() - glm::normalize(glm::cross(get_look_at(), get_up())) * camera_speed);
		if (input->is_pressed('d'))
			set_position(get_position() + glm::normalize(glm::cross(get_look_at(), get_up())) * camera_speed);
	}

	void CameraKeyboard::step(float time_step)
	{
		Camera::step(time_step);
		if (!System::get_cursor_enabled())
		{
			this->process_mouse();
			this->process_keyboard(time_step);
		}
	}

	void CameraKeyboard::reset()
	{
		this->flag = true;
	}

	void CameraKeyboard::set_speed(const float& speed)
	{
		this->speed = speed;
	}

	void CameraKeyboard::set_sensitivity(const float& sensitivity)
	{
		this->sensitivity = sensitivity;
	}
}