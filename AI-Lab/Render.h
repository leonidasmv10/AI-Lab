#pragma once

namespace API
{
	class Render
	{
	public:
		virtual void init();
		virtual void setup_object(Object*& obj);
		virtual void remove_object(Object*& obj);
		virtual void draw_objects(std::vector<Object*> objs);
		virtual bool is_closed();

		int get_width();
		int get_height();

		void set_width(const int& width);
		void set_height(const int& height);

	protected:
		int width;
		int height;
	};
}