// batch234016.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" s32 VECTORCALL ext_633910(float f);
extern "C" u32 STDCALL ext_5618b0_stdcall2(u32, u32) __asm__("ext_5618b0");
extern "C" u32 THISCALL ext_563110_thiscall3(u32, u32, u32) __asm__("ext_563110");
extern "C" u32 THISCALL ext_563710_thiscall3(u32, u32, u32) __asm__("ext_563710");
extern "C" u32 THISCALL ext_563750_thiscall3(u32, u32, u32) __asm__("ext_563750");
extern "C" u32 THISCALL ext_570040_thiscall4(u32, u32, u32, u32) __asm__("ext_570040");
extern "C" u32 THISCALL ext_570310_thiscall1(u32) __asm__("ext_570310");
extern "C" u32 THISCALL ext_571720_thiscall4(u32, u32, u32, u32) __asm__("ext_571720");
extern "C" u32 THISCALL ext_59cb50_thiscall3(u32, u32, u32) __asm__("ext_59cb50");
extern "C" u32 THISCALL ext_5a83c0_thiscall2(u32, u32) __asm__("ext_5a83c0");
extern "C" u32 THISCALL ext_5b1000_thiscall2(u32, u32) __asm__("ext_5b1000");
extern "C" u32 THISCALL ext_5b1440_thiscall2(u32, u32) __asm__("ext_5b1440");
extern "C" void FASTCALL ext_633654(u32 cookie);
static inline float U2F(u32 v) { float f; __builtin_memcpy(&f, &v, 4); return f; }
static inline u32 F2U(float f) { u32 v; __builtin_memcpy(&v, &f, 4); return v; }
static inline double U2D(u32 lo, u32 hi) { u64 v = ((u64)hi << 32) | lo; double d; __builtin_memcpy(&d, &v, 8); return d; }
static inline void SD(u32 *x, double d) { u64 v; __builtin_memcpy(&v, &d, 8); x[0] = (u32)v; x[1] = (u32)(v >> 32); }

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_570f10(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[71], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  long double FA = 0, FB = 0;
  u32 X0[4] = {0,0,0,0}, X1[4] = {0,0,0,0}, X2[4] = {0,0,0,0}, X3[4] = {0,0,0,0}, X4[4] = {0,0,0,0}, X5[4] = {0,0,0,0}, X6[4] = {0,0,0,0}, X7[4] = {0,0,0,0};
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_570f10
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 568), &v, sizeof v); }  // @1_570f10
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 419), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_570f10
  if (FL[0] != FL[1]) goto L5712dd;  // @3_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 144), sizeof v); (u32)v; });  // @4_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2130), sizeof v); (u32)v; });  // @5_570f10
  FL[2] = (eax & eax);  // @6_570f10
  if (FL[2] == 0) goto L5712dd;  // @7_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 7439), sizeof v); (u32)v; });  // @8_570f10
  FL[2] = (ecx & ecx);  // @9_570f10
  if (FL[2] == 0) goto L5712dd;  // @10_570f10
  eax = (u32)(EBP - 548);  // @11_570f10
  PV[0] = (u32)(eax);  // @12_570f10
  eax = ext_5a83c0_thiscall2(ecx, PV[0]);  // @13_570f10
    // @14_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @16_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @17_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6981436), (u32)(6981436));  // @19_570f10
  ecx = edx = 0;  // @20_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @21_570f10
  ebx = eax;  // @22_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @23_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @24_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6974948), (u32)(6981444));  // @26_570f10
  ecx = edx = 0;  // @27_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @28_570f10
  edi = eax;  // @29_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @30_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @31_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6974948), (u32)(6975076));  // @33_570f10
  ecx = edx = 0;  // @34_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_570f10
  esi = eax;  // @36_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @37_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @38_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6981436), (u32)(6981452));  // @40_570f10
  ecx = edx = 0;  // @41_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @43_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @44_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @45_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6981436), (u32)(6981468));  // @47_570f10
  ecx = edx = 0;  // @48_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @49_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 576), &v, sizeof v); }  // @50_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @51_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @52_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6981436), (u32)(6981484));  // @54_570f10
  ecx = edx = 0;  // @55_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 580), &v, sizeof v); }  // @57_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @58_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @59_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6981436), (u32)(6981496));  // @61_570f10
  ecx = edx = 0;  // @62_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @63_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 572), &v, sizeof v); }  // @64_570f10
  eax = ext_570310_thiscall1(ecx);  // @65_570f10
  ecx = edx = 0;  // @66_570f10
  PV[1] = (u32)(esi);  // @67_570f10
  PV[2] = (u32)(edi);  // @68_570f10
  PV[3] = (u32)(ebx);  // @69_570f10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @70_570f10
  ecx = ebx;  // @71_570f10
  eax = ext_571720_thiscall4(ecx, PV[3], PV[2], PV[1]);  // @72_570f10
  ecx = edx = 0;  // @73_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 400)))(ecx);  // @76_570f10
  ecx = edx = 0;  // @77_570f10
  PV[4] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 548), sizeof v); (u32)v; });  // @78_570f10
  edx = (u32)(EBP - 516);  // @79_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @80_570f10
  PV[5] = (u32)(edx);  // @81_570f10
  PV[6] = (u32)(eax);  // @82_570f10
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[6], PV[5], (u32)(6784244), PV[4]);  // @83_570f10
  ecx = edx = 0;  // @84_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @87_570f10
  ecx = edx = 0;  // @88_570f10
  PV[7] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 544), sizeof v); (u32)v; });  // @89_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @90_570f10
  edx = (u32)(EBP - 260);  // @91_570f10
  PV[8] = (u32)(edx);  // @92_570f10
  PV[9] = (u32)(eax);  // @93_570f10
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[9], PV[8], (u32)(6784244), PV[7]);  // @94_570f10
  ecx = edx = 0;  // @95_570f10
  eax = (u32)(EBP - 260);  // @96_570f10
  ecx = ebx;  // @97_570f10
  PV[10] = (u32)(eax);  // @98_570f10
  eax = (u32)(EBP - 516);  // @99_570f10
  PV[11] = (u32)(eax);  // @100_570f10
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 564), sizeof v); (u32)v; });  // @101_570f10
  eax = ext_570040_thiscall4(ecx, PV[12], PV[11], PV[10]);  // @102_570f10
  ecx = edx = 0;  // @103_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @104_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @106_570f10
  ecx = edx = 0;  // @107_570f10
  PV[13] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 524), sizeof v); (u32)v; });  // @108_570f10
  edx = (u32)(EBP - 516);  // @109_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_570f10
  PV[14] = (u32)(edx);  // @111_570f10
  PV[15] = (u32)(eax);  // @112_570f10
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[15], PV[14], (u32)(6784244), PV[13]);  // @113_570f10
  ecx = edx = 0;  // @114_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @115_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @117_570f10
  ecx = edx = 0;  // @118_570f10
  PV[16] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 520), sizeof v); (u32)v; });  // @119_570f10
  edx = (u32)(EBP - 260);  // @120_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @121_570f10
  PV[17] = (u32)(edx);  // @122_570f10
  PV[18] = (u32)(eax);  // @123_570f10
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[18], PV[17], (u32)(6784244), PV[16]);  // @124_570f10
  ecx = edx = 0;  // @125_570f10
  eax = (u32)(EBP - 260);  // @126_570f10
  ecx = ebx;  // @127_570f10
  PV[19] = (u32)(eax);  // @128_570f10
  eax = (u32)(EBP - 516);  // @129_570f10
  PV[20] = (u32)(eax);  // @130_570f10
  PV[21] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 576), sizeof v); (u32)v; });  // @131_570f10
  eax = ext_570040_thiscall4(ecx, PV[21], PV[20], PV[19]);  // @132_570f10
  ecx = edx = 0;  // @133_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @134_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @136_570f10
  ecx = edx = 0;  // @137_570f10
  PV[22] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @138_570f10
  edx = (u32)(EBP - 516);  // @139_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @140_570f10
  PV[23] = (u32)(edx);  // @141_570f10
  PV[24] = (u32)(eax);  // @142_570f10
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[24], PV[23], (u32)(6784244), PV[22]);  // @143_570f10
  ecx = edx = 0;  // @144_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @145_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @147_570f10
  ecx = edx = 0;  // @148_570f10
  PV[25] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 528), sizeof v); (u32)v; });  // @149_570f10
  edx = (u32)(EBP - 260);  // @150_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @151_570f10
  PV[26] = (u32)(edx);  // @152_570f10
  PV[27] = (u32)(eax);  // @153_570f10
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 408)))(PV[27], PV[26], (u32)(6784244), PV[25]);  // @154_570f10
  ecx = edx = 0;  // @155_570f10
  eax = (u32)(EBP - 260);  // @156_570f10
  ecx = ebx;  // @157_570f10
  PV[28] = (u32)(eax);  // @158_570f10
  eax = (u32)(EBP - 516);  // @159_570f10
  PV[29] = (u32)(eax);  // @160_570f10
  PV[30] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 580), sizeof v); (u32)v; });  // @161_570f10
  eax = ext_570040_thiscall4(ecx, PV[30], PV[29], PV[28]);  // @162_570f10
  ecx = edx = 0;  // @163_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @164_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @166_570f10
  ecx = edx = 0;  // @167_570f10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 536) + 0), 4); v; });  // @168_570f10
  X0[1] = 0;  // @169_570f10
  X0[2] = 0;  // @170_570f10
  X0[3] = 0;  // @171_570f10
  esi = eax;  // @172_570f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_570f10
  eax = (u32)ext_633910(U2F(X0[0]));  // @174_570f10
  ecx = edx = 0;  // @175_570f10
  edx = 0;  // @176_570f10
  FL[3] = edx;  // @177_570f10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 536) + 0), 4); v; });  // @178_570f10
  X0[1] = 0;  // @179_570f10
  X0[2] = 0;  // @180_570f10
  X0[3] = 0;  // @181_570f10
  ecx = (u32)(60);  // @182_570f10
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @183_570f10
  { u32 d_ = (u32)(ecx); u32 q_, r_; __asm__ volatile("divl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = q_; edx = r_; }  // @184_570f10
  PV[31] = (u32)(edx);  // @185_570f10
  eax = (u32)ext_633910(U2F(X0[0]));  // @186_570f10
  ecx = edx = 0;  // @187_570f10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 536) + 0), 4); v; });  // @188_570f10
  X0[1] = 0;  // @189_570f10
  X0[2] = 0;  // @190_570f10
  X0[3] = 0;  // @191_570f10
  edx = 0;  // @192_570f10
  FL[3] = edx;  // @193_570f10
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6981628) + 0), 4); v; })));  // @194_570f10
  ecx = (u32)(60);  // @195_570f10
  { u32 d_ = (u32)(ecx); u32 q_, r_; __asm__ volatile("divl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = q_; edx = r_; }  // @196_570f10
  PV[32] = (u32)(edx);  // @197_570f10
  eax = (u32)ext_633910(U2F(X0[0]));  // @198_570f10
  ecx = edx = 0;  // @199_570f10
  PV[33] = (u32)(eax);  // @200_570f10
  eax = (u32)(EBP - 516);  // @201_570f10
  PV[34] = (u32)(eax);  // @202_570f10
  PV[35] = (u32)(esi);  // @203_570f10
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 408)))(PV[35], PV[34], (u32)(6981508), PV[33], PV[32], PV[31]);  // @204_570f10
  ecx = edx = 0;  // @205_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @206_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @207_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 400)))(ecx);  // @208_570f10
  ecx = edx = 0;  // @209_570f10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 536) + 0), 4); v; });  // @210_570f10
  X0[1] = 0;  // @211_570f10
  X0[2] = 0;  // @212_570f10
  X0[3] = 0;  // @213_570f10
  esi = eax;  // @214_570f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @215_570f10
  eax = (u32)ext_633910(U2F(X0[0]));  // @216_570f10
  ecx = edx = 0;  // @217_570f10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 536) + 0), 4); v; });  // @218_570f10
  X0[1] = 0;  // @219_570f10
  X0[2] = 0;  // @220_570f10
  X0[3] = 0;  // @221_570f10
  edx = 0;  // @222_570f10
  FL[3] = edx;  // @223_570f10
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6785116) + 0), 4); v; })));  // @224_570f10
  ecx = (u32)(60);  // @225_570f10
  { u32 d_ = (u32)(ecx); u32 q_, r_; __asm__ volatile("divl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = q_; edx = r_; }  // @226_570f10
  PV[36] = (u32)(edx);  // @227_570f10
  eax = (u32)ext_633910(U2F(X0[0]));  // @228_570f10
  ecx = edx = 0;  // @229_570f10
  X0[0] = ({ u32 v; __builtin_memcpy(&v, (void *)((u32)(EBP - 536) + 0), 4); v; });  // @230_570f10
  X0[1] = 0;  // @231_570f10
  X0[2] = 0;  // @232_570f10
  X0[3] = 0;  // @233_570f10
  edx = 0;  // @234_570f10
  FL[3] = edx;  // @235_570f10
  X0[0] = F2U(U2F(X0[0]) / U2F(({ u32 v; __builtin_memcpy(&v, (void *)((u32)(6981628) + 0), 4); v; })));  // @236_570f10
  ecx = (u32)(60);  // @237_570f10
  { u32 d_ = (u32)(ecx); u32 q_, r_; __asm__ volatile("divl %4" : "=a"(q_), "=d"(r_) : "a"(eax), "d"(edx), "r"(d_) : "cc"); eax = q_; edx = r_; }  // @238_570f10
  PV[37] = (u32)(edx);  // @239_570f10
  eax = (u32)ext_633910(U2F(X0[0]));  // @240_570f10
  ecx = edx = 0;  // @241_570f10
  PV[38] = (u32)(eax);  // @242_570f10
  eax = (u32)(EBP - 260);  // @243_570f10
  PV[39] = (u32)(eax);  // @244_570f10
  PV[40] = (u32)(esi);  // @245_570f10
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 408)))(PV[40], PV[39], (u32)(6981508), PV[38], PV[37], PV[36]);  // @246_570f10
  ecx = edx = 0;  // @247_570f10
  eax = (u32)(EBP - 260);  // @248_570f10
  ecx = ebx;  // @249_570f10
  PV[41] = (u32)(eax);  // @250_570f10
  eax = (u32)(EBP - 516);  // @251_570f10
  PV[42] = (u32)(eax);  // @252_570f10
  PV[43] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 572), sizeof v); (u32)v; });  // @253_570f10
  eax = ext_570040_thiscall4(ecx, PV[43], PV[42], PV[41]);  // @254_570f10
  ecx = edx = 0;  // @255_570f10
  L5712dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @257_570f10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @258_570f10
  if (FL[2] == 0) goto L571308;  // @259_570f10
  ecx = ebx;  // @260_570f10
  eax = ext_563750_thiscall3(ecx, (u32)(3), (u32)(0));  // @261_570f10
  ecx = edx = 0;  // @262_570f10
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 419), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @263_570f10
  if (FL[0] != FL[1]) goto L571305;  // @264_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @265_570f10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(eax + 78490), &v, sizeof v); }  // @266_570f10
  L571305:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @268_570f10
  L571308:;
  PV[44] = (u32)(eax);  // @270_570f10
  PV[45] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @271_570f10
  ecx = ebx;  // @272_570f10
  eax = ext_563110_thiscall3(ecx, PV[45], PV[44]);  // @273_570f10
  ecx = edx = 0;  // @274_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @275_570f10
  eax = (u32)(ecx + 72);  // @276_570f10
  ecx = (ecx + (u32)(1295));  // @277_570f10
  FL[3] = ecx;  // @278_570f10
  PV[46] = (u32)(eax);  // @279_570f10
  eax = ext_5b1440_thiscall2(ecx, PV[46]);  // @280_570f10
  ecx = edx = 0;  // @281_570f10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @282_570f10
  if (FL[2] == 0) goto L571335;  // @283_570f10
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 416), &v, sizeof v); }  // @284_570f10
  L571335:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @286_570f10
  ecx = (u32)(6981524);  // @287_570f10
  eax = (u32)(esi + 72);  // @288_570f10
  L571343:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @290_570f10
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @291_570f10
  if (FL[0] != FL[1]) goto L571363;  // @292_570f10
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @293_570f10
  if (FL[2] == 0) goto L57135f;  // @294_570f10
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @295_570f10
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @296_570f10
  if (FL[0] != FL[1]) goto L571363;  // @297_570f10
  eax = (eax + (u32)(2));  // @298_570f10
  FL[3] = eax;  // @299_570f10
  ecx = (ecx + (u32)(2));  // @300_570f10
  FL[3] = ecx;  // @301_570f10
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @302_570f10
  if (FL[2] != 0) goto L571343;  // @303_570f10
  L57135f:;
  eax = 0;  // @305_570f10
  FL[3] = eax;  // @306_570f10
  goto L571368;  // @307_570f10
  L571363:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @309_570f10
  eax = (eax | (u32)(1));  // @310_570f10
  FL[3] = eax;  // @311_570f10
  L571368:;
  FL[2] = (eax & eax);  // @313_570f10
  if (FL[2] != 0) goto L57137b;  // @314_570f10
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 418), sizeof v); (u32)v; }); FL[1] = (eax & 0xff);  // @315_570f10
  if (FL[0] != FL[1]) goto L57137b;  // @316_570f10
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx + 416), &v, sizeof v); }  // @317_570f10
  L57137b:;
  ecx = (u32)(esi + 1295);  // @319_570f10
  eax = ext_5b1000_thiscall2(ecx, (u32)(6977828));  // @320_570f10
  ecx = edx = 0;  // @321_570f10
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @322_570f10
  if (FL[2] != 0) goto L5713c9;  // @323_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @324_570f10
  ecx = (u32)(6977560);  // @325_570f10
  eax = (eax + (u32)(72));  // @326_570f10
  FL[3] = eax;  // @327_570f10
  L5713a0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @329_570f10
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @330_570f10
  if (FL[0] != FL[1]) goto L5713c0;  // @331_570f10
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @332_570f10
  if (FL[2] == 0) goto L5713bc;  // @333_570f10
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @334_570f10
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @335_570f10
  if (FL[0] != FL[1]) goto L5713c0;  // @336_570f10
  eax = (eax + (u32)(2));  // @337_570f10
  FL[3] = eax;  // @338_570f10
  ecx = (ecx + (u32)(2));  // @339_570f10
  FL[3] = ecx;  // @340_570f10
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @341_570f10
  if (FL[2] != 0) goto L5713a0;  // @342_570f10
  L5713bc:;
  eax = 0;  // @344_570f10
  FL[3] = eax;  // @345_570f10
  goto L5713c5;  // @346_570f10
  L5713c0:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @348_570f10
  eax = (eax | (u32)(1));  // @349_570f10
  FL[3] = eax;  // @350_570f10
  L5713c5:;
  FL[2] = (eax & eax);  // @352_570f10
  if (FL[2] != 0) goto L57143e;  // @353_570f10
  L5713c9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @355_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @356_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @357_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @358_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6974004), (u32)(6978648));  // @359_570f10
  ecx = edx = 0;  // @360_570f10
  PV[47] = (u32)(eax);  // @361_570f10
  PV[48] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 388), sizeof v); (u32)v; });  // @362_570f10
  ecx = ebx;  // @363_570f10
  eax = ext_563710_thiscall3(ecx, PV[48], PV[47]);  // @364_570f10
  ecx = edx = 0;  // @365_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @366_570f10
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 416), &v, sizeof v); }  // @367_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @368_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6973260), (u32)(0));  // @369_570f10
  ecx = edx = 0;  // @370_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @371_570f10
  esi = eax;  // @372_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @373_570f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @374_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @375_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @376_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6975424), (u32)(6981532));  // @377_570f10
  ecx = edx = 0;  // @378_570f10
  PV[49] = (u32)(eax);  // @379_570f10
  ecx = esi;  // @380_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 644)))(ecx, PV[49]);  // @381_570f10
  ecx = edx = 0;  // @382_570f10
  L57143e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 388), sizeof v); (u32)v; });  // @384_570f10
  esi = (u32)(1);  // @385_570f10
  X0[0] = 0;  // @386_570f10
  X0[1] = 0;  // @387_570f10
  X0[2] = 0;  // @388_570f10
  X0[3] = 0;  // @389_570f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 520), &v, sizeof v); }  // @390_570f10
  PV[50] = (u32)(esi);  // @391_570f10
  __builtin_memcpy((void *)((u32)(EBP - 536) + 0), &X0[0], 4);  // @392_570f10
  __builtin_memcpy((void *)((u32)(EBP - 536) + 4), &X0[1], 4);  // @393_570f10
  __builtin_memcpy((void *)((u32)(EBP - 536) + 8), &X0[2], 4);  // @394_570f10
  __builtin_memcpy((void *)((u32)(EBP - 536) + 12), &X0[3], 4);  // @395_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @396_570f10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @397_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, PV[50]);  // @398_570f10
  ecx = edx = 0;  // @399_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @400_570f10
  PV[51] = (u32)(esi);  // @401_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @402_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, PV[51]);  // @403_570f10
  ecx = edx = 0;  // @404_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 396), sizeof v); (u32)v; });  // @405_570f10
  PV[52] = (u32)(esi);  // @406_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @407_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, PV[52]);  // @408_570f10
  ecx = edx = 0;  // @409_570f10
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 418), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @410_570f10
  if (FL[0] == FL[1]) goto L5714aa;  // @411_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 388), sizeof v); (u32)v; });  // @412_570f10
  esi = (u32)(2);  // @413_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @414_570f10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @415_570f10
  L5714aa:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 417), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @417_570f10
  if (FL[0] == FL[1]) goto L5714c7;  // @418_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 392), sizeof v); (u32)v; });  // @419_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + esi*4 - 536), &v, sizeof v); }  // @420_570f10
  esi = (esi + 1);  // @421_570f10
  FL[3] = esi;  // @422_570f10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @423_570f10
  L5714c7:;
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 416), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @425_570f10
  if (FL[0] == FL[1]) goto L5714e4;  // @426_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 396), sizeof v); (u32)v; });  // @427_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + esi*4 - 536), &v, sizeof v); }  // @428_570f10
  esi = (esi + 1);  // @429_570f10
  FL[3] = esi;  // @430_570f10
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 564), &v, sizeof v); }  // @431_570f10
  L5714e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @433_570f10
  edi = (u32)(1);  // @434_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + esi*4 - 536), &v, sizeof v); }  // @435_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 540), sizeof v); (u32)v; });  // @436_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @437_570f10
  FL[0] = esi; FL[1] = edi;  // @438_570f10
  if (FL[0] <= FL[1]) goto L57155a;  // @439_570f10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 564), sizeof v); (u32)v; });  // @440_570f10
  L571510:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi*4 - 536), sizeof v); (u32)v; });  // @442_570f10
  ecx = esi;  // @443_570f10
  PV[53] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi*4 - 532), sizeof v); (u32)v; });  // @444_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @445_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[53], (u32)(2));  // @446_570f10
  ecx = edx = 0;  // @447_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @448_570f10
  ecx = esi;  // @449_570f10
  PV[54] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edi*4 - 540), sizeof v); (u32)v; });  // @450_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[54], (u32)(1));  // @451_570f10
  ecx = edx = 0;  // @452_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @453_570f10
  ecx = esi;  // @454_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 188)))(ecx, (u32)(0));  // @455_570f10
  ecx = edx = 0;  // @456_570f10
  edi = (edi + 1);  // @457_570f10
  FL[3] = edi;  // @458_570f10
  FL[0] = edi; FL[1] = ebx;  // @459_570f10
  if (FL[0] < FL[1]) goto L571510;  // @460_570f10
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 568), sizeof v); (u32)v; });  // @461_570f10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 564), sizeof v); (u32)v; });  // @462_570f10
  L57155a:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @464_570f10
  ecx = (u32)(EBP - 560);  // @465_570f10
  PV[55] = (u32)(ecx);  // @466_570f10
  ecx = edi;  // @467_570f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 560), &v, sizeof v); }  // @468_570f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 556), &v, sizeof v); }  // @469_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @470_570f10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 552), &v, sizeof v); }  // @471_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, PV[55]);  // @472_570f10
  ecx = edx = 0;  // @473_570f10
  eax = (u32)(esi - 1);  // @474_570f10
  esi = (u32)(1);  // @475_570f10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 572), &v, sizeof v); }  // @476_570f10
  FL[0] = eax; FL[1] = esi;  // @477_570f10
  if (FL[0] <= FL[1]) goto L5715c0;  // @478_570f10
  edi = eax;  // @479_570f10
  L5715a0:;
  PV[56] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 532), sizeof v); (u32)v; });  // @481_570f10
  ecx = ebx;  // @482_570f10
  PV[57] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + esi*4 - 536), sizeof v); (u32)v; });  // @483_570f10
  eax = ext_5618b0_stdcall2(PV[57], PV[56]);  // @484_570f10
  ecx = edx = 0;  // @485_570f10
  esi = (esi + 1);  // @486_570f10
  FL[3] = esi;  // @487_570f10
  FL[0] = esi; FL[1] = edi;  // @488_570f10
  if (FL[0] < FL[1]) goto L5715a0;  // @489_570f10
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @490_570f10
  L5715c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @492_570f10
  ecx = ebx;  // @493_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @494_570f10
  ecx = edx = 0;  // @495_570f10
  PV[58] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @496_570f10
  ecx = eax;  // @497_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @498_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, PV[58]);  // @499_570f10
  ecx = edx = 0;  // @500_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @501_570f10
  ecx = ebx;  // @502_570f10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 132)))(ecx);  // @503_570f10
  ecx = edx = 0;  // @504_570f10
  PV[59] = (u32)(edi);  // @505_570f10
  ecx = eax;  // @506_570f10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @507_570f10
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 748)))(ecx, PV[59]);  // @508_570f10
  ecx = edx = 0;  // @509_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @510_570f10
  FL[2] = (ecx & ecx);  // @511_570f10
  if (FL[2] == 0) goto L57162a;  // @512_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @513_570f10
  PV[60] = (u32)(edi);  // @514_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[60], (u32)(3));  // @515_570f10
  ecx = edx = 0;  // @516_570f10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @517_570f10
  PV[61] = (u32)(edi);  // @518_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @519_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[61], (u32)(4));  // @520_570f10
  ecx = edx = 0;  // @521_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @522_570f10
  ecx = edi;  // @523_570f10
  PV[62] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @524_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[62], (u32)(3));  // @525_570f10
  ecx = edx = 0;  // @526_570f10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @527_570f10
  ecx = edi;  // @528_570f10
  PV[63] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; });  // @529_570f10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 796)))(ecx, PV[63], (u32)(4));  // @530_570f10
  ecx = edx = 0;  // @531_570f10
  L57162a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 148), sizeof v); (u32)v; });  // @533_570f10
  ecx = (u32)(6977432);  // @534_570f10
  eax = (u32)(esi + 72);  // @535_570f10
  L571638:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @537_570f10
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @538_570f10
  if (FL[0] != FL[1]) goto L571658;  // @539_570f10
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @540_570f10
  if (FL[2] == 0) goto L571654;  // @541_570f10
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @542_570f10
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; });  // @543_570f10
  if (FL[0] != FL[1]) goto L571658;  // @544_570f10
  eax = (eax + (u32)(2));  // @545_570f10
  FL[3] = eax;  // @546_570f10
  ecx = (ecx + (u32)(2));  // @547_570f10
  FL[3] = ecx;  // @548_570f10
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @549_570f10
  if (FL[2] != 0) goto L571638;  // @550_570f10
  L571654:;
  eax = 0;  // @552_570f10
  FL[3] = eax;  // @553_570f10
  goto L57165d;  // @554_570f10
  L571658:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @556_570f10
  eax = (eax | (u32)(1));  // @557_570f10
  FL[3] = eax;  // @558_570f10
  L57165d:;
  FL[2] = (eax & eax);  // @560_570f10
  if (FL[2] != 0) goto L57166f;  // @561_570f10
  ecx = esi;  // @562_570f10
  eax = ext_59cb50_thiscall3(ecx, (u32)(6981548), (u32)(1));  // @563_570f10
  ecx = 0;  // @564_570f10
  L57166f:;
  ext_633654(G(u32, 0x6f5630));  // @566_570f10
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @567_570f10
  return eax;  // @568_570f10
}
PCREG(570f10, lifted_570f10);

