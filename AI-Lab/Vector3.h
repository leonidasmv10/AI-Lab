#pragma once

namespace Math {

	class Vector3
	{
	public:
		float x, y, z, w;

		// Constructores
		Vector3();
		Vector3(float scalar);
		Vector3(float x, float y, float z);
		Vector3(float x, float y, float z, float w);

		// Operadores
		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3 operator+(const Vector3& other) const;
		Vector3 operator-(const Vector3& other) const;
		Vector3 operator*(float scalar) const;
		Vector3 operator/(float scalar) const;
		bool operator==(const Vector3& other) const;
		bool operator!=(const Vector3& other) const;

		// Métodos estáticos
		static float dot(const Vector3& v1, const Vector3& v2);
		static Vector3 cross(const Vector3& v1, const Vector3& v2);
		static float magnitude(const Vector3& v);
		static Vector3 normalize(const Vector3& v);
		static float angle(const Vector3& v1, const Vector3& v2);

		// Métodos de instancia
		void normalize();
		void add(const Vector3& v);

		// Para depuración
		friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
	};
}

