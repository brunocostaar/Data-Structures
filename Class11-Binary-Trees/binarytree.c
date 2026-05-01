#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
} Treenode;

Treenode* create_node (int value){
    Treenode* node = (Treenode*)malloc(sizeof(Treenode));
    if(node != NULL){
        node->left = NULL;
        node->right = NULL;
        node->value = value;
    }
    return node;
}

void link_node (Treenode* node, Treenode* parent_node, char lr){
    if(lr == 'r'){
        parent_node->right = node;
    }
    else{
        parent_node->left = node;
    }
}

Treenode* create_from_a_node (Treenode* parent_node, char lr, int value){
    Treenode* new_node = create_node(value);
    link_node(new_node, parent_node, lr);
    return new_node;
}

int isEmpty(Treenode* tree){
    if(tree == NULL) return 1;
    return 0;
}

void print_tree_inner(Treenode* node, int depth, const char* prefix){
    if(isEmpty(node)){
        return;
    }
    for(int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s%d\n", prefix, node->value);
    
    print_tree_inner(node->left, depth + 1, "L: ");
    print_tree_inner(node->right, depth + 1, "R: ");
}

void print_tree(Treenode* root){
    if(isEmpty(root)){
        printf("Tree is empty\n");
        return;
    }
    print_tree_inner(root, 0, "N1: ");
}

void free_tree(Treenode* root){
    if(isEmpty(root)){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(){

    Treenode* n1 = create_node(10);
    Treenode* n2 = create_from_a_node(n1, 'l', 11);
    Treenode* n3 = create_from_a_node(n1, 'r', 12);
    Treenode* n4 = create_from_a_node(n3, 'l', 13);
    Treenode* n5 = create_from_a_node(n3, 'r', 14);
    Treenode* n6 = create_from_a_node(n2, 'l', 15);

    print_tree(n1);
    
    free_tree(n1);

    return 0;
}