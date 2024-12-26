#pragma once
namespace API
{
	struct frustrum
	{
		float fov;
		int width;
		int height;
		float z_near;
		float z_far;

		frustrum()
		{
			fov = 0.0f;
			width = 800;
			height = 680;
			z_near = 0.01f;
			z_far = 1000.0f;
		}

		frustrum(float fov, int width, int height, float z_near, float z_far)
			: fov(fov),
			width(width),
			height(height),
			z_near(z_near),
			z_far(z_far)
		{
		}
	};
}