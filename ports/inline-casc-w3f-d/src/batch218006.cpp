// batch218006.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_430620_fastcall4(u32, u32, u32, u32) __asm__("ext_430620");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_430010_thiscall2(u32, u32) __asm__("ext_430010");
extern "C" u32 THISCALL ext_45c3e0_thiscall1(u32) __asm__("ext_45c3e0");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4e5000_thiscall1(u32) __asm__("ext_4e5000");
extern "C" u32 THISCALL ext_4e8450_thiscall2(u32, u32) __asm__("ext_4e8450");
extern "C" u32 THISCALL ext_5eaab0_thiscall3(u32, u32, u32) __asm__("ext_5eaab0");
extern "C" u32 THISCALL ext_5f10c0_thiscall2(u32, u32) __asm__("ext_5f10c0");
extern "C" u32 THISCALL ext_5fad90_thiscall1(u32) __asm__("ext_5fad90");
extern "C" u32 THISCALL ext_5fb110_thiscall2(u32, u32) __asm__("ext_5fb110");
extern "C" u32 THISCALL ext_5fb370_thiscall2(u32, u32) __asm__("ext_5fb370");
extern "C" u32 THISCALL ext_5fb980_thiscall3(u32, u32, u32) __asm__("ext_5fb980");
extern "C" u32 THISCALL ext_602290_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_602290");
extern "C" u32 THISCALL ext_602530_thiscall1(u32) __asm__("ext_602530");
extern "C" u32 THISCALL ext_61bbd0_thiscall1(u32) __asm__("ext_61bbd0");
extern "C" u32 THISCALL ext_61bbe0_thiscall1(u32) __asm__("ext_61bbe0");
extern "C" u32 THISCALL ext_61bbf0_thiscall4(u32, u32, u32, u32) __asm__("ext_61bbf0");
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)








extern "C" u32 THISCALL lifted_449d80(u32 ecx_in) {
  SEH_ENTER(0x666040);  // @h_449d80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @1_449d80
  { u32 v = (u32)((u32)(6813212)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @2_449d80
  if ((ecx & ecx) == 0) goto L449dbd;  // @3_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @5_449d80
  ecx = edx = 0;  // @6_449d80
  L449dbd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @8_449d80
  if ((ecx & ecx) == 0) goto L449e6b;  // @9_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_449d80
  edx = (u32)(EBP - 24);  // @11_449d80
  PV[0] = (u32)(edx);  // @12_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @13_449d80
  ecx = edx = 0;  // @14_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @15_449d80
  edx = (u32)(EBP - 24);  // @16_449d80
  PV[1] = (u32)(edx);  // @17_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @19_449d80
  ecx = edx = 0;  // @20_449d80
  ebx = eax;  // @21_449d80
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L449e5e;  // @22_449d80
  L449de5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @24_449d80
  if ((ecx & ecx) == 0) goto L449e4a;  // @25_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_449d80
  edx = (u32)(EBP - 36);  // @27_449d80
  PV[2] = (u32)(edx);  // @28_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[2]);  // @29_449d80
  ecx = edx = 0;  // @30_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @31_449d80
  edx = (u32)(EBP - 36);  // @32_449d80
  PV[3] = (u32)(edx);  // @33_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[3]);  // @35_449d80
  ecx = edx = 0;  // @36_449d80
  esi = eax;  // @37_449d80
  if ((esi & esi) == 0) goto L449e4a;  // @38_449d80
  L449e10:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_449d80
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_449d80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @42_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @44_449d80
  ecx = edx = 0;  // @45_449d80
  if ((eax & eax) == 0) goto L449e38;  // @46_449d80
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; });  // @47_449d80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_449d80
  PV[5] = (u32)(ebx);  // @49_449d80
  PV[6] = (u32)(ecx);  // @50_449d80
  ecx = eax;  // @51_449d80
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[6], PV[5], (u32)(0));  // @52_449d80
  ecx = edx = 0;  // @53_449d80
  L449e38:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @55_449d80
  edx = (u32)(EBP - 36);  // @56_449d80
  PV[7] = (u32)(edx);  // @57_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[7]);  // @59_449d80
  ecx = edx = 0;  // @60_449d80
  esi = eax;  // @61_449d80
  if ((esi & esi) != 0) goto L449e10;  // @62_449d80
  L449e4a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @64_449d80
  edx = (u32)(EBP - 24);  // @65_449d80
  PV[8] = (u32)(edx);  // @66_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @68_449d80
  ecx = edx = 0;  // @69_449d80
  ebx = eax;  // @70_449d80
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L449de5;  // @71_449d80
  L449e5e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @73_449d80
  if ((ecx & ecx) == 0) goto L449e6b;  // @74_449d80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_449d80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @76_449d80
  ecx = edx = 0;  // @77_449d80
  L449e6b:;
  ecx = edi;  // @79_449d80
  eax = ext_45c3e0_thiscall1(ecx);  // @80_449d80
  ecx = edx = 0;  // @81_449d80
  SEH_LEAVE();  // @82_449d80
  return eax;  // @83_449d80
}
PCREG(449d80, lifted_449d80);

