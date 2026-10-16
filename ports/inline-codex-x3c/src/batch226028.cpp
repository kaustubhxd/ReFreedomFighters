// batch226028.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_456b70_thiscall3(u32, u32, u32) __asm__("ext_456b70");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_516b60(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66a0d6);  // @h_516b60
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  ebx = ecx;  // @0_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_516b60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_516b60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @3_516b60
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @4_516b60
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(ebx + 41), &v, sizeof v); }  // @5_516b60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @6_516b60
  if ((eax & eax) != 0) goto L516c56;  // @7_516b60
  ecx = edx;  // @8_516b60
  edi = (u32)(ecx + 1);  // @9_516b60
  L516bb2:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @11_516b60
  ecx = (ecx + 1);  // @12_516b60
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L516bb2;  // @13_516b60
  ecx = (ecx - edi);  // @14_516b60
  if (ecx == 0) goto L516c56;  // @15_516b60
  PS[0] = edx;  // @16_516b60
  ecx = (u32)(EBP - 144);  // @17_516b60
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @18_516b60
  ecx = edx = 0;  // @19_516b60
  ecx = (u32)(EBP - 144);  // @20_516b60
  reg.state = (s32)((u32)(0));  // @21_516b60
  eax = ext_456ab0_thiscall1(ecx);  // @22_516b60
  ecx = edx = 0;  // @23_516b60
  ecx = (u32)(EBP - 144);  // @24_516b60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @25_516b60
  reg.state = (s32)((u32)(4294967295));  // @26_516b60
  eax = ext_4cbec0_thiscall1(ecx);  // @27_516b60
  ecx = edx = 0;  // @28_516b60
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; }) != (u32)(0)) goto L516c56;  // @29_516b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @30_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_516b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6941536), (u32)(116));  // @32_516b60
  ecx = edx = 0;  // @33_516b60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @34_516b60
  edi = eax;  // @35_516b60
  eax = (u32)(EBP - 272);  // @36_516b60
  ecx = esi;  // @37_516b60
  PS[1] = eax;  // @38_516b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @39_516b60
  ecx = edx = 0;  // @40_516b60
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_516b60
  ecx = eax;  // @42_516b60
  reg.state = (s32)((u32)(1));  // @43_516b60
  eax = ext_4cc1d0_thiscall1(ecx);  // @44_516b60
  ecx = edx = 0;  // @45_516b60
  PS[0] = eax;  // @46_516b60
  PS[3] = edi;  // @47_516b60
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[3]), (u32)(6941584), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 280), sizeof v); (u32)v; }), (u32)(PS[0]));  // @48_516b60
  ecx = edx = 0;  // @49_516b60
  reg.state = (s32)((u32)(4294967295));  // @50_516b60
  ecx = (u32)(EBP - 272);  // @51_516b60
  eax = ext_4cbec0_thiscall1(ecx);  // @52_516b60
  ecx = edx = 0;  // @53_516b60
  L516c56:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @55_516b60
  if ((edx & edx) == 0) goto L516cf1;  // @56_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @57_516b60
  PS[0] = edx;  // @58_516b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @59_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_516b60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @61_516b60
  ecx = edx = 0;  // @62_516b60
  esi = eax;  // @63_516b60
  if ((esi & esi) == 0) goto L516cb9;  // @64_516b60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @65_516b60
  ecx = esi;  // @66_516b60
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 480), sizeof v); (u32)v; });  // @67_516b60
  eax = ((u32(THISCALL *)(u32, u32))(edx))(ecx, (u32)(2097381));  // @68_516b60
  ecx = edx = 0;  // @69_516b60
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L516cb9;  // @70_516b60
  eax = (u32)(ebx + 4);  // @71_516b60
  ecx = esi;  // @72_516b60
  PS[0] = eax;  // @73_516b60
  eax = (u32)(EBP - 276);  // @74_516b60
  PS[1] = eax;  // @75_516b60
  eax = ext_456b70_thiscall3(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @76_516b60
  ecx = edx = 0;  // @77_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @78_516b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @79_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @80_516b60
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 276), sizeof v); (u32)v; }));  // @81_516b60
  ecx = edx = 0;  // @82_516b60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx), &v, sizeof v); }  // @83_516b60
  goto L516cf1;  // @84_516b60
  L516cb9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_516b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_516b60
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6941536), (u32)(124));  // @88_516b60
  ecx = edx = 0;  // @89_516b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 41), sizeof v); (u32)v; });  // @90_516b60
  edx = (u32)(6801640);  // @91_516b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 4), sizeof v); (u32)v; });  // @92_516b60
  if ((ecx & ecx) != 0) edx = ecx;  // @93_516b60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @94_516b60
  PS[0] = edx;  // @95_516b60
  PS[2] = eax;  // @96_516b60
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 44)))((u32)(PS[2]), (u32)(6941632), (u32)(PS[0]));  // @97_516b60
  ecx = edx = 0;  // @98_516b60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 8), &v, sizeof v); }  // @99_516b60
  L516cf1:;
  SEH_LEAVE();  // @101_516b60
  ext_633654(G(u32, 0x6f5630));  // @102_516b60
  return eax;  // @103_516b60
}
PCREG(516b60, lifted_516b60);

