// batch200070.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_49f9b0_fastcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_49f9b0");
extern "C" u32 FASTCALL ext_4cc850_fastcall2(u32, u32) __asm__("ext_4cc850");
extern "C" u32 STDCALL ext_42da80_stdcall1(u32) __asm__("ext_42da80");
extern "C" u32 STDCALL ext_4c4f10_stdcall3(u32, u32, u32) __asm__("ext_4c4f10");
extern "C" u32 STDCALL ext_4d39a0_stdcall2(u32, u32) __asm__("ext_4d39a0");
extern "C" u32 STDCALL ext_4d3ab0_stdcall2(u32, u32) __asm__("ext_4d3ab0");
extern "C" u32 THISCALL ext_42de30_thiscall1(u32) __asm__("ext_42de30");
extern "C" u32 THISCALL ext_45d3a0_thiscall1(u32) __asm__("ext_45d3a0");
extern "C" u32 THISCALL ext_465650_thiscall1(u32) __asm__("ext_465650");
extern "C" u32 THISCALL ext_468030_thiscall4(u32, u32, u32, u32) __asm__("ext_468030");
extern "C" u32 THISCALL ext_482ac0_thiscall1(u32) __asm__("ext_482ac0");
extern "C" u32 THISCALL ext_497990_thiscall2(u32, u32) __asm__("ext_497990");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_49d6c0_thiscall1(u32) __asm__("ext_49d6c0");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccd10_thiscall3(u32, u32, u32) __asm__("ext_4ccd10");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cd0e0_thiscall1(u32) __asm__("ext_4cd0e0");
extern "C" u32 THISCALL ext_4cd540_thiscall2(u32, u32) __asm__("ext_4cd540");
extern "C" u32 THISCALL ext_4d2280_thiscall1(u32) __asm__("ext_4d2280");
extern "C" u32 THISCALL ext_4d2330_thiscall1(u32) __asm__("ext_4d2330");
extern "C" u32 THISCALL ext_4da340_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_4da340");
extern "C" u32 THISCALL ext_4db860_thiscall2(u32, u32) __asm__("ext_4db860");
extern "C" u32 THISCALL ext_4dc030_thiscall1(u32) __asm__("ext_4dc030");
extern "C" u32 THISCALL ext_4dc110_thiscall1(u32) __asm__("ext_4dc110");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4de7a0_thiscall1(u32) __asm__("ext_4de7a0");
extern "C" u32 THISCALL ext_5ab2e0_thiscall2(u32, u32) __asm__("ext_5ab2e0");
extern "C" u32 THISCALL ext_5e0ee0_thiscall3(u32, u32, u32) __asm__("ext_5e0ee0");
extern "C" u32 THISCALL ext_5e0f80_thiscall3(u32, u32, u32) __asm__("ext_5e0f80");
extern "C" u32 THISCALL ext_5e0ff0_thiscall3(u32, u32, u32) __asm__("ext_5e0ff0");
extern "C" u32 THISCALL ext_5e10a0_thiscall3(u32, u32, u32) __asm__("ext_5e10a0");
extern "C" u32 THISCALL ext_5e1110_thiscall3(u32, u32, u32) __asm__("ext_5e1110");
extern "C" u32 THISCALL ext_5e1160_thiscall3(u32, u32, u32) __asm__("ext_5e1160");
extern "C" u32 THISCALL ext_5e1190_thiscall3(u32, u32, u32) __asm__("ext_5e1190");
extern "C" u32 THISCALL ext_5e11c0_thiscall3(u32, u32, u32) __asm__("ext_5e11c0");
extern "C" u32 THISCALL ext_5e1200_thiscall3(u32, u32, u32) __asm__("ext_5e1200");
extern "C" u32 THISCALL ext_5fe3b0_thiscall3(u32, u32, u32) __asm__("ext_5fe3b0");
extern "C" u32 THISCALL ext_603500_thiscall2(u32, u32) __asm__("ext_603500");
extern "C" u32 THISCALL ext_659220_thiscall3(u32, u32, u32) __asm__("ext_659220");
extern "C" u32 THISCALL ext_659330_thiscall3(u32, u32, u32) __asm__("ext_659330");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_44a1f0_cdecl0(void) __asm__("ext_44a1f0");
extern "C" u32 ext_46bca0_cdecl0(void) __asm__("ext_46bca0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c5090(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66997b);  // @h_4c5090
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c5090
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @1_4c5090
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4c5090
  ecx = (u32)(EBP - 188);  // @3_4c5090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @4_4c5090
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 208), &v, sizeof v); }  // @5_4c5090
  eax = ext_4ccba0_thiscall1(ecx);  // @6_4c5090
  ecx = edx = 0;  // @7_4c5090
  eax = (u32)(EBP - 188);  // @8_4c5090
  reg.state = (s32)((u32)(0));  // @9_4c5090
  ecx = ebx;  // @10_4c5090
  eax = ext_4c4f10_stdcall3((u32)(eax), (u32)(edi), (u32)(esi));  // @11_4c5090
  ecx = edx = 0;  // @12_4c5090
  eax = (u32)(EBP - 200);  // @13_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @14_4c5090
  ecx = (u32)(EBP - 188);  // @15_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @16_4c5090
  ecx = edx = 0;  // @17_4c5090
  eax = (u32)(EBP - 200);  // @18_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @19_4c5090
  ecx = (u32)(EBP - 188);  // @20_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @21_4c5090
  ecx = edx = 0;  // @22_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L4c51c7;  // @23_4c5090
  L4c5130:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @26_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @28_4c5090
  ecx = edx = 0;  // @29_4c5090
  esi = eax;  // @30_4c5090
  if ((esi & esi) == 0) goto L4c519e;  // @31_4c5090
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }) == (u32)(0)) goto L4c5197;  // @32_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @33_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @34_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(esi));  // @36_4c5090
  ecx = edx = 0;  // @37_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 106), sizeof v); (u32)v; });  // @38_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(eax));  // @40_4c5090
  ecx = edx = 0;  // @41_4c5090
  if ((eax & eax) == 0) goto L4c5172;  // @42_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @43_4c5090
  goto L4c5174;  // @44_4c5090
  L4c5172:;
  edx = 0;  // @46_4c5090
  L4c5174:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @51_4c5090
  ecx = edx = 0;  // @52_4c5090
  if ((eax & eax) == 0) goto L4c519e;  // @53_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @54_4c5090
  ecx = eax;  // @55_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 528)))(ecx, (u32)(1));  // @56_4c5090
  ecx = edx = 0;  // @57_4c5090
  goto L4c519e;  // @58_4c5090
  L4c5197:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @60_4c5090
  ecx = esi;  // @61_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @62_4c5090
  ecx = edx = 0;  // @63_4c5090
  L4c519e:;
  eax = (u32)(EBP - 200);  // @65_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @66_4c5090
  ecx = (u32)(EBP - 188);  // @67_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @68_4c5090
  ecx = edx = 0;  // @69_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L4c5130;  // @70_4c5090
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 208), sizeof v); (u32)v; });  // @71_4c5090
  L4c51c7:;
  eax = (u32)(EBP - 188);  // @73_4c5090
  ecx = ebx;  // @74_4c5090
  eax = ext_4c4f10_stdcall3((u32)(eax), (u32)(esi), (u32)(edi));  // @75_4c5090
  ecx = edx = 0;  // @76_4c5090
  eax = (u32)(EBP - 200);  // @77_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @78_4c5090
  ecx = (u32)(EBP - 188);  // @79_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @80_4c5090
  ecx = edx = 0;  // @81_4c5090
  eax = (u32)(EBP - 200);  // @82_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @83_4c5090
  ecx = (u32)(EBP - 188);  // @84_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @85_4c5090
  ecx = edx = 0;  // @86_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L4c52be;  // @87_4c5090
  L4c5210:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @89_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @90_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @92_4c5090
  ecx = edx = 0;  // @93_4c5090
  esi = eax;  // @94_4c5090
  if ((esi & esi) == 0) goto L4c529b;  // @95_4c5090
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; }) == (u32)(0)) goto L4c528a;  // @96_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @97_4c5090
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_4c5090
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(0), (u32)(0), (u32)(0), (u32)(1));  // @100_4c5090
  ecx = edx = 0;  // @101_4c5090
  ecx = esi;  // @102_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 440)))(ecx, (u32)(eax));  // @103_4c5090
  ecx = edx = 0;  // @104_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @105_4c5090
  ebx = eax;  // @106_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @107_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(ebx));  // @109_4c5090
  ecx = edx = 0;  // @110_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @111_4c5090
  edi = eax;  // @112_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @113_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(esi));  // @115_4c5090
  ecx = edx = 0;  // @116_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @117_4c5090
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 106), sizeof v); (u32)v; });  // @118_4c5090
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, (u32)(eax));  // @120_4c5090
  ecx = edx = 0;  // @121_4c5090
  esi = ebx;  // @122_4c5090
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; });  // @123_4c5090
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @124_4c5090
  L4c528a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @126_4c5090
  ecx = esi;  // @127_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @128_4c5090
  ecx = edx = 0;  // @129_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @130_4c5090
  ecx = esi;  // @131_4c5090
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 456)))(ecx);  // @132_4c5090
  ecx = edx = 0;  // @133_4c5090
  L4c529b:;
  eax = (u32)(EBP - 200);  // @135_4c5090
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @136_4c5090
  ecx = (u32)(EBP - 188);  // @137_4c5090
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @138_4c5090
  ecx = edx = 0;  // @139_4c5090
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L4c5210;  // @140_4c5090
  L4c52be:;
  ecx = (u32)(EBP - 188);  // @142_4c5090
  eax = ext_4ccf60_thiscall1(ecx);  // @143_4c5090
  ecx = edx = 0;  // @144_4c5090
  SEH_LEAVE();  // @145_4c5090
  ext_633654(G(u32, 0x6f5630));  // @146_4c5090
  return eax;  // @147_4c5090
}
PCREG(4c5090, lifted_4c5090);

extern "C" u32 THISCALL lifted_437440(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665ac2);  // @h_437440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @1_437440
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @2_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @3_437440
  eax = ext_41e290_cdecl1((u32)(28));  // @4_437440
  ecx = edx = 0;  // @5_437440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @6_437440
  reg.state = (s32)((u32)(0));  // @7_437440
  if ((eax & eax) == 0) goto L4374a3;  // @8_437440
  ecx = eax;  // @9_437440
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @10_437440
  ecx = edx = 0;  // @11_437440
  goto L4374a5;  // @12_437440
  L4374a3:;
  eax = 0;  // @14_437440
  L4374a5:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @16_437440
  reg.state = (s32)((u32)(4294967295));  // @17_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L437632;  // @18_437440
  L4374c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @20_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 8)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }));  // @22_437440
  ecx = edx = 0;  // @23_437440
  edi = eax;  // @24_437440
  if ((edi & edi) == 0) goto L437538;  // @25_437440
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 160), sizeof v); (u32)v; }) == (u32)(0)) goto L4374e5;  // @26_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @27_437440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 161), &v, sizeof v); }  // @28_437440
  L4374e5:;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) & (u32)(2)) == 0) goto L43752e;  // @30_437440
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 165), sizeof v); (u32)v; }) != (u32)(0)) goto L43752e;  // @31_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @32_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2574));  // @34_437440
  ecx = edx = 0;  // @35_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @36_437440
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6793848), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }));  // @37_437440
  ecx = edx = 0;  // @38_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @39_437440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 145), &v, sizeof v); }  // @40_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 16), sizeof v); (u32)v; }));  // @42_437440
  ecx = edx = 0;  // @43_437440
  L43752e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_437440
  ecx = ebx;  // @46_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edi));  // @47_437440
  ecx = edx = 0;  // @48_437440
  goto L437540;  // @49_437440
  L437538:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @51_437440
  ecx = ebx;  // @52_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(esi));  // @53_437440
  ecx = edx = 0;  // @54_437440
  L437540:;
  esi = (esi + (u32)(28));  // @56_437440
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) - (u32)(1))); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @57_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) != 0) goto L4374c0;  // @58_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 145), sizeof v); (u32)v; })) & 0xff);  // @59_437440
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @60_437440
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L437638;  // @61_437440
  if ((esi & esi) == 0) goto L437644;  // @62_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @63_437440
  ecx = (u32)(EBP - 164);  // @64_437440
  ecx = esi;  // @65_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @66_437440
  ecx = edx = 0;  // @67_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @68_437440
  ecx = (u32)(EBP - 164);  // @69_437440
  ecx = esi;  // @70_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @71_437440
  ecx = edx = 0;  // @72_437440
  ecx = eax;  // @73_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) == (u32)(0)) goto L437638;  // @74_437440
  L437594:;
  edx = (u32)(EBP - 144);  // @76_437440
  edx = (edx - ecx);  // @77_437440
  L4375a0:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @79_437440
  ecx = (u32)(ecx + 1);  // @80_437440
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edx + ecx - 1), &v, sizeof v); }  // @81_437440
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4375a0;  // @82_437440
  esi = (u32)(EBP - 144);  // @83_437440
  L4375b3:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @85_437440
  edi = esi;  // @86_437440
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L43760d;  // @87_437440
  if ((eax & 0xff) == (u32)(48)) goto L43760d;  // @88_437440
  L4375c0:;
  if ((eax & 0xff) == (u32)(43)) goto L4375d0;  // @90_437440
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; })) & 0xff);  // @91_437440
  esi = (esi + 1);  // @92_437440
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4375c0;  // @93_437440
  if ((eax & 0xff) != (u32)(43)) goto L4375d4;  // @94_437440
  L4375d0:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @96_437440
  esi = (esi + 1);  // @97_437440
  L4375d4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 17), sizeof v); (u32)v; });  // @99_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edi));  // @101_437440
  ecx = edx = 0;  // @102_437440
  if ((eax & eax) == 0) goto L4375e7;  // @103_437440
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @104_437440
  goto L4375b3;  // @105_437440
  L4375e7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @107_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_437440
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6793296), (u32)(2603));  // @109_437440
  ecx = edx = 0;  // @110_437440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @111_437440
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6793964), (u32)(edi));  // @112_437440
  ecx = edx = 0;  // @113_437440
  goto L4375b3;  // @114_437440
  L43760d:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @116_437440
  ecx = (u32)(EBP - 164);  // @117_437440
  ecx = esi;  // @118_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @119_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @120_437440
  ecx = edx = 0;  // @121_437440
  ecx = eax;  // @122_437440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) != (u32)(0)) goto L437594;  // @123_437440
  goto L437638;  // @124_437440
  L437632:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @126_437440
  L437638:;
  if ((esi & esi) == 0) goto L437644;  // @128_437440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_437440
  ecx = esi;  // @130_437440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @131_437440
  ecx = edx = 0;  // @132_437440
  L437644:;
  SEH_LEAVE();  // @134_437440
  ext_633654(G(u32, 0x6f5630));  // @135_437440
  return eax;  // @136_437440
}
PCREG(437440, lifted_437440);

