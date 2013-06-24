
#include<iostream.h>
#include<math.h>
#include<conio.h>


void bisection(double a0, double b0);
double equation(double x);
inline double modulus(double x);






main()
	{
	double a0, b0;
	
	cout<<"Enter a0: ";
	cin>>a0;
	cout<<"Enter b0: ";
	cin>>b0;
	bisection(a0,b0);
	
	return(0);
	}



void bisection(double a0, double b0)
	{
	int i=1;
	double fa, fb, mid = 0.0, fval;
	
	cout<<"Iteration #"<<i<<": a0 = "<<a0<<"\tb0 = "<<b0<<"\n";
	i++;
	fa = equation(a0);
	fb = equation(b0);
	if(fa*fb > 0)
		{
		cout<<"The roots donot exist in this interval.\n";
		return;
		}
	if(fa>0 && fb<0){fval = a0; a0 = b0; b0 = fval;}
	
	while(modulus(b0-a0) > pow(10, -10))
		{
		mid = (a0 + b0)/2.0;
		fval = equation(mid);
		if(fval < 0)a0 = mid;
		else b0 = mid;
		cout<<"Iteration #"<<i<<": a0 = "<<a0<<"\tb0 = "<<b0<<"\n";
		i++;
		}
	cout<<"Final Result = "<<mid<<"\n";
	}



inline double modulus(double x)
	{
	if(x < 0)x= -x;
	return(x);
	}


double equation(double x)
	{
	return(log(x)/log(0.5) - x);
	}


