// batch236007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e8e0_fastcall3(u32, u32, u32) __asm__("ext_43e8e0");
extern "C" u32 FASTCALL ext_43e920_fastcall3(u32, u32, u32) __asm__("ext_43e920");
extern "C" u32 FASTCALL ext_443ef0_fastcall4(u32, u32, u32, u32) __asm__("ext_443ef0");
extern "C" u32 FASTCALL ext_4e0870_fastcall2(u32, u32) __asm__("ext_4e0870");
extern "C" u32 THISCALL ext_44c840_thiscall1(u32) __asm__("ext_44c840");
extern "C" u32 THISCALL ext_477580_thiscall2(u32, u32) __asm__("ext_477580");
extern "C" u32 THISCALL ext_4e0a10_thiscall1(u32) __asm__("ext_4e0a10");
extern "C" u32 THISCALL ext_4e0d00_thiscall2(u32, u32) __asm__("ext_4e0d00");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_479910(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_479910
  edi = ecx;  // @1_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @2_479910
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @3_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1681), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @4_479910
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1731), sizeof v); (u32)v; })) & 0xff);  // @5_479910
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 69), &v, sizeof v); }  // @6_479910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1731), &v, sizeof v); }  // @7_479910
  if (FL[0] != FL[1]) goto L4799ac;  // @8_479910
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @9_479910
  FL[2] = (esi & esi);  // @10_479910
  if (FL[2] == 0) goto L47998f;  // @11_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @12_479910
  FL[2] = (eax & eax);  // @13_479910
  if (FL[2] == 0) goto L47995d;  // @14_479910
  PV[0] = (u32)(eax);  // @15_479910
  eax = ext_41e2c0_cdecl1(PV[0]);  // @16_479910
  ecx = edx = 0;  // @17_479910
  L47995d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @19_479910
  FL[2] = (eax & eax);  // @20_479910
  if (FL[2] == 0) goto L47996f;  // @21_479910
  PV[1] = (u32)(eax);  // @22_479910
  eax = ext_634273_cdecl2(PV[1], (u32)(4));  // @23_479910
  ecx = edx = 0;  // @24_479910
  L47996f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @26_479910
  FL[2] = (eax & eax);  // @27_479910
  if (FL[2] == 0) goto L479981;  // @28_479910
  PV[2] = (u32)(eax);  // @29_479910
  eax = ext_634273_cdecl2(PV[2], (u32)(4));  // @30_479910
  ecx = edx = 0;  // @31_479910
  L479981:;
  PV[3] = (u32)(esi);  // @33_479910
  eax = ext_634273_cdecl2(PV[3], (u32)(24));  // @34_479910
  ecx = edx = 0;  // @35_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @36_479910
  L47998f:;
  PV[4] = (u32)(eax);  // @38_479910
  eax = ext_634273_cdecl2(PV[4], (u32)(32));  // @39_479910
  ecx = edx = 0;  // @40_479910
  ext_633654(G(u32, 0x6f5630));  // @41_479910
  return eax;  // @42_479910
  L4799ac:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1681), &v, sizeof v); }  // @44_479910
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @45_479910
  FL[2] = (esi & esi);  // @46_479910
  if (FL[2] != 0) goto L479b55;  // @47_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @48_479910
  X0[1] = 0;  // @49_479910
  X0[2] = 0;  // @50_479910
  X0[3] = 0;  // @51_479910
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @52_479910
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @53_479910
  if (__builtin_parity(FL[2] & 0xff)) goto L479b2a;  // @54_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @55_479910
  FL[2] = (ecx & ecx);  // @56_479910
  if (FL[2] == 0) goto L479a35;  // @57_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_479910
  edx = (u32)(EBP - 16);  // @59_479910
  PV[5] = (u32)(edx);  // @60_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[5]);  // @61_479910
  ecx = edx = 0;  // @62_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @63_479910
  edx = (u32)(EBP - 16);  // @64_479910
  PV[6] = (u32)(edx);  // @65_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @67_479910
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[6]);  // @68_479910
  ecx = edx = 0;  // @69_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = esi;  // @70_479910
  if (FL[0] == FL[1]) goto L479a35;  // @71_479910
  L479a03:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_479910
  PV[7] = (u32)(eax);  // @74_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @75_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @76_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 544)))(ecx, PV[7]);  // @78_479910
  ecx = edx = 0;  // @79_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @80_479910
  edx = (u32)(EBP - 16);  // @81_479910
  PV[8] = (u32)(edx);  // @82_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @84_479910
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[8]);  // @85_479910
  ecx = edx = 0;  // @86_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @87_479910
  if (FL[0] != FL[1]) goto L479a03;  // @88_479910
  L479a35:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @90_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_479910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @92_479910
  ecx = edx = 0;  // @93_479910
  ecx = (u32)(EBP - 28);  // @94_479910
  eax = ext_4e0a10_thiscall1(ecx);  // @95_479910
  ecx = edx = 0;  // @96_479910
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @97_479910
  X3[1] = 0;  // @98_479910
  X3[2] = 0;  // @99_479910
  X3[3] = 0;  // @100_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @101_479910
  X0[1] = 0;  // @102_479910
  X0[2] = 0;  // @103_479910
  X0[3] = 0;  // @104_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; });  // @105_479910
  X2[1] = 0;  // @106_479910
  X2[2] = 0;  // @107_479910
  X2[3] = 0;  // @108_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @109_479910
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @110_479910
  X1[1] = 0;  // @111_479910
  X1[2] = 0;  // @112_479910
  X1[3] = 0;  // @113_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_479910
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @115_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @116_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @117_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @118_479910
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @119_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @120_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @121_479910
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @122_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @123_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @124_479910
  X0[1] = 0;  // @125_479910
  X0[2] = 0;  // @126_479910
  X0[3] = 0;  // @127_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @128_479910
  ecx = (ecx | (u32)(65280));  // @129_479910
  FL[3] = ecx;  // @130_479910
  ecx = (ecx << (u32)(8));  // @131_479910
  FL[3] = ecx;  // @132_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @133_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @134_479910
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @135_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @136_479910
  X0[1] = 0;  // @137_479910
  X0[2] = 0;  // @138_479910
  X0[3] = 0;  // @139_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @140_479910
  ecx = (ecx | eax);  // @141_479910
  FL[3] = ecx;  // @142_479910
  ecx = (ecx << (u32)(8));  // @143_479910
  FL[3] = ecx;  // @144_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @145_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @146_479910
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @147_479910
  ecx = (ecx | eax);  // @148_479910
  FL[3] = ecx;  // @149_479910
  PV[9] = (u32)(ecx);  // @150_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @151_479910
  eax = (u32)(ecx + 12);  // @152_479910
  PV[10] = (u32)(eax);  // @153_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 536), sizeof v); (u32)v; });  // @154_479910
  PV[11] = (u32)(ecx);  // @155_479910
  ecx = esi;  // @156_479910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[11], PV[10], PV[9]);  // @157_479910
  ecx = edx = 0;  // @158_479910
  PV[12] = (u32)(eax);  // @159_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @160_479910
  ecx = edi;  // @161_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[12]);  // @162_479910
  ecx = edx = 0;  // @163_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @164_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @166_479910
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(1342));  // @167_479910
  ecx = edx = 0;  // @168_479910
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @169_479910
  esi = eax;  // @170_479910
  ecx = edi;  // @171_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @172_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @173_479910
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @174_479910
  ecx = edx = 0;  // @175_479910
  edx = (u32)(6801640);  // @176_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @177_479910
  FL[2] = (ecx & ecx);  // @178_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @179_479910
  if (FL[2] != 0) edx = ecx;  // @180_479910
  PV[13] = (u32)(edx);  // @181_479910
  PV[14] = (u32)(esi);  // @182_479910
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[14], (u32)(6859528), PV[13]);  // @183_479910
  ecx = edx = 0;  // @184_479910
  L479b2a:;
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @186_479910
  eax = ext_634273_cdecl2(PV[15], (u32)(32));  // @187_479910
  ecx = edx = 0;  // @188_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @189_479910
  ecx = edi;  // @190_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1612)))(ecx, (u32)(0));  // @191_479910
  ecx = edx = 0;  // @192_479910
  ext_633654(G(u32, 0x6f5630));  // @193_479910
  return eax;  // @194_479910
  L479b55:;
  PV[16] = (u32)(eax);  // @196_479910
  eax = ext_634273_cdecl2(PV[16], (u32)(32));  // @197_479910
  ecx = edx = 0;  // @198_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1718) + 0), 4); v; });  // @199_479910
  X2[1] = 0;  // @200_479910
  X2[2] = 0;  // @201_479910
  X2[3] = 0;  // @202_479910
  X1[0] = 0;  // @203_479910
  X1[1] = 0;  // @204_479910
  X1[2] = 0;  // @205_479910
  X1[3] = 0;  // @206_479910
  if (((!(U2F(X2[0]) >= U2F(X1[0]))) || (!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))))) goto L479bab;  // @207_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @208_479910
  X0[1] = 0;  // @209_479910
  X0[2] = 0;  // @210_479910
  X0[3] = 0;  // @211_479910
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L479bab;  // @212_479910
  ecx = esi;  // @213_479910
  eax = ext_477580_thiscall2(ecx, (u32)(1));  // @214_479910
  ecx = edx = 0;  // @215_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @216_479910
  ecx = edi;  // @217_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1612)))(ecx, (u32)(2));  // @218_479910
  ecx = edx = 0;  // @219_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1718), &v, sizeof v); }  // @220_479910
  ext_633654(G(u32, 0x6f5630));  // @221_479910
  return eax;  // @222_479910
  L479bab:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1722) + 0), 4); v; });  // @224_479910
  X0[1] = 0;  // @225_479910
  X0[2] = 0;  // @226_479910
  X0[3] = 0;  // @227_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1718), &v, sizeof v); }  // @228_479910
  if (((!(U2F(X1[0]) >= U2F(X0[0]))) || (!((U2F(X1[0]) < U2F(X0[0])) || (U2F(X1[0]) > U2F(X0[0])))))) goto L479bf6;  // @229_479910
  X0[0] = X0[0] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @230_479910
  X0[1] = X0[1] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 4), 4); v; });  // @231_479910
  X0[2] = X0[2] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 8), 4); v; });  // @232_479910
  X0[3] = X0[3] ^ ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 12), 4); v; });  // @233_479910
  __builtin_memcpy((void *)((u32)(edi + 1722) + 0), &X0[0], 4);  // @234_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @235_479910
  X2[1] = 0;  // @236_479910
  X2[2] = 0;  // @237_479910
  X2[3] = 0;  // @238_479910
  if ((!(U2F(X0[0]) >= U2F(X2[0])))) goto L479bea;  // @239_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @240_479910
  ecx = edi;  // @241_479910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1616)))(ecx);  // @242_479910
  ecx = edx = 0;  // @243_479910
  X1[0] = 0;  // @244_479910
  X1[1] = 0;  // @245_479910
  X1[2] = 0;  // @246_479910
  X1[3] = 0;  // @247_479910
  goto L479bf6;  // @248_479910
  L479bea:;
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @250_479910
  __builtin_memcpy((void *)((u32)(edi + 1722) + 0), &X2[0], 4);  // @251_479910
  L479bf6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @253_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @254_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1714) + 0), 4); v; });  // @255_479910
  X2[1] = 0;  // @256_479910
  X2[2] = 0;  // @257_479910
  X2[3] = 0;  // @258_479910
  ecx = (ecx + ecx);  // @259_479910
  FL[3] = ecx;  // @260_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx*8 - 12) + 0), 4); v; });  // @261_479910
  X0[1] = 0;  // @262_479910
  X0[2] = 0;  // @263_479910
  X0[3] = 0;  // @264_479910
  __builtin_memcpy((void *)((u32)(EBP - 52) + 0), &X0[0], 4);  // @265_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx*8 - 8) + 0), 4); v; });  // @266_479910
  X0[1] = 0;  // @267_479910
  X0[2] = 0;  // @268_479910
  X0[3] = 0;  // @269_479910
  __builtin_memcpy((void *)((u32)(EBP - 48) + 0), &X0[0], 4);  // @270_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx*8 - 4) + 0), 4); v; });  // @271_479910
  X0[1] = 0;  // @272_479910
  X0[2] = 0;  // @273_479910
  X0[3] = 0;  // @274_479910
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @275_479910
  __builtin_memcpy((void *)((u32)(EBP - 44) + 0), &X0[0], 4);  // @276_479910
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X1[0])) || (U2F(X2[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @277_479910
  if (__builtin_parity(FL[2] & 0xff)) goto L479e03;  // @278_479910
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1689), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @279_479910
  if (FL[0] == FL[1]) goto L479c44;  // @280_479910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1689), &v, sizeof v); }  // @281_479910
  L479c44:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @283_479910
  X1[1] = 0;  // @284_479910
  X1[2] = 0;  // @285_479910
  X1[3] = 0;  // @286_479910
  X0[0] = X2[0];  // @287_479910
  X0[1] = X2[1];  // @288_479910
  X0[2] = X2[2];  // @289_479910
  X0[3] = X2[3];  // @290_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6788416) + 0), 4); v; })));  // @291_479910
  if ((!(U2F(X0[0]) >= U2F(X1[0])))) goto L479c8a;  // @292_479910
  ecx = esi;  // @293_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1714), &v, sizeof v); }  // @294_479910
  eax = ext_477580_thiscall2(ecx, (u32)(1));  // @295_479910
  ecx = edx = 0;  // @296_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @297_479910
  ecx = edi;  // @298_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1612)))(ecx, (u32)(1));  // @299_479910
  ecx = edx = 0;  // @300_479910
  ext_633654(G(u32, 0x6f5630));  // @301_479910
  return eax;  // @302_479910
  L479c8a:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @304_479910
  ecx = (u32)(edx - 1);  // @305_479910
  FL[2] = (ecx & ecx);  // @306_479910
  if ((s32)FL[2] < 0) goto L479cb1;  // @307_479910
  eax = ecx;  // @308_479910
  X1[0] = F2U(U2F(X1[0]) - U2F(X2[0]));  // @309_479910
  eax = (eax << (u32)(4));  // @310_479910
  FL[3] = eax;  // @311_479910
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));  // @312_479910
  FL[3] = eax;  // @313_479910
  L479ca0:;
  if ((!(!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; })))) && !(!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax) + 0), 4); v; }))))))) goto L479d3d;  // @315_479910
  eax = (eax - (u32)(16));  // @316_479910
  FL[3] = eax;  // @317_479910
  ecx = (ecx - (u32)(1));  // @318_479910
  FL[3] = ecx;  // @319_479910
  if ((s32)FL[3] >= 0) goto L479ca0;  // @320_479910
  L479cb1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @322_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @323_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @324_479910
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(1423));  // @325_479910
  ecx = edx = 0;  // @326_479910
  PV[17] = (u32)(eax);  // @327_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @328_479910
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[17], (u32)(6859560));  // @329_479910 (w3h hand fix: cdecl (log object, format), `add esp,8` follows after an unrelated mov)
  ecx = edx = 0;  // @330_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1714), &v, sizeof v); }  // @331_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @332_479910
  FL[2] = (eax & eax);  // @333_479910
  if (FL[2] == 0) goto L479cf0;  // @334_479910
  PV[18] = (u32)(eax);  // @335_479910
  eax = ext_41e2c0_cdecl1(PV[18]);  // @336_479910
  ecx = edx = 0;  // @337_479910
  L479cf0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @339_479910
  FL[2] = (eax & eax);  // @340_479910
  if (FL[2] == 0) goto L479d02;  // @341_479910
  PV[19] = (u32)(eax);  // @342_479910
  eax = ext_634273_cdecl2(PV[19], (u32)(4));  // @343_479910
  ecx = edx = 0;  // @344_479910
  L479d02:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @346_479910
  FL[2] = (eax & eax);  // @347_479910
  if (FL[2] == 0) goto L479d14;  // @348_479910
  PV[20] = (u32)(eax);  // @349_479910
  eax = ext_634273_cdecl2(PV[20], (u32)(4));  // @350_479910
  ecx = edx = 0;  // @351_479910
  L479d14:;
  PV[21] = (u32)(esi);  // @353_479910
  eax = ext_634273_cdecl2(PV[21], (u32)(24));  // @354_479910
  ecx = edx = 0;  // @355_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @356_479910
  ecx = edi;  // @357_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1612)))(ecx, (u32)(0));  // @358_479910
  ecx = edx = 0;  // @359_479910
  ext_633654(G(u32, 0x6f5630));  // @360_479910
  return eax;  // @361_479910
  L479d3d:;
  FL[2] = (ecx & ecx);  // @363_479910
  if ((s32)FL[2] < 0) goto L479cb1;  // @364_479910
  eax = (u32)(edx - 2);  // @365_479910
  FL[0] = ecx; FL[1] = eax;  // @366_479910
  if ((s32)FL[0] > (s32)FL[1]) goto L479cb1;  // @367_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @368_479910
  eax = (u32)(ecx + 2);  // @369_479910
  ecx = (ecx << (u32)(4));  // @370_479910
  FL[3] = ecx;  // @371_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @372_479910
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @373_479910
  eax = (u32)(edx + 4);  // @374_479910
  edx = (edx + (u32)(20));  // @375_479910
  FL[3] = edx;  // @376_479910
  eax = (eax + ecx);  // @377_479910
  FL[3] = eax;  // @378_479910
  edx = (edx + ecx);  // @379_479910
  FL[3] = edx;  // @380_479910
  PV[22] = (u32)(eax);  // @381_479910
  ecx = (u32)(EBP - 16);  // @382_479910
  eax = ext_43e920_fastcall3(ecx, edx, PV[22]);  // @383_479910
  ecx = edx = 0;  // @384_479910
  ecx = (u32)(EBP - 16);  // @385_479910
  eax = ext_44c840_thiscall1(ecx);  // @386_479910
  ecx = 0;  // @387_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @388_479910
  X0[1] = 0;  // @389_479910
  X0[2] = 0;  // @390_479910
  X0[3] = 0;  // @391_479910
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @392_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1714) + 0), 4); v; })));  // @393_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @394_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @395_479910
  PV[23] = (u32)(ecx);  // @396_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + eax) + 0), 4); v; })));  // @397_479910
  ecx = (u32)(EBP - 16);  // @398_479910
  PV[24] = X0[0];  // @399_479910
  eax = ext_4e0d00_thiscall2(ecx, PV[24]);  // @400_479910
    // @401_479910
  ecx = (u32)(EBP - 16);  // @402_479910
  PV[25] = (u32)(ecx);  // @403_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @404_479910
  edx = (u32)(ecx + 4);  // @405_479910
  ecx = (ecx + (u32)(20));  // @406_479910
  FL[3] = ecx;  // @407_479910
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));  // @408_479910
  FL[3] = edx;  // @409_479910
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));  // @410_479910
  FL[3] = ecx;  // @411_479910
  eax = ext_43e8e0_fastcall3(ecx, edx, PV[25]);  // @412_479910
  ecx = edx = 0;  // @413_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @414_479910
  X0[1] = 0;  // @415_479910
  X0[2] = 0;  // @416_479910
  X0[3] = 0;  // @417_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1714) + 0), 4); v; })));  // @418_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @419_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @420_479910
  __builtin_memcpy((void *)((u32)(ecx + eax + 16) + 0), &X0[0], 4);  // @421_479910
  edx = (u32)(ecx + 4);  // @422_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @423_479910
  ecx = (ecx + (u32)(20));  // @424_479910
  FL[3] = ecx;  // @425_479910
  edx = (edx + eax);  // @426_479910
  FL[3] = edx;  // @427_479910
  ecx = (ecx + eax);  // @428_479910
  FL[3] = ecx;  // @429_479910
  eax = ext_4e0870_fastcall2(ecx, edx);  // @430_479910
  ecx = edx = 0;  // @431_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @432_479910
  X0[1] = 0;  // @433_479910
  X0[2] = 0;  // @434_479910
  X0[3] = 0;  // @435_479910
  __asm__ volatile("fstp %%st(0)" ::: "st");  // @436_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1714) + 0), 4); v; })));  // @437_479910
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @438_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1714), &v, sizeof v); }  // @439_479910
  L479e03:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1727), sizeof v); (u32)v; });  // @441_479910
  FL[2] = (edx & edx);  // @442_479910
  if (FL[2] == 0) goto L47a16b;  // @443_479910
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 69), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @444_479910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1733), &v, sizeof v); }  // @445_479910
  if (FL[0] != FL[1]) goto L47a16b;  // @446_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @447_479910
  PV[26] = (u32)(edx);  // @448_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @449_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @450_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 88), sizeof v); (u32)v; });  // @451_479910
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[26]);  // @452_479910
  ecx = edx = 0;  // @453_479910
  ecx = (u32)(EBP - 52);  // @454_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 84), &v, sizeof v); }  // @455_479910
  PV[27] = (u32)(ecx);  // @456_479910
  ecx = eax;  // @457_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @458_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 140)))(ecx, PV[27]);  // @459_479910
  ecx = edx = 0;  // @460_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @461_479910
  edx = (u32)(EBP - 52);  // @462_479910
  PV[28] = (u32)(ecx);  // @463_479910
  PV[29] = (u32)(edx);  // @464_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @465_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @466_479910
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[29], (u32)(1092616192));  // @467_479910
  ecx = edx = 0;  // @468_479910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @469_479910
  if (FL[2] != 0) goto L47a16b;  // @470_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @471_479910
  X1[0] = 0;  // @472_479910
  X1[1] = 0;  // @473_479910
  X1[2] = 0;  // @474_479910
  X1[3] = 0;  // @475_479910
  X0[0] = X1[0];  // @476_479910
  X0[1] = X1[1];  // @477_479910
  X0[2] = X1[2];  // @478_479910
  X0[3] = X1[3];  // @479_479910
  ecx = (ecx - (u32)(1));  // @480_479910
  FL[3] = ecx;  // @481_479910
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @482_479910
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @483_479910
  if ((s32)FL[3] < 0) goto L479f21;  // @484_479910
  edi = ecx;  // @485_479910
  edi = (edi << (u32)(4));  // @486_479910
  FL[3] = edi;  // @487_479910
  L479e86:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @489_479910
  edx = (u32)(EBP - 16);  // @490_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @491_479910
  PV[30] = (u32)(edx);  // @492_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi + 4) + 0), 4); v; });  // @493_479910
  X0[1] = 0;  // @494_479910
  X0[2] = 0;  // @495_479910
  X0[3] = 0;  // @496_479910
  *(volatile u32 *)((u32)(EBP - 16)) = X0[0];  // @497_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi + 8) + 0), 4); v; });  // @498_479910
  X0[1] = 0;  // @499_479910
  X0[2] = 0;  // @500_479910
  X0[3] = 0;  // @501_479910
  *(volatile u32 *)((u32)(EBP - 12)) = X0[0];  // @502_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi + 12) + 0), 4); v; });  // @503_479910
  X0[1] = 0;  // @504_479910
  X0[2] = 0;  // @505_479910
  X0[3] = 0;  // @506_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @507_479910
  *(volatile u32 *)((u32)(EBP - 8)) = X0[0];  // @508_479910
  __asm__ volatile("" ::: "memory");   // w3h: keep the EBP-relative vector stores before the call that reads them
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[30]);  // @509_479910
  ecx = edx = 0;  // @510_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @511_479910
  edx = (u32)(EBP - 16);  // @512_479910
  PV[31] = (u32)(ecx);  // @513_479910
  PV[32] = (u32)(edx);  // @514_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @515_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 384), sizeof v); (u32)v; });  // @516_479910
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, PV[32], (u32)(1092616192));  // @517_479910
  ecx = edx = 0;  // @518_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @519_479910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @520_479910
  if (FL[2] != 0) goto L479f16;  // @521_479910
  FL[2] = (ecx & ecx);  // @522_479910
  if ((s32)FL[2] <= 0) goto L479ee8;  // @523_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @524_479910
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi - 16) + 0), 4); v; });  // @525_479910
  X1[1] = 0;  // @526_479910
  X1[2] = 0;  // @527_479910
  X1[3] = 0;  // @528_479910
  goto L479eeb;  // @529_479910
  L479ee8:;
  X1[0] = 0;  // @531_479910
  X1[1] = 0;  // @532_479910
  X1[2] = 0;  // @533_479910
  X1[3] = 0;  // @534_479910
  L479eeb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @536_479910
  ecx = (ecx - 1);  // @537_479910
  FL[3] = ecx;  // @538_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @539_479910
  X2[1] = 0;  // @540_479910
  X2[2] = 0;  // @541_479910
  X2[3] = 0;  // @542_479910
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @543_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + edi) + 0), 4); v; });  // @544_479910
  X0[1] = 0;  // @545_479910
  X0[2] = 0;  // @546_479910
  X0[3] = 0;  // @547_479910
  edi = (edi - (u32)(16));  // @548_479910
  FL[3] = edi;  // @549_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @550_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X2[0]));  // @551_479910
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @552_479910
  FL[2] = (ecx & ecx);  // @553_479910
  if ((s32)FL[2] >= 0) goto L479e86;  // @554_479910
  goto L479f1b;  // @555_479910
  L479f16:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @557_479910
  X0[1] = 0;  // @558_479910
  X0[2] = 0;  // @559_479910
  X0[3] = 0;  // @560_479910
  L479f1b:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @562_479910
  X1[0] = 0;  // @563_479910
  X1[1] = 0;  // @564_479910
  X1[2] = 0;  // @565_479910
  X1[3] = 0;  // @566_479910
  L479f21:;
  FL[0] = ecx; FL[1] = (u32)(-1);  // @568_479910
  if (FL[0] != FL[1]) goto L479f4d;  // @569_479910
  ecx = esi;  // @570_479910
  eax = ext_477580_thiscall2(ecx, (u32)(1));  // @571_479910
  ecx = edx = 0;  // @572_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @573_479910
  ecx = edi;  // @574_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1612)))(ecx, (u32)(3));  // @575_479910
  ecx = edx = 0;  // @576_479910
  ext_633654(G(u32, 0x6f5630));  // @577_479910
  return eax;  // @578_479910
  L479f4d:;
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47a16b;  // @580_479910
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1733), &v, sizeof v); }  // @581_479910
  edx = (u32)(EBP - 28);  // @582_479910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1689), &v, sizeof v); }  // @583_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @584_479910
  ecx = (ecx << (u32)(4));  // @585_479910
  FL[3] = ecx;  // @586_479910
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @587_479910
  PV[33] = (u32)(edx);  // @588_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 20) + 0), 4); v; });  // @589_479910
  X0[1] = 0;  // @590_479910
  X0[2] = 0;  // @591_479910
  X0[3] = 0;  // @592_479910
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @593_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 24) + 0), 4); v; });  // @594_479910
  X0[1] = 0;  // @595_479910
  X0[2] = 0;  // @596_479910
  X0[3] = 0;  // @597_479910
  __builtin_memcpy((void *)((u32)(EBP - 24) + 0), &X0[0], 4);  // @598_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 28) + 0), 4); v; });  // @599_479910
  X0[1] = 0;  // @600_479910
  X0[2] = 0;  // @601_479910
  X0[3] = 0;  // @602_479910
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X0[0], 4);  // @603_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 4) + 0), 4); v; });  // @604_479910
  X0[1] = 0;  // @605_479910
  X0[2] = 0;  // @606_479910
  X0[3] = 0;  // @607_479910
  __builtin_memcpy((void *)((u32)(EBP - 40) + 0), &X0[0], 4);  // @608_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 8) + 0), 4); v; });  // @609_479910
  X0[1] = 0;  // @610_479910
  X0[2] = 0;  // @611_479910
  X0[3] = 0;  // @612_479910
  __builtin_memcpy((void *)((u32)(EBP - 36) + 0), &X0[0], 4);  // @613_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx + 12) + 0), 4); v; });  // @614_479910
  X0[1] = 0;  // @615_479910
  X0[2] = 0;  // @616_479910
  X0[3] = 0;  // @617_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @618_479910
  __builtin_memcpy((void *)((u32)(EBP - 32) + 0), &X0[0], 4);  // @619_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @620_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[33]);  // @621_479910
  ecx = edx = 0;  // @622_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @623_479910
  edx = (u32)(EBP - 40);  // @624_479910
  PV[34] = (u32)(edx);  // @625_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @626_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, PV[34]);  // @627_479910
  ecx = edx = 0;  // @628_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @629_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @630_479910
  X0[1] = 0;  // @631_479910
  X0[2] = 0;  // @632_479910
  X0[3] = 0;  // @633_479910
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @634_479910
  X4[1] = 0;  // @635_479910
  X4[2] = 0;  // @636_479910
  X4[3] = 0;  // @637_479910
  X1[0] = X0[0];  // @638_479910
  X1[1] = X0[1];  // @639_479910
  X1[2] = X0[2];  // @640_479910
  X1[3] = X0[3];  // @641_479910
  X6[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6795072) + 0), 4); v; });  // @642_479910
  X6[1] = 0;  // @643_479910
  X6[2] = 0;  // @644_479910
  X6[3] = 0;  // @645_479910
  X2[0] = X0[0];  // @646_479910
  X2[1] = X0[1];  // @647_479910
  X2[2] = X0[2];  // @648_479910
  X2[3] = X0[3];  // @649_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @650_479910
  X3[0] = X0[0];  // @651_479910
  X3[1] = X0[1];  // @652_479910
  X3[2] = X0[2];  // @653_479910
  X3[3] = X0[3];  // @654_479910
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 64) + 0), 4); v; });  // @655_479910
  X5[1] = 0;  // @656_479910
  X5[2] = 0;  // @657_479910
  X5[3] = 0;  // @658_479910
  if (((!(U2F(X4[0]) >= U2F(X5[0]))) || (!((U2F(X4[0]) < U2F(X5[0])) || (U2F(X4[0]) > U2F(X5[0])))))) goto L47a00e;  // @659_479910
  X4[0] = F2U(U2F(X4[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @660_479910
  X1[0] = X5[0];  // @661_479910
  X1[1] = X5[1];  // @662_479910
  X1[2] = X5[2];  // @663_479910
  X1[3] = X5[3];  // @664_479910
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; })));  // @665_479910
  X1[0] = F2U(U2F(X1[0]) / U2F(X4[0]));  // @666_479910
  goto L47a02d;  // @667_479910
  L47a00e:;
  X0[0] = X5[0];  // @669_479910
  X0[1] = X5[1];  // @670_479910
  X0[2] = X5[2];  // @671_479910
  X0[3] = X5[3];  // @672_479910
  X0[0] = X0[0] ^ X6[0];  // @673_479910
  X0[1] = X0[1] ^ X6[1];  // @674_479910
  X0[2] = X0[2] ^ X6[2];  // @675_479910
  X0[3] = X0[3] ^ X6[3];  // @676_479910
  if (((!(U2F(X0[0]) >= U2F(X4[0]))) || (!((U2F(X0[0]) < U2F(X4[0])) || (U2F(X0[0]) > U2F(X4[0])))))) goto L47a02d;  // @677_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 40) + 0), 4); v; });  // @678_479910
  X0[1] = 0;  // @679_479910
  X0[2] = 0;  // @680_479910
  X0[3] = 0;  // @681_479910
  X1[0] = X0[0];  // @682_479910
  X1[1] = X0[1];  // @683_479910
  X1[2] = X0[2];  // @684_479910
  X1[3] = X0[3];  // @685_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(X4[0]));  // @686_479910
  X1[0] = F2U(U2F(X1[0]) + U2F(X5[0]));  // @687_479910
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @688_479910
  L47a02d:;
  X5[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 68) + 0), 4); v; });  // @690_479910
  X5[1] = 0;  // @691_479910
  X5[2] = 0;  // @692_479910
  X5[3] = 0;  // @693_479910
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @694_479910
  X4[1] = 0;  // @695_479910
  X4[2] = 0;  // @696_479910
  X4[3] = 0;  // @697_479910
  { float a_ = U2F(X1[0]), b_ = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6802756) + 0), 4); v; })); X1[0] = (a_ < b_) ? X1[0] : F2U(b_); }  // @698_479910
  if (((!(U2F(X4[0]) >= U2F(X5[0]))) || (!((U2F(X4[0]) < U2F(X5[0])) || (U2F(X4[0]) > U2F(X5[0])))))) goto L47a057;  // @699_479910
  X4[0] = F2U(U2F(X4[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @700_479910
  X2[0] = X5[0];  // @701_479910
  X2[1] = X5[1];  // @702_479910
  X2[2] = X5[2];  // @703_479910
  X2[3] = X5[3];  // @704_479910
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; })));  // @705_479910
  X2[0] = F2U(U2F(X2[0]) / U2F(X4[0]));  // @706_479910
  goto L47a076;  // @707_479910
  L47a057:;
  X0[0] = X5[0];  // @709_479910
  X0[1] = X5[1];  // @710_479910
  X0[2] = X5[2];  // @711_479910
  X0[3] = X5[3];  // @712_479910
  X0[0] = X0[0] ^ X6[0];  // @713_479910
  X0[1] = X0[1] ^ X6[1];  // @714_479910
  X0[2] = X0[2] ^ X6[2];  // @715_479910
  X0[3] = X0[3] ^ X6[3];  // @716_479910
  if (((!(U2F(X0[0]) >= U2F(X4[0]))) || (!((U2F(X0[0]) < U2F(X4[0])) || (U2F(X0[0]) > U2F(X4[0])))))) goto L47a076;  // @717_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 36) + 0), 4); v; });  // @718_479910
  X0[1] = 0;  // @719_479910
  X0[2] = 0;  // @720_479910
  X0[3] = 0;  // @721_479910
  X2[0] = X0[0];  // @722_479910
  X2[1] = X0[1];  // @723_479910
  X2[2] = X0[2];  // @724_479910
  X2[3] = X0[3];  // @725_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(X4[0]));  // @726_479910
  X2[0] = F2U(U2F(X2[0]) + U2F(X5[0]));  // @727_479910
  X2[0] = F2U(U2F(X2[0]) / U2F(X0[0]));  // @728_479910
  L47a076:;
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @730_479910
  X4[1] = 0;  // @731_479910
  X4[2] = 0;  // @732_479910
  X4[3] = 0;  // @733_479910
  { float a_ = U2F(X2[0]), b_ = U2F(X1[0]); X2[0] = (a_ < b_) ? X2[0] : F2U(b_); }  // @734_479910
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @735_479910
  X1[1] = 0;  // @736_479910
  X1[2] = 0;  // @737_479910
  X1[3] = 0;  // @738_479910
  if (((!(U2F(X1[0]) >= U2F(X4[0]))) || (!((U2F(X1[0]) < U2F(X4[0])) || (U2F(X1[0]) > U2F(X4[0])))))) goto L47a09c;  // @739_479910
  X1[0] = F2U(U2F(X1[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @740_479910
  X3[0] = X4[0];  // @741_479910
  X3[1] = X4[1];  // @742_479910
  X3[2] = X4[2];  // @743_479910
  X3[3] = X4[3];  // @744_479910
  X3[0] = F2U(U2F(X3[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; })));  // @745_479910
  X3[0] = F2U(U2F(X3[0]) / U2F(X1[0]));  // @746_479910
  goto L47a0bb;  // @747_479910
  L47a09c:;
  X0[0] = X4[0];  // @749_479910
  X0[1] = X4[1];  // @750_479910
  X0[2] = X4[2];  // @751_479910
  X0[3] = X4[3];  // @752_479910
  X0[0] = X0[0] ^ X6[0];  // @753_479910
  X0[1] = X0[1] ^ X6[1];  // @754_479910
  X0[2] = X0[2] ^ X6[2];  // @755_479910
  X0[3] = X0[3] ^ X6[3];  // @756_479910
  if (((!(U2F(X0[0]) >= U2F(X1[0]))) || (!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))))) goto L47a0bb;  // @757_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 32) + 0), 4); v; });  // @758_479910
  X0[1] = 0;  // @759_479910
  X0[2] = 0;  // @760_479910
  X0[3] = 0;  // @761_479910
  X3[0] = X0[0];  // @762_479910
  X3[1] = X0[1];  // @763_479910
  X3[2] = X0[2];  // @764_479910
  X3[3] = X0[3];  // @765_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @766_479910
  X3[0] = F2U(U2F(X3[0]) + U2F(X4[0]));  // @767_479910
  X3[0] = F2U(U2F(X3[0]) / U2F(X0[0]));  // @768_479910
  L47a0bb:;
  { float a_ = U2F(X3[0]), b_ = U2F(X2[0]); X3[0] = (a_ < b_) ? X3[0] : F2U(b_); }  // @770_479910
  eax = (u32)(EBP - 40);  // @771_479910
  PV[35] = (u32)(eax);  // @772_479910
  edx = (u32)(EBP - 28);  // @773_479910
  ecx = (u32)(EBP - 64);  // @774_479910
  __builtin_memcpy((void *)((u32)(EBP - 88) + 0), &X3[0], 4);  // @775_479910
  eax = ext_43e920_fastcall3(ecx, edx, PV[35]);  // @776_479910
  ecx = edx = 0;  // @777_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; });  // @778_479910
  X0[1] = 0;  // @779_479910
  X0[2] = 0;  // @780_479910
  X0[3] = 0;  // @781_479910
  eax = (u32)(EBP - 64);  // @782_479910
  PV[36] = (u32)(ecx);  // @783_479910
  PV[37] = X0[0];  // @784_479910
  edx = (u32)(EBP - 40);  // @785_479910
  PV[38] = (u32)(eax);  // @786_479910
  ecx = (u32)(EBP - 16);  // @787_479910
  eax = ext_443ef0_fastcall4(ecx, edx, PV[38], PV[37]);  // @788_479910
  ecx = edx = 0;  // @789_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 84), sizeof v); (u32)v; });  // @790_479910
  edx = (u32)(EBP - 16);  // @791_479910
  PV[39] = (u32)(edx);  // @792_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @793_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, PV[39]);  // @794_479910
  ecx = edx = 0;  // @795_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @796_479910
  ecx = (u32)(EBP - 16);  // @797_479910
  edx = (edx + (u32)(4));  // @798_479910
  FL[3] = edx;  // @799_479910
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));  // @800_479910
  FL[3] = edx;  // @801_479910
  eax = ext_4e0870_fastcall2(ecx, edx);  // @802_479910
  ecx = edx = 0;  // @803_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @804_479910
  X2[1] = 0;  // @805_479910
  X2[2] = 0;  // @806_479910
  X2[3] = 0;  // @807_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @808_479910
  X0[1] = 0;  // @809_479910
  X0[2] = 0;  // @810_479910
  X0[3] = 0;  // @811_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @812_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @813_479910
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 88)) :: "st");  // @814_479910
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; })));  // @815_479910
  X0[0] = F2U(U2F(X0[0]) - U2F(X2[0]));  // @816_479910
  __builtin_memcpy((void *)((u32)(esi + 4) + 0), &X0[0], 4);  // @817_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 16) + 0), 4); v; });  // @818_479910
  X0[1] = 0;  // @819_479910
  X0[2] = 0;  // @820_479910
  X0[3] = 0;  // @821_479910
  __builtin_memcpy((void *)((u32)(eax + ecx + 20) + 0), &X0[0], 4);  // @822_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 12) + 0), 4); v; });  // @823_479910
  X0[1] = 0;  // @824_479910
  X0[2] = 0;  // @825_479910
  X0[3] = 0;  // @826_479910
  __builtin_memcpy((void *)((u32)(eax + ecx + 24) + 0), &X0[0], 4);  // @827_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 8) + 0), 4); v; });  // @828_479910
  X0[1] = 0;  // @829_479910
  X0[2] = 0;  // @830_479910
  X0[3] = 0;  // @831_479910
  __builtin_memcpy((void *)((u32)(eax + ecx + 28) + 0), &X0[0], 4);  // @832_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @833_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + ecx) + 0), 4); v; });  // @834_479910
  X0[1] = 0;  // @835_479910
  X0[2] = 0;  // @836_479910
  X0[3] = 0;  // @837_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 88) + 0), 4); v; })));  // @838_479910
  __builtin_memcpy((void *)((u32)(eax + ecx + 16) + 0), &X0[0], 4);  // @839_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @840_479910
  eax = (eax + (u32)(2));  // @841_479910
  FL[3] = eax;  // @842_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @843_479910
  L47a16b:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1830), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @845_479910
  if (FL[0] != FL[1]) goto L47a180;  // @846_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @847_479910
  ecx = edi;  // @848_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 544)))(ecx, (u32)(1));  // @849_479910
  ecx = edx = 0;  // @850_479910
  L47a180:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1689), sizeof v); (u32)v; })) & 0xff);  // @852_479910
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 69), &v, sizeof v); }  // @853_479910
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @854_479910
  if (FL[2] == 0) goto L47a1b1;  // @855_479910
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1694) + 0), 4); v; });  // @856_479910
  X1[1] = 0;  // @857_479910
  X1[2] = 0;  // @858_479910
  X1[3] = 0;  // @859_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1690) + 0), 4); v; });  // @860_479910
  X0[1] = 0;  // @861_479910
  X0[2] = 0;  // @862_479910
  X0[3] = 0;  // @863_479910
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X1[0], 4);  // @864_479910
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1698) + 0), 4); v; });  // @865_479910
  X1[1] = 0;  // @866_479910
  X1[2] = 0;  // @867_479910
  X1[3] = 0;  // @868_479910
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X1[0], 4);  // @869_479910
  goto L47a1ca;  // @870_479910
  L47a1b1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 44) + 0), 4); v; });  // @872_479910
  X0[1] = 0;  // @873_479910
  X0[2] = 0;  // @874_479910
  X0[3] = 0;  // @875_479910
  __builtin_memcpy((void *)((u32)(EBP - 80) + 0), &X0[0], 4);  // @876_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 48) + 0), 4); v; });  // @877_479910
  X0[1] = 0;  // @878_479910
  X0[2] = 0;  // @879_479910
  X0[3] = 0;  // @880_479910
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @881_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 52) + 0), 4); v; });  // @882_479910
  X0[1] = 0;  // @883_479910
  X0[2] = 0;  // @884_479910
  X0[3] = 0;  // @885_479910
  L47a1ca:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @887_479910
  __builtin_memcpy((void *)((u32)(EBP - 76) + 0), &X0[0], 4);  // @888_479910
  if (FL[0] == FL[1]) goto L47a1eb;  // @889_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @890_479910
  ecx = edi;  // @891_479910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 1576)))(ecx, (u32)(2), (u32)(4), (u32)(0));  // @892_479910
  ecx = edx = 0;  // @893_479910
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 69), sizeof v); (u32)v; })) & 0xff);  // @894_479910
  L47a1eb:;
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @896_479910
  if (FL[2] == 0) goto L47a21d;  // @897_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 76) + 0), 4); v; });  // @898_479910
  X0[1] = 0;  // @899_479910
  X0[2] = 0;  // @900_479910
  X0[3] = 0;  // @901_479910
  __builtin_memcpy((void *)((u32)(edi + 1690) + 0), &X0[0], 4);  // @902_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 68) + 0), 4); v; });  // @903_479910
  X0[1] = 0;  // @904_479910
  X0[2] = 0;  // @905_479910
  X0[3] = 0;  // @906_479910
  __builtin_memcpy((void *)((u32)(edi + 1694) + 0), &X0[0], 4);  // @907_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 80) + 0), 4); v; });  // @908_479910
  X0[1] = 0;  // @909_479910
  X0[2] = 0;  // @910_479910
  X0[3] = 0;  // @911_479910
  __builtin_memcpy((void *)((u32)(edi + 1698) + 0), &X0[0], 4);  // @912_479910
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1689), &v, sizeof v); }  // @913_479910
  L47a21d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @915_479910
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 1685), &v, sizeof v); }  // @916_479910
  FL[2] = (ecx & ecx);  // @917_479910
  if (FL[2] == 0) goto L47a282;  // @918_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @919_479910
  edx = (u32)(EBP - 16);  // @920_479910
  PV[40] = (u32)(edx);  // @921_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[40]);  // @922_479910
  ecx = edx = 0;  // @923_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @924_479910
  edx = (u32)(EBP - 16);  // @925_479910
  PV[41] = (u32)(edx);  // @926_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @927_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @928_479910
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[41]);  // @929_479910
  ecx = edx = 0;  // @930_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @931_479910
  if (FL[0] == FL[1]) goto L47a282;  // @932_479910
  L47a250:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @934_479910
  PV[42] = (u32)(eax);  // @935_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @936_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2780), sizeof v); (u32)v; });  // @937_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @938_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 544)))(ecx, PV[42]);  // @939_479910
  ecx = edx = 0;  // @940_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @941_479910
  edx = (u32)(EBP - 16);  // @942_479910
  PV[43] = (u32)(edx);  // @943_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @944_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @945_479910
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[43]);  // @946_479910
  ecx = edx = 0;  // @947_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @948_479910
  if (FL[0] != FL[1]) goto L47a250;  // @949_479910
  L47a282:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1854), sizeof v); (u32)v; });  // @951_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @952_479910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 12)))(ecx);  // @953_479910
  ecx = edx = 0;  // @954_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7338568) + 0), 4); v; });  // @955_479910
  X0[1] = 0;  // @956_479910
  X0[2] = 0;  // @957_479910
  X0[3] = 0;  // @958_479910
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @959_479910
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @960_479910
  if (__builtin_parity(FL[2] & 0xff)) goto L47a3ab;  // @961_479910
  ecx = (u32)(EBP - 64);  // @962_479910
  eax = ext_4e0a10_thiscall1(ecx);  // @963_479910
  ecx = edx = 0;  // @964_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @965_479910
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @966_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; }); FL[1] = (u32)(1);  // @967_479910
  if ((s32)FL[0] <= (s32)FL[1]) goto L47a3ab;  // @968_479910
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @969_479910
  L47a2d0:;
  ecx = (u32)(EBP - 28);  // @971_479910
  eax = ext_4e0a10_thiscall1(ecx);  // @972_479910
  ecx = edx = 0;  // @973_479910
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @974_479910
  X3[1] = 0;  // @975_479910
  X3[2] = 0;  // @976_479910
  X3[3] = 0;  // @977_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 28) + 0), 4); v; });  // @978_479910
  X0[1] = 0;  // @979_479910
  X0[2] = 0;  // @980_479910
  X0[3] = 0;  // @981_479910
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860568) + 0), 4); v; });  // @982_479910
  X1[1] = 0;  // @983_479910
  X1[2] = 0;  // @984_479910
  X1[3] = 0;  // @985_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @986_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @987_479910
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6792876) + 0), 4); v; });  // @988_479910
  X2[1] = 0;  // @989_479910
  X2[2] = 0;  // @990_479910
  X2[3] = 0;  // @991_479910
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @992_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @993_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @994_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @995_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @996_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @997_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @998_479910
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edx = (u32)r_; }  // @999_479910
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1000_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1854), sizeof v); (u32)v; });  // @1001_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @1002_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 24) + 0), 4); v; });  // @1003_479910
  X0[1] = 0;  // @1004_479910
  X0[2] = 0;  // @1005_479910
  X0[3] = 0;  // @1006_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @1007_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @1008_479910
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 80), &v, sizeof v); }  // @1009_479910
  edx = (edx | (u32)(65280));  // @1010_479910
  FL[3] = edx;  // @1011_479910
  edx = (edx << (u32)(8));  // @1012_479910
  FL[3] = edx;  // @1013_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @1014_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @1015_479910
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @1016_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @1017_479910
  X0[1] = 0;  // @1018_479910
  X0[2] = 0;  // @1019_479910
  X0[3] = 0;  // @1020_479910
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @1021_479910
  edx = (edx | eax);  // @1022_479910
  FL[3] = edx;  // @1023_479910
  edx = (edx << (u32)(8));  // @1024_479910
  FL[3] = edx;  // @1025_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @1026_479910
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @1027_479910
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @1028_479910
  edx = (edx | eax);  // @1029_479910
  FL[3] = edx;  // @1030_479910
  PV[44] = (u32)(edx);  // @1031_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @1032_479910
  eax = (u32)(edx + 4);  // @1033_479910
  eax = (eax + edi);  // @1034_479910
  FL[3] = eax;  // @1035_479910
  PV[45] = (u32)(eax);  // @1036_479910
  eax = (u32)(edx - 12);  // @1037_479910
  eax = (eax + edi);  // @1038_479910
  FL[3] = eax;  // @1039_479910
  PV[46] = (u32)(eax);  // @1040_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 536), sizeof v); (u32)v; });  // @1041_479910
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[46], PV[45], PV[44]);  // @1042_479910
  ecx = edx = 0;  // @1043_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @1044_479910
  PV[47] = (u32)(eax);  // @1045_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 80), sizeof v); (u32)v; });  // @1046_479910
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[47]);  // @1047_479910
  ecx = edx = 0;  // @1048_479910
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @1049_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 76), sizeof v); (u32)v; });  // @1050_479910
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; }) + (u32)(16))); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @1051_479910
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 68), sizeof v); (u32)v; });  // @1052_479910
  ecx = (ecx + 1);  // @1053_479910
  FL[3] = ecx;  // @1054_479910
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 76), &v, sizeof v); }  // @1055_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @1056_479910
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @1057_479910
  if ((s32)FL[0] < (s32)FL[1]) goto L47a2d0;  // @1058_479910
  L47a3ab:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @1060_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @1061_479910
  X0[1] = 0;  // @1062_479910
  X0[2] = 0;  // @1063_479910
  X0[3] = 0;  // @1064_479910
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860588) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860588) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6860588) + 0), 4); v; }))))))) goto L47a413;  // @1065_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @1066_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1067_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @1068_479910
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(1602));  // @1069_479910
  ecx = edx = 0;  // @1070_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1071_479910
  ecx = edi;  // @1072_479910
  esi = eax;  // @1073_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @1074_479910
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @1075_479910
  ecx = edx = 0;  // @1076_479910
  edx = (u32)(6801640);  // @1077_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1078_479910
  FL[2] = (ecx & ecx);  // @1079_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1685), sizeof v); (u32)v; });  // @1080_479910
  if (FL[2] != 0) edx = ecx;  // @1081_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1082_479910
  PV[48] = (u32)(edx);  // @1083_479910
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 4) + 0), 4); v; });  // @1084_479910
  X0[1] = 0;  // @1085_479910
  X0[2] = 0;  // @1086_479910
  X0[3] = 0;  // @1087_479910
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @1088_479910
  PV[49] = X0[0]; PV[50] = X0[1];  // @1089_479910
  PV[51] = (u32)(esi);  // @1090_479910
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[51], (u32)(6859600), PV[49], PV[50], PV[48]);  // @1091_479910
  ecx = edx = 0;  // @1092_479910
  L47a413:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1790), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1094_479910
  if (FL[0] != FL[1]) goto L47a461;  // @1095_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @1096_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1097_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @1098_479910
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6858692), (u32)(1606));  // @1099_479910
  ecx = edx = 0;  // @1100_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1101_479910
  ecx = edi;  // @1102_479910
  esi = eax;  // @1103_479910
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @1104_479910
  eax = ((u32(THISCALL *)(u32))(edx))(ecx);  // @1105_479910
  ecx = edx = 0;  // @1106_479910
  edx = (u32)(6801640);  // @1107_479910
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @1108_479910
  FL[2] = (ecx & ecx);  // @1109_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @1110_479910
  if (FL[2] != 0) edx = ecx;  // @1111_479910
  PV[52] = (u32)(edx);  // @1112_479910
  PV[53] = (u32)(esi);  // @1113_479910
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[53], (u32)(6859648), PV[52]);  // @1114_479910
  ecx = edx = 0;  // @1115_479910
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1790), &v, sizeof v); }  // @1116_479910
  L47a461:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1118_479910
  ecx = edi;  // @1119_479910
  { u32 v = (u32)((u32)(1120403456)); __builtin_memcpy((void *)(u32)(edi + 1656), &v, sizeof v); }  // @1120_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1826), &v, sizeof v); }  // @1121_479910
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 1830), &v, sizeof v); }  // @1122_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1842), &v, sizeof v); }  // @1123_479910
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1839), &v, sizeof v); }  // @1124_479910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1524)))(ecx);  // @1125_479910
  ecx = edx = 0;  // @1126_479910
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1127_479910
  ecx = edi;  // @1128_479910
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1528)))(ecx);  // @1129_479910
  ecx = edx = 0;  // @1130_479910
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1612), sizeof v); (u32)v; }); FL[1] = (u32)(11);  // @1131_479910
  if (FL[0] != FL[1]) goto L47a4b4;  // @1132_479910
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 1612), &v, sizeof v); }  // @1133_479910
  L47a4b4:;
  ext_633654(G(u32, 0x6f5630));  // @1135_479910
  return eax;  // @1136_479910
}
PCREG(479910, lifted_479910);

