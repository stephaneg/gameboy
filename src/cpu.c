#include <stdio.h>
#include <stdlib.h>
#include "../include/cpu.h"


const Instruction instructions[256] = {
      {"NOP", 0, 4, nop},                       //0x00
      {"UNKNOWN", 0, 0, undefined},             //0x01
      {"UNKNOWN", 0, 0, undefined},             //0x02
      {"UNKNOWN", 0, 0, undefined},             //0x03
      {"UNKNOWN", 0, 0, undefined},             //0x04
      {"UNKNOWN", 0, 0, undefined},             //0x05
      {"LD B, 0x%02X", 1, 8, ld_b_n},           //0x06
      {"UNKNOWN", 0, 0, undefined},             //0x07
      {"UNKNOWN", 0, 0, undefined},             //0x08
      {"UNKNOWN", 0, 0, undefined},             //0x09
      {"LD A, (BC)", 0, 8, ld_a_bc},            //0x0A    -- 10
      {"UNKNOWN", 0, 0, undefined},             //0x0B
      {"UNKNOWN", 0, 0, undefined},             //0x0C
      {"UNKNOWN", 0, 0, undefined},             //0x0D
      {"LD C, 0x%02X", 1, 8, ld_c_n},           //0x0E
      {"UNKNOWN", 0, 0, undefined},             //0x0F
      {"UNKNOWN", 0, 0, undefined},             //0x10
      {"UNKNOWN", 0, 0, undefined},             //0x11
      {"UNKNOWN", 0, 0, undefined},             //0x12
      {"UNKNOWN", 0, 0, undefined},             //0x13
      {"UNKNOWN", 0, 0, undefined},             //0x14    -- 20
      {"UNKNOWN", 0, 0, undefined},             //0x15
      {"LD D, 0x%02X", 1, 8, ld_d_n},           //0x16
      {"UNKNOWN", 0, 0, undefined},             //0x17
      {"UNKNOWN", 0, 0, undefined},             //0x18
      {"UNKNOWN", 0, 0, undefined},             //0x19
      {"LD A, (DE)", 0, 8, ld_a_de},             //0x1A
      {"UNKNOWN", 0, 0, undefined},             //0x1B
      {"UNKNOWN", 0, 0, undefined},             //0x1C
      {"UNKNOWN", 0, 0, undefined},             //0x1D
      {"LD E, Ox%O2X", 1, 8, ld_e_n},           //0x1E    -- 30
      {"UNKNOWN", 0, 0, undefined},             //0x1F
      {"UNKNOWN", 0, 0, undefined},             //0x20
      {"UNKNOWN", 0, 0, undefined},             //0x21
      {"UNKNOWN", 0, 0, undefined},             //0x22
      {"UNKNOWN", 0, 0, undefined},             //0x23
      {"UNKNOWN", 0, 0, undefined},             //0x24
      {"UNKNOWN", 0, 0, undefined},             //0x25
      {"LD H, 0x%02X", 1, 8, ld_h_n},           //0x26
      {"UNKNOWN", 0, 0, undefined},             //0x27
      {"UNKNOWN", 0, 0, undefined},             //0x28    -- 40
      {"UNKNOWN", 0, 0, undefined},             //0x29
      {"UNKNOWN", 0, 0, undefined},             //0x2A
      {"UNKNOWN", 0, 0, undefined},             //0x2B
      {"UNKNOWN", 0, 0, undefined},             //0x2C
      {"UNKNOWN", 0, 0, undefined},             //0x2D
      {"LD L, 0x%02X", 1, 8, ld_l_n},           //0x2E
      {"UNKNOWN", 0, 0, undefined},             //0x2F
      {"UNKNOWN", 0, 0, undefined},             //0x30
      {"UNKNOWN", 0, 0, undefined},             //0x31
      {"UNKNOWN", 0, 0, undefined},             //0x32    -- 50
      {"UNKNOWN", 0, 0, undefined},             //0x33
      {"UNKNOWN", 0, 0, undefined},             //0x34
      {"UNKNOWN", 0, 0, undefined},             //0x35
      {"LD (HL), 0x%02X", 2, 12, ld_hl_n},      //0x36
      {"UNKNOWN", 0, 0, undefined},             //0x37
      {"UNKNOWN", 0, 0, undefined},             //0x38
      {"UNKNOWN", 0, 0, undefined},             //0x39
      {"UNKNOWN", 0, 0, undefined},             //0x3A
      {"UNKNOWN", 0, 0, undefined},             //0x3B
      {"UNKNOWN", 0, 0, undefined},             //0x3C    -- 60
      {"UNKNOWN", 0, 0, undefined},             //0x3D
      {"UNKNOWN", 0, 0, undefined},             //0x3E
      {"UNKNOWN", 0, 0, undefined},             //0x3F
      {"LD B, B", 0, 4, ld_b_b},                //0x40
      {"LD B, C", 0, 4, ld_b_c},                //0x41
      {"LD B, D", 0, 4, ld_b_d},                //0x42
      {"LD B, E", 0, 4, ld_b_e},                //0x43
      {"LD B, H", 0, 4, ld_b_h},                //0x44
      {"LD B, L", 0, 4, ld_b_l},                //0x45
      {"LD B, (HL)", 0, 8, ld_b_hl},            //0x46    -- 70
      {"UNKNOWN", 0, 4, undefined},             //0x47
      {"LD C, B", 0, 4, ld_c_b},                //0x48
      {"LD C, C", 0, 4, ld_c_c},                //0x49
      {"LD C, D", 0, 4, ld_c_d},                //0x4A
      {"LD C, E", 0, 4, ld_c_e},                //0x4B
      {"LD C, H", 0, 4, ld_c_h},                //0x4C
      {"LD C, L", 0, 4, ld_c_l},                //0x4D
      {"LD C, (HL)", 0, 8, ld_c_hl},            //0x4E
      {"UNKNOWN", 0, 0, undefined},             //0x4F
      {"LD D, B", 0, 4, ld_d_b},                //0x50    -- 80
      {"LD D, C", 0, 4, ld_d_c},                //0x51
      {"LD D, D", 0, 4, ld_d_d},                //0x52
      {"LD D, E", 0, 4, ld_d_e},                //0x53
      {"LD D, H", 0, 4, ld_d_h},                //0x54
      {"LD D, L", 0, 4, ld_d_l},                //0x55
      {"LD D, (HL)", 0, 8, ld_d_hl},            //0x56
      {"UNKNOWN", 0, 0, undefined},             //0x57
      {"LD E, B", 0, 4, ld_e_b},                //0x58
      {"LD E, C", 0, 4, ld_e_c},                //0x59
      {"LD E, D", 0, 4, ld_e_d},                //0x5A    -- 90
      {"LD E, E", 0, 4, ld_e_e},                //0x5B
      {"LD E, H", 0, 4, ld_e_h},                //0x5C
      {"LD E, L", 0, 4, ld_e_l},                //0x5D
      {"LD E, (HL)", 0, 8, ld_e_hl},            //0x5E
      {"UNKNOWN", 0, 0, undefined},             //0x5F
      {"LD H, B", 0, 4, ld_h_b},                //0x60
      {"LD H, C", 0, 4, ld_h_c},                //0x61
      {"LD H, D", 0, 4, ld_h_d},                //0x62
      {"LD H, E", 0, 4, ld_h_e},                //0x63
      {"LD H, H", 0, 4, ld_h_h},                //0x64    -- 100
      {"LD H, L", 0, 4, ld_h_l},                //0x65
      {"LD H, (HL)", 0, 8, ld_h_hl},            //0x66
      {"UNKNOWN", 0, 0, undefined},             //0x67
      {"LD L, B", 0, 4, ld_l_b},                //0x68
      {"LD L, C", 0, 4, ld_l_c},                //0x69
      {"LD L, D", 0, 4, ld_l_d},                //0x6A
      {"LD L, E", 0, 4, ld_l_e},                //0x6B
      {"LD L, H", 0, 4, ld_l_h},                //0x6C
      {"LD L, L", 0, 4, ld_l_l},                //0x6D
      {"LD L (HL)", 0, 8, ld_l_hl},             //0x6E    -- 110
      {"UNKNOWN", 0, 0, undefined},             //0x6F
      {"LD (HL), B", 0, 8, ld_hl_b},            //0x70
      {"LD (HL), C", 0, 8, ld_hl_c},            //0x71
      {"LD (HL), D", 0, 8, ld_hl_d},            //0x72
      {"LD (HL), E", 0, 8, ld_hl_e},            //0x73
      {"LD (HL), H", 0, 8, ld_hl_h},            //0x74
      {"LD (HL), L", 0, 8, ld_hl_l},            //0x75
      {"UNKNOWN", 0, 0, undefined},             //0x76
      {"UNKNOWN", 0, 0, undefined},             //0x77
      {"LD A, B", 0, 4, ld_a_b},                //0x78    -- 120
      {"LD A, C", 0, 4, ld_a_c},                //0x79
      {"LD A, D", 0, 4, ld_a_d},                //0x7A
      {"LD A, E", 0, 4, ld_a_e},                //0x7B
      {"LD A, H", 0, 4, ld_a_h},                //0x7C
      {"LD A, L", 0, 4, ld_a_l},                //0x7D
      {"LD A, (HL)", 0, 8, ld_a_hl},            //0x7E
      {"LD A, A", 0, 4, ld_a_a},                //0x7F
      {"UNKNOWN", 0, 0, undefined},             //0x80
      {"UNKNOWN", 0, 0, undefined},             //0x81
      {"UNKNOWN", 0, 0, undefined},             //0x82    -- 130
      {"UNKNOWN", 0, 0, undefined},             //0x83
      {"UNKNOWN", 0, 0, undefined},             //0x84
      {"UNKNOWN", 0, 0, undefined},             //0x85
      {"UNKNOWN", 0, 0, undefined},             //0x86
      {"UNKNOWN", 0, 0, undefined},             //0x87
      {"UNKNOWN", 0, 0, undefined},             //0x88
      {"UNKNOWN", 0, 0, undefined},             //0x89
      {"UNKNOWN", 0, 0, undefined},             //0x8A
      {"UNKNOWN", 0, 0, undefined},             //0x8B
      {"UNKNOWN", 0, 0, undefined},             //0x8C    -- 140
      {"UNKNOWN", 0, 0, undefined},             //0x8D
      {"UNKNOWN", 0, 0, undefined},             //0x8E
      {"UNKNOWN", 0, 0, undefined},             //0x8F
      {"UNKNOWN", 0, 0, undefined},             //0x90
      {"UNKNOWN", 0, 0, undefined},             //0x91
      {"UNKNOWN", 0, 0, undefined},             //0x92
      {"UNKNOWN", 0, 0, undefined},             //0x93
      {"UNKNOWN", 0, 0, undefined},             //0x94
      {"UNKNOWN", 0, 0, undefined},             //0x95
      {"UNKNOWN", 0, 0, undefined},             //0x96    -- 150
      {"UNKNOWN", 0, 0, undefined},             //0x97
      {"UNKNOWN", 0, 0, undefined},             //0x98
      {"UNKNOWN", 0, 0, undefined},             //0x99
      {"UNKNOWN", 0, 0, undefined},             //0x9A
      {"UNKNOWN", 0, 0, undefined},             //0x9B
      {"UNKNOWN", 0, 0, undefined},             //0x9C
      {"UNKNOWN", 0, 0, undefined},             //0x9D
      {"UNKNOWN", 0, 0, undefined},             //0x9E
      {"UNKNOWN", 0, 0, undefined},             //0x9F
      {"UNKNOWN", 0, 0, undefined},             //0xA0    -- 160
      {"UNKNOWN", 0, 0, undefined},             //0xA1
      {"UNKNOWN", 0, 0, undefined},             //0xA2
      {"UNKNOWN", 0, 0, undefined},             //0xA3
      {"UNKNOWN", 0, 0, undefined},             //0xA4
      {"UNKNOWN", 0, 0, undefined},             //0xA5
      {"UNKNOWN", 0, 0, undefined},             //0xA6
      {"UNKNOWN", 0, 0, undefined},             //0xA7
      {"UNKNOWN", 0, 0, undefined},             //0xA8
      {"UNKNOWN", 0, 0, undefined},             //0xA9
      {"UNKNOWN", 0, 0, undefined},             //0xAA    -- 170
      {"UNKNOWN", 0, 0, undefined},             //0xAB
      {"UNKNOWN", 0, 0, undefined},             //0xAC
      {"UNKNOWN", 0, 0, undefined},             //0xAD
      {"UNKNOWN", 0, 0, undefined},             //0xAE
      {"UNKNOWN", 0, 0, undefined},             //0xAF
      {"UNKNOWN", 0, 0, undefined},             //0xB0
      {"UNKNOWN", 0, 0, undefined},             //0xB1
      {"UNKNOWN", 0, 0, undefined},             //0xB2
      {"UNKNOWN", 0, 0, undefined},             //0xB3
      {"UNKNOWN", 0, 0, undefined},             //0xB4    -- 180
      {"UNKNOWN", 0, 0, undefined},             //0xB5
      {"UNKNOWN", 0, 0, undefined},             //0xB6
      {"UNKNOWN", 0, 0, undefined},             //0xB7
      {"UNKNOWN", 0, 0, undefined},             //0xB8
      {"UNKNOWN", 0, 0, undefined},             //0xB9
      {"UNKNOWN", 0, 0, undefined},             //0xBA
      {"UNKNOWN", 0, 0, undefined},             //0xBB
      {"UNKNOWN", 0, 0, undefined},             //0xBC
      {"UNKNOWN", 0, 0, undefined},             //0xBD
      {"UNKNOWN", 0, 0, undefined},             //0xBE    -- 190
      {"UNKNOWN", 0, 0, undefined},             //0xBF
      {"UNKNOWN", 0, 0, undefined},             //0xC0
      {"UNKNOWN", 0, 0, undefined},             //0xC1
      {"UNKNOWN", 0, 0, undefined},             //0xC2
      {"UNKNOWN", 0, 0, undefined},             //0xC3
      {"UNKNOWN", 0, 0, undefined},             //0xC4
      {"UNKNOWN", 0, 0, undefined},             //0xC5
      {"UNKNOWN", 0, 0, undefined},             //0xC6
      {"UNKNOWN", 0, 0, undefined},             //0xC7
      {"UNKNOWN", 0, 0, undefined},             //0xC8    -- 200
      {"UNKNOWN", 0, 0, undefined},             //0xC9
      {"UNKNOWN", 0, 0, undefined},             //0xCA
      {"UNKNOWN", 0, 0, undefined},             //0xCB
      {"UNKNOWN", 0, 0, undefined},             //0xCC
      {"UNKNOWN", 0, 0, undefined},             //0xCD
      {"UNKNOWN", 0, 0, undefined},             //0xCE
      {"UNKNOWN", 0, 0, undefined},             //0xCF
      {"UNKNOWN", 0, 0, undefined},             //0xD0
      {"UNKNOWN", 0, 0, undefined},             //0xD1
      {"UNKNOWN", 0, 0, undefined},             //0xD2    -- 210
      {"UNKNOWN", 0, 0, undefined},             //0xD3
      {"UNKNOWN", 0, 0, undefined},             //0xD4
      {"UNKNOWN", 0, 0, undefined},             //0xD5
      {"UNKNOWN", 0, 0, undefined},             //0xD6
      {"UNKNOWN", 0, 0, undefined},             //0xD7
      {"UNKNOWN", 0, 0, undefined},             //0xD8
      {"UNKNOWN", 0, 0, undefined},             //0xD9
      {"UNKNOWN", 0, 0, undefined},             //0xDA
      {"UNKNOWN", 0, 0, undefined},             //0xDB
      {"UNKNOWN", 0, 0, undefined},             //0xDC    -- 220
      {"UNKNOWN", 0, 0, undefined},             //0xDD
      {"UNKNOWN", 0, 0, undefined},             //0xDE
      {"UNKNOWN", 0, 0, undefined},             //0xDF
      {"UNKNOWN", 0, 0, undefined},             //0xE0
      {"UNKNOWN", 0, 0, undefined},             //0xE1
      {"UNKNOWN", 0, 0, undefined},             //0xE2
      {"UNKNOWN", 0, 0, undefined},             //0xE3
      {"UNKNOWN", 0, 0, undefined},             //0xE4
      {"UNKNOWN", 0, 0, undefined},             //0xE5
      {"UNKNOWN", 0, 0, undefined},             //0xE6    -- 230
      {"UNKNOWN", 0, 0, undefined},             //0xE7
      {"UNKNOWN", 0, 0, undefined},             //0xE8
      {"UNKNOWN", 0, 0, undefined},             //0xE9
      {"UNKNOWN", 0, 0, undefined},             //0xEA
      {"UNKNOWN", 0, 0, undefined},             //0xEB
      {"UNKNOWN", 0, 0, undefined},             //0xEC
      {"UNKNOWN", 0, 0, undefined},             //0xED
      {"UNKNOWN", 0, 0, undefined},             //0xEE
      {"UNKNOWN", 0, 0, undefined},             //0xEF
      {"UNKNOWN", 0, 0, undefined},             //0xF0    -- 240
      {"UNKNOWN", 0, 0, undefined},             //0xF1
      {"UNKNOWN", 0, 0, undefined},             //0xF2
      {"UNKNOWN", 0, 0, undefined},             //0xF3
      {"UNKNOWN", 0, 0, undefined},             //0xF4
      {"UNKNOWN", 0, 0, undefined},             //0xF5
      {"UNKNOWN", 0, 0, undefined},             //0xF6
      {"UNKNOWN", 0, 0, undefined},             //0xF7
      {"UNKNOWN", 0, 0, undefined},             //0xF8
      {"UNKNOWN", 0, 0, undefined},             //0xF9
      {"LD A, (0x%02X)", 2, 16, ld_a_nn},       //0xFA    -- 250
      {"UNKNOWN", 0, 0, undefined},             //0xFB
      {"UNKNOWN", 0, 0, undefined},             //0xFC
      {"UNKNOWN", 0, 0, undefined},             //0xFD
      {"UNKNOWN", 0, 0, undefined},             //0xFE
      {"UNKNOWN", 0, 0, undefined},             //0xFF

 

 
};


