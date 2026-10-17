// batch242005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441970_fastcall3(u32, u32, u32) __asm__("ext_441970");
extern "C" u32 FASTCALL ext_4e2c60_fastcall2(u32, u32) __asm__("ext_4e2c60");
extern "C" u32 THISCALL ext_5d4e80_thiscall4(u32, u32, u32, u32) __asm__("ext_5d4e80");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e5e40_thiscall1(u32) __asm__("ext_4e5e40");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5e80_thiscall1(u32) __asm__("ext_4e5e80");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c14b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c14b0
  esi = ecx;  // @1_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_4c14b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @3_4c14b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @4_4c14b0
  if (FL[0] == FL[1]) goto L4c14d6;  // @5_4c14b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @6_4c14b0
  FL[3] = (eax & 0xff);  // @7_4c14b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @8_4c14b0
  if (FL[0] != FL[1]) goto L4c14d6;  // @9_4c14b0
  ecx = edi;  // @10_4c14b0
  eax = ext_4e5e40_thiscall1(ecx);  // @11_4c14b0
  ecx = edx = 0;  // @12_4c14b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @13_4c14b0
  L4c14d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_4c14b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @16_4c14b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @17_4c14b0
  if (FL[0] == FL[1]) goto L4c14ef;  // @18_4c14b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @19_4c14b0
  FL[3] = (eax & 0xff);  // @20_4c14b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @21_4c14b0
  if (FL[0] != FL[1]) goto L4c14ef;  // @22_4c14b0
  ecx = edi;  // @23_4c14b0
  eax = ext_4e5e40_thiscall1(ecx);  // @24_4c14b0
  ecx = edx = 0;  // @25_4c14b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @26_4c14b0
  L4c14ef:;
  ecx = edi;  // @28_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @29_4c14b0
  ecx = edx = 0;  // @30_4c14b0
  ecx = edi;  // @31_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @32_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @33_4c14b0
  ecx = edx = 0;  // @34_4c14b0
  ecx = edi;  // @35_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @36_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @37_4c14b0
  ecx = edx = 0;  // @38_4c14b0
  ecx = edi;  // @39_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @40_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @41_4c14b0
  ecx = edx = 0;  // @42_4c14b0
  ecx = edi;  // @43_4c14b0
  ebx = eax;  // @44_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @45_4c14b0
  ecx = edx = 0;  // @46_4c14b0
  ecx = edi;  // @47_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @48_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @49_4c14b0
  ecx = edx = 0;  // @50_4c14b0
  ecx = edi;  // @51_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @52_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @53_4c14b0
  ecx = edx = 0;  // @54_4c14b0
  ecx = edi;  // @55_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @56_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @57_4c14b0
  ecx = edx = 0;  // @58_4c14b0
  ecx = edi;  // @59_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @60_4c14b0
  eax = ext_4e5e60_thiscall1(ecx);  // @61_4c14b0
  ecx = edx = 0;  // @62_4c14b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @63_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_4c14b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @65_4c14b0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @66_4c14b0
  if (FL[0] == FL[1]) goto L4c1564;  // @67_4c14b0
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @68_4c14b0
  FL[3] = (ecx & 0xff);  // @69_4c14b0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @70_4c14b0
  if (FL[0] != FL[1]) goto L4c1564;  // @71_4c14b0
  ecx = edi;  // @72_4c14b0
  eax = ext_4e5e80_thiscall1(ecx);  // @73_4c14b0
  ecx = edx = 0;  // @74_4c14b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 102)) :: "st");  // @75_4c14b0
  L4c1564:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @77_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @78_4c14b0
  eax = (eax << (u32)(4));  // @79_4c14b0
  FL[3] = eax;  // @80_4c14b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @81_4c14b0
  FL[3] = eax;  // @82_4c14b0
  ecx = (u32)(ecx + eax*4);  // @83_4c14b0
  eax = ecx;  // @84_4c14b0
  eax = (eax << (u32)(4));  // @85_4c14b0
  FL[3] = eax;  // @86_4c14b0
  eax = (eax - ecx);  // @87_4c14b0
  FL[3] = eax;  // @88_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @89_4c14b0
  eax = (u32)(ecx + eax*4);  // @90_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @91_4c14b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @92_4c14b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @93_4c14b0
  eax = (eax >> (u32)(31));  // @94_4c14b0
  FL[3] = eax;  // @95_4c14b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @96_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @97_4c14b0
  eax = (eax << (u32)(4));  // @98_4c14b0
  FL[3] = eax;  // @99_4c14b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @100_4c14b0
  FL[3] = eax;  // @101_4c14b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @102_4c14b0
  ecx = (u32)(ecx + eax*4);  // @103_4c14b0
  eax = ecx;  // @104_4c14b0
  eax = (eax << (u32)(4));  // @105_4c14b0
  FL[3] = eax;  // @106_4c14b0
  eax = (eax - ecx);  // @107_4c14b0
  FL[3] = eax;  // @108_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @109_4c14b0
  X0[0] = ebx; X0[1] = X0[2] = X0[3] = 0;  // @110_4c14b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @111_4c14b0
  ebx = (ebx >> (u32)(31));  // @112_4c14b0
  FL[3] = ebx;  // @113_4c14b0
  eax = (u32)(ecx + eax*4);  // @114_4c14b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @115_4c14b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 4), 4); v; })));  // @116_4c14b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @117_4c14b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; })));  // @118_4c14b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @119_4c14b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @120_4c14b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @121_4c14b0
  eax = (eax >> (u32)(31));  // @122_4c14b0
  FL[3] = eax;  // @123_4c14b0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @124_4c14b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @125_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @126_4c14b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @127_4c14b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @128_4c14b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @129_4c14b0
  eax = (eax >> (u32)(31));  // @130_4c14b0
  FL[3] = eax;  // @131_4c14b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @132_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_4c14b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @134_4c14b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @135_4c14b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; })));  // @136_4c14b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @137_4c14b0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X2[0], 4);  // @138_4c14b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6896704), (u32)(3103));  // @139_4c14b0
  ecx = edx = 0;  // @140_4c14b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 102) + 0), 4); v; });  // @141_4c14b0
  X0[1] = 0;  // @142_4c14b0
  X0[2] = 0;  // @143_4c14b0
  X0[3] = 0;  // @144_4c14b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @145_4c14b0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; }))))) goto L4c1650;  // @146_4c14b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @147_4c14b0
  goto L4c1654;  // @148_4c14b0
  L4c1650:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @150_4c14b0
  L4c1654:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @152_4c14b0
  if (FL[0] == FL[1]) goto L4c165f;  // @153_4c14b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @154_4c14b0
  L4c165f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @156_4c14b0
  X0[1] = 0;  // @157_4c14b0
  X0[2] = 0;  // @158_4c14b0
  X0[3] = 0;  // @159_4c14b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @160_4c14b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @161_4c14b0
  if (__builtin_parity(FL[2] & 0xff)) goto L4c168f;  // @162_4c14b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @163_4c14b0
  X1[1] = 0;  // @164_4c14b0
  X1[2] = 0;  // @165_4c14b0
  X1[3] = 0;  // @166_4c14b0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c168f;  // @167_4c14b0
  __builtin_memcpy((void *)((u32)(esi + 82) + 0), &X1[0], 4);  // @168_4c14b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @169_4c14b0
  __builtin_memcpy((void *)((u32)(esi + 86) + 0), &X0[0], 4);  // @170_4c14b0
  return eax;  // @171_4c14b0
  L4c168f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_4c14b0
  ecx = esi;  // @174_4c14b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @175_4c14b0
  ecx = edx = 0;  // @176_4c14b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @177_4c14b0
  return eax;  // @178_4c14b0
}
PCREG(4c14b0, lifted_4c14b0);

