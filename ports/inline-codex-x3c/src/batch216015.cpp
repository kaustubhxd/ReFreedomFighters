// batch216015.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_43e0f0_thiscall1(u32) __asm__("ext_43e0f0");
extern "C" u32 THISCALL ext_440e10_thiscall2(u32, u32) __asm__("ext_440e10");
extern "C" u32 THISCALL ext_456ab0_thiscall1(u32) __asm__("ext_456ab0");
extern "C" u32 THISCALL ext_4c4740_thiscall4(u32, u32, u32, u32) __asm__("ext_4c4740");
extern "C" u32 THISCALL ext_4cbe50_thiscall2(u32, u32) __asm__("ext_4cbe50");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4cc5f0_thiscall1(u32) __asm__("ext_4cc5f0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_4ff9d0_thiscall1(u32) __asm__("ext_4ff9d0");
extern "C" u32 THISCALL ext_59a9b0_thiscall2(u32, u32) __asm__("ext_59a9b0");
extern "C" u32 THISCALL ext_5f9700_thiscall3(u32, u32, u32) __asm__("ext_5f9700");
extern "C" u32 THISCALL ext_603430_thiscall3(u32, u32, u32) __asm__("ext_603430");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4558a0(u32 ecx_in) {
  SEH_ENTER(0x66bdd6);  // @h_4558a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  ebx = ecx;  // @0_4558a0
  eax = ext_43e0f0_thiscall1(ecx);  // @1_4558a0
  ecx = edx = 0;  // @2_4558a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) != (u32)(0)) goto L455981;  // @3_4558a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; });  // @4_4558a0
  if ((eax & eax) == 0) goto L455981;  // @5_4558a0
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; }) == (u32)(0)) goto L455981;  // @6_4558a0
  PS[0] = eax;  // @7_4558a0
  ecx = (u32)(EBP - 144);  // @8_4558a0
  eax = ext_4cbe80_thiscall2(ecx, (u32)(PS[0]));  // @9_4558a0
  ecx = edx = 0;  // @10_4558a0
  ecx = (u32)(EBP - 144);  // @11_4558a0
  reg.state = (s32)((u32)(0));  // @12_4558a0
  eax = ext_456ab0_thiscall1(ecx);  // @13_4558a0
  ecx = edx = 0;  // @14_4558a0
  ecx = (u32)(EBP - 144);  // @15_4558a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 73), &v, sizeof v); }  // @16_4558a0
  reg.state = (s32)((u32)(4294967295));  // @17_4558a0
  eax = ext_4cbec0_thiscall1(ecx);  // @18_4558a0
  ecx = edx = 0;  // @19_4558a0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 73), sizeof v); (u32)v; }) != (u32)(0)) goto L455981;  // @20_4558a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @21_4558a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_4558a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6827288), (u32)(322));  // @23_4558a0
  ecx = edx = 0;  // @24_4558a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @25_4558a0
  edi = eax;  // @26_4558a0
  eax = (u32)(EBP - 272);  // @27_4558a0
  ecx = ebx;  // @28_4558a0
  PS[1] = eax;  // @29_4558a0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @30_4558a0
  ecx = edx = 0;  // @31_4558a0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @32_4558a0
  ecx = eax;  // @33_4558a0
  reg.state = (s32)((u32)(1));  // @34_4558a0
  eax = ext_4cc1d0_thiscall1(ecx);  // @35_4558a0
  ecx = edx = 0;  // @36_4558a0
  PS[0] = eax;  // @37_4558a0
  PS[3] = edi;  // @38_4558a0
  eax = ((u32( *)(u32, u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[3]), (u32)(6827488), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 77), sizeof v); (u32)v; }), (u32)(PS[0]));  // @39_4558a0
  ecx = edx = 0;  // @40_4558a0
  ecx = (u32)(EBP - 272);  // @41_4558a0
  eax = ext_4cbec0_thiscall1(ecx);  // @42_4558a0
  ecx = edx = 0;  // @43_4558a0
  L455981:;
  SEH_LEAVE();  // @45_4558a0
  ext_633654(G(u32, 0x6f5630));  // @46_4558a0
  return eax;  // @47_4558a0
}
PCREG(4558a0, lifted_4558a0);

