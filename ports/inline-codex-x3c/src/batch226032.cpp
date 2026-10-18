// batch226032.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4d2030_thiscall2(u32, u32) __asm__("ext_4d2030");
extern "C" u32 THISCALL ext_4d9ce0_thiscall1(u32) __asm__("ext_4d9ce0");
extern "C" u32 THISCALL ext_4da720_thiscall2(u32, u32) __asm__("ext_4da720");
extern "C" u32 THISCALL ext_4e3180_thiscall1(u32) __asm__("ext_4e3180");
extern "C" u32 THISCALL ext_4e49d0_thiscall2(u32, u32) __asm__("ext_4e49d0");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_44a1f0_cdecl0(void) __asm__("ext_44a1f0");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_5afef0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66681b);  // @h_5afef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_5afef0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5afef0
  ecx = (u32)(EBP - 188);  // @2_5afef0
  eax = ext_4ccba0_thiscall1(ecx);  // @3_5afef0
  ecx = edx = 0;  // @4_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @5_5afef0
  ecx = esi;  // @6_5afef0
  reg.state = (s32)((u32)(0));  // @7_5afef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 744)))(ecx);  // @8_5afef0
  ecx = edx = 0;  // @9_5afef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 68), sizeof v); (u32)v; });  // @10_5afef0
  ebx = eax;  // @11_5afef0
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7467), sizeof v); (u32)v; });  // @12_5afef0
  eax = (u32)(EBP - 188);  // @13_5afef0
  PS[0] = eax;  // @14_5afef0
  PS[1] = edx;  // @15_5afef0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_5afef0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 304)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 7435), sizeof v); (u32)v; }), (u32)(PS[1]), (u32)(PS[0]));  // @17_5afef0
  ecx = edx = 0;  // @18_5afef0
  eax = (u32)(EBP - 200);  // @19_5afef0
  esi = 0;  // @20_5afef0
  PS[0] = eax;  // @21_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @22_5afef0
  ecx = (u32)(EBP - 188);  // @23_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @24_5afef0
  ecx = edx = 0;  // @25_5afef0
  eax = (u32)(EBP - 200);  // @26_5afef0
  PS[0] = eax;  // @27_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @28_5afef0
  ecx = (u32)(EBP - 188);  // @29_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @30_5afef0
  ecx = edx = 0;  // @31_5afef0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == esi) goto L5affe0;  // @32_5afef0
  L5affa0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @34_5afef0
  PS[0] = eax;  // @35_5afef0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @36_5afef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @37_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @38_5afef0
  ecx = edx = 0;  // @39_5afef0
  ecx = eax;  // @40_5afef0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @41_5afef0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 744)))(ecx);  // @42_5afef0
  ecx = edx = 0;  // @43_5afef0
  if (eax != ebx) goto L5affc1;  // @44_5afef0
  esi = (esi + 1);  // @45_5afef0
  L5affc1:;
  eax = (u32)(EBP - 200);  // @47_5afef0
  PS[0] = eax;  // @48_5afef0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @49_5afef0
  ecx = (u32)(EBP - 188);  // @50_5afef0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @51_5afef0
  ecx = edx = 0;  // @52_5afef0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L5affa0;  // @53_5afef0
  L5affe0:;
  ecx = (u32)(EBP - 188);  // @55_5afef0
  eax = ext_4ccf60_thiscall1(ecx);  // @56_5afef0
  ecx = edx = 0;  // @57_5afef0
  eax = esi;  // @58_5afef0
  SEH_LEAVE();  // @59_5afef0
  ext_633654(G(u32, 0x6f5630));  // @60_5afef0
  return eax;  // @61_5afef0
}
PCREG(5afef0, lifted_5afef0);

