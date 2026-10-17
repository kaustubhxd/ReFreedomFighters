// batch240020.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_45f430_thiscall3(u32, u32, u32) __asm__("ext_45f430");
extern "C" u32 THISCALL ext_496380_thiscall2(u32, u32) __asm__("ext_496380");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4cd950_thiscall2(u32, u32) __asm__("ext_4cd950");
extern "C" u32 THISCALL ext_4cdd40_thiscall1(u32) __asm__("ext_4cdd40");
extern "C" u32 THISCALL ext_4ce0c0_thiscall2(u32, u32) __asm__("ext_4ce0c0");
extern "C" u32 THISCALL ext_4cecd0_thiscall2(u32, u32) __asm__("ext_4cecd0");
extern "C" u32 THISCALL ext_4cf850_thiscall1(u32) __asm__("ext_4cf850");
extern "C" u32 THISCALL ext_4d8c30_thiscall2(u32, u32) __asm__("ext_4d8c30");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4d8af0(u32 ecx_in, u32 a0) {  // hand fix: the lifter took it for stdcall, ecx = this is live on entry
  SEH_ENTER(0x6696e8);  // @h_4d8af0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 260), sizeof v); (u32)v; });  // @0_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_4d8af0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @2_4d8af0
  ecx = edx = 0;  // @3_4d8af0
  ecx = (u32)(EBP - 52);  // @4_4d8af0
  esi = eax;  // @5_4d8af0
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @6_4d8af0
  ecx = edx = 0;  // @7_4d8af0
  reg.state = (s32)((u32)(0));  // @8_4d8af0
  FL[2] = (esi & esi);  // @9_4d8af0
  if (FL[2] == 0) goto L4d8b70;  // @10_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_4d8af0
  ecx = (u32)(EBP - 24);  // @12_4d8af0
  PV[0] = (u32)(ecx);  // @13_4d8af0
  ecx = esi;  // @14_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @15_4d8af0
  ecx = edx = 0;  // @16_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @17_4d8af0
  ecx = (u32)(EBP - 24);  // @18_4d8af0
  PV[1] = (u32)(ecx);  // @19_4d8af0
  ecx = esi;  // @20_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @21_4d8af0
  ecx = edx = 0;  // @22_4d8af0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @23_4d8af0
  if (FL[0] == FL[1]) goto L4d8b70;  // @24_4d8af0
  L4d8b56:;
  PV[2] = (u32)(eax);  // @26_4d8af0
  ecx = (u32)(EBP - 52);  // @27_4d8af0
  eax = ext_4cd950_thiscall2(ecx, PV[2]);  // @28_4d8af0
  ecx = edx = 0;  // @29_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_4d8af0
  ecx = (u32)(EBP - 24);  // @31_4d8af0
  PV[3] = (u32)(ecx);  // @32_4d8af0
  ecx = esi;  // @33_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[3]);  // @34_4d8af0
  ecx = edx = 0;  // @35_4d8af0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @36_4d8af0
  if (FL[0] != FL[1]) goto L4d8b56;  // @37_4d8af0
  L4d8b70:;
  ecx = (u32)(EBP - 52);  // @39_4d8af0
  eax = ext_4cf850_thiscall1(ecx);  // @40_4d8af0
  ecx = edx = 0;  // @41_4d8af0
  eax = (u32)(EBP - 24);  // @42_4d8af0
  PV[4] = (u32)(eax);  // @43_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @44_4d8af0
  ecx = (u32)(EBP - 52);  // @45_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @46_4d8af0
  ecx = edx = 0;  // @47_4d8af0
  eax = (u32)(EBP - 24);  // @48_4d8af0
  PV[5] = (u32)(eax);  // @49_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @50_4d8af0
  ecx = (u32)(EBP - 52);  // @51_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[5]);  // @52_4d8af0
  ecx = edx = 0;  // @53_4d8af0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @54_4d8af0
  esi = eax;  // @55_4d8af0
  if (FL[0] == FL[1]) goto L4d8bd6;  // @56_4d8af0
  L4d8ba0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @58_4d8af0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_4d8af0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6909064), (u32)(35));  // @60_4d8af0
  ecx = edx = 0;  // @61_4d8af0
  PV[6] = (u32)(esi);  // @62_4d8af0
  PV[7] = (u32)(eax);  // @63_4d8af0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @64_4d8af0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(6779752), PV[6]);  // @65_4d8af0
  ecx = edx = 0;  // @66_4d8af0
  eax = (u32)(EBP - 24);  // @67_4d8af0
  ecx = (u32)(EBP - 52);  // @68_4d8af0
  PV[8] = (u32)(eax);  // @69_4d8af0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 52), sizeof v); (u32)v; });  // @70_4d8af0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[8]);  // @71_4d8af0
  ecx = edx = 0;  // @72_4d8af0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @73_4d8af0
  esi = eax;  // @74_4d8af0
  if (FL[0] != FL[1]) goto L4d8ba0;  // @75_4d8af0
  L4d8bd6:;
  ecx = (u32)(EBP - 52);  // @77_4d8af0
  eax = ext_4cd0e0_thiscall1(ecx);  // @78_4d8af0
  ecx = edx = 0;  // @79_4d8af0
  SEH_LEAVE();  // @80_4d8af0
  return eax;  // @81_4d8af0
}
PCREG(4d8af0, lifted_4d8af0);

