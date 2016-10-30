#include <iostream>
#include<string.h>
using namespace std;

int main() {
	// your code goes here
	char *s = new char[200];
	cin>>s;
	int len = strlen(s);
	int **table = new int*[len];
	for(int i=0;i<len;i++)
	{
	    table[i] = new int[len];
	}
	int start;
	for(int i=0;i<len;i++)
	{
        table[i][i] = 1;
	}
	int maxlength=0;
	for(int i=0;i<len-1;i++)
	{
	    if(s[i]==s[i+1])
	    {
	        table[i][i+1]=1;
	        start = i;
	        maxlength=2;
	    }
	}
	int j;
	for(int k=3;k<=len;k++)
	{
	    for(int i=0;i<len-k+1;i++)
	    {
	        j=i+k-1;
	        if(table[i+1][j-1] && s[i]==s[j])
	        {
	            table[i][j]=1;
	            if(k>maxlength)
	            {
	                maxlength=k;
	                start=i;
	            }
	        }
	    }
	}
	
	cout<<start<<" "<<maxlength<<endl;
	for(int i=start;i<maxlength+start;i++)
	{
	    cout<<s[i];
	}
	
	for(int i=0;i<len;i++)
	    delete[] table[i];
	delete[] table;
	return 0;
}
