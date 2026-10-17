// batch244030.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_446ee0_fastcall3(u32, u32, u32) __asm__("ext_446ee0");
extern "C" u32 FASTCALL ext_539eb0_fastcall5(u32, u32, u32, u32, u32) __asm__("ext_539eb0");
extern "C" u32 THISCALL ext_54a0e0_thiscall3(u32, u32, u32) __asm__("ext_54a0e0");
extern "C" u32 THISCALL ext_54a170_thiscall3(u32, u32, u32) __asm__("ext_54a170");
extern "C" u32 THISCALL ext_44c2b0_thiscall1(u32) __asm__("ext_44c2b0");
extern "C" u32 THISCALL ext_44c370_thiscall1(u32) __asm__("ext_44c370");
extern "C" u32 THISCALL ext_5378a0_thiscall1(u32) __asm__("ext_5378a0");
extern "C" u32 THISCALL ext_54abf0_thiscall1(u32) __asm__("ext_54abf0");
extern "C" u32 THISCALL ext_54e1f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_54e1f0");
extern "C" u32 ext_401f20_cdecl2(...) __asm__("ext_401f20");
extern "C" u32 ext_402290_cdecl2(...) __asm__("ext_402290");
extern "C" u32 ext_4022f0_cdecl2(...) __asm__("ext_4022f0");
extern "C" u32 ext_402320_cdecl2(...) __asm__("ext_402320");
extern "C" u32 ext_4104c0_cdecl2(...) __asm__("ext_4104c0");
extern "C" u32 ext_410540_cdecl2(...) __asm__("ext_410540");
extern "C" u32 ext_4106b0_cdecl2(...) __asm__("ext_4106b0");
extern "C" u32 ext_4106f0_cdecl2(...) __asm__("ext_4106f0");
extern "C" u32 ext_410a00_cdecl2(...) __asm__("ext_410a00");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4a3e80(u32 ecx_in) {
  u32 nm_ = 0;
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_4a3e80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @1_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_4a3e80
  if (FL[0] == FL[1]) goto L4a3e99;  // @3_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 474), &v, sizeof v); }  // @4_4a3e80
  L4a3e99:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 474), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @6_4a3e80
  if (FL[0] != FL[1]) goto L4a420f;  // @7_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 436) + 0), 4); v; });  // @9_4a3e80
  X0[1] = 0;  // @10_4a3e80
  X0[2] = 0;  // @11_4a3e80
  X0[3] = 0;  // @12_4a3e80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784544) + 0), 4); v; })));  // @13_4a3e80
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @14_4a3e80
  ecx = esi;  // @15_4a3e80
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); eax = (u32)r_; }  // @16_4a3e80
  ecx = (ecx - eax);  // @17_4a3e80
  FL[3] = ecx;  // @18_4a3e80
  FL[0] = ecx; FL[1] = (u32)(71);  // @19_4a3e80
  if ((s32)FL[0] <= (s32)FL[1]) goto L4a420e;  // @20_4a3e80
  X0[0] = esi; X0[1] = X0[2] = X0[3] = 0;  // @21_4a3e80
  X0[0] = F2U((float)(s32)X0[0]);  // @22_4a3e80
  X0[1] = F2U((float)(s32)X0[1]);  // @23_4a3e80
  X0[2] = F2U((float)(s32)X0[2]);  // @24_4a3e80
  X0[3] = F2U((float)(s32)X0[3]);  // @25_4a3e80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784484) + 0), 4); v; })));  // @26_4a3e80
  __builtin_memcpy((void *)((u32)(edi + 436) + 0), &X0[0], 4);  // @27_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @28_4a3e80
  if (FL[0] == FL[1]) goto L4a3f04;  // @29_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @30_4a3e80
  if (FL[0] != FL[1]) goto L4a3f04;  // @31_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 472), &v, sizeof v); }  // @32_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @33_4a3e80
  L4a3f04:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4a3e80
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @36_4a3e80
  FL[3] = (ebx & 0xff);  // @37_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @38_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4a3e80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @40_4a3e80
  ecx = edx = 0;  // @41_4a3e80
  ecx = (u32)(EBP - 4);  // @42_4a3e80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @43_4a3e80
  PV[0] = (u32)(ecx);  // @44_4a3e80
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_4a3e80
  ecx = eax;  // @46_4a3e80
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6880492), PV[0]);  // @47_4a3e80
  ecx = edx = 0;  // @48_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @49_4a3e80
  eax = (u32)(1);  // @50_4a3e80
  FL[2] = (ecx & ecx);  // @51_4a3e80
  if (FL[2] == 0) ecx = eax;  // @52_4a3e80
  eax = 0;  // @53_4a3e80
  FL[3] = eax;  // @54_4a3e80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @55_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @56_4a3e80
  FL[2] = (ecx & ecx);  // @57_4a3e80
  if ((s32)FL[2] <= 0) goto L4a4009;  // @58_4a3e80
  L4a3f51:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @60_4a3e80
  ecx = edi;  // @61_4a3e80
  PV[1] = (u32)(eax);  // @62_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 136)))(ecx, PV[1]);  // @63_4a3e80
  ecx = edx = 0;  // @64_4a3e80
  PV[2] = (u32)(eax);  // @65_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 132), sizeof v); (u32)v; });  // @66_4a3e80
  ecx = edi;  // @67_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, PV[2]);  // @68_4a3e80
  ecx = edx = 0;  // @69_4a3e80
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @70_4a3e80
  ebx = (ebx & 0xff);  // @71_4a3e80
  eax = (u32)(1);  // @72_4a3e80
  if (FL[2] != 0) ebx = eax;  // @73_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @74_4a3e80
  eax = (eax + 1);  // @75_4a3e80
  FL[3] = eax;  // @76_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @77_4a3e80
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @78_4a3e80
  if ((s32)FL[0] < (s32)FL[1]) goto L4a3f51;  // @79_4a3e80
  FL[2] = ((ebx & 0xff) & (ebx & 0xff));  // @80_4a3e80
  if (FL[2] == 0) goto L4a4009;  // @81_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 444) + 0), 4); v; });  // @82_4a3e80
  X0[1] = 0;  // @83_4a3e80
  X0[2] = 0;  // @84_4a3e80
  X0[3] = 0;  // @85_4a3e80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @86_4a3e80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @87_4a3e80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4a3fcb;  // @88_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @89_4a3e80
  if (FL[0] != FL[1]) goto L4a3fcb;  // @90_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @91_4a3e80
  eax = ext_44c2b0_thiscall1(ecx);  // @92_4a3e80
  ecx = edx = 0;  // @93_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @94_4a3e80
  FL[2] = (ecx & ecx);  // @95_4a3e80
  if (FL[2] == 0) goto L4a3fbd;  // @96_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_4a3e80
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @98_4a3e80
  ecx = edx = 0;  // @99_4a3e80
  L4a3fbd:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 472), &v, sizeof v); }  // @101_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @102_4a3e80
  L4a3fcb:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 473), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @104_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @105_4a3e80
  X0[1] = 0;  // @106_4a3e80
  X0[2] = 0;  // @107_4a3e80
  X0[3] = 0;  // @108_4a3e80
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 448) + 0), 4); v; })));  // @109_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_4a3e80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @111_4a3e80
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 444) + 0), 4); v; })));  // @112_4a3e80
  __builtin_memcpy((void *)((u32)(edi + 444) + 0), &X0[0], 4);  // @113_4a3e80
  if (FL[0] != FL[1]) goto L4a4053;  // @114_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 473), &v, sizeof v); }  // @115_4a3e80
  nm_ = 1; goto L4a4049;  // @116_4a3e80
  L4a4009:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 473), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @118_4a3e80
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @119_4a3e80
  X1[1] = 0;  // @120_4a3e80
  X1[2] = 0;  // @121_4a3e80
  X1[3] = 0;  // @122_4a3e80
  X1[0] = F2U(U2F(X1[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 452) + 0), 4); v; })));  // @123_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 444) + 0), 4); v; });  // @125_4a3e80
  X0[1] = 0;  // @126_4a3e80
  X0[2] = 0;  // @127_4a3e80
  X0[3] = 0;  // @128_4a3e80
  X1[0] = F2U(U2F(X1[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @129_4a3e80
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @130_4a3e80
  __builtin_memcpy((void *)((u32)(edi + 444) + 0), &X0[0], 4);  // @131_4a3e80
  if (FL[0] == FL[1]) goto L4a4053;  // @132_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 473), &v, sizeof v); } nm_ = 0;  // @133_4a3e80
  L4a4049:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @135_4a3e80
  ecx = edi;  // @136_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, nm_);  // @137_4a3e80
  ecx = edx = 0;  // @138_4a3e80
  L4a4053:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 444) + 0), 4); v; });  // @140_4a3e80
  X0[1] = 0;  // @141_4a3e80
  X0[2] = 0;  // @142_4a3e80
  X0[3] = 0;  // @143_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 476), &v, sizeof v); }  // @144_4a3e80
  if (((!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; })))) || (!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; }))))))) goto L4a4078;  // @145_4a3e80
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(edi + 444), &v, sizeof v); }  // @146_4a3e80
  goto L4a40d2;  // @147_4a3e80
  L4a4078:;
  X1[0] = 0;  // @149_4a3e80
  X1[1] = 0;  // @150_4a3e80
  X1[2] = 0;  // @151_4a3e80
  X1[3] = 0;  // @152_4a3e80
  if ((!(U2F(X1[0]) >= U2F(X0[0])))) goto L4a40d9;  // @153_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 472), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @154_4a3e80
  if (FL[0] == FL[1]) goto L4a40c8;  // @155_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @156_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @157_4a3e80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 132), &v, sizeof v); }  // @158_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @159_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 32), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @160_4a3e80
  if (FL[0] == FL[1]) goto L4a40a7;  // @161_4a3e80
  eax = ext_44c370_thiscall1(ecx);  // @162_4a3e80
  ecx = edx = 0;  // @163_4a3e80
  L4a40a7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @165_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 472), &v, sizeof v); }  // @166_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @167_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @168_4a3e80
  FL[2] = (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) & (u32)(8));  // @169_4a3e80
  if (FL[2] != 0) goto L4a40c8;  // @170_4a3e80
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 474), &v, sizeof v); }  // @171_4a3e80
  L4a40c8:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 444), &v, sizeof v); }  // @173_4a3e80
  L4a40d2:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 476), &v, sizeof v); }  // @175_4a3e80
  L4a40d9:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 476), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @177_4a3e80
  if (FL[0] == FL[1]) goto L4a41db;  // @178_4a3e80
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 475), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @179_4a3e80
  if (FL[0] != FL[1]) goto L4a4128;  // @180_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @181_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 440) + 0), 4); v; });  // @182_4a3e80
  X0[1] = 0;  // @183_4a3e80
  X0[2] = 0;  // @184_4a3e80
  X0[3] = 0;  // @185_4a3e80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @186_4a3e80
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @187_4a3e80
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 132) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @188_4a3e80
  if (!__builtin_parity(FL[2] & 0xff)) goto L4a4128;  // @189_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 444), sizeof v); (u32)v; });  // @190_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 132), &v, sizeof v); }  // @191_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 444), sizeof v); (u32)v; });  // @192_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 440), &v, sizeof v); }  // @193_4a3e80
  return eax;  // @194_4a3e80
  L4a4128:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @196_4a3e80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 475), &v, sizeof v); }  // @197_4a3e80
  FL[2] = (ecx & ecx);  // @198_4a3e80
  if (FL[2] == 0) goto L4a414d;  // @199_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @200_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(0));  // @201_4a3e80
  ecx = edx = 0;  // @202_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @203_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 210) + 0), 4); v; });  // @204_4a3e80
  X0[1] = 0;  // @205_4a3e80
  X0[2] = 0;  // @206_4a3e80
  X0[3] = 0;  // @207_4a3e80
  goto L4a4184;  // @208_4a3e80
  L4a414d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @210_4a3e80
  FL[2] = (ecx & ecx);  // @211_4a3e80
  if (FL[2] == 0) goto L4a416b;  // @212_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @213_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(0));  // @214_4a3e80
  ecx = edx = 0;  // @215_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @216_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 213) + 0), 4); v; });  // @217_4a3e80
  X0[1] = 0;  // @218_4a3e80
  X0[2] = 0;  // @219_4a3e80
  X0[3] = 0;  // @220_4a3e80
  goto L4a4184;  // @221_4a3e80
  L4a416b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @223_4a3e80
  FL[2] = (ecx & ecx);  // @224_4a3e80
  if (FL[2] == 0) goto L4a41ac;  // @225_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @226_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(0));  // @227_4a3e80
  ecx = edx = 0;  // @228_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @229_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 121) + 0), 4); v; });  // @230_4a3e80
  X0[1] = 0;  // @231_4a3e80
  X0[2] = 0;  // @232_4a3e80
  X0[3] = 0;  // @233_4a3e80
  L4a4184:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @235_4a3e80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 444) + 0), 4); v; })));  // @236_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 24), sizeof v); (u32)v; });  // @237_4a3e80
  __builtin_memcpy((void *)((u32)(eax + 132) + 0), &X0[0], 4);  // @238_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 444), sizeof v); (u32)v; });  // @239_4a3e80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 440), &v, sizeof v); }  // @240_4a3e80
  return eax;  // @241_4a3e80
  L4a41ac:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @243_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @244_4a3e80
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 132) + 0), 4); v; });  // @245_4a3e80
  X0[1] = 0;  // @246_4a3e80
  X0[2] = 0;  // @247_4a3e80
  X0[3] = 0;  // @248_4a3e80
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 444) + 0), 4); v; })));  // @249_4a3e80
  __builtin_memcpy((void *)((u32)(edi + 440) + 0), &X0[0], 4);  // @250_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @251_4a3e80
  __builtin_memcpy((void *)((u32)(eax + 132) + 0), &X0[0], 4);  // @252_4a3e80
  return eax;  // @253_4a3e80
  L4a41db:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 72), sizeof v); (u32)v; });  // @255_4a3e80
  FL[2] = (ecx & ecx);  // @256_4a3e80
  if (FL[2] == 0) goto L4a41ec;  // @257_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @258_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 140)))(ecx, (u32)(1));  // @259_4a3e80
  ecx = edx = 0;  // @260_4a3e80
  L4a41ec:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 76), sizeof v); (u32)v; });  // @262_4a3e80
  FL[2] = (ecx & ecx);  // @263_4a3e80
  if (FL[2] == 0) goto L4a41fd;  // @264_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @265_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 144)))(ecx, (u32)(1));  // @266_4a3e80
  ecx = edx = 0;  // @267_4a3e80
  L4a41fd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 80), sizeof v); (u32)v; });  // @269_4a3e80
  FL[2] = (ecx & ecx);  // @270_4a3e80
  if (FL[2] == 0) goto L4a420e;  // @271_4a3e80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @272_4a3e80
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(1));  // @273_4a3e80
  ecx = edx = 0;  // @274_4a3e80
  L4a420e:;
  L4a420f:;
  return eax;  // @277_4a3e80
}
PCREG(4a3e80, lifted_4a3e80);

