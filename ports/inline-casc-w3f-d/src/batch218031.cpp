// batch218031.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_482800_thiscall2(u32, u32) __asm__("ext_482800");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12e0_thiscall3(u32, u32, u32) __asm__("ext_4e12e0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_59d330_thiscall3(u32, u32, u32) __asm__("ext_59d330");
extern "C" u32 THISCALL ext_59d430_thiscall2(u32, u32) __asm__("ext_59d430");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_590620(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b7bf);  // @h_590620
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0; u32 JL = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_590620
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_590620
  PV[0] = (u32)(esi);  // @2_590620
  eax = ext_482800_thiscall2(ecx, PV[0]);  // @3_590620
  ecx = edx = 0;  // @4_590620
  eax = (u32)(EBP - 20);  // @5_590620
  ecx = esi;  // @6_590620
  PV[1] = (u32)(eax);  // @7_590620
  eax = ext_4e12e0_thiscall3(ecx, PV[1], (u32)(1));  // @8_590620
  ecx = edx = 0;  // @9_590620
  ecx = esi;  // @10_590620
  eax = ext_4e1600_thiscall1(ecx);  // @11_590620
  ecx = edx = 0;  // @12_590620
  FL[0] = (eax & 0xff); FL[1] = (u32)(3);  // @13_590620
  if (FL[0] != FL[1]) goto L5907b4;  // @14_590620
  ebx = (u32)(edi + 1668);  // @15_590620
  ecx = esi;  // @16_590620
  PV[2] = (u32)(ebx);  // @17_590620
  eax = ext_4e11e0_thiscall3(ecx, PV[2], (u32)(1));  // @18_590620
  ecx = edx = 0;  // @19_590620
  eax = ext_41e290_cdecl1((u32)(24));  // @20_590620
  ecx = edx = 0;  // @21_590620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @22_590620
  reg.state = (s32)((u32)(0));  // @23_590620
  FL[2] = (eax & eax);  // @24_590620
  if (FL[2] == 0) goto L5906a3;  // @25_590620
  PV[3] = (u32)(edi);  // @26_590620
  ecx = eax;  // @27_590620
  eax = ext_59d330_thiscall3(ecx, PV[3], (u32)(0));  // @28_590620
  ecx = edx = 0;  // @29_590620
  goto L5906a5;  // @30_590620
  L5906a3:;
  eax = 0;  // @32_590620
  FL[3] = eax;  // @33_590620
  L5906a5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 84), &v, sizeof v); }  // @35_590620
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @36_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @37_590620
  reg.state = (s32)((u32)(4294967295));  // @38_590620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @39_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_590620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @41_590620
  ecx = edx = 0;  // @42_590620
  ecx = (u32)(EBP + 11);  // @43_590620
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @44_590620
  PV[4] = (u32)(ecx);  // @45_590620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @46_590620
  ecx = eax;  // @47_590620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, (u32)(6859220), PV[4]);  // @48_590620
  ecx = edx = 0;  // @49_590620
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @50_590620
  if (FL[0] == FL[1]) goto L5907ae;  // @51_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_590620
  eax = (eax - (u32)(2));  // @53_590620
  FL[3] = eax;  // @54_590620
  if (FL[3] == 0) goto L59075f;  // @55_590620
  eax = (eax - (u32)(1));  // @56_590620
  FL[3] = eax;  // @57_590620
  if (FL[3] == 0) goto L590741;  // @58_590620
  eax = (eax - (u32)(1));  // @59_590620
  FL[3] = eax;  // @60_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @61_590620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @62_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_590620
  if (FL[3] == 0) goto L590730;  // @64_590620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @65_590620
  ecx = edx = 0;  // @66_590620
  ecx = (u32)(EBP + 8);  // @67_590620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @68_590620
  PV[5] = (u32)(ecx);  // @69_590620
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @70_590620
  ecx = eax;  // @71_590620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6978836), PV[5]);  // @72_590620
  ecx = edx = 0;  // @73_590620
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @74_590620
  goto L59078c;  // @75_590620
  L590730:;
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @77_590620
  ecx = edx = 0;  // @78_590620
  ecx = (u32)(EBP + 8);  // @79_590620
  PV[6] = (u32)(ecx);  // @80_590620
  JL = 6979100; goto L59077b;  // @81_590620
  L590741:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_590620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @84_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_590620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @86_590620
  ecx = edx = 0;  // @87_590620
  ecx = (u32)(EBP + 8);  // @88_590620
  PV[7] = (u32)(ecx);  // @89_590620
  JL = 6979012; goto L59077b;  // @90_590620
  L59075f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_590620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @93_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_590620
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx); JL = 6978924;  // @95_590620
  ecx = edx = 0;  // @96_590620
  ecx = (u32)(EBP + 8);  // @97_590620
  PV[8] = (u32)(ecx);  // @98_590620
  L59077b:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @100_590620
  ecx = eax;  // @101_590620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @102_590620
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, JL, (u32)(EBP + 8));  // @103_590620
  ecx = edx = 0;  // @104_590620
  L59078c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @106_590620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @107_590620
  PV[9] = (u32)(eax);  // @108_590620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @109_590620
  eax = ext_59d430_thiscall2(ecx, PV[9]);  // @110_590620
  ecx = edx = 0;  // @111_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @112_590620
  ecx = (u32)(128);  // @113_590620
  ecx = (ecx | (1u << (eax & 31)));  // @114_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @115_590620
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @116_590620
  goto L5907b4;  // @117_590620
  L5907ae:;
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @119_590620
  L5907b4:;
  ecx = esi;  // @121_590620
  eax = ext_4e1600_thiscall1(ecx);  // @122_590620
  ecx = edx = 0;  // @123_590620
  FL[0] = (eax & 0xff); FL[1] = (u32)(8);  // @124_590620
  if (FL[0] != FL[1]) goto L5907cf;  // @125_590620
  eax = (u32)(edi + 2118);  // @126_590620
  ecx = esi;  // @127_590620
  PV[10] = (u32)(eax);  // @128_590620
  eax = ext_4e12e0_thiscall3(ecx, PV[10], (u32)(1));  // @129_590620
  ecx = edx = 0;  // @130_590620
  L5907cf:;
  ecx = esi;  // @132_590620
  eax = ext_4e1600_thiscall1(ecx);  // @133_590620
  ecx = edx = 0;  // @134_590620
  FL[0] = (eax & 0xff); FL[1] = (u32)(8);  // @135_590620
  if (FL[0] != FL[1]) goto L590800;  // @136_590620
  eax = (u32)(EBP - 16);  // @137_590620
  ecx = esi;  // @138_590620
  PV[11] = (u32)(eax);  // @139_590620
  eax = ext_4e12e0_thiscall3(ecx, PV[11], (u32)(1));  // @140_590620
  ecx = edx = 0;  // @141_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @142_590620
  PV[12] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @143_590620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @144_590620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_590620
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[12]);  // @146_590620
  ecx = edx = 0;  // @147_590620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 2126), &v, sizeof v); }  // @148_590620
  L590800:;
  ecx = esi;  // @150_590620
  eax = ext_4e1b30_thiscall1(ecx);  // @151_590620
  ecx = edx = 0;  // @152_590620
  SEH_LEAVE();  // @153_590620
  return eax;  // @154_590620
}
PCREG(590620, lifted_590620);