extern "C" u32 FASTCALL lifted_560440(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x66afdf);  // @h_560440
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0, PS[16];
  edi = edx;  // @0_560440
  ebx = ecx;  // @1_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7422364), &v, sizeof v); }  // @2_560440
  eax = ext_41e290_cdecl1((u32)(12));  // @3_560440
  ecx = edx = 0;  // @4_560440
  esi = eax;  // @5_560440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_560440
  reg.state = (s32)((u32)(0));  // @7_560440
  if ((esi & esi) == 0) goto L5604a1;  // @8_560440
  PS[0] = edi;  // @9_560440
  PS[1] = ebx;  // @10_560440
  ecx = esi;  // @11_560440
  eax = ext_5f9700_thiscall3(ecx, (u32)(PS[1]), (u32)(PS[0]));  // @12_560440
  ecx = edx = 0;  // @13_560440
  { u32 v = (u32)((u32)(6971852)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_560440
  goto L5604a3;  // @15_560440
  L5604a1:;
  esi = 0;  // @17_560440
  L5604a3:;
  reg.state = (s32)((u32)(4294967295));  // @19_560440
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(7422364), &v, sizeof v); }  // @20_560440
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422360), sizeof v); (u32)v; }) != (u32)(0)) goto L560514;  // @21_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 32), &v, sizeof v); }  // @22_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @23_560440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @24_560440
  ecx = (u32)(EBP - 32);  // @25_560440
  reg.state = (s32)((u32)(1));  // @26_560440
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @27_560440
  eax = ext_59a9b0_thiscall2(ecx, (u32)(50));  // @28_560440
  ecx = edx = 0;  // @29_560440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @30_560440
  ecx = (u32)(EBP - 32);  // @31_560440
  PS[0] = ecx;  // @32_560440
  ecx = esi;  // @33_560440
  reg.state = (s32)((u32)(2));  // @34_560440
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 28)))(ecx, (u32)(PS[0]));  // @35_560440
  ecx = edx = 0;  // @36_560440
  ecx = (u32)(EBP - 32);  // @37_560440
  eax = ext_4ff9d0_thiscall1(ecx);  // @38_560440
  ecx = edx = 0;  // @39_560440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7422364), sizeof v); (u32)v; });  // @40_560440
  SEH_LEAVE();  // @41_560440
  return eax;  // @42_560440
  L560514:;
  eax = esi;  // @44_560440
  SEH_LEAVE();  // @45_560440
  return eax;  // @46_560440
}
PCREG(560440, lifted_560440);

extern "C" u32 THISCALL lifted_4c90a0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66a8c6);  // @h_4c90a0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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

extern "C" u32 THISCALL lifted_42c380(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664d7c);  // @h_42c380
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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

