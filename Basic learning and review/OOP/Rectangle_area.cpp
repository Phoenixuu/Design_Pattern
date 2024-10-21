#include<iostream>

class Rectangle{
public:
	double length;
	double width;

	double caculateArea(){
		return length * width;
	}

	double caculatePerimeter(){
		return (length + width) * 2;
	}
};

int main()
{
	Rectangle r1;
	r1.length = 5.0;
	r1.width = 4.0;
	double R1_area = r1.caculateArea();
	double R1_Perimeter = r1.caculatePerimeter();

	Rectangle r2;
	r2.length = 35;
	r2.width = 25;
	double R2_area = r2.caculateArea();
	double R2_Perimeter = r2.caculatePerimeter();

	std::cout << R1_area << std::endl;
	std::cout << R1_Perimeter << std::endl;
	std::cout << R2_area << std::endl;
	std::cout << R2_Perimeter << std::endl;

	return 0;
}