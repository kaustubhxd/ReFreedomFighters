// batch226030.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_492200_stdcall1(u32) __asm__("ext_492200");
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_610100_stdcall1(u32) __asm__("ext_610100");
extern "C" u32 THISCALL ext_469870_thiscall1(u32) __asm__("ext_469870");
extern "C" u32 THISCALL ext_492880_thiscall2(u32, u32) __asm__("ext_492880");
extern "C" u32 THISCALL ext_499880_thiscall3(u32, u32, u32) __asm__("ext_499880");
extern "C" u32 THISCALL ext_499970_thiscall1(u32) __asm__("ext_499970");
extern "C" u32 THISCALL ext_49a790_thiscall3(u32, u32, u32) __asm__("ext_49a790");
extern "C" u32 THISCALL ext_49b2e0_thiscall2(u32, u32) __asm__("ext_49b2e0");
extern "C" u32 THISCALL ext_49b340_thiscall3(u32, u32, u32) __asm__("ext_49b340");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccdd0_thiscall4(u32, u32, u32, u32) __asm__("ext_4ccdd0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4e0fd0_thiscall2(u32, u32) __asm__("ext_4e0fd0");
extern "C" u32 THISCALL ext_4e1b30_thiscall1(u32) __asm__("ext_4e1b30");
extern "C" u32 THISCALL ext_5fae50_thiscall1(u32) __asm__("ext_5fae50");
extern "C" u32 THISCALL ext_5fb370_thiscall2(u32, u32) __asm__("ext_5fb370");
extern "C" u32 THISCALL ext_5fdb70_thiscall1(u32) __asm__("ext_5fdb70");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_492250(u32 ecx_in) {
  SEH_ENTER(0x667d5b);  // @h_492250
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @1_492250
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }) == (u32)(0)) goto L4923b9;  // @2_492250
  eax = (u32)(EBP - 30016);  // @3_492250
  PS[1] = eax;  // @4_492250
  ecx = (u32)(EBP - 30332);  // @5_492250
  eax = ext_499880_thiscall3(ecx, (u32)(PS[1]), (u32)(30000));  // @6_492250
  ecx = edx = 0;  // @7_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_492250
  ecx = (u32)(EBP - 30332);  // @9_492250
  reg.state = (s32)((u32)(0));  // @10_492250
  eax = ext_49a790_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6827), sizeof v); (u32)v; }), (u32)(2));  // @11_492250
  ecx = edx = 0;  // @12_492250
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L4922da;  // @13_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 2994), &v, sizeof v); }  // @14_492250
  goto L4923ae;  // @15_492250
  L4922da:;
  ecx = (u32)(EBP - 30332);  // @17_492250
  eax = ext_49b340_thiscall3(ecx, (u32)(1), (u32)(4));  // @18_492250
  ecx = edx = 0;  // @19_492250
  ecx = (u32)(EBP - 30332);  // @20_492250
  eax = ext_49b2e0_thiscall2(ecx, (u32)(1));  // @21_492250
  ecx = edx = 0;  // @22_492250
  eax = (u32)(esi + 2992);  // @23_492250
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 3008), &v, sizeof v); }  // @24_492250
  PS[0] = eax;  // @25_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @26_492250
  ecx = (u32)(EBP - 30332);  // @27_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(PS[0]));  // @28_492250
  ecx = edx = 0;  // @29_492250
  eax = (u32)(esi + 2993);  // @30_492250
  PS[0] = eax;  // @31_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @32_492250
  ecx = (u32)(EBP - 30332);  // @33_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(PS[0]));  // @34_492250
  ecx = edx = 0;  // @35_492250
  eax = (u32)(esi + 2995);  // @36_492250
  PS[0] = eax;  // @37_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @38_492250
  ecx = (u32)(EBP - 30332);  // @39_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, (u32)(PS[0]));  // @40_492250
  ecx = edx = 0;  // @41_492250
  eax = (u32)(esi + 23873);  // @42_492250
  PS[0] = eax;  // @43_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @44_492250
  ecx = (u32)(EBP - 30332);  // @45_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(PS[0]));  // @46_492250
  ecx = edx = 0;  // @47_492250
  eax = (u32)(esi + 2988);  // @48_492250
  PS[0] = eax;  // @49_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 30332), sizeof v); (u32)v; });  // @50_492250
  ecx = (u32)(EBP - 30332);  // @51_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 104)))(ecx, (u32)(PS[0]));  // @52_492250
  ecx = edx = 0;  // @53_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @54_492250
  edx = (u32)(EBP - 30332);  // @55_492250
  PS[0] = edx;  // @56_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @57_492250
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @58_492250
  ecx = edx = 0;  // @59_492250
  eax = (u32)(EBP - 30332);  // @60_492250
  ecx = esi;  // @61_492250
  PS[0] = eax;  // @62_492250
  eax = ext_492200_stdcall1((u32)(PS[0]));  // @63_492250
  ecx = edx = 0;  // @64_492250
  eax = (u32)(EBP - 30332);  // @65_492250
  ecx = esi;  // @66_492250
  PS[0] = eax;  // @67_492250
  eax = ext_492880_thiscall2(ecx, (u32)(PS[0]));  // @68_492250
  ecx = edx = 0;  // @69_492250
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @70_492250
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @71_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 188)))(ecx);  // @72_492250
  ecx = edx = 0;  // @73_492250
  ecx = eax;  // @74_492250
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @75_492250
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(edx + 112)))(ecx);  // @76_492250
  ecx = edx = 0;  // @77_492250
  L4923ae:;
  ecx = (u32)(EBP - 30332);  // @79_492250
  eax = ext_499970_thiscall1(ecx);  // @80_492250
  ecx = edx = 0;  // @81_492250
  L4923b9:;
  SEH_LEAVE();  // @83_492250
  ext_633654(G(u32, 0x6f5630));  // @84_492250
  return eax;  // @85_492250
}
PCREG(492250, lifted_492250);

