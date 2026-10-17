// batch216017.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cc1d0_thiscall1(u32) __asm__("ext_4cc1d0");
extern "C" u32 THISCALL ext_4cc2c0_thiscall2(u32, u32) __asm__("ext_4cc2c0");
extern "C" u32 THISCALL ext_4ccba0_thiscall1(u32) __asm__("ext_4ccba0");
extern "C" u32 THISCALL ext_4ccbe0_thiscall3(u32, u32, u32) __asm__("ext_4ccbe0");
extern "C" u32 THISCALL ext_4ccf60_thiscall1(u32) __asm__("ext_4ccf60");
extern "C" u32 THISCALL ext_4cdcc0_thiscall1(u32) __asm__("ext_4cdcc0");
extern "C" u32 THISCALL ext_4d9ce0_thiscall1(u32) __asm__("ext_4d9ce0");
extern "C" u32 THISCALL ext_4da720_thiscall2(u32, u32) __asm__("ext_4da720");
extern "C" u32 THISCALL ext_4dc630_thiscall3(u32, u32, u32) __asm__("ext_4dc630");
extern "C" u32 THISCALL ext_4e3180_thiscall1(u32) __asm__("ext_4e3180");
extern "C" u32 THISCALL ext_4e49d0_thiscall2(u32, u32) __asm__("ext_4e49d0");
extern "C" u32 THISCALL ext_5fb370_thiscall2(u32, u32) __asm__("ext_5fb370");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_42ac56_cdecl3(...) __asm__("ext_42ac56");
extern "C" u32 ext_44a1f0_cdecl0(void) __asm__("ext_44a1f0");
extern "C" u32 ext_4cc1d0_cdecl2(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4cd0e0(u32 ecx_in) {
  SEH_ENTER(0x669286);  // @h_4cd0e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = ecx;  // @0_4cd0e0
  { u32 v = (u32)((u32)(6904480)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @1_4cd0e0
  eax = ext_4cdcc0_thiscall1(ecx);  // @2_4cd0e0
  ecx = edx = 0;  // @3_4cd0e0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) | (u32)(2147483648))); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @4_4cd0e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_4cd0e0
  reg.state = (s32)((u32)(0));  // @6_4cd0e0
  { u32 v = (u32)((u32)(6903604)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @7_4cd0e0
  if ((edi & edi) == 0) goto L4cd13f;  // @8_4cd0e0
  L4cd130:;
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @10_4cd0e0
  ecx = esi;  // @11_4cd0e0
  PS[0] = edi;  // @12_4cd0e0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @13_4cd0e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 124)))(ecx, (u32)(PS[0]));  // @14_4cd0e0
  ecx = edx = 0;  // @15_4cd0e0
  if ((edi & edi) != 0) goto L4cd130;  // @16_4cd0e0
  L4cd13f:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @18_4cd0e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @19_4cd0e0
  SEH_LEAVE();  // @20_4cd0e0
  return eax;  // @21_4cd0e0
}
PCREG(4cd0e0, lifted_4cd0e0);

extern "C" u32 THISCALL lifted_4e6ce0(u32 ecx_in) {
  SEH_ENTER(0x666500);  // @h_4e6ce0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  esi = (u32)(ecx + 12);  // @0_4e6ce0
  { u32 v = (u32)((u32)(6877288)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @1_4e6ce0
  if ((esi & esi) == 0) goto L4e6d4c;  // @2_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_4e6ce0
  ecx = (u32)(EBP - 24);  // @4_4e6ce0
  PS[0] = ecx;  // @5_4e6ce0
  ecx = esi;  // @6_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @7_4e6ce0
  ecx = edx = 0;  // @8_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4e6ce0
  ecx = (u32)(EBP - 24);  // @10_4e6ce0
  PS[0] = ecx;  // @11_4e6ce0
  ecx = esi;  // @12_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @13_4e6ce0
  ecx = edx = 0;  // @14_4e6ce0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) == (u32)(0)) goto L4e6d4c;  // @15_4e6ce0
  L4e6d30:;
  PS[1] = eax;  // @17_4e6ce0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(24));  // @18_4e6ce0
  ecx = edx = 0;  // @19_4e6ce0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_4e6ce0
  ecx = (u32)(EBP - 24);  // @21_4e6ce0
  PS[0] = ecx;  // @22_4e6ce0
  ecx = esi;  // @23_4e6ce0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @24_4e6ce0
  ecx = edx = 0;  // @25_4e6ce0
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 24), sizeof v); (u32)v; }) != (u32)(0)) goto L4e6d30;  // @26_4e6ce0
  L4e6d4c:;
  ecx = esi;  // @28_4e6ce0
  eax = ext_4ccf60_thiscall1(ecx);  // @29_4e6ce0
  ecx = edx = 0;  // @30_4e6ce0
  SEH_LEAVE();  // @31_4e6ce0
  return eax;  // @32_4e6ce0
}
// retired: PCREG(4e6ce0, lifted_4e6ce0); (hand port in batch216060)

extern "C" u32 THISCALL lifted_444df0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66825f);  // @h_444df0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_444df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @1_444df0
  if ((ecx & ecx) != 0) goto L444e63;  // @2_444df0
  eax = ext_41e290_cdecl1((u32)(28));  // @3_444df0
  ecx = edx = 0;  // @4_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @5_444df0
  reg.state = (s32)((u32)(0));  // @6_444df0
  if ((eax & eax) == 0) goto L444e52;  // @7_444df0
  ecx = eax;  // @8_444df0
  eax = ext_4ccbe0_thiscall3(ecx, (u32)(32), (u32)(0));  // @9_444df0
  ecx = edx = 0;  // @10_444df0
  reg.state = (s32)((u32)(4294967295));  // @11_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @12_444df0
  goto L444e6f;  // @13_444df0
  L444e52:;
  eax = 0;  // @15_444df0
  reg.state = (s32)((u32)(4294967295));  // @16_444df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 164), &v, sizeof v); }  // @17_444df0
  goto L444e6f;  // @18_444df0
  L444e63:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 40)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @21_444df0
  ecx = edx = 0;  // @22_444df0
  if ((eax & eax) != 0) goto L444e9c;  // @23_444df0
  L444e6f:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 164), sizeof v); (u32)v; });  // @25_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @26_444df0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @27_444df0
  ecx = edx = 0;  // @28_444df0
  L444e80:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @30_444df0
  eax = ext_4dc630_thiscall3(ecx, (u32)(4194304), (u32)(0));  // @31_444df0
  ecx = edx = 0;  // @32_444df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_444df0
  ecx = esi;  // @34_444df0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @35_444df0
  ecx = edx = 0;  // @36_444df0
  esi = eax;  // @37_444df0
  if ((esi & esi) != 0) goto L444e80;  // @38_444df0
  L444e9c:;
  SEH_LEAVE();  // @40_444df0
  return eax;  // @41_444df0
}
PCREG(444df0, lifted_444df0);

