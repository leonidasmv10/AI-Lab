#include "stdafx.h"
#include "Transform.h"

namespace Engine
{
	Transform::Transform()
	{
		position = { 0.0f, 0.0f };
		scale = { 1.0f, 1.0f };
		rotation = 0.0f;
	}

	void Transform::log()
	{
		spdlog::info("Position: ({},{})", position.x, position.y);
	}
}
