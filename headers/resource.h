#pragma once
#include "Mainheader.h"

namespace SourceParameters {
	const size_t WIDTH = 4;
	const size_t HEIGHT = 3;

	using AnsTuple = std::tuple<double, double, double>;
	using MatrixVector = std::vector<std::vector<double>>;

	enum Position {
		FirstElement = 0,
		SecondElement = 1,
		ThirdElement = 2,
		FourthElement = 3
	};
	//						|y|                     |x|
#define X1 matrix.at(Position::FirstElement).at(Position::FirstElement)
#define X2 matrix.at(Position::SecondElement).at(Position::FirstElement)
#define X3 matrix.at(Position::ThirdElement).at(Position::FirstElement)
#define Y1 matrix.at(Position::FirstElement).at(Position::SecondElement)
#define Y2 matrix.at(Position::SecondElement).at(Position::SecondElement)
#define Y3 matrix.at(Position::ThirdElement).at(Position::SecondElement)
#define Z1 matrix.at(Position::FirstElement).at(Position::ThirdElement)
#define Z2 matrix.at(Position::SecondElement).at(Position::ThirdElement)
#define Z3 matrix.at(Position::ThirdElement).at(Position::ThirdElement)
#define SOL1 matrix.at(Position::FirstElement).at(Position::FourthElement)
#define SOL2 matrix.at(Position::SecondElement).at(Position::FourthElement)
#define SOL3 matrix.at(Position::ThirdElement).at(Position::FourthElement)

///<returns>Inverse of _BeginParam</returns>
#define _RESERVED(_BeginParam, _EndParam) _EndParam / _BeginParam * -1  
};