extern "C" u32 THISCALL lifted_42c380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d7c);  // @h_42c380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_42c380
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_42c380
  ecx = (u32)(EBP - 144);  // @2_42c380
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 404), &v, sizeof v); }  // @3_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @4_42c380
  ecx = edx = 0;  // @5_42c380
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_42c380
  ecx = (u32)(EBP - 400);  // @7_42c380
  PS[0] = ecx;  // @8_42c380
  ecx = esi;  // @9_42c380
  reg.state = (s32)((u32)(0));  // @10_42c380
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 284)))(ecx, (u32)(PS[0]));  // @11_42c380
  ecx = edx = 0;  // @12_42c380
  PS[0] = eax;  // @13_42c380
  ecx = (u32)(EBP - 144);  // @14_42c380
  reg.state = (s32)((u32)(1));  // @15_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @16_42c380
  ecx = edx = 0;  // @17_42c380
  ecx = (u32)(EBP - 400);  // @18_42c380
  reg.state = (s32)((u32)(0));  // @19_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @20_42c380
  ecx = edx = 0;  // @21_42c380
  ecx = (u32)(EBP - 144);  // @22_42c380
  eax = ext_4cc5f0_thiscall1(ecx);  // @23_42c380
  ecx = edx = 0;  // @24_42c380
  if ((eax & eax) != 0) goto L42c41d;  // @25_42c380
  eax = (u32)(EBP - 144);  // @26_42c380
  ecx = edi;  // @27_42c380
  PS[0] = eax;  // @28_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(PS[0]));  // @29_42c380
  ecx = edx = 0;  // @30_42c380
  goto L42c48c;  // @31_42c380
  L42c41d:;
  ecx = (u32)(EBP - 272);  // @33_42c380
  eax = ext_4cbeb0_thiscall1(ecx);  // @34_42c380
  ecx = edx = 0;  // @35_42c380
  ecx = (u32)(EBP - 400);  // @36_42c380
  reg.state = (s32)((u32)(2));  // @37_42c380
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6789684));  // @38_42c380
  ecx = edx = 0;  // @39_42c380
  eax = (u32)(EBP - 400);  // @40_42c380
  reg.state = (s32)((u32)(3));  // @41_42c380
  PS[0] = eax;  // @42_42c380
  ecx = (u32)(EBP - 272);  // @43_42c380
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @44_42c380
  ecx = edx = 0;  // @45_42c380
  ecx = (u32)(EBP - 400);  // @46_42c380
  reg.state = (s32)((u32)(2));  // @47_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @48_42c380
  ecx = edx = 0;  // @49_42c380
  eax = (u32)(EBP - 144);  // @50_42c380
  PS[0] = eax;  // @51_42c380
  ecx = (u32)(EBP - 272);  // @52_42c380
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(PS[0]));  // @53_42c380
  ecx = edx = 0;  // @54_42c380
  eax = (u32)(EBP - 272);  // @55_42c380
  ecx = edi;  // @56_42c380
  PS[0] = eax;  // @57_42c380
  eax = ext_4cbe50_thiscall2(ecx, (u32)(PS[0]));  // @58_42c380
  ecx = edx = 0;  // @59_42c380
  ecx = (u32)(EBP - 272);  // @60_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @61_42c380
  ecx = edx = 0;  // @62_42c380
  L42c48c:;
  ecx = (u32)(EBP - 144);  // @64_42c380
  eax = ext_4cbec0_thiscall1(ecx);  // @65_42c380
  ecx = edx = 0;  // @66_42c380
  eax = edi;  // @67_42c380
  SEH_LEAVE();  // @68_42c380
  ext_633654(G(u32, 0x6f5630));  // @69_42c380
  return eax;  // @70_42c380
}
PCREG(42c380, lifted_42c380);

extern "C" u32 THISCALL lifted_442ad0(u32 ecx_in) {
  SEH_ENTER(0x665e7b);  // @h_442ad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_442ad0
  eax = ext_44a1f0_cdecl0();  // @1_442ad0
  ecx = edx = 0;  // @2_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_442ad0
  ecx = esi;  // @4_442ad0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 788)))(ecx);  // @5_442ad0
  ecx = edx = 0;  // @6_442ad0
  esi = eax;  // @7_442ad0
  if ((esi & esi) == 0) goto L442be2;  // @8_442ad0
  ecx = (u32)(EBP - 188);  // @9_442ad0
  eax = ext_4ccba0_thiscall1(ecx);  // @10_442ad0
  ecx = edx = 0;  // @11_442ad0
  ecx = (u32)(EBP - 284);  // @12_442ad0
  reg.state = (s32)((u32)(0));  // @13_442ad0
  eax = ext_4e3180_thiscall1(ecx);  // @14_442ad0
  ecx = edx = 0;  // @15_442ad0
  eax = (u32)(EBP - 188);  // @16_442ad0
  { u32 v = (u32)((u32)(5124816)); __builtin_memcpy((void *)(u32)(EBP - 280), &v, sizeof v); }  // @17_442ad0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 192), &v, sizeof v); }  // @18_442ad0
  ecx = esi;  // @19_442ad0
  eax = (u32)(EBP - 284);  // @20_442ad0
  PS[0] = eax;  // @21_442ad0
  eax = ext_4e49d0_thiscall2(ecx, (u32)(PS[0]));  // @22_442ad0
  ecx = edx = 0;  // @23_442ad0
  eax = (u32)(EBP - 296);  // @24_442ad0
  PS[0] = eax;  // @25_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @26_442ad0
  ecx = (u32)(EBP - 188);  // @27_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @28_442ad0
  ecx = edx = 0;  // @29_442ad0
  eax = (u32)(EBP - 296);  // @30_442ad0
  PS[0] = eax;  // @31_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @32_442ad0
  ecx = (u32)(EBP - 188);  // @33_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @34_442ad0
  ecx = edx = 0;  // @35_442ad0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) == (u32)(0)) goto L442bd7;  // @36_442ad0
  L442b90:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @38_442ad0
  PS[0] = eax;  // @39_442ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @40_442ad0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @41_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 84)))(ecx, (u32)(PS[0]));  // @42_442ad0
  ecx = edx = 0;  // @43_442ad0
  esi = eax;  // @44_442ad0
  if ((esi & esi) == 0) goto L442bb8;  // @45_442ad0
  ecx = esi;  // @46_442ad0
  eax = ext_4da720_thiscall2(ecx, (u32)(0));  // @47_442ad0
  ecx = edx = 0;  // @48_442ad0
  ecx = esi;  // @49_442ad0
  eax = ext_4d9ce0_thiscall1(ecx);  // @50_442ad0
  ecx = edx = 0;  // @51_442ad0
  L442bb8:;
  eax = (u32)(EBP - 296);  // @53_442ad0
  PS[0] = eax;  // @54_442ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @55_442ad0
  ecx = (u32)(EBP - 188);  // @56_442ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @57_442ad0
  ecx = edx = 0;  // @58_442ad0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 296), sizeof v); (u32)v; }) != (u32)(0)) goto L442b90;  // @59_442ad0
  L442bd7:;
  ecx = (u32)(EBP - 188);  // @61_442ad0
  eax = ext_4ccf60_thiscall1(ecx);  // @62_442ad0
  ecx = edx = 0;  // @63_442ad0
  L442be2:;
  SEH_LEAVE();  // @65_442ad0
  ext_633654(G(u32, 0x6f5630));  // @66_442ad0
  return eax;  // @67_442ad0
}
PCREG(442ad0, lifted_442ad0);

