#include<iostream.h>


double f(int istart, int istop);
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


double f(int j, int k)
	{
	if(j > 0)return(f(j-1, k+1) - f(j-1, k));
	return(fi[k]);
	}



double p(double x)
	{
	int i;
	double r, fc = 0, fp = 1, a = 1, ans = 0;
	
	r = (x - xi) / h;
	for(i=0; i<=d; i++)
		{
		ans += a*f(i,0) / fp;
		a *= r;
		r--;
		fc++;
		fp *= fc;
		}
	return(ans);
	}


	
