// batch200133.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" { u32 w2ret_66ab18; u32 w2regs_66ab18[3]; u32 w2in_66ab18[3]; }
extern "C" u32 lifted_66ab18_in(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = w2in_66ab18[0], esi = 0, edi = 0;
  ebx = 0;  // @0_66ab18
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1_66ab18
  ecx = (u32)(52);  // @2_66ab18
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66ab18
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66ab18
  ebx = (0u - ebx);  // @5_66ab18
  ebx = (ebx | eax);  // @6_66ab18
  p0_ = ebx;  // @7_66ab18
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @8_66ab18
  p1_ = eax;  // @9_66ab18
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @10_66ab18
  ecx = edx = 0;  // @11_66ab18
  { w2regs_66ab18[0] = ebx; return eax; }  // @12_66ab18
}
__asm__(".text\n.globl lifted_66ab18\nlifted_66ab18:\n pop %eax\n mov %eax, w2ret_66ab18\n mov %ebx, w2in_66ab18\n mov %esi, w2in_66ab18+4\n mov %edi, w2in_66ab18+8\n call lifted_66ab18_in\n mov w2regs_66ab18+0, %ebx\n jmp *w2ret_66ab18\n");
extern "C" u32 lifted_66ab18(void);
PCREG(66ab18, lifted_66ab18);

extern "C" { u32 w2ret_66ab68; u32 w2regs_66ab68[3]; u32 w2in_66ab68[3]; }
extern "C" u32 lifted_66ab68_in(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = w2in_66ab68[0], esi = 0, edi = 0;
  ebx = 0;  // @0_66ab68
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @1_66ab68
  ecx = (u32)(52);  // @2_66ab68
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66ab68
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66ab68
  ebx = (0u - ebx);  // @5_66ab68
  ebx = (ebx | eax);  // @6_66ab68
  p0_ = ebx;  // @7_66ab68
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @8_66ab68
  p1_ = eax;  // @9_66ab68
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @10_66ab68
  ecx = edx = 0;  // @11_66ab68
  { w2regs_66ab68[0] = ebx; return eax; }  // @12_66ab68
}
__asm__(".text\n.globl lifted_66ab68\nlifted_66ab68:\n pop %eax\n mov %eax, w2ret_66ab68\n mov %ebx, w2in_66ab68\n mov %esi, w2in_66ab68+4\n mov %edi, w2in_66ab68+8\n call lifted_66ab68_in\n mov w2regs_66ab68+0, %ebx\n jmp *w2ret_66ab68\n");
extern "C" u32 lifted_66ab68(void);
PCREG(66ab68, lifted_66ab68);

extern "C" { u32 w2ret_665950; u32 w2regs_665950[3]; u32 w2in_665950[3]; }
extern "C" u32 lifted_665950_in(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = w2in_665950[0], esi = 0, edi = 0;
  ebx = 0;  // @0_665950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @1_665950
  ecx = (u32)(10);  // @2_665950
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_665950
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_665950
  ebx = (0u - ebx);  // @5_665950
  ebx = (ebx | eax);  // @6_665950
  eax = 0;  // @7_665950
  ebx = (ebx + (u32)(4));  // @8_665950
  eax = (eax & 0xffffff00u) | (((u32)(0 && ebx)) & 0xff);  // @9_665950
  eax = (0u - eax);  // @10_665950
  eax = (eax | ebx);  // @11_665950
  p0_ = eax;  // @12_665950
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @13_665950
  p1_ = eax;  // @14_665950
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @15_665950
  ecx = edx = 0;  // @16_665950
  { w2regs_665950[0] = ebx; return eax; }  // @17_665950
}
__asm__(".text\n.globl lifted_665950\nlifted_665950:\n pop %eax\n mov %eax, w2ret_665950\n mov %ebx, w2in_665950\n mov %esi, w2in_665950+4\n mov %edi, w2in_665950+8\n call lifted_665950_in\n mov w2regs_665950+0, %ebx\n jmp *w2ret_665950\n");
extern "C" u32 lifted_665950(void);
PCREG(665950, lifted_665950);

extern "C" { u32 w2ret_66d790; u32 w2regs_66d790[3]; u32 w2in_66d790[3]; }
extern "C" u32 lifted_66d790_in(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 p0_, p1_;
  u32 eax = 0, ecx = 0, edx = 0, ebx = w2in_66d790[0], esi = 0, edi = 0;
  ebx = 0;  // @0_66d790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @1_66d790
  ecx = (u32)(28);  // @2_66d790
  { u64 t_ = (u64)eax * (u64)(ecx); eax = (u32)t_; edx = (u32)(t_ >> 32); }  // @3_66d790
  ebx = (ebx & 0xffffff00u) | (((u32)((edx != 0))) & 0xff);  // @4_66d790
  ebx = (0u - ebx);  // @5_66d790
  ebx = (ebx | eax);  // @6_66d790
  eax = 0;  // @7_66d790
  ebx = (ebx + (u32)(4));  // @8_66d790
  eax = (eax & 0xffffff00u) | (((u32)(0 && ebx)) & 0xff);  // @9_66d790
  eax = (0u - eax);  // @10_66d790
  eax = (eax | ebx);  // @11_66d790
  p0_ = eax;  // @12_66d790
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @13_66d790
  p1_ = eax;  // @14_66d790
  eax = ext_634273_cdecl2((u32)(p1_), (u32)(p0_));  // @15_66d790
  ecx = edx = 0;  // @16_66d790
  { w2regs_66d790[0] = ebx; return eax; }  // @17_66d790
}
__asm__(".text\n.globl lifted_66d790\nlifted_66d790:\n pop %eax\n mov %eax, w2ret_66d790\n mov %ebx, w2in_66d790\n mov %esi, w2in_66d790+4\n mov %edi, w2in_66d790+8\n call lifted_66d790_in\n mov w2regs_66d790+0, %ebx\n jmp *w2ret_66d790\n");
extern "C" u32 lifted_66d790(void);
PCREG(66d790, lifted_66d790);

