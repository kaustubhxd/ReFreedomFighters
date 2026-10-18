// batch244012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4e2560_fastcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_4e2560");
extern "C" u32 THISCALL ext_48c4b0_thiscall3(u32, u32, u32) __asm__("ext_48c4b0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_6616f0_thiscall10(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_6616f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_463350(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_463350
  esi = ecx;  // @1_463350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_463350
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_463350
  ecx = edx = 0;  // @5_463350
  ecx = (u32)(EBP - 4);  // @6_463350
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_463350
  PV[0] = (u32)(ecx);  // @8_463350
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_463350
  ecx = eax;  // @10_463350
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6838808), PV[0]);  // @11_463350
  ecx = edx = 0;  // @12_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_463350
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @14_463350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_463350
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @17_463350
  ecx = edx = 0;  // @18_463350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_463350
  ebx = eax;  // @20_463350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @21_463350
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_463350
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 312)))(ecx);  // @23_463350
  ecx = edx = 0;  // @24_463350
  ecx = (u32)(EBP - 4);  // @25_463350
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @26_463350
  PV[2] = (u32)(ecx);  // @27_463350
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_463350
  ecx = eax;  // @29_463350
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6838820), PV[2]);  // @30_463350
  ecx = edx = 0;  // @31_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_463350
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @33_463350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @34_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_463350
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @36_463350
  ecx = edx = 0;  // @37_463350
  edi = eax;  // @38_463350
  FL[2] = (ebx & ebx);  // @39_463350
  if (FL[2] == 0) goto L4633ea;  // @40_463350
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 282), &v, sizeof v); }  // @41_463350
  goto L463410;  // @42_463350
  L4633ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_463350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @46_463350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_463350
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6838808), (u32)(0));  // @48_463350
  ecx = edx = 0;  // @49_463350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 282), &v, sizeof v); }  // @50_463350
  L463410:;
  FL[2] = (edi & edi);  // @52_463350
  if (FL[2] == 0) goto L46341a;  // @53_463350
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 286), &v, sizeof v); }  // @54_463350
  L46341a:;
  return eax;  // @56_463350
}
PCREG(463350, lifted_463350);

extern "C" u32 STDCALL lifted_661b40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  __builtin_memcpy(F + 0x300 + 36, &a7, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @0_661b40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_661b40
  eax = (eax + (u32)(-2));  // @2_661b40
  FL[3] = eax;  // @3_661b40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 20), &v, sizeof v); }  // @4_661b40
  FL[0] = esi; FL[1] = eax;  // @5_661b40
  if (FL[0] == FL[1]) goto L661bbb;  // @6_661b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_661b40
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; })) & 0xff);  // @8_661b40
  ecx = (ecx + (u32)(2));  // @9_661b40
  FL[3] = ecx;  // @10_661b40
  L661b5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 36), sizeof v); (u32)v; });  // @12_661b40
  edi = (u32)(ecx + 2);  // @13_661b40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_661b40
  PV[0] = (u32)(eax);  // @15_661b40
  eax = (u32)(EBP + 24);  // @16_661b40
  PV[1] = (u32)(eax);  // @17_661b40
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @18_661b40
  if (FL[2] == 0) goto L661b80;  // @19_661b40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_661b40
  eax = (u32)(eax + eax*8);  // @21_661b40
  eax = (u32)(edx + eax*4);  // @22_661b40
  PV[2] = (u32)(eax);  // @23_661b40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_661b40
  goto L661b8d;  // @25_661b40
  L661b80:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_661b40
  eax = (u32)(eax + eax*8);  // @28_661b40
  eax = (u32)(edx + eax*4);  // @29_661b40
  PV[2] = (u32)(eax);  // @30_661b40 (w4c: both diamond arms feed the same pushed slot)
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_661b40
  L661b8d:;
  eax = (u32)(eax + eax*8);  // @33_661b40
  eax = (u32)(edx + eax*4);  // @34_661b40
  PV[4] = (u32)(eax);  // @35_661b40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 2), sizeof v); (u32)v; });  // @36_661b40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @37_661b40
  eax = (u32)(eax + eax*8);  // @38_661b40
  eax = (u32)(edx + eax*4);  // @39_661b40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; });  // @40_661b40
  PV[5] = (u32)(eax);  // @41_661b40
  eax = ext_4e2560_fastcall7(ecx, edx, PV[5], PV[4], PV[2], PV[1], PV[0]);  // @42_661b40
    // @43_661b40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @44_661b40
  if (FL[2] != 0) goto L661bc4;  // @45_661b40
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @46_661b40
  ecx = edi;  // @47_661b40
  ebx = (ebx & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @48_661b40
  esi = (esi + 1);  // @49_661b40
  FL[3] = esi;  // @50_661b40
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @51_661b40
  if (FL[0] != FL[1]) goto L661b5f;  // @52_661b40
  L661bbb:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @54_661b40
  FL[3] = (eax & 0xff);  // @55_661b40
  return eax;  // @56_661b40
  L661bc4:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @58_661b40
  return eax;  // @59_661b40
}
PCREG(661b40, lifted_661b40);

