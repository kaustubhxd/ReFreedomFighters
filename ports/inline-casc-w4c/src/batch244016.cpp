// batch244016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4d06a0_thiscall1(u32, u32) __asm__("ext_4d06a0");
extern "C" u32 THISCALL ext_435a10_thiscall1(u32) __asm__("ext_435a10");
extern "C" u32 THISCALL ext_435d30_thiscall2(u32, u32) __asm__("ext_435d30");
extern "C" u32 THISCALL ext_436170_thiscall2(u32, u32) __asm__("ext_436170");
extern "C" u32 THISCALL ext_4361a0_thiscall2(u32, u32) __asm__("ext_4361a0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc1e0_thiscall3(u32, u32, u32) __asm__("ext_4cc1e0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4f9c90_thiscall2(u32, u32) __asm__("ext_4f9c90");
extern "C" u32 THISCALL ext_639df0_thiscall3(u32, u32, u32) __asm__("ext_639df0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_428420_cdecl4(...) __asm__("ext_428420");
extern "C" u32 ext_633648_cdecl2(...) __asm__("ext_633648");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_428990(u32 ecx_in) {
  SEH_ENTER(0x6647c7);  // @h_428990
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @0_428990
  edi = 0;  // @1_428990
  FL[3] = edi;  // @2_428990
  L4289c0:;
  eax = (u32)(EBP - 96);  // @4_428990
  X0[0] = 0;  // @5_428990
  X0[1] = 0;  // @6_428990
  X0[2] = 0;  // @7_428990
  X0[3] = 0;  // @8_428990
  PV[0] = (u32)(eax);  // @9_428990
  PV[1] = (u32)(edi);  // @10_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 0), &X0[0], 4);  // @11_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 4), &X0[1], 4);  // @12_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 8), &X0[2], 4);  // @13_428990
  __builtin_memcpy((void *)((u32)(EBP - 96) + 12), &X0[3], 4);  // @14_428990
  eax = ext_633648_cdecl2(PV[1], PV[0]);  // @15_428990
    // @16_428990
  FL[2] = (eax & eax);  // @17_428990
  if (FL[2] != 0) goto L428a89;  // @18_428990
  eax = ext_41e290_cdecl1((u32)(118));  // @19_428990
  ecx = edx = 0;  // @20_428990
  esi = eax;  // @21_428990
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @22_428990
  reg.state = (s32)((u32)(0));  // @23_428990
  FL[2] = (esi & esi);  // @24_428990
  if (FL[2] == 0) goto L428a77;  // @25_428990
  ecx = esi;  // @26_428990
  eax = ext_435a10_thiscall1(ecx);  // @27_428990
  ecx = edx = 0;  // @28_428990
  eax = (u32)(EBP - 80);  // @29_428990
  reg.state = (s32)((u32)(1));  // @30_428990
  PV[2] = (u32)(eax);  // @31_428990
  { u32 v = (u32)((u32)(6786640)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @32_428990
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @33_428990
  eax = ext_634d10_cdecl3(PV[2], (u32)(0), (u32)(64));  // @34_428990
    // @35_428990
  PV[3] = (u32)(edi);  // @36_428990
  eax = (u32)(EBP - 80);  // @37_428990
  PV[4] = (u32)(eax);  // @38_428990
  eax = ext_428420_cdecl4(PV[4], (u32)(-1), (u32)(6788384), PV[3]);  // @39_428990
  ecx = edx = 0;  // @40_428990
  eax = (u32)(EBP - 80);  // @41_428990
  ecx = esi;  // @42_428990
  PV[5] = (u32)(eax);  // @43_428990
  eax = ext_4361a0_thiscall2(ecx, PV[5]);  // @44_428990
  ecx = edx = 0;  // @45_428990
  X0[0] = 0;  // @46_428990
  X0[1] = 0;  // @47_428990
  X0[2] = 0;  // @48_428990
  X0[3] = 0;  // @49_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 13), &v, sizeof v); }  // @50_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @51_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @52_428990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @53_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 0), &X0[0], 4);  // @54_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 4), &X0[1], 4);  // @55_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 8), &X0[2], 4);  // @56_428990
  __builtin_memcpy((void *)((u32)(esi + 29) + 12), &X0[3], 4);  // @57_428990
  PV[6] = (u32)(ecx);  // @58_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 0), &X0[0], 4);  // @59_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 4), &X0[1], 4);  // @60_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 8), &X0[2], 4);  // @61_428990
  __builtin_memcpy((void *)((u32)(esi + 45) + 12), &X0[3], 4);  // @62_428990
  ecx = esi;  // @63_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 0), &X0[0], 4);  // @64_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 4), &X0[1], 4);  // @65_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 8), &X0[2], 4);  // @66_428990
  __builtin_memcpy((void *)((u32)(esi + 61) + 12), &X0[3], 4);  // @67_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 0), &X0[0], 4);  // @68_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 4), &X0[1], 4);  // @69_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 8), &X0[2], 4);  // @70_428990
  __builtin_memcpy((void *)((u32)(esi + 77) + 12), &X0[3], 4);  // @71_428990
  eax = ext_436170_thiscall2(ecx, (u32)(1050253722));  // @72_428990
    // @73_428990
  goto L428a79;  // @74_428990
  L428a77:;
  esi = 0;  // @76_428990
  FL[3] = esi;  // @77_428990
  L428a79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 100), sizeof v); (u32)v; });  // @79_428990
  PV[7] = (u32)(esi);  // @80_428990
  reg.state = (s32)((u32)(4294967295));  // @81_428990
  eax = ext_435d30_thiscall2(ecx, PV[7]);  // @82_428990
  edx = 0;  // @83_428990
  L428a89:;
  edi = (edi + 1);  // @85_428990
  FL[3] = edi;  // @86_428990
  FL[0] = edi; FL[1] = (u32)(4);  // @87_428990
  if (FL[0] < FL[1]) goto L4289c0;  // @88_428990
  SEH_LEAVE();  // @89_428990
  ext_633654(G(u32, 0x6f5630));  // @90_428990
  return eax;  // @91_428990
}
PCREG(428990, lifted_428990);

