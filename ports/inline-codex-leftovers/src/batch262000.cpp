// batch262000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_499980_thiscall1(u32) __asm__("ext_499980");
extern "C" u32 THISCALL ext_4999c0_thiscall2(u32, u32) __asm__("ext_4999c0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cdd40_thiscall1(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 THISCALL ext_4febf0_thiscall2(u32, u32) __asm__("ext_4febf0");
extern "C" u32 THISCALL ext_542110_thiscall1(u32) __asm__("ext_542110");
extern "C" u32 THISCALL ext_545260_thiscall1(u32) __asm__("ext_545260");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4c8fe0_cdecl0(void) __asm__("ext_4c8fe0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c90a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_4c90a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4c90a0
  ecx = (u32)(EBP - 144);  // @2_4c90a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4c90a0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @4_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, PV[0]);  // @5_4c90a0
  ecx = edx = 0;  // @6_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4c90a0
  reg.state = (s32)((u32)(0));  // @8_4c90a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @9_4c90a0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @10_4c90a0
  if (FL[0] == FL[1]) goto L4c9131;  // @11_4c90a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @12_4c90a0
  FL[3] = (eax & 0xff);  // @13_4c90a0
  FL[0] = (eax & 0xff); FL[1] = (u32)(4);  // @14_4c90a0
  if (FL[0] != FL[1]) goto L4c9131;  // @15_4c90a0
  ecx = esi;  // @16_4c90a0
  eax = ext_4e5ea0_thiscall1(ecx);  // @17_4c90a0
  ecx = edx = 0;  // @18_4c90a0
  PV[1] = (u32)(eax);  // @19_4c90a0
  ecx = (u32)(EBP - 272);  // @20_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, PV[1]);  // @21_4c90a0
  ecx = edx = 0;  // @22_4c90a0
  eax = (u32)(EBP - 272);  // @23_4c90a0
  reg.state = (s32)((u32)(1));  // @24_4c90a0
  PV[2] = (u32)(eax);  // @25_4c90a0
  ecx = (u32)(EBP - 144);  // @26_4c90a0
  eax = ext_4cbee0_thiscall2(ecx, PV[2]);  // @27_4c90a0
  ecx = edx = 0;  // @28_4c90a0
  ecx = (u32)(EBP - 272);  // @29_4c90a0
  reg.state = (s32)((u32)(0));  // @30_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @31_4c90a0
  ecx = edx = 0;  // @32_4c90a0
  L4c9131:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @37_4c90a0
  ecx = edx = 0;  // @38_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_4c90a0
  esi = eax;  // @40_4c90a0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @41_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @42_4c90a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @43_4c90a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_4c90a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[3], (u32)(2));  // @45_4c90a0
  ecx = edx = 0;  // @46_4c90a0
  PV[4] = (u32)(eax);  // @47_4c90a0
  ecx = (u32)(EBP - 144);  // @48_4c90a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @49_4c90a0
    // @50_4c90a0
  PV[5] = (u32)(eax);  // @51_4c90a0
  ecx = esi;  // @52_4c90a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, PV[5], PV[4]);  // @53_4c90a0
  ecx = edx = 0;  // @54_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @55_4c90a0
  ecx = ebx;  // @56_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @57_4c90a0
  ecx = edx = 0;  // @58_4c90a0
  ecx = (u32)(EBP - 144);  // @59_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @60_4c90a0
  ecx = edx = 0;  // @61_4c90a0
  SEH_LEAVE();  // @62_4c90a0
  ext_633654(G(u32, 0x6f5630));  // @63_4c90a0
  return eax;  // @64_4c90a0
}
PCREG(4c90a0, lifted_4c90a0);

extern "C" u32 THISCALL lifted_4fe8a0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b8b);  // @h_4fe8a0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4fe8a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4fe8a0
  eax = (u32)(edi + 72);  // @2_4fe8a0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4fe8a0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @4_4fe8a0
  ecx = esi;  // @5_4fe8a0
  PV[0] = (u32)(eax);  // @6_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @7_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[0], (u32)(1));  // @8_4fe8a0
  ecx = edx = 0;  // @9_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_4fe8a0
  eax = (u32)(edi + 95);  // @11_4fe8a0
  PV[1] = (u32)(eax);  // @12_4fe8a0
  ecx = esi;  // @13_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[1], (u32)(4));  // @14_4fe8a0
  ecx = edx = 0;  // @15_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_4fe8a0
  eax = (u32)(edi + 99);  // @17_4fe8a0
  PV[2] = (u32)(eax);  // @18_4fe8a0
  ecx = esi;  // @19_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[2], (u32)(4));  // @20_4fe8a0
  ecx = edx = 0;  // @21_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_4fe8a0
  eax = (u32)(edi + 103);  // @23_4fe8a0
  PV[3] = (u32)(eax);  // @24_4fe8a0
  ecx = esi;  // @25_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[3], (u32)(1));  // @26_4fe8a0
  ecx = edx = 0;  // @27_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @28_4fe8a0
  eax = (u32)(edi + 104);  // @29_4fe8a0
  PV[4] = (u32)(eax);  // @30_4fe8a0
  ecx = esi;  // @31_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[4], (u32)(4));  // @32_4fe8a0
  ecx = edx = 0;  // @33_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_4fe8a0
  eax = (u32)(edi + 108);  // @35_4fe8a0
  PV[5] = (u32)(eax);  // @36_4fe8a0
  ecx = esi;  // @37_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[5], (u32)(4));  // @38_4fe8a0
  ecx = edx = 0;  // @39_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_4fe8a0
  eax = (u32)(edi + 112);  // @41_4fe8a0
  PV[6] = (u32)(eax);  // @42_4fe8a0
  ecx = esi;  // @43_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[6], (u32)(4));  // @44_4fe8a0
  ecx = edx = 0;  // @45_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @46_4fe8a0
  eax = (u32)(edi + 228);  // @47_4fe8a0
  PV[7] = (u32)(eax);  // @48_4fe8a0
  ecx = esi;  // @49_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[7], (u32)(4));  // @50_4fe8a0
  ecx = edx = 0;  // @51_4fe8a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_4fe8a0
  eax = (u32)(edi + 232);  // @53_4fe8a0
  PV[8] = (u32)(eax);  // @54_4fe8a0
  ecx = esi;  // @55_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, PV[8], (u32)(4));  // @56_4fe8a0
  ecx = edx = 0;  // @57_4fe8a0
  PV[9] = (u32)(esi);  // @58_4fe8a0
  ecx = (u32)(EBP - 332);  // @59_4fe8a0
  eax = ext_4febf0_thiscall2(ecx, PV[9]);  // @60_4fe8a0
  ecx = edx = 0;  // @61_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 73), sizeof v); (u32)v; });  // @62_4fe8a0
  ecx = (u32)(EBP - 332);  // @63_4fe8a0
  PV[10] = (u32)(eax);  // @64_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @65_4fe8a0
  reg.state = (s32)((u32)(0));  // @66_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[10]);  // @67_4fe8a0
  ecx = edx = 0;  // @68_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 75), sizeof v); (u32)v; });  // @69_4fe8a0
  ecx = (u32)(EBP - 332);  // @70_4fe8a0
  PV[11] = (u32)(eax);  // @71_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @72_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[11]);  // @73_4fe8a0
  ecx = edx = 0;  // @74_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 77), sizeof v); (u32)v; });  // @75_4fe8a0
  ecx = (u32)(EBP - 332);  // @76_4fe8a0
  PV[12] = (u32)(eax);  // @77_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @78_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[12]);  // @79_4fe8a0
  ecx = edx = 0;  // @80_4fe8a0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 79), sizeof v); (u32)v; });  // @81_4fe8a0
  ecx = (u32)(EBP - 332);  // @82_4fe8a0
  PV[13] = (u32)(eax);  // @83_4fe8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @84_4fe8a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, PV[13]);  // @85_4fe8a0
  ecx = edx = 0;  // @86_4fe8a0
  ecx = (u32)(EBP - 332);  // @87_4fe8a0
  eax = ext_499980_thiscall1(ecx);  // @88_4fe8a0
  ecx = edx = 0;  // @89_4fe8a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @90_4fe8a0
  SEH_LEAVE();  // @91_4fe8a0
  ext_633654(G(u32, 0x6f5630));  // @92_4fe8a0
  return eax;  // @93_4fe8a0
}
PCREG(4fe8a0, lifted_4fe8a0);