/*
 * Registers functions
*/

// print registers
void cpu_print_registers(Registers* r) 
{
  printf("PC -> Ox%.2x \t SP -> 0x%.2x\n", r->pc, r->sp);
  printf("A |B |C |D |E |F |H |L \n");
  printf("-----------------------\n");
  printf("%.2x|%.2x|%.2x|%.2x|%.2x|%.2x|%.2x|%.2x\n", r->a, r->b, r->c, r->d, r->e, r->f, r->h, r->l);

}

u16 cpu_read_bc(Registers *r) 
{
  u16 res;
  u16 b, c;
  b = (u16)(r->b);
  c = (u16)(r->c);
  res = (b << 8) | c;
}

void cpu_write_bc(Registers *r, u16 v) 
{
  u8 b, c;
  b = (0xFF00 & v) >> 8;
  c = (0xFF & v);
  r->b = b;
  r->c = c;
}

u16 cpu_read_de(Registers *r) 
{
  u16 res;
  u16 d, e;
  d = (u16)(r->d);
  e = (u16)(r->e);
  res = (d << 8) | e;
}

void cpu_write_de(Registers *r, u16 v) 
{
  u8 d, e;
  d = (0xFF00 & v) >> 8;
  e = (0xFF & v);
  r->d = d;
  r->e = e;
}

