#pragma once
namespace Template
{

	class Box3d : public Engine::CoreBehaviour, public API::Object3D
	{
	public:
		Box3d();
		void compute_model_matrix() override;
		void step(const float& delta_time) override;
	};

}
