// batch248003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4658d0_fastcall3(u32, u32, u32) __asm__("ext_4658d0");
extern "C" u32 THISCALL ext_465930_thiscall2(u32, u32) __asm__("ext_465930");
extern "C" u32 THISCALL ext_5acfe0_thiscall1(u32) __asm__("ext_5acfe0");
extern "C" u32 THISCALL ext_5adea0_thiscall1(u32) __asm__("ext_5adea0");
extern "C" u32 THISCALL ext_5ae450_thiscall2(u32, u32) __asm__("ext_5ae450");
extern "C" u32 THISCALL ext_5ae900_thiscall2(u32, u32) __asm__("ext_5ae900");
extern "C" u32 THISCALL ext_663190_thiscall1(u32) __asm__("ext_663190");
extern "C" u32 THISCALL ext_663680_thiscall1(u32) __asm__("ext_663680");
extern "C" u32 THISCALL ext_663b60_thiscall3(u32, u32, u32) __asm__("ext_663b60");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_663250(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_663250
  eax = (u32)(ecx + 74164);  // @1_663250
  esi = (u32)(EBP - 132);  // @2_663250
  esi = (esi - eax);  // @3_663250
  FL[3] = esi;  // @4_663250
  L663276:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @6_663250
  eax = (u32)(eax + 1);  // @7_663250
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + eax - 1), &v, sizeof v); }  // @8_663250
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @9_663250
  if (FL[2] != 0) goto L663276;  // @10_663250
  edi = (u32)(EBP - 132);  // @11_663250
  edi = (edi - 1);  // @12_663250
  FL[3] = edi;  // @13_663250
  L663290:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @15_663250
  edi = (u32)(edi + 1);  // @16_663250
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @17_663250
  if (FL[2] != 0) goto L663290;  // @18_663250
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6784364), sizeof v); (u32)v; })) & 0xffff);  // @19_663250
  esi = edx;  // @20_663250
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @21_663250
  L6632a5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @23_663250
  edx = (edx + 1);  // @24_663250
  FL[3] = edx;  // @25_663250
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @26_663250
  if (FL[2] != 0) goto L6632a5;  // @27_663250
  edi = (u32)(EBP - 132);  // @28_663250
  edx = (edx - esi);  // @29_663250
  FL[3] = edx;  // @30_663250
  edi = (edi - 1);  // @31_663250
  FL[3] = edi;  // @32_663250
  L6632b5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @34_663250
  edi = (edi + 1);  // @35_663250
  FL[3] = edi;  // @36_663250
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @37_663250
  if (FL[2] != 0) goto L6632b5;  // @38_663250
  ecx = edx;  // @39_663250
  ecx = (ecx >> (u32)(2));  // @40_663250
  FL[3] = ecx;  // @41_663250
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @42_663250
  ecx = edx;  // @43_663250
  edx = (u32)(EBP - 132);  // @44_663250
  ecx = (ecx & (u32)(3));  // @45_663250
  FL[3] = ecx;  // @46_663250
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @47_663250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @48_663250
  PV[0] = (u32)(edx);  // @49_663250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_663250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @51_663250
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[0]);  // @52_663250
  ecx = edx = 0;  // @53_663250
  ext_633654(G(u32, 0x6f5630));  // @54_663250
  return eax;  // @55_663250
}
PCREG(663250, lifted_663250);

