#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*void sort(int[] &values)
{
	for (int i=0;i<values.length()-1; i++) {
			for (int j=i+1; j<values.length(); j++) {
				if(values[j]>values[j+1])
				{
					int swap=values[j];
					values[j]=values[j+1];
					values[j+1]=swap;
				}
			}
	}
}*/

void solve(int i)
{
	cout<<"Case #"<<i<<": ";
	int n, p;
	ll count=0;
	cin>>n>>p;
	ll customers[n][p];
	for(int i=0;i<n;i++)
	{
		for (int j=0; j < p; ++j)
		{
			cin>>customers[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(customers[i],customers[i]+p);
	}

	/*for(int i=0;i<n;i++)
	{
		for (int j=0; j < p; ++j)
		{
			cout<<customers[i][j]<<" ";
		}
		cout<<endl;
	}*/
	count+=customers[0][0];
	int lastIt=customers[0][p-1];
	for(int i=1;i<n-1;i++)
	{

		count+=customers[i][p-1]-customers[i][0];
		// count+=min(abs(customers[i-1][p-1])-customers[i][p-1]);
		
		if(abs(customers[i][p-1]-lastIt<abs(customers[i][0]-lastIt)))
		{
			count+=abs(customers[i][p-1]-lastIt);
			lastIt=customers[i][0];
		}	
		else
		{
			count+=abs(customers[i][0]-lastIt);
			lastIt=customers[i][p-1];
		}
		/*if(abs(customers[i-1][p-1]-customers[i][p-1])<abs(customers[i-1][p-1]-customers[i][0]))
			lastIt=	abs(customers[i-1][p-1]-customers[i][p-1]);
		else
			lastIt= abs(customers[i-1][p-1]-customers[i][0]);*/
	}
	count+=customers[i][p-1]-customers[i][0];
	cout<<count<<endl;
}

int main(int argc, char const *argv[])
{
	freopen("ts1_input.txt","r",stdin);
	freopen("ts1_output.txt","w",stdout);
	int t;
	cin>>t;

	for(int i=1;i<=t;i++)
		solve(i);
}