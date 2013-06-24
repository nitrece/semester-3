#include<iostream.h>


double L(double x, int k, double *xi, int d);
double p(double x, double *xi, double *fi, int d);





int main()
	{
	char s[256];
	int d, i;
	double *xi, *fi, x;
	
	cout<<"Number of cases: ";
	cin>>d;
	xi = new double[d];
	fi = new double[d];
	d--;
	
	for(i=0; i<=d; i++)
		{
		cout<<"\nEnter x"<<i<<": ";
		cin>>xi[i];
		cout<<"Enter f"<<i<<": ";
		cin>>fi[i];
		}
	while(1)
		{
		cout<<"\nFind f(x) at x: ";
		cin>>x;
		cout<<"f("<<x<<") = "<<p(x, xi, fi, d)<<"\n";
		cout<<"Stop? ";
		cin>>s;
		if(s[0]=='y' || s[0]=='Y')break;
		}
	
	delete fi;
	delete xi;
	return(0);
	}


double L(double x, int k, double *xi, int d)
	{
	int i;
	double ans = 1.0;
	
	for(i=0; i<=d; i++)
		{
		if(i == k)continue;
		ans *= (x - xi[i]) / (xi[k] - xi[i]);
		}
	return(ans);
	}



double p(double x, double *xi, double *fi, int d)
	{
	int i;
	double ans = 0.0;
	
	for(i=0; i<=d; i++)
		{
		ans += fi[i] * L(x, i, xi, d);
		}
	return(ans);
	}


