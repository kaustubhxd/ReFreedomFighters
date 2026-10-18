// batch244043.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4e0010_fastcall2(u32, u32) __asm__("ext_4e0010");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4db7c0_thiscall2(u32, u32) __asm__("ext_4db7c0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4f3390(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66993b);  // @h_4f3390
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4f3390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; }); X2[1] = X2[2] = X2[3] = 0;  // @2_4f3390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @3_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4f3390
  X2[0] = F2U((float)(s32)X2[0]);  // @5_4f3390
  X2[1] = F2U((float)(s32)X2[1]);  // @6_4f3390
  X2[2] = F2U((float)(s32)X2[2]);  // @7_4f3390
  X2[3] = F2U((float)(s32)X2[3]);  // @8_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @9_4f3390
  X0[1] = 0;  // @10_4f3390
  X0[2] = 0;  // @11_4f3390
  X0[3] = 0;  // @12_4f3390
  X1[0] = F2U((float)(s32)X1[0]);  // @13_4f3390
  X1[1] = F2U((float)(s32)X1[1]);  // @14_4f3390
  X1[2] = F2U((float)(s32)X1[2]);  // @15_4f3390
  X1[3] = F2U((float)(s32)X1[3]);  // @16_4f3390
  __builtin_memcpy((void *)((u32)(esi + 119) + 0), &X0[0], 4);  // @17_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @18_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 260) + 0), &X2[0], 4);  // @19_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 264) + 0), &X1[0], 4);  // @20_4f3390
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @21_4f3390
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L4f3401;  // @22_4f3390
  __builtin_memcpy((void *)((u32)(esi + 119) + 0), &X2[0], 4);  // @23_4f3390
  L4f3401:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 123) + 0), 4); v; });  // @25_4f3390
  X0[1] = 0;  // @26_4f3390
  X0[2] = 0;  // @27_4f3390
  X0[3] = 0;  // @28_4f3390
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4f3410;  // @29_4f3390
  __builtin_memcpy((void *)((u32)(esi + 123) + 0), &X1[0], 4);  // @30_4f3390
  L4f3410:;
  X0[0] = 0;  // @32_4f3390
  X0[1] = 0;  // @33_4f3390
  X0[2] = 0;  // @34_4f3390
  X0[3] = 0;  // @35_4f3390
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 119) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 119) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 119) + 0), 4); v; }))))))) goto L4f3420;  // @36_4f3390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @37_4f3390
  L4f3420:;
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 123) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 123) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 123) + 0), 4); v; }))))))) goto L4f342d;  // @39_4f3390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @40_4f3390
  L4f342d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 119) + 0), 4); v; });  // @43_4f3390
  X0[1] = 0;  // @44_4f3390
  X0[2] = 0;  // @45_4f3390
  X0[3] = 0;  // @46_4f3390
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 115), sizeof v); (u32)v; });  // @47_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 272) + 0), &X0[0], 4);  // @48_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 123) + 0), 4); v; });  // @50_4f3390
  X0[1] = 0;  // @51_4f3390
  X0[2] = 0;  // @52_4f3390
  X0[3] = 0;  // @53_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X0[0], 4);  // @54_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @56_4f3390
  ecx = edx = 0;  // @57_4f3390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 272) + 0), 4); v; });  // @58_4f3390
  X1[1] = 0;  // @59_4f3390
  X1[2] = 0;  // @60_4f3390
  X1[3] = 0;  // @61_4f3390
  edi = eax;  // @62_4f3390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @63_4f3390
  X2[1] = 0;  // @64_4f3390
  X2[2] = 0;  // @65_4f3390
  X2[3] = 0;  // @66_4f3390
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; });  // @67_4f3390
  X3[1] = 0;  // @68_4f3390
  X3[2] = 0;  // @69_4f3390
  X3[3] = 0;  // @70_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 256) + 0), 4); v; });  // @71_4f3390
  X0[1] = 0;  // @72_4f3390
  X0[2] = 0;  // @73_4f3390
  X0[3] = 0;  // @74_4f3390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @75_4f3390
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @76_4f3390
  if (!__builtin_parity(FL[2] & 0xff)) goto L4f349a;  // @77_4f3390
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @78_4f3390
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @79_4f3390
  if (__builtin_parity(FL[2] & 0xff)) goto L4f35ae;  // @80_4f3390
  L4f349a:;
  __builtin_memcpy((void *)((u32)(esi + 143) + 0), &X1[0], 4);  // @82_4f3390
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @83_4f3390
  __builtin_memcpy((void *)((u32)(esi + 147) + 0), &X0[0], 4);  // @84_4f3390
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @85_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X1[0], 4);  // @86_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X0[0], 4);  // @87_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @88_4f3390
  FL[2] = (edi & edi);  // @89_4f3390
  if (FL[2] == 0) goto L4f34f0;  // @90_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @91_4f3390
  eax = (u32)(EBP - 52);  // @92_4f3390
  PV[1] = (u32)(eax);  // @93_4f3390
  eax = ext_4db7c0_thiscall2(ecx, PV[1]);  // @94_4f3390
  edx = 0;  // @95_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @96_4f3390
  X0[1] = 0;  // @97_4f3390
  X0[2] = 0;  // @98_4f3390
  X0[3] = 0;  // @99_4f3390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @100_4f3390
  X1[1] = 0;  // @101_4f3390
  X1[2] = 0;  // @102_4f3390
  X1[3] = 0;  // @103_4f3390
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; });  // @104_4f3390
  X3[1] = 0;  // @105_4f3390
  X3[2] = 0;  // @106_4f3390
  X3[3] = 0;  // @107_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X0[0], 4);  // @108_4f3390
  goto L4f3505;  // @109_4f3390
  L4f34f0:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @111_4f3390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @112_4f3390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @113_4f3390
  L4f3505:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 260) + 0), 4); v; });  // @115_4f3390
  X2[1] = 0;  // @116_4f3390
  X2[2] = 0;  // @117_4f3390
  X2[3] = 0;  // @118_4f3390
  X2[0] = F2U(U2F(X2[0]) - U2F(X3[0]));  // @119_4f3390
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L4f3519;  // @120_4f3390
  X1[0] = X2[0];  // @121_4f3390
  X1[1] = X2[1];  // @122_4f3390
  X1[2] = X2[2];  // @123_4f3390
  X1[3] = X2[3];  // @124_4f3390
  L4f3519:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 264) + 0), 4); v; });  // @126_4f3390
  X2[1] = 0;  // @127_4f3390
  X2[2] = 0;  // @128_4f3390
  X2[3] = 0;  // @129_4f3390
  X2[0] = F2U(U2F(X2[0]) - U2F(X3[0]));  // @130_4f3390
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L4f3532;  // @131_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X2[0], 4);  // @132_4f3390
  L4f3532:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @134_4f3390
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @135_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 268) + 0), &X0[0], 4);  // @136_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 268) + 4), &X0[1], 4);  // @137_4f3390
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 268)) : "st");  // @138_4f3390
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[2] = (u32)v_; PV[3] = (u32)(v_ >> 32); }  // @139_4f3390
  eax = ext_634dca_cdecl2(PV[2], PV[3]);  // @140_4f3390
    // @141_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 256) + 0), 4); v; });  // @142_4f3390
  X0[1] = 0;  // @143_4f3390
  X0[2] = 0;  // @144_4f3390
  X0[3] = 0;  // @145_4f3390
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @146_4f3390
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 28)) :: "st");  // @147_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 268) + 0), &X0[0], 4);  // @148_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 268) + 4), &X0[1], 4);  // @149_4f3390
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 268)) : "st");  // @150_4f3390
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[4] = (u32)v_; PV[5] = (u32)(v_ >> 32); }  // @151_4f3390
  eax = ext_634dca_cdecl2(PV[4], PV[5]);  // @152_4f3390
    // @153_4f3390
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 24)) :: "st");  // @154_4f3390
  FL[2] = (edi & edi);  // @155_4f3390
  if (FL[2] == 0) goto L4f358e;  // @156_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @157_4f3390
  ecx = (u32)(EBP - 28);  // @158_4f3390
  PV[6] = (u32)(ecx);  // @159_4f3390
  ecx = edi;  // @160_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[6]);  // @161_4f3390
  ecx = edx = 0;  // @162_4f3390
  L4f358e:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 143) + 0), 4); v; });  // @164_4f3390
  X0[1] = 0;  // @165_4f3390
  X0[2] = 0;  // @166_4f3390
  X0[3] = 0;  // @167_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 272) + 0), &X0[0], 4);  // @168_4f3390
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 147) + 0), 4); v; });  // @169_4f3390
  X0[1] = 0;  // @170_4f3390
  X0[2] = 0;  // @171_4f3390
  X0[3] = 0;  // @172_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X0[0], 4);  // @173_4f3390
  L4f35ae:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @175_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @176_4f3390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @177_4f3390
  ecx = edx = 0;  // @178_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @179_4f3390
  PV[7] = (u32)(eax);  // @180_4f3390
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[7], (u32)(10), (u32)(14), (u32)(6918016));  // @181_4f3390
  ecx = edx = 0;  // @182_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_4f3390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @185_4f3390
  ecx = edx = 0;  // @186_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @187_4f3390
  PV[8] = (u32)(eax);  // @188_4f3390
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[8], (u32)(10), (u32)(15), (u32)(6918016));  // @189_4f3390
  ecx = edx = 0;  // @190_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @191_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @192_4f3390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @193_4f3390
  ecx = edx = 0;  // @194_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @195_4f3390
  PV[9] = (u32)(eax);  // @196_4f3390
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[9], (u32)(10), (u32)(16), (u32)(6918016));  // @197_4f3390
  ecx = edx = 0;  // @198_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @199_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @200_4f3390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @201_4f3390
  ecx = edx = 0;  // @202_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @203_4f3390
  PV[10] = (u32)(eax);  // @204_4f3390
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[10], (u32)(10), (u32)(17), (u32)(6918016));  // @205_4f3390
  ecx = edx = 0;  // @206_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @207_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @208_4f3390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @209_4f3390
  ecx = edx = 0;  // @210_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @211_4f3390
  PV[11] = (u32)(eax);  // @212_4f3390
  eax = ((u32(*)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[11], (u32)(10), (u32)(18), (u32)(6918016));  // @213_4f3390
  ecx = edx = 0;  // @214_4f3390
  ebx = 0;  // @215_4f3390
  FL[3] = ebx;  // @216_4f3390
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @217_4f3390
  FL[2] = (edi & edi);  // @218_4f3390
  if (FL[2] == 0) goto L4f38bf;  // @219_4f3390
  edi = (u32)(esi + 423);  // @220_4f3390
  FL[2] = (edi & edi);  // @221_4f3390
  if (FL[2] == 0) goto L4f38bf;  // @222_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @223_4f3390
  ecx = (u32)(EBP - 284);  // @224_4f3390
  PV[12] = (u32)(ecx);  // @225_4f3390
  ecx = edi;  // @226_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, PV[12]);  // @227_4f3390
  ecx = edx = 0;  // @228_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @229_4f3390
  ecx = (u32)(EBP - 284);  // @230_4f3390
  PV[13] = (u32)(ecx);  // @231_4f3390
  ecx = edi;  // @232_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, PV[13]);  // @233_4f3390
  ecx = edx = 0;  // @234_4f3390
  edx = eax;  // @235_4f3390
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; }); FL[1] = ebx;  // @236_4f3390
  if (FL[0] == FL[1]) goto L4f38bf;  // @237_4f3390
  L4f36b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @239_4f3390
  PV[14] = (u32)(edx);  // @240_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @241_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @242_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[14]);  // @243_4f3390
  ecx = edx = 0;  // @244_4f3390
  ebx = eax;  // @245_4f3390
  eax = (u32)(EBP - 68);  // @246_4f3390
  PV[15] = (u32)(eax);  // @247_4f3390
  ecx = ebx;  // @248_4f3390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @249_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 576)))(ecx, PV[15]);  // @250_4f3390
  ecx = edx = 0;  // @251_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @252_4f3390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @253_4f3390
  X2[1] = 0;  // @254_4f3390
  X2[2] = 0;  // @255_4f3390
  X2[3] = 0;  // @256_4f3390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 272) + 0), 4); v; });  // @257_4f3390
  X1[1] = 0;  // @258_4f3390
  X1[2] = 0;  // @259_4f3390
  X1[3] = 0;  // @260_4f3390
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 111), sizeof v); (u32)v; }); X3[1] = X3[2] = X3[3] = 0;  // @261_4f3390
  X3[0] = F2U((float)(s32)X3[0]);  // @262_4f3390
  X3[1] = F2U((float)(s32)X3[1]);  // @263_4f3390
  X3[2] = F2U((float)(s32)X3[2]);  // @264_4f3390
  X3[3] = F2U((float)(s32)X3[3]);  // @265_4f3390
  X0[0] = X3[0];  // @266_4f3390
  X0[1] = X3[1];  // @267_4f3390
  X0[2] = X3[2];  // @268_4f3390
  X0[3] = X3[3];  // @269_4f3390
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @270_4f3390
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L4f389c;  // @271_4f3390
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @272_4f3390
  X7[1] = 0;  // @273_4f3390
  X7[2] = 0;  // @274_4f3390
  X7[3] = 0;  // @275_4f3390
  X0[0] = X7[0];  // @276_4f3390
  X0[1] = X7[1];  // @277_4f3390
  X0[2] = X7[2];  // @278_4f3390
  X0[3] = X7[3];  // @279_4f3390
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @280_4f3390
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @281_4f3390
  if ((!(!(U2F(X1[0]) >= U2F(X0[0]))) && !(!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L4f389c;  // @282_4f3390
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; }); X4[1] = X4[2] = X4[3] = 0;  // @283_4f3390
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @284_4f3390
  X5[1] = 0;  // @285_4f3390
  X5[2] = 0;  // @286_4f3390
  X5[3] = 0;  // @287_4f3390
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 256) + 0), 4); v; });  // @288_4f3390
  X2[1] = 0;  // @289_4f3390
  X2[2] = 0;  // @290_4f3390
  X2[3] = 0;  // @291_4f3390
  X4[0] = F2U((float)(s32)X4[0]);  // @292_4f3390
  X4[1] = F2U((float)(s32)X4[1]);  // @293_4f3390
  X4[2] = F2U((float)(s32)X4[2]);  // @294_4f3390
  X4[3] = F2U((float)(s32)X4[3]);  // @295_4f3390
  X0[0] = X4[0];  // @296_4f3390
  X0[1] = X4[1];  // @297_4f3390
  X0[2] = X4[2];  // @298_4f3390
  X0[3] = X4[3];  // @299_4f3390
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @300_4f3390
  if ((!(!(U2F(X0[0]) >= U2F(X2[0]))) && !(!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L4f389c;  // @301_4f3390
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @302_4f3390
  X6[1] = 0;  // @303_4f3390
  X6[2] = 0;  // @304_4f3390
  X6[3] = 0;  // @305_4f3390
  X0[0] = X6[0];  // @306_4f3390
  X0[1] = X6[1];  // @307_4f3390
  X0[2] = X6[2];  // @308_4f3390
  X0[3] = X6[3];  // @309_4f3390
  X0[0] = F2U(U2F(X0[0]) + U2F(X5[0]));  // @310_4f3390
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @311_4f3390
  if ((!(!(U2F(X2[0]) >= U2F(X0[0]))) && !(!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L4f389c;  // @312_4f3390
  X3[0] = F2U(U2F(X3[0]) * U2F(X7[0]));  // @313_4f3390
  X0[0] = X1[0];  // @314_4f3390
  X0[1] = X1[1];  // @315_4f3390
  X0[2] = X1[2];  // @316_4f3390
  X0[3] = X1[3];  // @317_4f3390
  ecx = ebx;  // @318_4f3390
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @319_4f3390
  X0[0] = F2U(U2F(X0[0]) - U2F(X3[0]));  // @320_4f3390
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788420) + 0), 4); v; })));  // @321_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 268) + 0), &X0[0], 4);  // @322_4f3390
  X0[0] = X2[0];  // @323_4f3390
  X0[1] = X2[1];  // @324_4f3390
  X0[2] = X2[2];  // @325_4f3390
  X0[3] = X2[3];  // @326_4f3390
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @327_4f3390
  X1[0] = F2U((float)(s32)X1[0]);  // @328_4f3390
  X1[1] = F2U((float)(s32)X1[1]);  // @329_4f3390
  X1[2] = F2U((float)(s32)X1[2]);  // @330_4f3390
  X1[3] = F2U((float)(s32)X1[3]);  // @331_4f3390
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 252), &v, sizeof v); }  // @332_4f3390
  { u32 v = (u32)((u32)(2123789977)); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @333_4f3390
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 236), &v, sizeof v); }  // @334_4f3390
  X1[0] = F2U(U2F(X1[0]) * U2F(X6[0]));  // @335_4f3390
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @336_4f3390
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @337_4f3390
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806044) + 0), 4); v; })));  // @338_4f3390
  __builtin_memcpy((void *)((u32)(EBP - 264) + 0), &X0[0], 4);  // @339_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @340_4f3390
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 588)))(ecx);  // @341_4f3390
  ecx = edx = 0;  // @342_4f3390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @343_4f3390
  esi = eax;  // @344_4f3390
  eax = (u32)(EBP - 40);  // @345_4f3390
  ecx = ebx;  // @346_4f3390
  PV[16] = (u32)(eax);  // @347_4f3390
  eax = (u32)(EBP - 104);  // @348_4f3390
  PV[17] = (u32)(eax);  // @349_4f3390
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[17], PV[16]);  // @350_4f3390
  ecx = edx = 0;  // @351_4f3390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @352_4f3390
  eax = (u32)(EBP - 40);  // @353_4f3390
  PV[18] = (u32)(eax);  // @354_4f3390
  eax = (u32)(EBP - 104);  // @355_4f3390
  ecx = esi;  // @356_4f3390
  PV[19] = (u32)(eax);  // @357_4f3390
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 148)))(ecx, PV[19], PV[18]);  // @358_4f3390
  ecx = edx = 0;  // @359_4f3390
  ecx = (u32)(EBP - 40);  // @360_4f3390
  eax = ext_4e09b0_thiscall1(ecx);  // @361_4f3390
    // @362_4f3390
  edx = (u32)(EBP - 268);  // @363_4f3390
  ecx = (u32)(EBP - 40);  // @364_4f3390
  eax = ext_4e0010_fastcall2(ecx, edx);  // @365_4f3390
    // @366_4f3390
  ecx = (u32)(EBP - 104);  // @367_4f3390
  eax = ext_4de7a0_thiscall1(ecx);  // @368_4f3390
    // @369_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @370_4f3390
  ecx = (u32)(EBP - 104);  // @371_4f3390
  PV[20] = (u32)(ecx);  // @372_4f3390
  ecx = (u32)(EBP - 40);  // @373_4f3390
  PV[21] = (u32)(ecx);  // @374_4f3390
  ecx = (u32)(EBP - 252);  // @375_4f3390
  PV[22] = (u32)(ecx);  // @376_4f3390
  ecx = esi;  // @377_4f3390
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 716)))(ecx, PV[22], PV[21], PV[20]);  // @378_4f3390
  ecx = edx = 0;  // @379_4f3390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @380_4f3390
  FL[2] = (edx & edx);  // @381_4f3390
  if (FL[2] == 0) goto L4f389c;  // @382_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @383_4f3390
  PV[23] = (u32)(edx);  // @384_4f3390
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @385_4f3390
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @386_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[23]);  // @387_4f3390
  ecx = edx = 0;  // @388_4f3390
  ecx = (u32)(EBP - 232);  // @389_4f3390
  PV[24] = (u32)(ecx);  // @390_4f3390
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @391_4f3390
  ecx = eax;  // @392_4f3390
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, PV[24], (u32)(1));  // @393_4f3390
  ecx = edx = 0;  // @394_4f3390
  ecx = (u32)(EBP - 232);  // @395_4f3390
  reg.state = (s32)((u32)(0));  // @396_4f3390
  eax = ext_4cc1d0_thiscall1(ecx);  // @397_4f3390
    // @398_4f3390
  PV[25] = (u32)(eax);  // @399_4f3390
  eax = ((u32( *)(u32, u32))(*(u32 *)0x676258))(PV[25], (u32)(47));  // @400_4f3390
  ecx = edx = 0;  // @401_4f3390
  FL[2] = (eax & eax);  // @402_4f3390
  if (FL[2] != 0) goto L4f387c;  // @403_4f3390
  ecx = (u32)(EBP - 232);  // @404_4f3390
  eax = ext_4cc1d0_thiscall1(ecx);  // @405_4f3390
    // @406_4f3390
  L4f387c:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 252), sizeof v); (u32)v; });  // @408_4f3390
  ecx = (u32)(EBP - 232);  // @409_4f3390
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @410_4f3390
  reg.state = (s32)((u32)(4294967295));  // @411_4f3390
  eax = ext_4cbec0_thiscall1(ecx);  // @412_4f3390
  ecx = edx = 0;  // @413_4f3390
  goto L4f38a2;  // @414_4f3390
  L4f389c:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @416_4f3390
  L4f38a2:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @418_4f3390
  eax = (u32)(EBP - 284);  // @419_4f3390
  PV[26] = (u32)(eax);  // @420_4f3390
  ecx = edi;  // @421_4f3390
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[26]);  // @422_4f3390
  ecx = edx = 0;  // @423_4f3390
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @424_4f3390
  edx = eax;  // @425_4f3390
  if (FL[0] != FL[1]) goto L4f36b0;  // @426_4f3390
  L4f38bf:;
  eax = ebx;  // @428_4f3390
  SEH_LEAVE();  // @429_4f3390
  ext_633654(G(u32, 0x6f5630));  // @430_4f3390
  return eax;  // @431_4f3390
}
PCREG(4f3390, lifted_4f3390);

