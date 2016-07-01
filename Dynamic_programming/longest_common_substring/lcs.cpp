/******************************Dynamic Programming ***************************
*******************************Finding Longest Common SubSequence***************
*******************************Author: Sandeep S Rangaraju********************
*******************************Reference: Coreman Algorithms******************
*****************************************************************************/
#include<iostream>
using namespace std;

/* LCS Class Contains 2 input strings S1,S2,1 output string s3 which is least common subsequence 
   and the length of LCS */
class LCS
{
	private:
		char *s1;
		char *s2;
		char *s3;
		int length_lcs;
	public:
		LCS()
		{
			cout<<"Enter S1:";
			s1=new char[100];
			cin>>s1;
			
			cout<<"Enter S2:";
			s2=new char[100];
			cin>>s2;
		}
		int lcs_length();//Calculates the LCS length and stores LCS in s3
		char* get_string1(); //return s1
		char* get_string2(); //return s2
		void lcs_print(); //return s3(LCS)

		// Free the s3 memory
		~LCS()
		{
			//cout<<"free memory";
			delete[] s1;
			delete[] s2;
			delete[] s3;
		}
};

char* LCS::get_string1()
{
	return s1;
}

char* LCS::get_string2()
{
	return s2;
}

void lcs_print();


int LCS::lcs_length()
{
	// Calculate Length of s1 and store in m
	int m = 0;
	while (s1[m] != '\0')
		m++;
	// Calculate Lenght of s2 and store in n
	int n = 0;
	while (s2[n] != '\0')
		n++;
	/* Allocate substring  table with one extra row and columns 
	   as 0th row and 0th column is not used */

	int **c = new int* [m+1];
	for (int i = 0; i <= m; i++)
		c[i] = new int[n+1];
	//Initialize Column 0 to 0s as its not used	
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	//Inialize Row 0 to 0s as its not used
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;

       /* Start filling the table
	  1)If matched string is found take diagnol cell count and increment by 1
	  2)If matched string is not found compare immediate above cell and immediate left cell.
	    Fill the current cell with maximum of the compared cell
	  3)Last cell c[m][n] contains the length of subsequence */

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
					c[i][j] = c[i - 1][j];
				else
					c[i][j] = c[i][j-1];
			}

		}
	}

	length_lcs = c[m][n];
	// Allocate the subsequnce string length to s3
	s3 = new char[length_lcs];
	
	int index = length_lcs;
	s3[index] = '\0';//Null terminate the string
	int i = m;
	int j = n;

	/* To get the subsequence 
  	   compare the strings s1 and s2 from behind 
           if found store it in s3 
	   else compare the cells  c[i-1][j] and c[i][j-1] and go in the  direction of greater value unitl you reach oth row or column
          */
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			s3[--index] = s1[i-1];
			i--;
			j--;
		
		}
		else
		{
			if (c[i - 1][j] >= c[i][j - 1])
				i--;
			else
				j--;
		}
	}
	// Free the table memory
	for (int k = 0; k <= m; k++)
	{
		delete[] c[k];
	}
	delete[]  c;

	//return subsequence length
	return length_lcs;

}

void LCS::lcs_print()
{
	cout << s3<<endl;
}

int main()
{
	//LCS object is created with s1,s2 input strings, NULL for intial s3,0 for length_lcs
	LCS lcs;
	cout << "Length of longest common subsequence is : "<<lcs.lcs_length()<<endl;
	cout<<"Subsequence of s1 and s2 is s3"<<endl<<"s1:"<<lcs.get_string1()<<endl<<"s2:"<<lcs.get_string2()<<endl<<"s3:";
	lcs.lcs_print();
	return 0;
}
