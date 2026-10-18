// batch252011.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de4b0_fastcall3(u32, u32, u32) __asm__("ext_4de4b0");
extern "C" u32 FASTCALL ext_613690_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_613690");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4d8330_thiscall4(u32, u32, u32, u32) __asm__("ext_4d8330");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1440_thiscall2(u32, u32) __asm__("ext_4e1440");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_4ef660_thiscall2(u32, u32) __asm__("ext_4ef660");
extern "C" u32 THISCALL ext_64a410_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_64a410");
extern "C" u32 THISCALL ext_6528a0_thiscall1(u32) __asm__("ext_6528a0");
extern "C" u32 THISCALL ext_657da0_thiscall3(u32, u32, u32) __asm__("ext_657da0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ac56_cdecl4(...) __asm__("ext_42ac56");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");
extern "C" u32 ext_634d34_cdecl2(...) __asm__("ext_634d34");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_54b1f0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  edi = ecx;  // @0_54b1f0
  esi = 0;  // @1_54b1f0
  FL[3] = esi;  // @2_54b1f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 552), &v, sizeof v); }  // @3_54b1f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @4_54b1f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32869), sizeof v); (u32)v; }); FL[1] = esi;  // @5_54b1f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54b402;  // @6_54b1f0
  ebx = (u32)(edi + 32881);  // @7_54b1f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @8_54b1f0
  L54b230:;
  eax = (u32)(EBP - 536);  // @10_54b1f0
  PV[0] = (u32)(eax);  // @11_54b1f0
  eax = ext_634d10_cdecl3(PV[0], (u32)(0), (u32)(512));  // @12_54b1f0
    // @13_54b1f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_54b1f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @16_54b1f0
  ecx = edx = 0;  // @17_54b1f0
  PV[1] = (u32)(esi);  // @18_54b1f0
  edx = (u32)(EBP - 536);  // @19_54b1f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_54b1f0
  PV[2] = (u32)(edx);  // @21_54b1f0
  PV[3] = (u32)(eax);  // @22_54b1f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[3], PV[2], (u32)(6960268), PV[1]);  // @23_54b1f0
  ecx = edx = 0;  // @24_54b1f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @25_54b1f0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @26_54b1f0
  if ((s32)FL[0] <= (s32)FL[1]) goto L54b3b2;  // @27_54b1f0
  ebx = (ebx + (u32)(8));  // @28_54b1f0
  FL[3] = ebx;  // @29_54b1f0
  L54b283:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @31_54b1f0
  eax = (eax - (u32)(1));  // @32_54b1f0
  FL[3] = eax;  // @33_54b1f0
  if (FL[3] == 0) goto L54b311;  // @34_54b1f0
  ecx = (u32)(EBP - 536);  // @35_54b1f0
  eax = (eax - (u32)(1));  // @36_54b1f0
  FL[3] = eax;  // @37_54b1f0
  if (FL[3] == 0) goto L54b2f5;  // @38_54b1f0
  eax = (eax - (u32)(1));  // @39_54b1f0
  FL[3] = eax;  // @40_54b1f0
  if (FL[3] == 0) goto L54b2c6;  // @41_54b1f0
  ecx = (ecx - 1);  // @42_54b1f0
  FL[3] = ecx;  // @43_54b1f0
  L54b2a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @45_54b1f0
  ecx = (u32)(ecx + 1);  // @46_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @47_54b1f0
  if (FL[2] != 0) goto L54b2a0;  // @48_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960312), sizeof v); (u32)v; });  // @49_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @50_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960316), sizeof v); (u32)v; });  // @51_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @52_54b1f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6960320), sizeof v); (u32)v; })) & 0xff);  // @53_54b1f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @54_54b1f0
  goto L54b386;  // @55_54b1f0
  L54b2c6:;
  ecx = (ecx - 1);  // @57_54b1f0
  FL[3] = ecx;  // @58_54b1f0
  L54b2c7:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @60_54b1f0
  ecx = (u32)(ecx + 1);  // @61_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @62_54b1f0
  if (FL[2] != 0) goto L54b2c7;  // @63_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960296), sizeof v); (u32)v; });  // @64_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @65_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960300), sizeof v); (u32)v; });  // @66_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @67_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960304), sizeof v); (u32)v; });  // @68_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @69_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960308), sizeof v); (u32)v; });  // @70_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @71_54b1f0
  goto L54b386;  // @72_54b1f0
  L54b2f5:;
  ecx = (ecx - 1);  // @74_54b1f0
  FL[3] = ecx;  // @75_54b1f0
  L54b2f6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @77_54b1f0
  ecx = (u32)(ecx + 1);  // @78_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @79_54b1f0
  if (FL[2] != 0) goto L54b2f6;  // @80_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960280), sizeof v); (u32)v; });  // @81_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @82_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960284), sizeof v); (u32)v; });  // @83_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @84_54b1f0
  goto L54b386;  // @85_54b1f0
  L54b311:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_54b1f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @88_54b1f0
  X0[1] = 0;  // @89_54b1f0
  X0[2] = 0;  // @90_54b1f0
  X0[3] = 0;  // @91_54b1f0
  eax = (u32)(EBP - 24);  // @92_54b1f0
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @93_54b1f0
  __builtin_memcpy((void *)((u32)((EBP - 572)) + 0), &X0[0], 4);  // @94_54b1f0
  __builtin_memcpy((void *)((u32)((EBP - 572)) + 4), &X0[1], 4);  // @95_54b1f0
  PV[4] = (u32)(eax);  // @96_54b1f0
  eax = ext_42ac56_cdecl4(PV[4], (u32)(6955596), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), 4); v; }));  // @97_54b1f0
  ecx = edx = 0;  // @98_54b1f0
  ecx = (u32)(EBP - 536);  // @99_54b1f0
  ecx = (ecx - 1);  // @100_54b1f0
  FL[3] = ecx;  // @101_54b1f0
  L54b340:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @103_54b1f0
  ecx = (u32)(ecx + 1);  // @104_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @105_54b1f0
  if (FL[2] != 0) goto L54b340;  // @106_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6960288), sizeof v); (u32)v; });  // @107_54b1f0
  edx = (u32)(EBP - 24);  // @108_54b1f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @109_54b1f0
  esi = edx;  // @110_54b1f0
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6960292), sizeof v); (u32)v; })) & 0xffff);  // @111_54b1f0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @112_54b1f0
  L54b360:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @114_54b1f0
  edx = (edx + 1);  // @115_54b1f0
  FL[3] = edx;  // @116_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @117_54b1f0
  if (FL[2] != 0) goto L54b360;  // @118_54b1f0
  edi = (u32)(EBP - 536);  // @119_54b1f0
  edx = (edx - esi);  // @120_54b1f0
  FL[3] = edx;  // @121_54b1f0
  edi = (edi - 1);  // @122_54b1f0
  FL[3] = edi;  // @123_54b1f0
  L54b370:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @125_54b1f0
  edi = (edi + 1);  // @126_54b1f0
  FL[3] = edi;  // @127_54b1f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @128_54b1f0
  if (FL[2] != 0) goto L54b370;  // @129_54b1f0
  ecx = edx;  // @130_54b1f0
  ecx = (ecx >> (u32)(2));  // @131_54b1f0
  FL[3] = ecx;  // @132_54b1f0
  while (ecx) { u32 v_; __builtin_memcpy(&v_, (void *)esi, 4); __builtin_memcpy((void *)edi, &v_, 4); esi += 4; edi += 4; ecx--; }  // @133_54b1f0
  ecx = edx;  // @134_54b1f0
  ecx = (ecx & (u32)(3));  // @135_54b1f0
  FL[3] = ecx;  // @136_54b1f0
  while (ecx) { *(u8 *)edi = *(u8 *)esi; esi++; edi++; ecx--; }  // @137_54b1f0
  L54b386:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; });  // @139_54b1f0
  ebx = (ebx + (u32)(8));  // @140_54b1f0
  FL[3] = ebx;  // @141_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @142_54b1f0
  ecx = (ecx + 1);  // @143_54b1f0
  FL[3] = ecx;  // @144_54b1f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @145_54b1f0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @146_54b1f0
  if ((s32)FL[0] < (s32)FL[1]) goto L54b283;  // @147_54b1f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 548), sizeof v); (u32)v; });  // @148_54b1f0
  ebx = eax;  // @149_54b1f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 552), sizeof v); (u32)v; });  // @150_54b1f0
  L54b3b2:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 41581), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @152_54b1f0
  if (FL[0] == FL[1]) goto L54b3e2;  // @153_54b1f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @154_54b1f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @155_54b1f0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @156_54b1f0
  ecx = edx = 0;  // @157_54b1f0
  ecx = (u32)(EBP - 536);  // @158_54b1f0
  PV[5] = (u32)(ecx);  // @159_54b1f0
  ecx = (u32)(esi + 40);  // @160_54b1f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @161_54b1f0
  PV[6] = (u32)(ecx);  // @162_54b1f0
  PV[7] = (u32)(eax);  // @163_54b1f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[7], (u32)(30), PV[6], PV[5]);  // @164_54b1f0
  ecx = edx = 0;  // @165_54b1f0
  L54b3e2:;
  esi = (esi + 1);  // @167_54b1f0
  FL[3] = esi;  // @168_54b1f0
  ebx = (ebx + (u32)(272));  // @169_54b1f0
  FL[3] = ebx;  // @170_54b1f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @171_54b1f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @172_54b1f0
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32869), sizeof v); (u32)v; });  // @173_54b1f0
  if ((s32)FL[0] < (s32)FL[1]) goto L54b230;  // @174_54b1f0
  L54b402:;
  ext_633654(G(u32, 0x6f5630));  // @176_54b1f0
  return eax;  // @177_54b1f0
}
PCREG(54b1f0, lifted_54b1f0);

