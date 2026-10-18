// batch200072.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_5c6370_stdcall2(u32, u32) __asm__("ext_5c6370");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_42c9a0_thiscall1(u32) __asm__("ext_42c9a0");
extern "C" u32 THISCALL ext_439fd0_thiscall2(u32, u32) __asm__("ext_439fd0");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cbf30_thiscall2(u32, u32) __asm__("ext_4cbf30");
extern "C" u32 THISCALL ext_4cc130_thiscall2(u32, u32) __asm__("ext_4cc130");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc5a0_thiscall1(u32) __asm__("ext_4cc5a0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4da2f0_thiscall3(u32, u32, u32) __asm__("ext_4da2f0");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4da3a0_thiscall1(u32) __asm__("ext_4da3a0");
extern "C" u32 THISCALL ext_4db550_thiscall1(u32) __asm__("ext_4db550");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_5378a0_thiscall1(u32) __asm__("ext_5378a0");
extern "C" u32 THISCALL ext_54abf0_thiscall1(u32) __asm__("ext_54abf0");
extern "C" u32 THISCALL ext_5b6d00_thiscall1(u32) __asm__("ext_5b6d00");
extern "C" u32 THISCALL ext_5eaaf0_thiscall1(u32) __asm__("ext_5eaaf0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4690b0_cdecl0(void) __asm__("ext_4690b0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc5a0_cdecl2(...) __asm__("ext_4cc5a0");
extern "C" u32 ext_4cc5a0_cdecl4(...) __asm__("ext_4cc5a0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5335d0(u32 ecx_in) {
  SEH_ENTER(0x66a7a2);  // @h_5335d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_5335d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @2_5335d0
  edx = (u32)(EBP - 20);  // @3_5335d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @4_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @6_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953228), (u32)(edx));  // @7_5335d0
  ecx = edx = 0;  // @8_5335d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @9_5335d0
  edx = (u32)(EBP - 20);  // @10_5335d0
  eax = (eax & 0xffffff00u) | (((u32)(((eax & 0xff) & (eax & 0xff)) == 0)) & 0xff);  // @11_5335d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 134), &v, sizeof v); }  // @12_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @15_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953240), (u32)(edx));  // @16_5335d0
  ecx = edx = 0;  // @17_5335d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775512), sizeof v); (u32)v; });  // @18_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L53365c;  // @19_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @20_5335d0
  if ((eax & eax) == 0) goto L53365c;  // @21_5335d0
  eax = ((u32( *)(u32))(ebx))((u32)(eax));  // @22_5335d0
  ecx = edx = 0;  // @23_5335d0
  { u8 v = (u8)((u32)((eax & eax) != 0)); __builtin_memcpy((void *)(u32)(EBP - 13), &v, sizeof v); }  // @24_5335d0
  L53365c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @26_5335d0
  edx = (u32)(EBP - 20);  // @27_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @28_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @29_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953260), (u32)(edx));  // @30_5335d0
  ecx = edx = 0;  // @31_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533683;  // @32_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @33_5335d0
  if ((eax & eax) == 0) goto L533683;  // @34_5335d0
  eax = ((u32( *)(u32))(ebx))((u32)(eax));  // @35_5335d0
  ecx = edx = 0;  // @36_5335d0
  L533683:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_5335d0
  edx = (u32)(EBP - 20);  // @39_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @41_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953276), (u32)(edx));  // @42_5335d0
  ecx = edx = 0;  // @43_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5336aa;  // @44_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @45_5335d0
  if ((eax & eax) == 0) goto L5336aa;  // @46_5335d0
  eax = ((u32( *)(u32))(ebx))((u32)(eax));  // @47_5335d0
  ecx = edx = 0;  // @48_5335d0
  L5336aa:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_5335d0
  edx = (u32)(EBP - 20);  // @51_5335d0
  esi = (u32)(4);  // @52_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @54_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6953296), (u32)(edx));  // @55_5335d0
  ecx = edx = 0;  // @56_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5336ee;  // @57_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @58_5335d0
  if ((eax & eax) == 0) goto L5336ee;  // @59_5335d0
  eax = ((u32(STDCALL *)(u32))(ebx))((u32)(eax));  // @60_5335d0
  ecx = edx = 0;  // @61_5335d0
  esi = eax;  // @62_5335d0
  if ((s32)esi >= (s32)(u32)(1)) goto L5336e4;  // @63_5335d0
  esi = (u32)(1);  // @64_5335d0
  goto L5336ee;  // @65_5335d0
  L5336e4:;
  eax = (u32)(4);  // @67_5335d0
  if ((s32)esi > (s32)eax) esi = eax;  // @68_5335d0
  L5336ee:;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 21634), &v, sizeof v); }  // @70_5335d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 13), sizeof v); (u32)v; }) == (u32)(0)) goto L5337a5;  // @71_5335d0
  eax = ext_41e290_cdecl1((u32)(41693));  // @72_5335d0
  ecx = edx = 0;  // @73_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @74_5335d0
  reg.state = (s32)((u32)(0));  // @75_5335d0
  if ((eax & eax) == 0) goto L533724;  // @76_5335d0
  ecx = eax;  // @77_5335d0
  eax = ext_54abf0_thiscall1(ecx);  // @78_5335d0
  ecx = edx = 0;  // @79_5335d0
  edi = eax;  // @80_5335d0
  goto L533726;  // @81_5335d0
  L533724:;
  edi = 0;  // @83_5335d0
  L533726:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_5335d0
  ecx = edi;  // @86_5335d0
  reg.state = (s32)((u32)(4294967295));  // @87_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @88_5335d0
  ecx = edx = 0;  // @89_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_5335d0
  esi = eax;  // @91_5335d0
  eax = (u32)(EBP - 20);  // @92_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @93_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 92), sizeof v); (u32)v; });  // @94_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6953312), (u32)(eax));  // @95_5335d0
  ecx = edx = 0;  // @96_5335d0
  ecx = edi;  // @97_5335d0
  eax = (eax & 0xffffff00u) | (((u32)(((eax & 0xff) & (eax & 0xff)) == 0)) & 0xff);  // @98_5335d0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(esi + 202), &v, sizeof v); }  // @99_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @100_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 172), sizeof v); (u32)v; });  // @101_5335d0
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @102_5335d0
  ecx = edx = 0;  // @103_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533799;  // @104_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @105_5335d0
  ecx = edi;  // @106_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 168)))(ecx);  // @107_5335d0
  ecx = edx = 0;  // @108_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @109_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @110_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + ecx*4 + 21602), &v, sizeof v); }  // @111_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; });  // @112_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + ecx*4 + 21602), sizeof v); (u32)v; });  // @113_5335d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @114_5335d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 21614), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(edx + 21614), &v, sizeof v); }  // @115_5335d0
  L533799:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @117_5335d0
  ecx = edi;  // @118_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(1));  // @119_5335d0
  ecx = edx = 0;  // @120_5335d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @121_5335d0
  L5337a5:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775112), sizeof v); (u32)v; });  // @123_5335d0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(esi))((u32)(0), (u32)(0), (u32)(1), (u32)(0));  // @124_5335d0
  ecx = edx = 0;  // @125_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7347048), &v, sizeof v); }  // @126_5335d0
  eax = ((u32(STDCALL *)(u32, u32, u32, u32))(esi))((u32)(0), (u32)(1), (u32)(1), (u32)(0));  // @127_5335d0
  ecx = edx = 0;  // @128_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @129_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7347052), &v, sizeof v); }  // @130_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @131_5335d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @132_5335d0
  ecx = edx = 0;  // @133_5335d0
  esi = eax;  // @134_5335d0
  if ((esi & esi) == 0) goto L53388c;  // @135_5335d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_5335d0
  edx = (u32)(EBP - 24);  // @137_5335d0
  { u32 v = (u32)((u32)(24)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @138_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @139_5335d0
  { u32 v = (u32)((u32)(3)); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @140_5335d0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @141_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @142_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6792084), (u32)(edx));  // @143_5335d0
  ecx = edx = 0;  // @144_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L53381b;  // @145_5335d0
  eax = ((u32( *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @146_5335d0
  ecx = edx = 0;  // @147_5335d0
  { u8 v = (u8)((u32)((eax & eax) != 0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @148_5335d0
  L53381b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @150_5335d0
  edx = (u32)(EBP - 24);  // @151_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @153_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6792092), (u32)(edx));  // @154_5335d0
  ecx = edx = 0;  // @155_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533840;  // @156_5335d0
  eax = ((u32( *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @157_5335d0
  ecx = edx = 0;  // @158_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @159_5335d0
  L533840:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @161_5335d0
  eax = (u32)(EBP - 24);  // @162_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 92), sizeof v); (u32)v; });  // @164_5335d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(edx))(ecx, (u32)(6791240), (u32)(eax));  // @165_5335d0
  ecx = edx = 0;  // @166_5335d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L533865;  // @167_5335d0
  eax = ((u32( *)(u32))(ebx))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }));  // @168_5335d0
  ecx = edx = 0;  // @169_5335d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @170_5335d0
  L533865:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @172_5335d0
  ecx = esi;  // @173_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 232)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @174_5335d0
  ecx = edx = 0;  // @175_5335d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @176_5335d0
  ecx = esi;  // @177_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 228)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @178_5335d0
  ecx = edx = 0;  // @179_5335d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @180_5335d0
  ecx = esi;  // @181_5335d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 160)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @182_5335d0
  ecx = edx = 0;  // @183_5335d0
  L53388c:;
  ecx = edi;  // @185_5335d0
  eax = ext_5378a0_thiscall1(ecx);  // @186_5335d0
  ecx = edx = 0;  // @187_5335d0
  SEH_LEAVE();  // @188_5335d0
  return eax;  // @189_5335d0
}
PCREG(5335d0, lifted_5335d0);

extern "C" u32 THISCALL lifted_498270(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66713b);  // @h_498270
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_498270
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_498270
  ecx = esi;  // @2_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_498270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(9));  // @4_498270
  ecx = edx = 0;  // @5_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @6_498270
  ecx = esi;  // @7_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_498270
  eax = (eax + (u32)(12));  // @9_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @10_498270
  ecx = edx = 0;  // @11_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @12_498270
  ecx = esi;  // @13_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_498270
  eax = (eax + (u32)(16));  // @15_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @16_498270
  ecx = edx = 0;  // @17_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @18_498270
  ecx = esi;  // @19_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_498270
  eax = (eax + (u32)(20));  // @21_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @22_498270
  ecx = edx = 0;  // @23_498270
  ecx = (u32)(EBP - 188);  // @24_498270
  eax = ext_4ccba0_thiscall1(ecx);  // @25_498270
  ecx = edx = 0;  // @26_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_498270
  ecx = (u32)(EBP - 192);  // @28_498270
  ecx = esi;  // @29_498270
  reg.state = (s32)((u32)(0));  // @30_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @31_498270
  ecx = edx = 0;  // @32_498270
  edi = 0;  // @33_498270
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; }) == edi) goto L49833a;  // @34_498270
  L498310:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_498270
  ecx = (u32)(EBP - 200);  // @37_498270
  ecx = esi;  // @38_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @39_498270
  ecx = edx = 0;  // @40_498270
  ecx = (u32)(EBP - 188);  // @41_498270
  eax = ext_4cd540_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }));  // @42_498270
  ecx = edx = 0;  // @43_498270
  edi = (edi + 1);  // @44_498270
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; })) goto L498310;  // @45_498270
  L49833a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @47_498270
  edx = (u32)(EBP - 188);  // @48_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_498270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(edx));  // @50_498270
  ecx = edx = 0;  // @51_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_498270
  ecx = (u32)(EBP - 196);  // @53_498270
  ecx = esi;  // @54_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @55_498270
  ecx = edx = 0;  // @56_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @57_498270
  ecx = esi;  // @58_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_498270
  eax = (eax << (u32)(2));  // @60_498270
  eax = (u32)(EBP - 204);  // @61_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 16)))(ecx, (u32)(eax), (u32)(eax));  // @62_498270
  ecx = edx = 0;  // @63_498270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @64_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; }));  // @66_498270
  ecx = edx = 0;  // @67_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @68_498270
  ecx = esi;  // @69_498270
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(1280266803));  // @70_498270
  ecx = edx = 0;  // @71_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @72_498270
  ecx = esi;  // @73_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @74_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @75_498270
  eax = (u32)(eax*4 + 4);  // @76_498270
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; }), (u32)(eax));  // @77_498270
  ecx = edx = 0;  // @78_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @79_498270
  esi = 0;  // @80_498270
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @81_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @82_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @83_498270
  eax = (eax + (u32)(1));  // @84_498270
  if (eax == 0) goto L498406;  // @85_498270
  L4983c0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @87_498270
  ecx = (u32)(eax + esi*4);  // @88_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_498270
  if (eax == (u32)(-1)) goto L4983f4;  // @90_498270
  eax = (u32)((s32)eax * (s32)(u32)(112));  // @91_498270
  eax = (eax + edi);  // @92_498270
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @93_498270
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @94_498270
  if ((ecx & ecx) == 0) goto L4983fa;  // @95_498270
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_498270
  eax = (u32)(esi*4);  // @97_498270
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(6873948), (u32)(eax), (u32)(4));  // @98_498270
  ecx = edx = 0;  // @99_498270
  goto L4983fa;  // @100_498270
  L4983f4:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @102_498270
  L4983fa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @104_498270
  esi = (esi + 1);  // @105_498270
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @106_498270
  eax = (eax + 1);  // @107_498270
  if (esi != eax) goto L4983c0;  // @108_498270
  L498406:;
  ecx = (u32)(EBP - 188);  // @110_498270
  eax = ext_4ccf60_thiscall1(ecx);  // @111_498270
  ecx = edx = 0;  // @112_498270
  SEH_LEAVE();  // @113_498270
  ext_633654(G(u32, 0x6f5630));  // @114_498270
  return eax;  // @115_498270
}
PCREG(498270, lifted_498270);

