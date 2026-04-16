/** @file lc3vm.h
 * @brief LC-3 VM API
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Spring 2024
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for LC-3 simulator API/functions.
 */
#include <stdbool.h>
#include <stdint.h>

#ifndef LC3VM_H
#define LC3VM_H

// total number of opcodes in the LC-3 architecture.
#define NUMOPS (16)

// Need to #define all of your bit manipulation macros like DR, SR1, etc. here.
// Extract opcode (bits 15–12)
#define OPC(i)      (((i) >> 12) & 0xF)

// Extract destination register (bits 11–9)
#define DR(i)       (((i) >> 9) & 0x7)

// Extract source register 1 (bits 8–6)
#define SR1(i)      (((i) >> 6) & 0x7)

// Extract source register 2 (bits 2–0)
#define SR2(i)      ((i) & 0x7)

// Extract immediate 5-bit value (bits 4–0)
#define IMM5(i)     ((i) & 0x1F)

// Extract immediate 6-bit offset (bits 5–0)
#define OFF6(i)     ((i) & 0x3F)

// Extract immediate 9-bit offset (bits 8–0)
#define OFF9(i)     ((i) & 0x1FF)

// Extract N/Z/P condition bits (bits 11–9)
#define NZP(i)      (((i) >> 9) & 0x7)

#define FIMM(i) ((i >> 5) & 0x1)
#define FCND(i) (((i) >> 9) & 0x7)
#define BR(i) (((i) >> 6) & 0x7)
#define FL(i) (((i) >> 11) & 1)
#define TRP(i) ((i) & 0xFF)

typedef void (*op_ex_f)(uint16_t i);
typedef void (*trp_ex_f)();

enum
{
  trp_offset = 0x20
};

enum registr
{
  R0 = 0,
  R1,
  R2,
  R3,
  R4,
  R5,
  R6,
  R7,
  RPC,
  RCND,
  RCNT
};

enum flags
{
  FP = 1 << 0,
  FZ = 1 << 1,
  FN = 1 << 2
};

// If we are creating tests, make all declarations extern C so can
// work with catch2 C++ framework
#ifdef TEST
extern "C" {
#endif

extern bool running;
extern uint16_t mem[];
extern uint16_t reg[];
extern uint16_t PC_START;

// your task functions should go here

void rti(uint16_t i);
void res(uint16_t i);
void tgetc();
void tout();
void tputs();
void tin();
void thalt();
void tinu16();
void toutu16();
void trap(uint16_t i);
void ld_img(char* fname, uint16_t offset);

#ifdef TEST
} // end extern C for C++ test runner
#endif

#endif // LC3VM_H