extern "C" u32 THISCALL lifted_4c90a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_4c90a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  ebx = ecx;  // @0_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4c90a0
  ecx = (u32)(EBP - 144);  // @2_4c90a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @3_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; }));  // @4_4c90a0
  ecx = edx = 0;  // @5_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4c90a0
  reg.state = (s32)((u32)(0));  // @7_4c90a0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @8_4c90a0
  if ((eax & 0xff) == (u32)(255)) goto L4c9131;  // @9_4c90a0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(63))) & 0xff);  // @10_4c90a0
  if ((eax & 0xff) != (u32)(4)) goto L4c9131;  // @11_4c90a0
  ecx = esi;  // @12_4c90a0
  eax = ext_4e5ea0_thiscall1(ecx);  // @13_4c90a0
  ecx = edx = 0;  // @14_4c90a0
  PS[0] = eax;  // @15_4c90a0
  ecx = (u32)(EBP - 272);  // @16_4c90a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @17_4c90a0
  ecx = edx = 0;  // @18_4c90a0
  eax = (u32)(EBP - 272);  // @19_4c90a0
  reg.state = (s32)((u32)(1));  // @20_4c90a0
  PS[0] = eax;  // @21_4c90a0
  ecx = (u32)(EBP - 144);  // @22_4c90a0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @23_4c90a0
  ecx = edx = 0;  // @24_4c90a0
  ecx = (u32)(EBP - 272);  // @25_4c90a0
  reg.state = (s32)((u32)(0));  // @26_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @27_4c90a0
  ecx = edx = 0;  // @28_4c90a0
  L4c9131:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @30_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @31_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @32_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @33_4c90a0
  ecx = edx = 0;  // @34_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @35_4c90a0
  esi = eax;  // @36_4c90a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @37_4c90a0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @38_4c90a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @39_4c90a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 76)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; }), (u32)(2));  // @40_4c90a0
  ecx = edx = 0;  // @41_4c90a0
  PS[0] = eax;  // @42_4c90a0
  ecx = (u32)(EBP - 144);  // @43_4c90a0
  eax = ext_4cc1d0_cdecl1((u32)(PS[0]));  // @44_4c90a0
  ecx = edx = 0;  // @45_4c90a0
  PS[0] = eax;  // @46_4c90a0
  ecx = esi;  // @47_4c90a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edi + 96)))(ecx, (u32)(PS[0]));  // @48_4c90a0
  ecx = edx = 0;  // @49_4c90a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @50_4c90a0
  ecx = ebx;  // @51_4c90a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @52_4c90a0
  ecx = edx = 0;  // @53_4c90a0
  ecx = (u32)(EBP - 144);  // @54_4c90a0
  eax = ext_4cbec0_thiscall1(ecx);  // @55_4c90a0
  ecx = edx = 0;  // @56_4c90a0
  SEH_LEAVE();  // @57_4c90a0
  ext_633654(G(u32, 0x6f5630));  // @58_4c90a0
  return eax;  // @59_4c90a0
}
PCREG(4c90a0, lifted_4c90a0);