u16 cpu_read_hl(Registers *r) 
{
  u16 res;
  u16 h, l;
  h = (u16)(r->h);
  l = (u16)(r->l);
  res = (h << 8) | l;
}

void cpu_write_hl(Registers *r, u16 v) 
{
  u8 h, l;
  h = (0xFF00 & v) >> 8;
  l = (0xFF & v);
  r->h = h;
  r->l = l;
}

/*
* CPU  functions
*/

// Init the CPU
Cpu* cpu_init(Memory *mem, bool debug) 
{
  Registers *rs = calloc(1, sizeof(Registers));
  Cpu *cpu = calloc(1, sizeof(Cpu));

  cpu->regs = rs;
  cpu->opcode=0;
  cpu->cycles=0;
  cpu->ime=false;
  cpu->debug_mode=debug;
  cpu->mem = mem;
  return cpu;
}

// print the CPU status
void cpu_print(Cpu *cpu) 
{
  printf("\n================================\n");
  printf("CPU status\n");
  printf("ime: %B \t cycles : %d \t op code %.2x\n", cpu->ime, cpu->cycles, cpu->opcode );
  cpu_print_registers(cpu->regs);
  printf("================================\n");
}

/*
 * EXECUTE THE NEXT CPU CYCLE
 */
void cpu_next_cycle(Cpu *cpu) 
{
  // return if stopped
  if (cpu->ime) return;

  // fetch the next instruction
  u8 instruction =  memory_read(cpu->mem, cpu->regs->pc++);
  cpu->opcode = instruction;
  u8 op1=0;
  u8 op2=0;

  if (instructions[instruction].length==1) {
    op1 = memory_read(cpu->mem, cpu->regs->pc);
    cpu->regs->pc++;
  }
  else if (instructions[instruction].length==2) {
    op1 = memory_read(cpu->mem, cpu->regs->pc);
    cpu->regs->pc++;
    op2 = memory_read(cpu->mem, cpu->regs->pc);
    cpu->regs->pc++;
  }
  
  instructions[instruction].execute(cpu, op1, op2);

  cpu->cycles+=instructions[instruction].ticks;
}



