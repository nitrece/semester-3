#include<iostream.h>


double f(int istart, double istop);
double p(double x);


//Global Variables
int d;
double xi, *fi, h;



int main()
	{
	char s[256];
	int i;
	double x;
	
	cout<<"Number of cases: ";
	cin>>d;
	fi = new double[d];
	d--;
	
	cout<<"\nEnter x0: ";
	cin>>xi;
	cout<<"Enter h: ";
	cin>>h;
	cout<<"\n";
	for(i=0; i<=d; i++)
		{
		cout<<"Enter f"<<i<<": ";
		cin>>fi[i];
		}
	while(1)
		{
		cout<<"\nFind f(x) at x: ";
		cin>>x;
		cout<<"f("<<x<<") = "<<p(x)<<"\n";
		cout<<"Stop? ";
		cin>>s;
		if(s[0]=='y' || s[0]=='Y')break;
		}
	
	delete fi;
	return(0);
	}


double f(int j, double k)
	{
	if(j > 0)return(f(j-1, k+0.5) - f(j-1, k-0.5));
	return(fi[d/2+(int)k]);
	}



double p(double x)
	{
	int i;
	double k, kstart;
	double r, fc = 0, fp = 1, a = 1, ans = 0;
	
	kstart = d - (d/2);
	r = (x - (xi + d*h)) / h;
	for(i=0,k=kstart; i<=d; i++,k-=0.5)
		{
		ans += a*f(i,k) / fp;
		a *= r;
		r++;
		fc++;
		fp *= fc;
		}
	return(ans);
	}


	