extern "C" u32 THISCALL lifted_476720(u32 ecx_in) {
  SEH_ENTER(0x66713b);  // @h_476720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_476720
  eax = ext_45d3a0_thiscall1(ecx);  // @1_476720
  ecx = edx = 0;  // @2_476720
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 114), sizeof v); (u32)v; }) != (u32)(0)) goto L47694b;  // @3_476720
  edi = 0;  // @4_476720
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; }) <= (s32)edi) goto L47694b;  // @5_476720
  L476770:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 100), sizeof v); (u32)v; });  // @7_476720
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*4), sizeof v); (u32)v; });  // @8_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @9_476720
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L476941;  // @10_476720
  ecx = (u32)(EBP - 188);  // @11_476720
  eax = ext_4ccba0_thiscall1(ecx);  // @12_476720
  ecx = edx = 0;  // @13_476720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @14_476720
  reg.state = (s32)((u32)(0));  // @15_476720
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @16_476720
  if ((edx & edx) == 0) goto L4767e5;  // @17_476720
  L4767b0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @19_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @20_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edx));  // @22_476720
  ecx = edx = 0;  // @23_476720
  ecx = (u32)(EBP - 188);  // @24_476720
  eax = ext_4cd540_thiscall2(ecx, (u32)(eax));  // @25_476720
  ecx = edx = 0;  // @26_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_476720
  ecx = (u32)(EBP - 192);  // @28_476720
  ecx = esi;  // @29_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(ecx));  // @30_476720
  ecx = edx = 0;  // @31_476720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @32_476720
  if ((edx & edx) != 0) goto L4767b0;  // @33_476720
  L4767e5:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @36_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @38_476720
  ecx = edx = 0;  // @39_476720
  eax = (u32)(EBP - 204);  // @40_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @41_476720
  ecx = (u32)(EBP - 188);  // @42_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(eax));  // @43_476720
  ecx = edx = 0;  // @44_476720
  eax = (u32)(EBP - 204);  // @45_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @46_476720
  ecx = (u32)(EBP - 188);  // @47_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @48_476720
  ecx = edx = 0;  // @49_476720
  esi = eax;  // @50_476720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) == (u32)(0)) goto L47692f;  // @51_476720
  L476831:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @53_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @54_476720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @55_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(esi));  // @56_476720
  ecx = edx = 0;  // @57_476720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @58_476720
  if ((eax & eax) == 0) goto L47690a;  // @59_476720
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) != 0) goto L47690a;  // @60_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @61_476720
  if ((ecx & ecx) == 0) goto L47686d;  // @62_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_476720
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 340)))(ecx);  // @64_476720
  ecx = edx = 0;  // @65_476720
  L47686d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @67_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @68_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @70_476720
  ecx = edx = 0;  // @71_476720
  if ((eax & eax) == 0) goto L47690a;  // @72_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @73_476720
  eax = ext_4da340_thiscall5(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @74_476720
  ecx = edx = 0;  // @75_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @77_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @79_476720
  ecx = edx = 0;  // @80_476720
  if ((eax & eax) == 0) goto L47690a;  // @81_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @82_476720
  eax = ext_4da340_thiscall5(ecx, (u32)(2), (u32)(0), (u32)(0), (u32)(0));  // @83_476720
  ecx = edx = 0;  // @84_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @86_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, (u32)(esi));  // @88_476720
  ecx = edx = 0;  // @89_476720
  if ((eax & eax) == 0) goto L47690a;  // @90_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @91_476720
  eax = ext_4dc630_thiscall3(ecx, (u32)(8388608), (u32)(0));  // @92_476720
  ecx = edx = 0;  // @93_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @94_476720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @95_476720
  if ((ecx & ecx) == 0) goto L476903;  // @96_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @97_476720
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 344)))(ecx);  // @98_476720
  ecx = edx = 0;  // @99_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 192), sizeof v); (u32)v; });  // @100_476720
  L476903:;
  ecx = eax;  // @102_476720
  eax = ext_4dc030_thiscall1(ecx);  // @103_476720
  ecx = edx = 0;  // @104_476720
  L47690a:;
  eax = (u32)(EBP - 204);  // @106_476720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @107_476720
  ecx = (u32)(EBP - 188);  // @108_476720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(eax));  // @109_476720
  ecx = edx = 0;  // @110_476720
  esi = eax;  // @111_476720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 204), sizeof v); (u32)v; }) != (u32)(0)) goto L476831;  // @112_476720
  L47692f:;
  ecx = (u32)(EBP - 188);  // @114_476720
  reg.state = (s32)((u32)(4294967295));  // @115_476720
  eax = ext_4ccf60_thiscall1(ecx);  // @116_476720
  ecx = edx = 0;  // @117_476720
  L476941:;
  edi = (edi + 1);  // @119_476720
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 92), sizeof v); (u32)v; })) goto L476770;  // @120_476720
  L47694b:;
  SEH_LEAVE();  // @122_476720
  ext_633654(G(u32, 0x6f5630));  // @123_476720
  return eax;  // @124_476720
}
PCREG(476720, lifted_476720);

extern "C" u32 THISCALL lifted_4ad770(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6688a1);  // @h_4ad770
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4ad770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @3_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edi));  // @5_4ad770
  ecx = edx = 0;  // @6_4ad770
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @7_4ad770
  if ((eax & eax) != 0) goto L4ad816;  // @8_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @9_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @11_4ad770
  ecx = edx = 0;  // @12_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @13_4ad770
  edi = eax;  // @14_4ad770
  eax = (u32)(EBP - 144);  // @15_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @17_4ad770
  ecx = edx = 0;  // @18_4ad770
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @19_4ad770
  ecx = eax;  // @20_4ad770
  reg.state = (s32)((u32)(0));  // @21_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @22_4ad770
  ecx = edx = 0;  // @23_4ad770
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6884388), (u32)(eax));  // @24_4ad770
  ecx = edx = 0;  // @25_4ad770
  ecx = (u32)(EBP - 144);  // @26_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @27_4ad770
  ecx = edx = 0;  // @28_4ad770
  goto L4ad97a;  // @29_4ad770
  L4ad816:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @31_4ad770
  ecx = (u32)(esi + 282);  // @32_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(edi));  // @33_4ad770
  ecx = edx = 0;  // @34_4ad770
  if ((eax & eax) != 0) goto L4ad8c3;  // @35_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @36_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @38_4ad770
  ecx = edx = 0;  // @39_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @40_4ad770
  edi = eax;  // @41_4ad770
  eax = (u32)(EBP - 400);  // @42_4ad770
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @43_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @45_4ad770
  ecx = edx = 0;  // @46_4ad770
  ebx = eax;  // @47_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; });  // @48_4ad770
  eax = (u32)(EBP - 272);  // @49_4ad770
  reg.state = (s32)((u32)(1));  // @50_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @51_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @52_4ad770
  ecx = edx = 0;  // @53_4ad770
  esi = eax;  // @54_4ad770
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_4ad770
  ecx = ebx;  // @56_4ad770
  reg.state = (s32)((u32)(2));  // @57_4ad770
  eax = ext_4cc1d0_thiscall1(ecx);  // @58_4ad770
  ecx = edx = 0;  // @59_4ad770
  ecx = esi;  // @60_4ad770
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @61_4ad770
  ecx = edx = 0;  // @62_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }), (u32)(6884448), (u32)(eax));  // @63_4ad770
  ecx = edx = 0;  // @64_4ad770
  ecx = (u32)(EBP - 272);  // @65_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @66_4ad770
  ecx = edx = 0;  // @67_4ad770
  ecx = (u32)(EBP - 400);  // @68_4ad770
  eax = ext_4cbec0_thiscall1(ecx);  // @69_4ad770
  ecx = edx = 0;  // @70_4ad770
  goto L4ad97a;  // @71_4ad770
  L4ad8c3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @73_4ad770
  ecx = (u32)(esi + 282);  // @74_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(edi));  // @75_4ad770
  ecx = edx = 0;  // @76_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @77_4ad770
  if ((edx & edx) == 0) goto L4ad8fd;  // @78_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @79_4ad770
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @80_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @82_4ad770
  ecx = edx = 0;  // @83_4ad770
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @84_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @85_4ad770
  ecx = eax;  // @86_4ad770
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(ecx), (u32)(edi), (u32)(0));  // @87_4ad770
  ecx = edx = 0;  // @88_4ad770
  L4ad8fd:;
  esi = (esi + (u32)(454));  // @90_4ad770
  if (esi == 0) goto L4ad97a;  // @91_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @92_4ad770
  ecx = (u32)(EBP - 412);  // @93_4ad770
  ecx = esi;  // @94_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @95_4ad770
  ecx = edx = 0;  // @96_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @97_4ad770
  ecx = (u32)(EBP - 412);  // @98_4ad770
  ecx = esi;  // @99_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @100_4ad770
  ecx = edx = 0;  // @101_4ad770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad97a;  // @102_4ad770
  L4ad930:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @104_4ad770
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @105_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(eax));  // @106_4ad770
  ecx = edx = 0;  // @107_4ad770
  ecx = eax;  // @108_4ad770
  if ((ecx & ecx) == 0) goto L4ad955;  // @109_4ad770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }) != edi) goto L4ad963;  // @110_4ad770
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_4ad770
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @112_4ad770
  ecx = edx = 0;  // @113_4ad770
  L4ad955:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_4ad770
  ecx = (u32)(EBP - 412);  // @116_4ad770
  ecx = esi;  // @117_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(ecx));  // @118_4ad770
  ecx = edx = 0;  // @119_4ad770
  L4ad963:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @121_4ad770
  ecx = (u32)(EBP - 412);  // @122_4ad770
  ecx = esi;  // @123_4ad770
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @124_4ad770
  ecx = edx = 0;  // @125_4ad770
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) != (u32)(0)) goto L4ad930;  // @126_4ad770
  L4ad97a:;
  SEH_LEAVE();  // @128_4ad770
  ext_633654(G(u32, 0x6f5630));  // @129_4ad770
  return eax;  // @130_4ad770
}
PCREG(4ad770, lifted_4ad770);

extern "C" u32 THISCALL lifted_57c500(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  SEH_ENTER(0x66b18b);  // @h_57c500
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  ebx = ecx;  // @0_57c500
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_57c500
  ecx = (u32)(ebx + 44);  // @3_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @4_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @5_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @6_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; });  // @7_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @8_57c500
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @9_57c500
  eax = ext_4cbeb0_thiscall1(ecx);  // @10_57c500
  ecx = edx = 0;  // @11_57c500
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_57c500
  ecx = esi;  // @13_57c500
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 224), &v, sizeof v); }  // @14_57c500
  reg.state = (s32)((u32)(0));  // @15_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_57c500
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 708)))(ecx);  // @17_57c500
  ecx = edx = 0;  // @18_57c500
  ecx = eax;  // @19_57c500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @20_57c500
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 840)))(ecx);  // @21_57c500
  ecx = edx = 0;  // @22_57c500
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L57c6d7;  // @23_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @24_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 80), sizeof v); (u32)v; });  // @25_57c500
  if ((eax & eax) == 0) goto L57c588;  // @26_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 84), sizeof v); (u32)v; });  // @27_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @28_57c500
  L57c588:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_57c500
  ecx = esi;  // @31_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 648)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }), (u32)(0), (u32)(1));  // @32_57c500
  ecx = edx = 0;  // @33_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @34_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @35_57c500
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 780)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @36_57c500
  ecx = edx = 0;  // @37_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @38_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_57c500
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 44)))(ecx);  // @40_57c500
  ecx = edx = 0;  // @41_57c500
  edx = 0;  // @42_57c500
  { u32 v = (u32)((u32)(6990944)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @43_57c500
  { u32 v = (u32)((u32)(6990952)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @44_57c500
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @45_57c500
  L57c5c2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @47_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + edx*4 - 24), sizeof v); (u32)v; }), (u32)(0));  // @49_57c500
  ecx = edx = 0;  // @50_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_57c500
  esi = eax;  // @52_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @53_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @54_57c500
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2788), sizeof v); (u32)v; });  // @56_57c500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 0)))(ecx, (u32)(6990960), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @58_57c500
  ecx = edx = 0;  // @59_57c500
  ecx = esi;  // @60_57c500
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 644)))(ecx, (u32)(eax));  // @61_57c500
  ecx = edx = 0;  // @62_57c500
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @63_57c500
  edx = (edx + 1);  // @64_57c500
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 16), &v, sizeof v); }  // @65_57c500
  if (edx < (u32)(2)) goto L57c5c2;  // @66_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @67_57c500
  esi = (u32)(ebx + 12);  // @68_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @69_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6990976), (u32)(0));  // @70_57c500
  ecx = edx = 0;  // @71_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @72_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @73_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6990984), (u32)(0));  // @75_57c500
  ecx = edx = 0;  // @76_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 16), &v, sizeof v); }  // @77_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @78_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6990992), (u32)(0));  // @80_57c500
  ecx = edx = 0;  // @81_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 20), &v, sizeof v); }  // @82_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @83_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991000), (u32)(0));  // @85_57c500
  ecx = edx = 0;  // @86_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @87_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @88_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @89_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991008), (u32)(0));  // @90_57c500
  ecx = edx = 0;  // @91_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 28), &v, sizeof v); }  // @92_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @93_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991016), (u32)(0));  // @95_57c500
  ecx = edx = 0;  // @96_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 32), &v, sizeof v); }  // @97_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @98_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991024), (u32)(0));  // @100_57c500
  ecx = edx = 0;  // @101_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 36), &v, sizeof v); }  // @102_57c500
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @103_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_57c500
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 604)))(ecx, (u32)(6991032), (u32)(0));  // @105_57c500
  ecx = edx = 0;  // @106_57c500
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 40), &v, sizeof v); }  // @107_57c500
  edi = (u32)(7);  // @108_57c500
  L57c6c0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @110_57c500
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @111_57c500
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 644)))(ecx, (u32)(6781786));  // @112_57c500
  ecx = edx = 0;  // @113_57c500
  esi = (u32)(esi + 4);  // @114_57c500
  edi = (edi - (u32)(1));  // @115_57c500
  if (edi != 0) goto L57c6c0;  // @116_57c500
  L57c6d7:;
  eax = ebx;  // @118_57c500
  SEH_LEAVE();  // @119_57c500
  return eax;  // @120_57c500
}
PCREG(57c500, lifted_57c500);

extern "C" u32 THISCALL lifted_45e190(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x665bff);  // @h_45e190
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  edi = ecx;  // @0_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @1_45e190
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_45e190
  ebx = (ebx & (u32)(280));  // @3_45e190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 64)))(ecx);  // @4_45e190
  ecx = edx = 0;  // @5_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @6_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_45e190
  if ((ecx & ecx) == 0) goto L45e25e;  // @8_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_45e190
  edx = (u32)(EBP - 24);  // @10_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @11_45e190
  ecx = edx = 0;  // @12_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @13_45e190
  edx = (u32)(EBP - 24);  // @14_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @15_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @17_45e190
  ecx = edx = 0;  // @18_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L45e294;  // @19_45e190
  L45e200:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @21_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(eax));  // @23_45e190
  ecx = edx = 0;  // @24_45e190
  esi = eax;  // @25_45e190
  if ((esi & esi) != 0) goto L45e226;  // @26_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @27_45e190
  edx = (u32)(EBP - 24);  // @28_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @29_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(edx));  // @31_45e190
  ecx = edx = 0;  // @32_45e190
  goto L45e22c;  // @33_45e190
  L45e226:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; }) != (u32)(0)) goto L45e243;  // @35_45e190
  L45e22c:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @37_45e190
  edx = (u32)(EBP - 24);  // @38_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @39_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @40_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @41_45e190
  ecx = edx = 0;  // @42_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L45e200;  // @43_45e190
  goto L45e294;  // @44_45e190
  L45e243:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @46_45e190
  ecx = (u32)(esi + 16);  // @47_45e190
  eax = (eax + (u32)(64));  // @48_45e190
  if (ecx == eax) goto L45e256;  // @49_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @50_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @51_45e190
  L45e256:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) | ebx)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @53_45e190
  goto L45e2fe;  // @54_45e190
  L45e25e:;
  eax = ext_41e290_cdecl1((u32)(28));  // @56_45e190
  ecx = edx = 0;  // @57_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @58_45e190
  reg.state = (s32)((u32)(0));  // @59_45e190
  if ((eax & eax) == 0) goto L45e285;  // @60_45e190
  ecx = eax;  // @61_45e190
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(0));  // @62_45e190
  ecx = edx = 0;  // @63_45e190
  ecx = eax;  // @64_45e190
  goto L45e287;  // @65_45e190
  L45e285:;
  ecx = 0;  // @67_45e190
  L45e287:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @69_45e190
  reg.state = (s32)((u32)(4294967295));  // @70_45e190
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @71_45e190
  L45e294:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @73_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @74_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, (u32)(edi));  // @76_45e190
  ecx = edx = 0;  // @77_45e190
  esi = eax;  // @78_45e190
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @79_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @80_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @81_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(esi));  // @82_45e190
  ecx = edx = 0;  // @83_45e190
  if ((eax & eax) == 0) goto L45e2c1;  // @84_45e190
  edx = 0;  // @85_45e190
  goto L45e2f2;  // @86_45e190
  L45e2c1:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @88_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @89_45e190
  if ((eax & eax) == 0) goto L45e2e0;  // @90_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L45e2e0;  // @91_45e190
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L45e2e0;  // @92_45e190
  ecx = esi;  // @93_45e190
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @94_45e190
  ecx = edx = 0;  // @95_45e190
  edx = eax;  // @96_45e190
  goto L45e2f2;  // @97_45e190
  L45e2e0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L45e2ef;  // @99_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @101_45e190
  ecx = edx = 0;  // @102_45e190
  L45e2ef:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @104_45e190
  L45e2f2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @106_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @107_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(edx));  // @109_45e190
  ecx = edx = 0;  // @110_45e190
  L45e2fe:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @112_45e190
  ecx = edi;  // @113_45e190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @114_45e190
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @115_45e190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 284)))(ecx, (u32)(esi), (u32)(eax));  // @116_45e190
  ecx = edx = 0;  // @117_45e190
  if (((ebx & 0xff) & (u32)(8)) == 0) goto L45e36b;  // @118_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @119_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L45e36b;  // @120_45e190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @121_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(esi));  // @123_45e190
  ecx = edx = 0;  // @124_45e190
  if ((eax & eax) == 0) goto L45e332;  // @125_45e190
  ecx = 0;  // @126_45e190
  goto L45e363;  // @127_45e190
  L45e332:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @129_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @130_45e190
  if ((eax & eax) == 0) goto L45e351;  // @131_45e190
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L45e351;  // @132_45e190
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L45e351;  // @133_45e190
  ecx = esi;  // @134_45e190
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @135_45e190
  ecx = edx = 0;  // @136_45e190
  ecx = eax;  // @137_45e190
  goto L45e363;  // @138_45e190
  L45e351:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L45e360;  // @140_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @141_45e190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @142_45e190
  ecx = edx = 0;  // @143_45e190
  L45e360:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @145_45e190
  L45e363:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @147_45e190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 16), sizeof v); (u32)v; });  // @148_45e190
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @149_45e190
  L45e36b:;
  eax = esi;  // @151_45e190
  SEH_LEAVE();  // @152_45e190
  return eax;  // @153_45e190
}
PCREG(45e190, lifted_45e190);

