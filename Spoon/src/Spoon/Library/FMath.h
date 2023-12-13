#pragma once

#pragma region Vector

template <typename T>
struct Vector2D
{
	T X;
	T Y;

	// Constructor
	Vector2D<T>() : X(0), Y(0) {};

	explicit Vector2D<T>(T _val) : X(_val), Y(_val) {};

	Vector2D<T>(T _x, T _y) : X(_x), Y(_y) {};

	static Vector2D<T> Zero() { return Vector2D<T>(0); };

	// Operator
#pragma region Operator
	inline Vector2D<T> operator+=(Vector2D<T>& _val)
	{
		X += _val.X; Y += _val.Y;
		return *this;
	}

	inline Vector2D<T> operator-=(Vector2D<T>& _val)
	{
		X -= _val.X; Y -= _val.Y;
		return *this;
	}

	inline bool operator==(Vector2D<T>& _val)
	{
		return X == _val.X && Y == _val.Y;
	}

	inline bool operator!=(Vector2D<T>& _val)
	{
		return !(*this == _val);
	}

#pragma endregion // Operator

	// Math function
#pragma region BasicMath
	T GetSquareLenght() const
	{
		return (X * X) + (Y * Y);
	}

	T GetLenght() const
	{
		return std::sqrt(GetSquareLenght());
	}
#pragma endregion
};

#pragma region Operator Copy
template <typename T>
__forceinline Vector2D<T> operator+(Vector2D<T>& right, Vector2D<T>& left)
{
	return Vector2D<T>(right.X + left.X, right.Y + left.Y);
}

template <typename T>
__forceinline Vector2D<T> operator+(Vector2D<T>& right, T& left)
{
	return Vector2D<T>(right.X + left, right.Y + left);
}

template <typename T>
__forceinline Vector2D<T> operator-(Vector2D<T>& right, Vector2D<T>& left)
{
	return Vector2D<T>(right.X - left.X, right.Y - left.Y);
}

template <typename T>
__forceinline Vector2D<T> operator-(Vector2D<T>& right, T& left)
{
	return Vector2D<T>(right.X - left, right.Y - left);
}

template <typename T>
__forceinline bool operator==(Vector2D<T>& left, Vector2D<T>& right)
{
	return left.X == right.X && left.Y == right.Y;
}

template <typename T>
__forceinline bool operator!=(Vector2D<T>& left, Vector2D<T>& right)
{
	return !(left == right);
}

#pragma endregion

#pragma endregion Vector

#pragma region Color
struct FColor
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;

	FColor() : R(0), G(0), B(0), A(0) {};

	FColor(const unsigned char& val) : R(val), G(val), B(val), A(val) {};

	FColor(const unsigned char& color, unsigned char alpha) : R(color), G(color), B(color), A(alpha) {};

	FColor(const unsigned char& r, const unsigned char& g, const unsigned char& b) : R(r), G(g), B(b), A(255) {};

	FColor(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a) : R(r), G(g), B(b), A(a) {};

	static FColor Zero() { return FColor(0); }

	static FColor White() { return FColor(255); }

};

#pragma endregion