extern "C" u32 THISCALL lifted_4c8e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669176);  // @h_4c8e20
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4c8e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4c8e20
  ecx = (u32)(EBP - 360);  // @2_4c8e20
  eax = ext_4ccba0_thiscall1(ecx);  // @3_4c8e20
    // @4_4c8e20
  ecx = (u32)(EBP - 188);  // @5_4c8e20
  reg.state = (s32)((u32)(0));  // @6_4c8e20
  eax = ext_4ccba0_thiscall1(ecx);  // @7_4c8e20
    // @8_4c8e20
  eax = (u32)(EBP - 360);  // @9_4c8e20
  reg.state = (s32)((u32)(1));  // @10_4c8e20
  PV[0] = (u32)(eax);  // @11_4c8e20
  ecx = esi;  // @12_4c8e20
  eax = ext_4e6330_thiscall2(ecx, PV[0]);  // @13_4c8e20
  ecx = edx = 0;  // @14_4c8e20
  eax = (u32)(EBP - 188);  // @15_4c8e20
  ecx = esi;  // @16_4c8e20
  PV[1] = (u32)(eax);  // @17_4c8e20
  eax = ext_4e6330_thiscall2(ecx, PV[1]);  // @18_4c8e20
  ecx = edx = 0;  // @19_4c8e20
  ecx = (u32)(EBP - 360);  // @20_4c8e20
  eax = ext_4cdd40_thiscall1(ecx);  // @21_4c8e20
    // @22_4c8e20
  ecx = (u32)(EBP - 188);  // @23_4c8e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 80), &v, sizeof v); }  // @24_4c8e20
  eax = ext_4cdd40_thiscall1(ecx);  // @25_4c8e20
    // @26_4c8e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @27_4c8e20
  ebx = 0;  // @28_4c8e20
  FL[3] = ebx;  // @29_4c8e20
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; }));  // @30_4c8e20
  FL[3] = eax;  // @31_4c8e20
  ecx = (u32)(4);  // @32_4c8e20
  { u64 p_ = (u64)eax * (u64)(u32)(ecx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @33_4c8e20
  MOF = edx;  // @34_4c8e20
  ebx = (ebx & 0xffffff00u) | ((((MOF) != 0 ? 1 : 0)) & 0xff);  // @35_4c8e20
  FL[1] = ebx;  // @36_4c8e20
  ebx = (0u - ebx);  // @37_4c8e20
  ebx = (ebx | eax);  // @38_4c8e20
  FL[3] = ebx;  // @39_4c8e20
  PV[2] = (u32)(ebx);  // @40_4c8e20
  eax = ext_41e290_cdecl1(PV[2]);  // @41_4c8e20
  ecx = edx = 0;  // @42_4c8e20
  esi = eax;  // @43_4c8e20
  ecx = (u32)(EBP - 360);  // @44_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @45_4c8e20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @46_4c8e20
  eax = (u32)(esi + eax*4);  // @47_4c8e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @48_4c8e20
  eax = (u32)(EBP - 372);  // @49_4c8e20
  PV[3] = (u32)(eax);  // @50_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; });  // @51_4c8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @52_4c8e20
  ecx = edx = 0;  // @53_4c8e20
  eax = (u32)(EBP - 372);  // @54_4c8e20
  PV[4] = (u32)(eax);  // @55_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; });  // @56_4c8e20
  ecx = (u32)(EBP - 360);  // @57_4c8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[4]);  // @58_4c8e20
  ecx = edx = 0;  // @59_4c8e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @60_4c8e20
  if (FL[0] == FL[1]) goto L4c8f34;  // @61_4c8e20
  L4c8f10:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @63_4c8e20
  ecx = (u32)(EBP - 360);  // @64_4c8e20
  eax = (u32)(EBP - 372);  // @65_4c8e20
  esi = (esi + (u32)(4));  // @66_4c8e20
  FL[3] = esi;  // @67_4c8e20
  PV[5] = (u32)(eax);  // @68_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 360), sizeof v); (u32)v; });  // @69_4c8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @70_4c8e20
  ecx = edx = 0;  // @71_4c8e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @72_4c8e20
  if (FL[0] != FL[1]) goto L4c8f10;  // @73_4c8e20
  L4c8f34:;
  eax = (u32)(EBP - 372);  // @75_4c8e20
  PV[6] = (u32)(eax);  // @76_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @77_4c8e20
  ecx = (u32)(EBP - 188);  // @78_4c8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @79_4c8e20
  ecx = edx = 0;  // @80_4c8e20
  eax = (u32)(EBP - 372);  // @81_4c8e20
  PV[7] = (u32)(eax);  // @82_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @83_4c8e20
  ecx = (u32)(EBP - 188);  // @84_4c8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @85_4c8e20
  ecx = edx = 0;  // @86_4c8e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @87_4c8e20
  if (FL[0] == FL[1]) goto L4c8f94;  // @88_4c8e20
  L4c8f70:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @90_4c8e20
  ecx = (u32)(EBP - 188);  // @91_4c8e20
  eax = (u32)(EBP - 372);  // @92_4c8e20
  PV[8] = (u32)(eax);  // @93_4c8e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @94_4c8e20
  esi = (u32)(esi + 4);  // @95_4c8e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @96_4c8e20
  ecx = edx = 0;  // @97_4c8e20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 372), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @98_4c8e20
  if (FL[0] != FL[1]) goto L4c8f70;  // @99_4c8e20
  L4c8f94:;
  ecx = edi;  // @101_4c8e20
  eax = ext_4c8fe0_cdecl0();  // @102_4c8e20
  ecx = edx = 0;  // @103_4c8e20
  ecx = (u32)(EBP - 188);  // @104_4c8e20
  eax = ext_4ccf60_thiscall1(ecx);  // @105_4c8e20
  ecx = edx = 0;  // @106_4c8e20
  ecx = (u32)(EBP - 360);  // @107_4c8e20
  eax = ext_4ccf60_thiscall1(ecx);  // @108_4c8e20
  ecx = edx = 0;  // @109_4c8e20
  SEH_LEAVE();  // @110_4c8e20
  ext_633654(G(u32, 0x6f5630));  // @111_4c8e20
  return eax;  // @112_4c8e20
}
PCREG(4c8e20, lifted_4c8e20);

extern "C" u32 THISCALL lifted_4fe9e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669b4b);  // @h_4fe9e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4fe9e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @1_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_4fe9e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4fe9e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_4fe9e0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_4fe9e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 8)))(ecx);  // @6_4fe9e0
  ecx = edx = 0;  // @7_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_4fe9e0
  eax = (u32)(esi + 72);  // @9_4fe9e0
  PV[0] = (u32)(eax);  // @10_4fe9e0
  ecx = ebx;  // @11_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[0], (u32)(1));  // @12_4fe9e0
  ecx = edx = 0;  // @13_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4fe9e0
  eax = (u32)(esi + 95);  // @15_4fe9e0
  PV[1] = (u32)(eax);  // @16_4fe9e0
  ecx = ebx;  // @17_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[1], (u32)(4));  // @18_4fe9e0
  ecx = edx = 0;  // @19_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @20_4fe9e0
  eax = (u32)(esi + 99);  // @21_4fe9e0
  PV[2] = (u32)(eax);  // @22_4fe9e0
  ecx = ebx;  // @23_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[2], (u32)(4));  // @24_4fe9e0
  ecx = edx = 0;  // @25_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4fe9e0
  eax = (u32)(esi + 103);  // @27_4fe9e0
  PV[3] = (u32)(eax);  // @28_4fe9e0
  ecx = ebx;  // @29_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[3], (u32)(1));  // @30_4fe9e0
  ecx = edx = 0;  // @31_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_4fe9e0
  eax = (u32)(esi + 104);  // @33_4fe9e0
  PV[4] = (u32)(eax);  // @34_4fe9e0
  ecx = ebx;  // @35_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[4], (u32)(4));  // @36_4fe9e0
  ecx = edx = 0;  // @37_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_4fe9e0
  eax = (u32)(esi + 108);  // @39_4fe9e0
  PV[5] = (u32)(eax);  // @40_4fe9e0
  ecx = ebx;  // @41_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[5], (u32)(4));  // @42_4fe9e0
  ecx = edx = 0;  // @43_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @44_4fe9e0
  eax = (u32)(esi + 112);  // @45_4fe9e0
  PV[6] = (u32)(eax);  // @46_4fe9e0
  ecx = ebx;  // @47_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[6], (u32)(4));  // @48_4fe9e0
  ecx = edx = 0;  // @49_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_4fe9e0
  eax = (u32)(esi + 228);  // @51_4fe9e0
  PV[7] = (u32)(eax);  // @52_4fe9e0
  ecx = ebx;  // @53_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[7], (u32)(4));  // @54_4fe9e0
  ecx = edx = 0;  // @55_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_4fe9e0
  eax = (u32)(esi + 232);  // @57_4fe9e0
  PV[8] = (u32)(eax);  // @58_4fe9e0
  ecx = ebx;  // @59_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[8], (u32)(4));  // @60_4fe9e0
  ecx = edx = 0;  // @61_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @62_4fe9e0
  esi = (u32)(ebx + 36);  // @63_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 328), &v, sizeof v); }  // @64_4fe9e0
  edi = (u32)(EBP - 296);  // @65_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @66_4fe9e0
  ecx = (u32)(69);  // @67_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 324), &v, sizeof v); }  // @68_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @69_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 320), &v, sizeof v); }  // @70_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @71_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @72_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @73_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 312), &v, sizeof v); }  // @74_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; });  // @75_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 308), &v, sizeof v); }  // @76_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @77_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @78_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @79_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @80_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 312), sizeof v); (u32)v; });  // @81_4fe9e0
  { u32 v = (u32)((u32)(6875596)); __builtin_memcpy((void *)(u32)(EBP - 332), &v, sizeof v); }  // @82_4fe9e0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @83_4fe9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @84_4fe9e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 336), sizeof v); (u32)v; });  // @85_4fe9e0
  ecx = (u32)(EBP - 332);  // @86_4fe9e0
  reg.state = (s32)((u32)(0));  // @87_4fe9e0
  eax = (u32)(ebx + 73);  // @88_4fe9e0
  PV[9] = (u32)(eax);  // @89_4fe9e0
  eax = ext_4999c0_thiscall2(ecx, PV[9]);  // @90_4fe9e0
  ecx = edx = 0;  // @91_4fe9e0
  eax = (u32)(ebx + 75);  // @92_4fe9e0
  PV[10] = (u32)(eax);  // @93_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @94_4fe9e0
  ecx = (u32)(EBP - 332);  // @95_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[10]);  // @96_4fe9e0
  ecx = edx = 0;  // @97_4fe9e0
  eax = (u32)(ebx + 77);  // @98_4fe9e0
  PV[11] = (u32)(eax);  // @99_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @100_4fe9e0
  ecx = (u32)(EBP - 332);  // @101_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[11]);  // @102_4fe9e0
  ecx = edx = 0;  // @103_4fe9e0
  eax = (u32)(ebx + 79);  // @104_4fe9e0
  PV[12] = (u32)(eax);  // @105_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 332), sizeof v); (u32)v; });  // @106_4fe9e0
  ecx = (u32)(EBP - 332);  // @107_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, PV[12]);  // @108_4fe9e0
  ecx = edx = 0;  // @109_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_4fe9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @111_4fe9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4fe9e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @113_4fe9e0
  ecx = edx = 0;  // @114_4fe9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @115_4fe9e0
  esi = eax;  // @116_4fe9e0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @117_4fe9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @118_4fe9e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @119_4fe9e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[13], (u32)(16));  // @121_4fe9e0
  ecx = edx = 0;  // @122_4fe9e0
  PV[14] = (u32)(eax);  // @123_4fe9e0
  ecx = esi;  // @124_4fe9e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6891148), PV[14]);  // @125_4fe9e0
  ecx = edx = 0;  // @126_4fe9e0
  ecx = (u32)(EBP - 332);  // @127_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 212), &v, sizeof v); }  // @128_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 216), &v, sizeof v); }  // @129_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 220), &v, sizeof v); }  // @130_4fe9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 224), &v, sizeof v); }  // @131_4fe9e0
  eax = ext_499970_thiscall1(ecx);  // @132_4fe9e0
    // @133_4fe9e0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @134_4fe9e0
  SEH_LEAVE();  // @135_4fe9e0
  ext_633654(G(u32, 0x6f5630));  // @136_4fe9e0
  return eax;  // @137_4fe9e0
}
PCREG(4fe9e0, lifted_4fe9e0);

