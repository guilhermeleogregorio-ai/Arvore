#ifndef BST_H
#define BST_H


typedef struct s_node{
    char data;
    struct s_node* left;
    struct s_node* right;
} t_node;


t_node* create_tree(void);
t_node* create_node(char c);




#endif