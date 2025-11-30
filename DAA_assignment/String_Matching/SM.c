#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define base 256
#define prime 101
#define MAX_CHARS 256

// 1. Naive Method
void naiveSearch(char *text, char *pattern){
    int n = strlen(text), m = strlen(pattern);
    printf("Naive Search:\n");
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++)
            if(text[i + j] != pattern[j])
                break;
        if(j == m)
            printf("Pattern found at index %d\n", i);
    }
}


int Hash(int hi, int x, int y){
    return (hi - x + y) % prime;
}

// 2. Rabin-Karp Method
void rabinKarpSearch(char *text, char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int hp = 0, ht = 0;
    printf("Rabin-Karp Search:\n");

    // Initial hash
    for(int i = 0; i < m; i++){
        hp += pattern[i];
        ht += text[i];
    }
    hp %= prime;
    ht %= prime;

    for(int i = 0; i <= n - m; i++){
        if(ht == hp){
            int match = 1;
            for(int j = 0; j < m; j++){
                if(text[i + j] != pattern[j]){
                    match = 0;
                    break;
                }
            }
            if(match) printf("Pattern found at index %d\n", i);
        }
        //next hash
        if(i<n - m) ht = Hash(ht, text[i], text[i + m]);
    }
}


// 3. Finite Automaton Method
int getNextState(char *pattern, int m, int state, int x){
    if(state < m && x == pattern[state]) return state + 1;

    for(int ns = state; ns > 0; ns--){
        if(pattern[ns - 1] == x){
            int i;
            for(i = 0; i < ns - 1; i++)
                if(pattern[i] != pattern[state - ns + 1 + i])
                    break;
            if(i == ns - 1)
                return ns;
        }
    }
    return 0;
}

void computeTF(char *pattern, int m, int TF[][MAX_CHARS]){
    for(int state = 0; state <= m; ++state)
        for(int x = 0; x < MAX_CHARS; ++x)
            TF[state][x] = getNextState(pattern, m, state, x);
}

void finiteAutomatonSearch(char *text, char *pattern){
    int m = strlen(pattern);
    int n = strlen(text);
    int TF[100][MAX_CHARS];

    printf("Finite Automaton Search:\n");

    computeTF(pattern, m, TF);

    int state = 0;
    for(int i = 0; i < n; i++){
        state = TF[state][text[i]];
        if(state == m)
            printf("Pattern found at index %d\n", i - m + 1);
    }
}

int main(){
    char text[] = "BAABABABCABABCABAB";
    char pattern[] = "ABABCABAB";

    // naiveSearch(text, pattern);
    // printf("\n");
    rabinKarpSearch(text, pattern);
    printf("\n");
    // finiteAutomatonSearch(text, pattern);

    return 0;
}
