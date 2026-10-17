// batch240026.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 ext_42ac56_cdecl3(...) __asm__("ext_42ac56");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline double w4a_ltod(u32 lo, u32 hi) { double r; asm volatile("call *%[f]" : "=Yz"(r) : [f] "r"(0x633c60), "c"(lo), "d"(hi) : "xmm1", "cc", "memory"); return r; }
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_650430(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[68], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0; u32 CFv = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 148), sizeof v); (u32)v; });  // @1_650430
  ecx = (u32)(esi + 148);  // @2_650430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 236), &v, sizeof v); }  // @3_650430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @4_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 24)))(ecx);  // @5_650430
  ecx = edx = 0;  // @6_650430
  ebx = eax;  // @7_650430
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 268), &v, sizeof v); }  // @8_650430
  FL[2] = (ebx & ebx);  // @9_650430
  if (FL[2] != 0) goto L650480;  // @10_650430
  ext_633654(G(u32, 0x6f5630));  // @11_650430
  return eax;  // @12_650430
  L650480:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @15_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 236)))(ecx);  // @17_650430
  ecx = edx = 0;  // @18_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_650430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 216), &v, sizeof v); }  // @20_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6415), sizeof v); (u32)v; });  // @21_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 240)))(ecx);  // @23_650430
  ecx = edx = 0;  // @24_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_650430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 212), &v, sizeof v); }  // @26_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @27_650430
  X0[1] = 0;  // @28_650430
  X0[2] = 0;  // @29_650430
  X0[3] = 0;  // @30_650430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @31_650430
  FL[2] = ((u32)(0x02 | (!(U2F(X0[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X0[0]) != U2F(X0[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X0[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X0[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @32_650430
  if (!__builtin_parity(FL[2] & 0xff)) goto L6505b3;  // @33_650430
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7493657), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @34_650430
  if (FL[0] == FL[1]) goto L65059e;  // @35_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @36_650430
  ecx = (u32)(EBP - 252);  // @37_650430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @38_650430
  edi = 0;  // @39_650430
  FL[3] = edi;  // @40_650430
  PV[0] = (u32)(ecx);  // @41_650430
  ecx = ebx;  // @42_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @43_650430
  ecx = edx = 0;  // @44_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_650430
  ecx = (u32)(EBP - 252);  // @46_650430
  PV[1] = (u32)(ecx);  // @47_650430
  ecx = ebx;  // @48_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[1]);  // @49_650430
  ecx = edx = 0;  // @50_650430
  FL[2] = (eax & eax);  // @51_650430
  if (FL[2] == 0) goto L650552;  // @52_650430
  L650505:;
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }); FL[1] = esi;  // @54_650430
  if ((s32)FL[0] > (s32)FL[1]) goto L65051e;  // @55_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @56_650430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @57_650430
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @58_650430
  CFv = ((u32)(eax) < (u32)(edx));  // @59_650430
  eax = (eax - edx);  // @60_650430
  FL[3] = eax;  // @61_650430
  eax = (u32)((s32)eax >> (u32)(1));  // @62_650430
  FL[3] = eax;  // @63_650430
  CFv = ((u32)(edi + eax) < (u32)(edi));  // @64_650430
  edi = (edi + eax);  // @65_650430
  FL[3] = edi;  // @66_650430
  esi = (esi + 1);  // @67_650430
  FL[3] = esi;  // @68_650430
  L65051e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @72_650430
  ecx = edx = 0;  // @73_650430
  PV[2] = (u32)(esi);  // @74_650430
  PV[3] = (u32)(edi);  // @75_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @76_650430
  PV[4] = (u32)(eax);  // @77_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[4], PV[3], PV[2], (u32)(7091224));  // @78_650430
  ecx = edx = 0;  // @79_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @80_650430
  ecx = (u32)(EBP - 252);  // @81_650430
  esi = (esi + 1);  // @82_650430
  FL[3] = esi;  // @83_650430
  PV[5] = (u32)(ecx);  // @84_650430
  ecx = ebx;  // @85_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[5]);  // @86_650430
  ecx = edx = 0;  // @87_650430
  FL[2] = (eax & eax);  // @88_650430
  if (FL[2] != 0) goto L650505;  // @89_650430
  L650552:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @91_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @93_650430
  ecx = edx = 0;  // @94_650430
  PV[6] = (u32)(esi);  // @95_650430
  PV[7] = (u32)(edi);  // @96_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @97_650430
  PV[8] = (u32)(eax);  // @98_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[8], PV[7], PV[6], (u32)(7091224));  // @99_650430
  ecx = edx = 0;  // @100_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @103_650430
  ecx = edx = 0;  // @104_650430
  ecx = (u32)(esi + 1);  // @105_650430
  PV[9] = (u32)(ecx);  // @106_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @107_650430
  PV[10] = (u32)(edi);  // @108_650430
  PV[11] = (u32)(eax);  // @109_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[11], PV[10], PV[9], (u32)(7091224));  // @110_650430
  ecx = edx = 0;  // @111_650430
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(7493657), &v, sizeof v); }  // @112_650430
  L65059e:;
  eax = 0;  // @114_650430
  FL[3] = eax;  // @115_650430
  ext_633654(G(u32, 0x6f5630));  // @116_650430
  return eax;  // @117_650430
  L6505b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @119_650430
  ecx = ebx;  // @120_650430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 156), sizeof v); (u32)v; });  // @121_650430
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(7493657), &v, sizeof v); }  // @122_650430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @123_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @124_650430
  ecx = edx = 0;  // @125_650430
  FL[0] = eax; FL[1] = esi;  // @126_650430
  if ((s32)FL[0] >= (s32)FL[1]) goto L65068f;  // @127_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @128_650430
  edi = 0;  // @129_650430
  FL[3] = edi;  // @130_650430
  esi = ecx;  // @131_650430
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @132_650430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; }); FL[1] = edi;  // @133_650430
  if ((s32)FL[0] <= (s32)FL[1]) goto L65064a;  // @134_650430
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; });  // @135_650430
  L6505f0:;
  FL[0] = ebx; FL[1] = esi;  // @137_650430
  if ((s32)FL[0] > (s32)FL[1]) goto L650604;  // @138_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @139_650430
  esi = (u32)(ecx + 1);  // @140_650430
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @141_650430
  CFv = ((u32)(eax) < (u32)(edx));  // @142_650430
  eax = (eax - edx);  // @143_650430
  FL[3] = eax;  // @144_650430
  eax = (u32)((s32)eax >> (u32)(1));  // @145_650430
  FL[3] = eax;  // @146_650430
  CFv = ((u32)(edi + eax) < (u32)(edi));  // @147_650430
  edi = (edi + eax);  // @148_650430
  FL[3] = edi;  // @149_650430
  L650604:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @151_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @153_650430
  ecx = edx = 0;  // @154_650430
  PV[12] = (u32)(esi);  // @155_650430
  PV[13] = (u32)(edi);  // @156_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @157_650430
  PV[14] = (u32)(eax);  // @158_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[14], PV[13], PV[12], (u32)(7091224));  // @159_650430
  ecx = edx = 0;  // @160_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 236), sizeof v); (u32)v; });  // @161_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @162_650430
  esi = (esi + 1);  // @163_650430
  FL[3] = esi;  // @164_650430
  eax = (eax + 1);  // @165_650430
  FL[3] = eax;  // @166_650430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @167_650430
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 156), sizeof v); (u32)v; });  // @168_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @169_650430
  if ((s32)FL[0] < (s32)FL[1]) goto L6505f0;  // @170_650430
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @171_650430
  L65064a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @173_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @174_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @175_650430
  ecx = edx = 0;  // @176_650430
  PV[15] = (u32)(esi);  // @177_650430
  PV[16] = (u32)(edi);  // @178_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @179_650430
  PV[17] = (u32)(eax);  // @180_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[17], PV[16], PV[15], (u32)(7091224));  // @181_650430
  ecx = edx = 0;  // @182_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @183_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @184_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @185_650430
  ecx = edx = 0;  // @186_650430
  ecx = (u32)(esi + 1);  // @187_650430
  PV[18] = (u32)(ecx);  // @188_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @189_650430
  PV[19] = (u32)(edi);  // @190_650430
  PV[20] = (u32)(eax);  // @191_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[20], PV[19], PV[18], (u32)(7091224));  // @192_650430
  ecx = edx = 0;  // @193_650430
  L65068f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @195_650430
  ecx = (u32)(EBP - 252);  // @196_650430
  eax = (eax + 1);  // @197_650430
  FL[3] = eax;  // @198_650430
  edi = 0;  // @199_650430
  FL[3] = edi;  // @200_650430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @201_650430
  esi = eax;  // @202_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @203_650430
  PV[21] = (u32)(ecx);  // @204_650430
  ecx = ebx;  // @205_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[21]);  // @206_650430
  ecx = edx = 0;  // @207_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @208_650430
  ecx = (u32)(EBP - 252);  // @209_650430
  PV[22] = (u32)(ecx);  // @210_650430
  ecx = ebx;  // @211_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[22]);  // @212_650430
  ecx = edx = 0;  // @213_650430
  FL[2] = (eax & eax);  // @214_650430
  if (FL[2] == 0) goto L65075c;  // @215_650430
  L6506c1:;
  ecx = 0;  // @217_650430
  FL[3] = ecx;  // @218_650430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 472), sizeof v); (u32)v; }); FL[1] = ecx;  // @219_650430
  if ((s32)FL[0] <= (s32)FL[1]) goto L6506e6;  // @220_650430
  L6506d0:;
  FL[0] = ecx; FL[1] = (u32)(100);  // @222_650430
  if ((s32)FL[0] >= (s32)FL[1]) goto L6506e6;  // @223_650430
  { u8 v = (u8)((u32)(32)); __builtin_memcpy((void *)(u32)(EBP + ecx - 204), &v, sizeof v); }  // @224_650430
  ecx = (ecx + 1);  // @225_650430
  FL[3] = ecx;  // @226_650430
  FL[0] = ecx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 472), sizeof v); (u32)v; });  // @227_650430
  if ((s32)FL[0] < (s32)FL[1]) goto L6506d0;  // @228_650430
  L6506e6:;
  CFv = ((u32)(eax + (u32)(448)) < (u32)(eax));  // @230_650430
  eax = (eax + (u32)(448));  // @231_650430
  FL[3] = eax;  // @232_650430
  PV[23] = (u32)(eax);  // @233_650430
  eax = (u32)(EBP - 204);  // @234_650430
  CFv = ((u32)(eax + ecx) < (u32)(eax));  // @235_650430
  eax = (eax + ecx);  // @236_650430
  FL[3] = eax;  // @237_650430
  PV[24] = (u32)(eax);  // @238_650430
  eax = ext_42ac56_cdecl3(PV[24], (u32)(6779752), PV[23]);  // @239_650430
  ecx = edx = 0;  // @240_650430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }); FL[1] = esi;  // @241_650430
  if ((s32)FL[0] > (s32)FL[1]) goto L65071d;  // @242_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @243_650430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @244_650430
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @245_650430
  CFv = ((u32)(eax) < (u32)(edx));  // @246_650430
  eax = (eax - edx);  // @247_650430
  FL[3] = eax;  // @248_650430
  eax = (u32)((s32)eax >> (u32)(1));  // @249_650430
  FL[3] = eax;  // @250_650430
  CFv = ((u32)(edi + eax) < (u32)(edi));  // @251_650430
  edi = (edi + eax);  // @252_650430
  FL[3] = edi;  // @253_650430
  L65071d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @255_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @256_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @257_650430
  ecx = edx = 0;  // @258_650430
  edx = (u32)(EBP - 204);  // @259_650430
  PV[25] = (u32)(edx);  // @260_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @261_650430
  PV[26] = (u32)(esi);  // @262_650430
  PV[27] = (u32)(edi);  // @263_650430
  PV[28] = (u32)(eax);  // @264_650430
  eax = ((u32( *)(u32, u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[28], PV[27], PV[26], (u32)(6779752), PV[25]);  // @265_650430
  ecx = edx = 0;  // @266_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @267_650430
  ecx = (u32)(EBP - 252);  // @268_650430
  esi = (esi + 1);  // @269_650430
  FL[3] = esi;  // @270_650430
  PV[29] = (u32)(ecx);  // @271_650430
  ecx = ebx;  // @272_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[29]);  // @273_650430
  ecx = edx = 0;  // @274_650430
  FL[2] = (eax & eax);  // @275_650430
  if (FL[2] != 0) goto L6506c1;  // @276_650430
  L65075c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @278_650430
  ecx = (u32)(EBP - 252);  // @279_650430
  PV[30] = (u32)(ecx);  // @280_650430
  ecx = ebx;  // @281_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[30]);  // @282_650430
  ecx = edx = 0;  // @283_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @284_650430
  ecx = (u32)(EBP - 252);  // @285_650430
  PV[31] = (u32)(ecx);  // @286_650430
  ecx = ebx;  // @287_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[31]);  // @288_650430
  ecx = edx = 0;  // @289_650430
  edx = eax;  // @290_650430
  FL[2] = (edx & edx);  // @291_650430
  if (FL[2] == 0) goto L6507a6;  // @292_650430
  L650780:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 32), sizeof v); (u32)v; });  // @294_650430
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; })) < (u32)(ecx));  // @295_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) - ecx)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @296_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @297_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 36), sizeof v); (u32)v; });  // @298_650430
  { u32 a_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; }); u32 b_ = eax; u32 c_ = CFv; FL[3] = a_ - b_ - c_; CFv = ((u64)a_ < (u64)b_ + c_) ? 1 : 0; }  // @299_650430
  { u32 v = (u32)(FL[3]); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @300_650430
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; })) < (u32)(ecx));  // @301_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; }) - ecx)); __builtin_memcpy((void *)(u32)(edx + 16), &v, sizeof v); }  // @302_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 16), sizeof v); (u32)v; });  // @303_650430
  ecx = (u32)(EBP - 252);  // @304_650430
  PV[32] = (u32)(ecx);  // @305_650430
  { u32 a_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }); u32 b_ = eax; u32 c_ = CFv; FL[3] = a_ - b_ - c_; CFv = ((u64)a_ < (u64)b_ + c_) ? 1 : 0; }  // @306_650430
  { u32 v = (u32)(FL[3]); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @307_650430
  ecx = ebx;  // @308_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @309_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[32]);  // @310_650430
  ecx = edx = 0;  // @311_650430
  edx = eax;  // @312_650430
  FL[2] = (edx & edx);  // @313_650430
  if (FL[2] != 0) goto L650780;  // @314_650430
  L6507a6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @316_650430
  ecx = (u32)(EBP - 252);  // @317_650430
  PV[33] = (u32)(ecx);  // @318_650430
  ecx = ebx;  // @319_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[33]);  // @320_650430
  ecx = edx = 0;  // @321_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @322_650430
  ecx = (u32)(EBP - 252);  // @323_650430
  PV[34] = (u32)(ecx);  // @324_650430
  ecx = ebx;  // @325_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[34]);  // @326_650430
  ecx = edx = 0;  // @327_650430
  esi = eax;  // @328_650430
  FL[2] = (esi & esi);  // @329_650430
  if (FL[2] == 0) goto L65083f;  // @330_650430
  L6507d0:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 476), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @332_650430
  if (FL[0] != FL[1]) goto L65082b;  // @333_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 468), sizeof v); (u32)v; });  // @334_650430
  FL[2] = (edx & edx);  // @335_650430
  if (FL[2] == 0) goto L6507fb;  // @336_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @337_650430
  CFv = ((u32)(ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; })) < (u32)(ecx));  // @338_650430
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }));  // @339_650430
  FL[3] = ecx;  // @340_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @341_650430
  { u32 a_ = eax; u32 b_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }); u32 c_ = CFv; FL[3] = a_ + b_ + c_; CFv = (u32)(((u64)a_ + b_ + c_) >> 32); }  // @342_650430
  eax = FL[3];  // @343_650430
  CFv = ((u32)(ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) < (u32)(ecx));  // @344_650430
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }));  // @345_650430
  FL[3] = ecx;  // @346_650430
  { u32 a_ = eax; u32 b_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }); u32 c_ = CFv; FL[3] = a_ + b_ + c_; CFv = (u32)(((u64)a_ + b_ + c_) >> 32); }  // @347_650430
  eax = FL[3];  // @348_650430
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; })) < (u32)(ecx));  // @349_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; }) - ecx)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @350_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @351_650430
  { u32 a_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; }); u32 b_ = eax; u32 c_ = CFv; FL[3] = a_ - b_ - c_; CFv = ((u64)a_ < (u64)b_ + c_) ? 1 : 0; }  // @352_650430
  { u32 v = (u32)(FL[3]); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @353_650430
  L6507fb:;
  edi = 0;  // @355_650430
  FL[3] = edi;  // @356_650430
  FL[2] = (edx & edx);  // @357_650430
  if (FL[2] == 0) goto L65082b;  // @358_650430
  L650801:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 468), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @360_650430
  if (FL[0] != FL[1]) goto L65082b;  // @361_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @362_650430
  CFv = ((u32)(ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; })) < (u32)(ecx));  // @363_650430
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }));  // @364_650430
  FL[3] = ecx;  // @365_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @366_650430
  { u32 a_ = eax; u32 b_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }); u32 c_ = CFv; FL[3] = a_ + b_ + c_; CFv = (u32)(((u64)a_ + b_ + c_) >> 32); }  // @367_650430
  eax = FL[3];  // @368_650430
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) < (u32)(ecx));  // @369_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - ecx)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @370_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @371_650430
  { u32 a_ = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 4), sizeof v); (u32)v; }); u32 b_ = eax; u32 c_ = CFv; FL[3] = a_ - b_ - c_; CFv = ((u64)a_ < (u64)b_ + c_) ? 1 : 0; }  // @372_650430
  { u32 v = (u32)(FL[3]); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @373_650430
  edi = (edi + 1);  // @374_650430
  FL[3] = edi;  // @375_650430
  FL[0] = edi; FL[1] = (u32)(10);  // @376_650430
  if (FL[0] == FL[1]) goto L65082b;  // @377_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 460), sizeof v); (u32)v; });  // @378_650430
  FL[2] = (edx & edx);  // @379_650430
  if (FL[2] != 0) goto L650801;  // @380_650430
  L65082b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @382_650430
  ecx = (u32)(EBP - 252);  // @383_650430
  PV[35] = (u32)(ecx);  // @384_650430
  ecx = ebx;  // @385_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[35]);  // @386_650430
  ecx = edx = 0;  // @387_650430
  esi = eax;  // @388_650430
  FL[2] = (esi & esi);  // @389_650430
  if (FL[2] != 0) goto L6507d0;  // @390_650430
  L65083f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @392_650430
  X0[0] = 0;  // @393_650430
  X0[1] = 0;  // @394_650430
  X0[2] = 0;  // @395_650430
  X0[3] = 0;  // @396_650430
  __builtin_memcpy((void *)((u32)(EBP - 220) + 0), &X0[0], 4);  // @397_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @398_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @399_650430
  ecx = edx = 0;  // @400_650430
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @401_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @402_650430
  PV[37] = (u32)(eax);  // @403_650430
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 388)))(PV[37], (u32)(20), PV[36], (u32)(7091252));  // @404_650430
  ecx = edx = 0;  // @405_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @406_650430
  ecx = (u32)(EBP - 296);  // @407_650430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785112) + 0), 4); v; });  // @408_650430
  X1[1] = 0;  // @409_650430
  X1[2] = 0;  // @410_650430
  X1[3] = 0;  // @411_650430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @412_650430
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @413_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 88) + 0), 4); v; });  // @414_650430
  X0[1] = 0;  // @415_650430
  X0[2] = 0;  // @416_650430
  X0[3] = 0;  // @417_650430
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @418_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @419_650430
  PV[38] = (u32)(ecx);  // @420_650430
  ecx = ebx;  // @421_650430
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @422_650430
  X1[0] = F2U(U2F(X1[0]) / U2F(X0[0]));  // @423_650430
  X0[0] = X1[0];  // @424_650430
  X0[1] = X1[1];  // @425_650430
  X0[2] = X1[2];  // @426_650430
  X0[3] = X1[3];  // @427_650430
  __builtin_memcpy((void *)((u32)(EBP - 256) + 0), &X1[0], 4);  // @428_650430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6912128) + 0), 4); v; })));  // @429_650430
  __builtin_memcpy((void *)((u32)(EBP - 276) + 0), &X0[0], 4);  // @430_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[38]);  // @431_650430
  ecx = edx = 0;  // @432_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @433_650430
  ecx = (u32)(EBP - 296);  // @434_650430
  PV[39] = (u32)(ecx);  // @435_650430
  ecx = ebx;  // @436_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[39]);  // @437_650430
  ecx = edx = 0;  // @438_650430
  esi = eax;  // @439_650430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @440_650430
  FL[2] = (esi & esi);  // @441_650430
  if (FL[2] == 0) goto L650b2c;  // @442_650430
  L6508f0:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @444_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @445_650430
  SD(&X0[0], w4a_ltod(ecx, edx)); X0[2] = X0[3] = 0; ecx = edx = 0;  // @446_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @447_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @448_650430
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @449_650430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 256) + 0), 4); v; })));  // @450_650430
  __builtin_memcpy((void *)((u32)(EBP - 280) + 0), &X0[0], 4);  // @451_650430
  SD(&X0[0], w4a_ltod(ecx, edx)); X0[2] = X0[3] = 0; ecx = edx = 0;  // @452_650430
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @453_650430
  CFv = ((u32)(esi + (u32)(48)) < (u32)(esi));  // @454_650430
  esi = (esi + (u32)(48));  // @455_650430
  FL[3] = esi;  // @456_650430
  { u32 v = (u32)((u32)(50)); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @457_650430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 256) + 0), 4); v; })));  // @458_650430
  __builtin_memcpy((void *)((u32)(EBP - 236) + 0), &X0[0], 4);  // @459_650430
  X0[0] = 0;  // @460_650430
  X0[1] = 0;  // @461_650430
  X0[2] = 0;  // @462_650430
  X0[3] = 0;  // @463_650430
  __builtin_memcpy((void *)((u32)(EBP - 264) + 0), &X0[0], 4);  // @464_650430
  __builtin_memcpy((void *)((u32)(EBP - 264) + 4), &X0[1], 4);  // @465_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @466_650430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 264), sizeof v); (u32)v; });  // @467_650430
  __builtin_memcpy((void *)((u32)(EBP - 248) + 0), &X0[0], 4);  // @468_650430
  __builtin_memcpy((void *)((u32)(EBP - 248) + 4), &X0[1], 4);  // @469_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 248), sizeof v); (u32)v; });  // @470_650430
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 244), sizeof v); (u32)v; });  // @471_650430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @472_650430
  L650970:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @474_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @475_650430
  FL[0] = ecx; FL[1] = edx;  // @476_650430
  if ((s32)FL[0] > (s32)FL[1]) goto L650983;  // @477_650430
  if ((s32)FL[0] < (s32)FL[1]) goto L65097f;  // @478_650430
  FL[0] = edi; FL[1] = eax;  // @479_650430
  if (FL[0] >= FL[1]) goto L650983;  // @480_650430
  L65097f:;
  edi = eax;  // @482_650430
  ecx = edx;  // @483_650430
  L650983:;
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; }) + eax) < (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; })));  // @485_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 260), &v, sizeof v); }  // @486_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @487_650430
  { u32 a_ = ebx; u32 b_ = edx; u32 c_ = CFv; FL[3] = a_ + b_ + c_; CFv = (u32)(((u64)a_ + b_ + c_) >> 32); }  // @488_650430
  ebx = FL[3];  // @489_650430
  CFv = ((u32)(esi + (u32)(8)) < (u32)(esi));  // @490_650430
  esi = (esi + (u32)(8));  // @491_650430
  FL[3] = esi;  // @492_650430
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; })) < (u32)((u32)(1)));  // @493_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP - 228), &v, sizeof v); }  // @494_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 228), sizeof v); (u32)v; });  // @495_650430
  if (FL[3] != 0) goto L650970;  // @496_650430
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 232), &v, sizeof v); }  // @497_650430
  edx = ebx;  // @498_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 260), sizeof v); (u32)v; });  // @499_650430
  SD(&X0[0], w4a_ltod(ecx, edx)); X0[2] = X0[3] = 0; ecx = edx = 0;  // @500_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 232), sizeof v); (u32)v; });  // @501_650430
  ecx = edi;  // @502_650430
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @503_650430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 276) + 0), 4); v; })));  // @504_650430
  __builtin_memcpy((void *)((u32)(EBP - 228) + 0), &X0[0], 4);  // @505_650430
  SD(&X0[0], w4a_ltod(ecx, edx)); X0[2] = X0[3] = 0; ecx = edx = 0;  // @506_650430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 272), sizeof v); (u32)v; });  // @507_650430
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 268), sizeof v); (u32)v; });  // @508_650430
  X0[0] = F2U((float)U2D(X0[0], X0[1]));  // @509_650430
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 256) + 0), 4); v; })));  // @510_650430
  __builtin_memcpy((void *)((u32)(EBP - 232) + 0), &X0[0], 4);  // @511_650430
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }); FL[1] = edi;  // @512_650430
  if ((s32)FL[0] > (s32)FL[1]) goto L650a0a;  // @513_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 216), sizeof v); (u32)v; });  // @514_650430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @515_650430
  edx = ((s32)eax < 0) ? 0xffffffffu : 0u;  // @516_650430
  CFv = ((u32)(eax) < (u32)(edx));  // @517_650430
  eax = (eax - edx);  // @518_650430
  FL[3] = eax;  // @519_650430
  eax = (u32)((s32)eax >> (u32)(1));  // @520_650430
  FL[3] = eax;  // @521_650430
  CFv = ((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; }) + eax) < (u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; })));  // @522_650430
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; }) + eax)); __builtin_memcpy((void *)(u32)(EBP - 224), &v, sizeof v); }  // @523_650430
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @524_650430
  L650a0a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @526_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @527_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @528_650430
  ecx = edx = 0;  // @529_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 228) + 0), 4); v; });  // @530_650430
  X0[1] = 0;  // @531_650430
  X0[2] = 0;  // @532_650430
  X0[3] = 0;  // @533_650430
  ecx = eax;  // @534_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 240), sizeof v); (u32)v; });  // @535_650430
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @536_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @537_650430
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @538_650430
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 477), sizeof v); (u32)v; });  // @539_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @540_650430
  CFv = ((u32)(eax + (u32)(20)) < (u32)(eax));  // @541_650430
  eax = (eax + (u32)(20));  // @542_650430
  FL[3] = eax;  // @543_650430
  PV[42] = X0[0]; PV[43] = X0[1];  // @544_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 232) + 0), 4); v; });  // @545_650430
  X0[1] = 0;  // @546_650430
  X0[2] = 0;  // @547_650430
  X0[3] = 0;  // @548_650430
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @549_650430
  PV[44] = X0[0]; PV[45] = X0[1];  // @550_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 236) + 0), 4); v; });  // @551_650430
  X0[1] = 0;  // @552_650430
  X0[2] = 0;  // @553_650430
  X0[3] = 0;  // @554_650430
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @555_650430
  PV[46] = X0[0]; PV[47] = X0[1];  // @556_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 280) + 0), 4); v; });  // @557_650430
  X0[1] = 0;  // @558_650430
  X0[2] = 0;  // @559_650430
  X0[3] = 0;  // @560_650430
  { double a_ = (double)U2F(X0[0]), b_ = (double)U2F(X0[1]); SD(&X0[0], a_); SD(&X0[2], b_); }  // @561_650430
  PV[48] = X0[0]; PV[49] = X0[1];  // @562_650430
  PV[50] = (u32)(edi);  // @563_650430
  PV[51] = (u32)(eax);  // @564_650430
  PV[52] = (u32)(ecx);  // @565_650430
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[52], PV[51], PV[50], (u32)(7091296), PV[48], PV[49], PV[46], PV[47], PV[44], PV[45], PV[42], PV[43], PV[41], PV[40]);  // @566_650430
  ecx = edx = 0;  // @567_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 236) + 0), 4); v; });  // @568_650430
  X0[1] = 0;  // @569_650430
  X0[2] = 0;  // @570_650430
  X0[3] = 0;  // @571_650430
  ecx = (u32)(EBP - 296);  // @572_650430
  X0[0] = F2U(U2F(X0[0]) + U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 220) + 0), 4); v; })));  // @573_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @574_650430
  edi = (edi + 1);  // @575_650430
  FL[3] = edi;  // @576_650430
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @577_650430
  PV[53] = (u32)(ecx);  // @578_650430
  ecx = ebx;  // @579_650430
  __builtin_memcpy((void *)((u32)(EBP - 220) + 0), &X0[0], 4);  // @580_650430
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[53]);  // @581_650430
  ecx = edx = 0;  // @582_650430
  esi = eax;  // @583_650430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 240), &v, sizeof v); }  // @584_650430
  FL[2] = (esi & esi);  // @585_650430
  if (FL[2] != 0) goto L6508f0;  // @586_650430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 220) + 0), 4); v; });  // @587_650430
  X1[1] = 0;  // @588_650430
  X1[2] = 0;  // @589_650430
  X1[3] = 0;  // @590_650430
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) << 8);  // @591_650430
  FL[2] = ((u32)(0x02 | (!(U2F(X1[0]) >= U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) ? 1 : 0) | (((U2F(X1[0]) != U2F(X1[0])) || (U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })) != U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; })))) ? 4 : 0) | ((!((U2F(X1[0]) < U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))) || (U2F(X1[0]) > U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784464) + 0), 4); v; }))))) ? 0x40 : 0)) & 68);  // @592_650430
  if (__builtin_parity(FL[2] & 0xff)) goto L650b2c;  // @593_650430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @594_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @595_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @596_650430
  ecx = edx = 0;  // @597_650430
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 220) + 0), 4); v; });  // @598_650430
  X1[1] = 0;  // @599_650430
  X1[2] = 0;  // @600_650430
  X1[3] = 0;  // @601_650430
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7091936) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7091936) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @602_650430
  esi = eax;  // @603_650430
  { double a_ = (double)U2F(X1[0]), b_ = (double)U2F(X1[1]); SD(&X1[0], a_); SD(&X1[2], b_); }  // @604_650430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 224), sizeof v); (u32)v; });  // @605_650430
  eax = (eax + 1);  // @606_650430
  FL[3] = eax;  // @607_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @608_650430
  SD(&X0[0], U2D(X0[0], X0[1]) / U2D(X1[0], X1[1]));  // @609_650430
  PV[54] = X0[0]; PV[55] = X0[1];  // @610_650430
  PV[56] = X1[0]; PV[57] = X1[1];  // @611_650430
  PV[58] = (u32)(edi);  // @612_650430
  PV[59] = (u32)(eax);  // @613_650430
  PV[60] = (u32)(esi);  // @614_650430
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 388)))(PV[60], PV[59], PV[58], (u32)(7091328), PV[56], PV[57], PV[54], PV[55]);  // @615_650430
  ecx = edx = 0;  // @616_650430
  L650b2c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @618_650430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @619_650430
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @620_650430
  ecx = edx = 0;  // @621_650430
  ext_633654(G(u32, 0x6f5630));  // @622_650430
  eax = edi;  // @623_650430
  return eax;  // @624_650430
}
PCREG(650430, lifted_650430);

