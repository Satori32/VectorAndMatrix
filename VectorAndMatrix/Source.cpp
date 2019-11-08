#include <iostream>

#include "Vector.h"
#include "Matrix.h"


int main() {
	{
		Vector<double, 2> a = { 1,2,3,4 };
		Vector<double, 2> b = { 1,2,3,4 };
		Vector<double, 2> c = { 4,0 };
		Vector<double, 2> d = { 0,4 };
		auto A = a + b;
		auto B = a - b;
		auto C = a * 16;
		auto D = a / 16;
		auto E = a.InnerProduct(b);
		auto F = a.Norm();
		auto G = a.Norm2();
		auto H = a.IsParallel(b);
		auto I = c.IsVertical(d);
		auto J = c.Theta(d);
		auto K = c.Area(d);
		auto L = c.R(d);
	}
	{
		Matrix<double, 2, 2> A = { {1,2},{3,4} };
	}
}