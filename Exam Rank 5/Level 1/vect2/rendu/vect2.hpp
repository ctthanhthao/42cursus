#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &source);
		vect2 &operator=(const vect2 &other);
		int getx() const;
		int gety() const;
		~vect2();

		vect2 operator+(const vect2 &v2) const;
		vect2 &operator+=(const vect2 &v2);
		vect2 operator-(const vect2 &v2) const;
		vect2 operator-() const;
		vect2 &operator-=(const vect2 &v2);
		vect2 operator*(int n) const;
		vect2 &operator*=(int n);

		int operator[](int idx) const;
		int &operator[](int idx);

		vect2 &operator--();
		vect2 operator--(int);
		vect2 &operator++();
		vect2 operator++(int);

		bool operator==(const vect2 &v2) const;
		bool operator!=(const vect2 &v2) const;

};
vect2 operator*(int n, vect2 v);
std::ostream &operator<<(std::ostream &out, vect2 v);
#endif