extern "C" u32 THISCALL lifted_5335d0(u32 ecx_in) {
  SEH_ENTER(0x66a7a2);  // @h_5335d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5335d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5335d0
  edx = (u32)(EBP - 20);  // @3_5335d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_5335d0
  PV[0] = (u32)(edx);  // @5_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @7_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953228), PV[0]);  // @8_5335d0
  ecx = edx = 0;  // @9_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @10_5335d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @11_5335d0
  edx = (u32)(EBP - 20);  // @12_5335d0
  eax = (eax & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @13_5335d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 134), &v, sizeof v); }  // @14_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_5335d0
  PV[1] = (u32)(edx);  // @16_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @18_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953240), PV[1]);  // @19_5335d0
  ecx = edx = 0;  // @20_5335d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775512), sizeof v); (u32)v; });  // @21_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @22_5335d0
  if (FL[2] == 0) goto L53365c;  // @23_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @24_5335d0
  FL[2] = (eax & eax);  // @25_5335d0
  if (FL[2] == 0) goto L53365c;  // @26_5335d0
  PV[2] = (u32)(eax);  // @27_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[2]);  // @28_5335d0
  ecx = edx = 0;  // @29_5335d0
  FL[2] = (eax & eax);  // @30_5335d0
  { u8 v = (u8)(((FL[2] != 0) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @31_5335d0
  L53365c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_5335d0
  edx = (u32)(EBP - 20);  // @34_5335d0
  PV[3] = (u32)(edx);  // @35_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @37_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953260), PV[3]);  // @38_5335d0
  ecx = edx = 0;  // @39_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @40_5335d0
  if (FL[2] == 0) goto L533683;  // @41_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @42_5335d0
  FL[2] = (eax & eax);  // @43_5335d0
  if (FL[2] == 0) goto L533683;  // @44_5335d0
  PV[4] = (u32)(eax);  // @45_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[4]);  // @46_5335d0
  ecx = edx = 0;  // @47_5335d0
  L533683:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_5335d0
  edx = (u32)(EBP - 20);  // @50_5335d0
  PV[5] = (u32)(edx);  // @51_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @52_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @53_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953276), PV[5]);  // @54_5335d0
  ecx = edx = 0;  // @55_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @56_5335d0
  if (FL[2] == 0) goto L5336aa;  // @57_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @58_5335d0
  FL[2] = (eax & eax);  // @59_5335d0
  if (FL[2] == 0) goto L5336aa;  // @60_5335d0
  PV[6] = (u32)(eax);  // @61_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[6]);  // @62_5335d0
  ecx = edx = 0;  // @63_5335d0
  L5336aa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_5335d0
  edx = (u32)(EBP - 20);  // @66_5335d0
  PV[7] = (u32)(edx);  // @67_5335d0
  esi = (u32)(4);  // @68_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @70_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953296), PV[7]);  // @71_5335d0
  ecx = edx = 0;  // @72_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @73_5335d0
  if (FL[2] == 0) goto L5336ee;  // @74_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @75_5335d0
  FL[2] = (eax & eax);  // @76_5335d0
  if (FL[2] == 0) goto L5336ee;  // @77_5335d0
  PV[8] = (u32)(eax);  // @78_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[8]);  // @79_5335d0
  ecx = edx = 0;  // @80_5335d0
  esi = eax;  // @81_5335d0
  FL[0] = esi; FL[1] = (u32)(1);  // @82_5335d0
  if ((s32)FL[0] >= (s32)FL[1]) goto L5336e4;  // @83_5335d0
  esi = (u32)(1);  // @84_5335d0
  goto L5336ee;  // @85_5335d0
  L5336e4:;
  eax = (u32)(4);  // @87_5335d0
  FL[0] = esi; FL[1] = eax;  // @88_5335d0
  if ((s32)FL[0] > (s32)FL[1]) esi = eax;  // @89_5335d0
  L5336ee:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @91_5335d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 21634), &v, sizeof v); }  // @92_5335d0
  if (FL[0] == FL[1]) goto L5337a5;  // @93_5335d0
  eax = ext_41e290_cdecl1((u32)(41693));  // @94_5335d0
  ecx = edx = 0;  // @95_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @96_5335d0
  reg.state = (s32)((u32)(0));  // @97_5335d0
  FL[2] = (eax & eax);  // @98_5335d0
  if (FL[2] == 0) goto L533724;  // @99_5335d0
  ecx = eax;  // @100_5335d0
  eax = ext_54abf0_thiscall1(ecx);  // @101_5335d0
  ecx = edx = 0;  // @102_5335d0
  edi = eax;  // @103_5335d0
  goto L533726;  // @104_5335d0
  L533724:;
  edi = 0;  // @106_5335d0
  FL[3] = edi;  // @107_5335d0
  L533726:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @109_5335d0
  ecx = edi;  // @110_5335d0
  reg.state = (s32)((u32)(4294967295));  // @111_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @112_5335d0
  ecx = edx = 0;  // @113_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_5335d0
  esi = eax;  // @115_5335d0
  eax = (u32)(EBP - 20);  // @116_5335d0
  PV[9] = (u32)(eax);  // @117_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @118_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 92), sizeof v); (u32)v; });  // @119_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6953312), PV[9]);  // @120_5335d0
  ecx = edx = 0;  // @121_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @122_5335d0
  ecx = edi;  // @123_5335d0
  eax = (eax & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @124_5335d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 202), &v, sizeof v); }  // @125_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @126_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 172), sizeof v); (u32)v; });  // @127_5335d0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @128_5335d0
  ecx = edx = 0;  // @129_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @130_5335d0
  if (FL[2] == 0) goto L533799;  // @131_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @132_5335d0
  ecx = edi;  // @133_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @134_5335d0
  ecx = edx = 0;  // @135_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @136_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @137_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 21602), &v, sizeof v); }  // @138_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @139_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 21602), sizeof v); (u32)v; });  // @140_5335d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @141_5335d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 21614), &v, sizeof v); }  // @142_5335d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @143_5335d0
  L533799:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @145_5335d0
  ecx = edi;  // @146_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(1));  // @147_5335d0
  ecx = edx = 0;  // @148_5335d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @149_5335d0
  L5337a5:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775112), sizeof v); (u32)v; });  // @151_5335d0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(esi))((u32)(0), (u32)(0), (u32)(1), (u32)(0));  // @152_5335d0
  ecx = edx = 0;  // @153_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7347048), &v, sizeof v); }  // @154_5335d0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(esi))((u32)(0), (u32)(1), (u32)(1), (u32)(0));  // @155_5335d0
  ecx = edx = 0;  // @156_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @157_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7347052), &v, sizeof v); }  // @158_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @160_5335d0
  ecx = edx = 0;  // @161_5335d0
  esi = eax;  // @162_5335d0
  FL[2] = (esi & esi);  // @163_5335d0
  if (FL[2] == 0) goto L53388c;  // @164_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @165_5335d0
  edx = (u32)(EBP - 24);  // @166_5335d0
  PV[10] = (u32)(edx);  // @167_5335d0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @168_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @169_5335d0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @170_5335d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @171_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @172_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6792084), PV[10]);  // @173_5335d0
  ecx = edx = 0;  // @174_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @175_5335d0
  if (FL[2] == 0) goto L53381b;  // @176_5335d0
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @177_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[11]);  // @178_5335d0
  ecx = edx = 0;  // @179_5335d0
  FL[2] = (eax & eax);  // @180_5335d0
  { u8 v = (u8)(((FL[2] != 0) ? 1 : 0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @181_5335d0
  L53381b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_5335d0
  edx = (u32)(EBP - 24);  // @184_5335d0
  PV[12] = (u32)(edx);  // @185_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @186_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @187_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6792092), PV[12]);  // @188_5335d0
  ecx = edx = 0;  // @189_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @190_5335d0
  if (FL[2] == 0) goto L533840;  // @191_5335d0
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @192_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[13]);  // @193_5335d0
  ecx = edx = 0;  // @194_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @195_5335d0
  L533840:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @197_5335d0
  eax = (u32)(EBP - 24);  // @198_5335d0
  PV[14] = (u32)(eax);  // @199_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @200_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 92), sizeof v); (u32)v; });  // @201_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6791240), PV[14]);  // @202_5335d0
  ecx = edx = 0;  // @203_5335d0
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @204_5335d0
  if (FL[2] == 0) goto L533865;  // @205_5335d0
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @206_5335d0
  eax = ((u32( *)(u32))(ebx))(PV[15]);  // @207_5335d0
  ecx = edx = 0;  // @208_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @209_5335d0
  L533865:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @211_5335d0
  ecx = esi;  // @212_5335d0
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @213_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 232)))(ecx, PV[16]);  // @214_5335d0
  ecx = edx = 0;  // @215_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @216_5335d0
  ecx = esi;  // @217_5335d0
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @218_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 228)))(ecx, PV[17]);  // @219_5335d0
  ecx = edx = 0;  // @220_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @221_5335d0
  ecx = esi;  // @222_5335d0
  PV[18] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; });  // @223_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, PV[18]);  // @224_5335d0
  ecx = edx = 0;  // @225_5335d0
  L53388c:;
  ecx = edi;  // @227_5335d0
  eax = ext_5378a0_thiscall1(ecx);  // @228_5335d0
  ecx = edx = 0;  // @229_5335d0
  SEH_LEAVE();  // @230_5335d0
  return eax;  // @231_5335d0
}
PCREG(5335d0, lifted_5335d0);

