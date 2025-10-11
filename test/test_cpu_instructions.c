#include <stdio.h>
#include <stdlib.h>
#include "../include/memory.h"
#include "../include/cpu.h"


int main() 
{
  printf("\nTESTING CPU INSTRUCTIONS\n");

  // init memory and CPU
  printf("initialize cpu...");
  Memory *mem =  memory_init();
  Cpu *cpu = cpu_init(mem, false); 
  printf("completed !\n");

  memory_write(mem, 0x00, 0x00);    // NOP
  memory_write(mem, 0x01, 0x06);    // LD B
  memory_write(mem, 0x02, 0x05);    // value 5
  memory_write(mem, 0x03, 0x0E);     // LD C
  memory_write(mem, 0x04, 0x08);    // value 8
  memory_print_top(mem, 0x00);      // NOP
  cpu_print(cpu); 

  printf("\nstarting\n");
  printf("\nexecuting 1st cycle\n"); 
  cpu_next_cycle(cpu);
  cpu_print(cpu);
 
  printf("\nexecuting 2nd cycle\n"); 
  cpu_next_cycle(cpu);
  cpu_print(cpu);

  printf("\nexecuting 2nd cycle\n"); 
  cpu_next_cycle(cpu);
  cpu_print(cpu);


 


  return 0;
}

