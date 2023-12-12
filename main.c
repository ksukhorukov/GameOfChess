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

void print_matrix() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int check_horizontal(int i) {
  // printf("checking %d horiznotal\n", i);

  for(int k = 1; k < N; k++) {
    // printf("%d ", matrix[i][k]);
    if(matrix[i][k] == 1) {
      return 0;
    }
  }
  // printf("\n");
  return 1;
}

void check_horizontal_info(int i) {
  if(check_horizontal(i) == TRUE) {
    printf("positive horiznotal\n");
  } else {
    printf("negative horiznotal\n");
  }
}

int check_vertical(int j, int matrix[N][N]) {
  // printf("checking %d vertical\n", j);

  int counter = 0;
  for(int i = 0; i < N; i++) {
    counter = counter + matrix[i][j];
  }

  if(counter == 1) {
    return 1;  
  } 

  return 0;

  // printf("\n");
}

void check_vertical_info(int j) {
  if(check_vertical(j, matrix) == TRUE) {
    printf("positive vertical\n");
  } else {
    printf("negative vertical\n");
  }
}


int check_north_west_to_south_east_diagonal(int m) {
/*
        0 1 1 1 0 1 1 1 
        1 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 1 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
*/

  int counter = 0;

  for(int k = 0; k < N && m < N; k++, m++) {
    counter += matrix[k][m];
  }

  if(counter == 1) {
    // printf("check_north_west_to_south_east_diagonal positive\n");
    return 1;
  } 
  // printf("check_north_west_to_south_east_diagonal negative\n");
  return 0;
}

int check_north_east_to_south_west_diagonal() {
  /*
        0 1 1 1 0 1 1 1 
        1 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 1 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
*/

  int counter = 0;
  int m = N - 1;

  for(int k = 0; k < N && m >= 0; k++, m--) {
    counter += matrix[k][m];
  }

  if(counter == 1) {
    // printf("check_north_east_to_south_west_diagonal positive\n");
    return 1;
  } 
  // printf("check_north_east_to_south_west_diagonal negative\n");
  return 0;
}

int check_diagonals(int j) {

  /*
        0 1 1 1 0 1 1 1 
        1 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 1 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 
*/

  return check_north_west_to_south_east_diagonal(j) && check_north_east_to_south_west_diagonal();
}

void check_diagonals_info(int j) {
  if(check_diagonals(j) == TRUE) {
    printf("positive diagonal\n");
  } else {
    printf("negative diagonal\n");
  }
}

void display_total_bruted(int bruted) {
  printf("Total bruted: %d\n", bruted);
};

void display_result(int r) {
  printf("Result: %d\n", r);
}

void init_matrix() {
  /* init matrix with '1'-s as the first row and '0'-s for the rest of the matrix */
  
  for(int l = 0; l < N; l++) {
    for(int m = 0; m < N; m++) {
      if(l == 0) {
        matrix[0][m] = 1;  
      } else {
        matrix[l][m] = 0;
      }
    }    
  }
}

int check_matrix(int matrix[N][N]) {
  int result = 1;

  int k, l, m, p, bruted, counter = 0;  

  // int l = 0;
  // int m = 0;
  // int p = 0;
  // int bruted = 0;
  // int counter = 0;

  init_matrix();

  for(k = 0; k < N; k++) { 
    for(l = 0; l < N; l++) {
      if((k - 1) > 0) {
        matrix[k - 1][l] = 0;
      } else {
        matrix[k][l] = 0;
      }

      matrix[k + 1][l] = 1;

      for(m = 0; m < N; m++) {
        for(p = 0; p < N; p++) {
          result &= check_vertical(m, matrix); 
          bruted++;

          if(result == 1) {
            counter++;
            printf("\nNew result found:\n");
            print_matrix();
            printf("\n\n");
          } 
        
          result = 0;
        }
      }
    }
  }

  return counter;
}

int main() {
  int counter = check_matrix(matrix);

  printf("\nResults found: %d\n", counter);

  return 0;
}