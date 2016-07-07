/******************************Dynamic Programming *************************************
*******************************Minimum cost to reach destination************************
Calculates and Prints the lowest cost to reach from station source to destn*************
*******************************Author: Sandeep S Rangaraju******************************
*******************************Reference: Geeks for Geeks   ****************************
***************************************************************************************/

#include<iostream>
using namespace std;
#define MAX 99999

class min_cost
{
	private:
		int **cost;
		int n;
		int *d;
	public:
		min_cost()
		{
			cout << "Enter Number of stations:n: ";
			cin >> n;
			cost = new int*[n];
			for (int i = 0; i < n; i++)
				cost[i] = new int[n];
			//Initialize cost matrix
			for (int i = 0; i < n; i++)
				cost[i][i] = 0;

			//No backward travelling.So filling infinity
			for (int i = 1; i < n; i++)
				for (int j = 0; j < i; j++)
					cost[i][j] = MAX;
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					cout << endl << "Enter cost of stations from " << i << " to " << j<<": ";
					cin >> cost[i][j];
				}
			}

			//Allocate memory for distance table
			d = new int[n];
			d[0] = 0;
			for (int i = 1; i < n; i++)
				d[i] = MAX;
		}
		~min_cost()
		{
			for (int i = 0; i < n; i++)
				delete[] cost[i];
			delete[] cost;
			delete[] d;
		}

		void calculate_min_cost();
		void print_cost();

};

void min_cost::calculate_min_cost()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[j] > (d[i] + cost[i][j]))
				d[j] = d[i] + cost[i][j];
		}
	}
}

void min_cost::print_cost()
{
	cout << endl << "Minimum cost to reach from 0 to " <<( n - 1 )<< " is " << d[n - 1];
}

int main()
{
	min_cost m;
	m.calculate_min_cost();
	m.print_cost();
	return 0;
}