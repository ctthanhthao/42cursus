#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &source) : tree_bag(source){}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return (*this);
}
		
searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::search(node *tree, const int val) const
{
	if (tree == 0)
		return (false);
	if (tree->value == val)
		return (true);
	if (val < tree->value)
		return search(tree->l, val);
	else
		return search(tree->r, val);
}
bool searchable_tree_bag::has(int val) const
{
	return (search(this->tree, val));
}