extern "C" u32 THISCALL lifted_4f6f10(u32 ecx_in) {
  SEH_ENTER(0x6699e7);  // @h_4f6f10
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4f6f10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 147), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4f6f10
  if (FL[0] != FL[1]) goto L4f704f;  // @2_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_4f6f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @4_4f6f10
  ecx = edx = 0;  // @5_4f6f10
  ecx = (u32)(EBP - 272);  // @6_4f6f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; });  // @7_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6925952));  // @8_4f6f10
  ecx = edx = 0;  // @9_4f6f10
  ecx = (u32)(EBP - 144);  // @10_4f6f10
  reg.state = (s32)((u32)(0));  // @11_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6838840));  // @12_4f6f10
  ecx = edx = 0;  // @13_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @14_4f6f10
  ecx = (u32)(6801640);  // @15_4f6f10
  FL[2] = (eax & eax);  // @16_4f6f10
  reg.state = (s32)((u32)(1));  // @17_4f6f10
  if (FL[2] != 0) ecx = eax;  // @18_4f6f10
  PV[0] = (u32)(ecx);  // @19_4f6f10
  ecx = (u32)(EBP - 656);  // @20_4f6f10
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @21_4f6f10
  ecx = edx = 0;  // @22_4f6f10
  ecx = (u32)(EBP - 144);  // @23_4f6f10
  reg.state = (s32)((u32)(2));  // @24_4f6f10
  PV[1] = (u32)(ecx);  // @25_4f6f10
  ecx = (u32)(EBP - 528);  // @26_4f6f10
  PV[2] = (u32)(ecx);  // @27_4f6f10
  ecx = eax;  // @28_4f6f10
  eax = ext_4cc1e0_thiscall3(ecx, PV[2], PV[1]);  // @29_4f6f10
  ecx = edx = 0;  // @30_4f6f10
  ecx = (u32)(EBP - 272);  // @31_4f6f10
  reg.state = (s32)((u32)(3));  // @32_4f6f10
  PV[3] = (u32)(ecx);  // @33_4f6f10
  ecx = (u32)(EBP - 400);  // @34_4f6f10
  PV[4] = (u32)(ecx);  // @35_4f6f10
  ecx = eax;  // @36_4f6f10
  eax = ext_4cc1e0_thiscall3(ecx, PV[4], PV[3]);  // @37_4f6f10
  ecx = edx = 0;  // @38_4f6f10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_4f6f10
  ecx = eax;  // @40_4f6f10
  reg.state = (s32)((u32)(4));  // @41_4f6f10
  eax = ext_4cc1d0_thiscall1(ecx);  // @42_4f6f10
    // @43_4f6f10
  PV[5] = (u32)(eax);  // @44_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_4f6f10
  ecx = edi;  // @46_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @47_4f6f10
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @48_4f6f10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 440)))(ecx, PV[6], (u32)(0), PV[5], (u32)(0), (u32)(0));  // @49_4f6f10
  ecx = edx = 0;  // @50_4f6f10
  ecx = (u32)(EBP - 400);  // @51_4f6f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 147), &v, sizeof v); }  // @52_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @53_4f6f10
  ecx = edx = 0;  // @54_4f6f10
  ecx = (u32)(EBP - 528);  // @55_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @56_4f6f10
  ecx = edx = 0;  // @57_4f6f10
  ecx = (u32)(EBP - 656);  // @58_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @59_4f6f10
  ecx = edx = 0;  // @60_4f6f10
  ecx = (u32)(EBP - 144);  // @61_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @62_4f6f10
  ecx = edx = 0;  // @63_4f6f10
  ecx = (u32)(EBP - 272);  // @64_4f6f10
  reg.state = (s32)((u32)(4294967295));  // @65_4f6f10
  eax = ext_4cbec0_thiscall1(ecx);  // @66_4f6f10
  ecx = edx = 0;  // @67_4f6f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @68_4f6f10
  ecx = ebx;  // @69_4f6f10
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 147), sizeof v); (u32)v; });  // @70_4f6f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 876)))(ecx, PV[7]);  // @71_4f6f10
  ecx = edx = 0;  // @72_4f6f10
  L4f704f:;
  SEH_LEAVE();  // @74_4f6f10
  ext_633654(G(u32, 0x6f5630));  // @75_4f6f10
  return eax;  // @76_4f6f10
}
PCREG(4f6f10, lifted_4f6f10);