extern "C" u32 THISCALL lifted_603a50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66dc9f);  // @h_603a50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_603a50
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @2_603a50
  eax = ext_41e290_cdecl1((u32)(24));  // @3_603a50
  ecx = edx = 0;  // @4_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_603a50
  reg.state = (s32)((u32)(0));  // @6_603a50
  if ((eax & eax) == 0) goto L603aa7;  // @7_603a50
  ecx = eax;  // @8_603a50
  eax = ext_603500_thiscall2(ecx, (u32)(esi));  // @9_603a50
  ecx = edx = 0;  // @10_603a50
  edi = eax;  // @11_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @12_603a50
  goto L603aac;  // @13_603a50
  L603aa7:;
  edi = 0;  // @15_603a50
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @16_603a50
  L603aac:;
  esi = 0;  // @18_603a50
  reg.state = (s32)((u32)(4294967295));  // @19_603a50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; }) <= esi) goto L603b6f;  // @20_603a50
  L603ac0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @23_603a50
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L603af1;  // @24_603a50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @25_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_603a50
  ebx = (ebx + esi);  // @27_603a50
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L603aea;  // @28_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @29_603a50
  if ((eax & eax) == 0) goto L603ae9;  // @30_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @31_603a50
  ecx = edx = 0;  // @32_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @33_603a50
  ebx = (u32)(eax + ebx*8);  // @34_603a50
  goto L603b19;  // @35_603a50
  L603ae9:;
  __builtin_trap();  // @37_603a50
  L603aea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_603a50
  ebx = (u32)(eax + ebx*8);  // @40_603a50
  goto L603b19;  // @41_603a50
  L603af1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @43_603a50
  if ((eax & eax) == 0) goto L603afe;  // @44_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @45_603a50
  ecx = edx = 0;  // @46_603a50
  goto L603aff;  // @47_603a50
  L603afe:;
  __builtin_trap();  // @49_603a50
  L603aff:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_603a50
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; })) goto L603b14;  // @52_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @53_603a50
  if ((eax & eax) == 0) goto L603b13;  // @54_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @55_603a50
  ecx = edx = 0;  // @56_603a50
  goto L603b14;  // @57_603a50
  L603b13:;
  __builtin_trap();  // @59_603a50
  L603b14:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @61_603a50
  ebx = (u32)(eax + esi*8);  // @62_603a50
  L603b19:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @64_603a50
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; })) goto L603b2f;  // @65_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @66_603a50
  if ((eax & eax) == 0) goto L603b2e;  // @67_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @68_603a50
  ecx = edx = 0;  // @69_603a50
  goto L603b2f;  // @70_603a50
  L603b2e:;
  __builtin_trap();  // @72_603a50
  L603b2f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @74_603a50
  edi = (u32)(eax + esi*8);  // @75_603a50
  if (ebx == edi) goto L603b5f;  // @76_603a50
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) != (u32)(4)) goto L603b46;  // @77_603a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @78_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @80_603a50
  ecx = edx = 0;  // @81_603a50
  L603b46:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == (u32)(4)) goto L603b50;  // @83_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @84_603a50
  goto L603b57;  // @85_603a50
  L603b50:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @87_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @89_603a50
  ecx = edx = 0;  // @90_603a50
  L603b57:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @92_603a50
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; })) & 0xff);  // @93_603a50
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @94_603a50
  L603b5f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @96_603a50
  esi = (esi + 1);  // @97_603a50
  if (esi < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; })) goto L603ac0;  // @98_603a50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @99_603a50
  L603b6f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @101_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @102_603a50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) <= (u32)(0)) goto L603b9f;  // @103_603a50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @104_603a50
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_603a50
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; })) goto L603b98;  // @106_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @107_603a50
  if ((eax & eax) == 0) goto L603b97;  // @108_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @109_603a50
  ecx = edx = 0;  // @110_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @111_603a50
  esi = (u32)(eax + ebx*8);  // @112_603a50
  goto L603bc5;  // @113_603a50
  L603b97:;
  __builtin_trap();  // @115_603a50
  L603b98:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_603a50
  esi = (u32)(eax + ebx*8);  // @118_603a50
  goto L603bc5;  // @119_603a50
  L603b9f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @121_603a50
  if ((eax & eax) == 0) goto L603bac;  // @122_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @123_603a50
  ecx = edx = 0;  // @124_603a50
  goto L603bad;  // @125_603a50
  L603bac:;
  __builtin_trap();  // @127_603a50
  L603bad:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_603a50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }) > (u32)(0)) goto L603bc3;  // @130_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @131_603a50
  if ((eax & eax) == 0) goto L603bc2;  // @132_603a50
  eax = ((u32(STDCALL *)(void))(eax))();  // @133_603a50
  ecx = edx = 0;  // @134_603a50
  goto L603bc3;  // @135_603a50
  L603bc2:;
  __builtin_trap();  // @137_603a50
  L603bc3:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @139_603a50
  L603bc5:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; })) & 0xff);  // @141_603a50
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L603bd7;  // @142_603a50
  if ((eax & 0xff) != (u32)(4)) goto L603be4;  // @143_603a50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_603a50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @145_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @146_603a50
  ecx = edx = 0;  // @147_603a50
  L603bd7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @149_603a50
  ecx = edi;  // @150_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 36)))(ecx);  // @151_603a50
  ecx = edx = 0;  // @152_603a50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @153_603a50
  { u8 v = (u8)((u32)(4)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @154_603a50
  L603be4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @156_603a50
  ecx = edi;  // @157_603a50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 40)))(ecx);  // @158_603a50
  ecx = edx = 0;  // @159_603a50
  SEH_LEAVE();  // @160_603a50
  return eax;  // @161_603a50
}
PCREG(603a50, lifted_603a50);

extern "C" u32 THISCALL lifted_4923e0(u32 ecx_in) {
  SEH_ENTER(0x667d9b);  // @h_4923e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_4923e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }) == (u32)(0)) goto L492497;  // @2_4923e0
  eax = ext_41e290_cdecl1((u32)(10000000));  // @3_4923e0
  ecx = edx = 0;  // @4_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @5_4923e0
  edi = eax;  // @6_4923e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_4923e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 20)))(ecx);  // @8_4923e0
  ecx = edx = 0;  // @9_4923e0
  ecx = (u32)(EBP - 332);  // @10_4923e0
  eax = ext_499880_thiscall3(ecx, (u32)(edi), (u32)(10000000));  // @11_4923e0
  ecx = edx = 0;  // @12_4923e0
  ecx = (u32)(EBP - 332);  // @13_4923e0
  reg.state = (s32)((u32)(0));  // @14_4923e0
  eax = ext_49b340_thiscall3(ecx, (u32)(5), (u32)(21));  // @15_4923e0
  ecx = edx = 0;  // @16_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_4923e0
  ecx = (u32)(EBP - 332);  // @18_4923e0
  eax = ext_49a790_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }), (u32)(3));  // @19_4923e0
  ecx = edx = 0;  // @20_4923e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4924b2;  // @21_4923e0
  eax = ext_634273_cdecl2((u32)(edi), (u32)(1));  // @22_4923e0
  ecx = edx = 0;  // @23_4923e0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2994), &v, sizeof v); }  // @24_4923e0
  L49248c:;
  ecx = (u32)(EBP - 332);  // @26_4923e0
  eax = ext_499970_thiscall1(ecx);  // @27_4923e0
  ecx = edx = 0;  // @28_4923e0
  L492497:;
  SEH_LEAVE();  // @30_4923e0
  ext_633654(G(u32, 0x6f5630));  // @31_4923e0
  return eax;  // @32_4923e0
  L4924b2:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @35_4923e0
  if ((ecx & ecx) == 0) goto L4924d2;  // @36_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_4923e0
  edx = (u32)(EBP - 332);  // @38_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(edx));  // @39_4923e0
  ecx = edx = 0;  // @40_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @41_4923e0
  L4924d2:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6815), sizeof v); (u32)v; });  // @43_4923e0
  if ((ecx & ecx) == 0) goto L4924eb;  // @44_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4923e0
  edx = (u32)(EBP - 332);  // @46_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 136)))(ecx, (u32)(edx));  // @47_4923e0
  ecx = edx = 0;  // @48_4923e0
  L4924eb:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @50_4923e0
  eax = (u32)(EBP - 332);  // @51_4923e0
  eax = ext_497990_thiscall2(ecx, (u32)(eax));  // @52_4923e0
  ecx = edx = 0;  // @53_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @55_4923e0
  if ((ecx & ecx) == 0) goto L492515;  // @56_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4923e0
  edx = (u32)(EBP - 332);  // @58_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(edx));  // @59_4923e0
  ecx = edx = 0;  // @60_4923e0
  L492515:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340964), sizeof v); (u32)v; });  // @62_4923e0
  if ((ecx & ecx) == 0) goto L49252e;  // @63_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @64_4923e0
  edx = (u32)(EBP - 332);  // @65_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 212)))(ecx, (u32)(edx));  // @66_4923e0
  ecx = edx = 0;  // @67_4923e0
  L49252e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; }) == (u32)(0)) goto L492556;  // @69_4923e0
  ecx = (u32)(EBP - 332);  // @70_4923e0
  eax = ext_49b2e0_thiscall2(ecx, (u32)(21));  // @71_4923e0
  ecx = edx = 0;  // @72_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @73_4923e0
  edx = (u32)(EBP - 332);  // @74_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(edx));  // @76_4923e0
  ecx = edx = 0;  // @77_4923e0
  L492556:;
  ecx = (u32)(EBP - 332);  // @79_4923e0
  eax = ext_49b2e0_thiscall2(ecx, (u32)(10));  // @80_4923e0
  ecx = edx = 0;  // @81_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_4923e0
  edx = (u32)(EBP - 332);  // @83_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6407), sizeof v); (u32)v; });  // @84_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @85_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 180)))(ecx, (u32)(edx));  // @86_4923e0
  ecx = edx = 0;  // @87_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_4923e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 6827), &v, sizeof v); }  // @89_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @91_4923e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @92_4923e0
  ecx = edx = 0;  // @93_4923e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 3008), &v, sizeof v); }  // @94_4923e0
  eax = ext_634273_cdecl2((u32)(edi), (u32)(1));  // @95_4923e0
  ecx = edx = 0;  // @96_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 200), sizeof v); (u32)v; });  // @97_4923e0
  eax = ext_49d6c0_thiscall1(ecx);  // @98_4923e0
  ecx = edx = 0;  // @99_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @101_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @102_4923e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @103_4923e0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 336), &v, sizeof v); }  // @104_4923e0
  if ((edx & edx) == 0) goto L49248c;  // @105_4923e0
  L4925e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @107_4923e0
  eax = (eax & (u32)(289792));  // @108_4923e0
  if (eax != (u32)(278528)) goto L492606;  // @109_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @110_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 23857), sizeof v); (u32)v; });  // @111_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(edx));  // @113_4923e0
  ecx = edx = 0;  // @114_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @115_4923e0
  L492606:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @117_4923e0
  edx = (u32)(EBP - 336);  // @118_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; });  // @119_4923e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_4923e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edx));  // @121_4923e0
  ecx = edx = 0;  // @122_4923e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 336), sizeof v); (u32)v; });  // @123_4923e0
  if ((edx & edx) == 0) goto L49248c;  // @124_4923e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_4923e0
  goto L4925e0;  // @126_4923e0
}
PCREG(4923e0, lifted_4923e0);

extern "C" u32 THISCALL lifted_6166c0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66e658);  // @h_6166c0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
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
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47524), sizeof v); (u32)v; });  // @13_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @14_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @15_6166c0
  reg.state = (s32)((u32)(0));  // @16_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @17_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @18_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @19_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @20_6166c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @21_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @22_6166c0
  eax = (eax + ecx);  // @23_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @24_6166c0
  eax = ext_659220_thiscall3(ecx, (u32)(eax), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47536), sizeof v); (u32)v; }));  // @25_6166c0
  ecx = edx = 0;  // @26_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @27_6166c0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 14), sizeof v); (u32)v; });  // @28_6166c0
  ecx = edi;  // @29_6166c0
  ebx = eax;  // @30_6166c0
  eax = ext_659330_thiscall3(ecx, (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 47528), sizeof v); (u32)v; }));  // @31_6166c0
  ecx = edx = 0;  // @32_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5114), sizeof v); (u32)v; });  // @33_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @34_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @35_6166c0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @36_6166c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @37_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; }) == (u32)(0)) goto L616815;  // @38_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L6167aa;  // @39_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_6166c0
  ecx = edi;  // @41_6166c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @42_6166c0
  ecx = edx = 0;  // @43_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @44_6166c0
  L6167aa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @46_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 20), sizeof v); (u32)v; });  // @47_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 40), sizeof v); (u32)v; });  // @48_6166c0
  edi = (edi + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @49_6166c0
  ecx = (u32)(eax + eax*8);  // @50_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @51_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 48), sizeof v); (u32)v; });  // @52_6166c0
  eax = (u32)(eax + ecx*4);  // @53_6166c0
  if ((ebx & ebx) == 0) goto L616812;  // @54_6166c0
  edx = (u32)(edi + 12);  // @55_6166c0
  edi = (edi - eax);  // @56_6166c0
  ecx = (u32)(eax + 4);  // @57_6166c0
  L6167d0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 12), sizeof v); (u32)v; });  // @59_6166c0
  edx = (u32)(edx + 36);  // @60_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @61_6166c0
  ecx = (u32)(ecx + 36);  // @62_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx - 36), sizeof v); (u32)v; });  // @63_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 36), &v, sizeof v); }  // @64_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 40), sizeof v); (u32)v; });  // @65_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 32), &v, sizeof v); }  // @66_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 36), sizeof v); (u32)v; });  // @67_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 28), &v, sizeof v); }  // @68_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 32), sizeof v); (u32)v; });  // @69_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 24), &v, sizeof v); }  // @70_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 28), sizeof v); (u32)v; });  // @71_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 20), &v, sizeof v); }  // @72_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 24), sizeof v); (u32)v; });  // @73_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 16), &v, sizeof v); }  // @74_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 20), sizeof v); (u32)v; });  // @75_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 12), &v, sizeof v); }  // @76_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx - 16), sizeof v); (u32)v; });  // @77_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 8), &v, sizeof v); }  // @78_6166c0
  ebx = (ebx - (u32)(1));  // @79_6166c0
  if (ebx != 0) goto L6167d0;  // @80_6166c0
  L616812:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @82_6166c0
  L616815:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; }) == (u32)(0)) goto L61689f;  // @84_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L616834;  // @85_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_6166c0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0), (u32)(0));  // @87_6166c0
  ecx = edx = 0;  // @88_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @89_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @90_6166c0
  L616834:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @92_6166c0
  ebx = 0;  // @93_6166c0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @94_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @95_6166c0
  edi = (edi + (u32)(2));  // @96_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @97_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @98_6166c0
  edi = (edi + eax);  // @99_6166c0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) <= ebx) goto L61689f;  // @100_6166c0
  L616850:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @102_6166c0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @103_6166c0
  edi = (edi + (u32)(2));  // @104_6166c0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP + 12), &v, sizeof v); }  // @105_6166c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + ebx*8 + 4), sizeof v); (u32)v; });  // @106_6166c0
  if ((s32)(eax & eax) >= 0) goto L616896;  // @107_6166c0
  eax = (eax & (u32)(2147483647));  // @108_6166c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + ebx*8 + 4), &v, sizeof v); }  // @109_6166c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @110_6166c0
  ecx = (u32)(ecx + eax*2);  // @111_6166c0
  if ((edx & edx) == 0) goto L616896;  // @112_6166c0
  esi = edi;  // @113_6166c0
  esi = (esi - ecx);  // @114_6166c0
  L616880:;
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + ecx), sizeof v); (u32)v; })) & 0xffff);  // @116_6166c0
  ecx = (u32)(ecx + 2);  // @117_6166c0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(ecx - 2), &v, sizeof v); }  // @118_6166c0
  edx = (edx - (u32)(1));  // @119_6166c0
  if (edx != 0) goto L616880;  // @120_6166c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @121_6166c0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @122_6166c0
  L616896:;
  ebx = (ebx + 1);  // @124_6166c0
  edi = (u32)(edi + edx*2);  // @125_6166c0
  if (ebx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; })) goto L616850;  // @126_6166c0
  L61689f:;
  eax = esi;  // @128_6166c0
  SEH_LEAVE();  // @129_6166c0
  return eax;  // @130_6166c0
}
PCREG(6166c0, lifted_6166c0);

