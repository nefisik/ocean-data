#include <matplot/matplot.h>

int main() {
    using namespace matplot;

	std::vector<double> depth = {-1118, -714, -869, -900, -1105, -1264, -1115, -1234, -1345, -1497, -1741, -1534, -1311, -1196, -1499, -1683, -1527, -1235, -1238};
	std::vector<double> distance = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000};
	std::vector<double> temp = {6, 8, 7, 7, 6, 5, 6, 5, 4, 4, 3, 4, 5, 6, 7, 5, 4, 5, 7, 7};
	int temp_max = 23;

colormap(palette::jet());
	auto x = linspace(0, 20000, 1000);
	// auto x = transform(y, [&](double y)
	// 				   { return distance; });
	// auto c = linspace(temp_max, 0);
	// auto l = scatter(x, depth, 15, c);
	// l->marker_face(true);
	// l->marker_style(line_spec::marker_style::square);
	// std::cout << l-> << std::endl;
	plot3(distance, depth);

	// auto a = gca();
	// a->scatter(x, y, 15, c)->x;
	show();
}