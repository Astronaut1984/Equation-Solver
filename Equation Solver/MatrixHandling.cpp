#include "MatrixHandling.h"

string separator = "\n====================================\n";

int realHandler(int n, Matrix<double, Dynamic, 1> &Ans)
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

	int systemType = analyzeSystem<double>(coff, constant);

	if (systemType == 1)
	{
		Ans = coff.colPivHouseholderQr().solve(constant);
		return 1;
	}

	else
	{
		return systemType;
	}
}

int cmplxHandler(int n , Matrix<complex<double>, Dynamic, 1> & Ans)
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
	int systemType = analyzeSystem<complex<double>>(coff, constant);

	if(systemType == 1)
	{
		Ans = coff.colPivHouseholderQr().solve(constant);
		return 1;
	}

	else
	{
		return systemType;
	}

	
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
		<< "The formatting will be as if you put the coefficients and constants in a matrix\n"
		<< "For Real: \n"
		<< "\t Input ONLY ONE number whenever prompted\n"
		<< "For Complex: \n"
		<< "\t Input EXACTLY TWO numbers (a, b), they will be formatted as a + bi"
		<< separator;
}

template <typename Scalar> int analyzeSystem(const Matrix<Scalar,Dynamic,Dynamic>& A,const Matrix<Scalar,Dynamic, 1>& b)
{
	// Solve the system using QR decomposition
	ColPivHouseholderQR<Matrix<Scalar, Dynamic, Dynamic>> qr(A);

	// Get the rank of A
	int rank_A = qr.rank();

	// Check the number of variables (columns in A)
	int numVariables = A.cols();

	// Check the rank condition
	if (rank_A == numVariables) {
		// Check if a solution exists
		if ((A * qr.solve(b)).isApprox(b)) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		if ((A * qr.solve(b)).isApprox(b)) {
			return 0;
		}
		else {
			return -1;
		}
	}
}