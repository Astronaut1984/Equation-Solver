#pragma once
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


int realHandler(int n, Matrix<double, Dynamic, 1>& Ans);
string complexToStr(const std::complex<double>& z);
int cmplxHandler(int n, Matrix<complex<double>, Dynamic, 1>& Ans);
template <typename Scalar> int analyzeSystem(const Matrix<Scalar, Dynamic, Dynamic>& A,
    const Matrix<Scalar, Dynamic, 1>& b);
void Help();