extern "C" u32 THISCALL lifted_439970(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665b80);  // @h_439970
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_439970
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @2_439970
  if ((ecx & ecx) != 0) goto L439a0f;  // @3_439970
  eax = ext_41e290_cdecl1((u32)(28));  // @4_439970
  ecx = edx = 0;  // @5_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_439970
  reg.state = (s32)((u32)(0));  // @7_439970
  if ((eax & eax) == 0) goto L4399cc;  // @8_439970
  ecx = eax;  // @9_439970
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(45));  // @10_439970
  ecx = edx = 0;  // @11_439970
  goto L4399ce;  // @12_439970
  L4399cc:;
  eax = 0;  // @14_439970
  L4399ce:;
  reg.state = (s32)((u32)(4294967295));  // @16_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 4920), &v, sizeof v); }  // @17_439970
  L4399db:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_439970
  L4399de:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @21_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @23_439970
  ecx = edx = 0;  // @24_439970
  ebx = eax;  // @25_439970
  ebx = (ebx - (u32)(4));  // @26_439970
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @27_439970
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @28_439970
  reg.state = (s32)((u32)(1));  // @29_439970
  if (ebx == 0) goto L439a93;  // @30_439970
  ecx = ebx;  // @31_439970
  eax = ext_4cbeb0_thiscall1(ecx);  // @32_439970
  ecx = edx = 0;  // @33_439970
  goto L439a95;  // @34_439970
  L439a0f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_439970
  edx = (u32)(EBP - 36);  // @37_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @38_439970
  ecx = edx = 0;  // @39_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @40_439970
  edx = (u32)(EBP - 36);  // @41_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @43_439970
  ecx = edx = 0;  // @44_439970
  ebx = eax;  // @45_439970
  if ((ebx & ebx) == 0) goto L4399db;  // @46_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @47_439970
  L439a30:;
  ecx = ebx;  // @49_439970
  eax = ext_4cc130_thiscall2(ecx, (u32)(edi));  // @50_439970
  ecx = edx = 0;  // @51_439970
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L439a79;  // @52_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 175), sizeof v); (u32)v; });  // @53_439970
  if ((eax & eax) == 0) goto L439a79;  // @54_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 175), sizeof v); (u32)v; });  // @55_439970
  if ((ecx & ecx) == 0) goto L439a79;  // @56_439970
  L439a50:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @58_439970
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) goto L439a70;  // @59_439970
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L439a6c;  // @60_439970
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) & 0xff);  // @61_439970
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) goto L439a70;  // @62_439970
  eax = (eax + (u32)(2));  // @63_439970
  ecx = (ecx + (u32)(2));  // @64_439970
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L439a50;  // @65_439970
  L439a6c:;
  eax = 0;  // @67_439970
  goto L439a75;  // @68_439970
  L439a70:;
  eax = 0;  // @70_439970
  eax = (eax | (u32)(1));  // @71_439970
  L439a75:;
  if ((eax & eax) == 0) goto L439a9c;  // @73_439970
  L439a79:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4920), sizeof v); (u32)v; });  // @75_439970
  edx = (u32)(EBP - 36);  // @76_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @77_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @78_439970
  ecx = edx = 0;  // @79_439970
  ebx = eax;  // @80_439970
  if ((ebx & ebx) != 0) goto L439a30;  // @81_439970
  goto L4399de;  // @82_439970
  L439a93:;
  ebx = 0;  // @84_439970
  L439a95:;
  reg.state = (s32)((u32)(4294967295));  // @86_439970
  L439a9c:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; })) & 0xff);  // @88_439970
  ecx = ebx;  // @89_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 160), &v, sizeof v); }  // @90_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 161), sizeof v); (u32)v; });  // @91_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 161), &v, sizeof v); }  // @92_439970
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; })) & 0xff);  // @93_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 165), &v, sizeof v); }  // @94_439970
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 166), sizeof v); (u32)v; })) & 0xff);  // @95_439970
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ebx + 166), &v, sizeof v); }  // @96_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 167), sizeof v); (u32)v; });  // @97_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 167), &v, sizeof v); }  // @98_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 171), sizeof v); (u32)v; });  // @99_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 171), &v, sizeof v); }  // @100_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 175), sizeof v); (u32)v; });  // @101_439970
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 175), &v, sizeof v); }  // @102_439970
  eax = ext_4cbee0_thiscall2(ecx, (u32)(edi));  // @103_439970
  ecx = edx = 0;  // @104_439970
  esi = ebx;  // @105_439970
  eax = (u32)(edi + 128);  // @106_439970
  edx = 0;  // @107_439970
  esi = (esi - edi);  // @108_439970
  L439b04:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @110_439970
  { u32 v = (u32)((u32)(4)); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @111_439970
  if (ecx == (u32)(-1)) goto L439b20;  // @112_439970
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax), &v, sizeof v); }  // @113_439970
  edx = (edx + 1);  // @114_439970
  eax = (eax + (u32)(4));  // @115_439970
  if ((s32)edx < (s32)(u32)(4)) goto L439b04;  // @116_439970
  goto L439b38;  // @117_439970
  L439b20:;
  if ((s32)edx >= (s32)(u32)(4)) goto L439b38;  // @119_439970
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @120_439970
  edi = (u32)(edx + 32);  // @121_439970
  ecx = (ecx - edx);  // @122_439970
  edi = (u32)(ebx + edi*4);  // @123_439970
  eax = (eax | (u32)(4294967295));  // @124_439970
  while (ecx) { __builtin_memcpy((void *)(u32)edi, &eax, 4); edi += 4; ecx--; }  // @125_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @126_439970
  L439b38:;
  ecx = 0;  // @128_439970
  eax = (u32)(edi + 144);  // @129_439970
  L439b40:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @131_439970
  if (edx == (u32)(-1)) goto L439b55;  // @132_439970
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @133_439970
  ecx = (ecx + 1);  // @134_439970
  eax = (eax + (u32)(4));  // @135_439970
  if ((s32)ecx < (s32)(u32)(4)) goto L439b40;  // @136_439970
  goto L439b6c;  // @137_439970
  L439b55:;
  if ((s32)ecx >= (s32)(u32)(4)) goto L439b6c;  // @139_439970
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @140_439970
  edi = (u32)(ecx + 36);  // @141_439970
  eax = (eax - ecx);  // @142_439970
  edi = (u32)(ebx + edi*4);  // @143_439970
  ecx = eax;  // @144_439970
  eax = (eax | (u32)(4294967295));  // @145_439970
  while (ecx) { __builtin_memcpy((void *)(u32)edi, &eax, 4); edi += 4; ecx--; }  // @146_439970
  L439b6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 175), sizeof v); (u32)v; });  // @148_439970
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @149_439970
  if ((ecx & ecx) != 0) goto L439b8a;  // @150_439970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @151_439970
  ecx = ebx;  // @152_439970
  eax = ext_4cc1d0_thiscall1(ecx);  // @153_439970
  ecx = edx = 0;  // @154_439970
  ecx = edi;  // @155_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 88)))(ecx, (u32)(eax));  // @156_439970
  ecx = edx = 0;  // @157_439970
  goto L439ba7;  // @158_439970
  L439b8a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @160_439970
  ecx = edi;  // @161_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 96)))(ecx, (u32)(ecx));  // @162_439970
  ecx = edx = 0;  // @163_439970
  edi = eax;  // @164_439970
  if ((edi & edi) == 0) goto L439bb9;  // @165_439970
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @166_439970
  ecx = ebx;  // @167_439970
  eax = ext_4cc1d0_thiscall1(ecx);  // @168_439970
  ecx = edx = 0;  // @169_439970
  ecx = edi;  // @170_439970
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 16)))(ecx, (u32)(eax));  // @171_439970
  ecx = edx = 0;  // @172_439970
  L439ba7:;
  if ((eax & eax) == 0) goto L439bb9;  // @174_439970
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) != (u32)(0)) goto L439bb9;  // @175_439970
  ecx = (u32)(eax - 4);  // @176_439970
  eax = ext_439fd0_thiscall2(ecx, (u32)(ebx));  // @177_439970
  ecx = edx = 0;  // @178_439970
  L439bb9:;
  SEH_LEAVE();  // @180_439970
  return eax;  // @181_439970
}
PCREG(439970, lifted_439970);