extern "C" u32 THISCALL lifted_64a410(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_64a410
  ebx = ecx;  // @1_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 448), &v, sizeof v); }  // @2_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_64a410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @5_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @6_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @7_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @8_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 60), sizeof v); (u32)v; });  // @9_64a410
  edx = (u32)(edi + 44);  // @10_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @11_64a410
  eax = (u32)(ebx + 98845);  // @12_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @13_64a410
  ecx = (u32)(EBP - 16);  // @14_64a410
  PV[0] = (u32)(eax);  // @15_64a410
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @16_64a410
  ecx = edx = 0;  // @17_64a410
  esi = (u32)(ebx + 98809);  // @18_64a410
  edx = esi;  // @19_64a410
  ecx = (u32)(EBP - 16);  // @20_64a410
  eax = ext_441a60_fastcall2(ecx, edx);  // @21_64a410
  ecx = edx = 0;  // @22_64a410
  PV[1] = (u32)(esi);  // @23_64a410
  edx = (u32)(edi + 8);  // @24_64a410
  ecx = (u32)(EBP - 68);  // @25_64a410
  eax = ext_4de4b0_fastcall3(ecx, edx, PV[1]);  // @26_64a410
  ecx = edx = 0;  // @27_64a410
  edx = (u32)(EBP - 68);  // @28_64a410
  ecx = (u32)(EBP - 116);  // @29_64a410
  eax = ext_4de420_fastcall2(ecx, edx);  // @30_64a410
    // @31_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @32_64a410
  esi = 0;  // @33_64a410
  FL[3] = esi;  // @34_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @35_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @36_64a410
  X0[2] = 0;  // @37_64a410
  X0[3] = 0;  // @38_64a410
  edi = 0;  // @39_64a410
  FL[3] = edi;  // @40_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @41_64a410
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @42_64a410
  __builtin_memcpy((void *)((u32)(EBP - 32) + 4), &X0[1], 4);  // @43_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @44_64a410
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @45_64a410
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @46_64a410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 444), &v, sizeof v); }  // @47_64a410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 140), sizeof v); (u32)v; }); FL[1] = esi;  // @48_64a410
  if ((s32)FL[0] <= (s32)FL[1]) goto L64a60b;  // @49_64a410
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @50_64a410
  L64a4e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 144), sizeof v); (u32)v; });  // @52_64a410
  ecx = (ecx + edi);  // @53_64a410
  FL[3] = ecx;  // @54_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 440), &v, sizeof v); }  // @55_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 48), sizeof v); (u32)v; });  // @56_64a410
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 135), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @57_64a410
  if (FL[0] != FL[1]) goto L64a5dd;  // @58_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @59_64a410
  PV[2] = (u32)(ecx);  // @60_64a410
  ecx = (u32)(EBP - 32);  // @61_64a410
  PV[3] = (u32)(ecx);  // @62_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; });  // @63_64a410
  ecx = (u32)(EBP - 116);  // @64_64a410
  PV[4] = (u32)(ecx);  // @65_64a410
  ecx = (u32)(EBP - 164);  // @66_64a410
  PV[5] = (u32)(ecx);  // @67_64a410
  ecx = (u32)(EBP - 20);  // @68_64a410
  PV[6] = (u32)(ecx);  // @69_64a410
  ecx = ebx;  // @70_64a410
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[6], PV[5], PV[4], PV[3], PV[2]);  // @71_64a410
  ecx = edx = 0;  // @72_64a410
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @73_64a410
  if (FL[2] == 0) goto L64a5dd;  // @74_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @75_64a410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @76_64a410
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @77_64a410
  if (FL[0] == FL[1]) goto L64a5d7;  // @78_64a410
  L64a535:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @80_64a410
  ecx = (u32)(EBP - 164);  // @81_64a410
  PV[7] = (u32)(edi);  // @82_64a410
  PV[8] = (u32)(ecx);  // @83_64a410
  ecx = (u32)(EBP - 80);  // @84_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @85_64a410
  PV[9] = (u32)(ecx);  // @86_64a410
  ecx = ebx;  // @87_64a410
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[9], PV[8], PV[7]);  // @88_64a410
  ecx = edx = 0;  // @89_64a410
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @90_64a410
  if (FL[2] == 0) goto L64a5cb;  // @91_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; });  // @92_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @93_64a410
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 436), sizeof v); (u32)v; }); FL[1] = ecx;  // @94_64a410
  if (FL[0] == FL[1]) goto L64a5ac;  // @95_64a410
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 136), sizeof v); (u32)v; });  // @96_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 436), &v, sizeof v); }  // @97_64a410
  FL[2] = (esi & esi);  // @98_64a410
  if (FL[2] != 0) goto L64a58e;  // @99_64a410
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @100_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @101_64a410
  PV[11] = (u32)(ecx);  // @102_64a410
  ecx = ebx;  // @103_64a410
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[11], PV[10]);  // @104_64a410
  ecx = edx = 0;  // @105_64a410
  esi = eax;  // @106_64a410
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; });  // @107_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @108_64a410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ecx + 136), &v, sizeof v); }  // @109_64a410
  L64a58e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @111_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @112_64a410
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP + eax*8 - 420), &v, sizeof v); }  // @113_64a410
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + eax*8 - 416), &v, sizeof v); }  // @114_64a410
  eax = (eax + 1);  // @115_64a410
  FL[3] = eax;  // @116_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @117_64a410
  L64a5ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_64a410
  ecx = ebx;  // @120_64a410
  PV[12] = (u32)(esi);  // @121_64a410
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[12]);  // @122_64a410
  ecx = edx = 0;  // @123_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @124_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 4), 4); v; });  // @125_64a410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 8), 4); v; });  // @126_64a410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 12), 4); v; });  // @127_64a410
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @128_64a410
  __builtin_memcpy((void *)((u32)(eax) + 4), &X0[1], 4);  // @129_64a410
  __builtin_memcpy((void *)((u32)(eax) + 8), &X0[2], 4);  // @130_64a410
  __builtin_memcpy((void *)((u32)(eax) + 12), &X0[3], 4);  // @131_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @132_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 4), 4); v; });  // @133_64a410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 8), 4); v; });  // @134_64a410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 12), 4); v; });  // @135_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 0), &X0[0], 4);  // @136_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 4), &X0[1], 4);  // @137_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 8), &X0[2], 4);  // @138_64a410
  __builtin_memcpy((void *)((u32)(eax + 16) + 12), &X0[3], 4);  // @139_64a410
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @140_64a410
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 4), 4); v; });  // @141_64a410
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 8), 4); v; });  // @142_64a410
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 12), 4); v; });  // @143_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 0), &X0[0], 4);  // @144_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 4), &X0[1], 4);  // @145_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 8), &X0[2], 4);  // @146_64a410
  __builtin_memcpy((void *)((u32)(eax + 32) + 12), &X0[3], 4);  // @147_64a410
  L64a5cb:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @149_64a410
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @150_64a410
  if (FL[0] != FL[1]) goto L64a535;  // @151_64a410
  L64a5d7:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @153_64a410
  L64a5dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @155_64a410
  edi = (edi + (u32)(52));  // @156_64a410
  FL[3] = edi;  // @157_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @158_64a410
  eax = (eax + 1);  // @159_64a410
  FL[3] = eax;  // @160_64a410
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 444), &v, sizeof v); }  // @161_64a410
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @162_64a410
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 140), sizeof v); (u32)v; });  // @163_64a410
  if ((s32)FL[0] < (s32)FL[1]) goto L64a4e0;  // @164_64a410
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @165_64a410
  L64a60b:;
  esi = 0;  // @167_64a410
  FL[3] = esi;  // @168_64a410
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @169_64a410
  FL[2] = (edi & edi);  // @170_64a410
  if ((s32)FL[2] <= 0) goto L64a654;  // @171_64a410
  L64a620:;
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; });  // @173_64a410
  ecx = ebx;  // @174_64a410
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; });  // @175_64a410
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @176_64a410
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 416), sizeof v); (u32)v; });  // @177_64a410
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*8 - 420), sizeof v); (u32)v; });  // @178_64a410
  eax = ext_64a410_thiscall7(ecx, PV[17], PV[16], PV[15], PV[14], PV[13], (u32)(0));  // @179_64a410
  ecx = edx = 0;  // @180_64a410
  esi = (esi + 1);  // @181_64a410
  FL[3] = esi;  // @182_64a410
  FL[0] = esi; FL[1] = edi;  // @183_64a410
  if ((s32)FL[0] < (s32)FL[1]) goto L64a620;  // @184_64a410
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @185_64a410
  L64a654:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; })) & 0xff);  // @187_64a410
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @188_64a410
  ext_633654(G(u32, 0x6f5630));  // @189_64a410
  return eax;  // @190_64a410
}
PCREG(64a410, lifted_64a410);

