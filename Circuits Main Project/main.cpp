#include "MatrixHandling.h"

int main()
{
	string separator = "\n====================================\n";
	Help();
	int n;
	char t;
	cout << "Enter size of matrix: ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Invalid number, use a positive number! Exiting...\n";
		return -1;
	}
	cout << "Real or Complex? (R/C): ";
	cin >> t;
	t = toupper(t);
	
	if (t == 'R')
	{
		Matrix<double, Dynamic, 1> solution = realHandler(n);
		cout << separator;
		cout << "Solution: \n";
		for (int i = 0; i < n; i++)
		{
			cout << "X[" << i + 1 << "] = " << solution[i]<<'\n';
		}
	}

	else if (t == 'C')
	{
		Matrix<complex<double>, Dynamic, 1> solution = cmplxHandler(n);
		cout << separator;
		cout << "Solution: \n";
		for (int i = 0; i < n; i++)
		{
			cout << "x[" << i + 1 << "] = " << complexToStr(solution[i]) << '\n';
		}
	}

	else
	{

		cout << "Invalid input! Exiting...\n";
		return -1;
	}

	return 0;
}
