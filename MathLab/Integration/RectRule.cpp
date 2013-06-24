#include<iostream.h>
#include<math.h>


inline double f(double x);
double IntegrateRect(double start, double stop, int divs);


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
	cout<<"\nResult of Integration = "<<IntegrateRect(start,stop,divs)<<"\n\n";
	return(0);
	}



double IntegrateRect(double start, double stop, int divs)
	{
	double h,i,ans = 0;
	
	h = (stop - start)/divs;
	for(i=start; i<stop; i+=h)
		{
		ans += f(i + 0.5*h) * h;
		}
	return(ans);
	}



inline double f(double x)
	{
	return(sqrt(sin(x)));
	}