extern "C" u32 THISCALL lifted_43ff90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66c60b);  // @h_43ff90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  ebx = ecx;  // @0_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @2_43ff90
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_43ff90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @4_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_43ff90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @6_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @7_43ff90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @8_43ff90
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; })) & 0xff);  // @9_43ff90
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @10_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_43ff90
  ecx = ebx;  // @12_43ff90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 440)))(ecx, (u32)(ecx), (u32)(edi), (u32)(esi), (u32)(edx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; }));  // @13_43ff90
  ecx = edx = 0;  // @14_43ff90
  edi = eax;  // @15_43ff90
  if ((edi & edi) == 0) goto L4401f6;  // @16_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edi));  // @20_43ff90
  ecx = edx = 0;  // @21_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @22_43ff90
  ebx = eax;  // @23_43ff90
  if ((ecx & ecx) == 0) goto L440035;  // @24_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @25_43ff90
  if ((eax & eax) == 0) goto L440035;  // @26_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_43ff90
  ecx = edi;  // @28_43ff90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(ecx), (u32)(eax));  // @29_43ff90
  ecx = edx = 0;  // @30_43ff90
  L440035:;
  ecx = (u32)(EBP - 188);  // @32_43ff90
  eax = ext_4ccba0_thiscall1(ecx);  // @33_43ff90
  ecx = edx = 0;  // @34_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @35_43ff90
  reg.state = (s32)((u32)(0));  // @36_43ff90
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @37_43ff90
  if ((edx & edx) == 0) goto L440089;  // @38_43ff90
  L440054:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edx));  // @43_43ff90
  ecx = edx = 0;  // @44_43ff90
  ecx = (u32)(EBP - 188);  // @45_43ff90
  eax = ext_4cd540_thiscall2(ecx, (u32)(eax));  // @46_43ff90
  ecx = edx = 0;  // @47_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_43ff90
  ecx = (u32)(EBP - 192);  // @49_43ff90
  ecx = edi;  // @50_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(ecx));  // @51_43ff90
  ecx = edx = 0;  // @52_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @53_43ff90
  if ((edx & edx) != 0) goto L440054;  // @54_43ff90
  L440089:;
  eax = (u32)(EBP - 212);  // @56_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @57_43ff90
  ecx = (u32)(EBP - 188);  // @58_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @59_43ff90
  ecx = edx = 0;  // @60_43ff90
  eax = (u32)(EBP - 212);  // @61_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @62_43ff90
  ecx = (u32)(EBP - 188);  // @63_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @64_43ff90
  ecx = edx = 0;  // @65_43ff90
  esi = eax;  // @66_43ff90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) == (u32)(0)) goto L4401d2;  // @67_43ff90
  L4400d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @70_43ff90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(esi));  // @72_43ff90
  ecx = edx = 0;  // @73_43ff90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @74_43ff90
  if ((eax & eax) == 0) goto L4401ad;  // @75_43ff90
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L4401ad;  // @76_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @77_43ff90
  if ((ecx & ecx) == 0) goto L44010c;  // @78_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_43ff90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @80_43ff90
  ecx = edx = 0;  // @81_43ff90
  L44010c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @84_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @86_43ff90
  ecx = edx = 0;  // @87_43ff90
  if ((eax & eax) == 0) goto L4401ad;  // @88_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @89_43ff90
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @90_43ff90
  ecx = edx = 0;  // @91_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @93_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @95_43ff90
  ecx = edx = 0;  // @96_43ff90
  if ((eax & eax) == 0) goto L4401ad;  // @97_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @98_43ff90
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @99_43ff90
  ecx = edx = 0;  // @100_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @104_43ff90
  ecx = edx = 0;  // @105_43ff90
  if ((eax & eax) == 0) goto L4401ad;  // @106_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @107_43ff90
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @108_43ff90
  ecx = edx = 0;  // @109_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @110_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @111_43ff90
  if ((ecx & ecx) == 0) goto L44019c;  // @112_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_43ff90
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @114_43ff90
  ecx = edx = 0;  // @115_43ff90
  L44019c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @117_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @120_43ff90
  ecx = edx = 0;  // @121_43ff90
  L4401ad:;
  eax = (u32)(EBP - 212);  // @123_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @124_43ff90
  ecx = (u32)(EBP - 188);  // @125_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @126_43ff90
  ecx = edx = 0;  // @127_43ff90
  esi = eax;  // @128_43ff90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) != (u32)(0)) goto L4400d0;  // @129_43ff90
  L4401d2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_43ff90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @132_43ff90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_43ff90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(ebx));  // @134_43ff90
  ecx = edx = 0;  // @135_43ff90
  eax = (0u - eax);  // @136_43ff90
  ecx = (u32)(EBP - 188);  // @137_43ff90
  esi = 0;  // @138_43ff90
  esi = (esi & edi);  // @139_43ff90
  eax = ext_4ccf60_thiscall1(ecx);  // @140_43ff90
  ecx = edx = 0;  // @141_43ff90
  eax = esi;  // @142_43ff90
  L4401f6:;
  SEH_LEAVE();  // @144_43ff90
  ext_633654(G(u32, 0x6f5630));  // @145_43ff90
  return eax;  // @146_43ff90
}
PCREG(43ff90, lifted_43ff90);

extern "C" u32 THISCALL lifted_45f090(u32 ecx_in) {
  SEH_ENTER(0x66681b);  // @h_45f090
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @4_45f090
  ecx = edx = 0;  // @5_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @6_45f090
  edi = eax;  // @7_45f090
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }) & (u32)(1048576)) == 0) goto L45f28f;  // @8_45f090
  ecx = (u32)(EBP - 188);  // @9_45f090
  eax = ext_4ccba0_thiscall1(ecx);  // @10_45f090
  ecx = edx = 0;  // @11_45f090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @12_45f090
  reg.state = (s32)((u32)(0));  // @13_45f090
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @14_45f090
  if ((edx & edx) == 0) goto L45f136;  // @15_45f090
  L45f101:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edx));  // @20_45f090
  ecx = edx = 0;  // @21_45f090
  ecx = (u32)(EBP - 188);  // @22_45f090
  eax = ext_4cd540_thiscall2(ecx, (u32)(eax));  // @23_45f090
  ecx = edx = 0;  // @24_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @25_45f090
  ecx = (u32)(EBP - 192);  // @26_45f090
  ecx = esi;  // @27_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(ecx));  // @28_45f090
  ecx = edx = 0;  // @29_45f090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @30_45f090
  if ((edx & edx) != 0) goto L45f101;  // @31_45f090
  L45f136:;
  eax = (u32)(EBP - 204);  // @33_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @34_45f090
  ecx = (u32)(EBP - 188);  // @35_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @36_45f090
  ecx = edx = 0;  // @37_45f090
  eax = (u32)(EBP - 204);  // @38_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @39_45f090
  ecx = (u32)(EBP - 188);  // @40_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @41_45f090
  ecx = edx = 0;  // @42_45f090
  esi = eax;  // @43_45f090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) == (u32)(0)) goto L45f278;  // @44_45f090
  L45f171:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @47_45f090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(esi));  // @49_45f090
  ecx = edx = 0;  // @50_45f090
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @51_45f090
  if ((eax & eax) == 0) goto L45f253;  // @52_45f090
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L45f1a9;  // @53_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @54_45f090
  if ((ecx & ecx) == 0) goto L45f1a9;  // @55_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @57_45f090
  ecx = edx = 0;  // @58_45f090
  L45f1a9:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @63_45f090
  ecx = edx = 0;  // @64_45f090
  if ((eax & eax) == 0) goto L45f253;  // @65_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @66_45f090
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @67_45f090
  ecx = edx = 0;  // @68_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @70_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @72_45f090
  ecx = edx = 0;  // @73_45f090
  if ((eax & eax) == 0) goto L45f253;  // @74_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @75_45f090
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @76_45f090
  ecx = edx = 0;  // @77_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @81_45f090
  ecx = edx = 0;  // @82_45f090
  if ((eax & eax) == 0) goto L45f253;  // @83_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @84_45f090
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L45f242;  // @85_45f090
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @86_45f090
  ecx = edx = 0;  // @87_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @88_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @89_45f090
  if ((ecx & ecx) == 0) goto L45f242;  // @90_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @92_45f090
  ecx = edx = 0;  // @93_45f090
  L45f242:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @95_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @96_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @98_45f090
  ecx = edx = 0;  // @99_45f090
  L45f253:;
  eax = (u32)(EBP - 204);  // @101_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @102_45f090
  ecx = (u32)(EBP - 188);  // @103_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @104_45f090
  ecx = edx = 0;  // @105_45f090
  esi = eax;  // @106_45f090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) != (u32)(0)) goto L45f171;  // @107_45f090
  L45f278:;
  ecx = (u32)(EBP - 188);  // @109_45f090
  reg.state = (s32)((u32)(4294967295));  // @110_45f090
  eax = ext_4ccf60_thiscall1(ecx);  // @111_45f090
  ecx = edx = 0;  // @112_45f090
  goto L45f331;  // @113_45f090
  L45f28f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @115_45f090
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L45f2a5;  // @116_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_45f090
  ecx = esi;  // @118_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @119_45f090
  ecx = edx = 0;  // @120_45f090
  L45f2a5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @122_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @123_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edi));  // @125_45f090
  ecx = edx = 0;  // @126_45f090
  if ((eax & eax) != 0) goto L45f2c1;  // @127_45f090
  L45f2ba:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @129_45f090
  goto L45f347;  // @130_45f090
  L45f2c1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_45f090
  ecx = esi;  // @133_45f090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @134_45f090
  ecx = edx = 0;  // @135_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @137_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edi));  // @139_45f090
  ecx = edx = 0;  // @140_45f090
  if ((eax & eax) == 0) goto L45f2ba;  // @141_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_45f090
  ecx = esi;  // @143_45f090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @144_45f090
  ecx = edx = 0;  // @145_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @146_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @147_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @148_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(edi));  // @149_45f090
  ecx = edx = 0;  // @150_45f090
  if ((eax & eax) == 0) goto L45f2ba;  // @151_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @152_45f090
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L45f331;  // @153_45f090
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @154_45f090
  ecx = edx = 0;  // @155_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @156_45f090
  ecx = esi;  // @157_45f090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @158_45f090
  ecx = edx = 0;  // @159_45f090
  L45f331:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @161_45f090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @162_45f090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @163_45f090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(edi));  // @164_45f090
  ecx = edx = 0;  // @165_45f090
  eax = (eax & 0xffffff00u) | (((u32)((eax & eax) != 0)) & 0xff);  // @166_45f090
  L45f347:;
  SEH_LEAVE();  // @168_45f090
  ext_633654(G(u32, 0x6f5630));  // @169_45f090
  return eax;  // @170_45f090
}
PCREG(45f090, lifted_45f090);

