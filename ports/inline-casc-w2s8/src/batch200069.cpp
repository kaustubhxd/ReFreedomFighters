// batch200069.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_448a30_thiscall2(u32, u32) __asm__("ext_448a30");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4d83b0_thiscall4(u32, u32, u32, u32) __asm__("ext_4d83b0");
extern "C" u32 THISCALL ext_4e11e0_thiscall3(u32, u32, u32) __asm__("ext_4e11e0");
extern "C" u32 THISCALL ext_4e12f0_thiscall3(u32, u32, u32) __asm__("ext_4e12f0");
extern "C" u32 THISCALL ext_4e1600_thiscall1(u32) __asm__("ext_4e1600");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_540c70_thiscall3(u32, u32, u32) __asm__("ext_540c70");
extern "C" u32 THISCALL ext_5626d0_thiscall2(u32, u32) __asm__("ext_5626d0");
extern "C" u32 THISCALL ext_57c6f0_thiscall5(u32, u32, u32, u32, u32) __asm__("ext_57c6f0");
extern "C" u32 THISCALL ext_5c9530_thiscall1(u32) __asm__("ext_5c9530");
extern "C" u32 THISCALL ext_5ed460_thiscall1(u32) __asm__("ext_5ed460");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_57db50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b342);  // @h_57db50
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_57db50
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_57db50
  eax = ext_5626d0_thiscall2(ecx, (u32)(ebx));  // @2_57db50
  ecx = edx = 0;  // @3_57db50
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L57db9b;  // @4_57db50
  SEH_LEAVE();  // @5_57db50
  return eax;  // @6_57db50
  L57db9b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @8_57db50
  esi = (u32)(edi + 612);  // @9_57db50
  ecx = ebx;  // @10_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 112)))(ecx, (u32)(esi));  // @11_57db50
  ecx = edx = 0;  // @12_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_57db50
  ecx = (u32)(EBP - 16);  // @14_57db50
  ecx = ebx;  // @15_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @16_57db50
  ecx = edx = 0;  // @17_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_57db50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @21_57db50
  ecx = edx = 0;  // @22_57db50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 784), &v, sizeof v); }  // @23_57db50
  ecx = (u32)(EBP - 16);  // @24_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_57db50
  ecx = ebx;  // @26_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(ecx));  // @27_57db50
  ecx = edx = 0;  // @28_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_57db50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @30_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @32_57db50
  ecx = edx = 0;  // @33_57db50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 788), &v, sizeof v); }  // @34_57db50
  if ((esi & esi) == 0) goto L57dcf5;  // @35_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_57db50
  ecx = (u32)(EBP - 32);  // @37_57db50
  ecx = esi;  // @38_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(ecx));  // @39_57db50
  ecx = edx = 0;  // @40_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_57db50
  ecx = (u32)(EBP - 32);  // @42_57db50
  ecx = esi;  // @43_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(ecx));  // @44_57db50
  ecx = edx = 0;  // @45_57db50
  edx = eax;  // @46_57db50
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @47_57db50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) == (u32)(0)) goto L57dcf5;  // @48_57db50
  ebx = (u32)(6990032);  // @49_57db50
  L57dc23:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @51_57db50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @52_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @53_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @54_57db50
  ecx = edx = 0;  // @55_57db50
  eax = ext_41e290_cdecl1((u32)(225));  // @56_57db50
  ecx = edx = 0;  // @57_57db50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @58_57db50
  reg.state = (s32)((u32)(0));  // @59_57db50
  if ((eax & eax) == 0) goto L57dc6a;  // @60_57db50
  ecx = eax;  // @61_57db50
  eax = ext_57c6f0_thiscall5(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 784), sizeof v); (u32)v; }), (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 796), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @62_57db50
  ecx = edx = 0;  // @63_57db50
  esi = eax;  // @64_57db50
  goto L57dc6c;  // @65_57db50
  L57dc6a:;
  esi = 0;  // @67_57db50
  L57dc6c:;
  reg.state = (s32)((u32)(4294967295));  // @69_57db50
  if ((esi & esi) != 0) goto L57dc7b;  // @70_57db50
  ecx = 0;  // @71_57db50
  goto L57dcc0;  // @72_57db50
  L57dc7b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @74_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @75_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(esi));  // @76_57db50
  ecx = edx = 0;  // @77_57db50
  if ((eax & eax) == 0) goto L57dc8f;  // @78_57db50
  ecx = 0;  // @79_57db50
  goto L57dcc0;  // @80_57db50
  L57dc8f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @82_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @83_57db50
  if ((eax & eax) == 0) goto L57dcae;  // @84_57db50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; }) > esi) goto L57dcae;  // @85_57db50
  if (esi >= ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 16), sizeof v); (u32)v; })) goto L57dcae;  // @86_57db50
  ecx = esi;  // @87_57db50
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @88_57db50
  ecx = edx = 0;  // @89_57db50
  ecx = eax;  // @90_57db50
  goto L57dcc0;  // @91_57db50
  L57dcae:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; }) != (u32)(0)) goto L57dcbd;  // @93_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @94_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 172)))(ecx, (u32)(esi));  // @95_57db50
  ecx = edx = 0;  // @96_57db50
  L57dcbd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi - 4), sizeof v); (u32)v; });  // @98_57db50
  L57dcc0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 572), sizeof v); (u32)v; });  // @100_57db50
  ecx = (u32)(edi + 572);  // @101_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(ecx));  // @102_57db50
  ecx = edx = 0;  // @103_57db50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 612), sizeof v); (u32)v; });  // @104_57db50
  ecx = (u32)(edi + 612);  // @105_57db50
  edx = (u32)(EBP - 32);  // @106_57db50
  ebx = (ebx + (u32)(8));  // @107_57db50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(edx));  // @108_57db50
  ecx = edx = 0;  // @109_57db50
  edx = eax;  // @110_57db50
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @111_57db50
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 32), sizeof v); (u32)v; }) != (u32)(0)) goto L57dc23;  // @112_57db50
  L57dcf5:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @114_57db50
  SEH_LEAVE();  // @115_57db50
  return eax;  // @116_57db50
}
PCREG(57db50, lifted_57db50);