extern "C" u32 THISCALL lifted_4627d0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66693b);  // @h_4627d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @2_4627d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16604), &v, sizeof v); }  // @3_4627d0
  ecx = (u32)(edi + edi*2);  // @4_4627d0
  ecx = (u32)(eax + ecx*8);  // @5_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @6_4627d0
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4629f7;  // @7_4627d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @8_4627d0
  eax = (eax & (u32)(4294967292));  // @9_4627d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 16600), &v, sizeof v); }  // @10_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @11_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @12_4627d0
  ecx = esi;  // @13_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @14_4627d0
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16612), &v, sizeof v); }  // @15_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @16_4627d0
  ecx = edx = 0;  // @17_4627d0
  edi = (u32)(edi + edi*2);  // @18_4627d0
  edi = (edi + edi);  // @19_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 47), sizeof v); (u32)v; }) == (u32)(3)) goto L462909;  // @20_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L462909;  // @21_4627d0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 112), sizeof v); (u32)v; }) != (u32)(0)) goto L462909;  // @22_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @23_4627d0
  ecx = esi;  // @24_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @25_4627d0
  ecx = edx = 0;  // @26_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + edi*8 + 12), sizeof v); (u32)v; });  // @27_4627d0
  if ((s32)(edi & edi) < 0) goto L462909;  // @28_4627d0
  L462880:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @30_4627d0
  ecx = (u32)(edi + edi*2);  // @31_4627d0
  ebx = (u32)(eax + ecx*8);  // @32_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @33_4627d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16608), &v, sizeof v); }  // @34_4627d0
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L4628a1;  // @35_4627d0
  if (eax != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; })) goto L4628ba;  // @36_4627d0
  L4628a1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4627d0
  ecx = esi;  // @39_4627d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 716)))(ecx);  // @40_4627d0
  ecx = edx = 0;  // @41_4627d0
  ecx = (u32)(edi + edi*2);  // @42_4627d0
  ecx = (ecx + ecx);  // @43_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*8 + 12), sizeof v); (u32)v; });  // @44_4627d0
  if ((s32)(edi & edi) >= 0) goto L462880;  // @45_4627d0
  goto L462903;  // @46_4627d0
  L4628ba:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_4627d0
  ecx = esi;  // @49_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 700)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }));  // @50_4627d0
  ecx = edx = 0;  // @51_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 92), sizeof v); (u32)v; });  // @52_4627d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16608), sizeof v); (u32)v; });  // @53_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 48)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(eax));  // @55_4627d0
  ecx = edx = 0;  // @56_4627d0
  ecx = eax;  // @57_4627d0
  if ((ecx & ecx) == 0) goto L462903;  // @58_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 848), sizeof v); (u32)v; });  // @60_4627d0
  ecx = esi;  // @61_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(eax))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 112), sizeof v); (u32)v; }), (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16604), sizeof v); (u32)v; }), (u32)(edi));  // @62_4627d0
  ecx = edx = 0;  // @63_4627d0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L462903;  // @64_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 20), sizeof v); (u32)v; });  // @65_4627d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 68), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 68), &v, sizeof v); }  // @66_4627d0
  L462903:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16600), sizeof v); (u32)v; });  // @68_4627d0
  L462909:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) + (u32)(-1))); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @70_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }) != 0) goto L4629f7;  // @71_4627d0
  ecx = (u32)(EBP - 16596);  // @72_4627d0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(ebx + 68), &v, sizeof v); }  // @73_4627d0
  eax = ext_4d2280_thiscall1(ecx);  // @74_4627d0
  ecx = edx = 0;  // @75_4627d0
  edi = (u32)(ebx + 76);  // @76_4627d0
  reg.state = (s32)((u32)(0));  // @77_4627d0
  ecx = (u32)(EBP - 16596);  // @78_4627d0
  eax = ext_4d39a0_stdcall2((u32)(6838552), (u32)(edi));  // @79_4627d0
  ecx = edx = 0;  // @80_4627d0
  ecx = (u32)(EBP - 16596);  // @81_4627d0
  eax = ext_4d3ab0_stdcall2((u32)(6838564), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }));  // @82_4627d0
  ecx = edx = 0;  // @83_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @84_4627d0
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; }) & (u32)(8388608)) == 0) goto L462979;  // @85_4627d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_4627d0
  eax = (u32)(EBP - 16596);  // @87_4627d0
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 296), sizeof v); (u32)v; });  // @88_4627d0
  ecx = esi;  // @89_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 304)))(ecx, (u32)(esi), (u32)(eax), (u32)(eax));  // @90_4627d0
  ecx = edx = 0;  // @91_4627d0
  L462979:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @93_4627d0
  ecx = esi;  // @94_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 836)))(ecx, (u32)(edi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16612), sizeof v); (u32)v; }));  // @95_4627d0
  ecx = edx = 0;  // @96_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @97_4627d0
  ebx = (ebx & 0xffffff00u) | ((0) & 0xff);  // @98_4627d0
  if ((ecx & ecx) == 0) goto L4629ec;  // @99_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_4627d0
  edx = (u32)(EBP - 16624);  // @101_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(edx));  // @102_4627d0
  ecx = edx = 0;  // @103_4627d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @104_4627d0
  edx = (u32)(EBP - 16624);  // @105_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @106_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @107_4627d0
  ecx = edx = 0;  // @108_4627d0
  edx = eax;  // @109_4627d0
  if ((edx & edx) == 0) goto L4629ec;  // @110_4627d0
  L4629b4:;
  ecx = (u32)(edx + 4);  // @112_4627d0
  if (((ebx & 0xff) & (ebx & 0xff)) != 0) goto L4629d7;  // @113_4627d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 68), sizeof v); (u32)v; }) != (u32)(-2)) goto L4629d7;  // @114_4627d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 68), &v, sizeof v); }  // @115_4627d0
  ebx = (ebx & 0xffffff00u) | (((u32)(1)) & 0xff);  // @116_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @117_4627d0
  ecx = esi;  // @118_4627d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 844)))(ecx, (u32)(ecx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }));  // @119_4627d0
  ecx = edx = 0;  // @120_4627d0
  L4629d7:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; });  // @122_4627d0
  edx = (u32)(EBP - 16624);  // @123_4627d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_4627d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(edx));  // @125_4627d0
  ecx = edx = 0;  // @126_4627d0
  edx = eax;  // @127_4627d0
  if ((edx & edx) != 0) goto L4629b4;  // @128_4627d0
  L4629ec:;
  ecx = (u32)(EBP - 16596);  // @130_4627d0
  eax = ext_4d2330_thiscall1(ecx);  // @131_4627d0
  ecx = edx = 0;  // @132_4627d0
  L4629f7:;
  SEH_LEAVE();  // @134_4627d0
  ext_633654(G(u32, 0x6f5630));  // @135_4627d0
  return eax;  // @136_4627d0
}
PCREG(4627d0, lifted_4627d0);

extern "C" u32 THISCALL lifted_46bf20(u32 ecx_in) {
  SEH_ENTER(0x666d98);  // @h_46bf20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_46bf20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 276), &v, sizeof v); }  // @1_46bf20
  eax = ext_46bca0_cdecl0();  // @2_46bf20
  ecx = edx = 0;  // @3_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @6_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6851000), (u32)(6852056));  // @8_46bf20
  ecx = edx = 0;  // @9_46bf20
  edx = eax;  // @10_46bf20
  ecx = edi;  // @11_46bf20
  eax = ext_49f9b0_fastcall8(ecx, edx, (u32)(eax), (u32)(7), (u32)(0), (u32)(0), (u32)(150), (u32)(0));  // @12_46bf20
  ecx = edx = 0;  // @13_46bf20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 148), sizeof v); (u32)v; });  // @14_46bf20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 142), &v, sizeof v); }  // @15_46bf20
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 284), &v, sizeof v); }  // @16_46bf20
  eax = ext_41e290_cdecl1((u32)(28));  // @17_46bf20
  ecx = edx = 0;  // @18_46bf20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @19_46bf20
  reg.state = (s32)((u32)(0));  // @20_46bf20
  if ((eax & eax) == 0) goto L46bfcb;  // @21_46bf20
  ecx = eax;  // @22_46bf20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @23_46bf20
  ecx = edx = 0;  // @24_46bf20
  goto L46bfcd;  // @25_46bf20
  L46bfcb:;
  eax = 0;  // @27_46bf20
  L46bfcd:;
  reg.state = (s32)((u32)(4294967295));  // @29_46bf20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 148), &v, sizeof v); }  // @30_46bf20
  if ((ebx & ebx) == 0) goto L46c0a0;  // @31_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_46bf20
  ecx = (u32)(EBP - 296);  // @33_46bf20
  ecx = ebx;  // @34_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @35_46bf20
  ecx = edx = 0;  // @36_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_46bf20
  ecx = (u32)(EBP - 296);  // @38_46bf20
  ecx = ebx;  // @39_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @40_46bf20
  ecx = edx = 0;  // @41_46bf20
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L46c0a0;  // @42_46bf20
  L46c010:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @44_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @45_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @46_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(eax));  // @47_46bf20
  ecx = edx = 0;  // @48_46bf20
  esi = eax;  // @49_46bf20
  if ((esi & esi) == 0) goto L46c085;  // @50_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_46bf20
  ecx = esi;  // @52_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @53_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050579));  // @54_46bf20
  ecx = edx = 0;  // @55_46bf20
  ecx = esi;  // @56_46bf20
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L46c0bc;  // @57_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @58_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 708)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2780), sizeof v); (u32)v; }), (u32)(1230259533));  // @61_46bf20
  ecx = edx = 0;  // @62_46bf20
  esi = eax;  // @63_46bf20
  L46c05f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @65_46bf20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(esi));  // @69_46bf20
  ecx = edx = 0;  // @70_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @71_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 800)))(ecx, (u32)(eax));  // @72_46bf20
  ecx = edx = 0;  // @73_46bf20
  L46c07f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @75_46bf20
  L46c085:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @77_46bf20
  ecx = (u32)(EBP - 296);  // @78_46bf20
  ecx = ebx;  // @79_46bf20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @80_46bf20
  ecx = edx = 0;  // @81_46bf20
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) != (u32)(0)) goto L46c010;  // @82_46bf20
  L46c0a0:;
  SEH_LEAVE();  // @84_46bf20
  ext_633654(G(u32, 0x6f5630));  // @85_46bf20
  return eax;  // @86_46bf20
  L46c0bc:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @89_46bf20
  eax = ((u32(STDCALL *)(u32))(eax))((u32)(1050577));  // @90_46bf20
  ecx = edx = 0;  // @91_46bf20
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L46c05f;  // @92_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @93_46bf20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(3792));  // @95_46bf20
  ecx = edx = 0;  // @96_46bf20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; });  // @97_46bf20
  edi = eax;  // @98_46bf20
  eax = (u32)(EBP - 272);  // @99_46bf20
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @100_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @101_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @102_46bf20
  ecx = edx = 0;  // @103_46bf20
  ebx = eax;  // @104_46bf20
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @105_46bf20
  eax = (u32)(EBP - 144);  // @106_46bf20
  ecx = esi;  // @107_46bf20
  reg.state = (s32)((u32)(1));  // @108_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @109_46bf20
  ecx = edx = 0;  // @110_46bf20
  esi = eax;  // @111_46bf20
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @112_46bf20
  ecx = ebx;  // @113_46bf20
  reg.state = (s32)((u32)(2));  // @114_46bf20
  eax = ext_4cc1d0_thiscall1(ecx);  // @115_46bf20
  ecx = edx = 0;  // @116_46bf20
  ecx = esi;  // @117_46bf20
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @118_46bf20
  ecx = edx = 0;  // @119_46bf20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }), (u32)(6852072), (u32)(eax));  // @120_46bf20
  ecx = edx = 0;  // @121_46bf20
  ecx = (u32)(EBP - 144);  // @122_46bf20
  eax = ext_4cbec0_thiscall1(ecx);  // @123_46bf20
  ecx = edx = 0;  // @124_46bf20
  ecx = (u32)(EBP - 272);  // @125_46bf20
  reg.state = (s32)((u32)(4294967295));  // @126_46bf20
  eax = ext_4cbec0_thiscall1(ecx);  // @127_46bf20
  ecx = edx = 0;  // @128_46bf20
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 284), sizeof v); (u32)v; });  // @129_46bf20
  goto L46c07f;  // @130_46bf20
}
PCREG(46bf20, lifted_46bf20);

extern "C" u32 THISCALL lifted_4335e0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665608);  // @h_4335e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_4335e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @1_4335e0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_4335e0
  esi = (esi + (u32)(200));  // @3_4335e0
  if (esi == 0) goto L43370a;  // @4_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_4335e0
  ecx = (u32)(EBP - 416);  // @6_4335e0
  ecx = esi;  // @7_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @8_4335e0
  ecx = edx = 0;  // @9_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_4335e0
  ecx = (u32)(EBP - 416);  // @11_4335e0
  ecx = esi;  // @12_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(ecx));  // @13_4335e0
  ecx = edx = 0;  // @14_4335e0
  edi = eax;  // @15_4335e0
  if ((edi & edi) == 0) goto L43370a;  // @16_4335e0
  L433650:;
  ecx = (u32)(EBP - 144);  // @18_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791768));  // @19_4335e0
  ecx = edx = 0;  // @20_4335e0
  eax = (u32)(EBP - 144);  // @21_4335e0
  reg.state = (s32)((u32)(0));  // @22_4335e0
  ecx = ebx;  // @23_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @24_4335e0
  ecx = edx = 0;  // @25_4335e0
  ecx = (u32)(EBP - 144);  // @26_4335e0
  reg.state = (s32)((u32)(4294967295));  // @27_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @28_4335e0
  ecx = edx = 0;  // @29_4335e0
  ecx = (u32)(EBP - 144);  // @30_4335e0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @31_4335e0
  ecx = edx = 0;  // @32_4335e0
  eax = (u32)(EBP - 144);  // @33_4335e0
  reg.state = (s32)((u32)(1));  // @34_4335e0
  ecx = ebx;  // @35_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @36_4335e0
  ecx = edx = 0;  // @37_4335e0
  ecx = (u32)(EBP - 144);  // @38_4335e0
  reg.state = (s32)((u32)(4294967295));  // @39_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @40_4335e0
  ecx = edx = 0;  // @41_4335e0
  ecx = (u32)(EBP - 144);  // @42_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6778092));  // @43_4335e0
  ecx = edx = 0;  // @44_4335e0
  eax = (u32)(EBP - 144);  // @45_4335e0
  reg.state = (s32)((u32)(2));  // @46_4335e0
  ecx = ebx;  // @47_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @48_4335e0
  ecx = edx = 0;  // @49_4335e0
  ecx = (u32)(EBP - 144);  // @50_4335e0
  reg.state = (s32)((u32)(4294967295));  // @51_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @52_4335e0
  ecx = edx = 0;  // @53_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @54_4335e0
  ecx = (u32)(EBP - 416);  // @55_4335e0
  ecx = esi;  // @56_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(ecx));  // @57_4335e0
  ecx = edx = 0;  // @58_4335e0
  edi = eax;  // @59_4335e0
  if ((edi & edi) != 0) goto L433650;  // @60_4335e0
  L43370a:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @62_4335e0
  esi = (esi + (u32)(172));  // @63_4335e0
  if (esi == 0) goto L43386c;  // @64_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_4335e0
  ecx = (u32)(EBP - 428);  // @66_4335e0
  ecx = esi;  // @67_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @68_4335e0
  ecx = edx = 0;  // @69_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_4335e0
  ecx = (u32)(EBP - 428);  // @71_4335e0
  ecx = esi;  // @72_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(ecx));  // @73_4335e0
  ecx = edx = 0;  // @74_4335e0
  edi = eax;  // @75_4335e0
  if ((edi & edi) == 0) goto L43386c;  // @76_4335e0
  L433750:;
  ecx = (u32)(EBP - 144);  // @78_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791760));  // @79_4335e0
  ecx = edx = 0;  // @80_4335e0
  eax = (u32)(EBP - 144);  // @81_4335e0
  reg.state = (s32)((u32)(3));  // @82_4335e0
  ecx = ebx;  // @83_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @84_4335e0
  ecx = edx = 0;  // @85_4335e0
  ecx = (u32)(EBP - 144);  // @86_4335e0
  reg.state = (s32)((u32)(4294967295));  // @87_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @88_4335e0
  ecx = edx = 0;  // @89_4335e0
  ecx = (u32)(EBP - 144);  // @90_4335e0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; }));  // @91_4335e0
  ecx = edx = 0;  // @92_4335e0
  eax = (u32)(EBP - 144);  // @93_4335e0
  reg.state = (s32)((u32)(4));  // @94_4335e0
  ecx = ebx;  // @95_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @96_4335e0
  ecx = edx = 0;  // @97_4335e0
  ecx = (u32)(EBP - 144);  // @98_4335e0
  reg.state = (s32)((u32)(4294967295));  // @99_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @100_4335e0
  ecx = edx = 0;  // @101_4335e0
  ecx = (u32)(EBP - 144);  // @102_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6791776));  // @103_4335e0
  ecx = edx = 0;  // @104_4335e0
  eax = (u32)(EBP - 144);  // @105_4335e0
  reg.state = (s32)((u32)(5));  // @106_4335e0
  ecx = ebx;  // @107_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @108_4335e0
  ecx = edx = 0;  // @109_4335e0
  ecx = (u32)(EBP - 144);  // @110_4335e0
  reg.state = (s32)((u32)(4294967295));  // @111_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @112_4335e0
  ecx = edx = 0;  // @113_4335e0
  ecx = (u32)(EBP - 400);  // @114_4335e0
  eax = ext_4cbe50_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }));  // @115_4335e0
  ecx = edx = 0;  // @116_4335e0
  eax = (u32)(EBP - 400);  // @117_4335e0
  reg.state = (s32)((u32)(6));  // @118_4335e0
  ecx = ebx;  // @119_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @120_4335e0
  ecx = edx = 0;  // @121_4335e0
  ecx = (u32)(EBP - 272);  // @122_4335e0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6778092));  // @123_4335e0
  ecx = edx = 0;  // @124_4335e0
  eax = (u32)(EBP - 272);  // @125_4335e0
  reg.state = (s32)((u32)(7));  // @126_4335e0
  ecx = ebx;  // @127_4335e0
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(eax));  // @128_4335e0
  ecx = edx = 0;  // @129_4335e0
  ecx = (u32)(EBP - 272);  // @130_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @131_4335e0
  ecx = edx = 0;  // @132_4335e0
  ecx = (u32)(EBP - 400);  // @133_4335e0
  reg.state = (s32)((u32)(4294967295));  // @134_4335e0
  eax = ext_4cbec0_thiscall1(ecx);  // @135_4335e0
  ecx = edx = 0;  // @136_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @137_4335e0
  ecx = (u32)(EBP - 428);  // @138_4335e0
  ecx = esi;  // @139_4335e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(ecx));  // @140_4335e0
  ecx = edx = 0;  // @141_4335e0
  edi = eax;  // @142_4335e0
  if ((edi & edi) != 0) goto L433750;  // @143_4335e0
  L43386c:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @145_4335e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_4335e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6791032), (u32)(1134));  // @147_4335e0
  ecx = edx = 0;  // @148_4335e0
  esi = eax;  // @149_4335e0
  ecx = ebx;  // @150_4335e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @151_4335e0
  eax = ext_4cc1d0_thiscall1(ecx);  // @152_4335e0
  ecx = edx = 0;  // @153_4335e0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(esi), (u32)(6791780), (u32)(eax));  // @154_4335e0
  ecx = edx = 0;  // @155_4335e0
  SEH_LEAVE();  // @156_4335e0
  ext_633654(G(u32, 0x6f5630));  // @157_4335e0
  return eax;  // @158_4335e0
}
PCREG(4335e0, lifted_4335e0);

