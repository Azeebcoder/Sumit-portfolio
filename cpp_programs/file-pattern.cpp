#include"bits\stdc++.h"
using namespace std;
int main()
{
	int i,j,k,n;
	cout<<"Enter the Row : ";
	cin>>n;
	ofstream filepattern("pattern.txt");
	for(i=n;i>=1;i--)
	{
		for(j=n;j>i;j--)
		{
			filepattern<<"  ";
		}
		for(k=1;k<=2*i-1;k++)
		{
			filepattern<<"* ";
		}
		filepattern<<"\n";
	}
	return 0;
}
