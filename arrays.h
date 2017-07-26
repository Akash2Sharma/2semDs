                    
#ifndef arrays_h    
#define arrays_h    
#define TRUE 1
#define FALSE 0
/*
1d Array
*/
void print_1d_array(float a[], int length);
void read_1d_array(float a[], int length);
void save_1d_array(char *filename, float a[], int length);
void load_1d_array(char *filename, float a[], int *length);
void insert_1d_array(float new_value, int position,float a[], int *length);
void delete_1d_array(int position, float a[], int *length);
/*
Sorting
*/
void bubble_sort(float a[], int length);
void selection_sort(float a[], int length);
void insertion_sort(float a[], int length);
/*
Searching
*/

void linear_search(float target, float a[], int length);
void binary_search(float target, float a[], int length);
/*
2d Arrays
*/
void print_2d_array(float a[80][80], int columns, int rows);
void read_2d_array(float a[80][80], int columns, int rows);
void multiply(float A[80][80], int Arow,
              float B[80][80], int Bcol,
              float C[80][80], int AcolBrow);
#endif

