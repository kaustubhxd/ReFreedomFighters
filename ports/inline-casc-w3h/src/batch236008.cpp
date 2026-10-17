// batch236008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" double VECTORCALL ext_634d70_dbl(double) __asm__("ext_634d70");
extern "C" double VECTORCALL ext_634d76_dbl(double) __asm__("ext_634d76");
extern "C" double VECTORCALL ext_634d7c_dbl(double) __asm__("ext_634d7c");
extern "C" double VECTORCALL ext_634dbe_dbl(double) __asm__("ext_634dbe");
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4e0830_fastcall2(u32, u32) __asm__("ext_4e0830");
extern "C" u32 STDCALL ext_5941d0_stdcall7(u32, u32, u32, u32, u32, u32, u32) __asm__("ext_5941d0");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_595800(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; });  // @0_595800
  X0[1] = 0;  // @1_595800
  X0[2] = 0;  // @2_595800
  X0[3] = 0;  // @3_595800
  edi = ecx;  // @4_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_595800
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @6_595800
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; }))))))) goto L596663;  // @7_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @8_595800
  X0[1] = 0;  // @9_595800
  X0[2] = 0;  // @10_595800
  X0[3] = 0;  // @11_595800
  X1[0] = 0;  // @12_595800
  X1[1] = 0;  // @13_595800
  X1[2] = 0;  // @14_595800
  X1[3] = 0;  // @15_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @16_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @17_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59588e;  // @18_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @19_595800
  X0[1] = 0;  // @20_595800
  X0[2] = 0;  // @21_595800
  X0[3] = 0;  // @22_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @23_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @24_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59588e;  // @25_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @27_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @28_595800
  ecx = edx = 0;  // @29_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_595800
  PV[0] = (u32)(edx);  // @31_595800
  PV[1] = (u32)(eax);  // @32_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[1], PV[0], (u32)(6998696));  // @34_595800
  ecx = edx = 0;  // @35_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_595800
  L59588e:;
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @38_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3803) + 0), 4); v; });  // @39_595800
  X1[1] = 0;  // @40_595800
  X1[2] = 0;  // @41_595800
  X1[3] = 0;  // @42_595800
  if (FL[2] == 0) goto L5958aa;  // @43_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @44_595800
  L5958aa:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @46_595800
  X2[1] = 0;  // @47_595800
  X2[2] = 0;  // @48_595800
  X2[3] = 0;  // @49_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @50_595800
  X3[1] = 0;  // @51_595800
  X3[2] = 0;  // @52_595800
  X3[3] = 0;  // @53_595800
  if (((!(U2F(X1[0]) >= U2F(X2[0]))) || (!((U2F(X1[0]) < U2F(X2[0])) || (U2F(X1[0]) > U2F(X2[0])))))) goto L5958dd;  // @54_595800
  X0[0] = X1[0];  // @55_595800
  X0[1] = X1[1];  // @56_595800
  X0[2] = X1[2];  // @57_595800
  X0[3] = X1[3];  // @58_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @59_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })));  // @60_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @61_595800
  __builtin_memcpy((void *)((u32)(edi + 3799) + 0), &X0[0], 4);  // @62_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_595800
  L5958dd:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @65_595800
  X2[1] = 0;  // @66_595800
  X2[2] = 0;  // @67_595800
  X2[3] = 0;  // @68_595800
  X0[0] = X1[0];  // @69_595800
  X0[1] = X1[1];  // @70_595800
  X0[2] = X1[2];  // @71_595800
  X0[3] = X1[3];  // @72_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @73_595800
  if (((!(U2F(X2[0]) >= U2F(X0[0]))) || (!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))))) goto L59590a;  // @74_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @75_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 72) + 0), 4); v; })));  // @76_595800
  X2[0] = F2U(U2F(X2[0]) - U2F(X1[0]));  // @77_595800
  __builtin_memcpy((void *)((u32)(edi + 3799) + 0), &X2[0], 4);  // @78_595800
  L59590a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @80_595800
  ecx = (u32)((EBP - 264) + 104);  // @81_595800
  PV[2] = (u32)(ecx);  // @82_595800
  ecx = (u32)((EBP - 268) + 192);  // @83_595800
  PV[3] = (u32)(ecx);  // @84_595800
  ecx = edi;  // @85_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 128)))(ecx, PV[3], PV[2]);  // @86_595800
  ecx = edx = 0;  // @87_595800
  esi = (u32)(edi + 3763);  // @88_595800
  PV[4] = (u32)(esi);  // @89_595800
  edx = (u32)((EBP - 268) + 108);  // @90_595800
  ecx = (u32)((EBP - 268) + 180);  // @91_595800
  eax = ext_43e920_fastcall3(ecx, edx, PV[4]);  // @92_595800
  ecx = edx = 0;  // @93_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @94_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @95_595800
  X0[1] = 0;  // @96_595800
  X0[2] = 0;  // @97_595800
  X0[3] = 0;  // @98_595800
  PV[5] = (u32)(ecx);  // @99_595800
  ecx = (u32)((EBP - 268) + 180);  // @100_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @101_595800
  PV[6] = X0[0];  // @102_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[6]);  // @103_595800
    // @104_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @105_595800
  PV[7] = (u32)(ecx);  // @106_595800
  ecx = (u32)((EBP - 268) + 180);  // @107_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @108_595800
  X0[1] = 0;  // @109_595800
  X0[2] = 0;  // @110_595800
  X0[3] = 0;  // @111_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @112_595800
  PV[8] = X0[0];  // @113_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[8]);  // @114_595800
    // @115_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @116_595800
  ecx = (u32)(edi + 3775);  // @117_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @118_595800
  X1[1] = 0;  // @119_595800
  X1[2] = 0;  // @120_595800
  X1[3] = 0;  // @121_595800
  PV[9] = (u32)(ecx);  // @122_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @123_595800
  X0[1] = 0;  // @124_595800
  X0[2] = 0;  // @125_595800
  X0[3] = 0;  // @126_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818408) + 0), 4); v; })));  // @127_595800
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @128_595800
  PV[10] = X1[0];  // @129_595800
  eax = ext_4e0d00_thiscall2(ecx, PV[10]);  // @130_595800
    // @131_595800
  edx = (u32)((EBP - 264) + 176);  // @132_595800
  ecx = (u32)(edi + 3775);  // @133_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @134_595800
  ecx = edx = 0;  // @135_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 104) + 0), 4); v; });  // @136_595800
  X0[1] = 0;  // @137_595800
  X0[2] = 0;  // @138_595800
  X0[3] = 0;  // @139_595800
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @140_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @141_595800
  X0[1] = 0;  // @142_595800
  X0[2] = 0;  // @143_595800
  X0[3] = 0;  // @144_595800
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @145_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 112) + 0), 4); v; });  // @146_595800
  X0[1] = 0;  // @147_595800
  X0[2] = 0;  // @148_595800
  X0[3] = 0;  // @149_595800
  __builtin_memcpy((void *)((u32)(esi + 8) + 0), &X0[0], 4);  // @150_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3775) + 0), 4); v; });  // @151_595800
  X2[1] = 0;  // @152_595800
  X2[2] = 0;  // @153_595800
  X2[3] = 0;  // @154_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @155_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 52), &v, sizeof v); }  // @156_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3783) + 0), 4); v; });  // @157_595800
  X1[1] = 0;  // @158_595800
  X1[2] = 0;  // @159_595800
  X1[3] = 0;  // @160_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799768) + 0), 4); v; })));  // @161_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 48) + 0), &X2[0], 4);  // @162_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @163_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 56) + 0), &X1[0], 4);  // @164_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @165_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })));  // @166_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @167_595800
  { double a_ = (double)U2F(X2[0]), b_ = (double)U2F(X2[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @168_595800
  { double r_ = ext_634d7c_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @169_595800
  ecx = edx = 0;  // @170_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 188) + 0), 4); v; });  // @171_595800
  X1[1] = 0;  // @172_595800
  X1[2] = 0;  // @173_595800
  X1[3] = 0;  // @174_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @175_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 44) + 0), &X0[0], 4);  // @176_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 108) + 0), 4); v; });  // @177_595800
  X0[1] = 0;  // @178_595800
  X0[2] = 0;  // @179_595800
  X0[3] = 0;  // @180_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818436) + 0), 4); v; })));  // @181_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 108) + 0), &X0[0], 4);  // @182_595800
  if (((!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) || (!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))))) goto L595a69;  // @183_595800
  X0[0] = 0;  // @184_595800
  X0[1] = 0;  // @185_595800
  X0[2] = 0;  // @186_595800
  X0[3] = 0;  // @187_595800
  X1[0] = X0[0];  // @188_595800
  X1[1] = X0[1];  // @189_595800
  X1[2] = X0[2];  // @190_595800
  X1[3] = X0[3];  // @191_595800
  goto L595a92;  // @192_595800
  L595a69:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795052) + 0), 4); v; });  // @194_595800
  X0[1] = 0;  // @195_595800
  X0[2] = 0;  // @196_595800
  X0[3] = 0;  // @197_595800
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L595a80;  // @198_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; });  // @199_595800
  X1[1] = 0;  // @200_595800
  X1[2] = 0;  // @201_595800
  X1[3] = 0;  // @202_595800
  goto L595a8f;  // @203_595800
  L595a80:;
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @205_595800
  { double r_ = ext_634dbe_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @206_595800
  ecx = edx = 0;  // @207_595800
  X1[0] = 0;  // @208_595800
  X1[1] = 0;  // @209_595800
  X1[2] = 0;  // @210_595800
  X1[3] = 0;  // @211_595800
  X1[0] = F2U((float)U2D(X0[0], X0[1]));  // @212_595800
  L595a8f:;
  X0[0] = 0;  // @214_595800
  X0[1] = 0;  // @215_595800
  X0[2] = 0;  // @216_595800
  X0[3] = 0;  // @217_595800
  L595a92:;
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860536) + 0), 4); v; });  // @219_595800
  X2[1] = 0;  // @220_595800
  X2[2] = 0;  // @221_595800
  X2[3] = 0;  // @222_595800
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 212) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 212) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 212) + 0), 4); v; }))))))) goto L595aae;  // @223_595800
  X0[0] = X2[0];  // @224_595800
  X0[1] = X2[1];  // @225_595800
  X0[2] = X2[2];  // @226_595800
  X0[3] = X2[3];  // @227_595800
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @228_595800
  X1[0] = X0[0];  // @229_595800
  X1[1] = X0[1];  // @230_595800
  X1[2] = X0[2];  // @231_595800
  X1[3] = X0[3];  // @232_595800
  L595aae:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @234_595800
  eax = (u32)(6);  // @235_595800
  FL[0] = esi; FL[1] = eax;  // @236_595800
  if ((s32)FL[0] < (s32)FL[1]) esi = eax;  // @237_595800
  ecx = 0;  // @238_595800
  FL[3] = ecx;  // @239_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 32), &v, sizeof v); }  // @240_595800
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @241_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @242_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @243_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @244_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @245_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @246_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(X2[0]));  // @247_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; })));  // @248_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @249_595800
  FL[0] = eax; FL[1] = esi;  // @250_595800
  if ((s32)FL[0] < (s32)FL[1]) ecx = eax;  // @251_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @252_595800
  ecx = (u32)((EBP - 264) + 224);  // @253_595800
  eax = ext_4de7a0_thiscall1(ecx);  // @254_595800
    // @255_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @256_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @257_595800
  X3[1] = 0;  // @258_595800
  X3[2] = 0;  // @259_595800
  X3[3] = 0;  // @260_595800
  X3[0] = F2U(U2F(X3[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802752) + 0), 4); v; })));  // @261_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 164), &v, sizeof v); }  // @262_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 168), &v, sizeof v); }  // @263_595800
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)((EBP - 264) + 172), &v, sizeof v); }  // @264_595800
  X3[0] = F2U(U2F(X3[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; })));  // @265_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X3[0], 4);  // @266_595800
  if (FL[2] == 0) goto L595b4b;  // @267_595800
  X3[0] = F2U(U2F(X3[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799780) + 0), 4); v; })));  // @268_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X3[0], 4);  // @269_595800
  L595b4b:;
  eax = 0;  // @271_595800
  FL[3] = eax;  // @272_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @273_595800
  FL[2] = (esi & esi);  // @274_595800
  if ((s32)FL[2] <= 0) goto L595ec7;  // @275_595800
  esi = (u32)(edi + 3423);  // @276_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @277_595800
  L595b63:;
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @279_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @280_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @281_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @282_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @283_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @284_595800
  X1[0] = eax; X1[1] = X1[2] = X1[3] = 0;  // @285_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @286_595800
  X1[0] = F2U((float)(s32)X1[0]);  // @287_595800
  X1[1] = F2U((float)(s32)X1[1]);  // @288_595800
  X1[2] = F2U((float)(s32)X1[2]);  // @289_595800
  X1[3] = F2U((float)(s32)X1[3]);  // @290_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @291_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(X1[0]));  // @292_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @293_595800
  X1[1] = 0;  // @294_595800
  X1[2] = 0;  // @295_595800
  X1[3] = 0;  // @296_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @297_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X2[0], a_); SD(&X2[2], b_); }  // @298_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @299_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X2[0], 4);  // @300_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 4), &X2[1], 4);  // @301_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X0[0], 4);  // @302_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 4), &X0[1], 4);  // @303_595800
  X0[0] = X2[0];  // @304_595800
  X0[1] = X2[1];  // @305_595800
  X0[2] = X2[2];  // @306_595800
  X0[3] = X2[3];  // @307_595800
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @308_595800
  ecx = edx = 0;  // @309_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; })));  // @310_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @311_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 36) + 0), &X0[0], 4);  // @312_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @313_595800
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @314_595800
  ecx = edx = 0;  // @315_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; })));  // @316_595800
  edx = (u32)((EBP - 264) + 104);  // @317_595800
  ecx = (u32)((EBP - 264) + 116);  // @318_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 120), &v, sizeof v); }  // @319_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @320_595800
  X1[1] = 0;  // @321_595800
  X1[2] = 0;  // @322_595800
  X1[3] = 0;  // @323_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 116) + 0), &X1[0], 4);  // @324_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @325_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 124) + 0), &X0[0], 4);  // @326_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @327_595800
  ecx = edx = 0;  // @328_595800
  edx = (u32)((EBP - 264) + 48);  // @329_595800
  ecx = (u32)((EBP - 264) + 116);  // @330_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @331_595800
  ecx = edx = 0;  // @332_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3787), sizeof v); (u32)v; });  // @333_595800
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 15), &v, sizeof v); }  // @334_595800
  FL[2] = (ecx & ecx);  // @335_595800
  if (FL[2] == 0) goto L595c32;  // @336_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @337_595800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @338_595800
  if (FL[0] != FL[1]) goto L595c32;  // @339_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @340_595800
  edx = (u32)((EBP - 264) + 116);  // @341_595800
  PV[11] = (u32)(edx);  // @342_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 544), sizeof v); (u32)v; });  // @343_595800
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[11]);  // @344_595800
  ecx = edx = 0;  // @345_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @346_595800
  if (FL[2] == 0) goto L595dba;  // @347_595800
  L595c32:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @349_595800
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @350_595800
  if (FL[0] != FL[1]) goto L595d4a;  // @351_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @352_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1052), sizeof v); (u32)v; });  // @353_595800
  edx = (u32)(ecx + 1056);  // @354_595800
  eax = (eax + (u32)(264));  // @355_595800
  FL[3] = eax;  // @356_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 36), &v, sizeof v); }  // @357_595800
  eax = (u32)(ecx + eax*4);  // @358_595800
  FL[0] = edx; FL[1] = eax;  // @359_595800
  if (FL[0] == FL[1]) goto L595d4a;  // @360_595800
  L595c70:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @362_595800
  FL[2] = (esi & esi);  // @363_595800
  if (FL[2] == 0) goto L595d29;  // @364_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @365_595800
  ecx = esi;  // @366_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @367_595800
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1051586));  // @368_595800
  ecx = edx = 0;  // @369_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @370_595800
  if (FL[2] != 0) goto L595d1f;  // @371_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @372_595800
  edx = (u32)((EBP - 264) + 116);  // @373_595800
  eax = (eax + (u32)(36));  // @374_595800
  FL[3] = eax;  // @375_595800
  ecx = (u32)((EBP - 264) + 128);  // @376_595800
  PV[12] = (u32)(eax);  // @377_595800
  eax = ext_43e920_fastcall3(ecx, edx, PV[12]);  // @378_595800
  ecx = edx = 0;  // @379_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @380_595800
  ecx = (u32)((EBP - 264) + 128);  // @381_595800
  eax = ext_441a60_fastcall2(ecx, edx);  // @382_595800
  ecx = edx = 0;  // @383_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @384_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 128) + 0), 4); v; });  // @385_595800
  X1[1] = 0;  // @386_595800
  X1[2] = 0;  // @387_595800
  X1[3] = 0;  // @388_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 0), 4); v; }); X2[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802768) + 4), 4); v; }); X2[2] = X2[3] = 0;  // @389_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @390_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @391_595800
  X0[1] = 0;  // @392_595800
  X0[2] = 0;  // @393_595800
  X0[3] = 0;  // @394_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @395_595800
  X1[0] = X1[0] & X2[0];  // @396_595800
  X1[1] = X1[1] & X2[1];  // @397_595800
  X1[2] = X1[2] & X2[2];  // @398_595800
  X1[3] = X1[3] & X2[3];  // @399_595800
  if (((!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) || (!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L595d1f;  // @400_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 132) + 0), 4); v; });  // @401_595800
  X1[1] = 0;  // @402_595800
  X1[2] = 0;  // @403_595800
  X1[3] = 0;  // @404_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @405_595800
  X0[1] = 0;  // @406_595800
  X0[2] = 0;  // @407_595800
  X0[3] = 0;  // @408_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @409_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @410_595800
  X1[0] = X1[0] & X2[0];  // @411_595800
  X1[1] = X1[1] & X2[1];  // @412_595800
  X1[2] = X1[2] & X2[2];  // @413_595800
  X1[3] = X1[3] & X2[3];  // @414_595800
  if (((!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) || (!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L595d1f;  // @415_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 136) + 0), 4); v; });  // @416_595800
  X1[1] = 0;  // @417_595800
  X1[2] = 0;  // @418_595800
  X1[3] = 0;  // @419_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @420_595800
  X0[1] = 0;  // @421_595800
  X0[2] = 0;  // @422_595800
  X0[3] = 0;  // @423_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @424_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @425_595800
  X1[0] = X1[0] & X2[0];  // @426_595800
  X1[1] = X1[1] & X2[1];  // @427_595800
  X1[2] = X1[2] & X2[2];  // @428_595800
  X1[3] = X1[3] & X2[3];  // @429_595800
  if ((!(!(U2D(X0[0], X0[1]) >= U2D(X1[0], X1[1]))) && !(!((U2D(X0[0], X0[1]) < U2D(X1[0], X1[1])) || (U2D(X0[0], X0[1]) > U2D(X1[0], X1[1])))))) goto L595db6;  // @430_595800
  L595d1f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @432_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 36), sizeof v); (u32)v; });  // @433_595800
  L595d29:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1052), sizeof v); (u32)v; });  // @435_595800
  edx = (edx + (u32)(4));  // @436_595800
  FL[3] = edx;  // @437_595800
  eax = (eax + (u32)(264));  // @438_595800
  FL[3] = eax;  // @439_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 36), &v, sizeof v); }  // @440_595800
  eax = (u32)(ecx + eax*4);  // @441_595800
  FL[0] = edx; FL[1] = eax;  // @442_595800
  if (FL[0] != FL[1]) goto L595c70;  // @443_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @444_595800
  L595d4a:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @446_595800
  X1[1] = 0;  // @447_595800
  X1[2] = 0;  // @448_595800
  X1[3] = 0;  // @449_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @450_595800
  X0[1] = 0;  // @451_595800
  X0[2] = 0;  // @452_595800
  X0[3] = 0;  // @453_595800
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L595d75;  // @454_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @455_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @456_595800
  X0[1] = 0;  // @457_595800
  X0[2] = 0;  // @458_595800
  X0[3] = 0;  // @459_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @460_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @461_595800
  L595d71:;
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @463_595800
  L595d75:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3816) + 0), 4); v; });  // @465_595800
  X0[1] = 0;  // @466_595800
  X0[2] = 0;  // @467_595800
  X0[3] = 0;  // @468_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @469_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @470_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L595e53;  // @471_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @472_595800
  if (FL[0] == FL[1]) goto L595e14;  // @473_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 15), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @474_595800
  if (FL[0] == FL[1]) goto L595dd6;  // @475_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; });  // @476_595800
  edx = (u32)(65280);  // @477_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; }); FL[1] = eax;  // @478_595800
  eax = (u32)(16777215);  // @479_595800
  if (FL[0] == FL[1]) edx = eax;  // @480_595800
  goto L595ddb;  // @481_595800
  L595db6:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @483_595800
  L595dba:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @485_595800
  X0[1] = 0;  // @486_595800
  X0[2] = 0;  // @487_595800
  X0[3] = 0;  // @488_595800
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 15), &v, sizeof v); }  // @489_595800
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; }))))))) goto L595d75;  // @490_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799784) + 0), 4); v; })));  // @491_595800
  goto L595d71;  // @492_595800
  L595dd6:;
  edx = (u32)(16711680);  // @494_595800
  L595ddb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @496_595800
  PV[13] = (u32)(edx);  // @497_595800
  edx = (u32)((EBP - 272) + 172);  // @498_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @499_595800
  PV[14] = (u32)(edx);  // @500_595800
  edx = (u32)((EBP - 276) + 128);  // @501_595800
  PV[15] = (u32)(edx);  // @502_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @503_595800
  edx = (u32)((EBP - 280) + 240);  // @504_595800
  PV[16] = (u32)(edx);  // @505_595800
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; });  // @506_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @507_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 572)))(ecx, PV[17], PV[16], PV[15], PV[14], PV[13], (u32)(0));  // @508_595800
  ecx = edx = 0;  // @509_595800
  goto L595e7b;  // @510_595800
  L595e14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @512_595800
  edx = (u32)((EBP - 264) + 164);  // @513_595800
  PV[18] = (u32)(edx);  // @514_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @515_595800
  edx = (u32)((EBP - 276) + 128);  // @516_595800
  PV[19] = (u32)(edx);  // @517_595800
  edx = (u32)((EBP - 280) + 240);  // @518_595800
  PV[20] = (u32)(edx);  // @519_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @520_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @521_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 568), sizeof v); (u32)v; });  // @522_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(eax))(ecx, PV[20], PV[19], PV[18], (u32)(16711680), (u32)(0));  // @523_595800
  ecx = edx = 0;  // @524_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi - 17), &v, sizeof v); }  // @525_595800
  goto L595e7b;  // @526_595800
  L595e53:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 17), sizeof v); (u32)v; });  // @528_595800
  FL[2] = (edx & edx);  // @529_595800
  if (FL[2] == 0) goto L595e7b;  // @530_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @531_595800
  PV[21] = (u32)(edx);  // @532_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @533_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @534_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @535_595800
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 576)))(ecx, PV[21]);  // @536_595800
  ecx = edx = 0;  // @537_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi - 17), &v, sizeof v); }  // @538_595800
  L595e7b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 116) + 0), 4); v; });  // @540_595800
  X0[1] = 0;  // @541_595800
  X0[2] = 0;  // @542_595800
  X0[3] = 0;  // @543_595800
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 15), sizeof v); (u32)v; })) & 0xff);  // @544_595800
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @545_595800
  X3[1] = 0;  // @546_595800
  X3[2] = 0;  // @547_595800
  X3[3] = 0;  // @548_595800
  __builtin_memcpy((void *)((u32)(esi - 13) + 0), &X0[0], 4);  // @549_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 120) + 0), 4); v; });  // @550_595800
  X0[1] = 0;  // @551_595800
  X0[2] = 0;  // @552_595800
  X0[3] = 0;  // @553_595800
  __builtin_memcpy((void *)((u32)(esi - 9) + 0), &X0[0], 4);  // @554_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 124) + 0), 4); v; });  // @555_595800
  X0[1] = 0;  // @556_595800
  X0[2] = 0;  // @557_595800
  X0[3] = 0;  // @558_595800
  __builtin_memcpy((void *)((u32)(esi - 5) + 0), &X0[0], 4);  // @559_595800
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi - 1), &v, sizeof v); }  // @560_595800
  esi = (esi + (u32)(21));  // @561_595800
  FL[3] = esi;  // @562_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @563_595800
  eax = (eax + 1);  // @564_595800
  FL[3] = eax;  // @565_595800
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @566_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @567_595800
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @568_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L595b63;  // @569_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @570_595800
  L595ec7:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edi + 3807), &v, sizeof v); }  // @572_595800
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; });  // @573_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3807), sizeof v); (u32)v; }); FL[1] = esi;  // @574_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L595edf;  // @575_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 3807), &v, sizeof v); }  // @576_595800
  L595edf:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3816) + 0), 4); v; });  // @578_595800
  X0[1] = 0;  // @579_595800
  X0[2] = 0;  // @580_595800
  X0[3] = 0;  // @581_595800
  X1[0] = 0;  // @582_595800
  X1[1] = 0;  // @583_595800
  X1[2] = 0;  // @584_595800
  X1[3] = 0;  // @585_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @586_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @587_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59605a;  // @588_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @589_595800
  X0[1] = 0;  // @590_595800
  X0[2] = 0;  // @591_595800
  X0[3] = 0;  // @592_595800
  edx = (u32)((EBP - 264) + 104);  // @593_595800
  ecx = (u32)((EBP - 264) + 128);  // @594_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @595_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @596_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 136), &v, sizeof v); }  // @597_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @598_595800
  ecx = edx = 0;  // @599_595800
  esi = (u32)(1);  // @600_595800
  L595f33:;
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @602_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @603_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @604_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @605_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @606_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(X0[0]));  // @607_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6806040) + 0), 4); v; })));  // @608_595800
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818416) + 0), 4); v; })));  // @609_595800
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @610_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X0[0], 4);  // @611_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 4), &X0[1], 4);  // @612_595800
  { double r_ = ext_634d70_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @613_595800
  ecx = edx = 0;  // @614_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @615_595800
  X1[1] = 0;  // @616_595800
  X1[2] = 0;  // @617_595800
  X1[3] = 0;  // @618_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @619_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @620_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @621_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X0[0], 4);  // @622_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @623_595800
  { double r_ = ext_634d76_dbl(U2D(X0[0], X0[1])); SD(&X0[0], r_); X0[2] = X0[3] = 0; }  // @624_595800
  ecx = edx = 0;  // @625_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @626_595800
  X1[1] = 0;  // @627_595800
  X1[2] = 0;  // @628_595800
  X1[3] = 0;  // @629_595800
  edx = (u32)((EBP - 264) + 104);  // @630_595800
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @631_595800
  ecx = (u32)((EBP - 264) + 88);  // @632_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 92), &v, sizeof v); }  // @633_595800
  SD(&X0[0], U2D(X0[0], X0[1]) * U2D(X1[0], X1[1]));  // @634_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @635_595800
  X1[1] = 0;  // @636_595800
  X1[2] = 0;  // @637_595800
  X1[3] = 0;  // @638_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X1[0], 4);  // @639_595800
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @640_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 96) + 0), &X0[0], 4);  // @641_595800
  eax = ext_441940_fastcall2(ecx, edx);  // @642_595800
  ecx = edx = 0;  // @643_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422624), sizeof v); (u32)v; });  // @644_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @645_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax*4 + 7422628), sizeof v); (u32)v; });  // @646_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @647_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @648_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @649_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @650_595800
  FL[2] = (edx & edx);  // @651_595800
  if (FL[2] != 0) goto L596008;  // @652_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 536), sizeof v); (u32)v; });  // @653_595800
  edx = (u32)((EBP - 268) + 92);  // @654_595800
  PV[22] = (u32)(edx);  // @655_595800
  edx = (u32)((EBP - 272) + 136);  // @656_595800
  PV[23] = (u32)(edx);  // @657_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[23], PV[22], (u32)(16711680));  // @658_595800
  ecx = edx = 0;  // @659_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @660_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx*4 + 7422628), &v, sizeof v); }  // @661_595800
  goto L596020;  // @662_595800
  L596008:;
  edi = (u32)((EBP - 264) + 92);  // @664_595800
  PV[24] = (u32)(edi);  // @665_595800
  edi = (u32)((EBP - 268) + 136);  // @666_595800
  PV[25] = (u32)(edi);  // @667_595800
  PV[26] = (u32)(edx);  // @668_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 540)))(ecx, PV[26], PV[25], PV[24]);  // @669_595800
  ecx = edx = 0;  // @670_595800
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 24), sizeof v); (u32)v; });  // @671_595800
  L596020:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422624), sizeof v); (u32)v; });  // @673_595800
  ecx = (u32)(10);  // @674_595800
  eax = (eax + 1);  // @675_595800
  FL[3] = eax;  // @676_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; });  // @677_595800
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 4), 4); v; });  // @678_595800
  X0[2] = 0;  // @679_595800
  X0[3] = 0;  // @680_595800
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @681_595800
  esi = (esi + 1);  // @682_595800
  FL[3] = esi;  // @683_595800
  { s32 d_ = (s32)(ecx); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @684_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 96), sizeof v); (u32)v; });  // @685_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(7422624), &v, sizeof v); }  // @686_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 0), &X0[0], 4);  // @687_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 128) + 4), &X0[1], 4);  // @688_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 136), &v, sizeof v); }  // @689_595800
  FL[0] = esi; FL[1] = ecx;  // @690_595800
  if ((s32)FL[0] <= (s32)FL[1]) goto L595f33;  // @691_595800
  X1[0] = 0;  // @692_595800
  X1[1] = 0;  // @693_595800
  X1[2] = 0;  // @694_595800
  X1[3] = 0;  // @695_595800
  L59605a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @697_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @698_595800
  X0[1] = 0;  // @699_595800
  X0[2] = 0;  // @700_595800
  X0[3] = 0;  // @701_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @702_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @703_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L5960ab;  // @704_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @705_595800
  X0[1] = 0;  // @706_595800
  X0[2] = 0;  // @707_595800
  X0[3] = 0;  // @708_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @709_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @710_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L5960ab;  // @711_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @712_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @713_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @714_595800
  ecx = edx = 0;  // @715_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @716_595800
  PV[27] = (u32)(edx);  // @717_595800
  PV[28] = (u32)(eax);  // @718_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @719_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[28], PV[27], (u32)(6998704));  // @720_595800
  ecx = edx = 0;  // @721_595800
  L5960ab:;
  eax = 0;  // @723_595800
  FL[3] = eax;  // @724_595800
  edx = (u32)((EBP - 264) + 104);  // @725_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @726_595800
  ecx = (u32)((EBP - 264) + 60);  // @727_595800
  eax = (u32)((EBP - 264) + 48);  // @728_595800
  PV[29] = (u32)(eax);  // @729_595800
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[29]);  // @730_595800
  ecx = edx = 0;  // @731_595800
  eax = (u32)(edi + 2586);  // @732_595800
  esi = eax;  // @733_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @734_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @735_595800
  eax = (u32)(eax + eax*2);  // @736_595800
  eax = (eax << (u32)(4));  // @737_595800
  FL[3] = eax;  // @738_595800
  eax = (eax + (u32)(2586));  // @739_595800
  FL[3] = eax;  // @740_595800
  eax = (eax + edi);  // @741_595800
  FL[3] = eax;  // @742_595800
  FL[0] = esi; FL[1] = eax;  // @743_595800
  if (FL[0] == FL[1]) goto L5961cc;  // @744_595800
  L5960f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @746_595800
  edx = (u32)(esi + 32);  // @747_595800
  PV[30] = (u32)(edx);  // @748_595800
  edx = (u32)((EBP - 268) + 132);  // @749_595800
  PV[31] = (u32)(edx);  // @750_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @751_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 1404)))(ecx, PV[31], PV[30]);  // @752_595800
  ecx = edx = 0;  // @753_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 20) + 0), 4); v; });  // @754_595800
  X0[1] = 0;  // @755_595800
  X0[2] = 0;  // @756_595800
  X0[3] = 0;  // @757_595800
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })));  // @758_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @759_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @760_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @761_595800
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @762_595800
  if ((s32)FL[0] >= (s32)FL[1]) goto L59617a;  // @763_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; });  // @764_595800
  X0[1] = 0;  // @765_595800
  X0[2] = 0;  // @766_595800
  X0[3] = 0;  // @767_595800
  eax = (u32)((EBP - 264) + 188);  // @768_595800
  PV[32] = (u32)(ecx);  // @769_595800
  PV[33] = X0[0];  // @770_595800
  ecx = edi;  // @771_595800
  PV[34] = (u32)(eax);  // @772_595800
  eax = (u32)((EBP - 272) + 112);  // @773_595800
  PV[35] = (u32)(eax);  // @774_595800
  eax = (u32)((EBP - 276) + 72);  // @775_595800
  PV[36] = (u32)(eax);  // @776_595800
  eax = (u32)(esi + 32);  // @777_595800
  PV[37] = (u32)(eax);  // @778_595800
  eax = (u32)((EBP - 284) + 148);  // @779_595800
  PV[38] = (u32)(eax);  // @780_595800
  PV[39] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @781_595800
  eax = ext_5941d0_stdcall7(PV[39], PV[38], PV[37], PV[36], PV[35], PV[34], PV[33]);  // @782_595800
  ecx = edx = 0;  // @783_595800
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @784_595800
  if (FL[2] == 0) goto L59617a;  // @785_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @786_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @787_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @788_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @789_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @790_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @791_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @792_595800
  __builtin_memcpy((void *)((u32)(esi + 20) + 0), &X0[0], 4);  // @793_595800
  L59617a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; });  // @795_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 20), sizeof v); (u32)v; });  // @796_595800
  eax = (eax + ecx);  // @797_595800
  FL[3] = eax;  // @798_595800
  if ((s32)FL[3] >= 0) goto L59618c;  // @799_595800
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; }));  // @800_595800
  FL[3] = eax;  // @801_595800
  goto L596196;  // @802_595800
  L59618c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 32), sizeof v); (u32)v; });  // @804_595800
  FL[0] = eax; FL[1] = edx;  // @805_595800
  if ((s32)FL[0] < (s32)FL[1]) goto L596196;  // @806_595800
  eax = (eax - edx);  // @807_595800
  FL[3] = eax;  // @808_595800
  L596196:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @810_595800
  FL[2] = (ecx & ecx);  // @811_595800
  if ((s32)FL[2] >= 0) goto L5961a5;  // @812_595800
  FL[1] = ecx;  // @813_595800
  ecx = (0u - ecx);  // @814_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @815_595800
  goto L5961ae;  // @816_595800
  L5961a5:;
  eax = (eax | (u32)(4294967295));  // @818_595800
  FL[3] = eax;  // @819_595800
  eax = (eax - ecx);  // @820_595800
  FL[3] = eax;  // @821_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 20), &v, sizeof v); }  // @822_595800
  L5961ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @824_595800
  esi = (esi + (u32)(48));  // @825_595800
  FL[3] = esi;  // @826_595800
  eax = (u32)(eax + eax*2);  // @827_595800
  eax = (eax << (u32)(4));  // @828_595800
  FL[3] = eax;  // @829_595800
  eax = (eax + (u32)(2586));  // @830_595800
  FL[3] = eax;  // @831_595800
  eax = (eax + edi);  // @832_595800
  FL[3] = eax;  // @833_595800
  FL[0] = esi; FL[1] = eax;  // @834_595800
  if (FL[0] != FL[1]) goto L5960f0;  // @835_595800
  L5961cc:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @837_595800
  X1[0] = 0;  // @838_595800
  X1[1] = 0;  // @839_595800
  X1[2] = 0;  // @840_595800
  X1[3] = 0;  // @841_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @842_595800
  X0[1] = 0;  // @843_595800
  X0[2] = 0;  // @844_595800
  X0[3] = 0;  // @845_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @846_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @847_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59622b;  // @848_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @849_595800
  X0[1] = 0;  // @850_595800
  X0[2] = 0;  // @851_595800
  X0[3] = 0;  // @852_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @853_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @854_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59622b;  // @855_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @856_595800
  ecx = edx;  // @857_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @858_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @859_595800
  ecx = edx = 0;  // @860_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @861_595800
  PV[40] = (u32)(edx);  // @862_595800
  PV[41] = (u32)(eax);  // @863_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @864_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[41], PV[40], (u32)(6998704));  // @865_595800
  ecx = edx = 0;  // @866_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @867_595800
  X1[0] = 0;  // @868_595800
  X1[1] = 0;  // @869_595800
  X1[2] = 0;  // @870_595800
  X1[3] = 0;  // @871_595800
  L59622b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @873_595800
  X0[1] = 0;  // @874_595800
  X0[2] = 0;  // @875_595800
  X0[3] = 0;  // @876_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @877_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @878_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59627e;  // @879_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @880_595800
  X0[1] = 0;  // @881_595800
  X0[2] = 0;  // @882_595800
  X0[3] = 0;  // @883_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @884_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @885_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L59627e;  // @886_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @887_595800
  ecx = edx;  // @888_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @889_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601));  // @890_595800
  ecx = edx = 0;  // @891_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @892_595800
  PV[42] = (u32)(edx);  // @893_595800
  PV[43] = (u32)(eax);  // @894_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @895_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[43], PV[42], (u32)(6998712));  // @896_595800
  ecx = edx = 0;  // @897_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @898_595800
  L59627e:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3779) + 0), 4); v; });  // @900_595800
  X1[1] = 0;  // @901_595800
  X1[2] = 0;  // @902_595800
  X1[3] = 0;  // @903_595800
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3775) + 0), 4); v; });  // @904_595800
  X2[1] = 0;  // @905_595800
  X2[2] = 0;  // @906_595800
  X2[3] = 0;  // @907_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3783) + 0), 4); v; });  // @908_595800
  X0[1] = 0;  // @909_595800
  X0[2] = 0;  // @910_595800
  X0[3] = 0;  // @911_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; });  // @912_595800
  ecx = eax;  // @913_595800
  X2[0] = F2U(U2F(X2[0]) * U2F(X2[0]));  // @914_595800
  ecx = (ecx >> (u32)(1));  // @915_595800
  FL[3] = ecx;  // @916_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @917_595800
  ecx = (ecx & (u32)(4294967041));  // @918_595800
  FL[3] = ecx;  // @919_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 40), &v, sizeof v); }  // @920_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @921_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X1[0]));  // @922_595800
  X2[0] = F2U(U2F(X2[0]) + U2F(X0[0]));  // @923_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 88) + 0), &X2[0], 4);  // @924_595800
  FL[2] = (eax & (u32)(1024));  // @925_595800
  if (FL[2] == 0) goto L5962db;  // @926_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000612) + 0), 4); v; });  // @927_595800
  X1[1] = 0;  // @928_595800
  X1[2] = 0;  // @929_595800
  X1[3] = 0;  // @930_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 20) + 0), &X1[0], 4);  // @931_595800
  goto L5962e9;  // @932_595800
  L5962db:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000616) + 0), 4); v; });  // @934_595800
  X0[1] = 0;  // @935_595800
  X0[2] = 0;  // @936_595800
  X0[3] = 0;  // @937_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 20) + 0), &X0[0], 4);  // @938_595800
  L5962e9:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3795) + 0), 4); v; });  // @940_595800
  X0[1] = 0;  // @941_595800
  X0[2] = 0;  // @942_595800
  X0[3] = 0;  // @943_595800
  ecx = (u32)(edi + 2586);  // @944_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @945_595800
  X1[0] = X0[0];  // @946_595800
  X1[1] = X0[1];  // @947_595800
  X1[2] = X0[2];  // @948_595800
  X1[3] = X0[3];  // @949_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7000564) + 0), 4); v; })));  // @950_595800
  eax = (u32)(eax + eax*2);  // @951_595800
  eax = (eax << (u32)(4));  // @952_595800
  FL[3] = eax;  // @953_595800
  eax = (eax + (u32)(2586));  // @954_595800
  FL[3] = eax;  // @955_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @956_595800
  eax = (eax + edi);  // @957_595800
  FL[3] = eax;  // @958_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 44) + 0), &X1[0], 4);  // @959_595800
  FL[0] = ecx; FL[1] = eax;  // @960_595800
  if (FL[0] == FL[1]) goto L5965bd;  // @961_595800
  esi = (u32)(ecx + 12);  // @962_595800
  L596330:;
  edx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }) * (s32)(u32)(21));  // @964_595800
  ecx = (u32)(esi - 8);  // @965_595800
  edx = (edx + (u32)(3410));  // @966_595800
  FL[3] = edx;  // @967_595800
  edx = (edx + edi);  // @968_595800
  FL[3] = edx;  // @969_595800
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)((EBP - 264) + 28), &v, sizeof v); }  // @970_595800
  eax = ext_4e0830_fastcall2(ecx, edx);  // @971_595800
  ecx = edx = 0;  // @972_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @973_595800
  X0[1] = 0;  // @974_595800
  X0[2] = 0;  // @975_595800
  X0[3] = 0;  // @976_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @977_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @978_595800
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 264) + 24)) :: "st");  // @979_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; });  // @980_595800
  X1[1] = 0;  // @981_595800
  X1[2] = 0;  // @982_595800
  X1[3] = 0;  // @983_595800
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @984_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 64), sizeof v); (u32)v; });  // @985_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 32) + 0), &X1[0], 4);  // @986_595800
  eax = (eax - ecx);  // @987_595800
  FL[3] = eax;  // @988_595800
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @989_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @990_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @991_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @992_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @993_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @994_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 36) + 0), &X0[0], 4);  // @995_595800
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 44) + 0), 4); v; }))))))) goto L5963ae;  // @996_595800
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))))) goto L5963ae;  // @997_595800
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); FL[1] = (u32)(2);  // @998_595800
  if (FL[0] != FL[1]) goto L596594;  // @999_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1000_595800
  if (FL[0] != FL[1]) goto L596594;  // @1001_595800
  L5963ae:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 28), sizeof v); (u32)v; });  // @1003_595800
  ecx = (u32)(esi + 20);  // @1004_595800
  edx = (u32)((EBP - 264) + 104);  // @1005_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; });  // @1006_595800
  X0[1] = 0;  // @1007_595800
  X0[2] = 0;  // @1008_595800
  X0[3] = 0;  // @1009_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 72) + 0), &X0[0], 4);  // @1010_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @1011_595800
  X0[1] = 0;  // @1012_595800
  X0[2] = 0;  // @1013_595800
  X0[3] = 0;  // @1014_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 76) + 0), &X0[0], 4);  // @1015_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 8) + 0), 4); v; });  // @1016_595800
  X0[1] = 0;  // @1017_595800
  X0[2] = 0;  // @1018_595800
  X0[3] = 0;  // @1019_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 80) + 0), &X0[0], 4);  // @1020_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 3799) + 0), 4); v; });  // @1021_595800
  X0[1] = 0;  // @1022_595800
  X0[2] = 0;  // @1023_595800
  X0[3] = 0;  // @1024_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 28) + 0), &X0[0], 4);  // @1025_595800
  eax = ext_4e0830_fastcall2(ecx, edx);  // @1026_595800
  ecx = edx = 0;  // @1027_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 28) + 0), 4); v; });  // @1028_595800
  X1[1] = 0;  // @1029_595800
  X1[2] = 0;  // @1030_595800
  X1[3] = 0;  // @1031_595800
  eax = 0;  // @1032_595800
  FL[3] = eax;  // @1033_595800
  X1[0] = F2U(U2F(X1[0]) * U2F(X1[0]));  // @1034_595800
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 264) + 24)) :: "st");  // @1035_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; });  // @1036_595800
  X0[1] = 0;  // @1037_595800
  X0[2] = 0;  // @1038_595800
  X0[3] = 0;  // @1039_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; });  // @1040_595800
  X0[1] = 0;  // @1041_595800
  X0[2] = 0;  // @1042_595800
  X0[3] = 0;  // @1043_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 136) + 0), &X0[0], 4);  // @1044_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 76) + 0), 4); v; });  // @1045_595800
  X0[1] = 0;  // @1046_595800
  X0[2] = 0;  // @1047_595800
  X0[3] = 0;  // @1048_595800
  eax = (eax & 0xffffff00u) | (((((!(!(U2F(X0[0]) >= U2F(X1[0]))) && !(!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) ? 1 : 0)) & 0xff);  // @1049_595800
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 40), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1050_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 140) + 0), &X0[0], 4);  // @1051_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 80) + 0), 4); v; });  // @1052_595800
  X0[1] = 0;  // @1053_595800
  X0[2] = 0;  // @1054_595800
  X0[3] = 0;  // @1055_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 132), &v, sizeof v); }  // @1056_595800
  __builtin_memcpy((void *)((u32)((EBP - 264) + 144) + 0), &X0[0], 4);  // @1057_595800
  if (FL[0] != FL[1]) goto L596452;  // @1058_595800
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1059_595800
  FL[2] = (eax & eax);  // @1060_595800
  if (FL[2] == 0) goto L59645d;  // @1061_595800
  L596452:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1063_595800
  L59645d:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 36) + 0), 4); v; });  // @1065_595800
  X0[1] = 0;  // @1066_595800
  X0[2] = 0;  // @1067_595800
  X0[3] = 0;  // @1068_595800
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 32) + 0), 4); v; });  // @1069_595800
  X1[1] = 0;  // @1070_595800
  X1[2] = 0;  // @1071_595800
  X1[3] = 0;  // @1072_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(X0[0]));  // @1073_595800
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @1074_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 20) + 0), 4); v; });  // @1075_595800
  X0[1] = 0;  // @1076_595800
  X0[2] = 0;  // @1077_595800
  X0[3] = 0;  // @1078_595800
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L5964b2;  // @1079_595800
  edx = (u32)((EBP - 264) + 72);  // @1080_595800
  ecx = (u32)(esi + 20);  // @1081_595800
  eax = ext_4e0830_fastcall2(ecx, edx);  // @1082_595800
  ecx = edx = 0;  // @1083_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 20) + 0), 4); v; });  // @1084_595800
  X0[1] = 0;  // @1085_595800
  X0[2] = 0;  // @1086_595800
  X0[3] = 0;  // @1087_595800
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)((EBP - 264) + 24)) :: "st");  // @1088_595800
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 24) + 0), 4); v; }))))))) goto L5964b2;  // @1089_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6815516) + 0), 4); v; });  // @1090_595800
  X0[1] = 0;  // @1091_595800
  X0[2] = 0;  // @1092_595800
  X0[3] = 0;  // @1093_595800
  eax = 0;  // @1094_595800
  FL[3] = eax;  // @1095_595800
  eax = (eax & 0xffffff00u) | ((((((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 88) + 0), 4); v; }))))))) ? 1 : 0)) & 0xff);  // @1096_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)((EBP - 264) + 128), &v, sizeof v); }  // @1097_595800
  L5964b2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1099_595800
  eax = (u32)((EBP - 264) + 128);  // @1100_595800
  PV[44] = (u32)(eax);  // @1101_595800
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2024), sizeof v); (u32)v; });  // @1102_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1103_595800
  PV[45] = (u32)(eax);  // @1104_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1105_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[45], PV[44], (u32)(0));  // @1106_595800
  ecx = edx = 0;  // @1107_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 72) + 0), 4); v; });  // @1108_595800
  X0[1] = 0;  // @1109_595800
  X0[2] = 0;  // @1110_595800
  X0[3] = 0;  // @1111_595800
  X1[0] = 0;  // @1112_595800
  X1[1] = 0;  // @1113_595800
  X1[2] = 0;  // @1114_595800
  X1[3] = 0;  // @1115_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 128), sizeof v); (u32)v; });  // @1116_595800
  __builtin_memcpy((void *)((u32)(esi - 8) + 0), &X0[0], 4);  // @1117_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 76) + 0), 4); v; });  // @1118_595800
  X0[1] = 0;  // @1119_595800
  X0[2] = 0;  // @1120_595800
  X0[3] = 0;  // @1121_595800
  __builtin_memcpy((void *)((u32)(esi - 4) + 0), &X0[0], 4);  // @1122_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)((EBP - 264) + 80) + 0), 4); v; });  // @1123_595800
  X0[1] = 0;  // @1124_595800
  X0[2] = 0;  // @1125_595800
  X0[3] = 0;  // @1126_595800
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @1127_595800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @1128_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1129_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @1130_595800
  X0[0] = F2U((float)(s32)X0[0]);  // @1131_595800
  X0[1] = F2U((float)(s32)X0[1]);  // @1132_595800
  X0[2] = F2U((float)(s32)X0[2]);  // @1133_595800
  X0[3] = F2U((float)(s32)X0[3]);  // @1134_595800
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @1135_595800
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @1136_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 16) + 0), 4); v; });  // @1137_595800
  X0[1] = 0;  // @1138_595800
  X0[2] = 0;  // @1139_595800
  X0[3] = 0;  // @1140_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1141_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1142_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596544;  // @1143_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @1144_595800
  if (FL[2] != 0) goto L596544;  // @1145_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @1146_595800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @1147_595800
  goto L596568;  // @1148_595800
  L596544:;
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1150_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1151_595800
  if (!__builtin_parity(FL[2] & 0xff)) goto L59658e;  // @1152_595800
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1047), sizeof v); (u32)v; }) & (u32)(1024));  // @1153_595800
  if (FL[2] == 0) goto L59658e;  // @1154_595800
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @1155_595800
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)((EBP - 264) + 24), &v, sizeof v); }  // @1156_595800
  L596568:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 3811), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1158_595800
  if (FL[0] == FL[1]) goto L59658e;  // @1159_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1160_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1161_595800
  eax = (u32)((EBP - 268) + 28);  // @1162_595800
  PV[46] = (u32)(eax);  // @1163_595800
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2026), sizeof v); (u32)v; });  // @1164_595800
  PV[47] = (u32)(eax);  // @1165_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1166_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, PV[47], PV[46], (u32)(0));  // @1167_595800
  ecx = edx = 0;  // @1168_595800
  L59658e:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1170_595800
  L596594:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 2582), sizeof v); (u32)v; });  // @1172_595800
  esi = (esi + (u32)(48));  // @1173_595800
  FL[3] = esi;  // @1174_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)((EBP - 264) + 16), sizeof v); (u32)v; });  // @1175_595800
  ecx = (ecx + (u32)(48));  // @1176_595800
  FL[3] = ecx;  // @1177_595800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)((EBP - 264) + 16), &v, sizeof v); }  // @1178_595800
  eax = (u32)(eax + eax*2);  // @1179_595800
  eax = (eax << (u32)(4));  // @1180_595800
  FL[3] = eax;  // @1181_595800
  eax = (eax + (u32)(2586));  // @1182_595800
  FL[3] = eax;  // @1183_595800
  eax = (eax + edi);  // @1184_595800
  FL[3] = eax;  // @1185_595800
  FL[0] = ecx; FL[1] = eax;  // @1186_595800
  if (FL[0] != FL[1]) goto L596330;  // @1187_595800
  L5965bd:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @1189_595800
  X0[1] = 0;  // @1190_595800
  X0[2] = 0;  // @1191_595800
  X0[3] = 0;  // @1192_595800
  X1[0] = 0;  // @1193_595800
  X1[1] = 0;  // @1194_595800
  X1[2] = 0;  // @1195_595800
  X1[3] = 0;  // @1196_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1197_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1198_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596616;  // @1199_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @1200_595800
  X0[1] = 0;  // @1201_595800
  X0[2] = 0;  // @1202_595800
  X0[3] = 0;  // @1203_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1204_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1205_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596616;  // @1206_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1207_595800
  ecx = edx;  // @1208_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1209_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @1210_595800
  ecx = edx = 0;  // @1211_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1212_595800
  PV[48] = (u32)(edx);  // @1213_595800
  PV[49] = (u32)(eax);  // @1214_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1215_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[49], PV[48], (u32)(6998712));  // @1216_595800
  ecx = edx = 0;  // @1217_595800
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1218_595800
  X1[0] = 0;  // @1219_595800
  X1[1] = 0;  // @1220_595800
  X1[2] = 0;  // @1221_595800
  X1[3] = 0;  // @1222_595800
  L596616:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2503) + 0), 4); v; });  // @1224_595800
  X0[1] = 0;  // @1225_595800
  X0[2] = 0;  // @1226_595800
  X0[3] = 0;  // @1227_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1228_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1229_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596663;  // @1230_595800
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edx + 2499) + 0), 4); v; });  // @1231_595800
  X0[1] = 0;  // @1232_595800
  X0[2] = 0;  // @1233_595800
  X0[3] = 0;  // @1234_595800
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @1235_595800
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @1236_595800
  if (__builtin_parity(FL[2] & 0xff)) goto L596663;  // @1237_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1238_595800
  ecx = edx;  // @1239_595800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @1240_595800
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608));  // @1241_595800
  ecx = edx = 0;  // @1242_595800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1243_595800
  PV[50] = (u32)(edx);  // @1244_595800
  PV[51] = (u32)(eax);  // @1245_595800
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1246_595800
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[51], PV[50], (u32)(6998696));  // @1247_595800
  ecx = edx = 0;  // @1248_595800
  L596663:;
  ext_633654(G(u32, 0x6f5630));  // @1250_595800
  return eax;  // @1251_595800
}
PCREG(595800, lifted_595800);

