#include <stdio.h>
#include <stdlib.h>

const int N = 8;
const int TRUE = 1;
const int FALSE = 0;

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

int check_horizontal(int i, int array[N][N]) {
  for(int k = 0; k < N; k++) {
    if(array[i][k] == 1) {
      return 0;
    }
  }

  return 1;
}

int check_vertical(int i, int array[N][N]) {
  // for(int k = 0; k < N; k++) {
  //   if(array[i][k] == 1) {
  //     return 0;
  //   }
  // }

  return 1;
}

int check_diagonals(int i, int j, int array[N][N]) {
  // for(int k = 0; k < N; k++) {
  //   if(array[i][k] == 1) {
  //     return 0;
  //   }
  // }

  return 1;
}


int check_matrix(int i, int j, int array[N][N]) {
  return check_diagonals(i, j, array) & check_horizontal(i, array) & check_vertical(j, array);
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

  if(check_horizontal(0, matrix) == TRUE) {
    printf("positive horiznotal\n");
  } else {
    printf("negative horiznotal\n");
  }
}