// batch244009.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_41f190_thiscall1(u32, u32) __asm__("ext_41f190");
extern "C" u32 THISCALL ext_420a60_thiscall1(u32) __asm__("ext_420a60");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cd160_thiscall1(u32) __asm__("ext_4cd160");
extern "C" u32 THISCALL ext_54cb50_thiscall1(u32) __asm__("ext_54cb50");
extern "C" u32 THISCALL ext_648280_thiscall1(u32) __asm__("ext_648280");
extern "C" u32 THISCALL ext_64b070_thiscall1(u32) __asm__("ext_64b070");
extern "C" u32 THISCALL ext_65e130_thiscall1(u32) __asm__("ext_65e130");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_41f9b0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ecx;  // @0_41f9b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_41f9b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @2_41f9b0
  ecx = edx = 0;  // @3_41f9b0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_41f9b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_41f9b0
  PV[0] = (u32)(esi);  // @6_41f9b0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[0], (u32)(92));  // @7_41f9b0
  ecx = edx = 0;  // @8_41f9b0
  FL[2] = (eax & eax);  // @9_41f9b0
  ecx = (u32)(eax + 1);  // @10_41f9b0
  if (FL[2] != 0) esi = ecx;  // @11_41f9b0
  ecx = esi;  // @12_41f9b0
  edx = (u32)(ecx + 1);  // @13_41f9b0
  L41f9e0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @15_41f9b0
  ecx = (ecx + 1);  // @16_41f9b0
  FL[3] = ecx;  // @17_41f9b0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @18_41f9b0
  if (FL[2] != 0) goto L41f9e0;  // @19_41f9b0
  ecx = (ecx - edx);  // @20_41f9b0
  FL[3] = ecx;  // @21_41f9b0
  eax = (u32)(ecx + 1);  // @22_41f9b0
  PV[1] = (u32)(eax);  // @23_41f9b0
  eax = ((u32( *)(u32))(*(u32 *)0x6762f0))(PV[1]);  // @24_41f9b0
  ecx = edx = 0;  // @25_41f9b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 24), &v, sizeof v); }  // @26_41f9b0
  L41fa00:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @28_41f9b0
  esi = (u32)(esi + 1);  // @29_41f9b0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @30_41f9b0
  eax = (u32)(eax + 1);  // @31_41f9b0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @32_41f9b0
  if (FL[2] != 0) goto L41fa00;  // @33_41f9b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @34_41f9b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi - 20), &v, sizeof v); }  // @35_41f9b0
  ecx = ebx;  // @36_41f9b0
  PV[2] = (u32)(edi);  // @37_41f9b0
  eax = ext_41f190_thiscall1(ecx, PV[2]);  // @38_41f9b0
  ecx = edx = 0;  // @39_41f9b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @40_41f9b0
  ecx = ebx;  // @41_41f9b0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 232)))(ecx);  // @42_41f9b0
  ecx = edx = 0;  // @43_41f9b0
  eax = edi;  // @44_41f9b0
  return eax;  // @45_41f9b0
}
PCREG(41f9b0, lifted_41f9b0);

extern "C" u32 THISCALL lifted_4f00f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4f00f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1_4f00f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4f00f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @3_4f00f0
  ecx = edx = 0;  // @4_4f00f0
  ecx = (u32)(EBP - 4);  // @5_4f00f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @6_4f00f0
  PV[0] = (u32)(ecx);  // @7_4f00f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_4f00f0
  ecx = eax;  // @9_4f00f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6912776), PV[0]);  // @10_4f00f0
  ecx = edx = 0;  // @11_4f00f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_4f00f0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @13_4f00f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @14_4f00f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4f00f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @16_4f00f0
  ecx = edx = 0;  // @17_4f00f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @18_4f00f0
  edi = eax;  // @19_4f00f0
  if (FL[0] != FL[1]) goto L4f016e;  // @20_4f00f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @21_4f00f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4f00f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6912796), (u32)(522));  // @23_4f00f0
  ecx = edx = 0;  // @24_4f00f0
  PV[2] = (u32)(eax);  // @25_4f00f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @26_4f00f0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6915000));  // @27_4f00f0
  ecx = edx = 0;  // @28_4f00f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @29_4f00f0
  FL[2] = (eax & eax);  // @30_4f00f0
  if (FL[2] == 0) goto L4f016d;  // @31_4f00f0
  eax = ((u32(STDCALL *)(void))(eax))();  // @32_4f00f0
  ecx = edx = 0;  // @33_4f00f0
  goto L4f016e;  // @34_4f00f0
  L4f016d:;
  __builtin_trap();  // @36_4f00f0
  L4f016e:;
  FL[2] = (edi & edi);  // @38_4f00f0
  if (FL[2] != 0) goto L4f0179;  // @39_4f00f0
  eax = 0;  // @40_4f00f0
  FL[3] = eax;  // @41_4f00f0
  return eax;  // @42_4f00f0
  L4f0179:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @44_4f00f0
  return eax;  // @45_4f00f0
}
PCREG(4f00f0, lifted_4f00f0);