extern "C" u32 THISCALL lifted_6515d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66ecee);  // @h_6515d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_6515d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6515d0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6515d0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_6515d0
  eax = ext_657da0_thiscall3(ecx, PV[1], PV[0]);  // @4_6515d0
  ecx = edx = 0;  // @5_6515d0
  { u32 v = (u32)((u32)(7091948)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_6515d0
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4757), &v, sizeof v); }  // @7_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 311), &v, sizeof v); }  // @8_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_6515d0
  reg.state = (s32)((u32)(0));  // @10_6515d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @11_6515d0
  if (FL[0] == FL[1]) goto L65163d;  // @12_6515d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @13_6515d0
  if (FL[0] != FL[1]) goto L6516e8;  // @14_6515d0
  L65163d:;
  eax = ((u32(STDCALL *)(void))(*(u32 *)0x676240))();  // @16_6515d0
  ecx = edx = 0;  // @17_6515d0
  PV[2] = (u32)(eax);  // @18_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @19_6515d0
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x6761f8))(PV[2]);  // @20_6515d0
  ecx = edx = 0;  // @21_6515d0
  ebx = eax;  // @22_6515d0
  PV[3] = (u32)(ebx);  // @23_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676038))(PV[3], (u32)(14));  // @24_6515d0
  ecx = edx = 0;  // @25_6515d0
  PV[4] = (u32)(ebx);  // @26_6515d0
  edi = eax;  // @27_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x676038))(PV[4], (u32)(12));  // @28_6515d0
  ecx = edx = 0;  // @29_6515d0
  PV[5] = (u32)(ebx);  // @30_6515d0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @31_6515d0
  edi = (u32)((s32)edi * (s32)eax);  // @32_6515d0
  FL[3] = edi;  // @33_6515d0
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)0x67620c))(PV[6], PV[5]);  // @34_6515d0
  ecx = edx = 0;  // @35_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_6515d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + 127), &v, sizeof v); }  // @37_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_6515d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; }); FL[1] = (u32)(16);  // @39_6515d0
  if ((s32)FL[0] >= (s32)FL[1]) goto L6516a1;  // @40_6515d0
  eax = (u32)(EBP - 24);  // @41_6515d0
  { u32 v = (u32)((u32)(7092880)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @42_6515d0
  PV[7] = (u32)(eax);  // @43_6515d0
  { u32 v = (u32)((u32)(7092792)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @44_6515d0
  eax = ext_634d34_cdecl2(PV[7], (u32)(7197212));  // @45_6515d0
    // @46_6515d0
  L6516a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @48_6515d0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 118), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @49_6515d0
  if (FL[0] == FL[1]) goto L6516df;  // @50_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @51_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_6515d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7092888), (u32)(455));  // @53_6515d0
  ecx = edx = 0;  // @54_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_6515d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_6515d0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 127), sizeof v); (u32)v; });  // @57_6515d0
  PV[9] = (u32)(eax);  // @58_6515d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edx + 44)))(PV[9], (u32)(7092940), PV[8]);  // @59_6515d0
  ecx = edx = 0;  // @60_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_6515d0
  L6516df:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 99), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @63_6515d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @64_6515d0
  if (FL[0] == FL[1]) goto L651701;  // @65_6515d0
  L6516e8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 135), &v, sizeof v); }  // @67_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 139), &v, sizeof v); }  // @69_6515d0
  L651701:;
  { u32 v = (u32)((u32)(40000)); __builtin_memcpy((void *)(u32)(ebx + 4745), &v, sizeof v); }  // @71_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4585), &v, sizeof v); }  // @72_6515d0
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(ebx + 4583), &v, sizeof v); }  // @73_6515d0
  eax = ((u32( *)(void))(*(u32 *)0x676234))();  // @74_6515d0
  ecx = edx = 0;  // @75_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 303), sizeof v); (u32)v; });  // @76_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4593), &v, sizeof v); }  // @77_6515d0
  eax = ext_6528a0_thiscall1(ecx);  // @78_6515d0
  ecx = edx = 0;  // @79_6515d0
  eax = (u32)(ebx + 4613);  // @80_6515d0
  PV[10] = (u32)(eax);  // @81_6515d0
  eax = ext_634d10_cdecl3(PV[10], (u32)(0), (u32)(128));  // @82_6515d0
    // @83_6515d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4741), &v, sizeof v); }  // @84_6515d0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(ebx + 4749), &v, sizeof v); }  // @85_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @86_6515d0
  ecx = edx = 0;  // @87_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @88_6515d0
  reg.state = (s32)((u32)(1));  // @89_6515d0
  FL[2] = (eax & eax);  // @90_6515d0
  if (FL[2] == 0) goto L65178b;  // @91_6515d0
  ecx = eax;  // @92_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092956), (u32)(0), (u32)(7493664));  // @93_6515d0
  ecx = edx = 0;  // @94_6515d0
  edx = eax;  // @95_6515d0
  goto L65178d;  // @96_6515d0
  L65178b:;
  edx = 0;  // @98_6515d0
  FL[3] = edx;  // @99_6515d0
  L65178d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4759), &v, sizeof v); }  // @101_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_6515d0
  PV[11] = (u32)(edx);  // @103_6515d0
  reg.state = (s32)((u32)(0));  // @104_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[11]);  // @106_6515d0
  ecx = edx = 0;  // @107_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @108_6515d0
  ecx = edx = 0;  // @109_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @110_6515d0
  reg.state = (s32)((u32)(2));  // @111_6515d0
  FL[2] = (eax & eax);  // @112_6515d0
  if (FL[2] == 0) goto L6517d5;  // @113_6515d0
  ecx = eax;  // @114_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092980), (u32)(0), (u32)(7298720));  // @115_6515d0
  ecx = edx = 0;  // @116_6515d0
  edx = eax;  // @117_6515d0
  goto L6517d7;  // @118_6515d0
  L6517d5:;
  edx = 0;  // @120_6515d0
  FL[3] = edx;  // @121_6515d0
  L6517d7:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4763), &v, sizeof v); }  // @123_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_6515d0
  PV[12] = (u32)(edx);  // @125_6515d0
  reg.state = (s32)((u32)(0));  // @126_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[12]);  // @128_6515d0
  ecx = edx = 0;  // @129_6515d0
  eax = ext_41e290_cdecl1((u32)(264));  // @130_6515d0
  ecx = edx = 0;  // @131_6515d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @132_6515d0
  reg.state = (s32)((u32)(3));  // @133_6515d0
  FL[2] = (eax & eax);  // @134_6515d0
  if (FL[2] == 0) goto L65181f;  // @135_6515d0
  ecx = eax;  // @136_6515d0
  eax = ext_4d8330_thiscall4(ecx, (u32)(7092992), (u32)(0), (u32)(7298724));  // @137_6515d0
  ecx = edx = 0;  // @138_6515d0
  edx = eax;  // @139_6515d0
  goto L651821;  // @140_6515d0
  L65181f:;
  edx = 0;  // @142_6515d0
  FL[3] = edx;  // @143_6515d0
  L651821:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ebx + 4767), &v, sizeof v); }  // @145_6515d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_6515d0
  PV[13] = (u32)(edx);  // @147_6515d0
  reg.state = (s32)((u32)(0));  // @148_6515d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_6515d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, PV[13]);  // @150_6515d0
  ecx = edx = 0;  // @151_6515d0
  eax = ebx;  // @152_6515d0
  SEH_LEAVE();  // @153_6515d0
  return eax;  // @154_6515d0
}
PCREG(6515d0, lifted_6515d0);

