
#include<iostream.h>
#include<math.h>
#include<conio.h>



void secant(double x0, double x1);
double equation(double x);
inline double modulus(double x);
double derivative(double x);



main()
	{
	double x0, x1;
	
	cout<<"Enter x0: ";
	cin>>x0;
	cout<<"Enter x1: ";
	cin>>x1;
	secant(x0, x1);
	
	return(0);
	}



void secant(double x0, double x1)
	{
	int i=1;
	double fx1, fx0, xnew;
	
	cout<<"Iteration #"<<i<<": x0 = "<<x0<<"\n";
	i++;
	while(modulus(x1-x0) > pow(10,-10))
		{
		fx0 = equation(x0);
		fx1 = equation(x1);
		if((modulus(x1-x0) < pow(10, -10)) || (modulus(fx1 - fx0) < pow(10, -10)))
			{
			cout<<"\n"<<"Sorry, Root cant be reached from this point."<<"\n";
			return;
			}
		xnew = x1 - fx1 * ((x1 - x0) / (fx1 - fx0));
		x0 = x1;
		x1 = xnew;
		cout<<"Iteration #"<<i<<": x0 = "<<x0<<"\n";
		i++;
		}

	cout<<"Final Result = "<<x0<<"\n";
	}



inline double modulus(double x)
	{
	if(x < 0)x= -x;
	return(x);
	}


double equation(double x)
	{
	return(pow(x,4) - 2*pow(x,3) + 3*pow(x,2) -1);
	}