extern "C" u32 STDCALL lifted_468b10(u32 a0) {
  SEH_ENTER(0x66bdd6);  // @h_468b10
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_468b10
  ecx = esi;  // @1_468b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @2_468b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 480), sizeof v); (u32)v; });  // @3_468b10
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1050578));  // @4_468b10
  ecx = edx = 0;  // @5_468b10
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L468bc7;  // @6_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @7_468b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(4216));  // @9_468b10
  ecx = edx = 0;  // @10_468b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_468b10
  ebx = eax;  // @12_468b10
  eax = (u32)(EBP - 144);  // @13_468b10
  ecx = esi;  // @14_468b10
  PS[1] = eax;  // @15_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @16_468b10
  ecx = edx = 0;  // @17_468b10
  edi = eax;  // @18_468b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @19_468b10
  ecx = esi;  // @20_468b10
  reg.state = (s32)((u32)(0));  // @21_468b10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @22_468b10
  ecx = edx = 0;  // @23_468b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @24_468b10
  edx = (u32)(6801640);  // @25_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @26_468b10
  if ((ecx & ecx) != 0) edx = ecx;  // @27_468b10
  ecx = edi;  // @28_468b10
  PS[0] = edx;  // @29_468b10
  eax = ext_4cc1d0_cdecl1((u32)(PS[0]));  // @30_468b10
  ecx = edx = 0;  // @31_468b10
  PS[0] = eax;  // @32_468b10
  PS[2] = ebx;  // @33_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(PS[2]), (u32)(6852516), (u32)(PS[0]));  // @34_468b10
  ecx = edx = 0;  // @35_468b10
  ecx = (u32)(EBP - 144);  // @36_468b10
  eax = ext_4cbec0_thiscall1(ecx);  // @37_468b10
  ecx = edx = 0;  // @38_468b10
  goto L468c84;  // @39_468b10
  L468bc7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_468b10
  ecx = esi;  // @42_468b10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 808)))(ecx);  // @43_468b10
  ecx = edx = 0;  // @44_468b10
  edi = eax;  // @45_468b10
  if ((edi & edi) != 0) goto L468c45;  // @46_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @47_468b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(4224));  // @49_468b10
  ecx = edx = 0;  // @50_468b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @51_468b10
  ebx = eax;  // @52_468b10
  eax = (u32)(EBP - 272);  // @53_468b10
  ecx = esi;  // @54_468b10
  PS[1] = eax;  // @55_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @56_468b10
  ecx = edx = 0;  // @57_468b10
  edi = eax;  // @58_468b10
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @59_468b10
  ecx = esi;  // @60_468b10
  reg.state = (s32)((u32)(1));  // @61_468b10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @62_468b10
  ecx = edx = 0;  // @63_468b10
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_468b10
  edx = (u32)(6801640);  // @65_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @66_468b10
  if ((ecx & ecx) != 0) edx = ecx;  // @67_468b10
  ecx = edi;  // @68_468b10
  PS[0] = edx;  // @69_468b10
  eax = ext_4cc1d0_cdecl1((u32)(PS[0]));  // @70_468b10
  ecx = edx = 0;  // @71_468b10
  PS[0] = eax;  // @72_468b10
  PS[2] = ebx;  // @73_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(PS[2]), (u32)(6852556), (u32)(PS[0]));  // @74_468b10
  ecx = edx = 0;  // @75_468b10
  ecx = (u32)(EBP - 272);  // @76_468b10
  eax = ext_4cbec0_thiscall1(ecx);  // @77_468b10
  ecx = edx = 0;  // @78_468b10
  goto L468c84;  // @79_468b10
  L468c45:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @81_468b10
  ecx = edi;  // @82_468b10
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 820)))(ecx);  // @83_468b10
  ecx = edx = 0;  // @84_468b10
  if ((eax & eax) != 0) goto L468c86;  // @85_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @86_468b10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @87_468b10
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6850500), (u32)(4231));  // @88_468b10
  ecx = edx = 0;  // @89_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @90_468b10
  edx = (u32)(6801640);  // @91_468b10
  if ((ecx & ecx) != 0) edx = ecx;  // @92_468b10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @93_468b10
  PS[0] = edx;  // @94_468b10
  PS[2] = eax;  // @95_468b10
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(ecx + 48)))((u32)(PS[2]), (u32)(6852592), (u32)(PS[0]));  // @96_468b10
  ecx = edx = 0;  // @97_468b10
  L468c84:;
  eax = 0;  // @99_468b10
  L468c86:;
  SEH_LEAVE();  // @101_468b10
  ext_633654(G(u32, 0x6f5630));  // @102_468b10
  return eax;  // @103_468b10
}
PCREG(468b10, lifted_468b10);