extern "C" u32 THISCALL lifted_42a820(u32 ecx_in) {
  SEH_ENTER(0x66496c);  // @h_42a820
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edi = ecx;  // @0_42a820
  eax = ext_42de30_thiscall1(ecx);  // @1_42a820
  ecx = edx = 0;  // @2_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_42a820
  edx = (u32)(EBP - 276);  // @4_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @5_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @6_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783396), (u32)(edx));  // @7_42a820
  ecx = edx = 0;  // @8_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a875;  // @9_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @10_42a820
  L42a875:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @12_42a820
  edx = (u32)(EBP - 276);  // @13_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @15_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783568), (u32)(edx));  // @16_42a820
  ecx = edx = 0;  // @17_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a8da;  // @18_42a820
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7003), sizeof v); (u32)v; }) == (u32)(0)) goto L42a8c9;  // @19_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @20_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6788896), (u32)(80));  // @22_42a820
  ecx = edx = 0;  // @23_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @24_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6783580));  // @25_42a820
  ecx = edx = 0;  // @26_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @27_42a820
  if ((eax & eax) == 0) goto L42a8c8;  // @28_42a820
  eax = ((u32(STDCALL *)(void))(eax))();  // @29_42a820
  ecx = edx = 0;  // @30_42a820
  goto L42a8c9;  // @31_42a820
  L42a8c8:;
  __builtin_trap();  // @33_42a820
  L42a8c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @35_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_42a820
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 120)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @37_42a820
  ecx = edx = 0;  // @38_42a820
  L42a8da:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @40_42a820
  edx = (u32)(EBP - 276);  // @41_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @42_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @43_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783656), (u32)(edx));  // @44_42a820
  ecx = edx = 0;  // @45_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a933;  // @46_42a820
  ecx = (u32)(EBP - 144);  // @47_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @48_42a820
  ecx = edx = 0;  // @49_42a820
  eax = (u32)(EBP - 144);  // @50_42a820
  reg.state = (s32)((u32)(0));  // @51_42a820
  ecx = (u32)(edi + 7153);  // @52_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @53_42a820
  ecx = edx = 0;  // @54_42a820
  ecx = (u32)(EBP - 144);  // @55_42a820
  reg.state = (s32)((u32)(4294967295));  // @56_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @57_42a820
  ecx = edx = 0;  // @58_42a820
  L42a933:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_42a820
  edx = (u32)(EBP - 276);  // @61_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @63_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783668), (u32)(edx));  // @64_42a820
  ecx = edx = 0;  // @65_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42a99a;  // @66_42a820
  ecx = (u32)(EBP - 144);  // @67_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @68_42a820
  ecx = edx = 0;  // @69_42a820
  eax = (u32)(EBP - 144);  // @70_42a820
  reg.state = (s32)((u32)(1));  // @71_42a820
  esi = (u32)(edi + 7025);  // @72_42a820
  ecx = esi;  // @73_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @74_42a820
  ecx = edx = 0;  // @75_42a820
  ecx = (u32)(EBP - 144);  // @76_42a820
  reg.state = (s32)((u32)(4294967295));  // @77_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @78_42a820
  ecx = edx = 0;  // @79_42a820
  ecx = edi;  // @80_42a820
  eax = ext_42da80_stdcall1((u32)(esi));  // @81_42a820
  ecx = edx = 0;  // @82_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @83_42a820
  L42a99a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @85_42a820
  edx = (u32)(EBP - 276);  // @86_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @88_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783676), (u32)(edx));  // @89_42a820
  ecx = edx = 0;  // @90_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @91_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @92_42a820
  edx = (u32)(EBP - 276);  // @93_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @95_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783684), (u32)(edx));  // @96_42a820
  ecx = edx = 0;  // @97_42a820
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L42a9f1;  // @98_42a820
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @99_42a820
  edx = (u32)(EBP - 276);  // @100_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @101_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @102_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783696), (u32)(edx));  // @103_42a820
  ecx = edx = 0;  // @104_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aa3b;  // @105_42a820
  L42a9f1:;
  ecx = (u32)(EBP - 144);  // @107_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @108_42a820
  ecx = edx = 0;  // @109_42a820
  eax = (u32)(EBP - 144);  // @110_42a820
  reg.state = (s32)((u32)(2));  // @111_42a820
  esi = (u32)(edi + 7025);  // @112_42a820
  ecx = esi;  // @113_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @114_42a820
  ecx = edx = 0;  // @115_42a820
  ecx = (u32)(EBP - 144);  // @116_42a820
  reg.state = (s32)((u32)(4294967295));  // @117_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @118_42a820
  ecx = edx = 0;  // @119_42a820
  ecx = edi;  // @120_42a820
  eax = ext_42da80_stdcall1((u32)(esi));  // @121_42a820
  ecx = edx = 0;  // @122_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @123_42a820
  L42aa3b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @125_42a820
  edx = (u32)(EBP - 276);  // @126_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_42a820
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @128_42a820
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(6783708), (u32)(edx));  // @129_42a820
  ecx = edx = 0;  // @130_42a820
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L42aaa2;  // @131_42a820
  ecx = (u32)(EBP - 272);  // @132_42a820
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @133_42a820
  ecx = edx = 0;  // @134_42a820
  eax = (u32)(EBP - 272);  // @135_42a820
  reg.state = (s32)((u32)(3));  // @136_42a820
  esi = (u32)(edi + 7025);  // @137_42a820
  ecx = esi;  // @138_42a820
  eax = ext_4cbee0_thiscall2(ecx, (u32)(eax));  // @139_42a820
  ecx = edx = 0;  // @140_42a820
  ecx = (u32)(EBP - 272);  // @141_42a820
  reg.state = (s32)((u32)(4294967295));  // @142_42a820
  eax = ext_4cbec0_thiscall1(ecx);  // @143_42a820
  ecx = edx = 0;  // @144_42a820
  ecx = edi;  // @145_42a820
  eax = ext_42da80_stdcall1((u32)(esi));  // @146_42a820
  ecx = edx = 0;  // @147_42a820
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(edi + 98), &v, sizeof v); }  // @148_42a820
  L42aaa2:;
  SEH_LEAVE();  // @150_42a820
  ext_633654(G(u32, 0x6f5630));  // @151_42a820
  return eax;  // @152_42a820
}
PCREG(42a820, lifted_42a820);

extern "C" u32 THISCALL lifted_471b50(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666f28);  // @h_471b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_471b50
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_471b50
  eax = ext_468030_thiscall4(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));  // @2_471b50
  ecx = edx = 0;  // @3_471b50
  ecx = (u32)(esi + 618);  // @4_471b50
  reg.state = (s32)((u32)(0));  // @5_471b50
  { u32 v = (u32)((u32)(6852772)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_471b50
  eax = ext_465650_thiscall1(ecx);  // @7_471b50
  ecx = edx = 0;  // @8_471b50
  ecx = (u32)(esi + 747);  // @9_471b50
  eax = ext_465650_thiscall1(ecx);  // @10_471b50
  ecx = edx = 0;  // @11_471b50
  { u32 v = (u32)((u32)(6852736)); __builtin_memcpy((void *)(u32)(esi + 743), &v, sizeof v); }  // @12_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 833), &v, sizeof v); }  // @13_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 837), &v, sizeof v); }  // @14_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 841), &v, sizeof v); }  // @15_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @16_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @17_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854220), (u32)(0), (u32)(6854172), (u32)(19));  // @19_471b50
  ecx = edx = 0;  // @20_471b50
  ecx = (u32)(esi + 851);  // @21_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 845), &v, sizeof v); }  // @22_471b50
  { u32 v = (u32)((u32)(17)); __builtin_memcpy((void *)(u32)(esi + 829), &v, sizeof v); }  // @23_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 824), &v, sizeof v); }  // @24_471b50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 828), &v, sizeof v); }  // @25_471b50
  eax = ext_465650_thiscall1(ecx);  // @26_471b50
  ecx = edx = 0;  // @27_471b50
  { u32 v = (u32)((u32)(6852736)); __builtin_memcpy((void *)(u32)(esi + 847), &v, sizeof v); }  // @28_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 937), &v, sizeof v); }  // @29_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 941), &v, sizeof v); }  // @30_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 945), &v, sizeof v); }  // @31_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @32_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @33_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854248), (u32)(0), (u32)(6854172), (u32)(21));  // @35_471b50
  ecx = edx = 0;  // @36_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 949), &v, sizeof v); }  // @37_471b50
  { u32 v = (u32)((u32)(21)); __builtin_memcpy((void *)(u32)(esi + 933), &v, sizeof v); }  // @38_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 928), &v, sizeof v); }  // @39_471b50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 932), &v, sizeof v); }  // @40_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 833), &v, sizeof v); }  // @41_471b50
  { u32 v = (u32)((u32)(3229614080)); __builtin_memcpy((void *)(u32)(esi + 837), &v, sizeof v); }  // @42_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 841), &v, sizeof v); }  // @43_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1002), &v, sizeof v); }  // @44_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1006), &v, sizeof v); }  // @45_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1010), &v, sizeof v); }  // @46_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1014), &v, sizeof v); }  // @47_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1018), &v, sizeof v); }  // @48_471b50
  { u32 v = (u32)((u32)(1082130432)); __builtin_memcpy((void *)(u32)(esi + 1022), &v, sizeof v); }  // @49_471b50
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 1026), &v, sizeof v); }  // @50_471b50
  { u32 v = (u32)((u32)(1097859072)); __builtin_memcpy((void *)(u32)(esi + 1030), &v, sizeof v); }  // @51_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1034), &v, sizeof v); }  // @52_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1038), &v, sizeof v); }  // @53_471b50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 955), &v, sizeof v); }  // @54_471b50
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1000), &v, sizeof v); }  // @55_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 951), &v, sizeof v); }  // @56_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 739), &v, sizeof v); }  // @57_471b50
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 482), &v, sizeof v); }  // @58_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 486), &v, sizeof v); }  // @59_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 956), &v, sizeof v); }  // @60_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 960), &v, sizeof v); }  // @61_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 964), &v, sizeof v); }  // @62_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 968), &v, sizeof v); }  // @63_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 972), &v, sizeof v); }  // @64_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 976), &v, sizeof v); }  // @65_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 980), &v, sizeof v); }  // @66_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 984), &v, sizeof v); }  // @67_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 988), &v, sizeof v); }  // @68_471b50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 992), &v, sizeof v); }  // @69_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @71_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854340), (u32)(0), (u32)(6854172), (u32)(190));  // @73_471b50
  ecx = edx = 0;  // @74_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338400), &v, sizeof v); }  // @75_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @76_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @77_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @78_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854356), (u32)(0), (u32)(6854172), (u32)(191));  // @79_471b50
  ecx = edx = 0;  // @80_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338404), &v, sizeof v); }  // @81_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @82_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @83_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @84_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854372), (u32)(0), (u32)(6854172), (u32)(192));  // @85_471b50
  ecx = edx = 0;  // @86_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338408), &v, sizeof v); }  // @87_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @88_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @89_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @90_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854384), (u32)(0), (u32)(6854172), (u32)(193));  // @91_471b50
  ecx = edx = 0;  // @92_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338412), &v, sizeof v); }  // @93_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @94_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @95_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @96_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854400), (u32)(0), (u32)(6854172), (u32)(194));  // @97_471b50
  ecx = edx = 0;  // @98_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338416), &v, sizeof v); }  // @99_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854420), (u32)(0), (u32)(6854172), (u32)(195));  // @103_471b50
  ecx = edx = 0;  // @104_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338420), &v, sizeof v); }  // @105_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @106_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @107_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @108_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854440), (u32)(0), (u32)(6854172), (u32)(196));  // @109_471b50
  ecx = edx = 0;  // @110_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338424), &v, sizeof v); }  // @111_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @112_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @113_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @114_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854460), (u32)(0), (u32)(6854172), (u32)(197));  // @115_471b50
  ecx = edx = 0;  // @116_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 357), &v, sizeof v); }  // @117_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @118_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @119_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @120_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854476), (u32)(0), (u32)(6854172), (u32)(198));  // @121_471b50
  ecx = edx = 0;  // @122_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338428), &v, sizeof v); }  // @123_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @124_471b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @125_471b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @126_471b50
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854496), (u32)(0), (u32)(6854172), (u32)(201));  // @127_471b50
  ecx = edx = 0;  // @128_471b50
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7338396), &v, sizeof v); }  // @129_471b50
  eax = esi;  // @130_471b50
  SEH_LEAVE();  // @131_471b50
  return eax;  // @132_471b50
}
PCREG(471b50, lifted_471b50);

