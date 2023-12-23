#pragma once

#include <corecrt_math.h>
#include <numbers>

namespace MathLibrary
{
	
	constexpr double Pi() { return std::numbers::pi; }
	
	static float CosRad(float A) { return cosf(A); }
	static double CosRad(double A) { return cos(A);	}

	static float ACos(float A) { return acosf( (A<-1.f) ? -1.f : ( (A < 1.f) ? A : 1.f) ); }
	static double ACos(double A) { return acos( (A<-1.0) ? -1.0 : ( (A < 1.0) ? A : 1.0) ); }
}
