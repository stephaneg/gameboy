#ifndef CPU_H
#define CPU_H

#include <stdbool.h>
#include "memory.h"

#define FLAGS_ZERO (1 << 7)
#define FLAGS_NEGATIVE (1 << 6)
#define FLAGS_HALFCARRY (1 << 5)
#define FLAGS_CARRY (1 << 4)

/*
 * REGISTER
 */
typedef struct {
  u8 a;
  u8 b;
  u8 c;
  u8 d;
  u8 e;
  u8 f;
  u8 h;
  u8 l;
  u8 flags;
  u16 pc;
  u16 sp;
} Registers;

/*
 * CPU
 */
typedef struct {
  u8          opcode;
  bool        ime;
  bool        debug_mode;
  uint64_t    cycles;
  Registers   *regs;
  Memory      *mem;
} Cpu;

/*
 * INSTRUCTION
 */
typedef struct {
  char*     instr;
  uint8_t   length;
  uint8_t   ticks;
  void      (*execute) (Cpu*, u8, u8);
} Instruction;

// cpu functions
Cpu* cpu_init(Memory *mem, bool debug_mode);
void cpu_print(Cpu *c);

void cpu_next_cycle(Cpu *c);

// register functions
void cpu_print_registers(Registers *r);
u16 cpu_read_bc(Registers *r);
void cpu_write_bc(Registers *r, u16 v); 
u16 cpu_read_de(Registers *r);
void cpu_write_de(Registers *r, u16 v); 
u16 cpu_read_hl(Registers *r);
void cpu_write_hl(Registers *r, u16 v); 





// cpu operators
void undefined(Cpu *cpu, u8 op1, u8 op2);     //0x?? 
void nop(Cpu *cpu, u8 op1, u8 op2);           //0x00

//ld
void ld_b_n(Cpu *cpu, u8 op1, u8 op2);       //0x06
void ld_c_n(Cpu *cpu, u8 op1, u8 op2);       //0x0E
void ld_d_n(Cpu *cpu, u8 op1, u8 op2);       //0x16
void ld_e_n(Cpu *cpu, u8 op1, u8 op2);       //0x1E
void ld_h_n(Cpu *cpu, u8 op1, u8 op2);       //0x26
void ld_l_n(Cpu *cpu, u8 op1, u8 op2);       //0x2E
void ld_hl_n(Cpu *cpu, u8 op1, u8 op2);      //0x36

void ld_a_a(Cpu *cpu, u8 op1, u8 op2);       //0x7F
void ld_a_b(Cpu *cpu, u8 op1, u8 op2);       //0x78
void ld_a_c(Cpu *cpu, u8 op1, u8 op2);       //0x79
void ld_a_d(Cpu *cpu, u8 op1, u8 op2);       //0x7A
void ld_a_e(Cpu *cpu, u8 op1, u8 op2);       //0x7B
void ld_a_h(Cpu *cpu, u8 op1, u8 op2);       //0x7C
void ld_a_l(Cpu *cpu, u8 op1, u8 op2);       //0x7D
void ld_a_bc(Cpu *cpu, u8 op1, u8 op2);      //0x0A
void ld_a_de(Cpu *cpu, u8 op1, u8 op2);      //0x1A
void ld_a_hl(Cpu *cpu, u8 op1, u8 op2);      //0x7E
void ld_a_nn(Cpu *cpu, u8 op1, u8 op2);      //0xFA

void ld_b_b(Cpu *cpu, u8 op1, u8 op2);       //0x40
void ld_b_c(Cpu *cpu, u8 op1, u8 op2);       //0x41
void ld_b_d(Cpu *cpu, u8 op1, u8 op2);       //0x42
void ld_b_e(Cpu *cpu, u8 op1, u8 op2);       //0x43
void ld_b_h(Cpu *cpu, u8 op1, u8 op2);       //0X44
void ld_b_l(Cpu *cpu, u8 op1, u8 op2);       //0x45
void ld_b_hl(Cpu *cpu, u8 op1, u8 op2);      //0x46

void ld_c_b(Cpu *cpu, u8 op1, u8 op2);       //0x48
void ld_c_c(Cpu *cpu, u8 op1, u8 op2);       //0x49
void ld_c_d(Cpu *cpu, u8 op1, u8 op2);       //0x4A
void ld_c_e(Cpu *cpu, u8 op1, u8 op2);       //0x4B
void ld_c_h(Cpu *cpu, u8 op1, u8 op2);       //0X4C
void ld_c_l(Cpu *cpu, u8 op1, u8 op2);       //0x4D
void ld_c_hl(Cpu *cpu, u8 op1, u8 op2);      //0x4E

void ld_d_b(Cpu *cpu, u8 op1, u8 op2);       //0x50
void ld_d_c(Cpu *cpu, u8 op1, u8 op2);       //0x51
void ld_d_d(Cpu *cpu, u8 op1, u8 op2);       //0x52
void ld_d_e(Cpu *cpu, u8 op1, u8 op2);       //0x53
void ld_d_h(Cpu *cpu, u8 op1, u8 op2);       //0X54
void ld_d_l(Cpu *cpu, u8 op1, u8 op2);       //0x55
void ld_d_hl(Cpu *cpu, u8 op1, u8 op2);      //0x56

void ld_e_b(Cpu *cpu, u8 op1, u8 op2);       //0x58
void ld_e_c(Cpu *cpu, u8 op1, u8 op2);       //0x59
void ld_e_d(Cpu *cpu, u8 op1, u8 op2);       //0x5A
void ld_e_e(Cpu *cpu, u8 op1, u8 op2);       //0x5B
void ld_e_h(Cpu *cpu, u8 op1, u8 op2);       //0X5C
void ld_e_l(Cpu *cpu, u8 op1, u8 op2);       //0x5D
void ld_e_hl(Cpu *cpu, u8 op1, u8 op2);      //0x5E

void ld_h_b(Cpu *cpu, u8 op1, u8 op2);       //0x60
void ld_h_c(Cpu *cpu, u8 op1, u8 op2);       //0x61
void ld_h_d(Cpu *cpu, u8 op1, u8 op2);       //0x62
void ld_h_e(Cpu *cpu, u8 op1, u8 op2);       //0x63
void ld_h_h(Cpu *cpu, u8 op1, u8 op2);       //0X64
void ld_h_l(Cpu *cpu, u8 op1, u8 op2);       //0x65
void ld_h_hl(Cpu *cpu, u8 op1, u8 op2);      //0x66

void ld_l_b(Cpu *cpu, u8 op1, u8 op2);       //0x68
void ld_l_c(Cpu *cpu, u8 op1, u8 op2);       //0x69
void ld_l_d(Cpu *cpu, u8 op1, u8 op2);       //0x6A
void ld_l_e(Cpu *cpu, u8 op1, u8 op2);       //0x6B
void ld_l_h(Cpu *cpu, u8 op1, u8 op2);       //0X6C
void ld_l_l(Cpu *cpu, u8 op1, u8 op2);       //0x6D
void ld_l_hl(Cpu *cpu, u8 op1, u8 op2);      //0x6E

void ld_hl_b(Cpu *cpu, u8 op1, u8 op2);      //0x70
void ld_hl_c(Cpu *cpu, u8 op1, u8 op2);      //0x71
void ld_hl_d(Cpu *cpu, u8 op1, u8 op2);      //0x72
void ld_hl_e(Cpu *cpu, u8 op1, u8 op2);      //0x73
void ld_hl_h(Cpu *cpu, u8 op1, u8 op2);      //0x74
void ld_hl_l(Cpu *cpu, u8 op1, u8 op2);      //0x75




#endif

