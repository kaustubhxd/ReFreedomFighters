// batch226027.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_5f2b90_thiscall1(u32) __asm__("ext_5f2b90");
extern "C" u32 THISCALL ext_5fb330_thiscall2(u32, u32) __asm__("ext_5fb330");
extern "C" u32 THISCALL ext_5fb5b0_thiscall1(u32) __asm__("ext_5fb5b0");
extern "C" u32 THISCALL ext_5fbbe0_thiscall2(u32, u32) __asm__("ext_5fbbe0");
extern "C" u32 THISCALL ext_5fd170_thiscall1(u32) __asm__("ext_5fd170");
extern "C" u32 THISCALL ext_5fe200_thiscall2(u32, u32) __asm__("ext_5fe200");
extern "C" u32 THISCALL ext_602240_thiscall1(u32) __asm__("ext_602240");
extern "C" u32 THISCALL ext_638ce0_thiscall1(u32) __asm__("ext_638ce0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5f2400(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cfa8);  // @h_5f2400
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5f2400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @2_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @3_5f2400
  eax = ext_5fd170_thiscall1(ecx);  // @4_5f2400
  ecx = edx = 0;  // @5_5f2400
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_5f2400
  ecx = edi;  // @7_5f2400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @8_5f2400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(18));  // @9_5f2400
  ecx = edx = 0;  // @10_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @11_5f2400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_5f2400
  ecx = (ecx + (u32)(20));  // @13_5f2400
  eax = ext_4cc1d0_thiscall1(ecx);  // @14_5f2400
  ecx = edx = 0;  // @15_5f2400
  PS[0] = eax;  // @16_5f2400
  ecx = edi;  // @17_5f2400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 100)))(ecx, (u32)(PS[0]));  // @18_5f2400
  ecx = edx = 0;  // @19_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @20_5f2400
  ecx = (ecx + (u32)(152));  // @21_5f2400
  PS[0] = ecx;  // @22_5f2400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @23_5f2400
  ecx = eax;  // @24_5f2400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @25_5f2400
  ecx = edx = 0;  // @26_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @27_5f2400
  ecx = (ecx + (u32)(156));  // @28_5f2400
  PS[0] = ecx;  // @29_5f2400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @30_5f2400
  ecx = eax;  // @31_5f2400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @32_5f2400
  ecx = edx = 0;  // @33_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @34_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @35_5f2400
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @36_5f2400
  { u32 v = (u32)((u32)(7046660)); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @37_5f2400
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 23), &v, sizeof v); }  // @38_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @39_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @40_5f2400
  eax = (u32)(EBP - 44);  // @41_5f2400
  PS[0] = eax;  // @42_5f2400
  reg.state = (s32)((u32)(0));  // @43_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @44_5f2400
  eax = ext_5fbbe0_thiscall2(ecx, (u32)(PS[0]));  // @45_5f2400
  ecx = edx = 0;  // @46_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @47_5f2400
  edi = 0;  // @48_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @49_5f2400
  eax = ext_638ce0_thiscall1(ecx);  // @50_5f2400
  ecx = edx = 0;  // @51_5f2400
  if ((eax & eax) == 0) goto L5f25a9;  // @52_5f2400
  L5f24c7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @54_5f2400
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @55_5f2400
  if (edi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; })) goto L5f24e0;  // @56_5f2400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @57_5f2400
  if ((eax & eax) == 0) goto L5f24df;  // @58_5f2400
  eax = ((u32(STDCALL *)(void))(eax))();  // @59_5f2400
  ecx = edx = 0;  // @60_5f2400
  goto L5f24e0;  // @61_5f2400
  L5f24df:;
  __builtin_trap();  // @63_5f2400
  L5f24e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @65_5f2400
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @66_5f2400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 32), sizeof v); (u32)v; }) != (u32)(0)) goto L5f2592;  // @67_5f2400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @68_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @69_5f2400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @70_5f2400
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 36), sizeof v); (u32)v; }));  // @71_5f2400
  ecx = edx = 0;  // @72_5f2400
  esi = eax;  // @73_5f2400
  if ((esi & esi) == 0) goto L5f2592;  // @74_5f2400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }) != (u32)(0)) goto L5f251a;  // @75_5f2400
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @76_5f2400
  ecx = esi;  // @77_5f2400
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 64)))(ecx);  // @78_5f2400
  ecx = edx = 0;  // @79_5f2400
  L5f251a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @81_5f2400
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L5f2586;  // @82_5f2400
  eax = ext_41e290_cdecl1((u32)(8));  // @83_5f2400
  ecx = edx = 0;  // @84_5f2400
  ecx = eax;  // @85_5f2400
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @86_5f2400
  if ((ecx & ecx) == 0) goto L5f2545;  // @87_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @88_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @89_5f2400
  goto L5f2547;  // @90_5f2400
  L5f2545:;
  ecx = 0;  // @92_5f2400
  L5f2547:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @94_5f2400
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 28), &v, sizeof v); }  // @95_5f2400
  eax = ext_41e290_cdecl1((u32)(16));  // @96_5f2400
  ecx = edx = 0;  // @97_5f2400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @98_5f2400
  if ((eax & eax) == 0) goto L5f257b;  // @99_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @100_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @101_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @102_5f2400
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @103_5f2400
  goto L5f257d;  // @104_5f2400
  L5f257b:;
  eax = 0;  // @106_5f2400
  L5f257d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @108_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @109_5f2400
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @110_5f2400
  L5f2586:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; });  // @112_5f2400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @113_5f2400
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @114_5f2400
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @115_5f2400
  L5f2592:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @117_5f2400
  edi = (edi + 1);  // @118_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @119_5f2400
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @120_5f2400
  eax = ext_638ce0_thiscall1(ecx);  // @121_5f2400
  ecx = edx = 0;  // @122_5f2400
  if (edi < eax) goto L5f24c7;  // @123_5f2400
  L5f25a9:;
  ecx = ebx;  // @125_5f2400
  eax = ext_5f2b90_thiscall1(ecx);  // @126_5f2400
  ecx = edx = 0;  // @127_5f2400
  ecx = (u32)(EBP - 44);  // @128_5f2400
  eax = ext_602240_thiscall1(ecx);  // @129_5f2400
  ecx = edx = 0;  // @130_5f2400
  SEH_LEAVE();  // @131_5f2400
  return eax;  // @132_5f2400
}
PCREG(5f2400, lifted_5f2400);