extern "C" u32 THISCALL lifted_4c16b0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c16b0
  esi = ecx;  // @1_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @2_4c16b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @3_4c16b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @4_4c16b0
  if (FL[0] == FL[1]) goto L4c16d6;  // @5_4c16b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @6_4c16b0
  FL[3] = (eax & 0xff);  // @7_4c16b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @8_4c16b0
  if (FL[0] != FL[1]) goto L4c16d6;  // @9_4c16b0
  ecx = edi;  // @10_4c16b0
  eax = ext_4e5e40_thiscall1(ecx);  // @11_4c16b0
  ecx = edx = 0;  // @12_4c16b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @13_4c16b0
  L4c16d6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_4c16b0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @16_4c16b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(255);  // @17_4c16b0
  if (FL[0] == FL[1]) goto L4c16ef;  // @18_4c16b0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @19_4c16b0
  FL[3] = (eax & 0xff);  // @20_4c16b0
  FL[0] = (eax & 0xff); FL[1] = (u32)(10);  // @21_4c16b0
  if (FL[0] != FL[1]) goto L4c16ef;  // @22_4c16b0
  ecx = edi;  // @23_4c16b0
  eax = ext_4e5e40_thiscall1(ecx);  // @24_4c16b0
  ecx = edx = 0;  // @25_4c16b0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @26_4c16b0
  L4c16ef:;
  ecx = edi;  // @28_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @29_4c16b0
  ecx = edx = 0;  // @30_4c16b0
  ecx = edi;  // @31_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @32_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @33_4c16b0
  ecx = edx = 0;  // @34_4c16b0
  ecx = edi;  // @35_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @36_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @37_4c16b0
  ecx = edx = 0;  // @38_4c16b0
  ecx = edi;  // @39_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @40_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @41_4c16b0
  ecx = edx = 0;  // @42_4c16b0
  ecx = edi;  // @43_4c16b0
  ebx = eax;  // @44_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @45_4c16b0
  ecx = edx = 0;  // @46_4c16b0
  ecx = edi;  // @47_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @48_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @49_4c16b0
  ecx = edx = 0;  // @50_4c16b0
  ecx = edi;  // @51_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @52_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @53_4c16b0
  ecx = edx = 0;  // @54_4c16b0
  ecx = edi;  // @55_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @56_4c16b0
  eax = ext_4e5e60_thiscall1(ecx);  // @57_4c16b0
  ecx = edx = 0;  // @58_4c16b0
  ecx = edi;  // @59_4c16b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @60_4c16b0
  eax = ext_4e5e80_thiscall1(ecx);  // @61_4c16b0
  ecx = edx = 0;  // @62_4c16b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 94)) :: "st");  // @63_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @64_4c16b0
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @65_4c16b0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(255);  // @66_4c16b0
  if (FL[0] == FL[1]) goto L4c1764;  // @67_4c16b0
  ecx = (ecx & 0xffffff00u) | ((((ecx & 0xff) & (u32)(63))) & 0xff);  // @68_4c16b0
  FL[3] = (ecx & 0xff);  // @69_4c16b0
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @70_4c16b0
  if (FL[0] != FL[1]) goto L4c1764;  // @71_4c16b0
  ecx = edi;  // @72_4c16b0
  eax = ext_4e5e80_thiscall1(ecx);  // @73_4c16b0
  ecx = edx = 0;  // @74_4c16b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(esi + 102)) :: "st");  // @75_4c16b0
  L4c1764:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @77_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @78_4c16b0
  eax = (eax << (u32)(4));  // @79_4c16b0
  FL[3] = eax;  // @80_4c16b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @81_4c16b0
  FL[3] = eax;  // @82_4c16b0
  ecx = (u32)(ecx + eax*4);  // @83_4c16b0
  eax = ecx;  // @84_4c16b0
  eax = (eax << (u32)(4));  // @85_4c16b0
  FL[3] = eax;  // @86_4c16b0
  eax = (eax - ecx);  // @87_4c16b0
  FL[3] = eax;  // @88_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @89_4c16b0
  eax = (u32)(ecx + eax*4);  // @90_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @91_4c16b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @92_4c16b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @93_4c16b0
  eax = (eax >> (u32)(31));  // @94_4c16b0
  FL[3] = eax;  // @95_4c16b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @96_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @97_4c16b0
  eax = (eax << (u32)(4));  // @98_4c16b0
  FL[3] = eax;  // @99_4c16b0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; }));  // @100_4c16b0
  FL[3] = eax;  // @101_4c16b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @102_4c16b0
  ecx = (u32)(ecx + eax*4);  // @103_4c16b0
  eax = ecx;  // @104_4c16b0
  eax = (eax << (u32)(4));  // @105_4c16b0
  FL[3] = eax;  // @106_4c16b0
  eax = (eax - ecx);  // @107_4c16b0
  FL[3] = eax;  // @108_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @109_4c16b0
  X0[0] = ebx; X0[1] = X0[2] = X0[3] = 0;  // @110_4c16b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @111_4c16b0
  ebx = (ebx >> (u32)(31));  // @112_4c16b0
  FL[3] = ebx;  // @113_4c16b0
  eax = (u32)(ecx + eax*4);  // @114_4c16b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @115_4c16b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx*8 + 6818464) + 4), 4); v; })));  // @116_4c16b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @117_4c16b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; })));  // @118_4c16b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @119_4c16b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @120_4c16b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @121_4c16b0
  eax = (eax >> (u32)(31));  // @122_4c16b0
  FL[3] = eax;  // @123_4c16b0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X2[0], 4);  // @124_4c16b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @125_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @126_4c16b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X2[0] = F2U(a_); X2[1] = F2U(b_); X2[2] = X2[3] = 0; }  // @127_4c16b0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @128_4c16b0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @129_4c16b0
  eax = (eax >> (u32)(31));  // @130_4c16b0
  FL[3] = eax;  // @131_4c16b0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @132_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_4c16b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 448), sizeof v); (u32)v; });  // @134_4c16b0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @135_4c16b0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6840448) + 0), 4); v; })));  // @136_4c16b0
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @137_4c16b0
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X2[0], 4);  // @138_4c16b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6896704), (u32)(3294));  // @139_4c16b0
  ecx = edx = 0;  // @140_4c16b0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 102) + 0), 4); v; });  // @141_4c16b0
  X0[1] = 0;  // @142_4c16b0
  X0[2] = 0;  // @143_4c16b0
  X0[3] = 0;  // @144_4c16b0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP + 8)) :: "st");  // @145_4c16b0
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; }))))) goto L4c1850;  // @146_4c16b0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @147_4c16b0
  goto L4c1854;  // @148_4c16b0
  L4c1850:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @150_4c16b0
  L4c1854:;
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @152_4c16b0
  if (FL[0] == FL[1]) goto L4c185f;  // @153_4c16b0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @154_4c16b0
  L4c185f:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @156_4c16b0
  X0[1] = 0;  // @157_4c16b0
  X0[2] = 0;  // @158_4c16b0
  X0[3] = 0;  // @159_4c16b0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @160_4c16b0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @161_4c16b0
  if (__builtin_parity(FL[2] & 0xff)) goto L4c188f;  // @162_4c16b0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @163_4c16b0
  X1[1] = 0;  // @164_4c16b0
  X1[2] = 0;  // @165_4c16b0
  X1[3] = 0;  // @166_4c16b0
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4c188f;  // @167_4c16b0
  __builtin_memcpy((void *)((u32)(esi + 82) + 0), &X1[0], 4);  // @168_4c16b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @169_4c16b0
  __builtin_memcpy((void *)((u32)(esi + 86) + 0), &X0[0], 4);  // @170_4c16b0
  return eax;  // @171_4c16b0
  L4c188f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_4c16b0
  ecx = esi;  // @174_4c16b0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(16), (u32)(0));  // @175_4c16b0
  ecx = edx = 0;  // @176_4c16b0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @177_4c16b0
  return eax;  // @178_4c16b0
}
PCREG(4c16b0, lifted_4c16b0);

