#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include <cstdlib>
#include <iostream>
#include "set.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		return 1;
	searchable_bag *t = new searchable_tree_bag;
	searchable_bag *a = new searchable_array_bag;
	for (int i = 1; i < ac; i++)
	{
		t->insert(atoi(av[i]));
		a->insert(atoi(av[i]));
	}
	t->print();
	a->print();
	for (int i = 1; i < ac; i++)
	{
		std::cout << t->has(atoi(av[i])) << std::endl;
		std::cout << a->has(atoi(av[i])) << std::endl;
		std::cout << t->has(atoi(av[i]) - 1) << std::endl;
		std::cout << a->has(atoi(av[i]) - 1) << std::endl;
	}
	t->clear();
	a->clear();
	const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
	std::cout << "===== print tmp =============" << std::endl;
	tmp.print();
	std::cout << "===== tmp has 1 : "<< tmp.has(1) << std::endl;
	set sa(*a);
	set st(*t);
	for (int i = 1; i < ac; i++)
	{
		st.insert(atoi(av[i]));
		sa.insert(atoi(av[i]));
	}
	sa.has(atoi(av[1]));
	sa.print();
	sa.get_bag().print();
	st.print();
	sa.clear();
 	int arr[] = {1, 2, 3, 4,};
	sa.insert(arr, 4);
	delete t;
	delete a;
}