extern "C" u32 THISCALL lifted_4d8450(u32 ecx_in) {
  SEH_ENTER(0x665420);  // @h_4d8450
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_4d8450
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @1_4d8450
  { u32 v = (u32)((u32)(6909020)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @2_4d8450
  eax = ext_4d8c30_thiscall2(ecx, PV[0]);  // @3_4d8450
  ecx = edx = 0;  // @4_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @5_4d8450
  FL[2] = (ecx & ecx);  // @6_4d8450
  if (FL[2] == 0) goto L4d8495;  // @7_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @9_4d8450
  ecx = edx = 0;  // @10_4d8450
  L4d8495:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @12_4d8450
  ecx = ebx;  // @13_4d8450
  eax = ext_4d8c30_thiscall2(ecx, PV[1]);  // @14_4d8450
  ecx = edx = 0;  // @15_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @16_4d8450
  FL[2] = (ecx & ecx);  // @17_4d8450
  if (FL[2] == 0) goto L4d84ac;  // @18_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @20_4d8450
  ecx = edx = 0;  // @21_4d8450
  L4d84ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @23_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4d8450
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @25_4d8450
  ecx = edx = 0;  // @26_4d8450
  FL[2] = (eax & eax);  // @27_4d8450
  if (FL[2] == 0) goto L4d84e6;  // @28_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @29_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4d8450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(243));  // @31_4d8450
  ecx = edx = 0;  // @32_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @33_4d8450
  esi = eax;  // @34_4d8450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4d8450
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_4d8450
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @37_4d8450
  ecx = edx = 0;  // @38_4d8450
  PV[2] = (u32)(eax);  // @39_4d8450
  PV[3] = (u32)(esi);  // @40_4d8450
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[3], (u32)(6909420), PV[2]);  // @41_4d8450
  ecx = edx = 0;  // @42_4d8450
  L4d84e6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @44_4d8450
  FL[2] = (ecx & ecx);  // @45_4d8450
  if (FL[2] == 0) goto L4d8555;  // @46_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_4d8450
  edx = (u32)(EBP - 24);  // @48_4d8450
  PV[4] = (u32)(edx);  // @49_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[4]);  // @50_4d8450
  ecx = edx = 0;  // @51_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @52_4d8450
  edx = (u32)(EBP - 24);  // @53_4d8450
  PV[5] = (u32)(edx);  // @54_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @56_4d8450
  ecx = edx = 0;  // @57_4d8450
  edi = eax;  // @58_4d8450
  FL[2] = (edi & edi);  // @59_4d8450
  if (FL[2] == 0) goto L4d8555;  // @60_4d8450
  L4d8510:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @62_4d8450
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @63_4d8450
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4d8450
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6909064), (u32)(250));  // @65_4d8450
  ecx = edx = 0;  // @66_4d8450
  PV[6] = (u32)(esi);  // @67_4d8450
  PV[7] = (u32)(eax);  // @68_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @69_4d8450
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[7], (u32)(6909468), PV[6]);  // @70_4d8450
  ecx = edx = 0;  // @71_4d8450
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @72_4d8450
  FL[2] = (ecx & ecx);  // @73_4d8450
  if (FL[2] == 0) goto L4d8543;  // @74_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @76_4d8450
  ecx = edx = 0;  // @77_4d8450
  L4d8543:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @79_4d8450
  edx = (u32)(EBP - 24);  // @80_4d8450
  PV[8] = (u32)(edx);  // @81_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[8]);  // @83_4d8450
  ecx = edx = 0;  // @84_4d8450
  edi = eax;  // @85_4d8450
  FL[2] = (edi & edi);  // @86_4d8450
  if (FL[2] != 0) goto L4d8510;  // @87_4d8450
  L4d8555:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @89_4d8450
  FL[2] = (ecx & ecx);  // @90_4d8450
  if (FL[2] == 0) goto L4d8562;  // @91_4d8450
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_4d8450
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @93_4d8450
  ecx = edx = 0;  // @94_4d8450
  L4d8562:;
  SEH_LEAVE();  // @96_4d8450
  return eax;  // @97_4d8450
}
PCREG(4d8450, lifted_4d8450);