extern "C" u32 THISCALL lifted_5d4c00(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_5d4c00
  edi = ecx;  // @1_5d4c00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @2_5d4c00
  X0[1] = 0;  // @3_5d4c00
  X0[2] = 0;  // @4_5d4c00
  X0[3] = 0;  // @5_5d4c00
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; })));  // @6_5d4c00
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @7_5d4c00
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @8_5d4c00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @9_5d4c00
  if ((s32)FL[0] >= (s32)FL[1]) goto L5d4de8;  // @10_5d4c00
  L5d4c40:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @12_5d4c00
  X0[1] = 0;  // @13_5d4c00
  X0[2] = 0;  // @14_5d4c00
  X0[3] = 0;  // @15_5d4c00
  ecx = (u32)(EBP - 64);  // @16_5d4c00
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; })));  // @17_5d4c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @18_5d4c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @19_5d4c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @20_5d4c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @21_5d4c00
  __builtin_memcpy((void *)((u32)(edi + 76) + 0), &X0[0], 4);  // @22_5d4c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @23_5d4c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @24_5d4c00
  eax = ext_4de7a0_thiscall1(ecx);  // @25_5d4c00
    // @26_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_5d4c00
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @28_5d4c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @31_5d4c00
  ecx = edx = 0;  // @32_5d4c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_5d4c00
  ebx = eax;  // @34_5d4c00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @35_5d4c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @36_5d4c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, PV[1]);  // @38_5d4c00
  ecx = edx = 0;  // @39_5d4c00
  esi = eax;  // @40_5d4c00
  FL[2] = (ebx & ebx);  // @41_5d4c00
  if (FL[2] == 0) goto L5d4dc2;  // @42_5d4c00
  FL[2] = (esi & esi);  // @43_5d4c00
  if (FL[2] == 0) goto L5d4dc2;  // @44_5d4c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_5d4c00
  eax = (u32)(EBP - 16);  // @46_5d4c00
  PV[2] = (u32)(eax);  // @47_5d4c00
  eax = (u32)(EBP - 64);  // @48_5d4c00
  ecx = ebx;  // @49_5d4c00
  PV[3] = (u32)(eax);  // @50_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 152)))(ecx, PV[3], PV[2]);  // @51_5d4c00
  ecx = edx = 0;  // @52_5d4c00
  eax = (u32)(EBP - 16);  // @53_5d4c00
  ecx = edi;  // @54_5d4c00
  PV[4] = (u32)(eax);  // @55_5d4c00
  eax = (u32)(EBP - 64);  // @56_5d4c00
  PV[5] = (u32)(eax);  // @57_5d4c00
  PV[6] = (u32)(ebx);  // @58_5d4c00
  eax = ext_5d4e80_thiscall4(ecx, PV[6], PV[5], PV[4]);   // hand fix: ecx = this (edi)  // @59_5d4c00
  ecx = edx = 0;  // @60_5d4c00
  eax = (u32)(EBP - 28);  // @61_5d4c00
  ecx = edi;  // @62_5d4c00
  PV[7] = (u32)(eax);  // @63_5d4c00
  eax = (u32)(EBP - 64);  // @64_5d4c00
  PV[8] = (u32)(eax);  // @65_5d4c00
  PV[9] = (u32)(esi);  // @66_5d4c00
  eax = ext_5d4e80_thiscall4(ecx, PV[9], PV[8], PV[7]);   // hand fix: ecx = this (edi)  // @67_5d4c00
  ecx = edx = 0;  // @68_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_5d4c00
  PV[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 92), sizeof v); (u32)v; });  // @70_5d4c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[10]);  // @73_5d4c00
  ecx = edx = 0;  // @74_5d4c00
  esi = eax;  // @75_5d4c00
  FL[2] = (esi & esi);  // @76_5d4c00
  if (FL[2] == 0) goto L5d4dc2;  // @77_5d4c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @78_5d4c00
  ecx = esi;  // @79_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, (u32)(1));  // @80_5d4c00
  ecx = edx = 0;  // @81_5d4c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @82_5d4c00
  ecx = esi;  // @83_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 828)))(ecx, (u32)(2));  // @84_5d4c00
  ecx = edx = 0;  // @85_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_5d4c00
  ecx = esi;  // @87_5d4c00
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 860)))(ecx);  // @88_5d4c00
  ecx = edx = 0;  // @89_5d4c00
  FL[2] = (eax & eax);  // @90_5d4c00
  if (FL[2] != 0) goto L5d4d3d;  // @91_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_5d4c00
  ecx = esi;  // @93_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 864)))(ecx, (u32)(100));  // @94_5d4c00
  ecx = edx = 0;  // @95_5d4c00
  L5d4d3d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_5d4c00
  ecx = esi;  // @98_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 852), sizeof v); (u32)v; });  // @99_5d4c00
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @100_5d4c00
  ecx = edx = 0;  // @101_5d4c00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @102_5d4c00
  if (FL[2] != 0) goto L5d4d69;  // @103_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @104_5d4c00
  ecx = esi;  // @105_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(6), (u32)(0));  // @106_5d4c00
  ecx = edx = 0;  // @107_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5d4c00
  ecx = esi;  // @109_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(0), (u32)(0));  // @110_5d4c00
  ecx = edx = 0;  // @111_5d4c00
  L5d4d69:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @113_5d4c00
  ecx = (u32)(EBP - 16);  // @114_5d4c00
  PV[11] = (u32)(ecx);  // @115_5d4c00
  ecx = (u32)(EBP - 64);  // @116_5d4c00
  PV[12] = (u32)(ecx);  // @117_5d4c00
  ecx = esi;  // @118_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 124)))(ecx, PV[12], PV[11]);  // @119_5d4c00
  ecx = edx = 0;  // @120_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_5d4c00
  ecx = (u32)(EBP - 28);  // @122_5d4c00
  PV[13] = (u32)(ecx);  // @123_5d4c00
  ecx = esi;  // @124_5d4c00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 812)))(ecx, PV[13]);  // @125_5d4c00
  ecx = edx = 0;  // @126_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @127_5d4c00
  ecx = esi;  // @128_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(3), (u32)(0));  // @129_5d4c00
  ecx = edx = 0;  // @130_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @131_5d4c00
  ecx = esi;  // @132_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 720)))(ecx, (u32)(0), (u32)(0));  // @133_5d4c00
  ecx = edx = 0;  // @134_5d4c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @135_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @136_5d4c00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7033772), (u32)(101));  // @137_5d4c00
  ecx = edx = 0;  // @138_5d4c00
  PV[14] = (u32)(eax);  // @139_5d4c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @140_5d4c00
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[14], (u32)(7033824));  // @141_5d4c00
  ecx = edx = 0;  // @142_5d4c00
  L5d4dc2:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 72) + 0), 4); v; });  // @144_5d4c00
  X0[1] = 0;  // @145_5d4c00
  X0[2] = 0;  // @146_5d4c00
  X0[3] = 0;  // @147_5d4c00
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 76) + 0), 4); v; })));  // @148_5d4c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @149_5d4c00
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @150_5d4c00
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @151_5d4c00
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @152_5d4c00
  if ((s32)FL[0] < (s32)FL[1]) goto L5d4c40;  // @153_5d4c00
  L5d4de8:;
  ext_633654(G(u32, 0x6f5630));  // @155_5d4c00
  return eax;  // @156_5d4c00
}
PCREG(5d4c00, lifted_5d4c00);

