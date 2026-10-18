// batch244015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_636020_thiscall9(u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_636020");
extern "C" u32 THISCALL ext_6363a0_thiscall1(u32) __asm__("ext_6363a0");
extern "C" u32 THISCALL ext_639d00_thiscall2(u32, u32) __asm__("ext_639d00");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_607a20(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e06b);  // @h_607a20
  u8 F[0x40190] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x40090);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x40090 + 8, &a0, 4);
  __builtin_memcpy(F + 0x40090 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @0_607a20
  ecx = esi;  // @1_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 262220), &v, sizeof v); }  // @3_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 262216), &v, sizeof v); }  // @5_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_607a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @7_607a20
  ecx = edx = 0;  // @8_607a20
  edi = eax;  // @9_607a20
  { u32 v = (u32)((u32)(4278255360)); __builtin_memcpy((void *)(u32)(EBP - 262212), &v, sizeof v); }  // @10_607a20
  ebx = 0;  // @11_607a20
  FL[3] = ebx;  // @12_607a20
  edx = (u32)(EBP - 262160);  // @13_607a20
  L607a82:;
  ecx = 0;  // @15_607a20
  FL[3] = ecx;  // @16_607a20
  L607a84:;
  eax = (eax & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @18_607a20
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) ^ (ecx & 0xff))) & 0xff);  // @19_607a20
  FL[3] = (eax & 0xff);  // @20_607a20
  FL[2] = ((eax & 0xff) & (u32)(1));  // @21_607a20
  eax = (u32)(4294901760);  // @22_607a20
  if (FL[2] != 0) eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262212), sizeof v); (u32)v; });  // @23_607a20
  ecx = (ecx + 1);  // @24_607a20
  FL[3] = ecx;  // @25_607a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @26_607a20
  edx = (edx + (u32)(4));  // @27_607a20
  FL[3] = edx;  // @28_607a20
  FL[0] = ecx; FL[1] = (u32)(256);  // @29_607a20
  if (FL[0] < FL[1]) goto L607a84;  // @30_607a20
  ebx = (ebx + 1);  // @31_607a20
  FL[3] = ebx;  // @32_607a20
  FL[0] = ebx; FL[1] = (u32)(256);  // @33_607a20
  if (FL[0] < FL[1]) goto L607a82;  // @34_607a20
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262216), sizeof v); (u32)v; });  // @35_607a20
  eax = (u32)(EBP - 262160);  // @36_607a20
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 262220), sizeof v); (u32)v; });  // @37_607a20
  ecx = (u32)(EBP - 262208);  // @38_607a20
  PV[2] = (u32)(eax);  // @39_607a20
  eax = ext_636020_thiscall9(ecx, PV[2], PV[1], PV[0], (u32)(16711680), (u32)(65280), (u32)(255), (u32)(4278190080), (u32)(0));  // @40_607a20
  ecx = edx = 0;  // @41_607a20
  ecx = (u32)(EBP - 262208);  // @42_607a20
  reg.state = (s32)((u32)(0));  // @43_607a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 262180), &v, sizeof v); }  // @44_607a20
  eax = ext_639d00_thiscall2(ecx, (u32)(7053240));  // @45_607a20
  ecx = edx = 0;  // @46_607a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_607a20
  ecx = esi;  // @48_607a20
  PV[3] = (u32)(edi);  // @49_607a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[3], (u32)(0));  // @50_607a20
  ecx = edx = 0;  // @51_607a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_607a20
  ecx = esi;  // @53_607a20
  PV[4] = (u32)(eax);  // @54_607a20
  eax = (u32)(EBP - 262208);  // @55_607a20
  PV[5] = (u32)(eax);  // @56_607a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[5], PV[4]);  // @57_607a20
  ecx = edx = 0;  // @58_607a20
  ecx = (u32)(EBP - 262208);  // @59_607a20
  eax = ext_6363a0_thiscall1(ecx);  // @60_607a20
  ecx = edx = 0;  // @61_607a20
  eax = edi;  // @62_607a20
  SEH_LEAVE();  // @63_607a20
  ext_633654(G(u32, 0x6f5630));  // @64_607a20
  return eax;  // @65_607a20
}
PCREG(607a20, lifted_607a20);

