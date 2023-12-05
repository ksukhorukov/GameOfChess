#include <stdio.h>
#include <stdlib.h>

const int N = 8;
int matrix[N][N];

void system_error(char *msg) {
  printf("%s", msg);
  exit(-1);
}

void main(int argc, char** argv) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {

      matrix[i][j] = 0;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}