extern "C" u32 THISCALL lifted_4cb200(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4cb200
  esi = ecx;  // @1_4cb200
  ecx = ebx;  // @2_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_4cb200
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @4_4cb200
  ecx = edx = 0;  // @5_4cb200
  eax = (u32)(eax + eax*2);  // @6_4cb200
  eax = (u32)(eax*8 + 32);  // @7_4cb200
  PV[0] = (u32)(eax);  // @8_4cb200
  eax = ext_41e290_cdecl1(PV[0]);  // @9_4cb200
  ecx = edx = 0;  // @10_4cb200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @11_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @12_4cb200
  ecx = ebx;  // @13_4cb200
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @14_4cb200
  ecx = edx = 0;  // @15_4cb200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @16_4cb200
  edx = (u32)(EBP - 40);  // @17_4cb200
  PV[1] = (u32)(edx);  // @18_4cb200
  edx = (u32)(EBP - 88);  // @19_4cb200
  PV[2] = (u32)(edx);  // @20_4cb200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @21_4cb200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @22_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @23_4cb200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @24_4cb200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @25_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_4cb200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[2], PV[1]);  // @27_4cb200
  ecx = edx = 0;  // @28_4cb200
  eax = (u32)(EBP - 88);  // @29_4cb200
  PV[3] = (u32)(eax);  // @30_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @31_4cb200
  ecx = (u32)(EBP - 152);  // @32_4cb200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @33_4cb200
  edx = (edx + (u32)(48));  // @34_4cb200
  FL[3] = edx;  // @35_4cb200
  eax = ext_441970_fastcall3(ecx, edx, PV[3]);  // @36_4cb200
  ecx = edx = 0;  // @37_4cb200
  edx = (u32)(EBP - 152);  // @38_4cb200
  ecx = (u32)(EBP - 40);  // @39_4cb200
  eax = ext_441940_fastcall2(ecx, edx);  // @40_4cb200
  ecx = edx = 0;  // @41_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @42_4cb200
  edx = (u32)(EBP - 16);  // @43_4cb200
  ecx = (u32)(EBP - 88);  // @44_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @45_4cb200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @46_4cb200
  X0[1] = 0;  // @47_4cb200
  X0[2] = 0;  // @48_4cb200
  X0[3] = 0;  // @49_4cb200
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @50_4cb200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @51_4cb200
  X0[1] = 0;  // @52_4cb200
  X0[2] = 0;  // @53_4cb200
  X0[3] = 0;  // @54_4cb200
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @55_4cb200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @56_4cb200
  X0[1] = 0;  // @57_4cb200
  X0[2] = 0;  // @58_4cb200
  X0[3] = 0;  // @59_4cb200
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @60_4cb200
  eax = ext_4e2c60_fastcall2(ecx, edx);  // @61_4cb200
    // @62_4cb200
  ecx = (u32)(EBP - 88);  // @63_4cb200
  eax = ext_4de7a0_thiscall1(ecx);  // @64_4cb200
    // @65_4cb200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @66_4cb200
  eax = (u32)(EBP - 16);  // @67_4cb200
  PV[4] = (u32)(eax);  // @68_4cb200
  ecx = (ecx + (u32)(8));  // @69_4cb200
  FL[3] = ecx;  // @70_4cb200
  edx = (u32)(EBP - 40);  // @71_4cb200
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @72_4cb200
  ecx = edx = 0;  // @73_4cb200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @74_4cb200
  eax = (u32)(EBP - 16);  // @75_4cb200
  PV[5] = (u32)(eax);  // @76_4cb200
  ecx = (ecx + (u32)(20));  // @77_4cb200
  FL[3] = ecx;  // @78_4cb200
  edx = (u32)(EBP - 40);  // @79_4cb200
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[5]);  // @80_4cb200
  ecx = edx = 0;  // @81_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @82_4cb200
  ecx = (u32)(EBP - 140);  // @83_4cb200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @84_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @85_4cb200
  PV[6] = (u32)(ecx);  // @86_4cb200
  ecx = ebx;  // @87_4cb200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @88_4cb200
  ecx = edx = 0;  // @89_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_4cb200
  ecx = (u32)(EBP - 140);  // @91_4cb200
  PV[7] = (u32)(ecx);  // @92_4cb200
  ecx = ebx;  // @93_4cb200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @94_4cb200
  ecx = edx = 0;  // @95_4cb200
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @96_4cb200
  edx = eax;  // @97_4cb200
  if (FL[0] == FL[1]) goto L4cb3f5;  // @98_4cb200
  edi = 0;  // @99_4cb200
  FL[3] = edi;  // @100_4cb200
  L4cb320:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_4cb200
  PV[8] = (u32)(edx);  // @103_4cb200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @104_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_4cb200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[8]);  // @106_4cb200
  ecx = edx = 0;  // @107_4cb200
  esi = eax;  // @108_4cb200
  FL[2] = (esi & esi);  // @109_4cb200
  if (FL[2] != 0) goto L4cb346;  // @110_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @111_4cb200
  FL[2] = (eax & eax);  // @112_4cb200
  if (FL[2] == 0) goto L4cb345;  // @113_4cb200
  eax = ((u32(STDCALL *)(void))(eax))();  // @114_4cb200
  ecx = edx = 0;  // @115_4cb200
  goto L4cb346;  // @116_4cb200
  L4cb345:;
  __builtin_trap();  // @118_4cb200
  L4cb346:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_4cb200
  ecx = (u32)(EBP - 52);  // @121_4cb200
  PV[9] = (u32)(ecx);  // @122_4cb200
  ecx = (u32)(EBP - 124);  // @123_4cb200
  PV[10] = (u32)(ecx);  // @124_4cb200
  ecx = esi;  // @125_4cb200
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[10], PV[9]);  // @126_4cb200
  ecx = edx = 0;  // @127_4cb200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @128_4cb200
  eax = (u32)(EBP - 124);  // @129_4cb200
  PV[11] = (u32)(eax);  // @130_4cb200
  edx = (edx + (u32)(48));  // @131_4cb200
  FL[3] = edx;  // @132_4cb200
  ecx = (u32)(EBP - 164);  // @133_4cb200
  eax = ext_441970_fastcall3(ecx, edx, PV[11]);  // @134_4cb200
  ecx = edx = 0;  // @135_4cb200
  edx = (u32)(EBP - 164);  // @136_4cb200
  ecx = (u32)(EBP - 52);  // @137_4cb200
  eax = ext_441940_fastcall2(ecx, edx);  // @138_4cb200
  ecx = edx = 0;  // @139_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @140_4cb200
  edx = (u32)(EBP - 28);  // @141_4cb200
  ecx = (u32)(EBP - 124);  // @142_4cb200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @143_4cb200
  X0[1] = 0;  // @144_4cb200
  X0[2] = 0;  // @145_4cb200
  X0[3] = 0;  // @146_4cb200
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @147_4cb200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @148_4cb200
  X0[1] = 0;  // @149_4cb200
  X0[2] = 0;  // @150_4cb200
  X0[3] = 0;  // @151_4cb200
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @152_4cb200
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @153_4cb200
  X0[1] = 0;  // @154_4cb200
  X0[2] = 0;  // @155_4cb200
  X0[3] = 0;  // @156_4cb200
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @157_4cb200
  eax = ext_4e2c60_fastcall2(ecx, edx);  // @158_4cb200
    // @159_4cb200
  ecx = (u32)(EBP - 124);  // @160_4cb200
  eax = ext_4de7a0_thiscall1(ecx);  // @161_4cb200
    // @162_4cb200
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 128), sizeof v); (u32)v; });  // @163_4cb200
  eax = (u32)(EBP - 28);  // @164_4cb200
  PV[12] = (u32)(eax);  // @165_4cb200
  edx = (u32)(EBP - 52);  // @166_4cb200
  ecx = (u32)(esi + 32);  // @167_4cb200
  ecx = (ecx + edi);  // @168_4cb200
  FL[3] = ecx;  // @169_4cb200
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @170_4cb200
  ecx = edx = 0;  // @171_4cb200
  eax = (u32)(EBP - 28);  // @172_4cb200
  ecx = (u32)(esi + 44);  // @173_4cb200
  PV[13] = (u32)(eax);  // @174_4cb200
  ecx = (ecx + edi);  // @175_4cb200
  FL[3] = ecx;  // @176_4cb200
  edx = (u32)(EBP - 52);  // @177_4cb200
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[13]);  // @178_4cb200
  ecx = edx = 0;  // @179_4cb200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @180_4cb200
  ecx = (u32)(EBP - 140);  // @181_4cb200
  PV[14] = (u32)(ecx);  // @182_4cb200
  ecx = ebx;  // @183_4cb200
  edi = (edi + (u32)(24));  // @184_4cb200
  FL[3] = edi;  // @185_4cb200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[14]);  // @186_4cb200
  ecx = edx = 0;  // @187_4cb200
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 140), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @188_4cb200
  edx = eax;  // @189_4cb200
  if (FL[0] != FL[1]) goto L4cb320;  // @190_4cb200
  L4cb3f5:;
  ext_633654(G(u32, 0x6f5630));  // @192_4cb200
  return eax;  // @193_4cb200
}
PCREG(4cb200, lifted_4cb200);

