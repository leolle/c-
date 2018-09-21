#include <iostream>

using namespace std;
int main()
{
	int a=1,b=1,c=1,d=1,e=1,f=1,g=1,h=1,i=1;
	while(a > 0 && a < 10)
	{
	while(b > 0 && b < 10)
	{
	while(c > 0 && c < 10)
	{
	while(d > 0 && d < 10)
	{
	while(e > 0 && e < 10)
	{
	while(f > 0 && f < 10)
	{
	while(g > 0 && g < 10)
	{
	while(h > 0 && h < 10)
	{
	while(i > 0 && i < 10)
	{
		if ((a+b+c+d==20)&&(b+c+d+e+f==20)&&(d+e+f+g+h==20)&&(f+g+h+i==20))
		{
			/* code */
			cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << endl;
		}
		i++;
	}
		h++;
	}
		g++;
	}
		f++;
	}
		e++;
	}
		d++;
	}
			c++;	
	}
b++;
	}
a++;
	}
	return 0;
}