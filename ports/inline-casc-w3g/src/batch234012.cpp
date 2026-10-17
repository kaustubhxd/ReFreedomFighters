// batch234012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5003d0_thiscall2(u32, u32) __asm__("ext_5003d0");
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_50ed00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @1_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @2_50ed00
  ecx = edx = 0;  // @3_50ed00
  edi = eax;  // @4_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @5_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @6_50ed00
  if (FL[2] == 0) goto L50ed57;  // @7_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @8_50ed00
  if (FL[0] == FL[1]) goto L50ed57;  // @9_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @10_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @12_50ed00
  ecx = edx = 0;  // @13_50ed00
  PV[0] = (u32)(eax);  // @14_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @15_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[0], (u32)(6932144), (u32)(6932792));  // @16_50ed00
  ecx = edx = 0;  // @17_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @18_50ed00
  FL[2] = (eax & eax);  // @19_50ed00
  if (FL[2] == 0) goto L50ed56;  // @20_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @21_50ed00
  ecx = edx = 0;  // @22_50ed00
  goto L50ed57;  // @23_50ed00
  L50ed56:;
  __builtin_trap();  // @25_50ed00
  L50ed57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_50ed00
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @29_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_50ed00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @31_50ed00
  ecx = edx = 0;  // @32_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @33_50ed00
  edi = eax;  // @34_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(3));  // @35_50ed00
  ecx = edx = 0;  // @36_50ed00
  ebx = eax;  // @37_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @38_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @39_50ed00
  if (FL[2] == 0) goto L50edba;  // @40_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @41_50ed00
  if (FL[0] == FL[1]) goto L50edba;  // @42_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @43_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @45_50ed00
  ecx = edx = 0;  // @46_50ed00
  PV[2] = (u32)(eax);  // @47_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @48_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[2], (u32)(6932144), (u32)(6932792));  // @49_50ed00
  ecx = edx = 0;  // @50_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @51_50ed00
  FL[2] = (eax & eax);  // @52_50ed00
  if (FL[2] == 0) goto L50edb9;  // @53_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @54_50ed00
  ecx = edx = 0;  // @55_50ed00
  goto L50edba;  // @56_50ed00
  L50edb9:;
  __builtin_trap();  // @58_50ed00
  L50edba:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @60_50ed00
  X0[1] = 0;  // @61_50ed00
  X0[2] = 0;  // @62_50ed00
  X0[3] = 0;  // @63_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @64_50ed00
  __builtin_memcpy((void *)((u32)(EBP - 4) + 0), &X0[0], 4);  // @65_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @66_50ed00
  ecx = edx = 0;  // @67_50ed00
  ebx = eax;  // @68_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @69_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @70_50ed00
  if (FL[2] == 0) goto L50ee11;  // @71_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @72_50ed00
  if (FL[0] == FL[1]) goto L50ee11;  // @73_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @74_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @76_50ed00
  ecx = edx = 0;  // @77_50ed00
  PV[3] = (u32)(eax);  // @78_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @79_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[3], (u32)(6932144), (u32)(6932792));  // @80_50ed00
  ecx = edx = 0;  // @81_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @82_50ed00
  FL[2] = (eax & eax);  // @83_50ed00
  if (FL[2] == 0) goto L50ee10;  // @84_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @85_50ed00
  ecx = edx = 0;  // @86_50ed00
  goto L50ee11;  // @87_50ed00
  L50ee10:;
  __builtin_trap();  // @89_50ed00
  L50ee11:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @91_50ed00
  X0[1] = 0;  // @92_50ed00
  X0[2] = 0;  // @93_50ed00
  X0[3] = 0;  // @94_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @95_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @96_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @97_50ed00
  ecx = edx = 0;  // @98_50ed00
  ebx = eax;  // @99_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @100_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @101_50ed00
  if (FL[2] == 0) goto L50ee68;  // @102_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @103_50ed00
  if (FL[0] == FL[1]) goto L50ee68;  // @104_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @105_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @107_50ed00
  ecx = edx = 0;  // @108_50ed00
  PV[4] = (u32)(eax);  // @109_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[4], (u32)(6932144), (u32)(6932792));  // @111_50ed00
  ecx = edx = 0;  // @112_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @113_50ed00
  FL[2] = (eax & eax);  // @114_50ed00
  if (FL[2] == 0) goto L50ee67;  // @115_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @116_50ed00
  ecx = edx = 0;  // @117_50ed00
  goto L50ee68;  // @118_50ed00
  L50ee67:;
  __builtin_trap();  // @120_50ed00
  L50ee68:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @122_50ed00
  X0[1] = 0;  // @123_50ed00
  X0[2] = 0;  // @124_50ed00
  X0[3] = 0;  // @125_50ed00
  __builtin_memcpy((void *)((u32)(7345268) + 0), &X0[0], 4);  // @126_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @127_50ed00
  X0[1] = 0;  // @128_50ed00
  X0[2] = 0;  // @129_50ed00
  X0[3] = 0;  // @130_50ed00
  __builtin_memcpy((void *)((u32)(7345272) + 0), &X0[0], 4);  // @131_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 4) + 0), 4); v; });  // @132_50ed00
  X0[1] = 0;  // @133_50ed00
  X0[2] = 0;  // @134_50ed00
  X0[3] = 0;  // @135_50ed00
  __builtin_memcpy((void *)((u32)(7345276) + 0), &X0[0], 4);  // @136_50ed00
  FL[2] = (edi & edi);  // @137_50ed00
  if (FL[2] == 0) goto L50eea3;  // @138_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @139_50ed00
  ecx = edi;  // @140_50ed00
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(7345268));  // @141_50ed00
  ecx = edx = 0;  // @142_50ed00
  goto L50ef18;  // @143_50ed00
  L50eea3:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @145_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6937396), (u32)(688));  // @147_50ed00
  ecx = edx = 0;  // @148_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @149_50ed00
  edi = eax;  // @150_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @151_50ed00
  ecx = edx = 0;  // @152_50ed00
  ebx = eax;  // @153_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @154_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @155_50ed00
  if (FL[2] == 0) goto L50ef08;  // @156_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(1);  // @157_50ed00
  if (FL[0] == FL[1]) goto L50ef08;  // @158_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @159_50ed00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @160_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6932704), (u32)(260));  // @161_50ed00
  ecx = edx = 0;  // @162_50ed00
  PV[5] = (u32)(eax);  // @163_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @164_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[5], (u32)(6932144), (u32)(6932792));  // @165_50ed00
  ecx = edx = 0;  // @166_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @167_50ed00
  FL[2] = (eax & eax);  // @168_50ed00
  if (FL[2] == 0) goto L50ef07;  // @169_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @170_50ed00
  ecx = edx = 0;  // @171_50ed00
  goto L50ef08;  // @172_50ed00
  L50ef07:;
  __builtin_trap();  // @174_50ed00
  L50ef08:;
  PV[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @176_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @177_50ed00
  PV[7] = (u32)(edi);  // @178_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(eax + 44)))(PV[7], (u32)(6938384), PV[6]);  // @179_50ed00
  ecx = edx = 0;  // @180_50ed00
  L50ef18:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7345268) + 0), 4); v; });  // @182_50ed00
  X0[1] = 0;  // @183_50ed00
  X0[2] = 0;  // @184_50ed00
  X0[3] = 0;  // @185_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @186_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @187_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(0));  // @188_50ed00
  ecx = edx = 0;  // @189_50ed00
  edi = eax;  // @190_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @191_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @192_50ed00
  if (FL[2] == 0) goto L50ef74;  // @193_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @194_50ed00
  if (FL[0] == FL[1]) goto L50ef74;  // @195_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @196_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @197_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @198_50ed00
  ecx = edx = 0;  // @199_50ed00
  PV[8] = (u32)(eax);  // @200_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @201_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[8], (u32)(6932144), (u32)(6932792));  // @202_50ed00
  ecx = edx = 0;  // @203_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @204_50ed00
  FL[2] = (eax & eax);  // @205_50ed00
  if (FL[2] == 0) goto L50ef73;  // @206_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @207_50ed00
  ecx = edx = 0;  // @208_50ed00
  goto L50ef74;  // @209_50ed00
  L50ef73:;
  __builtin_trap();  // @211_50ed00
  L50ef74:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @213_50ed00
  X0[1] = 0;  // @214_50ed00
  X0[2] = 0;  // @215_50ed00
  X0[3] = 0;  // @216_50ed00
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @217_50ed00
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @218_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7345272) + 0), 4); v; });  // @219_50ed00
  X0[1] = 0;  // @220_50ed00
  X0[2] = 0;  // @221_50ed00
  X0[3] = 0;  // @222_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @223_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @224_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(1));  // @225_50ed00
  ecx = edx = 0;  // @226_50ed00
  edi = eax;  // @227_50ed00
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; })) & 0xff);  // @228_50ed00
  FL[2] = ((ecx & 0xff) & (ecx & 0xff));  // @229_50ed00
  if (FL[2] == 0) goto L50efdc;  // @230_50ed00
  FL[0] = (ecx & 0xff); FL[1] = (u32)(2);  // @231_50ed00
  if (FL[0] == FL[1]) goto L50efdc;  // @232_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @233_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @234_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @235_50ed00
  ecx = edx = 0;  // @236_50ed00
  PV[9] = (u32)(eax);  // @237_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @238_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[9], (u32)(6932144), (u32)(6932792));  // @239_50ed00
  ecx = edx = 0;  // @240_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @241_50ed00
  FL[2] = (eax & eax);  // @242_50ed00
  if (FL[2] == 0) goto L50efdb;  // @243_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @244_50ed00
  ecx = edx = 0;  // @245_50ed00
  goto L50efdc;  // @246_50ed00
  L50efdb:;
  __builtin_trap();  // @248_50ed00
  L50efdc:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @250_50ed00
  X0[1] = 0;  // @251_50ed00
  X0[2] = 0;  // @252_50ed00
  X0[3] = 0;  // @253_50ed00
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @254_50ed00
  __builtin_memcpy((void *)((u32)(edi) + 0), &X0[0], 4);  // @255_50ed00
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(7345276) + 0), 4); v; });  // @256_50ed00
  X0[1] = 0;  // @257_50ed00
  X0[2] = 0;  // @258_50ed00
  X0[3] = 0;  // @259_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @260_50ed00
  __builtin_memcpy((void *)((u32)(EBP + 8) + 0), &X0[0], 4);  // @261_50ed00
  eax = ext_5003d0_thiscall2(ecx, (u32)(2));  // @262_50ed00
  ecx = edx = 0;  // @263_50ed00
  esi = eax;  // @264_50ed00
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @265_50ed00
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @266_50ed00
  if (FL[2] == 0) goto L50f043;  // @267_50ed00
  FL[0] = (eax & 0xff); FL[1] = (u32)(2);  // @268_50ed00
  if (FL[0] == FL[1]) goto L50f043;  // @269_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @270_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @271_50ed00
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6932704), (u32)(260));  // @272_50ed00
  ecx = edx = 0;  // @273_50ed00
  PV[10] = (u32)(eax);  // @274_50ed00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @275_50ed00
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(PV[10], (u32)(6932144), (u32)(6932792));  // @276_50ed00
  ecx = edx = 0;  // @277_50ed00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @278_50ed00
  FL[2] = (eax & eax);  // @279_50ed00
  if (FL[2] == 0) goto L50f042;  // @280_50ed00
  eax = ((u32(STDCALL *)(void))(eax))();  // @281_50ed00
  ecx = edx = 0;  // @282_50ed00
  goto L50f043;  // @283_50ed00
  L50f042:;
  __builtin_trap();  // @285_50ed00
  L50f043:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP + 8) + 0), 4); v; });  // @287_50ed00
  X0[1] = 0;  // @288_50ed00
  X0[2] = 0;  // @289_50ed00
  X0[3] = 0;  // @290_50ed00
  { u8 v = (u8)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @291_50ed00
  __builtin_memcpy((void *)((u32)(esi) + 0), &X0[0], 4);  // @292_50ed00
  return eax;  // @293_50ed00
}
PCREG(50ed00, lifted_50ed00);

