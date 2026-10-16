// batch220013.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_576a30_thiscall2(u32, u32) __asm__("ext_576a30");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_576330(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  u32 STK[11];
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_576330
  edi = ecx;  // @1_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_576330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_576330
  ecx = edx = 0;  // @5_576330
  ecx = (u32)(EBP - 4);  // @6_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_576330
  STK[0] = ecx;  // @8_576330
  STK[1] = (u32)(6983656);  // @9_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @10_576330
  ecx = eax;  // @11_576330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, STK[1], STK[0]);  // @12_576330
  ecx = edx = 0;  // @13_576330
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @14_576330
  ecx = (u32)(6975068);  // @15_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @16_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 533), &v, sizeof v); }  // @17_576330
  esi = (u32)(ebx + 72);  // @18_576330
  eax = esi;  // @19_576330
  L576380:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @21_576330
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L5763a0;  // @22_576330
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L57639c;  // @23_576330
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @24_576330
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L5763a0;  // @25_576330
  eax = (eax + (u32)(2));  // @26_576330
  ecx = (ecx + (u32)(2));  // @27_576330
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L576380;  // @28_576330
  L57639c:;
  eax = 0;  // @30_576330
  goto L5763a5;  // @31_576330
  L5763a0:;
  eax = 0;  // @33_576330
  eax = (eax | (u32)(1));  // @34_576330
  L5763a5:;
  if ((eax & eax) != 0) goto L5763bd;  // @36_576330
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4160), sizeof v); (u32)v; }) != (eax & 0xff)) goto L5763bd;  // @37_576330
  STK[2] = (u32)(6977432);  // @38_576330
  ecx = edi;  // @39_576330
  eax = ext_576a30_thiscall2(ecx, STK[2]);  // @40_576330
  ecx = edx = 0;  // @41_576330
  L5763bd:;
  eax = (u32)(6980952);  // @43_576330
  L5763c2:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @45_576330
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5763e2;  // @46_576330
  if (((ecx & 0xff) & (ecx & 0xff)) == 0) goto L5763de;  // @47_576330
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @48_576330
  if ((ecx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5763e2;  // @49_576330
  esi = (esi + (u32)(2));  // @50_576330
  eax = (eax + (u32)(2));  // @51_576330
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L5763c2;  // @52_576330
  L5763de:;
  eax = 0;  // @54_576330
  goto L5763e7;  // @55_576330
  L5763e2:;
  eax = 0;  // @57_576330
  eax = (eax | (u32)(1));  // @58_576330
  L5763e7:;
  if ((eax & eax) != 0) goto L5763f7;  // @60_576330
  STK[3] = (u32)(6981524);  // @61_576330
  ecx = edi;  // @62_576330
  eax = ext_576a30_thiscall2(ecx, STK[3]);  // @63_576330
  ecx = edx = 0;  // @64_576330
  L5763f7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_576330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @69_576330
  ecx = edx = 0;  // @70_576330
  ecx = (u32)(EBP - 4);  // @71_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @72_576330
  STK[4] = ecx;  // @73_576330
  STK[5] = (u32)(6985060);  // @74_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_576330
  ecx = eax;  // @76_576330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, STK[5], STK[4]);  // @77_576330
  ecx = edx = 0;  // @78_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_576330
  STK[6] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @80_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @81_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_576330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, STK[6]);  // @83_576330
  ecx = edx = 0;  // @84_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 553), &v, sizeof v); }  // @85_576330
  ecx = eax;  // @86_576330
  STK[7] = (u32)(1);  // @87_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @88_576330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 188)))(ecx, STK[7]);  // @89_576330
  ecx = edx = 0;  // @90_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @91_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @92_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_576330
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @94_576330
  ecx = edx = 0;  // @95_576330
  ecx = (u32)(EBP - 4);  // @96_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @97_576330
  STK[8] = ecx;  // @98_576330
  STK[9] = (u32)(6978112);  // @99_576330
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @100_576330
  ecx = eax;  // @101_576330
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, STK[9], STK[8]);  // @102_576330
  ecx = edx = 0;  // @103_576330
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @104_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @105_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 537), &v, sizeof v); }  // @106_576330
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 557), &v, sizeof v); }  // @107_576330
  if ((esi & esi) == 0) goto L5764ac;  // @108_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @109_576330
  STK[10] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @110_576330
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @111_576330
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_576330
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, STK[10]);  // @113_576330
  ecx = edx = 0;  // @114_576330
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 78499), &v, sizeof v); }  // @115_576330
  L5764ac:;
  return eax;  // @117_576330
}
PCREG(576330, lifted_576330);