extern "C" u32 THISCALL lifted_4f8c50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4f8c50
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_4f8c50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4f8c50
  PV[0] = (u32)(esi);  // @2_4f8c50
  eax = ext_4f9c90_thiscall2(ecx, PV[0]);  // @3_4f8c50
  ecx = edx = 0;  // @4_4f8c50
  eax = (u32)(EBP - 148);  // @5_4f8c50
  ecx = esi;  // @6_4f8c50
  PV[1] = (u32)(eax);  // @7_4f8c50
  eax = ext_4e12e0_thiscall3(ecx, PV[1], (u32)(1));  // @8_4f8c50
    // @9_4f8c50
  eax = (u32)(ebx + 455);  // @10_4f8c50
  ecx = esi;  // @11_4f8c50
  PV[2] = (u32)(eax);  // @12_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, PV[2], (u32)(1));  // @13_4f8c50
  ecx = edx = 0;  // @14_4f8c50
  eax = (u32)(ebx + 459);  // @15_4f8c50
  ecx = esi;  // @16_4f8c50
  PV[3] = (u32)(eax);  // @17_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, PV[3], (u32)(1));  // @18_4f8c50
  ecx = edx = 0;  // @19_4f8c50
  eax = (u32)(ebx + 471);  // @20_4f8c50
  ecx = esi;  // @21_4f8c50
  PV[4] = (u32)(eax);  // @22_4f8c50
  eax = ext_4e11e0_thiscall3(ecx, PV[4], (u32)(1));  // @23_4f8c50
  ecx = edx = 0;  // @24_4f8c50
  ecx = esi;  // @25_4f8c50
  eax = ext_4e1b30_thiscall1(ecx);  // @26_4f8c50
  ecx = edx = 0;  // @27_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_4f8c50
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @29_4f8c50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_4f8c50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @32_4f8c50
  ecx = edx = 0;  // @33_4f8c50
  ecx = eax;  // @34_4f8c50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(ebx + 451), &v, sizeof v); }  // @35_4f8c50
  FL[2] = (ecx & ecx);  // @36_4f8c50
  if (FL[2] == 0) goto L4f8d05;  // @37_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @39_4f8c50
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097199));  // @40_4f8c50
  ecx = edx = 0;  // @41_4f8c50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @42_4f8c50
  if (FL[2] != 0) goto L4f8d5e;  // @43_4f8c50
  L4f8d05:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @45_4f8c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_4f8c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6927940), (u32)(37));  // @47_4f8c50
  ecx = edx = 0;  // @48_4f8c50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @49_4f8c50
  edi = eax;  // @50_4f8c50
  eax = (u32)(EBP - 144);  // @51_4f8c50
  ecx = ebx;  // @52_4f8c50
  PV[6] = (u32)(eax);  // @53_4f8c50
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(1));  // @54_4f8c50
  ecx = edx = 0;  // @55_4f8c50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_4f8c50
  ecx = eax;  // @57_4f8c50
  reg.state = (s32)((u32)(0));  // @58_4f8c50
  eax = ext_4cc1d0_thiscall1(ecx);  // @59_4f8c50
    // @60_4f8c50
  PV[7] = (u32)(eax);  // @61_4f8c50
  PV[8] = (u32)(edi);  // @62_4f8c50
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))(PV[8], (u32)(6927984), PV[7]);  // @63_4f8c50
  ecx = edx = 0;  // @64_4f8c50
  ecx = (u32)(EBP - 144);  // @65_4f8c50
  eax = ext_4cbec0_thiscall1(ecx);  // @66_4f8c50
  ecx = edx = 0;  // @67_4f8c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 451), &v, sizeof v); }  // @68_4f8c50
  L4f8d5e:;
  SEH_LEAVE();  // @70_4f8c50
  ext_633654(G(u32, 0x6f5630));  // @71_4f8c50
  return eax;  // @72_4f8c50
}
PCREG(4f8c50, lifted_4f8c50);

