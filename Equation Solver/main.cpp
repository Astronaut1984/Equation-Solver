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
		Matrix<double, Dynamic, 1> Ans;
		int flag = realHandler(n, Ans);
		cout << separator;
		switch(flag){
		case 1:
			cout << "Solution: \n";
			for (int i = 0; i < n; i++)
			{
				cout << "X[" << i + 1 << "] = " << Ans[i] << '\n';
			}
			break;
		case 0:
			cout << "Infinite Solutions!\n";
			break;
		case -1:
			cout << "No Solutions!\n";
		}
	}

	else if (t == 'C')
	{
		Matrix<complex<double>, Dynamic, 1> Ans;
		int flag = cmplxHandler(n, Ans);
		cout << separator;
		switch (flag) {
		case 1:
			cout << "Solution: \n";
			for (int i = 0; i < n; i++)
			{
				cout << "X[" << i + 1 << "] = " << complexToStr(Ans[i]) << '\n';
			}
			break;
		case 0:
			cout << "Infinite Solutions!\n";
			break;
		case -1:
			cout << "No Solutions!\n";
		}
	}

	else
	{

		cout << "Invalid input! Exiting...\n";
		return -1;
	}

	system("pause");

	return 0;
}
