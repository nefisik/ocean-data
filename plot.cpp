#include <matplot/matplot.h>
#include <algorithm>
#include <iterator>

int main()
{
	using namespace matplot;

	auto f = gcf();
	f->height(f->height() * 2.4);
	f->width(f->width() * 2.4);
	// f->title("Line #1");

	// tiledlayout(2, 2);
	auto ax1 = nexttile();

	hold(on);
	std::vector<double> depth = {-1118, -714, -869, -900, -1105, -1264, -1115, -1234, -1345, -1497, -1741, -1534, -1311, -1196, -1499, -1683, -1527, -1235, -1238};
	std::vector<double> distance = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000};
	std::vector<double> geography = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000};
	// std::vector<double> geography = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000};
	std::vector<double> temp = {6, 8, 7, 7, 6, 5, 6, 5, 4, 4, 3, 4, 5, 6, 7, 5, 4, 5, 7, 7};
	std::vector<double> lats;
	std::vector<double> lons;
	int temp0 = 23;
	auto min = *std::min_element(depth.begin(), depth.end());
	for (int i = 0; i < depth.size(); ++i)
	{
		colormap(ax1, palette::jet());
		auto y = linspace(0-21, depth.at(i)+21, 10);
		auto x = transform(y, [&](double y)
						   { return distance.at(i); });
		auto c = linspace(temp0, temp.at(i), y.size());
		auto l = scatter(ax1, x, y, 15, c);
		l->marker_face(true);
		l->marker_style(line_spec::marker_style::square);
	}

	// set labels properties
	auto a = gca();
		a->xtickangle(31);
	ylabel(ax1, "Depth");
		a->y_axis().label_font_size(12);
		a->y_axis().label_weight("bold");
	xlabel(ax1, "Distance");
		a->x_axis().label_font_size(12);
		a->x_axis().label_weight("bold");
	xtickformat("%g m");
	ytickformat("%g m");
	ylim({min*1.1, 0});
	// title(ax1, "Line 1");

	auto b = gca();
	xlim({0,20000});
	x2lim({0, 20000});
		b->x2ticks(geography);

	std::vector<std::string> s;
	std::string str;
	for(int i = 0; i < geography.size(); ++i) {
		str = std::to_string(geography.at(i)) + ", " + std::to_string(geography.at(i));
		s.push_back(str);
	}
	b->x2ticklabels(s);
	b->x2_axis().tickangle(200);
	// b->x2_axis().reverse(0);
	// b->x2_axis().tick_rotate_string();
	b->x2_axis().visible(1);

	// print colorbar temperature
	colorbar()
		.limits({0, 25})
        .tick_values({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25})
        .ticklabels({"0 °C","1 °C","2 °C","3 °C","4 °C","5 °C","6 °C","7 °C","8 °C","9 °C","10 °C","11 °C","12 °C","13 °C","14 °C","15 °C","16 °C","17 °C","18 °C","19 °C","20 °C","21 °C","22 °C","23 °C","24 °C","25 °C"});
	hold(off);

	// auto ax2 = nexttile();
	// hold(on);
	// std::vector<double> depth2 = {-1118, -714, -869, -900, -1105, -1264, -1115, -1234, -1345, -1497, -1741, -1534, -1311, -1196, -1499, -1683, -1527, -1235, -1238};
	// std::vector<double> distance2 = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000};
	// auto min2 = *std::min_element(depth2.begin(), depth2.end());
	// for(int i = 0; i < depth2.size(); ++i)
	// {
	// 	auto y = linspace(0, min2, 100);
	// 	auto x = transform(y, [&](double y) { return distance2.at(i); });
	// 	auto c = linspace(35, 1, y.size());
	// 	auto l = scatter(ax2, x, y, 15, c);
	// 	l->marker_face(true);
	// 	l->marker_style(line_spec::marker_style::square);

	// 	y = linspace(depth2.at(i),min,100);
	// 	auto a2 = plot(ax2, x,y);
	// 	a2->line_width(15);
	// 	a2->marker_style(line_spec::marker_style::square);
	// 	a2->color("w");
	// }
	// hold(off);

	// xtickformat(ax2, "%g m");
	// ytickformat(ax2, "%g m");

	// for(int i = 0; i < distance.size(); ++i)
	// {
	// 	text(ax2, distance.at(i),175,"lat\\nlon")->alignment(labels::center);
	// }
	// ylabel(ax2, "Depth");
	// xlabel(ax2, "Distance");
	// title(ax2, "Line 2");
	// colorbar().label("Temperature");

	// hold(off);

	// auto ax3 = nexttile();
	// geoplot(ax3, vector_1d{61.62, 52.20}, vector_1d{-122.33, -114.90}, "g-*");
	// geolimits(ax3, {40, 60}, {-150, -100});

	// auto ax4 = nexttile();
	// geoplot(ax4, vector_1d{52.20, 56.30}, vector_1d{-114.90, -125.90}, "g-*");
	// geolimits(ax4, {40, 60}, {-150, -100});
	grid(on);
	// gca()->gr

	show();

	save("img.jpg");

	return 0;
}
