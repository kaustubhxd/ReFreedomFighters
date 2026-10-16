// batch228010.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6166c0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e658);  // @h_6166c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64];
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @0_6166c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_6166c0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_6166c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @3_6166c0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @4_6166c0
  { u32 v = (u32)((u32)(7069160)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @5_6166c0
  eax = (u32)(ecx + 12);  // @6_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @7_6166c0
  edi = (u32)(ecx + 36);  // @8_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @9_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @10_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @11_6166c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @12_6166c0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47536), sizeof v); (u32)v; });  // @13_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47524), sizeof v); (u32)v; });  // @14_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_6166c0
  reg.state = (s32)((u32)(0));  // @17_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @18_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @19_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @20_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @21_6166c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @23_6166c0
  eax = (eax + ecx);  // @24_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @25_6166c0
  PV[1] = (u32)(eax);  // @26_6166c0
  eax = ext_659220_thiscall3(ecx, PV[1], PV[0]);  // @27_6166c0
  ecx = edx = 0;  // @28_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @29_6166c0
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47528), sizeof v); (u32)v; });  // @30_6166c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @31_6166c0
  ecx = edi;  // @32_6166c0
  ebx = eax;  // @33_6166c0
  PV[3] = (u32)(ebx);  // @34_6166c0
  eax = ext_659330_thiscall3(ecx, PV[3], PV[2]);  // @35_6166c0
  ecx = edx = 0;  // @36_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5114), sizeof v); (u32)v; });  // @37_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @38_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @39_6166c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @40_6166c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @41_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) == (u32)(0)) goto L616815;  // @42_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L6167aa;  // @43_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @44_6166c0
  ecx = edi;  // @45_6166c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @46_6166c0
  ecx = edx = 0;  // @47_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @48_6166c0
  L6167aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @50_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @51_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @52_6166c0
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @53_6166c0
  ecx = (u32)(eax + eax*8);  // @54_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @55_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @56_6166c0
  eax = (u32)(eax + ecx*4);  // @57_6166c0
  if ((ebx & ebx) == 0) goto L616812;  // @58_6166c0
  edx = (u32)(edi + 12);  // @59_6166c0
  edi = (edi - eax);  // @60_6166c0
  ecx = (u32)(eax + 4);  // @61_6166c0
  L6167d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 12), sizeof v); (u32)v; });  // @63_6166c0
  edx = (u32)(edx + 36);  // @64_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @65_6166c0
  ecx = (u32)(ecx + 36);  // @66_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx - 36), sizeof v); (u32)v; });  // @67_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 36), &v, sizeof v); }  // @68_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 40), sizeof v); (u32)v; });  // @69_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 32), &v, sizeof v); }  // @70_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 36), sizeof v); (u32)v; });  // @71_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 28), &v, sizeof v); }  // @72_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 32), sizeof v); (u32)v; });  // @73_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 24), &v, sizeof v); }  // @74_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 28), sizeof v); (u32)v; });  // @75_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 20), &v, sizeof v); }  // @76_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 24), sizeof v); (u32)v; });  // @77_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 16), &v, sizeof v); }  // @78_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 20), sizeof v); (u32)v; });  // @79_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 12), &v, sizeof v); }  // @80_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 16), sizeof v); (u32)v; });  // @81_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 8), &v, sizeof v); }  // @82_6166c0
  ebx = (ebx - (u32)(1));  // @83_6166c0
  if (ebx != 0) goto L6167d0;  // @84_6166c0
  L616812:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @86_6166c0
  L616815:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L61689f;  // @88_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L616834;  // @89_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_6166c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @91_6166c0
  ecx = edx = 0;  // @92_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @93_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @94_6166c0
  L616834:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @96_6166c0
  ebx = 0;  // @97_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @98_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @99_6166c0
  edi = (edi + (u32)(2));  // @100_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @101_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @102_6166c0
  edi = (edi + eax);  // @103_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L61689f;  // @104_6166c0
  L616850:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @106_6166c0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @107_6166c0
  edi = (edi + (u32)(2));  // @108_6166c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @109_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*8 + 4), sizeof v); (u32)v; });  // @110_6166c0
  if ((s32)(eax & eax) >= 0) goto L616896;  // @111_6166c0
  eax = (eax & (u32)(2147483647));  // @112_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*8 + 4), &v, sizeof v); }  // @113_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @114_6166c0
  ecx = (u32)(ecx + eax*2);  // @115_6166c0
  if ((edx & edx) == 0) goto L616896;  // @116_6166c0
  esi = edi;  // @117_6166c0
  esi = (esi - ecx);  // @118_6166c0
  L616880:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + ecx), sizeof v); (u32)v; })) & 0xffff);  // @120_6166c0
  ecx = (u32)(ecx + 2);  // @121_6166c0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx - 2), &v, sizeof v); }  // @122_6166c0
  edx = (edx - (u32)(1));  // @123_6166c0
  if (edx != 0) goto L616880;  // @124_6166c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @125_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @126_6166c0
  L616896:;
  ebx = (ebx + 1);  // @128_6166c0
  edi = (u32)(edi + edx*2);  // @129_6166c0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L616850;  // @130_6166c0
  L61689f:;
  eax = esi;  // @132_6166c0
  SEH_LEAVE();  // @133_6166c0
  return eax;  // @134_6166c0
}
PCREG(6166c0, lifted_6166c0);

