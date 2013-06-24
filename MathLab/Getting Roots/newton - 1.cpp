
#include<iostream.h>
#include<math.h>
#include<conio.h>



void newton(double x0);
double equation(double x);
inline double modulus(double x);
double derivative(double x);






main()
	{
	double x0;
	
	cout<<"Enter x0: ";
	cin>>x0;
	newton(x0);
	
	return(0);
	}



void newton(double x0)
	{
	int i=1;
	double fch, fx, fdx;
	
	cout<<"Iteration #"<<i<<": x0 = "<<x0<<"\n";
	i++;
	do
		{
		fx = equation(x0);
		fdx = derivative(x0);
		fch = fx/fdx;
		if((modulus(fx) < pow(10, -10)) || ((modulus(fx/fch)<pow(10, -15)) || (modulus(fdx/fch)<pow(10, -15))))
			{
			cout<<"No reachable root from given point.";
			return;
			}
		x0 = x0 - fch;
		cout<<"Iteration #"<<i<<": x0 = "<<x0<<"\n";
		i++;
		}
	while(modulus(fch) > pow(10, -10));

	cout<<"Final Result = "<<x0<<"\n";
	}



inline double modulus(double x)
	{
	if(x < 0)x= -x;
	return(x);
	}


double equation(double x)
	{
	return(5 * pow(x,4) - 1);
	}



double derivative(double x)
	{
	return(pow(x,5) - x + 2);
	}