extern "C" u32 THISCALL lifted_4c4630(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66976b);  // @h_4c4630
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_4c4630
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_4c4630
  eax = (u32)(edi + 130);  // @2_4c4630
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(edi + 4), &v, sizeof v); }  // @3_4c4630
  ecx = esi;  // @4_4c4630
  PS[0] = eax;  // @5_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @6_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @7_4c4630
  ecx = edx = 0;  // @8_4c4630
  ecx = (u32)(edi + 134);  // @9_4c4630
  PS[0] = ecx;  // @10_4c4630
  ecx = eax;  // @11_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @12_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @13_4c4630
  ecx = edx = 0;  // @14_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_4c4630
  eax = (u32)(edi + 138);  // @16_4c4630
  PS[0] = eax;  // @17_4c4630
  ecx = esi;  // @18_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @19_4c4630
  ecx = edx = 0;  // @20_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_4c4630
  eax = (u32)(edi + 142);  // @22_4c4630
  PS[0] = eax;  // @23_4c4630
  ecx = esi;  // @24_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(PS[0]));  // @25_4c4630
  ecx = edx = 0;  // @26_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_4c4630
  eax = (u32)(edi + 146);  // @28_4c4630
  PS[0] = eax;  // @29_4c4630
  ecx = esi;  // @30_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(PS[0]));  // @31_4c4630
  ecx = edx = 0;  // @32_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_4c4630
  eax = (u32)(edi + 150);  // @34_4c4630
  PS[0] = eax;  // @35_4c4630
  ecx = esi;  // @36_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 108)))(ecx, (u32)(PS[0]));  // @37_4c4630
  ecx = edx = 0;  // @38_4c4630
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @39_4c4630
  eax = (u32)(edi + 162);  // @40_4c4630
  PS[0] = eax;  // @41_4c4630
  ecx = esi;  // @42_4c4630
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(PS[0]));  // @43_4c4630
  ecx = edx = 0;  // @44_4c4630
  ecx = (u32)(EBP - 144);  // @45_4c4630
  eax = ext_4cbeb0_thiscall1(ecx);  // @46_4c4630
  ecx = edx = 0;  // @47_4c4630
  eax = (u32)(EBP - 148);  // @48_4c4630
  reg.state = (s32)((u32)(0));  // @49_4c4630
  PS[0] = eax;  // @50_4c4630
  ecx = edi;  // @51_4c4630
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @52_4c4630
  eax = ext_6352f0_thiscall2(ecx, (u32)(PS[0]));  // @53_4c4630
  ecx = edx = 0;  // @54_4c4630
  eax = (u32)(EBP - 144);  // @55_4c4630
  ecx = edi;  // @56_4c4630
  PS[0] = eax;  // @57_4c4630
  eax = (u32)(EBP - 152);  // @58_4c4630
  PS[1] = eax;  // @59_4c4630
  eax = (u32)(EBP - 148);  // @60_4c4630
  PS[2] = eax;  // @61_4c4630
  eax = ext_4c4740_thiscall4(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(PS[0]));  // @62_4c4630
  ecx = edx = 0;  // @63_4c4630
  ecx = (u32)(EBP - 144);  // @64_4c4630
  eax = ext_4cbec0_thiscall1(ecx);  // @65_4c4630
  ecx = edx = 0;  // @66_4c4630
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @67_4c4630
  SEH_LEAVE();  // @68_4c4630
  ext_633654(G(u32, 0x6f5630));  // @69_4c4630
  return eax;  // @70_4c4630
}
PCREG(4c4630, lifted_4c4630);

extern "C" u32 THISCALL lifted_444eb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66606f);  // @h_444eb0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_444eb0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_444eb0
  PS[0] = esi;  // @2_444eb0
  eax = ext_440e10_thiscall2(ecx, (u32)(PS[0]));  // @3_444eb0
  ecx = edx = 0;  // @4_444eb0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L444ef7;  // @5_444eb0
  SEH_LEAVE();  // @6_444eb0
  return eax;  // @7_444eb0
  L444ef7:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_444eb0
  eax = (u32)(edi + 148);  // @10_444eb0
  PS[0] = eax;  // @11_444eb0
  ecx = esi;  // @12_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @13_444eb0
  ecx = edx = 0;  // @14_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @15_444eb0
  eax = (u32)(edi + 152);  // @16_444eb0
  PS[0] = eax;  // @17_444eb0
  ecx = esi;  // @18_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @19_444eb0
  ecx = edx = 0;  // @20_444eb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_444eb0
  eax = (u32)(edi + 192);  // @22_444eb0
  PS[0] = eax;  // @23_444eb0
  ecx = esi;  // @24_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @25_444eb0
  ecx = edx = 0;  // @26_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @27_444eb0
  ecx = (u32)(EBP + 8);  // @28_444eb0
  PS[0] = ecx;  // @29_444eb0
  ecx = esi;  // @30_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @31_444eb0
  ecx = edx = 0;  // @32_444eb0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L444f70;  // @33_444eb0
  eax = ext_41e290_cdecl1((u32)(28));  // @34_444eb0
  ecx = edx = 0;  // @35_444eb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @36_444eb0
  reg.state = (s32)((u32)(0));  // @37_444eb0
  if ((eax & eax) == 0) goto L444f59;  // @38_444eb0
  ecx = eax;  // @39_444eb0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @40_444eb0
  ecx = edx = 0;  // @41_444eb0
  ecx = eax;  // @42_444eb0
  goto L444f5b;  // @43_444eb0
  L444f59:;
  ecx = 0;  // @45_444eb0
  L444f5b:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edi + 164), &v, sizeof v); }  // @47_444eb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @48_444eb0
  PS[0] = ecx;  // @49_444eb0
  ecx = esi;  // @50_444eb0
  reg.state = (s32)((u32)(4294967295));  // @51_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, (u32)(PS[0]));  // @52_444eb0
  ecx = edx = 0;  // @53_444eb0
  L444f70:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @55_444eb0
  eax = (u32)(edi + 172);  // @56_444eb0
  PS[0] = eax;  // @57_444eb0
  ecx = esi;  // @58_444eb0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 64)))(ecx, (u32)(PS[0]));  // @59_444eb0
  ecx = edx = 0;  // @60_444eb0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @61_444eb0
  SEH_LEAVE();  // @62_444eb0
  return eax;  // @63_444eb0
}
PCREG(444eb0, lifted_444eb0);

