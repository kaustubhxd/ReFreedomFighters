// batch230017.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_4df040_fastcall4(u32, u32, u32, u32) __asm__("ext_4df040");
extern "C" u32 STDCALL ext_4e5de0_stdcall2(u32, u32) __asm__("ext_4e5de0");
extern "C" u32 ext_634dc4_cdecl0(void) __asm__("ext_634dc4");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4e54c0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
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
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_4e54c0
  X1[0] = 0;  // @1_4e54c0
  X1[1] = 0;  // @2_4e54c0
  X1[2] = 0;  // @3_4e54c0
  X1[3] = 0;  // @4_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_4e54c0
  { float a_ = U2F(X1[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 24) + 0), 4); v; })); X1[0] = (a_ > b_) ? X1[0] : F2U(b_); }  // @6_4e54c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @7_4e54c0
  ebx = ecx;  // @8_4e54c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @9_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @10_4e54c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @11_4e54c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @12_4e54c0
  if (FL[0] == FL[1]) goto L4e5520;  // @13_4e54c0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @14_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @15_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 4), &X0[1], 4);  // @16_4e54c0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 12)) : "st");  // @17_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @18_4e54c0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @19_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @20_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 4), &X0[1], 4);  // @21_4e54c0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 12)) : "st");  // @22_4e54c0
  eax = ext_634dc4_cdecl0();  // @23_4e54c0
    // @24_4e54c0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 8)) :: "st");  // @25_4e54c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @26_4e54c0
  X0[1] = 0;  // @27_4e54c0
  X0[2] = 0;  // @28_4e54c0
  X0[3] = 0;  // @29_4e54c0
  goto L4e552b;  // @30_4e54c0
  L4e5520:;
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @32_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @33_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @34_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @35_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @36_4e54c0
  { float a_ = U2F(X0[0]), b_ = U2F(X1[0]); X0[0] = (a_ < b_) ? X0[0] : F2U(b_); }  // @37_4e54c0
  L4e552b:;
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 10), sizeof v); (u32)v; });  // @39_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @40_4e54c0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @41_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @42_4e54c0
  FL[2] = ((ecx & 0xff) & (u32)(8));  // @43_4e54c0
  if (FL[2] == 0) goto L4e556a;  // @44_4e54c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @45_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 28), sizeof v); (u32)v; });  // @46_4e54c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @47_4e54c0
  edx = (u32)(eax + eax*2);  // @48_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4), sizeof v); (u32)v; });  // @49_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @50_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4 + 4), sizeof v); (u32)v; });  // @51_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @52_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edx*4 + 8), sizeof v); (u32)v; });  // @53_4e54c0
  ecx = edi;  // @54_4e54c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @55_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @56_4e54c0
  goto L4e5699;  // @57_4e54c0
  L4e556a:;
  PV[0] = (u32)(eax);  // @59_4e54c0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @60_4e54c0
  ecx = ebx;  // @61_4e54c0
  eax = ext_4e5de0_stdcall2(PV[1], PV[0]);  // @62_4e54c0
  ecx = edx = 0;  // @63_4e54c0
  PV[2] = (u32)(eax);  // @64_4e54c0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @65_4e54c0
  ecx = ebx;  // @66_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @67_4e54c0
  eax = ext_4e5de0_stdcall2(PV[3], PV[2]);  // @68_4e54c0
  ecx = edx = 0;  // @69_4e54c0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 10), sizeof v); (u32)v; });  // @70_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @71_4e54c0
  FL[2] = ((ecx & 0xff) & (u32)(4));  // @72_4e54c0
  if (FL[2] == 0) goto L4e5699;  // @73_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @74_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @75_4e54c0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }));  // @76_4e54c0
  FL[3] = edx;  // @77_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @78_4e54c0
  eax = (u32)(eax + eax*2);  // @79_4e54c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @80_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @81_4e54c0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @82_4e54c0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4e55c2;  // @83_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @84_4e54c0
  FL[2] = (ecx & ecx);  // @85_4e54c0
  if (FL[2] == 0) goto L4e55c1;  // @86_4e54c0
  eax = ((u32(THISCALL *)(u32))(ecx))(ecx);  // @87_4e54c0
  ecx = edx = 0;  // @88_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @89_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @90_4e54c0
  goto L4e55c2;  // @91_4e54c0
  L4e55c1:;
  __builtin_trap();  // @93_4e54c0
  L4e55c2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4), sizeof v); (u32)v; });  // @95_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @96_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @97_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @98_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 4), sizeof v); (u32)v; });  // @99_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @100_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @101_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 8), sizeof v); (u32)v; });  // @102_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @103_4e54c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @104_4e54c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; }); FL[1] = eax;  // @105_4e54c0
  if (FL[0] == FL[1]) goto L4e5699;  // @106_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @107_4e54c0
  ecx = ebx;  // @108_4e54c0
  eax = (eax + 1);  // @109_4e54c0
  FL[3] = eax;  // @110_4e54c0
  PV[4] = (u32)(eax);  // @111_4e54c0
  PV[5] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; });  // @112_4e54c0
  eax = ext_4e5de0_stdcall2(PV[5], PV[4]);  // @113_4e54c0
  ecx = edx = 0;  // @114_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @115_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @116_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @117_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 12), sizeof v); (u32)v; });  // @118_4e54c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @119_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 16), sizeof v); (u32)v; });  // @120_4e54c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @121_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + eax*4 + 20), sizeof v); (u32)v; });  // @122_4e54c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @123_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @124_4e54c0
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @125_4e54c0
  if ((s32)FL[0] > (s32)FL[1]) goto L4e5631;  // @126_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @127_4e54c0
  FL[2] = (eax & eax);  // @128_4e54c0
  if (FL[2] == 0) goto L4e5630;  // @129_4e54c0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @130_4e54c0
  ecx = edx = 0;  // @131_4e54c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @132_4e54c0
  goto L4e5631;  // @133_4e54c0
  L4e5630:;
  __builtin_trap();  // @135_4e54c0
  L4e5631:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 44), sizeof v); (u32)v; });  // @137_4e54c0
  ecx = (ecx - eax);  // @138_4e54c0
  FL[3] = ecx;  // @139_4e54c0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @140_4e54c0
  X2[1] = 0;  // @141_4e54c0
  X2[2] = 0;  // @142_4e54c0
  X2[3] = 0;  // @143_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @144_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @145_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @146_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @147_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @148_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @149_4e54c0
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @150_4e54c0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @151_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @152_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @153_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @154_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @155_4e54c0
  X2[0] = F2U(U2F(X2[0]) / U2F(X0[0]));  // @156_4e54c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @157_4e54c0
  X0[1] = 0;  // @158_4e54c0
  X0[2] = 0;  // @159_4e54c0
  X0[3] = 0;  // @160_4e54c0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @161_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @162_4e54c0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })));  // @163_4e54c0
  __builtin_memcpy((void *)((u32)(eax) + 0), &X0[0], 4);  // @164_4e54c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @165_4e54c0
  X0[1] = 0;  // @166_4e54c0
  X0[2] = 0;  // @167_4e54c0
  X0[3] = 0;  // @168_4e54c0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @169_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @170_4e54c0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; })));  // @171_4e54c0
  __builtin_memcpy((void *)((u32)(eax + 4) + 0), &X0[0], 4);  // @172_4e54c0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @173_4e54c0
  X0[1] = 0;  // @174_4e54c0
  X0[2] = 0;  // @175_4e54c0
  X0[3] = 0;  // @176_4e54c0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @177_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @178_4e54c0
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; })));  // @179_4e54c0
  __builtin_memcpy((void *)((u32)(eax + 8) + 0), &X0[0], 4);  // @180_4e54c0
  L4e5699:;
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 10), sizeof v); (u32)v; });  // @182_4e54c0
  FL[2] = ((eax & 0xff) & (u32)(16));  // @183_4e54c0
  if (FL[2] == 0) goto L4e56d7;  // @184_4e54c0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; });  // @185_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; });  // @186_4e54c0
  ecx = (ecx + ecx);  // @187_4e54c0
  FL[3] = ecx;  // @188_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8), sizeof v); (u32)v; });  // @189_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @190_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8 + 4), sizeof v); (u32)v; });  // @191_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @192_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8 + 8), sizeof v); (u32)v; });  // @193_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @194_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8 + 12), sizeof v); (u32)v; });  // @195_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @196_4e54c0
  ext_633654(G(u32, 0x6f5630));  // @197_4e54c0
  return eax;  // @198_4e54c0
  L4e56d7:;
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @200_4e54c0
  ecx = ebx;  // @201_4e54c0
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @202_4e54c0
  eax = ext_4e5de0_stdcall2(PV[7], PV[6]);  // @203_4e54c0
  ecx = edx = 0;  // @204_4e54c0
  edx = eax;  // @205_4e54c0
  ecx = ebx;  // @206_4e54c0
  PV[8] = (u32)(edx);  // @207_4e54c0
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @208_4e54c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @209_4e54c0
  eax = ext_4e5de0_stdcall2(PV[9], PV[8]);  // @210_4e54c0
  ecx = edx = 0;  // @211_4e54c0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 10), sizeof v); (u32)v; });  // @212_4e54c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @213_4e54c0
  FL[2] = ((ecx & 0xff) & (u32)(1));  // @214_4e54c0
  if (FL[2] == 0) goto L4e581b;  // @215_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @216_4e54c0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }));  // @217_4e54c0
  FL[3] = edx;  // @218_4e54c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @219_4e54c0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @220_4e54c0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4e5723;  // @221_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @222_4e54c0
  FL[2] = (eax & eax);  // @223_4e54c0
  if (FL[2] == 0) goto L4e5722;  // @224_4e54c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @225_4e54c0
  ecx = edx = 0;  // @226_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @227_4e54c0
  goto L4e5723;  // @228_4e54c0
  L4e5722:;
  __builtin_trap();  // @230_4e54c0
  L4e5723:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @232_4e54c0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6911068) + 0), 4); v; });  // @233_4e54c0
  X4[1] = 0;  // @234_4e54c0
  X4[2] = 0;  // @235_4e54c0
  X4[3] = 0;  // @236_4e54c0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8 + 2), sizeof v); (u32)v; }));  // @237_4e54c0
  X3[0] = eax; X3[1] = X3[2] = X3[3] = 0;  // @238_4e54c0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8 + 4), sizeof v); (u32)v; }));  // @239_4e54c0
  X3[0] = F2U((float)(s32)X3[0]);  // @240_4e54c0
  X3[1] = F2U((float)(s32)X3[1]);  // @241_4e54c0
  X3[2] = F2U((float)(s32)X3[2]);  // @242_4e54c0
  X3[3] = F2U((float)(s32)X3[3]);  // @243_4e54c0
  X2[0] = eax; X2[1] = X2[2] = X2[3] = 0;  // @244_4e54c0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8 + 6), sizeof v); (u32)v; }));  // @245_4e54c0
  X2[0] = F2U((float)(s32)X2[0]);  // @246_4e54c0
  X2[1] = F2U((float)(s32)X2[1]);  // @247_4e54c0
  X2[2] = F2U((float)(s32)X2[2]);  // @248_4e54c0
  X2[3] = F2U((float)(s32)X2[3]);  // @249_4e54c0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @250_4e54c0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*8), sizeof v); (u32)v; }));  // @251_4e54c0
  X1[0] = F2U((float)(s32)X1[0]);  // @252_4e54c0
  X1[1] = F2U((float)(s32)X1[1]);  // @253_4e54c0
  X1[2] = F2U((float)(s32)X1[2]);  // @254_4e54c0
  X1[3] = F2U((float)(s32)X1[3]);  // @255_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @256_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @257_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @258_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @259_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @260_4e54c0
  X3[0] = F2U(U2F(X3[0]) * U2F(X4[0]));  // @261_4e54c0
  X2[0] = F2U(U2F(X2[0]) * U2F(X4[0]));  // @262_4e54c0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @263_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @264_4e54c0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X3[0], 4);  // @265_4e54c0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X2[0], 4);  // @266_4e54c0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @267_4e54c0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X1[0], 4);  // @268_4e54c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @269_4e54c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = eax;  // @270_4e54c0
  if (FL[0] == FL[1]) goto L4e5997;  // @271_4e54c0
  eax = (u32)(ecx + 1);  // @272_4e54c0
  ecx = ebx;  // @273_4e54c0
  PV[10] = (u32)(eax);  // @274_4e54c0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @275_4e54c0
  eax = ext_4e5de0_stdcall2(PV[11], PV[10]);  // @276_4e54c0
  ecx = edx = 0;  // @277_4e54c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @278_4e54c0
  ebx = eax;  // @279_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @280_4e54c0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6911068) + 0), 4); v; });  // @281_4e54c0
  X1[1] = 0;  // @282_4e54c0
  X1[2] = 0;  // @283_4e54c0
  X1[3] = 0;  // @284_4e54c0
  ecx = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*8 + 8), sizeof v); (u32)v; }));  // @285_4e54c0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*8 + 12), sizeof v); (u32)v; }));  // @286_4e54c0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @287_4e54c0
  ecx = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*8 + 10), sizeof v); (u32)v; }));  // @288_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @289_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @290_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @291_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @292_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @293_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @294_4e54c0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @295_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @296_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @297_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @298_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @299_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @300_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @301_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @302_4e54c0
  eax = (u32)(s32)(s16)(({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*8 + 14), sizeof v); (u32)v; }));  // @303_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @304_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @305_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @306_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @307_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @308_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @309_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @310_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @311_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @312_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @313_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @314_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @315_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @316_4e54c0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @317_4e54c0
  if ((s32)FL[0] > (s32)FL[1]) goto L4e5932;  // @318_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @319_4e54c0
  FL[2] = (eax & eax);  // @320_4e54c0
  if (FL[2] != 0) goto L4e592d;  // @321_4e54c0
  __builtin_trap();  // @322_4e54c0
  L4e581b:;
  FL[2] = ((ecx & 0xff) & (u32)(2));  // @324_4e54c0
  if (FL[2] == 0) goto L4e5978;  // @325_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @326_4e54c0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }));  // @327_4e54c0
  FL[3] = edx;  // @328_4e54c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @329_4e54c0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @330_4e54c0
  if ((s32)FL[0] <= (s32)FL[1]) goto L4e5843;  // @331_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @332_4e54c0
  FL[2] = (eax & eax);  // @333_4e54c0
  if (FL[2] == 0) goto L4e5842;  // @334_4e54c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @335_4e54c0
  ecx = edx = 0;  // @336_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @337_4e54c0
  goto L4e5843;  // @338_4e54c0
  L4e5842:;
  __builtin_trap();  // @340_4e54c0
  L4e5843:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @342_4e54c0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6911072) + 0), 4); v; });  // @343_4e54c0
  X4[1] = 0;  // @344_4e54c0
  X4[2] = 0;  // @345_4e54c0
  X4[3] = 0;  // @346_4e54c0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 1), sizeof v); (u32)v; }));  // @347_4e54c0
  X3[0] = eax; X3[1] = X3[2] = X3[3] = 0;  // @348_4e54c0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 2), sizeof v); (u32)v; }));  // @349_4e54c0
  X3[0] = F2U((float)(s32)X3[0]);  // @350_4e54c0
  X3[1] = F2U((float)(s32)X3[1]);  // @351_4e54c0
  X3[2] = F2U((float)(s32)X3[2]);  // @352_4e54c0
  X3[3] = F2U((float)(s32)X3[3]);  // @353_4e54c0
  X2[0] = eax; X2[1] = X2[2] = X2[3] = 0;  // @354_4e54c0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 3), sizeof v); (u32)v; }));  // @355_4e54c0
  X2[0] = F2U((float)(s32)X2[0]);  // @356_4e54c0
  X2[1] = F2U((float)(s32)X2[1]);  // @357_4e54c0
  X2[2] = F2U((float)(s32)X2[2]);  // @358_4e54c0
  X2[3] = F2U((float)(s32)X2[3]);  // @359_4e54c0
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @360_4e54c0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4), sizeof v); (u32)v; }));  // @361_4e54c0
  X1[0] = F2U((float)(s32)X1[0]);  // @362_4e54c0
  X1[1] = F2U((float)(s32)X1[1]);  // @363_4e54c0
  X1[2] = F2U((float)(s32)X1[2]);  // @364_4e54c0
  X1[3] = F2U((float)(s32)X1[3]);  // @365_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @366_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @367_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @368_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @369_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @370_4e54c0
  X3[0] = F2U(U2F(X3[0]) * U2F(X4[0]));  // @371_4e54c0
  X2[0] = F2U(U2F(X2[0]) * U2F(X4[0]));  // @372_4e54c0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @373_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X4[0]));  // @374_4e54c0
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X3[0], 4);  // @375_4e54c0
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X2[0], 4);  // @376_4e54c0
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @377_4e54c0
  __builtin_memcpy((void *)((u32)(edi + 12) + 0), &X1[0], 4);  // @378_4e54c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @379_4e54c0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }); FL[1] = eax;  // @380_4e54c0
  if (FL[0] == FL[1]) goto L4e5997;  // @381_4e54c0
  eax = (u32)(ecx + 1);  // @382_4e54c0
  ecx = ebx;  // @383_4e54c0
  PV[12] = (u32)(eax);  // @384_4e54c0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @385_4e54c0
  eax = ext_4e5de0_stdcall2(PV[13], PV[12]);  // @386_4e54c0
  ecx = edx = 0;  // @387_4e54c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @388_4e54c0
  ebx = eax;  // @389_4e54c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @390_4e54c0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6911072) + 0), 4); v; });  // @391_4e54c0
  X1[1] = 0;  // @392_4e54c0
  X1[2] = 0;  // @393_4e54c0
  X1[3] = 0;  // @394_4e54c0
  ecx = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4 + 4), sizeof v); (u32)v; }));  // @395_4e54c0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4 + 6), sizeof v); (u32)v; }));  // @396_4e54c0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @397_4e54c0
  ecx = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4 + 5), sizeof v); (u32)v; }));  // @398_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @399_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @400_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @401_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @402_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @403_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @404_4e54c0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @405_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @406_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @407_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @408_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @409_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @410_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @411_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @412_4e54c0
  eax = (u32)(s32)(s8)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + edx*4 + 7), sizeof v); (u32)v; }));  // @413_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @414_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @415_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @416_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @417_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @418_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @419_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @420_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @421_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @422_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @423_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @424_4e54c0
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @425_4e54c0
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @426_4e54c0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @427_4e54c0
  if ((s32)FL[0] > (s32)FL[1]) goto L4e5932;  // @428_4e54c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @429_4e54c0
  FL[2] = (eax & eax);  // @430_4e54c0
  if (FL[2] == 0) goto L4e5931;  // @431_4e54c0
  L4e592d:;
  eax = ((u32(STDCALL *)(void))(eax))();  // @433_4e54c0
  ecx = edx = 0;  // @434_4e54c0
  goto L4e5932;  // @435_4e54c0
  L4e5931:;
  __builtin_trap();  // @437_4e54c0
  L4e5932:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @439_4e54c0
  edx = edi;  // @440_4e54c0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @441_4e54c0
  X1[1] = 0;  // @442_4e54c0
  X1[2] = 0;  // @443_4e54c0
  X1[3] = 0;  // @444_4e54c0
  ebx = (ebx - eax);  // @445_4e54c0
  FL[3] = ebx;  // @446_4e54c0
  PV[14] = (u32)(ecx);  // @447_4e54c0
  ecx = edi;  // @448_4e54c0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @449_4e54c0
  eax = (u32)(EBP - 20);  // @450_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @451_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @452_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @453_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @454_4e54c0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @455_4e54c0
  X0[0] = ebx; X0[1] = X0[2] = X0[3] = 0;  // @456_4e54c0
  X0[0] = F2U((float)(s32)X0[0]);  // @457_4e54c0
  X0[1] = F2U((float)(s32)X0[1]);  // @458_4e54c0
  X0[2] = F2U((float)(s32)X0[2]);  // @459_4e54c0
  X0[3] = F2U((float)(s32)X0[3]);  // @460_4e54c0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @461_4e54c0
  PV[15] = X1[0];  // @462_4e54c0
  PV[16] = (u32)(eax);  // @463_4e54c0
  eax = ext_4df040_fastcall4(ecx, edx, PV[16], PV[15]);  // @464_4e54c0
  ecx = edx = 0;  // @465_4e54c0
  ext_633654(G(u32, 0x6f5630));  // @466_4e54c0
  return eax;  // @467_4e54c0
  L4e5978:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @469_4e54c0
  FL[2] = (eax & eax);  // @470_4e54c0
  if (FL[2] == 0) goto L4e5996;  // @471_4e54c0
  eax = ((u32(STDCALL *)(void))(eax))();  // @472_4e54c0
  ecx = edx = 0;  // @473_4e54c0
  ext_633654(G(u32, 0x6f5630));  // @474_4e54c0
  return eax;  // @475_4e54c0
  L4e5996:;
  __builtin_trap();  // @477_4e54c0
  L4e5997:;
  ext_633654(G(u32, 0x6f5630));  // @479_4e54c0
  return eax;  // @480_4e54c0
}
PCREG(4e54c0, lifted_4e54c0);