extern "C" u32 THISCALL lifted_4385e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66606f);  // @h_4385e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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

extern "C" u32 STDCALL lifted_48f5e0(u32 a0) {
  SEH_ENTER(0x667c5b);  // @h_48f5e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_48f5e0
  esi = (u32)(1);  // @1_48f5e0
  L48f620:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @3_48f5e0
  edx = (u32)(EBP - 1168);  // @4_48f5e0
  PS[0] = edx;  // @5_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_48f5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 320)))(ecx, (u32)(PS[0]));  // @7_48f5e0
  ecx = edx = 0;  // @8_48f5e0
  PS[0] = esi;  // @9_48f5e0
  PS[1] = edi;  // @10_48f5e0
  ecx = eax;  // @11_48f5e0
  reg.state = (s32)((u32)(0));  // @12_48f5e0
  eax = ext_4cc1d0_cdecl2((u32)(PS[1]), (u32)(PS[0]));  // @13_48f5e0
  ecx = edx = 0;  // @14_48f5e0
  PS[0] = eax;  // @15_48f5e0
  eax = (u32)(EBP - 1040);  // @16_48f5e0
  PS[2] = eax;  // @17_48f5e0
  eax = ext_42ac56_cdecl3((u32)(PS[2]), (u32)(6871000), (u32)(PS[0]));  // @18_48f5e0
  ecx = edx = 0;  // @19_48f5e0
  reg.state = (s32)((u32)(4294967295));  // @20_48f5e0
  ecx = (u32)(EBP - 1168);  // @21_48f5e0
  eax = ext_4cbec0_thiscall1(ecx);  // @22_48f5e0
  ecx = edx = 0;  // @23_48f5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @24_48f5e0
  edx = (u32)(EBP - 1040);  // @25_48f5e0
  PS[0] = edx;  // @26_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @27_48f5e0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 92)))(ecx, (u32)(PS[0]));  // @28_48f5e0
  ecx = edx = 0;  // @29_48f5e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @30_48f5e0
  edx = (u32)(EBP - 1040);  // @31_48f5e0
  PS[1] = edx;  // @32_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @33_48f5e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 52), sizeof v); (u32)v; });  // @34_48f5e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(eax))(ecx, (u32)(PS[1]), (u32)(0));  // @35_48f5e0
  ecx = edx = 0;  // @36_48f5e0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L48f6a2;  // @37_48f5e0
  esi = (esi + 1);  // @38_48f5e0
  if ((s32)esi <= (s32)(u32)(3)) goto L48f620;  // @39_48f5e0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @40_48f5e0
  goto L48f6a4;  // @41_48f5e0
  L48f6a2:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @43_48f5e0
  L48f6a4:;
  SEH_LEAVE();  // @45_48f5e0
  ext_633654(G(u32, 0x6f5630));  // @46_48f5e0
  return eax;  // @47_48f5e0
}
PCREG(48f5e0, lifted_48f5e0);