extern "C" u32 THISCALL lifted_4d1530(u32 ecx_in) {
  SEH_ENTER(0x6656a0);  // @h_4d1530
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });  // @1_4d1530
  { u32 v = (u32)((u32)(6905720)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_4d1530
  if ((eax & eax) == 0) goto L4d1574;  // @3_4d1530
  PS[1] = eax;  // @4_4d1530
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(4));  // @5_4d1530
  ecx = edx = 0;  // @6_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @7_4d1530
  L4d1574:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; });  // @9_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @10_4d1530
  if ((eax & eax) == 0) goto L4d158d;  // @11_4d1530
  PS[1] = eax;  // @12_4d1530
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(4));  // @13_4d1530
  ecx = edx = 0;  // @14_4d1530
  L4d158d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) == (u32)(0)) goto L4d15a7;  // @16_4d1530
  L4d1593:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; });  // @18_4d1530
  if ((ecx & ecx) == 0) goto L4d15a1;  // @19_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_4d1530
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 20)))(ecx, (u32)(1));  // @21_4d1530
  ecx = edx = 0;  // @22_4d1530
  L4d15a1:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 36), sizeof v); (u32)v; }) != (u32)(0)) goto L4d1593;  // @24_4d1530
  L4d15a7:;
  ecx = esi;  // @26_4d1530
  eax = ext_4d2030_thiscall2(ecx, (u32)(-1));  // @27_4d1530
  ecx = edx = 0;  // @28_4d1530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @29_4d1530
  if ((ecx & ecx) == 0) goto L4d15ec;  // @30_4d1530
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @31_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @32_4d1530
  if ((edx & edx) == 0) goto L4d15c6;  // @33_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 48), &v, sizeof v); }  // @34_4d1530
  goto L4d15c9;  // @35_4d1530
  L4d15c6:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 36), &v, sizeof v); }  // @37_4d1530
  L4d15c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 48), sizeof v); (u32)v; });  // @39_4d1530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 52), sizeof v); (u32)v; });  // @40_4d1530
  if ((ecx & ecx) == 0) goto L4d15d8;  // @41_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 52), &v, sizeof v); }  // @42_4d1530
  goto L4d15de;  // @43_4d1530
  L4d15d8:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 44), sizeof v); (u32)v; });  // @45_4d1530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 40), &v, sizeof v); }  // @46_4d1530
  L4d15de:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @48_4d1530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 52), &v, sizeof v); }  // @49_4d1530
  L4d15ec:;
  SEH_LEAVE();  // @51_4d1530
  return eax;  // @52_4d1530
}
PCREG(4d1530, lifted_4d1530);

extern "C" u32 THISCALL lifted_4385e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66606f);  // @h_4385e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_4385e0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 62), sizeof v); (u32)v; }) != (u32)(0)) goto L43863e;  // @1_4385e0
  eax = ext_41e290_cdecl1((u32)(28));  // @2_4385e0
  ecx = edx = 0;  // @3_4385e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_4385e0
  reg.state = (s32)((u32)(0));  // @5_4385e0
  if ((eax & eax) == 0) goto L438632;  // @6_4385e0
  ecx = eax;  // @7_4385e0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(2), (u32)(2));  // @8_4385e0
  ecx = edx = 0;  // @9_4385e0
  goto L438634;  // @10_4385e0
  L438632:;
  eax = 0;  // @12_4385e0
  L438634:;
  reg.state = (s32)((u32)(4294967295));  // @14_4385e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 62), &v, sizeof v); }  // @15_4385e0
  L43863e:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 62), sizeof v); (u32)v; });  // @17_4385e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @18_4385e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @19_4385e0
  ecx = edx = 0;  // @20_4385e0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_4385e0
  edi = eax;  // @22_4385e0
  ecx = esi;  // @23_4385e0
  edx = (u32)(ecx + 1);  // @24_4385e0
  L438652:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @26_4385e0
  ecx = (ecx + 1);  // @27_4385e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L438652;  // @28_4385e0
  ecx = (ecx - edx);  // @29_4385e0
  eax = (u32)(ecx + 1);  // @30_4385e0
  PS[0] = eax;  // @31_4385e0
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @32_4385e0
  ecx = edx = 0;  // @33_4385e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi - 4), &v, sizeof v); }  // @34_4385e0
  L438670:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; })) & 0xff);  // @36_4385e0
  esi = (u32)(esi + 1);  // @37_4385e0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @38_4385e0
  eax = (u32)(eax + 1);  // @39_4385e0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L438670;  // @40_4385e0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; })) & 0xff);  // @41_4385e0
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @42_4385e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @43_4385e0
  SEH_LEAVE();  // @44_4385e0
  return eax;  // @45_4385e0
}
PCREG(4385e0, lifted_4385e0);

