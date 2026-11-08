#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


t_node* create_tree(void){
    return NULL;
}


t_node* create_node(char c){
    t_node *n = malloc(sizeof(t_node));
    if(n == NULL) return NULL;
    n->data = c;
    n->left = NULL;
    n->right = NULL;
    return n;
}



int insert_left(t_node *pai, char c){
    if(pai == NULL || pai->left != NULL) return 0;
    pai->left = create_node(c);
    return pai->left != NULL;
}

int insert_right(t_node *pai, char c){
    if(pai == NULL || pai->right != NULL) return 0;
    pai->right = create_node(c);
    return pai->right != NULL;
}

void pre_order(t_node *No){
    if(No != NULL){
        printf("%c\t", No->data);
        pre_order(No->left);
        pre_order(No->right);
    }
}

void in_order(t_node *No){
    if(No != NULL){
        in_order(No->left);
        printf("%c\t",No->data);
        in_order(No->right);
    }
}

void post_order(t_node *No){
    if(No != NULL){
        post_order(No->left);
        post_order(No->right);
        printf("%c\t", No->data);
    }
}

int tree_height(t_node *No){
    if(No == NULL){
        return -1;
    }
    //descobre a altura de cada lado
    int h_left = tree_height(No->left);
    int h_right = tree_height(No->right);

    //quem for maior ganha e soma 1 (o nivel atual)
    if(h_left > h_right){
        return h_left + 1;
    }else{
        return h_right + 1;
    }
}

int count_nodes (t_node *No){
    return No ? 1 + count_nodes(No->left) + count_nodes(No->right) : 0 ; // se o no for diferente de null, soma  1 + lado esquerdo + lado direito, senão 0;
}

int count_leaves( t_node *No){
    if(No == NULL){
        return 0;
    }
    if(No->left == NULL && No->right == NULL){
        return 1;
    }
    return count_leaves(No->left) + count_leaves(No->right);
}

void free_tree (t_node *No){
    if(No == NULL){
        return;
    }else{
    free_tree(No->left);
    free_tree(No->right);
    free(No);
    }    
}

int remove_left_leaf(t_node *pai){
    if(pai == NULL || pai->left == NULL) return 0;

    t_node *alvo = pai->left;
    if(alvo->left != NULL || alvo->right != NULL) return 0; // Não é folha

    free(alvo);
    pai->left = NULL;
    return 1;
}

int remove_right_leaf(t_node *pai){
    if(pai == NULL || pai->right == NULL) return 0;

    t_node *alvo = pai->right;
    if(alvo->right != NULL || alvo->left != NULL) return 0;

    free(alvo);
    pai->right = NULL;
    return 1;
}



