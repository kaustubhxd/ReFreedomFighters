// batch218034.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_57d500_thiscall3(u32, u32, u32) __asm__("ext_57d500");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_57cb40(u32 ecx_in) {
  SEH_ENTER(0x66b22b);  // @h_57cb40
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_57cb40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 108), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @2_57cb40
  if (FL[0] != FL[1]) goto L57ccfa;  // @3_57cb40
  edi = (u32)(ebx + 572);  // @4_57cb40
  FL[2] = (edi & edi);  // @5_57cb40
  if (FL[2] == 0) goto L57ccd9;  // @6_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @7_57cb40
  ecx = (u32)(EBP - 208);  // @8_57cb40
  PV[0] = (u32)(ecx);  // @9_57cb40
  ecx = edi;  // @10_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[0]);  // @11_57cb40
  ecx = edx = 0;  // @12_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @13_57cb40
  ecx = (u32)(EBP - 208);  // @14_57cb40
  PV[1] = (u32)(ecx);  // @15_57cb40
  ecx = edi;  // @16_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[1]);  // @17_57cb40
  ecx = edx = 0;  // @18_57cb40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @19_57cb40
  if (FL[0] == FL[1]) goto L57ccd9;  // @20_57cb40
  L57cbb6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @22_57cb40
  PV[2] = (u32)(eax);  // @23_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, PV[2]);  // @25_57cb40
  ecx = edx = 0;  // @26_57cb40
  esi = eax;  // @27_57cb40
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 223), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @28_57cb40
  if (FL[0] == FL[1]) goto L57ccbe;  // @29_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 188)))(ecx);  // @32_57cb40
  ecx = edx = 0;  // @33_57cb40
  ecx = (u32)(esi + 44);  // @34_57cb40
  PV[3] = (u32)(ecx);  // @35_57cb40
  ecx = eax;  // @36_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @37_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, PV[3]);  // @38_57cb40
  ecx = edx = 0;  // @39_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @40_57cb40
  ecx = (u32)(6990352);  // @41_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_57cb40
  L57cbf6:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @44_57cb40
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @45_57cb40
  if (FL[0] != FL[1]) goto L57cc16;  // @46_57cb40
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @47_57cb40
  if (FL[2] == 0) goto L57cc12;  // @48_57cb40
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @49_57cb40
  FL[0] = (edx & 0xff); FL[1] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @50_57cb40
  if (FL[0] != FL[1]) goto L57cc16;  // @51_57cb40
  ecx = (ecx + (u32)(2));  // @52_57cb40
  FL[3] = ecx;  // @53_57cb40
  eax = (eax + (u32)(2));  // @54_57cb40
  FL[3] = eax;  // @55_57cb40
  FL[2] = ((edx & 0xff) & (edx & 0xff));  // @56_57cb40
  if (FL[2] != 0) goto L57cbf6;  // @57_57cb40
  L57cc12:;
  eax = 0;  // @59_57cb40
  FL[3] = eax;  // @60_57cb40
  goto L57cc1b;  // @61_57cb40
  L57cc16:;
  eax = (0u - (u32)(FL[0] < FL[1]));  // @63_57cb40
  eax = (eax | (u32)(1));  // @64_57cb40
  FL[3] = eax;  // @65_57cb40
  L57cc1b:;
  FL[2] = (eax & eax);  // @67_57cb40
  if (FL[2] != 0) goto L57ccbe;  // @68_57cb40
  ecx = (u32)(EBP - 196);  // @69_57cb40
  eax = ext_4cbeb0_thiscall1(ecx);  // @70_57cb40
  ecx = edx = 0;  // @71_57cb40
  eax = (u32)(EBP - 196);  // @72_57cb40
  reg.state = (s32)((u32)(0));  // @73_57cb40
  PV[4] = (u32)(eax);  // @74_57cb40
  ecx = esi;  // @75_57cb40
  eax = ext_57d500_thiscall3(ecx, PV[4], (u32)(6991200));  // @76_57cb40
  ecx = edx = 0;  // @77_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 172), sizeof v); (u32)v; });  // @78_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 68), &v, sizeof v); }  // @80_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 188), sizeof v); (u32)v; });  // @81_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 52), &v, sizeof v); }  // @82_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 176), sizeof v); (u32)v; });  // @83_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 64), &v, sizeof v); }  // @84_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 192), sizeof v); (u32)v; });  // @85_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @86_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 180), sizeof v); (u32)v; });  // @87_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 60), &v, sizeof v); }  // @88_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 196), sizeof v); (u32)v; });  // @89_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @90_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 184), sizeof v); (u32)v; });  // @91_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 56), &v, sizeof v); }  // @92_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; });  // @93_57cb40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @94_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @96_57cb40
  ecx = edx = 0;  // @97_57cb40
  ecx = (u32)(EBP - 196);  // @98_57cb40
  PV[5] = (u32)(ecx);  // @99_57cb40
  ecx = eax;  // @100_57cb40
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @101_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 52)))(ecx, PV[5]);  // @102_57cb40
  ecx = edx = 0;  // @103_57cb40
  ecx = (u32)(EBP - 196);  // @104_57cb40
  reg.state = (s32)((u32)(4294967295));  // @105_57cb40
  eax = ext_4cbec0_thiscall1(ecx);  // @106_57cb40
  ecx = edx = 0;  // @107_57cb40
  L57ccbe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @109_57cb40
  ecx = (u32)(EBP - 208);  // @110_57cb40
  PV[6] = (u32)(ecx);  // @111_57cb40
  ecx = edi;  // @112_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, PV[6]);  // @113_57cb40
  ecx = edx = 0;  // @114_57cb40
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @115_57cb40
  if (FL[0] != FL[1]) goto L57cbb6;  // @116_57cb40
  L57ccd9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @118_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 116)))(ecx);  // @120_57cb40
  ecx = edx = 0;  // @121_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @122_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 112)))(ecx);  // @124_57cb40
  ecx = edx = 0;  // @125_57cb40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 796), sizeof v); (u32)v; });  // @126_57cb40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_57cb40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @128_57cb40
  ecx = edx = 0;  // @129_57cb40
  L57ccfa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @131_57cb40
  ecx = ebx;  // @132_57cb40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 208)))(ecx, (u32)(0));  // @133_57cb40
  ecx = edx = 0;  // @134_57cb40
  SEH_LEAVE();  // @135_57cb40
  ext_633654(G(u32, 0x6f5630));  // @136_57cb40
  return eax;  // @137_57cb40
}
PCREG(57cb40, lifted_57cb40);

