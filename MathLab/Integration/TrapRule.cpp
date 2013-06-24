#include<iostream.h>
#include<math.h>


inline double f(double x);
double IntegrateTrap(double start, double stop, int divs);


int main()
	{
	int divs;
	double start, stop;
	
	cout<<"Enter Range Start: ";
	cin>>start;
	cout<<"Enter Range Stop: ";
	cin>>stop;
	cout<<"Enter number of divisions: ";
	cin>>divs;
	cout<<"\nResult of Integration = "<<IntegrateTrap(start,stop,divs)<<"\n\n";
	return(0);
	}



double IntegrateTrap(double start, double stop, int divs)
	{
	double h,i,ans = 0;
	
	h = (stop - start)/divs;
	for(i=start; i<stop; i+=h)
		{
		ans += 0.5*(f(i) + f(i+h)) * h;
		}
	return(ans);
	}



inline double f(double x)
	{
	return(sqrt(sin(x)));
	}