extern "C" u32 THISCALL lifted_5fb660(u32 ecx_in) {
  SEH_ENTER(0x66d496);  // @h_5fb660
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  edi = ecx;  // @0_5fb660
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @1_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; });  // @2_5fb660
  ebx = (u32)(edi + 1);  // @3_5fb660
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 5), sizeof v); (u32)v; });  // @4_5fb660
  if (esi == eax) goto L5fb72e;  // @5_5fb660
  L5fb6a0:;
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 25), sizeof v); (u32)v; });  // @7_5fb660
  if ((edi & edi) == 0) goto L5fb6ee;  // @8_5fb660
  ecx = (u32)(edi + 370);  // @9_5fb660
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @11_5fb660
  eax = (eax - edx);  // @12_5fb660
  reg.state = (s32)((u32)(0));  // @13_5fb660
  if ((edx & edx) == 0) goto L5fb6ca;  // @14_5fb660
  if ((eax & eax) == 0) goto L5fb6ca;  // @15_5fb660
  PS[0] = eax;  // @16_5fb660
  PS[1] = edx;  // @17_5fb660
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @18_5fb660
  ecx = edx = 0;  // @19_5fb660
  L5fb6ca:;
  ecx = (u32)(edi + 60);  // @21_5fb660
  reg.state = (s32)((u32)(4294967295));  // @22_5fb660
  eax = ext_5fdb70_thiscall1(ecx);  // @23_5fb660
  ecx = edx = 0;  // @24_5fb660
  ecx = edi;  // @25_5fb660
  eax = ext_5fae50_thiscall1(ecx);  // @26_5fb660
  ecx = edx = 0;  // @27_5fb660
  PS[1] = edi;  // @28_5fb660
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(382));  // @29_5fb660
  ecx = edx = 0;  // @30_5fb660
  L5fb6ee:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; });  // @32_5fb660
  if ((eax & eax) == 0) goto L5fb70b;  // @33_5fb660
  esi = eax;  // @34_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @35_5fb660
  if ((eax & eax) == 0) goto L5fb723;  // @36_5fb660
  L5fb700:;
  esi = eax;  // @38_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @39_5fb660
  if ((eax & eax) != 0) goto L5fb700;  // @40_5fb660
  goto L5fb723;  // @41_5fb660
  L5fb70b:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 1), sizeof v); (u32)v; });  // @43_5fb660
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L5fb71d;  // @44_5fb660
  L5fb713:;
  esi = eax;  // @46_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; });  // @47_5fb660
  if (esi == ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 9), sizeof v); (u32)v; })) goto L5fb713;  // @48_5fb660
  L5fb71d:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }) != eax) esi = eax;  // @50_5fb660
  L5fb723:;
  if (esi != ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; })) goto L5fb6a0;  // @52_5fb660
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @53_5fb660
  L5fb72e:;
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) == (u32)(0)) goto L5fb75a;  // @55_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_5fb660
  ecx = ebx;  // @57_5fb660
  eax = ext_5fb370_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; }));  // @58_5fb660
  ecx = edx = 0;  // @59_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @60_5fb660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 5), &v, sizeof v); }  // @61_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @62_5fb660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 1), &v, sizeof v); }  // @63_5fb660
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @64_5fb660
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(eax + 9), &v, sizeof v); }  // @65_5fb660
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @66_5fb660
  L5fb75a:;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @68_5fb660
  SEH_LEAVE();  // @69_5fb660
  return eax;  // @70_5fb660
}
PCREG(5fb660, lifted_5fb660);