extern "C" u32 THISCALL lifted_5c5d20(u32 ecx_in) {
  SEH_ENTER(0x66c693);  // @h_5c5d20
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5c5d20
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5c5d20
  eax = ext_469870_thiscall1(ecx);  // @2_5c5d20
  ecx = edx = 0;  // @3_5c5d20
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5c5d20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5c5d20
  reg.state = (s32)((u32)(0));  // @6_5c5d20
  { u32 v = (u32)((u32)(7029940)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_5c5d20
  eax = ext_41e290_cdecl1((u32)(28));  // @8_5c5d20
  ecx = edx = 0;  // @9_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @10_5c5d20
  reg.state = (s32)((u32)(1));  // @11_5c5d20
  if ((eax & eax) == 0) goto L5c5d8a;  // @12_5c5d20
  ecx = eax;  // @13_5c5d20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @14_5c5d20
  ecx = edx = 0;  // @15_5c5d20
  goto L5c5d8c;  // @16_5c5d20
  L5c5d8a:;
  eax = 0;  // @18_5c5d20
  L5c5d8c:;
  reg.state = (s32)((u32)(0));  // @20_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @21_5c5d20
  eax = ext_41e290_cdecl1((u32)(28));  // @22_5c5d20
  ecx = edx = 0;  // @23_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @24_5c5d20
  reg.state = (s32)((u32)(2));  // @25_5c5d20
  if ((eax & eax) == 0) goto L5c5db5;  // @26_5c5d20
  ecx = eax;  // @27_5c5d20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @28_5c5d20
  ecx = edx = 0;  // @29_5c5d20
  goto L5c5db7;  // @30_5c5d20
  L5c5db5:;
  eax = 0;  // @32_5c5d20
  L5c5db7:;
  reg.state = (s32)((u32)(0));  // @34_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @35_5c5d20
  eax = ext_41e290_cdecl1((u32)(28));  // @36_5c5d20
  ecx = edx = 0;  // @37_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @38_5c5d20
  reg.state = (s32)((u32)(3));  // @39_5c5d20
  if ((eax & eax) == 0) goto L5c5de0;  // @40_5c5d20
  ecx = eax;  // @41_5c5d20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @42_5c5d20
  ecx = edx = 0;  // @43_5c5d20
  goto L5c5de2;  // @44_5c5d20
  L5c5de0:;
  eax = 0;  // @46_5c5d20
  L5c5de2:;
  reg.state = (s32)((u32)(0));  // @48_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @49_5c5d20
  eax = ext_41e290_cdecl1((u32)(28));  // @50_5c5d20
  ecx = edx = 0;  // @51_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @52_5c5d20
  reg.state = (s32)((u32)(4));  // @53_5c5d20
  if ((eax & eax) == 0) goto L5c5e0b;  // @54_5c5d20
  ecx = eax;  // @55_5c5d20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @56_5c5d20
  ecx = edx = 0;  // @57_5c5d20
  goto L5c5e0d;  // @58_5c5d20
  L5c5e0b:;
  eax = 0;  // @60_5c5d20
  L5c5e0d:;
  reg.state = (s32)((u32)(0));  // @62_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @63_5c5d20
  eax = ext_41e290_cdecl1((u32)(28));  // @64_5c5d20
  ecx = edx = 0;  // @65_5c5d20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @66_5c5d20
  reg.state = (s32)((u32)(5));  // @67_5c5d20
  if ((eax & eax) == 0) goto L5c5e36;  // @68_5c5d20
  ecx = eax;  // @69_5c5d20
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(1), (u32)(0));  // @70_5c5d20
  ecx = edx = 0;  // @71_5c5d20
  goto L5c5e38;  // @72_5c5d20
  L5c5e36:;
  eax = 0;  // @74_5c5d20
  L5c5e38:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @76_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @77_5c5d20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @78_5c5d20
  reg.state = (s32)((u32)(0));  // @79_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_5c5d20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6900844), (u32)(0), (u32)(7030208), (u32)(37));  // @81_5c5d20
  ecx = edx = 0;  // @82_5c5d20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422780), &v, sizeof v); }  // @83_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @84_5c5d20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @85_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_5c5d20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7029816), (u32)(0), (u32)(7030208), (u32)(38));  // @87_5c5d20
  ecx = edx = 0;  // @88_5c5d20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422784), &v, sizeof v); }  // @89_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @90_5c5d20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @91_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @92_5c5d20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7029836), (u32)(0), (u32)(7030208), (u32)(39));  // @93_5c5d20
  ecx = edx = 0;  // @94_5c5d20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422788), &v, sizeof v); }  // @95_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @96_5c5d20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @97_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @98_5c5d20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6881040), (u32)(0), (u32)(7030208), (u32)(40));  // @99_5c5d20
  ecx = edx = 0;  // @100_5c5d20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422792), &v, sizeof v); }  // @101_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @102_5c5d20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @103_5c5d20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @104_5c5d20
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6881068), (u32)(0), (u32)(7030208), (u32)(41));  // @105_5c5d20
  ecx = edx = 0;  // @106_5c5d20
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(7422796), &v, sizeof v); }  // @107_5c5d20
  eax = esi;  // @108_5c5d20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @109_5c5d20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @110_5c5d20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }  // @111_5c5d20
  SEH_LEAVE();  // @112_5c5d20
  return eax;  // @113_5c5d20
}
PCREG(5c5d20, lifted_5c5d20);