extern "C" u32 THISCALL lifted_540c70(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ab39);  // @h_540c70
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_540c70
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_540c70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_540c70
  reg.state = (s32)((u32)(0));  // @3_540c70
  { u32 v = (u32)((u32)(6958612)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_540c70
  { u32 v = (u32)((u32)(3212836864)); __builtin_memcpy((void *)(u32)(esi + 97), &v, sizeof v); }  // @5_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @6_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @7_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @8_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 89), &v, sizeof v); }  // @9_540c70
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @10_540c70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 14), &v, sizeof v); }  // @11_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 10), &v, sizeof v); }  // @12_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 93), &v, sizeof v); }  // @13_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 15), &v, sizeof v); }  // @14_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @15_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 23), &v, sizeof v); }  // @16_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @17_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @18_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @19_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @20_540c70
  FL[2] = (edi & edi);  // @21_540c70
  if (FL[2] != 0) goto L540d68;  // @22_540c70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @23_540c70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_540c70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6958624), (u32)(3265));  // @25_540c70
  ecx = edx = 0;  // @26_540c70
  PV[0] = (u32)(eax);  // @27_540c70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @28_540c70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6958976));  // @29_540c70
  ecx = edx = 0;  // @30_540c70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @31_540c70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_540c70
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6958624), (u32)(3266));  // @33_540c70
  ecx = edx = 0;  // @34_540c70
  PV[1] = (u32)(eax);  // @35_540c70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_540c70
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[1], (u32)(6959048));  // @37_540c70
  ecx = edx = 0;  // @38_540c70
  goto L540eb6;  // @39_540c70
  L540d68:;
  ecx = 0;  // @41_540c70
  FL[3] = ecx;  // @42_540c70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @43_540c70
  eax = edi;  // @44_540c70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @45_540c70
  edx = (u32)(52);  // @46_540c70
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @47_540c70
  MOF = edx;  // @48_540c70
  ecx = (ecx & 0xffffff00u) | ((((MOF) != 0 ? 1 : 0)) & 0xff);  // @49_540c70
  FL[1] = ecx;  // @50_540c70
  ecx = (0u - ecx);  // @51_540c70
  ecx = (ecx | eax);  // @52_540c70
  FL[3] = ecx;  // @53_540c70
  PV[2] = (u32)(ecx);  // @54_540c70
  eax = ext_41e290_cdecl1(PV[2]);  // @55_540c70
  ecx = edx = 0;  // @56_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @57_540c70
  reg.state = (s32)((u32)(1));  // @58_540c70
  FL[2] = (eax & eax);  // @59_540c70
  if (FL[2] == 0) goto L540db4;  // @60_540c70
  ebx = eax;  // @61_540c70
  FL[2] = (edi & edi);  // @62_540c70
  if (FL[2] == 0) goto L540db6;  // @63_540c70
  L540da0:;
  ecx = ebx;  // @65_540c70
  eax = ext_542110_thiscall1(ecx);  // @66_540c70
  ecx = edx = 0;  // @67_540c70
  ebx = (ebx + (u32)(52));  // @68_540c70
  FL[3] = ebx;  // @69_540c70
  edi = (edi - (u32)(1));  // @70_540c70
  FL[3] = edi;  // @71_540c70
  if (FL[3] != 0) goto L540da0;  // @72_540c70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @73_540c70
  goto L540db6;  // @74_540c70
  L540db4:;
  eax = 0;  // @76_540c70
  FL[3] = eax;  // @77_540c70
  L540db6:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @79_540c70
  ecx = 0;  // @80_540c70
  FL[3] = ecx;  // @81_540c70
  edi = (edi << (u32)(2));  // @82_540c70
  FL[3] = edi;  // @83_540c70
  ebx = (u32)(12);  // @84_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 15), &v, sizeof v); }  // @85_540c70
  eax = edi;  // @86_540c70
  { u64 p_ = (u64)eax * (u64)(u32)(ebx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @87_540c70
  MOF = edx;  // @88_540c70
  reg.state = (s32)((u32)(0));  // @89_540c70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @90_540c70
  ecx = (ecx & 0xffffff00u) | ((((MOF) != 0 ? 1 : 0)) & 0xff);  // @91_540c70
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @92_540c70
  FL[1] = ecx;  // @93_540c70
  ecx = (0u - ecx);  // @94_540c70
  ecx = (ecx | eax);  // @95_540c70
  FL[3] = ecx;  // @96_540c70
  PV[3] = (u32)(ecx);  // @97_540c70
  eax = ext_41e290_cdecl1(PV[3]);  // @98_540c70
  ecx = edx = 0;  // @99_540c70
  ecx = eax;  // @100_540c70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @101_540c70
  FL[2] = (ecx & ecx);  // @102_540c70
  if (FL[2] == 0) goto L540e13;  // @103_540c70
  FL[2] = (edi & edi);  // @104_540c70
  if (FL[2] == 0) goto L540e15;  // @105_540c70
  eax = (u32)(ecx + 8);  // @106_540c70
  L540df4:;
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(eax - 4), &v, sizeof v); }  // @108_540c70
  eax = (u32)(eax + 12);  // @109_540c70
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(eax - 20), &v, sizeof v); }  // @110_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax - 12), &v, sizeof v); }  // @111_540c70
  edi = (edi - (u32)(1));  // @112_540c70
  FL[3] = edi;  // @113_540c70
  if (FL[3] != 0) goto L540df4;  // @114_540c70
  goto L540e15;  // @115_540c70
  L540e13:;
  ecx = 0;  // @117_540c70
  FL[3] = ecx;  // @118_540c70
  L540e15:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 19), &v, sizeof v); }  // @120_540c70
  eax = (u32)(150);  // @121_540c70
  ecx = 0;  // @122_540c70
  FL[3] = ecx;  // @123_540c70
  { u32 v = (u32)((u32)(150)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @124_540c70
  { u64 p_ = (u64)eax * (u64)(u32)(ebx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @125_540c70
  MOF = edx;  // @126_540c70
  ecx = (ecx & 0xffffff00u) | ((((MOF) != 0 ? 1 : 0)) & 0xff);  // @127_540c70
  FL[1] = ecx;  // @128_540c70
  ecx = (0u - ecx);  // @129_540c70
  ecx = (ecx | eax);  // @130_540c70
  FL[3] = ecx;  // @131_540c70
  PV[4] = (u32)(ecx);  // @132_540c70
  eax = ext_41e290_cdecl1(PV[4]);  // @133_540c70
  ecx = edx = 0;  // @134_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @135_540c70
  FL[2] = (eax & eax);  // @136_540c70
  if (FL[2] == 0) goto L540e6f;  // @137_540c70
  edx = (u32)(150);  // @138_540c70
  ecx = (u32)(eax + 8);  // @139_540c70
  L540e50:;
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @141_540c70
  ecx = (u32)(ecx + 12);  // @142_540c70
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ecx - 20), &v, sizeof v); }  // @143_540c70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx - 12), &v, sizeof v); }  // @144_540c70
  edx = (edx - (u32)(1));  // @145_540c70
  FL[3] = edx;  // @146_540c70
  if (FL[3] != 0) goto L540e50;  // @147_540c70
  goto L540e71;  // @148_540c70
  L540e6f:;
  eax = 0;  // @150_540c70
  FL[3] = eax;  // @151_540c70
  L540e71:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(3);  // @153_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 23), &v, sizeof v); }  // @154_540c70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 27), &v, sizeof v); }  // @155_540c70
  if (FL[0] != FL[1]) goto L540e86;  // @156_540c70
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @157_540c70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 27), &v, sizeof v); }  // @158_540c70
  L540e86:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 15), sizeof v); (u32)v; });  // @160_540c70
  edi = 0;  // @161_540c70
  FL[3] = edi;  // @162_540c70
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }); FL[1] = edi;  // @163_540c70
  if ((s32)FL[0] <= (s32)FL[1]) goto L540eb1;  // @164_540c70
  ecx = (u32)(edx + 20);  // @165_540c70
  L540e93:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @167_540c70
  edx = (u32)(edx + 52);  // @168_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx - 52), &v, sizeof v); }  // @169_540c70
  ecx = (u32)(ecx + 52);  // @170_540c70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 56), sizeof v); (u32)v; });  // @171_540c70
  edi = (edi + 1);  // @172_540c70
  FL[3] = edi;  // @173_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 68), &v, sizeof v); }  // @174_540c70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 52), sizeof v); (u32)v; });  // @175_540c70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 64), &v, sizeof v); }  // @176_540c70
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @177_540c70
  if ((s32)FL[0] < (s32)FL[1]) goto L540e93;  // @178_540c70
  L540eb1:;
  eax = ext_545260_thiscall1(ecx);  // @180_540c70
  ecx = edx = 0;  // @181_540c70
  L540eb6:;
  eax = esi;  // @183_540c70
  SEH_LEAVE();  // @184_540c70
  return eax;  // @185_540c70
}
PCREG(540c70, lifted_540c70);