/*
* Instructions
*/
// UNDEFINED
void undefined(Cpu *cpu, u8 op1, u8 op2)
{
  printf("undefined instruction 0x%02x!\n", cpu->opcode); 
  cpu_print_registers(cpu->regs);
}
// NOP
void nop(Cpu *cpu, u8 op1, u8 op2)  { }     // OxOO

// LD B, N
void ld_b_n(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = op1;}         //0x06
void ld_c_n(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = op1;}         //0x0E
void ld_d_n(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = op1;}         //0x16
void ld_e_n(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = op1;}         //0x1E
void ld_h_n(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = op1;}         //0x26
void ld_l_n(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = op1;}         //0x2E
void ld_hl_n(Cpu *cpu, u8 op1, u8 op2)                              //0x36
{
  cpu->regs->h = op1;
  cpu->regs->l =op2 ;
}

// LD A, <reg>
void ld_a_a(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->a;}       //0x7F
void ld_a_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->b;}       //0X78
void ld_a_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->c;}       //0x79
void ld_a_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->d;}       //0x7A
void ld_a_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->e;}       //0x7B
void ld_a_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->h;}       //0x7C
void ld_a_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = cpu->regs->l;}       //0x7D
void ld_a_bc(Cpu *cpu, u8 op1, u8 op2) {                                   //0x0A
  u16 bc = cpu_read_bc(cpu->regs);
  cpu->regs->a = memory_read(cpu->mem, bc);
}
void ld_a_de(Cpu *cpu, u8 op1, u8 op2) {                                   //0x1A
  u16 de = cpu_read_de(cpu->regs);
  cpu->regs->a = memory_read(cpu->mem, de);
}
void ld_a_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x7E
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->a = memory_read(cpu->mem, hl);
}
void ld_a_nn(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->a = memory_read(cpu->mem, (op1 <<8 | op2));} // 0xFA

