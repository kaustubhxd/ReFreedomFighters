// batch230013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_4e0030_fastcall2(u32, u32) __asm__("ext_4e0030");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_4e09b0_thiscall1(u32) __asm__("ext_4e09b0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e0d80_thiscall2(u32, u32) __asm__("ext_4e0d80");
extern "C" u32 THISCALL ext_515930_thiscall3(u32, u32, u32) __asm__("ext_515930");
extern "C" u32 THISCALL ext_523330_thiscall2(u32, u32) __asm__("ext_523330");
extern "C" u32 THISCALL ext_5ceed0_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5ceed0");
extern "C" u32 THISCALL ext_5cefc0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_5cefc0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5cfb10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5cfb10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5cfb10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 2636), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @2_5cfb10
  if (FL[0] != FL[1]) goto L5cfb62;  // @3_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3293) + 0), 4); v; });  // @4_5cfb10
  X0[1] = 0;  // @5_5cfb10
  X0[2] = 0;  // @6_5cfb10
  X0[3] = 0;  // @7_5cfb10
  ecx = (u32)(EBP - 16);  // @8_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @9_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3297) + 0), 4); v; });  // @10_5cfb10
  X0[1] = 0;  // @11_5cfb10
  X0[2] = 0;  // @12_5cfb10
  X0[3] = 0;  // @13_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @14_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3301) + 0), 4); v; });  // @15_5cfb10
  X0[1] = 0;  // @16_5cfb10
  X0[2] = 0;  // @17_5cfb10
  X0[3] = 0;  // @18_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @19_5cfb10
  eax = ext_4e09b0_thiscall1(ecx);  // @20_5cfb10
    // @21_5cfb10
  goto L5cfb7c;  // @22_5cfb10
  L5cfb62:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 2674) + 0), 4); v; });  // @24_5cfb10
  X0[1] = 0;  // @25_5cfb10
  X0[2] = 0;  // @26_5cfb10
  X0[3] = 0;  // @27_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @28_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 2682) + 0), 4); v; });  // @29_5cfb10
  X0[1] = 0;  // @30_5cfb10
  X0[2] = 0;  // @31_5cfb10
  X0[3] = 0;  // @32_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 8) + 0), &X0[0], 4);  // @33_5cfb10
  L5cfb7c:;
  PV[0] = (u32)(ecx);  // @35_5cfb10
  ecx = (u32)(EBP - 16);  // @36_5cfb10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @37_5cfb10
  eax = ext_4e0d80_thiscall2(ecx, (u32)(1170735104));  // @38_5cfb10
  ecx = edx = 0;  // @39_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3185) + 0), 4); v; });  // @40_5cfb10
  X0[1] = 0;  // @41_5cfb10
  X0[2] = 0;  // @42_5cfb10
  X0[3] = 0;  // @43_5cfb10
  eax = (u32)(EBP - 16);  // @44_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @45_5cfb10
  ecx = ebx;  // @46_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3189) + 0), 4); v; });  // @47_5cfb10
  X0[1] = 0;  // @48_5cfb10
  X0[2] = 0;  // @49_5cfb10
  X0[3] = 0;  // @50_5cfb10
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806060) + 0), 4); v; })));  // @51_5cfb10
  PV[1] = (u32)(eax);  // @52_5cfb10
  eax = (u32)(EBP - 52);  // @53_5cfb10
  PV[2] = (u32)(eax);  // @54_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @55_5cfb10
  eax = (u32)(EBP - 40);  // @56_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3193) + 0), 4); v; });  // @57_5cfb10
  X0[1] = 0;  // @58_5cfb10
  X0[2] = 0;  // @59_5cfb10
  X0[3] = 0;  // @60_5cfb10
  PV[3] = (u32)(eax);  // @61_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @62_5cfb10
  eax = ext_5ceed0_thiscall7(ecx, PV[3], PV[2], PV[1], (u32)(16), (u32)(1), (u32)(0));  // @63_5cfb10
  ecx = edx = 0;  // @64_5cfb10
  PV[4] = (u32)(ecx);  // @65_5cfb10
  eax = (u32)(EBP - 16);  // @66_5cfb10
  PV[5] = (u32)(eax);  // @67_5cfb10
  eax = (u32)(EBP - 40);  // @68_5cfb10
  ecx = ebx;  // @69_5cfb10
  PV[6] = (u32)(eax);  // @70_5cfb10
  eax = ext_5cefc0_thiscall5(ecx, PV[6], PV[5], (u32)(1132068864), (u32)(2));  // @71_5cfb10
  ecx = edx = 0;  // @72_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 3189) + 0), 4); v; });  // @73_5cfb10
  X0[1] = 0;  // @74_5cfb10
  X0[2] = 0;  // @75_5cfb10
  X0[3] = 0;  // @76_5cfb10
  eax = (u32)(EBP - 16);  // @77_5cfb10
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806052) + 0), 4); v; })));  // @78_5cfb10
  PV[7] = (u32)(eax);  // @79_5cfb10
  eax = (u32)(EBP - 52);  // @80_5cfb10
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @81_5cfb10
  PV[8] = (u32)(eax);  // @82_5cfb10
  eax = (u32)(EBP - 28);  // @83_5cfb10
  ecx = ebx;  // @84_5cfb10
  PV[9] = (u32)(eax);  // @85_5cfb10
  eax = ext_5ceed0_thiscall7(ecx, PV[9], PV[8], PV[7], (u32)(16), (u32)(1), (u32)(0));  // @86_5cfb10
  ecx = edx = 0;  // @87_5cfb10
  PV[10] = (u32)(ecx);  // @88_5cfb10
  eax = (u32)(EBP - 16);  // @89_5cfb10
  PV[11] = (u32)(eax);  // @90_5cfb10
  eax = (u32)(EBP - 28);  // @91_5cfb10
  ecx = ebx;  // @92_5cfb10
  PV[12] = (u32)(eax);  // @93_5cfb10
  eax = ext_5cefc0_thiscall5(ecx, PV[12], PV[11], (u32)(1132068864), (u32)(2));  // @94_5cfb10
  ecx = edx = 0;  // @95_5cfb10
  edx = (u32)(EBP - 28);  // @96_5cfb10
  ecx = (u32)(ebx + 3185);  // @97_5cfb10
  eax = ext_4e0870_fastcall2(ecx, edx);  // @98_5cfb10
  ecx = edx = 0;  // @99_5cfb10
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 60)) :: "st");  // @100_5cfb10
  edx = (u32)(EBP - 40);  // @101_5cfb10
  ecx = (u32)(ebx + 3185);  // @102_5cfb10
  eax = ext_4e0870_fastcall2(ecx, edx);  // @103_5cfb10
  ecx = edx = 0;  // @104_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @105_5cfb10
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 56)) :: "st");  // @106_5cfb10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 3787), sizeof v); (u32)v; });  // @107_5cfb10
  FL[2] = (esi & esi);  // @108_5cfb10
  if (FL[2] == 0) goto L5cfc9d;  // @109_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @110_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @111_5cfb10
  X0[1] = 0;  // @112_5cfb10
  X0[2] = 0;  // @113_5cfb10
  X0[3] = 0;  // @114_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 544), sizeof v); (u32)v; });  // @115_5cfb10
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; }))))))) goto L5cfccd;  // @116_5cfb10
  ecx = (u32)(EBP - 40);  // @117_5cfb10
  PV[13] = (u32)(ecx);  // @118_5cfb10
  ecx = esi;  // @119_5cfb10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[13]);  // @120_5cfb10
  ecx = edx = 0;  // @121_5cfb10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @122_5cfb10
  if (FL[2] != 0) goto L5cfced;  // @123_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_5cfb10
  ecx = (u32)(EBP - 28);  // @125_5cfb10
  PV[14] = (u32)(ecx);  // @126_5cfb10
  ecx = esi;  // @127_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 544), sizeof v); (u32)v; });  // @128_5cfb10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[14]);  // @129_5cfb10
  ecx = edx = 0;  // @130_5cfb10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @131_5cfb10
  if (FL[2] == 0) goto L5cfd07;  // @132_5cfb10
  L5cfc9d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @134_5cfb10
  X0[1] = 0;  // @135_5cfb10
  X0[2] = 0;  // @136_5cfb10
  X0[3] = 0;  // @137_5cfb10
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @138_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @139_5cfb10
  X0[1] = 0;  // @140_5cfb10
  X0[2] = 0;  // @141_5cfb10
  X0[3] = 0;  // @142_5cfb10
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @143_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @144_5cfb10
  X0[1] = 0;  // @145_5cfb10
  X0[2] = 0;  // @146_5cfb10
  X0[3] = 0;  // @147_5cfb10
  L5cfcb5:;
  __builtin_memcpy((void *)((u32)(edi + 8) + 0), &X0[0], 4);  // @149_5cfb10
  ext_633654(G(u32, 0x6f5630));  // @150_5cfb10
  return eax;  // @151_5cfb10
  L5cfccd:;
  ecx = (u32)(EBP - 28);  // @153_5cfb10
  PV[15] = (u32)(ecx);  // @154_5cfb10
  ecx = esi;  // @155_5cfb10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[15]);  // @156_5cfb10
  ecx = edx = 0;  // @157_5cfb10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @158_5cfb10
  if (FL[2] != 0) goto L5cfc9d;  // @159_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_5cfb10
  ecx = (u32)(EBP - 40);  // @161_5cfb10
  PV[16] = (u32)(ecx);  // @162_5cfb10
  ecx = esi;  // @163_5cfb10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 544), sizeof v); (u32)v; });  // @164_5cfb10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[16]);  // @165_5cfb10
  ecx = edx = 0;  // @166_5cfb10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @167_5cfb10
  if (FL[2] == 0) goto L5cfd07;  // @168_5cfb10
  L5cfced:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @170_5cfb10
  X0[1] = 0;  // @171_5cfb10
  X0[2] = 0;  // @172_5cfb10
  X0[3] = 0;  // @173_5cfb10
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @174_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @175_5cfb10
  X0[1] = 0;  // @176_5cfb10
  X0[2] = 0;  // @177_5cfb10
  X0[3] = 0;  // @178_5cfb10
  __builtin_memcpy((void *)((u32)(edi + 4) + 0), &X0[0], 4);  // @179_5cfb10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @180_5cfb10
  X0[1] = 0;  // @181_5cfb10
  X0[2] = 0;  // @182_5cfb10
  X0[3] = 0;  // @183_5cfb10
  goto L5cfcb5;  // @184_5cfb10
  L5cfd07:;
  ecx = (u32)(EBP - 16);  // @186_5cfb10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @187_5cfb10
  eax = ext_44c840_thiscall1(ecx);  // @188_5cfb10
  ecx = 0;  // @189_5cfb10
  edx = (u32)(EBP - 72);  // @190_5cfb10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 72), &v, sizeof v); }  // @191_5cfb10
  ecx = (u32)(EBP - 16);  // @192_5cfb10
  { u32 v = (u32)((u32)(3175926989)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @193_5cfb10
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @194_5cfb10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @195_5cfb10
  eax = ext_441940_fastcall2(ecx, edx);  // @196_5cfb10
  ecx = edx = 0;  // @197_5cfb10
  PV[17] = (u32)(ecx);  // @198_5cfb10
  ecx = (u32)(EBP - 16);  // @199_5cfb10
  eax = ext_4e0d80_thiscall2(ecx, (u32)(1169915904));  // @200_5cfb10
  ecx = edx = 0;  // @201_5cfb10
  eax = (u32)(EBP - 16);  // @202_5cfb10
  ecx = ebx;  // @203_5cfb10
  PV[18] = (u32)(eax);  // @204_5cfb10
  eax = (u32)(EBP - 52);  // @205_5cfb10
  PV[19] = (u32)(eax);  // @206_5cfb10
  PV[20] = (u32)(edi);  // @207_5cfb10
  eax = ext_5ceed0_thiscall7(ecx, PV[20], PV[19], PV[18], (u32)(16), (u32)(1), (u32)(0));  // @208_5cfb10
  ecx = edx = 0;  // @209_5cfb10
  PV[21] = (u32)(ecx);  // @210_5cfb10
  eax = (u32)(EBP - 16);  // @211_5cfb10
  PV[22] = (u32)(eax);  // @212_5cfb10
  PV[23] = (u32)(edi);  // @213_5cfb10
  ecx = ebx;  // @214_5cfb10
  eax = ext_5cefc0_thiscall5(ecx, PV[23], PV[22], (u32)(1112014848), (u32)(2));  // @215_5cfb10
  ecx = edx = 0;  // @216_5cfb10
  ext_633654(G(u32, 0x6f5630));  // @217_5cfb10
  return eax;  // @218_5cfb10
}
PCREG(5cfb10, lifted_5cfb10);


