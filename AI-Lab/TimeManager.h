#pragma once
namespace API
{
	class TimeManager
	{
	public:
		virtual ~TimeManager() = default;
		virtual void init();
		virtual void update();
		virtual float get_delta_time();
		virtual float get_time();
	protected:
		float new_time;
		float delta_time;
		float last_time;
	};
}
