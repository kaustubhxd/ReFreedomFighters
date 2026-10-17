// batch244004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 THISCALL ext_64d030_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_64d030");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_655b80(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_655b80
  esi = (u32)(eax + eax*2);  // @1_655b80
  esi = (esi << (u32)(3));  // @2_655b80
  FL[3] = esi;  // @3_655b80
  FL[2] = (esi & esi);  // @4_655b80
  if (FL[2] != 0) goto L655b98;  // @5_655b80
  eax = 0;  // @6_655b80
  FL[3] = eax;  // @7_655b80
  return eax;  // @8_655b80
  L655b98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_655b80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @11_655b80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_655b80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @13_655b80
  ecx = edx = 0;  // @14_655b80
  PV[0] = (u32)(esi);  // @15_655b80
  ecx = eax;  // @16_655b80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_655b80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, PV[0]);  // @18_655b80
  ecx = edx = 0;  // @19_655b80
  return eax;  // @20_655b80
}
PCREG(655b80, lifted_655b80);

extern "C" u32 THISCALL lifted_4270d0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x590] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x490);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x490 + 8, &a0, 4);
  __builtin_memcpy(F + 0x490 + 12, &a1, 4);
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_4270d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_4270d0
  edx = (u32)(EBP - 1028);  // @2_4270d0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4270d0
  PV[2] = (u32)(edx);  // @4_4270d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 324)))(ecx, PV[2], PV[1], PV[0]);  // @5_4270d0
  ecx = edx = 0;  // @6_4270d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @7_4270d0
  edx = (u32)(EBP - 1028);  // @8_4270d0
  PV[3] = (u32)(edx);  // @9_4270d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4270d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[3], (u32)(0));  // @11_4270d0
  ecx = edx = 0;  // @12_4270d0
  ext_633654(G(u32, 0x6f5630));  // @13_4270d0
  return eax;  // @14_4270d0
}
PCREG(4270d0, lifted_4270d0);

extern "C" u32 FASTCALL lifted_6403a0(u32 ecx_in, u32 edx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6403a0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @1_6403a0
  FL[2] = ((edx & 0xffff) & (edx & 0xffff));  // @2_6403a0
  if (FL[2] == 0) goto L6403e4;  // @3_6403a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 104), sizeof v); (u32)v; });  // @4_6403a0
  edx = (edx & (u32)(4095));  // @5_6403a0
  FL[3] = edx;  // @6_6403a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*4), sizeof v); (u32)v; });  // @7_6403a0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @8_6403a0
  eax = (eax - 1);  // @9_6403a0
  FL[3] = eax;  // @10_6403a0
  FL[0] = eax; FL[1] = (u32)(3);  // @11_6403a0
  if (FL[0] > FL[1]) goto L6403d4;  // @12_6403a0
  switch (eax) {  // @13_6403a0
  case 0: goto L6403e4;  // @14_6403a0
  case 1: goto L6403cc;  // @15_6403a0
  case 2: goto L6403e4;  // @16_6403a0
  case 3: goto L6403e4;  // @17_6403a0
  default: __builtin_trap(); }  // @18_6403a0
  L6403cc:;
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 66), sizeof v); (u32)v; }) | (u32)(1))); __builtin_memcpy((void *)(u32)(ecx + 66), &v, sizeof v); }  // @20_6403a0
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 66), sizeof v); (u32)v; });  // @21_6403a0
  return eax;  // @22_6403a0
  L6403d4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @24_6403a0
  FL[2] = (eax & eax);  // @25_6403a0
  if (FL[2] == 0) goto L6403e3;  // @26_6403a0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @27_6403a0
  ecx = edx = 0;  // @28_6403a0
  return eax;  // @29_6403a0
  L6403e3:;
  __builtin_trap();  // @31_6403a0
  L6403e4:;
  return eax;  // @33_6403a0
}
PCREG(6403a0, lifted_6403a0);

extern "C" u32 THISCALL lifted_65f410(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_65f410
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @1_65f410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @2_65f410
  eax = ext_64d030_thiscall5(ecx, PV[1], PV[0], (u32)(1), (u32)(0));  // @3_65f410
  ecx = edx = 0;  // @4_65f410
  esi = eax;  // @5_65f410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @6_65f410
  FL[2] = (edi & edi);  // @7_65f410
  if (FL[2] == 0) goto L65f44f;  // @8_65f410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @9_65f410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @10_65f410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 36), &v, sizeof v); }  // @11_65f410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @12_65f410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 40), &v, sizeof v); }  // @13_65f410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @14_65f410
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_65f410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @16_65f410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @17_65f410
  eax = ext_4de420_fastcall2(ecx, edx);  // @18_65f410
    // @19_65f410
  L65f44f:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; })) & 0xff);  // @21_65f410
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @22_65f410
  if (FL[0] == FL[1]) goto L65f459;  // @23_65f410
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 22), &v, sizeof v); }  // @24_65f410
  L65f459:;
  return eax;  // @26_65f410
}
PCREG(65f410, lifted_65f410);


