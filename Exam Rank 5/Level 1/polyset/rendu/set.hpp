#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set : public bag
{
	private:
		searchable_bag &s_bag;
		set();
		set(const set &source);
		set &operator=(const set &other);
	public:
		set(searchable_bag &s_bag);
		~set();

		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();
		bool has(int) const;

		const searchable_bag &get_bag();
};

#endif