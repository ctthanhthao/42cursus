#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node *tree, const int val) const;
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &source);
		searchable_tree_bag &operator=(const searchable_tree_bag &other);
		~searchable_tree_bag();
		bool has(int) const;
};
#endif