extern "C" u32 THISCALL lifted_4d8840(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6696b1);  // @h_4d8840
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4d8840
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @1_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 260), sizeof v); (u32)v; });  // @2_4d8840
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @5_4d8840
  ecx = edx = 0;  // @6_4d8840
  FL[2] = (esi & esi);  // @7_4d8840
  if (FL[2] != 0) goto L4d8a00;  // @8_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_4d8840
  esi = eax;  // @10_4d8840
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @11_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6909064), (u32)(62));  // @13_4d8840
  ecx = edx = 0;  // @14_4d8840
  PV[0] = (u32)(eax);  // @15_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_4d8840
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6909136));  // @17_4d8840
  ecx = edx = 0;  // @18_4d8840
  ecx = (u32)(EBP - 192);  // @19_4d8840
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @20_4d8840
  ecx = edx = 0;  // @21_4d8840
  reg.state = (s32)((u32)(0));  // @22_4d8840
  FL[2] = (esi & esi);  // @23_4d8840
  if (FL[2] == 0) goto L4d89d0;  // @24_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_4d8840
  ecx = (u32)(EBP - 164);  // @26_4d8840
  PV[1] = (u32)(ecx);  // @27_4d8840
  ecx = esi;  // @28_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @29_4d8840
  ecx = edx = 0;  // @30_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @31_4d8840
  ecx = (u32)(EBP - 164);  // @32_4d8840
  PV[2] = (u32)(ecx);  // @33_4d8840
  ecx = esi;  // @34_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @35_4d8840
  ecx = edx = 0;  // @36_4d8840
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @37_4d8840
  ebx = eax;  // @38_4d8840
  if (FL[0] == FL[1]) goto L4d89d0;  // @39_4d8840
  L4d8900:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 260), sizeof v); (u32)v; });  // @41_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 16)))(ecx);  // @43_4d8840
  ecx = edx = 0;  // @44_4d8840
  PV[3] = (u32)(ebx);  // @45_4d8840
  ecx = eax;  // @46_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[3]);  // @48_4d8840
  ecx = edx = 0;  // @49_4d8840
  FL[2] = (eax & eax);  // @50_4d8840
  if (FL[2] == 0) goto L4d89b3;  // @51_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @52_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @54_4d8840
  ecx = edx = 0;  // @55_4d8840
  ecx = eax;  // @56_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @57_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @58_4d8840
  ecx = edx = 0;  // @59_4d8840
  PV[4] = (u32)(eax);  // @60_4d8840
  ecx = (u32)(EBP - 144);  // @61_4d8840
  eax = ext_4cbe50_thiscall2(ecx, PV[4]);  // @62_4d8840
  ecx = edx = 0;  // @63_4d8840
  ecx = (u32)(EBP - 144);  // @64_4d8840
  reg.state = (s32)((u32)(1));  // @65_4d8840
  eax = ext_4cc5f0_thiscall1(ecx);  // @66_4d8840
  ecx = edx = 0;  // @67_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @68_4d8840
  FL[2] = (eax & eax);  // @69_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_4d8840
  if (FL[2] == 0) goto L4d898b;  // @71_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(77));  // @72_4d8840
  ecx = edx = 0;  // @73_4d8840
  esi = eax;  // @74_4d8840
  ecx = (u32)(EBP - 144);  // @75_4d8840
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_4d8840
  eax = ext_4cc1d0_thiscall1(ecx);  // @77_4d8840
    // @78_4d8840
  PV[5] = (u32)(eax);  // @79_4d8840
  PV[6] = (u32)(ebx);  // @80_4d8840
  PV[7] = (u32)(esi);  // @81_4d8840
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[7], (u32)(6909216), PV[6], PV[5]);  // @82_4d8840
  ecx = edx = 0;  // @83_4d8840
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @84_4d8840
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @85_4d8840
  goto L4d89a4;  // @86_4d8840
  L4d898b:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(81));  // @88_4d8840
  ecx = edx = 0;  // @89_4d8840
  PV[8] = (u32)(ebx);  // @90_4d8840
  PV[9] = (u32)(eax);  // @91_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @92_4d8840
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[9], (u32)(6909228), PV[8]);  // @93_4d8840
  ecx = edx = 0;  // @94_4d8840
  L4d89a4:;
  ecx = (u32)(EBP - 144);  // @96_4d8840
  reg.state = (s32)((u32)(0));  // @97_4d8840
  eax = ext_4cbec0_thiscall1(ecx);  // @98_4d8840
  ecx = edx = 0;  // @99_4d8840
  L4d89b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @101_4d8840
  ecx = (u32)(EBP - 164);  // @102_4d8840
  PV[10] = (u32)(ecx);  // @103_4d8840
  ecx = esi;  // @104_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[10]);  // @105_4d8840
  ecx = edx = 0;  // @106_4d8840
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @107_4d8840
  ebx = eax;  // @108_4d8840
  if (FL[0] != FL[1]) goto L4d8900;  // @109_4d8840
  L4d89d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @111_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(86));  // @113_4d8840
  ecx = edx = 0;  // @114_4d8840
  PV[11] = (u32)(eax);  // @115_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @116_4d8840
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[11], (u32)(6909136));  // @117_4d8840
  ecx = edx = 0;  // @118_4d8840
  ecx = (u32)(EBP - 192);  // @119_4d8840
  eax = ext_4cd0e0_thiscall1(ecx);  // @120_4d8840
  ecx = edx = 0;  // @121_4d8840
  goto L4d8ac7;  // @122_4d8840
  L4d8a00:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @124_4d8840
  ecx = eax;  // @125_4d8840
  PV[12] = (u32)(esi);  // @126_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[12]);  // @127_4d8840
  ecx = edx = 0;  // @128_4d8840
  FL[2] = (eax & eax);  // @129_4d8840
  if (FL[2] == 0) goto L4d8aa6;  // @130_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @131_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @132_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @133_4d8840
  ecx = edx = 0;  // @134_4d8840
  ecx = eax;  // @135_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @136_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @137_4d8840
  ecx = edx = 0;  // @138_4d8840
  PV[13] = (u32)(eax);  // @139_4d8840
  ecx = (u32)(EBP - 144);  // @140_4d8840
  eax = ext_4cbe50_thiscall2(ecx, PV[13]);  // @141_4d8840
  ecx = edx = 0;  // @142_4d8840
  ecx = (u32)(EBP - 144);  // @143_4d8840
  reg.state = (s32)((u32)(2));  // @144_4d8840
  eax = ext_4cc5f0_thiscall1(ecx);  // @145_4d8840
  ecx = edx = 0;  // @146_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @147_4d8840
  FL[2] = (eax & eax);  // @148_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_4d8840
  if (FL[2] == 0) goto L4d8a81;  // @150_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(100));  // @151_4d8840
  ecx = edx = 0;  // @152_4d8840
  esi = eax;  // @153_4d8840
  ecx = (u32)(EBP - 144);  // @154_4d8840
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @155_4d8840
  eax = ext_4cc1d0_thiscall1(ecx);  // @156_4d8840
    // @157_4d8840
  PV[14] = (u32)(eax);  // @158_4d8840
  PV[15] = (u32)(esi);  // @159_4d8840
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[15], (u32)(6779752), PV[14]);  // @160_4d8840
  ecx = edx = 0;  // @161_4d8840
  ecx = (u32)(EBP - 144);  // @162_4d8840
  eax = ext_4cbec0_thiscall1(ecx);  // @163_4d8840
  ecx = edx = 0;  // @164_4d8840
  goto L4d8ac7;  // @165_4d8840
  L4d8a81:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(102));  // @167_4d8840
  ecx = edx = 0;  // @168_4d8840
  PV[16] = (u32)(eax);  // @169_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @170_4d8840
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[16], (u32)(6909256));  // @171_4d8840
  ecx = edx = 0;  // @172_4d8840
  ecx = (u32)(EBP - 144);  // @173_4d8840
  eax = ext_4cbec0_thiscall1(ecx);  // @174_4d8840
  ecx = edx = 0;  // @175_4d8840
  goto L4d8ac7;  // @176_4d8840
  L4d8aa6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @178_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @179_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(105));  // @180_4d8840
  ecx = edx = 0;  // @181_4d8840
  PV[17] = (u32)(esi);  // @182_4d8840
  PV[18] = (u32)(eax);  // @183_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @184_4d8840
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[18], (u32)(6909276), PV[17]);  // @185_4d8840
  ecx = edx = 0;  // @186_4d8840
  L4d8ac7:;
  SEH_LEAVE();  // @188_4d8840
  ext_633654(G(u32, 0x6f5630));  // @189_4d8840
  return eax;  // @190_4d8840
}
PCREG(4d8840, lifted_4d8840);

