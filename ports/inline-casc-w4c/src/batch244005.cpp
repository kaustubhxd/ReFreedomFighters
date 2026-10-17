// batch244005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_65f690_fastcall3(u32, u32, u32) __asm__("ext_65f690");
extern "C" u32 FASTCALL ext_6604c0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_6604c0");
extern "C" u32 STDCALL ext_65a630_stdcall5(u32, u32, u32, u32, u32) __asm__("ext_65a630");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_533c60(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_533c60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32796), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_533c60
  if (FL[0] == FL[1]) goto L533cb7;  // @2_533c60
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775012), sizeof v); (u32)v; });  // @3_533c60
  L533c77:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_533c60
  ecx = esi;  // @6_533c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 56), sizeof v); (u32)v; });  // @7_533c60
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @8_533c60
  ecx = edx = 0;  // @9_533c60
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @10_533c60
  if (FL[2] == 0) goto L533c92;  // @11_533c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @12_533c60
  ecx = esi;  // @13_533c60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 108)))(ecx);  // @14_533c60
  ecx = edx = 0;  // @15_533c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_533c60
  ecx = esi;  // @17_533c60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 60)))(ecx);  // @18_533c60
  ecx = edx = 0;  // @19_533c60
  L533c92:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32796), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @21_533c60
  if (FL[0] == FL[1]) goto L533caf;  // @22_533c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_533c60
  ecx = esi;  // @24_533c60
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 112)))(ecx);  // @25_533c60
  ecx = edx = 0;  // @26_533c60
  eax = ((u32(STDCALL *)(u32))(edi))((u32)(15));  // @27_533c60
  ecx = edx = 0;  // @28_533c60
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32796), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @29_533c60
  if (FL[0] != FL[1]) goto L533c77;  // @30_533c60
  L533caf:;
  eax = 0;  // @32_533c60
  FL[3] = eax;  // @33_533c60
  return eax;  // @34_533c60
  L533cb7:;
  eax = 0;  // @36_533c60
  FL[3] = eax;  // @37_533c60
  return eax;  // @38_533c60
}
PCREG(533c60, lifted_533c60);

extern "C" u32 THISCALL lifted_537fd0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_537fd0
  edi = ecx;  // @1_537fd0
  FL[0] = esi; FL[1] = (u32)(2147483648);  // @2_537fd0
  if (FL[0] == FL[1]) goto L538036;  // @3_537fd0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_537fd0
  L537fe6:;
  FL[2] = (esi & esi);  // @6_537fd0
  if (FL[2] == 0) goto L537ffd;  // @7_537fd0
  FL[0] = esi; FL[1] = (u32)(2147483648);  // @8_537fd0
  if (FL[0] == FL[1]) goto L537ffd;  // @9_537fd0
  edx = (u32)(edi + 4263);  // @10_537fd0
  edx = (u32)(edx + esi*8);  // @11_537fd0
  goto L537fff;  // @12_537fd0
  L537ffd:;
  edx = 0;  // @14_537fd0
  FL[3] = edx;  // @15_537fd0
  L537fff:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_537fd0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @18_537fd0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @19_537fd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_537fd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_537fd0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @22_537fd0
  ecx = edx = 0;  // @23_537fd0
  FL[2] = (eax & eax);  // @24_537fd0
  if (FL[2] == 0) goto L53802d;  // @25_537fd0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20647), sizeof v); (u32)v; });  // @26_537fd0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @27_537fd0
  PV[1] = (u32)(ebx);  // @28_537fd0
  PV[2] = (u32)(ecx);  // @29_537fd0
  ecx = eax;  // @30_537fd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[2], PV[1], (u32)(0));  // @31_537fd0
  ecx = edx = 0;  // @32_537fd0
  L53802d:;
  FL[0] = esi; FL[1] = (u32)(2147483648);  // @34_537fd0
  if (FL[0] != FL[1]) goto L537fe6;  // @35_537fd0
  L538036:;
  return eax;  // @37_537fd0
}
PCREG(537fd0, lifted_537fd0);

