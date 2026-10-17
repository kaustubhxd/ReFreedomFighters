// batch234020.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 STDCALL ext_5c7160_stdcall2(u32, u32) __asm__("ext_5c7160");
extern "C" u32 STDCALL ext_5c74a0_stdcall1(u32) __asm__("ext_5c74a0");
extern "C" u32 STDCALL ext_5c7a00_stdcall1(u32) __asm__("ext_5c7a00");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_5c61b0_thiscall3(u32, u32, u32) __asm__("ext_5c61b0");
extern "C" u32 THISCALL ext_5c6640_thiscall1(u32) __asm__("ext_5c6640");
extern "C" u32 THISCALL ext_5c7980_thiscall2(u32, u32) __asm__("ext_5c7980");
extern "C" u32 THISCALL ext_5c7a40_thiscall2(u32, u32) __asm__("ext_5c7a40");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5c6770(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5c6770
  eax = ext_5c6640_thiscall1(ecx);  // @1_5c6770
  ecx = edx = 0;  // @2_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @3_5c6770
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; });  // @4_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, PV[0]);  // @6_5c6770
  ecx = edx = 0;  // @7_5c6770
  edi = eax;  // @8_5c6770
  FL[2] = (edi & edi);  // @9_5c6770
  if (FL[2] == 0) goto L5c69bc;  // @10_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @11_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @12_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; });  // @13_5c6770
  ecx = (ecx >> (u32)(10));  // @14_5c6770
  FL[3] = ecx;  // @15_5c6770
  ecx = (ecx & 0xffffff00u) | (((~(ecx & 0xff))) & 0xff);  // @16_5c6770
  FL[2] = ((ecx & 0xff) & (u32)(1));  // @17_5c6770
  if (FL[2] == 0) goto L5c69bc;  // @18_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 96), sizeof v); (u32)v; });  // @19_5c6770
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(ebx + 100), &v, sizeof v); }  // @20_5c6770
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; });  // @21_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5c6770
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @23_5c6770
  ecx = edx = 0;  // @24_5c6770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }); FL[1] = eax;  // @25_5c6770
  if (FL[0] != FL[1]) goto L5c67d7;  // @26_5c6770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 100), &v, sizeof v); }  // @27_5c6770
  L5c67d7:;
  PV[1] = (u32)(edi);  // @29_5c6770
  ecx = ebx;  // @30_5c6770
  eax = ext_5c74a0_stdcall1(PV[1]);  // @31_5c6770
  ecx = edx = 0;  // @32_5c6770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @33_5c6770
  if (FL[2] != 0) goto L5c682a;  // @34_5c6770
  PV[2] = (u32)(edi);  // @35_5c6770
  ecx = ebx;  // @36_5c6770
  eax = ext_5c7a40_thiscall2(ecx, PV[2]);  // @37_5c6770
  ecx = edx = 0;  // @38_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @39_5c6770
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 32), sizeof v); (u32)v; });  // @40_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @43_5c6770
  ecx = edx = 0;  // @44_5c6770
  FL[2] = (eax & eax);  // @45_5c6770
  if (FL[2] == 0) goto L5c680e;  // @46_5c6770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @47_5c6770
  ecx = eax;  // @48_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @49_5c6770
  ecx = edx = 0;  // @50_5c6770
  L5c680e:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 32), &v, sizeof v); }  // @52_5c6770
  ext_633654(G(u32, 0x6f5630));  // @53_5c6770
  return eax;  // @54_5c6770
  L5c682a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @56_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_5c6770
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @58_5c6770
  ecx = edx = 0;  // @59_5c6770
  ecx = ebx;  // @60_5c6770
  PV[4] = (u32)(edi);  // @61_5c6770
  FL[2] = (eax & eax);  // @62_5c6770
  if (FL[2] == 0) goto L5c686f;  // @63_5c6770
  eax = ext_5c7a40_thiscall2(ecx, PV[4]);  // @64_5c6770
  ecx = edx = 0;  // @65_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 109) + 0), 4); v; });  // @66_5c6770
  X0[1] = 0;  // @67_5c6770
  X0[2] = 0;  // @68_5c6770
  X0[3] = 0;  // @69_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @70_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @71_5c6770
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @72_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @73_5c6770
  eax = (eax - ecx);  // @74_5c6770
  FL[3] = eax;  // @75_5c6770
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @76_5c6770
  X0[0] = F2U((float)(s32)X0[0]);  // @77_5c6770
  X0[1] = F2U((float)(s32)X0[1]);  // @78_5c6770
  X0[2] = F2U((float)(s32)X0[2]);  // @79_5c6770
  X0[3] = F2U((float)(s32)X0[3]);  // @80_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @81_5c6770
  __builtin_memcpy((void *)((u32)(edi + 36) + 0), &X0[0], 4);  // @82_5c6770
  goto L5c6897;  // @83_5c6770
  L5c686f:;
  eax = ext_5c7980_thiscall2(ecx, PV[4]);  // @85_5c6770
  ecx = edx = 0;  // @86_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 36) + 0), 4); v; });  // @87_5c6770
  X0[1] = 0;  // @88_5c6770
  X0[2] = 0;  // @89_5c6770
  X0[3] = 0;  // @90_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @91_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_5c6770
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @93_5c6770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); FL[1] = ecx;  // @94_5c6770
  if ((s32)FL[0] <= (s32)FL[1]) goto L5c6897;  // @95_5c6770
  PV[5] = (u32)(edi);  // @96_5c6770
  ecx = ebx;  // @97_5c6770
  eax = ext_5c7a00_stdcall1(PV[5]);  // @98_5c6770
  ecx = edx = 0;  // @99_5c6770
  L5c6897:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 28), sizeof v); (u32)v; });  // @101_5c6770
  edx = (u32)((EBP - 272) + 220);  // @102_5c6770
  PV[6] = (u32)(edx);  // @103_5c6770
  edx = (u32)((EBP - 276) + 236);  // @104_5c6770
  PV[7] = (u32)(edx);  // @105_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_5c6770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[7], PV[6]);  // @107_5c6770
  ecx = edx = 0;  // @108_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 232) + 0), 4); v; });  // @109_5c6770
  X0[1] = 0;  // @110_5c6770
  X0[2] = 0;  // @111_5c6770
  X0[3] = 0;  // @112_5c6770
  eax = (u32)((EBP - 272) + 24);  // @113_5c6770
  __builtin_memcpy((void *)((u32)((EBP - 272) + 24) + 0), &X0[0], 4);  // @114_5c6770
  edx = (u32)((EBP - 272) + 220);  // @115_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 236) + 0), 4); v; });  // @116_5c6770
  X0[1] = 0;  // @117_5c6770
  X0[2] = 0;  // @118_5c6770
  X0[3] = 0;  // @119_5c6770
  __builtin_memcpy((void *)((u32)((EBP - 272) + 28) + 0), &X0[0], 4);  // @120_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 240) + 0), 4); v; });  // @121_5c6770
  X0[1] = 0;  // @122_5c6770
  X0[2] = 0;  // @123_5c6770
  X0[3] = 0;  // @124_5c6770
  PV[8] = (u32)(ecx);  // @125_5c6770
  __builtin_memcpy((void *)((u32)((EBP - 276) + 36) + 0), &X0[0], 4);  // @126_5c6770
  ecx = (u32)((EBP - 276) + 88);  // @127_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @128_5c6770
  X0[1] = 0;  // @129_5c6770
  X0[2] = 0;  // @130_5c6770
  X0[3] = 0;  // @131_5c6770
  PV[9] = X0[0];  // @132_5c6770
  PV[10] = (u32)(eax);  // @133_5c6770
  eax = ext_443ef0_fastcall4(ecx, edx, PV[10], PV[9]);  // @134_5c6770
  ecx = edx = 0;  // @135_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @136_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @137_5c6770
  FL[2] = (ecx & ecx);  // @138_5c6770
  if (FL[2] == 0) goto L5c69bc;  // @139_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @140_5c6770
  edx = (u32)((EBP - 272) + 60);  // @141_5c6770
  PV[11] = (u32)(edx);  // @142_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[11]);  // @143_5c6770
  ecx = edx = 0;  // @144_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @145_5c6770
  edx = (u32)((EBP - 272) + 60);  // @146_5c6770
  PV[12] = (u32)(edx);  // @147_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @148_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[12]);  // @150_5c6770
  ecx = edx = 0;  // @151_5c6770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 60), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @152_5c6770
  esi = eax;  // @153_5c6770
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 272) + 20), &v, sizeof v); }  // @154_5c6770
  if (FL[0] == FL[1]) goto L5c69bc;  // @155_5c6770
  L5c6940:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @157_5c6770
  PV[13] = (u32)(esi);  // @158_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @159_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[13]);  // @161_5c6770
  ecx = edx = 0;  // @162_5c6770
  ecx = eax;  // @163_5c6770
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 272) + 12), &v, sizeof v); }  // @164_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 84), sizeof v); (u32)v; });  // @165_5c6770
  FL[2] = (eax & eax);  // @166_5c6770
  if (FL[2] == 0) goto L5c699f;  // @167_5c6770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @168_5c6770
  if (FL[0] != FL[1]) goto L5c699f;  // @169_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @170_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @171_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097268));  // @172_5c6770
  ecx = edx = 0;  // @173_5c6770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @174_5c6770
  if (FL[2] == 0) goto L5c69d1;  // @175_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 12), sizeof v); (u32)v; });  // @176_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @177_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1080), sizeof v); (u32)v; });  // @178_5c6770
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @179_5c6770
  ecx = edx = 0;  // @180_5c6770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @181_5c6770
  if (FL[2] == 0) goto L5c69d1;  // @182_5c6770
  PV[14] = (u32)(edi);  // @183_5c6770
  PV[15] = (u32)(esi);  // @184_5c6770
  ecx = ebx;  // @185_5c6770
  eax = ext_5c7160_stdcall2(PV[15], PV[14]);  // @186_5c6770
  ecx = edx = 0;  // @187_5c6770
  L5c6992:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @189_5c6770
  if (FL[2] == 0) goto L5c699f;  // @190_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @191_5c6770
  PV[16] = (u32)(esi);  // @192_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @193_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, PV[16]);  // @194_5c6770
  ecx = edx = 0;  // @195_5c6770
  L5c699f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @197_5c6770
  edx = (u32)((EBP - 272) + 60);  // @198_5c6770
  PV[17] = (u32)(edx);  // @199_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @200_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[17]);  // @202_5c6770
  ecx = edx = 0;  // @203_5c6770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 60), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @204_5c6770
  esi = eax;  // @205_5c6770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 272) + 20), &v, sizeof v); }  // @206_5c6770
  if (FL[0] != FL[1]) goto L5c6940;  // @207_5c6770
  L5c69bc:;
  ext_633654(G(u32, 0x6f5630));  // @209_5c6770
  return eax;  // @210_5c6770
  L5c69d1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 12), sizeof v); (u32)v; });  // @212_5c6770
  ecx = (u32)((EBP - 272) + 208);  // @213_5c6770
  PV[18] = (u32)(ecx);  // @214_5c6770
  ecx = eax;  // @215_5c6770
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 276) + 20), &v, sizeof v); }  // @216_5c6770
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @217_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 928)))(ecx, PV[18]);  // @218_5c6770
  ecx = edx = 0;  // @219_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 16), sizeof v); (u32)v; });  // @220_5c6770
  PV[19] = (u32)(eax);  // @221_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 920)))(ecx, PV[19]);  // @222_5c6770
  ecx = edx = 0;  // @223_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 12), sizeof v); (u32)v; });  // @224_5c6770
  edx = (u32)((EBP - 272) + 208);  // @225_5c6770
  PV[20] = (u32)(edx);  // @226_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @227_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[20]);  // @228_5c6770
  ecx = edx = 0;  // @229_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 24) + 0), 4); v; });  // @230_5c6770
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 24) + 4), 4); v; });  // @231_5c6770
  X0[2] = 0;  // @232_5c6770
  X0[3] = 0;  // @233_5c6770
  ecx = (u32)((EBP - 272) + 36);  // @234_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 32), sizeof v); (u32)v; });  // @235_5c6770
  __builtin_memcpy((void *)((u32)((EBP - 272) + 36) + 0), &X0[0], 4);  // @236_5c6770
  __builtin_memcpy((void *)((u32)((EBP - 272) + 36) + 4), &X0[1], 4);  // @237_5c6770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 272) + 44), &v, sizeof v); }  // @238_5c6770
  eax = ext_44c840_thiscall1(ecx);  // @239_5c6770
  ecx = 0;  // @240_5c6770
  eax = (u32)((EBP - 272) + 220);  // @241_5c6770
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @242_5c6770
  PV[21] = (u32)(eax);  // @243_5c6770
  edx = (u32)((EBP - 276) + 212);  // @244_5c6770
  ecx = (u32)((EBP - 276) + 52);  // @245_5c6770
  eax = ext_43e920_fastcall3(ecx, edx, PV[21]);  // @246_5c6770
  ecx = edx = 0;  // @247_5c6770
  ecx = (u32)((EBP - 272) + 48);  // @248_5c6770
  eax = ext_44c840_thiscall1(ecx);  // @249_5c6770
  ecx = 0;  // @250_5c6770
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 52) + 0), 4); v; });  // @251_5c6770
  X1[1] = 0;  // @252_5c6770
  X1[2] = 0;  // @253_5c6770
  X1[3] = 0;  // @254_5c6770
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @255_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 48) + 0), 4); v; });  // @256_5c6770
  X0[1] = 0;  // @257_5c6770
  X0[2] = 0;  // @258_5c6770
  X0[3] = 0;  // @259_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 36) + 0), 4); v; })));  // @260_5c6770
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 40) + 0), 4); v; })));  // @261_5c6770
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @262_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 56) + 0), 4); v; });  // @263_5c6770
  X0[1] = 0;  // @264_5c6770
  X0[2] = 0;  // @265_5c6770
  X0[3] = 0;  // @266_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 44) + 0), 4); v; })));  // @267_5c6770
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @268_5c6770
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @269_5c6770
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @270_5c6770
  ecx = edx = 0;  // @271_5c6770
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @272_5c6770
  X1[1] = 0;  // @273_5c6770
  X1[2] = 0;  // @274_5c6770
  X1[3] = 0;  // @275_5c6770
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @276_5c6770
  FA = U2D(X1[0], X1[1]); FB = U2D(X0[0], X0[1]);  // @277_5c6770
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5c6b8e;  // @278_5c6770
  eax = (u32)((EBP - 272) + 220);  // @279_5c6770
  PV[22] = (u32)(eax);  // @280_5c6770
  edx = (u32)((EBP - 276) + 212);  // @281_5c6770
  ecx = (u32)((EBP - 276) + 76);  // @282_5c6770
  eax = ext_43e920_fastcall3(ecx, edx, PV[22]);  // @283_5c6770
  ecx = edx = 0;  // @284_5c6770
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 72) + 0), 4); v; });  // @285_5c6770
  X1[1] = 0;  // @286_5c6770
  X1[2] = 0;  // @287_5c6770
  X1[3] = 0;  // @288_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 76) + 0), 4); v; });  // @289_5c6770
  X0[1] = 0;  // @290_5c6770
  X0[2] = 0;  // @291_5c6770
  X0[3] = 0;  // @292_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @293_5c6770
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @294_5c6770
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @295_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 272) + 80) + 0), 4); v; });  // @296_5c6770
  X0[1] = 0;  // @297_5c6770
  X0[2] = 0;  // @298_5c6770
  X0[3] = 0;  // @299_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @300_5c6770
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @301_5c6770
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @302_5c6770
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @303_5c6770
  ecx = edx = 0;  // @304_5c6770
  X1[0] = 0;  // @305_5c6770
  X1[1] = 0;  // @306_5c6770
  X1[2] = 0;  // @307_5c6770
  X1[3] = 0;  // @308_5c6770
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @309_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @310_5c6770
  X0[1] = 0;  // @311_5c6770
  X0[2] = 0;  // @312_5c6770
  X0[3] = 0;  // @313_5c6770
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @314_5c6770
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L5c6b8e;  // @315_5c6770
  ecx = (u32)((EBP - 272) + 96);  // @316_5c6770
  eax = ext_4e1b60_thiscall1(ecx);  // @317_5c6770
    // @318_5c6770
  edx = (u32)((EBP - 272) + 232);  // @319_5c6770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 272) + 96), &v, sizeof v); }  // @320_5c6770
  ecx = (u32)((EBP - 272) + 96);  // @321_5c6770
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 272) + 100), &v, sizeof v); }  // @322_5c6770
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)((EBP - 272) + 104), &v, sizeof v); }  // @323_5c6770
  eax = ext_4419f0_fastcall2(ecx, edx);  // @324_5c6770
  ecx = edx = 0;  // @325_5c6770
  edx = (u32)((EBP - 272) + 220);  // @326_5c6770
  ecx = (u32)((EBP - 272) + 96);  // @327_5c6770
  eax = ext_441940_fastcall2(ecx, edx);  // @328_5c6770
  ecx = edx = 0;  // @329_5c6770
  eax = (u32)((EBP - 272) + 96);  // @330_5c6770
  PV[23] = (u32)(eax);  // @331_5c6770
  edx = (u32)((EBP - 276) + 212);  // @332_5c6770
  ecx = (u32)((EBP - 276) + 112);  // @333_5c6770
  eax = ext_43e920_fastcall3(ecx, edx, PV[23]);  // @334_5c6770
  ecx = edx = 0;  // @335_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @336_5c6770
  edx = (u32)((EBP - 272) + 96);  // @337_5c6770
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 272) + 204), &v, sizeof v); }  // @338_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @339_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @340_5c6770
  PV[24] = (u32)(edx);  // @341_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @342_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @343_5c6770
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[24], (u32)(0), (u32)(1), (u32)(2097152), (u32)(1), (u32)(0));  // @344_5c6770
  ecx = edx = 0;  // @345_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 16), sizeof v); (u32)v; });  // @346_5c6770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @347_5c6770
  ecx = (ecx & 0xff);  // @348_5c6770
  eax = (u32)(1);  // @349_5c6770
  if (FL[2] == 0) ecx = eax;  // @350_5c6770
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 272) + 16), &v, sizeof v); }  // @351_5c6770
  L5c6b8e:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 20), sizeof v); (u32)v; });  // @353_5c6770
  ecx = ebx;  // @354_5c6770
  PV[25] = (u32)(edi);  // @355_5c6770
  PV[26] = (u32)(esi);  // @356_5c6770
  eax = ext_5c7160_stdcall2(PV[26], PV[25]);  // @357_5c6770
  ecx = edx = 0;  // @358_5c6770
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 272) + 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @359_5c6770
  if (FL[0] == FL[1]) goto L5c6992;  // @360_5c6770
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @361_5c6770
  if (FL[2] != 0) goto L5c699f;  // @362_5c6770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @363_5c6770
  PV[27] = (u32)(esi);  // @364_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @365_5c6770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[27]);  // @366_5c6770
  ecx = edx = 0;  // @367_5c6770
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 40) + 0), 4); v; });  // @368_5c6770
  X0[1] = 0;  // @369_5c6770
  X0[2] = 0;  // @370_5c6770
  X0[3] = 0;  // @371_5c6770
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @372_5c6770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @373_5c6770
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @374_5c6770
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); FL[1] = ecx;  // @375_5c6770
  if ((s32)FL[0] <= (s32)FL[1]) goto L5c699f;  // @376_5c6770
  PV[28] = (u32)(edi);  // @377_5c6770
  eax = (u32)((EBP - 276) + 212);  // @378_5c6770
  ecx = ebx;  // @379_5c6770
  PV[29] = (u32)(eax);  // @380_5c6770
  eax = ext_5c61b0_thiscall3(ecx, PV[29], PV[28]);  // @381_5c6770
  ecx = edx = 0;  // @382_5c6770
  goto L5c699f;  // @383_5c6770
}
PCREG(5c6770, lifted_5c6770);