extern "C" u32 THISCALL lifted_5ef560(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66cd12);  // @h_5ef560
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 169), sizeof v); (u32)v; });  // @1_5ef560
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi));  // @4_5ef560
  ecx = edx = 0;  // @5_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 161), sizeof v); (u32)v; });  // @6_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi));  // @8_5ef560
  ecx = edx = 0;  // @9_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 165), sizeof v); (u32)v; });  // @10_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi));  // @12_5ef560
  ecx = edx = 0;  // @13_5ef560
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @14_5ef560
  eax = (u32)(esi + 8);  // @15_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_5ef560
  ecx = edi;  // @17_5ef560
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(128));  // @18_5ef560
  ecx = edx = 0;  // @19_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @20_5ef560
  eax = (u32)(esi + 136);  // @21_5ef560
  ecx = edi;  // @22_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(eax));  // @23_5ef560
  ecx = edx = 0;  // @24_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @25_5ef560
  eax = (u32)(esi + 140);  // @26_5ef560
  ecx = edi;  // @27_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @28_5ef560
  ecx = edx = 0;  // @29_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @30_5ef560
  eax = (u32)(esi + 144);  // @31_5ef560
  ecx = edi;  // @32_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 72)))(ecx, (u32)(eax));  // @33_5ef560
  ecx = edx = 0;  // @34_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @35_5ef560
  eax = (u32)(esi + 148);  // @36_5ef560
  ecx = edi;  // @37_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @38_5ef560
  ecx = edx = 0;  // @39_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @40_5ef560
  eax = (u32)(esi + 152);  // @41_5ef560
  ecx = edi;  // @42_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @43_5ef560
  ecx = edx = 0;  // @44_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @45_5ef560
  eax = (u32)(esi + 156);  // @46_5ef560
  ecx = edi;  // @47_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @48_5ef560
  ecx = edx = 0;  // @49_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @50_5ef560
  eax = (u32)(esi + 160);  // @51_5ef560
  ecx = edi;  // @52_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @53_5ef560
  ecx = edx = 0;  // @54_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @55_5ef560
  eax = (u32)(esi + 183);  // @56_5ef560
  ecx = edi;  // @57_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(eax));  // @58_5ef560
  ecx = edx = 0;  // @59_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @60_5ef560
  eax = (u32)(esi + 185);  // @61_5ef560
  ecx = edi;  // @62_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 76)))(ecx, (u32)(eax));  // @63_5ef560
  ecx = edx = 0;  // @64_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_5ef560
  eax = (u32)(esi + 181);  // @66_5ef560
  ecx = edi;  // @67_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @68_5ef560
  ecx = edx = 0;  // @69_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @70_5ef560
  ecx = (u32)(EBP - 16);  // @71_5ef560
  ecx = edi;  // @72_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(ecx));  // @73_5ef560
  ecx = edx = 0;  // @74_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @75_5ef560
  ecx = (u32)(EBP - 20);  // @76_5ef560
  ecx = edi;  // @77_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(ecx));  // @78_5ef560
  ecx = edx = 0;  // @79_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @80_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 187), &v, sizeof v); }  // @81_5ef560
  ecx = edi;  // @82_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @83_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 191), &v, sizeof v); }  // @84_5ef560
  eax = (u32)(esi + 182);  // @85_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @86_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @87_5ef560
  ecx = edx = 0;  // @88_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @89_5ef560
  ecx = (u32)(EBP + 11);  // @90_5ef560
  ecx = edi;  // @91_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(ecx));  // @92_5ef560
  ecx = edx = 0;  // @93_5ef560
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 11), sizeof v); (u32)v; }) == (u32)(0)) goto L5ef708;  // @94_5ef560
  eax = ext_41e290_cdecl1((u32)(12));  // @95_5ef560
  ecx = edx = 0;  // @96_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 195), &v, sizeof v); }  // @97_5ef560
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @98_5ef560
  ecx = edi;  // @99_5ef560
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, (u32)(eax), (u32)(12));  // @100_5ef560
  ecx = edx = 0;  // @101_5ef560
  eax = ext_41e290_cdecl1((u32)(247));  // @102_5ef560
  ecx = edx = 0;  // @103_5ef560
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @104_5ef560
  reg.state = (s32)((u32)(0));  // @105_5ef560
  if ((eax & eax) == 0) goto L5ef6da;  // @106_5ef560
  ecx = eax;  // @107_5ef560
  eax = ext_5ed460_thiscall1(ecx);  // @108_5ef560
  ecx = edx = 0;  // @109_5ef560
  ecx = eax;  // @110_5ef560
  goto L5ef6dc;  // @111_5ef560
  L5ef6da:;
  ecx = 0;  // @113_5ef560
  L5ef6dc:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + 177), &v, sizeof v); }  // @115_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @116_5ef560
  reg.state = (s32)((u32)(4294967295));  // @117_5ef560
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(eax + 20)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 195), sizeof v); (u32)v; }), (u32)(0), (u32)(0), (u32)(0), (u32)(0));  // @118_5ef560
  ecx = edx = 0;  // @119_5ef560
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 177), sizeof v); (u32)v; });  // @120_5ef560
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @121_5ef560
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi));  // @122_5ef560
  ecx = edx = 0;  // @123_5ef560
  L5ef708:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 173), &v, sizeof v); }  // @125_5ef560
  SEH_LEAVE();  // @126_5ef560
  return eax;  // @127_5ef560
}
PCREG(5ef560, lifted_5ef560);

extern "C" u32 THISCALL lifted_49d480(u32 ecx_in) {
  SEH_ENTER(0x66b2ab);  // @h_49d480
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_49d480
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(EBP - 156), &v, sizeof v); }  // @1_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @2_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(424));  // @4_49d480
  ecx = edx = 0;  // @5_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(ecx + 44)))(ecx, (u32)(eax), (u32)(6876896));  // @7_49d480
  ecx = edx = 0;  // @8_49d480
  ecx = 0;  // @9_49d480
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; }) == ecx) goto L49d65d;  // @10_49d480
  L49d4e4:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @12_49d480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @13_49d480
  ecx = (ecx + 1);  // @14_49d480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 160), &v, sizeof v); }  // @15_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @16_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @17_49d480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 204)))(ecx, (u32)(edx));  // @18_49d480
  ecx = edx = 0;  // @19_49d480
  esi = eax;  // @20_49d480
  if ((esi & esi) == 0) goto L49d62b;  // @21_49d480
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 24), sizeof v); (u32)v; }) & (u32)(16)) == 0) goto L49d62b;  // @22_49d480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 28), sizeof v); (u32)v; });  // @23_49d480
  if ((edx & edx) == 0) goto L49d57a;  // @24_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @25_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @26_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_49d480
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(edx));  // @28_49d480
  ecx = edx = 0;  // @29_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @30_49d480
  if ((eax & eax) != 0) goto L49d54f;  // @31_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(441));  // @33_49d480
  ecx = edx = 0;  // @34_49d480
  goto L49d645;  // @35_49d480
  L49d54f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @37_49d480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(445), (u32)(6876984));  // @40_49d480
  ecx = edx = 0;  // @41_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @42_49d480
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6877004), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }), (u32)(edi));  // @43_49d480
  ecx = edx = 0;  // @44_49d480
  goto L49d64e;  // @45_49d480
  L49d57a:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @47_49d480
  if ((edi & edi) != 0) goto L49d5a0;  // @48_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @49_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(453));  // @51_49d480
  ecx = edx = 0;  // @52_49d480
  goto L49d645;  // @53_49d480
  L49d5a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 64), sizeof v); (u32)v; });  // @55_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @56_49d480
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 29), sizeof v); (u32)v; });  // @57_49d480
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @58_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @59_49d480
  eax = (eax << (u32)(20));  // @60_49d480
  eax = (eax | ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 32), sizeof v); (u32)v; }));  // @61_49d480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 152), &v, sizeof v); }  // @62_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @63_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(475), (u32)(6877032));  // @64_49d480
  ecx = edx = 0;  // @65_49d480
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @66_49d480
  ebx = eax;  // @67_49d480
  eax = (u32)(EBP - 144);  // @68_49d480
  ecx = edi;  // @69_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @70_49d480
  ecx = edx = 0;  // @71_49d480
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @72_49d480
  ecx = eax;  // @73_49d480
  reg.state = (s32)((u32)(0));  // @74_49d480
  eax = ext_4cc1d0_thiscall1(ecx);  // @75_49d480
  ecx = edx = 0;  // @76_49d480
  eax = ((u32( *)(u32, u32, u32, u32, u32, u32))(*(u32 *)(edi + 44)))((u32)(ebx), (u32)(6877052), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 152), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }), (u32)(eax));  // @77_49d480
  ecx = edx = 0;  // @78_49d480
  reg.state = (s32)((u32)(4294967295));  // @79_49d480
  ecx = (u32)(EBP - 144);  // @80_49d480
  eax = ext_4cbec0_thiscall1(ecx);  // @81_49d480
  ecx = edx = 0;  // @82_49d480
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 156), sizeof v); (u32)v; });  // @83_49d480
  goto L49d64e;  // @84_49d480
  L49d62b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(432));  // @88_49d480
  ecx = edx = 0;  // @89_49d480
  L49d645:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @91_49d480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6876964));  // @92_49d480
  ecx = edx = 0;  // @93_49d480
  L49d64e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 160), sizeof v); (u32)v; });  // @95_49d480
  if (ecx != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 16), sizeof v); (u32)v; })) goto L49d4e4;  // @96_49d480
  L49d65d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @98_49d480
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @99_49d480
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6876832), (u32)(478));  // @100_49d480
  ecx = edx = 0;  // @101_49d480
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @102_49d480
  eax = ((u32( *)(u32, u32))(*(u32 *)(ecx + 44)))((u32)(eax), (u32)(6877112));  // @103_49d480
  ecx = edx = 0;  // @104_49d480
  SEH_LEAVE();  // @105_49d480
  ext_633654(G(u32, 0x6f5630));  // @106_49d480
  return eax;  // @107_49d480
}
PCREG(49d480, lifted_49d480);

