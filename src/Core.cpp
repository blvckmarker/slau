#include "MainMatrix.h"

using namespace SourceParameters;
//      0)   1)   2)   3)
//      x    y    z    sol	
//  0)  3   -2    4    21
//  1)  3    4   -2    9
//  2)	2   -1   -1    10
int main()
{
	MatrixVector matrix(HEIGHT, std::vector<double>(WIDTH));
	Matrix* mtrx = new Matrix(matrix);
	std::tuple<double, double, double> GaussAns;
	mtrx->SetMatrix();
	auto&& [x, y, z] = mtrx->KramerMethod();
	std::thread A([&]()
		{
			GaussAns = mtrx->GaussMethod();
		});
	A.join();
#if __cpp_lib_format
	std::cout << std::format("{} {} {}", x, y, z);
	std::cout << std::format("\n {} {} {}", std::get<0>(GaussAns), std::get<1>(GaussAns), std::get<2>(GaussAns));
#else
	std::cout << x << " " << y << " " << z << std::endl;
	std::cout << std::get<0>(GaussAns) << " " << std::get<1>(GaussAns) << " " << std::get<2>(GaussAns));
#endif
	delete mtrx;
}