extern "C" u32 THISCALL lifted_5b8b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x663fdf);  // @h_5b8b50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_5b8b50
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5b8b50
  eax = (u32)(esi + 72);  // @2_5b8b50
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @3_5b8b50
  ecx = edi;  // @4_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @6_5b8b50
  ecx = edx = 0;  // @7_5b8b50
  eax = ext_41e290_cdecl1((u32)(28));  // @8_5b8b50
  ecx = edx = 0;  // @9_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @10_5b8b50
  reg.state = (s32)((u32)(0));  // @11_5b8b50
  if ((eax & eax) == 0) goto L5b8bb0;  // @12_5b8b50
  ecx = eax;  // @13_5b8b50
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @14_5b8b50
  ecx = edx = 0;  // @15_5b8b50
  ecx = eax;  // @16_5b8b50
  goto L5b8bb2;  // @17_5b8b50
  L5b8bb0:;
  ecx = 0;  // @19_5b8b50
  L5b8bb2:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @21_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @22_5b8b50
  ecx = edi;  // @23_5b8b50
  reg.state = (s32)((u32)(4294967295));  // @24_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, (u32)(ecx));  // @25_5b8b50
  ecx = edx = 0;  // @26_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_5b8b50
  eax = (u32)(esi + 80);  // @28_5b8b50
  ecx = edi;  // @29_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @30_5b8b50
  ecx = edx = 0;  // @31_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_5b8b50
  eax = (u32)(esi + 84);  // @33_5b8b50
  ecx = edi;  // @34_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @35_5b8b50
  ecx = edx = 0;  // @36_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @37_5b8b50
  eax = (u32)(esi + 88);  // @38_5b8b50
  ecx = edi;  // @39_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @40_5b8b50
  ecx = edx = 0;  // @41_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @42_5b8b50
  eax = (u32)(esi + 92);  // @43_5b8b50
  ecx = edi;  // @44_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @45_5b8b50
  ecx = edx = 0;  // @46_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @47_5b8b50
  ecx = (u32)(EBP + 8);  // @48_5b8b50
  ecx = edi;  // @49_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @50_5b8b50
  ecx = edx = 0;  // @51_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @55_5b8b50
  ecx = edx = 0;  // @56_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 126), &v, sizeof v); }  // @57_5b8b50
  ecx = (u32)(EBP + 8);  // @58_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @59_5b8b50
  ecx = edi;  // @60_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @61_5b8b50
  ecx = edx = 0;  // @62_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @63_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @64_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @66_5b8b50
  ecx = edx = 0;  // @67_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 130), &v, sizeof v); }  // @68_5b8b50
  ecx = (u32)(EBP + 8);  // @69_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_5b8b50
  ecx = edi;  // @71_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @72_5b8b50
  ecx = edx = 0;  // @73_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @74_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @75_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @76_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @77_5b8b50
  ecx = edx = 0;  // @78_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 134), &v, sizeof v); }  // @79_5b8b50
  ecx = edi;  // @80_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_5b8b50
  eax = (u32)(esi + 138);  // @82_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @83_5b8b50
  ecx = edx = 0;  // @84_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @85_5b8b50
  eax = (u32)(esi + 150);  // @86_5b8b50
  ecx = edi;  // @87_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @88_5b8b50
  ecx = edx = 0;  // @89_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @90_5b8b50
  eax = (u32)(esi + 162);  // @91_5b8b50
  ecx = edi;  // @92_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @93_5b8b50
  ecx = edx = 0;  // @94_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @95_5b8b50
  eax = (u32)(esi + 174);  // @96_5b8b50
  ecx = edi;  // @97_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @98_5b8b50
  ecx = edx = 0;  // @99_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @100_5b8b50
  eax = (u32)(esi + 178);  // @101_5b8b50
  ecx = edi;  // @102_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @103_5b8b50
  ecx = edx = 0;  // @104_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @105_5b8b50
  eax = (u32)(esi + 179);  // @106_5b8b50
  ecx = edi;  // @107_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @108_5b8b50
  ecx = edx = 0;  // @109_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @110_5b8b50
  eax = (u32)(esi + 183);  // @111_5b8b50
  ecx = edi;  // @112_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 116)))(ecx, (u32)(eax));  // @113_5b8b50
  ecx = edx = 0;  // @114_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @115_5b8b50
  ecx = (u32)(EBP + 8);  // @116_5b8b50
  ecx = edi;  // @117_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @118_5b8b50
  ecx = edx = 0;  // @119_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @120_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @121_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @122_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @123_5b8b50
  ecx = edx = 0;  // @124_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @125_5b8b50
  ecx = edi;  // @126_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @127_5b8b50
  eax = (u32)(esi + 222);  // @128_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @129_5b8b50
  ecx = edx = 0;  // @130_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @131_5b8b50
  ecx = (u32)(EBP + 8);  // @132_5b8b50
  ecx = edi;  // @133_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @134_5b8b50
  ecx = edx = 0;  // @135_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @136_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @137_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @138_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @139_5b8b50
  ecx = edx = 0;  // @140_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 226), &v, sizeof v); }  // @141_5b8b50
  ecx = (u32)(EBP - 16);  // @142_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @143_5b8b50
  ecx = edi;  // @144_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @145_5b8b50
  ecx = edx = 0;  // @146_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @147_5b8b50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @148_5b8b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @149_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @150_5b8b50
  ecx = edx = 0;  // @151_5b8b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 230), &v, sizeof v); }  // @152_5b8b50
  ecx = edi;  // @153_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @154_5b8b50
  eax = (u32)(esi + 234);  // @155_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(eax));  // @156_5b8b50
  ecx = edx = 0;  // @157_5b8b50
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @158_5b8b50
  eax = (u32)(esi + 221);  // @159_5b8b50
  ecx = edi;  // @160_5b8b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @161_5b8b50
  ecx = edx = 0;  // @162_5b8b50
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @163_5b8b50
  SEH_LEAVE();  // @164_5b8b50
  return eax;  // @165_5b8b50
}
PCREG(5b8b50, lifted_5b8b50);

extern "C" u32 THISCALL lifted_590e20(u32 ecx_in) {
  SEH_ENTER(0x66b9ff);  // @h_590e20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_590e20
  eax = ext_482ac0_thiscall1(ecx);  // @1_590e20
  ecx = edx = 0;  // @2_590e20
  eax = ext_41e290_cdecl1((u32)(1425));  // @3_590e20
  ecx = edx = 0;  // @4_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_590e20
  reg.state = (s32)((u32)(0));  // @6_590e20
  if ((eax & eax) == 0) goto L590e74;  // @7_590e20
  ecx = eax;  // @8_590e20
  eax = ext_5e1110_thiscall3(ecx, (u32)(esi), (u32)(7));  // @9_590e20
  ecx = edx = 0;  // @10_590e20
  ecx = eax;  // @11_590e20
  goto L590e76;  // @12_590e20
  L590e74:;
  ecx = 0;  // @14_590e20
  L590e76:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @16_590e20
  ecx = esi;  // @17_590e20
  reg.state = (s32)((u32)(4294967295));  // @18_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @19_590e20
  ecx = edx = 0;  // @20_590e20
  eax = ext_41e290_cdecl1((u32)(1485));  // @21_590e20
  ecx = edx = 0;  // @22_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @23_590e20
  reg.state = (s32)((u32)(1));  // @24_590e20
  if ((eax & eax) == 0) goto L590eb1;  // @25_590e20
  ecx = eax;  // @26_590e20
  eax = ext_5e1200_thiscall3(ecx, (u32)(esi), (u32)(8));  // @27_590e20
  ecx = edx = 0;  // @28_590e20
  ecx = eax;  // @29_590e20
  goto L590eb3;  // @30_590e20
  L590eb1:;
  ecx = 0;  // @32_590e20
  L590eb3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_590e20
  ecx = esi;  // @35_590e20
  reg.state = (s32)((u32)(4294967295));  // @36_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @37_590e20
  ecx = edx = 0;  // @38_590e20
  eax = ext_41e290_cdecl1((u32)(1471));  // @39_590e20
  ecx = edx = 0;  // @40_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @41_590e20
  reg.state = (s32)((u32)(2));  // @42_590e20
  if ((eax & eax) == 0) goto L590eee;  // @43_590e20
  ecx = eax;  // @44_590e20
  eax = ext_5e1160_thiscall3(ecx, (u32)(esi), (u32)(15));  // @45_590e20
  ecx = edx = 0;  // @46_590e20
  ecx = eax;  // @47_590e20
  goto L590ef0;  // @48_590e20
  L590eee:;
  ecx = 0;  // @50_590e20
  L590ef0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_590e20
  ecx = esi;  // @53_590e20
  reg.state = (s32)((u32)(4294967295));  // @54_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @55_590e20
  ecx = edx = 0;  // @56_590e20
  eax = ext_41e290_cdecl1((u32)(1467));  // @57_590e20
  ecx = edx = 0;  // @58_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @59_590e20
  reg.state = (s32)((u32)(3));  // @60_590e20
  if ((eax & eax) == 0) goto L590f2b;  // @61_590e20
  ecx = eax;  // @62_590e20
  eax = ext_5e1190_thiscall3(ecx, (u32)(esi), (u32)(16));  // @63_590e20
  ecx = edx = 0;  // @64_590e20
  ecx = eax;  // @65_590e20
  goto L590f2d;  // @66_590e20
  L590f2b:;
  ecx = 0;  // @68_590e20
  L590f2d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @70_590e20
  ecx = esi;  // @71_590e20
  reg.state = (s32)((u32)(4294967295));  // @72_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @73_590e20
  ecx = edx = 0;  // @74_590e20
  eax = ext_41e290_cdecl1((u32)(1384));  // @75_590e20
  ecx = edx = 0;  // @76_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @77_590e20
  reg.state = (s32)((u32)(4));  // @78_590e20
  if ((eax & eax) == 0) goto L590f68;  // @79_590e20
  ecx = eax;  // @80_590e20
  eax = ext_5e11c0_thiscall3(ecx, (u32)(esi), (u32)(17));  // @81_590e20
  ecx = edx = 0;  // @82_590e20
  ecx = eax;  // @83_590e20
  goto L590f6a;  // @84_590e20
  L590f68:;
  ecx = 0;  // @86_590e20
  L590f6a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @88_590e20
  ecx = esi;  // @89_590e20
  reg.state = (s32)((u32)(4294967295));  // @90_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @91_590e20
  ecx = edx = 0;  // @92_590e20
  eax = ext_41e290_cdecl1((u32)(1455));  // @93_590e20
  ecx = edx = 0;  // @94_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @95_590e20
  reg.state = (s32)((u32)(5));  // @96_590e20
  if ((eax & eax) == 0) goto L590fa5;  // @97_590e20
  ecx = eax;  // @98_590e20
  eax = ext_5e10a0_thiscall3(ecx, (u32)(esi), (u32)(9));  // @99_590e20
  ecx = edx = 0;  // @100_590e20
  ecx = eax;  // @101_590e20
  goto L590fa7;  // @102_590e20
  L590fa5:;
  ecx = 0;  // @104_590e20
  L590fa7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @106_590e20
  ecx = esi;  // @107_590e20
  reg.state = (s32)((u32)(4294967295));  // @108_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @109_590e20
  ecx = edx = 0;  // @110_590e20
  eax = ext_41e290_cdecl1((u32)(122));  // @111_590e20
  ecx = edx = 0;  // @112_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @113_590e20
  reg.state = (s32)((u32)(6));  // @114_590e20
  if ((eax & eax) == 0) goto L590fdf;  // @115_590e20
  ecx = eax;  // @116_590e20
  eax = ext_5e0ee0_thiscall3(ecx, (u32)(esi), (u32)(11));  // @117_590e20
  ecx = edx = 0;  // @118_590e20
  ecx = eax;  // @119_590e20
  goto L590fe1;  // @120_590e20
  L590fdf:;
  ecx = 0;  // @122_590e20
  L590fe1:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @124_590e20
  ecx = esi;  // @125_590e20
  reg.state = (s32)((u32)(4294967295));  // @126_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @127_590e20
  ecx = edx = 0;  // @128_590e20
  eax = ext_41e290_cdecl1((u32)(1553));  // @129_590e20
  ecx = edx = 0;  // @130_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @131_590e20
  reg.state = (s32)((u32)(7));  // @132_590e20
  if ((eax & eax) == 0) goto L59101c;  // @133_590e20
  ecx = eax;  // @134_590e20
  eax = ext_5e0f80_thiscall3(ecx, (u32)(esi), (u32)(12));  // @135_590e20
  ecx = edx = 0;  // @136_590e20
  ecx = eax;  // @137_590e20
  goto L59101e;  // @138_590e20
  L59101c:;
  ecx = 0;  // @140_590e20
  L59101e:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @142_590e20
  ecx = esi;  // @143_590e20
  reg.state = (s32)((u32)(4294967295));  // @144_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @145_590e20
  ecx = edx = 0;  // @146_590e20
  eax = ext_41e290_cdecl1((u32)(1400));  // @147_590e20
  ecx = edx = 0;  // @148_590e20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @149_590e20
  reg.state = (s32)((u32)(8));  // @150_590e20
  if ((eax & eax) == 0) goto L591059;  // @151_590e20
  ecx = eax;  // @152_590e20
  eax = ext_5e0ff0_thiscall3(ecx, (u32)(esi), (u32)(14));  // @153_590e20
  ecx = edx = 0;  // @154_590e20
  ecx = eax;  // @155_590e20
  goto L59105b;  // @156_590e20
  L591059:;
  ecx = 0;  // @158_590e20
  L59105b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @160_590e20
  ecx = esi;  // @161_590e20
  reg.state = (s32)((u32)(4294967295));  // @162_590e20
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 1572)))(ecx, (u32)(ecx));  // @163_590e20
  ecx = edx = 0;  // @164_590e20
  SEH_LEAVE();  // @165_590e20
  return eax;  // @166_590e20
}
PCREG(590e20, lifted_590e20);

extern "C" u32 THISCALL lifted_4ad4d0(u32 ecx_in) {
  SEH_ENTER(0x668851);  // @h_4ad4d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ad4d0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 432), &v, sizeof v); }  // @1_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 282), sizeof v); (u32)v; });  // @2_4ad4d0
  ebx = (u32)(esi + 282);  // @3_4ad4d0
  ecx = ebx;  // @4_4ad4d0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @5_4ad4d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @6_4ad4d0
  ecx = edx = 0;  // @7_4ad4d0
  if ((eax & eax) == 0) goto L4ad74f;  // @8_4ad4d0
  L4ad525:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @10_4ad4d0
  ecx = ebx;  // @11_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @12_4ad4d0
  ecx = edx = 0;  // @13_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @14_4ad4d0
  edi = eax;  // @15_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @16_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(edi));  // @18_4ad4d0
  ecx = edx = 0;  // @19_4ad4d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @20_4ad4d0
  if ((eax & eax) == 0) goto L4ad740;  // @21_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @22_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @23_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(edi));  // @25_4ad4d0
  ecx = edx = 0;  // @26_4ad4d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 416), &v, sizeof v); }  // @27_4ad4d0
  if ((eax & eax) != 0) goto L4ad5cb;  // @28_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @29_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @31_4ad4d0
  ecx = edx = 0;  // @32_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @33_4ad4d0
  edi = eax;  // @34_4ad4d0
  eax = (u32)(EBP - 144);  // @35_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @37_4ad4d0
  ecx = edx = 0;  // @38_4ad4d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_4ad4d0
  ecx = eax;  // @40_4ad4d0
  reg.state = (s32)((u32)(0));  // @41_4ad4d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @42_4ad4d0
  ecx = edx = 0;  // @43_4ad4d0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6884388), (u32)(eax));  // @44_4ad4d0
  ecx = edx = 0;  // @45_4ad4d0
  reg.state = (s32)((u32)(4294967295));  // @46_4ad4d0
  ecx = (u32)(EBP - 144);  // @47_4ad4d0
  eax = ext_4cbec0_thiscall1(ecx);  // @48_4ad4d0
  ecx = edx = 0;  // @49_4ad4d0
  goto L4ad72a;  // @50_4ad4d0
  L4ad5cb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_4ad4d0
  ecx = ebx;  // @53_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(edi));  // @54_4ad4d0
  ecx = edx = 0;  // @55_4ad4d0
  if ((eax & eax) != 0) goto L4ad67d;  // @56_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @57_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @58_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @59_4ad4d0
  ecx = edx = 0;  // @60_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @61_4ad4d0
  edi = eax;  // @62_4ad4d0
  eax = (u32)(EBP - 400);  // @63_4ad4d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @64_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @66_4ad4d0
  ecx = edx = 0;  // @67_4ad4d0
  ebx = eax;  // @68_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; });  // @69_4ad4d0
  eax = (u32)(EBP - 272);  // @70_4ad4d0
  reg.state = (s32)((u32)(1));  // @71_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @72_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @73_4ad4d0
  ecx = edx = 0;  // @74_4ad4d0
  esi = eax;  // @75_4ad4d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @76_4ad4d0
  ecx = ebx;  // @77_4ad4d0
  reg.state = (s32)((u32)(2));  // @78_4ad4d0
  eax = ext_4cc1d0_thiscall1(ecx);  // @79_4ad4d0
  ecx = edx = 0;  // @80_4ad4d0
  ecx = esi;  // @81_4ad4d0
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @82_4ad4d0
  ecx = edx = 0;  // @83_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; }), (u32)(6884448), (u32)(eax));  // @84_4ad4d0
  ecx = edx = 0;  // @85_4ad4d0
  ecx = (u32)(EBP - 272);  // @86_4ad4d0
  eax = ext_4cbec0_thiscall1(ecx);  // @87_4ad4d0
  ecx = edx = 0;  // @88_4ad4d0
  ecx = (u32)(EBP - 400);  // @89_4ad4d0
  reg.state = (s32)((u32)(4294967295));  // @90_4ad4d0
  eax = ext_4cbec0_thiscall1(ecx);  // @91_4ad4d0
  ecx = edx = 0;  // @92_4ad4d0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; });  // @93_4ad4d0
  goto L4ad72a;  // @94_4ad4d0
  L4ad67d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @96_4ad4d0
  ecx = ebx;  // @97_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(edi));  // @98_4ad4d0
  ecx = edx = 0;  // @99_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @100_4ad4d0
  if ((edx & edx) == 0) goto L4ad6af;  // @101_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_4ad4d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @103_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @105_4ad4d0
  ecx = edx = 0;  // @106_4ad4d0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @107_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @108_4ad4d0
  ecx = eax;  // @109_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(ecx), (u32)(edi), (u32)(0));  // @110_4ad4d0
  ecx = edx = 0;  // @111_4ad4d0
  L4ad6af:;
  esi = (esi + (u32)(454));  // @113_4ad4d0
  if (esi == 0) goto L4ad72a;  // @114_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @115_4ad4d0
  ecx = (u32)(EBP - 412);  // @116_4ad4d0
  ecx = esi;  // @117_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @118_4ad4d0
  ecx = edx = 0;  // @119_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @120_4ad4d0
  ecx = (u32)(EBP - 412);  // @121_4ad4d0
  ecx = esi;  // @122_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @123_4ad4d0
  ecx = edx = 0;  // @124_4ad4d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad72a;  // @125_4ad4d0
  L4ad6e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @127_4ad4d0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @128_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(eax));  // @129_4ad4d0
  ecx = edx = 0;  // @130_4ad4d0
  ecx = eax;  // @131_4ad4d0
  if ((ecx & ecx) == 0) goto L4ad705;  // @132_4ad4d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }) != edi) goto L4ad713;  // @133_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_4ad4d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @135_4ad4d0
  ecx = edx = 0;  // @136_4ad4d0
  L4ad705:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @138_4ad4d0
  ecx = (u32)(EBP - 412);  // @139_4ad4d0
  ecx = esi;  // @140_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(ecx));  // @141_4ad4d0
  ecx = edx = 0;  // @142_4ad4d0
  L4ad713:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @144_4ad4d0
  ecx = (u32)(EBP - 412);  // @145_4ad4d0
  ecx = esi;  // @146_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @147_4ad4d0
  ecx = edx = 0;  // @148_4ad4d0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 412), sizeof v); (u32)v; }) != (u32)(0)) goto L4ad6e0;  // @149_4ad4d0
  L4ad72a:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @151_4ad4d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @152_4ad4d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 528)))(ecx, (u32)(1));  // @153_4ad4d0
  ecx = edx = 0;  // @154_4ad4d0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 432), sizeof v); (u32)v; });  // @155_4ad4d0
  L4ad740:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @157_4ad4d0
  ecx = ebx;  // @158_4ad4d0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @159_4ad4d0
  ecx = edx = 0;  // @160_4ad4d0
  if ((eax & eax) != 0) goto L4ad525;  // @161_4ad4d0
  L4ad74f:;
  SEH_LEAVE();  // @163_4ad4d0
  ext_633654(G(u32, 0x6f5630));  // @164_4ad4d0
  return eax;  // @165_4ad4d0
}
PCREG(4ad4d0, lifted_4ad4d0);

