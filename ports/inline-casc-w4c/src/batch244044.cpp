// batch244044.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4e0830_fastcall2(u32, u32) __asm__("ext_4e0830");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_53b6d0_thiscall1(u32) __asm__("ext_53b6d0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5390d0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, ebxh = 0, edxh = 0, ecxh = 0, eaxh = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 52), &v, sizeof v); }  // @1_5390d0
  ebx = (u32)((EBP - 380) + 232);  // @2_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 48), &v, sizeof v); }  // @4_5390d0
  esi = (u32)(ecx + 30);  // @5_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @6_5390d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 380) + 56), &v, sizeof v); }  // @7_5390d0
  edi = 0;  // @8_5390d0
  FL[3] = edi;  // @9_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 44), &v, sizeof v); }  // @10_5390d0
  L539112:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi - 9), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @12_5390d0
  if (FL[0] == FL[1]) goto L53916b;  // @13_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_5390d0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[0]);  // @18_5390d0
  ecx = edx = 0;  // @19_5390d0
  ecx = (u32)((EBP - 380) + 148);  // @20_5390d0
  ecx = (ecx + edi);  // @21_5390d0
  FL[3] = ecx;  // @22_5390d0
  PV[1] = (u32)(ecx);  // @23_5390d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_5390d0
  ecx = eax;  // @25_5390d0
  PV[2] = (u32)(ebx);  // @26_5390d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[2], PV[1]);  // @27_5390d0
  ecx = edx = 0;  // @28_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5390d0
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @30_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[3]);  // @33_5390d0
  ecx = edx = 0;  // @34_5390d0
  ecx = (u32)((EBP - 380) + 100);  // @35_5390d0
  ecx = (ecx + edi);  // @36_5390d0
  FL[3] = ecx;  // @37_5390d0
  PV[4] = (u32)(ecx);  // @38_5390d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_5390d0
  ecx = (u32)((EBP - 384) + 200);  // @40_5390d0
  PV[5] = (u32)(ecx);  // @41_5390d0
  ecx = eax;  // @42_5390d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 128)))(ecx, PV[5], PV[4]);  // @43_5390d0
  ecx = edx = 0;  // @44_5390d0
  L53916b:;
  edi = (edi + (u32)(12));  // @46_5390d0
  FL[3] = edi;  // @47_5390d0
  esi = (esi + (u32)(13));  // @48_5390d0
  FL[3] = esi;  // @49_5390d0
  ebx = (ebx + (u32)(36));  // @50_5390d0
  FL[3] = ebx;  // @51_5390d0
  FL[0] = edi; FL[1] = (u32)(48);  // @52_5390d0
  if ((s32)FL[0] < (s32)FL[1]) goto L539112;  // @53_5390d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 52), sizeof v); (u32)v; });  // @54_5390d0
  FL[2] = (ebx & ebx);  // @55_5390d0
  if (FL[2] == 0) goto L53963e;  // @56_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_5390d0
  ecx = (u32)((EBP - 380) + 64);  // @58_5390d0
  PV[6] = (u32)(ecx);  // @59_5390d0
  ecx = ebx;  // @60_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[6]);  // @61_5390d0
  ecx = edx = 0;  // @62_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @63_5390d0
  ecx = (u32)((EBP - 380) + 64);  // @64_5390d0
  PV[7] = (u32)(ecx);  // @65_5390d0
  ecx = ebx;  // @66_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[7]);  // @67_5390d0
  ecx = edx = 0;  // @68_5390d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 64), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @69_5390d0
  edx = eax;  // @70_5390d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 380) + 24), &v, sizeof v); }  // @71_5390d0
  if (FL[0] == FL[1]) goto L53963e;  // @72_5390d0
  L5391b0:;
  eax = (eax | (u32)(4294967295));  // @74_5390d0
  FL[3] = eax;  // @75_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 20), &v, sizeof v); }  // @76_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_5390d0
  PV[8] = (u32)(edx);  // @78_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, PV[8]);  // @81_5390d0
  ecx = edx = 0;  // @82_5390d0
  ebx = eax;  // @83_5390d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)((EBP - 380) + 60), &v, sizeof v); }  // @84_5390d0
  FL[2] = (ebx & ebx);  // @85_5390d0
  if (FL[2] == 0) goto L53961f;  // @86_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 124), sizeof v); (u32)v; });  // @87_5390d0
  FL[2] = (eax & eax);  // @88_5390d0
  if (FL[2] == 0) goto L53961f;  // @89_5390d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 56), sizeof v); (u32)v; });  // @90_5390d0
  ecx = edi;  // @91_5390d0
  PV[9] = (u32)(eax);  // @92_5390d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @93_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 64)))(ecx, PV[9]);  // @94_5390d0
  ecx = edx = 0;  // @95_5390d0
  PV[10] = (u32)(eax);  // @96_5390d0
  ecx = edi;  // @97_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 476)))(ecx, PV[10]);  // @98_5390d0
  ecx = edx = 0;  // @99_5390d0
  FL[2] = (eax & eax);  // @100_5390d0
  if (FL[2] == 0) goto L53961f;  // @101_5390d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @102_5390d0
  FL[0] = edx; FL[1] = (u32)(11);  // @103_5390d0
  if (FL[0] == FL[1]) goto L53961f;  // @104_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @105_5390d0
  eax = (eax + (u32)(-2));  // @106_5390d0
  FL[3] = eax;  // @107_5390d0
  FL[0] = eax; FL[1] = (u32)(7);  // @108_5390d0
  if (FL[0] > FL[1]) goto L5392e6;  // @109_5390d0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5478056), sizeof v); (u32)v; });  // @110_5390d0
  switch (eax) {  // @111_5390d0
  case 0: goto L539227;  // @112_5390d0
  case 1: goto L539289;  // @113_5390d0
  default: __builtin_trap(); }  // @114_5390d0
  L539227:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 120) + 0), 4); v; });  // @116_5390d0
  X0[1] = 0;  // @117_5390d0
  X0[2] = 0;  // @118_5390d0
  X0[3] = 0;  // @119_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @120_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @121_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 132) + 0), 4); v; });  // @122_5390d0
  X1[1] = 0;  // @123_5390d0
  X1[2] = 0;  // @124_5390d0
  X1[3] = 0;  // @125_5390d0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @126_5390d0
  X2[1] = 0;  // @127_5390d0
  X2[2] = 0;  // @128_5390d0
  X2[3] = 0;  // @129_5390d0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @130_5390d0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @131_5390d0
  ecx = (ecx - eax);  // @132_5390d0
  FL[3] = ecx;  // @133_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 16) + 0), &X1[0], 4);  // @135_5390d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = ecx;  // @136_5390d0
  if ((s32)FL[0] > (s32)FL[1]) goto L53959c;  // @137_5390d0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(64));  // @138_5390d0
  if (FL[2] != 0) goto L53959c;  // @139_5390d0
  FL[0] = edx; FL[1] = (u32)(10);  // @140_5390d0
  if (FL[0] == FL[1]) goto L53927d;  // @141_5390d0
  FL[0] = edx; FL[1] = (u32)(2);  // @142_5390d0
  if (FL[0] != FL[1]) goto L53959c;  // @143_5390d0
  L53927d:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @145_5390d0
  goto L53959c;  // @146_5390d0
  L539289:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 120) + 0), 4); v; });  // @148_5390d0
  X0[1] = 0;  // @149_5390d0
  X0[2] = 0;  // @150_5390d0
  X0[3] = 0;  // @151_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @152_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @153_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; });  // @154_5390d0
  X1[1] = 0;  // @155_5390d0
  X1[2] = 0;  // @156_5390d0
  X1[3] = 0;  // @157_5390d0
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(ebx + 12), &v, sizeof v); }  // @158_5390d0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @159_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 16) + 0), &X1[0], 4);  // @160_5390d0
  ecx = (ecx - eax);  // @161_5390d0
  FL[3] = ecx;  // @162_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @163_5390d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = ecx;  // @164_5390d0
  if ((s32)FL[0] < (s32)FL[1]) goto L539594;  // @165_5390d0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(64));  // @166_5390d0
  if (FL[2] != 0) goto L539594;  // @167_5390d0
  FL[0] = edx; FL[1] = (u32)(10);  // @168_5390d0
  if (FL[0] == FL[1]) goto L5392da;  // @169_5390d0
  FL[0] = edx; FL[1] = (u32)(2);  // @170_5390d0
  if (FL[0] != FL[1]) goto L539594;  // @171_5390d0
  L5392da:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @173_5390d0
  goto L539594;  // @174_5390d0
  L5392e6:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20649), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @176_5390d0
  if (FL[0] == FL[1]) goto L53934d;  // @177_5390d0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(8));  // @178_5390d0
  if (FL[2] == 0) goto L539310;  // @179_5390d0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 24), sizeof v); (u32)v; });  // @180_5390d0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @181_5390d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 384) + 48), sizeof v); (u32)v; });  // @182_5390d0
  ecx = ebx;  // @183_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @184_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[11]);  // @185_5390d0
  ecx = edx = 0;  // @186_5390d0
  goto L53961f;  // @187_5390d0
  L539310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 208), sizeof v); (u32)v; });  // @189_5390d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 48), sizeof v); (u32)v; });  // @190_5390d0
  PV[12] = (u32)(ecx);  // @191_5390d0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @192_5390d0
  ecx = esi;  // @193_5390d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @194_5390d0
  { double a_ = (double)(s32)X0[0], b_ = (double)(s32)X0[1]; SD(&X0[0], a_); SD(&X0[2], b_); }  // @195_5390d0
  eax = (eax >> (u32)(31));  // @196_5390d0
  FL[3] = eax;  // @197_5390d0
  SD(&X0[0], U2D(X0[0], X0[1]) + U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax*8 + 6818464) + 4), 4); v; })));  // @198_5390d0
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @199_5390d0
  PV[13] = X0[0];  // @200_5390d0
  PV[14] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 388) + 32), sizeof v); (u32)v; });  // @201_5390d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 152)))(ecx, PV[14], PV[13], (u32)(0));  // @202_5390d0
  ecx = edx = 0;  // @203_5390d0
  goto L53961f;  // @204_5390d0
  L53934d:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 92) + 0), 4); v; });  // @206_5390d0
  X1[1] = 0;  // @207_5390d0
  X1[2] = 0;  // @208_5390d0
  X1[3] = 0;  // @209_5390d0
  eax = (u32)((EBP - 380) + 100);  // @210_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802756) + 0), 4); v; });  // @211_5390d0
  X0[1] = 0;  // @212_5390d0
  X0[2] = 0;  // @213_5390d0
  X0[3] = 0;  // @214_5390d0
  esi = 0;  // @215_5390d0
  FL[3] = esi;  // @216_5390d0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @217_5390d0
  edi = (edi + (u32)(21));  // @218_5390d0
  FL[3] = edi;  // @219_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 32), &v, sizeof v); }  // @220_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 28) + 0), &X0[0], 4);  // @221_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 40) + 0), &X1[0], 4);  // @222_5390d0
  L539377:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @224_5390d0
  if (FL[0] == FL[1]) goto L5393c1;  // @225_5390d0
  ecx = (u32)(ebx + 212);  // @226_5390d0
  edx = eax;  // @227_5390d0
  eax = ext_4e0830_fastcall2(ecx, edx);  // @228_5390d0
  ecx = edx = 0;  // @229_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 40) + 0), 4); v; });  // @230_5390d0
  X1[1] = 0;  // @231_5390d0
  X1[2] = 0;  // @232_5390d0
  X1[3] = 0;  // @233_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 32), sizeof v); (u32)v; });  // @234_5390d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 380) + 36)) :: "st");  // @235_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 36) + 0), 4); v; });  // @236_5390d0
  X0[1] = 0;  // @237_5390d0
  X0[2] = 0;  // @238_5390d0
  X0[3] = 0;  // @239_5390d0
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L5393bb;  // @240_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 28) + 0), 4); v; });  // @241_5390d0
  X1[1] = 0;  // @242_5390d0
  X1[2] = 0;  // @243_5390d0
  X1[3] = 0;  // @244_5390d0
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L5393bb;  // @245_5390d0
  ecx = esi;  // @246_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 28) + 0), &X0[0], 4);  // @247_5390d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 380) + 20), &v, sizeof v); }  // @248_5390d0
  goto L5393c5;  // @249_5390d0
  L5393bb:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 28) + 0), 4); v; });  // @251_5390d0
  X0[1] = 0;  // @252_5390d0
  X0[2] = 0;  // @253_5390d0
  X0[3] = 0;  // @254_5390d0
  L5393c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 20), sizeof v); (u32)v; });  // @256_5390d0
  L5393c5:;
  esi = (esi + 1);  // @258_5390d0
  FL[3] = esi;  // @259_5390d0
  eax = (eax + (u32)(12));  // @260_5390d0
  FL[3] = eax;  // @261_5390d0
  edi = (edi + (u32)(13));  // @262_5390d0
  FL[3] = edi;  // @263_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 32), &v, sizeof v); }  // @264_5390d0
  FL[0] = esi; FL[1] = (u32)(4);  // @265_5390d0
  if ((s32)FL[0] < (s32)FL[1]) goto L539377;  // @266_5390d0
  FL[0] = ecx; FL[1] = (u32)(-1);  // @267_5390d0
  if (FL[0] == FL[1]) goto L5395ab;  // @268_5390d0
  SD(&X0[0], (double)U2F(X0[0]));  // @269_5390d0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @270_5390d0
  ecx = edx = 0;  // @271_5390d0
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @272_5390d0
  X1[0] = 0;  // @273_5390d0
  X1[1] = 0;  // @274_5390d0
  X1[2] = 0;  // @275_5390d0
  X1[3] = 0;  // @276_5390d0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @277_5390d0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @278_5390d0
  if (!__builtin_parity(FL[2] & 0xff)) goto L5393ff;  // @279_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @280_5390d0
  X0[1] = 0;  // @281_5390d0
  X0[2] = 0;  // @282_5390d0
  X0[3] = 0;  // @283_5390d0
  L5393ff:;
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 84) + 0), 4); v; })));  // @285_5390d0
  esi = (u32)((EBP - 380) + 148);  // @286_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 20), sizeof v); (u32)v; });  // @287_5390d0
  ecx = (u32)(ebx + 212);  // @288_5390d0
  edi = (u32)(eax + eax*2);  // @289_5390d0
  edi = (edi << (u32)(2));  // @290_5390d0
  FL[3] = edi;  // @291_5390d0
  esi = (esi + edi);  // @292_5390d0
  FL[3] = esi;  // @293_5390d0
  edx = esi;  // @294_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 136) + 0), 4); v; });  // @295_5390d0
  X1[1] = 0;  // @296_5390d0
  X1[2] = 0;  // @297_5390d0
  X1[3] = 0;  // @298_5390d0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 132) + 0), 4); v; })));  // @299_5390d0
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @300_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 212) + 0), 4); v; });  // @301_5390d0
  X0[1] = 0;  // @302_5390d0
  X0[2] = 0;  // @303_5390d0
  X0[3] = 0;  // @304_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 88) + 0), &X0[0], 4);  // @305_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 216) + 0), 4); v; });  // @306_5390d0
  X0[1] = 0;  // @307_5390d0
  X0[2] = 0;  // @308_5390d0
  X0[3] = 0;  // @309_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 92) + 0), &X0[0], 4);  // @310_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 220) + 0), 4); v; });  // @311_5390d0
  X0[1] = 0;  // @312_5390d0
  X0[2] = 0;  // @313_5390d0
  X0[3] = 0;  // @314_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 16) + 0), &X1[0], 4);  // @315_5390d0
  __builtin_memcpy((void *)((u32)((EBP - 380) + 96) + 0), &X0[0], 4);  // @316_5390d0
  eax = ext_43e960_fastcall2(ecx, edx);  // @317_5390d0
  ecx = edx = 0;  // @318_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 20), sizeof v); (u32)v; });  // @319_5390d0
  edx = (u32)((EBP - 380) + 232);  // @320_5390d0
  ecx = (u32)(ebx + 212);  // @321_5390d0
  eax = (u32)(eax + eax*8);  // @322_5390d0
  edx = (u32)(edx + eax*4);  // @323_5390d0
  eax = ext_441a60_fastcall2(ecx, edx);  // @324_5390d0
  ecx = edx = 0;  // @325_5390d0
  edx = (u32)((EBP - 380) + 88);  // @326_5390d0
  ecx = esi;  // @327_5390d0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @328_5390d0
  ecx = edx = 0;  // @329_5390d0
  esi = (u32)((EBP - 380) + 100);  // @330_5390d0
  esi = (esi + edi);  // @331_5390d0
  FL[3] = esi;  // @332_5390d0
  edx = (u32)((EBP - 380) + 88);  // @333_5390d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 380) + 36)) :: "st");  // @334_5390d0
  ecx = esi;  // @335_5390d0
  eax = ext_4e0870_fastcall2(ecx, edx);  // @336_5390d0
  ecx = edx = 0;  // @337_5390d0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 380) + 40)) :: "st");  // @338_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 40) + 0), 4); v; });  // @339_5390d0
  X1[1] = 0;  // @340_5390d0
  X1[2] = 0;  // @341_5390d0
  X1[3] = 0;  // @342_5390d0
  X0[0] = 0;  // @343_5390d0
  X0[1] = 0;  // @344_5390d0
  X0[2] = 0;  // @345_5390d0
  X0[3] = 0;  // @346_5390d0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))) ? 0x40 : 0)) << 8);  // @347_5390d0
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))) ? 0x40 : 0)) & 68);  // @348_5390d0
  if (__builtin_parity(FL[2] & 0xff)) goto L5394c6;  // @349_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 36) + 0), 4); v; });  // @350_5390d0
  X0[1] = 0;  // @351_5390d0
  X0[2] = 0;  // @352_5390d0
  X0[3] = 0;  // @353_5390d0
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @354_5390d0
  goto L5394ce;  // @355_5390d0
  L5394c6:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; });  // @357_5390d0
  X0[1] = 0;  // @358_5390d0
  X0[2] = 0;  // @359_5390d0
  X0[3] = 0;  // @360_5390d0
  L5394ce:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 60), sizeof v); (u32)v; });  // @362_5390d0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(16));  // @363_5390d0
  __builtin_memcpy((void *)((u32)(ebx + 88) + 0), &X0[0], 4);  // @364_5390d0
  if (FL[2] == 0) goto L53954a;  // @365_5390d0
  PV[15] = (u32)(esi);  // @366_5390d0
  edx = (u32)((EBP - 384) + 92);  // @367_5390d0
  ecx = (u32)((EBP - 384) + 80);  // @368_5390d0
  eax = ext_43e920_fastcall3(ecx, edx, PV[15]);  // @369_5390d0
  ecx = edx = 0;  // @370_5390d0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 76) + 0), 4); v; });  // @371_5390d0
  X1[1] = 0;  // @372_5390d0
  X1[2] = 0;  // @373_5390d0
  X1[3] = 0;  // @374_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 80) + 0), 4); v; });  // @375_5390d0
  X0[1] = 0;  // @376_5390d0
  X0[2] = 0;  // @377_5390d0
  X0[3] = 0;  // @378_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @379_5390d0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @380_5390d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @381_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 84) + 0), 4); v; });  // @382_5390d0
  X0[1] = 0;  // @383_5390d0
  X0[2] = 0;  // @384_5390d0
  X0[3] = 0;  // @385_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @386_5390d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @387_5390d0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @388_5390d0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @389_5390d0
  ecx = edx = 0;  // @390_5390d0
  X1[0] = 0;  // @391_5390d0
  X1[1] = 0;  // @392_5390d0
  X1[2] = 0;  // @393_5390d0
  X1[3] = 0;  // @394_5390d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(4294967279))); __builtin_memcpy((void *)(u32)(ebx + 64), &v, sizeof v); }  // @395_5390d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; });  // @396_5390d0
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @397_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 120) + 0), 4); v; });  // @398_5390d0
  X0[1] = 0;  // @399_5390d0
  X0[2] = 0;  // @400_5390d0
  X0[3] = 0;  // @401_5390d0
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6956272) + 0), 4); v; })));  // @402_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6803812) + 0), 4); v; })));  // @403_5390d0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @404_5390d0
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806012) + 0), 4); v; })));  // @405_5390d0
  __builtin_memcpy((void *)((u32)(ebx + 120) + 0), &X1[0], 4);  // @406_5390d0
  L53954a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 120) + 0), 4); v; });  // @408_5390d0
  X0[1] = 0;  // @409_5390d0
  X0[2] = 0;  // @410_5390d0
  X0[3] = 0;  // @411_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784556) + 0), 4); v; })));  // @412_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 108), sizeof v); (u32)v; });  // @413_5390d0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @414_5390d0
  ecx = (ecx - eax);  // @415_5390d0
  FL[3] = ecx;  // @416_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @417_5390d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }); FL[1] = ecx;  // @418_5390d0
  if ((s32)FL[0] < (s32)FL[1]) goto L539584;  // @419_5390d0
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(64));  // @420_5390d0
  if (FL[2] != 0) goto L539584;  // @421_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @422_5390d0
  FL[0] = eax; FL[1] = (u32)(10);  // @423_5390d0
  if (FL[0] == FL[1]) goto L53957d;  // @424_5390d0
  FL[0] = eax; FL[1] = (u32)(2);  // @425_5390d0
  if (FL[0] != FL[1]) goto L539584;  // @426_5390d0
  L53957d:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @428_5390d0
  L539584:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 16) + 0), 4); v; });  // @430_5390d0
  X1[1] = 0;  // @431_5390d0
  X1[2] = 0;  // @432_5390d0
  X1[3] = 0;  // @433_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 140), &v, sizeof v); }  // @434_5390d0
  L539594:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; });  // @436_5390d0
  X2[1] = 0;  // @437_5390d0
  X2[2] = 0;  // @438_5390d0
  X2[3] = 0;  // @439_5390d0
  L53959c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @441_5390d0
  FL[0] = eax; FL[1] = (u32)(4);  // @442_5390d0
  if (FL[0] > FL[1]) goto L5395ef;  // @443_5390d0
  switch (eax) {  // @444_5390d0
  case 0: goto L5395c7;  // @445_5390d0
  case 1: goto L5395d1;  // @446_5390d0
  case 2: goto L5395ef;  // @447_5390d0
  case 3: goto L5395db;  // @448_5390d0
  case 4: goto L5395e5;  // @449_5390d0
  default: __builtin_trap(); }  // @450_5390d0
  L5395ab:;
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 64), sizeof v); (u32)v; }) & (u32)(8));  // @452_5390d0
  if (FL[2] == 0) goto L539584;  // @453_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 44), sizeof v); (u32)v; });  // @454_5390d0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 24), sizeof v); (u32)v; });  // @455_5390d0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @456_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @457_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[16]);  // @458_5390d0
  ecx = edx = 0;  // @459_5390d0
  goto L53961f;  // @460_5390d0
  L5395c7:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806016) + 0), 4); v; })));  // @462_5390d0
  goto L5395e9;  // @463_5390d0
  L5395d1:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @465_5390d0
  goto L5395e9;  // @466_5390d0
  L5395db:;
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @468_5390d0
  goto L5395e9;  // @469_5390d0
  L5395e5:;
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @471_5390d0
  L5395e9:;
  __builtin_memcpy((void *)((u32)((EBP - 380) + 16) + 0), &X1[0], 4);  // @473_5390d0
  L5395ef:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 48), sizeof v); (u32)v; });  // @475_5390d0
  PV[17] = (u32)(ecx);  // @476_5390d0
  PV[18] = X1[0];  // @477_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @478_5390d0
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 388) + 32), sizeof v); (u32)v; });  // @479_5390d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[19], PV[18], (u32)(0));  // @480_5390d0
  ecx = edx = 0;  // @481_5390d0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 380) + 16) + 0), 4); v; });  // @482_5390d0
  X0[1] = 0;  // @483_5390d0
  X0[2] = 0;  // @484_5390d0
  X0[3] = 0;  // @485_5390d0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @486_5390d0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @487_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 208), &v, sizeof v); }  // @488_5390d0
  L53961f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 52), sizeof v); (u32)v; });  // @490_5390d0
  edx = (u32)((EBP - 380) + 64);  // @491_5390d0
  PV[20] = (u32)(edx);  // @492_5390d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @493_5390d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[20]);  // @494_5390d0
  ecx = edx = 0;  // @495_5390d0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 64), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @496_5390d0
  edx = eax;  // @497_5390d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 380) + 24), &v, sizeof v); }  // @498_5390d0
  if (FL[0] != FL[1]) goto L5391b0;  // @499_5390d0
  L53963e:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 380) + 56), sizeof v); (u32)v; });  // @501_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 118), &v, sizeof v); }  // @502_5390d0
  ecx = (u32)(ebx + 74);  // @503_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 114), &v, sizeof v); }  // @504_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 110), &v, sizeof v); }  // @505_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 130), &v, sizeof v); }  // @506_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 126), &v, sizeof v); }  // @507_5390d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 122), &v, sizeof v); }  // @508_5390d0
  eax = ext_4de7a0_thiscall1(ecx);  // @509_5390d0
    // @510_5390d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 21246), sizeof v); (u32)v; });  // @511_5390d0
  FL[2] = (ecx & ecx);  // @512_5390d0
  if (FL[2] == 0) goto L539686;  // @513_5390d0
  eax = ext_53b6d0_thiscall1(ecx);  // @514_5390d0
    // @515_5390d0
  L539686:;
  ext_633654(G(u32, 0x6f5630));  // @517_5390d0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @518_5390d0
  return eax;  // @519_5390d0
}
PCREG(5390d0, lifted_5390d0);

