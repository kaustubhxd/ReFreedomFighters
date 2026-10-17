// batch236001.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_5a7530_fastcall3(u32, u32, u32) __asm__("ext_5a7530");
extern "C" u32 FASTCALL ext_5f1050_fastcall6(u32, u32, u32, u32, u32, u32) __asm__("ext_5f1050");
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
extern "C" u32 THISCALL ext_591b20_thiscall1(u32) __asm__("ext_591b20");
extern "C" u32 THISCALL ext_5cc880_thiscall2(u32, u32) __asm__("ext_5cc880");
extern "C" u32 THISCALL ext_5d11c0_thiscall1(u32) __asm__("ext_5d11c0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5fba50(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5fba50
  edx = ebx;  // @1_5fba50
  edi = ecx;  // @2_5fba50
  ecx = (u32)(edx + 1);  // @3_5fba50
  L5fba60:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @5_5fba50
  edx = (edx + 1);  // @6_5fba50
  FL[3] = edx;  // @7_5fba50
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @8_5fba50
  if (FL[2] != 0) goto L5fba60;  // @9_5fba50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @10_5fba50
  edx = (edx - ecx);  // @11_5fba50
  FL[3] = edx;  // @12_5fba50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_5fba50
  esi = (esi - ecx);  // @14_5fba50
  FL[3] = esi;  // @15_5fba50
  FL[0] = esi; FL[1] = (u32)(1);  // @16_5fba50
  if (FL[0] < FL[1]) goto L5fbaa8;  // @17_5fba50
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @18_5fba50
  esi = (esi - 1);  // @19_5fba50
  FL[3] = esi;  // @20_5fba50
  eax = (u32)(ecx + 1);  // @21_5fba50
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = esi;  // @22_5fba50
  if (FL[0] < FL[1]) esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @23_5fba50
  eax = (eax + esi);  // @24_5fba50
  FL[3] = eax;  // @25_5fba50
  esi = (u32)(edx + ebx);  // @26_5fba50
  PV[1] = (u32)(esi);  // @27_5fba50
  PV[2] = (u32)(ecx);  // @28_5fba50
  PV[3] = (u32)(eax);  // @29_5fba50
  edx = ebx;  // @30_5fba50
  ecx = (u32)(EBP + 8);  // @31_5fba50
  eax = ext_5f1050_fastcall6(ecx, edx, PV[3], PV[2], PV[1], PV[0]);  // @32_5fba50
  ecx = edx = 0;  // @33_5fba50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_5fba50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @35_5fba50
  FL[0] = eax; FL[1] = ecx;  // @36_5fba50
  if (FL[0] == FL[1]) goto L5fbaa8;  // @37_5fba50
  eax = (eax - ecx);  // @38_5fba50
  FL[3] = eax;  // @39_5fba50
  eax = (eax - 1);  // @40_5fba50
  FL[3] = eax;  // @41_5fba50
  return eax;  // @42_5fba50
  L5fbaa8:;
  eax = (eax | (u32)(4294967295));  // @44_5fba50
  FL[3] = eax;  // @45_5fba50
  return eax;  // @46_5fba50
}
PCREG(5fba50, lifted_5fba50);

