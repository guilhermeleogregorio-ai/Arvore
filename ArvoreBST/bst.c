#include <stdlib.h>
#include "bst.h"

t_node* create_tree(void){
    return NULL;
}

t_node* create_tree(char c){
    t_node *n = malloc(sizeof(t_node));
    if(n == NULL) return NULL;
    n->data = c;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void pre_order(t_node *No){
    printf("%c\t", No->data);
    pre_order(No->left);
    pre_order(No->right);
}

void in_order(t_node *No){
    in_order(No->left);
    printf("%c\t", No->data);
    in_order(No->right);
}

void post_order(t_node *No){
    post_order(No->left);
    post_order(No->right);
    printf("%c\t", No->data);
}

int tree_height(t_node *No){
        if(No == NULL) return -1;
        int e = tree_height(No->left);
        int d = tree_height(No->right);
        return (e > d ?  : d ) + 1;
}

int count_nodes(t_node *No){
    return No ? 1 + count_nodes(No->left) + count_nodes(No->right) : 0;
}

int count_leaves(t_node *No){
    if(No == NULL) return 0;
    if(No->left == NULL || No->right == NULL) return 1;
    return count_leaves(No->left) + count_leaves(No->right);
}

void free_tree(t_node *No){
    if(No == NULL) return;
    free_tree(No->left);
    free_tree(No->right);
    free(No);
}

t_node* bst_insert(t_node *root, char c){
    if(root == NULL){
        return create_node(c);
    }

    if(c < root->data){
        root->left = bst_insert(root->left,c);
    }else if(c > root->data){
        root->right = bst_insert(root->right,c);
    }

    return root;
}

t_node* bst_search(t_node *No, char c){
    if(No == NULL || No->data == c) return No;
    return ( c < No->data) ? bst_search(No->left, c) : bst_search(No->right, c);
}

t_node* bst_min(t_node *No){
    if(No == NULL) return NULL;
    while (No->left != NULL){
        No = No->left;
    }
    return No;
}

t_node* bst_max(t_node *No){
    if(No == NULL) return NULL;
    while (No->right != NULL){
        No = No->right;
    }
    return No;
}

t_node* bst_remove(t_node *No, char c){
     if(No == NULL) return NULL;

     if(c < No->data){
        No->left = bst_remove(No->left,c);
     } else if( c > No->data){
        No->right = bst_remove(No->right, c);
     }else{  //achou o nó
        if(No->left == NULL){ //caso sem filho esquerdo
            t_node *tmp = No->right;
            free(No);
            return tmp;
        }

        if(No->right == NULL){ //caso sem filho direito
            t_node *tmp = No->left;
            free(No);
            return tmp;
        }
                                        //caso dois filhos, usa o sucessor(menor da direita)
        t_node *succ = bst_min(No->right);
        No->data = succ->data;
        No->right = bst_remove(No->right, succ->right);
     }
     return No;
}

static int is_bst_util(t_node *No, char *min, char *max){
    if(No == NULL) return 1;
    
    if(min && No->data <= *min) return 0; //violou o limite inferior
    if(max && No->data >= *max) return 0; //violou o limite supeior

    return is_bst_util(No->left, min, &No->data) && is_bst_util(No->right, &No->data, max);

 }

 int is_bst(t_node *No){
    return is_bst_util(No,NULL,NULL);
 }