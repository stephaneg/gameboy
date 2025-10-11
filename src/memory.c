#include <stdlib.h>
#include <stdio.h>
#include "../include/memory.h"


Memory* memory_init() 
{
  // allocate the structure that will hold memory pointers
  Memory *mem = calloc(1, sizeof(Memory));
  if (!mem) 
  {
        fprintf(stderr, "error: failed to allocate memory structure\n");
  }

  // allocate the full memory buk
  u8 *bulk = calloc(1, 0xFFFF);

  // initialize pointers on sub memory ranges
  mem->rom0   = bulk ;
  mem->romx   = bulk+0x4000;
  mem->vram   = bulk+0x8000;
  mem->sram   = bulk+0xA000;
  mem->wram0  = bulk+0xC000;
  mem->wramx  = bulk+0xE000;
  mem->oam    = bulk+0xFE00;
  mem->io     = bulk+0xFF00;
  mem->hram   = bulk+0xFF80;
  mem->ie_reg = bulk+0xFFFF;



  return mem;
}

void memory_clear(Memory *mem) {
  free(mem->rom0);
  free(mem);
}


// print memory pointeres
void memory_print(Memory* mem) {
  printf("\nMemory pointers\n");
  printf("ie_reg  -> %.2x\n", mem->ie_reg);
  printf("hram    -> %.2x\n", mem->hram);
  printf("io      -> %.2x\n", mem->io);
  printf("oam     -> %.2x\n", mem->oam);
  printf("wramx   -> %.2x\n", mem->wramx);
  printf("wram0   -> %.2x\n", mem->wram0);
  printf("sram    -> %.2x\n", mem->sram);
  printf("vram    -> %.2x\n", mem->vram);
  printf("romx    -> %.2x\n", mem->romx);
  printf("rom0    -> %.2x\n", mem->rom0);

}

u8 memory_read(Memory* mem, u16 address) 
{
  return mem->rom0[address];
}

void memory_write(Memory* mem, u16 address, u8 value) {
  mem->rom0[address] = value;
}

void memory_print_top(Memory* mem, u16 address) 
{
  int i;
  u16 offset;
  if (address>0x0000 )
    offset = address-0x0001; 
  else 
    offset = address;


  for (int i=0 ; i<5 ; i++) 
  {
    printf("0x%.2x \t %.2x\n",offset+i, mem->rom0[offset+i]);
  }
}

