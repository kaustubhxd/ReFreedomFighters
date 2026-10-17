// batch240022.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }
static inline u32 w4a_ftol(u32 fn, u32 xbits, u32 *hi) { float x; __builtin_memcpy(&x, &xbits, 4); u32 a, d;
  asm volatile("call *%[f]" : "=a"(a), "=d"(d), "+Yz"(x) : [f] "r"(fn) : "ecx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "cc", "memory");
  *hi = d; return a; }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4f5e00(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4f5e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @1_4f5e00
  edi = ecx;  // @2_4f5e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @3_4f5e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @5_4f5e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @6_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4f5e00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @8_4f5e00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @9_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 660)))(ecx, (u32)(6923904), (u32)(6921360), (u32)(0), (u32)(1));  // @10_4f5e00
  ecx = edx = 0;  // @11_4f5e00
  ebx = eax;  // @12_4f5e00
  FL[2] = (ebx & ebx);  // @13_4f5e00
  if (FL[2] == 0) goto L4f5e6b;  // @14_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_4f5e00
  ecx = edi;  // @16_4f5e00
  PV[0] = (u32)(esi);  // @17_4f5e00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @18_4f5e00
  PV[2] = (u32)(ebx);  // @19_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 732)))(ecx, PV[2], PV[1], PV[0]);  // @20_4f5e00
  ecx = edx = 0;  // @21_4f5e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @22_4f5e00
  FL[2] = (eax & eax);  // @23_4f5e00
  if (FL[2] != 0) goto L4f5e80;  // @24_4f5e00
  L4f5e5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4f5e00
  ecx = ebx;  // @27_4f5e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @28_4f5e00
  ecx = edx = 0;  // @29_4f5e00
  L4f5e6b:;
  eax = 0;  // @31_4f5e00
  FL[3] = eax;  // @32_4f5e00
  ext_633654(G(u32, 0x6f5630));  // @33_4f5e00
  return eax;  // @34_4f5e00
  L4f5e80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @36_4f5e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_4f5e00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @38_4f5e00
  X0[1] = 0;  // @39_4f5e00
  X0[2] = 0;  // @40_4f5e00
  X0[3] = 0;  // @41_4f5e00
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @42_4f5e00
  { u32 _h; eax = w4a_ftol(0x633910, X0[0], &_h); edx = _h; ecx = 0; }  // @43_4f5e00
  eax = (eax + (u32)(40));  // @44_4f5e00
  FL[3] = eax;  // @45_4f5e00
  ecx = edi;  // @46_4f5e00
  PV[3] = (u32)(eax);  // @47_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @48_4f5e00
  eax = (eax + (u32)(20));  // @49_4f5e00
  FL[3] = eax;  // @50_4f5e00
  PV[4] = (u32)(eax);  // @51_4f5e00
  PV[5] = (u32)(ebx);  // @52_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(esi + 740)))(ecx, PV[5], PV[4], PV[3], (u32)(0));  // @53_4f5e00
  ecx = edx = 0;  // @54_4f5e00
  esi = eax;  // @55_4f5e00
  FL[2] = (esi & esi);  // @56_4f5e00
  if (FL[2] == 0) goto L4f5e5f;  // @57_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @58_4f5e00
  ecx = esi;  // @59_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 620)))(ecx, (u32)(0), (u32)(0), (u32)(1120403456));  // @60_4f5e00
  ecx = edx = 0;  // @61_4f5e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @62_4f5e00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 64) + 0), 4); v; });  // @63_4f5e00
  X0[1] = 0;  // @64_4f5e00
  X0[2] = 0;  // @65_4f5e00
  X0[3] = 0;  // @66_4f5e00
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @67_4f5e00
  { u32 _h; eax = w4a_ftol(0x633910, X0[0], &_h); edx = _h; ecx = 0; }  // @68_4f5e00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 68) + 0), 4); v; });  // @69_4f5e00
  X0[1] = 0;  // @70_4f5e00
  X0[2] = 0;  // @71_4f5e00
  X0[3] = 0;  // @72_4f5e00
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @73_4f5e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @74_4f5e00
  { u32 _h; eax = w4a_ftol(0x633910, X0[0], &_h); edx = _h; ecx = 0; }  // @75_4f5e00
  ecx = eax;  // @76_4f5e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @77_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @78_4f5e00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @79_4f5e00
  ecx = (ecx >> (u32)(1));  // @80_4f5e00
  FL[3] = ecx;  // @81_4f5e00
  ecx = (ecx - (u32)(8));  // @82_4f5e00
  FL[3] = ecx;  // @83_4f5e00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @84_4f5e00
  eax = (eax >> (u32)(1));  // @85_4f5e00
  FL[3] = eax;  // @86_4f5e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @87_4f5e00
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @88_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @89_4f5e00
  ecx = (ecx >> (u32)(31));  // @90_4f5e00
  FL[3] = ecx;  // @91_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx*8 + 6818464) + 4), 4); v; })));  // @92_4f5e00
  ecx = esi;  // @93_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @94_4f5e00
  PV[6] = X0[0];  // @95_4f5e00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @96_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @97_4f5e00
  eax = (eax >> (u32)(31));  // @98_4f5e00
  FL[3] = eax;  // @99_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @100_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @101_4f5e00
  PV[7] = X0[0];  // @102_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 620)))(ecx, PV[7], PV[6], (u32)(1117782016));  // @103_4f5e00
  ecx = edx = 0;  // @104_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_4f5e00
  ecx = esi;  // @106_4f5e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 608)))(ecx, (u32)(68));  // @107_4f5e00
  ecx = edx = 0;  // @108_4f5e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @109_4f5e00
  ecx = edi;  // @110_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @111_4f5e00
  PV[8] = (u32)(esi);  // @112_4f5e00
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; });  // @113_4f5e00
  PV[10] = (u32)(ebx);  // @114_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 736)))(ecx, PV[10], PV[9], PV[8], (u32)(33));  // @115_4f5e00
  ecx = edx = 0;  // @116_4f5e00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @117_4f5e00
  ecx = edi;  // @118_4f5e00
  PV[11] = (u32)(esi);  // @119_4f5e00
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 152), sizeof v); (u32)v; });  // @120_4f5e00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @121_4f5e00
  PV[13] = (u32)(ebx);  // @122_4f5e00
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edx + 736)))(ecx, PV[13], PV[12], PV[11], (u32)(34));  // @123_4f5e00
  ecx = edx = 0;  // @124_4f5e00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @125_4f5e00
  esi = eax;  // @126_4f5e00
  FL[2] = (ecx & ecx);  // @127_4f5e00
  if (FL[2] != 0) goto L4f5fa5;  // @128_4f5e00
  FL[2] = (esi & esi);  // @129_4f5e00
  if (FL[2] != 0) goto L4f5e5f;  // @130_4f5e00
  L4f5fa5:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @132_4f5e00
  edx = (u32)(EBP - 16);  // @133_4f5e00
  PV[14] = (u32)(edx);  // @134_4f5e00
  { u32 v = (u32)((u32)(1117782016)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @135_4f5e00
  eax = (u32)(edi - 8);  // @136_4f5e00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @137_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @138_4f5e00
  eax = (eax >> (u32)(31));  // @139_4f5e00
  FL[3] = eax;  // @140_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @141_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @142_4f5e00
  eax = (eax + (u32)(-12));  // @143_4f5e00
  FL[3] = eax;  // @144_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @145_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @146_4f5e00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @147_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @148_4f5e00
  eax = (eax >> (u32)(31));  // @149_4f5e00
  FL[3] = eax;  // @150_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @151_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @153_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @154_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @155_4f5e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[14]);  // @156_4f5e00
  ecx = edx = 0;  // @157_4f5e00
  eax = (u32)(edi + 8);  // @158_4f5e00
  { u32 v = (u32)((u32)(1117782016)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @159_4f5e00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @160_4f5e00
  ecx = (u32)(EBP - 16);  // @161_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @162_4f5e00
  eax = (eax >> (u32)(31));  // @163_4f5e00
  FL[3] = eax;  // @164_4f5e00
  PV[15] = (u32)(ecx);  // @165_4f5e00
  ecx = esi;  // @166_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @167_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @169_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @170_4f5e00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @171_4f5e00
  X0[1] = 0;  // @172_4f5e00
  X0[2] = 0;  // @173_4f5e00
  X0[3] = 0;  // @174_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @175_4f5e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[15]);  // @176_4f5e00
  ecx = edx = 0;  // @177_4f5e00
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @178_4f5e00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @179_4f5e00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 111), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @180_4f5e00
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @181_4f5e00
  X0[0] = F2U((float)(s32)X0[0]);  // @182_4f5e00
  X0[1] = F2U((float)(s32)X0[1]);  // @183_4f5e00
  X0[2] = F2U((float)(s32)X0[2]);  // @184_4f5e00
  X0[3] = F2U((float)(s32)X0[3]);  // @185_4f5e00
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 36) + 0), 4); v; })));  // @186_4f5e00
  { u32 _h; eax = w4a_ftol(0x633910, X0[0], &_h); edx = _h; ecx = 0; }  // @187_4f5e00
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; }));  // @188_4f5e00
  FL[3] = eax;  // @189_4f5e00
  eax = (eax >> (u32)(1));  // @190_4f5e00
  FL[3] = eax;  // @191_4f5e00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @192_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @193_4f5e00
  eax = (eax >> (u32)(31));  // @194_4f5e00
  FL[3] = eax;  // @195_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @196_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @197_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @198_4f5e00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 115), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @199_4f5e00
  X0[0] = F2U((float)(s32)X0[0]);  // @200_4f5e00
  X0[1] = F2U((float)(s32)X0[1]);  // @201_4f5e00
  X0[2] = F2U((float)(s32)X0[2]);  // @202_4f5e00
  X0[3] = F2U((float)(s32)X0[3]);  // @203_4f5e00
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 40) + 0), 4); v; })));  // @204_4f5e00
  { u32 _h; eax = w4a_ftol(0x633910, X0[0], &_h); edx = _h; ecx = 0; }  // @205_4f5e00
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @206_4f5e00
  FL[3] = eax;  // @207_4f5e00
  ecx = (u32)(EBP - 16);  // @208_4f5e00
  eax = (eax >> (u32)(1));  // @209_4f5e00
  FL[3] = eax;  // @210_4f5e00
  PV[16] = (u32)(ecx);  // @211_4f5e00
  ecx = ebx;  // @212_4f5e00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @213_4f5e00
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @214_4f5e00
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @215_4f5e00
  eax = (eax >> (u32)(31));  // @216_4f5e00
  FL[3] = eax;  // @217_4f5e00
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @218_4f5e00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @219_4f5e00
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @220_4f5e00
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @221_4f5e00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[16]);  // @222_4f5e00
  ecx = edx = 0;  // @223_4f5e00
  ext_633654(G(u32, 0x6f5630));  // @224_4f5e00
  eax = ebx;  // @225_4f5e00
  return eax;  // @226_4f5e00
}
PCREG(4f5e00, lifted_4f5e00);