extern "C" u32 THISCALL lifted_53ccd0(u32 ecx_in) {
  SEH_ENTER(0x66aab3);  // @h_53ccd0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_53ccd0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_53ccd0
  eax = ext_469870_thiscall1(ecx);  // @2_53ccd0
  ecx = edx = 0;  // @3_53ccd0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_53ccd0
  edi = (u32)(esi + 106);  // @6_53ccd0
  reg.state = (s32)((u32)(0));  // @7_53ccd0
  ecx = edi;  // @8_53ccd0
  { u32 v = (u32)((u32)(6958104)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @9_53ccd0
  eax = ext_540c70_thiscall3(ecx, (u32)(3), (u32)(5));  // @10_53ccd0
  ecx = edx = 0;  // @11_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 330), &v, sizeof v); }  // @12_53ccd0
  ebx = (u32)(esi + 330);  // @13_53ccd0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 329), &v, sizeof v); }  // @14_53ccd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 342), &v, sizeof v); }  // @15_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 334), &v, sizeof v); }  // @16_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @17_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @18_53ccd0
  reg.state = (s32)((u32)(1));  // @19_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958284), (u32)(0), (u32)(6958240), (u32)(153));  // @21_53ccd0
  ecx = edx = 0;  // @22_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @23_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @24_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @25_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6892260), (u32)(0), (u32)(6958240), (u32)(154));  // @27_53ccd0
  ecx = edx = 0;  // @28_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 78), &v, sizeof v); }  // @29_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958300), (u32)(0), (u32)(6958240), (u32)(155));  // @33_53ccd0
  ecx = edx = 0;  // @34_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @35_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @36_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @37_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958312), (u32)(0), (u32)(6958240), (u32)(156));  // @39_53ccd0
  ecx = edx = 0;  // @40_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 82), &v, sizeof v); }  // @41_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @42_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @43_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @44_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6827544), (u32)(0), (u32)(6958240), (u32)(157));  // @45_53ccd0
  ecx = edx = 0;  // @46_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @47_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @48_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @49_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @50_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958328), (u32)(0), (u32)(6958240), (u32)(158));  // @51_53ccd0
  ecx = edx = 0;  // @52_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 86), &v, sizeof v); }  // @53_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @55_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854816), (u32)(0), (u32)(6958240), (u32)(159));  // @57_53ccd0
  ecx = edx = 0;  // @58_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 88), &v, sizeof v); }  // @59_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @60_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @61_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @62_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958340), (u32)(0), (u32)(6958240), (u32)(160));  // @63_53ccd0
  ecx = edx = 0;  // @64_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 90), &v, sizeof v); }  // @65_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @66_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @67_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958352), (u32)(0), (u32)(6958240), (u32)(161));  // @69_53ccd0
  ecx = edx = 0;  // @70_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 92), &v, sizeof v); }  // @71_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @72_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @73_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @74_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6958364), (u32)(0), (u32)(6958240), (u32)(162));  // @75_53ccd0
  ecx = edx = 0;  // @76_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 94), &v, sizeof v); }  // @77_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_53ccd0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_53ccd0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_53ccd0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6854804), (u32)(0), (u32)(6958240), (u32)(163));  // @81_53ccd0
  ecx = edx = 0;  // @82_53ccd0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 96), &v, sizeof v); }  // @83_53ccd0
  eax = (u32)(EBP - 20);  // @84_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 325), &v, sizeof v); }  // @85_53ccd0
  { u32 v = (u32)((u32)(1000)); __builtin_memcpy((void *)(u32)(esi + 247), &v, sizeof v); }  // @86_53ccd0
  eax = esi;  // @87_53ccd0
  { u32 v = (u32)((u32)(1162346496)); __builtin_memcpy((void *)(u32)(esi + 251), &v, sizeof v); }  // @88_53ccd0
  { u32 v = (u32)((u32)(1137180672)); __builtin_memcpy((void *)(u32)(esi + 255), &v, sizeof v); }  // @89_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 98), &v, sizeof v); }  // @90_53ccd0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 271), &v, sizeof v); }  // @91_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 102), &v, sizeof v); }  // @92_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 309), &v, sizeof v); }  // @93_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 313), &v, sizeof v); }  // @94_53ccd0
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 317), &v, sizeof v); }  // @95_53ccd0
  { u32 v = (u32)((u32)(10)); __builtin_memcpy((void *)(u32)(esi + 321), &v, sizeof v); }  // @96_53ccd0
  if (ebx == eax) goto L53cf80;  // @97_53ccd0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @98_53ccd0
  L53cf80:;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + 207), &v, sizeof v); }  // @100_53ccd0
  SEH_LEAVE();  // @101_53ccd0
  return eax;  // @102_53ccd0
}
PCREG(53ccd0, lifted_53ccd0);