extern "C" u32 THISCALL lifted_598a50(u32 ecx_in) {
  SEH_ENTER(0x66bb8c);  // @h_598a50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_598a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8919), sizeof v); (u32)v; });  // @1_598a50
  { u32 v = (u32)((u32)(7001516)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_598a50
  if ((edi & edi) == 0) goto L598a9a;  // @3_598a50
  ecx = edi;  // @4_598a50
  eax = ext_5eaaf0_thiscall1(ecx);  // @5_598a50
  ecx = edx = 0;  // @6_598a50
  eax = ext_634273_cdecl2((u32)(edi), (u32)(76));  // @7_598a50
  ecx = edx = 0;  // @8_598a50
  L598a9a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @10_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 117), sizeof v); (u32)v; }));  // @12_598a50
  ecx = edx = 0;  // @13_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 117), sizeof v); (u32)v; });  // @14_598a50
  if ((ecx & ecx) == 0) goto L598ab8;  // @15_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @17_598a50
  ecx = edx = 0;  // @18_598a50
  L598ab8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @20_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }));  // @22_598a50
  ecx = edx = 0;  // @23_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });  // @24_598a50
  if ((ecx & ecx) == 0) goto L598ad6;  // @25_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @27_598a50
  ecx = edx = 0;  // @28_598a50
  L598ad6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }));  // @32_598a50
  ecx = edx = 0;  // @33_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; });  // @34_598a50
  if ((ecx & ecx) == 0) goto L598af4;  // @35_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @37_598a50
  ecx = edx = 0;  // @38_598a50
  L598af4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }));  // @42_598a50
  ecx = edx = 0;  // @43_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; });  // @44_598a50
  if ((ecx & ecx) == 0) goto L598b12;  // @45_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @47_598a50
  ecx = edx = 0;  // @48_598a50
  L598b12:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @50_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; }));  // @52_598a50
  ecx = edx = 0;  // @53_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 113), sizeof v); (u32)v; });  // @54_598a50
  if ((ecx & ecx) == 0) goto L598b30;  // @55_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @57_598a50
  ecx = edx = 0;  // @58_598a50
  L598b30:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 121), sizeof v); (u32)v; }));  // @62_598a50
  ecx = edx = 0;  // @63_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 121), sizeof v); (u32)v; });  // @64_598a50
  if ((ecx & ecx) == 0) goto L598b4e;  // @65_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @67_598a50
  ecx = edx = 0;  // @68_598a50
  L598b4e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 125), sizeof v); (u32)v; }));  // @72_598a50
  ecx = edx = 0;  // @73_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 125), sizeof v); (u32)v; });  // @74_598a50
  if ((ecx & ecx) == 0) goto L598b6c;  // @75_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @77_598a50
  ecx = edx = 0;  // @78_598a50
  L598b6c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @80_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 424)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 129), sizeof v); (u32)v; }));  // @82_598a50
  ecx = edx = 0;  // @83_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 129), sizeof v); (u32)v; });  // @84_598a50
  if ((ecx & ecx) == 0) goto L598b90;  // @85_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @87_598a50
  ecx = edx = 0;  // @88_598a50
  L598b90:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7586), sizeof v); (u32)v; });  // @90_598a50
  ebx = (u32)(esi + 7586);  // @91_598a50
  if (edi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; })) goto L598c3e;  // @92_598a50
  L598ba8:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @94_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @95_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @96_598a50
  if ((eax & eax) == 0) goto L598bc8;  // @97_598a50
  ecx = eax;  // @98_598a50
  eax = ext_4690b0_cdecl0();  // @99_598a50
  ecx = edx = 0;  // @100_598a50
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(16));  // @101_598a50
  ecx = edx = 0;  // @102_598a50
  L598bc8:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 12), sizeof v); (u32)v; });  // @104_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @105_598a50
  if ((eax & eax) == 0) goto L598be6;  // @106_598a50
  ecx = eax;  // @107_598a50
  eax = ext_4690b0_cdecl0();  // @108_598a50
  ecx = edx = 0;  // @109_598a50
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(41));  // @110_598a50
  ecx = edx = 0;  // @111_598a50
  L598be6:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @113_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @114_598a50
  if ((eax & eax) == 0) goto L598c04;  // @115_598a50
  ecx = eax;  // @116_598a50
  eax = ext_4690b0_cdecl0();  // @117_598a50
  ecx = edx = 0;  // @118_598a50
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }), (u32)(41));  // @119_598a50
  ecx = edx = 0;  // @120_598a50
  L598c04:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @122_598a50
  if ((ebx & ebx) == 0) goto L598c1d;  // @123_598a50
  ecx = ebx;  // @124_598a50
  eax = ext_4690b0_cdecl0();  // @125_598a50
  ecx = edx = 0;  // @126_598a50
  eax = ext_634273_cdecl2((u32)(ebx), (u32)(41));  // @127_598a50
  ecx = edx = 0;  // @128_598a50
  L598c1d:;
  eax = ext_634273_cdecl2(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }), (u32)(28));  // @130_598a50
  ecx = edx = 0;  // @131_598a50
  edi = (edi + (u32)(4));  // @132_598a50
  if (edi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 7590), sizeof v); (u32)v; })) goto L598ba8;  // @133_598a50
  ebx = (u32)(esi + 7586);  // @134_598a50
  L598c3e:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @136_598a50
  edx = edi;  // @137_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @138_598a50
  edx = (edx - edi);  // @139_598a50
  edx = (u32)((s32)edx >> (u32)(2));  // @140_598a50
  ecx = eax;  // @141_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @142_598a50
  if ((s32)(edx & edx) <= 0) goto L598c6e;  // @143_598a50
  ebx = edi;  // @144_598a50
  ebx = (ebx - eax);  // @145_598a50
  L598c57:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + ecx), sizeof v); (u32)v; });  // @147_598a50
  ecx = (u32)(ecx + 4);  // @148_598a50
  edx = (edx - 1);  // @149_598a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @150_598a50
  if ((s32)(edx & edx) > 0) goto L598c57;  // @151_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @152_598a50
  ebx = (u32)(esi + 7586);  // @153_598a50
  L598c6e:;
  edi = (edi - eax);  // @155_598a50
  edi = (u32)((s32)edi >> (u32)(2));  // @156_598a50
  edi = (0u - edi);  // @157_598a50
  edi = (edi << (u32)(2));  // @158_598a50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + edi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @159_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @160_598a50
  if ((ecx & ecx) == 0) goto L598c88;  // @161_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @162_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @163_598a50
  ecx = edx = 0;  // @164_598a50
  L598c88:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @166_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @167_598a50
  eax = (eax - ecx);  // @168_598a50
  eax = (u32)((s32)eax >> (u32)(2));  // @169_598a50
  reg.state = (s32)((u32)(0));  // @170_598a50
  if ((eax & eax) == 0) goto L598ca9;  // @171_598a50
  eax = (eax << (u32)(2));  // @172_598a50
  ecx = ebx;  // @173_598a50
  eax = ext_54f870_stdcall2((u32)(ecx), (u32)(eax));  // @174_598a50
  ecx = edx = 0;  // @175_598a50
  L598ca9:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @177_598a50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @178_598a50
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @179_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @180_598a50
  reg.state = (s32)((u32)(1));  // @181_598a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @182_598a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @183_598a50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));  // @184_598a50
  ecx = edx = 0;  // @185_598a50
  SEH_LEAVE();  // @186_598a50
  return eax;  // @187_598a50
}
PCREG(598a50, lifted_598a50);

extern "C" u32 THISCALL lifted_5c6cb0(u32 ecx_in) {
  SEH_ENTER(0x66c6f6);  // @h_5c6cb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5c6cb0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_5c6cb0
  ecx = edx = 0;  // @5_5c6cb0
  ecx = (u32)(EBP - 148);  // @6_5c6cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @7_5c6cb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_5c6cb0
  ecx = eax;  // @9_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6970440), (u32)(ecx));  // @10_5c6cb0
  ecx = edx = 0;  // @11_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @13_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @15_5c6cb0
  ecx = edx = 0;  // @16_5c6cb0
  edi = eax;  // @17_5c6cb0
  if ((edi & edi) == 0) goto L5c6f23;  // @18_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @19_5c6cb0
  eax = (u32)(EBP - 160);  // @20_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_5c6cb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @22_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @23_5c6cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @24_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @25_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6970472), (u32)(0), (u32)(7030208), (u32)(812), (u32)(eax), (u32)(0));  // @27_5c6cb0
  ecx = edx = 0;  // @28_5c6cb0
  eax = (eax & 0xffff);  // @29_5c6cb0
  ecx = edi;  // @30_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, (u32)(eax));  // @31_5c6cb0
  ecx = edx = 0;  // @32_5c6cb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; }) == (u32)(0)) goto L5c6f23;  // @33_5c6cb0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 84), &v, sizeof v); }  // @34_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @38_5c6cb0
  ecx = edx = 0;  // @39_5c6cb0
  esi = eax;  // @40_5c6cb0
  if ((esi & esi) == 0) goto L5c6e22;  // @41_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @42_5c6cb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }) == (u32)(134217754)) goto L5c6e13;  // @43_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @44_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7030208), (u32)(819));  // @46_5c6cb0
  ecx = edx = 0;  // @47_5c6cb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_5c6cb0
  edi = eax;  // @49_5c6cb0
  eax = (u32)(EBP - 144);  // @50_5c6cb0
  ecx = esi;  // @51_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @52_5c6cb0
  ecx = edx = 0;  // @53_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @54_5c6cb0
  ecx = eax;  // @55_5c6cb0
  reg.state = (s32)((u32)(0));  // @56_5c6cb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @57_5c6cb0
  ecx = edx = 0;  // @58_5c6cb0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(7030636), (u32)(eax));  // @59_5c6cb0
  ecx = edx = 0;  // @60_5c6cb0
  reg.state = (s32)((u32)(4294967295));  // @61_5c6cb0
  ecx = (u32)(EBP - 144);  // @62_5c6cb0
  eax = ext_4cbec0_thiscall1(ecx);  // @63_5c6cb0
  ecx = edx = 0;  // @64_5c6cb0
  goto L5c6e22;  // @65_5c6cb0
  L5c6e13:;
  eax = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; });  // @67_5c6cb0
  ecx = ebx;  // @68_5c6cb0
  eax = ext_5c6370_stdcall2((u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }));  // @69_5c6cb0
  ecx = edx = 0;  // @70_5c6cb0
  L5c6e22:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @73_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 76), sizeof v); (u32)v; }));  // @75_5c6cb0
  ecx = edx = 0;  // @76_5c6cb0
  esi = eax;  // @77_5c6cb0
  if ((esi & esi) == 0) goto L5c6eb7;  // @78_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @79_5c6cb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 35), sizeof v); (u32)v; }) == (u32)(134217754)) goto L5c6ea2;  // @80_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @81_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(7030208), (u32)(827));  // @83_5c6cb0
  ecx = edx = 0;  // @84_5c6cb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_5c6cb0
  edi = eax;  // @86_5c6cb0
  eax = (u32)(EBP - 144);  // @87_5c6cb0
  ecx = esi;  // @88_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @89_5c6cb0
  ecx = edx = 0;  // @90_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @91_5c6cb0
  ecx = eax;  // @92_5c6cb0
  reg.state = (s32)((u32)(1));  // @93_5c6cb0
  eax = ext_4cc1d0_thiscall1(ecx);  // @94_5c6cb0
  ecx = edx = 0;  // @95_5c6cb0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(7030636), (u32)(eax));  // @96_5c6cb0
  ecx = edx = 0;  // @97_5c6cb0
  reg.state = (s32)((u32)(4294967295));  // @98_5c6cb0
  ecx = (u32)(EBP - 144);  // @99_5c6cb0
  eax = ext_4cbec0_thiscall1(ecx);  // @100_5c6cb0
  ecx = edx = 0;  // @101_5c6cb0
  goto L5c6eb7;  // @102_5c6cb0
  L5c6ea2:;
  ecx = ebx;  // @104_5c6cb0
  eax = (eax & 0xffffff00u) | (((u32)(({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 84), sizeof v); (u32)v; }) == (u32)(0))) & 0xff);  // @105_5c6cb0
  eax = (eax & 0xff);  // @106_5c6cb0
  eax = ext_5c6370_stdcall2((u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }));  // @107_5c6cb0
  ecx = edx = 0;  // @108_5c6cb0
  L5c6eb7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @110_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @111_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @112_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6840132), (u32)(0));  // @114_5c6cb0
  ecx = edx = 0;  // @115_5c6cb0
  edi = eax;  // @116_5c6cb0
  if ((edi & edi) == 0) goto L5c6f23;  // @117_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_5c6cb0
  eax = (u32)(EBP - 152);  // @119_5c6cb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @120_5c6cb0
  { u32 v = (u32)((u32)(1056964608)); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @121_5c6cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @122_5c6cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @123_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6882516), (u32)(0), (u32)(7030208), (u32)(836), (u32)(eax), (u32)(0));  // @124_5c6cb0
  ecx = edx = 0;  // @125_5c6cb0
  eax = (eax & 0xffff);  // @126_5c6cb0
  ecx = edi;  // @127_5c6cb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 296)))(ecx, (u32)(eax));  // @128_5c6cb0
  ecx = edx = 0;  // @129_5c6cb0
  L5c6f23:;
  SEH_LEAVE();  // @131_5c6cb0
  ext_633654(G(u32, 0x6f5630));  // @132_5c6cb0
  return eax;  // @133_5c6cb0
}
PCREG(5c6cb0, lifted_5c6cb0);

