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

int isEmpty(Treenode* tree){
    if(tree == NULL) return 1;
    return 0;
}

Treenode* insert (Treenode* root, int value){
    if(isEmpty(root)){
        return create_node(value);
    }
    
    if(value < root->value){
        root->left = insert(root->left, value);
    } else if(value > root->value){
        root->right = insert(root->right, value);
    }
    
    return root;
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

    Treenode* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);

    print_tree(root);
    
    free_tree(root);

    return 0;
}