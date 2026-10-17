// batch230019.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_44e630_fastcall2(u32, u32) __asm__("ext_44e630");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4856f0_thiscall1(u32) __asm__("ext_4856f0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e1b60_thiscall1(u32) __asm__("ext_4e1b60");
extern "C" u32 THISCALL ext_4e64a0_thiscall1(u32) __asm__("ext_4e64a0");
extern "C" u32 THISCALL ext_4e64b0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4e64b0");
extern "C" u32 THISCALL ext_4e65e0_thiscall3(u32, u32, u32) __asm__("ext_4e65e0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_485110(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_485110
  ecx = (u32)(EBP - 328);  // @1_485110
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 264), &v, sizeof v); }  // @2_485110
  eax = ext_4e64a0_thiscall1(ecx);  // @3_485110
    // @4_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @5_485110
  ecx = (u32)(EBP - 40);  // @6_485110
  PV[0] = (u32)(ecx);  // @7_485110
  ecx = (u32)(EBP - 112);  // @8_485110
  PV[1] = (u32)(ecx);  // @9_485110
  ecx = ebx;  // @10_485110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1436)))(ecx, PV[1], PV[0]);  // @11_485110
  ecx = edx = 0;  // @12_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_485110
  ecx = (u32)(EBP - 52);  // @14_485110
  PV[2] = (u32)(ecx);  // @15_485110
  ecx = ebx;  // @16_485110
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1476)))(ecx, PV[2]);  // @17_485110
  ecx = edx = 0;  // @18_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_485110
  edx = (u32)(EBP - 40);  // @20_485110
  PV[3] = (u32)(ecx);  // @21_485110
  ecx = (u32)(EBP - 340);  // @22_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @23_485110
  X0[1] = 0;  // @24_485110
  X0[2] = 0;  // @25_485110
  X0[3] = 0;  // @26_485110
  eax = (u32)(EBP - 52);  // @27_485110
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @28_485110
  PV[4] = X0[0];  // @29_485110
  PV[5] = (u32)(eax);  // @30_485110
  eax = ext_443ef0_fastcall4(ecx, edx, PV[5], PV[4]);  // @31_485110
  ecx = edx = 0;  // @32_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @33_485110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 1265), &v, sizeof v); }  // @34_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @35_485110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 52) + 0), 4); v; });  // @36_485110
  X1[1] = 0;  // @37_485110
  X1[2] = 0;  // @38_485110
  X1[3] = 0;  // @39_485110
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 336) + 0), 4); v; })));  // @40_485110
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @41_485110
  X2[1] = 0;  // @42_485110
  X2[2] = 0;  // @43_485110
  X2[3] = 0;  // @44_485110
  edx = (u32)(ecx + 1204);  // @45_485110
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @46_485110
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @47_485110
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; })));  // @48_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1200), sizeof v); (u32)v; });  // @49_485110
  eax = (eax + (u32)(301));  // @50_485110
  FL[3] = eax;  // @51_485110
  __builtin_memcpy((void *)((u32)(EBP - 300) + 0), &X2[0], 4);  // @52_485110
  __builtin_memcpy((void *)((u32)(EBP - 304) + 0), &X1[0], 4);  // @53_485110
  eax = (u32)(ecx + eax*4);  // @54_485110
  FL[0] = edx; FL[1] = eax;  // @55_485110
  if (FL[0] == FL[1]) goto L485687;  // @56_485110
  L4851e3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @58_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @59_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_485110
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @61_485110
  ecx = edx = 0;  // @62_485110
  edi = eax;  // @63_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @64_485110
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(2048));  // @65_485110
  if (FL[2] == 0) goto L48520f;  // @66_485110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_485110
  ecx = (u32)(esi + 8);  // @68_485110
  PV[6] = (u32)(ecx);  // @69_485110
  ecx = (u32)(esi + 20);  // @70_485110
  PV[7] = (u32)(ecx);  // @71_485110
  ecx = edi;  // @72_485110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[7], PV[6]);  // @73_485110
  ecx = edx = 0;  // @74_485110
  goto L48565a;  // @75_485110
  L48520f:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @77_485110
  if (FL[0] == FL[1]) goto L4856b3;  // @78_485110
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 1535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @79_485110
  if (FL[0] == FL[1]) goto L4856b3;  // @80_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @81_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @82_485110
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }) & (u32)(2));  // @83_485110
  if (FL[2] != 0) goto L4856b3;  // @84_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_485110
  ecx = (u32)(EBP - 28);  // @86_485110
  PV[8] = (u32)(ecx);  // @87_485110
  ecx = (u32)(EBP - 148);  // @88_485110
  PV[9] = (u32)(ecx);  // @89_485110
  ecx = edi;  // @90_485110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[9], PV[8]);  // @91_485110
  ecx = edx = 0;  // @92_485110
  eax = (u32)(EBP - 340);  // @93_485110
  ebx = (u32)(esi + 8);  // @94_485110
  PV[10] = (u32)(eax);  // @95_485110
  edx = ebx;  // @96_485110
  ecx = (u32)(EBP - 16);  // @97_485110
  eax = ext_43e920_fastcall3(ecx, edx, PV[10]);  // @98_485110
  ecx = edx = 0;  // @99_485110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @100_485110
  X1[1] = 0;  // @101_485110
  X1[2] = 0;  // @102_485110
  X1[3] = 0;  // @103_485110
  X0[0] = 0;  // @104_485110
  X0[1] = 0;  // @105_485110
  X0[2] = 0;  // @106_485110
  X0[3] = 0;  // @107_485110
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @108_485110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @109_485110
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @110_485110
  X2[1] = 0;  // @111_485110
  X2[2] = 0;  // @112_485110
  X2[3] = 0;  // @113_485110
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6835440) + 0), 4); v; })));  // @114_485110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @115_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @116_485110
  X0[1] = 0;  // @117_485110
  X0[2] = 0;  // @118_485110
  X0[3] = 0;  // @119_485110
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @120_485110
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @121_485110
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @122_485110
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L485696;  // @123_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @124_485110
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 300) + 0), 4); v; });  // @125_485110
  X3[1] = 0;  // @126_485110
  X3[2] = 0;  // @127_485110
  X3[3] = 0;  // @128_485110
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 52) + 0), 4); v; });  // @129_485110
  X2[1] = 0;  // @130_485110
  X2[2] = 0;  // @131_485110
  X2[3] = 0;  // @132_485110
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; })));  // @133_485110
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @134_485110
  X1[1] = 0;  // @135_485110
  X1[2] = 0;  // @136_485110
  X1[3] = 0;  // @137_485110
  X0[0] = X2[0];  // @138_485110
  X0[1] = X2[1];  // @139_485110
  X0[2] = X2[2];  // @140_485110
  X0[3] = X2[3];  // @141_485110
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @142_485110
  if (((!(U2F(X3[0]) >= U2F(X0[0]))) || (!((U2F(X3[0]) < U2F(X0[0])) || (U2F(X3[0]) > U2F(X0[0])))))) goto L485696;  // @143_485110
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @144_485110
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 304) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 304) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 304) + 0), 4); v; }))))))) goto L485696;  // @145_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 60) + 0), 4); v; });  // @146_485110
  X0[1] = 0;  // @147_485110
  X0[2] = 0;  // @148_485110
  X0[3] = 0;  // @149_485110
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; }))))) goto L48534b;  // @150_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @151_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1265), sizeof v); (u32)v; });  // @152_485110
  FL[0] = ecx; FL[1] = (u32)(4);  // @153_485110
  if ((s32)FL[0] >= (s32)FL[1]) goto L485306;  // @154_485110
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + ecx*4 + 1249), &v, sizeof v); }  // @155_485110
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1265), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 1265), &v, sizeof v); }  // @156_485110
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1265), sizeof v); (u32)v; });  // @157_485110
  goto L485329;  // @158_485110
  L485306:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @160_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_485110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6864060), (u32)(1468));  // @162_485110
  ecx = edx = 0;  // @163_485110
  PV[11] = (u32)(eax);  // @164_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @165_485110
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 48)))(PV[11], (u32)(6864960));  // @166_485110
  ecx = edx = 0;  // @167_485110
  L485329:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @169_485110
  X0[1] = 0;  // @170_485110
  X0[2] = 0;  // @171_485110
  X0[3] = 0;  // @172_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @173_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @174_485110
  X0[1] = 0;  // @175_485110
  X0[2] = 0;  // @176_485110
  X0[3] = 0;  // @177_485110
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @178_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @179_485110
  X0[1] = 0;  // @180_485110
  X0[2] = 0;  // @181_485110
  X0[3] = 0;  // @182_485110
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @183_485110
  goto L485632;  // @184_485110
  L48534b:;
  eax = (u32)(EBP - 40);  // @186_485110
  edx = ebx;  // @187_485110
  PV[12] = (u32)(eax);  // @188_485110
  ecx = (u32)(EBP - 16);  // @189_485110
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @190_485110
  ecx = edx = 0;  // @191_485110
  eax = (u32)(EBP - 28);  // @192_485110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @193_485110
  PV[13] = (u32)(eax);  // @194_485110
  edx = ebx;  // @195_485110
  ecx = (u32)(EBP - 64);  // @196_485110
  eax = ext_43e920_fastcall3(ecx, edx, PV[13]);  // @197_485110
  ecx = edx = 0;  // @198_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @199_485110
  ecx = (u32)(EBP - 328);  // @200_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 60) + 0), 4); v; });  // @201_485110
  X0[1] = 0;  // @202_485110
  X0[2] = 0;  // @203_485110
  X0[3] = 0;  // @204_485110
  PV[14] = X0[0];  // @205_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 1245) + 0), 4); v; });  // @206_485110
  X0[1] = 0;  // @207_485110
  X0[2] = 0;  // @208_485110
  X0[3] = 0;  // @209_485110
  PV[15] = X0[0];  // @210_485110
  eax = ext_4e65e0_thiscall3(ecx, PV[15], PV[14]);  // @211_485110
    // @212_485110
  PV[16] = (u32)(ecx);  // @213_485110
  eax = (u32)(EBP - 16);  // @214_485110
  PV[17] = (u32)(eax);  // @215_485110
  eax = (u32)(EBP - 64);  // @216_485110
  PV[18] = (u32)(eax);  // @217_485110
  eax = (u32)(EBP - 52);  // @218_485110
  PV[19] = (u32)(eax);  // @219_485110
  ecx = (u32)(EBP - 328);  // @220_485110
  eax = ext_4e64b0_thiscall5(ecx, PV[19], PV[18], PV[17], (u32)(0));  // @221_485110
  ecx = edx = 0;  // @222_485110
  eax = (u32)(EBP - 64);  // @223_485110
  PV[20] = (u32)(eax);  // @224_485110
  edx = (u32)(EBP - 28);  // @225_485110
  ecx = (u32)(EBP - 16);  // @226_485110
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[20]);  // @227_485110
  ecx = edx = 0;  // @228_485110
  eax = (u32)(EBP - 40);  // @229_485110
  PV[21] = (u32)(eax);  // @230_485110
  edx = (u32)(EBP - 16);  // @231_485110
  ecx = (u32)(EBP - 320);  // @232_485110
  eax = ext_43e920_fastcall3(ecx, edx, PV[21]);  // @233_485110
  ecx = edx = 0;  // @234_485110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 316), &v, sizeof v); }  // @235_485110
  ecx = (u32)(EBP - 320);  // @236_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @237_485110
  X0[1] = 0;  // @238_485110
  X0[2] = 0;  // @239_485110
  X0[3] = 0;  // @240_485110
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806048) + 0), 4); v; })));  // @241_485110
  __builtin_memcpy((void *)((u32)(EBP - 268) + 0), &X0[0], 4);  // @242_485110
  eax = ext_44c840_thiscall1(ecx);  // @243_485110
  ecx = 0;  // @244_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 268) + 0), 4); v; });  // @245_485110
  X0[1] = 0;  // @246_485110
  X0[2] = 0;  // @247_485110
  X0[3] = 0;  // @248_485110
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 308)) :: "st");  // @249_485110
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 308) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 308) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 308) + 0), 4); v; }))))))) goto L485466;  // @250_485110
  ecx = (u32)(EBP - 320);  // @251_485110
  eax = ext_4856f0_thiscall1(ecx);  // @252_485110
    // @253_485110
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @254_485110
  if (FL[2] != 0) goto L485456;  // @255_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 268) + 0), 4); v; });  // @256_485110
  X0[1] = 0;  // @257_485110
  X0[2] = 0;  // @258_485110
  X0[3] = 0;  // @259_485110
  eax = (u32)(EBP - 320);  // @260_485110
  PV[22] = (u32)(ecx);  // @261_485110
  PV[23] = X0[0];  // @262_485110
  edx = (u32)(EBP - 40);  // @263_485110
  PV[24] = (u32)(eax);  // @264_485110
  ecx = (u32)(EBP - 16);  // @265_485110
  eax = ext_443ef0_fastcall4(ecx, edx, PV[24], PV[23]);  // @266_485110
  ecx = edx = 0;  // @267_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @268_485110
  X0[1] = 0;  // @269_485110
  X0[2] = 0;  // @270_485110
  X0[3] = 0;  // @271_485110
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @272_485110
  goto L485466;  // @273_485110
  L485456:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @275_485110
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @276_485110
  X0[2] = 0;  // @277_485110
  X0[3] = 0;  // @278_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @279_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @280_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @281_485110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @282_485110
  L485466:;
  ecx = (u32)(EBP - 260);  // @284_485110
  eax = ext_4e1b60_thiscall1(ecx);  // @285_485110
    // @286_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @287_485110
  X0[1] = 0;  // @288_485110
  X0[2] = 0;  // @289_485110
  X0[3] = 0;  // @290_485110
  eax = (u32)(EBP - 284);  // @291_485110
  __builtin_memcpy((void *)((u32)(EBP - 284) + 0), &X0[0], 4);  // @292_485110
  edx = (u32)(EBP - 296);  // @293_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @294_485110
  X0[1] = 0;  // @295_485110
  X0[2] = 0;  // @296_485110
  X0[3] = 0;  // @297_485110
  ecx = (u32)(EBP - 248);  // @298_485110
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @299_485110
  PV[25] = (u32)(eax);  // @300_485110
  __builtin_memcpy((void *)((u32)(EBP - 280) + 0), &X0[0], 4);  // @301_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @302_485110
  X0[1] = 0;  // @303_485110
  X0[2] = 0;  // @304_485110
  X0[3] = 0;  // @305_485110
  __builtin_memcpy((void *)((u32)(EBP - 276) + 0), &X0[0], 4);  // @306_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @307_485110
  X0[1] = 0;  // @308_485110
  X0[2] = 0;  // @309_485110
  X0[3] = 0;  // @310_485110
  __builtin_memcpy((void *)((u32)(EBP - 296) + 0), &X0[0], 4);  // @311_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @312_485110
  X0[1] = 0;  // @313_485110
  X0[2] = 0;  // @314_485110
  X0[3] = 0;  // @315_485110
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @316_485110
  __builtin_memcpy((void *)((u32)(EBP - 292) + 0), &X0[0], 4);  // @317_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @318_485110
  X0[1] = 0;  // @319_485110
  X0[2] = 0;  // @320_485110
  X0[3] = 0;  // @321_485110
  __builtin_memcpy((void *)((u32)(EBP - 288) + 0), &X0[0], 4);  // @322_485110
  eax = ext_43e920_fastcall3(ecx, edx, PV[25]);  // @323_485110
  ecx = edx = 0;  // @324_485110
  ecx = (u32)(EBP - 248);  // @325_485110
  eax = ext_4856f0_thiscall1(ecx);  // @326_485110
    // @327_485110
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @328_485110
  if (FL[2] != 0) goto L485632;  // @329_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 284) + 0), 4); v; });  // @330_485110
  X0[1] = 0;  // @331_485110
  X0[2] = 0;  // @332_485110
  X0[3] = 0;  // @333_485110
  edx = (u32)(EBP - 248);  // @334_485110
  __builtin_memcpy((void *)((u32)(EBP - 260) + 0), &X0[0], 4);  // @335_485110
  ecx = (u32)(EBP - 76);  // @336_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 280) + 0), 4); v; });  // @337_485110
  X0[1] = 0;  // @338_485110
  X0[2] = 0;  // @339_485110
  X0[3] = 0;  // @340_485110
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X0[0], 4);  // @341_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 276) + 0), 4); v; });  // @342_485110
  X0[1] = 0;  // @343_485110
  X0[2] = 0;  // @344_485110
  X0[3] = 0;  // @345_485110
  __builtin_memcpy((void *)((u32)(EBP - 252) + 0), &X0[0], 4);  // @346_485110
  eax = ext_44e630_fastcall2(ecx, edx);  // @347_485110
  ecx = edx = 0;  // @348_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 56) + 0), 4); v; });  // @349_485110
  X0[1] = 0;  // @350_485110
  X0[2] = 0;  // @351_485110
  X0[3] = 0;  // @352_485110
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @353_485110
  PV[26] = (u32)(ecx);  // @354_485110
  ecx = (u32)(EBP - 76);  // @355_485110
  PV[27] = X0[0];  // @356_485110
  eax = ext_4e0d00_thiscall2(ecx, PV[27]);  // @357_485110
    // @358_485110
  edx = (u32)(EBP - 76);  // @359_485110
  ecx = (u32)(EBP - 248);  // @360_485110
  eax = ext_441940_fastcall2(ecx, edx);  // @361_485110
  ecx = edx = 0;  // @362_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @363_485110
  edx = (u32)(EBP - 260);  // @364_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @365_485110
  PV[28] = (u32)(edx);  // @366_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @367_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @368_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @369_485110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[28], (u32)(0), (u32)(32), (u32)(-1), (u32)(1), (u32)(0));  // @370_485110
  ecx = edx = 0;  // @371_485110
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @372_485110
  if (FL[2] == 0) goto L48559a;  // @373_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @374_485110
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @375_485110
  X0[2] = 0;  // @376_485110
  X0[3] = 0;  // @377_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @378_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @379_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @380_485110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @381_485110
  L48559a:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 296) + 0), 4); v; });  // @383_485110
  X0[1] = 0;  // @384_485110
  X0[2] = 0;  // @385_485110
  X0[3] = 0;  // @386_485110
  edx = (u32)(EBP - 260);  // @387_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @388_485110
  __builtin_memcpy((void *)((u32)(EBP - 260) + 0), &X0[0], 4);  // @389_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 292) + 0), 4); v; });  // @390_485110
  X0[1] = 0;  // @391_485110
  X0[2] = 0;  // @392_485110
  X0[3] = 0;  // @393_485110
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X0[0], 4);  // @394_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 288) + 0), 4); v; });  // @395_485110
  X0[1] = 0;  // @396_485110
  X0[2] = 0;  // @397_485110
  X0[3] = 0;  // @398_485110
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @399_485110
  __builtin_memcpy((void *)((u32)(EBP - 252) + 0), &X0[0], 4);  // @400_485110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 248), &v, sizeof v); }  // @401_485110
  { u32 v = (u32)((u32)(3221225472)); __builtin_memcpy((void *)(u32)(EBP - 244), &v, sizeof v); }  // @402_485110
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @403_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @404_485110
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @405_485110
  PV[29] = (u32)(edx);  // @406_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @407_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 736), sizeof v); (u32)v; });  // @408_485110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[29], (u32)(0), (u32)(32), (u32)(-1), (u32)(1), (u32)(0));  // @409_485110
  ecx = edx = 0;  // @410_485110
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @411_485110
  if (FL[2] != 0) goto L485632;  // @412_485110
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @413_485110
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @414_485110
  X0[2] = 0;  // @415_485110
  X0[3] = 0;  // @416_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @417_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @418_485110
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @419_485110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @420_485110
  L485632:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @422_485110
  ecx = (u32)(esi + 77);  // @423_485110
  eax = (eax + (u32)(64));  // @424_485110
  FL[3] = eax;  // @425_485110
  FL[0] = ecx; FL[1] = eax;  // @426_485110
  if (FL[0] == FL[1]) goto L485645;  // @427_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @428_485110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @429_485110
  L485645:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @431_485110
  eax = (u32)(EBP - 16);  // @432_485110
  PV[30] = (u32)(eax);  // @433_485110
  L48564b:;
  eax = (u32)(esi + 20);  // @435_485110
  ecx = edi;  // @436_485110
  PV[31] = (u32)(eax);  // @437_485110
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[31], PV[30]);  // @438_485110
  ecx = edx = 0;  // @439_485110
  L485654:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @441_485110
  L48565a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @443_485110
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @444_485110
  edx = (edx + (u32)(4));  // @445_485110
  FL[3] = edx;  // @446_485110
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @447_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1200), sizeof v); (u32)v; });  // @448_485110
  eax = (eax + (u32)(301));  // @449_485110
  FL[3] = eax;  // @450_485110
  eax = (u32)(ecx + eax*4);  // @451_485110
  FL[0] = edx; FL[1] = eax;  // @452_485110
  if (FL[0] != FL[1]) goto L4851e3;  // @453_485110
  L485687:;
  ext_633654(G(u32, 0x6f5630));  // @455_485110
  return eax;  // @456_485110
  L485696:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @458_485110
  edx = (u32)(esi + 77);  // @459_485110
  ecx = (ecx + (u32)(64));  // @460_485110
  FL[3] = ecx;  // @461_485110
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @462_485110
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @463_485110
  if ((s32)FL[0] <= (s32)FL[1]) goto L485654;  // @464_485110
  FL[0] = edx; FL[1] = ecx;  // @465_485110
  if (FL[0] == FL[1]) goto L4856ae;  // @466_485110
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @467_485110
  L4856ae:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @469_485110
  PV[32] = (u32)(ebx);  // @470_485110
  goto L48564b;  // @471_485110
  L4856b3:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @473_485110
  eax = (u32)(esi + 8);  // @474_485110
  PV[33] = (u32)(eax);  // @475_485110
  eax = (u32)(esi + 20);  // @476_485110
  ecx = edi;  // @477_485110
  PV[34] = (u32)(eax);  // @478_485110
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 124)))(ecx, PV[34], PV[33], PV[32]);  // @479_485110
  ecx = edx = 0;  // @480_485110
  goto L48565a;  // @481_485110
}
PCREG(485110, lifted_485110);