extern "C" u32 THISCALL lifted_60d610(u32 ecx_in) {
  SEH_ENTER(0x66e252);  // @h_60d610
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_60d610
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5106), sizeof v); (u32)v; });  // @1_60d610
  if ((edi & edi) == 0) goto L60d685;  // @2_60d610
  reg.state = (s32)((u32)(0));  // @3_60d610
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L60d65d;  // @4_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @5_60d610
  if ((ecx & ecx) == 0) goto L60d669;  // @6_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(ecx));  // @8_60d610
  ecx = edx = 0;  // @9_60d610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @10_60d610
  L60d65d:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_60d610
  if ((ecx & ecx) == 0) goto L60d669;  // @13_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @15_60d610
  ecx = edx = 0;  // @16_60d610
  L60d669:;
  reg.state = (s32)((u32)(4294967295));  // @18_60d610
  eax = ext_634273_cdecl2((u32)(edi), (u32)(42));  // @19_60d610
  ecx = edx = 0;  // @20_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5106), &v, sizeof v); }  // @21_60d610
  L60d685:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5130), sizeof v); (u32)v; });  // @23_60d610
  if ((ecx & ecx) == 0) goto L60d69f;  // @24_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @25_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @26_60d610
  ecx = edx = 0;  // @27_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5130), &v, sizeof v); }  // @28_60d610
  L60d69f:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5110), sizeof v); (u32)v; });  // @30_60d610
  if ((edi & edi) == 0) goto L60d6ee;  // @31_60d610
  reg.state = (s32)((u32)(1));  // @32_60d610
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) == (u32)(0)) goto L60d6c6;  // @33_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @34_60d610
  if ((ecx & ecx) == 0) goto L60d6d2;  // @35_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @36_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(ecx));  // @37_60d610
  ecx = edx = 0;  // @38_60d610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @39_60d610
  L60d6c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_60d610
  if ((ecx & ecx) == 0) goto L60d6d2;  // @42_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @43_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @44_60d610
  ecx = edx = 0;  // @45_60d610
  L60d6d2:;
  reg.state = (s32)((u32)(4294967295));  // @47_60d610
  eax = ext_634273_cdecl2((u32)(edi), (u32)(34));  // @48_60d610
  ecx = edx = 0;  // @49_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5110), &v, sizeof v); }  // @50_60d610
  L60d6ee:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5114), sizeof v); (u32)v; });  // @52_60d610
  if ((ecx & ecx) == 0) goto L60d708;  // @53_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @55_60d610
  ecx = edx = 0;  // @56_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5114), &v, sizeof v); }  // @57_60d610
  L60d708:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5118), sizeof v); (u32)v; });  // @59_60d610
  if ((ecx & ecx) == 0) goto L60d722;  // @60_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @61_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @62_60d610
  ecx = edx = 0;  // @63_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5118), &v, sizeof v); }  // @64_60d610
  L60d722:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5122), sizeof v); (u32)v; });  // @66_60d610
  if ((ecx & ecx) == 0) goto L60d73c;  // @67_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @68_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @69_60d610
  ecx = edx = 0;  // @70_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5122), &v, sizeof v); }  // @71_60d610
  L60d73c:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5126), sizeof v); (u32)v; });  // @73_60d610
  if ((edi & edi) == 0) goto L60d78b;  // @74_60d610
  reg.state = (s32)((u32)(2));  // @75_60d610
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; }) == (u32)(0)) goto L60d763;  // @76_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @77_60d610
  if ((ecx & ecx) == 0) goto L60d76f;  // @78_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @79_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(ecx));  // @80_60d610
  ecx = edx = 0;  // @81_60d610
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @82_60d610
  L60d763:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @84_60d610
  if ((ecx & ecx) == 0) goto L60d76f;  // @85_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @86_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @87_60d610
  ecx = edx = 0;  // @88_60d610
  L60d76f:;
  reg.state = (s32)((u32)(4294967295));  // @90_60d610
  eax = ext_634273_cdecl2((u32)(edi), (u32)(42));  // @91_60d610
  ecx = edx = 0;  // @92_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 5126), &v, sizeof v); }  // @93_60d610
  L60d78b:;
  esi = (esi + (u32)(5134));  // @95_60d610
  edi = (u32)(2);  // @96_60d610
  L60d796:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @98_60d610
  if ((ecx & ecx) == 0) goto L60d7a8;  // @99_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @100_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @101_60d610
  ecx = edx = 0;  // @102_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @103_60d610
  L60d7a8:;
  esi = (esi + (u32)(4));  // @105_60d610
  edi = (edi - (u32)(1));  // @106_60d610
  if (edi != 0) goto L60d796;  // @107_60d610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490120), sizeof v); (u32)v; });  // @108_60d610
  if ((ecx & ecx) == 0) goto L60d7c6;  // @109_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @110_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @111_60d610
  ecx = edx = 0;  // @112_60d610
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(7490120), &v, sizeof v); }  // @113_60d610
  L60d7c6:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490192), sizeof v); (u32)v; });  // @115_60d610
  if ((ecx & ecx) == 0) goto L60d7e0;  // @116_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @117_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @118_60d610
  ecx = edx = 0;  // @119_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7490192), &v, sizeof v); }  // @120_60d610
  L60d7e0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7490336), sizeof v); (u32)v; });  // @122_60d610
  if ((ecx & ecx) == 0) goto L60d7fa;  // @123_60d610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @124_60d610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(ecx));  // @125_60d610
  ecx = edx = 0;  // @126_60d610
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7490336), &v, sizeof v); }  // @127_60d610
  L60d7fa:;
  SEH_LEAVE();  // @129_60d610
  return eax;  // @130_60d610
}
PCREG(60d610, lifted_60d610);

