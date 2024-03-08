#include <iostream>
using namespace std;

class Parallelogram
{
	double base;
	double height;
	double side;
	unsigned int color;
public:
	Parallelogram() : base(5.0), height(3.0), side(6.0), color(0) {};

	Parallelogram(double Height) : base(5.0), side(6.0), color(0) {
		this->height = Height;
	};

	Parallelogram(double Base, double Height, double Side, int Color) {
		this->base = Base;
		this->height = Height;
		this->side = Side;
		if (Color >= 0) color = Color; else color = 0;
	}


	//base
	double getBase() const {
		return base;
	}
	void setBase(double base) {
		if (base < 0 || base > 1.e+100)
		{
			cout << " Error base! \n";
			return;
		}
		this->base = base;
	}

	//height
	double getHeight() const {
		return height;
	}
	void setHeight(double height) {
		if (height < 0 || height > 1.e+100)
		{
			cout << " Error height! \n";
			return;
		}
		this->height = height;
	}

	// side
	double getSide() const {
		return side;
	}
	void setSide(double side) {
		if (side < 0 || side > 1.e+100)
		{
			cout << "Error side! \n";
			return;
		}
		this->side = side;
	}

	//color
	double getColor() const {
		return color;
	}
	void setColor(int color) {
		if (color < 0 || color > 10000)
		{
			cout << " Error color! \n";
			return;
		}
		this->color = color;
		this->color = color;
	}
	// functions
	double S() {
		return base * height;
	}
	double P() {
		return 2 * base + 2 * side;
	}
	void printInfo()
	{
		cout << "\n Base = " << base << " Side = " << side << " Height = " << height << " Color = " << color << endl;
		cout << " S= " << S() << " P = " << P() << endl;
	}
};


int main()
{
	Parallelogram parallelogram1;
	cout << "Parallelogram 1:" << endl;
	parallelogram1.printInfo();
	Parallelogram parallelogram2(4.0);
	cout << "\nParallelogram 2:" << endl;
	parallelogram2.printInfo();
	Parallelogram parallelogram3(3.0, 5.0, 6.0, 500);
	cout << "\nParallelogram 3:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setBase(7.0);
	cout << "\nParallelogram 3 after setting base to 7.0:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setHeight(4.0);
	cout << "\nParallelogram 3 after setting height to 4.0:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setSide(8.0);
	cout << "\nParallelogram 3 after setting side to 8.0:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setColor(700);
	cout << "\nParallelogram 3 after setting color to 700:" << endl;
	parallelogram3.printInfo();
	return 0;
}

