// batch242018.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634db2_dbl2(double, double) __asm__("ext_634db2");
extern "C" double VECTORCALL ext_634dd6_dbl(double) __asm__("ext_634dd6");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_4e0030_fastcall2(u32, u32) __asm__("ext_4e0030");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_440530_thiscall1(u32) __asm__("ext_440530");
extern "C" u32 THISCALL ext_441730_thiscall1(u32) __asm__("ext_441730");
extern "C" u32 THISCALL ext_460aa0_thiscall3(u32, u32, u32) __asm__("ext_460aa0");
extern "C" u32 THISCALL ext_48aad0_thiscall1(u32) __asm__("ext_48aad0");
extern "C" u32 THISCALL ext_4bf520_thiscall2(u32, u32) __asm__("ext_4bf520");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c0160(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4c0160
  edi = ecx;  // @1_4c0160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_4c0160
  if (FL[0] == FL[1]) goto L4c091f;  // @3_4c0160
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 109), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_4c0160
  if (FL[0] == FL[1]) goto L4c091f;  // @5_4c0160
  ecx = (u32)(6880376);  // @6_4c0160
  eax = ext_441730_thiscall1(ecx);  // @7_4c0160
  ecx = edx = 0;  // @8_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 141), sizeof v); (u32)v; });  // @9_4c0160
  X4[0] = 0;  // @10_4c0160
  X4[1] = 0;  // @11_4c0160
  X4[2] = 0;  // @12_4c0160
  X4[3] = 0;  // @13_4c0160
  X2[0] = X4[0];  // @14_4c0160
  X2[1] = X4[1];  // @15_4c0160
  X2[2] = X4[2];  // @16_4c0160
  X2[3] = X4[3];  // @17_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X4[0], 4);  // @18_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X2[0], 4);  // @19_4c0160
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 137), sizeof v); (u32)v; });  // @29_4c0160
  if (FL[0] < FL[1]) goto L4c0415;  // @30_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 141), &v, sizeof v); }  // @31_4c0160
  ebx = (u32)(edi + 80);  // @32_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @33_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @34_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @35_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 100), &v, sizeof v); }  // @36_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 96), &v, sizeof v); }  // @37_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 92), &v, sizeof v); }  // @38_4c0160
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @39_4c0160
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @40_4c0160
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @41_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @43_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @45_4c0160
  ecx = edx = 0;  // @46_4c0160
  FL[0] = eax; FL[1] = (u32)(3);  // @47_4c0160
  if (FL[0] > FL[1]) goto L4c03e5;  // @48_4c0160
  switch (eax) {  // @49_4c0160
  case 0: goto L4c03e5;  // @50_4c0160
  case 1: goto L4c0267;  // @51_4c0160
  case 2: goto L4c02e6;  // @52_4c0160
  case 3: goto L4c0356;  // @53_4c0160
  default: __builtin_trap(); }  // @54_4c0160
  L4c0267:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @57_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @59_4c0160
  ecx = edx = 0;  // @60_4c0160
  FL[2] = (eax & eax);  // @61_4c0160
  if (FL[2] == 0) goto L4c091d;  // @62_4c0160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_4c0160
  ecx = (u32)(edi + 173);  // @64_4c0160
  PV[0] = (u32)(ebx);  // @65_4c0160
  PV[1] = (u32)(ecx);  // @66_4c0160
  ecx = eax;  // @67_4c0160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[1], PV[0]);  // @68_4c0160
  ecx = edx = 0;  // @69_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @73_4c0160
  ecx = edx = 0;  // @74_4c0160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @75_4c0160
  ecx = (u32)(EBP - 88);  // @76_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_4c0160
  { u32 v = (u32)((u32)(6820640)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @78_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_4c0160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @80_4c0160
  eax = ext_48aad0_thiscall1(ecx);  // @81_4c0160
  ecx = edx = 0;  // @82_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_4c0160
  PV[2] = (u32)(eax);  // @84_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @85_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[2]);  // @86_4c0160
  ecx = edx = 0;  // @87_4c0160
  FL[2] = (eax & eax);  // @88_4c0160
  if (FL[2] == 0) goto L4c091d;  // @89_4c0160
  ecx = (u32)(EBP - 76);  // @90_4c0160
  goto L4c0406;  // @91_4c0160
  L4c02e6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @93_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @94_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @96_4c0160
  ecx = edx = 0;  // @97_4c0160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @98_4c0160
  ecx = (u32)(EBP - 88);  // @99_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4c0160
  { u32 v = (u32)((u32)(6820640)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @101_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4c0160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @103_4c0160
  eax = ext_48aad0_thiscall1(ecx);  // @104_4c0160
  ecx = edx = 0;  // @105_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_4c0160
  PV[3] = (u32)(eax);  // @107_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @108_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[3]);  // @109_4c0160
  ecx = edx = 0;  // @110_4c0160
  FL[2] = (eax & eax);  // @111_4c0160
  if (FL[2] == 0) goto L4c091d;  // @112_4c0160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @113_4c0160
  ecx = (u32)(edi + 173);  // @114_4c0160
  PV[4] = (u32)(ebx);  // @115_4c0160
  PV[5] = (u32)(ecx);  // @116_4c0160
  ecx = eax;  // @117_4c0160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[5], PV[4]);  // @118_4c0160
  ecx = edx = 0;  // @119_4c0160
  ecx = ebx;  // @120_4c0160
  eax = ext_4e09b0_thiscall1(ecx);  // @121_4c0160
    // @122_4c0160
  ecx = (u32)(edi + 104);  // @123_4c0160
  eax = ext_4e09b0_thiscall1(ecx);  // @124_4c0160
    // @125_4c0160
  goto L4c0412;  // @126_4c0160
  L4c0356:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @128_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @129_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @130_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @131_4c0160
  ecx = edx = 0;  // @132_4c0160
  FL[2] = (eax & eax);  // @133_4c0160
  if (FL[2] == 0) goto L4c091d;  // @134_4c0160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @135_4c0160
  ecx = (u32)(edi + 173);  // @136_4c0160
  PV[6] = (u32)(ebx);  // @137_4c0160
  PV[7] = (u32)(ecx);  // @138_4c0160
  ecx = eax;  // @139_4c0160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[7], PV[6]);  // @140_4c0160
  ecx = edx = 0;  // @141_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @143_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @144_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @145_4c0160
  ecx = edx = 0;  // @146_4c0160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @147_4c0160
  ecx = (u32)(EBP - 88);  // @148_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_4c0160
  { u32 v = (u32)((u32)(6820640)); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @150_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @151_4c0160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @152_4c0160
  eax = ext_48aad0_thiscall1(ecx);  // @153_4c0160
  ecx = edx = 0;  // @154_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @155_4c0160
  PV[8] = (u32)(eax);  // @156_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @157_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[8]);  // @158_4c0160
  ecx = edx = 0;  // @159_4c0160
  FL[2] = (eax & eax);  // @160_4c0160
  if (FL[2] == 0) goto L4c091d;  // @161_4c0160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @162_4c0160
  ecx = (u32)(edi + 92);  // @163_4c0160
  PV[9] = (u32)(ecx);  // @164_4c0160
  ecx = (u32)(EBP - 76);  // @165_4c0160
  PV[10] = (u32)(ecx);  // @166_4c0160
  ecx = eax;  // @167_4c0160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[10], PV[9]);  // @168_4c0160
  ecx = edx = 0;  // @169_4c0160
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 104), &v, sizeof v); }  // @170_4c0160
  goto L4c0412;  // @171_4c0160
  L4c03e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @174_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @175_4c0160
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 192)))(ecx);  // @176_4c0160
  ecx = edx = 0;  // @177_4c0160
  FL[2] = (eax & eax);  // @178_4c0160
  if (FL[2] == 0) goto L4c091d;  // @179_4c0160
  ecx = (u32)(edi + 173);  // @180_4c0160
  L4c0406:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @182_4c0160
  PV[11] = (u32)(ebx);  // @183_4c0160
  PV[12] = (u32)(ecx);  // @184_4c0160
  ecx = eax;  // @185_4c0160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[12], PV[11]);  // @186_4c0160
  ecx = edx = 0;  // @187_4c0160
  L4c0412:;
  X4[0] = 0;  // @189_4c0160
  X4[1] = 0;  // @190_4c0160
  X4[2] = 0;  // @191_4c0160
  X4[3] = 0;  // @192_4c0160
  L4c0415:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 105), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @194_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 133), &v, sizeof v); }  // @195_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 149), &v, sizeof v); }  // @196_4c0160
  if (FL[0] <= FL[1]) goto L4c0851;  // @197_4c0160
  ebx = (u32)(edi + 80);  // @198_4c0160
  L4c0440:;
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 141), sizeof v); (u32)v; });  // @200_4c0160
  ecx = edi;  // @201_4c0160
  eax = ext_4bf520_thiscall2(ecx, PV[13]);  // @202_4c0160
  ecx = edx = 0;  // @203_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @204_4c0160
  PV[14] = (u32)(eax);  // @205_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @206_4c0160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 109), sizeof v); (u32)v; });  // @208_4c0160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @209_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 48)))(ecx, PV[14]);  // @210_4c0160
  ecx = edx = 0;  // @211_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @212_4c0160
  PV[15] = (u32)(eax);  // @213_4c0160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @214_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[15]);  // @215_4c0160
  ecx = edx = 0;  // @216_4c0160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @217_4c0160
  esi = eax;  // @218_4c0160
  if (FL[0] == FL[1]) goto L4c048a;  // @219_4c0160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @220_4c0160
  ecx = (u32)(edi + 92);  // @221_4c0160
  PV[16] = (u32)(ecx);  // @222_4c0160
  ecx = esi;  // @223_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[16]);  // @224_4c0160
  ecx = edx = 0;  // @225_4c0160
  L4c048a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @227_4c0160
  ecx = esi;  // @228_4c0160
  PV[17] = (u32)(ebx);  // @229_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[17]);  // @230_4c0160
  ecx = edx = 0;  // @231_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 197) + 0), 4); v; });  // @232_4c0160
  X0[1] = 0;  // @233_4c0160
  X0[2] = 0;  // @234_4c0160
  X0[3] = 0;  // @235_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @236_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 201) + 0), 4); v; });  // @237_4c0160
  X0[1] = 0;  // @238_4c0160
  X0[2] = 0;  // @239_4c0160
  X0[3] = 0;  // @240_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @241_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 205) + 0), 4); v; });  // @242_4c0160
  X0[1] = 0;  // @243_4c0160
  X0[2] = 0;  // @244_4c0160
  X0[3] = 0;  // @245_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @246_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 121) + 0), 4); v; });  // @247_4c0160
  X0[1] = 0;  // @248_4c0160
  X0[2] = 0;  // @249_4c0160
  X0[3] = 0;  // @250_4c0160
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @251_4c0160
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 153) + 0), 4); v; })));  // @252_4c0160
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @253_4c0160
  { double r_ = ext_634dd6_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @254_4c0160
  ecx = edx = 0;  // @255_4c0160
  SD(&X0[0], U2D(X0[0], X0[1]) / U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 4), 4); v; })));  // @256_4c0160
  ecx = (u32)(esi + 28);  // @257_4c0160
  ebx = 0;  // @258_4c0160
  FL[3] = ebx;  // @259_4c0160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @260_4c0160
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @261_4c0160
  __builtin_memcpy((void *)((u32)(edi + 169) + 0), &X0[0], 4);  // @262_4c0160
  L4c0500:;
  eax = ebx;  // @264_4c0160
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 149), sizeof v); (u32)v; }));  // @265_4c0160
  FL[3] = eax;  // @266_4c0160
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 141), sizeof v); (u32)v; }));  // @267_4c0160
  FL[3] = eax;  // @268_4c0160
  PV[18] = (u32)(ecx);  // @269_4c0160
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @270_4c0160
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @271_4c0160
  eax = (eax >> (u32)(31));  // @272_4c0160
  FL[3] = eax;  // @273_4c0160
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @274_4c0160
  eax = (u32)(EBP - 28);  // @275_4c0160
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @276_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @277_4c0160
  X0[1] = 0;  // @278_4c0160
  X0[2] = 0;  // @279_4c0160
  X0[3] = 0;  // @280_4c0160
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 129) + 0), 4); v; })));  // @281_4c0160
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 125) + 0), 4); v; })));  // @282_4c0160
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @283_4c0160
  PV[19] = X0[0];  // @284_4c0160
  PV[20] = (u32)(eax);  // @285_4c0160
  eax = ext_460aa0_thiscall3(ecx, PV[20], PV[19]);  // @286_4c0160
  ecx = edx = 0;  // @287_4c0160
  eax = (u32)(EBP - 28);  // @288_4c0160
  PV[21] = (u32)(eax);  // @289_4c0160
  edx = (u32)(edi + 80);  // @290_4c0160
  ecx = (u32)(EBP - 40);  // @291_4c0160
  eax = ext_43e920_fastcall3(ecx, edx, PV[21]);  // @292_4c0160
  ecx = edx = 0;  // @293_4c0160
  edx = (u32)(EBP - 16);  // @294_4c0160
  ecx = (u32)(EBP - 40);  // @295_4c0160
  eax = ext_4e0030_fastcall2(ecx, edx);  // @296_4c0160
  ecx = edx = 0;  // @297_4c0160
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 104), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @298_4c0160
  edx = (u32)(EBP - 28);  // @299_4c0160
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 100)) :: "st");  // @300_4c0160
  ecx = (u32)(edi + 92);  // @301_4c0160
  if (FL[0] != FL[1]) goto L4c057a;  // @302_4c0160
  ecx = (u32)(edi + 80);  // @303_4c0160
  L4c057a:;
  eax = ext_4e0870_fastcall2(ecx, edx);  // @305_4c0160
  ecx = edx = 0;  // @306_4c0160
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6806016)) : "st");  // @307_4c0160
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 153) + 0), 4); v; });  // @308_4c0160
  X2[1] = 0;  // @309_4c0160
  X2[2] = 0;  // @310_4c0160
  X2[3] = 0;  // @311_4c0160
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @312_4c0160
  X3[1] = 0;  // @313_4c0160
  X3[2] = 0;  // @314_4c0160
  X3[3] = 0;  // @315_4c0160
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 96)) :: "st");  // @316_4c0160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @317_4c0160
  X1[1] = 0;  // @318_4c0160
  X1[2] = 0;  // @319_4c0160
  X1[3] = 0;  // @320_4c0160
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4c0617;  // @321_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 121) + 0), 4); v; });  // @322_4c0160
  X0[1] = 0;  // @323_4c0160
  X0[2] = 0;  // @324_4c0160
  X0[3] = 0;  // @325_4c0160
  X0[0] = F2U(U2F(X0[0]) / U2F(X3[0]));  // @326_4c0160
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @327_4c0160
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L4c0617;  // @328_4c0160
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @329_4c0160
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @330_4c0160
  { double r_ = ext_634dd6_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @331_4c0160
  ecx = edx = 0;  // @332_4c0160
  SD(&X0[0], U2D(X0[0], X0[1]) / U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 4), 4); v; })));  // @333_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @334_4c0160
  PV[22] = (u32)(ecx);  // @335_4c0160
  ecx = edi;  // @336_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @337_4c0160
  X2[0] = 0;  // @338_4c0160
  X2[1] = 0;  // @339_4c0160
  X2[2] = 0;  // @340_4c0160
  X2[3] = 0;  // @341_4c0160
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @342_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 161) + 0), 4); v; });  // @343_4c0160
  X0[1] = 0;  // @344_4c0160
  X0[2] = 0;  // @345_4c0160
  X0[3] = 0;  // @346_4c0160
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @347_4c0160
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @348_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @349_4c0160
  X0[1] = 0;  // @350_4c0160
  X0[2] = 0;  // @351_4c0160
  X0[3] = 0;  // @352_4c0160
  PV[23] = X0[0];  // @353_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X2[0], 4);  // @354_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[23]);  // @355_4c0160
  ecx = edx = 0;  // @356_4c0160
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi + 165)) : "st");  // @357_4c0160
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 80)) :: "st");  // @358_4c0160
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @359_4c0160
  X5[1] = 0;  // @360_4c0160
  X5[2] = 0;  // @361_4c0160
  X5[3] = 0;  // @362_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X5[0], 4);  // @363_4c0160
  goto L4c06a9;  // @364_4c0160
  L4c0617:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 121) + 0), 4); v; });  // @366_4c0160
  X0[1] = 0;  // @367_4c0160
  X0[2] = 0;  // @368_4c0160
  X0[3] = 0;  // @369_4c0160
  X0[0] = F2U(U2F(X0[0]) / U2F(X3[0]));  // @370_4c0160
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @371_4c0160
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c06a4;  // @372_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @373_4c0160
  X1[0] = F2U(U2F(X1[0]) / U2F(X2[0]));  // @374_4c0160
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @375_4c0160
  { double r_ = ext_634dd6_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @376_4c0160
  ecx = edx = 0;  // @377_4c0160
  SD(&X0[0], U2D(X0[0], X0[1]) / U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6896960) + 4), 4); v; })));  // @378_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @379_4c0160
  PV[24] = (u32)(ecx);  // @380_4c0160
  ecx = edi;  // @381_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 132), sizeof v); (u32)v; });  // @382_4c0160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 161) + 0), 4); v; });  // @383_4c0160
  X1[1] = 0;  // @384_4c0160
  X1[2] = 0;  // @385_4c0160
  X1[3] = 0;  // @386_4c0160
  X2[0] = 0;  // @387_4c0160
  X2[1] = 0;  // @388_4c0160
  X2[2] = 0;  // @389_4c0160
  X2[3] = 0;  // @390_4c0160
  X2[0] = F2U((float)U2D(X0[0], X0[1]));  // @391_4c0160
  X0[0] = X1[0];  // @392_4c0160
  X0[1] = X1[1];  // @393_4c0160
  X0[2] = X1[2];  // @394_4c0160
  X0[3] = X1[3];  // @395_4c0160
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @396_4c0160
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6836864) + 0), 4); v; })));  // @397_4c0160
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 169) + 0), 4); v; })));  // @398_4c0160
  X2[0] = F2U(U2F(X2[0]) * U2F(X0[0]));  // @399_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @400_4c0160
  X0[1] = 0;  // @401_4c0160
  X0[2] = 0;  // @402_4c0160
  X0[3] = 0;  // @403_4c0160
  PV[25] = X0[0];  // @404_4c0160
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @405_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 92) + 0), &X2[0], 4);  // @406_4c0160
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[25]);  // @407_4c0160
  ecx = edx = 0;  // @408_4c0160
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(edi + 165)) : "st");  // @409_4c0160
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 80)) :: "st");  // @410_4c0160
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @411_4c0160
  X5[1] = 0;  // @412_4c0160
  X5[2] = 0;  // @413_4c0160
  X5[3] = 0;  // @414_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X5[0], 4);  // @415_4c0160
  goto L4c06a9;  // @416_4c0160
  L4c06a4:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @418_4c0160
  X5[1] = 0;  // @419_4c0160
  X5[2] = 0;  // @420_4c0160
  X5[3] = 0;  // @421_4c0160
  L4c06a9:;
  X4[0] = 0;  // @423_4c0160
  X4[1] = 0;  // @424_4c0160
  X4[2] = 0;  // @425_4c0160
  X4[3] = 0;  // @426_4c0160
  if (((!(U2F(X5[0]) >= U2F(X4[0]))) || (!((U2F(X5[0]) < U2F(X4[0])) || (U2F(X5[0]) > U2F(X4[0])))))) goto L4c0762;  // @427_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @428_4c0160
  X0[1] = 0;  // @429_4c0160
  X0[2] = 0;  // @430_4c0160
  X0[3] = 0;  // @431_4c0160
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @432_4c0160
  X2[1] = 0;  // @433_4c0160
  X2[2] = 0;  // @434_4c0160
  X2[3] = 0;  // @435_4c0160
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; });  // @436_4c0160
  X3[1] = 0;  // @437_4c0160
  X3[2] = 0;  // @438_4c0160
  X3[3] = 0;  // @439_4c0160
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L4c06e5;  // @440_4c0160
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @441_4c0160
  if (((!(U2F(X0[0]) >= U2F(X3[0]))) || (!((U2F(X0[0]) < U2F(X3[0])) || (U2F(X0[0]) > U2F(X3[0])))))) goto L4c06dc;  // @442_4c0160
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X2[0], 4);  // @443_4c0160
  goto L4c0703;  // @444_4c0160
  L4c06dc:;
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @446_4c0160
  X0[0] = X2[0];  // @447_4c0160
  X0[1] = X2[1];  // @448_4c0160
  X0[2] = X2[2];  // @449_4c0160
  X0[3] = X2[3];  // @450_4c0160
  goto L4c06f5;  // @451_4c0160
  L4c06e5:;
  X1[0] = X2[0];  // @453_4c0160
  X1[1] = X2[1];  // @454_4c0160
  X1[2] = X2[2];  // @455_4c0160
  X1[3] = X2[3];  // @456_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @457_4c0160
  if (((!(U2F(X3[0]) >= U2F(X1[0]))) || (!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))))) goto L4c0703;  // @458_4c0160
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @459_4c0160
  L4c06f5:;
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 6895112) + 0), 4); v; })));  // @461_4c0160
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X0[0], 4);  // @462_4c0160
  L4c0703:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @464_4c0160
  X1[1] = 0;  // @465_4c0160
  X1[2] = 0;  // @466_4c0160
  X1[3] = 0;  // @467_4c0160
  X0[0] = X5[0];  // @468_4c0160
  X0[1] = X5[1];  // @469_4c0160
  X0[2] = X5[2];  // @470_4c0160
  X0[3] = X5[3];  // @471_4c0160
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @472_4c0160
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c073e;  // @473_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @474_4c0160
  if (((!(U2F(X1[0]) >= U2F(X3[0]))) || (!((U2F(X1[0]) < U2F(X3[0])) || (U2F(X1[0]) > U2F(X3[0])))))) goto L4c0727;  // @475_4c0160
  __builtin_memcpy((void *)((u32)(edi + 72) + 0), &X0[0], 4);  // @476_4c0160
  goto L4c0809;  // @477_4c0160
  L4c0727:;
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @479_4c0160
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 6895112) + 0), 4); v; })));  // @480_4c0160
  __builtin_memcpy((void *)((u32)(edi + 72) + 0), &X0[0], 4);  // @481_4c0160
  goto L4c0809;  // @482_4c0160
  L4c073e:;
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @484_4c0160
  if (((!(U2F(X3[0]) >= U2F(X0[0]))) || (!((U2F(X3[0]) < U2F(X0[0])) || (U2F(X3[0]) > U2F(X0[0])))))) goto L4c0809;  // @485_4c0160
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @486_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 6895112) + 0), 4); v; })));  // @487_4c0160
  __builtin_memcpy((void *)((u32)(edi + 72) + 0), &X1[0], 4);  // @488_4c0160
  goto L4c0809;  // @489_4c0160
  L4c0762:;
  if (((!(U2F(X4[0]) >= U2F(X5[0]))) || (!((U2F(X4[0]) < U2F(X5[0])) || (U2F(X4[0]) > U2F(X5[0])))))) goto L4c0809;  // @491_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @492_4c0160
  X0[1] = 0;  // @493_4c0160
  X0[2] = 0;  // @494_4c0160
  X0[3] = 0;  // @495_4c0160
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @496_4c0160
  X2[1] = 0;  // @497_4c0160
  X2[2] = 0;  // @498_4c0160
  X2[3] = 0;  // @499_4c0160
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818432) + 0), 4); v; });  // @500_4c0160
  X3[1] = 0;  // @501_4c0160
  X3[2] = 0;  // @502_4c0160
  X3[3] = 0;  // @503_4c0160
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L4c079b;  // @504_4c0160
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @505_4c0160
  if (((!(U2F(X0[0]) >= U2F(X3[0]))) || (!((U2F(X0[0]) < U2F(X3[0])) || (U2F(X0[0]) > U2F(X3[0])))))) goto L4c0792;  // @506_4c0160
  __builtin_memcpy((void *)((u32)(edi + 72) + 0), &X2[0], 4);  // @507_4c0160
  goto L4c07b9;  // @508_4c0160
  L4c0792:;
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @510_4c0160
  X0[0] = X2[0];  // @511_4c0160
  X0[1] = X2[1];  // @512_4c0160
  X0[2] = X2[2];  // @513_4c0160
  X0[3] = X2[3];  // @514_4c0160
  goto L4c07ab;  // @515_4c0160
  L4c079b:;
  X1[0] = X2[0];  // @517_4c0160
  X1[1] = X2[1];  // @518_4c0160
  X1[2] = X2[2];  // @519_4c0160
  X1[3] = X2[3];  // @520_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @521_4c0160
  if (((!(U2F(X3[0]) >= U2F(X1[0]))) || (!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))))) goto L4c07b9;  // @522_4c0160
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @523_4c0160
  L4c07ab:;
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 6895112) + 0), 4); v; })));  // @525_4c0160
  __builtin_memcpy((void *)((u32)(edi + 72) + 0), &X0[0], 4);  // @526_4c0160
  L4c07b9:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; });  // @528_4c0160
  X1[1] = 0;  // @529_4c0160
  X1[2] = 0;  // @530_4c0160
  X1[3] = 0;  // @531_4c0160
  X0[0] = X2[0];  // @532_4c0160
  X0[1] = X2[1];  // @533_4c0160
  X0[2] = X2[2];  // @534_4c0160
  X0[3] = X2[3];  // @535_4c0160
  X0[0] = F2U(U2F(X0[0]) - U2F(X5[0]));  // @536_4c0160
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4c07ee;  // @537_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @538_4c0160
  if (((!(U2F(X1[0]) >= U2F(X3[0]))) || (!((U2F(X1[0]) < U2F(X3[0])) || (U2F(X1[0]) > U2F(X3[0])))))) goto L4c07da;  // @539_4c0160
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X0[0], 4);  // @540_4c0160
  goto L4c0809;  // @541_4c0160
  L4c07da:;
  { float f_ = U2F(X1[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @543_4c0160
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 6895112) + 0), 4); v; })));  // @544_4c0160
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X0[0], 4);  // @545_4c0160
  goto L4c0809;  // @546_4c0160
  L4c07ee:;
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @548_4c0160
  if (((!(U2F(X3[0]) >= U2F(X0[0]))) || (!((U2F(X3[0]) < U2F(X0[0])) || (U2F(X3[0]) > U2F(X0[0])))))) goto L4c0809;  // @549_4c0160
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @550_4c0160
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*4 + 6895112) + 0), 4); v; })));  // @551_4c0160
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X1[0], 4);  // @552_4c0160
  L4c0809:;
  if (((!(U2F(X4[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; })))) || (!((U2F(X4[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; }))) || (U2F(X4[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; }))))))) goto L4c0816;  // @554_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 76), &v, sizeof v); }  // @555_4c0160
  L4c0816:;
  if (((!(U2F(X4[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; })))) || (!((U2F(X4[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; }))) || (U2F(X4[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; }))))))) goto L4c0823;  // @557_4c0160
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 72), &v, sizeof v); }  // @558_4c0160
  L4c0823:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @560_4c0160
  ebx = (ebx + 1);  // @561_4c0160
  FL[3] = ebx;  // @562_4c0160
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 133), sizeof v); (u32)v; });  // @563_4c0160
  if (FL[0] < FL[1]) goto L4c0500;  // @564_4c0160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 141), sizeof v); (u32)v; }) + ebx)); __builtin_memcpy((void *)(u32)(edi + 141), &v, sizeof v); }  // @565_4c0160
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 141), sizeof v); (u32)v; });  // @566_4c0160
  ebx = (u32)(edi + 80);  // @567_4c0160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 133), sizeof v); (u32)v; });  // @568_4c0160
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 149), sizeof v); (u32)v; }));  // @569_4c0160
  FL[3] = eax;  // @570_4c0160
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 105), sizeof v); (u32)v; });  // @571_4c0160
  if (FL[0] < FL[1]) goto L4c0440;  // @572_4c0160
  L4c0851:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 141), sizeof v); (u32)v; });  // @574_4c0160
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 137), sizeof v); (u32)v; });  // @575_4c0160
  if (FL[0] < FL[1]) goto L4c08eb;  // @576_4c0160
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @577_4c0160
  X2[1] = 0;  // @578_4c0160
  X2[2] = 0;  // @579_4c0160
  X2[3] = 0;  // @580_4c0160
  X0[0] = X2[0];  // @581_4c0160
  X0[1] = X2[1];  // @582_4c0160
  X0[2] = X2[2];  // @583_4c0160
  X0[3] = X2[3];  // @584_4c0160
  { float a_ = U2F(X0[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; })); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @585_4c0160
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; })));  // @586_4c0160
  { float a_ = U2F(X4[0]), b_ = U2F(X0[0]); X4[0] = (a_ > b_) ? X4[0] : F2U(b_); }  // @587_4c0160
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X2[0], 4);  // @588_4c0160
  if ((!(U2F(X4[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; }))))) goto L4c089b;  // @589_4c0160
  PV[28] = 0; PV[27] = 0; goto L4c0909;  // @590_4c0160 hand fix
  L4c089b:;
  X4[0] = F2U(U2F(X4[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @592_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6891408) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @593_4c0160
  { double a_ = (double)U2F(X4[0]), b_ = (double)U2F(X4[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @594_4c0160
  { double r_ = ext_634db2_dbl2(U2D(X0[0], X0[1]), U2D(X1[0], X1[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @595_4c0160
  ecx = edx = 0;  // @596_4c0160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 0), 4); v; }); X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 4), 4); v; }); X1[2] = X1[3] = 0;  // @597_4c0160
  SD(&X1[0], U2D(X1[0], X1[1]) / U2D(X0[0], X0[1]));  // @598_4c0160
  { float a_ = (float)U2D(X1[0], X1[1]), b_ = (float)U2D(X1[2], X1[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @599_4c0160
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @600_4c0160
  X1[1] = 0;  // @601_4c0160
  X1[2] = 0;  // @602_4c0160
  X1[3] = 0;  // @603_4c0160
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @604_4c0160
  __builtin_memcpy((void *)((u32)(edi + 210) + 0), &X0[0], 4);  // @605_4c0160
  __builtin_memcpy((void *)((u32)(edi + 214) + 0), &X1[0], 4);  // @606_4c0160
  PV[27] = X1[0];  // @607_4c0160
  goto L4c0904;  // @608_4c0160
  L4c08eb:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 214) + 0), 4); v; });  // @610_4c0160
  X0[1] = 0;  // @611_4c0160
  X0[2] = 0;  // @612_4c0160
  X0[3] = 0;  // @613_4c0160
  PV[27] = X0[0];  // @614_4c0160
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 210) + 0), 4); v; });  // @615_4c0160
  X0[1] = 0;  // @616_4c0160
  X0[2] = 0;  // @617_4c0160
  X0[3] = 0;  // @618_4c0160
  L4c0904:;
  PV[28] = X0[0];  // @620_4c0160
  L4c0909:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @622_4c0160
  ecx = edi;  // @623_4c0160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 136)))(ecx, PV[28], PV[27]);  // @624_4c0160
  ecx = edx = 0;  // @625_4c0160
  ecx = (u32)(6880376);  // @626_4c0160
  eax = ext_440530_thiscall1(ecx);  // @627_4c0160
  ecx = edx = 0;  // @628_4c0160
  L4c091d:;
  L4c091f:;
  ext_633654(G(u32, 0x6f5630));  // @631_4c0160
  return eax;  // @632_4c0160
}
PCREG(4c0160, lifted_4c0160);

