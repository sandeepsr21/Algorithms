/******************************Dynamic Programming ***************************
*******************************ROD CUTING PROBLEM*****************************
*******************************Finding MAX profit*****************************
*******************************Author: Sandeep S Rangaraju********************
*******************************Reference: Coreman Algorithms******************
*****************************************************************************/

#include<iostream>
#include<conio.h>
using namespace std;

class rod
{
private:
	int *p;//Price for each lenght of rod
	int length;//Max length of rod
	int n;//max profit to be founf for this length
	int *r;//price list table
	int *s;//Length table
public:
	rod()
	{
		cout << "Enter Max length :";
		cin >> length;
		p = new int[length];
		for (int i = 0; i < length; i++)
		{
			cout << endl << "Enter price for length:" << i+1<<":";
			cin >> p[i];
		}
		cout << endl << "Enter rod length n to be cut to find the maximum profit:";
		cin >> n;
		r = new int[n + 1];
		r[0] = 0;
		s = new int[n + 1];
		s[0] = 0;
	}
	void rod_cut();
	void print_rod_lengths();
	~rod()
	{
		delete[] p;
		delete[] r;
		delete[] s;
	}

};

void rod::rod_cut()
{
	for (int j = 0; j < n; j++)
	{
		int q = -999;
		for (int i = 0; i <= j; i++)
		{
			if (q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j+1] = i+1;
			}
		}
		r[j+1] = q;
	}
}

void rod::print_rod_lengths()
{
	cout << endl << "Max profit is :" << r[n];
	while (n > 0)
	{
		cout <<endl<< "Rods are of lengths:" << s[n];
		n = n - s[n];
	}
}

int main()
{
	rod r;
	r.rod_cut();
	r.print_rod_lengths();
	_getch();
	return 0;
}