extern "C" u32 THISCALL lifted_4f91f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669acb);  // @h_4f91f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4f91f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 164), &v, sizeof v); }  // @1_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4f91f0
  ecx = (u32)(EBP - 144);  // @3_4f91f0
  PV[0] = (u32)(esi);  // @4_4f91f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @5_4f91f0
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @6_4f91f0
  ecx = edx = 0;  // @7_4f91f0
  eax = (u32)(edi + 143);  // @8_4f91f0
  reg.state = (s32)((u32)(0));  // @9_4f91f0
  ecx = (u32)(EBP - 144);  // @10_4f91f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @11_4f91f0
  PV[1] = (u32)(ecx);  // @12_4f91f0
  ecx = eax;  // @13_4f91f0
  eax = ext_4cbee0_thiscall2(ecx, PV[1]);  // @14_4f91f0
  ecx = edx = 0;  // @15_4f91f0
  ecx = (u32)(EBP - 144);  // @16_4f91f0
  reg.state = (s32)((u32)(4294967295));  // @17_4f91f0
  eax = ext_4cbec0_thiscall1(ecx);  // @18_4f91f0
  ecx = edx = 0;  // @19_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 271), sizeof v); (u32)v; });  // @20_4f91f0
  ecx = (u32)(edi + 271);  // @21_4f91f0
  ebx = 0;  // @22_4f91f0
  FL[3] = ebx;  // @23_4f91f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @24_4f91f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @25_4f91f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @26_4f91f0
  ecx = edx = 0;  // @27_4f91f0
  FL[2] = (eax & eax);  // @28_4f91f0
  if ((s32)FL[2] <= 0) goto L4f92f6;  // @29_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @30_4f91f0
  L4f9295:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_4f91f0
  ecx = esi;  // @33_4f91f0
  PV[2] = (u32)(ebx);  // @34_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_4f91f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @37_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[2]);  // @38_4f91f0
  ecx = edx = 0;  // @39_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4f91f0
  PV[3] = (u32)(eax);  // @41_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @42_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 88)))(ecx, PV[3]);  // @43_4f91f0
  ecx = edx = 0;  // @44_4f91f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @45_4f91f0
  edi = eax;  // @46_4f91f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_4f91f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @48_4f91f0
    // @49_4f91f0
  PV[4] = (u32)(eax);  // @50_4f91f0
  ecx = edi;  // @51_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(ebx + 644)))(ecx, PV[4]);  // @52_4f91f0
  ecx = edx = 0;  // @53_4f91f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @54_4f91f0
  ecx = esi;  // @55_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @56_4f91f0
  ebx = (ebx + 1);  // @57_4f91f0
  FL[3] = ebx;  // @58_4f91f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @59_4f91f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @60_4f91f0
  ecx = edx = 0;  // @61_4f91f0
  FL[0] = ebx; FL[1] = eax;  // @62_4f91f0
  if ((s32)FL[0] < (s32)FL[1]) goto L4f9295;  // @63_4f91f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @64_4f91f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @65_4f91f0
  L4f92f6:;
  ecx = (u32)(esi + 1);  // @67_4f91f0
  L4f9300:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @69_4f91f0
  esi = (esi + 1);  // @70_4f91f0
  FL[3] = esi;  // @71_4f91f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @72_4f91f0
  if (FL[2] != 0) goto L4f9300;  // @73_4f91f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_4f91f0
  esi = (esi - ecx);  // @75_4f91f0
  FL[3] = esi;  // @76_4f91f0
  PV[5] = (u32)(esi);  // @77_4f91f0
  ecx = edi;  // @78_4f91f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 868)))(ecx, PV[5]);  // @79_4f91f0
  ecx = edx = 0;  // @80_4f91f0
  SEH_LEAVE();  // @81_4f91f0
  ext_633654(G(u32, 0x6f5630));  // @82_4f91f0
  return eax;  // @83_4f91f0
}
PCREG(4f91f0, lifted_4f91f0);

