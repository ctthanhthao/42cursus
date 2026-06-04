#include "bigint.hpp"

bigint::bigint(): numStr("0"){}

bigint::bigint(const bigint &source)
{
	*this = source;
}
		
bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->numStr = ss.str();
}

bigint &bigint::operator=(const bigint &b)
{
	if (this != &b)
	{
		this->numStr = b.numStr;
	}
	return (*this);
}
		
bigint::~bigint(){};

std::string bigint::getStr() const
{
	return (this->numStr);
}

unsigned int stringToUInt(std::string &str)
{
	unsigned int num;
	std::stringstream ss(str);
	ss >> num;
	return (num);
}

std::string addition(std::string s1, std::string s2)
{
	int l1 = s1.length() - 1;
	int l2 = s2.length() - 1;
	int d1;
	int d2;
	int carry = 0;
	int sum;
	std::string result;
	while (l1 >= 0 || l2 >= 0 || carry > 0)
	{
		d1 = (l1 < 0) ? 0 : s1[l1] - '0';
		d2 = (l2 < 0) ? 0 : s2[l2] - '0';
		sum = d1 + d2 + carry;
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
		l1--;
		l2--;
	}
	std::reverse(result.begin(), result.end());
	return (result);
}

bigint bigint::operator+(const bigint &b) const
{
	bigint reInt;
	reInt.numStr = addition(this->numStr, b.numStr);
	return (reInt);
}

bigint &bigint::operator+=(const bigint &b)
{
	*this = *this + b;
	return (*this);
}

bigint &bigint::operator++()
{
	*this = *this + bigint(1);
	return (*this);
}
bigint bigint::operator++(int)
{
	bigint tmp(*this);
	*this = *this + bigint(1);
	return (tmp);
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint re(*this);
	re.numStr.insert(re.numStr.end(), n, '0');
	return (re);
}
		
bigint &bigint::operator<<=(unsigned int num)
{
	*this = (*this) << num;
	return(*this);
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint tmp(*this);
	size_t len = tmp.numStr.length();
	if (n >= len)
		tmp.numStr = "0";
	else
		tmp.numStr.erase(len - n, n);
	return (tmp);
}
		
bigint &bigint::operator>>=(const bigint &b)
{
	bigint tmp(b);
	*this = (*this) >> stringToUInt(tmp.numStr);
	return(*this);
}

bool bigint::operator<(const bigint &b) const
{
	std::string s1 = this->numStr;
	std::string s2 = b.numStr;
	size_t l1 = s1.length();
	size_t l2 = s2.length();
	if (l1 != l2)
		return (l1 < l2);
	else
		return (s1 < s2);
}

bool bigint::operator>(const bigint &b) const
{
	return (!((*this) < b));
}

bool bigint::operator==(const bigint &b) const
{
	if(this->numStr == b.getStr())
		return (true);
	return (false);
}

bool bigint::operator!=(const bigint &b) const
{
	return (!(*this == b));
}
		
bool bigint::operator<=(const bigint &b) const
{
	return (*this == b || *this < b);
}
		
bool bigint::operator>=(const bigint &b) const
{
	return (*this > b || *this == b);
}

std::string removeLeadingZero(std::string s)
{
	int len = s.length();
	std::string result;

	if (len == 0)
		return 0;
	if (len == 1 && s[0] == '0')
		return ("0");
	int i = 0;
	while (s[i] == '0')
		i++;
	while (i < len)
	{
		result.push_back(s[i]);
		i++;
	}
	return (result);
}

std::ostream &operator<<(std::ostream &out, const bigint &bi)
{
	out << removeLeadingZero(bi.getStr());
	return (out);
}