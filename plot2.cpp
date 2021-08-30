#include <matplot/matplot.h>

int main() {
    using namespace matplot;

	auto f = gcf();
	f->height(f->height() * 2);
	f->width(f->width() * 2);
	f->title("Salinity / Distance");

	std::vector<double> salinity = {34.1, 34.2, 34.3, 34.2, 34.6, 35.2, 34.3, 34.2, 34.3, 32.9, 34.2, 34.4, 34.6, 34.8, 34.9, 35.3, 35.6, 36.2, 36.1, 36.0, 36.1, 35.9, 35.7, 35.6, 35.4, 35.5, 35.2, 35.1, 35.2, 35.0, 34.8, 34.6, 34.4, 34.3, 34.5, 34.3, 34.1, 34.4, 34.5};
	std::vector<double> distance = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 38000, 39000};

	hold(on);
	plot(distance,salinity)->color("red");

	std::vector<std::pair<double,std::string>> lines_vec;
	lines_vec.push_back(std::make_pair(13000,"-141.535, 185.972"));
	lines_vec.push_back(std::make_pair(26000,"231.498, 131.535"));

	auto a = gca();
	a->xlim({0,40000});
	a->ylim({32,37});
	a->x2ticks({13000,26000});
	a->x2ticklabels({"-141.535, 185.972","231.498, 131.535"});
	a->x2_axis().visible(1);

	// plot lines
	for(auto & i : lines_vec)
	{
		auto c = line(i.first, 32, i.first, 37);
		c->color("black");
		c->line_width(1);
		c->visible(1);
	}
	hold(off);

    show();

	save("img2.jpg");

    return 0;
}