// batch244002.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_533500(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 21614), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_533500
  if (FL[0] != FL[1]) goto L533512;  // @1_533500
  eax = 0;  // @2_533500
  FL[3] = eax;  // @3_533500
  return eax;  // @4_533500
  L533512:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_533500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 + 21602), sizeof v); (u32)v; });  // @7_533500
  return eax;  // @8_533500
}
PCREG(533500, lifted_533500);

extern "C" u32 THISCALL lifted_65ca30(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_65ca30
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 1024), &v, sizeof v); }  // @1_65ca30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 1040), &v, sizeof v); }  // @2_65ca30
  eax = (u32)(edx + 4);  // @3_65ca30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 1052), &v, sizeof v); }  // @4_65ca30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_65ca30
  eax = (eax + edx);  // @6_65ca30
  FL[3] = eax;  // @7_65ca30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 1056), &v, sizeof v); }  // @8_65ca30
  return eax;  // @9_65ca30
}
PCREG(65ca30, lifted_65ca30);

extern "C" u32 THISCALL lifted_537e70(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_537e70
  FL[0] = eax; FL[1] = (u32)(4);  // @1_537e70
  if ((s32)FL[0] < (s32)FL[1]) goto L537e81;  // @2_537e70
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @3_537e70
  FL[3] = (eax & 0xff);  // @4_537e70
  return eax;  // @5_537e70
  L537e81:;
  eax = (u32)((s32)eax * (s32)(u32)(13));  // @7_537e70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx + 21), &v, sizeof v); }  // @8_537e70
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @9_537e70
  return eax;  // @10_537e70
}
PCREG(537e70, lifted_537e70);


// ---- hand ports (lifter rejects these bodies). GUESS names.
#define NAKED __attribute__((naked))
struct W4c_u32 { u32 v; } __attribute__((packed));
struct W4c_u16 { u16 v; } __attribute__((packed));

// 0x5382d0: o = G[0x700390]->slot0x20(0x6a1e2c, 0x73b) (thiscall, callee pops); then with ecx = [o] (the vtable itself) call [ecx+0x2c](o, 0x6a236c) cdecl-style (add esp,8)
static void NAKED fn5382d0() {
  __asm__ volatile("mov 0x700390, %ecx\n\tpush $0x73b\n\tpush $0x6a1e2c\n\tmov (%ecx), %eax\n\tcall *0x20(%eax)\n\tpush $0x6a236c\n\tpush %eax\n\tmov (%eax), %ecx\n\tcall *0x2c(%ecx)\n\tadd $8, %esp\n\tret");
}
PCREG(5382d0, fn5382d0);

// 0x648c10: records an entry in a small table: flag byte +0x18282 |= 1, dword +0x1827d = -1, ptr +0x18291 = this+0x18259, word +0x1828f = word [this+0x20],
// n = [this+0x20]; [this+n*8+0x2c] = this+0x1827d; [this+n*8+0x28] = 0x8068009; [this+0x20]++
static void THISCALL fn648c10(u8 *self) {
  self[0x18282] |= 1;
  u8 *edx = self + 0x1827d;
  ((W4c_u32 *)edx)->v = 0xffffffff;
  ((W4c_u32 *)(self + 0x18291))->v = (u32)(self + 0x18259);
  ((W4c_u16 *)(self + 0x1828f))->v = *(u16 *)(self + 0x20);
  u32 n = *(u32 *)(self + 0x20);
  *(u32 *)(self + n * 8 + 0x2c) = (u32)edx;
  *(u32 *)(self + n * 8 + 0x28) = 0x8068009;
  (*(u32 *)(self + 0x20))++;
}
PCREG(648c10, fn648c10);

// 0x63ce20: walks the ring/list starting at [this+8] through next pointers at +8; returns the number of steps (byte counter) until back at the head or null
static u32 THISCALL fn63ce20(u8 *self) {
  u32 head = *(u32 *)(self + 8);
  u8 n = 0;
  u32 p = head;
  if (p) {
    for (;;) {
      p = *(u32 *)(p + 8);
      n++;
      if (p == head) break;
      if (!p) break;
    }
  }
  return n;
}
PCREG(63ce20, fn63ce20);

// 0x612170: cpuid(1): true when EDX bit 23 (MMX) is set. bool result in al.
static u8 STDCALL fn612170() {
  u32 a = 1, b, c = 0, d;
  __asm__ volatile("cpuid" : "+a"(a), "=b"(b), "+c"(c), "=d"(d));
  return (d & 0x800000) != 0;
}
PCREG(612170, fn612170);
