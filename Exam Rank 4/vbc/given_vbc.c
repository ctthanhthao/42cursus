#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

typedef struct s_parser
{
	char *s;
	int pos;
	char curr;
} t_parser;

node    *parse_expr(t_parser *p);

static void init_parser(t_parser *p, char *s)
{
	p->s = s;
	p->pos = 0;
	p->curr = s[0];
}

static void advance(t_parser *p)
{
	if (p->curr != '\0')
	{
		p->pos++;
		p->curr = p->s[p->pos];
	}
}

node    *new_node(node n)
{
	node *ret = calloc(1, sizeof(node));
	if (!ret)
		return (NULL);
	ret->type = n.type;
	ret->val = n.val;
	ret->l = NULL;
	ret->r = NULL;
	return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

node *parse_factor(t_parser *p)
{
	if (p->curr == '\0')
	{
		 printf("Unexpected end of file\n");
		 return (NULL);
	}
	if (p->curr == '(')
	{
		advance(p);
		node *group = parse_expr(p);
		if (!group)
			return (NULL);
		advance(p);
		if (p->curr != ')')
		{
			destroy_tree(group);
			unexpected(p->curr);
			return (NULL);
		}
		return (group);
	}
	if (isdigit(p->curr))
	{
		node val;
		val.type = VAL;
		node *val_pt = new_node(val);
		if (!val_pt)
			return (NULL);
		val_pt->val = p->curr - '0';
		val_pt->l = NULL;
		val_pt->r = NULL;
		return (val_pt);
	}
	else
		return (unexpected(p->curr), NULL);
}

node *parse_term(t_parser *p)
{
	node *l = parse_factor(p);
	if (!l)
		return (NULL);
	while (p->s[p->pos + 1] == '*')
	{
		advance(p);
		advance(p);
		node multi;
		multi.type = MULTI;
		node *multi_pt = new_node(multi);
		if (!multi_pt)
			return (destroy_tree(l), NULL);
		multi_pt->l = l;
		node *r = parse_factor(p);
		if (!r)
			return (destroy_tree(multi_pt), NULL);
		multi_pt->r = r;
		l = multi_pt;
	}
	return (l);
}

node    *parse_expr(t_parser *p)
{
	node *l = parse_term(p);
	if (!l)
		return (NULL);
	while (p->s[p->pos + 1] == '+')
	{
		advance(p);
		advance(p);
		node add;
		add.type = ADD;
		node *add_pt = new_node(add);
		if (!add_pt)
			return (destroy_tree(l), NULL);
		add_pt->l = l;
		node *r = parse_term(p);
		if (!r)
			return (destroy_tree(add_pt), NULL);
		add_pt->r = r;
		l = add_pt;
	}
	return (l);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
	return (0);
}

static int check_valid_group(char *s)
{
	int bal = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
			bal--;
		i++;
	}
	if (bal > 0)
		 printf("Unexpected token '('\n");
	else if (bal < 0)
		 printf("Unexpected token ')'\n");
	return (bal == 0);
}

int main(int argc, char **argv)
{
	t_parser p;

	if (argc != 2)
		return (1);
	init_parser(&p, argv[1]);
	node *tree = parse_expr(&p);
	if (!tree)
		return (1);
	if (!check_valid_group(argv[1]))
		return (destroy_tree(tree), 1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
}