extern "C" u32 THISCALL lifted_533520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_533520
  edi = ecx;  // @1_533520
  FL[2] = (ebx & ebx);  // @2_533520
  if (FL[2] != 0) goto L53353d;  // @3_533520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @4_533520
  PV[0] = (u32)(ebx);  // @5_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, PV[0]);  // @6_533520
  ecx = edx = 0;  // @7_533520
  return eax;  // @8_533520
  L53353d:;
  esi = 0;  // @10_533520
  FL[3] = esi;  // @11_533520
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21614), sizeof v); (u32)v; }); FL[1] = esi;  // @12_533520
  if ((s32)FL[0] <= (s32)FL[1]) goto L53356e;  // @13_533520
  L533548:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_533520
  ecx = edi;  // @16_533520
  PV[1] = (u32)(ebx);  // @17_533520
  PV[2] = (u32)(esi);  // @18_533520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 584)))(ecx, PV[2], PV[1]);  // @19_533520
  ecx = edx = 0;  // @20_533520
  eax = (eax + (u32)(4));  // @21_533520
  FL[3] = eax;  // @22_533520
  PV[3] = (u32)(eax);  // @23_533520
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676414))(PV[3]);  // @24_533520
  ecx = edx = 0;  // @25_533520
  FL[2] = (eax & eax);  // @26_533520
  if (FL[2] == 0) goto L533581;  // @27_533520
  esi = (esi + 1);  // @28_533520
  FL[3] = esi;  // @29_533520
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21614), sizeof v); (u32)v; });  // @30_533520
  if ((s32)FL[0] < (s32)FL[1]) goto L533548;  // @31_533520
  L53356e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @33_533520
  ecx = edi;  // @34_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, (u32)(0));  // @35_533520
  ecx = edx = 0;  // @36_533520
  return eax;  // @37_533520
  L533581:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_533520
  ecx = edi;  // @40_533520
  PV[4] = (u32)(esi);  // @41_533520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 584)))(ecx, PV[4]);  // @42_533520
  ecx = edx = 0;  // @43_533520
  return eax;  // @44_533520
}
PCREG(533520, lifted_533520);

extern "C" u32 THISCALL lifted_54b420(u32 ecx_in) {
  SEH_ENTER(0x66acdf);  // @h_54b420
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_54b420
  eax = ext_41e290_cdecl1((u32)(84));  // @1_54b420
  ecx = edx = 0;  // @2_54b420
  esi = eax;  // @3_54b420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_54b420
  reg.state = (s32)((u32)(0));  // @5_54b420
  FL[2] = (esi & esi);  // @6_54b420
  if (FL[2] == 0) goto L54b485;  // @7_54b420
  ecx = esi;  // @8_54b420
  eax = ext_54cb50_thiscall1(ecx);  // @9_54b420
    // @10_54b420
  { u32 v = (u32)((u32)(6961212)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @11_54b420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @12_54b420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @13_54b420
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @14_54b420
  goto L54b487;  // @15_54b420
  L54b485:;
  esi = 0;  // @17_54b420
  FL[3] = esi;  // @18_54b420
  L54b487:;
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41592), sizeof v); (u32)v; });  // @20_54b420
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 32841), &v, sizeof v); }  // @21_54b420
  ecx = esi;  // @22_54b420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_54b420
  reg.state = (s32)((u32)(4294967295));  // @24_54b420
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[0]);  // @25_54b420
  ecx = edx = 0;  // @26_54b420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_54b420
  ecx = esi;  // @28_54b420
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @29_54b420
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @30_54b420
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @31_54b420
  ecx = edx = 0;  // @32_54b420
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @33_54b420
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @34_54b420
  SEH_LEAVE();  // @35_54b420
  return eax;  // @36_54b420
}
PCREG(54b420, lifted_54b420);

