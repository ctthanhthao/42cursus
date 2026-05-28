#include "bigint.hpp"

bigint::bigint()
{
	this->str = "0";
}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->str = ss.str();
	 std::cout << "str: " << str << std::endl;
}

bigint::bigint(const bigint& source)
{
	(*this) = source;
}

bigint& bigint::operator=(const bigint& source)
{
	if(this == &source)
		return(*this);
	this->str = source.str;
	return(*this);
}

std::string bigint::getStr() const
{
	return(this->str);
}

std::string addition(const bigint& a, const bigint& b)
{
    const std::string& s1 = a.getStr();
    const std::string& s2 = b.getStr();

    int i = s1.size() - 1;
    int j = s2.size() - 1;

    int carry = 0;
    std::string result;

    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? s1[i] - '0' : 0;
        int digit2 = (j >= 0) ? s2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        result.push_back((sum % 10) + '0');

        i--;
        j--;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

bigint bigint::operator+(const bigint& other)const
{
	std::string result = addition(*this, other);
	//std::cout << "r: " << result << std::endl;

	return(bigint(stringToUINT(result)));
}

bigint& bigint::operator+=(const bigint& other)
{
	(*this) = (*this) + other;
	return(*this);
}

bigint& bigint::operator++()
{
	*(this) = *(this) + bigint(1);
	return(*this);
}

bigint bigint::operator++(int)
{
	bigint temp = (*this);
	*(this) = *(this) + bigint(1);
	return(temp);
}


bigint bigint::operator<<(unsigned int n)const
{
	bigint temp = *this;

	temp.str.insert(temp.str.end(), n, '0');
	//std::cout << temp.str << std::endl;
	return(temp);
}

bigint bigint::operator>>(unsigned int n)const
{
	bigint temp = *this;
	size_t len = temp.str.length();
	if(n >= len)
		temp.str = "0";
	else
	{
		temp.str.erase(temp.str.length() - n, n); // ilk parametre: silme yapacağın yerin başlangıç indexi, diğeri: kaç tane eleman silinecek
	}
	return(temp);
}

bigint& bigint::operator<<=(unsigned int n)
{
	(*this) = (*this) << n;
	return(*this);
}

bigint& bigint::operator>>=(unsigned int n)
{
	(*this) = (*this) >> n;
	return(*this);
}

unsigned int stringToUINT(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

bigint bigint::operator<<(const bigint& other)const
{
	bigint temp;
	temp = (*this) << stringToUINT(other.str);
	return(temp);
}

bigint bigint::operator>>(const bigint& other)const
{
	bigint temp;
	temp = (*this) >> stringToUINT(other.str);
	return(temp);
}

bigint& bigint::operator<<=(const bigint& other)
{
	(*this) = (*this) << stringToUINT(other.str);
	return(*this);
}

bigint& bigint::operator>>=(const bigint& other)
{
	(*this) = (*this) >> stringToUINT(other.str);
	return(*this);
}


bool bigint::operator==(const bigint& other) const
{
	if(this->getStr() == other.getStr())
		return(true);
	return(false);
}

bool bigint::operator!=(const bigint& other) const
{
	return(!((*this) == (other)));
}

bool bigint::operator<(const bigint& other) const
{
	std::string str1 = this->str;
	std::string str2 = other.getStr();
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	if(len1 != len2)
		return(len1 < len2);
	return(str1 < str2);  // thanks for your feedback, mjuicha!! o7
}

bool bigint::operator>(const bigint& other) const
{
	return(!(((*this) < other)));
}

bool bigint::operator<=(const bigint& other) const
{
	return((((*this) < other) || ((*this) == other)));
}

bool bigint::operator>=(const bigint& other) const
{
	return((((*this) > other) || ((*this) == other)));
}

// non member func
std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return(output);
}