extern "C" u32 THISCALL lifted_4402a0(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  SEH_ENTER(0x66c60b);  // @h_4402a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  __builtin_memcpy(F + 0x300 + 32, &a6, 4);
  ebx = ecx;  // @0_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @1_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @2_4402a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @3_4402a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_4402a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 196), &v, sizeof v); }  // @6_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @7_4402a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 200), &v, sizeof v); }  // @8_4402a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 32), sizeof v); (u32)v; })) & 0xff);  // @9_4402a0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @10_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @11_4402a0
  ecx = ebx;  // @12_4402a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 448)))(ecx, (u32)(ecx), (u32)(edi), (u32)(esi), (u32)(edx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; }));  // @13_4402a0
  ecx = edx = 0;  // @14_4402a0
  edi = eax;  // @15_4402a0
  if ((edi & edi) == 0) goto L440506;  // @16_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edi));  // @20_4402a0
  ecx = edx = 0;  // @21_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 196), sizeof v); (u32)v; });  // @22_4402a0
  ebx = eax;  // @23_4402a0
  if ((ecx & ecx) == 0) goto L440345;  // @24_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; });  // @25_4402a0
  if ((eax & eax) == 0) goto L440345;  // @26_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_4402a0
  ecx = edi;  // @28_4402a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(ecx), (u32)(eax));  // @29_4402a0
  ecx = edx = 0;  // @30_4402a0
  L440345:;
  ecx = (u32)(EBP - 188);  // @32_4402a0
  eax = ext_4ccba0_thiscall1(ecx);  // @33_4402a0
  ecx = edx = 0;  // @34_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @35_4402a0
  reg.state = (s32)((u32)(0));  // @36_4402a0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @37_4402a0
  if ((edx & edx) == 0) goto L440399;  // @38_4402a0
  L440364:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @41_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edx));  // @43_4402a0
  ecx = edx = 0;  // @44_4402a0
  ecx = (u32)(EBP - 188);  // @45_4402a0
  eax = ext_4cd540_thiscall2(ecx, (u32)(eax));  // @46_4402a0
  ecx = edx = 0;  // @47_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @48_4402a0
  ecx = (u32)(EBP - 192);  // @49_4402a0
  ecx = edi;  // @50_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(ecx));  // @51_4402a0
  ecx = edx = 0;  // @52_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @53_4402a0
  if ((edx & edx) != 0) goto L440364;  // @54_4402a0
  L440399:;
  eax = (u32)(EBP - 212);  // @56_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @57_4402a0
  ecx = (u32)(EBP - 188);  // @58_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @59_4402a0
  ecx = edx = 0;  // @60_4402a0
  eax = (u32)(EBP - 212);  // @61_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @62_4402a0
  ecx = (u32)(EBP - 188);  // @63_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @64_4402a0
  ecx = edx = 0;  // @65_4402a0
  esi = eax;  // @66_4402a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) == (u32)(0)) goto L4404e2;  // @67_4402a0
  L4403e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @69_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @70_4402a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(esi));  // @72_4402a0
  ecx = edx = 0;  // @73_4402a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @74_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @75_4402a0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L4404bd;  // @76_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @77_4402a0
  if ((ecx & ecx) == 0) goto L44041c;  // @78_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_4402a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @80_4402a0
  ecx = edx = 0;  // @81_4402a0
  L44041c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @83_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @84_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @86_4402a0
  ecx = edx = 0;  // @87_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @88_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @89_4402a0
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @90_4402a0
  ecx = edx = 0;  // @91_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @93_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @95_4402a0
  ecx = edx = 0;  // @96_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @97_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @98_4402a0
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @99_4402a0
  ecx = edx = 0;  // @100_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @101_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @102_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @104_4402a0
  ecx = edx = 0;  // @105_4402a0
  if ((eax & eax) == 0) goto L4404bd;  // @106_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @107_4402a0
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @108_4402a0
  ecx = edx = 0;  // @109_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @110_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @111_4402a0
  if ((ecx & ecx) == 0) goto L4404ac;  // @112_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @113_4402a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @114_4402a0
  ecx = edx = 0;  // @115_4402a0
  L4404ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @117_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @120_4402a0
  ecx = edx = 0;  // @121_4402a0
  L4404bd:;
  eax = (u32)(EBP - 212);  // @123_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @124_4402a0
  ecx = (u32)(EBP - 188);  // @125_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @126_4402a0
  ecx = edx = 0;  // @127_4402a0
  esi = eax;  // @128_4402a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 212), sizeof v); (u32)v; }) != (u32)(0)) goto L4403e0;  // @129_4402a0
  L4404e2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @131_4402a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @132_4402a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @133_4402a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(ebx));  // @134_4402a0
  ecx = edx = 0;  // @135_4402a0
  eax = (0u - eax);  // @136_4402a0
  ecx = (u32)(EBP - 188);  // @137_4402a0
  esi = 0;  // @138_4402a0
  esi = (esi & edi);  // @139_4402a0
  eax = ext_4ccf60_thiscall1(ecx);  // @140_4402a0
  ecx = edx = 0;  // @141_4402a0
  eax = esi;  // @142_4402a0
  L440506:;
  SEH_LEAVE();  // @144_4402a0
  ext_633654(G(u32, 0x6f5630));  // @145_4402a0
  return eax;  // @146_4402a0
}
PCREG(4402a0, lifted_4402a0);

extern "C" u32 THISCALL lifted_5b6e20(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66c39e);  // @h_5b6e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 40), &v, sizeof v); }  // @1_5b6e20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @2_5b6e20
  eax = ext_5b6d00_thiscall1(ecx);  // @3_5b6e20
  ecx = edx = 0;  // @4_5b6e20
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_5b6e20
  ecx = (u32)(EBP - 24);  // @6_5b6e20
  ecx = esi;  // @7_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @8_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @9_5b6e20
  ecx = edx = 0;  // @10_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @11_5b6e20
  if ((eax & eax) == 0) goto L5b7078;  // @12_5b6e20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @13_5b6e20
  if ((s32)(eax & eax) <= 0) goto L5b7078;  // @14_5b6e20
  L5b6e80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_5b6e20
  ecx = (u32)(EBP - 28);  // @17_5b6e20
  ecx = esi;  // @18_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @19_5b6e20
  ecx = edx = 0;  // @20_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; });  // @21_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @23_5b6e20
  ecx = edx = 0;  // @24_5b6e20
  edi = eax;  // @25_5b6e20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @26_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @27_5b6e20
  ecx = edx = 0;  // @28_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 44), &v, sizeof v); }  // @29_5b6e20
  reg.state = (s32)((u32)(0));  // @30_5b6e20
  if ((eax & eax) == 0) goto L5b6ec2;  // @31_5b6e20
  ecx = eax;  // @32_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(29));  // @33_5b6e20
  ecx = edx = 0;  // @34_5b6e20
  goto L5b6ec4;  // @35_5b6e20
  L5b6ec2:;
  eax = 0;  // @37_5b6e20
  L5b6ec4:;
  reg.state = (s32)((u32)(4294967295));  // @39_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @40_5b6e20
  eax = ext_41e290_cdecl1((u32)(28));  // @41_5b6e20
  ecx = edx = 0;  // @42_5b6e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 48), &v, sizeof v); }  // @43_5b6e20
  reg.state = (s32)((u32)(1));  // @44_5b6e20
  if ((eax & eax) == 0) goto L5b6ef2;  // @45_5b6e20
  ecx = eax;  // @46_5b6e20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(12), (u32)(32));  // @47_5b6e20
  ecx = edx = 0;  // @48_5b6e20
  goto L5b6ef4;  // @49_5b6e20
  L5b6ef2:;
  eax = 0;  // @51_5b6e20
  L5b6ef4:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @53_5b6e20
  ecx = esi;  // @54_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_5b6e20
  eax = (u32)(edi + 56);  // @56_5b6e20
  reg.state = (s32)((u32)(4294967295));  // @57_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @58_5b6e20
  ecx = edx = 0;  // @59_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_5b6e20
  eax = (u32)(edi + 96);  // @61_5b6e20
  ecx = esi;  // @62_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(36));  // @63_5b6e20
  ecx = edx = 0;  // @64_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_5b6e20
  eax = (u32)(edi + 72);  // @66_5b6e20
  ecx = esi;  // @67_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @68_5b6e20
  ecx = edx = 0;  // @69_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_5b6e20
  eax = (u32)(edi + 84);  // @71_5b6e20
  ecx = esi;  // @72_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @73_5b6e20
  ecx = edx = 0;  // @74_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @75_5b6e20
  eax = (u32)(edi + 60);  // @76_5b6e20
  ecx = esi;  // @77_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @78_5b6e20
  ecx = edx = 0;  // @79_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @80_5b6e20
  eax = (u32)(edi + 8);  // @81_5b6e20
  ecx = esi;  // @82_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(48));  // @83_5b6e20
  ecx = edx = 0;  // @84_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @85_5b6e20
  eax = (u32)(edi + 132);  // @86_5b6e20
  ecx = esi;  // @87_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @88_5b6e20
  ecx = edx = 0;  // @89_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @90_5b6e20
  eax = (u32)(edi + 136);  // @91_5b6e20
  ecx = esi;  // @92_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @93_5b6e20
  ecx = edx = 0;  // @94_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @95_5b6e20
  eax = (u32)(edi + 140);  // @96_5b6e20
  ecx = esi;  // @97_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(1));  // @98_5b6e20
  ecx = edx = 0;  // @99_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @100_5b6e20
  ecx = (u32)(EBP + 8);  // @101_5b6e20
  ecx = esi;  // @102_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @103_5b6e20
  ecx = edx = 0;  // @104_5b6e20
  ebx = 0;  // @105_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b6ffd;  // @106_5b6e20
  L5b6f90:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @108_5b6e20
  ecx = (u32)(EBP - 32);  // @109_5b6e20
  ecx = esi;  // @110_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @111_5b6e20
  ecx = edx = 0;  // @112_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @113_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }));  // @115_5b6e20
  ecx = edx = 0;  // @116_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_5b6e20
  edi = eax;  // @118_5b6e20
  ecx = esi;  // @119_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(edi), (u32)(4));  // @120_5b6e20
  ecx = edx = 0;  // @121_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @122_5b6e20
  ecx = (u32)(edi + 4);  // @123_5b6e20
  ecx = esi;  // @124_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(ecx), (u32)(4));  // @125_5b6e20
  ecx = edx = 0;  // @126_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @127_5b6e20
  eax = (u32)(edi + 8);  // @128_5b6e20
  ecx = esi;  // @129_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @130_5b6e20
  ecx = edx = 0;  // @131_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @132_5b6e20
  eax = (u32)(edi + 12);  // @133_5b6e20
  ecx = esi;  // @134_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(1));  // @135_5b6e20
  ecx = edx = 0;  // @136_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_5b6e20
  eax = (u32)(edi + 13);  // @138_5b6e20
  ecx = esi;  // @139_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @140_5b6e20
  ecx = edx = 0;  // @141_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_5b6e20
  eax = (u32)(edi + 17);  // @143_5b6e20
  ecx = esi;  // @144_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @145_5b6e20
  ecx = edx = 0;  // @146_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @147_5b6e20
  ebx = (ebx + 1);  // @148_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b6f90;  // @149_5b6e20
  L5b6ffd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_5b6e20
  ecx = (u32)(EBP + 8);  // @152_5b6e20
  ecx = esi;  // @153_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @154_5b6e20
  ecx = edx = 0;  // @155_5b6e20
  ebx = 0;  // @156_5b6e20
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) <= (s32)ebx) goto L5b7065;  // @157_5b6e20
  L5b7011:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @159_5b6e20
  ecx = (u32)(EBP - 36);  // @160_5b6e20
  ecx = esi;  // @161_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 24)))(ecx, (u32)(ecx), (u32)(4));  // @162_5b6e20
  ecx = edx = 0;  // @163_5b6e20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @164_5b6e20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @165_5b6e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 36), sizeof v); (u32)v; }));  // @166_5b6e20
  ecx = edx = 0;  // @167_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_5b6e20
  edi = eax;  // @169_5b6e20
  ecx = esi;  // @170_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(edi), (u32)(12));  // @171_5b6e20
  ecx = edx = 0;  // @172_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @173_5b6e20
  ecx = (u32)(edi + 12);  // @174_5b6e20
  ecx = esi;  // @175_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(ecx), (u32)(12));  // @176_5b6e20
  ecx = edx = 0;  // @177_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @178_5b6e20
  eax = (u32)(edi + 28);  // @179_5b6e20
  ecx = esi;  // @180_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @181_5b6e20
  ecx = edx = 0;  // @182_5b6e20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @183_5b6e20
  eax = (u32)(edi + 24);  // @184_5b6e20
  ecx = esi;  // @185_5b6e20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(4));  // @186_5b6e20
  ecx = edx = 0;  // @187_5b6e20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @188_5b6e20
  ebx = (ebx + 1);  // @189_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L5b7011;  // @190_5b6e20
  L5b7065:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @192_5b6e20
  ebx = (ebx + 1);  // @193_5b6e20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @194_5b6e20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 40), sizeof v); (u32)v; });  // @195_5b6e20
  if ((s32)ebx < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5b6e80;  // @196_5b6e20
  L5b7078:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @198_5b6e20
  SEH_LEAVE();  // @199_5b6e20
  return eax;  // @200_5b6e20
}
PCREG(5b6e20, lifted_5b6e20);