extern "C" u32 THISCALL lifted_496a40(u32 ecx_in) {
  SEH_ENTER(0x668158);  // @h_496a40
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_496a40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_496a40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(3016));  // @4_496a40
  ecx = edx = 0;  // @5_496a40
  PV[0] = (u32)(eax);  // @6_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_496a40
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6874772));  // @8_496a40 (hand fix: cdecl logger slot, ecx is the vtable word)
  ecx = edx = 0;  // @9_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @10_496a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @11_496a40
  eax = (u32)(613566757);  // @12_496a40
  { u64 p_ = (u64)eax * (u64)(u32)(ebx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @13_496a40
  ebx = (ebx - edx);  // @14_496a40
  FL[3] = ebx;  // @15_496a40
  ebx = (ebx >> (u32)(1));  // @16_496a40
  FL[3] = ebx;  // @17_496a40
  ebx = (ebx + edx);  // @18_496a40
  FL[3] = ebx;  // @19_496a40
  ebx = (ebx >> (u32)(6));  // @20_496a40
  FL[3] = ebx;  // @21_496a40
  esi = (u32)(ebx + 7);  // @22_496a40
  esi = (esi >> (u32)(3));  // @23_496a40
  FL[3] = esi;  // @24_496a40
  PV[1] = (u32)(esi);  // @25_496a40
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @26_496a40
  eax = ext_41e290_cdecl1(PV[1]);  // @27_496a40
  ecx = edx = 0;  // @28_496a40
  edi = eax;  // @29_496a40
  PV[2] = (u32)(esi);  // @30_496a40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @31_496a40
  eax = ext_41e290_cdecl1(PV[2]);  // @32_496a40
  ecx = edx = 0;  // @33_496a40
  PV[3] = (u32)(esi);  // @34_496a40
  PV[4] = (u32)(edi);  // @35_496a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @36_496a40
  eax = ext_634d10_cdecl3(PV[4], (u32)(255), PV[3]);  // @37_496a40
    // @38_496a40
  PV[5] = (u32)(esi);  // @39_496a40
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @40_496a40
  eax = ext_634d10_cdecl3(PV[6], (u32)(0), PV[5]);  // @41_496a40
    // @42_496a40
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(7))) & 0xff);  // @43_496a40
  FL[3] = (ebx & 0xff);  // @44_496a40
  if (FL[3] == 0) goto L496aeb;  // @45_496a40
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @46_496a40
  ecx = (ecx & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @47_496a40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (ecx & 0xff))) & 0xff);  // @48_496a40
  FL[3] = (eax & 0xff);  // @49_496a40
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @50_496a40
  FL[3] = (eax & 0xff);  // @51_496a40
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + esi - 1), &v, sizeof v); }  // @52_496a40
  L496aeb:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @54_496a40
  ecx = ebx;  // @55_496a40
  PV[7] = (u32)(edi);  // @56_496a40
  eax = ext_496380_thiscall2(ecx, PV[7]);  // @57_496a40
  ecx = edx = 0;  // @58_496a40
  ecx = (u32)(EBP - 80);  // @59_496a40
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(64), (u32)(1));  // @60_496a40
  ecx = edx = 0;  // @61_496a40
  eax = 0;  // @62_496a40
  FL[3] = eax;  // @63_496a40
  reg.state = (s32)((u32)(0));  // @64_496a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @65_496a40
  FL[2] = (esi & esi);  // @66_496a40
  if (FL[2] == 0) goto L496bdf;  // @67_496a40
  ecx = 0;  // @68_496a40
  FL[3] = ecx;  // @69_496a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @70_496a40
  L496b20:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi), sizeof v); (u32)v; })) & 0xff);  // @72_496a40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @73_496a40
  if (FL[2] == 0) goto L496bc7;  // @74_496a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @75_496a40
  edi = (u32)(1);  // @76_496a40
  eax = (eax & 0xff);  // @77_496a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @78_496a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @79_496a40
  esi = (esi + ecx);  // @80_496a40
  FL[3] = esi;  // @81_496a40
  L496b40:;
  FL[2] = (eax & edi);  // @83_496a40
  if (FL[2] == 0) goto L496bae;  // @84_496a40
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(67108864));  // @85_496a40
  if (FL[2] != 0) goto L496bae;  // @86_496a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @87_496a40
  FL[2] = (ebx & ebx);  // @88_496a40
  if (FL[2] == 0) goto L496bae;  // @89_496a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @90_496a40
  FL[2] = (ebx & ebx);  // @91_496a40
  if (FL[2] == 0) goto L496bae;  // @92_496a40
  PV[8] = (u32)(ebx);  // @93_496a40
  ecx = (u32)(EBP - 80);  // @94_496a40
  eax = ext_4ce0c0_thiscall2(ecx, PV[8]);  // @95_496a40
  ecx = edx = 0;  // @96_496a40
  FL[2] = (eax & eax);  // @97_496a40
  if (FL[2] == 0) goto L496b6d;  // @98_496a40
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @99_496a40
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @100_496a40
  goto L496b7c;  // @101_496a40
  L496b6d:;
  PV[9] = (u32)(ebx);  // @103_496a40
  ecx = (u32)(EBP - 80);  // @104_496a40
  eax = ext_4cd540_thiscall2(ecx, PV[9]);  // @105_496a40
  ecx = edx = 0;  // @106_496a40
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @107_496a40
  L496b7c:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(134217728));  // @109_496a40
  if (FL[2] != 0) goto L496bab;  // @110_496a40
  ecx = esi;  // @111_496a40
  eax = ext_4db9a0_thiscall2(ecx, (u32)(1048577));  // @112_496a40
  ecx = 0;  // @113_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @114_496a40
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @115_496a40
  if (FL[2] == 0) goto L496ba3;  // @116_496a40
  eax = ext_45f430_thiscall3(ecx, (u32)(0), (u32)(0));  // @117_496a40
  ecx = edx = 0;  // @118_496a40
  goto L496bab;  // @119_496a40
  L496ba3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_496a40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 524)))(ecx, (u32)(0), (u32)(0));  // @122_496a40
  ecx = edx = 0;  // @123_496a40
  L496bab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @125_496a40
  L496bae:;
  edi = (edi + edi);  // @127_496a40
  FL[3] = edi;  // @128_496a40
  esi = (esi + (u32)(112));  // @129_496a40
  FL[3] = esi;  // @130_496a40
  FL[0] = edi; FL[1] = (u32)(128);  // @131_496a40
  if (FL[0] <= FL[1]) goto L496b40;  // @132_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @133_496a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @134_496a40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @135_496a40
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @136_496a40
  L496bc7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @138_496a40
  ecx = (ecx + (u32)(896));  // @139_496a40
  FL[3] = ecx;  // @140_496a40
  eax = (eax + 1);  // @141_496a40
  FL[3] = eax;  // @142_496a40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @143_496a40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @144_496a40
  FL[0] = eax; FL[1] = esi;  // @145_496a40
  if (FL[0] != FL[1]) goto L496b20;  // @146_496a40
  L496bdf:;
  ecx = (u32)(EBP - 80);  // @148_496a40
  eax = ext_4cdd40_thiscall1(ecx);  // @149_496a40
    // @150_496a40
  FL[2] = (eax & eax);  // @151_496a40
  if (FL[2] == 0) goto L496c84;  // @152_496a40
  L496bf0:;
  eax = (u32)(EBP - 52);  // @154_496a40
  ebx = 0;  // @155_496a40
  FL[3] = ebx;  // @156_496a40
  PV[10] = (u32)(eax);  // @157_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @158_496a40
  ecx = (u32)(EBP - 80);  // @159_496a40
  edi = 0;  // @160_496a40
  FL[3] = edi;  // @161_496a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[10]);  // @162_496a40
  ecx = edx = 0;  // @163_496a40
  eax = (u32)(EBP - 52);  // @164_496a40
  PV[11] = (u32)(eax);  // @165_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @166_496a40
  ecx = (u32)(EBP - 80);  // @167_496a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[11]);  // @168_496a40
  ecx = edx = 0;  // @169_496a40
  FL[2] = (eax & eax);  // @170_496a40
  if (FL[2] == 0) goto L496c3b;  // @171_496a40
  L496c12:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @173_496a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @174_496a40
  ecx = (u32)(EBP - 80);  // @175_496a40
  esi = (esi + (u32)(112));  // @176_496a40
  FL[3] = esi;  // @177_496a40
  esi = (u32)((s32)esi * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @178_496a40
  FL[3] = esi;  // @179_496a40
  FL[0] = ebx; FL[1] = esi;  // @180_496a40
  if (FL[0] < FL[1]) edi = eax;  // @181_496a40
  eax = (u32)(EBP - 52);  // @182_496a40
  PV[12] = (u32)(eax);  // @183_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @184_496a40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[12]);  // @185_496a40
  ecx = edx = 0;  // @186_496a40
  FL[0] = ebx; FL[1] = esi;  // @187_496a40
  if (FL[0] >= FL[1]) esi = ebx;  // @188_496a40
  ebx = esi;  // @189_496a40
  FL[2] = (eax & eax);  // @190_496a40
  if (FL[2] != 0) goto L496c12;  // @191_496a40
  L496c3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @193_496a40
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @194_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @195_496a40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(3101));  // @196_496a40
  ecx = edx = 0;  // @197_496a40
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @198_496a40
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @199_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @200_496a40
  PV[15] = (u32)(ebx);  // @201_496a40
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @202_496a40
  PV[17] = (u32)(eax);  // @203_496a40
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[17], (u32)(6874828), PV[16], PV[15], PV[14], (u32)(112), PV[13]);  // @204_496a40
  ecx = edx = 0;  // @205_496a40
  ecx = (u32)(EBP - 80);  // @206_496a40
  PV[18] = (u32)(esi);  // @207_496a40
  eax = ext_4cecd0_thiscall2(ecx, PV[18]);  // @208_496a40
  ecx = edx = 0;  // @209_496a40
  ecx = (u32)(EBP - 80);  // @210_496a40
  eax = ext_4cdd40_thiscall1(ecx);  // @211_496a40
    // @212_496a40
  FL[2] = (eax & eax);  // @213_496a40
  if (FL[2] != 0) goto L496bf0;  // @214_496a40
  L496c84:;
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @216_496a40
  eax = ext_634273_cdecl2(PV[19], (u32)(1));  // @217_496a40
  ecx = edx = 0;  // @218_496a40
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @219_496a40
  eax = ext_634273_cdecl2(PV[20], (u32)(1));  // @220_496a40
  ecx = edx = 0;  // @221_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @222_496a40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @223_496a40
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(3107));  // @224_496a40
  ecx = edx = 0;  // @225_496a40
  PV[21] = (u32)(eax);  // @226_496a40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @227_496a40
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[21], (u32)(6874884));  // @228_496a40
  ecx = edx = 0;  // @229_496a40
  ecx = (u32)(EBP - 80);  // @230_496a40
  eax = ext_4ccfe0_thiscall1(ecx);  // @231_496a40
  ecx = edx = 0;  // @232_496a40
  SEH_LEAVE();  // @233_496a40
  return eax;  // @234_496a40
}
PCREG(496a40, lifted_496a40);