extern "C" u32 THISCALL lifted_5ca720(u32 ecx_in) {
  SEH_ENTER(0x66c7fa);  // @h_5ca720
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_5ca720
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5ca720
  eax = ext_5c9530_thiscall1(ecx);  // @2_5ca720
  ecx = edx = 0;  // @3_5ca720
  { u32 v = (u32)((u32)(7031784)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_5ca720
  eax = (u32)(esi + 1206);  // @5_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @6_5ca720
  ecx = (u32)(EBP - 20);  // @7_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1252), &v, sizeof v); }  // @8_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1256), &v, sizeof v); }  // @9_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1260), &v, sizeof v); }  // @10_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1264), &v, sizeof v); }  // @11_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1268), &v, sizeof v); }  // @12_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1269), &v, sizeof v); }  // @13_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1273), &v, sizeof v); }  // @14_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1277), &v, sizeof v); }  // @15_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1281), &v, sizeof v); }  // @16_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1285), &v, sizeof v); }  // @17_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1289), &v, sizeof v); }  // @18_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1293), &v, sizeof v); }  // @19_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1297), &v, sizeof v); }  // @20_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1301), &v, sizeof v); }  // @21_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1305), &v, sizeof v); }  // @22_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1309), &v, sizeof v); }  // @23_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1313), &v, sizeof v); }  // @24_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1314), &v, sizeof v); }  // @25_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1318), &v, sizeof v); }  // @26_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1322), &v, sizeof v); }  // @27_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1326), &v, sizeof v); }  // @28_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1330), &v, sizeof v); }  // @29_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1334), &v, sizeof v); }  // @30_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1338), &v, sizeof v); }  // @31_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1342), &v, sizeof v); }  // @32_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1346), &v, sizeof v); }  // @33_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1350), &v, sizeof v); }  // @34_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1354), &v, sizeof v); }  // @35_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1358), &v, sizeof v); }  // @36_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1359), &v, sizeof v); }  // @37_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1363), &v, sizeof v); }  // @38_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1367), &v, sizeof v); }  // @39_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1371), &v, sizeof v); }  // @40_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1375), &v, sizeof v); }  // @41_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1379), &v, sizeof v); }  // @42_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1383), &v, sizeof v); }  // @43_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1387), &v, sizeof v); }  // @44_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1391), &v, sizeof v); }  // @45_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1395), &v, sizeof v); }  // @46_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1399), &v, sizeof v); }  // @47_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 1403), &v, sizeof v); }  // @48_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1404), &v, sizeof v); }  // @49_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1408), &v, sizeof v); }  // @50_5ca720
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 1412), &v, sizeof v); }  // @51_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1416), &v, sizeof v); }  // @52_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1420), &v, sizeof v); }  // @53_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1424), &v, sizeof v); }  // @54_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1428), &v, sizeof v); }  // @55_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1452), &v, sizeof v); }  // @56_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1137), &v, sizeof v); }  // @57_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1226), &v, sizeof v); }  // @58_5ca720
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1432), &v, sizeof v); }  // @59_5ca720
  { u32 v = (u32)((u32)(1084227584)); __builtin_memcpy((void *)(u32)(esi + 762), &v, sizeof v); }  // @60_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 778), &v, sizeof v); }  // @61_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @62_5ca720
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @63_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1214), &v, sizeof v); }  // @64_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1210), &v, sizeof v); }  // @65_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1218), &v, sizeof v); }  // @66_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1222), &v, sizeof v); }  // @67_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1105), &v, sizeof v); }  // @68_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1109), &v, sizeof v); }  // @69_5ca720
  { u32 v = (u32)((u32)(2147483648)); __builtin_memcpy((void *)(u32)(esi + 1113), &v, sizeof v); }  // @70_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1117), &v, sizeof v); }  // @71_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1121), &v, sizeof v); }  // @72_5ca720
  { u32 v = (u32)((u32)(2147483648)); __builtin_memcpy((void *)(u32)(esi + 1125), &v, sizeof v); }  // @73_5ca720
  reg.state = (s32)((u32)(0));  // @74_5ca720
  { u32 v = (u32)((u32)(1048576000)); __builtin_memcpy((void *)(u32)(esi + 1202), &v, sizeof v); }  // @75_5ca720
  if (eax == ecx) goto L5ca9fc;  // @76_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @77_5ca720
  L5ca9fc:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1240), &v, sizeof v); }  // @79_5ca720
  { u32 v = (u32)((u32)(1112014848)); __builtin_memcpy((void *)(u32)(esi + 1157), &v, sizeof v); }  // @80_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1145), &v, sizeof v); }  // @81_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1149), &v, sizeof v); }  // @82_5ca720
  { u32 v = (u32)((u32)(1140457472)); __builtin_memcpy((void *)(u32)(esi + 1161), &v, sizeof v); }  // @83_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1227), &v, sizeof v); }  // @84_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1231), &v, sizeof v); }  // @85_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1235), &v, sizeof v); }  // @86_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1244), &v, sizeof v); }  // @87_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1248), &v, sizeof v); }  // @88_5ca720
  { u32 v = (u32)((u32)(4271273625)); __builtin_memcpy((void *)(u32)(esi + 1198), &v, sizeof v); }  // @89_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 216), &v, sizeof v); }  // @90_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 217), &v, sizeof v); }  // @91_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 346), &v, sizeof v); }  // @92_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 347), &v, sizeof v); }  // @93_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 476), &v, sizeof v); }  // @94_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 477), &v, sizeof v); }  // @95_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 606), &v, sizeof v); }  // @96_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 607), &v, sizeof v); }  // @97_5ca720
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 736), &v, sizeof v); }  // @98_5ca720
  { u32 v = (u32)((u32)(1153138688)); __builtin_memcpy((void *)(u32)(esi + 737), &v, sizeof v); }  // @99_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @100_5ca720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @101_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @102_5ca720
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(7032036), (u32)(0), (u32)(7031988), (u32)(165));  // @103_5ca720
  ecx = edx = 0;  // @104_5ca720
  edi = (u32)(esi + 1968);  // @105_5ca720
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 1434), &v, sizeof v); }  // @106_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @107_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1969), &v, sizeof v); }  // @108_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1973), &v, sizeof v); }  // @109_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1977), &v, sizeof v); }  // @110_5ca720
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1239), &v, sizeof v); }  // @111_5ca720
  { u32 v = (u32)((u32)(1068823723)); __builtin_memcpy((void *)(u32)(esi + 1133), &v, sizeof v); }  // @112_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1293), &v, sizeof v); }  // @113_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1338), &v, sizeof v); }  // @114_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1383), &v, sizeof v); }  // @115_5ca720
  { u32 v = (u32)((u32)(1000593162)); __builtin_memcpy((void *)(u32)(esi + 1428), &v, sizeof v); }  // @116_5ca720
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 1141), &v, sizeof v); }  // @117_5ca720
  eax = ext_41e290_cdecl1((u32)(264));  // @118_5ca720
  ecx = edx = 0;  // @119_5ca720
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @120_5ca720
  reg.state = (s32)((u32)(1));  // @121_5ca720
  if ((eax & eax) == 0) goto L5cab7f;  // @122_5ca720
  ecx = eax;  // @123_5ca720
  eax = ext_4d83b0_thiscall4(ecx, (u32)(7032084), (u32)(7032052), (u32)(edi));  // @124_5ca720
  ecx = edx = 0;  // @125_5ca720
  edx = eax;  // @126_5ca720
  goto L5cab81;  // @127_5ca720
  L5cab7f:;
  edx = 0;  // @129_5ca720
  L5cab81:;
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(esi + 1448), &v, sizeof v); }  // @131_5ca720
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @132_5ca720
  reg.state = (s32)((u32)(0));  // @133_5ca720
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @134_5ca720
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 420)))(ecx, (u32)(edx));  // @135_5ca720
  ecx = edx = 0;  // @136_5ca720
  eax = esi;  // @137_5ca720
  SEH_LEAVE();  // @138_5ca720
  return eax;  // @139_5ca720
}
PCREG(5ca720, lifted_5ca720);

