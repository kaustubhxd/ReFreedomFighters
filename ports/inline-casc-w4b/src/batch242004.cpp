// batch242004.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4711f0_thiscall3(u32, u32, u32) __asm__("ext_4711f0");
extern "C" u32 THISCALL ext_449d40_thiscall4(u32, u32, u32, u32) __asm__("ext_449d40");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4daf90_thiscall2(u32, u32) __asm__("ext_4daf90");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" u32 THISCALL ext_4e6330_thiscall2(u32, u32) __asm__("ext_4e6330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5c3c60(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5c3c60
  edi = ecx;  // @1_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5c3c60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_5c3c60
  ecx = edx = 0;  // @5_5c3c60
  ecx = (u32)(EBP - 20);  // @6_5c3c60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @7_5c3c60
  PV[0] = (u32)(ecx);  // @8_5c3c60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_5c3c60
  ecx = eax;  // @10_5c3c60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), PV[0]);  // @11_5c3c60
  ecx = edx = 0;  // @12_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5c3c60
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @14_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5c3c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @17_5c3c60
  ecx = edx = 0;  // @18_5c3c60
  esi = eax;  // @19_5c3c60
  eax = (u32)(EBP - 16);  // @20_5c3c60
  PV[2] = (u32)(eax);  // @21_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @22_5c3c60
  eax = ext_4daf90_thiscall2(ecx, PV[2]);  // @23_5c3c60
  edx = 0;  // @24_5c3c60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_5c3c60
  eax = (u32)(EBP - 16);  // @26_5c3c60
  PV[3] = (u32)(eax);  // @27_5c3c60
  ecx = esi;  // @28_5c3c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, PV[3]);  // @29_5c3c60
  ecx = edx = 0;  // @30_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @31_5c3c60
  edx = (u32)(EBP - 16);  // @32_5c3c60
  PV[4] = (u32)(edx);  // @33_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_5c3c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[4]);  // @35_5c3c60
  ecx = edx = 0;  // @36_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @37_5c3c60
  edx = (u32)(EBP - 16);  // @38_5c3c60
  PV[5] = (u32)(ecx);  // @39_5c3c60
  PV[6] = (u32)(edx);  // @40_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @42_5c3c60
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[6], (u32)(3240099840));  // @43_5c3c60
  ecx = edx = 0;  // @44_5c3c60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @45_5c3c60
  if (FL[2] == 0) goto L5c3d74;  // @46_5c3c60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @47_5c3c60
  if (FL[0] != FL[1]) goto L5c3d7e;  // @48_5c3c60
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 73), sizeof v); (u32)v; });  // @49_5c3c60
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @50_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5c3c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[7]);  // @54_5c3c60
  ecx = edx = 0;  // @55_5c3c60
  esi = eax;  // @56_5c3c60
  FL[2] = (esi & esi);  // @57_5c3c60
  if (FL[2] == 0) goto L5c3d44;  // @58_5c3c60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_5c3c60
  ecx = esi;  // @60_5c3c60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 708)))(ecx);  // @61_5c3c60
  ecx = edx = 0;  // @62_5c3c60
  PV[8] = (u32)(esi);  // @63_5c3c60
  ecx = eax;  // @64_5c3c60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @65_5c3c60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 764)))(ecx, PV[8]);  // @66_5c3c60
  ecx = edx = 0;  // @67_5c3c60
  ext_633654(G(u32, 0x6f5630));  // @68_5c3c60
  return eax;  // @69_5c3c60
  L5c3d44:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @71_5c3c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5c3c60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7028408), (u32)(47));  // @73_5c3c60
  ecx = edx = 0;  // @74_5c3c60
  PV[9] = (u32)(eax);  // @75_5c3c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_5c3c60
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[9], (u32)(7028460));  // @77_5c3c60
  ecx = edx = 0;  // @78_5c3c60
  ext_633654(G(u32, 0x6f5630));  // @79_5c3c60
  return eax;  // @80_5c3c60
  L5c3d74:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @82_5c3c60
  if (FL[0] == FL[1]) goto L5c3d7e;  // @83_5c3c60
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @84_5c3c60
  L5c3d7e:;
  ext_633654(G(u32, 0x6f5630));  // @86_5c3c60
  return eax;  // @87_5c3c60
}
PCREG(5c3c60, lifted_5c3c60);

