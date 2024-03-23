// StaticLibSqrt.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "mysqrt.h"


double GetSquareRoot(int num) 
{
	if (num < 0)
		throw std::runtime_error("Negative Number.");

	return sqrt(static_cast<double>(num));
}