extern "C" u32 THISCALL lifted_496760(u32 ecx_in) {
  SEH_ENTER(0x668128);  // @h_496760
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_496760
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @1_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_496760
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(3111));  // @4_496760
  ecx = edx = 0;  // @5_496760
  PV[0] = (u32)(eax);  // @6_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_496760
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6874948));  // @8_496760 (hand fix: cdecl logger slot, ecx is the vtable word)
  ecx = edx = 0;  // @9_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @10_496760
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @11_496760
  eax = (u32)(613566757);  // @12_496760
  { u64 p_ = (u64)eax * (u64)(u32)(ebx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @13_496760
  ebx = (ebx - edx);  // @14_496760
  FL[3] = ebx;  // @15_496760
  ebx = (ebx >> (u32)(1));  // @16_496760
  FL[3] = ebx;  // @17_496760
  ebx = (ebx + edx);  // @18_496760
  FL[3] = ebx;  // @19_496760
  ebx = (ebx >> (u32)(6));  // @20_496760
  FL[3] = ebx;  // @21_496760
  esi = (u32)(ebx + 7);  // @22_496760
  esi = (esi >> (u32)(3));  // @23_496760
  FL[3] = esi;  // @24_496760
  PV[1] = (u32)(esi);  // @25_496760
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @26_496760
  eax = ext_41e290_cdecl1(PV[1]);  // @27_496760
  ecx = edx = 0;  // @28_496760
  edi = eax;  // @29_496760
  PV[2] = (u32)(esi);  // @30_496760
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @31_496760
  eax = ext_41e290_cdecl1(PV[2]);  // @32_496760
  ecx = edx = 0;  // @33_496760
  PV[3] = (u32)(esi);  // @34_496760
  PV[4] = (u32)(edi);  // @35_496760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @36_496760
  eax = ext_634d10_cdecl3(PV[4], (u32)(255), PV[3]);  // @37_496760
    // @38_496760
  PV[5] = (u32)(esi);  // @39_496760
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @40_496760
  eax = ext_634d10_cdecl3(PV[6], (u32)(0), PV[5]);  // @41_496760
    // @42_496760
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(7))) & 0xff);  // @43_496760
  FL[3] = (ebx & 0xff);  // @44_496760
  if (FL[3] == 0) goto L49680b;  // @45_496760
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @46_496760
  ecx = (ecx & 0xffffff00u) | (((ebx & 0xff)) & 0xff);  // @47_496760
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) << (ecx & 0xff))) & 0xff);  // @48_496760
  FL[3] = (eax & 0xff);  // @49_496760
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) - 1)) & 0xff);  // @50_496760
  FL[3] = (eax & 0xff);  // @51_496760
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + esi - 1), &v, sizeof v); }  // @52_496760
  L49680b:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @54_496760
  ecx = ebx;  // @55_496760
  PV[7] = (u32)(edi);  // @56_496760
  eax = ext_496380_thiscall2(ecx, PV[7]);  // @57_496760
  ecx = edx = 0;  // @58_496760
  ecx = (u32)(EBP - 84);  // @59_496760
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(64), (u32)(1));  // @60_496760
  ecx = edx = 0;  // @61_496760
  eax = 0;  // @62_496760
  FL[3] = eax;  // @63_496760
  reg.state = (s32)((u32)(0));  // @64_496760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @65_496760
  FL[2] = (esi & esi);  // @66_496760
  if (FL[2] == 0) goto L496943;  // @67_496760
  edx = 0;  // @68_496760
  FL[3] = edx;  // @69_496760
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @70_496760
  L496840:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi), sizeof v); (u32)v; })) & 0xff);  // @72_496760
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @73_496760
  if (FL[2] == 0) goto L49692b;  // @74_496760
  ecx = (eax & 0xff);  // @75_496760
  esi = (u32)(1);  // @76_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @77_496760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @78_496760
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @79_496760
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @80_496760
  ebx = (ebx + (u32)(84));  // @81_496760
  FL[3] = ebx;  // @82_496760
  ebx = (ebx + edx);  // @83_496760
  FL[3] = ebx;  // @84_496760
  L496864:;
  FL[2] = (ecx & esi);  // @86_496760
  if (FL[2] == 0) goto L49690b;  // @87_496760
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx - 24), sizeof v); (u32)v; }) & (u32)(67108864));  // @88_496760
  if (FL[2] != 0) goto L49690b;  // @89_496760
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_496760
  FL[2] = (edi & edi);  // @91_496760
  if (FL[2] == 0) goto L49690b;  // @92_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @93_496760
  FL[2] = (eax & eax);  // @94_496760
  if (FL[2] == 0) goto L49690b;  // @95_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @96_496760
  FL[2] = (ecx & ecx);  // @97_496760
  if (FL[2] == 0) goto L496908;  // @98_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_496760
  edx = (u32)(EBP - 56);  // @100_496760
  PV[8] = (u32)(edx);  // @101_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @102_496760
  ecx = edx = 0;  // @103_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @104_496760
  edx = (u32)(EBP - 56);  // @105_496760
  PV[9] = (u32)(edx);  // @106_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @107_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[9]);  // @109_496760
  ecx = edx = 0;  // @110_496760
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @111_496760
  if (FL[0] == FL[1]) goto L496908;  // @112_496760
  L4968b3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @114_496760
  PV[10] = (u32)(eax);  // @115_496760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[10]);  // @117_496760
  ecx = edx = 0;  // @118_496760
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @119_496760
  if (FL[0] != FL[1]) goto L4968f0;  // @120_496760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @121_496760
  FL[2] = (esi & esi);  // @122_496760
  if (FL[2] == 0) goto L4968f0;  // @123_496760
  PV[11] = (u32)(esi);  // @124_496760
  ecx = (u32)(EBP - 84);  // @125_496760
  eax = ext_4ce0c0_thiscall2(ecx, PV[11]);  // @126_496760
  ecx = edx = 0;  // @127_496760
  FL[2] = (eax & eax);  // @128_496760
  if (FL[2] == 0) goto L4968e1;  // @129_496760
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @130_496760
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @131_496760
  goto L4968f0;  // @132_496760
  L4968e1:;
  PV[12] = (u32)(esi);  // @134_496760
  ecx = (u32)(EBP - 84);  // @135_496760
  eax = ext_4cd540_thiscall2(ecx, PV[12]);  // @136_496760
  ecx = edx = 0;  // @137_496760
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @138_496760
  L4968f0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @140_496760
  edx = (u32)(EBP - 56);  // @141_496760
  PV[13] = (u32)(edx);  // @142_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @143_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[13]);  // @145_496760
  ecx = edx = 0;  // @146_496760
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 56), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @147_496760
  if (FL[0] != FL[1]) goto L4968b3;  // @148_496760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @149_496760
  L496908:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @151_496760
  L49690b:;
  esi = (esi + esi);  // @153_496760
  FL[3] = esi;  // @154_496760
  ebx = (ebx + (u32)(112));  // @155_496760
  FL[3] = ebx;  // @156_496760
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @157_496760
  FL[0] = esi; FL[1] = (u32)(128);  // @158_496760
  if (FL[0] <= FL[1]) goto L496864;  // @159_496760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @160_496760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @161_496760
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @162_496760
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @163_496760
  L49692b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @165_496760
  edx = (edx + (u32)(896));  // @166_496760
  FL[3] = edx;  // @167_496760
  eax = (eax + 1);  // @168_496760
  FL[3] = eax;  // @169_496760
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @170_496760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @171_496760
  FL[0] = eax; FL[1] = esi;  // @172_496760
  if (FL[0] != FL[1]) goto L496840;  // @173_496760
  L496943:;
  ecx = (u32)(EBP - 84);  // @175_496760
  eax = ext_4cdd40_thiscall1(ecx);  // @176_496760
    // @177_496760
  FL[2] = (eax & eax);  // @178_496760
  if (FL[2] == 0) goto L4969e5;  // @179_496760
  L496953:;
  eax = (u32)(EBP - 56);  // @181_496760
  ebx = 0;  // @182_496760
  FL[3] = ebx;  // @183_496760
  PV[14] = (u32)(eax);  // @184_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @185_496760
  ecx = (u32)(EBP - 84);  // @186_496760
  edi = 0;  // @187_496760
  FL[3] = edi;  // @188_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[14]);  // @189_496760
  ecx = edx = 0;  // @190_496760
  eax = (u32)(EBP - 56);  // @191_496760
  PV[15] = (u32)(eax);  // @192_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @193_496760
  ecx = (u32)(EBP - 84);  // @194_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[15]);  // @195_496760
  ecx = edx = 0;  // @196_496760
  FL[2] = (eax & eax);  // @197_496760
  if (FL[2] == 0) goto L49699e;  // @198_496760
  L496975:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @200_496760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @201_496760
  ecx = (u32)(EBP - 84);  // @202_496760
  esi = (esi + (u32)(112));  // @203_496760
  FL[3] = esi;  // @204_496760
  esi = (u32)((s32)esi * (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @205_496760
  FL[3] = esi;  // @206_496760
  FL[0] = ebx; FL[1] = esi;  // @207_496760
  if (FL[0] < FL[1]) edi = eax;  // @208_496760
  eax = (u32)(EBP - 56);  // @209_496760
  PV[16] = (u32)(eax);  // @210_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @211_496760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[16]);  // @212_496760
  ecx = edx = 0;  // @213_496760
  FL[0] = ebx; FL[1] = esi;  // @214_496760
  if (FL[0] >= FL[1]) esi = ebx;  // @215_496760
  ebx = esi;  // @216_496760
  FL[2] = (eax & eax);  // @217_496760
  if (FL[2] != 0) goto L496975;  // @218_496760
  L49699e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @220_496760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @221_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @222_496760
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(3200));  // @223_496760
  ecx = edx = 0;  // @224_496760
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @225_496760
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @226_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @227_496760
  PV[19] = (u32)(ebx);  // @228_496760
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @229_496760
  PV[21] = (u32)(eax);  // @230_496760
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[21], (u32)(6875004), PV[20], PV[19], PV[18], PV[17]);  // @231_496760
  ecx = edx = 0;  // @232_496760
  ecx = (u32)(EBP - 84);  // @233_496760
  PV[22] = (u32)(esi);  // @234_496760
  eax = ext_4cecd0_thiscall2(ecx, PV[22]);  // @235_496760
  ecx = edx = 0;  // @236_496760
  ecx = (u32)(EBP - 84);  // @237_496760
  eax = ext_4cdd40_thiscall1(ecx);  // @238_496760
    // @239_496760
  FL[2] = (eax & eax);  // @240_496760
  if (FL[2] != 0) goto L496953;  // @241_496760
  L4969e5:;
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @243_496760
  eax = ext_634273_cdecl2(PV[23], (u32)(1));  // @244_496760
  ecx = edx = 0;  // @245_496760
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @246_496760
  eax = ext_634273_cdecl2(PV[24], (u32)(1));  // @247_496760
  ecx = edx = 0;  // @248_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @249_496760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @250_496760
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6873964), (u32)(3206));  // @251_496760
  ecx = edx = 0;  // @252_496760
  PV[25] = (u32)(eax);  // @253_496760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @254_496760
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[25], (u32)(6875028));  // @255_496760
  ecx = edx = 0;  // @256_496760
  ecx = (u32)(EBP - 84);  // @257_496760
  eax = ext_4ccfe0_thiscall1(ecx);  // @258_496760
  ecx = edx = 0;  // @259_496760
  SEH_LEAVE();  // @260_496760
  return eax;  // @261_496760
}
PCREG(496760, lifted_496760);