extern "C" u32 THISCALL lifted_6638c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_6638c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_6638c0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @2_6638c0
  ecx = edx = 0;  // @3_6638c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_6638c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_6638c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_6638c0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @7_6638c0
  ecx = edx = 0;  // @8_6638c0
  ecx = (u32)(EBP - 4);  // @9_6638c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @10_6638c0
  PV[0] = (u32)(ecx);  // @11_6638c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_6638c0
  ecx = eax;  // @13_6638c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6973164), PV[0]);  // @14_6638c0
  ecx = edx = 0;  // @15_6638c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @16_6638c0
  if (FL[0] == FL[1]) goto L663967;  // @17_6638c0
  esi = (u32)(1);  // @18_6638c0
  L663930:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @20_6638c0
  PV[1] = (u32)(esi);  // @21_6638c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_6638c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 224)))(ecx, (u32)(1), PV[1]);  // @23_6638c0
  ecx = edx = 0;  // @24_6638c0
  FL[0] = eax; FL[1] = (u32)(-1);  // @25_6638c0
  if (FL[0] == FL[1]) goto L663955;  // @26_6638c0
  esi = (esi + 1);  // @27_6638c0
  FL[3] = esi;  // @28_6638c0
  FL[0] = esi; FL[1] = (u32)(4);  // @29_6638c0
  if ((s32)FL[0] < (s32)FL[1]) goto L663930;  // @30_6638c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @31_6638c0
  return eax;  // @32_6638c0
  L663955:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @34_6638c0
  { u32 v = (u32)((u32)(14)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @35_6638c0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @36_6638c0
  FL[3] = (eax & 0xff);  // @37_6638c0
  return eax;  // @38_6638c0
  L663967:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @40_6638c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_6638c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7097012), (u32)(75));  // @42_6638c0
  ecx = edx = 0;  // @43_6638c0
  PV[2] = (u32)(eax);  // @44_6638c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_6638c0
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(7097056));  // @46_6638c0
  ecx = edx = 0;  // @47_6638c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @48_6638c0
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @49_6638c0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @50_6638c0
  FL[3] = (eax & 0xff);  // @51_6638c0
  return eax;  // @52_6638c0
}
PCREG(6638c0, lifted_6638c0);

extern "C" u32 THISCALL lifted_663520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_663520
  esi = ecx;  // @1_663520
  if (FL[0] == FL[1]) goto L663573;  // @2_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @3_663520
  ebx = (u32)(esi + 74124);  // @4_663520
  ecx = ebx;  // @5_663520
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @6_663520
  ecx = edx = 0;  // @7_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @8_663520
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @11_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @12_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @14_663520
  ecx = edx = 0;  // @15_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @16_663520
  PV[0] = (u32)(eax);  // @17_663520
  PV[1] = (u32)(ebx);  // @18_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 308)))(ecx, PV[1], PV[0]);  // @19_663520
  ecx = edx = 0;  // @20_663520
  L663573:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @22_663520
  ecx = (u32)(esi + 74124);  // @23_663520
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @24_663520
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @25_663520
  ecx = edx = 0;  // @26_663520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @27_663520
  FL[2] = (eax & eax);  // @28_663520
  if ((s32)FL[2] <= 0) goto L6635e7;  // @29_663520
  edi = 0;  // @30_663520
  FL[3] = edi;  // @31_663520
  FL[2] = (eax & eax);  // @32_663520
  if ((s32)FL[2] <= 0) goto L6635e7;  // @33_663520
  L6635a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @35_663520
  ecx = (u32)(esi + 74124);  // @36_663520
  PV[2] = (u32)(edi);  // @37_663520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[2]);  // @38_663520
  ecx = edx = 0;  // @39_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; });  // @40_663520
  PV[3] = (u32)(eax);  // @41_663520
  eax = ext_5ae900_thiscall2(ecx, PV[3]);  // @42_663520
  ecx = edx = 0;  // @43_663520
  ecx = esi;  // @44_663520
  eax = ext_663680_thiscall1(ecx);  // @45_663520
  ecx = edx = 0;  // @46_663520
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @47_663520
  if (FL[2] == 0) goto L6635f8;  // @48_663520
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; });  // @49_663520
  ecx = (u32)(esi + 4);  // @50_663520
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; });  // @51_663520
  eax = ext_663b60_thiscall3(ecx, PV[5], PV[4]);  // @52_663520
  ecx = edx = 0;  // @53_663520
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @54_663520
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; });  // @55_663520
  edi = (edi + 1);  // @56_663520
  FL[3] = edi;  // @57_663520
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @58_663520
  if ((s32)FL[0] < (s32)FL[1]) goto L6635a0;  // @59_663520
  L6635e7:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @61_663520
  eax = (eax & 0xffffff00u) | ((((FL[0] != FL[1]) ? 1 : 0)) & 0xff);  // @62_663520
  return eax;  // @63_663520
  L6635f8:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @65_663520
  FL[3] = (eax & 0xff);  // @66_663520
  return eax;  // @67_663520
}
PCREG(663520, lifted_663520);

