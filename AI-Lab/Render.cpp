#include "stdafx.h"
#include "Render.h"

namespace API
{
	void Render::init()
	{
	}

	void Render::setup_object(Object*& obj)
	{
	}

	void Render::remove_object(Object*& obj)
	{
	}

	void Render::draw_objects(std::vector<Object*> objs)
	{
		
	}

	bool Render::is_closed()
	{
		return false;
	}

	int Render::get_width()
	{
		return width;
	}

	int Render::get_height()
	{
		return height;
	}

	void Render::set_width(const int& width)
	{
		this->width = width;
	}

	void Render::set_height(const int& height)
	{
		this->height = height;
	}

}