// LD B, <reg>
void ld_b_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = cpu->regs->b;}       //0x40
void ld_b_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = cpu->regs->c;}       //0x41
void ld_b_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = cpu->regs->d;}       //0x42
void ld_b_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = cpu->regs->e;}       //0x43
void ld_b_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = cpu->regs->h;}       //0X44
void ld_b_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->b = cpu->regs->l;}       //0x45
void ld_b_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x46
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->b = memory_read(cpu->mem, hl);
}

// LD C, <reg>
void ld_c_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = cpu->regs->b;}       //0x48
void ld_c_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = cpu->regs->c;}       //0x49
void ld_c_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = cpu->regs->d;}       //0x4A
void ld_c_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = cpu->regs->e;}       //0x4B
void ld_c_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = cpu->regs->h;}       //0X4C
void ld_c_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->c = cpu->regs->l;}       //0x4D
void ld_c_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x4E
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->c = memory_read(cpu->mem, hl);
}

// LD D, <reg>
void ld_d_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = cpu->regs->b;}       //0x50
void ld_d_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = cpu->regs->c;}       //0x51
void ld_d_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = cpu->regs->d;}       //0x52
void ld_d_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = cpu->regs->e;}       //0x53
void ld_d_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = cpu->regs->h;}       //0x54
void ld_d_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->d = cpu->regs->l;}       //0x55
void ld_d_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x56
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->d = memory_read(cpu->mem, hl);
}

