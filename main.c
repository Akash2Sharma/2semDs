     
#include <stdio.h>
#include "ui.h"
#include "arrays.h"

int main(int argc, char *argv[]) {
  printf ("enter \'x\' to exit\n");
  /* See ui.h, ui.c for execute_command and get_command */
  while (execute_command(get_command( "\nEnter command")));
}    
