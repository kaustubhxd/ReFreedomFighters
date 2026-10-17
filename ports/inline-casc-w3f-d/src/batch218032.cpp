// batch218032.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccfe0_thiscall1(u32) __asm__("ext_4ccfe0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4db860_thiscall2(u32, u32) __asm__("ext_4db860");
extern "C" u32 THISCALL ext_4dbe30_thiscall2(u32, u32) __asm__("ext_4dbe30");
extern "C" u32 THISCALL ext_4dc440_thiscall2(u32, u32) __asm__("ext_4dc440");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_496160(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6680f8);  // @h_496160
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_496160
  ecx = (u32)(EBP - 72);  // @1_496160
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(1));  // @2_496160
  ecx = edx = 0;  // @3_496160
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_496160
  ecx = ebx;  // @5_496160
  reg.state = (s32)((u32)(0));  // @6_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_496160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(10));  // @8_496160
  ecx = edx = 0;  // @9_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @10_496160
  ecx = (u32)(EBP - 20);  // @11_496160
  PV[0] = (u32)(ecx);  // @12_496160
  ecx = ebx;  // @13_496160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @14_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @15_496160
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @16_496160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[0], (u32)(2));  // @17_496160
  ecx = edx = 0;  // @18_496160
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; })) & 0xffff);  // @19_496160
  edi = (u32)(65535);  // @20_496160
  FL[0] = (eax & 0xffff); FL[1] = (edi & 0xffff);  // @21_496160
  if (FL[0] == FL[1]) goto L4962ad;  // @22_496160
  L4961d1:;
  eax = (eax & 0xffff);  // @24_496160
  ecx = (u32)(EBP - 16);  // @25_496160
  eax = (u32)((s32)eax * (s32)(u32)(112));  // @26_496160
  PV[1] = (u32)(ecx);  // @27_496160
  ecx = ebx;  // @28_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi + 84), sizeof v); (u32)v; });  // @29_496160
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @30_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_496160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[1], (u32)(2));  // @32_496160
  ecx = edx = 0;  // @33_496160
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (edi & 0xffff);  // @34_496160
  if (FL[0] == FL[1]) goto L496293;  // @35_496160
  L4961f5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_496160
  ecx = (u32)(EBP - 24);  // @38_496160
  PV[2] = (u32)(ecx);  // @39_496160
  ecx = ebx;  // @40_496160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[2], (u32)(2));  // @41_496160
  ecx = edx = 0;  // @42_496160
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @43_496160
  edi = (u32)((s32)eax * (s32)(u32)(112));  // @44_496160
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @45_496160
  edi = (edi + esi);  // @46_496160
  FL[3] = edi;  // @47_496160
  esi = (u32)((s32)eax * (s32)(u32)(112));  // @48_496160
  esi = (esi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @49_496160
  FL[3] = esi;  // @50_496160
  FL[0] = esi; FL[1] = edi;  // @51_496160
  if (FL[0] > FL[1]) goto L496274;  // @52_496160
  L496220:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @54_496160
  FL[2] = (eax & (u32)(67108864));  // @55_496160
  if (FL[2] != 0) goto L49626a;  // @56_496160
  FL[2] = (eax & (u32)(262144));  // @57_496160
  if (FL[2] == 0) goto L496246;  // @58_496160
  PV[3] = (u32)(esi);  // @59_496160
  ecx = (u32)(EBP - 72);  // @60_496160
  eax = ext_4cd540_thiscall2(ecx, PV[3]);  // @61_496160
  ecx = edx = 0;  // @62_496160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @63_496160
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @64_496160
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(4294688767))); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @65_496160
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @66_496160
  L496246:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; });  // @68_496160
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; });  // @69_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_496160
  PV[4] = (u32)(esi);  // @71_496160
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 652)))(ecx, PV[4], (u32)(0), (u32)(1));  // @72_496160
  ecx = edx = 0;  // @73_496160
  ebx = (ebx >> (u32)(11));  // @74_496160
  FL[3] = ebx;  // @75_496160
  ecx = esi;  // @76_496160
  ebx = (ebx & 0xffffff00u) | ((((ebx & 0xff) & (u32)(1))) & 0xff);  // @77_496160
  FL[3] = (ebx & 0xff);  // @78_496160
  eax = (ebx & 0xff);  // @79_496160
  PV[5] = (u32)(eax);  // @80_496160
  eax = ext_4db860_thiscall2(ecx, PV[5]);  // @81_496160
  ecx = edx = 0;  // @82_496160
  L49626a:;
  esi = (esi + (u32)(112));  // @84_496160
  FL[3] = esi;  // @85_496160
  FL[0] = esi; FL[1] = edi;  // @86_496160
  if (FL[0] <= FL[1]) goto L496220;  // @87_496160
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @88_496160
  L496274:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @90_496160
  ecx = (u32)(EBP - 16);  // @91_496160
  PV[6] = (u32)(ecx);  // @92_496160
  ecx = ebx;  // @93_496160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[6], (u32)(2));  // @94_496160
  ecx = edx = 0;  // @95_496160
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @96_496160
  edi = (u32)(65535);  // @97_496160
  FL[0] = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }); FL[1] = (edi & 0xffff);  // @98_496160
  if (FL[0] != FL[1]) goto L4961f5;  // @99_496160
  L496293:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @101_496160
  ecx = (u32)(EBP - 20);  // @102_496160
  PV[7] = (u32)(ecx);  // @103_496160
  ecx = ebx;  // @104_496160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, PV[7], (u32)(2));  // @105_496160
  ecx = edx = 0;  // @106_496160
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; })) & 0xffff);  // @107_496160
  FL[0] = (eax & 0xffff); FL[1] = (edi & 0xffff);  // @108_496160
  if (FL[0] != FL[1]) goto L4961d1;  // @109_496160
  L4962ad:;
  eax = (u32)(EBP - 44);  // @111_496160
  PV[8] = (u32)(eax);  // @112_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @113_496160
  ecx = (u32)(EBP - 72);  // @114_496160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, PV[8]);  // @115_496160
  ecx = edx = 0;  // @116_496160
  eax = (u32)(EBP - 44);  // @117_496160
  PV[9] = (u32)(eax);  // @118_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @119_496160
  ecx = (u32)(EBP - 72);  // @120_496160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[9]);  // @121_496160
  ecx = edx = 0;  // @122_496160
  esi = eax;  // @123_496160
  FL[2] = (esi & esi);  // @124_496160
  if (FL[2] == 0) goto L496300;  // @125_496160
  L4962d0:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @127_496160
  ecx = edi;  // @128_496160
  eax = ext_4dbe30_thiscall2(ecx, (u32)(1));  // @129_496160
  ecx = edx = 0;  // @130_496160
  FL[2] = (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(16384));  // @131_496160
  if (FL[2] == 0) goto L4962ed;  // @132_496160
  ecx = edi;  // @133_496160
  eax = ext_4dc440_thiscall2(ecx, (u32)(1));  // @134_496160
  ecx = edx = 0;  // @135_496160
  L4962ed:;
  eax = (u32)(EBP - 44);  // @137_496160
  PV[10] = (u32)(eax);  // @138_496160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 72), sizeof v); (u32)v; });  // @139_496160
  ecx = (u32)(EBP - 72);  // @140_496160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, PV[10]);  // @141_496160
  ecx = edx = 0;  // @142_496160
  esi = eax;  // @143_496160
  FL[2] = (esi & esi);  // @144_496160
  if (FL[2] != 0) goto L4962d0;  // @145_496160
  L496300:;
  ecx = (u32)(EBP - 72);  // @147_496160
  eax = ext_4ccfe0_thiscall1(ecx);  // @148_496160
  ecx = edx = 0;  // @149_496160
  SEH_LEAVE();  // @150_496160
  return eax;  // @151_496160
}
PCREG(496160, lifted_496160);

