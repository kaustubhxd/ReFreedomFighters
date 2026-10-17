// batch242016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 THISCALL ext_4db500_thiscall2(u32, u32) __asm__("ext_4db500");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e0d80_thiscall2(u32, u32) __asm__("ext_4e0d80");
extern "C" u32 THISCALL ext_4e8c00_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4e8c00");
extern "C" u32 THISCALL ext_4ea300_thiscall2(u32, u32) __asm__("ext_4ea300");
extern "C" u32 THISCALL ext_4eb020_thiscall4(u32, u32, u32, u32) __asm__("ext_4eb020");
extern "C" u32 THISCALL ext_53eaa0_thiscall2(u32, u32) __asm__("ext_53eaa0");
extern "C" u32 THISCALL ext_53f630_thiscall1(u32) __asm__("ext_53f630");
extern "C" u32 THISCALL ext_53f770_thiscall1(u32) __asm__("ext_53f770");
extern "C" u32 THISCALL ext_53f980_thiscall1(u32) __asm__("ext_53f980");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 STDCALL lifted_4ff4a0(u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0xca50] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0xc950);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0xc950 + 8, &a0, 4);
  __builtin_memcpy(F + 0xc950 + 12, &a1, 4);
  __builtin_memcpy(F + 0xc950 + 16, &a2, 4);
  __builtin_memcpy(F + 0xc950 + 20, &a3, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_4ff4a0
  ecx = (u32)((EBP - 51404) + 100);  // @1_4ff4a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ff4a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4ff4a0
  PV[0] = (u32)(edi);  // @4_4ff4a0
  eax = ext_43e920_fastcall3(ecx, edx, PV[0]);  // @5_4ff4a0
  ecx = edx = 0;  // @6_4ff4a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 112) + 0), 4); v; });  // @7_4ff4a0
  X1[1] = 0;  // @8_4ff4a0
  X1[2] = 0;  // @9_4ff4a0
  X1[3] = 0;  // @10_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 116) + 0), 4); v; });  // @11_4ff4a0
  X0[1] = 0;  // @12_4ff4a0
  X0[2] = 0;  // @13_4ff4a0
  X0[3] = 0;  // @14_4ff4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @15_4ff4a0
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @16_4ff4a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @17_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 120) + 0), 4); v; });  // @18_4ff4a0
  X0[1] = 0;  // @19_4ff4a0
  X0[2] = 0;  // @20_4ff4a0
  X0[3] = 0;  // @21_4ff4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @22_4ff4a0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @23_4ff4a0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @24_4ff4a0
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @25_4ff4a0
  ecx = edx = 0;  // @26_4ff4a0
  X1[0] = 0;  // @27_4ff4a0
  X1[1] = 0;  // @28_4ff4a0
  X1[2] = 0;  // @29_4ff4a0
  X1[3] = 0;  // @30_4ff4a0
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @31_4ff4a0
  PV[1] = (u32)(ecx);  // @32_4ff4a0
  ecx = (u32)((EBP - 51420) + 116);  // @33_4ff4a0
  X1[0] = F2U(U2F(X1[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; })));  // @34_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51420) + 16) + 0), &X1[0], 4);  // @35_4ff4a0
  PV[2] = X1[0];  // @36_4ff4a0
  eax = ext_4e0d80_thiscall2(ecx, PV[2]);  // @37_4ff4a0
  ecx = edx = 0;  // @38_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @39_4ff4a0
  X0[1] = 0;  // @40_4ff4a0
  X0[2] = 0;  // @41_4ff4a0
  X0[3] = 0;  // @42_4ff4a0
  edx = (u32)((EBP - 51416) + 112);  // @43_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 148) + 0), &X0[0], 4);  // @44_4ff4a0
  ecx = (u32)((EBP - 51416) + 172);  // @45_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 152) + 0), &X0[0], 4);  // @46_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 12) + 0), 4); v; });  // @47_4ff4a0
  X0[1] = 0;  // @48_4ff4a0
  X0[2] = 0;  // @49_4ff4a0
  X0[3] = 0;  // @50_4ff4a0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @51_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51420) + 160) + 0), &X0[0], 4);  // @52_4ff4a0
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @53_4ff4a0
  ecx = edx = 0;  // @54_4ff4a0
  PV[3] = (u32)(ecx);  // @55_4ff4a0
  edx = (u32)((EBP - 51420) + 116);  // @56_4ff4a0
  ecx = (u32)((EBP - 51420) + 164);  // @57_4ff4a0
  eax = ext_4e0d40_fastcall3(ecx, edx, (u32)(1056964608));  // @58_4ff4a0
    // @59_4ff4a0
  edx = edi;  // @60_4ff4a0
  ecx = (u32)((EBP - 51416) + 160);  // @61_4ff4a0
  eax = ext_441940_fastcall2(ecx, edx);  // @62_4ff4a0
  ecx = edx = 0;  // @63_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @64_4ff4a0
  X0[1] = 0;  // @65_4ff4a0
  X0[2] = 0;  // @66_4ff4a0
  X0[3] = 0;  // @67_4ff4a0
  edx = (u32)((EBP - 51416) + 196);  // @68_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 100) + 0), &X0[0], 4);  // @69_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @70_4ff4a0
  X0[1] = 0;  // @71_4ff4a0
  X0[2] = 0;  // @72_4ff4a0
  X0[3] = 0;  // @73_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 104) + 0), &X0[0], 4);  // @74_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @75_4ff4a0
  X0[1] = 0;  // @76_4ff4a0
  X0[2] = 0;  // @77_4ff4a0
  X0[3] = 0;  // @78_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 108) + 0), &X0[0], 4);  // @79_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @80_4ff4a0
  X0[1] = 0;  // @81_4ff4a0
  X0[2] = 0;  // @82_4ff4a0
  X0[3] = 0;  // @83_4ff4a0
  PV[4] = (u32)(ecx);  // @84_4ff4a0
  ecx = (u32)((EBP - 51420) + 128);  // @85_4ff4a0
  PV[5] = X0[0];  // @86_4ff4a0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[5]);  // @87_4ff4a0
    // @88_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @89_4ff4a0
  X0[1] = 0;  // @90_4ff4a0
  X0[2] = 0;  // @91_4ff4a0
  X0[3] = 0;  // @92_4ff4a0
  edx = (u32)((EBP - 51416) + 184);  // @93_4ff4a0
  PV[6] = (u32)(ecx);  // @94_4ff4a0
  ecx = (u32)((EBP - 51420) + 140);  // @95_4ff4a0
  PV[7] = X0[0];  // @96_4ff4a0
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[7]);  // @97_4ff4a0
    // @98_4ff4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_4ff4a0
  edx = (u32)((EBP - 51416) + 208);  // @100_4ff4a0
  PV[8] = (u32)(edx);  // @101_4ff4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @102_4ff4a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @103_4ff4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_4ff4a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[8], (u32)(51200));  // @105_4ff4a0
  ecx = edx = 0;  // @106_4ff4a0
  esi = eax;  // @107_4ff4a0
  eax = (u32)((EBP - 51416) + 148);  // @108_4ff4a0
  PV[9] = (u32)(eax);  // @109_4ff4a0
  eax = (u32)((EBP - 51420) + 164);  // @110_4ff4a0
  ecx = esi;  // @111_4ff4a0
  PV[10] = (u32)(eax);  // @112_4ff4a0
  eax = (u32)((EBP - 51424) + 180);  // @113_4ff4a0
  PV[11] = (u32)(eax);  // @114_4ff4a0
  eax = ext_4eb020_thiscall4(ecx, PV[11], PV[10], PV[9]);  // @115_4ff4a0
  ecx = edx = 0;  // @116_4ff4a0
  ecx = esi;  // @117_4ff4a0
  eax = ext_4ea300_thiscall2(ecx, (u32)(1));  // @118_4ff4a0
  ecx = edx = 0;  // @119_4ff4a0
  eax = (u32)((EBP - 51420) + 116);  // @120_4ff4a0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)((EBP - 51420) + 28), &v, sizeof v); }  // @121_4ff4a0
  PV[12] = (u32)(eax);  // @122_4ff4a0
  eax = (u32)((EBP - 51424) + 108);  // @123_4ff4a0
  ecx = esi;  // @124_4ff4a0
  PV[13] = (u32)(eax);  // @125_4ff4a0
  eax = (u32)((EBP - 51428) + 36);  // @126_4ff4a0
  PV[14] = (u32)(eax);  // @127_4ff4a0
  eax = ext_4e8c00_thiscall5(ecx, PV[14], PV[13], PV[12], (u32)(1));  // @128_4ff4a0
  ecx = edx = 0;  // @129_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 24) + 0), 4); v; });  // @130_4ff4a0
  X0[1] = 0;  // @131_4ff4a0
  X0[2] = 0;  // @132_4ff4a0
  X0[3] = 0;  // @133_4ff4a0
  edx = (u32)((EBP - 51416) + 124);  // @134_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @135_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 16) + 0), &X0[0], 4);  // @136_4ff4a0
  eax = ext_441940_fastcall2(ecx, edx);  // @137_4ff4a0
  ecx = edx = 0;  // @138_4ff4a0
  eax = (u32)((EBP - 51420) + 116);  // @139_4ff4a0
  ecx = esi;  // @140_4ff4a0
  PV[15] = (u32)(eax);  // @141_4ff4a0
  eax = (u32)((EBP - 51424) + 108);  // @142_4ff4a0
  PV[16] = (u32)(eax);  // @143_4ff4a0
  eax = (u32)((EBP - 51428) + 36);  // @144_4ff4a0
  PV[17] = (u32)(eax);  // @145_4ff4a0
  eax = ext_4e8c00_thiscall5(ecx, PV[17], PV[16], PV[15], (u32)(1));  // @146_4ff4a0
  ecx = edx = 0;  // @147_4ff4a0
  edx = (u32)((EBP - 51416) + 124);  // @148_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @149_4ff4a0
  eax = ext_43e960_fastcall2(ecx, edx);  // @150_4ff4a0
  ecx = edx = 0;  // @151_4ff4a0
  edx = (u32)((EBP - 51416) + 124);  // @152_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @153_4ff4a0
  eax = ext_43e960_fastcall2(ecx, edx);  // @154_4ff4a0
  ecx = edx = 0;  // @155_4ff4a0
  eax = (u32)((EBP - 51420) + 116);  // @156_4ff4a0
  ecx = esi;  // @157_4ff4a0
  PV[18] = (u32)(eax);  // @158_4ff4a0
  eax = (u32)((EBP - 51424) + 108);  // @159_4ff4a0
  PV[19] = (u32)(eax);  // @160_4ff4a0
  eax = (u32)((EBP - 51428) + 36);  // @161_4ff4a0
  PV[20] = (u32)(eax);  // @162_4ff4a0
  eax = ext_4e8c00_thiscall5(ecx, PV[20], PV[19], PV[18], (u32)(1));  // @163_4ff4a0
  ecx = edx = 0;  // @164_4ff4a0
  edx = (u32)((EBP - 51416) + 124);  // @165_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @166_4ff4a0
  eax = ext_441940_fastcall2(ecx, edx);  // @167_4ff4a0
  ecx = edx = 0;  // @168_4ff4a0
  edx = (u32)((EBP - 51416) + 136);  // @169_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @170_4ff4a0
  eax = ext_441940_fastcall2(ecx, edx);  // @171_4ff4a0
  ecx = edx = 0;  // @172_4ff4a0
  eax = (u32)((EBP - 51420) + 116);  // @173_4ff4a0
  ecx = esi;  // @174_4ff4a0
  PV[21] = (u32)(eax);  // @175_4ff4a0
  eax = (u32)((EBP - 51424) + 108);  // @176_4ff4a0
  PV[22] = (u32)(eax);  // @177_4ff4a0
  eax = (u32)((EBP - 51428) + 36);  // @178_4ff4a0
  PV[23] = (u32)(eax);  // @179_4ff4a0
  eax = ext_4e8c00_thiscall5(ecx, PV[23], PV[22], PV[21], (u32)(1));  // @180_4ff4a0
  ecx = edx = 0;  // @181_4ff4a0
  edx = (u32)((EBP - 51416) + 136);  // @182_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @183_4ff4a0
  eax = ext_43e960_fastcall2(ecx, edx);  // @184_4ff4a0
  ecx = edx = 0;  // @185_4ff4a0
  edx = (u32)((EBP - 51416) + 136);  // @186_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @187_4ff4a0
  eax = ext_43e960_fastcall2(ecx, edx);  // @188_4ff4a0
  ecx = edx = 0;  // @189_4ff4a0
  eax = (u32)((EBP - 51420) + 116);  // @190_4ff4a0
  ecx = esi;  // @191_4ff4a0
  PV[24] = (u32)(eax);  // @192_4ff4a0
  eax = (u32)((EBP - 51424) + 108);  // @193_4ff4a0
  PV[25] = (u32)(eax);  // @194_4ff4a0
  eax = (u32)((EBP - 51428) + 36);  // @195_4ff4a0
  PV[26] = (u32)(eax);  // @196_4ff4a0
  eax = ext_4e8c00_thiscall5(ecx, PV[26], PV[25], PV[24], (u32)(1));  // @197_4ff4a0
  ecx = edx = 0;  // @198_4ff4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @199_4ff4a0
  PV[27] = (u32)(esi);  // @200_4ff4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @201_4ff4a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @202_4ff4a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @203_4ff4a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[27]);  // @204_4ff4a0
  ecx = edx = 0;  // @205_4ff4a0
  edx = (u32)((EBP - 51416) + 136);  // @206_4ff4a0
  ecx = (u32)((EBP - 51416) + 100);  // @207_4ff4a0
  eax = ext_441940_fastcall2(ecx, edx);  // @208_4ff4a0
  ecx = edx = 0;  // @209_4ff4a0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 24) + 0), 4); v; });  // @210_4ff4a0
  X1[1] = 0;  // @211_4ff4a0
  X1[2] = 0;  // @212_4ff4a0
  X1[3] = 0;  // @213_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 16) + 0), 4); v; });  // @214_4ff4a0
  X0[1] = 0;  // @215_4ff4a0
  X0[2] = 0;  // @216_4ff4a0
  X0[3] = 0;  // @217_4ff4a0
  __builtin_memcpy((void *)((u32)((EBP - 51416) + 20) + 0), &X1[0], 4);  // @218_4ff4a0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @219_4ff4a0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @220_4ff4a0
  if (!__builtin_parity(FL[2] & 0xff)) goto L4ff76d;  // @221_4ff4a0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 20) + 0), 4); v; });  // @222_4ff4a0
  X0[1] = 0;  // @223_4ff4a0
  X0[2] = 0;  // @224_4ff4a0
  X0[3] = 0;  // @225_4ff4a0
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 51416) + 12) + 0), 4); v; })));  // @226_4ff4a0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @227_4ff4a0
  L4ff76d:;
  PV[28] = (u32)(ecx);  // @229_4ff4a0
  ecx = (u32)((EBP - 51420) + 116);  // @230_4ff4a0
  PV[29] = X1[0];  // @231_4ff4a0
  eax = ext_4e0d00_thiscall2(ecx, PV[29]);  // @232_4ff4a0
    // @233_4ff4a0
  eax = (u32)((EBP - 51416) + 112);  // @234_4ff4a0
  edx = edi;  // @235_4ff4a0
  PV[30] = (u32)(eax);  // @236_4ff4a0
  ecx = ebx;  // @237_4ff4a0
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[30]);  // @238_4ff4a0
  ecx = edx = 0;  // @239_4ff4a0
  ext_633654(G(u32, 0x6f5630));  // @240_4ff4a0
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)((EBP - 51416) + 20)) : "st");  // @241_4ff4a0
  return eax;  // @242_4ff4a0
}
PCREG(4ff4a0, lifted_4ff4a0);

