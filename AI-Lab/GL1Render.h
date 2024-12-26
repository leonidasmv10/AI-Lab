#pragma once

namespace API
{
	class GL1Render : public Render
	{
	public:

		GL1Render(int width, int height);
		void init() override;
		void setup_object(Object*& obj) override;
		void remove_object(Object*& obj) override;
		void draw_objects(std::vector<Object*> objs) override;
		bool is_closed() override;
		GLFWwindow* get_window();

	private:
		GLFWwindow* window;
	};
}