extern "C" u32 THISCALL lifted_497750(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66818f);  // @h_497750
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @1_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @2_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, (u32)(2138367));  // @3_497750
  ecx = edx = 0;  // @4_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_497750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; }) != (u32)(0)) goto L497797;  // @6_497750
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; }) == (u32)(0)) goto L4977e0;  // @7_497750
  L497797:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @9_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_497750
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 220)))(ecx);  // @11_497750
  ecx = edx = 0;  // @12_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @13_497750
  if ((eax & eax) == 0) goto L4977be;  // @14_497750
  PS[1] = eax;  // @15_497750
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @16_497750
  ecx = edx = 0;  // @17_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @18_497750
  L4977be:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 44), sizeof v); (u32)v; });  // @20_497750
  if ((ecx & ecx) == 0) goto L4977d2;  // @21_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @22_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @23_497750
  ecx = edx = 0;  // @24_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @25_497750
  L4977d2:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @27_497750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 56), &v, sizeof v); }  // @28_497750
  L4977e0:;
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_497750
  PS[0] = ebx;  // @31_497750
  { u32 v = (u32)(ebx); __builtin_memcpy((void *)(u32)(edi + 52), &v, sizeof v); }  // @32_497750
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @33_497750
  ecx = edx = 0;  // @34_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 48), &v, sizeof v); }  // @35_497750
  eax = ext_41e290_cdecl1((u32)(16));  // @36_497750
  ecx = edx = 0;  // @37_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @38_497750
  reg.state = (s32)((u32)(0));  // @39_497750
  if ((eax & eax) == 0) goto L49781a;  // @40_497750
  ecx = eax;  // @41_497750
  eax = ext_4ccdd0_thiscall4(ecx, (u32)(0), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; }), (u32)(512));  // @42_497750
  ecx = edx = 0;  // @43_497750
  goto L49781c;  // @44_497750
  L49781a:;
  eax = 0;  // @46_497750
  L49781c:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 48), sizeof v); (u32)v; });  // @48_497750
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 44), &v, sizeof v); }  // @49_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @50_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 52), sizeof v); (u32)v; });  // @51_497750
  eax = (eax + edx);  // @52_497750
  reg.state = (s32)((u32)(4294967295));  // @53_497750
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_497750
  PS[1] = eax;  // @55_497750
  PS[2] = edx;  // @56_497750
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(esi + 216)))(ecx, (u32)(PS[2]), (u32)(PS[1]), (u32)(4809904));  // @57_497750
  ecx = edx = 0;  // @58_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @59_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @60_497750
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 72)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));  // @61_497750
  ecx = edx = 0;  // @62_497750
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @63_497750
  if ((ecx & ecx) == 0) goto L497866;  // @64_497750
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @65_497750
  PS[0] = ebx;  // @66_497750
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 36)))(ecx, (u32)(6874404), (u32)(PS[0]));  // @67_497750
  ecx = edx = 0;  // @68_497750
  L497866:;
  SEH_LEAVE();  // @70_497750
  return eax;  // @71_497750
}
PCREG(497750, lifted_497750);

