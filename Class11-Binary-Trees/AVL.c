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

Treenode* rotate_right(Treenode* root){
    Treenode* node = root->left;
    root->left = node->right;
    node->right = root;
    root = node;
    return root;
}

Treenode* rotate_left(Treenode* root){
    Treenode* node = root->right;
    root->right = node->left;
    node->left = root;
    root = node;
    return root;
}

int height(Treenode* root){
    if(isEmpty(root)){
        return 0;
    }
    else{
        int left_height;
        int right_height;
        left_height = height(root->left);
        right_height = height(root->right);

        if(left_height>right_height){
            return (1+left_height);
        }
        else{
            return (1+right_height);
        }
    }
}

int balanceFactor(Treenode* root){
    if(isEmpty(root)){
        return 0;
    }
    int balancefactor = height(root->left) - height(root->right);
    return balancefactor;
}

Treenode* balance(Treenode* root){
    int bf = balanceFactor(root);
    int lrbf = balanceFactor(root->left);
    int rrbf = balanceFactor(root->right);

    if(bf > 1 && lrbf >=0){
        return rotate_right(root);
    }

    if(bf < -1 && rrbf <= 0){
        return rotate_left(root);
    }

    if(bf > 1 && lrbf < 0){
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if(bf < -1 && rrbf > 0){
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

Treenode* insert (Treenode* root, int value){
    if(isEmpty(root)){
        return create_node(value);
    }
    
    if(value < root->value){
        root->left = insert(root->left, value);
    } else if(value > root->value) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    return balance(root);
}

// Helper function to find the node with the next minimum value
Treenode* min_value_node(Treenode* node) {
    Treenode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Treenode* delete_node(Treenode* root, int value) {
    if (isEmpty(root)) {
        return root;
    }

    if (value < root->value) {
        root->left = delete_node(root->left, value);
    } else if (value > root->value) {
        root->right = delete_node(root->right, value);
    } else {
        // Node to be deleted found
        if (isEmpty(root->left)) {
            Treenode* temp = root->right;
            free(root);
            root = temp;
        } else if (isEmpty(root->right)) {
            Treenode* temp = root->left;
            free(root);
            root = temp;
        } else {
            // Node with two children: Get the in-order successor
            Treenode* temp = min_value_node(root->right);
            root->value = temp->value;
            root->right = delete_node(root->right, temp->value);
        }
    }

    if (isEmpty(root)) return root; // If tree had only one node

    return balance(root); // Automatically re-balance the tree 
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

// Helper function to "draw" the nodes and branches in the matrix
void fill_matrix(Treenode* node, int row, int left, int right, char matrix[20][120]) {
    if (isEmpty(node) || row >= 20) return;
    
    // Finds the exact middle of the space allocated for this subtree
    int mid = (left + right) / 2;
    
    // Converts the integer value of the node to string (to know the size)
    char buffer[10];
    sprintf(buffer, "%d", node->value);
    int len = 0;
    while (buffer[len] != '\0') len++;
    
    // Positions the number centralized at 'mid'
    int start = mid - len / 2;
    for (int i = 0; i < len; i++) {
        if (start + i >= 0 && start + i < 119) {
            matrix[row][start + i] = buffer[i];
        }
    }
    
    // Draws the branches (if children exist and there's space in the matrix)
    if (!isEmpty(node->left) && row + 1 < 20) {
        matrix[row + 1][(left + mid) / 2] = '/';
    }
    if (!isEmpty(node->right) && row + 1 < 20) {
        matrix[row + 1][(mid + right) / 2] = '\\';
    }
    
    // Recursion for the children (skipping a row for the branch)
    fill_matrix(node->left, row + 2, left, mid, matrix);
    fill_matrix(node->right, row + 2, mid, right, matrix);
}

// Main function to print visually
void print_tree_visual(Treenode* root) {
    int h = height(root);
    if (h == 0) {
        printf("Tree is empty.\n");
        return;
    }
    
    // We calculate the maximum needed rows (nodes + branches)
    int rows = h * 2 - 1;
    if (rows > 20) rows = 20; // safety limit for the matrix
    int cols = 120; // max screen width (default size for many terminals)
    
    // Create our "screen" and fill it with empty spaces
    char matrix[20][120];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < cols - 1; j++) {
            matrix[i][j] = ' ';
        }
        matrix[i][cols - 1] = '\0'; // Null character at the end to ease printf
    }
    
    // Fill the screen recursively starting from the root node
    fill_matrix(root, 0, 0, cols - 2, matrix);
    
    // Print the ready screen!
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", matrix[i]);
    }
    printf("\n");
}

int count_even(Treenode* node) {
    if (isEmpty(node)) {
        return 0;
    }
    int even_left = count_even(node->left);
    int even_right = count_even(node->right);

    if ((node->value) % 2 == 0) {
        return (1 + even_left + even_right);
    } else {
        return (even_left + even_right);
    }
}

int count_leaves(Treenode* node) {
    if (isEmpty(node)) {
        return 0;
    }
    int leaves_left = count_leaves(node->left);
    int leaves_right = count_leaves(node->right);

    if (isEmpty(node->right) && isEmpty(node->left)) {
        return 1;
    } else {
        return (leaves_left + leaves_right);
    }
}

int count_one_child(Treenode* node) {
    if (isEmpty(node)) return 0;

    int one_child_left = count_one_child(node->left);
    int one_child_right = count_one_child(node->right);

    if ((!isEmpty(node->left) && isEmpty(node->right)) || (!isEmpty(node->right) && isEmpty(node->left))) {
        return (1 + one_child_left + one_child_right);
    } else {
        return (one_child_left + one_child_right);
    }
}

int is_equal(Treenode* a, Treenode* b) {
    if (isEmpty(a) && isEmpty(b)) return 1; // Both empty: they are equal
    if (isEmpty(a) || isEmpty(b)) return 0; // Only one is empty: they are different
    
    // If the values match, verify recursively left AND right
    if (a->value == b->value) {
        return is_equal(a->left, b->left) && is_equal(a->right, b->right);
    }
    
    return 0; // Different values
}

void in_order(Treenode* a) {
    if (isEmpty(a)) {
        return;
    }

    in_order(a->left);
    printf("%d ", a->value);
    in_order(a->right);
}

void pre_order(Treenode* a) {
    if (isEmpty(a)) {
        return;
    }

    printf("%d ", a->value);
    pre_order(a->left);
    pre_order(a->right);
}

void post_order(Treenode* a) {
    if (isEmpty(a)) {
        return;
    }

    post_order(a->left);
    post_order(a->right);
    printf("%d ", a->value);
}

int main(){

    Treenode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 14);
    root = insert(root, 16);
    root = insert(root, 17);
    root = insert(root, 18);
    root = insert(root, 19);
    root = insert(root, 21);

    print_tree(root);

    int tree_height = height(root);
    printf("Tree height: %d\n", tree_height);
    
    printf("\n--- Deleting Node 15 ---\n");
    root = delete_node(root, 15);
    print_tree(root);
    printf("New Tree height: %d\n", height(root));

    printf("\nVisual Tree:\n");
    print_tree_visual(root);

    printf("Number of even values in the tree: %d\n", count_even(root));
    printf("Number of leaves in the tree: %d\n", count_leaves(root));
    printf("Number of nodes with only one child: %d\n", count_one_child(root));

    Treenode* root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 20);
    
    int are_equal = is_equal(root, root2);
    are_equal == 1 ? printf("Tree 1 is equal to Tree 2.\n") : printf("Tree 1 is different from Tree 2.\n");

    printf("In-order: ");
    in_order(root);
    printf("\n");
    
    printf("Post-order: ");
    post_order(root);
    printf("\n");
    
    printf("Pre-order: ");
    pre_order(root);
    printf("\n");

    free_tree(root2);
    free_tree(root);

    return 0;
}