// LD E, <reg>
void ld_e_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = cpu->regs->b;}       //0x58
void ld_e_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = cpu->regs->c;}       //0x59
void ld_e_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = cpu->regs->d;}       //0x5A
void ld_e_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = cpu->regs->e;}       //0x5B
void ld_e_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = cpu->regs->h;}       //0x5C
void ld_e_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->e = cpu->regs->l;}       //0x5D
void ld_e_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x5E
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->e = memory_read(cpu->mem, hl);
}

// LD H, <reg>
void ld_h_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = cpu->regs->b;}       //0x60
void ld_h_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = cpu->regs->c;}       //0x61
void ld_h_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = cpu->regs->d;}       //0x62
void ld_h_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = cpu->regs->e;}       //0x63
void ld_h_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = cpu->regs->h;}       //0X64
void ld_h_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->h = cpu->regs->l;}       //0x65
void ld_h_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x66
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->h = memory_read(cpu->mem, hl);
}

// LD L, <reg>
void ld_l_b(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = cpu->regs->b;}       //0x68
void ld_l_c(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = cpu->regs->c;}       //0x69
void ld_l_d(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = cpu->regs->d;}       //0x6A
void ld_l_e(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = cpu->regs->e;}       //0x6B
void ld_l_h(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = cpu->regs->h;}       //0x6C
void ld_l_l(Cpu *cpu, u8 op1, u8 op2) {cpu->regs->l = cpu->regs->l;}       //0x6D
void ld_l_hl(Cpu *cpu, u8 op1, u8 op2) {                                   //0x6E
  u16 hl = cpu_read_hl(cpu->regs);
  cpu->regs->l = memory_read(cpu->mem, hl);
}

