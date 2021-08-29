#include <matplot/matplot.h>
#include <algorithm>
#include <iterator>
#include <thread>
// #include <future>
// #include <mutex>
// #include <future>

// std::mutex mu;

void plot(matplot::axes_handle a, int i, double distance, double depth, double temp, int temp_max)
{
	using namespace matplot;

	int size = 20;
	if(depth==1) depth = -1233;
	// std::lock_guard<std::mutex> lock(mu);
	auto y = linspace(0 - size * 2.4, depth + size * 2.4, 100);
	auto x = transform(y, [&](double y)
					   { return distance; });
	auto c = linspace(temp_max, temp, y.size());
	auto l = scatter(a, x, y, size, c);
	l->marker_face(true);
	l->marker_style(line_spec::marker_style::square);
}

int main()
{
	using namespace matplot;

	auto f = gcf();
	f->height(f->height() * 2);
	f->width(f->width() * 2);
	f->title("Depth / Temperature");

	// tiledlayout(2, 1);
	// auto ax1 = nexttile();

	hold(on);
	std::vector<double> depth = {-1118, -714, -869, -900, -1105, -1264, -1115, -1234, -1222, -1345, -1497, -1741, -1534, -1311, -1196, -1499, -1683, -1527, -1235, -1118, -894, -869, -900, -1105, -1264, -1115, -1234, -1222, -1345, -1497, -1741, -1534, -1311, -1196, -1499, -1683, -1527, -1235, -1238};
	std::vector<double> distance = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 38000, 39000};
	std::vector<std::pair<double,std::string>> lines_vec;
	lines_vec.push_back(std::make_pair(13000,"-141.535, 185.972"));
	lines_vec.push_back(std::make_pair(26000,"231.498, 131.535"));
	std::vector<double> temp = {0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
	
	std::vector<double> temp_tick_values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	std::vector<std::string> temp_tick_labels = {"0 °C", "1 °C", "2 °C", "3 °C", "4 °C", "5 °C", "6 °C", "7 °C", "8 °C", "9 °C", "10 °C", "11 °C", "12 °C", "13 °C", "14 °C", "15 °C", "16 °C", "17 °C", "18 °C", "19 °C", "20 °C", "21 °C", "22 °C", "23 °C", "24 °C", "25 °C"};

	std::cout << depth.size() << " " << distance.size() << " " << temp.size() << std::endl;
	int temp_max = 23;
	auto min = *std::min_element(depth.begin(), depth.end());

	//
	for(int i = 0; i < temp.size(); ++i)
	{
		temp[i] = temp_max-depth.at(i)/min*temp_max;
	}
	//

	colormap(palette::jet());
	// std::vector<std::thread> ThreadVector;
	for (int i = 0; i < depth.size(); ++i)
	{
		auto a = gca();
		// ThreadVector.emplace_back([&](){plot(a, i, distance[i], depth[i], temp[i], temp_max);});
		// std::async(std::launch::async, plot, ax1, i, distance, depth, temp, temp0);
		plot(a, i, distance[i], depth[i], temp[i], temp_max);
	}
	// for(auto& t: ThreadVector)
	// {
	// 	t.join();
	// }

	// set labels properties
	auto a = gca();
	a->xtickangle(31);
	ylabel("Depth");
	a->y_axis().label_font_size(12);
	a->y_axis().label_weight("bold");
	xlabel("Distance");
	a->x_axis().label_font_size(12);
	a->x_axis().label_weight("bold");
	a->xtickformat("%g m");
	a->ytickformat("%g m");
	a->ylim({min * 1.1, 0});

	auto b = gca();
	xlim({0, *(distance.end()-1)+1000});
	b->x2ticks({13000,26000});
	b->x2ticklabels({"-141.535, 185.972","231.498, 131.535"});
	b->x2_axis().visible(1);

	// plot lines
	for(auto & i : lines_vec)
	{
		auto c = line(i.first, 0, i.first, -20000);
		c->color("black");
		c->line_width(1);
	}

	// print colorbar temperature
	colorbar()
		.limits({0, 25})
		.tick_values(temp_tick_values)
		.ticklabels(temp_tick_labels);
	hold(off);

	grid(on);

	show();

	save("img.jpg");

	return 0;
}
