// batch244042.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5ec8b0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @0_5ec8b0
  X2[1] = 0;  // @1_5ec8b0
  X2[2] = 0;  // @2_5ec8b0
  X2[3] = 0;  // @3_5ec8b0
  ebx = ecx;  // @4_5ec8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 98), sizeof v); (u32)v; });  // @6_5ec8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @7_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 203), sizeof v); (u32)v; });  // @8_5ec8b0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 12) + 0), 4); v; });  // @9_5ec8b0
  X4[1] = 0;  // @10_5ec8b0
  X4[2] = 0;  // @11_5ec8b0
  X4[3] = 0;  // @12_5ec8b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @13_5ec8b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; });  // @14_5ec8b0
  edi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @15_5ec8b0
  esi = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; });  // @16_5ec8b0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 8) + 0), 4); v; });  // @17_5ec8b0
  X3[1] = 0;  // @18_5ec8b0
  X3[2] = 0;  // @19_5ec8b0
  X3[3] = 0;  // @20_5ec8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @21_5ec8b0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 6), sizeof v); (u32)v; });  // @22_5ec8b0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @23_5ec8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @24_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; }));  // @25_5ec8b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @26_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @27_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X4[0], 4);  // @28_5ec8b0
  FL[0] = eax; FL[1] = (u32)(3);  // @29_5ec8b0
  if (FL[0] > FL[1]) goto L5ecaad;  // @30_5ec8b0
  switch (eax) {  // @31_5ec8b0
  case 0: goto L5ec916;  // @32_5ec8b0
  case 1: goto L5ec96d;  // @33_5ec8b0
  case 2: goto L5ec9c5;  // @34_5ec8b0
  case 3: goto L5eca45;  // @35_5ec8b0
  default: __builtin_trap(); }  // @36_5ec8b0
  L5ec916:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @38_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @39_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @40_5ec8b0
  eax = (eax >> (u32)(31));  // @41_5ec8b0
  FL[3] = eax;  // @42_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @43_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }));  // @44_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @45_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @46_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @47_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @48_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @49_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @50_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @51_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @52_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @53_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @54_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @55_5ec8b0
  edi = (edi >> (u32)(31));  // @56_5ec8b0
  FL[3] = edi;  // @57_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @58_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @59_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @60_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @61_5ec8b0
  goto L5ecab7;  // @62_5ec8b0
  L5ec96d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @64_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @65_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @66_5ec8b0
  eax = (eax >> (u32)(31));  // @67_5ec8b0
  FL[3] = eax;  // @68_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @69_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }));  // @70_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @71_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @72_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @73_5ec8b0
  edi = (edi >> (u32)(31));  // @74_5ec8b0
  FL[3] = edi;  // @75_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @76_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @77_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @78_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @79_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @80_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @81_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @82_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @83_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @84_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @85_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @86_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @87_5ec8b0
  goto L5ecab7;  // @88_5ec8b0
  L5ec9c5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @90_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @91_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @92_5ec8b0
  eax = (eax >> (u32)(31));  // @93_5ec8b0
  FL[3] = eax;  // @94_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @95_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @96_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @97_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @98_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @99_5ec8b0
  edi = (edi >> (u32)(31));  // @100_5ec8b0
  FL[3] = edi;  // @101_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @102_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @103_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @104_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @105_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 195) + 0), 4); v; })));  // @106_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @107_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @108_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @109_5ec8b0
  eax = (eax >> (u32)(31));  // @110_5ec8b0
  FL[3] = eax;  // @111_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @112_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }));  // @113_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @114_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @115_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @116_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @117_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @118_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @119_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @120_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @121_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @122_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @123_5ec8b0
  goto L5ecab7;  // @124_5ec8b0
  L5eca45:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 195) + 0), 4); v; });  // @126_5ec8b0
  X1[1] = 0;  // @127_5ec8b0
  X1[2] = 0;  // @128_5ec8b0
  X1[3] = 0;  // @129_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }));  // @130_5ec8b0
  X0[0] = edi; X0[1] = X0[2] = X0[3] = 0;  // @131_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @132_5ec8b0
  edi = (edi >> (u32)(31));  // @133_5ec8b0
  FL[3] = edi;  // @134_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @135_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi*8 + 6818464) + 4), 4); v; })));  // @136_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @137_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @138_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @139_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 82), sizeof v); (u32)v; });  // @140_5ec8b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @141_5ec8b0
  FL[3] = eax;  // @142_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @143_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @144_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @145_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @146_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @147_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @148_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @149_5ec8b0
  eax = (eax >> (u32)(31));  // @150_5ec8b0
  FL[3] = eax;  // @151_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @152_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @153_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @154_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @155_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @156_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X1[0], 4);  // @157_5ec8b0
  goto L5ecab7;  // @158_5ec8b0
  L5ecaad:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @160_5ec8b0
  X0[1] = 0;  // @161_5ec8b0
  X0[2] = 0;  // @162_5ec8b0
  X0[3] = 0;  // @163_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @164_5ec8b0
  L5ecab7:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @166_5ec8b0
  FL[0] = edx; FL[1] = (u32)(3);  // @167_5ec8b0
  if (FL[0] > FL[1]) goto L5ecc7a;  // @168_5ec8b0
  switch (edx) {  // @169_5ec8b0
  case 0: goto L5ecaca;  // @170_5ec8b0
  case 1: goto L5ecb22;  // @171_5ec8b0
  case 2: goto L5ecb77;  // @172_5ec8b0
  case 3: goto L5ecbf7;  // @173_5ec8b0
  default: __builtin_trap(); }  // @174_5ec8b0
  L5ecaca:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @176_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @177_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @178_5ec8b0
  eax = (eax >> (u32)(31));  // @179_5ec8b0
  FL[3] = eax;  // @180_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @181_5ec8b0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; }));  // @182_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @183_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @184_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @185_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @186_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @187_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @188_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @189_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @190_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @191_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @192_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @193_5ec8b0
  esi = (esi >> (u32)(31));  // @194_5ec8b0
  FL[3] = esi;  // @195_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @196_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @197_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @198_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @199_5ec8b0
  goto L5ecc84;  // @200_5ec8b0
  L5ecb22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @202_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @203_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @204_5ec8b0
  eax = (eax >> (u32)(31));  // @205_5ec8b0
  FL[3] = eax;  // @206_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @207_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @208_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @209_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @210_5ec8b0
  esi = (esi >> (u32)(31));  // @211_5ec8b0
  FL[3] = esi;  // @212_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @213_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @214_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @215_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @216_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @217_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @218_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @219_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @220_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @221_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @222_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @223_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @224_5ec8b0
  goto L5ecc84;  // @225_5ec8b0
  L5ecb77:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @227_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @228_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @229_5ec8b0
  eax = (eax >> (u32)(31));  // @230_5ec8b0
  FL[3] = eax;  // @231_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @232_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @233_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X1[0] = F2U(a_); X1[1] = F2U(b_); X1[2] = X1[3] = 0; }  // @234_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @235_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @236_5ec8b0
  esi = (esi >> (u32)(31));  // @237_5ec8b0
  FL[3] = esi;  // @238_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @239_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @240_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @241_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @242_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 199) + 0), 4); v; })));  // @243_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @244_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @245_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @246_5ec8b0
  eax = (eax >> (u32)(31));  // @247_5ec8b0
  FL[3] = eax;  // @248_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @249_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @250_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @251_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @252_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @253_5ec8b0
  X0[0] = F2U((float)(s32)X0[0]);  // @254_5ec8b0
  X0[1] = F2U((float)(s32)X0[1]);  // @255_5ec8b0
  X0[2] = F2U((float)(s32)X0[2]);  // @256_5ec8b0
  X0[3] = F2U((float)(s32)X0[3]);  // @257_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @258_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X1[0], 4);  // @259_5ec8b0
  goto L5ecc84;  // @260_5ec8b0
  L5ecbf7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @262_5ec8b0
  ecx = edi;  // @263_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @264_5ec8b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @265_5ec8b0
  ecx = edx = 0;  // @266_5ec8b0
  __asm__ volatile("fld1" ::: "st");  // @267_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 86), sizeof v); (u32)v; });  // @268_5ec8b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @269_5ec8b0
  FL[3] = eax;  // @270_5ec8b0
  __asm__ volatile(".byte 0xde, 0xf1" ::: "st");  // @271_5ec8b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @272_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @273_5ec8b0
  eax = (eax >> (u32)(31));  // @274_5ec8b0
  FL[3] = eax;  // @275_5ec8b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @276_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @277_5ec8b0
  X1[0] = F2U((float)(s32)X1[0]);  // @278_5ec8b0
  X1[1] = F2U((float)(s32)X1[1]);  // @279_5ec8b0
  X1[2] = F2U((float)(s32)X1[2]);  // @280_5ec8b0
  X1[3] = F2U((float)(s32)X1[3]);  // @281_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @282_5ec8b0
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @283_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @284_5ec8b0
  esi = (esi >> (u32)(31));  // @285_5ec8b0
  FL[3] = esi;  // @286_5ec8b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @287_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @288_5ec8b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi*8 + 6818464) + 4), 4); v; })));  // @289_5ec8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @290_5ec8b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @291_5ec8b0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @292_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 199) + 0), 4); v; });  // @293_5ec8b0
  X0[1] = 0;  // @294_5ec8b0
  X0[2] = 0;  // @295_5ec8b0
  X0[3] = 0;  // @296_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @297_5ec8b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @298_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; })));  // @299_5ec8b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @300_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X2[0], 4);  // @301_5ec8b0
  goto L5ecc84;  // @302_5ec8b0
  L5ecc7a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 16) + 0), 4); v; });  // @304_5ec8b0
  X0[1] = 0;  // @305_5ec8b0
  X0[2] = 0;  // @306_5ec8b0
  X0[3] = 0;  // @307_5ec8b0
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @308_5ec8b0
  L5ecc84:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @310_5ec8b0
  ecx = edi;  // @311_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @312_5ec8b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @313_5ec8b0
  ecx = edx = 0;  // @314_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @315_5ec8b0
  ecx = edi;  // @316_5ec8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 16)) :: "st");  // @317_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @318_5ec8b0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @319_5ec8b0
  ecx = edx = 0;  // @320_5ec8b0
  __asm__ volatile("fld1" ::: "st");  // @321_5ec8b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @322_5ec8b0
  X0[1] = 0;  // @323_5ec8b0
  X0[2] = 0;  // @324_5ec8b0
  X0[3] = 0;  // @325_5ec8b0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @326_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @327_5ec8b0
  ecx = (u32)(eax + eax*4);  // @328_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 58), sizeof v); (u32)v; });  // @329_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @330_5ec8b0
  __asm__ volatile(".byte 0xde, 0xf1" ::: "st");  // @331_5ec8b0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @332_5ec8b0
  X2[1] = 0;  // @333_5ec8b0
  X2[2] = 0;  // @334_5ec8b0
  X2[3] = 0;  // @335_5ec8b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @336_5ec8b0
  X1[1] = 0;  // @337_5ec8b0
  X1[2] = 0;  // @338_5ec8b0
  X1[3] = 0;  // @339_5ec8b0
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @340_5ec8b0
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @341_5ec8b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 12)) :: "st");  // @342_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 179) + 0), 4); v; })));  // @343_5ec8b0
  X0[0] = X1[0];  // @344_5ec8b0
  X0[1] = X1[1];  // @345_5ec8b0
  X0[2] = X1[2];  // @346_5ec8b0
  X0[3] = X1[3];  // @347_5ec8b0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; })));  // @348_5ec8b0
  __builtin_memcpy((void *)((u32)(eax + ecx*8) + 0), &X2[0], 4);  // @349_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 183) + 0), 4); v; })));  // @350_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 58), sizeof v); (u32)v; });  // @351_5ec8b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; })));  // @352_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @353_5ec8b0
  __builtin_memcpy((void *)((u32)(eax + ecx*8 + 4) + 0), &X0[0], 4);  // @354_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 58), sizeof v); (u32)v; });  // @355_5ec8b0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 183) + 0), 4); v; })));  // @356_5ec8b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @357_5ec8b0
  __builtin_memcpy((void *)((u32)(eax + ecx*8 + 4) + 0), &X1[0], 4);  // @358_5ec8b0
  return eax;  // @359_5ec8b0
}
PCREG(5ec8b0, lifted_5ec8b0);