extern "C" u32 THISCALL lifted_663680(u32 ecx_in) {
  u8 F[0x610] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x510);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_663680
  edx = (u32)(EBP - 132);  // @1_663680
  eax = (u32)(ebx + 74164);  // @2_663680
  edx = (edx - eax);  // @3_663680
  FL[3] = edx;  // @4_663680
  L6636a6:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @6_663680
  eax = (u32)(eax + 1);  // @7_663680
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @8_663680
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @9_663680
  if (FL[2] != 0) goto L6636a6;  // @10_663680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73988), sizeof v); (u32)v; });  // @11_663680
  eax = ext_5adea0_thiscall1(ecx);  // @12_663680
    // @13_663680
  edx = eax;  // @14_663680
  esi = eax;  // @15_663680
  L6636c2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @17_663680
  edx = (edx + 1);  // @18_663680
  FL[3] = edx;  // @19_663680
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @20_663680
  if (FL[2] != 0) goto L6636c2;  // @21_663680
  edi = (u32)(EBP - 132);  // @22_663680
  edx = (edx - esi);  // @23_663680
  FL[3] = edx;  // @24_663680
  edi = (edi - 1);  // @25_663680
  FL[3] = edi;  // @26_663680
  L6636d2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @28_663680
  edi = (edi + 1);  // @29_663680
  FL[3] = edi;  // @30_663680
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @31_663680
  if (FL[2] != 0) goto L6636d2;  // @32_663680
  ecx = edx;  // @33_663680
  ecx = (ecx >> (u32)(2));  // @34_663680
  FL[3] = ecx;  // @35_663680
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @36_663680
  ecx = edx;  // @37_663680
  edx = (u32)(EBP - 132);  // @38_663680
  ecx = (ecx & (u32)(3));  // @39_663680
  FL[3] = ecx;  // @40_663680
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @41_663680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @42_663680
  PV[0] = (u32)(edx);  // @43_663680
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_663680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, PV[0]);  // @45_663680
  ecx = edx = 0;  // @46_663680
  edi = eax;  // @47_663680
  FL[2] = (edi & edi);  // @48_663680
  if (FL[2] == 0) goto L663753;  // @49_663680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @50_663680
  eax = (u32)(EBP - 1156);  // @51_663680
  PV[1] = (u32)(eax);  // @52_663680
  PV[2] = (u32)(edi);  // @53_663680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_663680
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[2], PV[1], (u32)(1024));  // @55_663680
  ecx = edx = 0;  // @56_663680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @57_663680
  esi = eax;  // @58_663680
  PV[3] = (u32)(edi);  // @59_663680
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_663680
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 28)))(ecx, PV[3]);  // @61_663680
  ecx = edx = 0;  // @62_663680
  FL[0] = esi; FL[1] = (u32)(1024);  // @63_663680
  if (FL[0] != FL[1]) goto L663753;  // @64_663680
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73988), sizeof v); (u32)v; });  // @65_663680
  eax = (u32)(EBP - 1156);  // @66_663680
  PV[4] = (u32)(eax);  // @67_663680
  eax = ext_5ae450_thiscall2(ecx, PV[4]);  // @68_663680
  ecx = edx = 0;  // @69_663680
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @70_663680
  ext_633654(G(u32, 0x6f5630));  // @71_663680
  return eax;  // @72_663680
  L663753:;
  ext_633654(G(u32, 0x6f5630));  // @74_663680
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @75_663680
  FL[3] = (eax & 0xff);  // @76_663680
  return eax;  // @77_663680
}
PCREG(663680, lifted_663680);