extern "C" u32 THISCALL lifted_4ee2e0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66985a);  // @h_4ee2e0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  ebx = ecx;  // @0_4ee2e0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_4ee2e0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @2_4ee2e0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4ee2e0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4ee2e0
  eax = ext_449d40_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @5_4ee2e0
  ecx = edx = 0;  // @6_4ee2e0
  { u32 v = (u32)((u32)(6912196)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @7_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4ee2e0
  reg.state = (s32)((u32)(0));  // @9_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4ee2e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @12_4ee2e0
  ecx = edx = 0;  // @13_4ee2e0
  ecx = (u32)(EBP + 16);  // @14_4ee2e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @15_4ee2e0
  PV[3] = (u32)(ecx);  // @16_4ee2e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_4ee2e0
  ecx = eax;  // @18_4ee2e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6912776), PV[3]);  // @19_4ee2e0
  ecx = edx = 0;  // @20_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_4ee2e0
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @22_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @23_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4ee2e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[4]);  // @25_4ee2e0
  ecx = edx = 0;  // @26_4ee2e0
  esi = eax;  // @27_4ee2e0
  FL[2] = (esi & esi);  // @28_4ee2e0
  if (FL[2] == 0) goto L4ee3bc;  // @29_4ee2e0
  FL[0] = esi; FL[1] = ebx;  // @30_4ee2e0
  if (FL[0] == FL[1]) goto L4ee3bc;  // @31_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @32_4ee2e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_4ee2e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6912796), (u32)(470));  // @34_4ee2e0
  ecx = edx = 0;  // @35_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @36_4ee2e0
  edi = eax;  // @37_4ee2e0
  FL[2] = (ecx & ecx);  // @38_4ee2e0
  esi = (u32)(6801640);  // @39_4ee2e0
  edx = esi;  // @40_4ee2e0
  if (FL[2] != 0) edx = ecx;  // @41_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @42_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @43_4ee2e0
  FL[2] = (ecx & ecx);  // @44_4ee2e0
  PV[5] = (u32)(edx);  // @45_4ee2e0
  if (FL[2] != 0) esi = ecx;  // @46_4ee2e0
  PV[6] = (u32)(esi);  // @47_4ee2e0
  PV[7] = (u32)(edi);  // @48_4ee2e0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(eax + 44)))(PV[7], (u32)(6912840), PV[6], PV[5]);  // @49_4ee2e0
  ecx = edx = 0;  // @50_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @51_4ee2e0
  FL[2] = (eax & eax);  // @52_4ee2e0
  if (FL[2] == 0) goto L4ee3bb;  // @53_4ee2e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @54_4ee2e0
  ecx = edx = 0;  // @55_4ee2e0
  goto L4ee3bc;  // @56_4ee2e0
  L4ee3bb:;
  __builtin_trap();  // @58_4ee2e0
  L4ee3bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_4ee2e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_4ee2e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @63_4ee2e0
  ecx = edx = 0;  // @64_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_4ee2e0
  esi = eax;  // @66_4ee2e0
  PV[8] = (u32)(ebx);  // @67_4ee2e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @68_4ee2e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @69_4ee2e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_4ee2e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, PV[8], (u32)(4));  // @71_4ee2e0
  ecx = edx = 0;  // @72_4ee2e0
  PV[9] = (u32)(eax);  // @73_4ee2e0
  ecx = esi;  // @74_4ee2e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(6912776), PV[9]);  // @75_4ee2e0
  ecx = edx = 0;  // @76_4ee2e0
  eax = ext_41e290_cdecl1((u32)(172));  // @77_4ee2e0
  ecx = edx = 0;  // @78_4ee2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @79_4ee2e0
  reg.state = (s32)((u32)(1));  // @80_4ee2e0
  FL[2] = (eax & eax);  // @81_4ee2e0
  if (FL[2] == 0) goto L4ee416;  // @82_4ee2e0
  ecx = eax;  // @83_4ee2e0
  eax = ext_4ccba0_thiscall1(ecx);  // @84_4ee2e0
    // @85_4ee2e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @86_4ee2e0
  goto L4ee41d;  // @87_4ee2e0
  L4ee416:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @89_4ee2e0
  L4ee41d:;
  eax = ebx;  // @91_4ee2e0
  SEH_LEAVE();  // @92_4ee2e0
  return eax;  // @93_4ee2e0
}
PCREG(4ee2e0, lifted_4ee2e0);

