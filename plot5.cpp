#include <matplot/matplot.h>
#include <random>

int main() {
    using namespace matplot;

    // auto x = linspace(0, 3 * pi, 20000);
    // auto y = transform(x, [&](double x) { return cos(x) + rand(0, 1); });
    // auto c = linspace(1, 10, x.size());

    // auto l = scatter(x, y, 6, c);
    // l->marker_face(true);
	// auto a = gca();
	auto a = line(5,0,5,-2000);
	a->color("black");
	// a->color("black");
	// plot(x,y)->color("black");

    show();
    return 0;
}