extern "C" u32 THISCALL lifted_54a760(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_54a760
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6910676) + 0), 4); v; });  // @1_54a760
  X1[1] = 0;  // @2_54a760
  X1[2] = 0;  // @3_54a760
  X1[3] = 0;  // @4_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_54a760
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @6_54a760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @7_54a760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @8_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8982), sizeof v); (u32)v; });  // @9_54a760
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @10_54a760
  { s32 d_ = (s32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8701), sizeof v); (u32)v; })); s32 q_, r_; __asm__ volatile("idivl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = (u32)q_; edx = (u32)r_; }  // @11_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8257), &v, sizeof v); }  // @12_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @13_54a760
  eax = (eax - (u32)(1));  // @14_54a760
  FL[3] = eax;  // @15_54a760
  if (FL[3] == 0) goto L54a7ab;  // @16_54a760
  eax = (eax - (u32)(2));  // @17_54a760
  FL[3] = eax;  // @18_54a760
  if (FL[3] == 0) goto L54a7f2;  // @19_54a760
  goto L54a8ea;  // @20_54a760
  L54a7ab:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @22_54a760
  L54a7b2:;
  eax = (u32)(esi + 37);  // @24_54a760
  PV[0] = (u32)(eax);  // @25_54a760
  eax = (u32)(esi + 8745);  // @26_54a760
  PV[1] = (u32)(eax);  // @27_54a760
  eax = ext_402290_cdecl2(PV[1], PV[0]);  // @28_54a760
  ecx = edx = 0;  // @29_54a760
  ecx = eax;  // @30_54a760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 41), &v, sizeof v); }  // @31_54a760
  FL[2] = (ecx & ecx);  // @32_54a760
  if ((s32)FL[2] <= 0) goto L54a8c2;  // @33_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8257), sizeof v); (u32)v; });  // @34_54a760
  FL[0] = ecx; FL[1] = eax;  // @35_54a760
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6910676) + 0), 4); v; });  // @36_54a760
  X1[1] = 0;  // @37_54a760
  X1[2] = 0;  // @38_54a760
  X1[3] = 0;  // @39_54a760
  if ((s32)FL[0] < (s32)FL[1]) eax = ecx;  // @40_54a760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @41_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @42_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 53), &v, sizeof v); }  // @43_54a760
  L54a7f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 37), sizeof v); (u32)v; });  // @45_54a760
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_54a760
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @47_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @48_54a760
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 53), sizeof v); (u32)v; });  // @49_54a760
  if ((s32)FL[0] >= (s32)FL[1]) goto L54a8a4;  // @50_54a760
  L54a810:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @52_54a760
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = eax;  // @53_54a760
  if (FL[0] == FL[1]) goto L54aa86;  // @54_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @55_54a760
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + eax*4) + 0), 4); v; });  // @56_54a760
  X0[1] = 0;  // @57_54a760
  X0[2] = 0;  // @58_54a760
  X0[3] = 0;  // @59_54a760
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @60_54a760
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); edx = (u32)r_; }  // @61_54a760
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + eax*4) + 0), 4); v; });  // @62_54a760
  X0[1] = 0;  // @63_54a760
  X0[2] = 0;  // @64_54a760
  X0[3] = 0;  // @65_54a760
  eax = (u32)(32767);  // @66_54a760
  X0[0] = F2U(U2F(X0[0]) * U2F(X1[0]));  // @67_54a760
  { float f_ = U2F(X0[0]); s32 r_; __asm__("cvttss2si %1, %0" : "=r"(r_) : "x"(f_)); ecx = (u32)r_; }  // @68_54a760
  FL[0] = edx; FL[1] = (u32)(4294934528);  // @69_54a760
  if ((s32)FL[0] >= (s32)FL[1]) goto L54a84c;  // @70_54a760
  edx = (u32)(4294934528);  // @71_54a760
  goto L54a855;  // @72_54a760
  L54a84c:;
  FL[0] = edx; FL[1] = (u32)(32767);  // @74_54a760
  if ((s32)FL[0] > (s32)FL[1]) edx = eax;  // @75_54a760
  L54a855:;
  FL[0] = ecx; FL[1] = (u32)(4294934528);  // @77_54a760
  if ((s32)FL[0] >= (s32)FL[1]) goto L54a864;  // @78_54a760
  ecx = (u32)(4294934528);  // @79_54a760
  goto L54a86d;  // @80_54a760
  L54a864:;
  FL[0] = ecx; FL[1] = (u32)(32767);  // @82_54a760
  if ((s32)FL[0] > (s32)FL[1]) ecx = eax;  // @83_54a760
  L54a86d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8990), sizeof v); (u32)v; });  // @85_54a760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @86_54a760
  { u16 v = (u16)((edx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + esi*4), &v, sizeof v); }  // @87_54a760
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @88_54a760
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @89_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8990), sizeof v); (u32)v; });  // @90_54a760
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(eax + edx*4 + 2), &v, sizeof v); }  // @91_54a760
  edx = (edx + 1);  // @92_54a760
  FL[3] = edx;  // @93_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @94_54a760
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @95_54a760
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @96_54a760
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_54a760
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 45), &v, sizeof v); }  // @98_54a760
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @99_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 45), sizeof v); (u32)v; });  // @100_54a760
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 53), sizeof v); (u32)v; });  // @101_54a760
  if ((s32)FL[0] < (s32)FL[1]) goto L54a810;  // @102_54a760
  L54a8a4:;
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 53), sizeof v); (u32)v; });  // @104_54a760
  eax = (u32)(esi + 8745);  // @105_54a760
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @106_54a760
  PV[3] = (u32)(eax);  // @107_54a760
  eax = ext_4022f0_cdecl2(PV[3], PV[2]);  // @108_54a760
  ecx = edx = 0;  // @109_54a760
  goto L54a7b2;  // @110_54a760
  L54a8c2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @112_54a760
  L54a8c9:;
  eax = (u32)(esi + 8665);  // @114_54a760
  PV[4] = (u32)(eax);  // @115_54a760
  eax = (u32)(esi + 8289);  // @116_54a760
  PV[5] = (u32)(eax);  // @117_54a760
  eax = ext_410a00_cdecl2(PV[5], PV[4]);  // @118_54a760
  ecx = edx = 0;  // @119_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @120_54a760
  FL[2] = (eax & eax);  // @121_54a760
  if (FL[2] != 0) goto L54aa26;  // @122_54a760
  L54a8ea:;
  edi = (u32)(esi + 8261);  // @124_54a760
  ebx = (u32)(esi + 8649);  // @125_54a760
  L54a8f6:;
  PV[6] = (u32)(ebx);  // @127_54a760
  PV[7] = (u32)(edi);  // @128_54a760
  eax = ext_4106b0_cdecl2(PV[7], PV[6]);  // @129_54a760
  ecx = edx = 0;  // @130_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @131_54a760
  FL[2] = (eax & eax);  // @132_54a760
  if (FL[2] != 0) goto L54a9dc;  // @133_54a760
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @134_54a760
  if (FL[0] == FL[1]) goto L54a917;  // @135_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @136_54a760
  ecx = esi;  // @137_54a760
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @138_54a760
  ecx = edx = 0;  // @139_54a760
  L54a917:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8982), sizeof v); (u32)v; });  // @141_54a760
  PV[9] = (u32)(edi);  // @142_54a760
  eax = ext_4104c0_cdecl2(PV[9], PV[8]);  // @143_54a760
  ecx = edx = 0;  // @144_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8969), &v, sizeof v); }  // @145_54a760
  ecx = (u32)(EBP - 4);  // @146_54a760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @147_54a760
  PV[10] = (u32)(ecx);  // @148_54a760
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8982), sizeof v); (u32)v; });  // @149_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @150_54a760
  PV[12] = (u32)(eax);  // @151_54a760
  eax = ext_54e1f0_thiscall5(ecx, PV[12], PV[11], PV[10], (u32)(0));  // @152_54a760
  ecx = edx = 0;  // @153_54a760
  FL[0] = eax; FL[1] = (u32)(2);  // @154_54a760
  if (FL[0] != FL[1]) goto L54a953;  // @155_54a760
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @156_54a760
  goto L54a9a0;  // @157_54a760
  L54a953:;
  FL[0] = eax; FL[1] = (u32)(3);  // @159_54a760
  if (FL[0] == FL[1]) goto L54aaa2;  // @160_54a760
  FL[2] = (eax & eax);  // @161_54a760
  if (FL[2] == 0) goto L54aaa2;  // @162_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @163_54a760
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8982), sizeof v); (u32)v; });  // @164_54a760
  if (FL[0] == FL[1]) goto L54a9a3;  // @165_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @166_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @167_54a760
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6960324), (u32)(1067));  // @168_54a760
  ecx = edx = 0;  // @169_54a760
  PV[13] = (u32)(eax);  // @170_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @171_54a760
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[13], (u32)(6960696));  // @172_54a760
  ecx = edx = 0;  // @173_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @174_54a760
  FL[2] = (eax & eax);  // @175_54a760
  if (FL[2] == 0) goto L54a99f;  // @176_54a760
  eax = ((u32(STDCALL *)(void))(eax))();  // @177_54a760
  ecx = edx = 0;  // @178_54a760
  goto L54a9a0;  // @179_54a760
  L54a99f:;
  __builtin_trap();  // @181_54a760
  L54a9a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @183_54a760
  L54a9a3:;
  FL[2] = (eax & eax);  // @185_54a760
  if (FL[2] == 0) goto L54aaa2;  // @186_54a760
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @187_54a760
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @188_54a760
  PV[14] = (u32)(eax);  // @189_54a760
  PV[15] = (u32)(edi);  // @190_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8973), &v, sizeof v); }  // @191_54a760
  eax = ext_410540_cdecl2(PV[15], PV[14]);  // @192_54a760
  ecx = edx = 0;  // @193_54a760
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @194_54a760
  if (FL[0] == FL[1]) goto L54aaa2;  // @195_54a760
  PV[16] = (u32)(ebx);  // @196_54a760
  PV[17] = (u32)(edi);  // @197_54a760
  eax = ext_4106b0_cdecl2(PV[17], PV[16]);  // @198_54a760
  ecx = edx = 0;  // @199_54a760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 33), &v, sizeof v); }  // @200_54a760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @201_54a760
  L54a9dc:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 33), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @203_54a760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @204_54a760
  if ((s32)FL[0] >= (s32)FL[1]) goto L54aa11;  // @205_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @206_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_54a760
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6960324), (u32)(1086));  // @208_54a760
  ecx = edx = 0;  // @209_54a760
  PV[18] = (u32)(eax);  // @210_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @211_54a760
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[18], (u32)(6960756));  // @212_54a760
  ecx = edx = 0;  // @213_54a760
  goto L54a8f6;  // @214_54a760
  L54aa11:;
  eax = (u32)(esi + 8289);  // @216_54a760
  PV[19] = (u32)(ebx);  // @217_54a760
  PV[20] = (u32)(eax);  // @218_54a760
  eax = ext_4106f0_cdecl2(PV[20], PV[19]);  // @219_54a760
  ecx = edx = 0;  // @220_54a760
  goto L54a8c9;  // @221_54a760
  L54aa26:;
  FL[0] = eax; FL[1] = (u32)(1);  // @223_54a760
  if (FL[0] != FL[1]) goto L54a8c9;  // @224_54a760
  eax = (u32)(esi + 8665);  // @225_54a760
  PV[21] = (u32)(eax);  // @226_54a760
  edi = (u32)(esi + 8857);  // @227_54a760
  PV[22] = (u32)(edi);  // @228_54a760
  eax = ext_402320_cdecl2(PV[22], PV[21]);  // @229_54a760
  ecx = edx = 0;  // @230_54a760
  FL[2] = (eax & eax);  // @231_54a760
  if (FL[2] != 0) goto L54aa5e;  // @232_54a760
  eax = (u32)(esi + 8745);  // @233_54a760
  PV[23] = (u32)(edi);  // @234_54a760
  PV[24] = (u32)(eax);  // @235_54a760
  eax = ext_401f20_cdecl2(PV[24], PV[23]);  // @236_54a760
  ecx = edx = 0;  // @237_54a760
  goto L54a7b2;  // @238_54a760
  L54aa5e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @240_54a760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @241_54a760
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6960324), (u32)(1110));  // @242_54a760
  ecx = edx = 0;  // @243_54a760
  PV[25] = (u32)(eax);  // @244_54a760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @245_54a760
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))(PV[25], (u32)(6960812));  // @246_54a760
  ecx = edx = 0;  // @247_54a760
  goto L54a7b2;  // @248_54a760
  L54aa86:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @250_54a760
  eax = 0;  // @251_54a760
  FL[3] = eax;  // @252_54a760
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(esi + 21), &v, sizeof v); }  // @253_54a760
  eax = (eax | (u32)(2));  // @254_54a760
  FL[3] = eax;  // @255_54a760
  return eax;  // @256_54a760
  L54aaa2:;
  eax = 0;  // @258_54a760
  FL[3] = eax;  // @259_54a760
  return eax;  // @260_54a760
}
PCREG(54a760, lifted_54a760);