extern "C" u32 THISCALL lifted_4c18b0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x668dce);  // @h_4c18b0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4c18b0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4c18b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_4c18b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @3_4c18b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @4_4c18b0
  if (FL[0] == FL[1]) goto L4c1920;  // @5_4c18b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @6_4c18b0
  FL[3] = (eax & 0xff);  // @7_4c18b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(9);  // @8_4c18b0
  if (FL[0] != FL[1]) goto L4c1920;  // @9_4c18b0
  eax = ext_41e290_cdecl1((u32)(28));  // @10_4c18b0
  ecx = edx = 0;  // @11_4c18b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @12_4c18b0
  reg.state = (s32)((u32)(0));  // @13_4c18b0
  FL[2] = (eax & eax);  // @14_4c18b0
  if (FL[2] == 0) goto L4c190c;  // @15_4c18b0
  ecx = eax;  // @16_4c18b0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @17_4c18b0
  ecx = edx = 0;  // @18_4c18b0
  goto L4c190e;  // @19_4c18b0
  L4c190c:;
  eax = 0;  // @21_4c18b0
  FL[3] = eax;  // @22_4c18b0
  L4c190e:;
  PV[0] = (u32)(eax);  // @24_4c18b0
  ecx = edi;  // @25_4c18b0
  reg.state = (s32)((u32)(4294967295));  // @26_4c18b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @27_4c18b0
  eax = ext_4e6330_thiscall2(ecx, PV[0]);  // @28_4c18b0
  ecx = edx = 0;  // @29_4c18b0
  L4c1920:;
  ecx = edi;  // @31_4c18b0
  eax = ext_4e5e60_thiscall1(ecx);  // @32_4c18b0
  ecx = edx = 0;  // @33_4c18b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 113), &v, sizeof v); }  // @34_4c18b0
  FL[2] = (eax & eax);  // @35_4c18b0
  if (FL[2] == 0) goto L4c1970;  // @36_4c18b0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @37_4c18b0
  if (FL[0] != FL[1]) goto L4c1965;  // @38_4c18b0
  eax = ext_41e290_cdecl1((u32)(28));  // @39_4c18b0
  ecx = edx = 0;  // @40_4c18b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @41_4c18b0
  reg.state = (s32)((u32)(1));  // @42_4c18b0
  FL[2] = (eax & eax);  // @43_4c18b0
  if (FL[2] == 0) goto L4c1959;  // @44_4c18b0
  ecx = eax;  // @45_4c18b0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @46_4c18b0
  ecx = edx = 0;  // @47_4c18b0
  goto L4c195b;  // @48_4c18b0
  L4c1959:;
  eax = 0;  // @50_4c18b0
  FL[3] = eax;  // @51_4c18b0
  L4c195b:;
  reg.state = (s32)((u32)(4294967295));  // @53_4c18b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @54_4c18b0
  L4c1965:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 109), sizeof v); (u32)v; });  // @56_4c18b0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @57_4c18b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4c18b0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[1]);  // @59_4c18b0
  ecx = edx = 0;  // @60_4c18b0
  L4c1970:;
  ecx = edi;  // @62_4c18b0
  eax = ext_4e5e80_thiscall1(ecx);  // @63_4c18b0
  ecx = edx = 0;  // @64_4c18b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 121)) :: "st");  // @65_4c18b0
  ecx = edi;  // @66_4c18b0
  eax = ext_4e5e80_thiscall1(ecx);  // @67_4c18b0
  ecx = edx = 0;  // @68_4c18b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 161)) :: "st");  // @69_4c18b0
  ecx = edi;  // @70_4c18b0
  eax = ext_4e5e80_thiscall1(ecx);  // @71_4c18b0
  ecx = edx = 0;  // @72_4c18b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 165)) :: "st");  // @73_4c18b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @74_4c18b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @75_4c18b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @76_4c18b0
  if (FL[0] == FL[1]) goto L4c19af;  // @77_4c18b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @78_4c18b0
  FL[3] = (eax & 0xff);  // @79_4c18b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @80_4c18b0
  if (FL[0] != FL[1]) goto L4c19af;  // @81_4c18b0
  ecx = edi;  // @82_4c18b0
  eax = ext_4e5e80_thiscall1(ecx);  // @83_4c18b0
  ecx = edx = 0;  // @84_4c18b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 157)) :: "st");  // @85_4c18b0
  L4c19af:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 210), &v, sizeof v); }  // @87_4c18b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @88_4c18b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 214), &v, sizeof v); }  // @89_4c18b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 209), &v, sizeof v); }  // @90_4c18b0
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @91_4c18b0
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @92_4c18b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @93_4c18b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 141), &v, sizeof v); }  // @94_4c18b0
  SEH_LEAVE();  // @95_4c18b0
  return eax;  // @96_4c18b0
}
PCREG(4c18b0, lifted_4c18b0);

