// batch242030.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_41d220_thiscall1(u32) __asm__("ext_41d220");
extern "C" u32 THISCALL ext_41d540_thiscall1(u32) __asm__("ext_41d540");
extern "C" u32 ext_41dd90_cdecl0(void) __asm__("ext_41dd90");
extern "C" u32 ext_41e010_cdecl1(...) __asm__("ext_41e010");
extern "C" u32 ext_41e010_cdecl2(...) __asm__("ext_41e010");
extern "C" u32 ext_41e010_cdecl3(...) __asm__("ext_41e010");
extern "C" u32 ext_41e010_cdecl6(...) __asm__("ext_41e010");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 FASTCALL lifted_41dc60(u32 ecx_in, u32 edx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = edx;  // @0_41dc60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @1_41dc60
  eax = ext_41e010_cdecl1((u32)(6779156));  // @2_41dc60
    // @3_41dc60
  eax = ext_41dd90_cdecl0();  // @4_41dc60
  ecx = edx = 0;  // @5_41dc60
  eax = (u32)(EBP - 168);  // @6_41dc60
  PV[0] = (u32)(eax);  // @7_41dc60
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(164));  // @8_41dc60
    // @9_41dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 184), sizeof v); (u32)v; });  // @10_41dc60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @11_41dc60
  edi = 0;  // @12_41dc60
  FL[3] = edi;  // @13_41dc60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @14_41dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 180), sizeof v); (u32)v; });  // @15_41dc60
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @16_41dc60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 144), &v, sizeof v); }  // @17_41dc60
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 136), &v, sizeof v); }  // @18_41dc60
  FL[2] = (esi & esi);  // @19_41dc60
  if (FL[2] == 0) goto L41dd3e;  // @20_41dc60
  L41dce0:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327072), sizeof v); (u32)v; });  // @22_41dc60
  eax = (u32)(EBP - 168);  // @23_41dc60
  esi = (esi - 1);  // @24_41dc60
  FL[3] = esi;  // @25_41dc60
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327064), sizeof v); (u32)v; });  // @26_41dc60
  PV[3] = (u32)(ebx);  // @27_41dc60
  PV[4] = (u32)(eax);  // @28_41dc60
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @29_41dc60
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327104), sizeof v); (u32)v; });  // @30_41dc60
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)0x6fcd50))((u32)(332), PV[6], PV[5], PV[4], PV[3], (u32)(0), PV[2], PV[1], (u32)(0));  // @31_41dc60
  ecx = edx = 0;  // @32_41dc60
  FL[2] = (eax & eax);  // @33_41dc60
  if (FL[2] == 0) goto L41dd3e;  // @34_41dc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @35_41dc60
  eax = ext_41d540_thiscall1(ecx);  // @36_41dc60
  ecx = edx = 0;  // @37_41dc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @38_41dc60
  FL[0] = edi; FL[1] = eax;  // @39_41dc60
  if (FL[0] == FL[1]) goto L41dd31;  // @40_41dc60
  edi = eax;  // @41_41dc60
  FL[2] = (esi & esi);  // @42_41dc60
  if (FL[2] != 0) goto L41dce0;  // @43_41dc60
  goto L41dd3e;  // @44_41dc60
  L41dd31:;
  eax = ext_41e010_cdecl1((u32)(6779220));  // @46_41dc60
    // @47_41dc60
  L41dd3e:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327100), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(7327100), &v, sizeof v); }  // @49_41dc60
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7327100), sizeof v); (u32)v; });  // @50_41dc60
  if (FL[3] != 0) goto L41dd57;  // @51_41dc60
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x6760ac))();  // @52_41dc60
  ecx = edx = 0;  // @53_41dc60
  PV[7] = (u32)(eax);  // @54_41dc60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6fcd54))(PV[7]);  // @55_41dc60
  ecx = edx = 0;  // @56_41dc60
  L41dd57:;
  ext_633654(G(u32, 0x6f5630));  // @58_41dc60
  eax = (u32)(1);  // @59_41dc60
  return eax;  // @60_41dc60
}
PCREG(41dc60, lifted_41dc60);