extern "C" u32 THISCALL lifted_45f430(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x666866);  // @h_45f430
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_45f430
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 532), &v, sizeof v); }  // @1_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @2_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_45f430
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 272), &v, sizeof v); }  // @4_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 536), &v, sizeof v); }  // @5_45f430
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(262144)) == 0) goto L45f4a9;  // @6_45f430
  ecx = (u32)(EBP - 272);  // @7_45f430
  ecx = (ecx - 1);  // @8_45f430
  L45f490:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @10_45f430
  ecx = (u32)(ecx + 1);  // @11_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f490;  // @12_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836280), sizeof v); (u32)v; });  // @13_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @14_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836284), sizeof v); (u32)v; });  // @15_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @16_45f430
  L45f4a9:;
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 60), sizeof v); (u32)v; }) & (u32)(16384)) == 0) goto L45f5c3;  // @18_45f430
  edx = (u32)(EBP - 272);  // @19_45f430
  edx = (edx - 1);  // @20_45f430
  L45f4c0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + 1), sizeof v); (u32)v; })) & 0xff);  // @22_45f430
  edx = (u32)(edx + 1);  // @23_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f4c0;  // @24_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802596), sizeof v); (u32)v; });  // @25_45f430
  ecx = esi;  // @26_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @27_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802600), sizeof v); (u32)v; });  // @28_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @29_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802604), sizeof v); (u32)v; });  // @30_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @31_45f430
  eax = ext_4db550_thiscall1(ecx);  // @32_45f430
  ecx = edx = 0;  // @33_45f430
  ecx = eax;  // @34_45f430
  if ((ecx & ecx) == 0) goto L45f599;  // @35_45f430
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }) == (u32)(0)) goto L45f599;  // @36_45f430
  edi = (u32)(EBP - 272);  // @37_45f430
  edi = (edi - 1);  // @38_45f430
  L45f503:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @40_45f430
  edi = (u32)(edi + 1);  // @41_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f503;  // @42_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6802608), sizeof v); (u32)v; })) & 0xffff);  // @43_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @44_45f430
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; }) <= (u32)(0)) goto L45f520;  // @45_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_45f430
  goto L45f522;  // @47_45f430
  L45f520:;
  ecx = 0;  // @49_45f430
  L45f522:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_45f430
  edx = (u32)(EBP - 400);  // @52_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, (u32)(edx), (u32)(1));  // @53_45f430
  ecx = edx = 0;  // @54_45f430
  ecx = eax;  // @55_45f430
  reg.state = (s32)((u32)(0));  // @56_45f430
  eax = ext_4cc1d0_thiscall1(ecx);  // @57_45f430
  ecx = edx = 0;  // @58_45f430
  edx = eax;  // @59_45f430
  esi = eax;  // @60_45f430
  L45f545:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @62_45f430
  edx = (edx + 1);  // @63_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f545;  // @64_45f430
  edi = (u32)(EBP - 272);  // @65_45f430
  edx = (edx - esi);  // @66_45f430
  edi = (edi - 1);  // @67_45f430
  L45f555:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @69_45f430
  edi = (edi + 1);  // @70_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f555;  // @71_45f430
  ecx = edx;  // @72_45f430
  reg.state = (s32)((u32)(4294967295));  // @73_45f430
  ecx = (ecx >> (u32)(2));  // @74_45f430
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 4); esi += 4; edi += 4; ecx--; }  // @75_45f430
  ecx = edx;  // @76_45f430
  ecx = (ecx & (u32)(3));  // @77_45f430
  while (ecx) { __builtin_memcpy((void *)(u32)edi, (void *)(u32)esi, 1); esi += 1; edi += 1; ecx--; }  // @78_45f430
  ecx = (u32)(EBP - 400);  // @79_45f430
  eax = ext_4cbec0_thiscall1(ecx);  // @80_45f430
  ecx = edx = 0;  // @81_45f430
  edi = (u32)(EBP - 272);  // @82_45f430
  edi = (edi - 1);  // @83_45f430
  L45f584:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @85_45f430
  edi = (u32)(edi + 1);  // @86_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f584;  // @87_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6802612), sizeof v); (u32)v; })) & 0xffff);  // @88_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @89_45f430
  goto L45f5c3;  // @90_45f430
  L45f599:;
  ecx = (u32)(EBP - 272);  // @92_45f430
  ecx = (ecx - 1);  // @93_45f430
  L45f5a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @95_45f430
  ecx = (u32)(ecx + 1);  // @96_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f5a0;  // @97_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802616), sizeof v); (u32)v; });  // @98_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @99_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6802620), sizeof v); (u32)v; });  // @100_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @101_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6802624), sizeof v); (u32)v; })) & 0xffff);  // @102_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @103_45f430
  L45f5c3:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @105_45f430
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; }) & (u32)(2048)) == 0) goto L45f5f9;  // @106_45f430
  ecx = (u32)(EBP - 272);  // @107_45f430
  ecx = (ecx - 1);  // @108_45f430
  L45f5d6:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @110_45f430
  ecx = (u32)(ecx + 1);  // @111_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f5d6;  // @112_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836288), sizeof v); (u32)v; });  // @113_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @114_45f430
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6836292), sizeof v); (u32)v; })) & 0xffff);  // @115_45f430
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @116_45f430
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6836294), sizeof v); (u32)v; })) & 0xff);  // @117_45f430
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 6), &v, sizeof v); }  // @118_45f430
  L45f5f9:;
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; }) & (u32)(1024)) == 0) goto L45f631;  // @120_45f430
  ecx = (u32)(EBP - 272);  // @121_45f430
  ecx = (ecx - 1);  // @122_45f430
  L45f610:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @124_45f430
  ecx = (u32)(ecx + 1);  // @125_45f430
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45f610;  // @126_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836296), sizeof v); (u32)v; });  // @127_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @128_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6836300), sizeof v); (u32)v; });  // @129_45f430
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @130_45f430
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(6836304), sizeof v); (u32)v; })) & 0xff);  // @131_45f430
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @132_45f430
  L45f631:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @134_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @135_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(535));  // @136_45f430
  ecx = edx = 0;  // @137_45f430
  ebx = eax;  // @138_45f430
  edx = (u32)(6801640);  // @139_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @140_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @141_45f430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @142_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @143_45f430
  edi = (edi + (u32)(36));  // @144_45f430
  if ((ecx & ecx) != 0) edx = ecx;  // @145_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @146_45f430
  eax = (u32)(EBP - 272);  // @147_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @148_45f430
  eax = ext_4cc5a0_cdecl4(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }), (u32)(edx), (u32)(edi), (u32)(eax));  // @149_45f430
  ecx = edx = 0;  // @150_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(ebx), (u32)(6802628), (u32)(eax));  // @151_45f430
  ecx = edx = 0;  // @152_45f430
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) <= (s32)(u32)(0)) goto L45f796;  // @153_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @154_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @155_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23861), sizeof v); (u32)v; });  // @156_45f430
  if ((ecx & ecx) == 0) goto L45f796;  // @157_45f430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @158_45f430
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @159_45f430
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; }) == (u32)(0)) goto L45f796;  // @160_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @161_45f430
  edx = (u32)(EBP - 532);  // @162_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 104), sizeof v); (u32)v; }));  // @163_45f430
  ecx = edx = 0;  // @164_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; });  // @165_45f430
  esi = eax;  // @166_45f430
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 540), &v, sizeof v); }  // @167_45f430
  if ((ecx & ecx) == 0) goto L45f765;  // @168_45f430
  ebx = 0;  // @169_45f430
  if ((ecx & ecx) == 0) goto L45f796;  // @170_45f430
  L45f6f0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @172_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @173_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(548));  // @174_45f430
  ecx = edx = 0;  // @175_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + ebx*4), sizeof v); (u32)v; });  // @176_45f430
  edi = eax;  // @177_45f430
  eax = (u32)(EBP - 528);  // @178_45f430
  eax = ext_4da2f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @179_45f430
  ecx = edx = 0;  // @180_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @181_45f430
  ecx = eax;  // @182_45f430
  reg.state = (s32)((u32)(1));  // @183_45f430
  eax = ext_4cc1d0_thiscall1(ecx);  // @184_45f430
  ecx = edx = 0;  // @185_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @186_45f430
  eax = ext_4cc5a0_cdecl2((u32)(ebx), (u32)(eax));  // @187_45f430
  ecx = edx = 0;  // @188_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))(ecx, (u32)(edi), (u32)(6836348), (u32)(eax));  // @189_45f430
  ecx = edx = 0;  // @190_45f430
  reg.state = (s32)((u32)(4294967295));  // @191_45f430
  ecx = (u32)(EBP - 528);  // @192_45f430
  eax = ext_4cbec0_thiscall1(ecx);  // @193_45f430
  ecx = edx = 0;  // @194_45f430
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 540), sizeof v); (u32)v; });  // @195_45f430
  ebx = (ebx + 1);  // @196_45f430
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 532), sizeof v); (u32)v; })) goto L45f6f0;  // @197_45f430
  goto L45f796;  // @198_45f430
  L45f765:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @200_45f430
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @201_45f430
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(553));  // @202_45f430
  ecx = edx = 0;  // @203_45f430
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 536), sizeof v); (u32)v; });  // @204_45f430
  esi = eax;  // @205_45f430
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @206_45f430
  eax = ext_4cc5a0_thiscall1(ecx);  // @207_45f430
  ecx = edx = 0;  // @208_45f430
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(esi), (u32)(6836364), (u32)(eax));  // @209_45f430
  ecx = edx = 0;  // @210_45f430
  L45f796:;
  SEH_LEAVE();  // @212_45f430
  ext_633654(G(u32, 0x6f5630));  // @213_45f430
  return eax;  // @214_45f430
}
PCREG(45f430, lifted_45f430);

