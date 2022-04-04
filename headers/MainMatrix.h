#pragma once
#include "resource.h"

using namespace SourceParameters;

#pragma warning (disable: 26495)
class Matrix
{
private:
	struct Ans { double _x, _y, _z; }jopa;
	MatrixVector matrix;
public:
	AnsTuple KramerMethod();
	AnsTuple GaussMethod();
	void SetMatrix();
	[[noreturn]] Matrix() {
		jopa._x = 0, jopa._y = 0, jopa._z = 0;
	};
	[[noreturn]] explicit Matrix(MatrixVector& mtrx) : matrix(std::move(mtrx)) {};
	[[noreturn]] ~Matrix() {};
};
#pragma warning (default: 26495)