extern "C" u32 THISCALL lifted_601720(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_601720
  esi = 0;  // @1_601720
  FL[3] = esi;  // @2_601720
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }); FL[1] = esi;  // @3_601720
  if (FL[0] <= FL[1]) goto L601784;  // @4_601720
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_601720
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @6_601720
  if (FL[0] < FL[1]) goto L601745;  // @7_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @8_601720
  FL[2] = (eax & eax);  // @9_601720
  if (FL[2] == 0) goto L601744;  // @10_601720
  eax = ((u32(STDCALL *)(void))(eax))();  // @11_601720
  ecx = edx = 0;  // @12_601720
  goto L601745;  // @13_601720
  L601744:;
  __builtin_trap();  // @15_601720
  L601745:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @17_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @18_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @19_601720
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @20_601720
  if (FL[0] != FL[1]) goto L60177e;  // @21_601720
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @22_601720
  if (FL[0] < FL[1]) goto L601765;  // @23_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @24_601720
  FL[2] = (eax & eax);  // @25_601720
  if (FL[2] == 0) goto L601764;  // @26_601720
  eax = ((u32(STDCALL *)(void))(eax))();  // @27_601720
  ecx = edx = 0;  // @28_601720
  goto L601765;  // @29_601720
  L601764:;
  __builtin_trap();  // @31_601720
  L601765:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @33_601720
  PV[0] = (u32)(ebx);  // @34_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @35_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_601720
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @37_601720
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676414))(PV[1], PV[0]);  // @38_601720
  ecx = edx = 0;  // @39_601720
  FL[2] = (eax & eax);  // @40_601720
  if (FL[2] == 0) goto L60178d;  // @41_601720
  L60177e:;
  esi = (esi + 1);  // @43_601720
  FL[3] = esi;  // @44_601720
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @45_601720
  if (FL[0] < FL[1]) goto L601745;  // @46_601720
  L601784:;
  eax = 0;  // @48_601720
  FL[3] = eax;  // @49_601720
  return eax;  // @50_601720
  L60178d:;
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @52_601720
  if (FL[0] < FL[1]) goto L6017b0;  // @53_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @54_601720
  FL[2] = (eax & eax);  // @55_601720
  if (FL[2] == 0) goto L6017af;  // @56_601720
  eax = ((u32(STDCALL *)(void))(eax))();  // @57_601720
  ecx = edx = 0;  // @58_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @59_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @60_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @61_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @62_601720
  return eax;  // @63_601720
  L6017af:;
  __builtin_trap();  // @65_601720
  L6017b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @67_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi*4), sizeof v); (u32)v; });  // @68_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @69_601720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @70_601720
  return eax;  // @71_601720
}
PCREG(601720, lifted_601720);

extern "C" u32 THISCALL lifted_509b10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_509b10
  edi = ecx;  // @1_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @2_509b10
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @3_509b10
  ecx = edx = 0;  // @4_509b10
  edx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @5_509b10
  edx = (edx - (u32)(3));  // @6_509b10
  FL[3] = edx;  // @7_509b10
  if (FL[3] == 0) goto L509b7a;  // @8_509b10
  edx = (edx - (u32)(1));  // @9_509b10
  FL[3] = edx;  // @10_509b10
  if (FL[3] == 0) goto L509b71;  // @11_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @12_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_509b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(273));  // @14_509b10
  ecx = edx = 0;  // @15_509b10
  PV[0] = (u32)(eax);  // @16_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @17_509b10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932912));  // @18_509b10
  ecx = edx = 0;  // @19_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @20_509b10
  FL[2] = (eax & eax);  // @21_509b10
  if (FL[2] == 0) goto L509b6c;  // @22_509b10
  eax = ((u32(STDCALL *)(void))(eax))();  // @23_509b10
  ecx = edx = 0;  // @24_509b10
  eax = 0;  // @25_509b10
  FL[3] = eax;  // @26_509b10
  goto L509b7c;  // @27_509b10
  L509b6c:;
  __builtin_trap();  // @29_509b10
  L509b71:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @31_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_509b10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @33_509b10
  ecx = edx = 0;  // @34_509b10
  goto L509b7c;  // @35_509b10
  L509b7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @37_509b10
  L509b7c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @39_509b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @40_509b10
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @41_509b10
  ecx = edx = 0;  // @42_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @43_509b10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @44_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @45_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @46_509b10
  FL[2] = (ecx & ecx);  // @47_509b10
  if (FL[2] == 0) goto L509c13;  // @48_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_509b10
  edx = (u32)(EBP - 20);  // @50_509b10
  PV[1] = (u32)(edx);  // @51_509b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @52_509b10
  ecx = edx = 0;  // @53_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @54_509b10
  edx = (u32)(EBP - 20);  // @55_509b10
  PV[2] = (u32)(edx);  // @56_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @57_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_509b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[2]);  // @59_509b10
  ecx = edx = 0;  // @60_509b10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @61_509b10
  ebx = eax;  // @62_509b10
  if (FL[0] == FL[1]) goto L509c12;  // @63_509b10
  L509bc0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @65_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_509b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @67_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_509b10
  eax = (u32)(EBP - 8);  // @69_509b10
  PV[3] = (u32)(eax);  // @70_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_509b10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6900844), (u32)(0), (u32)(6935060), (u32)(208), PV[3]);  // @72_509b10
  ecx = edx = 0;  // @73_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @74_509b10
  eax = (eax & 0xffff);  // @75_509b10
  PV[4] = (u32)(eax);  // @76_509b10
  PV[5] = (u32)(ebx);  // @77_509b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 300)))(ecx, PV[5], PV[4]);  // @78_509b10
  ecx = edx = 0;  // @79_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @80_509b10
  edx = (u32)(EBP - 20);  // @81_509b10
  PV[6] = (u32)(edx);  // @82_509b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @83_509b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_509b10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @85_509b10
  ecx = edx = 0;  // @86_509b10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @87_509b10
  ebx = eax;  // @88_509b10
  if (FL[0] != FL[1]) goto L509bc0;  // @89_509b10
  L509c12:;
  L509c13:;
  return eax;  // @92_509b10
}
PCREG(509b10, lifted_509b10);