extern "C" u32 THISCALL lifted_49d480(u32 ecx_in) {
  SEH_ENTER(0x66b2ab);  // @h_49d480
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 w4a_fmt = 0; u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_49d480
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @1_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(424));  // @4_49d480
  ecx = edx = 0;  // @5_49d480
  PV[0] = (u32)(eax);  // @6_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_49d480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6876896));  // @8_49d480 (hand fix: the logger slot is cdecl, ecx is the vtable word)
  ecx = edx = 0;  // @9_49d480
  ecx = 0;  // @10_49d480
  FL[3] = ecx;  // @11_49d480
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }); FL[1] = ecx;  // @12_49d480
  if (FL[0] == FL[1]) goto L49d65d;  // @13_49d480
  L49d4e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @15_49d480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @16_49d480
  ecx = (ecx + 1);  // @17_49d480
  FL[3] = ecx;  // @18_49d480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @19_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @20_49d480
  PV[1] = (u32)(edx);  // @21_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_49d480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[1]);  // @23_49d480
  ecx = edx = 0;  // @24_49d480
  esi = eax;  // @25_49d480
  FL[2] = (esi & esi);  // @26_49d480
  if (FL[2] == 0) goto L49d62b;  // @27_49d480
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) & (u32)(16));  // @28_49d480
  if (FL[2] == 0) goto L49d62b;  // @29_49d480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @30_49d480
  FL[2] = (edx & edx);  // @31_49d480
  if (FL[2] == 0) goto L49d57a;  // @32_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_49d480
  PV[2] = (u32)(edx);  // @34_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @35_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_49d480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[2]);  // @37_49d480
  ecx = edx = 0;  // @38_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @39_49d480
  FL[2] = (eax & eax);  // @40_49d480
  if (FL[2] != 0) goto L49d54f;  // @41_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(441));  // @43_49d480
  ecx = edx = 0;  // @44_49d480
  w4a_fmt = 6876984; goto L49d645;  // @45_49d480 (hand fix: format pushed before the shared tail)
  L49d54f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @47_49d480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(445));  /* hand fix: stale argument removed */  // @50_49d480
  ecx = edx = 0;  // @51_49d480
  PV[3] = (u32)(edi);  // @52_49d480
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @53_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_49d480
  PV[5] = (u32)(eax);  // @55_49d480
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6877004), PV[4], PV[3]);  // @56_49d480
  ecx = edx = 0;  // @57_49d480
  goto L49d64e;  // @58_49d480
  L49d57a:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @60_49d480
  FL[2] = (edi & edi);  // @61_49d480
  if (FL[2] != 0) goto L49d5a0;  // @62_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @63_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(453));  // @65_49d480
  ecx = edx = 0;  // @66_49d480
  w4a_fmt = 6877032; goto L49d645;  // @67_49d480 (hand fix)
  L49d5a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @69_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @70_49d480
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; });  // @71_49d480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @72_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @73_49d480
  eax = (eax << (u32)(20));  // @74_49d480
  FL[3] = eax;  // @75_49d480
  eax = (eax | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }));  // @76_49d480
  FL[3] = eax;  // @77_49d480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @78_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(475));  // @80_49d480 (hand fix: stale pushed argument removed)
  ecx = edx = 0;  // @81_49d480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_49d480
  ebx = eax;  // @83_49d480
  eax = (u32)(EBP - 144);  // @84_49d480
  ecx = edi;  // @85_49d480
  PV[6] = (u32)(eax);  // @86_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[6], (u32)(1));  // @87_49d480
  ecx = edx = 0;  // @88_49d480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @89_49d480
  ecx = eax;  // @90_49d480
  reg.state = (s32)((u32)(0));  // @91_49d480
  eax = ext_4cc1d0_thiscall1(ecx);  // @92_49d480
    // @93_49d480
  PV[7] = (u32)(eax);  // @94_49d480
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @95_49d480
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @96_49d480
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @97_49d480
  PV[11] = (u32)(ebx);  // @98_49d480
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 44)))(PV[11], (u32)(6877052), PV[10], PV[9], PV[8], PV[7]);  // @99_49d480
  ecx = edx = 0;  // @100_49d480
  reg.state = (s32)((u32)(4294967295));  // @101_49d480
  ecx = (u32)(EBP - 144);  // @102_49d480
  eax = ext_4cbec0_thiscall1(ecx);  // @103_49d480
  ecx = edx = 0;  // @104_49d480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @105_49d480
  goto L49d64e;  // @106_49d480
  L49d62b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @108_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @109_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(432));  // @110_49d480
  ecx = edx = 0;  // @111_49d480
  w4a_fmt = 6876964;
  L49d645:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @113_49d480
  PV[12] = (u32)(eax);  // @114_49d480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[12], (u32)(w4a_fmt));  // @115_49d480
  ecx = edx = 0;  // @116_49d480
  L49d64e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @118_49d480
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @119_49d480
  if (FL[0] != FL[1]) goto L49d4e4;  // @120_49d480
  L49d65d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @122_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(478));  // @124_49d480
  ecx = edx = 0;  // @125_49d480
  PV[13] = (u32)(eax);  // @126_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @127_49d480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[13], (u32)(6877112));  // @128_49d480
  ecx = edx = 0;  // @129_49d480
  SEH_LEAVE();  // @130_49d480
  ext_633654(G(u32, 0x6f5630));  // @131_49d480
  return eax;  // @132_49d480
}
PCREG(49d480, lifted_49d480);

