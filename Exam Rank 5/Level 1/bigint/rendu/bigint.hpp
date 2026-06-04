#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

class bigint
{
	private:
		std::string numStr;

	public:
		bigint();
		bigint(const bigint &source);
		bigint(unsigned int num);
		bigint &operator=(const bigint &b);
		~bigint();

		std::string getStr() const;

		bigint operator+(const bigint &b) const;
		bigint &operator+=(const bigint &b);

		bigint &operator++(); //++x;
		bigint operator++(int); //x++;

		bigint operator<<(unsigned int num) const;
		bigint &operator<<=(unsigned int num);
		bigint operator>>(unsigned int num)const;
		bigint &operator>>=(const bigint &b);

		bool operator<(const bigint &b) const;
		bool operator>(const bigint &b) const;
		bool operator==(const bigint &b) const;
		bool operator!=(const bigint &b) const;
		bool operator<=(const bigint &b) const;
		bool operator>=(const bigint &b) const;
};
std::ostream &operator<<(std::ostream &out, const bigint &bi);
#endif