extern "C" u32 THISCALL lifted_5fdb70(u32 ecx_in) {
  SEH_ENTER(0x66d6fa);  // @h_5fdb70
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_5fdb70
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 152), sizeof v); (u32)v; });  // @2_5fdb70
  { u32 v = (u32)((u32)(7049892)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @3_5fdb70
  if ((eax & eax) == 0) goto L5fdbc2;  // @4_5fdb70
  PS[1] = eax;  // @5_5fdb70
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @6_5fdb70
  ecx = edx = 0;  // @7_5fdb70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 152), &v, sizeof v); }  // @8_5fdb70
  L5fdbc2:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 268), sizeof v); (u32)v; });  // @10_5fdb70
  eax = (u32)(ebx + 268);  // @11_5fdb70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @12_5fdb70
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 272), sizeof v); (u32)v; })) goto L5fdc19;  // @13_5fdb70
  L5fdbe0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @15_5fdb70
  if ((esi & esi) == 0) goto L5fdc0e;  // @16_5fdb70
  ecx = esi;  // @17_5fdb70
  reg.state = (s32)((u32)(0));  // @18_5fdb70
  eax = ext_5fb5b0_thiscall1(ecx);  // @19_5fdb70
  ecx = edx = 0;  // @20_5fdb70
  ecx = esi;  // @21_5fdb70
  reg.state = (s32)((u32)(1));  // @22_5fdb70
  eax = ext_54f870_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(19));  // @23_5fdb70
  ecx = edx = 0;  // @24_5fdb70
  PS[1] = esi;  // @25_5fdb70
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(9));  // @26_5fdb70
  ecx = edx = 0;  // @27_5fdb70
  L5fdc0e:;
  edi = (edi + (u32)(4));  // @29_5fdb70
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 272), sizeof v); (u32)v; })) goto L5fdbe0;  // @30_5fdb70
  L5fdc19:;
  edi = (u32)(ebx + 289);  // @32_5fdb70
  reg.state = (s32)((u32)(2));  // @33_5fdb70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L5fdc7a;  // @34_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @36_5fdb70
  if ((eax & eax) == 0) goto L5fdc60;  // @37_5fdb70
  ebx = eax;  // @38_5fdb70
  L5fdc40:;
  ecx = edi;  // @40_5fdb70
  eax = ext_5fb330_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 9), sizeof v); (u32)v; }));  // @41_5fdb70
  ecx = edx = 0;  // @42_5fdb70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 5), sizeof v); (u32)v; });  // @43_5fdb70
  ecx = edi;  // @44_5fdb70
  PS[1] = ebx;  // @45_5fdb70
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(21));  // @46_5fdb70
  ecx = edx = 0;  // @47_5fdb70
  ebx = esi;  // @48_5fdb70
  if ((esi & esi) != 0) goto L5fdc40;  // @49_5fdb70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @50_5fdb70
  L5fdc60:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @52_5fdb70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @53_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_5fdb70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @55_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_5fdb70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @57_5fdb70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @58_5fdb70
  L5fdc7a:;
  ecx = edi;  // @60_5fdb70
  reg.state = (s32)((u32)(3));  // @61_5fdb70
  eax = ext_54f870_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), (u32)(21));  // @62_5fdb70
  ecx = edx = 0;  // @63_5fdb70
  edi = (u32)(ebx + 280);  // @64_5fdb70
  reg.state = (s32)((u32)(4));  // @65_5fdb70
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L5fdcdc;  // @66_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @67_5fdb70
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @68_5fdb70
  if ((ebx & ebx) == 0) goto L5fdcc2;  // @69_5fdb70
  L5fdca5:;
  ecx = edi;  // @71_5fdb70
  eax = ext_5fe200_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 9), sizeof v); (u32)v; }));  // @72_5fdb70
  ecx = edx = 0;  // @73_5fdb70
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 5), sizeof v); (u32)v; });  // @74_5fdb70
  ecx = edi;  // @75_5fdb70
  PS[1] = ebx;  // @76_5fdb70
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(19));  // @77_5fdb70
  ecx = edx = 0;  // @78_5fdb70
  ebx = esi;  // @79_5fdb70
  if ((esi & esi) != 0) goto L5fdca5;  // @80_5fdb70
  L5fdcc2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @82_5fdb70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @83_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_5fdb70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @85_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @86_5fdb70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @87_5fdb70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @88_5fdb70
  L5fdcdc:;
  ecx = edi;  // @90_5fdb70
  reg.state = (s32)((u32)(5));  // @91_5fdb70
  eax = ext_54f870_stdcall2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), (u32)(19));  // @92_5fdb70
  ecx = edx = 0;  // @93_5fdb70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @94_5fdb70
  reg.state = (s32)((u32)(6));  // @95_5fdb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @96_5fdb70
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_5fdb70
  eax = (eax - edx);  // @98_5fdb70
  eax = (u32)((s32)eax >> (u32)(2));  // @99_5fdb70
  if ((eax & eax) == 0) goto L5fdd0d;  // @100_5fdb70
  eax = (eax << (u32)(2));  // @101_5fdb70
  PS[0] = eax;  // @102_5fdb70
  PS[1] = edx;  // @103_5fdb70
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @104_5fdb70
  ecx = edx = 0;  // @105_5fdb70
  L5fdd0d:;
  SEH_LEAVE();  // @107_5fdb70
  return eax;  // @108_5fdb70
}
PCREG(5fdb70, lifted_5fdb70);

