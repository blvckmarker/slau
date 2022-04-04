#include "MainMatrix.h"

AnsTuple Matrix::KramerMethod()
{
	std::unique_ptr<Ans> KramAnswer = std::make_unique<Ans>();
	double _MainDeterminant = X1 * ((Y2 * Z3) - (Z2 * Y3)) - Y1 * ((X2 * Z3) - (Z2 * X3)) + Z1 * ((X2 * Y3) - (X3 * Y2));
	if (_MainDeterminant == 0) {
		std::cerr << "Determinant == 0\n";
	}
	auto _XDeterminant = SOL1 * ((Y2 * Z3) - (Y3 * Z2)) - Y1 * ((SOL2 * Z3) - (SOL3 * Z2)) + Z1 * ((SOL2 * Y3) - (Y2 * SOL3));
	auto _YDeterminant = X1 * ((SOL2 * Z3) - (Z2 * SOL3)) - SOL1 * ((X2 * Z3) - (Z2 * X3)) + Z1 * ((X2 * SOL3) - (SOL2 * X3));
	auto _ZDeterminant = X1 * ((Y2 * SOL3) - (SOL2 * Y3)) - Y1 * ((X2 * SOL3) - (SOL2 * X3)) + SOL1 * ((X2 * Y3) - (Y2 * X3));
	KramAnswer->_x = _XDeterminant / _MainDeterminant;
	KramAnswer->_y = _YDeterminant / _MainDeterminant;
	KramAnswer->_z = _ZDeterminant / _MainDeterminant;
	return AnsTuple(KramAnswer->_x, KramAnswer->_y, KramAnswer->_z);
}

AnsTuple Matrix::GaussMethod() //костыли заказывали?
{
	std::unique_ptr<Ans> GaussAnswer = std::make_unique<Ans>();
	for (int Pos{}; Pos < 2; ++Pos) // шоб один и тот же код не повторять для операций(военных)))
	{
		auto _temp = _RESERVED(X1, matrix.at(Position::SecondElement + Pos).at(Position::FirstElement));
		for (auto EachElement = matrix.at(Position::FirstElement).begin(); EachElement != matrix.at(Position::FirstElement).end(); ++EachElement)
			*EachElement *= _temp; // ну типа перемножаем строку на темп.

		for (int EachElement{}; EachElement < WIDTH; ++EachElement)
			matrix.at(Position::SecondElement + Pos).at(EachElement) += matrix.at(Position::FirstElement).at(EachElement); // складываем 
	}
	auto _temp = _RESERVED(Y2, Y3);
	for (auto EachElement = matrix.at(Position::SecondElement).begin(); EachElement != matrix.at(Position::SecondElement).end(); ++EachElement)
		*EachElement *= _temp;
	for (int EachElement{}; EachElement < WIDTH; ++EachElement)
		matrix.at(Position::ThirdElement).at(EachElement) += matrix.at(Position::SecondElement).at(EachElement); // складываем 
	GaussAnswer->_z = SOL3 / Z3;
	GaussAnswer->_y = (SOL2 - (Z2 * GaussAnswer->_z)) / Y2;
	GaussAnswer->_x = (SOL1 - (Y1 * GaussAnswer->_y) - (Z1 * GaussAnswer->_z)) / X1;
	return AnsTuple(GaussAnswer->_x, GaussAnswer->_y, GaussAnswer->_z);
}

void Matrix::SetMatrix()
{
	for (int i{}; i < matrix.size(); ++i)
		for (int j{}; j < matrix.data()->size(); ++j)
			std::cin >> matrix.at(i).at(j);
}