extern "C" u32 THISCALL lifted_612a20(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_612a20
  esi = ecx;  // @1_612a20
  ecx = ebx;  // @2_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139312), sizeof v); (u32)v; });  // @3_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @4_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 52)))(ecx);  // @6_612a20
  ecx = edx = 0;  // @7_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @9_612a20
  ecx = (u32)(eax - 1);  // @10_612a20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 147), sizeof v); (u32)v; });  // @11_612a20
  FL[0] = ecx; FL[1] = edi;  // @12_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_612a20
  if (FL[0] < FL[1]) edi = ecx;  // @14_612a20
  ecx = ebx;  // @15_612a20
  PV[0] = (u32)(edi);  // @16_612a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @17_612a20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[0]);  // @18_612a20
  ecx = edx = 0;  // @19_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139268), sizeof v); (u32)v; });  // @20_612a20
  ecx = (u32)(EBP - 8);  // @21_612a20
  PV[1] = (u32)(ecx);  // @22_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @23_612a20
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @24_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @25_612a20
  ecx = (ecx - edi);  // @26_612a20
  FL[3] = ecx;  // @27_612a20
  PV[3] = (u32)(ecx);  // @28_612a20
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @29_612a20
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @30_612a20
  PV[6] = (u32)(edx);  // @31_612a20
  eax = ((u32(STDCALL *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(esi + 80)))(PV[6], PV[5], PV[4], PV[3], (u32)(0), PV[2], (u32)(1), PV[1]);  // @32_612a20
  ecx = edx = 0;  // @33_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @34_612a20
  ecx = ebx;  // @35_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @36_612a20
  ecx = edx = 0;  // @37_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @38_612a20
  ecx = ebx;  // @39_612a20
  esi = eax;  // @40_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 28)))(ecx);  // @41_612a20
  ecx = edx = 0;  // @42_612a20
  eax = (u32)((s32)eax * (s32)esi);  // @43_612a20
  FL[3] = eax;  // @44_612a20
  ecx = 0;  // @45_612a20
  FL[3] = ecx;  // @46_612a20
  edx = (u32)(4);  // @47_612a20
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @48_612a20
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @49_612a20
  FL[1] = ecx;  // @50_612a20
  ecx = (0u - ecx);  // @51_612a20
  ecx = (ecx | eax);  // @52_612a20
  FL[3] = ecx;  // @53_612a20
  PV[7] = (u32)(ecx);  // @54_612a20
  eax = ext_41e290_cdecl1(PV[7]);  // @55_612a20
  ecx = edx = 0;  // @56_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_612a20
  ecx = ebx;  // @58_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @59_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 32)))(ecx);  // @60_612a20
  ecx = edx = 0;  // @61_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_612a20
  ecx = ebx;  // @63_612a20
  esi = eax;  // @64_612a20
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 28)))(ecx);  // @65_612a20
  ecx = edx = 0;  // @66_612a20
  eax = (u32)((s32)eax * (s32)esi);  // @67_612a20
  FL[3] = eax;  // @68_612a20
  ecx = 0;  // @69_612a20
  FL[3] = ecx;  // @70_612a20
  edx = (u32)(4);  // @71_612a20
  { u64 p_ = (u64)eax * (u64)(u32)(edx); eax = (u32)p_; edx = (u32)(p_ >> 32); }  // @72_612a20
  ecx = (ecx & 0xffffff00u) | ((((edx) != 0 ? 1 : 0)) & 0xff);  // @73_612a20
  FL[1] = ecx;  // @74_612a20
  ecx = (0u - ecx);  // @75_612a20
  ecx = (ecx | eax);  // @76_612a20
  FL[3] = ecx;  // @77_612a20
  PV[8] = (u32)(ecx);  // @78_612a20
  eax = ext_41e290_cdecl1(PV[8]);  // @79_612a20
  ecx = edx = 0;  // @80_612a20
  esi = eax;  // @81_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @82_612a20
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @83_612a20
  if (FL[0] >= FL[1]) goto L612bd6;  // @84_612a20
  esi = 0;  // @85_612a20
  FL[3] = esi;  // @86_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @87_612a20
  L612af1:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @89_612a20
  ecx = ebx;  // @90_612a20
  PV[9] = (u32)(edi);  // @91_612a20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 56)))(ecx, PV[9]);  // @92_612a20
  ecx = edx = 0;  // @93_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @94_612a20
  ebx = eax;  // @95_612a20
  eax = (u32)(EBP - 44);  // @96_612a20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @97_612a20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_612a20
  PV[10] = (u32)(eax);  // @99_612a20
  PV[11] = (u32)(esi);  // @100_612a20
  PV[12] = (u32)(ecx);  // @101_612a20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 64)))(ecx, PV[12], PV[11], PV[10], (u32)(0), (u32)(0));  // @102_612a20
  ecx = edx = 0;  // @103_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @104_612a20
  edx = (u32)(EBP - 92);  // @105_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @106_612a20
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 0), 4); v; });  // @107_612a20
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 4), 4); v; });  // @108_612a20
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 8), 4); v; });  // @109_612a20
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7067808) + 12), 4); v; });  // @110_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @111_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @112_612a20
  eax = (eax << (u32)(2));  // @113_612a20
  FL[3] = eax;  // @114_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @115_612a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @116_612a20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @117_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @118_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @119_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @120_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @121_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_612a20
  PV[13] = (u32)(edi);  // @123_612a20
  PV[14] = (u32)(edx);  // @124_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 0), &X0[0], 4);  // @125_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 4), &X0[1], 4);  // @126_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 8), &X0[2], 4);  // @127_612a20
  __builtin_memcpy((void *)((u32)(EBP - 72) + 12), &X0[3], 4);  // @128_612a20
  { u32 v = (u32)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @129_612a20
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @130_612a20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[14], PV[13]);  // @131_612a20
  ecx = edx = 0;  // @132_612a20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @133_612a20
  edx = esi;  // @134_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @135_612a20
  ecx = esi;  // @136_612a20
  PV[15] = (u32)(edi);  // @137_612a20
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @138_612a20
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @139_612a20
  eax = ext_613690_fastcall5(ecx, edx, PV[17], PV[16], PV[15]);  // @140_612a20
  ecx = edx = 0;  // @141_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @142_612a20
  eax = (eax + eax);  // @143_612a20
  FL[3] = eax;  // @144_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @145_612a20
  FL[0] = edi; FL[1] = (u32)(62);  // @146_612a20
  if (FL[0] != FL[1]) goto L612b84;  // @147_612a20
  eax = (eax + eax);  // @148_612a20
  FL[3] = eax;  // @149_612a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @150_612a20
  L612b84:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @152_612a20
  edi = esi;  // @153_612a20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @154_612a20
  esi = 0;  // @155_612a20
  FL[3] = esi;  // @156_612a20
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; }); FL[1] = esi;  // @157_612a20
  if ((s32)FL[0] <= (s32)FL[1]) goto L612baf;  // @158_612a20
  L612b93:;
  PV[18] = (u32)(eax);  // @160_612a20
  PV[19] = (u32)(edi);  // @161_612a20
  PV[20] = (u32)(ebx);  // @162_612a20
  eax = ext_634d22_cdecl3(PV[20], PV[19], PV[18]);  // @163_612a20
    // @164_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @165_612a20
  esi = (esi + 1);  // @166_612a20
  FL[3] = esi;  // @167_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @168_612a20
  ebx = (ebx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; }));  // @169_612a20
  FL[3] = ebx;  // @170_612a20
  edi = (edi + eax);  // @171_612a20
  FL[3] = edi;  // @172_612a20
  FL[0] = esi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @173_612a20
  if ((s32)FL[0] < (s32)FL[1]) goto L612b93;  // @174_612a20
  L612baf:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @176_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @177_612a20
  PV[21] = (u32)(esi);  // @178_612a20
  PV[22] = (u32)(eax);  // @179_612a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @180_612a20
  eax = ((u32(STDCALL *)(u32, u32))(*(u32 *)(ecx + 68)))(PV[22], PV[21]);  // @181_612a20
  ecx = edx = 0;  // @182_612a20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @183_612a20
  esi = (esi + 1);  // @184_612a20
  FL[3] = esi;  // @185_612a20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @186_612a20
  edi = (edi + 1);  // @187_612a20
  FL[3] = edi;  // @188_612a20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @189_612a20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @190_612a20
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @191_612a20
  if (FL[0] < FL[1]) goto L612af1;  // @192_612a20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @193_612a20
  L612bd6:;
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @195_612a20
  eax = ext_634273_cdecl2(PV[23], (u32)(4));  // @196_612a20
  ecx = edx = 0;  // @197_612a20
  PV[24] = (u32)(esi);  // @198_612a20
  eax = ext_634273_cdecl2(PV[24], (u32)(4));  // @199_612a20
  ecx = edx = 0;  // @200_612a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @201_612a20
  return eax;  // @202_612a20
}
PCREG(612a20, lifted_612a20);

