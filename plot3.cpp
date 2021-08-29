#include <matplot/matplot.h>

int main() {
    using namespace matplot;

    std::vector<std::vector<double>> Y = {
        {1, 3, 1, 2}, {3, 7, 3, 1}, {5, 2, 5, 6}};

    auto f = gcf();
    f->width(f->width() * 2);

    auto h1 = area(Y, 0.);
    h1[0]->line_style("|");
    h1[1]->line_style("|");
    h1[2]->line_style("|");
	// colormap(palette::jet());
	h1[0]->face_color({22, 22, 0.25, 0.25});
    h1[1]->face_color({0, 0, 0.9, 0.55});
    h1[2]->face_color({0, 0, 0.75, 0.75});
	colorbar();
	// h1[0]->color();
    // title("Stacked");


	auto a = gca();
	area(a, Y, 0.);


    show();
    return 0;
}