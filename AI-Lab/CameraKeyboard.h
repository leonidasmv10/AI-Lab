#pragma once
namespace API
{
	class CameraKeyboard : public Camera
	{
	public:
		CameraKeyboard(ProjectionType projection_type, glm::vec3 position, glm::vec3 up, glm::vec3 look_at, frustrum _frustrum = {});
		void step(float time_step) override;
		void reset() override;
		void set_speed(const float& speed);
		void set_sensitivity(const float& sensitivity);
	private:
		void rotation_in_mouse(float xoffset, float yoffset);
		void process_mouse();
		void process_keyboard(const float& time_step);
	private:
		InputManager* input;
		bool flag;
		int last_x, last_y;
		float speed, sensitivity;
	};
}
