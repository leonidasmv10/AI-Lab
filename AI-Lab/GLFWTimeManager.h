#pragma once

namespace API
{
	class GLFWTimeManager : public TimeManager
	{
	public:
		GLFWTimeManager();
		void init() override;
		void update() override;
		float get_delta_time() override;
	};

}