extern "C" u32 THISCALL lifted_5ee720(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cbf2);  // @h_5ee720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ee720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @1_5ee720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 21), sizeof v); (u32)v; });  // @2_5ee720
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(ebx));  // @5_5ee720
  ecx = edx = 0;  // @6_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @7_5ee720
  eax = (u32)(EBP + 11);  // @8_5ee720
  eax = (u32)(esi + 106);  // @9_5ee720
  ecx = ebx;  // @10_5ee720
  eax = (u32)(esi + 77);  // @11_5ee720
  eax = (u32)(esi + 4);  // @12_5ee720
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32, u32, u32, u32))(*(u32 *)(edx + 44)))(ecx, (u32)(eax), (u32)(eax), (u32)(eax), (u32)(eax), (u32)(eax), (u32)(eax), (u32)(eax), (u32)(eax));  // @13_5ee720
  ecx = edx = 0;  // @14_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @15_5ee720
  ecx = (u32)(EBP - 16);  // @16_5ee720
  ecx = ebx;  // @17_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @18_5ee720
  ecx = edx = 0;  // @19_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @20_5ee720
  ecx = ebx;  // @21_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 17), &v, sizeof v); }  // @22_5ee720
  eax = (u32)(esi + 25);  // @23_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @25_5ee720
  ecx = edx = 0;  // @26_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @27_5ee720
  eax = (u32)(esi + 65);  // @28_5ee720
  ecx = ebx;  // @29_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @30_5ee720
  ecx = edx = 0;  // @31_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @32_5ee720
  eax = (u32)(esi + 69);  // @33_5ee720
  ecx = ebx;  // @34_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @35_5ee720
  ecx = edx = 0;  // @36_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @37_5ee720
  eax = (u32)(esi + 73);  // @38_5ee720
  ecx = ebx;  // @39_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @40_5ee720
  ecx = edx = 0;  // @41_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @42_5ee720
  eax = (u32)(esi + 78);  // @43_5ee720
  ecx = ebx;  // @44_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @45_5ee720
  ecx = edx = 0;  // @46_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @47_5ee720
  eax = (u32)(esi + 82);  // @48_5ee720
  ecx = ebx;  // @49_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @50_5ee720
  ecx = edx = 0;  // @51_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @52_5ee720
  eax = (u32)(esi + 86);  // @53_5ee720
  ecx = ebx;  // @54_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @55_5ee720
  ecx = edx = 0;  // @56_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @57_5ee720
  ecx = (u32)(EBP - 16);  // @58_5ee720
  ecx = ebx;  // @59_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @60_5ee720
  ecx = edx = 0;  // @61_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @62_5ee720
  ecx = (u32)(EBP - 16);  // @63_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @64_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @65_5ee720
  ecx = ebx;  // @66_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @67_5ee720
  ecx = edx = 0;  // @68_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @69_5ee720
  ecx = ebx;  // @70_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @71_5ee720
  eax = (u32)(esi + 98);  // @72_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @73_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @74_5ee720
  ecx = edx = 0;  // @75_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @76_5ee720
  eax = (u32)(esi + 102);  // @77_5ee720
  ecx = ebx;  // @78_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @79_5ee720
  ecx = edx = 0;  // @80_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @81_5ee720
  eax = (u32)(esi + 107);  // @82_5ee720
  ecx = ebx;  // @83_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @84_5ee720
  ecx = edx = 0;  // @85_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @86_5ee720
  ecx = (u32)(EBP - 16);  // @87_5ee720
  ecx = ebx;  // @88_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @89_5ee720
  ecx = edx = 0;  // @90_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @91_5ee720
  ecx = (u32)(EBP - 16);  // @92_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 115), &v, sizeof v); }  // @93_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @94_5ee720
  ecx = ebx;  // @95_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @96_5ee720
  ecx = edx = 0;  // @97_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @98_5ee720
  ecx = ebx;  // @99_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 111), &v, sizeof v); }  // @100_5ee720
  eax = (u32)(esi + 120);  // @101_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @102_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @103_5ee720
  ecx = edx = 0;  // @104_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @105_5ee720
  eax = (u32)(esi + 124);  // @106_5ee720
  ecx = ebx;  // @107_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @108_5ee720
  ecx = edx = 0;  // @109_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @110_5ee720
  ecx = (u32)(esi + 128);  // @111_5ee720
  ecx = ebx;  // @112_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @113_5ee720
  ecx = edx = 0;  // @114_5ee720
  ecx = (u32)(esi + 29);  // @115_5ee720
  eax = ext_4de7a0_thiscall1(ecx);  // @116_5ee720
  ecx = edx = 0;  // @117_5ee720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 119), &v, sizeof v); }  // @118_5ee720
  ecx = (u32)(EBP - 24);  // @119_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @120_5ee720
  ecx = ebx;  // @121_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @122_5ee720
  ecx = edx = 0;  // @123_5ee720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @124_5ee720
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) <= (u32)(0)) goto L5ee90b;  // @125_5ee720
  L5ee883:;
  eax = ext_41e290_cdecl1((u32)(8));  // @127_5ee720
  ecx = edx = 0;  // @128_5ee720
  edi = eax;  // @129_5ee720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @130_5ee720
  eax = ext_41e290_cdecl1((u32)(168));  // @131_5ee720
  ecx = edx = 0;  // @132_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 36), &v, sizeof v); }  // @133_5ee720
  reg.state = (s32)((u32)(0));  // @134_5ee720
  if ((eax & eax) == 0) goto L5ee8be;  // @135_5ee720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @136_5ee720
  ecx = eax;  // @137_5ee720
  eax = ext_5ab2e0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 128), sizeof v); (u32)v; }));  // @138_5ee720
  ecx = edx = 0;  // @139_5ee720
  ecx = eax;  // @140_5ee720
  goto L5ee8c0;  // @141_5ee720
  L5ee8be:;
  ecx = 0;  // @143_5ee720
  L5ee8c0:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @145_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @146_5ee720
  reg.state = (s32)((u32)(4294967295));  // @147_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(ebx));  // @148_5ee720
  ecx = edx = 0;  // @149_5ee720
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @150_5ee720
  eax = (u32)(edi + 4);  // @151_5ee720
  ecx = ebx;  // @152_5ee720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @153_5ee720
  ecx = edx = 0;  // @154_5ee720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @155_5ee720
  if (eax == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 13), sizeof v); (u32)v; })) goto L5ee8ee;  // @156_5ee720
  if ((eax & eax) == 0) goto L5ee8e8;  // @157_5ee720
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @158_5ee720
  L5ee8e8:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) + (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 9), &v, sizeof v); }  // @160_5ee720
  goto L5ee8fb;  // @161_5ee720
  L5ee8ee:;
  ecx = (u32)(EBP - 32);  // @163_5ee720
  ecx = (u32)(esi + 5);  // @164_5ee720
  eax = ext_5fe3b0_thiscall3(ecx, (u32)(eax), (u32)(ecx));  // @165_5ee720
  ecx = edx = 0;  // @166_5ee720
  L5ee8fb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @168_5ee720
  eax = (eax + 1);  // @169_5ee720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @170_5ee720
  if (eax < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; })) goto L5ee883;  // @171_5ee720
  L5ee90b:;
  SEH_LEAVE();  // @173_5ee720
  return eax;  // @174_5ee720
}
PCREG(5ee720, lifted_5ee720);

extern "C" u32 THISCALL lifted_4d8840(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6696b1);  // @h_4d8840
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4d8840
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @1_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 260), sizeof v); (u32)v; });  // @2_4d8840
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @3_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 16)))(ecx);  // @5_4d8840
  ecx = edx = 0;  // @6_4d8840
  if ((esi & esi) != 0) goto L4d8a00;  // @7_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @8_4d8840
  esi = eax;  // @9_4d8840
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @10_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6909064), (u32)(62));  // @12_4d8840
  ecx = edx = 0;  // @13_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_4d8840
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6909136));  // @15_4d8840
  ecx = edx = 0;  // @16_4d8840
  ecx = (u32)(EBP - 192);  // @17_4d8840
  eax = ext_4ccd10_thiscall3(ecx, (u32)(32), (u32)(0));  // @18_4d8840
  ecx = edx = 0;  // @19_4d8840
  reg.state = (s32)((u32)(0));  // @20_4d8840
  if ((esi & esi) == 0) goto L4d89d0;  // @21_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_4d8840
  ecx = (u32)(EBP - 164);  // @23_4d8840
  ecx = esi;  // @24_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @25_4d8840
  ecx = edx = 0;  // @26_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4d8840
  ecx = (u32)(EBP - 164);  // @28_4d8840
  ecx = esi;  // @29_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @30_4d8840
  ecx = edx = 0;  // @31_4d8840
  ebx = eax;  // @32_4d8840
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) == (u32)(0)) goto L4d89d0;  // @33_4d8840
  L4d8900:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 260), sizeof v); (u32)v; });  // @35_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 16)))(ecx);  // @37_4d8840
  ecx = edx = 0;  // @38_4d8840
  ecx = eax;  // @39_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @40_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(ebx));  // @41_4d8840
  ecx = edx = 0;  // @42_4d8840
  if ((eax & eax) == 0) goto L4d89b3;  // @43_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @44_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @46_4d8840
  ecx = edx = 0;  // @47_4d8840
  ecx = eax;  // @48_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @49_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @50_4d8840
  ecx = edx = 0;  // @51_4d8840
  ecx = (u32)(EBP - 144);  // @52_4d8840
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @53_4d8840
  ecx = edx = 0;  // @54_4d8840
  ecx = (u32)(EBP - 144);  // @55_4d8840
  reg.state = (s32)((u32)(1));  // @56_4d8840
  eax = ext_4cc5f0_thiscall1(ecx);  // @57_4d8840
  ecx = edx = 0;  // @58_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4d8840
  if ((eax & eax) == 0) goto L4d898b;  // @61_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(77));  // @62_4d8840
  ecx = edx = 0;  // @63_4d8840
  esi = eax;  // @64_4d8840
  ecx = (u32)(EBP - 144);  // @65_4d8840
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @66_4d8840
  eax = ext_4cc1d0_thiscall1(ecx);  // @67_4d8840
  ecx = edx = 0;  // @68_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, (u32)(esi), (u32)(6909216), (u32)(ebx), (u32)(eax));  // @69_4d8840
  ecx = edx = 0;  // @70_4d8840
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; });  // @71_4d8840
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; });  // @72_4d8840
  goto L4d89a4;  // @73_4d8840
  L4d898b:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(81));  // @75_4d8840
  ecx = edx = 0;  // @76_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @77_4d8840
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6909228), (u32)(ebx));  // @78_4d8840
  ecx = edx = 0;  // @79_4d8840
  L4d89a4:;
  ecx = (u32)(EBP - 144);  // @81_4d8840
  reg.state = (s32)((u32)(0));  // @82_4d8840
  eax = ext_4cbec0_thiscall1(ecx);  // @83_4d8840
  ecx = edx = 0;  // @84_4d8840
  L4d89b3:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @86_4d8840
  ecx = (u32)(EBP - 164);  // @87_4d8840
  ecx = esi;  // @88_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @89_4d8840
  ecx = edx = 0;  // @90_4d8840
  ebx = eax;  // @91_4d8840
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 164), sizeof v); (u32)v; }) != (u32)(0)) goto L4d8900;  // @92_4d8840
  L4d89d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @94_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(86));  // @96_4d8840
  ecx = edx = 0;  // @97_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @98_4d8840
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6909136));  // @99_4d8840
  ecx = edx = 0;  // @100_4d8840
  ecx = (u32)(EBP - 192);  // @101_4d8840
  eax = ext_4cd0e0_thiscall1(ecx);  // @102_4d8840
  ecx = edx = 0;  // @103_4d8840
  goto L4d8ac7;  // @104_4d8840
  L4d8a00:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @106_4d8840
  ecx = eax;  // @107_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 132)))(ecx, (u32)(esi));  // @108_4d8840
  ecx = edx = 0;  // @109_4d8840
  if ((eax & eax) == 0) goto L4d8aa6;  // @110_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @111_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @112_4d8840
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(0));  // @113_4d8840
  ecx = edx = 0;  // @114_4d8840
  ecx = eax;  // @115_4d8840
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @116_4d8840
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @117_4d8840
  ecx = edx = 0;  // @118_4d8840
  ecx = (u32)(EBP - 144);  // @119_4d8840
  eax = ext_4cbe50_thiscall2(ecx, (u32)(eax));  // @120_4d8840
  ecx = edx = 0;  // @121_4d8840
  ecx = (u32)(EBP - 144);  // @122_4d8840
  reg.state = (s32)((u32)(2));  // @123_4d8840
  eax = ext_4cc5f0_thiscall1(ecx);  // @124_4d8840
  ecx = edx = 0;  // @125_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @126_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @127_4d8840
  if ((eax & eax) == 0) goto L4d8a81;  // @128_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(100));  // @129_4d8840
  ecx = edx = 0;  // @130_4d8840
  esi = eax;  // @131_4d8840
  ecx = (u32)(EBP - 144);  // @132_4d8840
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @133_4d8840
  eax = ext_4cc1d0_thiscall1(ecx);  // @134_4d8840
  ecx = edx = 0;  // @135_4d8840
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(esi), (u32)(6779752), (u32)(eax));  // @136_4d8840
  ecx = edx = 0;  // @137_4d8840
  ecx = (u32)(EBP - 144);  // @138_4d8840
  eax = ext_4cbec0_thiscall1(ecx);  // @139_4d8840
  ecx = edx = 0;  // @140_4d8840
  goto L4d8ac7;  // @141_4d8840
  L4d8a81:;
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(102));  // @143_4d8840
  ecx = edx = 0;  // @144_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @145_4d8840
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6909256));  // @146_4d8840
  ecx = edx = 0;  // @147_4d8840
  ecx = (u32)(EBP - 144);  // @148_4d8840
  eax = ext_4cbec0_thiscall1(ecx);  // @149_4d8840
  ecx = edx = 0;  // @150_4d8840
  goto L4d8ac7;  // @151_4d8840
  L4d8aa6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @153_4d8840
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @154_4d8840
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6909064), (u32)(105));  // @155_4d8840
  ecx = edx = 0;  // @156_4d8840
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @157_4d8840
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6909276), (u32)(esi));  // @158_4d8840
  ecx = edx = 0;  // @159_4d8840
  L4d8ac7:;
  SEH_LEAVE();  // @161_4d8840
  ext_633654(G(u32, 0x6f5630));  // @162_4d8840
  return eax;  // @163_4d8840
}
PCREG(4d8840, lifted_4d8840);