extern "C" u32 THISCALL lifted_442ad0(u32 ecx_in) {
  SEH_ENTER(0x665e7b);  // @h_442ad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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

extern "C" u32 THISCALL lifted_5afef0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66681b);  // @h_5afef0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
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
// retired: PCREG(5afef0, lifted_5afef0); (hand port in batch216060)

extern "C" u32 THISCALL lifted_5fb370(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66d436);  // @h_5fb370
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ebx = ecx;  // @0_5fb370
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_5fb370
  if ((esi & esi) == 0) goto L5fb3e4;  // @2_5fb370
  L5fb3a0:;
  ecx = ebx;  // @4_5fb370
  eax = ext_5fb370_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 9), sizeof v); (u32)v; }));  // @5_5fb370
  ecx = edx = 0;  // @6_5fb370
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @7_5fb370
  ecx = (u32)(esi + 13);  // @8_5fb370
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @9_5fb370
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @10_5fb370
  eax = (eax - edx);  // @11_5fb370
  reg.state = (s32)((u32)(0));  // @12_5fb370
  if ((edx & edx) == 0) goto L5fb3cd;  // @13_5fb370
  if ((eax & eax) == 0) goto L5fb3cd;  // @14_5fb370
  PS[0] = eax;  // @15_5fb370
  PS[1] = edx;  // @16_5fb370
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @17_5fb370
  ecx = edx = 0;  // @18_5fb370
  L5fb3cd:;
  PS[1] = esi;  // @20_5fb370
  ecx = ebx;  // @21_5fb370
  reg.state = (s32)((u32)(4294967295));  // @22_5fb370
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(29));  // @23_5fb370
  ecx = edx = 0;  // @24_5fb370
  esi = edi;  // @25_5fb370
  if ((edi & edi) != 0) goto L5fb3a0;  // @26_5fb370
  L5fb3e4:;
  SEH_LEAVE();  // @28_5fb370
  return eax;  // @29_5fb370
}
// retired: PCREG(5fb370, lifted_5fb370); (hand port in batch216060)

extern "C" u32 STDCALL lifted_42da80(u32 a0) {
  SEH_ENTER(0x66697b);  // @h_42da80
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16];
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_42da80
  ecx = edi;  // @1_42da80
  eax = ext_4cc1d0_thiscall1(ecx);  // @2_42da80
  ecx = edx = 0;  // @3_42da80
  esi = eax;  // @4_42da80
  edx = esi;  // @5_42da80
  eax = (u32)(edx + 1);  // @6_42da80
  L42dac0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @8_42da80
  edx = (edx + 1);  // @9_42da80
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L42dac0;  // @10_42da80
  edx = (edx - eax);  // @11_42da80
  if (edx == 0) goto L42db16;  // @12_42da80
  eax = 0;  // @13_42da80
  L42dad0:;
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + esi), sizeof v); (u32)v; }) != (u32)(47)) goto L42dada;  // @15_42da80
  { u8 v = (u8)((u32)(92)); __builtin_memcpy((void *)(u32)(eax + esi), &v, sizeof v); }  // @16_42da80
  L42dada:;
  eax = (eax + 1);  // @18_42da80
  if (eax != edx) goto L42dad0;  // @19_42da80
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx + esi - 1), sizeof v); (u32)v; }) == (u32)(92)) goto L42db16;  // @20_42da80
  ecx = (u32)(EBP - 144);  // @21_42da80
  eax = ext_4cbe80_thiscall2(ecx, (u32)(6784364));  // @22_42da80
  ecx = edx = 0;  // @23_42da80
  eax = (u32)(EBP - 144);  // @24_42da80
  reg.state = (s32)((u32)(0));  // @25_42da80
  PS[0] = eax;  // @26_42da80
  ecx = edi;  // @27_42da80
  eax = ext_4cc2c0_thiscall2(ecx, (u32)(PS[0]));  // @28_42da80
  ecx = edx = 0;  // @29_42da80
  ecx = (u32)(EBP - 144);  // @30_42da80
  eax = ext_4cbec0_thiscall1(ecx);  // @31_42da80
  ecx = edx = 0;  // @32_42da80
  L42db16:;
  SEH_LEAVE();  // @34_42da80
  ext_633654(G(u32, 0x6f5630));  // @35_42da80
  return eax;  // @36_42da80
}
PCREG(42da80, lifted_42da80);

