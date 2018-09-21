#include <iostream>

using namespace std;
int main()
{
	for (int a = 0; a < 10; ++a)
	{
		/* code */
		for (int b = 0; b < 10; ++b)
		{
					for (int c = 0; c < 10; ++c)
		{
					for (int d = 0; d < 10; ++d)
		{
					for (int e = 0; e < 10; ++e)
		{
					for (int f = 0; f < 10; ++f)
		{
					for (int g = 0; g < 10; ++g)
		{
					for (int h = 0; h < 10; ++h)
		{
					for (int i = 0; i < 10; ++i)
		{
					if ((a!=b!=c!=d!=e!=f!=g!=h!=i)&&
						(a+b+c+d==20)&&(b+c+d+e+f==20)&&(d+e+f+g+h==20)&&(f+g+h+i==20))
		{
			/* code */
			cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << endl;
		}

		}

		}

		}

		}

		}

		}

		}

		}
	}
}