extern "C" u32 FASTCALL lifted_41d0c0(u32 ecx_in, u32 edx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_41d0c0
  edi = ecx;  // @1_41d0c0
  FL[2] = (edx & edx);  // @2_41d0c0
  if (FL[2] == 0) goto L41d0ee;  // @3_41d0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_41d0c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7327096), &v, sizeof v); }  // @5_41d0c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7328160), &v, sizeof v); }  // @6_41d0c0
  goto L41d107;  // @7_41d0c0
  L41d0ee:;
  { u32 v = (u32)((u32)(4317472)); __builtin_memcpy((void *)(u32)(7327096), &v, sizeof v); }  // @9_41d0c0
  esi = (u32)(4317456);  // @10_41d0c0
  { u32 v = (u32)((u32)(4317312)); __builtin_memcpy((void *)(u32)(7328160), &v, sizeof v); }  // @11_41d0c0
  L41d107:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7327108), &v, sizeof v); }  // @13_41d0c0
  FL[2] = (esi & esi);  // @14_41d0c0
  if (FL[2] == 0) goto L41d113;  // @15_41d0c0
  eax = ((u32(STDCALL *)(void))(esi))();  // @16_41d0c0
  ecx = edx = 0;  // @17_41d0c0
  L41d113:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676080))();  // @19_41d0c0
  ecx = edx = 0;  // @20_41d0c0
  PV[0] = (u32)(eax);  // @21_41d0c0
  eax = ext_41e010_cdecl2((u32)(6778812), PV[0]);  // @22_41d0c0
    // @23_41d0c0
  eax = (u32)(EBP - 516);  // @24_41d0c0
  PV[1] = (u32)(eax);  // @25_41d0c0
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67607c))((u32)(0), PV[1], (u32)(512));  // @26_41d0c0
  ecx = edx = 0;  // @27_41d0c0
  eax = (u32)(EBP - 516);  // @28_41d0c0
  PV[2] = (u32)(eax);  // @29_41d0c0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)0x676068))(PV[2], (u32)(2147483648), (u32)(1), (u32)(0), (u32)(3), (u32)(128), (u32)(0));  // @30_41d0c0
  ecx = edx = 0;  // @31_41d0c0
  esi = eax;  // @32_41d0c0
  FL[0] = esi; FL[1] = (u32)(-1);  // @33_41d0c0
  if (FL[0] == FL[1]) goto L41d1c3;  // @34_41d0c0
  eax = (u32)(EBP - 540);  // @35_41d0c0
  PV[3] = (u32)(eax);  // @36_41d0c0
  PV[4] = (u32)(esi);  // @37_41d0c0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x676090))(PV[4], (u32)(0), (u32)(0), PV[3]);  // @38_41d0c0
  ecx = edx = 0;  // @39_41d0c0
  eax = (u32)(EBP - 532);  // @40_41d0c0
  PV[5] = (u32)(eax);  // @41_41d0c0
  eax = (u32)(EBP - 540);  // @42_41d0c0
  PV[6] = (u32)(eax);  // @43_41d0c0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760bc))(PV[6], PV[5]);  // @44_41d0c0
  ecx = edx = 0;  // @45_41d0c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 522), sizeof v); (u32)v; });  // @46_41d0c0
  PV[7] = (u32)(eax);  // @47_41d0c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 524), sizeof v); (u32)v; });  // @48_41d0c0
  PV[8] = (u32)(eax);  // @49_41d0c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 526), sizeof v); (u32)v; });  // @50_41d0c0
  PV[9] = (u32)(eax);  // @51_41d0c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 530), sizeof v); (u32)v; });  // @52_41d0c0
  PV[10] = (u32)(eax);  // @53_41d0c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @54_41d0c0
  PV[11] = (u32)(eax);  // @55_41d0c0
  eax = ext_41e010_cdecl6((u32)(6778836), PV[11], PV[10], PV[9], PV[8], PV[7]);  // @56_41d0c0
    // @57_41d0c0
  PV[12] = (u32)(esi);  // @58_41d0c0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676070))(PV[12]);  // @59_41d0c0
  ecx = edx = 0;  // @60_41d0c0
  L41d1c3:;
  eax = ext_41e010_cdecl1((u32)(6778884));  // @62_41d0c0
    // @63_41d0c0
  FL[2] = (edi & edi);  // @64_41d0c0
  if (FL[2] == 0) goto L41d1ee;  // @65_41d0c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_41d0c0
  eax = ext_41d220_thiscall1(ecx);  // @67_41d0c0
  ecx = edx = 0;  // @68_41d0c0
  PV[13] = (u32)(eax);  // @69_41d0c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_41d0c0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @71_41d0c0
  eax = ext_41e010_cdecl3((u32)(6778948), PV[14], PV[13]);  // @72_41d0c0
    // @73_41d0c0
  L41d1ee:;
  ext_633654(G(u32, 0x6f5630));  // @75_41d0c0
  return eax;  // @76_41d0c0
}
PCREG(41d0c0, lifted_41d0c0);