extern "C" u32 THISCALL lifted_44a200(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6660dd);  // @h_44a200
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_44a200
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_44a200
  PS[0] = ebx;  // @2_44a200
  eax = ext_610100_stdcall1((u32)(PS[0]));  // @3_44a200
  ecx = edx = 0;  // @4_44a200
  ecx = (u32)(EBP - 188);  // @5_44a200
  eax = ext_4ccba0_thiscall1(ecx);  // @6_44a200
  ecx = edx = 0;  // @7_44a200
  eax = (u32)(EBP - 188);  // @8_44a200
  reg.state = (s32)((u32)(0));  // @9_44a200
  PS[0] = eax;  // @10_44a200
  ecx = ebx;  // @11_44a200
  eax = ext_4e0fd0_thiscall2(ecx, (u32)(PS[0]));  // @12_44a200
  ecx = edx = 0;  // @13_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; }) != (u32)(0)) goto L44a28d;  // @14_44a200
  eax = ext_41e290_cdecl1((u32)(28));  // @15_44a200
  ecx = edx = 0;  // @16_44a200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 204), &v, sizeof v); }  // @17_44a200
  reg.state = (s32)((u32)(1));  // @18_44a200
  if ((eax & eax) == 0) goto L44a284;  // @19_44a200
  ecx = eax;  // @20_44a200
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @21_44a200
  ecx = edx = 0;  // @22_44a200
  goto L44a286;  // @23_44a200
  L44a284:;
  eax = 0;  // @25_44a200
  L44a286:;
  reg.state = (s32)((u32)(0));  // @27_44a200
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 24), &v, sizeof v); }  // @28_44a200
  L44a28d:;
  eax = (u32)(EBP - 200);  // @30_44a200
  PS[0] = eax;  // @31_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @32_44a200
  ecx = (u32)(EBP - 188);  // @33_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @34_44a200
  ecx = edx = 0;  // @35_44a200
  eax = (u32)(EBP - 200);  // @36_44a200
  PS[0] = eax;  // @37_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @38_44a200
  ecx = (u32)(EBP - 188);  // @39_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @40_44a200
  ecx = edx = 0;  // @41_44a200
  esi = eax;  // @42_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) == (u32)(0)) goto L44a310;  // @43_44a200
  L44a2d0:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @45_44a200
  PS[0] = esi;  // @46_44a200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });  // @47_44a200
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @48_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, (u32)(PS[0]));  // @49_44a200
  ecx = edx = 0;  // @50_44a200
  if ((eax & eax) == 0) goto L44a2ef;  // @51_44a200
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 24), sizeof v); (u32)v; });  // @52_44a200
  PS[0] = esi;  // @53_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @54_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(PS[0]));  // @55_44a200
  ecx = edx = 0;  // @56_44a200
  L44a2ef:;
  eax = (u32)(EBP - 200);  // @58_44a200
  PS[0] = eax;  // @59_44a200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 188), sizeof v); (u32)v; });  // @60_44a200
  ecx = (u32)(EBP - 188);  // @61_44a200
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @62_44a200
  ecx = edx = 0;  // @63_44a200
  esi = eax;  // @64_44a200
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 200), sizeof v); (u32)v; }) != (u32)(0)) goto L44a2d0;  // @65_44a200
  L44a310:;
  ecx = ebx;  // @67_44a200
  eax = ext_4e1b30_thiscall1(ecx);  // @68_44a200
  ecx = edx = 0;  // @69_44a200
  ecx = (u32)(EBP - 188);  // @70_44a200
  eax = ext_4ccf60_thiscall1(ecx);  // @71_44a200
  ecx = edx = 0;  // @72_44a200
  SEH_LEAVE();  // @73_44a200
  ext_633654(G(u32, 0x6f5630));  // @74_44a200
  return eax;  // @75_44a200
}
PCREG(44a200, lifted_44a200);

