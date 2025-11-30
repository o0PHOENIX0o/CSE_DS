#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;
Node* newNode(char ch, int freq) {
    Node* n = malloc(sizeof(Node));
    n->ch = ch; n->freq = freq; n->left = n->right = NULL;
    return n;
}
void insert(Node** heap, int* size, Node* node) {
    int i = *size, j;
    for (j = i - 1; j >= 0 && heap[j]->freq > node->freq; j--)
        heap[j + 1] = heap[j];
    heap[j + 1] = node;
    (*size)++;
}
Node* extractMin(Node** heap, int* size) {
    Node* min = heap[0];
    for (int i = 1; i < *size; i++) heap[i - 1] = heap[i];
    (*size)--;
    return min;
}
void printCodes(Node* root, char* code, int depth) {
    if (!root) return;
    if (!root->left && !root->right) {
        code[depth] = '\0';
        printf("%c: %s\n", root->ch, code);
        return;
    }
    code[depth] = '0'; printCodes(root->left, code, depth + 1);
    code[depth] = '1'; printCodes(root->right, code, depth + 1);
}
int main() {
    char chars[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    int freq[] = { 10, 10, 20, 30, 5, 8, 5, 12 };
    int n = 8, size = 0;
    Node* heap[100], *left, *right, *top;
    for (int i = 0; i < n; i++)
        insert(heap, &size, newNode(chars[i], freq[i]));

    while (size > 1) {
        left = extractMin(heap, &size);
        right = extractMin(heap, &size);
        top = newNode('$', left->freq + right->freq);
        top->left = left; top->right = right;
        insert(heap, &size, top);
    }
    char code[100];
    printf("Huffman Codes:\n");
    printCodes(heap[0], code, 0);
    return 0;
}