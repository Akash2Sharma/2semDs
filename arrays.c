 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrays.h"
#include "ui.h"
/*
* Test code: lets you print the contents of an array with a
* message. If you want no message call with an empty string (e.g.,
* "print_array("", a, 10)")
*/
void print_array(char *msg, float array[], int length)
{
  printf("%s", msg);
  for(int i = 0; i < (length - 1); i++) {
    printf("%f, ", array[i]);
  }
  printf("%f\n", array[length - 1]);
}
/* Story 1
* As a user, I want to be able to print out a 1 dimensional array of
* integers so I can see the results of my array algorithms.
*/
void print_1d_array(float array[], int length)
{
	int i;
	printf("(");
	for(i=0;i<length-1;i++){
	printf("%f, ",array[i]);
	}
	printf("%f)\n",array[length-1]);
	}
/* Story 2
* As a user, I want to enter a 1-dimensional array of integers so I
* can sort on them.
*/
void read_1d_array(float a[], int length)
{
	int i;
	for(i=0;i<length;i++){
	printf("Value %d> > ",i);scanf("%f",&a[i]);
	}
}
/* Story 3
* As a user, I want to be able to read and write a 1 dimensional
* array in a file so I can save and retrieve the array.
*/
void save_1d_array(char *filename, float a[], int length)
{
  FILE *fp;
  fp = fopen(filename, "w");
  fprintf(fp, "%d ", length);
  for(int i = 0; i < length; i++) {
    fprintf(fp, "%f ", a[i]);
  }
  fclose(fp);
}
void load_1d_array(char *filename, float a[], int *length)
{
  FILE *fp;
  fp = fopen(filename, "r");
  fscanf(fp, "%d ", length);
  for(int i = 0; i < *length; i++) {
    fscanf(fp, "%f ", &a[i]);
  }
  fclose(fp);
}
/* Story 4
* As a programmer, I want to add an item to a 1-d array to learn how
* to do it.
*/
void insert_1d_array(float new_value, int position,
                     float a[], int *length)
{
	int i;
	for(i=*length-1;i>=position-1;i--){
	a[i+1]=a[i];
	}
	a[position-1]=new_value;
	*length+=1;
}
/* Story 5
* As a programmer, I want to delete an item from a 1-d array so I can* learn how to do it.
*/
void delete_1d_array(int position, float a[], int *length)
{
	int i;
	for(i=position-1;i<*length;i++){
	a[i]=a[i+1];
	}
	*length-=1;
}
/* Story 6
* As a user, I want to print out a 2 dimensional array, so I can see
* the results of array multiplication.
*/
void print_2d_array(float a[80][80], int columns, int rows)
{
	int i,j;
	for(i=0;i<rows;i++){
	printf("(");
	for(j=0;j<columns-1;j++){
	printf("%f, ",a[i][j]);
	}
	printf("%f)\n",a[i][columns-1]);
	}
}
/* Story 7
* As a user, I want to be able to input out a 2 dimensional array of
* integers so I can input arrays to multiply.
*/
void read_2d_array(float a[80][80], int columns, int rows)
{
	int i,j;
	for(i=0;i<rows;i++){
	for(j=0;j<columns;j++){
	printf("value %d> > ",j);
	scanf("%f",&a[i][j]);
	}
	}
}
/* Story 8
* As a user, I want to be able to multiply matrices, to show I can
* manage two dimensional arrays.
*/
void multiply(float A[80][80], int Arow,float B[80][80], int Bcol,float C[80][80], int AcolBrow)
{
	int i,j,k;
	for(i=0;i<Arow;i++){
	for(j=0;j<Bcol;j++){
	int sum=0;
	for(k=0;k<AcolBrow;k++){
	sum += A[i][k]*B[k][j];
                        }
                        C[i][j]=sum;
	}
	}
}
/* Story 9
* As a user, I want to be able to do a bubble sort so I can compare
* the speed of various types of sort.
*/
void bubble_sort(float a[], int length)
{
	int i,j,temp;
	for(i=0;i<length;i++){
	for(j=0;j<length-1-i;j++){
	if(a[j]>a[j+1]){
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
	}
	}
}
/* Story 10
* As a user, I want to be able to do a selection sort so I can
* compare the speed of various types of sort.
*/
void selection_sort(float a[], int length)
{
	int i,j,min,temp;
	for(i=0;i<length-1;i++){
	min=i;
	for(j=i+1;j<length;j++){
	if(a[j]<a[min]) min=j;
	}
		temp=a[i];
		a[i]=a[min];
	a[min]=temp;
}}
/* Story 11
* As a user, I want to be able to do a insertion sort so I can
* compare the speed of various types of sort.
*/
void insertion_sort(float a[], int length)
{
	int i,j,temp;
	for(i=1;i<length;i++){
	temp=a[i];
	j=i-1;
	while(a[j]>temp && j>=0){
		a[j+1]=a[j];
		j=j-1;
		}
	a[j+1]=temp;
	}
}
 /* Story 12
* As a user, I want to be able to do a linear search so I can compare
* the speed of various linear and binary searching.
*/
void linear_search(float target, float a[], int length)
{
	int i,pos=-1;
	for(i=0;i<length;i++){
	if(a[i]==target) pos=i;
	}
	if(pos != -1) printf("Found %f, at Position %d\n",a[pos],pos);
	else printf("%f not Found\n",target);
}
/* Story 13
* As a user, I want to be able to do a binary search so I can compare
* the speed of linear and binary searching.
*/
void binary_search(float target, float a[], int length)
{
	int low=0,high=length-1,mid,pos=0;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==target){
			printf("Found %f, at position %d\n",target,mid);
			pos=1;
			break;
			}
		else if(a[mid]>target) high=mid-1;
		else low=mid+1;
		}
	if(pos != 1) printf("%f not found\n",target);
}
