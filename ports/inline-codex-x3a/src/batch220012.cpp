// batch220012.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5b5420_thiscall1(u32) __asm__("ext_5b5420");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5b3c30(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[27];
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @0_5b3c30
  esi = ecx;  // @1_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 11285), sizeof v); (u32)v; });  // @2_5b3c30
  if ((eax & eax) == 0) goto L5b3c7f;  // @3_5b3c30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4156), sizeof v); (u32)v; }) == (u32)(0)) goto L5b3c7f;  // @4_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @6_5b3c30
  if ((ecx & ecx) == 0) goto L5b3c6f;  // @7_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_5b3c30
  STK[0] = (u32)(0);  // @9_5b3c30
  STK[1] = (u32)(6932112);  // @10_5b3c30
  STK[2] = (u32)(7268848);  // @11_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, STK[2], STK[1], STK[0]);  // @12_5b3c30
  ecx = edx = 0;  // @13_5b3c30
  L5b3c6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_5b3c30
  ecx = esi;  // @16_5b3c30
  STK[3] = (u32)(0);  // @17_5b3c30
  STK[4] = (u32)(16);  // @18_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 104)))(ecx, STK[4], STK[3]);  // @19_5b3c30
  ecx = edx = 0;  // @20_5b3c30
  return eax;  // @21_5b3c30
  L5b3c7f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @23_5b3c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 95), &v, sizeof v); }  // @24_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @26_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_5b3c30
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @28_5b3c30
  ecx = edx = 0;  // @29_5b3c30
  ecx = (u32)(EBP - 1);  // @30_5b3c30
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 1), &v, sizeof v); }  // @31_5b3c30
  STK[5] = ecx;  // @32_5b3c30
  STK[6] = (u32)(6859220);  // @33_5b3c30
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @34_5b3c30
  ecx = eax;  // @35_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 144)))(ecx, STK[6], STK[5]);  // @36_5b3c30
  ecx = edx = 0;  // @37_5b3c30
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 1), sizeof v); (u32)v; }) == (u32)(0)) goto L5b3d80;  // @38_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 95), sizeof v); (u32)v; });  // @39_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1668), sizeof v); (u32)v; });  // @40_5b3c30
  eax = (eax - (u32)(2));  // @41_5b3c30
  if (eax == 0) goto L5b3d54;  // @42_5b3c30
  eax = (eax - (u32)(1));  // @43_5b3c30
  if (eax == 0) goto L5b3d28;  // @44_5b3c30
  eax = (eax - (u32)(1));  // @45_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @47_5b3c30
  if (eax == 0) goto L5b3d04;  // @48_5b3c30
  if ((ecx & ecx) == 0) goto L5b3cfa;  // @49_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_5b3c30
  STK[7] = (u32)(0);  // @51_5b3c30
  STK[8] = (u32)(7020584);  // @52_5b3c30
  STK[9] = (u32)(7268852);  // @53_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, STK[9], STK[8], STK[7]);  // @54_5b3c30
  ecx = edx = 0;  // @55_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @56_5b3c30
  L5b3cfa:;
  STK[10] = (u32)(7020584);  // @58_5b3c30
  goto L5b3daa;  // @59_5b3c30
  L5b3d04:;
  if ((ecx & ecx) == 0) goto L5b3d1e;  // @61_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_5b3c30
  STK[11] = (u32)(0);  // @63_5b3c30
  STK[12] = (u32)(7020572);  // @64_5b3c30
  STK[13] = (u32)(7268864);  // @65_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, STK[13], STK[12], STK[11]);  // @66_5b3c30
  ecx = edx = 0;  // @67_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_5b3c30
  L5b3d1e:;
  STK[14] = (u32)(7020572);  // @70_5b3c30
  goto L5b3daa;  // @71_5b3c30
  L5b3d28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @74_5b3c30
  if ((ecx & ecx) == 0) goto L5b3d4d;  // @75_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_5b3c30
  STK[15] = (u32)(0);  // @77_5b3c30
  STK[16] = (u32)(7020560);  // @78_5b3c30
  STK[17] = (u32)(7268860);  // @79_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, STK[17], STK[16], STK[15]);  // @80_5b3c30
  ecx = edx = 0;  // @81_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_5b3c30
  L5b3d4d:;
  STK[18] = (u32)(7020560);  // @84_5b3c30
  goto L5b3daa;  // @85_5b3c30
  L5b3d54:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @87_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @88_5b3c30
  if ((ecx & ecx) == 0) goto L5b3d79;  // @89_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_5b3c30
  STK[19] = (u32)(0);  // @91_5b3c30
  STK[20] = (u32)(7020548);  // @92_5b3c30
  STK[21] = (u32)(7268856);  // @93_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, STK[21], STK[20], STK[19]);  // @94_5b3c30
  ecx = edx = 0;  // @95_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_5b3c30
  L5b3d79:;
  STK[22] = (u32)(7020548);  // @98_5b3c30
  goto L5b3daa;  // @99_5b3c30
  L5b3d80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_5b3c30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @102_5b3c30
  if ((ecx & ecx) == 0) goto L5b3da5;  // @103_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_5b3c30
  STK[23] = (u32)(0);  // @105_5b3c30
  STK[24] = (u32)(6932112);  // @106_5b3c30
  STK[25] = (u32)(7268848);  // @107_5b3c30
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, STK[25], STK[24], STK[23]);  // @108_5b3c30
  ecx = edx = 0;  // @109_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_5b3c30
  L5b3da5:;
  STK[26] = (u32)(6932112);  // @112_5b3c30
  L5b3daa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @114_5b3c30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @115_5b3c30
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, STK[26]);  // @116_5b3c30
  ecx = edx = 0;  // @117_5b3c30
  ecx = esi;  // @118_5b3c30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 87), &v, sizeof v); }  // @119_5b3c30
  eax = ext_5b5420_thiscall1(ecx);  // @120_5b3c30
  ecx = edx = 0;  // @121_5b3c30
  return eax;  // @122_5b3c30
}
PCREG(5b3c30, lifted_5b3c30);

