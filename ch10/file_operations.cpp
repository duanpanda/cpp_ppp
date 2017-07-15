#include "../std_lib_facilities.h"

class Point
{
public:
	double x;
	double y;

	Point()
	{
		x = 0.0;
		y = 0.0;
	}

	Point(double px, double py)
	{
		x = px;
		y = py;
	}

	friend istream& operator>>(istream &input, Point &p)
	{
		input >> p.x >> p.y;
		return input;
	}
};

int main()
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("can't open input file ", iname);

	vector<Point> points;
	for (Point p; ist >> p;)
		points.push_back(p);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open output file ", oname);

	for (Point p : points)
		ost << '(' << p.x << ',' << p.y << ")\n";

	return 0;
}

void fill_from_file(vector<Point>& points, string& name)
{
	ifstream ist{ name }; // open file for reading
	if (!ist) error("can't open input file ", name);
	// ... use ist ...
	// the file is implicitly closed when we leave the function
}