extern "C" u32 THISCALL lifted_512590(u32 ecx_in) {
  SEH_ENTER(0x664d1b);  // @h_512590
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @1_512590
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 292)))(ecx, (u32)(1), (u32)(0), (u32)(0), (u32)(0));  // @2_512590
  ecx = edx = 0;  // @3_512590
  ecx = ebx;  // @4_512590
  eax = ext_44a1f0_cdecl0();  // @5_512590
  ecx = edx = 0;  // @6_512590
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 80), sizeof v); (u32)v; });  // @7_512590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 291), &v, sizeof v); }  // @8_512590
  if ((edi & edi) == 0) goto L51274d;  // @9_512590
  L5125f0:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L5126b6;  // @11_512590
  ecx = edi;  // @12_512590
  eax = ext_4dc110_thiscall1(ecx);  // @13_512590
  ecx = edx = 0;  // @14_512590
  edx = (u32)(6939940);  // @15_512590
  ecx = eax;  // @16_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @17_512590
  ecx = edx = 0;  // @18_512590
  if ((eax & eax) != 0) goto L51262a;  // @19_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @20_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @21_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @22_512590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @23_512590
  ecx = edx = 0;  // @24_512590
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L51269a;  // @25_512590
  L51262a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L5126b6;  // @27_512590
  ecx = edi;  // @28_512590
  eax = ext_4dc110_thiscall1(ecx);  // @29_512590
  ecx = edx = 0;  // @30_512590
  edx = (u32)(6939956);  // @31_512590
  ecx = eax;  // @32_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @33_512590
  ecx = edx = 0;  // @34_512590
  if ((eax & eax) != 0) goto L512664;  // @35_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @36_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @38_512590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @39_512590
  ecx = edx = 0;  // @40_512590
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L51269a;  // @41_512590
  L512664:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L5126b6;  // @43_512590
  ecx = edi;  // @44_512590
  eax = ext_4dc110_thiscall1(ecx);  // @45_512590
  ecx = edx = 0;  // @46_512590
  edx = (u32)(6939964);  // @47_512590
  ecx = eax;  // @48_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @49_512590
  ecx = edx = 0;  // @50_512590
  if ((eax & eax) != 0) goto L5126b6;  // @51_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 84), sizeof v); (u32)v; });  // @52_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @54_512590
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(2097154));  // @55_512590
  ecx = edx = 0;  // @56_512590
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5126b6;  // @57_512590
  L51269a:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @59_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @60_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edi));  // @62_512590
  ecx = edx = 0;  // @63_512590
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 291), &v, sizeof v); }  // @64_512590
  goto L512742;  // @65_512590
  L5126b6:;
  ecx = edi;  // @67_512590
  eax = ext_4dc110_thiscall1(ecx);  // @68_512590
  ecx = edx = 0;  // @69_512590
  edx = (u32)(6939972);  // @70_512590
  ecx = eax;  // @71_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @72_512590
  ecx = edx = 0;  // @73_512590
  ecx = edi;  // @74_512590
  if ((eax & eax) != 0) goto L5126fb;  // @75_512590
  eax = ext_4db860_thiscall2(ecx, (u32)(1));  // @76_512590
  ecx = edx = 0;  // @77_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 295), sizeof v); (u32)v; });  // @78_512590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @79_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @80_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @81_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @82_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edi));  // @83_512590
  ecx = edx = 0;  // @84_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 295), sizeof v); (u32)v; });  // @85_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, (u32)(eax));  // @86_512590
  ecx = edx = 0;  // @87_512590
  goto L512742;  // @88_512590
  L5126fb:;
  eax = ext_4dc110_thiscall1(ecx);  // @90_512590
  ecx = edx = 0;  // @91_512590
  edx = (u32)(6939984);  // @92_512590
  ecx = eax;  // @93_512590
  eax = ext_4cc850_fastcall2(ecx, edx);  // @94_512590
  ecx = edx = 0;  // @95_512590
  if ((eax & eax) != 0) goto L512742;  // @96_512590
  ecx = edi;  // @97_512590
  eax = ext_4db860_thiscall2(ecx, (u32)(1));  // @98_512590
  ecx = edx = 0;  // @99_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 299), sizeof v); (u32)v; });  // @100_512590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @101_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @103_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(edi));  // @105_512590
  ecx = edx = 0;  // @106_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 299), sizeof v); (u32)v; });  // @107_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 4)))(ecx, (u32)(eax));  // @108_512590
  ecx = edx = 0;  // @109_512590
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @110_512590
  L512742:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 96), sizeof v); (u32)v; });  // @112_512590
  if ((edi & edi) != 0) goto L5125f0;  // @113_512590
  L51274d:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; });  // @115_512590
  if ((edx & edx) == 0) goto L5127b5;  // @116_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @117_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @118_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @119_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @120_512590
  ecx = edx = 0;  // @121_512590
  edi = eax;  // @122_512590
  ecx = edi;  // @123_512590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @124_512590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 268)))(ecx, (u32)(6878332), (u32)(-1));  // @125_512590
  ecx = edx = 0;  // @126_512590
  esi = eax;  // @127_512590
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) != 0) goto L512794;  // @128_512590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @129_512590
  ecx = esi;  // @130_512590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 8)))(ecx);  // @131_512590
  ecx = edx = 0;  // @132_512590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(4))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @133_512590
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L5127ac;  // @134_512590
  L512794:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @136_512590
  ecx = esi;  // @137_512590
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 76)))(ecx);  // @138_512590
  ecx = edx = 0;  // @139_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @140_512590
  ecx = esi;  // @141_512590
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(256))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @142_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 84)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; }));  // @143_512590
  ecx = edx = 0;  // @144_512590
  L5127ac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @146_512590
  ecx = edi;  // @147_512590
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(1));  // @148_512590
  ecx = edx = 0;  // @149_512590
  L5127b5:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 291), sizeof v); (u32)v; }) != (u32)(0)) goto L512825;  // @151_512590
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @152_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @153_512590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6939836), (u32)(314));  // @154_512590
  ecx = edx = 0;  // @155_512590
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @156_512590
  edi = eax;  // @157_512590
  eax = (u32)(EBP - 144);  // @158_512590
  ecx = ebx;  // @159_512590
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @160_512590
  ecx = edx = 0;  // @161_512590
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @162_512590
  ecx = eax;  // @163_512590
  reg.state = (s32)((u32)(0));  // @164_512590
  eax = ext_4cc1d0_thiscall1(ecx);  // @165_512590
  ecx = edx = 0;  // @166_512590
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6940000), (u32)(eax));  // @167_512590
  ecx = edx = 0;  // @168_512590
  reg.state = (s32)((u32)(4294967295));  // @169_512590
  ecx = (u32)(EBP - 144);  // @170_512590
  eax = ext_4cbec0_thiscall1(ecx);  // @171_512590
  ecx = edx = 0;  // @172_512590
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @173_512590
  if ((eax & eax) == 0) goto L512824;  // @174_512590
  eax = ((u32(STDCALL *)(void))(eax))();  // @175_512590
  ecx = edx = 0;  // @176_512590
  goto L512825;  // @177_512590
  L512824:;
  __builtin_trap();  // @179_512590
  L512825:;
  SEH_LEAVE();  // @181_512590
  ext_633654(G(u32, 0x6f5630));  // @182_512590
  return eax;  // @183_512590
}
PCREG(512590, lifted_512590);

extern "C" u32 THISCALL lifted_4ad9a0(u32 ecx_in) {
  SEH_ENTER(0x6688f1);  // @h_4ad9a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_4ad9a0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @1_4ad9a0
  ebx = (u32)(esi + 282);  // @2_4ad9a0
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 428), &v, sizeof v); }  // @3_4ad9a0
  goto L4ad9ea;  // @4_4ad9a0
  L4ad9e4:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 404), sizeof v); (u32)v; });  // @6_4ad9a0
  L4ad9ea:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_4ad9a0
  ecx = ebx;  // @9_4ad9a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @10_4ad9a0
  ecx = edx = 0;  // @11_4ad9a0
  if ((eax & eax) == 0) goto L4ada64;  // @12_4ad9a0
  if ((ebx & ebx) == 0) goto L4ad9ea;  // @13_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @14_4ad9a0
  ecx = (u32)(EBP - 440);  // @15_4ad9a0
  ecx = ebx;  // @16_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @17_4ad9a0
  ecx = edx = 0;  // @18_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_4ad9a0
  ecx = (u32)(EBP - 440);  // @20_4ad9a0
  ecx = ebx;  // @21_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @22_4ad9a0
  ecx = edx = 0;  // @23_4ad9a0
  edi = eax;  // @24_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad9ea;  // @25_4ad9a0
  L4ada20:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @28_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(edi));  // @30_4ad9a0
  ecx = edx = 0;  // @31_4ad9a0
  ecx = eax;  // @32_4ad9a0
  if ((ecx & ecx) == 0) goto L4ada4b;  // @33_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @34_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @35_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050578));  // @36_4ad9a0
  ecx = edx = 0;  // @37_4ad9a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4ada80;  // @38_4ad9a0
  L4ada4b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @40_4ad9a0
  ecx = (u32)(EBP - 440);  // @41_4ad9a0
  ecx = ebx;  // @42_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @43_4ad9a0
  ecx = edx = 0;  // @44_4ad9a0
  edi = eax;  // @45_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 440), sizeof v); (u32)v; }) != (u32)(0)) goto L4ada20;  // @46_4ad9a0
  L4ada64:;
  SEH_LEAVE();  // @48_4ad9a0
  ext_633654(G(u32, 0x6f5630));  // @49_4ad9a0
  return eax;  // @50_4ad9a0
  L4ada80:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @52_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @53_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edi));  // @55_4ad9a0
  ecx = edx = 0;  // @56_4ad9a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 420), &v, sizeof v); }  // @57_4ad9a0
  if ((eax & eax) != 0) goto L4adafa;  // @58_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(656));  // @61_4ad9a0
  ecx = edx = 0;  // @62_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @63_4ad9a0
  edi = eax;  // @64_4ad9a0
  eax = (u32)(EBP - 144);  // @65_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @66_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @67_4ad9a0
  ecx = edx = 0;  // @68_4ad9a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @69_4ad9a0
  ecx = eax;  // @70_4ad9a0
  reg.state = (s32)((u32)(0));  // @71_4ad9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @72_4ad9a0
  ecx = edx = 0;  // @73_4ad9a0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6884388), (u32)(eax));  // @74_4ad9a0
  ecx = edx = 0;  // @75_4ad9a0
  reg.state = (s32)((u32)(4294967295));  // @76_4ad9a0
  ecx = (u32)(EBP - 144);  // @77_4ad9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @78_4ad9a0
  ecx = edx = 0;  // @79_4ad9a0
  goto L4ad9e4;  // @80_4ad9a0
  L4adafa:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @82_4ad9a0
  ecx = ebx;  // @83_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(edi));  // @84_4ad9a0
  ecx = edx = 0;  // @85_4ad9a0
  if ((eax & eax) != 0) goto L4adbac;  // @86_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @87_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @88_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6883748), (u32)(661));  // @89_4ad9a0
  ecx = edx = 0;  // @90_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 68), sizeof v); (u32)v; });  // @91_4ad9a0
  edi = eax;  // @92_4ad9a0
  eax = (u32)(EBP - 400);  // @93_4ad9a0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 424), &v, sizeof v); }  // @94_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @95_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @96_4ad9a0
  ecx = edx = 0;  // @97_4ad9a0
  ebx = eax;  // @98_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 420), sizeof v); (u32)v; });  // @99_4ad9a0
  eax = (u32)(EBP - 272);  // @100_4ad9a0
  reg.state = (s32)((u32)(1));  // @101_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @103_4ad9a0
  ecx = edx = 0;  // @104_4ad9a0
  esi = eax;  // @105_4ad9a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @106_4ad9a0
  ecx = ebx;  // @107_4ad9a0
  reg.state = (s32)((u32)(2));  // @108_4ad9a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @109_4ad9a0
  ecx = edx = 0;  // @110_4ad9a0
  ecx = esi;  // @111_4ad9a0
  eax = ext_4cc1d0_cdecl1((u32)(eax));  // @112_4ad9a0
  ecx = edx = 0;  // @113_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edi + 44)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 424), sizeof v); (u32)v; }), (u32)(6884448), (u32)(eax));  // @114_4ad9a0
  ecx = edx = 0;  // @115_4ad9a0
  ecx = (u32)(EBP - 272);  // @116_4ad9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @117_4ad9a0
  ecx = edx = 0;  // @118_4ad9a0
  ecx = (u32)(EBP - 400);  // @119_4ad9a0
  reg.state = (s32)((u32)(4294967295));  // @120_4ad9a0
  eax = ext_4cbec0_thiscall1(ecx);  // @121_4ad9a0
  ecx = edx = 0;  // @122_4ad9a0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 428), sizeof v); (u32)v; });  // @123_4ad9a0
  goto L4ad9e4;  // @124_4ad9a0
  L4adbac:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @126_4ad9a0
  ecx = ebx;  // @127_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 60)))(ecx, (u32)(edi));  // @128_4ad9a0
  ecx = edx = 0;  // @129_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 106), sizeof v); (u32)v; });  // @130_4ad9a0
  if ((edx & edx) == 0) goto L4adbde;  // @131_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_4ad9a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @133_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @135_4ad9a0
  ecx = edx = 0;  // @136_4ad9a0
  ecx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74), sizeof v); (u32)v; });  // @137_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @138_4ad9a0
  ecx = eax;  // @139_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 296)))(ecx, (u32)(ecx), (u32)(edi), (u32)(0));  // @140_4ad9a0
  ecx = edx = 0;  // @141_4ad9a0
  L4adbde:;
  esi = (esi + (u32)(454));  // @143_4ad9a0
  if (esi == 0) goto L4ad9e4;  // @144_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @145_4ad9a0
  ecx = (u32)(EBP - 416);  // @146_4ad9a0
  ecx = esi;  // @147_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @148_4ad9a0
  ecx = edx = 0;  // @149_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @150_4ad9a0
  ecx = (u32)(EBP - 416);  // @151_4ad9a0
  ecx = esi;  // @152_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @153_4ad9a0
  ecx = edx = 0;  // @154_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; }) == (u32)(0)) goto L4ad9e4;  // @155_4ad9a0
  L4adc13:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @157_4ad9a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @158_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 204)))(ecx, (u32)(eax));  // @159_4ad9a0
  ecx = edx = 0;  // @160_4ad9a0
  ecx = eax;  // @161_4ad9a0
  if ((ecx & ecx) == 0) goto L4adc38;  // @162_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 262), sizeof v); (u32)v; }) != edi) goto L4adc46;  // @163_4ad9a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @164_4ad9a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 172)))(ecx);  // @165_4ad9a0
  ecx = edx = 0;  // @166_4ad9a0
  L4adc38:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @168_4ad9a0
  ecx = (u32)(EBP - 416);  // @169_4ad9a0
  ecx = esi;  // @170_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 68)))(ecx, (u32)(ecx));  // @171_4ad9a0
  ecx = edx = 0;  // @172_4ad9a0
  L4adc46:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @174_4ad9a0
  ecx = (u32)(EBP - 416);  // @175_4ad9a0
  ecx = esi;  // @176_4ad9a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @177_4ad9a0
  ecx = edx = 0;  // @178_4ad9a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 416), sizeof v); (u32)v; }) != (u32)(0)) goto L4adc13;  // @179_4ad9a0
  goto L4ad9e4;  // @180_4ad9a0
}
PCREG(4ad9a0, lifted_4ad9a0);

