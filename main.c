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
  // printf("checking %d horiznotal\n", i);

  for(int k = 1; k < N; k++) {
    // printf("%d ", array[i][k]);
    if(array[i][k] == 1) {
      return 0;
    }
  }
  // printf("\n");
  return 1;
}

void check_horizontal_info(int i, int array[N][N]) {
  if(check_horizontal(i, matrix) == TRUE) {
    printf("positive horiznotal\n");
  } else {
    printf("negative horiznotal\n");
  }
}

int check_vertical(int j, int array[N][N]) {
  // printf("checking %d vertical\n", j);

  int counter = 0;
  for(int i = 0; i < N; i++) {
    counter = counter + array[i][j];
  }

  if(counter == 1) {
    return 1;  
  } 

  return 0;

  // printf("\n");
}

void check_vertical_info(int j, int array[N][N]) {
  if(check_vertical(j, matrix) == TRUE) {
    printf("positive vertical\n");
  } else {
    printf("negative vertical\n");
  }
}


int check_north_west_to_south_east_diagonal(int i, int j, int array[N][N]) {
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
  int m = j;

  for(int k = 0; k < N && m < N; k++, m++) {
    counter += array[k][m];
  }

  if(counter == 1) {
    // printf("check_north_west_to_south_east_diagonal positive\n");
    return 1;
  } 
  // printf("check_north_west_to_south_east_diagonal negative\n");
  return 0;
}

int check_north_east_to_south_west_diagonal(int i, int j, int array[N][N]) {
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
    counter += array[k][m];
  }

  if(counter == 1) {
    // printf("check_north_east_to_south_west_diagonal positive\n");
    return 1;
  } 
  // printf("check_north_east_to_south_west_diagonal negative\n");
  return 0;
}

int check_diagonals(int i, int j, int array[N][N]) {

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

  return check_north_west_to_south_east_diagonal(i, j, array) && check_north_east_to_south_west_diagonal(i, j, array);
}

void check_diagonals_info(int i, int j, int array[N][N]) {
  printf("checking diagonal %d %d = %d\n", i, j, array[i][j]);
  if(check_diagonals(i, j, matrix) == TRUE) {
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
  /* inint matrix */
  
  for(int l = 0; l < N; l++) {
    for(int m = 0; m < N; m++) {
      if(l == 0) {
        matrix[0][m] = 1;  
      } else {
        matrix[l][m] = 0;
      }
    }    
  }

  /* end of initiation */
}

void check_matrix(int array[N][N]) {
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

  int result = 1;

  int i = 0;
  int j = 0;
  int k = 0;  
  int bruted = 0;

  for(k = 0; k < N; k++) { 
    init_matrix();
    for(i = 0; i < N; i++) {

      if((k - 1) > 0) {
        matrix[k - 1][j] = 0;
      } else {
        matrix[k][j] = 0;
      }

      matrix[k + 1][j] = 1;

      print_matrix(matrix);


      for(j = 0; j < N; j++) { 
        result &= check_diagonals(i, j, matrix) && check_horizontal(i, matrix) && check_vertical(j, matrix); 
        bruted++;
        display_total_bruted(bruted);
        
        if(result == 1) {
          printf("\nNew result found:\n");
          print_matrix(matrix);
          printf("\n\n");
        } 
        
        result = 1;
        
      }

      j = 0;
    }
    init_matrix();
  }
}

void main(int argc, char** argv) {
  check_matrix(matrix);

// /*
//         1 1 1 1 1 1 1 1 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
// */

//   print_matrix(matrix);

//   check_horizontal_info(0, matrix);

// /*
//         0 1 1 1 1 1 1 1 
//         1 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
// */

//   matrix[0][0] = 0;
//   matrix[1][0] = 1;

//   print_matrix(matrix);

//   check_horizontal_info(1, matrix);

// /*
//         1 1 1 1 1 1 1 1 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
// */

//   print_matrix(matrix);

//   check_vertical_info(0, matrix);
//   print_matrix(matrix);

// /*
//         0 1 1 1 1 1 1 1 
//         1 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
// */

//   matrix[0][0] = 0;
//   matrix[1][0] = 1;

//   print_matrix(matrix);

//   check_vertical_info(1, matrix);

  
//   matrix[0][1] = 1;
//   matrix[1][1] = 1;

//   check_vertical_info(1, matrix);

//   /*
//         0 1 1 1 0 1 1 1 
//         1 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 1 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
// */

//   matrix[3][4] = 1;

//   check_diagonals_info(3, 4, matrix);

// /*
//         0 1 1 1 0 1 1 1 
//         1 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 1 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 0 0 
//         0 0 0 0 0 0 1 0 
//         0 0 0 0 0 0 0 0 
// */
  
//   for(int i = 0; i < N; i++) {
//     for(int j = 0; j < N; j++) {
//       if(i == 0) {
//         matrix[0][j] = 1;  
//       } else {
//         matrix[i][j] = 0;
//       }
//     }    
//   }

//   matrix[6][6] = 1;

//   check_diagonals_info(6, 6, matrix);


}