extern "C" u32 THISCALL lifted_639c50(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_639c50
  ebx = 0;  // @1_639c50
  FL[3] = ebx;  // @2_639c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_639c50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @4_639c50
  ecx = edx = 0;  // @5_639c50
  FL[2] = (eax & eax);  // @6_639c50
  if (FL[2] == 0) goto L639c8d;  // @7_639c50
  edi = 0;  // @8_639c50
  FL[3] = edi;  // @9_639c50
  L639c65:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @11_639c50
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @12_639c50
  if (FL[0] == FL[1]) goto L639c7d;  // @13_639c50
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi + 16), sizeof v); (u32)v; });  // @14_639c50
  eax = ext_634273_cdecl2(PV[0], (u32)(1));  // @15_639c50
  ecx = edx = 0;  // @16_639c50
  L639c7d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @18_639c50
  ecx = esi;  // @19_639c50
  ebx = (ebx + 1);  // @20_639c50
  FL[3] = ebx;  // @21_639c50
  edi = (edi + (u32)(20));  // @22_639c50
  FL[3] = edi;  // @23_639c50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @24_639c50
  ecx = edx = 0;  // @25_639c50
  FL[0] = ebx; FL[1] = eax;  // @26_639c50
  if (FL[0] < FL[1]) goto L639c65;  // @27_639c50
  L639c8d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @29_639c50
  FL[2] = (eax & eax);  // @30_639c50
  if (FL[2] == 0) goto L639c9f;  // @31_639c50
  PV[1] = (u32)(eax);  // @32_639c50
  eax = ext_634273_cdecl2(PV[1], (u32)(20));  // @33_639c50
  ecx = edx = 0;  // @34_639c50
  L639c9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_639c50
  ecx = 0;  // @37_639c50
  FL[3] = ecx;  // @38_639c50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @39_639c50
  edx = (u32)(20);  // @40_639c50
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @41_639c50
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @42_639c50
  FL[1] = ecx;  // @43_639c50
  ecx = (0u - ecx);  // @44_639c50
  ecx = (ecx | eax);  // @45_639c50
  FL[3] = ecx;  // @46_639c50
  PV[2] = (u32)(ecx);  // @47_639c50
  eax = ext_41e290_cdecl1(PV[2]);  // @48_639c50
  ecx = edx = 0;  // @49_639c50
  edx = 0;  // @50_639c50
  FL[3] = edx;  // @51_639c50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @52_639c50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }); FL[1] = edx;  // @53_639c50
  if ((s32)FL[0] <= (s32)FL[1]) goto L639cf7;  // @54_639c50
  ecx = 0;  // @55_639c50
  FL[3] = ecx;  // @56_639c50
  L639cd0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @58_639c50
  ecx = (u32)(ecx + 20);  // @59_639c50
  edx = (edx + 1);  // @60_639c50
  FL[3] = edx;  // @61_639c50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx - 8), &v, sizeof v); }  // @62_639c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @63_639c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx - 4), &v, sizeof v); }  // @64_639c50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @65_639c50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + eax - 20), &v, sizeof v); }  // @66_639c50
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @67_639c50
  if ((s32)FL[0] < (s32)FL[1]) goto L639cd0;  // @68_639c50
  L639cf7:;
  return eax;  // @70_639c50
}
PCREG(639c50, lifted_639c50);