extern "C" u32 STDCALL lifted_651ce0(u32 a0) {
  SEH_ENTER(0x66428b);  // @h_651ce0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_651ce0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_651ce0
  PV[0] = (u32)(esi);  // @2_651ce0
  ecx = (u32)(ecx + 7825);  // @3_651ce0
  eax = ext_4cc1d0_thiscall1(ecx);  // @4_651ce0
    // @5_651ce0
  PV[1] = (u32)(eax);  // @6_651ce0
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[1], PV[0]);  // @7_651ce0
  ecx = edx = 0;  // @8_651ce0
  FL[2] = (eax & eax);  // @9_651ce0
  if (FL[2] == 0) goto L651d89;  // @10_651ce0
  PV[2] = (u32)(esi);  // @11_651ce0
  ecx = (u32)(EBP - 144);  // @12_651ce0
  eax = ext_4cbe80_thiscall2(ecx, PV[2]);  // @13_651ce0
  ecx = edx = 0;  // @14_651ce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_651ce0
  eax = (u32)(EBP - 144);  // @16_651ce0
  PV[3] = (u32)(eax);  // @17_651ce0
  reg.state = (s32)((u32)(0));  // @18_651ce0
  ecx = (u32)(ecx + 7825);  // @19_651ce0
  eax = ext_4cbee0_thiscall2(ecx, PV[3]);  // @20_651ce0
  ecx = edx = 0;  // @21_651ce0
  ecx = (u32)(EBP - 144);  // @22_651ce0
  eax = ext_4cbec0_thiscall1(ecx);  // @23_651ce0
  ecx = edx = 0;  // @24_651ce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_651ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 111), sizeof v); (u32)v; });  // @26_651ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 119), &v, sizeof v); }  // @27_651ce0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_651ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 115), sizeof v); (u32)v; });  // @29_651ce0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 123), &v, sizeof v); }  // @30_651ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @31_651ce0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 6807), &v, sizeof v); }  // @32_651ce0
  L651d89:;
  SEH_LEAVE();  // @34_651ce0
  ext_633654(G(u32, 0x6f5630));  // @35_651ce0
  return eax;  // @36_651ce0
}
PCREG(651ce0, lifted_651ce0);

extern "C" u32 THISCALL lifted_63ab30(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_63ab30
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_63ab30
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_63ab30
  edi = 0;  // @2_63ab30
  FL[3] = edi;  // @3_63ab30
  { u32 v = (u32)((u32)(7086900)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_63ab30
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 236), sizeof v); (u32)v; }); FL[1] = edi;  // @5_63ab30
  if (FL[0] == FL[1]) goto L63aba4;  // @6_63ab30
  ebx = (ebx + (u32)(240));  // @7_63ab30
  FL[3] = ebx;  // @8_63ab30
  L63ab71:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_63ab30
  ecx = esi;  // @11_63ab30
  eax = ext_64b070_thiscall1(ecx);  // @12_63ab30
  ecx = edx = 0;  // @13_63ab30
  FL[2] = (esi & esi);  // @14_63ab30
  if (FL[2] == 0) goto L63ab93;  // @15_63ab30
  ecx = esi;  // @16_63ab30
  eax = ext_648280_thiscall1(ecx);  // @17_63ab30
    // @18_63ab30
  PV[0] = (u32)(esi);  // @19_63ab30
  eax = ext_634273_cdecl2(PV[0], (u32)(98977));  // @20_63ab30
  ecx = edx = 0;  // @21_63ab30
  L63ab93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @23_63ab30
  edi = (edi + 1);  // @24_63ab30
  FL[3] = edi;  // @25_63ab30
  ebx = (ebx + (u32)(4));  // @26_63ab30
  FL[3] = ebx;  // @27_63ab30
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 236), sizeof v); (u32)v; });  // @28_63ab30
  if (FL[0] != FL[1]) goto L63ab71;  // @29_63ab30
  ebx = eax;  // @30_63ab30
  L63aba4:;
  ecx = (u32)(ebx + 47504);  // @32_63ab30
  eax = ext_4cd160_thiscall1(ecx);  // @33_63ab30
  ecx = edx = 0;  // @34_63ab30
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47433), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(ebx + 47433), &v, sizeof v); }  // @35_63ab30
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47433), sizeof v); (u32)v; });  // @36_63ab30
  ecx = (u32)(ebx + 33392);  // @37_63ab30
  eax = ext_65e130_thiscall1(ecx);  // @38_63ab30
  ecx = edx = 0;  // @39_63ab30
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(ebx + 25), &v, sizeof v); }  // @40_63ab30
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 25), sizeof v); (u32)v; });  // @41_63ab30
  SEH_LEAVE();  // @42_63ab30
  return eax;  // @43_63ab30
}
PCREG(63ab30, lifted_63ab30);