extern "C" u32 THISCALL lifted_42b460(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664b9e);  // @h_42b460
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42b460
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @1_42b460
  { u32 v = (u32)((u32)(6789024)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_42b460
  edi = (u32)(esi + 28);  // @3_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @4_42b460
  ebx = (u32)(esi + 36);  // @5_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @6_42b460
  ecx = (u32)(esi + 163);  // @7_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @8_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 56), &v, sizeof v); }  // @9_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 64), &v, sizeof v); }  // @10_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @11_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @12_42b460
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @13_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @14_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @15_42b460
  ecx = edx = 0;  // @16_42b460
  ecx = (u32)(esi + 291);  // @17_42b460
  reg.state = (s32)((u32)(0));  // @18_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @19_42b460
  ecx = edx = 0;  // @20_42b460
  ecx = (u32)(esi + 419);  // @21_42b460
  reg.state = (s32)((u32)(1));  // @22_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @23_42b460
  ecx = edx = 0;  // @24_42b460
  ecx = (u32)(esi + 547);  // @25_42b460
  reg.state = (s32)((u32)(2));  // @26_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @27_42b460
  ecx = edx = 0;  // @28_42b460
  ecx = (u32)(esi + 675);  // @29_42b460
  reg.state = (s32)((u32)(3));  // @30_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789488));  // @31_42b460
  ecx = edx = 0;  // @32_42b460
  ecx = (u32)(esi + 803);  // @33_42b460
  reg.state = (s32)((u32)(4));  // @34_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @35_42b460
  ecx = edx = 0;  // @36_42b460
  ecx = (u32)(esi + 931);  // @37_42b460
  reg.state = (s32)((u32)(5));  // @38_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @39_42b460
  ecx = edx = 0;  // @40_42b460
  ecx = (u32)(esi + 1059);  // @41_42b460
  reg.state = (s32)((u32)(6));  // @42_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @43_42b460
  ecx = edx = 0;  // @44_42b460
  ecx = (u32)(esi + 1187);  // @45_42b460
  reg.state = (s32)((u32)(7));  // @46_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789504));  // @47_42b460
  ecx = edx = 0;  // @48_42b460
  ecx = (u32)(esi + 1315);  // @49_42b460
  reg.state = (s32)((u32)(8));  // @50_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @51_42b460
  ecx = edx = 0;  // @52_42b460
  ecx = (u32)(esi + 1443);  // @53_42b460
  reg.state = (s32)((u32)(9));  // @54_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @55_42b460
  ecx = edx = 0;  // @56_42b460
  ecx = (u32)(esi + 1571);  // @57_42b460
  reg.state = (s32)((u32)(10));  // @58_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @59_42b460
  ecx = edx = 0;  // @60_42b460
  ecx = (u32)(esi + 1699);  // @61_42b460
  reg.state = (s32)((u32)(11));  // @62_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @63_42b460
  ecx = edx = 0;  // @64_42b460
  ecx = (u32)(esi + 1827);  // @65_42b460
  reg.state = (s32)((u32)(12));  // @66_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @67_42b460
  ecx = edx = 0;  // @68_42b460
  ecx = (u32)(esi + 1955);  // @69_42b460
  reg.state = (s32)((u32)(13));  // @70_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @71_42b460
  ecx = edx = 0;  // @72_42b460
  ecx = (u32)(esi + 2083);  // @73_42b460
  reg.state = (s32)((u32)(14));  // @74_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @75_42b460
  ecx = edx = 0;  // @76_42b460
  ecx = (u32)(esi + 2211);  // @77_42b460
  reg.state = (s32)((u32)(15));  // @78_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @79_42b460
  ecx = edx = 0;  // @80_42b460
  ecx = (u32)(esi + 2339);  // @81_42b460
  reg.state = (s32)((u32)(16));  // @82_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @83_42b460
  ecx = edx = 0;  // @84_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @85_42b460
  ecx = (u32)(esi + 6423);  // @86_42b460
  reg.state = (s32)((u32)(17));  // @87_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 2511), &v, sizeof v); }  // @88_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @89_42b460
  ecx = edx = 0;  // @90_42b460
  ecx = (u32)(esi + 6551);  // @91_42b460
  reg.state = (s32)((u32)(18));  // @92_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @93_42b460
  ecx = edx = 0;  // @94_42b460
  ecx = (u32)(esi + 6679);  // @95_42b460
  reg.state = (s32)((u32)(19));  // @96_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @97_42b460
  ecx = edx = 0;  // @98_42b460
  ecx = (u32)(esi + 6839);  // @99_42b460
  reg.state = (s32)((u32)(20));  // @100_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6815), &v, sizeof v); }  // @101_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6819), &v, sizeof v); }  // @102_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6823), &v, sizeof v); }  // @103_42b460
  eax = ext_4cbeb0_thiscall1(ecx);  // @104_42b460
  ecx = edx = 0;  // @105_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7004), &v, sizeof v); }  // @106_42b460
  ecx = (u32)(EBP - 160);  // @107_42b460
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 6808), &v, sizeof v); }  // @108_42b460
  eax = (u32)(esi + 76);  // @109_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6993), &v, sizeof v); }  // @110_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6997), &v, sizeof v); }  // @111_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7001), &v, sizeof v); }  // @112_42b460
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7340956), &v, sizeof v); }  // @113_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6827), &v, sizeof v); }  // @114_42b460
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2487), &v, sizeof v); }  // @115_42b460
  { u32 v = (u32)((u32)(16777216)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @116_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @117_42b460
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 6976), &v, sizeof v); }  // @118_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6980), &v, sizeof v); }  // @119_42b460
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 6984), &v, sizeof v); }  // @120_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6812), &v, sizeof v); }  // @121_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2531), &v, sizeof v); }  // @122_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6807), &v, sizeof v); }  // @123_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 127), &v, sizeof v); }  // @124_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 147), &v, sizeof v); }  // @125_42b460
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 151), &v, sizeof v); }  // @126_42b460
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(esi + 143), &v, sizeof v); }  // @127_42b460
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @128_42b460
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 108), &v, sizeof v); }  // @129_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 110), &v, sizeof v); }  // @130_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2489), &v, sizeof v); }  // @131_42b460
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 2467), &v, sizeof v); }  // @132_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6967), &v, sizeof v); }  // @133_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2503), &v, sizeof v); }  // @134_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @135_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2491), &v, sizeof v); }  // @136_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 2495), &v, sizeof v); }  // @137_42b460
  { u32 v = (u32)((u32)(7227576)); __builtin_memcpy((void *)(u32)(esi + 6411), &v, sizeof v); }  // @138_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6974), &v, sizeof v); }  // @139_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6415), &v, sizeof v); }  // @140_42b460
  { u32 v = (u32)((u32)(1040187392)); __builtin_memcpy((void *)(u32)(esi + 2471), &v, sizeof v); }  // @141_42b460
  { u32 v = (u32)((u32)(1056293519)); __builtin_memcpy((void *)(u32)(esi + 2475), &v, sizeof v); }  // @142_42b460
  { u32 v = (u32)((u32)(1061158912)); __builtin_memcpy((void *)(u32)(esi + 2479), &v, sizeof v); }  // @143_42b460
  { u32 v = (u32)((u32)(1025758986)); __builtin_memcpy((void *)(u32)(esi + 2483), &v, sizeof v); }  // @144_42b460
  reg.state = (s32)((u32)(21));  // @145_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 6989), &v, sizeof v); }  // @146_42b460
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @147_42b460
  if (eax == ecx) goto L42b7bc;  // @148_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @149_42b460
  L42b7bc:;
  eax = (u32)(EBP - 164);  // @151_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @152_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @153_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @154_42b460
  if (edi == eax) goto L42b7e1;  // @155_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @156_42b460
  L42b7e1:;
  eax = (u32)(EBP - 168);  // @158_42b460
  if (ebx == eax) goto L42b7f1;  // @159_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @160_42b460
  L42b7f1:;
  ecx = (u32)(EBP - 144);  // @162_42b460
  { u32 v = (u32)((u32)(1114636288)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @163_42b460
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @164_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @165_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7003), &v, sizeof v); }  // @166_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789528));  // @167_42b460
  ecx = edx = 0;  // @168_42b460
  eax = (u32)(EBP - 144);  // @169_42b460
  reg.state = (s32)((u32)(22));  // @170_42b460
  ecx = (u32)(esi + 2211);  // @171_42b460
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @172_42b460
  ecx = edx = 0;  // @173_42b460
  ecx = (u32)(EBP - 144);  // @174_42b460
  reg.state = (s32)((u32)(21));  // @175_42b460
  eax = ext_4cbec0_thiscall1(ecx);  // @176_42b460
  ecx = edx = 0;  // @177_42b460
  ecx = (u32)(esi + 1955);  // @178_42b460
  eax = ext_4cbf30_thiscall2(ecx, (u32)(0));  // @179_42b460
  ecx = edx = 0;  // @180_42b460
  ecx = (u32)(esi + 2083);  // @181_42b460
  eax = ext_4cbf30_thiscall2(ecx, (u32)(0));  // @182_42b460
  ecx = edx = 0;  // @183_42b460
  ecx = (u32)(EBP - 144);  // @184_42b460
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789540));  // @185_42b460
  ecx = edx = 0;  // @186_42b460
  eax = (u32)(EBP - 144);  // @187_42b460
  reg.state = (s32)((u32)(23));  // @188_42b460
  ecx = (u32)(esi + 419);  // @189_42b460
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @190_42b460
  ecx = edx = 0;  // @191_42b460
  ecx = (u32)(EBP - 144);  // @192_42b460
  reg.state = (s32)((u32)(21));  // @193_42b460
  eax = ext_4cbec0_thiscall1(ecx);  // @194_42b460
  ecx = edx = 0;  // @195_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 7005), &v, sizeof v); }  // @196_42b460
  { u16 v = (u16)((u32)(256)); __builtin_memcpy((void *)(u32)(esi + 6971), &v, sizeof v); }  // @197_42b460
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 6973), &v, sizeof v); }  // @198_42b460
  eax = ext_41e290_cdecl1((u32)(12));  // @199_42b460
  ecx = edx = 0;  // @200_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @201_42b460
  if ((eax & eax) == 0) goto L42b8d5;  // @202_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @203_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @204_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @205_42b460
  goto L42b8d7;  // @206_42b460
  L42b8d5:;
  eax = 0;  // @208_42b460
  L42b8d7:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7009), &v, sizeof v); }  // @210_42b460
  eax = ext_41e290_cdecl1((u32)(9));  // @211_42b460
  ecx = edx = 0;  // @212_42b460
  edi = eax;  // @213_42b460
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @214_42b460
  reg.state = (s32)((u32)(24));  // @215_42b460
  if ((edi & edi) == 0) goto L42b927;  // @216_42b460
  ecx = edi;  // @217_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @218_42b460
  eax = ext_6014a0_stdcall1((u32)(37));  // @219_42b460
  ecx = edx = 0;  // @220_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @221_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @222_42b460
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @223_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @224_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @225_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @226_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @227_42b460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @228_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @229_42b460
  goto L42b929;  // @230_42b460
  L42b927:;
  edi = 0;  // @232_42b460
  L42b929:;
  reg.state = (s32)((u32)(21));  // @234_42b460
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 7013), &v, sizeof v); }  // @235_42b460
  eax = ext_41e290_cdecl1((u32)(12));  // @236_42b460
  ecx = edx = 0;  // @237_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @238_42b460
  if ((eax & eax) == 0) goto L42b95d;  // @239_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @240_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @241_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @242_42b460
  goto L42b95f;  // @243_42b460
  L42b95d:;
  eax = 0;  // @245_42b460
  L42b95f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7017), &v, sizeof v); }  // @247_42b460
  eax = ext_41e290_cdecl1((u32)(12));  // @248_42b460
  ecx = edx = 0;  // @249_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @250_42b460
  if ((eax & eax) == 0) goto L42b98f;  // @251_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @252_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @253_42b460
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @254_42b460
  goto L42b991;  // @255_42b460
  L42b98f:;
  eax = 0;  // @257_42b460
  L42b991:;
  ecx = esi;  // @259_42b460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 7021), &v, sizeof v); }  // @260_42b460
  eax = ext_42c9a0_thiscall1(ecx);  // @261_42b460
  ecx = edx = 0;  // @262_42b460
  eax = esi;  // @263_42b460
  SEH_LEAVE();  // @264_42b460
  ext_633654(G(u32, 0x6f5630));  // @265_42b460
  return eax;  // @266_42b460
}
PCREG(42b460, lifted_42b460);