extern "C" u32 THISCALL lifted_491140(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x664d1b);  // @h_491140
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_491140
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_491140
  PV[0] = (u32)(ecx);  // @3_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @4_491140
  eax = ((u32(STDCALL *)(u32, u32, u32))(eax))((u32)(2), (u32)(0), (u32)(0));  // @5_491140
  ecx = edx = 0;  // @6_491140
  eax = (u32)(EBP - 144);  // @7_491140
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @8_491140
  PV[1] = (u32)(eax);  // @9_491140
  ecx = ebx;  // @10_491140
  eax = ext_48c4b0_thiscall3(ecx, PV[1], (u32)(6871120));  // @11_491140
  ecx = edx = 0;  // @12_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @13_491140
  ecx = (u32)(EBP - 144);  // @14_491140
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @15_491140
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_491140
  PV[3] = (u32)(edi);  // @17_491140
  reg.state = (s32)((u32)(0));  // @18_491140
  eax = ext_4cc1d0_thiscall1(ecx);  // @19_491140
    // @20_491140
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @21_491140
  PV[4] = (u32)(eax);  // @22_491140
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 96)))(ecx, PV[4], PV[3], PV[2], (u32)(0), (u32)(0));  // @23_491140
  ecx = edx = 0;  // @24_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_491140
  PV[5] = (u32)(ecx);  // @26_491140
  ecx = ebx;  // @27_491140
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 144), sizeof v); (u32)v; });  // @28_491140
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, (u32)(2), (u32)(0), (u32)(1041865114));  // @29_491140
  ecx = edx = 0;  // @30_491140
  ecx = (u32)(EBP - 144);  // @31_491140
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @32_491140
  eax = ext_4cbec0_thiscall1(ecx);  // @33_491140
  ecx = edx = 0;  // @34_491140
  SEH_LEAVE();  // @35_491140
  ext_633654(G(u32, 0x6f5630));  // @36_491140
  return eax;  // @37_491140
}
PCREG(491140, lifted_491140);

extern "C" u32 THISCALL lifted_661650(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @1_661650
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_661650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @3_661650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @4_661650
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_661650
  esi = edx;  // @6_661650
  eax = edx;  // @7_661650
  ebx = (edx & 0xffff);  // @8_661650
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_661650
  eax = (eax >> (u32)(31));  // @10_661650
  FL[3] = eax;  // @11_661650
  edx = (edx + ecx);  // @12_661650
  FL[3] = edx;  // @13_661650
  esi = (esi >> (u32)(16));  // @14_661650
  FL[3] = esi;  // @15_661650
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @16_661650
  FL[3] = (eax & 0xff);  // @17_661650
  esi = (esi & (u32)(32767));  // @18_661650
  FL[3] = esi;  // @19_661650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @20_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @21_661650
  ebx = (ebx + esi);  // @22_661650
  FL[3] = ebx;  // @23_661650
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @24_661650
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax);  // @25_661650
  if (FL[2] == 0) goto L6616e5;  // @26_661650
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @27_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @28_661650
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @29_661650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @30_661650
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @31_661650
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @32_661650
  FL[3] = ecx;  // @33_661650
  eax = (u32)(eax + esi*2);  // @34_661650
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @35_661650
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @36_661650
  FL[3] = eax;  // @37_661650
  PV[4] = (u32)(ebx);  // @38_661650
  PV[5] = (u32)(esi);  // @39_661650
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @40_661650
  PV[6] = (u32)(eax);  // @41_661650
  PV[7] = (u32)(ecx);  // @42_661650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @43_661650
  PV[8] = (u32)(esi);  // @44_661650
  eax = ext_6616f0_thiscall10(ecx, PV[8], PV[7], PV[6], PV[5], PV[4], PV[3], PV[2], PV[1], PV[0]);  // @45_661650
  ecx = edx = 0;  // @46_661650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @47_661650
  if (FL[2] == 0) goto L6616e5;  // @48_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 56), sizeof v); (u32)v; });  // @49_661650
  eax = (eax << (u32)(16));  // @50_661650
  FL[3] = eax;  // @51_661650
  eax = (eax | (u32)(3));  // @52_661650
  FL[3] = eax;  // @53_661650
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @54_661650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @55_661650
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @56_661650
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @57_661650
  return eax;  // @58_661650
  L6616e5:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @60_661650
  FL[3] = (eax & 0xff);  // @61_661650
  return eax;  // @62_661650
}
PCREG(661650, lifted_661650);

