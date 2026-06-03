#include "vect2.hpp"

vect2::vect2(): x(0), y(0){}

vect2::vect2(int x, int y) : x(x), y(y){}

int vect2::getx() const
{
	return this->x;
}
int vect2::gety() const
{
	return this->y;
}

vect2::vect2(const vect2 &source)
{
	*this = source;
}

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

vect2::~vect2(){}

vect2 vect2::operator+(const vect2 &v2) const
{
	vect2 re(*this);
	re.x = re.x + v2.x;
	re.y = re.y + v2.y;
	return (re);
}

vect2 &vect2::operator+=(const vect2 &v2)
{
	this->x = this->x + v2.x;
	this->y = this->y + v2.y;
	return(*this);
}
		
vect2 vect2::operator-(const vect2 &v2) const
{
	vect2 re(*this);
	re.x = re.x - v2.x;
	re.y = re.y - v2.y;
	return (re);
}
		
vect2 vect2::operator-() const
{
	vect2 re(*this);
	re.x = 0 - re.x;
	re.y = 0 - re.y;
	return (re);
}

vect2 &vect2::operator-=(const vect2 &v2)
{
	this->x = this->x - v2.x;
	this->y = this->y - v2.y;
	return(*this);
}
		
vect2 vect2::operator*(int n) const
{
	vect2 re(*this);
	re.x = re.x * n;
	re.y = re.y * n;
	return (re);
}
		
vect2 &vect2::operator*=(int n)
{
	this->x = this->x * n;
	this->y = this->y * n;
	return(*this);
}

int vect2::operator[](int idx) const
{
	vect2 re(*this);
	if (idx == 0)
		return re.x;
	return re.y;
}

int &vect2::operator[](int idx)
{
	if (idx == 0)
		return this->x;
	return this->y;
}

vect2 &vect2::operator--()
{
	this->x = this->x - 1;
	this->y = this->y - 1;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 re(*this);
	this->x = this->x - 1;
	this->y = this->y - 1;
	return (re);
}

vect2 &vect2::operator++()
{
	this->x = this->x + 1;
	this->y = this->y + 1;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 re(*this);
	this->x = this->x + 1;
	this->y = this->y + 1;
	return (re);
}

bool vect2::operator==(const vect2 &v2) const
{
	if (this->x == v2.x && this->y == v2.y)
		return (true);
	return (false);
}
bool vect2::operator!=(const vect2 &v2) const
{
	return (!(*this == v2));
}

vect2 operator*(int n, vect2 v)
{
	return (vect2(n * v.getx(), n * v.gety()));
}

std::ostream &operator<<(std::ostream &out, vect2 v)
{
	std::cout << "{" << v[0] << ", " << v[1] << "}";
	return (out); 
}