extern "C" u32 FASTCALL lifted_660c00(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_660c00
  ebx = ecx;  // @1_660c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_660c00
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @3_660c00
  edi = edx;  // @4_660c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_660c00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @6_660c00
  PV[2] = (u32)(esi);  // @7_660c00
  eax = ext_6604c0_fastcall5(ecx, edx, PV[2], PV[1], PV[0]);  // @8_660c00
  ecx = edx = 0;  // @9_660c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @10_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @11_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @12_660c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(8471088), &v, sizeof v); }  // @13_660c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(8471092), &v, sizeof v); }  // @14_660c00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(8471096), &v, sizeof v); }  // @15_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(8471100), &v, sizeof v); }  // @16_660c00
  FL[2] = (edi & edi);  // @17_660c00
  if ((s32)FL[2] <= 0) goto L660c79;  // @18_660c00
  ecx = (u32)(83);  // @19_660c00
  L660c57:;
  FL[0] = edi; FL[1] = (u32)(83);  // @21_660c00
  esi = edi;  // @22_660c00
  edx = ebx;  // @23_660c00
  if ((s32)FL[0] > (s32)FL[1]) esi = ecx;  // @24_660c00
  ecx = eax;  // @25_660c00
  PV[3] = (u32)(esi);  // @26_660c00
  eax = ext_65f690_fastcall3(ecx, edx, PV[3]);  // @27_660c00
  ecx = edx = 0;  // @28_660c00
  edi = (edi - esi);  // @29_660c00
  FL[3] = edi;  // @30_660c00
  ecx = (u32)(83);  // @31_660c00
  esi = (esi << (u32)(6));  // @32_660c00
  FL[3] = esi;  // @33_660c00
  ebx = (ebx + esi);  // @34_660c00
  FL[3] = ebx;  // @35_660c00
  FL[2] = (edi & edi);  // @36_660c00
  if ((s32)FL[2] > 0) goto L660c57;  // @37_660c00
  L660c79:;
  return eax;  // @39_660c00
}
PCREG(660c00, lifted_660c00);

extern "C" u32 THISCALL lifted_65bc00(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
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
  ebx = ecx;  // @0_65bc00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_65bc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @2_65bc00
  FL[2] = (u32)(s32)(s8)(ecx & 0xff);  // @3_65bc00 (w4c: sign-extend the byte before the signed jump; the lifter left it zero-extended)
  if ((s32)FL[2] < 0) goto L65bc22;  // @4_65bc00
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_65bc00
  ecx = ebx;  // @6_65bc00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_65bc00
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_65bc00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[2], PV[1], PV[0]);  // @9_65bc00
  ecx = edx = 0;  // @10_65bc00
  return eax;  // @11_65bc00
  L65bc22:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @13_65bc00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @14_65bc00
  PV[3] = (u32)(ecx);  // @15_65bc00
  PV[4] = (u32)(edi);  // @16_65bc00
  PV[5] = (u32)(esi);  // @17_65bc00
  ecx = ebx;  // @18_65bc00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[5], PV[4], PV[3]);  // @19_65bc00
  ecx = edx = 0;  // @20_65bc00
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @21_65bc00
  ecx = ebx;  // @22_65bc00
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @23_65bc00
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @24_65bc00
  PV[9] = (u32)(edi);  // @25_65bc00
  PV[10] = (u32)(esi);  // @26_65bc00
  eax = ext_65a630_stdcall5(PV[10], PV[9], PV[8], PV[7], PV[6]);  // @27_65bc00
  ecx = edx = 0;  // @28_65bc00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @29_65bc00
  ecx = ebx;  // @30_65bc00
  PV[11] = (u32)(edi);  // @31_65bc00
  PV[12] = (u32)(esi);  // @32_65bc00
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @33_65bc00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, PV[13], PV[12], PV[11]);  // @34_65bc00
  ecx = edx = 0;  // @35_65bc00
  return eax;  // @36_65bc00
}
PCREG(65bc00, lifted_65bc00);