extern "C" u32 THISCALL lifted_45cd90(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3) {
  SEH_ENTER(0x666733);  // @h_45cd90
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  ebx = ecx;  // @0_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 448), &v, sizeof v); }  // @1_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_45cd90
  edi = 0;  // @3_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 480), &v, sizeof v); }  // @4_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @5_45cd90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @6_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @7_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 476), &v, sizeof v); }  // @8_45cd90
  eax = ext_4da3a0_thiscall1(ecx);  // @9_45cd90
  ecx = edx = 0;  // @10_45cd90
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L45cdf4;  // @11_45cd90
  eax = (u32)(edi + 1);  // @12_45cd90
  goto L45d079;  // @13_45cd90
  L45cdf4:;
  ecx = (u32)(EBP - 444);  // @15_45cd90
  eax = ext_4ccba0_thiscall1(ecx);  // @16_45cd90
  ecx = edx = 0;  // @17_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @18_45cd90
  reg.state = (s32)((u32)(0));  // @19_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @20_45cd90
  if ((ecx & ecx) == 0) goto L45ce90;  // @21_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_45cd90
  edx = (u32)(EBP - 472);  // @23_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @24_45cd90
  ecx = edx = 0;  // @25_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @26_45cd90
  edx = (u32)(EBP - 472);  // @27_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @28_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @30_45cd90
  ecx = edx = 0;  // @31_45cd90
  esi = eax;  // @32_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) == (u32)(0)) goto L45ce90;  // @33_45cd90
  L45ce40:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @35_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(esi));  // @37_45cd90
  ecx = edx = 0;  // @38_45cd90
  if ((eax & eax) != 0) goto L45ce67;  // @39_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @40_45cd90
  edx = (u32)(EBP - 472);  // @41_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @42_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(edx));  // @44_45cd90
  ecx = edx = 0;  // @45_45cd90
  goto L45ce73;  // @46_45cd90
  L45ce67:;
  ecx = (u32)(EBP - 444);  // @48_45cd90
  eax = ext_4cd540_thiscall2(ecx, (u32)(esi));  // @49_45cd90
  ecx = edx = 0;  // @50_45cd90
  L45ce73:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; });  // @52_45cd90
  edx = (u32)(EBP - 472);  // @53_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @54_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @56_45cd90
  ecx = edx = 0;  // @57_45cd90
  esi = eax;  // @58_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) != (u32)(0)) goto L45ce40;  // @59_45cd90
  L45ce90:;
  eax = (u32)(EBP - 472);  // @61_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @62_45cd90
  ecx = (u32)(EBP - 444);  // @63_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @64_45cd90
  ecx = edx = 0;  // @65_45cd90
  eax = (u32)(EBP - 472);  // @66_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @67_45cd90
  ecx = (u32)(EBP - 444);  // @68_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @69_45cd90
  ecx = edx = 0;  // @70_45cd90
  edx = eax;  // @71_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) == (u32)(0)) goto L45d052;  // @72_45cd90
  L45ced0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @74_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(edx));  // @76_45cd90
  ecx = edx = 0;  // @77_45cd90
  esi = eax;  // @78_45cd90
  if ((esi & esi) == 0) goto L45d02d;  // @79_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @80_45cd90
  eax = ebx;  // @81_45cd90
  eax = (eax & (u32)(1));  // @82_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @83_45cd90
  if (eax == 0) goto L45cf03;  // @84_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4)) != 0) goto L45d027;  // @85_45cd90
  L45cf03:;
  eax = ebx;  // @87_45cd90
  eax = (eax & (u32)(2));  // @88_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @89_45cd90
  if (eax == 0) goto L45cf1a;  // @90_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(8)) != 0) goto L45d027;  // @91_45cd90
  L45cf1a:;
  if (ebx != (u32)(4)) goto L45cf28;  // @93_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (ebx & 0xff)) == 0) goto L45d027;  // @94_45cd90
  L45cf28:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @96_45cd90
  eax = (eax & (u32)(4));  // @97_45cd90
  if (eax != 0) goto L45d097;  // @98_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L45d097;  // @99_45cd90
  if (ebx == (u32)(1)) goto L45d097;  // @100_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 476), sizeof v); (u32)v; });  // @101_45cd90
  if ((ecx & ecx) == 0) goto L45cf7e;  // @102_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @103_45cd90
  edx = (u32)(EBP - 144);  // @104_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 472)))(ecx, (u32)(edx), (u32)(1));  // @105_45cd90
  ecx = edx = 0;  // @106_45cd90
  edi = (edi | (u32)(1));  // @107_45cd90
  reg.state = (s32)((u32)(1));  // @108_45cd90
  ecx = eax;  // @109_45cd90
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @110_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @111_45cd90
  ecx = edx = 0;  // @112_45cd90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @113_45cd90
  goto L45cf88;  // @114_45cd90
  L45cf7e:;
  { u32 v = (u32)((u32)(6836600)); __builtin_memcpy((void *)(u32)(EBP - 456), &v, sizeof v); }  // @116_45cd90
  L45cf88:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @118_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1620));  // @120_45cd90
  ecx = edx = 0;  // @121_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @122_45cd90
  ebx = eax;  // @123_45cd90
  eax = (u32)(EBP - 272);  // @124_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 460), &v, sizeof v); }  // @125_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @126_45cd90
  ecx = edi;  // @127_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @128_45cd90
  ecx = edx = 0;  // @129_45cd90
  edi = eax;  // @130_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @131_45cd90
  ecx = esi;  // @132_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @133_45cd90
  reg.state = (s32)((u32)(2));  // @134_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 20)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; }));  // @135_45cd90
  ecx = edx = 0;  // @136_45cd90
  ecx = edi;  // @137_45cd90
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @138_45cd90
  ecx = edx = 0;  // @139_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ebx + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; }), (u32)(6836608), (u32)(eax));  // @140_45cd90
  ecx = edx = 0;  // @141_45cd90
  ecx = (u32)(EBP - 272);  // @142_45cd90
  eax = ext_4cbec0_thiscall1(ecx);  // @143_45cd90
  ecx = edx = 0;  // @144_45cd90
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @145_45cd90
  reg.state = (s32)((u32)(0));  // @146_45cd90
  if (((ebx & 0xff) & (u32)(1)) == 0) goto L45d021;  // @147_45cd90
  ebx = (ebx & (u32)(4294967294));  // @148_45cd90
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @149_45cd90
  L45d016:;
  ecx = (u32)(EBP - 144);  // @151_45cd90
  eax = ext_4cbec0_thiscall1(ecx);  // @152_45cd90
  ecx = edx = 0;  // @153_45cd90
  L45d021:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @155_45cd90
  L45d027:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @157_45cd90
  L45d02d:;
  eax = (u32)(EBP - 472);  // @159_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 444), sizeof v); (u32)v; });  // @160_45cd90
  ecx = (u32)(EBP - 444);  // @161_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @162_45cd90
  ecx = edx = 0;  // @163_45cd90
  edx = eax;  // @164_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 472), sizeof v); (u32)v; }) != (u32)(0)) goto L45ced0;  // @165_45cd90
  L45d052:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != (u32)(1)) goto L45d067;  // @167_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @168_45cd90
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @169_45cd90
  ecx = edx = 0;  // @170_45cd90
  L45d067:;
  esi = (u32)(1);  // @172_45cd90
  L45d06c:;
  ecx = (u32)(EBP - 444);  // @174_45cd90
  eax = ext_4ccf60_thiscall1(ecx);  // @175_45cd90
  ecx = edx = 0;  // @176_45cd90
  eax = esi;  // @177_45cd90
  L45d079:;
  SEH_LEAVE();  // @179_45cd90
  ext_633654(G(u32, 0x6f5630));  // @180_45cd90
  return eax;  // @181_45cd90
  L45d097:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L45d027;  // @183_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @184_45cd90
  if ((ebx & ecx) != 0) goto L45d0b2;  // @185_45cd90
  if (ebx == (u32)(4)) goto L45d0b2;  // @186_45cd90
  if (ebx != (u32)(32)) goto L45d027;  // @187_45cd90
  L45d0b2:;
  if ((eax & eax) != 0) goto L45d11b;  // @189_45cd90
  if (((ecx & 0xff) & (u32)(1)) == 0) goto L45d11b;  // @190_45cd90
  if (ebx == (u32)(1)) goto L45d11b;  // @191_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @192_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @193_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6836308), (u32)(1634));  // @194_45cd90
  ecx = edx = 0;  // @195_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @196_45cd90
  ebx = eax;  // @197_45cd90
  eax = (u32)(EBP - 144);  // @198_45cd90
  ecx = edi;  // @199_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @200_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @201_45cd90
  ecx = edx = 0;  // @202_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @203_45cd90
  ecx = eax;  // @204_45cd90
  reg.state = (s32)((u32)(3));  // @205_45cd90
  eax = ext_4cc1d0_thiscall1(ecx);  // @206_45cd90
  ecx = edx = 0;  // @207_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @208_45cd90
  ecx = esi;  // @209_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(eax));  // @210_45cd90
  ecx = edx = 0;  // @211_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, (u32)(ebx), (u32)(6836680), (u32)(eax));  // @212_45cd90
  ecx = edx = 0;  // @213_45cd90
  reg.state = (s32)((u32)(0));  // @214_45cd90
  goto L45d016;  // @215_45cd90
  L45d11b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @217_45cd90
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @218_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @219_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @220_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edi));  // @221_45cd90
  ecx = edx = 0;  // @222_45cd90
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @223_45cd90
  ecx = esi;  // @224_45cd90
  edi = eax;  // @225_45cd90
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 480), sizeof v); (u32)v; }));  // @226_45cd90
  ecx = edx = 0;  // @227_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @228_45cd90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @229_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @230_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(edi));  // @231_45cd90
  ecx = edx = 0;  // @232_45cd90
  if ((eax & eax) == 0) goto L45d194;  // @233_45cd90
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 460), sizeof v); (u32)v; }) == (u32)(0)) goto L45d168;  // @234_45cd90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @235_45cd90
  L45d168:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 456), sizeof v); (u32)v; }) == (u32)(0)) goto L45d175;  // @237_45cd90
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(8))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @238_45cd90
  L45d175:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 448), sizeof v); (u32)v; });  // @240_45cd90
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L45d189;  // @241_45cd90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @242_45cd90
  ecx = esi;  // @243_45cd90
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(ebx));  // @244_45cd90
  ecx = edx = 0;  // @245_45cd90
  L45d189:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @247_45cd90
  goto L45d02d;  // @248_45cd90
  L45d194:;
  esi = 0;  // @250_45cd90
  goto L45d06c;  // @251_45cd90
}
PCREG(45cd90, lifted_45cd90);