extern "C" u32 THISCALL lifted_663770(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_663770
  ebx = ecx;  // @1_663770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @2_663770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73988), sizeof v); (u32)v; });  // @3_663770
  ecx = (ecx + (u32)(858));  // @4_663770
  FL[3] = ecx;  // @5_663770
  eax = ext_5acfe0_thiscall1(ecx);  // @6_663770
    // @7_663770
  edx = (u32)(EBP - 132);  // @8_663770
  edx = (edx - eax);  // @9_663770
  FL[3] = edx;  // @10_663770
  L6637b0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @12_663770
  eax = (u32)(eax + 1);  // @13_663770
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @14_663770
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @15_663770
  if (FL[2] != 0) goto L6637b0;  // @16_663770
  ecx = (u32)(EBP - 132);  // @17_663770
  ecx = (ecx - 1);  // @18_663770
  FL[3] = ecx;  // @19_663770
  L6637c4:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @21_663770
  ecx = (u32)(ecx + 1);  // @22_663770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @23_663770
  if (FL[2] != 0) goto L6637c4;  // @24_663770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6786312), sizeof v); (u32)v; });  // @25_663770
  edx = (u32)(EBP - 260);  // @26_663770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @27_663770
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6786316), sizeof v); (u32)v; })) & 0xff);  // @28_663770
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @29_663770
  eax = (u32)(ebx + 74164);  // @30_663770
  edx = (edx - eax);  // @31_663770
  FL[3] = edx;  // @32_663770
  L6637f0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @34_663770
  eax = (u32)(eax + 1);  // @35_663770
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @36_663770
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @37_663770
  if (FL[2] != 0) goto L6637f0;  // @38_663770
  edx = (u32)(EBP - 132);  // @39_663770
  esi = edx;  // @40_663770
  L663807:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @42_663770
  edx = (edx + 1);  // @43_663770
  FL[3] = edx;  // @44_663770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @45_663770
  if (FL[2] != 0) goto L663807;  // @46_663770
  edi = (u32)(EBP - 260);  // @47_663770
  edx = (edx - esi);  // @48_663770
  FL[3] = edx;  // @49_663770
  edi = (edi - 1);  // @50_663770
  FL[3] = edi;  // @51_663770
  L663817:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @53_663770
  edi = (edi + 1);  // @54_663770
  FL[3] = edi;  // @55_663770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @56_663770
  if (FL[2] != 0) goto L663817;  // @57_663770
  ecx = edx;  // @58_663770
  eax = (u32)(EBP - 132);  // @59_663770
  ecx = (ecx >> (u32)(2));  // @60_663770
  FL[3] = ecx;  // @61_663770
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @62_663770
  ecx = edx;  // @63_663770
  ecx = (ecx & (u32)(3));  // @64_663770
  FL[3] = ecx;  // @65_663770
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @66_663770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73988), sizeof v); (u32)v; });  // @67_663770
  PV[0] = (u32)(eax);  // @68_663770
  eax = ext_5ae900_thiscall2(ecx, PV[0]);  // @69_663770
  ecx = edx = 0;  // @70_663770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @71_663770
  edx = (u32)(EBP - 260);  // @72_663770
  PV[1] = (u32)(edx);  // @73_663770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_663770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @75_663770
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[1], (u32)(0));  // @76_663770
  ecx = edx = 0;  // @77_663770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @78_663770
  if (FL[2] == 0) goto L66387a;  // @79_663770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @80_663770
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @81_663770
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @82_663770
  FL[3] = (eax & 0xff);  // @83_663770
  ext_633654(G(u32, 0x6f5630));  // @84_663770
  return eax;  // @85_663770
  L66387a:;
  ecx = ebx;  // @87_663770
  eax = ext_663190_thiscall1(ecx);  // @88_663770
  ecx = edx = 0;  // @89_663770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @90_663770
  if (FL[2] != 0) goto L6638a4;  // @91_663770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @92_663770
  { u32 v = (u32)((u32)(18)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @93_663770
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @94_663770
  FL[3] = (eax & 0xff);  // @95_663770
  ext_633654(G(u32, 0x6f5630));  // @96_663770
  return eax;  // @97_663770
  L6638a4:;
  ext_633654(G(u32, 0x6f5630));  // @99_663770
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @100_663770
  return eax;  // @101_663770
}
PCREG(663770, lifted_663770);

extern "C" u32 THISCALL lifted_467410(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_467410
  esi = ecx;  // @1_467410
  eax = ext_4658d0_fastcall3(ecx, edx, PV[0]);  // @2_467410
  ecx = edx = 0;  // @3_467410
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 12) + 0), 4); v; });  // @4_467410
  X2[1] = 0;  // @5_467410
  X2[2] = 0;  // @6_467410
  X2[3] = 0;  // @7_467410
  X3[0] = 0;  // @8_467410
  X3[1] = 0;  // @9_467410
  X3[2] = 0;  // @10_467410
  X3[3] = 0;  // @11_467410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @12_467410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 4), 4); v; });  // @13_467410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 8), 4); v; });  // @14_467410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 12), 4); v; });  // @15_467410
  FA = U2F(X2[0]); FB = U2F(X3[0]);  // @16_467410
  __builtin_memcpy((void *)((u32)(esi + 61) + 0), &X0[0], 4);  // @17_467410
  __builtin_memcpy((void *)((u32)(esi + 61) + 4), &X0[1], 4);  // @18_467410
  __builtin_memcpy((void *)((u32)(esi + 61) + 8), &X0[2], 4);  // @19_467410
  __builtin_memcpy((void *)((u32)(esi + 61) + 12), &X0[3], 4);  // @20_467410
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @21_467410
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @22_467410
  if (!__builtin_parity(FL[2] & 0xff)) goto L46751e;  // @23_467410
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 53) + 0), 4); v; });  // @24_467410
  X1[1] = 0;  // @25_467410
  X1[2] = 0;  // @26_467410
  X1[3] = 0;  // @27_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_467410
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @29_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @30_467410
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @31_467410
  X5[1] = 0;  // @32_467410
  X5[2] = 0;  // @33_467410
  X5[3] = 0;  // @34_467410
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @35_467410
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @36_467410
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @37_467410
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @38_467410
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @39_467410
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @40_467410
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @41_467410
  eax = (eax - ecx);  // @42_467410
  FL[3] = eax;  // @43_467410
  FA = U2F(X1[0]); FB = U2F(X3[0]);  // @44_467410
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @45_467410
  X1[1] = 0;  // @46_467410
  X1[2] = 0;  // @47_467410
  X1[3] = 0;  // @48_467410
  X2[0] = eax; X2[1] = X2[2] = X2[3] = 0;  // @49_467410
  X2[0] = F2U((float)(s32)X2[0]);  // @50_467410
  X2[1] = F2U((float)(s32)X2[1]);  // @51_467410
  X2[2] = F2U((float)(s32)X2[2]);  // @52_467410
  X2[3] = F2U((float)(s32)X2[3]);  // @53_467410
  X2[0] = F2U(U2F(X2[0]) * U2F(X5[0]));  // @54_467410
  if ((!(!(FA >= FB)))) goto L4674b1;  // @55_467410
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 49) + 0), 4); v; });  // @56_467410
  X4[1] = 0;  // @57_467410
  X4[2] = 0;  // @58_467410
  X4[3] = 0;  // @59_467410
  FA = U2F(X2[0]); FB = U2F(X4[0]);  // @60_467410
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L467493;  // @61_467410
  X2[0] = X3[0];  // @62_467410
  X2[1] = X3[1];  // @63_467410
  X2[2] = X3[2];  // @64_467410
  X2[3] = X3[3];  // @65_467410
  goto L4674c4;  // @66_467410
  L467493:;
  FA = U2F(X4[0]); FB = U2F(X3[0]);  // @68_467410
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @69_467410
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @70_467410
  if (!__builtin_parity(FL[2] & 0xff)) goto L4674a1;  // @71_467410
  X2[0] = X3[0];  // @72_467410
  X2[1] = X3[1];  // @73_467410
  X2[2] = X3[2];  // @74_467410
  X2[3] = X3[3];  // @75_467410
  goto L4674c4;  // @76_467410
  L4674a1:;
  X0[0] = X2[0];  // @78_467410
  X0[1] = X2[1];  // @79_467410
  X0[2] = X2[2];  // @80_467410
  X0[3] = X2[3];  // @81_467410
  X2[0] = X1[0];  // @82_467410
  X2[1] = X1[1];  // @83_467410
  X2[2] = X1[2];  // @84_467410
  X2[3] = X1[3];  // @85_467410
  X0[0] = F2U(U2F(X0[0]) / U2F(X4[0]));  // @86_467410
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @87_467410
  goto L4674c4;  // @88_467410
  L4674b1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 49) + 0), 4); v; });  // @90_467410
  X0[1] = 0;  // @91_467410
  X0[2] = 0;  // @92_467410
  X0[3] = 0;  // @93_467410
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @94_467410
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L4674c1;  // @95_467410
  X2[0] = F2U(U2F(X2[0]) / U2F(X0[0]));  // @96_467410
  goto L4674c4;  // @97_467410
  L4674c1:;
  X2[0] = X1[0];  // @99_467410
  X2[1] = X1[1];  // @100_467410
  X2[2] = X1[2];  // @101_467410
  X2[3] = X1[3];  // @102_467410
  L4674c4:;
  FA = U2F(X2[0]); FB = U2F(X1[0]);  // @104_467410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 49), &v, sizeof v); }  // @105_467410
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @106_467410
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @107_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @108_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @109_467410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @110_467410
  if (__builtin_parity(FL[2] & 0xff)) goto L4674fd;  // @111_467410
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @112_467410
  FL[1] = eax;  // @113_467410
  eax = (0u - eax);  // @114_467410
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @115_467410
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @116_467410
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @117_467410
  eax = (eax - ecx);  // @118_467410
  FL[3] = eax;  // @119_467410
  goto L4674ff;  // @120_467410
  L4674fd:;
  FL[1] = eax;  // @122_467410
  eax = (0u - eax);  // @123_467410
  L4674ff:;
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @125_467410
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @126_467410
  ecx = esi;  // @127_467410
  X0[0] = F2U((float)(s32)X0[0]);  // @128_467410
  X0[1] = F2U((float)(s32)X0[1]);  // @129_467410
  X0[2] = F2U((float)(s32)X0[2]);  // @130_467410
  X0[3] = F2U((float)(s32)X0[3]);  // @131_467410
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @132_467410
  __builtin_memcpy((void *)((u32)(esi + 53) + 0), &X0[0], 4);  // @133_467410
  eax = ext_465930_thiscall2(ecx, PV[1]);  // @134_467410
  ecx = edx = 0;  // @135_467410
  return eax;  // @136_467410
  L46751e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 53) + 0), 4); v; });  // @138_467410
  X0[1] = 0;  // @139_467410
  X0[2] = 0;  // @140_467410
  X0[3] = 0;  // @141_467410
  FA = U2F(X0[0]); FB = U2F(X3[0]);  // @142_467410
  if ((!(FA >= FB))) goto L4675c7;  // @143_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @144_467410
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @145_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @146_467410
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; });  // @147_467410
  X3[1] = 0;  // @148_467410
  X3[2] = 0;  // @149_467410
  X3[3] = 0;  // @150_467410
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @151_467410
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @152_467410
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @153_467410
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @154_467410
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @155_467410
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 49) + 0), 4); v; });  // @156_467410
  X4[1] = 0;  // @157_467410
  X4[2] = 0;  // @158_467410
  X4[3] = 0;  // @159_467410
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @160_467410
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @161_467410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @162_467410
  X0[1] = 0;  // @163_467410
  X0[2] = 0;  // @164_467410
  X0[3] = 0;  // @165_467410
  eax = (eax - ecx);  // @166_467410
  FL[3] = eax;  // @167_467410
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @168_467410
  X1[0] = F2U((float)(s32)X1[0]);  // @169_467410
  X1[1] = F2U((float)(s32)X1[1]);  // @170_467410
  X1[2] = F2U((float)(s32)X1[2]);  // @171_467410
  X1[3] = F2U((float)(s32)X1[3]);  // @172_467410
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @173_467410
  FA = U2F(X4[0]); FB = U2F(X1[0]);  // @174_467410
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L46757b;  // @175_467410
  X1[0] = F2U(U2F(X1[0]) / U2F(X4[0]));  // @176_467410
  goto L46757e;  // @177_467410
  L46757b:;
  X1[0] = X0[0];  // @179_467410
  X1[1] = X0[1];  // @180_467410
  X1[2] = X0[2];  // @181_467410
  X1[3] = X0[3];  // @182_467410
  L46757e:;
  FA = U2F(X1[0]); FB = U2F(X0[0]);  // @184_467410
  __builtin_memcpy((void *)((u32)(esi + 49) + 0), &X2[0], 4);  // @185_467410
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @186_467410
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @187_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_467410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @189_467410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 57), &v, sizeof v); }  // @190_467410
  if (__builtin_parity(FL[2] & 0xff)) goto L4675b5;  // @191_467410
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @192_467410
  FL[1] = eax;  // @193_467410
  eax = (0u - eax);  // @194_467410
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @195_467410
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @196_467410
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @197_467410
  eax = (eax - ecx);  // @198_467410
  FL[3] = eax;  // @199_467410
  goto L4675b7;  // @200_467410
  L4675b5:;
  FL[1] = eax;  // @202_467410
  eax = (0u - eax);  // @203_467410
  L4675b7:;
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @205_467410
  X0[0] = F2U((float)(s32)X0[0]);  // @206_467410
  X0[1] = F2U((float)(s32)X0[1]);  // @207_467410
  X0[2] = F2U((float)(s32)X0[2]);  // @208_467410
  X0[3] = F2U((float)(s32)X0[3]);  // @209_467410
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @210_467410
  __builtin_memcpy((void *)((u32)(esi + 53) + 0), &X0[0], 4);  // @211_467410
  L4675c7:;
  return eax;  // @213_467410
}
PCREG(467410, lifted_467410);

