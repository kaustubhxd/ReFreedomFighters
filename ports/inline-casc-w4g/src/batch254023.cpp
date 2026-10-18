// batch254023.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_431410_thiscall3(u32, u32, u32) __asm__("ext_431410");
extern "C" u32 THISCALL ext_43b710_thiscall3(u32, u32, u32) __asm__("ext_43b710");
extern "C" u32 THISCALL ext_43b9f0_thiscall1(u32) __asm__("ext_43b9f0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_61ba60_thiscall1(u32) __asm__("ext_61ba60");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_432650(u32 ecx_in) {
  SEH_ENTER(0x665536);  // @h_432650
  u8 F[0x430] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x330);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; float FC0 = 0, FC1 = 0; u32 MOF = 0; u32 ecx_zero = 0, edx_zero = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_432650
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(ebx + 232), &v, sizeof v); }  // @1_432650
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(ebx + 236), &v, sizeof v); }  // @2_432650
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(ebx + 240), &v, sizeof v); }  // @3_432650
  { u32 v = (u32)((u32)(90)); __builtin_memcpy((void *)(u32)(ebx + 244), &v, sizeof v); }  // @4_432650
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(ebx + 228), &v, sizeof v); }  // @5_432650
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(ebx + 248), &v, sizeof v); }  // @6_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_432650
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @8_432650
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 253), &v, sizeof v); }  // @9_432650
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @10_432650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 252), &v, sizeof v); }  // @11_432650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_432650
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_432650
  ecx = (ecx + (u32)(1187));  // @14_432650
  FL[3] = ecx;  // @15_432650
  eax = ext_4cc1d0_thiscall1(ecx);  // @16_432650
    // @17_432650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_432650
  PV[0] = (u32)(eax);  // @19_432650
  eax = (u32)(EBP - 144);  // @20_432650
  PV[1] = (u32)(eax);  // @21_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 324)))(ecx, PV[1], PV[0]);  // @22_432650
  ecx = edx = 0;  // @23_432650
  ecx = eax;  // @24_432650
  reg.state = (s32)((u32)(0));  // @25_432650
  eax = ext_4cc1d0_thiscall1(ecx);  // @26_432650
    // @27_432650
  PV[2] = (u32)(eax);  // @28_432650
  PV[3] = (u32)(ebx);  // @29_432650
  ecx = (u32)(EBP - 732);  // @30_432650
  eax = ext_43b710_thiscall3(ecx, PV[3], PV[2]);  // @31_432650
  ecx = edx = 0;  // @32_432650
  ecx = (u32)(EBP - 144);  // @33_432650
  reg.state = (s32)((u32)(2));  // @34_432650
  eax = ext_4cbec0_thiscall1(ecx);  // @35_432650
  ecx = edx = 0;  // @36_432650
  ecx = (u32)(EBP - 732);  // @37_432650
  eax = ext_43b9f0_thiscall1(ecx);  // @38_432650
  ecx = edx = 0;  // @39_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @40_432650
  if (FL[2] != 0) goto L432769;  // @41_432650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @42_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(58));  // @44_432650
  ecx = edx = 0;  // @45_432650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_432650
  esi = eax;  // @47_432650
  ecx = (ecx + (u32)(1187));  // @48_432650
  FL[3] = ecx;  // @49_432650
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @50_432650
  eax = ext_4cc1d0_thiscall1(ecx);  // @51_432650
    // @52_432650
  PV[4] = (u32)(eax);  // @53_432650
  PV[5] = (u32)(esi);  // @54_432650
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))(PV[5], (u32)(6791076), PV[4]);  // @55_432650
  ecx = edx = 0;  // @56_432650
  L432769:;
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 257), &v, sizeof v); }  // @58_432650
  edx = (u32)(EBP - 736);  // @59_432650
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_432650
  PV[6] = (u32)(edx);  // @61_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @63_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791112), PV[6]);  // @64_432650
  ecx = edx = 0;  // @65_432650
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775512), sizeof v); (u32)v; });  // @66_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @67_432650
  if (FL[2] == 0) goto L4327ce;  // @68_432650
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @69_432650
  eax = ((u32( *)(u32))(esi))(PV[7]);  // @70_432650
  ecx = edx = 0;  // @71_432650
  FL[2] = (eax & eax);  // @72_432650
  if ((s32)FL[2] >= 0) goto L4327a6;  // @73_432650
  eax = 0;  // @74_432650
  FL[3] = eax;  // @75_432650
  goto L4327c8;  // @76_432650
  L4327a6:;
  PV[8] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @78_432650
  eax = ((u32( *)(u32))(esi))(PV[8]);  // @79_432650
  ecx = edx = 0;  // @80_432650
  FL[0] = eax; FL[1] = (u32)(100);  // @81_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L4327bd;  // @82_432650
  eax = (u32)(100);  // @83_432650
  goto L4327c8;  // @84_432650
  L4327bd:;
  PV[9] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @86_432650
  eax = ((u32( *)(u32))(esi))(PV[9]);  // @87_432650
  ecx = edx = 0;  // @88_432650
  L4327c8:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 232), &v, sizeof v); }  // @90_432650
  L4327ce:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_432650
  edx = (u32)(EBP - 736);  // @93_432650
  PV[10] = (u32)(edx);  // @94_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @96_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791132), PV[10]);  // @97_432650
  ecx = edx = 0;  // @98_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @99_432650
  if (FL[2] == 0) goto L432826;  // @100_432650
  PV[11] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @101_432650
  eax = ((u32( *)(u32))(esi))(PV[11]);  // @102_432650
  ecx = edx = 0;  // @103_432650
  FL[2] = (eax & eax);  // @104_432650
  if ((s32)FL[2] >= 0) goto L4327fe;  // @105_432650
  eax = 0;  // @106_432650
  FL[3] = eax;  // @107_432650
  goto L432820;  // @108_432650
  L4327fe:;
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @110_432650
  eax = ((u32( *)(u32))(esi))(PV[12]);  // @111_432650
  ecx = edx = 0;  // @112_432650
  FL[0] = eax; FL[1] = (u32)(100);  // @113_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L432815;  // @114_432650
  eax = (u32)(100);  // @115_432650
  goto L432820;  // @116_432650
  L432815:;
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @118_432650
  eax = ((u32( *)(u32))(esi))(PV[13]);  // @119_432650
  ecx = edx = 0;  // @120_432650
  L432820:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 236), &v, sizeof v); }  // @122_432650
  L432826:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_432650
  edx = (u32)(EBP - 736);  // @125_432650
  PV[14] = (u32)(edx);  // @126_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @128_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791144), PV[14]);  // @129_432650
  ecx = edx = 0;  // @130_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @131_432650
  if (FL[2] == 0) goto L43287e;  // @132_432650
  PV[15] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @133_432650
  eax = ((u32( *)(u32))(esi))(PV[15]);  // @134_432650
  ecx = edx = 0;  // @135_432650
  FL[2] = (eax & eax);  // @136_432650
  if ((s32)FL[2] >= 0) goto L432856;  // @137_432650
  eax = 0;  // @138_432650
  FL[3] = eax;  // @139_432650
  goto L432878;  // @140_432650
  L432856:;
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @142_432650
  eax = ((u32( *)(u32))(esi))(PV[16]);  // @143_432650
  ecx = edx = 0;  // @144_432650
  FL[0] = eax; FL[1] = (u32)(100);  // @145_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L43286d;  // @146_432650
  eax = (u32)(100);  // @147_432650
  goto L432878;  // @148_432650
  L43286d:;
  PV[17] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @150_432650
  eax = ((u32( *)(u32))(esi))(PV[17]);  // @151_432650
  ecx = edx = 0;  // @152_432650
  L432878:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 244), &v, sizeof v); }  // @154_432650
  L43287e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @156_432650
  edx = (u32)(EBP - 736);  // @157_432650
  PV[18] = (u32)(edx);  // @158_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @159_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @160_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791164), PV[18]);  // @161_432650
  ecx = edx = 0;  // @162_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @163_432650
  if (FL[2] == 0) goto L4328d6;  // @164_432650
  PV[19] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @165_432650
  eax = ((u32( *)(u32))(esi))(PV[19]);  // @166_432650
  ecx = edx = 0;  // @167_432650
  FL[2] = (eax & eax);  // @168_432650
  if ((s32)FL[2] >= 0) goto L4328ae;  // @169_432650
  eax = 0;  // @170_432650
  FL[3] = eax;  // @171_432650
  goto L4328d0;  // @172_432650
  L4328ae:;
  PV[20] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @174_432650
  eax = ((u32( *)(u32))(esi))(PV[20]);  // @175_432650
  ecx = edx = 0;  // @176_432650
  FL[0] = eax; FL[1] = (u32)(100);  // @177_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L4328c5;  // @178_432650
  eax = (u32)(100);  // @179_432650
  goto L4328d0;  // @180_432650
  L4328c5:;
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @182_432650
  eax = ((u32( *)(u32))(esi))(PV[21]);  // @183_432650
  ecx = edx = 0;  // @184_432650
  L4328d0:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 240), &v, sizeof v); }  // @186_432650
  L4328d6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @188_432650
  edx = (u32)(EBP - 736);  // @189_432650
  PV[22] = (u32)(edx);  // @190_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @191_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @192_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791180), PV[22]);  // @193_432650
  ecx = edx = 0;  // @194_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @195_432650
  if (FL[2] == 0) goto L43294b;  // @196_432650
  PV[23] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @197_432650
  eax = ((u32( *)(u32))(*(u32 *)0x6762d4))(PV[23]);  // @198_432650
  ecx = edx = 0;  // @199_432650
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784504) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784504) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @200_432650
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)(EBP - 744)) :: "st");  // @201_432650
  if ((!(!(U2D(X0[0], X0[1]) >= U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 4), 4); v; })))) && !(!((U2D(X0[0], X0[1]) < U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 4), 4); v; }))) || (U2D(X0[0], X0[1]) > U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 4), 4); v; }))))))) goto L43293f;  // @202_432650
  PV[24] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @203_432650
  eax = ((u32( *)(u32))(*(u32 *)0x6762d4))(PV[24]);  // @204_432650
  ecx = edx = 0;  // @205_432650
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 0), 4); v; }); X0[1] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6784528) + 4), 4); v; }); X0[2] = X0[3] = 0;  // @206_432650
  __asm__ volatile("fstpl %0" : "=m"(*(double *)(u32)(EBP - 744)) :: "st");  // @207_432650
  { double a_ = U2D(X0[0], X0[1]), b_ = U2D(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 0), 4); v; }), ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 744) + 4), 4); v; })); SD(&X0[0], (a_ < b_) ? a_ : b_); }  // @208_432650
  L43293f:;
  { float a_ = (float)U2D(X0[0], X0[1]), b_ = (float)U2D(X0[2], X0[3]); X0[0] = F2U(a_); X0[1] = F2U(b_); X0[2] = X0[3] = 0; }  // @210_432650
  __builtin_memcpy((void *)((u32)(ebx + 228) + 0), &X0[0], 4);  // @211_432650
  L43294b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @213_432650
  edx = (u32)(EBP - 736);  // @214_432650
  PV[25] = (u32)(edx);  // @215_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @216_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @217_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791192), PV[25]);  // @218_432650
  ecx = edx = 0;  // @219_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @220_432650
  if (FL[2] == 0) goto L4329a8;  // @221_432650
  PV[26] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @222_432650
  eax = ((u32( *)(u32))(esi))(PV[26]);  // @223_432650
  ecx = edx = 0;  // @224_432650
  FL[2] = (eax & eax);  // @225_432650
  if ((s32)FL[2] >= 0) goto L43297b;  // @226_432650
  eax = 0;  // @227_432650
  FL[3] = eax;  // @228_432650
  goto L43299d;  // @229_432650
  L43297b:;
  PV[27] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @231_432650
  eax = ((u32( *)(u32))(esi))(PV[27]);  // @232_432650
  ecx = edx = 0;  // @233_432650
  FL[0] = eax; FL[1] = (u32)(1);  // @234_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L432992;  // @235_432650
  eax = (u32)(1);  // @236_432650
  goto L43299d;  // @237_432650
  L432992:;
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @239_432650
  eax = ((u32( *)(u32))(esi))(PV[28]);  // @240_432650
  ecx = edx = 0;  // @241_432650
  L43299d:;
  FL[2] = (eax & eax);  // @243_432650
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @244_432650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 253), &v, sizeof v); }  // @245_432650
  L4329a8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @247_432650
  edx = (u32)(EBP - 736);  // @248_432650
  PV[29] = (u32)(edx);  // @249_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @250_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @251_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791204), PV[29]);  // @252_432650
  ecx = edx = 0;  // @253_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @254_432650
  if (FL[2] == 0) goto L432a05;  // @255_432650
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @256_432650
  eax = ((u32( *)(u32))(esi))(PV[30]);  // @257_432650
  ecx = edx = 0;  // @258_432650
  FL[2] = (eax & eax);  // @259_432650
  if ((s32)FL[2] >= 0) goto L4329d8;  // @260_432650
  eax = 0;  // @261_432650
  FL[3] = eax;  // @262_432650
  goto L4329fa;  // @263_432650
  L4329d8:;
  PV[31] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @265_432650
  eax = ((u32( *)(u32))(esi))(PV[31]);  // @266_432650
  ecx = edx = 0;  // @267_432650
  FL[0] = eax; FL[1] = (u32)(1);  // @268_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L4329ef;  // @269_432650
  eax = (u32)(1);  // @270_432650
  goto L4329fa;  // @271_432650
  L4329ef:;
  PV[32] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @273_432650
  eax = ((u32( *)(u32))(esi))(PV[32]);  // @274_432650
  ecx = edx = 0;  // @275_432650
  L4329fa:;
  FL[2] = (eax & eax);  // @277_432650
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @278_432650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 254), &v, sizeof v); }  // @279_432650
  L432a05:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @281_432650
  edx = (u32)(EBP - 736);  // @282_432650
  PV[33] = (u32)(edx);  // @283_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @284_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @285_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791228), PV[33]);  // @286_432650
  ecx = edx = 0;  // @287_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @288_432650
  if (FL[2] == 0) goto L432a62;  // @289_432650
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @290_432650
  eax = ((u32( *)(u32))(esi))(PV[34]);  // @291_432650
  ecx = edx = 0;  // @292_432650
  FL[2] = (eax & eax);  // @293_432650
  if ((s32)FL[2] >= 0) goto L432a35;  // @294_432650
  eax = 0;  // @295_432650
  FL[3] = eax;  // @296_432650
  goto L432a57;  // @297_432650
  L432a35:;
  PV[35] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @299_432650
  eax = ((u32( *)(u32))(esi))(PV[35]);  // @300_432650
  ecx = edx = 0;  // @301_432650
  FL[0] = eax; FL[1] = (u32)(1);  // @302_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L432a4c;  // @303_432650
  eax = (u32)(1);  // @304_432650
  goto L432a57;  // @305_432650
  L432a4c:;
  PV[36] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @307_432650
  eax = ((u32( *)(u32))(esi))(PV[36]);  // @308_432650
  ecx = edx = 0;  // @309_432650
  L432a57:;
  FL[2] = (eax & eax);  // @311_432650
  eax = (eax & 0xffffff00u) | ((((FL[2] != 0) ? 1 : 0)) & 0xff);  // @312_432650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 252), &v, sizeof v); }  // @313_432650
  L432a62:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @315_432650
  edx = (u32)(EBP - 736);  // @316_432650
  PV[37] = (u32)(edx);  // @317_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @318_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @319_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791240), PV[37]);  // @320_432650
  ecx = edx = 0;  // @321_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @322_432650
  if (FL[2] == 0) goto L432a90;  // @323_432650
  PV[38] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @324_432650
  eax = ((u32( *)(u32))(esi))(PV[38]);  // @325_432650
  ecx = edx = 0;  // @326_432650
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 248), &v, sizeof v); }  // @327_432650
  L432a90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @329_432650
  edx = (u32)(EBP - 736);  // @330_432650
  PV[39] = (u32)(edx);  // @331_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @332_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @333_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6791256), PV[39]);  // @334_432650
  ecx = edx = 0;  // @335_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @336_432650
  if (FL[2] == 0) goto L432aed;  // @337_432650
  PV[40] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @338_432650
  eax = ((u32( *)(u32))(esi))(PV[40]);  // @339_432650
  ecx = edx = 0;  // @340_432650
  FL[2] = (eax & eax);  // @341_432650
  if ((s32)FL[2] >= 0) goto L432ac0;  // @342_432650
  eax = 0;  // @343_432650
  FL[3] = eax;  // @344_432650
  goto L432ae2;  // @345_432650
  L432ac0:;
  PV[41] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @347_432650
  eax = ((u32( *)(u32))(esi))(PV[41]);  // @348_432650
  ecx = edx = 0;  // @349_432650
  FL[0] = eax; FL[1] = (u32)(1);  // @350_432650
  if ((s32)FL[0] <= (s32)FL[1]) goto L432ad7;  // @351_432650
  eax = (u32)(1);  // @352_432650
  goto L432ae2;  // @353_432650
  L432ad7:;
  PV[42] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 736), sizeof v); (u32)v; });  // @355_432650
  eax = ((u32( *)(u32))(esi))(PV[42]);  // @356_432650
  ecx = edx = 0;  // @357_432650
  L432ae2:;
  FL[2] = (eax & eax);  // @359_432650
  eax = (eax & 0xffffff00u) | ((((FL[2] == 0) ? 1 : 0)) & 0xff);  // @360_432650
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 257), &v, sizeof v); }  // @361_432650
  L432aed:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @363_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @364_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @365_432650
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6790096), (u32)(0));  // @366_432650
  ecx = edx = 0;  // @367_432650
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @368_432650
  if (FL[2] == 0) goto L432b1f;  // @369_432650
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @370_432650
  ecx = ebx;  // @371_432650
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 2489), &v, sizeof v); }  // @372_432650
  eax = ext_431410_thiscall3(ecx, (u32)(6790096), (u32)(1));  // @373_432650
  ecx = edx = 0;  // @374_432650
  L432b1f:;
  ecx = (u32)(EBP - 281);  // @376_432650
  eax = ext_4cbec0_thiscall1(ecx);  // @377_432650
  ecx = edx = 0;  // @378_432650
  ecx = (u32)(EBP - 409);  // @379_432650
  eax = ext_4cbec0_thiscall1(ecx);  // @380_432650
  ecx = edx = 0;  // @381_432650
  ecx = (u32)(EBP - 537);  // @382_432650
  eax = ext_4cbec0_thiscall1(ecx);  // @383_432650
  ecx = edx = 0;  // @384_432650
  ecx = (u32)(EBP - 716);  // @385_432650
  eax = ext_4cbec0_thiscall1(ecx);  // @386_432650
  ecx = edx = 0;  // @387_432650
  ecx = (u32)(EBP - 732);  // @388_432650
  eax = ext_61ba60_thiscall1(ecx);  // @389_432650
  ecx = edx = 0;  // @390_432650
  SEH_LEAVE();  // @391_432650
  ext_633654(G(u32, 0x6f5630));  // @392_432650
  return eax;  // @393_432650
}
PCREG(432650, lifted_432650);