// LD (HL), <reg>
void ld_hl_b(Cpu *cpu, u8 op1, u8 op2) { u16 hl = cpu_read_hl(cpu->regs); memory_write(cpu->mem, hl, cpu->regs->b);}    //0x70
void ld_hl_c(Cpu *cpu, u8 op1, u8 op2) { u16 hl = cpu_read_hl(cpu->regs); memory_write(cpu->mem, hl, cpu->regs->c);}    //0x71
void ld_hl_d(Cpu *cpu, u8 op1, u8 op2) { u16 hl = cpu_read_hl(cpu->regs); memory_write(cpu->mem, hl, cpu->regs->d);}    //0x72
void ld_hl_e(Cpu *cpu, u8 op1, u8 op2) { u16 hl = cpu_read_hl(cpu->regs); memory_write(cpu->mem, hl, cpu->regs->e);}    //0x73
void ld_hl_h(Cpu *cpu, u8 op1, u8 op2) { u16 hl = cpu_read_hl(cpu->regs); memory_write(cpu->mem, hl, cpu->regs->h);}    //0x74
void ld_hl_l(Cpu *cpu, u8 op1, u8 op2) { u16 hl = cpu_read_hl(cpu->regs); memory_write(cpu->mem, hl, cpu->regs->l);}    //0x75





