#include <matplot/matplot.h>

int main()
{
	using namespace matplot;

	std::vector<std::vector<double>> depth = {{-1118, -714, -869, -900, -1105, -1264, -1115, -1234, -1345, -1497, -1741, -1534, -1311, -1196, -1499, -1683, -1527, -1235, -1238}};

	auto f = gcf();
	f->width(f->width() * 2);

// 	int n = 50;               // number of colors

// auto R = linspace(1,0,n);  // Red from 1 to 0
// auto B = linspace(0,1,n);  // Blue from 0 to 1
// auto G = zeros(R.size());   // Green all zero
	colormap(palette::jet());
	// figure(1);
	auto a = gca();
	// a->scatter();
	// subplot(1, 2, 0);
	a->area(depth);
	// scatter()
	a->colormap_interpolation(100, -500, 0);
	a->colormap(palette::jet());
	a->handle_visibility(1);
	a->grid(1);
	a->line()
	// a->sur
// pcolor();

	// subplot(1, 2, 1);
	// area(Y, false);
	// title("Not stacked");

	show();
	return 0;
}
