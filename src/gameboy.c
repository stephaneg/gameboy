#include <stdio.h>
#include <stdlib.h>
#include "../include/cpu.h"


int main() 
{
  // init memory
  printf("\ninitialize gameboy memory...");
  Memory *gb_mem =  memory_init();;
  printf("completed !\n");
  memory_print(gb_mem);

  bool debug_mode = true;

  // init CPU
  printf("\ninitialize cpu...");
  Cpu *cpu = cpu_init(gb_mem, debug_mode);
  printf("completed !\n");
  cpu_print(cpu);

  return 0;
}

