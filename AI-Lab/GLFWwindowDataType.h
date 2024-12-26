#pragma once

namespace API
{
	inline GLFWwindow* RenderTypeToGLFWwindow(const RenderType& type)
	{
		switch (type)
		{
		case GL1:
			return static_cast<GL1Render*>(FactoryEngine::get_render())->get_window();
		case GL4:
			return static_cast<GL4Render*>(FactoryEngine::get_render())->get_window();
		default:
			break;
		}
		return nullptr;
	}
}