extern "C" u32 THISCALL lifted_471300(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_471300
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_471300
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @2_471300
  if (FL[0] == FL[1]) goto L47138a;  // @3_471300
  FL[0] = edi; FL[1] = (u32)(6);  // @4_471300
  if (FL[0] > FL[1]) goto L471483;  // @5_471300
  switch (edi) {  // @6_471300
  case 0: goto L4713f0;  // @7_471300
  case 1: goto L471457;  // @8_471300
  case 2: goto L471457;  // @9_471300
  case 3: goto L47131f;  // @10_471300
  case 4: goto L471483;  // @11_471300
  case 5: goto L4713b5;  // @12_471300
  case 6: goto L4713cf;  // @13_471300
  default: __builtin_trap(); }  // @14_471300
  L47131f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 876), sizeof v); (u32)v; });  // @17_471300
  eax = ((u32(STDCALL *)(void))(eax))();  // @18_471300
  ecx = edx = 0;  // @19_471300
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @20_471300
  if (FL[2] == 0) goto L471392;  // @21_471300
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 202), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @22_471300
  if (FL[0] != FL[1]) goto L471350;  // @23_471300
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 203), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @24_471300
  if (FL[0] != FL[1]) goto L471350;  // @25_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_471300
  ecx = esi;  // @27_471300
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 202), &v, sizeof v); }  // @28_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 904)))(ecx);  // @29_471300
  ecx = edx = 0;  // @30_471300
  L471350:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @32_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @33_471300
  eax = (eax >> (u32)(10));  // @34_471300
  FL[3] = eax;  // @35_471300
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @36_471300
  FL[2] = ((eax & 0xff) & (u32)(1));  // @37_471300
  if (FL[2] != 0) goto L471387;  // @38_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_471300
  ecx = esi;  // @40_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @41_471300
  ecx = edx = 0;  // @42_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_471300
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 237), sizeof v); (u32)v; });  // @44_471300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @45_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_471300
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @47_471300
  ecx = edx = 0;  // @48_471300
  FL[2] = (eax & eax);  // @49_471300
  if (FL[2] == 0) goto L471387;  // @50_471300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_471300
  ecx = eax;  // @52_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 40)))(ecx);  // @53_471300
  ecx = edx = 0;  // @54_471300
  L471387:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @56_471300
  L47138a:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @58_471300
  return eax;  // @59_471300
  L471392:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @61_471300
  ecx = esi;  // @62_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 848)))(ecx);  // @63_471300
  ecx = edx = 0;  // @64_471300
  ecx = eax;  // @65_471300
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @66_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 812), sizeof v); (u32)v; });  // @67_471300
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @68_471300
  ecx = edx = 0;  // @69_471300
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @70_471300
  if (FL[2] != 0) goto L471350;  // @71_471300
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 203), &v, sizeof v); }  // @72_471300
  goto L471350;  // @73_471300
  L4713b5:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @75_471300
  if (FL[0] != FL[1]) goto L471350;  // @76_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @77_471300
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 200), &v, sizeof v); }  // @78_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 888)))(ecx);  // @79_471300
  ecx = edx = 0;  // @80_471300
  goto L471350;  // @81_471300
  L4713cf:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 201), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @83_471300
  if (FL[0] != FL[1]) goto L471350;  // @84_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_471300
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 201), &v, sizeof v); }  // @86_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 896)))(ecx);  // @87_471300
  ecx = edx = 0;  // @88_471300
  goto L471350;  // @89_471300
  L4713f0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 203), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @91_471300
  if (FL[0] == FL[1]) goto L471402;  // @92_471300
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 203), &v, sizeof v); }  // @93_471300
  goto L47141a;  // @94_471300
  L471402:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 202), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_471300
  if (FL[0] == FL[1]) goto L47141a;  // @97_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_471300
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 202), &v, sizeof v); }  // @99_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 908)))(ecx);  // @100_471300
  ecx = edx = 0;  // @101_471300
  L47141a:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @103_471300
  if (FL[0] == FL[1]) goto L471434;  // @104_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_471300
  ecx = esi;  // @106_471300
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 200), &v, sizeof v); }  // @107_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 892)))(ecx);  // @108_471300
  ecx = edx = 0;  // @109_471300
  L471434:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 201), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @111_471300
  if (FL[0] == FL[1]) goto L471350;  // @112_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @113_471300
  ecx = esi;  // @114_471300
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 201), &v, sizeof v); }  // @115_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 900)))(ecx);  // @116_471300
  ecx = edx = 0;  // @117_471300
  goto L471350;  // @118_471300
  L471457:;
  FL[0] = edi; FL[1] = (u32)(1);  // @120_471300
  if (FL[0] != FL[1]) goto L471350;  // @121_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @122_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @123_471300
  eax = (eax >> (u32)(10));  // @124_471300
  FL[3] = eax;  // @125_471300
  eax = (eax & 0xffffff00u) | (((~(eax & 0xff))) & 0xff);  // @126_471300
  FL[2] = ((eax & 0xff) & (u32)(1));  // @127_471300
  if (FL[2] == 0) goto L471387;  // @128_471300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_471300
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @130_471300
  ecx = edx = 0;  // @131_471300
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @132_471300
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @133_471300
  return eax;  // @134_471300
  L471483:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @136_471300
  FL[2] = (eax & eax);  // @137_471300
  if (FL[2] == 0) goto L47149f;  // @138_471300
  eax = ((u32(STDCALL *)(void))(eax))();  // @139_471300
  ecx = edx = 0;  // @140_471300
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @141_471300
  ecx = esi;  // @142_471300
  PV[2] = (u32)(edi);  // @143_471300
  eax = ext_4711f0_thiscall3(ecx, PV[2], PV[1]);   // hand fix: ecx = this (esi) was dropped  // @144_471300
  ecx = edx = 0;  // @145_471300
  return eax;  // @146_471300
  L47149f:;
  __builtin_trap();  // @148_471300
}
PCREG(471300, lifted_471300);

