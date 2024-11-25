#include "MatrixHandling.h"

string separator = "\n====================================\n";

Matrix<double, Dynamic, 1> realHandler(int n)
{
	Matrix<double, Dynamic, Dynamic> coff(n, n);
	cout << "Enter Coefficients: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double num;
			cout << "Coefficient[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> num;
			coff(i, j) = num;
		}
	}

	Matrix<double, Dynamic, 1> constant(n);
	cout << "Enter Constants: \n";
	for (int i = 0; i < n; i++)
	{
		double num;
		cout << "Constant[" << i + 1 << "] = ";
		cin >> num;
		constant(i) = num;
	}

	Matrix<double, Dynamic, 1> soln = coff.colPivHouseholderQr().solve(constant);

	return soln;
}

Matrix<complex<double>, Dynamic, 1> cmplxHandler(int n)
{
	Matrix<complex<double>, Dynamic, Dynamic> coff(n, n);
	cout << "Enter Coefficients (real, imaginary) separated with space: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double real, imag;
			cout << "Coefficient[" << i + 1 << "][" << j + 1 << "]= ";
			cin >> real >> imag;
			complex<double> num(real, imag);
			coff(i, j) = num;
		}
	}

	Matrix<complex<double>, Dynamic, 1> constant(n);
	cout << "Enter Constants (real, imaginary) separated with space: \n";
	for (int i = 0; i < n; i++)
	{
		double real, imag;
		cout << "Constant[" << i + 1 << "] = ";
		cin >> real >> imag;
		complex<double> num(real, imag);
		constant(i) = num;
	}

	Matrix<complex<double>, Dynamic, 1> soln = coff.colPivHouseholderQr().solve(constant);

	return soln;
}

string complexToStr(const std::complex<double>& z)
{
	string complexnum = "";

	complexnum += to_string(z.real());

	if (z.imag() > 0)
	{
		complexnum += (" + " + to_string(z.imag()) + "i");
	}
	else if (z.imag() < 0)
	{
		complexnum += (" - " + to_string(-z.imag()) + "i");
	}
	return complexnum;
}

void Help()
{
	cout << separator << "\t EQUATION SOLVER" << separator
		<< "Help: " << separator
		<< "Input R/C when prompted (case insensitive).\n"
		<< "You will be asked to input the coefficients (ie. Coefficient[1][2]), then Constants (ie. Constant[1])\n"
		<< "The formatting will be as if you put the coefficients in a matrix\n"
		<< "For Real: \n"
		<< "\t Input ONLY ONE number whenever prompted\n"
		<< "For Complex: \n"
		<< "\t Input EXACTLY TWO numbers (a, b), they will be formatted as a + bi"
		<< separator;
}