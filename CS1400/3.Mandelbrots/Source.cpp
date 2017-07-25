/*
For each pixel on the screen do:
{
x0 = scaled x coordinate of pixel (must be scaled to lie somewhere in the mandelbrot X scale (-2.5, 1)
y0 = scaled y coordinate of pixel (must be scaled to lie somewhere in the mandelbrot Y scale (-1, 1)

x = 0
y = 0

iteration = 0
max_iteration = 1000

while ( x*x + y*y < 2*2  AND  iteration < max_iteration )
{
xtemp = x*x - y*y + x0
y = 2*x*y + y0

x = xtemp

iteration = iteration + 1
}

color = iteration

plot(x0,y0,color)
}

*/

//declare includes
#include <fstream>
#include <cstdlib>

//declare constants
auto const MAX_ITER = 1000;
auto const SIZE = 512;

int mandelbrot(double x0, double y0)
{
	auto x = 0.0;
	auto y = 0.0;
	auto iter = 0;
	while (x*x + y*y < 4 && iter < MAX_ITER)
	{
		auto xtemp = x*x - y*y + x0;
		y = 2 * x*y + y0;
		x = xtemp;
		++iter;
	}
	return iter;
}


int main(void)
{

	//insert three 'doubles' from a text file called mandelinput.txt, of c1.real, c1.imag, and c2. real
	std::ifstream fin("mandelinput.txt");
	double xMin, yMin, width;
	fin >> xMin >> yMin >> width;
	std::ofstream fout("mandelbrot.ppm");
	fout << "P3" << std::endl;
	fout << SIZE << std::endl;
	fout << 256 << std::endl;
	// c2.imag should be calculated as c1.imag + (c1.real-c2.real)
	// do something for the width of the screen
	for (auto i = 0; i < SIZE; ++i)
	{
		// do the same thing for the legth of the screen
		for (auto j = 0; j < SIZE; ++j)
		{
			// do things to each pixel...
			auto x = xMin + i*((xMin + width) / SIZE);
			auto y = yMin + j*((yMin + width) / SIZE);
			//  ... Mandelbrot stuff
			auto n = mandelbrot(x, y);
			n = 256 - n;
			//color each pixel, output to ppm
			int r = (n % 256);
			int g = (n % 256);
			int b = (n % 256);

			fout << r << " " << g << " " << b << " ";


		}
		fout << std::endl;
	}
	fout.close();
	return EXIT_SUCCESS;
}