extern "C" u32 THISCALL lifted_649440(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089904) + 0), 4); v; });  // @0_649440
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089904) + 4), 4); v; });  // @1_649440
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089904) + 8), 4); v; });  // @2_649440
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089904) + 12), 4); v; });  // @3_649440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_649440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @5_649440
  ebx = (u32)(EBP - 84);  // @6_649440
  __builtin_memcpy((void *)((u32)(EBP - 84) + 0), &X0[0], 4);  // @7_649440
  __builtin_memcpy((void *)((u32)(EBP - 84) + 4), &X0[1], 4);  // @8_649440
  __builtin_memcpy((void *)((u32)(EBP - 84) + 8), &X0[2], 4);  // @9_649440
  __builtin_memcpy((void *)((u32)(EBP - 84) + 12), &X0[3], 4);  // @10_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089888) + 0), 4); v; });  // @11_649440
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089888) + 4), 4); v; });  // @12_649440
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089888) + 8), 4); v; });  // @13_649440
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7089888) + 12), 4); v; });  // @14_649440
  edi = (u32)(EBP - 52);  // @15_649440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 96), &v, sizeof v); }  // @16_649440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @17_649440
  __builtin_memcpy((void *)((u32)(EBP - 68) + 0), &X0[0], 4);  // @18_649440
  __builtin_memcpy((void *)((u32)(EBP - 68) + 4), &X0[1], 4);  // @19_649440
  __builtin_memcpy((void *)((u32)(EBP - 68) + 8), &X0[2], 4);  // @20_649440
  __builtin_memcpy((void *)((u32)(EBP - 68) + 12), &X0[3], 4);  // @21_649440
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @22_649440
  L649482:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @24_649440
  ecx = esi;  // @25_649440
  PV[0] = (u32)(ebx);  // @26_649440
  PV[1] = (u32)(edi);  // @27_649440
  { u32 v = (u32)((u32)(1036831949)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @28_649440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 628)))(ecx, PV[1], PV[0]);  // @29_649440
  ecx = edx = 0;  // @30_649440
  edi = (edi + (u32)(12));  // @31_649440
  FL[3] = edi;  // @32_649440
  ebx = (ebx + (u32)(8));  // @33_649440
  FL[3] = ebx;  // @34_649440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @35_649440
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @36_649440
  if (FL[3] != 0) goto L649482;  // @37_649440
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @38_649440
  eax = (u32)(EBP - 40);  // @39_649440
  PV[2] = (u32)(eax);  // @40_649440
  edx = (u32)(EBP - 52);  // @41_649440
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @42_649440
  ecx = ebx;  // @43_649440
  eax = ext_446ee0_fastcall3(ecx, edx, PV[2]);  // @44_649440
  ecx = edx = 0;  // @45_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @46_649440
  X0[1] = 0;  // @47_649440
  X0[2] = 0;  // @48_649440
  X0[3] = 0;  // @49_649440
  X1[0] = 0;  // @50_649440
  X1[1] = 0;  // @51_649440
  X1[2] = 0;  // @52_649440
  X1[3] = 0;  // @53_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @54_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @55_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L6494e1;  // @56_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @57_649440
  X0[1] = 0;  // @58_649440
  X0[2] = 0;  // @59_649440
  X0[3] = 0;  // @60_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @61_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @62_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L6494e1;  // @63_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @64_649440
  X0[1] = 0;  // @65_649440
  X0[2] = 0;  // @66_649440
  X0[3] = 0;  // @67_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @68_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @69_649440
  if (__builtin_parity(FL[2] & 0xff)) goto L64951d;  // @70_649440
  L6494e1:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @72_649440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @73_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @74_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @75_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @76_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @77_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @78_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @79_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @80_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @81_649440
  __asm__ volatile("fsqrt" ::: "st");  // @82_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 88)) : "st");  // @83_649440
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @84_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @85_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @86_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @87_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @88_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @89_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @90_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @91_649440
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @92_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @93_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 88)) :: "st");  // @94_649440
  L64951d:;
  edi = (u32)(ebx + 12);  // @96_649440
  eax = (u32)(EBP - 28);  // @97_649440
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @98_649440
  PV[3] = (u32)(eax);  // @99_649440
  edx = (u32)(EBP - 40);  // @100_649440
  ecx = edi;  // @101_649440
  eax = ext_446ee0_fastcall3(ecx, edx, PV[3]);  // @102_649440
  ecx = edx = 0;  // @103_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @104_649440
  X0[1] = 0;  // @105_649440
  X0[2] = 0;  // @106_649440
  X0[3] = 0;  // @107_649440
  X1[0] = 0;  // @108_649440
  X1[1] = 0;  // @109_649440
  X1[2] = 0;  // @110_649440
  X1[3] = 0;  // @111_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @112_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @113_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L64955d;  // @114_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @115_649440
  X0[1] = 0;  // @116_649440
  X0[2] = 0;  // @117_649440
  X0[3] = 0;  // @118_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @119_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @120_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L64955d;  // @121_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @122_649440
  X0[1] = 0;  // @123_649440
  X0[2] = 0;  // @124_649440
  X0[3] = 0;  // @125_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @126_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @127_649440
  if (__builtin_parity(FL[2] & 0xff)) goto L649599;  // @128_649440
  L64955d:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @130_649440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @131_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @132_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @133_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @134_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @135_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @136_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @137_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @138_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @139_649440
  __asm__ volatile("fsqrt" ::: "st");  // @140_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 88)) : "st");  // @141_649440
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @142_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @143_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @144_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @145_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @146_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @147_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @148_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @149_649440
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @150_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @151_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 88)) :: "st");  // @152_649440
  L649599:;
  edi = (u32)(ebx + 24);  // @154_649440
  eax = (u32)(EBP - 16);  // @155_649440
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @156_649440
  PV[4] = (u32)(eax);  // @157_649440
  edx = (u32)(EBP - 28);  // @158_649440
  ecx = edi;  // @159_649440
  eax = ext_446ee0_fastcall3(ecx, edx, PV[4]);  // @160_649440
  ecx = edx = 0;  // @161_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi) + 0), 4); v; });  // @162_649440
  X0[1] = 0;  // @163_649440
  X0[2] = 0;  // @164_649440
  X0[3] = 0;  // @165_649440
  X1[0] = 0;  // @166_649440
  X1[1] = 0;  // @167_649440
  X1[2] = 0;  // @168_649440
  X1[3] = 0;  // @169_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @170_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @171_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L6495d9;  // @172_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 4) + 0), 4); v; });  // @173_649440
  X0[1] = 0;  // @174_649440
  X0[2] = 0;  // @175_649440
  X0[3] = 0;  // @176_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @177_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @178_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L6495d9;  // @179_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 8) + 0), 4); v; });  // @180_649440
  X0[1] = 0;  // @181_649440
  X0[2] = 0;  // @182_649440
  X0[3] = 0;  // @183_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @184_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @185_649440
  if (__builtin_parity(FL[2] & 0xff)) goto L649615;  // @186_649440
  L6495d9:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @188_649440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @189_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @190_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @191_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @192_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @193_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @194_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @195_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @196_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @197_649440
  __asm__ volatile("fsqrt" ::: "st");  // @198_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 88)) : "st");  // @199_649440
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @200_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @201_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @202_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @203_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @204_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @205_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @206_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @207_649440
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @208_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @209_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 88)) :: "st");  // @210_649440
  L649615:;
  ebx = (ebx + (u32)(36));  // @212_649440
  FL[3] = ebx;  // @213_649440
  eax = (u32)(EBP - 52);  // @214_649440
  PV[5] = (u32)(eax);  // @215_649440
  edx = (u32)(EBP - 16);  // @216_649440
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 92), &v, sizeof v); }  // @217_649440
  ecx = ebx;  // @218_649440
  eax = ext_446ee0_fastcall3(ecx, edx, PV[5]);  // @219_649440
  ecx = edx = 0;  // @220_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @221_649440
  X0[1] = 0;  // @222_649440
  X0[2] = 0;  // @223_649440
  X0[3] = 0;  // @224_649440
  X1[0] = 0;  // @225_649440
  X1[1] = 0;  // @226_649440
  X1[2] = 0;  // @227_649440
  X1[3] = 0;  // @228_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @229_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @230_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L649655;  // @231_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @232_649440
  X0[1] = 0;  // @233_649440
  X0[2] = 0;  // @234_649440
  X0[3] = 0;  // @235_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @236_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @237_649440
  if (!__builtin_parity(FL[2] & 0xff)) goto L649655;  // @238_649440
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @239_649440
  X0[1] = 0;  // @240_649440
  X0[2] = 0;  // @241_649440
  X0[3] = 0;  // @242_649440
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @243_649440
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @244_649440
  if (__builtin_parity(FL[2] & 0xff)) goto L649691;  // @245_649440
  L649655:;
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @247_649440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 92), sizeof v); (u32)v; });  // @248_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @249_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @250_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @251_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @252_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @253_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @254_649440
  __asm__ volatile("fmul %%st(0), %%st" ::: "st");  // @255_649440
  __asm__ volatile("faddp %%st, %%st(1)" ::: "st");  // @256_649440
  __asm__ volatile("fsqrt" ::: "st");  // @257_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(EBP - 88)) : "st");  // @258_649440
  __asm__ volatile("fdiv %%st(1), %%st" ::: "st");  // @259_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx)) : "st");  // @260_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @261_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx)) :: "st");  // @262_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 4)) : "st");  // @263_649440
  __asm__ volatile("fmul %%st(1), %%st" ::: "st");  // @264_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 4)) :: "st");  // @265_649440
  __asm__ volatile("flds %0" :: "m"(*(float *)(u32)(ecx + 8)) : "st");  // @266_649440
  __asm__ volatile("fmulp %%st, %%st(1)" ::: "st");  // @267_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(ecx + 8)) :: "st");  // @268_649440
  __asm__ volatile("fstps %0" : "=m"(*(float *)(u32)(EBP - 88)) :: "st");  // @269_649440
  L649691:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 96), sizeof v); (u32)v; });  // @271_649440
  ebx = (u32)(EBP - 84);  // @272_649440
  edi = (edi + (u32)(98761));  // @273_649440
  FL[3] = edi;  // @274_649440
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @275_649440
  L6496a4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 104), sizeof v); (u32)v; });  // @277_649440
  ecx = esi;  // @278_649440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @279_649440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @280_649440
  PV[6] = (u32)(ebx);  // @281_649440
  PV[7] = (u32)(edi);  // @282_649440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 628)))(ecx, PV[7], PV[6]);  // @283_649440
  ecx = edx = 0;  // @284_649440
  edi = (edi + (u32)(12));  // @285_649440
  FL[3] = edi;  // @286_649440
  ebx = (ebx + (u32)(8));  // @287_649440
  FL[3] = ebx;  // @288_649440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 88), &v, sizeof v); }  // @289_649440
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 88), sizeof v); (u32)v; });  // @290_649440
  if (FL[3] != 0) goto L6496a4;  // @291_649440
  ext_633654(G(u32, 0x6f5630));  // @292_649440
  return eax;  // @293_649440
}
PCREG(649440, lifted_649440);