extern "C" u32 THISCALL lifted_6387d0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @0_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_6387d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6387d0
  PV[0] = (u32)(eax);  // @3_6387d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[0]);  // @4_6387d0
  ecx = edx = 0;  // @5_6387d0
  ebx = eax;  // @6_6387d0
  { u32 v = (u32)((u32)(255)); __builtin_memcpy((void *)(u32)(EBP - 100), &v, sizeof v); }  // @7_6387d0
  eax = (u32)(EBP - 100);  // @8_6387d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 120), &v, sizeof v); }  // @9_6387d0
  PV[1] = (u32)(eax);  // @10_6387d0
  ecx = eax;  // @11_6387d0
  { u32 v = (u32)((u32)(65280)); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @12_6387d0
  { u32 v = (u32)((u32)(16711680)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @13_6387d0
  { u32 v = (u32)((u32)(4278190080)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @14_6387d0
  eax = ext_4d06a0_thiscall1(ecx, PV[1]);  // @15_6387d0
  ecx = edx = 0;  // @16_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @17_6387d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @18_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @19_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @20_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @21_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @22_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @23_6387d0
  eax = (u32)(EBP - 52);  // @24_6387d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @25_6387d0
  ecx = (u32)(EBP - 100);  // @26_6387d0
  PV[2] = (u32)(eax);  // @27_6387d0
  eax = ext_4d06a0_thiscall1(ecx, PV[2]);  // @28_6387d0
  ecx = edx = 0;  // @29_6387d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @30_6387d0
  edx = 0;  // @31_6387d0
  FL[3] = edx;  // @32_6387d0
  ecx = (u32)((s32)ecx * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }));  // @33_6387d0
  FL[3] = ecx;  // @34_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @35_6387d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @36_6387d0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @37_6387d0
  FL[3] = ecx;  // @38_6387d0
  ecx = (u32)(eax + ecx*4);  // @39_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @40_6387d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @41_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @42_6387d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); FL[1] = edx;  // @43_6387d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L6388c2;  // @44_6387d0
  L638861:;
  ebx = 0;  // @46_6387d0
  FL[3] = ebx;  // @47_6387d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }); FL[1] = ebx;  // @48_6387d0
  if ((s32)FL[0] <= (s32)FL[1]) goto L6388a3;  // @49_6387d0
  eax = (eax - ecx);  // @50_6387d0
  FL[3] = eax;  // @51_6387d0
  edi = ecx;  // @52_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 116), &v, sizeof v); }  // @53_6387d0
  L638870:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @55_6387d0
  ecx = (u32)(EBP - 100);  // @56_6387d0
  PV[3] = (u32)(eax);  // @57_6387d0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @58_6387d0
  eax = ext_639df0_thiscall3(ecx, PV[4], PV[3]);  // @59_6387d0
  ecx = edx = 0;  // @60_6387d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }); FL[1] = (u32)(16);  // @61_6387d0
  if (FL[0] != FL[1]) goto L63888e;  // @62_6387d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @63_6387d0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + ebx*2), &v, sizeof v); }  // @64_6387d0
  goto L638894;  // @65_6387d0
  L63888e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 116), sizeof v); (u32)v; });  // @67_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + edi), &v, sizeof v); }  // @68_6387d0
  L638894:;
  ebx = (ebx + 1);  // @70_6387d0
  FL[3] = ebx;  // @71_6387d0
  edi = (edi + (u32)(4));  // @72_6387d0
  FL[3] = edi;  // @73_6387d0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @74_6387d0
  if ((s32)FL[0] < (s32)FL[1]) goto L638870;  // @75_6387d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 108), sizeof v); (u32)v; });  // @76_6387d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 112), sizeof v); (u32)v; });  // @77_6387d0
  L6388a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 120), sizeof v); (u32)v; });  // @79_6387d0
  edx = (edx + 1);  // @80_6387d0
  FL[3] = edx;  // @81_6387d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 112), &v, sizeof v); }  // @82_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @83_6387d0
  ecx = (u32)(ecx + eax*4);  // @84_6387d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 104), sizeof v); (u32)v; });  // @85_6387d0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @86_6387d0
  FL[3] = eax;  // @87_6387d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 108), &v, sizeof v); }  // @88_6387d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 104), &v, sizeof v); }  // @89_6387d0
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @90_6387d0
  if ((s32)FL[0] < (s32)FL[1]) goto L638861;  // @91_6387d0
  L6388c2:;
  ext_633654(G(u32, 0x6f5630));  // @93_6387d0
  return eax;  // @94_6387d0
}
PCREG(6387d0, lifted_6387d0);

