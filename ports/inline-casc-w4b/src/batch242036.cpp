// batch242036.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_451890_fastcall3(u32, u32, u32) __asm__("ext_451890");
extern "C" u32 FASTCALL ext_4de040_fastcall3(u32, u32, u32) __asm__("ext_4de040");
extern "C" u32 FASTCALL ext_4e0d40_fastcall3(u32, u32, u32) __asm__("ext_4e0d40");
extern "C" u32 FASTCALL ext_53d160_fastcall4(u32, u32, u32, u32) __asm__("ext_53d160");
extern "C" u32 STDCALL ext_5403f0_stdcall10(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5403f0");
extern "C" u32 THISCALL ext_43ec00_thiscall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_43ec00");
extern "C" u32 THISCALL ext_4db3b0_thiscall1(u32) __asm__("ext_4db3b0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 THISCALL ext_4e8c80_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4e8c80");
extern "C" u32 THISCALL ext_4ea280_thiscall3(u32, u32, u32) __asm__("ext_4ea280");
extern "C" u32 THISCALL ext_4ea2b0_thiscall3(u32, u32, u32) __asm__("ext_4ea2b0");
extern "C" u32 THISCALL ext_4ea2e0_thiscall2(u32, u32) __asm__("ext_4ea2e0");
extern "C" u32 THISCALL ext_545cb0_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_545cb0");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_53d230(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x4c0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x3c0);
  u32 PV[162], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 ALLOC_PTR = 0; u32 X87SW = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, ebq = 0;
  __builtin_memcpy(F + 0x3c0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x3c0 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_53d230
  eax = (u32)(EBP - 256);  // @1_53d230
  PV[0] = (u32)(eax);  // @2_53d230
  eax = (u32)(EBP - 768);  // @3_53d230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 572), &v, sizeof v); }  // @4_53d230
  PV[1] = (u32)(eax);  // @5_53d230
  eax = (u32)(EBP - 100);  // @6_53d230
  edi = ecx;  // @7_53d230
  PV[2] = (u32)(eax);  // @8_53d230
  eax = (u32)(EBP - 124);  // @9_53d230
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 568), &v, sizeof v); }  // @10_53d230
  PV[3] = (u32)(eax);  // @11_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @12_53d230
  eax = ext_545cb0_thiscall6(ecx, (u32)(1), PV[3], PV[2], PV[1], PV[0]);  // @13_53d230
  ecx = edx = 0;  // @14_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @15_53d230
  eax = (u32)(EBP - 244);  // @16_53d230
  PV[4] = (u32)(eax);  // @17_53d230
  eax = (u32)(EBP - 740);  // @18_53d230
  PV[5] = (u32)(eax);  // @19_53d230
  eax = (u32)(EBP - 88);  // @20_53d230
  PV[6] = (u32)(eax);  // @21_53d230
  eax = (u32)(EBP - 112);  // @22_53d230
  PV[7] = (u32)(eax);  // @23_53d230
  eax = ext_545cb0_thiscall6(ecx, (u32)(2), PV[7], PV[6], PV[5], PV[4]);  // @24_53d230
  ecx = edx = 0;  // @25_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @26_53d230
  eax = (u32)(EBP - 232);  // @27_53d230
  PV[8] = (u32)(eax);  // @28_53d230
  eax = (u32)(EBP - 712);  // @29_53d230
  PV[9] = (u32)(eax);  // @30_53d230
  eax = (u32)(EBP - 64);  // @31_53d230
  PV[10] = (u32)(eax);  // @32_53d230
  eax = (u32)(EBP - 76);  // @33_53d230
  PV[11] = (u32)(eax);  // @34_53d230
  eax = ext_545cb0_thiscall6(ecx, (u32)(3), PV[11], PV[10], PV[9], PV[8]);  // @35_53d230
  ecx = edx = 0;  // @36_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @37_53d230
  eax = (u32)(EBP - 280);  // @38_53d230
  PV[12] = (u32)(eax);  // @39_53d230
  eax = (u32)(EBP - 696);  // @40_53d230
  PV[13] = (u32)(eax);  // @41_53d230
  eax = (u32)(EBP - 52);  // @42_53d230
  PV[14] = (u32)(eax);  // @43_53d230
  eax = (u32)(EBP - 40);  // @44_53d230
  PV[15] = (u32)(eax);  // @45_53d230
  eax = ext_545cb0_thiscall6(ecx, (u32)(4), PV[15], PV[14], PV[13], PV[12]);  // @46_53d230
  ecx = edx = 0;  // @47_53d230
  eax = (u32)(EBP - 112);  // @48_53d230
  PV[16] = (u32)(eax);  // @49_53d230
  edx = (u32)(EBP - 124);  // @50_53d230
  ecx = (u32)(EBP - 16);  // @51_53d230
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[16]);  // @52_53d230
  ecx = edx = 0;  // @53_53d230
  edx = (u32)(EBP - 76);  // @54_53d230
  ecx = (u32)(EBP - 16);  // @55_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @56_53d230
  ecx = edx = 0;  // @57_53d230
  edx = (u32)(EBP - 40);  // @58_53d230
  ecx = (u32)(EBP - 16);  // @59_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @60_53d230
  ecx = edx = 0;  // @61_53d230
  PV[17] = (u32)(ecx);  // @62_53d230
  ecx = (u32)(EBP - 16);  // @63_53d230
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1048576000));  // @64_53d230
    // @65_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @66_53d230
  edx = (u32)(EBP - 100);  // @67_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @68_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @69_53d230
  X0[2] = 0;  // @70_53d230
  X0[3] = 0;  // @71_53d230
  ecx = (u32)(EBP - 136);  // @72_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 756), &v, sizeof v); }  // @73_53d230
  eax = (u32)(EBP - 88);  // @74_53d230
  PV[18] = (u32)(eax);  // @75_53d230
  __builtin_memcpy((void *)((u32)(EBP - 764) + 0), &X0[0], 4);  // @76_53d230
  __builtin_memcpy((void *)((u32)(EBP - 764) + 4), &X0[1], 4);  // @77_53d230
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[18]);  // @78_53d230
  ecx = edx = 0;  // @79_53d230
  edx = (u32)(EBP - 64);  // @80_53d230
  ecx = (u32)(EBP - 136);  // @81_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @82_53d230
  ecx = edx = 0;  // @83_53d230
  edx = (u32)(EBP - 52);  // @84_53d230
  ecx = (u32)(EBP - 136);  // @85_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @86_53d230
  ecx = edx = 0;  // @87_53d230
  PV[19] = (u32)(ecx);  // @88_53d230
  ecx = (u32)(EBP - 136);  // @89_53d230
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1048576000));  // @90_53d230
    // @91_53d230
  eax = (u32)(EBP - 244);  // @92_53d230
  PV[20] = (u32)(eax);  // @93_53d230
  edx = (u32)(EBP - 256);  // @94_53d230
  ecx = (u32)(EBP - 148);  // @95_53d230
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[20]);  // @96_53d230
  ecx = edx = 0;  // @97_53d230
  edx = (u32)(EBP - 232);  // @98_53d230
  ecx = (u32)(EBP - 148);  // @99_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @100_53d230
  ecx = edx = 0;  // @101_53d230
  edx = (u32)(EBP - 280);  // @102_53d230
  ecx = (u32)(EBP - 148);  // @103_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @104_53d230
  ecx = edx = 0;  // @105_53d230
  PV[21] = (u32)(ecx);  // @106_53d230
  ecx = (u32)(EBP - 148);  // @107_53d230
  eax = ext_4e0d00_thiscall2(ecx, (u32)(1048576000));  // @108_53d230
    // @109_53d230
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @110_53d230
  FL[3] = (eax & 0xff);  // @111_53d230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 533), &v, sizeof v); }  // @112_53d230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 534), &v, sizeof v); }  // @113_53d230
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 342), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @114_53d230
  if (FL[0] == FL[1]) goto L53d6e7;  // @115_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @116_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @117_53d230
  FL[2] = (ecx & ecx);  // @118_53d230
  if (FL[2] == 0) goto L53da3c;  // @119_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_53d230
  edx = (u32)(EBP - 736);  // @121_53d230
  PV[22] = (u32)(edx);  // @122_53d230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[22]);  // @123_53d230
  ecx = edx = 0;  // @124_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @125_53d230
  edx = (u32)(EBP - 736);  // @126_53d230
  PV[23] = (u32)(edx);  // @127_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @128_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @129_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; });  // @130_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[23]);  // @131_53d230
  ecx = edx = 0;  // @132_53d230
  esi = eax;  // @133_53d230
  FL[2] = (esi & esi);  // @134_53d230
  if (FL[2] == 0) goto L53da3c;  // @135_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @136_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @137_53d230
  L53d420:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @139_53d230
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @141_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @142_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @143_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[24]);  // @144_53d230
  ecx = edx = 0;  // @145_53d230
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @146_53d230
  if (FL[0] == FL[1]) goto L53d6b6;  // @147_53d230
  eax = (u32)(EBP - 148);  // @148_53d230
  PV[25] = (u32)(eax);  // @149_53d230
  edx = (u32)(EBP - 16);  // @150_53d230
  ecx = (u32)(EBP - 668);  // @151_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[25]);  // @152_53d230
  ecx = edx = 0;  // @153_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 664) + 0), 4); v; });  // @154_53d230
  X0[1] = 0;  // @155_53d230
  X0[2] = 0;  // @156_53d230
  X0[3] = 0;  // @157_53d230
  eax = (u32)(esi + 52);  // @158_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 668) + 0), 4); v; });  // @159_53d230
  X1[1] = 0;  // @160_53d230
  X1[2] = 0;  // @161_53d230
  X1[3] = 0;  // @162_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; })));  // @163_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; })));  // @164_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @165_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 660) + 0), 4); v; });  // @166_53d230
  X0[1] = 0;  // @167_53d230
  X0[2] = 0;  // @168_53d230
  X0[3] = 0;  // @169_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 48) + 0), 4); v; })));  // @170_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @171_53d230
  __builtin_memcpy((void *)((u32)(EBP - 540) + 0), &X1[0], 4);  // @172_53d230
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))))) goto L53d6b6;  // @173_53d230
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @174_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6814416) + 0), 4); v; }); X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6814416) + 4), 4); v; }); X1[2] = X1[3] = 0;  // @175_53d230
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @176_53d230
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @177_53d230
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @178_53d230
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @179_53d230
  if ((!(!(U2D(X1[0], X1[1]) >= U2D(X0[0], X0[1]))) && !(!((U2D(X1[0], X1[1]) < U2D(X0[0], X0[1])) || (U2D(X1[0], X1[1]) > U2D(X0[0], X0[1])))))) goto L53d6b6;  // @180_53d230
  PV[26] = (u32)(eax);  // @181_53d230
  edx = (u32)(EBP - 148);  // @182_53d230
  ecx = (u32)(EBP - 564);  // @183_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[26]);  // @184_53d230
  ecx = edx = 0;  // @185_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 560) + 0), 4); v; });  // @186_53d230
  X0[1] = 0;  // @187_53d230
  X0[2] = 0;  // @188_53d230
  X0[3] = 0;  // @189_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 36) + 0), 4); v; })));  // @190_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 564) + 0), 4); v; });  // @191_53d230
  X1[1] = 0;  // @192_53d230
  X1[2] = 0;  // @193_53d230
  X1[3] = 0;  // @194_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 24) + 0), 4); v; })));  // @195_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @196_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 556) + 0), 4); v; });  // @197_53d230
  X0[1] = 0;  // @198_53d230
  X0[2] = 0;  // @199_53d230
  X0[3] = 0;  // @200_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 48) + 0), 4); v; })));  // @201_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @202_53d230
  X0[0] = 0;  // @203_53d230
  X0[1] = 0;  // @204_53d230
  X0[2] = 0;  // @205_53d230
  X0[3] = 0;  // @206_53d230
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 540) + 0), 4); v; })));  // @207_53d230
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @208_53d230
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @209_53d230
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @210_53d230
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @211_53d230
  __builtin_memcpy((void *)((u32)(EBP - 540) + 0), &X1[0], 4);  // @212_53d230
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))))) goto L53d6b6;  // @213_53d230
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))))) goto L53d6b6;  // @214_53d230
  PV[27] = (u32)(ecx);  // @215_53d230
  edx = (u32)(EBP - 668);  // @216_53d230
  PV[28] = X1[0];  // @217_53d230
  ecx = (u32)(EBP - 564);  // @218_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[28]);  // @219_53d230
  ecx = 0;  // @220_53d230
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 564) + 0), 4); v; });  // @221_53d230
  X6[1] = 0;  // @222_53d230
  X6[2] = 0;  // @223_53d230
  X6[3] = 0;  // @224_53d230
  X1[0] = 0;  // @225_53d230
  X1[1] = 0;  // @226_53d230
  X1[2] = 0;  // @227_53d230
  X1[3] = 0;  // @228_53d230
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 28) + 0), 4); v; });  // @229_53d230
  X4[1] = 0;  // @230_53d230
  X4[2] = 0;  // @231_53d230
  X4[3] = 0;  // @232_53d230
  X0[0] = X6[0];  // @233_53d230
  X0[1] = X6[1];  // @234_53d230
  X0[2] = X6[2];  // @235_53d230
  X0[3] = X6[3];  // @236_53d230
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 560) + 0), 4); v; });  // @237_53d230
  X5[1] = 0;  // @238_53d230
  X5[2] = 0;  // @239_53d230
  X5[3] = 0;  // @240_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; })));  // @241_53d230
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 556) + 0), 4); v; });  // @242_53d230
  X7[1] = 0;  // @243_53d230
  X7[2] = 0;  // @244_53d230
  X7[3] = 0;  // @245_53d230
  X4[0] = F2U(U2F(X4[0]) * U2F(X5[0]));  // @246_53d230
  X4[0] = F2U(U2F(X4[0]) + U2F(X0[0]));  // @247_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 40) + 0), 4); v; });  // @248_53d230
  X0[1] = 0;  // @249_53d230
  X0[2] = 0;  // @250_53d230
  X0[3] = 0;  // @251_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @252_53d230
  X4[0] = F2U(U2F(X4[0]) + U2F(X0[0]));  // @253_53d230
  if ((!(!(U2F(X1[0]) >= U2F(X4[0]))) && !(!((U2F(X1[0]) < U2F(X4[0])) || (U2F(X1[0]) > U2F(X4[0])))))) goto L53d6b6;  // @254_53d230
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @255_53d230
  X2[1] = 0;  // @256_53d230
  X2[2] = 0;  // @257_53d230
  X2[3] = 0;  // @258_53d230
  if ((!(!(U2F(X4[0]) >= U2F(X2[0]))) && !(!((U2F(X4[0]) < U2F(X2[0])) || (U2F(X4[0]) > U2F(X2[0])))))) goto L53d6b6;  // @259_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 32) + 0), 4); v; });  // @260_53d230
  X0[1] = 0;  // @261_53d230
  X0[2] = 0;  // @262_53d230
  X0[3] = 0;  // @263_53d230
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @264_53d230
  X3[1] = 0;  // @265_53d230
  X3[2] = 0;  // @266_53d230
  X3[3] = 0;  // @267_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @268_53d230
  X3[0] = F2U(U2F(X3[0]) * U2F(X6[0]));  // @269_53d230
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @270_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 44) + 0), 4); v; });  // @271_53d230
  X0[1] = 0;  // @272_53d230
  X0[2] = 0;  // @273_53d230
  X0[3] = 0;  // @274_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @275_53d230
  X3[0] = F2U(U2F(X3[0]) + U2F(X0[0]));  // @276_53d230
  if ((!(!(U2F(X1[0]) >= U2F(X3[0]))) && !(!((U2F(X1[0]) < U2F(X3[0])) || (U2F(X1[0]) > U2F(X3[0])))))) goto L53d6b6;  // @277_53d230
  X3[0] = F2U(U2F(X3[0]) + U2F(X4[0]));  // @278_53d230
  if ((!(!(U2F(X3[0]) >= U2F(X2[0]))) && !(!((U2F(X3[0]) < U2F(X2[0])) || (U2F(X3[0]) > U2F(X2[0])))))) goto L53d6b6;  // @279_53d230
  eax = (u32)(esi + 52);  // @280_53d230
  PV[29] = (u32)(eax);  // @281_53d230
  edx = (u32)(EBP - 564);  // @282_53d230
  ecx = (u32)(EBP - 780);  // @283_53d230
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[29]);  // @284_53d230
  ecx = edx = 0;  // @285_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 540) + 0), 4); v; });  // @286_53d230
  X1[1] = 0;  // @287_53d230
  X1[2] = 0;  // @288_53d230
  X1[3] = 0;  // @289_53d230
  if ((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) goto L53d6b6;  // @290_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @291_53d230
  X0[1] = 0;  // @292_53d230
  X0[2] = 0;  // @293_53d230
  X0[3] = 0;  // @294_53d230
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L53d6b6;  // @295_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @296_53d230
  X0[1] = 0;  // @297_53d230
  X0[2] = 0;  // @298_53d230
  X0[3] = 0;  // @299_53d230
  eax = (u32)(esi + 4);  // @300_53d230
  PV[30] = (u32)(ecx);  // @301_53d230
  ecx = edi;  // @302_53d230
  PV[31] = (u32)(eax);  // @303_53d230
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @304_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @305_53d230
  X0[1] = 0;  // @306_53d230
  X0[2] = 0;  // @307_53d230
  X0[3] = 0;  // @308_53d230
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @309_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @310_53d230
  X0[1] = 0;  // @311_53d230
  X0[2] = 0;  // @312_53d230
  X0[3] = 0;  // @313_53d230
  eax = (u32)(EBP - 52);  // @314_53d230
  PV[32] = (u32)(eax);  // @315_53d230
  eax = (u32)(EBP - 64);  // @316_53d230
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @317_53d230
  PV[33] = (u32)(eax);  // @318_53d230
  eax = (u32)(EBP - 88);  // @319_53d230
  PV[34] = (u32)(eax);  // @320_53d230
  eax = (u32)(EBP - 100);  // @321_53d230
  PV[35] = (u32)(eax);  // @322_53d230
  eax = (u32)(EBP - 136);  // @323_53d230
  PV[36] = (u32)(eax);  // @324_53d230
  eax = (u32)(EBP - 184);  // @325_53d230
  PV[37] = (u32)(eax);  // @326_53d230
  eax = (u32)(EBP - 780);  // @327_53d230
  PV[38] = (u32)(eax);  // @328_53d230
  eax = (u32)(EBP - 624);  // @329_53d230
  PV[39] = (u32)(eax);  // @330_53d230
  eax = ext_5403f0_stdcall10(PV[39], PV[38], PV[37], PV[36], PV[35], PV[34], PV[33], PV[32], PV[31], (u32)(1065353216));  // @331_53d230
  ecx = edx = 0;  // @332_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 616), sizeof v); (u32)v; });  // @333_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 624) + 0), 4); v; });  // @334_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 624) + 4), 4); v; });  // @335_53d230
  X0[2] = 0;  // @336_53d230
  X0[3] = 0;  // @337_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @338_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @339_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @340_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @341_53d230
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @342_53d230
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @343_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 184) + 0), 4); v; });  // @344_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 184) + 4), 4); v; });  // @345_53d230
  X0[2] = 0;  // @346_53d230
  X0[3] = 0;  // @347_53d230
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @348_53d230
  __builtin_memcpy((void *)((u32)(EBP - 136) + 4), &X0[1], 4);  // @349_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @350_53d230
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @351_53d230
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 533), &v, sizeof v); }  // @352_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @353_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @354_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[40]);  // @355_53d230
  ecx = edx = 0;  // @356_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @357_53d230
  L53d6b6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @359_53d230
  eax = (u32)(EBP - 736);  // @360_53d230
  PV[41] = (u32)(eax);  // @361_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @362_53d230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @363_53d230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 100), sizeof v); (u32)v; });  // @364_53d230
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, PV[41]);  // @365_53d230
  ecx = edx = 0;  // @366_53d230
  esi = eax;  // @367_53d230
  FL[2] = (esi & esi);  // @368_53d230
  if (FL[2] != 0) goto L53d420;  // @369_53d230
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 533), sizeof v); (u32)v; })) & 0xff);  // @370_53d230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @371_53d230
  if (FL[2] == 0) goto L53da48;  // @372_53d230
  goto L53d860;  // @373_53d230
  L53d6e7:;
  eax = (u32)(EBP - 148);  // @375_53d230
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @376_53d230
  PV[42] = (u32)(eax);  // @377_53d230
  edx = (u32)(EBP - 16);  // @378_53d230
  ecx = (u32)(EBP - 804);  // @379_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[42]);  // @380_53d230
  ecx = edx = 0;  // @381_53d230
  eax = (u32)(EBP - 148);  // @382_53d230
  ecx = esi;  // @383_53d230
  PV[43] = (u32)(eax);  // @384_53d230
  eax = (u32)(EBP - 268);  // @385_53d230
  PV[44] = (u32)(eax);  // @386_53d230
  eax = ext_4ea280_thiscall3(ecx, PV[44], PV[43]);  // @387_53d230
  ecx = edx = 0;  // @388_53d230
  eax = (u32)(EBP - 16);  // @389_53d230
  ecx = esi;  // @390_53d230
  PV[45] = (u32)(eax);  // @391_53d230
  eax = (u32)(EBP - 316);  // @392_53d230
  PV[46] = (u32)(eax);  // @393_53d230
  eax = ext_4ea280_thiscall3(ecx, PV[46], PV[45]);  // @394_53d230
  ecx = edx = 0;  // @395_53d230
  eax = (u32)(EBP - 268);  // @396_53d230
  PV[47] = (u32)(eax);  // @397_53d230
  edx = (u32)(EBP - 316);  // @398_53d230
  ecx = (u32)(EBP - 328);  // @399_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[47]);  // @400_53d230
  ecx = edx = 0;  // @401_53d230
  eax = (u32)(EBP - 328);  // @402_53d230
  ecx = esi;  // @403_53d230
  PV[48] = (u32)(eax);  // @404_53d230
  eax = (u32)(EBP - 268);  // @405_53d230
  PV[49] = (u32)(eax);  // @406_53d230
  eax = (u32)(EBP - 532);  // @407_53d230
  PV[50] = (u32)(eax);  // @408_53d230
  eax = ext_4e8c80_thiscall5(ecx, PV[50], PV[49], PV[48], (u32)(0));  // @409_53d230
  ecx = edx = 0;  // @410_53d230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @411_53d230
  if (FL[2] == 0) goto L53da3c;  // @412_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 532) + 0), 4); v; });  // @413_53d230
  X0[1] = 0;  // @414_53d230
  X0[2] = 0;  // @415_53d230
  X0[3] = 0;  // @416_53d230
  eax = (u32)(EBP - 804);  // @417_53d230
  PV[51] = (u32)(ecx);  // @418_53d230
  PV[52] = X0[0];  // @419_53d230
  edx = (u32)(EBP - 148);  // @420_53d230
  PV[53] = (u32)(eax);  // @421_53d230
  ecx = (u32)(EBP - 792);  // @422_53d230
  __builtin_memcpy((void *)((u32)(EBP - 540) + 0), &X0[0], 4);  // @423_53d230
  eax = ext_443ef0_fastcall4(ecx, edx, PV[53], PV[52]);  // @424_53d230
  ecx = edx = 0;  // @425_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 540) + 0), 4); v; });  // @426_53d230
  X1[1] = 0;  // @427_53d230
  X1[2] = 0;  // @428_53d230
  X1[3] = 0;  // @429_53d230
  if ((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6958592) + 0), 4); v; }))))) goto L53da3c;  // @430_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6958576) + 0), 4); v; });  // @431_53d230
  X0[1] = 0;  // @432_53d230
  X0[2] = 0;  // @433_53d230
  X0[3] = 0;  // @434_53d230
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L53da3c;  // @435_53d230
  eax = (u32)(EBP - 488);  // @436_53d230
  PV[54] = (u32)(eax);  // @437_53d230
  eax = (u32)(EBP - 500);  // @438_53d230
  PV[55] = (u32)(eax);  // @439_53d230
  edx = (u32)(EBP - 512);  // @440_53d230
  ecx = (u32)(EBP - 28);  // @441_53d230
  eax = ext_53d160_fastcall4(ecx, edx, PV[55], PV[54]);  // @442_53d230
  ecx = edx = 0;  // @443_53d230
  eax = (u32)(EBP - 28);  // @444_53d230
  ecx = esi;  // @445_53d230
  PV[56] = (u32)(eax);  // @446_53d230
  eax = ext_4ea2e0_thiscall2(ecx, PV[56]);  // @447_53d230
  ecx = edx = 0;  // @448_53d230
  PV[57] = (u32)(ecx);  // @449_53d230
  eax = (u32)(EBP - 28);  // @450_53d230
  PV[58] = (u32)(eax);  // @451_53d230
  eax = (u32)(EBP - 52);  // @452_53d230
  ecx = edi;  // @453_53d230
  PV[59] = (u32)(eax);  // @454_53d230
  eax = (u32)(EBP - 64);  // @455_53d230
  PV[60] = (u32)(eax);  // @456_53d230
  eax = (u32)(EBP - 88);  // @457_53d230
  PV[61] = (u32)(eax);  // @458_53d230
  eax = (u32)(EBP - 100);  // @459_53d230
  PV[62] = (u32)(eax);  // @460_53d230
  eax = (u32)(EBP - 136);  // @461_53d230
  PV[63] = (u32)(eax);  // @462_53d230
  eax = (u32)(EBP - 184);  // @463_53d230
  PV[64] = (u32)(eax);  // @464_53d230
  eax = (u32)(EBP - 792);  // @465_53d230
  PV[65] = (u32)(eax);  // @466_53d230
  eax = (u32)(EBP - 624);  // @467_53d230
  PV[66] = (u32)(eax);  // @468_53d230
  eax = ext_5403f0_stdcall10(PV[66], PV[65], PV[64], PV[63], PV[62], PV[61], PV[60], PV[59], PV[58], (u32)(1065353216));  // @469_53d230
  ecx = edx = 0;  // @470_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 624) + 0), 4); v; });  // @471_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 624) + 4), 4); v; });  // @472_53d230
  X0[2] = 0;  // @473_53d230
  X0[3] = 0;  // @474_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 616), sizeof v); (u32)v; });  // @475_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @476_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 176), sizeof v); (u32)v; });  // @477_53d230
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @478_53d230
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @479_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 184) + 0), 4); v; });  // @480_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 184) + 4), 4); v; });  // @481_53d230
  X0[2] = 0;  // @482_53d230
  X0[3] = 0;  // @483_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 128), &v, sizeof v); }  // @484_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 516), sizeof v); (u32)v; });  // @485_53d230
  __builtin_memcpy((void *)((u32)(EBP - 136) + 0), &X0[0], 4);  // @486_53d230
  __builtin_memcpy((void *)((u32)(EBP - 136) + 4), &X0[1], 4);  // @487_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @488_53d230
  L53d860:;
  eax = (u32)(EBP - 764);  // @490_53d230
  PV[67] = (u32)(eax);  // @491_53d230
  edx = (u32)(EBP - 624);  // @492_53d230
  ecx = (u32)(EBP - 588);  // @493_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[67]);  // @494_53d230
  ecx = edx = 0;  // @495_53d230
  edx = (u32)(EBP - 588);  // @496_53d230
  ecx = (u32)(EBP - 124);  // @497_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @498_53d230
  ecx = edx = 0;  // @499_53d230
  edx = (u32)(EBP - 588);  // @500_53d230
  ecx = (u32)(EBP - 112);  // @501_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @502_53d230
  ecx = edx = 0;  // @503_53d230
  edx = (u32)(EBP - 588);  // @504_53d230
  ecx = (u32)(EBP - 76);  // @505_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @506_53d230
  ecx = edx = 0;  // @507_53d230
  edx = (u32)(EBP - 588);  // @508_53d230
  ecx = (u32)(EBP - 40);  // @509_53d230
  eax = ext_441940_fastcall2(ecx, edx);  // @510_53d230
  ecx = edx = 0;  // @511_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 616), sizeof v); (u32)v; });  // @512_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 624) + 0), 4); v; });  // @513_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 624) + 4), 4); v; });  // @514_53d230
  X0[2] = 0;  // @515_53d230
  X0[3] = 0;  // @516_53d230
  __builtin_memcpy((void *)((u32)(EBP - 16) + 0), &X0[0], 4);  // @517_53d230
  __builtin_memcpy((void *)((u32)(EBP - 16) + 4), &X0[1], 4);  // @518_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @519_53d230
  X0[1] = 0;  // @520_53d230
  X0[2] = 0;  // @521_53d230
  X0[3] = 0;  // @522_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @523_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @524_53d230
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 534), &v, sizeof v); }  // @525_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @526_53d230
  __builtin_memcpy((void *)((u32)(eax + 64) + 0), &X0[0], 4);  // @527_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; });  // @528_53d230
  X0[1] = 0;  // @529_53d230
  X0[2] = 0;  // @530_53d230
  X0[3] = 0;  // @531_53d230
  __builtin_memcpy((void *)((u32)(eax + 68) + 0), &X0[0], 4);  // @532_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; });  // @533_53d230
  X0[1] = 0;  // @534_53d230
  X0[2] = 0;  // @535_53d230
  X0[3] = 0;  // @536_53d230
  __builtin_memcpy((void *)((u32)(eax + 72) + 0), &X0[0], 4);  // @537_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @538_53d230
  X0[1] = 0;  // @539_53d230
  X0[2] = 0;  // @540_53d230
  X0[3] = 0;  // @541_53d230
  __builtin_memcpy((void *)((u32)(eax + 88) + 0), &X0[0], 4);  // @542_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @543_53d230
  X0[1] = 0;  // @544_53d230
  X0[2] = 0;  // @545_53d230
  X0[3] = 0;  // @546_53d230
  __builtin_memcpy((void *)((u32)(eax + 92) + 0), &X0[0], 4);  // @547_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @548_53d230
  X0[1] = 0;  // @549_53d230
  X0[2] = 0;  // @550_53d230
  X0[3] = 0;  // @551_53d230
  __builtin_memcpy((void *)((u32)(eax + 96) + 0), &X0[0], 4);  // @552_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @553_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 112) + 0), 4); v; });  // @554_53d230
  X0[1] = 0;  // @555_53d230
  X0[2] = 0;  // @556_53d230
  X0[3] = 0;  // @557_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @558_53d230
  __builtin_memcpy((void *)((u32)(eax + 116) + 0), &X0[0], 4);  // @559_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @560_53d230
  X0[1] = 0;  // @561_53d230
  X0[2] = 0;  // @562_53d230
  X0[3] = 0;  // @563_53d230
  __builtin_memcpy((void *)((u32)(eax + 120) + 0), &X0[0], 4);  // @564_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 104) + 0), 4); v; });  // @565_53d230
  X0[1] = 0;  // @566_53d230
  X0[2] = 0;  // @567_53d230
  X0[3] = 0;  // @568_53d230
  __builtin_memcpy((void *)((u32)(eax + 124) + 0), &X0[0], 4);  // @569_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @570_53d230
  X0[1] = 0;  // @571_53d230
  X0[2] = 0;  // @572_53d230
  X0[3] = 0;  // @573_53d230
  __builtin_memcpy((void *)((u32)(eax + 140) + 0), &X0[0], 4);  // @574_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @575_53d230
  X0[1] = 0;  // @576_53d230
  X0[2] = 0;  // @577_53d230
  X0[3] = 0;  // @578_53d230
  __builtin_memcpy((void *)((u32)(eax + 144) + 0), &X0[0], 4);  // @579_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @580_53d230
  X0[1] = 0;  // @581_53d230
  X0[2] = 0;  // @582_53d230
  X0[3] = 0;  // @583_53d230
  __builtin_memcpy((void *)((u32)(eax + 148) + 0), &X0[0], 4);  // @584_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @585_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @586_53d230
  X0[1] = 0;  // @587_53d230
  X0[2] = 0;  // @588_53d230
  X0[3] = 0;  // @589_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @590_53d230
  __builtin_memcpy((void *)((u32)(eax + 168) + 0), &X0[0], 4);  // @591_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @592_53d230
  X0[1] = 0;  // @593_53d230
  X0[2] = 0;  // @594_53d230
  X0[3] = 0;  // @595_53d230
  __builtin_memcpy((void *)((u32)(eax + 172) + 0), &X0[0], 4);  // @596_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @597_53d230
  X0[1] = 0;  // @598_53d230
  X0[2] = 0;  // @599_53d230
  X0[3] = 0;  // @600_53d230
  __builtin_memcpy((void *)((u32)(eax + 176) + 0), &X0[0], 4);  // @601_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @602_53d230
  X0[1] = 0;  // @603_53d230
  X0[2] = 0;  // @604_53d230
  X0[3] = 0;  // @605_53d230
  __builtin_memcpy((void *)((u32)(eax + 192) + 0), &X0[0], 4);  // @606_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @607_53d230
  X0[1] = 0;  // @608_53d230
  X0[2] = 0;  // @609_53d230
  X0[3] = 0;  // @610_53d230
  __builtin_memcpy((void *)((u32)(eax + 196) + 0), &X0[0], 4);  // @611_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @612_53d230
  X0[1] = 0;  // @613_53d230
  X0[2] = 0;  // @614_53d230
  X0[3] = 0;  // @615_53d230
  __builtin_memcpy((void *)((u32)(eax + 200) + 0), &X0[0], 4);  // @616_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @617_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @618_53d230
  X0[1] = 0;  // @619_53d230
  X0[2] = 0;  // @620_53d230
  X0[3] = 0;  // @621_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @622_53d230
  __builtin_memcpy((void *)((u32)(eax + 220) + 0), &X0[0], 4);  // @623_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @624_53d230
  X0[1] = 0;  // @625_53d230
  X0[2] = 0;  // @626_53d230
  X0[3] = 0;  // @627_53d230
  __builtin_memcpy((void *)((u32)(eax + 224) + 0), &X0[0], 4);  // @628_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @629_53d230
  X0[1] = 0;  // @630_53d230
  X0[2] = 0;  // @631_53d230
  X0[3] = 0;  // @632_53d230
  __builtin_memcpy((void *)((u32)(eax + 228) + 0), &X0[0], 4);  // @633_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @634_53d230
  X0[1] = 0;  // @635_53d230
  X0[2] = 0;  // @636_53d230
  X0[3] = 0;  // @637_53d230
  __builtin_memcpy((void *)((u32)(eax + 244) + 0), &X0[0], 4);  // @638_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @639_53d230
  X0[1] = 0;  // @640_53d230
  X0[2] = 0;  // @641_53d230
  X0[3] = 0;  // @642_53d230
  __builtin_memcpy((void *)((u32)(eax + 248) + 0), &X0[0], 4);  // @643_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @644_53d230
  X0[1] = 0;  // @645_53d230
  X0[2] = 0;  // @646_53d230
  X0[3] = 0;  // @647_53d230
  __builtin_memcpy((void *)((u32)(eax + 252) + 0), &X0[0], 4);  // @648_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @649_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @650_53d230
  X0[2] = 0;  // @651_53d230
  X0[3] = 0;  // @652_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @653_53d230
  __builtin_memcpy((void *)((u32)(EBP - 196) + 0), &X0[0], 4);  // @654_53d230
  __builtin_memcpy((void *)((u32)(EBP - 196) + 4), &X0[1], 4);  // @655_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @656_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @657_53d230
  X0[2] = 0;  // @658_53d230
  X0[3] = 0;  // @659_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @660_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @661_53d230
  __builtin_memcpy((void *)((u32)(EBP - 208) + 0), &X0[0], 4);  // @662_53d230
  __builtin_memcpy((void *)((u32)(EBP - 208) + 4), &X0[1], 4);  // @663_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @664_53d230
  goto L53da48;  // @665_53d230
  L53da3c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @667_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @668_53d230
  L53da48:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @670_53d230
  if (FL[0] == FL[1]) goto L53e6a4;  // @671_53d230
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @672_53d230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 309), sizeof v); (u32)v; });  // @673_53d230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @674_53d230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @675_53d230
  if ((s32)FL[0] <= (s32)FL[1]) goto L53e4ad;  // @676_53d230
  L53da72:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @678_53d230
  X0[1] = 0;  // @679_53d230
  X0[2] = 0;  // @680_53d230
  X0[3] = 0;  // @681_53d230
  edx = (u32)(EBP - 124);  // @682_53d230
  PV[68] = (u32)(ecx);  // @683_53d230
  ecx = (u32)(EBP - 160);  // @684_53d230
  PV[69] = X0[0];  // @685_53d230
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[69]);  // @686_53d230
    // @687_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @688_53d230
  X0[1] = 0;  // @689_53d230
  X0[2] = 0;  // @690_53d230
  X0[3] = 0;  // @691_53d230
  edx = (u32)(EBP - 112);  // @692_53d230
  PV[70] = (u32)(ecx);  // @693_53d230
  ecx = (u32)(EBP - 160);  // @694_53d230
  PV[71] = X0[0];  // @695_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[71]);  // @696_53d230
  ecx = 0;  // @697_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @698_53d230
  X0[1] = 0;  // @699_53d230
  X0[2] = 0;  // @700_53d230
  X0[3] = 0;  // @701_53d230
  edx = (u32)(EBP - 76);  // @702_53d230
  PV[72] = (u32)(ecx);  // @703_53d230
  ecx = (u32)(EBP - 160);  // @704_53d230
  PV[73] = X0[0];  // @705_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[73]);  // @706_53d230
  ecx = 0;  // @707_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @708_53d230
  X0[1] = 0;  // @709_53d230
  X0[2] = 0;  // @710_53d230
  X0[3] = 0;  // @711_53d230
  edx = (u32)(EBP - 40);  // @712_53d230
  PV[74] = (u32)(ecx);  // @713_53d230
  ecx = (u32)(EBP - 160);  // @714_53d230
  PV[75] = X0[0];  // @715_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[75]);  // @716_53d230
  ecx = 0;  // @717_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 0), 4); v; });  // @718_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 160) + 4), 4); v; });  // @719_53d230
  X0[2] = 0;  // @720_53d230
  X0[3] = 0;  // @721_53d230
  edx = (u32)(EBP - 256);  // @722_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @723_53d230
  __builtin_memcpy((void *)((u32)(EBP - 600) + 0), &X0[0], 4);  // @724_53d230
  __builtin_memcpy((void *)((u32)(EBP - 600) + 4), &X0[1], 4);  // @725_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 592), &v, sizeof v); }  // @726_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @727_53d230
  X0[1] = 0;  // @728_53d230
  X0[2] = 0;  // @729_53d230
  X0[3] = 0;  // @730_53d230
  PV[76] = (u32)(ecx);  // @731_53d230
  ecx = (u32)(EBP - 172);  // @732_53d230
  PV[77] = X0[0];  // @733_53d230
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[77]);  // @734_53d230
    // @735_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @736_53d230
  X0[1] = 0;  // @737_53d230
  X0[2] = 0;  // @738_53d230
  X0[3] = 0;  // @739_53d230
  edx = (u32)(EBP - 244);  // @740_53d230
  PV[78] = (u32)(ecx);  // @741_53d230
  ecx = (u32)(EBP - 172);  // @742_53d230
  PV[79] = X0[0];  // @743_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[79]);  // @744_53d230
  ecx = 0;  // @745_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @746_53d230
  X0[1] = 0;  // @747_53d230
  X0[2] = 0;  // @748_53d230
  X0[3] = 0;  // @749_53d230
  edx = (u32)(EBP - 232);  // @750_53d230
  PV[80] = (u32)(ecx);  // @751_53d230
  ecx = (u32)(EBP - 172);  // @752_53d230
  PV[81] = X0[0];  // @753_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[81]);  // @754_53d230
  ecx = 0;  // @755_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @756_53d230
  X0[1] = 0;  // @757_53d230
  X0[2] = 0;  // @758_53d230
  X0[3] = 0;  // @759_53d230
  edx = (u32)(EBP - 280);  // @760_53d230
  PV[82] = (u32)(ecx);  // @761_53d230
  ecx = (u32)(EBP - 172);  // @762_53d230
  PV[83] = X0[0];  // @763_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[83]);  // @764_53d230
  ecx = 0;  // @765_53d230
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @766_53d230
  FL[3] = (eax & 0xff);  // @767_53d230
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 533), &v, sizeof v); }  // @768_53d230
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 342), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @769_53d230
  if (FL[0] == FL[1]) goto L53deea;  // @770_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @771_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @772_53d230
  FL[2] = (ecx & ecx);  // @773_53d230
  if (FL[2] == 0) goto L53e48e;  // @774_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @775_53d230
  edx = (u32)(EBP - 708);  // @776_53d230
  PV[84] = (u32)(edx);  // @777_53d230
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[84]);  // @778_53d230
  ecx = edx = 0;  // @779_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 98), sizeof v); (u32)v; });  // @780_53d230
  edx = (u32)(EBP - 708);  // @781_53d230
  PV[85] = (u32)(edx);  // @782_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @783_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @784_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; });  // @785_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[85]);  // @786_53d230
  ecx = edx = 0;  // @787_53d230
  edi = eax;  // @788_53d230
  FL[2] = (edi & edi);  // @789_53d230
  if (FL[2] == 0) goto L53e488;  // @790_53d230
  L53dbb0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @792_53d230
  PV[86] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @793_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @794_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @795_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @796_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[86]);  // @797_53d230
  ecx = edx = 0;  // @798_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @799_53d230
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; });  // @800_53d230
  if (FL[0] == FL[1]) goto L53dea7;  // @801_53d230
  eax = (u32)(EBP - 16);  // @802_53d230
  PV[87] = (u32)(eax);  // @803_53d230
  edx = (u32)(EBP - 600);  // @804_53d230
  ecx = (u32)(EBP - 680);  // @805_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[87]);  // @806_53d230
  ecx = edx = 0;  // @807_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 36) + 0), 4); v; });  // @808_53d230
  X0[1] = 0;  // @809_53d230
  X0[2] = 0;  // @810_53d230
  X0[3] = 0;  // @811_53d230
  esi = (u32)(edi + 52);  // @812_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @813_53d230
  X1[1] = 0;  // @814_53d230
  X1[2] = 0;  // @815_53d230
  X1[3] = 0;  // @816_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 676) + 0), 4); v; })));  // @817_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 680) + 0), 4); v; })));  // @818_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @819_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 48) + 0), 4); v; });  // @820_53d230
  X0[1] = 0;  // @821_53d230
  X0[2] = 0;  // @822_53d230
  X0[3] = 0;  // @823_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 672) + 0), 4); v; })));  // @824_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @825_53d230
  __builtin_memcpy((void *)((u32)(EBP - 552) + 0), &X1[0], 4);  // @826_53d230
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))))) goto L53dea7;  // @827_53d230
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @828_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6814416) + 0), 4); v; }); X1[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6814416) + 4), 4); v; }); X1[2] = X1[3] = 0;  // @829_53d230
  X0[0] = X0[0] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; });  // @830_53d230
  X0[1] = X0[1] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; });  // @831_53d230
  X0[2] = X0[2] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 8), 4); v; });  // @832_53d230
  X0[3] = X0[3] & ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 12), 4); v; });  // @833_53d230
  if ((!(!(U2D(X1[0], X1[1]) >= U2D(X0[0], X0[1]))) && !(!((U2D(X1[0], X1[1]) < U2D(X0[0], X0[1])) || (U2D(X1[0], X1[1]) > U2D(X0[0], X0[1])))))) goto L53dea7;  // @834_53d230
  PV[88] = (u32)(esi);  // @835_53d230
  edx = (u32)(EBP - 16);  // @836_53d230
  ecx = (u32)(EBP - 640);  // @837_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[88]);  // @838_53d230
  ecx = edx = 0;  // @839_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 36) + 0), 4); v; });  // @840_53d230
  X0[1] = 0;  // @841_53d230
  X0[2] = 0;  // @842_53d230
  X0[3] = 0;  // @843_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 636) + 0), 4); v; })));  // @844_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 24) + 0), 4); v; });  // @845_53d230
  X1[1] = 0;  // @846_53d230
  X1[2] = 0;  // @847_53d230
  X1[3] = 0;  // @848_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 640) + 0), 4); v; })));  // @849_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @850_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 48) + 0), 4); v; });  // @851_53d230
  X0[1] = 0;  // @852_53d230
  X0[2] = 0;  // @853_53d230
  X0[3] = 0;  // @854_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 632) + 0), 4); v; })));  // @855_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @856_53d230
  X0[0] = 0;  // @857_53d230
  X0[1] = 0;  // @858_53d230
  X0[2] = 0;  // @859_53d230
  X0[3] = 0;  // @860_53d230
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 552) + 0), 4); v; })));  // @861_53d230
  X1[0] = X1[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @862_53d230
  X1[1] = X1[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @863_53d230
  X1[2] = X1[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @864_53d230
  X1[3] = X1[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @865_53d230
  __builtin_memcpy((void *)((u32)(EBP - 552) + 0), &X1[0], 4);  // @866_53d230
  if ((!(!(U2F(X0[0]) >= U2F(X1[0]))))) goto L53dea7;  // @867_53d230
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))))) goto L53dea7;  // @868_53d230
  PV[89] = (u32)(ecx);  // @869_53d230
  edx = (u32)(EBP - 680);  // @870_53d230
  PV[90] = X1[0];  // @871_53d230
  ecx = (u32)(EBP - 640);  // @872_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[90]);  // @873_53d230
  ecx = 0;  // @874_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 16) + 0), 4); v; });  // @875_53d230
  X0[1] = 0;  // @876_53d230
  X0[2] = 0;  // @877_53d230
  X0[3] = 0;  // @878_53d230
  X3[0] = 0;  // @879_53d230
  X3[1] = 0;  // @880_53d230
  X3[2] = 0;  // @881_53d230
  X3[3] = 0;  // @882_53d230
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 28) + 0), 4); v; });  // @883_53d230
  X2[1] = 0;  // @884_53d230
  X2[2] = 0;  // @885_53d230
  X2[3] = 0;  // @886_53d230
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 636) + 0), 4); v; });  // @887_53d230
  X5[1] = 0;  // @888_53d230
  X5[2] = 0;  // @889_53d230
  X5[3] = 0;  // @890_53d230
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 640) + 0), 4); v; });  // @891_53d230
  X6[1] = 0;  // @892_53d230
  X6[2] = 0;  // @893_53d230
  X6[3] = 0;  // @894_53d230
  X7[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 632) + 0), 4); v; });  // @895_53d230
  X7[1] = 0;  // @896_53d230
  X7[2] = 0;  // @897_53d230
  X7[3] = 0;  // @898_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X6[0]));  // @899_53d230
  X2[0] = F2U(U2F(X2[0]) * U2F(X5[0]));  // @900_53d230
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @901_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 40) + 0), 4); v; });  // @902_53d230
  X0[1] = 0;  // @903_53d230
  X0[2] = 0;  // @904_53d230
  X0[3] = 0;  // @905_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @906_53d230
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @907_53d230
  if ((!(!(U2F(X3[0]) >= U2F(X2[0]))) && !(!((U2F(X3[0]) < U2F(X2[0])) || (U2F(X3[0]) > U2F(X2[0])))))) goto L53dea7;  // @908_53d230
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @909_53d230
  X4[1] = 0;  // @910_53d230
  X4[2] = 0;  // @911_53d230
  X4[3] = 0;  // @912_53d230
  if ((!(!(U2F(X2[0]) >= U2F(X4[0]))) && !(!((U2F(X2[0]) < U2F(X4[0])) || (U2F(X2[0]) > U2F(X4[0])))))) goto L53dea7;  // @913_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 32) + 0), 4); v; });  // @914_53d230
  X0[1] = 0;  // @915_53d230
  X0[2] = 0;  // @916_53d230
  X0[3] = 0;  // @917_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 20) + 0), 4); v; });  // @918_53d230
  X1[1] = 0;  // @919_53d230
  X1[2] = 0;  // @920_53d230
  X1[3] = 0;  // @921_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X5[0]));  // @922_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(X6[0]));  // @923_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @924_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 44) + 0), 4); v; });  // @925_53d230
  X0[1] = 0;  // @926_53d230
  X0[2] = 0;  // @927_53d230
  X0[3] = 0;  // @928_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(X7[0]));  // @929_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @930_53d230
  if ((!(!(U2F(X3[0]) >= U2F(X1[0]))) && !(!((U2F(X3[0]) < U2F(X1[0])) || (U2F(X3[0]) > U2F(X1[0])))))) goto L53dea7;  // @931_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X2[0]));  // @932_53d230
  if ((!(!(U2F(X1[0]) >= U2F(X4[0]))) && !(!((U2F(X1[0]) < U2F(X4[0])) || (U2F(X1[0]) > U2F(X4[0])))))) goto L53dea7;  // @933_53d230
  PV[91] = (u32)(esi);  // @934_53d230
  edx = (u32)(EBP - 640);  // @935_53d230
  ecx = (u32)(EBP - 816);  // @936_53d230
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[91]);  // @937_53d230
  ecx = edx = 0;  // @938_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 552) + 0), 4); v; });  // @939_53d230
  X0[1] = 0;  // @940_53d230
  X0[2] = 0;  // @941_53d230
  X0[3] = 0;  // @942_53d230
  if ((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) goto L53dea7;  // @943_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @944_53d230
  X1[1] = 0;  // @945_53d230
  X1[2] = 0;  // @946_53d230
  X1[3] = 0;  // @947_53d230
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L53dea7;  // @948_53d230
  eax = (u32)(EBP - 600);  // @949_53d230
  edx = esi;  // @950_53d230
  PV[92] = (u32)(eax);  // @951_53d230
  ecx = (u32)(EBP - 612);  // @952_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[92]);  // @953_53d230
  ecx = edx = 0;  // @954_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @955_53d230
  X0[1] = 0;  // @956_53d230
  X0[2] = 0;  // @957_53d230
  X0[3] = 0;  // @958_53d230
  esi = (u32)(edi + 4);  // @959_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @960_53d230
  X1[1] = 0;  // @961_53d230
  X1[2] = 0;  // @962_53d230
  X1[3] = 0;  // @963_53d230
  edx = esi;  // @964_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 612) + 0), 4); v; })));  // @965_53d230
  PV[93] = (u32)(ecx);  // @966_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 608) + 0), 4); v; })));  // @967_53d230
  ecx = (u32)(EBP - 600);  // @968_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @969_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @970_53d230
  X0[1] = 0;  // @971_53d230
  X0[2] = 0;  // @972_53d230
  X0[3] = 0;  // @973_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 604) + 0), 4); v; })));  // @974_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @975_53d230
  PV[94] = X1[0];  // @976_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[94]);  // @977_53d230
  ecx = 0;  // @978_53d230
  eax = (u32)(EBP - 172);  // @979_53d230
  PV[95] = (u32)(eax);  // @980_53d230
  edx = (u32)(edi + 52);  // @981_53d230
  ecx = (u32)(EBP - 612);  // @982_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[95]);  // @983_53d230
  ecx = edx = 0;  // @984_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @985_53d230
  X0[1] = 0;  // @986_53d230
  X0[2] = 0;  // @987_53d230
  X0[3] = 0;  // @988_53d230
  edx = (u32)(EBP - 172);  // @989_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @990_53d230
  X1[1] = 0;  // @991_53d230
  X1[2] = 0;  // @992_53d230
  X1[3] = 0;  // @993_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 612) + 0), 4); v; })));  // @994_53d230
  PV[96] = (u32)(ecx);  // @995_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 608) + 0), 4); v; })));  // @996_53d230
  ecx = (u32)(EBP - 752);  // @997_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @998_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @999_53d230
  X0[1] = 0;  // @1000_53d230
  X0[2] = 0;  // @1001_53d230
  X0[3] = 0;  // @1002_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 604) + 0), 4); v; })));  // @1003_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1004_53d230
  PV[97] = X1[0];  // @1005_53d230
  PV[98] = (u32)(esi);  // @1006_53d230
  eax = ext_443ef0_fastcall4(ecx, edx, PV[98], PV[97]);  // @1007_53d230
  ecx = edx = 0;  // @1008_53d230
  eax = (u32)(EBP - 752);  // @1009_53d230
  PV[99] = (u32)(eax);  // @1010_53d230
  edx = (u32)(EBP - 600);  // @1011_53d230
  ecx = (u32)(EBP - 612);  // @1012_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[99]);  // @1013_53d230
  ecx = edx = 0;  // @1014_53d230
  PV[100] = (u32)(ecx);  // @1015_53d230
  eax = (u32)(EBP - 612);  // @1016_53d230
  PV[101] = (u32)(eax);  // @1017_53d230
  edx = (u32)(EBP - 752);  // @1018_53d230
  ecx = (u32)(EBP - 600);  // @1019_53d230
  eax = ext_443ef0_fastcall4(ecx, edx, PV[101], (u32)(1036831949));  // @1020_53d230
  ecx = edx = 0;  // @1021_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1022_53d230
  PV[102] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1023_53d230
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 533), &v, sizeof v); }  // @1024_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1025_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1026_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @1027_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[102]);  // @1028_53d230
  ecx = edx = 0;  // @1029_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @1030_53d230
  L53dea7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @1032_53d230
  edx = (u32)(EBP - 708);  // @1033_53d230
  PV[103] = (u32)(edx);  // @1034_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 98), sizeof v); (u32)v; });  // @1035_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @1036_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1037_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 100), sizeof v); (u32)v; });  // @1038_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[103]);  // @1039_53d230
  ecx = edx = 0;  // @1040_53d230
  edi = eax;  // @1041_53d230
  FL[2] = (edi & edi);  // @1042_53d230
  if (FL[2] != 0) goto L53dbb0;  // @1043_53d230
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 533), sizeof v); (u32)v; })) & 0xff);  // @1044_53d230
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @1045_53d230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; });  // @1046_53d230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1047_53d230
  if (FL[2] == 0) goto L53e48e;  // @1048_53d230
  goto L53e0f5;  // @1049_53d230
  L53deea:;
  eax = (u32)(EBP - 16);  // @1051_53d230
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @1052_53d230
  PV[104] = (u32)(eax);  // @1053_53d230
  edx = (u32)(EBP - 160);  // @1054_53d230
  ecx = (u32)(EBP - 828);  // @1055_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[104]);  // @1056_53d230
  ecx = edx = 0;  // @1057_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), sizeof v); (u32)v; });  // @1058_53d230
  eax = (u32)(EBP - 16);  // @1059_53d230
  PV[105] = (u32)(eax);  // @1060_53d230
  eax = (u32)(EBP - 292);  // @1061_53d230
  PV[106] = (u32)(eax);  // @1062_53d230
  eax = ext_4ea280_thiscall3(ecx, PV[106], PV[105]);  // @1063_53d230
  ecx = edx = 0;  // @1064_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), sizeof v); (u32)v; });  // @1065_53d230
  eax = (u32)(EBP - 160);  // @1066_53d230
  PV[107] = (u32)(eax);  // @1067_53d230
  eax = (u32)(EBP - 340);  // @1068_53d230
  PV[108] = (u32)(eax);  // @1069_53d230
  eax = ext_4ea280_thiscall3(ecx, PV[108], PV[107]);  // @1070_53d230
  ecx = edx = 0;  // @1071_53d230
  eax = (u32)(EBP - 292);  // @1072_53d230
  PV[109] = (u32)(eax);  // @1073_53d230
  edx = (u32)(EBP - 340);  // @1074_53d230
  ecx = (u32)(EBP - 352);  // @1075_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[109]);  // @1076_53d230
  ecx = edx = 0;  // @1077_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), sizeof v); (u32)v; });  // @1078_53d230
  eax = (u32)(EBP - 352);  // @1079_53d230
  PV[110] = (u32)(eax);  // @1080_53d230
  eax = (u32)(EBP - 292);  // @1081_53d230
  PV[111] = (u32)(eax);  // @1082_53d230
  eax = (u32)(EBP - 460);  // @1083_53d230
  PV[112] = (u32)(eax);  // @1084_53d230
  eax = ext_4e8c80_thiscall5(ecx, PV[112], PV[111], PV[110], (u32)(0));  // @1085_53d230
  ecx = edx = 0;  // @1086_53d230
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @1087_53d230
  if (FL[2] == 0) goto L53e48e;  // @1088_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 460) + 0), 4); v; });  // @1089_53d230
  X0[1] = 0;  // @1090_53d230
  X0[2] = 0;  // @1091_53d230
  X0[3] = 0;  // @1092_53d230
  eax = (u32)(EBP - 440);  // @1093_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), sizeof v); (u32)v; });  // @1094_53d230
  PV[113] = (u32)(eax);  // @1095_53d230
  eax = (u32)(EBP - 304);  // @1096_53d230
  __builtin_memcpy((void *)((u32)(EBP - 552) + 0), &X0[0], 4);  // @1097_53d230
  PV[114] = (u32)(eax);  // @1098_53d230
  eax = ext_4ea2b0_thiscall3(ecx, PV[114], PV[113]);  // @1099_53d230
  ecx = edx = 0;  // @1100_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 552) + 0), 4); v; });  // @1101_53d230
  X1[1] = 0;  // @1102_53d230
  X1[2] = 0;  // @1103_53d230
  X1[3] = 0;  // @1104_53d230
  if ((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) goto L53e48e;  // @1105_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @1106_53d230
  X0[1] = 0;  // @1107_53d230
  X0[2] = 0;  // @1108_53d230
  X0[3] = 0;  // @1109_53d230
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L53e48e;  // @1110_53d230
  eax = (u32)(EBP - 416);  // @1111_53d230
  PV[115] = (u32)(eax);  // @1112_53d230
  eax = (u32)(EBP - 428);  // @1113_53d230
  PV[116] = (u32)(eax);  // @1114_53d230
  edx = (u32)(EBP - 440);  // @1115_53d230
  ecx = (u32)(EBP - 28);  // @1116_53d230
  eax = ext_53d160_fastcall4(ecx, edx, PV[116], PV[115]);  // @1117_53d230
  ecx = edx = 0;  // @1118_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), sizeof v); (u32)v; });  // @1119_53d230
  eax = (u32)(EBP - 28);  // @1120_53d230
  PV[117] = (u32)(eax);  // @1121_53d230
  eax = ext_4ea2e0_thiscall2(ecx, PV[117]);  // @1122_53d230
  ecx = edx = 0;  // @1123_53d230
  eax = (u32)(EBP - 600);  // @1124_53d230
  PV[118] = (u32)(eax);  // @1125_53d230
  edx = (u32)(EBP - 304);  // @1126_53d230
  ecx = (u32)(EBP - 564);  // @1127_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[118]);  // @1128_53d230
  ecx = edx = 0;  // @1129_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @1130_53d230
  X0[1] = 0;  // @1131_53d230
  X0[2] = 0;  // @1132_53d230
  X0[3] = 0;  // @1133_53d230
  edx = (u32)(EBP - 28);  // @1134_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @1135_53d230
  X1[1] = 0;  // @1136_53d230
  X1[2] = 0;  // @1137_53d230
  X1[3] = 0;  // @1138_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 564) + 0), 4); v; })));  // @1139_53d230
  PV[119] = (u32)(ecx);  // @1140_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 560) + 0), 4); v; })));  // @1141_53d230
  ecx = (u32)(EBP - 600);  // @1142_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1143_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @1144_53d230
  X0[1] = 0;  // @1145_53d230
  X0[2] = 0;  // @1146_53d230
  X0[3] = 0;  // @1147_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 556) + 0), 4); v; })));  // @1148_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1149_53d230
  PV[120] = X1[0];  // @1150_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[120]);  // @1151_53d230
  ecx = 0;  // @1152_53d230
  eax = (u32)(EBP - 172);  // @1153_53d230
  PV[121] = (u32)(eax);  // @1154_53d230
  edx = (u32)(EBP - 304);  // @1155_53d230
  ecx = (u32)(EBP - 564);  // @1156_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[121]);  // @1157_53d230
  ecx = edx = 0;  // @1158_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @1159_53d230
  X0[1] = 0;  // @1160_53d230
  X0[2] = 0;  // @1161_53d230
  X0[3] = 0;  // @1162_53d230
  eax = (u32)(EBP - 28);  // @1163_53d230
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @1164_53d230
  X1[1] = 0;  // @1165_53d230
  X1[2] = 0;  // @1166_53d230
  X1[3] = 0;  // @1167_53d230
  edx = (u32)(EBP - 172);  // @1168_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 564) + 0), 4); v; })));  // @1169_53d230
  PV[122] = (u32)(ecx);  // @1170_53d230
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 560) + 0), 4); v; })));  // @1171_53d230
  ecx = (u32)(EBP - 724);  // @1172_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1173_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @1174_53d230
  X0[1] = 0;  // @1175_53d230
  X0[2] = 0;  // @1176_53d230
  X0[3] = 0;  // @1177_53d230
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 556) + 0), 4); v; })));  // @1178_53d230
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @1179_53d230
  PV[123] = X1[0];  // @1180_53d230
  PV[124] = (u32)(eax);  // @1181_53d230
  eax = ext_443ef0_fastcall4(ecx, edx, PV[124], PV[123]);  // @1182_53d230
  ecx = edx = 0;  // @1183_53d230
  eax = (u32)(EBP - 724);  // @1184_53d230
  PV[125] = (u32)(eax);  // @1185_53d230
  edx = (u32)(EBP - 600);  // @1186_53d230
  ecx = (u32)(EBP - 564);  // @1187_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[125]);  // @1188_53d230
  ecx = edx = 0;  // @1189_53d230
  PV[126] = (u32)(ecx);  // @1190_53d230
  eax = (u32)(EBP - 564);  // @1191_53d230
  PV[127] = (u32)(eax);  // @1192_53d230
  edx = (u32)(EBP - 724);  // @1193_53d230
  ecx = (u32)(EBP - 600);  // @1194_53d230
  eax = ext_443ef0_fastcall4(ecx, edx, PV[127], (u32)(1036831949));  // @1195_53d230
  ecx = edx = 0;  // @1196_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @1197_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 548), &v, sizeof v); }  // @1198_53d230
  L53e0f5:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @1200_53d230
  X0[1] = 0;  // @1201_53d230
  X0[2] = 0;  // @1202_53d230
  X0[3] = 0;  // @1203_53d230
  eax = (u32)(EBP - 160);  // @1204_53d230
  __builtin_memcpy((void *)((u32)(EBP - 648) + 0), &X0[0], 4);  // @1205_53d230
  edx = (u32)(EBP - 600);  // @1206_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @1207_53d230
  X0[1] = 0;  // @1208_53d230
  X0[2] = 0;  // @1209_53d230
  X0[3] = 0;  // @1210_53d230
  ecx = (u32)(EBP - 588);  // @1211_53d230
  __builtin_memcpy((void *)((u32)(EBP - 628) + 0), &X0[0], 4);  // @1212_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @1213_53d230
  X0[1] = 0;  // @1214_53d230
  X0[2] = 0;  // @1215_53d230
  X0[3] = 0;  // @1216_53d230
  __builtin_memcpy((void *)((u32)(EBP - 652) + 0), &X0[0], 4);  // @1217_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 12) + 0), 4); v; });  // @1218_53d230
  X0[1] = 0;  // @1219_53d230
  X0[2] = 0;  // @1220_53d230
  X0[3] = 0;  // @1221_53d230
  __builtin_memcpy((void *)((u32)(EBP - 552) + 0), &X0[0], 4);  // @1222_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @1223_53d230
  X0[1] = 0;  // @1224_53d230
  X0[2] = 0;  // @1225_53d230
  X0[3] = 0;  // @1226_53d230
  PV[128] = (u32)(eax);  // @1227_53d230
  __builtin_memcpy((void *)((u32)(EBP - 544) + 0), &X0[0], 4);  // @1228_53d230
  eax = ext_43e920_fastcall3(ecx, edx, PV[128]);  // @1229_53d230
  ecx = edx = 0;  // @1230_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 588) + 0), 4); v; });  // @1231_53d230
  X0[1] = 0;  // @1232_53d230
  X0[2] = 0;  // @1233_53d230
  X0[3] = 0;  // @1234_53d230
  eax = (u32)(EBP - 588);  // @1235_53d230
  X1[0] = 0;  // @1236_53d230
  X1[1] = 0;  // @1237_53d230
  X1[2] = 0;  // @1238_53d230
  X1[3] = 0;  // @1239_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 576), &v, sizeof v); }  // @1240_53d230
  eax = (u32)(EBP - 692);  // @1241_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 656), &v, sizeof v); }  // @1242_53d230
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1243_53d230
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1244_53d230
  if (!__builtin_parity(FL[2] & 0xff)) goto L53e1bb;  // @1245_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 584) + 0), 4); v; });  // @1246_53d230
  X0[1] = 0;  // @1247_53d230
  X0[2] = 0;  // @1248_53d230
  X0[3] = 0;  // @1249_53d230
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1250_53d230
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1251_53d230
  if (!__builtin_parity(FL[2] & 0xff)) goto L53e1bb;  // @1252_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 580) + 0), 4); v; });  // @1253_53d230
  X0[1] = 0;  // @1254_53d230
  X0[2] = 0;  // @1255_53d230
  X0[3] = 0;  // @1256_53d230
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1257_53d230
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1258_53d230
  if (!__builtin_parity(FL[2] & 0xff)) goto L53e1bb;  // @1259_53d230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 692), &v, sizeof v); }  // @1260_53d230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 688), &v, sizeof v); }  // @1261_53d230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 684), &v, sizeof v); }  // @1262_53d230
  goto L53e209;  // @1263_53d230
  L53e1bb:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 644), &v, sizeof v); }  // @1265_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 656), sizeof v); (u32)v; });  // @1266_53d230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 576), sizeof v); (u32)v; });  // @1267_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @1268_53d230
  __asm__ volatile(".byte 0xd8, 0xc8" ::: "st");  // @1269_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + 4)) : "st");  // @1270_53d230
  __asm__ volatile(".byte 0xd8, 0xc8" ::: "st");  // @1271_53d230
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @1272_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + 8)) : "st");  // @1273_53d230
  __asm__ volatile(".byte 0xd8, 0xc8" ::: "st");  // @1274_53d230
  __asm__ volatile(".byte 0xde, 0xc1" ::: "st");  // @1275_53d230
  __asm__ volatile("fsqrt" ::: "st");  // @1276_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 644)) : "st");  // @1277_53d230
  __asm__ volatile(".byte 0xd8, 0xf1" ::: "st");  // @1278_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx)) : "st");  // @1279_53d230
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @1280_53d230
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @1281_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + 4)) : "st");  // @1282_53d230
  __asm__ volatile(".byte 0xd8, 0xc9" ::: "st");  // @1283_53d230
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @1284_53d230
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(edx + 8)) : "st");  // @1285_53d230
  __asm__ volatile(".byte 0xde, 0xc9" ::: "st");  // @1286_53d230
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @1287_53d230
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 644)) :: "st");  // @1288_53d230
  L53e209:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 648) + 0), 4); v; });  // @1290_53d230
  X0[1] = 0;  // @1291_53d230
  X0[2] = 0;  // @1292_53d230
  X0[3] = 0;  // @1293_53d230
  edx = (u32)(EBP - 588);  // @1294_53d230
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 544) + 0), 4); v; })));  // @1295_53d230
  PV[129] = (u32)(ecx);  // @1296_53d230
  ecx = (u32)(EBP - 124);  // @1297_53d230
  PV[130] = X0[0];  // @1298_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[130]);  // @1299_53d230
  ecx = 0;  // @1300_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 628) + 0), 4); v; });  // @1301_53d230
  X0[1] = 0;  // @1302_53d230
  X0[2] = 0;  // @1303_53d230
  X0[3] = 0;  // @1304_53d230
  edx = (u32)(EBP - 588);  // @1305_53d230
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 544) + 0), 4); v; })));  // @1306_53d230
  PV[131] = (u32)(ecx);  // @1307_53d230
  ecx = (u32)(EBP - 112);  // @1308_53d230
  PV[132] = X0[0];  // @1309_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[132]);  // @1310_53d230
  ecx = 0;  // @1311_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 652) + 0), 4); v; });  // @1312_53d230
  X0[1] = 0;  // @1313_53d230
  X0[2] = 0;  // @1314_53d230
  X0[3] = 0;  // @1315_53d230
  edx = (u32)(EBP - 588);  // @1316_53d230
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 544) + 0), 4); v; })));  // @1317_53d230
  PV[133] = (u32)(ecx);  // @1318_53d230
  ecx = (u32)(EBP - 76);  // @1319_53d230
  PV[134] = X0[0];  // @1320_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[134]);  // @1321_53d230
  ecx = 0;  // @1322_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 552) + 0), 4); v; });  // @1323_53d230
  X0[1] = 0;  // @1324_53d230
  X0[2] = 0;  // @1325_53d230
  X0[3] = 0;  // @1326_53d230
  edx = (u32)(EBP - 588);  // @1327_53d230
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 544) + 0), 4); v; })));  // @1328_53d230
  PV[135] = (u32)(ecx);  // @1329_53d230
  ecx = (u32)(EBP - 40);  // @1330_53d230
  PV[136] = X0[0];  // @1331_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[136]);  // @1332_53d230
  ecx = 0;  // @1333_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 648) + 0), 4); v; });  // @1334_53d230
  X0[1] = 0;  // @1335_53d230
  X0[2] = 0;  // @1336_53d230
  X0[3] = 0;  // @1337_53d230
  edx = (u32)(EBP - 100);  // @1338_53d230
  PV[137] = (u32)(ecx);  // @1339_53d230
  ecx = (u32)(EBP - 220);  // @1340_53d230
  PV[138] = X0[0];  // @1341_53d230
  eax = ext_4e0d40_fastcall3(ecx, edx, PV[138]);  // @1342_53d230
    // @1343_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 628) + 0), 4); v; });  // @1344_53d230
  X0[1] = 0;  // @1345_53d230
  X0[2] = 0;  // @1346_53d230
  X0[3] = 0;  // @1347_53d230
  edx = (u32)(EBP - 88);  // @1348_53d230
  PV[139] = (u32)(ecx);  // @1349_53d230
  ecx = (u32)(EBP - 220);  // @1350_53d230
  PV[140] = X0[0];  // @1351_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[140]);  // @1352_53d230
  ecx = 0;  // @1353_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 652) + 0), 4); v; });  // @1354_53d230
  X0[1] = 0;  // @1355_53d230
  X0[2] = 0;  // @1356_53d230
  X0[3] = 0;  // @1357_53d230
  edx = (u32)(EBP - 64);  // @1358_53d230
  PV[141] = (u32)(ecx);  // @1359_53d230
  ecx = (u32)(EBP - 220);  // @1360_53d230
  PV[142] = X0[0];  // @1361_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[142]);  // @1362_53d230
  ecx = 0;  // @1363_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 552) + 0), 4); v; });  // @1364_53d230
  X0[1] = 0;  // @1365_53d230
  X0[2] = 0;  // @1366_53d230
  X0[3] = 0;  // @1367_53d230
  edx = (u32)(EBP - 52);  // @1368_53d230
  PV[143] = (u32)(ecx);  // @1369_53d230
  ecx = (u32)(EBP - 220);  // @1370_53d230
  PV[144] = X0[0];  // @1371_53d230
  eax = ext_451890_fastcall3(ecx, edx, PV[144]);  // @1372_53d230
  ecx = 0;  // @1373_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @1374_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 124) + 0), 4); v; });  // @1375_53d230
  X0[1] = 0;  // @1376_53d230
  X0[2] = 0;  // @1377_53d230
  X0[3] = 0;  // @1378_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @1379_53d230
  __builtin_memcpy((void *)((u32)(eax + 64) + 0), &X0[0], 4);  // @1380_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 120) + 0), 4); v; });  // @1381_53d230
  X0[1] = 0;  // @1382_53d230
  X0[2] = 0;  // @1383_53d230
  X0[3] = 0;  // @1384_53d230
  __builtin_memcpy((void *)((u32)(eax + 68) + 0), &X0[0], 4);  // @1385_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 116) + 0), 4); v; });  // @1386_53d230
  X0[1] = 0;  // @1387_53d230
  X0[2] = 0;  // @1388_53d230
  X0[3] = 0;  // @1389_53d230
  __builtin_memcpy((void *)((u32)(eax + 72) + 0), &X0[0], 4);  // @1390_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 100) + 0), 4); v; });  // @1391_53d230
  X0[1] = 0;  // @1392_53d230
  X0[2] = 0;  // @1393_53d230
  X0[3] = 0;  // @1394_53d230
  __builtin_memcpy((void *)((u32)(eax + 88) + 0), &X0[0], 4);  // @1395_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 96) + 0), 4); v; });  // @1396_53d230
  X0[1] = 0;  // @1397_53d230
  X0[2] = 0;  // @1398_53d230
  X0[3] = 0;  // @1399_53d230
  __builtin_memcpy((void *)((u32)(eax + 92) + 0), &X0[0], 4);  // @1400_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 92) + 0), 4); v; });  // @1401_53d230
  X0[1] = 0;  // @1402_53d230
  X0[2] = 0;  // @1403_53d230
  X0[3] = 0;  // @1404_53d230
  __builtin_memcpy((void *)((u32)(eax + 96) + 0), &X0[0], 4);  // @1405_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @1406_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 112) + 0), 4); v; });  // @1407_53d230
  X0[1] = 0;  // @1408_53d230
  X0[2] = 0;  // @1409_53d230
  X0[3] = 0;  // @1410_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @1411_53d230
  __builtin_memcpy((void *)((u32)(eax + 116) + 0), &X0[0], 4);  // @1412_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 108) + 0), 4); v; });  // @1413_53d230
  X0[1] = 0;  // @1414_53d230
  X0[2] = 0;  // @1415_53d230
  X0[3] = 0;  // @1416_53d230
  __builtin_memcpy((void *)((u32)(eax + 120) + 0), &X0[0], 4);  // @1417_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 104) + 0), 4); v; });  // @1418_53d230
  X0[1] = 0;  // @1419_53d230
  X0[2] = 0;  // @1420_53d230
  X0[3] = 0;  // @1421_53d230
  __builtin_memcpy((void *)((u32)(eax + 124) + 0), &X0[0], 4);  // @1422_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @1423_53d230
  X0[1] = 0;  // @1424_53d230
  X0[2] = 0;  // @1425_53d230
  X0[3] = 0;  // @1426_53d230
  __builtin_memcpy((void *)((u32)(eax + 140) + 0), &X0[0], 4);  // @1427_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 84) + 0), 4); v; });  // @1428_53d230
  X0[1] = 0;  // @1429_53d230
  X0[2] = 0;  // @1430_53d230
  X0[3] = 0;  // @1431_53d230
  __builtin_memcpy((void *)((u32)(eax + 144) + 0), &X0[0], 4);  // @1432_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @1433_53d230
  X0[1] = 0;  // @1434_53d230
  X0[2] = 0;  // @1435_53d230
  X0[3] = 0;  // @1436_53d230
  __builtin_memcpy((void *)((u32)(eax + 148) + 0), &X0[0], 4);  // @1437_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @1438_53d230
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 534), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1439_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @1440_53d230
  X0[1] = 0;  // @1441_53d230
  X0[2] = 0;  // @1442_53d230
  X0[3] = 0;  // @1443_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @1444_53d230
  __builtin_memcpy((void *)((u32)(eax + 168) + 0), &X0[0], 4);  // @1445_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 72) + 0), 4); v; });  // @1446_53d230
  X0[1] = 0;  // @1447_53d230
  X0[2] = 0;  // @1448_53d230
  X0[3] = 0;  // @1449_53d230
  __builtin_memcpy((void *)((u32)(eax + 172) + 0), &X0[0], 4);  // @1450_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @1451_53d230
  X0[1] = 0;  // @1452_53d230
  X0[2] = 0;  // @1453_53d230
  X0[3] = 0;  // @1454_53d230
  __builtin_memcpy((void *)((u32)(eax + 176) + 0), &X0[0], 4);  // @1455_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 64) + 0), 4); v; });  // @1456_53d230
  X0[1] = 0;  // @1457_53d230
  X0[2] = 0;  // @1458_53d230
  X0[3] = 0;  // @1459_53d230
  __builtin_memcpy((void *)((u32)(eax + 192) + 0), &X0[0], 4);  // @1460_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 60) + 0), 4); v; });  // @1461_53d230
  X0[1] = 0;  // @1462_53d230
  X0[2] = 0;  // @1463_53d230
  X0[3] = 0;  // @1464_53d230
  __builtin_memcpy((void *)((u32)(eax + 196) + 0), &X0[0], 4);  // @1465_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 56) + 0), 4); v; });  // @1466_53d230
  X0[1] = 0;  // @1467_53d230
  X0[2] = 0;  // @1468_53d230
  X0[3] = 0;  // @1469_53d230
  __builtin_memcpy((void *)((u32)(eax + 200) + 0), &X0[0], 4);  // @1470_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 207), sizeof v); (u32)v; });  // @1471_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @1472_53d230
  X0[1] = 0;  // @1473_53d230
  X0[2] = 0;  // @1474_53d230
  X0[3] = 0;  // @1475_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 15), sizeof v); (u32)v; });  // @1476_53d230
  __builtin_memcpy((void *)((u32)(eax + 220) + 0), &X0[0], 4);  // @1477_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @1478_53d230
  X0[1] = 0;  // @1479_53d230
  X0[2] = 0;  // @1480_53d230
  X0[3] = 0;  // @1481_53d230
  __builtin_memcpy((void *)((u32)(eax + 224) + 0), &X0[0], 4);  // @1482_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @1483_53d230
  X0[1] = 0;  // @1484_53d230
  X0[2] = 0;  // @1485_53d230
  X0[3] = 0;  // @1486_53d230
  __builtin_memcpy((void *)((u32)(eax + 228) + 0), &X0[0], 4);  // @1487_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @1488_53d230
  X0[1] = 0;  // @1489_53d230
  X0[2] = 0;  // @1490_53d230
  X0[3] = 0;  // @1491_53d230
  __builtin_memcpy((void *)((u32)(eax + 244) + 0), &X0[0], 4);  // @1492_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @1493_53d230
  X0[1] = 0;  // @1494_53d230
  X0[2] = 0;  // @1495_53d230
  X0[3] = 0;  // @1496_53d230
  __builtin_memcpy((void *)((u32)(eax + 248) + 0), &X0[0], 4);  // @1497_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @1498_53d230
  X0[1] = 0;  // @1499_53d230
  X0[2] = 0;  // @1500_53d230
  X0[3] = 0;  // @1501_53d230
  __builtin_memcpy((void *)((u32)(eax + 252) + 0), &X0[0], 4);  // @1502_53d230
  if (FL[0] != FL[1]) goto L53e48e;  // @1503_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @1504_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 4), 4); v; });  // @1505_53d230
  X0[2] = 0;  // @1506_53d230
  X0[3] = 0;  // @1507_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @1508_53d230
  __builtin_memcpy((void *)((u32)(EBP - 196) + 0), &X0[0], 4);  // @1509_53d230
  __builtin_memcpy((void *)((u32)(EBP - 196) + 4), &X0[1], 4);  // @1510_53d230
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @1511_53d230
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 4), 4); v; });  // @1512_53d230
  X0[2] = 0;  // @1513_53d230
  X0[3] = 0;  // @1514_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 188), &v, sizeof v); }  // @1515_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @1516_53d230
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 534), &v, sizeof v); }  // @1517_53d230
  __builtin_memcpy((void *)((u32)(EBP - 208) + 0), &X0[0], 4);  // @1518_53d230
  __builtin_memcpy((void *)((u32)(EBP - 208) + 4), &X0[1], 4);  // @1519_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @1520_53d230
  goto L53e48e;  // @1521_53d230
  L53e488:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @1523_53d230
  L53e48e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @1525_53d230
  esi = (esi + (u32)(20));  // @1526_53d230
  FL[3] = esi;  // @1527_53d230
  eax = (eax + 1);  // @1528_53d230
  FL[3] = eax;  // @1529_53d230
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @1530_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @1531_53d230
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 102), sizeof v); (u32)v; });  // @1532_53d230
  if ((s32)FL[0] < (s32)FL[1]) goto L53da72;  // @1533_53d230
  L53e4ad:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 534), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1535_53d230
  if (FL[0] == FL[1]) goto L53e6a4;  // @1536_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1537_53d230
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1538_53d230
  if (FL[0] == FL[1]) goto L53e6a4;  // @1539_53d230
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 317), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1540_53d230
  if (FL[0] == FL[1]) goto L53e693;  // @1541_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 64), sizeof v); (u32)v; });  // @1542_53d230
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 330), sizeof v); (u32)v; }));  // @1543_53d230
  FL[3] = eax;  // @1544_53d230
  FL[0] = eax; FL[1] = (u32)(153);  // @1545_53d230
  if ((s32)FL[0] <= (s32)FL[1]) goto L53e693;  // @1546_53d230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 548), sizeof v); (u32)v; });  // @1547_53d230
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @1548_53d230
  FL[2] = (esi & esi);  // @1549_53d230
  if (FL[2] == 0) goto L53e687;  // @1550_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6819), sizeof v); (u32)v; });  // @1551_53d230
  PV[145] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 108), sizeof v); (u32)v; });  // @1552_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @1553_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1554_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 248), sizeof v); (u32)v; });  // @1555_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[145]);  // @1556_53d230
  ecx = edx = 0;  // @1557_53d230
  FL[2] = (eax & eax);  // @1558_53d230
  if (FL[2] == 0) goto L53e568;  // @1559_53d230
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; })) & 0xff);  // @1560_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1561_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @1562_53d230
  eax = (edx & 0xff);  // @1563_53d230
  PV[146] = (u32)(eax);  // @1564_53d230
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1565_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 352), sizeof v); (u32)v; });  // @1566_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[146]);  // @1567_53d230
  ecx = edx = 0;  // @1568_53d230
  FL[2] = (eax & eax);  // @1569_53d230
  if (FL[2] == 0) goto L53e545;  // @1570_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; });  // @1571_53d230
  goto L53e55c;  // @1572_53d230
  L53e545:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1574_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @1575_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1576_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @1577_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(6840316));  // @1578_53d230
  ecx = edx = 0;  // @1579_53d230
  L53e55c:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 548), sizeof v); (u32)v; });  // @1581_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 544), &v, sizeof v); }  // @1582_53d230
  L53e568:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 325), sizeof v); (u32)v; });  // @1584_53d230
  edx = (u32)(0);  // @1585_53d230
  PV[147] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; });  // @1586_53d230
  FL[2] = (ecx & ecx);  // @1587_53d230
  if (FL[2] != 0) edx = ecx;  // @1588_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1589_53d230
  PV[148] = (u32)(edx);  // @1590_53d230
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 576), &v, sizeof v); }  // @1591_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @1592_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1593_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @1594_53d230
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[148], PV[147]);  // @1595_53d230
  ecx = edx = 0;  // @1596_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @1597_53d230
  FL[2] = (eax & eax);  // @1598_53d230
  if (FL[2] != 0) goto L53e5e2;  // @1599_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1600_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @1601_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1602_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @1603_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(6840316));  // @1604_53d230
  ecx = edx = 0;  // @1605_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1606_53d230
  PV[149] = (u32)(eax);  // @1607_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 576), sizeof v); (u32)v; });  // @1608_53d230
  PV[150] = (u32)(eax);  // @1609_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6815), sizeof v); (u32)v; });  // @1610_53d230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1611_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 88), sizeof v); (u32)v; });  // @1612_53d230
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[150], PV[149]);  // @1613_53d230
  ecx = edx = 0;  // @1614_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @1615_53d230
  FL[2] = (eax & eax);  // @1616_53d230
  if (FL[2] == 0) goto L53e687;  // @1617_53d230
  L53e5e2:;
  ecx = (u32)(EBP - 388);  // @1619_53d230
  eax = ext_4de7a0_thiscall1(ecx);  // @1620_53d230
    // @1621_53d230
  edx = (u32)(EBP - 208);  // @1622_53d230
  ecx = (u32)(EBP - 388);  // @1623_53d230
  eax = ext_4de040_fastcall3(ecx, edx, (u32)(0));  // @1624_53d230
  ecx = edx = 0;  // @1625_53d230
  PV[151] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @1626_53d230
  eax = (u32)(EBP - 196);  // @1627_53d230
  ecx = esi;  // @1628_53d230
  PV[152] = (u32)(eax);  // @1629_53d230
  eax = (u32)(EBP - 388);  // @1630_53d230
  PV[153] = (u32)(eax);  // @1631_53d230
  eax = ext_4db3b0_thiscall1(ecx);  // @1632_53d230
  ecx = edx = 0;  // @1633_53d230
  ecx = eax;  // @1634_53d230
  eax = ext_43ec00_thiscall7(ecx, PV[153], PV[152], PV[151], (u32)(0), (u32)(0), (u32)(0));  // @1635_53d230
  ecx = edx = 0;  // @1636_53d230
  edx = eax;  // @1637_53d230
  FL[2] = (edx & edx);  // @1638_53d230
  if (FL[2] == 0) goto L53e687;  // @1639_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1640_53d230
  PV[154] = (u32)(edx);  // @1641_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @1642_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1643_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 96), sizeof v); (u32)v; });  // @1644_53d230
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[154]);  // @1645_53d230
  ecx = edx = 0;  // @1646_53d230
  esi = eax;  // @1647_53d230
  FL[2] = (esi & esi);  // @1648_53d230
  if (FL[2] == 0) goto L53e687;  // @1649_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1650_53d230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1651_53d230
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 448), sizeof v); (u32)v; });  // @1652_53d230
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6958240), (u32)(1477));  // @1653_53d230
  ecx = edx = 0;  // @1654_53d230
  __asm__ volatile("fsubs %0" :: "m"(*(float *)(u32)(6792876)) : "st");  // @1655_53d230
  __asm__ volatile("fmuls %0" :: "m"(*(float *)(u32)(6860564)) : "st");  // @1656_53d230
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 576)) :: "st");  // @1657_53d230
  { float f_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 576) + 0), 4); v; })); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @1658_53d230
  eax = ecx;  // @1659_53d230
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 100), sizeof v); (u32)v; }));  // @1660_53d230
  FL[3] = eax;  // @1661_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @1662_53d230
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @1663_53d230
  L53e687:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 317), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 317), &v, sizeof v); }  // @1665_53d230
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 317), sizeof v); (u32)v; });  // @1666_53d230
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1667_53d230
  L53e693:;
  eax = (u32)(ecx + 64);  // @1669_53d230
  edi = (edi + (u32)(330));  // @1670_53d230
  FL[3] = edi;  // @1671_53d230
  FL[0] = edi; FL[1] = eax;  // @1672_53d230
  if (FL[0] == FL[1]) goto L53e6a4;  // @1673_53d230
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1674_53d230
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @1675_53d230
  L53e6a4:;
  ext_633654(G(u32, 0x6f5630));  // @1677_53d230
  return eax;  // @1678_53d230
}
PCREG(53d230, lifted_53d230);

