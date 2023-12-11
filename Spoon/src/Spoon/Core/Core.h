#pragma once
#ifdef SN_BUILD_DLL
	#define SPOON_API __declspec(dllexport)
#else
	#define SPOON_API __declspec(dllimport)
#endif // SN_BUILD_DLL

template <typename T> struct Vector2D;

using FVector2D = Vector2D<float>;

struct FColor;

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
