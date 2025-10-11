#include <stdio.h>
#include <stdlib.h>
#include "../include/memory.h"


int main() 
{
  printf("\ntesting gameboy memory\n");

  // init memory
  printf("\ninitialize gameboy memory...");
  Memory *gb_mem =  memory_init();;
  printf("completed !\n");
  memory_print(gb_mem);

  memory_print_top(gb_mem, 0x01);


  return 0;
}

