#include<bits/stdc++.h>
using namespace std;

void solve(int i)
{
	cout<<"Case #"<<i<<": ";
	string original, needed;
	long long int total=0;
	cin>>original>>needed;
	bool present[26]={false};
	for(int i=0;i<needed.length();i++)
	{
		present[needed[i]-'a']=true;
	}
	
	for(int i=0;i<original.length();i++)
	{
		int min=26;
		if(!(present[original[i]-'a']))
		{
			for(int j=0;j<26;j++)
			{
				if(present[j])
				{
					if(abs(j-(original[i]-'a'))<min)
						min=abs(j-(original[i]-'a'));
					else if((abs(j-(original[i]-'a'))>13)&&(abs(j-(original[i]-'a'))-13<min))
						min=abs(j-(original[i]-'a'))-13;
				}
			}
			total+=min;
		}
		
	}
	cout<<total<<endl;
}

int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;

	for(int i=1;i<=t;i++)
		solve(i);
}