extern "C" u32 THISCALL lifted_5bfac0(u32 ecx_in) {
  SEH_ENTER(0x66c558);  // @h_5bfac0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  esi = ecx;  // @0_5bfac0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @1_5bfac0
  eax = ext_469870_thiscall1(ecx);  // @2_5bfac0
  ecx = edx = 0;  // @3_5bfac0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }  // @5_5bfac0
  { u32 v = (u32)((u32)(7026868)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @6_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 84), &v, sizeof v); }  // @7_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @8_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @9_5bfac0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 100), &v, sizeof v); }  // @10_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_5bfac0
  reg.state = (s32)((u32)(0));  // @13_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @14_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968700), (u32)(0), (u32)(7027024), (u32)(63));  // @15_5bfac0
  ecx = edx = 0;  // @16_5bfac0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @17_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @18_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @19_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32, u32))(*(u32 *)(eax + 276)))(ecx, (u32)(6968716), (u32)(0), (u32)(7027024), (u32)(64));  // @21_5bfac0
  ecx = edx = 0;  // @22_5bfac0
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 74), &v, sizeof v); }  // @23_5bfac0
  edx = (u32)(EBP - 16);  // @24_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340984), sizeof v); (u32)v; });  // @25_5bfac0
  PS[0] = edx;  // @26_5bfac0
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(eax + 11281), &v, sizeof v); }  // @27_5bfac0
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @28_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @29_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @30_5bfac0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 92), sizeof v); (u32)v; });  // @31_5bfac0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(7027076), (u32)(PS[0]));  // @32_5bfac0
  ecx = edx = 0;  // @33_5bfac0
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L5bfbdf;  // @34_5bfac0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @35_5bfac0
  eax = (u32)(6792920);  // @36_5bfac0
  L5bfba0:;
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @38_5bfac0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) goto L5bfbc0;  // @39_5bfac0
  if (((edx & 0xff) & (edx & 0xff)) == 0) goto L5bfbbc;  // @40_5bfac0
  edx = (edx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 1), sizeof v); (u32)v; })) & 0xff);  // @41_5bfac0
  if ((edx & 0xff) != ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + 1), sizeof v); (u32)v; })) goto L5bfbc0;  // @42_5bfac0
  ecx = (ecx + (u32)(2));  // @43_5bfac0
  eax = (eax + (u32)(2));  // @44_5bfac0
  if (((edx & 0xff) & (edx & 0xff)) != 0) goto L5bfba0;  // @45_5bfac0
  L5bfbbc:;
  eax = 0;  // @47_5bfac0
  goto L5bfbc5;  // @48_5bfac0
  L5bfbc0:;
  eax = (u32)(0 - CF);  // @50_5bfac0
  eax = (eax | (u32)(1));  // @51_5bfac0
  L5bfbc5:;
  eax = esi;  // @53_5bfac0
  if ((eax & eax) != 0) goto L5bfbe1;  // @54_5bfac0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 104), &v, sizeof v); }  // @55_5bfac0
  SEH_LEAVE();  // @56_5bfac0
  return eax;  // @57_5bfac0
  L5bfbdf:;
  eax = esi;  // @59_5bfac0
  L5bfbe1:;
  SEH_LEAVE();  // @61_5bfac0
  return eax;  // @62_5bfac0
}
PCREG(5bfac0, lifted_5bfac0);

