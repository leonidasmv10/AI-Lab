#pragma once

namespace API
{
	class Object3D : public Object
	{
	public:
		Object3D();
		void load_data_from_file(const std::string& file) override;
		virtual void compute_model_matrix() override;
	};
}