extern "C" u32 THISCALL lifted_4ef3f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66988b);  // @h_4ef3f0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4ef3f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 168), &v, sizeof v); }  // @1_4ef3f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ef3f0
  PV[0] = (u32)(edi);  // @3_4ef3f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 172), &v, sizeof v); }  // @4_4ef3f0
  eax = ext_4ef660_thiscall2(ecx, PV[0]);  // @5_4ef3f0
  ecx = edx = 0;  // @6_4ef3f0
  eax = (u32)(EBP - 160);  // @7_4ef3f0
  ecx = edi;  // @8_4ef3f0
  PV[1] = (u32)(eax);  // @9_4ef3f0
  eax = ext_4e1440_thiscall2(ecx, PV[1]);  // @10_4ef3f0
  ecx = edx = 0;  // @11_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 155), sizeof v); (u32)v; });  // @12_4ef3f0
  FL[2] = (edx & edx);  // @13_4ef3f0
  if (FL[2] == 0) goto L4ef45c;  // @14_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_4ef3f0
  PV[2] = (u32)(edx);  // @16_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 252)))(ecx, PV[2]);  // @18_4ef3f0
  ecx = edx = 0;  // @19_4ef3f0
  L4ef45c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @21_4ef3f0
  ecx = (u32)(6915152);  // @22_4ef3f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @23_4ef3f0
  eax = edx;  // @24_4ef3f0
  L4ef473:;
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @26_4ef3f0
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4ef3f0
  if (FL[0] != FL[1]) goto L4ef493;  // @28_4ef3f0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @29_4ef3f0
  if (FL[2] == 0) goto L4ef48f;  // @30_4ef3f0
  ebx = (ebx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @31_4ef3f0
  FL[0] = (ebx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @32_4ef3f0
  if (FL[0] != FL[1]) goto L4ef493;  // @33_4ef3f0
  eax = (eax + (u32)(2));  // @34_4ef3f0
  FL[3] = eax;  // @35_4ef3f0
  ecx = (ecx + (u32)(2));  // @36_4ef3f0
  FL[3] = ecx;  // @37_4ef3f0
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @38_4ef3f0
  if (FL[2] != 0) goto L4ef473;  // @39_4ef3f0
  L4ef48f:;
  eax = 0;  // @41_4ef3f0
  FL[3] = eax;  // @42_4ef3f0
  goto L4ef498;  // @43_4ef3f0
  L4ef493:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @45_4ef3f0
  eax = (eax | (u32)(1));  // @46_4ef3f0
  FL[3] = eax;  // @47_4ef3f0
  L4ef498:;
  FL[2] = (eax & eax);  // @49_4ef3f0
  if (FL[2] != 0) goto L4ef4d7;  // @50_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 168), sizeof v); (u32)v; });  // @51_4ef3f0
  FL[0] = eax; FL[1] = (u32)(55);  // @52_4ef3f0
  if (FL[0] == FL[1]) goto L4ef4ac;  // @53_4ef3f0
  FL[0] = eax; FL[1] = (u32)(56);  // @54_4ef3f0
  if (FL[0] != FL[1]) goto L4ef4d7;  // @55_4ef3f0
  L4ef4ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 248)))(ecx, (u32)(35));  // @59_4ef3f0
  ecx = edx = 0;  // @60_4ef3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @61_4ef3f0
  edx = (u32)(6915192);  // @62_4ef3f0
  L4ef4c7:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @64_4ef3f0
  edx = (u32)(edx + 1);  // @65_4ef3f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @66_4ef3f0
  eax = (u32)(eax + 1);  // @67_4ef3f0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @68_4ef3f0
  if (FL[2] != 0) goto L4ef4c7;  // @69_4ef3f0
  goto L4ef51e;  // @70_4ef3f0
  L4ef4d7:;
  ecx = (u32)(edx + 1);  // @72_4ef3f0
  L4ef4e0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @74_4ef3f0
  edx = (edx + 1);  // @75_4ef3f0
  FL[3] = edx;  // @76_4ef3f0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @77_4ef3f0
  if (FL[2] != 0) goto L4ef4e0;  // @78_4ef3f0
  edx = (edx - ecx);  // @79_4ef3f0
  FL[3] = edx;  // @80_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @81_4ef3f0
  eax = (u32)(edx + 1);  // @82_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_4ef3f0
  eax = (eax & 0xffff);  // @84_4ef3f0
  PV[3] = (u32)(eax);  // @85_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 248)))(ecx, PV[3]);  // @86_4ef3f0
  ecx = edx = 0;  // @87_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @88_4ef3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 155), &v, sizeof v); }  // @89_4ef3f0
  L4ef510:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @91_4ef3f0
  edx = (u32)(edx + 1);  // @92_4ef3f0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @93_4ef3f0
  eax = (u32)(eax + 1);  // @94_4ef3f0
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @95_4ef3f0
  if (FL[2] != 0) goto L4ef510;  // @96_4ef3f0
  L4ef51e:;
  eax = (u32)(EBP - 164);  // @98_4ef3f0
  ecx = edi;  // @99_4ef3f0
  PV[4] = (u32)(eax);  // @100_4ef3f0
  eax = ext_4e12e0_thiscall3(ecx, PV[4], (u32)(1));  // @101_4ef3f0
    // @102_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @103_4ef3f0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @104_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @105_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[5]);  // @107_4ef3f0
  ecx = edx = 0;  // @108_4ef3f0
  FL[2] = (eax & eax);  // @109_4ef3f0
  if (FL[2] == 0) goto L4ef555;  // @110_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_4ef3f0
  ecx = esi;  // @112_4ef3f0
  PV[6] = (u32)(eax);  // @113_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 636)))(ecx, PV[6]);  // @114_4ef3f0
  ecx = edx = 0;  // @115_4ef3f0
  goto L4ef5c0;  // @116_4ef3f0
  L4ef555:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @118_4ef3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6912796), (u32)(1312));  // @120_4ef3f0
  ecx = edx = 0;  // @121_4ef3f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_4ef3f0
  edi = eax;  // @123_4ef3f0
  eax = (u32)(EBP - 156);  // @124_4ef3f0
  ecx = esi;  // @125_4ef3f0
  PV[7] = (u32)(eax);  // @126_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[7], (u32)(1));  // @127_4ef3f0
  ecx = edx = 0;  // @128_4ef3f0
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; });  // @129_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @130_4ef3f0
  ecx = eax;  // @131_4ef3f0
  reg.state = (s32)((u32)(0));  // @132_4ef3f0
  eax = ext_4cc1d0_thiscall1(ecx);  // @133_4ef3f0
    // @134_4ef3f0
  PV[9] = (u32)(eax);  // @135_4ef3f0
  PV[10] = (u32)(edi);  // @136_4ef3f0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(PV[10], (u32)(6915228), PV[9], PV[8]);  // @137_4ef3f0
  ecx = edx = 0;  // @138_4ef3f0
  reg.state = (s32)((u32)(4294967295));  // @139_4ef3f0
  ecx = (u32)(EBP - 156);  // @140_4ef3f0
  eax = ext_4cbec0_thiscall1(ecx);  // @141_4ef3f0
  ecx = edx = 0;  // @142_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @143_4ef3f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 172), sizeof v); (u32)v; });  // @144_4ef3f0
  L4ef5c0:;
  eax = (u32)(EBP - 28);  // @146_4ef3f0
  ecx = edi;  // @147_4ef3f0
  PV[11] = (u32)(eax);  // @148_4ef3f0
  eax = ext_4e12f0_thiscall3(ecx, PV[11], (u32)(3));  // @149_4ef3f0
  ecx = edx = 0;  // @150_4ef3f0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; });  // @151_4ef3f0
  X1[1] = 0;  // @152_4ef3f0
  X1[2] = 0;  // @153_4ef3f0
  X1[3] = 0;  // @154_4ef3f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @155_4ef3f0
  X0[1] = 0;  // @156_4ef3f0
  X0[2] = 0;  // @157_4ef3f0
  X0[3] = 0;  // @158_4ef3f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @159_4ef3f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_4ef3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 168), sizeof v); (u32)v; });  // @161_4ef3f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6915412) + 0), 4); v; })));  // @162_4ef3f0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edx = (u32)r_; }  // @163_4ef3f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @164_4ef3f0
  X0[1] = 0;  // @165_4ef3f0
  X0[2] = 0;  // @166_4ef3f0
  X0[3] = 0;  // @167_4ef3f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @168_4ef3f0
  edx = (edx & (u32)(16711680));  // @169_4ef3f0
  FL[3] = edx;  // @170_4ef3f0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @171_4ef3f0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @172_4ef3f0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @173_4ef3f0
  X0[1] = 0;  // @174_4ef3f0
  X0[2] = 0;  // @175_4ef3f0
  X0[3] = 0;  // @176_4ef3f0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @177_4ef3f0
  eax = (eax & 0xff);  // @178_4ef3f0
  edx = (edx | eax);  // @179_4ef3f0
  FL[3] = edx;  // @180_4ef3f0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6915408) + 0), 4); v; })));  // @181_4ef3f0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @182_4ef3f0
  eax = (eax & (u32)(65280));  // @183_4ef3f0
  FL[3] = eax;  // @184_4ef3f0
  edx = (edx | eax);  // @185_4ef3f0
  FL[3] = edx;  // @186_4ef3f0
  PV[12] = (u32)(edx);  // @187_4ef3f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 584)))(ecx, PV[12]);  // @188_4ef3f0
  ecx = edx = 0;  // @189_4ef3f0
  ecx = edi;  // @190_4ef3f0
  eax = ext_4e1b30_thiscall1(ecx);  // @191_4ef3f0
  ecx = edx = 0;  // @192_4ef3f0
  SEH_LEAVE();  // @193_4ef3f0
  ext_633654(G(u32, 0x6f5630));  // @194_4ef3f0
  return eax;  // @195_4ef3f0
}
PCREG(4ef3f0, lifted_4ef3f0);

