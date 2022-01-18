#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMatrix(int x, int y, int size, int matrix[][size]){
    for (int r = 0; r<x; r++){
        for (int c = 0; c<y; c++){
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

void initMatrix(int x, int y, int size, int matrix[][size]){
    
    for (int r = 0; r<x; r++){
        for (int c = 0; c<y; c++){
            matrix[r][c] = rand()%25;
        }
    }
}

void initResultM(int x, int y, int size, int m[][size]){
    for (int r = 0; r<x; r++){
        for (int c = 0; c<y; c++){
            m[r][c] = 0;
        }
    } 
}


int main(){
    srand(time(0));
    int n, m, p, result;
    printf("Enter the number of columns for m1: ");
    scanf("%d", &n);
    printf("Enter the number of rows for m1 and number of cloumns for m2: ");
    scanf("%d", &m);
    printf("Enter the number of columns for m2: ");
    scanf("%d", &p);
    int m1[n][m], m2[m][p], m3[n][p];
    initMatrix(n, m, m, m1);
    initMatrix(m, p, p, m2);
    printf("Matrix 1:\n");
    displayMatrix(n, m, m, m1);
    printf("\nMatrix 2:\n");
    displayMatrix(m, p, p, m2);
    initResultM(n, p, p, m3);
    for (int r = 0; r<n; r++){
        for (int c = 0; c<p; c++){
            for (int x = 0; x<m; x++){
                m3[r][c] += (m1[r][x] * m2[x][c]);
            }
        }
    }
    printf("\nResult matrix:\n");
    displayMatrix(n, p, p, m3);
    return 0;
    
}