#define NAKED __attribute__((naked))
// ---- hand ports (lifter rejects these bodies). GUESS names.
extern "C" void ext_634273(u8 *p, u32 n);                 // cdecl free-style
extern "C" void ext_634d10(u8 *p, u32 v, u32 n);          // cdecl memset-style
typedef void(STDCALL *w4c_s1_t)(void *);

// 0x4f3950: thiscall(flag byte) ret 4. r = table(engine+0x9b)->slot 0x58([this+0x73]); r == 0: return 0. Else [this+0x5fa] = flag; r->slot 0xbc(flag == 0) tail-called with ecx = r.
static void NAKED THISCALL fn4f3950() {
  __asm__ volatile(
      "push %ebp\n\tmov %esp, %ebp\n\tmov 0x70039c, %eax\n\tpush %esi\n\tmov %ecx, %esi\n\tmov 0x9b(%eax), %ecx\n\t"
      "pushl 0x73(%esi)\n\tmov (%ecx), %eax\n\tcall *0x58(%eax)\n\ttest %eax, %eax\n\tje 1f\n\t"
      "mov 8(%ebp), %cl\n\tmov %cl, 0x5fa(%esi)\n\ttest %cl, %cl\n\tmov (%eax), %edx\n\tsete %cl\n\tmovzbl %cl, %ecx\n\t"
      "pop %esi\n\tmov %ecx, 8(%ebp)\n\tmov %eax, %ecx\n\tpop %ebp\n\tjmp *0xbc(%edx)\n"
      "1:\tpop %esi\n\tpop %ebp\n\tret $4");
}
PCREG(4f3950, fn4f3950);

// 0x511770: stdcall(p) ret 4. idx = word [p+0x10]; idx < [0x7014b0] (unsigned): tail jump through the table at 0x7014b8 with the same argument;
// otherwise engine(0x700390)->slot 0x20(0x69e0a4, 0x78), then (ecx = its vtable) slot 0x2c(o, 0x69c6b0, 0x69ca40) cdecl-style, then the assert hook at 0x7003b0 (int3 when null).
static void NAKED STDCALL fn511770() {
  __asm__ volatile(
      "push %ebp\n\tmov %esp, %ebp\n\tmov 8(%ebp), %eax\n\tmovzwl 0x10(%eax), %edx\n\tcmp 0x7014b0, %edx\n\tjae 1f\n\t"
      "mov %eax, 8(%ebp)\n\tmov 0x7014b8(,%edx,4), %eax\n\tpop %ebp\n\tjmp *%eax\n"
      "1:\tmov 0x700390, %ecx\n\tpush $0x78\n\tpush $0x69e0a4\n\tmov (%ecx), %eax\n\tcall *0x20(%eax)\n\t"
      "push $0x69ca40\n\tpush $0x69c6b0\n\tpush %eax\n\tmov (%eax), %ecx\n\tcall *0x2c(%ecx)\n\tmov 0x7003b0, %eax\n\tadd $0xc, %esp\n\t"
      "test %eax, %eax\n\tje 2f\n\tcall *%eax\n\tpop %ebp\n\tret $4\n2:\tint3");
}
PCREG(511770, fn511770);

// 0x6132a0: teardown of 0x800 records of 0x44 bytes starting at this+0x3c: object at +0 (stdcall slot 8 with the object), buffer at +4 (freed with size 4);
// finally the 0x22000 bytes at this+4 are cleared.
static void THISCALL fn6132a0(u8 *self) {
  u8 *e = self + 0x40;
  for (u32 i = 0x800; i != 0; i--, e += 0x44) {
    void *o = *(void **)(e - 4);
    if (o) (*(w4c_s1_t **)o)[2](o);
    u8 *p = *(u8 **)e;
    if (p) ext_634273(p, 4);
  }
  ext_634d10(self + 4, 0, 0x22000);
}
PCREG(6132a0, fn6132a0);

// 0x420e00: stdcall(vkey) ret 4: GetKeyboardState, MapVirtualKeyA(vkey, 0), ToAscii(vkey, scan, state, &out16, 0); when the count is >= 1 returns eax = (count & 0xffff0000) | out16, else 0.
static u32 STDCALL fn420e00(u32 vkey) {
  u8 state[256];
  u16 out = 0;
  ((u32(STDCALL *)(u8 *))G(u32, 0x6761a4))(state);
  u32 scan = ((u32(STDCALL *)(u32, u32))G(u32, 0x6761b0))(vkey, 0);
  s32 n = ((s32(STDCALL *)(u32, u32, u8 *, u16 *, u32))G(u32, 0x6761ac))(vkey, scan, state, &out, 0);
  if (n >= 1) return ((u32)n & 0xffff0000u) | out;
  return 0;
}
PCREG(420e00, fn420e00);