extern "C" u32 THISCALL lifted_532f30(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_532f30
  edx = ecx;  // @1_532f30
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_532f30
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 136) + 0), 4); v; });  // @3_532f30
  X1[1] = 0;  // @4_532f30
  X1[2] = 0;  // @5_532f30
  X1[3] = 0;  // @6_532f30
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 132) + 0), 4); v; })));  // @7_532f30
  __builtin_memcpy((void *)((u32)(esi + 76) + 0), &X1[0], 4);  // @8_532f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @9_532f30
  eax = (u32)(edx + ecx*8);  // @10_532f30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax + 20825) + 0), 4); v; });  // @11_532f30
  X0[1] = 0;  // @12_532f30
  X0[2] = 0;  // @13_532f30
  X0[3] = 0;  // @14_532f30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 20913) + 0), 4); v; })));  // @15_532f30
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @16_532f30
  __builtin_memcpy((void *)((u32)(esi + 76) + 0), &X0[0], 4);  // @17_532f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @18_532f30
  eax = (u32)(edx + ecx*8);  // @19_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax + 20830), sizeof v); (u32)v; });  // @20_532f30
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 100), sizeof v); (u32)v; }));  // @21_532f30
  FL[3] = eax;  // @22_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @23_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @24_532f30
  eax = (eax - 1);  // @25_532f30
  FL[3] = eax;  // @26_532f30
  FL[0] = eax; FL[1] = (u32)(9);  // @27_532f30
  if (FL[0] > FL[1]) goto L5330c8;  // @28_532f30
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5452012), sizeof v); (u32)v; });  // @29_532f30
  switch (eax) {  // @30_532f30
  case 0: goto L53306d;  // @31_532f30
  case 1: goto L532fa0;  // @32_532f30
  case 2: goto L532fc0;  // @33_532f30
  default: __builtin_trap(); }  // @34_532f30
  L532fa0:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @36_532f30
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @37_532f30
  { u32 v = (u32)((u32)(116)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @38_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; });  // @39_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @40_532f30
  return eax;  // @41_532f30
  L532fc0:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @43_532f30
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @44_532f30
  { u32 v = (u32)((u32)(192)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @45_532f30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 88) + 0), 4); v; });  // @46_532f30
  X0[1] = 0;  // @47_532f30
  X0[2] = 0;  // @48_532f30
  X0[3] = 0;  // @49_532f30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; })));  // @50_532f30
  __builtin_memcpy((void *)((u32)(esi + 172) + 0), &X0[0], 4);  // @51_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @52_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @53_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @54_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @55_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @56_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @57_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @58_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 188), &v, sizeof v); }  // @59_532f30
  L53300a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 224), sizeof v); (u32)v; });  // @61_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 112), &v, sizeof v); }  // @62_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 228), sizeof v); (u32)v; });  // @63_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 116), &v, sizeof v); }  // @64_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 232), sizeof v); (u32)v; });  // @65_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 120), &v, sizeof v); }  // @66_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 212), sizeof v); (u32)v; });  // @67_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 148), &v, sizeof v); }  // @68_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 216), sizeof v); (u32)v; });  // @69_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 152), &v, sizeof v); }  // @70_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 220), sizeof v); (u32)v; });  // @71_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 156), &v, sizeof v); }  // @72_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 168), &v, sizeof v); }  // @73_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @74_532f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 160), &v, sizeof v); }  // @75_532f30
  return eax;  // @76_532f30
  L53306d:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @78_532f30
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @79_532f30
  { u32 v = (u32)((u32)(192)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @80_532f30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 88) + 0), 4); v; });  // @81_532f30
  X0[1] = 0;  // @82_532f30
  X0[2] = 0;  // @83_532f30
  X0[3] = 0;  // @84_532f30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 84) + 0), 4); v; })));  // @85_532f30
  __builtin_memcpy((void *)((u32)(esi + 172) + 0), &X0[0], 4);  // @86_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @87_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 176), &v, sizeof v); }  // @88_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @89_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 180), &v, sizeof v); }  // @90_532f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @91_532f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 184), &v, sizeof v); }  // @92_532f30
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @93_532f30
  X0[1] = 0;  // @94_532f30
  X0[2] = 0;  // @95_532f30
  X0[3] = 0;  // @96_532f30
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @97_532f30
  __builtin_memcpy((void *)((u32)(esi + 188) + 0), &X0[0], 4);  // @98_532f30
  goto L53300a;  // @99_532f30
  L5330c8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @101_532f30
  FL[2] = (eax & eax);  // @102_532f30
  if (FL[2] == 0) goto L5330d9;  // @103_532f30
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @104_532f30
  ecx = edx = 0;  // @105_532f30
  return eax;  // @106_532f30
  L5330d9:;
  __builtin_trap();  // @108_532f30
}
// (lifted_532f30 replaced by the hand port below: shared jump-table tail and SSE operand order)


