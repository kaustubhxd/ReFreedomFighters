// batch236005.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4f9680_thiscall2(u32, u32) __asm__("ext_4f9680");
extern "C" u32 THISCALL ext_561c60_thiscall1(u32) __asm__("ext_561c60");
extern "C" u32 THISCALL ext_562080_thiscall2(u32, u32) __asm__("ext_562080");
extern "C" u32 THISCALL ext_5621a0_thiscall2(u32, u32) __asm__("ext_5621a0");
extern "C" u32 ext_634dca_cdecl2(...) __asm__("ext_634dca");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_563da0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_563da0
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 137), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_563da0
  if (FL[0] == FL[1]) goto L563de4;  // @2_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_563da0
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 220), &v, sizeof v); }  // @4_563da0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @5_563da0
  ecx = edx = 0;  // @6_563da0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @7_563da0
  ext_633654(G(u32, 0x6f5630));  // @8_563da0
  return eax;  // @9_563da0
  L563de4:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 138), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @11_563da0
  if (FL[0] == FL[1]) goto L563e17;  // @12_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 224), sizeof v); (u32)v; });  // @13_563da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 220), &v, sizeof v); }  // @14_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_563da0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 232)))(ecx);  // @16_563da0
  ecx = edx = 0;  // @17_563da0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 138), &v, sizeof v); }  // @18_563da0
  ext_633654(G(u32, 0x6f5630));  // @19_563da0
  return eax;  // @20_563da0
  L563e17:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 100) + 0), 4); v; });  // @22_563da0
  X0[1] = 0;  // @23_563da0
  X0[2] = 0;  // @24_563da0
  X0[3] = 0;  // @25_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @26_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_563da0
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @28_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @29_563da0
  eax = (eax - ecx);  // @30_563da0
  FL[3] = eax;  // @31_563da0
  X2[0] = eax; X2[1] = X2[2] = X2[3] = 0;  // @32_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 220), sizeof v); (u32)v; });  // @33_563da0
  X2[0] = F2U((float)(s32)X2[0]);  // @34_563da0
  X2[1] = F2U((float)(s32)X2[1]);  // @35_563da0
  X2[2] = F2U((float)(s32)X2[2]);  // @36_563da0
  X2[3] = F2U((float)(s32)X2[3]);  // @37_563da0
  X2[0] = F2U(U2F(X2[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @38_563da0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @39_563da0
  FL[0] = eax; FL[1] = (u32)(7);  // @40_563da0
  if (FL[0] > FL[1]) goto L564431;  // @41_563da0
  switch (eax) {  // @42_563da0
  case 0: goto L563e5d;  // @43_563da0
  case 1: goto L563f7a;  // @44_563da0
  case 2: goto L564430;  // @45_563da0
  case 3: goto L564430;  // @46_563da0
  case 4: goto L56413b;  // @47_563da0
  case 5: goto L564430;  // @48_563da0
  case 6: goto L5642b4;  // @49_563da0
  case 7: goto L563f7a;  // @50_563da0
  default: __builtin_trap(); }  // @51_563da0
  L563e5d:;
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; });  // @53_563da0
  X3[1] = 0;  // @54_563da0
  X3[2] = 0;  // @55_563da0
  X3[3] = 0;  // @56_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @57_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @58_563da0
  if (((!(U2F(X3[0]) >= U2F(X2[0]))) || (!((U2F(X3[0]) < U2F(X2[0])) || (U2F(X3[0]) > U2F(X2[0])))))) goto L563f2b;  // @59_563da0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @60_563da0
  X3[0] = F2U(U2F(X3[0]) - U2F(X2[0]));  // @61_563da0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X3[0], 4);  // @62_563da0
  FL[2] = (edi & edi);  // @63_563da0
  if (FL[2] == 0) goto L563ee0;  // @64_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 104) + 0), 4); v; });  // @65_563da0
  X0[1] = 0;  // @66_563da0
  X0[2] = 0;  // @67_563da0
  X0[3] = 0;  // @68_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @69_563da0
  X1[1] = 0;  // @70_563da0
  X1[2] = 0;  // @71_563da0
  X1[3] = 0;  // @72_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @73_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @74_563da0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @75_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @76_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @77_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @78_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @79_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @80_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @81_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @82_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @83_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @84_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @85_563da0
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[0] = (u32)v_; PV[1] = (u32)(v_ >> 32); }  // @86_563da0
  eax = ext_634dca_cdecl2(PV[0], PV[1]);  // @87_563da0
    // @88_563da0
  ecx = (u32)(EBP - 16);  // @89_563da0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 12)) :: "st");  // @90_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @91_563da0
  PV[2] = (u32)(ecx);  // @92_563da0
  ecx = edi;  // @93_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[2]);  // @94_563da0
  ecx = edx = 0;  // @95_563da0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @96_563da0
  X3[1] = 0;  // @97_563da0
  X3[2] = 0;  // @98_563da0
  X3[3] = 0;  // @99_563da0
  L563ee0:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @101_563da0
  FL[2] = (edi & edi);  // @102_563da0
  if (FL[2] == 0) goto L564430;  // @103_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; });  // @104_563da0
  eax = (u32)(448);  // @105_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 104) + 0), 4); v; });  // @106_563da0
  X1[1] = 0;  // @107_563da0
  X1[2] = 0;  // @108_563da0
  X1[3] = 0;  // @109_563da0
  eax = (eax - ecx);  // @110_563da0
  FL[3] = eax;  // @111_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @112_563da0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @113_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @114_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @115_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @116_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @117_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @118_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @119_563da0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @120_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @121_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @122_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @123_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @124_563da0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @125_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @126_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @127_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @128_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @129_563da0
  goto L56437f;  // @130_563da0
  L563f2b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @132_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @133_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @134_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @135_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @136_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @137_563da0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @138_563da0
  FL[2] = (ecx & ecx);  // @139_563da0
  if (FL[2] == 0) goto L563f4b;  // @140_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_563da0
  edx = (u32)(EBP - 16);  // @142_563da0
  PV[3] = (u32)(edx);  // @143_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[3]);  // @144_563da0
  ecx = edx = 0;  // @145_563da0
  L563f4b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @147_563da0
  FL[2] = (ecx & ecx);  // @148_563da0
  if (FL[2] == 0) goto L563f5b;  // @149_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @150_563da0
  edx = (u32)(EBP - 16);  // @151_563da0
  PV[4] = (u32)(edx);  // @152_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[4]);  // @153_563da0
  ecx = edx = 0;  // @154_563da0
  L563f5b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @156_563da0
  X0[1] = 0;  // @157_563da0
  X0[2] = 0;  // @158_563da0
  X0[3] = 0;  // @159_563da0
  if ((!(!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799776) + 0), 4); v; })))) && !(!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799776) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799776) + 0), 4); v; }))))))) goto L5643e9;  // @160_563da0
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; })));  // @161_563da0
  goto L564423;  // @162_563da0
  L563f7a:;
  X0[0] = 0;  // @164_563da0
  X0[1] = 0;  // @165_563da0
  X0[2] = 0;  // @166_563da0
  X0[3] = 0;  // @167_563da0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))) ? 0x40 : 0)) << 8);  // @168_563da0
  FL[2] = ((u32)(0x02 | (!(U2F(X2[0]) >= U2F(X0[0])) ? 1 : 0) | (((U2F(X2[0]) != U2F(X2[0])) || (U2F(X0[0]) != U2F(X0[0]))) ? 4 : 0) | ((!((U2F(X2[0]) < U2F(X0[0])) || (U2F(X2[0]) > U2F(X0[0])))) ? 0x40 : 0)) & 68);  // @169_563da0
  if (!__builtin_parity(FL[2] & 0xff)) goto L563f97;  // @170_563da0
  ecx = (u32)(7343652);  // @171_563da0
  eax = ext_4f9680_thiscall2(ecx, (u32)(3));  // @172_563da0
  ecx = edx = 0;  // @173_563da0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @174_563da0
  X2[1] = 0;  // @175_563da0
  X2[2] = 0;  // @176_563da0
  X2[3] = 0;  // @177_563da0
  L563f97:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973568) + 0), 4); v; });  // @179_563da0
  X0[1] = 0;  // @180_563da0
  X0[2] = 0;  // @181_563da0
  X0[3] = 0;  // @182_563da0
  if ((!(!(U2F(X0[0]) >= U2F(X2[0]))) && !(!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L564148;  // @183_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @184_563da0
  ecx = esi;  // @185_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(0));  // @186_563da0
  ecx = edx = 0;  // @187_563da0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @188_563da0
  X2[1] = 0;  // @189_563da0
  X2[2] = 0;  // @190_563da0
  X2[3] = 0;  // @191_563da0
  X2[0] = F2U(U2F(X2[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973568) + 0), 4); v; })));  // @192_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; });  // @193_563da0
  X0[1] = 0;  // @194_563da0
  X0[2] = 0;  // @195_563da0
  X0[3] = 0;  // @196_563da0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @197_563da0
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L56408e;  // @198_563da0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @199_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @200_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @201_563da0
  FL[2] = (edi & edi);  // @202_563da0
  if (FL[2] == 0) goto L564040;  // @203_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 104) + 0), 4); v; });  // @204_563da0
  X0[1] = 0;  // @205_563da0
  X0[2] = 0;  // @206_563da0
  X0[3] = 0;  // @207_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @208_563da0
  X1[1] = 0;  // @209_563da0
  X1[2] = 0;  // @210_563da0
  X1[3] = 0;  // @211_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @212_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @213_563da0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @214_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @215_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @216_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @217_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @218_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @219_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @220_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @221_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @222_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @223_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @224_563da0
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[5] = (u32)v_; PV[6] = (u32)(v_ >> 32); }  // @225_563da0
  eax = ext_634dca_cdecl2(PV[5], PV[6]);  // @226_563da0
    // @227_563da0
  ecx = (u32)(EBP - 16);  // @228_563da0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 12)) :: "st");  // @229_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @230_563da0
  PV[7] = (u32)(ecx);  // @231_563da0
  ecx = edi;  // @232_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[7]);  // @233_563da0
  ecx = edx = 0;  // @234_563da0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @235_563da0
  X2[1] = 0;  // @236_563da0
  X2[2] = 0;  // @237_563da0
  X2[3] = 0;  // @238_563da0
  L564040:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @240_563da0
  FL[2] = (edi & edi);  // @241_563da0
  if (FL[2] == 0) goto L564430;  // @242_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @243_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; });  // @244_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 104) + 0), 4); v; });  // @245_563da0
  X1[1] = 0;  // @246_563da0
  X1[2] = 0;  // @247_563da0
  X1[3] = 0;  // @248_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @249_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; });  // @250_563da0
  eax = (eax - ecx);  // @251_563da0
  FL[3] = eax;  // @252_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @253_563da0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @254_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @255_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @256_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @257_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @258_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X0[0]));  // @259_563da0
  X0[0] = ecx; X0[1] = X0[2] = X0[3] = 0;  // @260_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @261_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @262_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @263_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @264_563da0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @265_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @266_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @267_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @268_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @269_563da0
  goto L56437f;  // @270_563da0
  L56408e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @272_563da0
  ecx = esi;  // @273_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(0));  // @274_563da0
  ecx = edx = 0;  // @275_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @276_563da0
  eax = (u32)(esi + 120);  // @277_563da0
  PV[8] = (u32)(eax);  // @278_563da0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @279_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[8]);  // @280_563da0
  ecx = edx = 0;  // @281_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @282_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @283_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @284_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @285_563da0
  FL[2] = (ecx & ecx);  // @286_563da0
  if (FL[2] == 0) goto L5640cb;  // @287_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @288_563da0
  edx = (u32)(EBP - 16);  // @289_563da0
  PV[9] = (u32)(edx);  // @290_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[9]);  // @291_563da0
  ecx = edx = 0;  // @292_563da0
  L5640cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @294_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @295_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 115), sizeof v); (u32)v; });  // @296_563da0
  eax = (eax + 1);  // @297_563da0
  FL[3] = eax;  // @298_563da0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @299_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @300_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @301_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @302_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @303_563da0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @304_563da0
  FL[2] = (ecx & ecx);  // @305_563da0
  if (FL[2] == 0) goto L5640f0;  // @306_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @307_563da0
  edx = (u32)(EBP - 16);  // @308_563da0
  PV[10] = (u32)(edx);  // @309_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[10]);  // @310_563da0
  ecx = edx = 0;  // @311_563da0
  L5640f0:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 220), sizeof v); (u32)v; }); FL[1] = (u32)(7);  // @313_563da0
  if (FL[0] != FL[1]) goto L56411a;  // @314_563da0
  ecx = esi;  // @315_563da0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 220), &v, sizeof v); }  // @316_563da0
  eax = ext_561c60_thiscall1(ecx);  // @317_563da0
  ecx = edx = 0;  // @318_563da0
  ext_633654(G(u32, 0x6f5630));  // @319_563da0
  return eax;  // @320_563da0
  L56411a:;
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 224), &v, sizeof v); }  // @322_563da0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 138), &v, sizeof v); }  // @323_563da0
  ext_633654(G(u32, 0x6f5630));  // @324_563da0
  return eax;  // @325_563da0
  L56413b:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973568) + 0), 4); v; });  // @327_563da0
  X0[1] = 0;  // @328_563da0
  X0[2] = 0;  // @329_563da0
  X0[3] = 0;  // @330_563da0
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L564165;  // @331_563da0
  L564148:;
  PV[11] = (u32)(ecx);  // @333_563da0
  ecx = esi;  // @334_563da0
  PV[12] = X2[0];  // @335_563da0
  eax = ext_562080_thiscall2(ecx, PV[12]);  // @336_563da0
  ecx = edx = 0;  // @337_563da0
  ext_633654(G(u32, 0x6f5630));  // @338_563da0
  return eax;  // @339_563da0
  L564165:;
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @341_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; });  // @342_563da0
  X0[1] = 0;  // @343_563da0
  X0[2] = 0;  // @344_563da0
  X0[3] = 0;  // @345_563da0
  __builtin_memcpy((void *)((u32)(EBP - 20) + 0), &X2[0], 4);  // @346_563da0
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L564223;  // @347_563da0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @348_563da0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973572) + 0), 4); v; });  // @349_563da0
  X3[1] = 0;  // @350_563da0
  X3[2] = 0;  // @351_563da0
  X3[3] = 0;  // @352_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @353_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @354_563da0
  FL[2] = (edi & edi);  // @355_563da0
  if (FL[2] == 0) goto L5641ec;  // @356_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 112) + 0), 4); v; });  // @357_563da0
  X1[1] = 0;  // @358_563da0
  X1[2] = 0;  // @359_563da0
  X1[3] = 0;  // @360_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @361_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @362_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @363_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @364_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @365_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @366_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X3[0]));  // @367_563da0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @368_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @369_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @370_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @371_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @372_563da0
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[13] = (u32)v_; PV[14] = (u32)(v_ >> 32); }  // @373_563da0
  eax = ext_634dca_cdecl2(PV[13], PV[14]);  // @374_563da0
    // @375_563da0
  ecx = (u32)(EBP - 16);  // @376_563da0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 12)) :: "st");  // @377_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @378_563da0
  PV[15] = (u32)(ecx);  // @379_563da0
  ecx = edi;  // @380_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[15]);  // @381_563da0
  ecx = edx = 0;  // @382_563da0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @383_563da0
  X2[1] = 0;  // @384_563da0
  X2[2] = 0;  // @385_563da0
  X2[3] = 0;  // @386_563da0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973572) + 0), 4); v; });  // @387_563da0
  X3[1] = 0;  // @388_563da0
  X3[2] = 0;  // @389_563da0
  X3[3] = 0;  // @390_563da0
  L5641ec:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @392_563da0
  FL[2] = (edi & edi);  // @393_563da0
  if (FL[2] == 0) goto L564430;  // @394_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 112) + 0), 4); v; });  // @395_563da0
  X0[1] = 0;  // @396_563da0
  X0[2] = 0;  // @397_563da0
  X0[3] = 0;  // @398_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X1[1] = X1[2] = X1[3] = 0;  // @399_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @400_563da0
  X1[0] = F2U((float)(s32)X1[0]);  // @401_563da0
  X1[1] = F2U((float)(s32)X1[1]);  // @402_563da0
  X1[2] = F2U((float)(s32)X1[2]);  // @403_563da0
  X1[3] = F2U((float)(s32)X1[3]);  // @404_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X3[0]));  // @405_563da0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @406_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @407_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @408_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @409_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @410_563da0
  goto L56437f;  // @411_563da0
  L564223:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @413_563da0
  ecx = esi;  // @414_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(0));  // @415_563da0
  ecx = edx = 0;  // @416_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @417_563da0
  eax = (u32)(esi + 120);  // @418_563da0
  PV[16] = (u32)(eax);  // @419_563da0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @420_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[16]);  // @421_563da0
  ecx = edx = 0;  // @422_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @423_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @424_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @425_563da0
  FL[2] = (ecx & ecx);  // @426_563da0
  if (FL[2] == 0) goto L56426e;  // @427_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; });  // @428_563da0
  edx = (u32)(EBP - 16);  // @429_563da0
  eax = (eax + (u32)(125));  // @430_563da0
  FL[3] = eax;  // @431_563da0
  PV[17] = (u32)(edx);  // @432_563da0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @433_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @434_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @435_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @436_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @437_563da0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @438_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @439_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[17]);  // @440_563da0
  ecx = edx = 0;  // @441_563da0
  L56426e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @443_563da0
  FL[2] = (ecx & ecx);  // @444_563da0
  if (FL[2] == 0) goto L564293;  // @445_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; });  // @446_563da0
  edx = (u32)(EBP - 16);  // @447_563da0
  eax = (eax - (u32)(125));  // @448_563da0
  FL[3] = eax;  // @449_563da0
  PV[18] = (u32)(edx);  // @450_563da0
  X0[0] = eax; X0[1] = X0[2] = X0[3] = 0;  // @451_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @452_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @453_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @454_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @455_563da0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @456_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @457_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[18]);  // @458_563da0
  ecx = edx = 0;  // @459_563da0
  L564293:;
  { u32 v = (u32)((u32)(5)); __builtin_memcpy((void *)(u32)(esi + 224), &v, sizeof v); }  // @461_563da0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 138), &v, sizeof v); }  // @462_563da0
  ext_633654(G(u32, 0x6f5630));  // @463_563da0
  return eax;  // @464_563da0
  L5642b4:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; });  // @466_563da0
  X0[1] = 0;  // @467_563da0
  X0[2] = 0;  // @468_563da0
  X0[3] = 0;  // @469_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @470_563da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @471_563da0
  if (((!(U2F(X0[0]) >= U2F(X2[0]))) || (!((U2F(X0[0]) < U2F(X2[0])) || (U2F(X0[0]) > U2F(X2[0])))))) goto L5643ab;  // @472_563da0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @473_563da0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @474_563da0
  X3[1] = 0;  // @475_563da0
  X3[2] = 0;  // @476_563da0
  X3[3] = 0;  // @477_563da0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973572) + 0), 4); v; });  // @478_563da0
  X4[1] = 0;  // @479_563da0
  X4[2] = 0;  // @480_563da0
  X4[3] = 0;  // @481_563da0
  FL[2] = (edi & edi);  // @482_563da0
  if (FL[2] == 0) goto L564349;  // @483_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 112) + 0), 4); v; });  // @484_563da0
  X0[1] = 0;  // @485_563da0
  X0[2] = 0;  // @486_563da0
  X0[3] = 0;  // @487_563da0
  X1[0] = X3[0];  // @488_563da0
  X1[1] = X3[1];  // @489_563da0
  X1[2] = X3[2];  // @490_563da0
  X1[3] = X3[3];  // @491_563da0
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @492_563da0
  X1[0] = F2U(U2F(X1[0]) - U2F(X0[0]));  // @493_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @494_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @495_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @496_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @497_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @498_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @499_563da0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @500_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @501_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @502_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @503_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @504_563da0
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[19] = (u32)v_; PV[20] = (u32)(v_ >> 32); }  // @505_563da0
  eax = ext_634dca_cdecl2(PV[19], PV[20]);  // @506_563da0
    // @507_563da0
  ecx = (u32)(EBP - 16);  // @508_563da0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 12)) :: "st");  // @509_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @510_563da0
  PV[21] = (u32)(ecx);  // @511_563da0
  ecx = edi;  // @512_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[21]);  // @513_563da0
  ecx = edx = 0;  // @514_563da0
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @515_563da0
  X2[1] = 0;  // @516_563da0
  X2[2] = 0;  // @517_563da0
  X2[3] = 0;  // @518_563da0
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @519_563da0
  X3[1] = 0;  // @520_563da0
  X3[2] = 0;  // @521_563da0
  X3[3] = 0;  // @522_563da0
  X4[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6973572) + 0), 4); v; });  // @523_563da0
  X4[1] = 0;  // @524_563da0
  X4[2] = 0;  // @525_563da0
  X4[3] = 0;  // @526_563da0
  L564349:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @528_563da0
  FL[2] = (edi & edi);  // @529_563da0
  if (FL[2] == 0) goto L564430;  // @530_563da0
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 112) + 0), 4); v; });  // @531_563da0
  X1[1] = 0;  // @532_563da0
  X1[2] = 0;  // @533_563da0
  X1[3] = 0;  // @534_563da0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @535_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X2[0]));  // @536_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @537_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @538_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @539_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @540_563da0
  X1[0] = F2U(U2F(X1[0]) - U2F(X3[0]));  // @541_563da0
  X1[0] = F2U(U2F(X1[0]) * U2F(X4[0]));  // @542_563da0
  X1[0] = F2U(U2F(X1[0]) + U2F(X0[0]));  // @543_563da0
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @544_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 0), &X0[0], 4);  // @545_563da0
  __builtin_memcpy((void *)((u32)(EBP - 28) + 4), &X0[1], 4);  // @546_563da0
  __asm__ volatile("fldl %0" :: "m"(*(double *)(u32)(EBP - 28)) : "st");  // @547_563da0
  L56437f:;
  { double d_; __asm__ volatile("fstpl %0" : "=m"(d_) :: "st"); u64 v_; __builtin_memcpy(&v_, &d_, 8); PV[22] = (u32)v_; PV[23] = (u32)(v_ >> 32); }  // @549_563da0
  eax = ext_634dca_cdecl2(PV[22], PV[23]);  // @550_563da0
    // @551_563da0
  ecx = (u32)(EBP - 16);  // @552_563da0
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 12)) :: "st");  // @553_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @554_563da0
  PV[24] = (u32)(ecx);  // @555_563da0
  ecx = edi;  // @556_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[24]);  // @557_563da0
  ecx = edx = 0;  // @558_563da0
  ext_633654(G(u32, 0x6f5630));  // @559_563da0
  return eax;  // @560_563da0
  L5643ab:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 139), sizeof v); (u32)v; }); X0[1] = X0[2] = X0[3] = 0;  // @562_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @563_563da0
  X0[0] = F2U((float)(s32)X0[0]);  // @564_563da0
  X0[1] = F2U((float)(s32)X0[1]);  // @565_563da0
  X0[2] = F2U((float)(s32)X0[2]);  // @566_563da0
  X0[3] = F2U((float)(s32)X0[3]);  // @567_563da0
  __builtin_memcpy((void *)((u32)(EBP - 12) + 0), &X0[0], 4);  // @568_563da0
  FL[2] = (ecx & ecx);  // @569_563da0
  if (FL[2] == 0) goto L5643cb;  // @570_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @571_563da0
  edx = (u32)(EBP - 16);  // @572_563da0
  PV[25] = (u32)(edx);  // @573_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[25]);  // @574_563da0
  ecx = edx = 0;  // @575_563da0
  L5643cb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @577_563da0
  FL[2] = (ecx & ecx);  // @578_563da0
  if (FL[2] == 0) goto L5643db;  // @579_563da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @580_563da0
  edx = (u32)(EBP - 16);  // @581_563da0
  PV[26] = (u32)(edx);  // @582_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[26]);  // @583_563da0
  ecx = edx = 0;  // @584_563da0
  L5643db:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 20) + 0), 4); v; });  // @586_563da0
  X0[1] = 0;  // @587_563da0
  X0[2] = 0;  // @588_563da0
  X0[3] = 0;  // @589_563da0
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799772) + 0), 4); v; }))))))) goto L56441b;  // @590_563da0
  L5643e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @592_563da0
  ecx = esi;  // @593_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(254));  // @594_563da0
  ecx = edx = 0;  // @595_563da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 84), sizeof v); (u32)v; });  // @596_563da0
  eax = (u32)(esi + 120);  // @597_563da0
  PV[27] = (u32)(eax);  // @598_563da0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @599_563da0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 112)))(ecx, PV[27]);  // @600_563da0
  ecx = edx = 0;  // @601_563da0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }  // @602_563da0
  ext_633654(G(u32, 0x6f5630));  // @603_563da0
  return eax;  // @604_563da0
  L56441b:;
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6799764) + 0), 4); v; })));  // @606_563da0
  L564423:;
  PV[28] = (u32)(ecx);  // @608_563da0
  ecx = esi;  // @609_563da0
  PV[29] = X0[0];  // @610_563da0
  eax = ext_5621a0_thiscall2(ecx, PV[29]);  // @611_563da0
  ecx = edx = 0;  // @612_563da0
  L564430:;
  L564431:;
  ext_633654(G(u32, 0x6f5630));  // @615_563da0
  return eax;  // @616_563da0
}
PCREG(563da0, lifted_563da0);