extern "C" u32 THISCALL lifted_6168f0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e688);  // @h_6168f0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_6168f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6168f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6168f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_6168f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_6168f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @5_6168f0
  { u32 v = (u32)((u32)(7068748)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_6168f0
  ecx = (u32)(esi + 12);  // @7_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @8_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @9_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @10_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @11_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @12_6168f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @13_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_6168f0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 47536), sizeof v); (u32)v; });  // @15_6168f0
  reg.state = (s32)((u32)(0));  // @16_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @17_6168f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @18_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @19_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @20_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @21_6168f0
  eax = (eax + ebx);  // @22_6168f0
  PV[1] = (u32)(eax);  // @23_6168f0
  eax = ext_659220_thiscall3(ecx, PV[1], PV[0]);  // @24_6168f0
  ecx = edx = 0;  // @25_6168f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L616a1f;  // @26_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 47524), sizeof v); (u32)v; });  // @27_6168f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5130), sizeof v); (u32)v; });  // @28_6168f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L6169b0;  // @29_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_6168f0
  ecx = edi;  // @31_6168f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @32_6168f0
  ecx = edx = 0;  // @33_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @34_6168f0
  L6169b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @36_6168f0
  edi = (u32)(ebx + 2);  // @37_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @38_6168f0
  ebx = 0;  // @39_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @40_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @41_6168f0
  edi = (edi + eax);  // @42_6168f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L616a1f;  // @43_6168f0
  L6169d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @45_6168f0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_6168f0
  edi = (edi + (u32)(2));  // @47_6168f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @48_6168f0
  edx = (u32)(eax + ebx*8);  // @49_6168f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @50_6168f0
  if ((s32)(eax & eax) >= 0) goto L616a16;  // @51_6168f0
  eax = (eax & (u32)(2147483647));  // @52_6168f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @53_6168f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @54_6168f0
  eax = (u32)(edx + eax*2);  // @55_6168f0
  if ((ecx & ecx) == 0) goto L616a16;  // @56_6168f0
  esi = edi;  // @57_6168f0
  edx = ecx;  // @58_6168f0
  esi = (esi - eax);  // @59_6168f0
  L616a00:;
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; })) & 0xffff);  // @61_6168f0
  eax = (u32)(eax + 2);  // @62_6168f0
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax - 2), &v, sizeof v); }  // @63_6168f0
  edx = (edx - (u32)(1));  // @64_6168f0
  if (edx != 0) goto L616a00;  // @65_6168f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @66_6168f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @67_6168f0
  L616a16:;
  ebx = (ebx + 1);  // @69_6168f0
  edi = (u32)(edi + ecx*2);  // @70_6168f0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L6169d0;  // @71_6168f0
  L616a1f:;
  eax = esi;  // @73_6168f0
  SEH_LEAVE();  // @74_6168f0
  return eax;  // @75_6168f0
}
PCREG(6168f0, lifted_6168f0);







