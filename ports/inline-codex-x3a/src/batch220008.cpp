// batch220008.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_5ab9d0_thiscall1(u32) __asm__("ext_5ab9d0");
extern "C" u32 THISCALL ext_5ac5d0_thiscall2(u32, u32) __asm__("ext_5ac5d0");
extern "C" u32 THISCALL ext_5aca30_thiscall3(u32, u32, u32) __asm__("ext_5aca30");
extern "C" u32 THISCALL ext_5ee110_thiscall4(u32, u32, u32, u32) __asm__("ext_5ee110");
extern "C" u32 THISCALL ext_5ee920_thiscall1(u32) __asm__("ext_5ee920");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5edf70(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5edf70
  esi = ecx;  // @1_5edf70
  ecx = edx;  // @2_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; });  // @3_5edf70
  edi = (u32)(ecx + 1);  // @4_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 12), &v, sizeof v); }  // @5_5edf70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @6_5edf70
  L5edf90:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @8_5edf70
  ecx = (ecx + 1);  // @9_5edf70
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L5edf90;  // @10_5edf70
  ecx = (ecx - edi);  // @11_5edf70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_5edf70
  edi = ecx;  // @13_5edf70
  if (ecx <= (u32)(1)) goto L5ee0e9;  // @14_5edf70
  ebx = (u32)(ecx - 2);  // @15_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @16_5edf70
  if ((ebx & ebx) == 0) goto L5ee0e9;  // @17_5edf70
  L5edfb5:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx), sizeof v); (u32)v; }) != (u32)(92)) goto L5ee0bd;  // @19_5edf70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + edx + 1), sizeof v); (u32)v; }) != (u32)(110)) goto L5ee0bd;  // @20_5edf70
  edi = (edi - ebx);  // @21_5edf70
  edi = (edi - (u32)(2));  // @22_5edf70
  if (edi == 0) goto L5ee0bb;  // @23_5edf70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 17), sizeof v); (u32)v; }) != (u32)(1)) goto L5ee010;  // @24_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @25_5edf70
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }));  // @26_5edf70
  eax = (u32)((s32)eax >> (u32)(2));  // @27_5edf70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }) != eax) goto L5edff7;  // @28_5edf70
  ecx = esi;  // @29_5edf70
  eax = ext_5ee920_thiscall1(ecx);  // @30_5edf70
  ecx = edx = 0;  // @31_5edf70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @32_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @33_5edf70
  L5edff7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @35_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @36_5edf70
  edx = a1;  // @37_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @38_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @39_5edf70
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @40_5edf70
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @41_5edf70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @42_5edf70
  goto L5ee046;  // @43_5edf70
  L5ee010:;
  ecx = esi;  // @45_5edf70
  eax = ext_5ee920_thiscall1(ecx);  // @46_5edf70
  ecx = edx = 0;  // @47_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @48_5edf70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @49_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @52_5edf70
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }));  // @53_5edf70
  eax = (u32)((s32)eax >> (u32)(2));  // @54_5edf70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @55_5edf70
  if (edx == eax) goto L5ee03b;  // @56_5edf70
  eax = (u32)(edx + 1);  // @57_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @58_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 25), &v, sizeof v); }  // @59_5edf70
  L5ee03b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @61_5edf70
  edx = a1;  // @62_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @63_5edf70
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @64_5edf70
  L5ee046:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @66_5edf70
  eax = (eax + (u32)(2));  // @67_5edf70
  eax = (eax + ebx);  // @68_5edf70
  eax = ext_5aca30_thiscall3(ecx, (u32)(eax), (u32)(edi));  // @69_5edf70
  ecx = edx = 0;  // @70_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @71_5edf70
  eax = ext_5ac5d0_thiscall2(ecx, a1);  // @72_5edf70
  ecx = edx = 0;  // @73_5edf70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 65), &v, sizeof v); }  // @74_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @75_5edf70
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; }) == (u32)(0)) goto L5ee0b4;  // @76_5edf70
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @77_5edf70
  ebx = 0;  // @78_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @79_5edf70
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; })) goto L5ee0a2;  // @80_5edf70
  L5ee080:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_5edf70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @83_5edf70
  eax = ext_5ab9d0_thiscall1(ecx);  // @84_5edf70
  ecx = edx = 0;  // @85_5edf70
  if (eax > ebx) ebx = eax;  // @86_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @87_5edf70
  eax = (eax + 1);  // @88_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @89_5edf70
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; })) goto L5ee0a2;  // @90_5edf70
  edi = (edi + (u32)(4));  // @91_5edf70
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; })) goto L5ee080;  // @92_5edf70
  L5ee0a2:;
  ebx = (ebx + (u32)(10));  // @94_5edf70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }) == ebx) goto L5ee0b1;  // @95_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @96_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @97_5edf70
  L5ee0b1:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @99_5edf70
  L5ee0b4:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @101_5edf70
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @102_5edf70
  L5ee0bb:;
  edi = ebx;  // @104_5edf70
  L5ee0bd:;
  ebx = (ebx - (u32)(1));  // @106_5edf70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @107_5edf70
  if (ebx != 0) goto L5edfb5;  // @108_5edf70
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; })) goto L5ee0e9;  // @109_5edf70
  ecx = esi;  // @110_5edf70
  eax = ext_5ee110_thiscall4(ecx, (u32)(edx), (u32)(edi), a1);  // @111_5edf70
  ecx = edx = 0;  // @112_5edf70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @113_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @114_5edf70
  return eax;  // @115_5edf70
  L5ee0e9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 12), sizeof v); (u32)v; });  // @117_5edf70
  ecx = esi;  // @118_5edf70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @119_5edf70
  eax = ext_5ee110_thiscall4(ecx, (u32)(edx), (u32)(edi), a1);  // @120_5edf70
  ecx = edx = 0;  // @121_5edf70
  return eax;  // @122_5edf70
}
PCREG(5edf70, lifted_5edf70);

