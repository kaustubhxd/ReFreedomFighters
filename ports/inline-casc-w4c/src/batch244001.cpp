// batch244001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_645100(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_645100
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 63), &v, sizeof v); }  // @1_645100
  return eax;  // @2_645100
}
PCREG(645100, lifted_645100);

extern "C" u32 THISCALL lifted_638c90(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_638c90
  edx = (u32)(eax + eax*4);  // @1_638c90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @2_638c90
  eax = (u32)(eax + edx*4);  // @3_638c90
  return eax;  // @4_638c90
}
PCREG(638c90, lifted_638c90);


// ---- hand ports (lifter rejects these bodies). Tail-jump thunks keep the original push/pop ebp frame in naked asm. GUESS names.
extern "C" void ext_533fc0();
extern "C" void ext_4f00f0();
#define NAKED __attribute__((naked))

// 0x4bb2c0: p = [this+0x44]; p = [p+0x18]; v = [p+0x70]; unaligned dword [this+0x4e] = v; eax = v
struct W4c_u32 { u32 v; } __attribute__((packed));
static u32 THISCALL fn4bb2c0(u8 *self) {
  u8 *p = *(u8 **)(self + 0x44);
  p = *(u8 **)(p + 0x18);
  u32 v = *(u32 *)(p + 0x70);
  ((W4c_u32 *)(self + 0x4e))->v = v;
  return v;
}
PCREG(4bb2c0, fn4bb2c0);
// 0x533be0: ecx += 0x8b; jmp 0x533fc0
static void NAKED THISCALL fn533be0() { __asm__ volatile("push %ebp\n\tmov %esp, %ebp\n\tadd $0x8b, %ecx\n\tpop %ebp\n\tjmp ext_533fc0"); }
PCREG(533be0, fn533be0);
// 0x4f0010: o = 0x4f00f0(this); jmp [[o]+4] with ecx = o
static void NAKED THISCALL fn4f0010() { __asm__ volatile("push %ebp\n\tmov %esp, %ebp\n\tcall ext_4f00f0\n\tmov (%eax), %edx\n\tmov %eax, %ecx\n\tpop %ebp\n\tjmp *4(%edx)"); }
PCREG(4f0010, fn4f0010);
// 0x63e620: dec [this+0xc]; ecx = [this+4]; jmp [[ecx]+0x24]
static void NAKED THISCALL fn63e620() { __asm__ volatile("push %ebp\n\tmov %esp, %ebp\n\tdecl 0xc(%ecx)\n\tmov 4(%ecx), %ecx\n\tmov (%ecx), %eax\n\tpop %ebp\n\tjmp *0x24(%eax)"); }
PCREG(63e620, fn63e620);
// 0x5145e0: [this] slot 0x33c(this); then jmp [this] slot 0x340 with ecx = this
static void NAKED THISCALL fn5145e0() { __asm__ volatile("push %esi\n\tmov %ecx, %esi\n\tmov (%esi), %eax\n\tcall *0x33c(%eax)\n\tmov (%esi), %eax\n\tmov %esi, %ecx\n\tpop %esi\n\tjmp *0x340(%eax)"); }
PCREG(5145e0, fn5145e0);
// 0x64fe20: this and arg0 swap: ecx = arg0, arg0 = this; jmp [[arg0]+0x238]
static void NAKED THISCALL fn64fe20() { __asm__ volatile("push %ebp\n\tmov %esp, %ebp\n\tmov %ecx, %edx\n\tmov 8(%ebp), %ecx\n\tmov (%ecx), %eax\n\tmov %edx, 8(%ebp)\n\tpop %ebp\n\tjmp *0x238(%eax)"); }
PCREG(64fe20, fn64fe20);
