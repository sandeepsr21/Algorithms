/******************************Dynamic Programming *************************************
*******************************Matrix Chain Multiplication.*****************************
******************************Prints lowest number of multiplications*******************
******************************Prints parenthesised order of matrix multiplications******
*******************************Author: Sandeep S Rangaraju******************************
*******************************Reference: Coreman Algorithms****************************
*****************************************************************************/
#include<iostream>
using namespace std;

//Class matrix
class matrix
{
	private:
		int n;//number of matrices
		int *p;//matrix size stored in an array
		int **m;//m table
		int **s;// s table to print order of multiplications
		int result;//final result
	public:
		matrix()
		{
			int a, b;
			cout << endl << "Enter number of matrices:n: ";
			cin >> n;
			n++;
			//Allocate p array to store sizes
			p = new int[n];

			//store sizes of matrices in 'p' Array
			for (int i = 0; i < n; i++) {
				cout << endl << "Enter " << i+1 << " Matrix size: ";
				cin >> a >> b;
				if (i != n - 2)
					p[i] = a;
				else
				{
					p[i] = a;
					i++;
					p[i] = b;
				}
			}

			//Allocate m table matrix
			m = new int*[n];
			for (int i = 0; i < n; i++)
				m[i] = new int[n];

			//Allocate s table matrix
			s = new int*[n];
			for (int i = 0; i < n; i++)
				s[i] = new int[n];

		}

		//calculate the number of multiplications needed
		void matrix_chain();

		void print_result();

		//Recursive function call to print order of matrix multiplications
		void print_matrix_order(int, int);

		~matrix()
		{
			//Free all the memory allocated
			for (int i = 0; i < n; i++) {
				delete[] m[i];
				delete[] s[i];
			}
			delete[] m;
			delete[] s;
			delete[] p;
		}
};

//Reference Coreman matrix chain multiplication pseudocode
void matrix::matrix_chain()
{
	int i, j, k, l,q;

	//0th Rown and column are not used hence ignored
	for (i = 1; i < n; i++)
		m[i][i] = 0;
	
	for (l = 2; l < n; l++)
	{
		for (i = 1; i <= n - l; i++)
		{
			j = i + l - 1;
			m[i][j] = 99999;
			for (k = i; k < j; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}

		}

	}
	result = m[1][n - 1];
	cout << endl<< "Number of multiplications needed : "<<result;
}

void matrix::print_result()
{
	cout <<endl<<"Matrix order is: ";
	print_matrix_order(1, n - 1);
}

//Reference Coreman Algorithms matrix chain multiplication pseudocode
void matrix::print_matrix_order(int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		cout << "(";
		print_matrix_order(i, s[i][j]);
		print_matrix_order(s[i][j] + 1, j);
		cout << ")";
	}
}

int main()
{
	matrix m;
	m.matrix_chain();
	m.print_result();
	return 0;
}