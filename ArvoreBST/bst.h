#ifndef BST_H
#define BST_H


typedef struct s_node{
    char data;
    struct s_node* left;
    struct s_node* right;
} t_node;


t_node* create_tree(void);
t_node* create_node(char c);
t_node* bst_insert(t_node* root, char c);
t_node* bst_remove(t_node* root,char c);
t_node* bst_search(t_node* root,char c);
t_node* bst_min(t_node* root);
t_node* bst_max(t_node* root);
int is_bst(t_node *root);
void pre_order(t_node* root);
void in_order(t_node* root);
void post_order(t_node* root);
int tree_height(t_node* root);
int count_nodes(t_node* root);
int count_leaves(t_node* root);
void free_tree(t_node* root);




#endif