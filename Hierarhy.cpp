#include <iostream>
#include <math.h>

using namespace std;

class CPolygon {
protected:
		string Name;
		int Long;
		int Width;
	public:
	CPolygon() {
		Name = "CPolygon";
		Long = 5;
		Width = 10;
	}
	CPolygon(int long_, int width_) {
		Name = "CPolygon";
		Long = long_;
		Width = width_;
	}
	virtual ~CPolygon(){}
	virtual double Area(){}
	virtual void Show() {
		cout<< "Shape: " << Name <<endl;
		cout<< "Width: " << Width << endl;
		cout << "Area: " << Area() << endl;
	}
};

class CTriangle :public CPolygon
{
public:
	CTriangle() {
		Name="TRIANGLE";
	}
	double Area()
	{
		double Area;
		return Area=Long*Width/2;
	}
	void Show()
	{
		cout << "Shape: " << Name <<endl;
		cout << "Height: " << Long << endl;
		cout << "Width: " << Width << endl;
		cout << "Area: " << Area() << endl;
	}
};
class CRectangle: public CTriangle {
public:
	CRectangle() {
		Name="RECTANGLE";
	}
	double Area()
	{
		double Area;
		return Area = Long * Width;
	}
	void Show()
	{
		cout<< "Shape:" << Name <<endl;
		cout<< "Size of line: " << Long <<endl;
		cout << "Width:" << Width << endl;
		cout << "Area:" <<Area()<<endl;
	}
};

class CSquare: public CRectangle {
public:
	CSquare() {
		Name = "Square";
	}
	double Area() {
		double Area;
		return Area = Width * Width;
	}
};

class CQuadrangle: public CPolygon {
	int a; int b; int c; int d;
	double alfa;
	double betta;
public:
	CQuadrangle(int c_, int d_, double alfa_, double betta_) : a(Long), b(Width) {
		Name = "Quadrangle";
		c = c_;
		d = d_;
		alfa = alfa_;
		betta = betta_;
	}
	double half_perimetr() {
		return ((a + b + c + d) / 2);
	}
	double Area() {
		double p = half_perimetr();
		double pow_ = pow(cos((alfa + betta)/ 2), 2);
		return sqrt((p - a)*(p - b) * (p - c) * (p - d) - a* b * c * d * pow_);
	}
};


int main() {
	std::string shape = "";
	// CPolygon *POL[4];
	std::unique_ptr<CPolygon[]> POL = std::make_unique<CPolygon[]>(4);
	for (size_t i = 0; i < 4; ++i) {
		std::cin >> shape;
		if(!strcmp(shape.c_str(), "Triangle")) {
			POL[i] = new CTriangle();
			POL[i]->Area();
			POL[i]->Show();
		}
		else if(!strcmp(shape.c_str(), "Rectangle")) {
			POL[i] = std::make_unique<CRectangle>();
			// POL[i] = new CRectangle();
			POL[i]->Area();
			POL[i]->Show();
		}
		else if(!strcmp(shape.c_str(), "Square")) {
			POL[i] = new CSquare();
			POL[i]->Area();
			POL[i]->Show();
		}
		else if(!strcmp(shape.c_str(),"CQuadrangle")) {
			int c, d;
			double alfa, betta;
			std::cin >> c >> d >> alfa >> betta;
			POL[i] = new CQuadrangle(c, d, alfa, betta);
			POL[i]->Area();
			POL[i]->Show();
		}
	}

	for(int j = 0; j < 4; j++) {
		delete POL[j];
	}
	return 0;
}