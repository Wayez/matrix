#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
	
  screen s;
  color c;
  c.green = MAX_COLOR;
  c.blue = 0;
  c.red = 0;
  struct matrix *edges;
  struct matrix *transform;
  /**
  struct matrix *test;
  struct matrix *test2;
  struct matrix *test3;
  struct matrix *test4;
  struct matrix *test5;
  struct matrix *test6;
  struct matrix *test7;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  test = new_matrix(2, 3);
  test2 = new_matrix(3, 2);
  test3 = make_translate(1.0, 2.0, 3.0);
  test4 = make_scale(1.0, 2.0, 3.0);
  test5 = make_rotX(M_PI);
  test6 = make_rotY(M_PI);
  test7 = make_rotZ(M_PI);
  
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
  
  print_matrix(test5);
  printf("\n");
  
  print_matrix(test6);
  printf("\n");
  
  print_matrix(test7);
  printf("\n");
  
  free_matrix( transform );
  free_matrix( edges );
  free_matrix( test );
  free_matrix( test2 );
  free_matrix( test3 );
  free_matrix( test4 );
  free_matrix( test5 );
  free_matrix( test6 );
  free_matrix( test7 );
  **/
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  
  //add_edge(edges, 10, 25, 0, 25, 10, 0);
  //add_edge(edges, 25, 10, 0, 10, 25, 0);
  //add_edge(edges, 10, 25, 0, 25, 25, 0);
  //add_edge(edges, 25, 25, 0, 10, 25, 0);
  
  add_edge(edges, XRES / 2, 0, 0, XRES, YRES / 2, 0);
  add_edge(edges, XRES, YRES / 2, 0, XRES / 2, YRES, 0);
  add_edge(edges, XRES / 2, YRES, 0, 0, YRES / 2, 0);
  add_edge(edges, 0, YRES / 2, 0, XRES / 2, 0, 0);
  draw_lines(edges, s , c);
  
  //struct matrix *rZ = new_matrix(4, 4);
  //rZ = make_rotZ(M_PI / 2);
  //matrix_mult(rZ, edges);
  //draw_lines(edges, s, c);
  int i;
  for(i = 2; i < 125; i++){
    struct matrix *rZ = new_matrix(4, 4);
    rZ = make_rotZ(60);
    matrix_mult(rZ, edges);
    //draw_lines(edges, s, c);
    scalar_mult(1.01, edges); 
    c.blue++;
    c.green-=2;
    c.red++;
    draw_lines(edges, s, c);
  }
  
  c.blue = MAX_COLOR;
  c.green = 0;
  
  add_edge(edges, XRES, 0, 0, XRES, YRES, 0);
  add_edge(edges, XRES, YRES, 0, 0, YRES, 0);
  add_edge(edges, 0, YRES, 0, 0, 0, 0);
  add_edge(edges, 0, 0, 0, XRES, 0, 0);
  draw_lines(edges, s , c);
  
  for(i = 2; i < 125; i++){
    struct matrix *temp = new_matrix(4, 4);
    temp = make_scale((i * 1.0 - 1) / i, (i * 1.0 - 1) / i, 1);
    matrix_mult(temp, edges);
    c.blue-=2;
    c.green++;
    c.red++;
    draw_lines(edges, s, c);
  }
  
  c.red = MAX_COLOR;
  
  add_point(transform, 250, 250, 0);
  int r;
  for (r = 0; r < 125; r++){
  	struct matrix *rot = new_matrix(4, 4);
  	rot = make_rotZ(15);
  	matrix_mult(rot, transform);
  	draw_lines(transform, s, c);
  }

  //print_matrix( edges );
  
  //draw_lines(edges, s, c);
  //display(s);
  save_ppm(s, "matrix.ppm");
  save_extension(s, "matrix.png");
  free_matrix( transform );
  free_matrix( edges );
}  
