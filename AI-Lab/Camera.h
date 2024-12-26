#pragma once
namespace API
{

	class Camera : public Entity
	{
	public:
		Camera(ProjectionType projection_type, glm::vec3 position, glm::vec3 up, glm::vec3 look_at, frustrum _frustrum = {});

		void set_frustrum(const frustrum frustrum);
		void compute_projection_matrix();
		void compute_view_matrix();
		void calculate_look_at();

		virtual void step(float time_step);
		virtual void reset();

		glm::mat4 get_projection();
		glm::mat4 get_view();
		frustrum get_frustrum();
		glm::vec3 get_look_at();
		glm::vec3 get_up();

	private:

		glm::mat4 view;
		glm::mat4 projection;
		glm::vec3 look_at;
		glm::vec3 up;
		glm::vec3 pos_init;

		frustrum _frustrum;
		ProjectionType type;

	protected:
		float yaw;
		float pitch;
	};
}