extern "C" u32 THISCALL lifted_63cfe0(u32 ecx_in) {
  SEH_ENTER(0x66e848);  // @h_63cfe0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + (-16), &ecx, 4);
  esi = ecx;  // @0_63cfe0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 536), sizeof v); (u32)v; }) != (u32)(0)) goto L63d052;  // @1_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @2_63cfe0
  ecx = edx = 0;  // @3_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_63cfe0
  if ((eax & eax) == 0) goto L63d043;  // @5_63cfe0
  ecx = (u32)(esi + 568);  // @6_63cfe0
  { u32 v = (u32)((u32)(7087124)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @7_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @8_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @10_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @11_63cfe0
  goto L63d045;  // @12_63cfe0
  L63d043:;
  eax = 0;  // @14_63cfe0
  L63d045:;
  reg.state = (s32)((u32)(4294967295));  // @16_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 536), &v, sizeof v); }  // @17_63cfe0
  L63d052:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 540), sizeof v); (u32)v; }) != (u32)(0)) goto L63d09e;  // @19_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @20_63cfe0
  ecx = edx = 0;  // @21_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @22_63cfe0
  if ((eax & eax) == 0) goto L63d08f;  // @23_63cfe0
  ecx = (u32)(esi + 568);  // @24_63cfe0
  { u32 v = (u32)((u32)(7087184)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @25_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @26_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @27_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @28_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @29_63cfe0
  goto L63d091;  // @30_63cfe0
  L63d08f:;
  eax = 0;  // @32_63cfe0
  L63d091:;
  reg.state = (s32)((u32)(4294967295));  // @34_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 540), &v, sizeof v); }  // @35_63cfe0
  L63d09e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 544), sizeof v); (u32)v; }) != (u32)(0)) goto L63d0ea;  // @37_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @38_63cfe0
  ecx = edx = 0;  // @39_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @40_63cfe0
  if ((eax & eax) == 0) goto L63d0db;  // @41_63cfe0
  ecx = (u32)(esi + 568);  // @42_63cfe0
  { u32 v = (u32)((u32)(7087244)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @43_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @44_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @45_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @46_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @47_63cfe0
  goto L63d0dd;  // @48_63cfe0
  L63d0db:;
  eax = 0;  // @50_63cfe0
  L63d0dd:;
  reg.state = (s32)((u32)(4294967295));  // @52_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 544), &v, sizeof v); }  // @53_63cfe0
  L63d0ea:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 548), sizeof v); (u32)v; }) != (u32)(0)) goto L63d136;  // @55_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @56_63cfe0
  ecx = edx = 0;  // @57_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @58_63cfe0
  if ((eax & eax) == 0) goto L63d127;  // @59_63cfe0
  ecx = (u32)(esi + 568);  // @60_63cfe0
  { u32 v = (u32)((u32)(7087304)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @61_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @62_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @63_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @64_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @65_63cfe0
  goto L63d129;  // @66_63cfe0
  L63d127:;
  eax = 0;  // @68_63cfe0
  L63d129:;
  reg.state = (s32)((u32)(4294967295));  // @70_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 548), &v, sizeof v); }  // @71_63cfe0
  L63d136:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 552), sizeof v); (u32)v; }) != (u32)(0)) goto L63d182;  // @73_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @74_63cfe0
  ecx = edx = 0;  // @75_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @76_63cfe0
  if ((eax & eax) == 0) goto L63d173;  // @77_63cfe0
  ecx = (u32)(esi + 568);  // @78_63cfe0
  { u32 v = (u32)((u32)(7087364)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @79_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @80_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @81_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @82_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @83_63cfe0
  goto L63d175;  // @84_63cfe0
  L63d173:;
  eax = 0;  // @86_63cfe0
  L63d175:;
  reg.state = (s32)((u32)(4294967295));  // @88_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 552), &v, sizeof v); }  // @89_63cfe0
  L63d182:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 556), sizeof v); (u32)v; }) != (u32)(0)) goto L63d1ce;  // @91_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @92_63cfe0
  ecx = edx = 0;  // @93_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @94_63cfe0
  if ((eax & eax) == 0) goto L63d1bf;  // @95_63cfe0
  ecx = (u32)(esi + 568);  // @96_63cfe0
  { u32 v = (u32)((u32)(7087424)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @97_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @98_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @99_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @100_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @101_63cfe0
  goto L63d1c1;  // @102_63cfe0
  L63d1bf:;
  eax = 0;  // @104_63cfe0
  L63d1c1:;
  reg.state = (s32)((u32)(4294967295));  // @106_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 556), &v, sizeof v); }  // @107_63cfe0
  L63d1ce:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 560), sizeof v); (u32)v; }) != (u32)(0)) goto L63d21a;  // @109_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @110_63cfe0
  ecx = edx = 0;  // @111_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @112_63cfe0
  if ((eax & eax) == 0) goto L63d20b;  // @113_63cfe0
  ecx = (u32)(esi + 568);  // @114_63cfe0
  { u32 v = (u32)((u32)(7087484)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @115_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @116_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @117_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @118_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @119_63cfe0
  goto L63d20d;  // @120_63cfe0
  L63d20b:;
  eax = 0;  // @122_63cfe0
  L63d20d:;
  reg.state = (s32)((u32)(4294967295));  // @124_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 560), &v, sizeof v); }  // @125_63cfe0
  L63d21a:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 564), sizeof v); (u32)v; }) != (u32)(0)) goto L63d25f;  // @127_63cfe0
  eax = ext_41e290_cdecl1((u32)(20));  // @128_63cfe0
  ecx = edx = 0;  // @129_63cfe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @130_63cfe0
  if ((eax & eax) == 0) goto L63d257;  // @131_63cfe0
  ecx = (u32)(esi + 568);  // @132_63cfe0
  { u32 v = (u32)((u32)(7087544)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @133_63cfe0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @134_63cfe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @135_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 12), &v, sizeof v); }  // @136_63cfe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @137_63cfe0
  goto L63d259;  // @138_63cfe0
  L63d257:;
  eax = 0;  // @140_63cfe0
  L63d259:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 564), &v, sizeof v); }  // @142_63cfe0
  L63d25f:;
  SEH_LEAVE();  // @144_63cfe0
  return eax;  // @145_63cfe0
}
PCREG(63cfe0, lifted_63cfe0);