extern "C" u32 THISCALL lifted_540bc0(u32 ecx_in) {
  u8 F[0x3080] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x2f80);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(EBP - 12016);  // @0_540bc0
  esi = ecx;  // @1_540bc0
  PV[0] = (u32)(eax);  // @2_540bc0
  eax = ext_53eaa0_thiscall2(ecx, PV[0]);  // @3_540bc0
  ecx = edx = 0;  // @4_540bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 338), &v, sizeof v); }  // @5_540bc0
  ecx = esi;  // @6_540bc0
  eax = (u32)(EBP - 12016);  // @7_540bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 334), &v, sizeof v); }  // @8_540bc0
  eax = ext_53f630_thiscall1(ecx);  // @9_540bc0
  ecx = edx = 0;  // @10_540bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @11_540bc0
  eax = (u32)(EBP - 16);  // @12_540bc0
  PV[1] = (u32)(eax);  // @13_540bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @14_540bc0
  eax = ext_4db500_thiscall2(ecx, PV[1]);  // @15_540bc0
  edx = 0;  // @16_540bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 273), sizeof v); (u32)v; });  // @17_540bc0
  ecx = (u32)(esi + 297);  // @18_540bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @19_540bc0
  edx = (u32)(EBP - 16);  // @20_540bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 277), sizeof v); (u32)v; });  // @21_540bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @22_540bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 281), sizeof v); (u32)v; });  // @23_540bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @24_540bc0
  eax = ext_43e960_fastcall2(ecx, edx);  // @25_540bc0
  ecx = edx = 0;  // @26_540bc0
  ecx = esi;  // @27_540bc0
  eax = ext_53f770_thiscall1(ecx);  // @28_540bc0
  ecx = edx = 0;  // @29_540bc0
  ecx = esi;  // @30_540bc0
  eax = ext_53f980_thiscall1(ecx);  // @31_540bc0
  ecx = edx = 0;  // @32_540bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @33_540bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @34_540bc0
  eax = ext_4dc630_thiscall3(ecx, (u32)(0), (u32)(32));  // @35_540bc0
  ecx = edx = 0;  // @36_540bc0
  ext_633654(G(u32, 0x6f5630));  // @37_540bc0
  return eax;  // @38_540bc0
}
PCREG(540bc0, lifted_540bc0);

