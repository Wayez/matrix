#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *transform;
  struct matrix *test;
  struct matrix *test2;
  struct matrix *test3;
  struct matrix *test4;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  test = new_matrix(2, 3);
  test2 = new_matrix(3, 2);
  test3 = make_translate(1.0, 2.0, 3.0);
  test4 = make_scale(1.0, 2.0, 3.0);
  
  test->m[0][0]=1;
  test->m[0][1]=2;
  test->m[0][2]=3;
  test->m[1][0]=4;
  test->m[1][1]=5;
  test->m[1][2]=6;
  
  test2->m[0][0]=10;
  test2->m[0][1]=40;
  test2->m[1][0]=20;
  test2->m[1][1]=50;
  test2->m[2][0]=30;
  test2->m[2][1]=60;
  
  ident(edges);
  scalar_mult(5, edges);
  ident(transform);
  print_matrix(edges);
  printf("\n");
  matrix_mult(transform, edges);
  print_matrix(transform);
  printf("\n");
  print_matrix(edges);
  printf("\n");
 
  print_matrix(test2);
  printf("\n");
  matrix_mult(test, test2);
  print_matrix(test);
  printf("\n");
  print_matrix(test2);
  printf("\n");
  
  print_matrix(test3);
  printf("\n");
  
  print_matrix(test4);
  printf("\n");
  
  free_matrix( transform );
  free_matrix( edges );
  free_matrix( test );
  free_matrix( test2 );
  free_matrix( test3 );
  free_matrix( test4 );
}  