extern "C" u32 THISCALL lifted_6041e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66dd06);  // @h_6041e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;  // @0_6041e0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_6041e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_6041e0
  PS[1] = edi;  // @3_6041e0
  eax = ext_603430_thiscall3(ecx, (u32)(PS[1]), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @4_6041e0
  ecx = edx = 0;  // @5_6041e0
  { u32 v = (u32)((u32)(7051188)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_6041e0
  eax = (u32)(esi + 12);  // @7_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @8_6041e0
  ecx = (u32)(EBP - 28);  // @9_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @10_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @11_6041e0
  reg.state = (s32)((u32)(0));  // @12_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 38), &v, sizeof v); }  // @13_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @14_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @15_6041e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @16_6041e0
  eax = ext_6014a0_stdcall1((u32)(8));  // @17_6041e0
  ecx = edx = 0;  // @18_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 28), &v, sizeof v); }  // @19_6041e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 24), &v, sizeof v); }  // @20_6041e0
  ecx = (u32)(eax + 8);  // @21_6041e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @22_6041e0
  if ((eax & eax) == 0) goto L604272;  // @23_6041e0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @24_6041e0
  L604272:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @26_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @27_6041e0
  ecx = (u32)(EBP - 28);  // @28_6041e0
  PS[0] = ecx;  // @29_6041e0
  ecx = edi;  // @30_6041e0
  reg.state = (s32)((u32)(1));  // @31_6041e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 108)))(ecx, (u32)(PS[0]));  // @32_6041e0
  ecx = edx = 0;  // @33_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; });  // @34_6041e0
  eax = (eax - ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @35_6041e0
  if (eax <= (u32)(32)) goto L60429d;  // @36_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });  // @37_6041e0
  if ((eax & eax) == 0) goto L60429c;  // @38_6041e0
  eax = ((u32(STDCALL *)(void))(eax))();  // @39_6041e0
  ecx = edx = 0;  // @40_6041e0
  goto L60429d;  // @41_6041e0
  L60429c:;
  __builtin_trap();  // @43_6041e0
  L60429d:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7488120), sizeof v); (u32)v; });  // @45_6041e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @46_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @47_6041e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; }));  // @48_6041e0
  ecx = edx = 0;  // @49_6041e0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @50_6041e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 20), sizeof v); (u32)v; });  // @51_6041e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 28), sizeof v); (u32)v; });  // @52_6041e0
  eax = (eax - ecx);  // @53_6041e0
  reg.state = (s32)((u32)(2));  // @54_6041e0
  if ((ecx & ecx) == 0) goto L6042ce;  // @55_6041e0
  if ((eax & eax) == 0) goto L6042ce;  // @56_6041e0
  PS[0] = eax;  // @57_6041e0
  PS[1] = ecx;  // @58_6041e0
  ecx = (u32)(EBP - 28);  // @59_6041e0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @60_6041e0
  ecx = edx = 0;  // @61_6041e0
  L6042ce:;
  eax = esi;  // @63_6041e0
  SEH_LEAVE();  // @64_6041e0
  return eax;  // @65_6041e0
}
PCREG(6041e0, lifted_6041e0);

