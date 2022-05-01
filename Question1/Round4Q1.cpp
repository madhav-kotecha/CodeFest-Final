#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(int i)
{
	cout<<"Case #"<<i<<": ";
	ll stroke=0;
	int len;
	string color;

	cin>>len>>color;

	int colorR[len]={0},colorY[len]={0},colorB[len]={0};
	int R=0,Y=1,B=2;
	bool pick;
	for(int c=0;c<3;c++)
	{
		pick=false;
		if(c==R)
		{
			for(int i=0;i<len;i++)
			{
				if(color[i]=='R' || color[i]=='O' || color[i]=='P' || color[i]=='A')
					colorR[i]=1;
			}
			for(int i=0;i<len;i++)
			{
				if(!pick && colorR[i])
					pick=true;
				else if(pick && !colorR[i])
				{
					stroke++;
					pick=false;
				}	
			}
			if(pick)
				stroke++;
		}
		else if(c==Y)
		{
			for(int i=0;i<len;i++)
			{
				if(color[i]=='Y' || color [i]=='O' || color[i]=='G' || color[i]=='A')
					colorY[i]=1;
			}
			for(int i=0;i<len;i++)
			{
				if(!pick && colorY[i])
					pick=true;
				else if(pick && !colorY[i])
				{
					stroke++;
					pick=false;
				}
			}
			if(pick)
				stroke++;
		}
		else if(c==B)
		{
			for(int i=0;i<len;i++)
			{
				if(color[i]=='B' || color[i]=='G' || color[i]=='P' || color[i]=='A')
					colorB[i]=1;
			}
			for(int i=0;i<len;i++)
			{
				if(!pick && colorB[i])
					pick=true;
				else if(pick && !colorB[i])
				{
					stroke++;
					pick=false;
				}
			}
			if(pick)
				stroke++;
		}
		
	}
	cout<<stroke<<endl;
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