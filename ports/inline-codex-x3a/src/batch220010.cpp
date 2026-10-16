// batch220010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_64c7e0_thiscall2(u32, u32) __asm__("ext_64c7e0");
extern "C" u32 THISCALL ext_64d5f0_thiscall2(u32, u32) __asm__("ext_64d5f0");
extern "C" u32 ext_634d22_cdecl3(...) __asm__("ext_634d22");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_63d2f0(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[8];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63d2f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @1_63d2f0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 90), sizeof v); (u32)v; });  // @2_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_63d2f0
  if ((eax & eax) == 0) goto L63d491;  // @4_63d2f0
  esi = eax;  // @5_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 104), sizeof v); (u32)v; });  // @6_63d2f0
  esi = (esi & (u32)(4095));  // @7_63d2f0
  esi = (esi << (u32)(2));  // @8_63d2f0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @9_63d2f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; });  // @10_63d2f0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @11_63d2f0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 61), sizeof v); (u32)v; })) & 0xff);  // @12_63d2f0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 11), &v, sizeof v); }  // @13_63d2f0
  if ((eax & 0xff) <= (u32)(1)) goto L63d48f;  // @14_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_63d2f0
  edx = 0;  // @16_63d2f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @17_63d2f0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @18_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @19_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @20_63d2f0
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @21_63d2f0
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; });  // @22_63d2f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @23_63d2f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @24_63d2f0
  if ((eax & eax) == 0) goto L63d373;  // @25_63d2f0
  L63d360:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == ecx) goto L63d36d;  // @27_63d2f0
  edx = (edx + 1);  // @28_63d2f0
  ebx = (ebx + (u32)(8));  // @29_63d2f0
  if (edx != eax) goto L63d360;  // @30_63d2f0
  L63d36d:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @32_63d2f0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @33_63d2f0
  L63d373:;
  if (edx == eax) goto L63d48e;  // @35_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @36_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 236), sizeof v); (u32)v; }) == (u32)(0)) goto L63d427;  // @37_63d2f0
  eax = (eax + (u32)(240));  // @38_63d2f0
  ebx = 0;  // @39_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @40_63d2f0
  L63d395:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_63d2f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @43_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 65649), sizeof v); (u32)v; });  // @44_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + eax), sizeof v); (u32)v; }) == (u32)(0)) goto L63d405;  // @45_63d2f0
  STK[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @46_63d2f0
  eax = ext_64c7e0_thiscall2(ecx, STK[0]);  // @47_63d2f0
  ecx = edx = 0;  // @48_63d2f0
  edi = (u32)(eax + 28);  // @49_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L63d405;  // @50_63d2f0
  L63d3b7:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @53_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; });  // @54_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @55_63d2f0
  if (ecx == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; })) goto L63d3d2;  // @56_63d2f0
  edi = (u32)(esi + 28);  // @57_63d2f0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L63d3b7;  // @58_63d2f0
  goto L63d402;  // @59_63d2f0
  L63d3d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @61_63d2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @62_63d2f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @63_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 65625), sizeof v); (u32)v; });  // @64_63d2f0
  eax = (~eax);  // @65_63d2f0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; }) & eax)); __builtin_memcpy((void *)(u32)(edx + 20), &v, sizeof v); }  // @66_63d2f0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L63d3f6;  // @67_63d2f0
  STK[1] = esi;  // @68_63d2f0
  eax = ext_64d5f0_thiscall2(ecx, STK[1]);  // @69_63d2f0
  ecx = edx = 0;  // @70_63d2f0
  L63d3f6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @72_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @73_63d2f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @74_63d2f0
  L63d402:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @76_63d2f0
  L63d405:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @78_63d2f0
  ebx = (ebx + 1);  // @79_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @80_63d2f0
  eax = (eax + (u32)(4));  // @81_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @82_63d2f0
  if (ebx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 236), sizeof v); (u32)v; })) goto L63d395;  // @83_63d2f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @84_63d2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @85_63d2f0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @86_63d2f0
  L63d427:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @88_63d2f0
  if ((eax & eax) == 0) goto L63d434;  // @89_63d2f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @90_63d2f0
  L63d434:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 64), sizeof v); (u32)v; });  // @92_63d2f0
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 61), sizeof v); (u32)v; });  // @93_63d2f0
  ecx = (u32)(eax + ecx*8);  // @94_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 4), sizeof v); (u32)v; });  // @95_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @96_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx - 8), sizeof v); (u32)v; });  // @97_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @98_63d2f0
  if ((eax & eax) == 0) goto L63d450;  // @99_63d2f0
  { u8 v = (u8)((edx & 0xff)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @100_63d2f0
  L63d450:;
  edi = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 61), sizeof v); (u32)v; });  // @102_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @103_63d2f0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @104_63d2f0
  ecx = ebx;  // @105_63d2f0
  edi = (edi << (u32)(3));  // @106_63d2f0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @107_63d2f0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @108_63d2f0
  eax = (u32)(edi - 8);  // @109_63d2f0
  STK[2] = eax;  // @110_63d2f0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, STK[2]);  // @111_63d2f0
  ecx = edx = 0;  // @112_63d2f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @113_63d2f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 64), &v, sizeof v); }  // @114_63d2f0
  ecx = (u32)(edi - 8);  // @115_63d2f0
  STK[3] = ecx;  // @116_63d2f0
  STK[4] = esi;  // @117_63d2f0
  STK[5] = eax;  // @118_63d2f0
  eax = ext_634d22_cdecl3(STK[5], STK[4], STK[3]);  // @119_63d2f0
  ecx = edx = 0;  // @120_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @121_63d2f0
  ecx = ebx;  // @122_63d2f0
  STK[6] = edi;  // @123_63d2f0
  STK[7] = esi;  // @124_63d2f0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, STK[7], STK[6]);  // @125_63d2f0
  ecx = edx = 0;  // @126_63d2f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @127_63d2f0
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 61), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(eax + 61), &v, sizeof v); }  // @128_63d2f0
  L63d48e:;
  L63d48f:;
  L63d491:;
  return eax;  // @132_63d2f0
}
PCREG(63d2f0, lifted_63d2f0);

