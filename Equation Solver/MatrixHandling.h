#pragma once
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


Matrix<double, Dynamic, 1> realHandler(int n);
string complexToStr(const std::complex<double>& z);
Matrix<complex<double>, Dynamic, 1> cmplxHandler(int n);
void Help();