extern "C" u32 THISCALL lifted_532ab0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_532ab0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @1_532ab0
  if (FL[0] == FL[1]) goto L532ea2;  // @2_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @3_532ab0
  edi = 0;  // @4_532ab0
  FL[3] = edi;  // @5_532ab0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @6_532ab0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @7_532ab0
  { u32 v = (u32)((u32)(48)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @9_532ab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @10_532ab0
  edx = (edx + ecx);  // @11_532ab0
  FL[3] = edx;  // @12_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @13_532ab0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @14_532ab0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 197), sizeof v); (u32)v; }); FL[1] = edi;  // @15_532ab0
  if ((s32)FL[0] <= (s32)FL[1]) goto L532e85;  // @16_532ab0
  ecx = (ecx + (u32)(238));  // @17_532ab0
  FL[3] = ecx;  // @18_532ab0
  X1[0] = 0;  // @19_532ab0
  X1[1] = 0;  // @20_532ab0
  X1[2] = 0;  // @21_532ab0
  X1[3] = 0;  // @22_532ab0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @23_532ab0
  L532b30:;
  { u32 v = (u32)((u32)(65)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @25_532ab0
  ebx = 0;  // @26_532ab0
  FL[3] = ebx;  // @27_532ab0
  { u32 v = (u32)((u32)(16)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @28_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @29_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @30_532ab0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @31_532ab0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @32_532ab0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 37), sizeof v); (u32)v; });  // @33_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @34_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 36), sizeof v); (u32)v; });  // @35_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @36_532ab0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = ebx;  // @37_532ab0
  if ((s32)FL[0] <= (s32)FL[1]) goto L532e37;  // @38_532ab0
  edi = (u32)(ecx + 4);  // @39_532ab0
  L532b66:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @41_532ab0
  eax = (eax - 1);  // @42_532ab0
  FL[3] = eax;  // @43_532ab0
  FL[0] = eax; FL[1] = (u32)(6);  // @44_532ab0
  if (FL[0] > FL[1]) goto L532e0e;  // @45_532ab0
  switch (eax) {  // @46_532ab0
  case 0: goto L532db9;  // @47_532ab0
  case 1: goto L532ba1;  // @48_532ab0
  case 2: goto L532b7a;  // @49_532ab0
  case 3: goto L532e0e;  // @50_532ab0
  case 4: goto L532c36;  // @51_532ab0
  case 5: goto L532e0e;  // @52_532ab0
  case 6: goto L532df0;  // @53_532ab0
  default: __builtin_trap(); }  // @54_532ab0
  L532b7a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @56_532ab0
  { u32 v = (u32)((u32)(12)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @57_532ab0
  { u32 v = (u32)((u32)(113)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @58_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @59_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @60_532ab0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @61_532ab0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @62_532ab0
  goto L532e22;  // @63_532ab0
  L532ba1:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 21626) + 0), 4); v; });  // @65_532ab0
  X0[1] = 0;  // @66_532ab0
  X0[2] = 0;  // @67_532ab0
  X0[3] = 0;  // @68_532ab0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @69_532ab0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @70_532ab0
  if (__builtin_parity(FL[2] & 0xff)) goto L532bce;  // @71_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @72_532ab0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @73_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_532ab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[0]);  // @75_532ab0
  ecx = edx = 0;  // @76_532ab0
  FL[2] = (eax & eax);  // @77_532ab0
  if (FL[2] == 0) goto L532c1c;  // @78_532ab0
  ecx = (u32)(eax + 132);  // @79_532ab0
  goto L532bd6;  // @80_532ab0
  L532bce:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21250), sizeof v); (u32)v; });  // @82_532ab0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @83_532ab0
  FL[3] = ecx;  // @84_532ab0
  L532bd6:;
  FL[2] = (ecx & ecx);  // @86_532ab0
  if (FL[2] == 0) goto L532c1c;  // @87_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @88_532ab0
  { u32 v = (u32)((u32)(108)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @89_532ab0
  { u32 v = (u32)((u32)(112)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @90_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 0), 4); v; });  // @91_532ab0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 4), 4); v; });  // @92_532ab0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 8), 4); v; });  // @93_532ab0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx) + 12), 4); v; });  // @94_532ab0
  __builtin_memcpy((void *)((u32)(eax + 12) + 0), &X0[0], 4);  // @95_532ab0
  __builtin_memcpy((void *)((u32)(eax + 12) + 4), &X0[1], 4);  // @96_532ab0
  __builtin_memcpy((void *)((u32)(eax + 12) + 8), &X0[2], 4);  // @97_532ab0
  __builtin_memcpy((void *)((u32)(eax + 12) + 12), &X0[3], 4);  // @98_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 0), 4); v; });  // @99_532ab0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 4), 4); v; });  // @100_532ab0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 8), 4); v; });  // @101_532ab0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 16) + 12), 4); v; });  // @102_532ab0
  __builtin_memcpy((void *)((u32)(eax + 28) + 0), &X0[0], 4);  // @103_532ab0
  __builtin_memcpy((void *)((u32)(eax + 28) + 4), &X0[1], 4);  // @104_532ab0
  __builtin_memcpy((void *)((u32)(eax + 28) + 8), &X0[2], 4);  // @105_532ab0
  __builtin_memcpy((void *)((u32)(eax + 28) + 12), &X0[3], 4);  // @106_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 0), 4); v; });  // @107_532ab0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 4), 4); v; });  // @108_532ab0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 8), 4); v; });  // @109_532ab0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 32) + 12), 4); v; });  // @110_532ab0
  __builtin_memcpy((void *)((u32)(eax + 44) + 0), &X0[0], 4);  // @111_532ab0
  __builtin_memcpy((void *)((u32)(eax + 44) + 4), &X0[1], 4);  // @112_532ab0
  __builtin_memcpy((void *)((u32)(eax + 44) + 8), &X0[2], 4);  // @113_532ab0
  __builtin_memcpy((void *)((u32)(eax + 44) + 12), &X0[3], 4);  // @114_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 48) + 0), 4); v; });  // @115_532ab0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 48) + 4), 4); v; });  // @116_532ab0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 48) + 8), 4); v; });  // @117_532ab0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 48) + 12), 4); v; });  // @118_532ab0
  __builtin_memcpy((void *)((u32)(eax + 60) + 0), &X0[0], 4);  // @119_532ab0
  __builtin_memcpy((void *)((u32)(eax + 60) + 4), &X0[1], 4);  // @120_532ab0
  __builtin_memcpy((void *)((u32)(eax + 60) + 8), &X0[2], 4);  // @121_532ab0
  __builtin_memcpy((void *)((u32)(eax + 60) + 12), &X0[3], 4);  // @122_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 64) + 0), 4); v; });  // @123_532ab0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 64) + 4), 4); v; });  // @124_532ab0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 64) + 8), 4); v; });  // @125_532ab0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 64) + 12), 4); v; });  // @126_532ab0
  __builtin_memcpy((void *)((u32)(eax + 76) + 0), &X0[0], 4);  // @127_532ab0
  __builtin_memcpy((void *)((u32)(eax + 76) + 4), &X0[1], 4);  // @128_532ab0
  __builtin_memcpy((void *)((u32)(eax + 76) + 8), &X0[2], 4);  // @129_532ab0
  __builtin_memcpy((void *)((u32)(eax + 76) + 12), &X0[3], 4);  // @130_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 80) + 0), 4); v; });  // @131_532ab0
  X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 80) + 4), 4); v; });  // @132_532ab0
  X0[2] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 80) + 8), 4); v; });  // @133_532ab0
  X0[3] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 80) + 12), 4); v; });  // @134_532ab0
  __builtin_memcpy((void *)((u32)(eax + 92) + 0), &X0[0], 4);  // @135_532ab0
  __builtin_memcpy((void *)((u32)(eax + 92) + 4), &X0[1], 4);  // @136_532ab0
  __builtin_memcpy((void *)((u32)(eax + 92) + 8), &X0[2], 4);  // @137_532ab0
  __builtin_memcpy((void *)((u32)(eax + 92) + 12), &X0[3], 4);  // @138_532ab0
  L532c1c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @140_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @141_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @142_532ab0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @143_532ab0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @144_532ab0
  goto L532e22;  // @145_532ab0
  L532c36:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 21626) + 0), 4); v; });  // @147_532ab0
  X0[1] = 0;  // @148_532ab0
  X0[2] = 0;  // @149_532ab0
  X0[3] = 0;  // @150_532ab0
  eax = 0;  // @151_532ab0
  FL[3] = eax;  // @152_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @153_532ab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @154_532ab0
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) << 8);  // @155_532ab0
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(X1[0])) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(X1[0]) != U2F(X1[0]))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(X1[0])) || (U2F(X0[0]) > U2F(X1[0])))) ? 0x40 : 0)) & 68);  // @156_532ab0
  if (__builtin_parity(FL[2] & 0xff)) goto L532cac;  // @157_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @158_532ab0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @159_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_532ab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, PV[1]);  // @161_532ab0
  ecx = edx = 0;  // @162_532ab0
  FL[2] = (eax & eax);  // @163_532ab0
  if (FL[2] == 0) goto L532c78;  // @164_532ab0
  eax = (eax + (u32)(132));  // @165_532ab0
  FL[3] = eax;  // @166_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @167_532ab0
  L532c78:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @169_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @170_532ab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @171_532ab0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @172_532ab0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @173_532ab0
  ecx = edx = 0;  // @174_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @175_532ab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 352), sizeof v); (u32)v; });  // @176_532ab0
  FL[2] = (eax & eax);  // @177_532ab0
  if (FL[2] == 0) goto L532cef;  // @178_532ab0
  eax = (eax + (u32)(132));  // @179_532ab0
  FL[3] = eax;  // @180_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @181_532ab0
  goto L532cf5;  // @182_532ab0
  L532cac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @184_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @185_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @186_532ab0
  FL[2] = (eax & eax);  // @187_532ab0
  if (FL[2] == 0) goto L532e22;  // @188_532ab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @189_532ab0
  FL[2] = (edx & edx);  // @190_532ab0
  if (FL[2] == 0) goto L532e22;  // @191_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21250), sizeof v); (u32)v; });  // @192_532ab0
  edx = (edx + eax);  // @193_532ab0
  FL[3] = edx;  // @194_532ab0
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; }));  // @195_532ab0
  FL[3] = eax;  // @196_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @197_532ab0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 352), &v, sizeof v); }  // @198_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 348), &v, sizeof v); }  // @199_532ab0
  goto L532cf5;  // @200_532ab0
  L532cef:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @202_532ab0
  L532cf5:;
  FL[2] = (edx & edx);  // @204_532ab0
  if (FL[2] == 0) goto L532e22;  // @205_532ab0
  FL[2] = (eax & eax);  // @206_532ab0
  if (FL[2] == 0) goto L532e22;  // @207_532ab0
  eax = (u32)(EBP - 228);  // @208_532ab0
  PV[3] = (u32)(eax);  // @209_532ab0
  eax = ext_634d10_cdecl3(PV[3], (u32)(0), (u32)(112));  // @210_532ab0
    // @211_532ab0
  eax = (u32)(EBP - 116);  // @212_532ab0
  PV[4] = (u32)(eax);  // @213_532ab0
  eax = ext_634d10_cdecl3(PV[4], (u32)(0), (u32)(112));  // @214_532ab0
    // @215_532ab0
  eax = (u32)(EBP - 340);  // @216_532ab0
  PV[5] = (u32)(eax);  // @217_532ab0
  eax = ext_634d10_cdecl3(PV[5], (u32)(0), (u32)(112));  // @218_532ab0
    // @219_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @220_532ab0
  eax = (u32)(EBP - 228);  // @221_532ab0
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 352), sizeof v); (u32)v; });  // @222_532ab0
  PV[7] = (u32)(eax);  // @223_532ab0
  eax = ext_54a0e0_thiscall3(ecx, PV[7], PV[6]);  // @224_532ab0
  ecx = edx = 0;  // @225_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 348), sizeof v); (u32)v; });  // @226_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @227_532ab0
  PV[8] = (u32)(eax);  // @228_532ab0
  eax = (u32)(EBP - 116);  // @229_532ab0
  PV[9] = (u32)(eax);  // @230_532ab0
  eax = ext_54a0e0_thiscall3(ecx, PV[9], PV[8]);  // @231_532ab0
  ecx = edx = 0;  // @232_532ab0
  eax = (u32)(EBP - 340);  // @233_532ab0
  PV[10] = (u32)(eax);  // @234_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @235_532ab0
  edx = (u32)(EBP - 116);  // @236_532ab0
  PV[11] = (u32)(ecx);  // @237_532ab0
  ecx = (u32)(EBP - 228);  // @238_532ab0
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 12) + 0), 4); v; });  // @239_532ab0
  X0[1] = 0;  // @240_532ab0
  X0[2] = 0;  // @241_532ab0
  X0[3] = 0;  // @242_532ab0
  PV[12] = X0[0];  // @243_532ab0
  eax = ext_539eb0_fastcall5(ecx, edx, PV[12], PV[10], (u32)(0));  // @244_532ab0
  ecx = edx = 0;  // @245_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @246_532ab0
  ecx = (u32)(EBP - 340);  // @247_532ab0
  PV[13] = (u32)(ecx);  // @248_532ab0
  { u32 v = (u32)((u32)(108)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @249_532ab0
  { u32 v = (u32)((u32)(112)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @250_532ab0
  eax = (eax + (u32)(12));  // @251_532ab0
  FL[3] = eax;  // @252_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21642), sizeof v); (u32)v; });  // @253_532ab0
  PV[14] = (u32)(eax);  // @254_532ab0
  eax = ext_54a170_thiscall3(ecx, PV[14], PV[13]);  // @255_532ab0
  ecx = edx = 0;  // @256_532ab0
  goto L532c1c;  // @257_532ab0
  L532db9:;
  edx = (u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }) * (s32)(u32)(164));  // @259_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @260_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @261_532ab0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4601), sizeof v); (u32)v; }));  // @262_532ab0
  FL[3] = edx;  // @263_532ab0
  { u32 v = (u32)((u32)(20)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @264_532ab0
  { u32 v = (u32)((u32)(66)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @265_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @266_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @267_532ab0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @268_532ab0
  goto L532c1c;  // @269_532ab0
  L532df0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @271_532ab0
  { u32 v = (u32)((u32)(20)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @272_532ab0
  { u32 v = (u32)((u32)(68)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @273_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @274_532ab0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @275_532ab0
  goto L532c1c;  // @276_532ab0
  L532e0e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @278_532ab0
  FL[2] = (eax & eax);  // @279_532ab0
  if (FL[2] == 0) goto L532e21;  // @280_532ab0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @281_532ab0
  ecx = edx = 0;  // @282_532ab0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 344), sizeof v); (u32)v; });  // @283_532ab0
  goto L532e22;  // @284_532ab0
  L532e21:;
  __builtin_trap();  // @286_532ab0
  L532e22:;
  ebx = (ebx + 1);  // @288_532ab0
  FL[3] = ebx;  // @289_532ab0
  edi = (edi + (u32)(12));  // @290_532ab0
  FL[3] = edi;  // @291_532ab0
  X1[0] = 0;  // @292_532ab0
  X1[1] = 0;  // @293_532ab0
  X1[2] = 0;  // @294_532ab0
  X1[3] = 0;  // @295_532ab0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @296_532ab0
  if ((s32)FL[0] < (s32)FL[1]) goto L532b66;  // @297_532ab0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 356), sizeof v); (u32)v; });  // @298_532ab0
  L532e37:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @300_532ab0
  edi = (edi + 1);  // @301_532ab0
  FL[3] = edi;  // @302_532ab0
  ecx = (ecx + (u32)(137));  // @303_532ab0
  FL[3] = ecx;  // @304_532ab0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 356), &v, sizeof v); }  // @305_532ab0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 344), &v, sizeof v); }  // @306_532ab0
  { u32 v = (u32)((u32)(64)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @307_532ab0
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @308_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @309_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @310_532ab0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @311_532ab0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @312_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21246), sizeof v); (u32)v; });  // @313_532ab0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @314_532ab0
  FL[0] = edi; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 197), sizeof v); (u32)v; });  // @315_532ab0
  if ((s32)FL[0] < (s32)FL[1]) goto L532b30;  // @316_532ab0
  L532e85:;
  { u32 v = (u32)((u32)(8)); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @318_532ab0
  { u32 v = (u32)((u32)(49)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @319_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @320_532ab0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @321_532ab0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(esi + 20905), &v, sizeof v); }  // @322_532ab0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20905), sizeof v); (u32)v; });  // @323_532ab0
  L532ea2:;
  ext_633654(G(u32, 0x6f5630));  // @325_532ab0
  return eax;  // @326_532ab0
}
PCREG(532ab0, lifted_532ab0);

