#include "set.hpp"

set::set(searchable_bag &bag): s_bag(bag){}
		
set::~set(){}

void set::insert(int val)
{
	s_bag.insert(val);
}

void set::insert(int *data, int s)
{
	s_bag.insert(data, s);
}
		
void set::print() const
{
	s_bag.print();

}
void set::clear()
{
	s_bag.clear();
}

bool set::has(int val) const
{
	return s_bag.has(val);
}

const searchable_bag &set::get_bag()
{
	return this->s_bag;
}