extern "C" u32 THISCALL lifted_537cc0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_537cc0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_537cc0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20666), sizeof v); (u32)v; })) & 0xff);  // @1_537cc0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_537cc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @3_537cc0
  if (FL[2] == 0) goto L537dd5;  // @4_537cc0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_537cc0
  FL[0] = edi; FL[1] = (u32)(-1);  // @6_537cc0
  if (FL[0] != FL[1]) goto L537d10;  // @7_537cc0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @8_537cc0
  FL[3] = (eax & 0xff);  // @9_537cc0
  goto L537dd7;  // @10_537cc0
  L537d10:;
  ecx = (u32)(EBP - 144);  // @12_537cc0
  eax = ext_4cbeb0_thiscall1(ecx);  // @13_537cc0
    // @14_537cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @15_537cc0
  edx = (u32)(EBP - 272);  // @16_537cc0
  PV[0] = (u32)(ebx);  // @17_537cc0
  PV[1] = (u32)(edx);  // @18_537cc0
  reg.state = (s32)((u32)(0));  // @19_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_537cc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 208)))(ecx, PV[1], PV[0]);  // @21_537cc0
  ecx = edx = 0;  // @22_537cc0
  PV[2] = (u32)(eax);  // @23_537cc0
  ecx = (u32)(EBP - 144);  // @24_537cc0
  reg.state = (s32)((u32)(1));  // @25_537cc0
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @26_537cc0
  ecx = edx = 0;  // @27_537cc0
  ecx = (u32)(EBP - 272);  // @28_537cc0
  reg.state = (s32)((u32)(0));  // @29_537cc0
  eax = ext_4cbec0_thiscall1(ecx);  // @30_537cc0
  ecx = edx = 0;  // @31_537cc0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @32_537cc0
  ecx = (u32)(EBP - 144);  // @33_537cc0
  { u32 v = (u32)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @34_537cc0
  { u32 v = (u32)((u32)(140)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @35_537cc0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @36_537cc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @37_537cc0
    // @38_537cc0
  edx = (u32)(ebx + 12);  // @39_537cc0
  edx = (edx - eax);  // @40_537cc0
  FL[3] = edx;  // @41_537cc0
  L537d80:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @43_537cc0
  eax = (u32)(eax + 1);  // @44_537cc0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @45_537cc0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @46_537cc0
  if (FL[2] != 0) goto L537d80;  // @47_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @48_537cc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @49_537cc0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @50_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @51_537cc0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @52_537cc0
  { u32 v = (u32)((u32)(65536)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @53_537cc0
  L537db0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_537cc0
  ecx = esi;  // @56_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 412), sizeof v); (u32)v; });  // @57_537cc0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @58_537cc0
  ecx = edx = 0;  // @59_537cc0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @60_537cc0
  if (FL[2] == 0) goto L537db0;  // @61_537cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @62_537cc0
  ecx = esi;  // @63_537cc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 356)))(ecx);  // @64_537cc0
  ecx = edx = 0;  // @65_537cc0
  ecx = (u32)(EBP - 144);  // @66_537cc0
  eax = ext_4cbec0_thiscall1(ecx);  // @67_537cc0
  ecx = edx = 0;  // @68_537cc0
  L537dd5:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_537cc0
  L537dd7:;
  SEH_LEAVE();  // @72_537cc0
  ext_633654(G(u32, 0x6f5630));  // @73_537cc0
  return eax;  // @74_537cc0
}
PCREG(537cc0, lifted_537cc0);

extern "C" u32 THISCALL lifted_420ce0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_420ce0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 6811), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_420ce0
  if (FL[0] == FL[1]) goto L420ddd;  // @2_420ce0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2519), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @3_420ce0
  if (FL[0] == FL[1]) goto L420ddd;  // @4_420ce0
  eax = ext_41e290_cdecl1((u32)(8));  // @5_420ce0
  ecx = edx = 0;  // @6_420ce0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_420ce0
  esi = eax;  // @8_420ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @9_420ce0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @10_420ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_420ce0
  FL[0] = edi; FL[1] = (u32)(7);  // @12_420ce0
  if (FL[0] == FL[1]) goto L420d63;  // @13_420ce0
  FL[0] = edi; FL[1] = (u32)(9);  // @14_420ce0
  if (FL[0] == FL[1]) goto L420d63;  // @15_420ce0
  FL[0] = edi; FL[1] = (u32)(8);  // @16_420ce0
  if (FL[0] == FL[1]) goto L420d63;  // @17_420ce0
  FL[0] = edi; FL[1] = (u32)(4);  // @18_420ce0
  if (FL[0] == FL[1]) goto L420d63;  // @19_420ce0
  FL[0] = edi; FL[1] = (u32)(5);  // @20_420ce0
  if (FL[0] == FL[1]) goto L420d63;  // @21_420ce0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_420ce0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @23_420ce0
  if (FL[0] == FL[1]) goto L420d69;  // @24_420ce0
  PV[0] = (u32)(eax);  // @25_420ce0
  eax = ext_41e290_cdecl1(PV[0]);  // @26_420ce0
  ecx = edx = 0;  // @27_420ce0
  esi = eax;  // @28_420ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @29_420ce0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_420ce0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_420ce0
  PV[3] = (u32)(esi);  // @32_420ce0
  eax = ext_634d22_cdecl3(PV[3], PV[2], PV[1]);  // @33_420ce0
    // @34_420ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @35_420ce0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @36_420ce0
  esi = eax;  // @37_420ce0
  goto L420d69;  // @38_420ce0
  L420d63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @40_420ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @41_420ce0
  L420d69:;
  eax = (u32)(edi - 1);  // @43_420ce0
  FL[0] = eax; FL[1] = (u32)(9);  // @44_420ce0
  if (FL[0] > FL[1]) goto L420d9b;  // @45_420ce0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4328940), sizeof v); (u32)v; });  // @46_420ce0
  switch (eax) {  // @47_420ce0
  case 0: goto L420d7f;  // @48_420ce0
  case 1: goto L420d9b;  // @49_420ce0
  default: __builtin_trap(); }  // @50_420ce0
  L420d7f:;
  PV[4] = (u32)(esi);  // @52_420ce0
  PV[5] = (u32)(edi);  // @53_420ce0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2519), sizeof v); (u32)v; });  // @54_420ce0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x67621c))(PV[6], (u32)(12345), PV[5], PV[4]);  // @55_420ce0
  ecx = edx = 0;  // @56_420ce0
  return eax;  // @57_420ce0
  L420d9b:;
  PV[7] = (u32)(esi);  // @59_420ce0
  PV[8] = (u32)(edi);  // @60_420ce0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2519), sizeof v); (u32)v; });  // @61_420ce0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6761d4))(PV[9], (u32)(12345), PV[8], PV[7]);  // @62_420ce0
  ecx = edx = 0;  // @63_420ce0
  FL[2] = (eax & eax);  // @64_420ce0
  if (FL[2] != 0) goto L420ddb;  // @65_420ce0
  L420db2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @67_420ce0
  PV[10] = (u32)(ecx);  // @68_420ce0
  ecx = ebx;  // @69_420ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 372)))(ecx, (u32)(1120403456));  // @70_420ce0
  ecx = edx = 0;  // @71_420ce0
  PV[11] = (u32)(esi);  // @72_420ce0
  PV[12] = (u32)(edi);  // @73_420ce0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2519), sizeof v); (u32)v; });  // @74_420ce0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(*(u32 *)0x6761d4))(PV[13], (u32)(12345), PV[12], PV[11]);  // @75_420ce0
  ecx = edx = 0;  // @76_420ce0
  FL[2] = (eax & eax);  // @77_420ce0
  if (FL[2] == 0) goto L420db2;  // @78_420ce0
  L420ddb:;
  L420ddd:;
  return eax;  // @81_420ce0
}
PCREG(420ce0, lifted_420ce0);


// ---- hand port (lifter: sbb/adc 64-bit arithmetic). GUESS name.
extern "C" u32 ext_41e290_c1(...) __asm__("ext_41e290");
typedef u64(THISCALL *w4c_u64_t)(void *, u32, u32);
typedef u32(THISCALL *w4c_vr_t)(void *, u32, u32);

// 0x661210: thiscall(lo, hi, text) ret 0xc: timer record update. Already reported ([this+0x20]) returns. No current record ([this+0x10] == 0): report via [0x700390] and set [this+0x20].
// text non-null and strncmp(text, rec+0x1b8, 0x13) != 0: report and set [this+0x20]. Otherwise add (lo,hi) - [rec+0x10] to the 64-bit fields rec+0 and rec+8, count++ at rec+0x1d5, [this+0x1c]--,
// [this+0x10] = [rec+0x1cc], then adds (engine time() - (lo,hi)) (64-bit via slot 0x1c8(0x6c4928, 0x7a)) to the 64-bit field at rec+0x20.
static u32 THISCALL fn661210(u8 *self, u32 lo, u32 hi, u32 text) {
  if (self[0x20]) return 0;
  u8 *rec = *(u8 **)(self + 0x10);
  if (!rec) {
    u8 *e = *(u8 **)0x700390;
    u8 *o = (u8 *)(*(w4c_vr_t **)e)[0x20 / 4](e, 0x6c4928, 0x6b);
    typedef u32(*cd3_t)(void *, u32, u32);
    u32 r = (*(cd3_t **)o)[0x2c / 4](o, 0x6c4950, text);
    self[0x20] = 1;
    return r;
  }
  if (text) {
    u32 d = ((u32(*)(u32, u32, u32))G(u32, 0x676410))(text, (u32)(rec + 0x1b8), 0x13);
    if (d) {
      u8 *e = *(u8 **)0x700390;
      u8 *o = (u8 *)(*(w4c_vr_t **)e)[0x20 / 4](e, 0x6c4928, 0x70);
      typedef u32(*cd3_t)(void *, u32, u32);
      u32 r = (*(cd3_t **)o)[0x2c / 4](o, 0x6c4970, (u32)(rec + 0x1b8));
      self[0x20] = 1;
      return r;
    }
  }
  u64 in = ((u64)hi << 32) | lo;
  u64 d = in - *(u64 *)(rec + 0x10);
  *(u64 *)rec += d;
  *(u64 *)(rec + 8) += d;
  (*(u32 *)(rec + 0x1d5))++;
  u32 nxt = *(u32 *)(rec + 0x1cc);
  (*(u32 *)(self + 0x1c))--;
  *(u32 *)(self + 0x10) = nxt;
  u8 *eng = *(u8 **)0x70039c;
  u64 now = (*(w4c_u64_t **)eng)[0x1c8 / 4](eng, 0x6c4928, 0x7a);
  *(u64 *)(rec + 0x20) += now - in;
  return (u32)(now - in);
}
PCREG(661210, fn661210);