extern "C" u32 THISCALL lifted_4a01c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_4a01c0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 94), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_4a01c0
  if (FL[0] == FL[1]) goto L4a02d0;  // @2_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_4a01c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_4a01c0
  PV[0] = (u32)(ebx);  // @6_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @8_4a01c0
  ecx = edx = 0;  // @9_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @10_4a01c0
  ecx = 0;  // @11_4a01c0
  FL[3] = ecx;  // @12_4a01c0
  FL[2] = (esi & esi);  // @13_4a01c0
  if (FL[2] == 0) goto L4a02ce;  // @14_4a01c0
  edx = (u32)(edi + 110);  // @15_4a01c0
  L4a01f7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = eax;  // @17_4a01c0
  if (FL[0] == FL[1]) goto L4a020c;  // @18_4a01c0
  ecx = (ecx + 1);  // @19_4a01c0
  FL[3] = ecx;  // @20_4a01c0
  edx = (edx + (u32)(4));  // @21_4a01c0
  FL[3] = edx;  // @22_4a01c0
  FL[0] = ecx; FL[1] = esi;  // @23_4a01c0
  if (FL[0] != FL[1]) goto L4a01f7;  // @24_4a01c0
  return eax;  // @25_4a01c0
  L4a020c:;
  FL[0] = ecx; FL[1] = (u32)(-1);  // @27_4a01c0
  if (FL[0] == FL[1]) goto L4a02ce;  // @28_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_4a01c0
  PV[1] = (u32)(ebx);  // @30_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[1]);  // @33_4a01c0
  ecx = edx = 0;  // @34_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @35_4a01c0
  ecx = 0;  // @36_4a01c0
  FL[3] = ecx;  // @37_4a01c0
  ebx = eax;  // @38_4a01c0
  FL[2] = (esi & esi);  // @39_4a01c0
  if (FL[2] == 0) goto L4a0255;  // @40_4a01c0
  edx = (u32)(edi + 110);  // @41_4a01c0
  L4a0234:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = ebx;  // @43_4a01c0
  if (FL[0] == FL[1]) goto L4a0242;  // @44_4a01c0
  ecx = (ecx + 1);  // @45_4a01c0
  FL[3] = ecx;  // @46_4a01c0
  edx = (edx + (u32)(4));  // @47_4a01c0
  FL[3] = edx;  // @48_4a01c0
  FL[0] = ecx; FL[1] = esi;  // @49_4a01c0
  if (FL[0] != FL[1]) goto L4a0234;  // @50_4a01c0
  goto L4a0255;  // @51_4a01c0
  L4a0242:;
  FL[0] = ecx; FL[1] = (u32)(-1);  // @53_4a01c0
  if (FL[0] == FL[1]) goto L4a0255;  // @54_4a01c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 106), &v, sizeof v); }  // @55_4a01c0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @56_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 106), sizeof v); (u32)v; });  // @57_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + eax*4 + 110), sizeof v); (u32)v; });  // @58_4a01c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + ecx*4 + 110), &v, sizeof v); }  // @59_4a01c0
  L4a0255:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @62_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_4a01c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @64_4a01c0
  ecx = edx = 0;  // @65_4a01c0
  ecx = (u32)(EBP - 4);  // @66_4a01c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @67_4a01c0
  PV[2] = (u32)(ecx);  // @68_4a01c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @69_4a01c0
  ecx = eax;  // @70_4a01c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6820640), PV[2]);  // @71_4a01c0
  ecx = edx = 0;  // @72_4a01c0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @73_4a01c0
  if (FL[0] != FL[1]) goto L4a02a3;  // @74_4a01c0
  ecx = 0;  // @75_4a01c0
  FL[3] = ecx;  // @76_4a01c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; }); FL[1] = ecx;  // @77_4a01c0
  if (FL[0] == FL[1]) goto L4a02a3;  // @78_4a01c0
  edx = (u32)(edi + 130);  // @79_4a01c0
  L4a0294:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @81_4a01c0
  edx = (u32)(edx + 4);  // @82_4a01c0
  ecx = (ecx + 1);  // @83_4a01c0
  FL[3] = ecx;  // @84_4a01c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; }) | (u32)(2))); __builtin_memcpy((void *)(u32)(eax + 90), &v, sizeof v); }  // @85_4a01c0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @86_4a01c0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 126), sizeof v); (u32)v; });  // @87_4a01c0
  if (FL[0] != FL[1]) goto L4a0294;  // @88_4a01c0
  L4a02a3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_4a01c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @91_4a01c0
  PV[3] = (u32)(edx);  // @92_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @93_4a01c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @94_4a01c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_4a01c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[3]);  // @96_4a01c0
  ecx = edx = 0;  // @97_4a01c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @98_4a01c0
  PV[4] = (u32)(eax);  // @99_4a01c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(7340740), sizeof v); (u32)v; });  // @100_4a01c0
  PV[5] = (u32)(eax);  // @101_4a01c0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @102_4a01c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, PV[6], PV[5], PV[4]);  // @103_4a01c0
  ecx = edx = 0;  // @104_4a01c0
  L4a02ce:;
  L4a02d0:;
  return eax;  // @107_4a01c0
}
PCREG(4a01c0, lifted_4a01c0);

