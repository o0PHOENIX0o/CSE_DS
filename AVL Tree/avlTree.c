//AVL
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
    int height;
} Node;

Node* root = NULL;

int max(int a, int b);
Node *CreateNode(int val);
int getHeight(Node *n);
int getBalanceFactor(Node *n);
void insert(Node **node, int val);
int Search(Node *node, int val);
void InOrderTraversal(Node *root);


int main(){

    printf("Insertion: ");
    insert(&root, 10);
    insert(&root, 15);
    insert(&root, 5);
    insert(&root, 55);
    insert(&root, 35);

    InOrderTraversal(root);

    printf("\n");

    (Search(root, 35)) ? printf("node with value 35 found in the tree\n") : printf("node with value 35 not found in the tree\n");
    (Search(root, 2)) ? printf("node with value 2 found in the tree\n") : printf("node with value 2 not found in the tree\n");

    return 0;
}


int max(int a, int b){
    return (a>b) ? a : b;
}

Node *CreateNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->lchild = NULL;
    node->rchild = NULL;
    node->height = 1;

    return node;
}

int getHeight(Node *n){
    if(n == NULL) return 0;
    return n->height;
}

int getBalanceFactor(Node *n){
    if(n == NULL) return 0;
    return getHeight(n->lchild) - getHeight(n->rchild);
}

Node* leftRotation(Node *A){
    Node * B = A->rchild;
    A->rchild = B->lchild;
    B->lchild = A;

    A->height = 1 + max(getHeight(A->lchild), getHeight(A->rchild));
    B->height = 1 + max(getHeight(B->lchild), getHeight(B->rchild));

    return B;   
}

Node* rightRotation(Node *A){
     Node *B = A->lchild;
    A->lchild = B->rchild;
    B->rchild = A;

    A->height = 1 + max(getHeight(A->lchild), getHeight(A->rchild));
    B->height = 1 + max(getHeight(B->lchild), getHeight(B->rchild));

    return B;

}

void insert(Node **node, int val){
    if(*node == NULL){
        *node = CreateNode(val);
        return;
    }

    if(val < (*node)->data) insert(&(*node)->lchild, val);
    else if(val > (*node)->data) insert(&(*node)->rchild, val);
    else return;

    (*node)->height = 1 + max(getHeight((*node)->lchild), getHeight((*node)->rchild));

    int BF = getBalanceFactor(*node);
    if(BF > 1 && val < (*node)->lchild->data){
        // LL rotation
        *node = rightRotation(*node);
    }else if(BF < -1 && val > (*node)->rchild->data){
        // RR rotation
        *node = leftRotation(*node);
    } else if(BF > 1 && val > (*node)->lchild->data){
        // LR rotation
        (*node)->lchild = leftRotation((*node)->lchild);
        *node = rightRotation(*node);
    } else if(BF < -1 && val < (*node)->rchild->data){
        // RL rotation
        (*node)->rchild = rightRotation((*node)->rchild);
        *node = leftRotation(*node);
    }
}


int Search(Node *node, int val){
    if(node == NULL) return 0;

    if(node->data == val) return 1;
    else if(node->data > val) return Search(node->lchild, val);
    else return Search(node->rchild, val);
}


void InOrderTraversal(Node *root){
    if(root != NULL){
        InOrderTraversal(root->lchild);
        printf("%d, ", root->data);
        InOrderTraversal(root->rchild);
    }
}