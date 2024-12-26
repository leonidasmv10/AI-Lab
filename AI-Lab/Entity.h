#pragma once

namespace API
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity() = default;

		void set_position(const glm::vec3& position);
		void set_rotation(const glm::vec3& rotation);
		void set_scale(const glm::vec3& scale);
		void set_model(const glm::mat4& model);
		void set_enabled(const bool& enabled);

		glm::vec3& get_position();
		glm::vec3& get_rotation();
		glm::vec3& get_scale();
		glm::mat4& get_model();
		bool& get_enabled();

		virtual void compute_model_matrix();
		virtual void step(const float& delta_time);

	protected:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::mat4 model;

		bool enabled;
	};
}