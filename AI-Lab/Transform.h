#pragma once

namespace Engine
{
	class Transform : public Component
	{
		CLASS_DECLARATION(Transform)
	public:
		Transform();
		Math::Vector3 position;
		Math::Vector3 scale;
		float rotation;

		void log();
	};
}