extern "C" u32 THISCALL lifted_5ef560(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cd12);  // @h_5ef560
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 169), sizeof v); (u32)v; });  // @1_5ef560
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5ef560
  PV[0] = (u32)(edi);  // @3_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[0]);  // @5_5ef560
  ecx = edx = 0;  // @6_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 161), sizeof v); (u32)v; });  // @7_5ef560
  PV[1] = (u32)(edi);  // @8_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[1]);  // @10_5ef560
  ecx = edx = 0;  // @11_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 165), sizeof v); (u32)v; });  // @12_5ef560
  PV[2] = (u32)(edi);  // @13_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[2]);  // @15_5ef560
  ecx = edx = 0;  // @16_5ef560
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @17_5ef560
  eax = (u32)(esi + 8);  // @18_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_5ef560
  ecx = edi;  // @20_5ef560
  PV[3] = (u32)(eax);  // @21_5ef560
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[3], (u32)(128));  // @22_5ef560
  ecx = edx = 0;  // @23_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @24_5ef560
  eax = (u32)(esi + 136);  // @25_5ef560
  PV[4] = (u32)(eax);  // @26_5ef560
  ecx = edi;  // @27_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[4]);  // @28_5ef560
  ecx = edx = 0;  // @29_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_5ef560
  eax = (u32)(esi + 140);  // @31_5ef560
  PV[5] = (u32)(eax);  // @32_5ef560
  ecx = edi;  // @33_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[5]);  // @34_5ef560
  ecx = edx = 0;  // @35_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_5ef560
  eax = (u32)(esi + 144);  // @37_5ef560
  PV[6] = (u32)(eax);  // @38_5ef560
  ecx = edi;  // @39_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, PV[6]);  // @40_5ef560
  ecx = edx = 0;  // @41_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_5ef560
  eax = (u32)(esi + 148);  // @43_5ef560
  PV[7] = (u32)(eax);  // @44_5ef560
  ecx = edi;  // @45_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[7]);  // @46_5ef560
  ecx = edx = 0;  // @47_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_5ef560
  eax = (u32)(esi + 152);  // @49_5ef560
  PV[8] = (u32)(eax);  // @50_5ef560
  ecx = edi;  // @51_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[8]);  // @52_5ef560
  ecx = edx = 0;  // @53_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_5ef560
  eax = (u32)(esi + 156);  // @55_5ef560
  PV[9] = (u32)(eax);  // @56_5ef560
  ecx = edi;  // @57_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, PV[9]);  // @58_5ef560
  ecx = edx = 0;  // @59_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @60_5ef560
  eax = (u32)(esi + 160);  // @61_5ef560
  PV[10] = (u32)(eax);  // @62_5ef560
  ecx = edi;  // @63_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[10]);  // @64_5ef560
  ecx = edx = 0;  // @65_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_5ef560
  eax = (u32)(esi + 183);  // @67_5ef560
  PV[11] = (u32)(eax);  // @68_5ef560
  ecx = edi;  // @69_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[11]);  // @70_5ef560
  ecx = edx = 0;  // @71_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @72_5ef560
  eax = (u32)(esi + 185);  // @73_5ef560
  PV[12] = (u32)(eax);  // @74_5ef560
  ecx = edi;  // @75_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[12]);  // @76_5ef560
  ecx = edx = 0;  // @77_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_5ef560
  eax = (u32)(esi + 181);  // @79_5ef560
  PV[13] = (u32)(eax);  // @80_5ef560
  ecx = edi;  // @81_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[13]);  // @82_5ef560
  ecx = edx = 0;  // @83_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_5ef560
  ecx = (u32)(EBP - 16);  // @85_5ef560
  PV[14] = (u32)(ecx);  // @86_5ef560
  ecx = edi;  // @87_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[14]);  // @88_5ef560
  ecx = edx = 0;  // @89_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @90_5ef560
  ecx = (u32)(EBP - 20);  // @91_5ef560
  PV[15] = (u32)(ecx);  // @92_5ef560
  ecx = edi;  // @93_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[15]);  // @94_5ef560
  ecx = edx = 0;  // @95_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @96_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 187), &v, sizeof v); }  // @97_5ef560
  ecx = edi;  // @98_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @99_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 191), &v, sizeof v); }  // @100_5ef560
  eax = (u32)(esi + 182);  // @101_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @102_5ef560
  PV[16] = (u32)(eax);  // @103_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[16]);  // @104_5ef560
  ecx = edx = 0;  // @105_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @106_5ef560
  ecx = (u32)(EBP + 11);  // @107_5ef560
  PV[17] = (u32)(ecx);  // @108_5ef560
  ecx = edi;  // @109_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, PV[17]);  // @110_5ef560
  ecx = edx = 0;  // @111_5ef560
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @112_5ef560
  if (FL[0] == FL[1]) goto L5ef708;  // @113_5ef560
  eax = ext_41e290_cdecl1((u32)(12));  // @114_5ef560
  ecx = edx = 0;  // @115_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 195), &v, sizeof v); }  // @116_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @117_5ef560
  ecx = edi;  // @118_5ef560
  PV[18] = (u32)(eax);  // @119_5ef560
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[18], (u32)(12));  // @120_5ef560
  ecx = edx = 0;  // @121_5ef560
  eax = ext_41e290_cdecl1((u32)(247));  // @122_5ef560
  ecx = edx = 0;  // @123_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @124_5ef560
  reg.state = (s32)((u32)(0));  // @125_5ef560
  FL[2] = (eax & eax);  // @126_5ef560
  if (FL[2] == 0) goto L5ef6da;  // @127_5ef560
  ecx = eax;  // @128_5ef560
  eax = ext_5ed460_thiscall1(ecx);  // @129_5ef560
  ecx = edx = 0;  // @130_5ef560
  ecx = eax;  // @131_5ef560
  goto L5ef6dc;  // @132_5ef560
  L5ef6da:;
  ecx = 0;  // @134_5ef560
  FL[3] = ecx;  // @135_5ef560
  L5ef6dc:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 177), &v, sizeof v); }  // @137_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_5ef560
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 195), sizeof v); (u32)v; });  // @139_5ef560
  reg.state = (s32)((u32)(4294967295));  // @140_5ef560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[19], (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @141_5ef560
  ecx = edx = 0;  // @142_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 177), sizeof v); (u32)v; });  // @143_5ef560
  PV[20] = (u32)(edi);  // @144_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[20]);  // @146_5ef560
  ecx = edx = 0;  // @147_5ef560
  L5ef708:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 173), &v, sizeof v); }  // @149_5ef560
  SEH_LEAVE();  // @150_5ef560
  return eax;  // @151_5ef560
}
PCREG(5ef560, lifted_5ef560);