extern "C" u32 THISCALL lifted_420a60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_420a60
  PV[0] = (u32)(ebx);  // @1_420a60
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6760d8))(PV[0]);  // @2_420a60
  ecx = edx = 0;  // @3_420a60
  FL[0] = eax; FL[1] = (u32)(-1);  // @4_420a60
  if (FL[0] == FL[1]) goto L420a77;  // @5_420a60
  FL[2] = ((eax & 0xff) & (u32)(16));  // @6_420a60
  if (FL[2] != 0) goto L420ad9;  // @7_420a60
  L420a77:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @9_420a60
  PV[1] = (u32)(ebx);  // @10_420a60
  eax = ((u32(STDCALL *)(u32, u32))(esi))(PV[1], (u32)(92));  // @11_420a60
  ecx = edx = 0;  // @12_420a60
  PV[2] = (u32)(ebx);  // @13_420a60
  edi = eax;  // @14_420a60
  eax = ((u32(STDCALL *)(u32, u32))(esi))(PV[2], (u32)(92));  // @15_420a60
  ecx = edx = 0;  // @16_420a60
  eax = (eax - ebx);  // @17_420a60
  FL[3] = eax;  // @18_420a60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @19_420a60
  FL[2] = (edi & edi);  // @20_420a60
  if (FL[2] == 0) goto L420ace;  // @21_420a60
  FL[0] = eax; FL[1] = (u32)(2);  // @22_420a60
  if (FL[0] == FL[1]) goto L420ace;  // @23_420a60
  ecx = (u32)(eax + 1);  // @24_420a60
  PV[3] = (u32)(ecx);  // @25_420a60
  eax = ext_41e290_cdecl1(PV[3]);  // @26_420a60
  ecx = edx = 0;  // @27_420a60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @28_420a60
  esi = eax;  // @29_420a60
  PV[4] = (u32)(edi);  // @30_420a60
  PV[5] = (u32)(ebx);  // @31_420a60
  PV[6] = (u32)(esi);  // @32_420a60
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x67642c))(PV[6], PV[5], PV[4]);  // @33_420a60
  ecx = edx = 0;  // @34_420a60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + edi), &v, sizeof v); }  // @35_420a60
  FL[2] = (esi & esi);  // @36_420a60
  if (FL[2] == 0) goto L420ace;  // @37_420a60
  ecx = esi;  // @38_420a60
  eax = ext_420a60_thiscall1(ecx);  // @39_420a60
  ecx = edx = 0;  // @40_420a60
  PV[7] = (u32)(esi);  // @41_420a60
  eax = ext_41e2c0_cdecl1(PV[7]);  // @42_420a60
  ecx = edx = 0;  // @43_420a60
  L420ace:;
  PV[8] = (u32)(ebx);  // @45_420a60
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x6760d4))(PV[8], (u32)(0));  // @46_420a60
  ecx = edx = 0;  // @47_420a60
  L420ad9:;
  return eax;  // @49_420a60
}
PCREG(420a60, lifted_420a60);