extern "C" u32 THISCALL lifted_4affa0(u32 ecx_in) {
  SEH_ENTER(0x66976b);  // @h_4affa0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  ebx = ecx;  // @0_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @1_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 256)))(ecx, (u32)(6886756));  // @3_4affa0
  ecx = edx = 0;  // @4_4affa0
  ecx = eax;  // @5_4affa0
  if ((ecx & ecx) != 0) goto L4b0049;  // @6_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340944), sizeof v); (u32)v; });  // @7_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 32)))(ecx, (u32)(6889180), (u32)(2434));  // @9_4affa0
  ecx = edx = 0;  // @10_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 68), sizeof v); (u32)v; });  // @11_4affa0
  edi = eax;  // @12_4affa0
  eax = (u32)(EBP - 144);  // @13_4affa0
  PS[1] = eax;  // @14_4affa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @15_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 472)))(ecx, (u32)(PS[1]), (u32)(1));  // @16_4affa0
  ecx = edx = 0;  // @17_4affa0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_4affa0
  ecx = eax;  // @19_4affa0
  reg.state = (s32)((u32)(0));  // @20_4affa0
  eax = ext_4cc1d0_thiscall1(ecx);  // @21_4affa0
  ecx = edx = 0;  // @22_4affa0
  PS[0] = eax;  // @23_4affa0
  PS[2] = edi;  // @24_4affa0
  eax = ((u32( *)(u32, u32, u32))(*(u32 *)(esi + 44)))((u32)(PS[2]), (u32)(6890800), (u32)(PS[0]));  // @25_4affa0
  ecx = edx = 0;  // @26_4affa0
  reg.state = (s32)((u32)(4294967295));  // @27_4affa0
  ecx = (u32)(EBP - 144);  // @28_4affa0
  eax = ext_4cbec0_thiscall1(ecx);  // @29_4affa0
  ecx = edx = 0;  // @30_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @31_4affa0
  ecx = ebx;  // @32_4affa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 88)))(ecx);  // @33_4affa0
  ecx = edx = 0;  // @34_4affa0
  goto L4b00a4;  // @35_4affa0
  L4b0049:;
  if ((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 72), sizeof v); (u32)v; }) < (s32)(u32)(0)) goto L4b0058;  // @37_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @38_4affa0
  PS[0] = ebx;  // @39_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 132)))(ecx, (u32)(PS[0]));  // @40_4affa0
  ecx = edx = 0;  // @41_4affa0
  L4b0058:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @43_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @44_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @45_4affa0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @46_4affa0
  ecx = edx = 0;  // @47_4affa0
  ecx = (u32)(EBP - 148);  // @48_4affa0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 148), &v, sizeof v); }  // @49_4affa0
  PS[0] = ecx;  // @50_4affa0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @51_4affa0
  ecx = eax;  // @52_4affa0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6889580), (u32)(PS[0]));  // @53_4affa0
  ecx = edx = 0;  // @54_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @55_4affa0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @56_4affa0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_4affa0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 148), sizeof v); (u32)v; }));  // @58_4affa0
  ecx = edx = 0;  // @59_4affa0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 76), &v, sizeof v); }  // @60_4affa0
  L4b00a4:;
  SEH_LEAVE();  // @62_4affa0
  ext_633654(G(u32, 0x6f5630));  // @63_4affa0
  return eax;  // @64_4affa0
}
PCREG(4affa0, lifted_4affa0);

