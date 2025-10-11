#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;

typedef struct {
    u8 *rom0;   //    Non-switchable ROM Bank
    u8 *romx;   //    Switchable ROM bank
    u8 *vram;   //    Video RAM, switchable (0-1) in GBC mode
    u8 *sram;   //    External RAM in cartridge, often battery buffered
    u8 *wram0;  //    Work RAM
    u8 *wramx;  //    Work RAM, switchable (1-7) in GBC mode
    u8 *oam;    //    (Object Attribute Table) Sprite information table
    u8 *io;     //    I/O ports
    u8 *hram;   //    Internal CPU RAM
    u8 *ie_reg; //    Interrupt enable flags
} Memory ;

Memory* memory_init(void);
u8 memory_read(Memory* memory, u16 address);
void memory_write(Memory* memory, u16 address, u8 value);
void memory_clear(Memory* mem);

void memory_print(Memory* mem);
void memory_print_top(Memory* mem, u16 address);

#endif