typedef u32(*w4c_hook_t)();
static inline float w4c_f(u8 *p) { return *(float *)p; }
// 0x532f30 hand port: thiscall(src, dst) ret 8. dst+0x4c = (src+0x88 * src+0x84), then scaled by the per-row float table (this + row*9 + 0x5159) and this+0x51b1;
// dst+0x28 = table dword (this + row*9 + 0x515e) + src+0x64; mode [src+8]-1: 0 -> kind 2/1 with 100.0f scaling, 1..8 -> kind 1, 9 -> kind 2/10; others: assert hook (int3 when null).
static u32 THISCALL fn532f30(u8 *self, u8 *src, u8 *dst) {
  float x1 = w4c_f(src + 0x88) * w4c_f(src + 0x84);
  *(float *)(dst + 0x4c) = x1;
  u32 row = *(u32 *)(src + 0x2c);
  float x0 = (w4c_f(self + row * 9 + 0x5159) * w4c_f(self + 0x51b1)) * x1;
  *(float *)(dst + 0x4c) = x0;
  row = *(u32 *)(src + 0x2c);
  *(u32 *)(dst + 0x28) = *(u32 *)(self + row * 9 + 0x515e) + *(u32 *)(src + 0x64);
  u32 mode = *(u32 *)(src + 8) - 1;
  if (mode > 9) {
    w4c_hook_t h = G(w4c_hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    return h();
  }
  if (mode >= 1 && mode <= 8) {
    *(u32 *)dst = 1;
    *(u32 *)(dst + 0x24) = 3;
    *(u32 *)(dst + 4) = 0x74;
    u32 v = *(u32 *)(src + 0x68);
    *(u32 *)(dst + 0x70) = v;
    return v;
  }
  *(u32 *)dst = 2;
  *(u32 *)(dst + 4) = 0xc0;
  *(float *)(dst + 0xac) = w4c_f(src + 0x58) * w4c_f(src + 0x54);
  *(u32 *)(dst + 0xb0) = *(u32 *)(src + 0x5c);
  *(u32 *)(dst + 0xb4) = *(u32 *)(src + 0x44);
  *(u32 *)(dst + 0xb8) = *(u32 *)(src + 0x48);
  if (mode == 0) {
    *(u32 *)(dst + 0x24) = 1;
    *(float *)(dst + 0xbc) = w4c_f(src + 0x4c) * G(float, 0x67cd40);
  } else {
    *(u32 *)(dst + 0x24) = 0xa;
    *(u32 *)(dst + 0xbc) = *(u32 *)(src + 0x4c);
  }
  *(u32 *)(dst + 0x70) = *(u32 *)(src + 0xe0);
  *(u32 *)(dst + 0x74) = *(u32 *)(src + 0xe4);
  *(u32 *)(dst + 0x78) = *(u32 *)(src + 0xe8);
  *(u32 *)(dst + 0x94) = *(u32 *)(src + 0xd4);
  *(u32 *)(dst + 0x98) = *(u32 *)(src + 0xd8);
  u32 last = *(u32 *)(src + 0xdc);
  *(u32 *)(dst + 0x9c) = last;
  *(u32 *)(dst + 0xa8) = 0;
  *(u32 *)(dst + 0xa4) = 0;
  *(u32 *)(dst + 0xa0) = 0;
  return last;
}
PCREG(532f30, fn532f30);