// w3h hand port of 0x5d2eb0 (the lifter mishandles the shared `push N; jmp L; L: call` tails of the two switches)
extern "C" u32 THISCALL ext_5a7530_t1(u32, u32) __asm__("ext_5a7530");
extern "C" u32 THISCALL ext_5cc880_t1(u32, u32) __asm__("ext_5cc880");
extern "C" u32 THISCALL ext_5d11c0_t0(u32) __asm__("ext_5d11c0");
extern "C" u32 THISCALL ext_591b20_t0(u32) __asm__("ext_591b20");
static inline u32 w3h_r32(u32 a) { u32 v; __builtin_memcpy(&v, (void *)a, 4); return v; }
static inline void w3h_w32(u32 a, u32 v) { __builtin_memcpy((void *)a, &v, 4); }
static inline u32 w3h_r8(u32 a) { return *(volatile u8 *)a; }
static inline void w3h_w8(u32 a, u32 v) { *(volatile u8 *)a = (u8)v; }
extern "C" u32 THISCALL lifted_5d2eb0(u32 t) {
  u32 flag = 0, bl = 0;
#define A_(x) ext_5a7530_t1(w3h_r32(t + 0xe18), (x))
#define FL_(b01, add, af9, afd) w3h_w32(t + 0xb01, b01); w3h_w32(t + 0xadd, add); w3h_w32(t + 0xaf9, af9); w3h_w32(t + 0xafd, afd)
#define FA_(a96, a9a, a9e, aa2) w3h_w32(t + 0xa96, a96); w3h_w32(t + 0xa9a, a9a); w3h_w32(t + 0xa9e, a9e); w3h_w32(t + 0xaa2, aa2)
#define VT58_() { u32 g_ = w3h_r32(w3h_r32(0x70039c) + 0x9b); ((u32(THISCALL *)(u32, u32))(w3h_r32(w3h_r32(g_) + 0x58)))(g_, w3h_r32(t + 0xd0d)); }
  if (w3h_r32(t + 0xe18) == 0) {
    u32 q = w3h_r32(w3h_r32(t + 0x44) + 0x852);
    if (q) w3h_w32(t + 0xe18, w3h_r32(q + 0x1d0f));
    if (w3h_r32(t + 0xe18) == 0) {
      u32 e = w3h_r32(0x700390);
      u32 l = ((u32(THISCALL *)(u32, u32, u32))(w3h_r32(w3h_r32(e) + 0x20)))(e, 0x6b4e78, 0x156);
      return ((u32(*)(u32, u32))(w3h_r32(w3h_r32(l) + 0x30)))(l, 0x6b4f30);
    }
  }
  w3h_w32(w3h_r32(t + 0xb54) + 0x4dc, w3h_r32(t + 0xad5));
  w3h_w32(t + 0xdfd, 0x453b8000);
  w3h_w32(t + 0xe01, 0x4b095440);
  if (w3h_r32(t + 0xa4c) == 1) w3h_w32(t + 0xdf9, 0x3fc90fdb);
  else w3h_w32(t + 0xdf9, w3h_r32(t + 0xdf5));
  if (w3h_r8(t + 0xb45) != 0) {
    u32 v = w3h_r32(t + 0xad5);
    flag = 1; w3h_w8(t + 0xd32, 0);
    FL_(0x3e99999a, 0x3e800000, 0x3e860a92, 0x3dfa35dd);
    FA_(0xbfa78d36, 0x3fa78d36, 0xbfa78d36, 0x3fa78d36);
    if (v <= 0xc) {
      switch (v) {
      case 0: A_(0); break;
      case 1: A_(1); break;
      case 2: A_(3); break;
      case 3: A_(0x12); break;
      case 4: FL_(0x3f800000, 0x3dcccccd, 0, 0); A_(0x10); break;
      case 5: ext_5cc880_t1(w3h_r32(t + 0xb54), 0); break;
      case 6: A_(5); break;
      case 7: A_(7); break;
      case 8: A_(9); break;
      case 9:
        if (!(ext_5d11c0_t0(t) & 0xff)) { A_(0); break; }
        VT58_();
        A_(0);
        break;
      case 10: {
        ext_5cc880_t1(w3h_r32(t + 0xb54), 0);
        u32 e = w3h_r32(0x700390);
        u32 l = ((u32(THISCALL *)(u32, u32, u32))(w3h_r32(w3h_r32(e) + 0x20)))(e, 0x6b4e78, 0x1bd);
        ((u32(*)(u32, u32))(w3h_r32(w3h_r32(l) + 0x2c)))(l, 0x6b4f64);
        u32 as = w3h_r32(0x7003b0);
        if (as) ((u32(STDCALL *)(void))as)(); else __builtin_trap();
        break;
      }
      case 11: A_(0xd); break;
      case 12: FL_(0x3f800000, 0x3e800000, 0, 0); A_(0x11); break;
      }
    }
  } else {
    u32 p = w3h_r32(t + 0x44);
    w3h_w8(t + 0xd32, 1);
    bl = (w3h_r8(p + 0x67a) != 0);
    if (w3h_r32(t + 0xe1c) == 3) { bl = 1; w3h_w8(t + 0xd32, 0); }
    u32 ec = w3h_r32(t + 0xe18);
    w3h_w32(t + 0xadd, 0x3f800000); w3h_w32(t + 0xb01, 0x3f800000); w3h_w32(t + 0xaf9, 0); w3h_w32(t + 0xafd, 0);
    FA_(0xbf9c61aa, 0x3f860a92, 0xbf9c61aa, 0x3f860a92);
    ext_5a7530_t1(ec, 0);
    u32 v = w3h_r32(t + 0xad5);
    if (v <= 9) {
      switch (v) {
      case 0: A_(0); break;
      case 1: if (bl & 0xff) A_(1); break;
      case 2: case 4: if (bl & 0xff) A_(3); break;
      case 3: if (bl & 0xff) A_(0x12); break;
      case 5:
        flag = 1; w3h_w8(t + 0xd32, 0);
        FL_(0x3e99999a, 0x3eb33333, 0x3e860a92, 0x3dfa35dd);
        FA_(0xbfa78d36, 0x3fa78d36, 0xbfa78d36, 0x3fa78d36);
        A_(5); break;
      case 6: if (bl & 0xff) A_(5); break;
      case 7: w3h_w8(t + 0xd32, 0); A_(7); break;
      case 8: if (bl & 0xff) A_(9); break;
      case 9:
        if (ext_5d11c0_t0(t) & 0xff) VT58_();
        A_(0);
        break;
      }
    }
  }
  ext_5cc880_t1(w3h_r32(t + 0xb54), (t & 0xffffff00u) | flag);   // `push ecx` slot [ebp-4]: only its low byte is the flag, the rest is `this`
  u32 r = ext_591b20_t0(w3h_r32(t + 0x44));
  if (r == 0xb) w3h_w8(t + 0xd32, 0);
  return r;
}
PCREG(5d2eb0, lifted_5d2eb0);

