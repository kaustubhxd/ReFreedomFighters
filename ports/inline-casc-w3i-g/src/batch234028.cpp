// batch234028.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_43e960_fastcall2(u32, u32) __asm__("ext_43e960");
extern "C" u32 FASTCALL ext_441940_fastcall2(u32, u32) __asm__("ext_441940");
extern "C" u32 FASTCALL ext_4419f0_fastcall2(u32, u32) __asm__("ext_4419f0");
extern "C" u32 FASTCALL ext_441a60_fastcall2(u32, u32) __asm__("ext_441a60");
extern "C" u32 FASTCALL ext_4de420_fastcall2(u32, u32) __asm__("ext_4de420");
extern "C" u32 FASTCALL ext_4de480_fastcall2(u32, u32) __asm__("ext_4de480");
extern "C" u32 FASTCALL ext_4de4f0_fastcall2(u32, u32) __asm__("ext_4de4f0");
extern "C" u32 FASTCALL ext_4de520_fastcall4(u32, u32, u32, u32) __asm__("ext_4de520");
extern "C" u32 THISCALL ext_484b10_thiscall6(u32, u32, u32, u32, u32, u32) __asm__("ext_484b10");
extern "C" u32 THISCALL ext_4895c0_thiscall3(u32, u32, u32) __asm__("ext_4895c0");
extern "C" u32 THISCALL ext_4dafb0_thiscall1(u32) __asm__("ext_4dafb0");
extern "C" u32 THISCALL ext_4db6c0_thiscall3(u32, u32, u32) __asm__("ext_4db6c0");
extern "C" u32 THISCALL ext_4db9a0_thiscall2(u32, u32) __asm__("ext_4db9a0");
extern "C" u32 THISCALL ext_4ea260_thiscall2(u32, u32) __asm__("ext_4ea260");
extern "C" u32 THISCALL ext_4ea300_thiscall2(u32, u32) __asm__("ext_4ea300");
extern "C" u32 THISCALL ext_4ea8e0_thiscall3(u32, u32, u32) __asm__("ext_4ea8e0");
extern "C" u32 THISCALL ext_4eb080_thiscall4(u32, u32, u32, u32) __asm__("ext_4eb080");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_484380(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  u8 F[0x101d0] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x100d0);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0x0b0b0b0b, esi = 0x0d0d0d0d, edi = 0x05151515;
  __builtin_memcpy(F + 0x100d0 + 8, &a0, 4);
  __builtin_memcpy(F + 0x100d0 + 12, &a1, 4);
  __builtin_memcpy(F + 0x100d0 + 16, &a2, 4);
  __builtin_memcpy(F + 0x100d0 + 20, &a3, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_484380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65648), &v, sizeof v); }  // @2_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_484380
  edi = ecx;  // @4_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65668), &v, sizeof v); }  // @5_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @6_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65664), &v, sizeof v); }  // @7_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_484380
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 65640), &v, sizeof v); }  // @9_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 804), sizeof v); (u32)v; });  // @10_484380
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(0));  // @11_484380
  ecx = edx = 0;  // @12_484380
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @13_484380
  if (FL[2] == 0) goto L4843f9;  // @14_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_484380
  ecx = edi;  // @16_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 800)))(ecx, (u32)(0));  // @17_484380
  ecx = edx = 0;  // @18_484380
  FL[2] = ((eax & 0xff) & (u32)(32));  // @19_484380
  if (FL[2] != 0) goto L4843f9;  // @20_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_484380
  ecx = edi;  // @22_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1600)))(ecx, (u32)(1));  // @23_484380
  ecx = edx = 0;  // @24_484380
  esi = eax;  // @25_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65660), &v, sizeof v); }  // @26_484380
  goto L484482;  // @27_484380
  L4843f9:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1113), sizeof v); (u32)v; });  // @29_484380
  FL[2] = (esi & esi);  // @30_484380
  if (FL[2] == 0) goto L484476;  // @31_484380
  ebx = (u32)(edi + 1117);  // @32_484380
  ebx = (u32)(ebx + esi*4);  // @33_484380
  L484410:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @35_484380
  FL[2] = (ecx & ecx);  // @36_484380
  if (FL[2] == 0) goto L484434;  // @37_484380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_484380
  eax = (u32)(edi + 1093);  // @39_484380
  PV[0] = (u32)(eax);  // @40_484380
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65640), sizeof v); (u32)v; });  // @41_484380
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65648), sizeof v); (u32)v; });  // @42_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @43_484380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(eax))(ecx, PV[2], PV[1], PV[0]);  // @44_484380
  ecx = edx = 0;  // @45_484380
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @46_484380
  if (FL[2] != 0) goto L48443e;  // @47_484380
  L484434:;
  ebx = (ebx - (u32)(4));  // @49_484380
  FL[3] = ebx;  // @50_484380
  esi = (esi - (u32)(1));  // @51_484380
  FL[3] = esi;  // @52_484380
  if (FL[3] != 0) goto L484410;  // @53_484380
  goto L484470;  // @54_484380
  L48443e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @56_484380
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + esi*4 + 1117), sizeof v); (u32)v; }); FL[1] = ecx;  // @57_484380
  if (FL[0] == FL[1]) goto L484470;  // @58_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @60_484380
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(0));  // @61_484380
  ecx = edx = 0;  // @62_484380
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @63_484380
  if (FL[2] == 0) goto L484470;  // @64_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_484380
  ecx = edi;  // @66_484380
  PV[3] = (u32)(esi);  // @67_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1604)))(ecx, PV[3]);  // @68_484380
  ecx = edx = 0;  // @69_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @70_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_484380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @72_484380
  ecx = edx = 0;  // @73_484380
  L484470:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65640), sizeof v); (u32)v; });  // @75_484380
  L484476:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1109), sizeof v); (u32)v; });  // @77_484380
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 65660), &v, sizeof v); }  // @78_484380
  L484482:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @80_484380
  edx = (u32)(EBP - 65540);  // @81_484380
  PV[4] = (u32)(edx);  // @82_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @83_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @84_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_484380
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 72)))(ecx, PV[4], (u32)(65536));  // @86_484380
  ecx = edx = 0;  // @87_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6818400) + 0), 4); v; });  // @88_484380
  X0[1] = 0;  // @89_484380
  X0[2] = 0;  // @90_484380
  X0[3] = 0;  // @91_484380
  ecx = edi;  // @92_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @93_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65644), &v, sizeof v); }  // @94_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_484380
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 84) + 0), 4); v; })));  // @96_484380
  __builtin_memcpy((void *)((u32)(EBP - 65652) + 0), &X0[0], 4);  // @97_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; });  // @98_484380
  X0[1] = 0;  // @99_484380
  X0[2] = 0;  // @100_484380
  X0[3] = 0;  // @101_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_484380
  __builtin_memcpy((void *)((u32)(EBP - 65656) + 0), &X0[0], 4);  // @103_484380
  X0[0] = 0;  // @104_484380
  X0[1] = 0;  // @105_484380
  X0[2] = 0;  // @106_484380
  X0[3] = 0;  // @107_484380
  __builtin_memcpy((void *)((u32)(EBP - 65640) + 0), &X0[0], 4);  // @108_484380
  __builtin_memcpy((void *)((u32)(EBP - 65672) + 0), &X0[0], 4);  // @109_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @111_484380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 1064)))(ecx);  // @112_484380
  ecx = edx = 0;  // @113_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @114_484380
  PV[5] = (u32)(eax);  // @115_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @116_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, PV[5]);  // @117_484380
  ecx = edx = 0;  // @118_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65676), &v, sizeof v); }  // @119_484380
  FL[2] = (eax & eax);  // @120_484380
  if (FL[2] == 0) goto L484587;  // @121_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @122_484380
  eax = ext_4dafb0_thiscall1(ecx);  // @123_484380
  ecx = edx = 0;  // @124_484380
  FL[2] = (eax & eax);  // @125_484380
  if (FL[2] == 0) goto L484587;  // @126_484380
  ecx = (u32)(EBP - 65564);  // @127_484380
  PV[6] = (u32)(ecx);  // @128_484380
  ecx = (u32)(EBP - 65600);  // @129_484380
  PV[7] = (u32)(ecx);  // @130_484380
  ecx = eax;  // @131_484380
  eax = ext_4db6c0_thiscall3(ecx, PV[7], PV[6]);  // @132_484380
  ecx = edx = 0;  // @133_484380
  edx = (u32)(edi + 1305);  // @134_484380
  ecx = ebx;  // @135_484380
  eax = ext_43e960_fastcall2(ecx, edx);  // @136_484380
  ecx = edx = 0;  // @137_484380
  edx = (u32)(edi + 1269);  // @138_484380
  ecx = ebx;  // @139_484380
  eax = ext_441a60_fastcall2(ecx, edx);  // @140_484380
  ecx = edx = 0;  // @141_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65648), sizeof v); (u32)v; });  // @142_484380
  edx = (u32)(edi + 1269);  // @143_484380
  eax = ext_4de4f0_fastcall2(ecx, edx);  // @144_484380
  ecx = edx = 0;  // @145_484380
  edx = (u32)(EBP - 65600);  // @146_484380
  ecx = ebx;  // @147_484380
  eax = ext_4419f0_fastcall2(ecx, edx);  // @148_484380
  ecx = edx = 0;  // @149_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65648), sizeof v); (u32)v; });  // @150_484380
  edx = (u32)(EBP - 65600);  // @151_484380
  eax = ext_4de480_fastcall2(ecx, edx);  // @152_484380
  ecx = edx = 0;  // @153_484380
  edx = (u32)(EBP - 65564);  // @154_484380
  ecx = ebx;  // @155_484380
  eax = ext_441940_fastcall2(ecx, edx);  // @156_484380
  ecx = edx = 0;  // @157_484380
  L484587:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65648), sizeof v); (u32)v; });  // @159_484380
  ecx = (u32)(EBP - 65636);  // @160_484380
  eax = ext_4de420_fastcall2(ecx, edx);  // @161_484380
    // @162_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx) + 0), 4); v; });  // @163_484380
  X0[1] = 0;  // @164_484380
  X0[2] = 0;  // @165_484380
  X0[3] = 0;  // @166_484380
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65652) + 0), 4); v; });  // @167_484380
  X3[1] = 0;  // @168_484380
  X3[2] = 0;  // @169_484380
  X3[3] = 0;  // @170_484380
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65656) + 0), 4); v; });  // @171_484380
  X1[1] = 0;  // @172_484380
  X1[2] = 0;  // @173_484380
  X1[3] = 0;  // @174_484380
  __builtin_memcpy((void *)((u32)(EBP - 65552) + 0), &X0[0], 4);  // @175_484380
  X2[0] = X1[0];  // @176_484380
  X2[1] = X1[1];  // @177_484380
  X2[2] = X1[2];  // @178_484380
  X2[3] = X1[3];  // @179_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 4) + 0), 4); v; });  // @180_484380
  X0[1] = 0;  // @181_484380
  X0[2] = 0;  // @182_484380
  X0[3] = 0;  // @183_484380
  __builtin_memcpy((void *)((u32)(EBP - 65548) + 0), &X0[0], 4);  // @184_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ebx + 8) + 0), 4); v; });  // @185_484380
  X0[1] = 0;  // @186_484380
  X0[2] = 0;  // @187_484380
  X0[3] = 0;  // @188_484380
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65644), sizeof v); (u32)v; });  // @189_484380
  __builtin_memcpy((void *)((u32)(EBP - 65544) + 0), &X0[0], 4);  // @190_484380
  X0[0] = X3[0];  // @191_484380
  X0[1] = X3[1];  // @192_484380
  X0[2] = X3[2];  // @193_484380
  X0[3] = X3[3];  // @194_484380
  X0[0] = F2U(U2F(X0[0]) * U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6791812) + 0), 4); v; })));  // @195_484380
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @196_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65640) + 0), 4); v; });  // @197_484380
  X0[1] = 0;  // @198_484380
  X0[2] = 0;  // @199_484380
  X0[3] = 0;  // @200_484380
  __builtin_memcpy((void *)((u32)(EBP - 65648) + 0), &X2[0], 4);  // @201_484380
  L484600:;
  X0[0] = F2U(U2F(X0[0]) + U2F(X3[0]));  // @203_484380
  FA = U2F(X0[0]); FB = U2F(X2[0]);  // @204_484380
  __builtin_memcpy((void *)((u32)(EBP - 65640) + 0), &X0[0], 4);  // @205_484380
  if (((!(FA >= FB)) || (!((FA < FB) || (FA > FB))))) goto L484619;  // @206_484380
  __builtin_memcpy((void *)((u32)(EBP - 65640) + 0), &X1[0], 4);  // @207_484380
  L484619:;
  eax = (u32)(EBP - 65552);  // @209_484380
  ecx = edi;  // @210_484380
  PV[8] = (u32)(eax);  // @211_484380
  PV[9] = (u32)(ebx);  // @212_484380
  eax = ext_484b10_thiscall6(ecx, PV[9], (u32)(0), PV[8], (u32)(0), (u32)(0));  // @213_484380
  ecx = edx = 0;  // @214_484380
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1425), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @215_484380
  if (FL[0] == FL[1]) goto L484714;  // @216_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @217_484380
  edx = (u32)(edi + 1317);  // @218_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65656) + 0), 4); v; });  // @219_484380
  X0[1] = 0;  // @220_484380
  X0[2] = 0;  // @221_484380
  X0[3] = 0;  // @222_484380
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65640) + 0), 4); v; });  // @223_484380
  X2[1] = 0;  // @224_484380
  X2[2] = 0;  // @225_484380
  X2[3] = 0;  // @226_484380
  PV[10] = (u32)(ecx);  // @227_484380
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @228_484380
  ecx = (u32)(EBP - 65600);  // @229_484380
  X2[0] = F2U(U2F(X2[0]) - U2F(X0[0]));  // @230_484380
  X2[0] = F2U(U2F(X2[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(eax + 72) + 0), 4); v; })));  // @231_484380
  eax = (u32)(edi + 1365);  // @232_484380
  PV[11] = X2[0];  // @233_484380
  PV[12] = (u32)(eax);  // @234_484380
  __builtin_memcpy((void *)((u32)(EBP - 65644) + 0), &X2[0], 4);  // @235_484380
  eax = ext_4de520_fastcall4(ecx, edx, PV[12], PV[11]);  // @236_484380
  ecx = edx = 0;  // @237_484380
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1353) + 0), 4); v; });  // @238_484380
  X1[1] = 0;  // @239_484380
  X1[2] = 0;  // @240_484380
  X1[3] = 0;  // @241_484380
  eax = (u32)(edi + 1413);  // @242_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1401) + 0), 4); v; });  // @243_484380
  X0[1] = 0;  // @244_484380
  X0[2] = 0;  // @245_484380
  X0[3] = 0;  // @246_484380
  ecx = ebx;  // @247_484380
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65644) + 0), 4); v; });  // @248_484380
  X2[1] = 0;  // @249_484380
  X2[2] = 0;  // @250_484380
  X2[3] = 0;  // @251_484380
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @252_484380
  PV[13] = (u32)(eax);  // @253_484380
  eax = (u32)(EBP - 65564);  // @254_484380
  PV[14] = (u32)(eax);  // @255_484380
  eax = (u32)(EBP - 65600);  // @256_484380
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @257_484380
  PV[15] = (u32)(eax);  // @258_484380
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @259_484380
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1357) + 0), 4); v; });  // @260_484380
  X1[1] = 0;  // @261_484380
  X1[2] = 0;  // @262_484380
  X1[3] = 0;  // @263_484380
  __builtin_memcpy((void *)((u32)(EBP - 65564) + 0), &X0[0], 4);  // @264_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1405) + 0), 4); v; });  // @265_484380
  X0[1] = 0;  // @266_484380
  X0[2] = 0;  // @267_484380
  X0[3] = 0;  // @268_484380
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @269_484380
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @270_484380
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @271_484380
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1361) + 0), 4); v; });  // @272_484380
  X1[1] = 0;  // @273_484380
  X1[2] = 0;  // @274_484380
  X1[3] = 0;  // @275_484380
  __builtin_memcpy((void *)((u32)(EBP - 65560) + 0), &X0[0], 4);  // @276_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(edi + 1409) + 0), 4); v; });  // @277_484380
  X0[1] = 0;  // @278_484380
  X0[2] = 0;  // @279_484380
  X0[3] = 0;  // @280_484380
  X0[0] = F2U(U2F(X0[0]) - U2F(X1[0]));  // @281_484380
  X0[0] = F2U(U2F(X0[0]) * U2F(X2[0]));  // @282_484380
  X0[0] = F2U(U2F(X0[0]) + U2F(X1[0]));  // @283_484380
  __builtin_memcpy((void *)((u32)(EBP - 65556) + 0), &X0[0], 4);  // @284_484380
  eax = ext_4eb080_thiscall4(ecx, PV[15], PV[14], PV[13]);  // @285_484380
  ecx = edx = 0;  // @286_484380
  L484714:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @288_484380
  X1[0] = 0;  // @289_484380
  X1[1] = 0;  // @290_484380
  X1[2] = 0;  // @291_484380
  X1[3] = 0;  // @292_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @293_484380
  X0[1] = 0;  // @294_484380
  X0[2] = 0;  // @295_484380
  X0[3] = 0;  // @296_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @297_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @298_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @299_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L48476e;  // @300_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @301_484380
  X0[1] = 0;  // @302_484380
  X0[2] = 0;  // @303_484380
  X0[3] = 0;  // @304_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @305_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @306_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @307_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L48476e;  // @308_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @309_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @310_484380
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @311_484380 edx:eax result (w3g)
  ecx = 0;  // @312_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @313_484380
  PV[16] = (u32)(edx);  // @314_484380
  PV[17] = (u32)(eax);  // @315_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @316_484380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[17], PV[16], (u32)(6864932));  // @317_484380
  ecx = edx = 0;  // @318_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @319_484380
  L48476e:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1535), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @321_484380
  if (FL[0] == FL[1]) goto L484786;  // @322_484380
  ecx = ebx;  // @323_484380
  eax = ext_4ea300_thiscall2(ecx, (u32)(32));  // @324_484380
  ecx = edx = 0;  // @325_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @326_484380
  L484786:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @328_484380
  X0[1] = 0;  // @329_484380
  X0[2] = 0;  // @330_484380
  X0[3] = 0;  // @331_484380
  X1[0] = 0;  // @332_484380
  X1[1] = 0;  // @333_484380
  X1[2] = 0;  // @334_484380
  X1[3] = 0;  // @335_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @336_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @337_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @338_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L4847d4;  // @339_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @340_484380
  X0[1] = 0;  // @341_484380
  X0[2] = 0;  // @342_484380
  X0[3] = 0;  // @343_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @344_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @345_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @346_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L4847d4;  // @347_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @348_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @349_484380
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @350_484380 edx:eax result (w3g)
  ecx = 0;  // @351_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @352_484380
  PV[18] = (u32)(edx);  // @353_484380
  PV[19] = (u32)(eax);  // @354_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @355_484380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[19], PV[18], (u32)(6864932));  // @356_484380
  ecx = edx = 0;  // @357_484380
  L4847d4:;
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65640) + 0), 4); v; });  // @359_484380
  X1[1] = 0;  // @360_484380
  X1[2] = 0;  // @361_484380
  X1[3] = 0;  // @362_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65660), sizeof v); (u32)v; });  // @363_484380
  X0[0] = X1[0];  // @364_484380
  X0[1] = X1[1];  // @365_484380
  X0[2] = X1[2];  // @366_484380
  X0[3] = X1[3];  // @367_484380
  X0[0] = F2U(U2F(X0[0]) - U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65672) + 0), 4); v; })));  // @368_484380
  PV[20] = X0[0];  // @369_484380
  __builtin_memcpy((void *)((u32)(EBP - 65644) + 0), &X0[0], 4);  // @370_484380
  PV[21] = X1[0];  // @371_484380
  eax = ext_4895c0_thiscall3(ecx, PV[21], PV[20]);  // @372_484380
    // @373_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65644) + 0), 4); v; });  // @374_484380
  X0[1] = 0;  // @375_484380
  X0[2] = 0;  // @376_484380
  X0[3] = 0;  // @377_484380
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65640) + 0), 4); v; });  // @378_484380
  X2[1] = 0;  // @379_484380
  X2[2] = 0;  // @380_484380
  X2[3] = 0;  // @381_484380
  ecx = ebx;  // @382_484380
  PV[22] = X0[0];  // @383_484380
  PV[23] = X2[0];  // @384_484380
  eax = ext_4ea8e0_thiscall3(ecx, PV[23], PV[22]);  // @385_484380
    // @386_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @387_484380
  X1[0] = 0;  // @388_484380
  X1[1] = 0;  // @389_484380
  X1[2] = 0;  // @390_484380
  X1[3] = 0;  // @391_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @392_484380
  X0[1] = 0;  // @393_484380
  X0[2] = 0;  // @394_484380
  X0[3] = 0;  // @395_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @396_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @397_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @398_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L484881;  // @399_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @400_484380
  X0[1] = 0;  // @401_484380
  X0[2] = 0;  // @402_484380
  X0[3] = 0;  // @403_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @404_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @405_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @406_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L484881;  // @407_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @408_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @409_484380
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(601)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @410_484380 edx:eax result (w3g)
  ecx = 0;  // @411_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @412_484380
  PV[24] = (u32)(edx);  // @413_484380
  PV[25] = (u32)(eax);  // @414_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @415_484380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 376)))(ecx, PV[25], PV[24], (u32)(6864944));  // @416_484380
  ecx = edx = 0;  // @417_484380
  L484881:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65660), sizeof v); (u32)v; });  // @419_484380
  edx = (u32)(edi + 1093);  // @420_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65664), sizeof v); (u32)v; });  // @421_484380
  PV[26] = (u32)(edx);  // @422_484380
  PV[27] = (u32)(esi);  // @423_484380
  PV[28] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65668), sizeof v); (u32)v; });  // @424_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @425_484380
  edx = (u32)(EBP - 65552);  // @426_484380
  PV[29] = (u32)(edx);  // @427_484380
  edx = (u32)(EBP - 65636);  // @428_484380
  PV[30] = (u32)(edx);  // @429_484380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, PV[30], PV[29], PV[28], PV[27], PV[26]);  // @430_484380
  ecx = edx = 0;  // @431_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @432_484380
  X1[0] = 0;  // @433_484380
  X1[1] = 0;  // @434_484380
  X1[2] = 0;  // @435_484380
  X1[3] = 0;  // @436_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2503) + 0), 4); v; });  // @437_484380
  X0[1] = 0;  // @438_484380
  X0[2] = 0;  // @439_484380
  X0[3] = 0;  // @440_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @441_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @442_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @443_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L484908;  // @444_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(ecx + 2499) + 0), 4); v; });  // @445_484380
  X0[1] = 0;  // @446_484380
  X0[2] = 0;  // @447_484380
  X0[3] = 0;  // @448_484380
  FA = U2F(X0[0]); FB = U2F(X1[0]);  // @449_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @450_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @451_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L484908;  // @452_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @453_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 456), sizeof v); (u32)v; });  // @454_484380
  { u64 r64_ = ((u64(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6793208), (u32)(608)); eax = (u32)r64_; edx = (u32)(r64_ >> 32); }  // @455_484380 edx:eax result (w3g)
  ecx = 0;  // @456_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @457_484380
  PV[31] = (u32)(edx);  // @458_484380
  PV[32] = (u32)(eax);  // @459_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @460_484380
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 380)))(ecx, PV[32], PV[31], (u32)(6864944));  // @461_484380
  ecx = edx = 0;  // @462_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65664), sizeof v); (u32)v; });  // @463_484380
  L484908:;
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65640) + 0), 4); v; });  // @465_484380
  X0[1] = 0;  // @466_484380
  X0[2] = 0;  // @467_484380
  X0[3] = 0;  // @468_484380
  FA = U2F(X0[0]); FB = U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65656) + 0), 4); v; }));  // @469_484380
  eax = (eax & 0xffff00ffu) | ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) << 8);  // @470_484380
  FL[2] = ((u32)(0x02 | (!(FA >= FB) ? 1 : 0) | (((FA != FA) || (FB != FB)) ? 4 : 0) | ((!((FA < FB) || (FA > FB))) ? 0x40 : 0)) & 68);  // @471_484380
  if (__builtin_parity(FL[2] & 0xff)) goto L484981;  // @472_484380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65668), sizeof v); (u32)v; });  // @473_484380
  ecx = (u32)(EBP - 65636);  // @474_484380
  eax = ext_4de420_fastcall2(ecx, edx);  // @475_484380
    // @476_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi) + 0), 4); v; });  // @477_484380
  X0[1] = 0;  // @478_484380
  X0[2] = 0;  // @479_484380
  X0[3] = 0;  // @480_484380
  X1[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65656) + 0), 4); v; });  // @481_484380
  X1[1] = 0;  // @482_484380
  X1[2] = 0;  // @483_484380
  X1[3] = 0;  // @484_484380
  X2[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65648) + 0), 4); v; });  // @485_484380
  X2[1] = 0;  // @486_484380
  X2[2] = 0;  // @487_484380
  X2[3] = 0;  // @488_484380
  X3[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65652) + 0), 4); v; });  // @489_484380
  X3[1] = 0;  // @490_484380
  X3[2] = 0;  // @491_484380
  X3[3] = 0;  // @492_484380
  __builtin_memcpy((void *)((u32)(EBP - 65552) + 0), &X0[0], 4);  // @493_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 4) + 0), 4); v; });  // @494_484380
  X0[1] = 0;  // @495_484380
  X0[2] = 0;  // @496_484380
  X0[3] = 0;  // @497_484380
  __builtin_memcpy((void *)((u32)(EBP - 65548) + 0), &X0[0], 4);  // @498_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(esi + 8) + 0), 4); v; });  // @499_484380
  X0[1] = 0;  // @500_484380
  X0[2] = 0;  // @501_484380
  X0[3] = 0;  // @502_484380
  __builtin_memcpy((void *)((u32)(EBP - 65544) + 0), &X0[0], 4);  // @503_484380
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 65640) + 0), 4); v; });  // @504_484380
  X0[1] = 0;  // @505_484380
  X0[2] = 0;  // @506_484380
  X0[3] = 0;  // @507_484380
  __builtin_memcpy((void *)((u32)(EBP - 65672) + 0), &X0[0], 4);  // @508_484380
  goto L484600;  // @509_484380
  L484981:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65676), sizeof v); (u32)v; });  // @511_484380
  eax = 0;  // @512_484380
  FL[3] = eax;  // @513_484380
  FL[2] = (ecx & ecx);  // @514_484380
  if (FL[2] == 0) goto L484990;  // @515_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @516_484380
  L484990:;
  PV[33] = (u32)(eax);  // @518_484380
  ecx = ebx;  // @519_484380
  eax = ext_4ea260_thiscall2(ecx, PV[33]);  // @520_484380
  ecx = edx = 0;  // @521_484380
  esi = eax;  // @522_484380
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 65644), &v, sizeof v); }  // @523_484380
  FL[2] = (esi & esi);  // @524_484380
  if (FL[2] == 0) goto L484a0d;  // @525_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65676), sizeof v); (u32)v; });  // @526_484380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 65652), &v, sizeof v); }  // @527_484380
  FL[2] = (eax & eax);  // @528_484380
  if (FL[2] == 0) goto L4849c6;  // @529_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @530_484380
  eax = ext_4dafb0_thiscall1(ecx);  // @531_484380
  ecx = edx = 0;  // @532_484380
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 65652), &v, sizeof v); }  // @533_484380
  L4849c6:;
  ecx = esi;  // @535_484380
  eax = ext_4dafb0_thiscall1(ecx);  // @536_484380
  ecx = edx = 0;  // @537_484380
  FL[2] = (eax & eax);  // @538_484380
  if (FL[2] == 0) goto L4849e9;  // @539_484380
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65652), sizeof v); (u32)v; });  // @540_484380
  if (FL[0] == FL[1]) goto L4849e9;  // @541_484380
  ecx = eax;  // @542_484380
  eax = ext_4db9a0_thiscall2(ecx, (u32)(1051583));  // @543_484380
  ecx = 0;  // @544_484380
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @545_484380
  if (FL[2] != 0) goto L484a0d;  // @546_484380
  L4849e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @548_484380
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65644), sizeof v); (u32)v; });  // @549_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @550_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @551_484380
  PV[34] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 84), sizeof v); (u32)v; });  // @552_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @553_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[34]);  // @554_484380
  ecx = edx = 0;  // @555_484380
  PV[35] = (u32)(eax);  // @556_484380
  ecx = edi;  // @557_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 1060)))(ecx, PV[35]);  // @558_484380
  ecx = edx = 0;  // @559_484380
  L484a0d:;
  ecx = ebx;  // @561_484380
  eax = ext_4ea8e0_thiscall3(ecx, (u32)(0), (u32)(0));  // @562_484380
    // @563_484380
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 65660), sizeof v); (u32)v; });  // @564_484380
  ecx = esi;  // @565_484380
  eax = ext_4895c0_thiscall3(ecx, (u32)(0), (u32)(0));  // @566_484380
    // @567_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @568_484380
  PV[36] = (u32)(ebx);  // @569_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @570_484380
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @571_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @572_484380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[36]);  // @573_484380
  ecx = edx = 0;  // @574_484380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @575_484380
  ecx = esi;  // @576_484380
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 24)))(ecx);  // @577_484380
  ecx = edx = 0;  // @578_484380
  ext_633654(G(u32, 0x6f5630));  // @579_484380
  return eax;  // @580_484380
}
PCREG(484380, lifted_484380);

