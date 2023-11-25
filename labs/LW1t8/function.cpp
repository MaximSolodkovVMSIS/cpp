#include "Header.h"

circle::circle(double r){
	this->radius = r;
	//std::cout << "radius of circle: " << radius << " was create" << std::endl;
}
circle::~circle(){
	//std::cout << "circle with radius: " << radius << " was delete" << std::endl;
}

circle& circle::operator+=(const circle& other) {
	radius += other.radius;
	return *this;
}

circle circle::operator+(const circle& other)
{
	return circle(radius + other.radius);
}

double circle::Length(circle& c1, circle& c2)
{
	return c1.Length() - c2.Length();
}

double circle::Length() {
	return 2 * pi * radius;
}
double circle::Square() {
	return radius * radius * pi;
}
void circle::Output() {
	std::cout << "radius: " << radius << std::endl;
	std::cout << "length of circle: " << Length() << std::endl;
	std::cout << "square of circle: " << Square() << std::endl;
}

void circle::SetRadius(const double r) {
	this->radius = r;
}

double circle::GetRadius() {
	return radius;
}
