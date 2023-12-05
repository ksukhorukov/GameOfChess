#include <stdio.h>
#include <stdlib.h>

const int N = 8;
int matrix[N][N];

void system_error(char *msg) {
  printf("%s", msg);
  exit(-1);
}

void print_matrix(int array[N][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void main(int argc, char** argv) {
  /* inint matrix */
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == 0) {
        matrix[0][j] = 1;  
      } else {
        matrix[i][j] = 0;
      }
    }    
  }

/*
  1 1 1 1 1 1 1 1 
  0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 0 
*/

  print_matrix(matrix);

}