extern "C" u32 THISCALL lifted_452bc0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x666326);  // @h_452bc0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_452bc0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 288), &v, sizeof v); }  // @2_452bc0
  eax = ext_448a30_thiscall2(ecx, (u32)(esi));  // @3_452bc0
  ecx = edx = 0;  // @4_452bc0
  ecx = esi;  // @5_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 292), &v, sizeof v); }  // @6_452bc0
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 296), &v, sizeof v); }  // @7_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 300), &v, sizeof v); }  // @8_452bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 304), &v, sizeof v); }  // @9_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @10_452bc0
  ecx = edx = 0;  // @11_452bc0
  if ((eax & 0xff) != (u32)(2)) goto L452d47;  // @12_452bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @13_452bc0
  ecx = ebx;  // @14_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @15_452bc0
  ecx = edx = 0;  // @16_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @17_452bc0
  esi = eax;  // @18_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @19_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(63));  // @20_452bc0
  ecx = edx = 0;  // @21_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @22_452bc0
  edi = eax;  // @23_452bc0
  eax = (u32)(EBP - 156);  // @24_452bc0
  ecx = esi;  // @25_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @26_452bc0
  ecx = edx = 0;  // @27_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @28_452bc0
  ecx = eax;  // @29_452bc0
  reg.state = (s32)((u32)(0));  // @30_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @31_452bc0
  ecx = edx = 0;  // @32_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 48)))((u32)(edi), (u32)(6813044), (u32)(eax));  // @33_452bc0
  ecx = edx = 0;  // @34_452bc0
  reg.state = (s32)((u32)(4294967295));  // @35_452bc0
  ecx = (u32)(EBP - 156);  // @36_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @37_452bc0
  ecx = edx = 0;  // @38_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @39_452bc0
  ecx = esi;  // @40_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @41_452bc0
  ecx = edx = 0;  // @42_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452cbb;  // @43_452bc0
  eax = (u32)(EBP - 288);  // @44_452bc0
  ecx = esi;  // @45_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @46_452bc0
  ecx = edx = 0;  // @47_452bc0
  goto L452d47;  // @48_452bc0
  L452cbb:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_452bc0
  ecx = ebx;  // @51_452bc0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @52_452bc0
  ecx = edx = 0;  // @53_452bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @54_452bc0
  esi = eax;  // @55_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @56_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 32)))(ecx, (u32)(6822564), (u32)(68));  // @57_452bc0
  ecx = edx = 0;  // @58_452bc0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_452bc0
  edi = eax;  // @60_452bc0
  eax = (u32)(EBP - 284);  // @61_452bc0
  ecx = esi;  // @62_452bc0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(eax), (u32)(1));  // @63_452bc0
  ecx = edx = 0;  // @64_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @65_452bc0
  ecx = eax;  // @66_452bc0
  reg.state = (s32)((u32)(1));  // @67_452bc0
  eax = ext_4cc1d0_thiscall1(ecx);  // @68_452bc0
  ecx = edx = 0;  // @69_452bc0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(edi), (u32)(6822612), (u32)(eax));  // @70_452bc0
  ecx = edx = 0;  // @71_452bc0
  reg.state = (s32)((u32)(4294967295));  // @72_452bc0
  ecx = (u32)(EBP - 284);  // @73_452bc0
  eax = ext_4cbec0_thiscall1(ecx);  // @74_452bc0
  ecx = edx = 0;  // @75_452bc0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 288), sizeof v); (u32)v; });  // @76_452bc0
  eax = (u32)(EBP - 28);  // @77_452bc0
  ecx = esi;  // @78_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @79_452bc0
  ecx = edx = 0;  // @80_452bc0
  eax = (u32)(EBP - 24);  // @81_452bc0
  ecx = esi;  // @82_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @83_452bc0
  ecx = edx = 0;  // @84_452bc0
  eax = (u32)(EBP - 20);  // @85_452bc0
  ecx = esi;  // @86_452bc0
  eax = ext_4e12f0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @87_452bc0
  ecx = edx = 0;  // @88_452bc0
  L452d47:;
  eax = (u32)(EBP - 292);  // @90_452bc0
  ecx = esi;  // @91_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @92_452bc0
  ecx = edx = 0;  // @93_452bc0
  eax = (u32)(EBP - 296);  // @94_452bc0
  ecx = esi;  // @95_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @96_452bc0
  ecx = edx = 0;  // @97_452bc0
  ecx = esi;  // @98_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @99_452bc0
  ecx = edx = 0;  // @100_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d82;  // @101_452bc0
  eax = (u32)(EBP - 300);  // @102_452bc0
  ecx = esi;  // @103_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @104_452bc0
  ecx = edx = 0;  // @105_452bc0
  L452d82:;
  ecx = esi;  // @107_452bc0
  eax = ext_4e1600_thiscall1(ecx);  // @108_452bc0
  ecx = edx = 0;  // @109_452bc0
  if ((eax & 0xff) != (u32)(3)) goto L452d9d;  // @110_452bc0
  eax = (u32)(EBP - 304);  // @111_452bc0
  ecx = esi;  // @112_452bc0
  eax = ext_4e11e0_thiscall3(ecx, (u32)(eax), (u32)(1));  // @113_452bc0
  ecx = edx = 0;  // @114_452bc0
  L452d9d:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) & (u32)(4294955007))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @116_452bc0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 292), sizeof v); (u32)v; }) == (u32)(0)) goto L452db4;  // @117_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(4096))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @118_452bc0
  L452db4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L452dc4;  // @120_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(8192))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @121_452bc0
  L452dc4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 300), sizeof v); (u32)v; }) == (u32)(0)) goto L452dd4;  // @123_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(16384))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @124_452bc0
  L452dd4:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 304), sizeof v); (u32)v; }) == (u32)(0)) goto L452de4;  // @126_452bc0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 24), sizeof v); (u32)v; }) | (u32)(32768))); __builtin_memcpy((void *)(u32)(ebx + 24), &v, sizeof v); }  // @127_452bc0
  L452de4:;
  ecx = esi;  // @129_452bc0
  eax = ext_4e1b30_thiscall1(ecx);  // @130_452bc0
  ecx = edx = 0;  // @131_452bc0
  SEH_LEAVE();  // @132_452bc0
  ext_633654(G(u32, 0x6f5630));  // @133_452bc0
  return eax;  // @134_452bc0
}
PCREG(452bc0, lifted_452bc0);

