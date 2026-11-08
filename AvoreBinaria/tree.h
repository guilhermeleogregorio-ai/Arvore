#ifndef TREE_H
#define TREE_H

typedef struct s_node {
    char data;   //guarda valor do 
    struct s_node* left;
    struct s_node* right;
}t_node;

t_node* create_tree(void);
t_node* create_node(char c);
int insert_left(t_node* root, char c);
int insert_right(t_node* root, char c);
int remove_left_promote (t_node* pai);
int remove_right_promote(t_node* pai);
void pre_order(t_node* root);
void in_order(t_node* root);
void post_order(t_node* root);
int tree_height(t_node* root);
int count_nodes(t_node* root);
int count_leaves(t_node* root);
void free_tree(t_node* root);
int remove_left_leaf(t_node* pai);
int remove_right_leaf(t_node* pai);

#endif