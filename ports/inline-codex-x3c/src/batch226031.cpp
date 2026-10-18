// batch226031.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 STDCALL ext_54f870_stdcall2(u32, u32) __asm__("ext_54f870");
extern "C" u32 STDCALL ext_6014a0_stdcall1(u32) __asm__("ext_6014a0");
extern "C" u32 THISCALL ext_441e40_thiscall2(u32, u32) __asm__("ext_441e40");
extern "C" u32 THISCALL ext_4cbe80_thiscall2(u32, u32) __asm__("ext_4cbe80");
extern "C" u32 THISCALL ext_4cbeb0_thiscall1(u32) __asm__("ext_4cbeb0");
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_4cbee0_thiscall2(u32, u32) __asm__("ext_4cbee0");
extern "C" u32 THISCALL ext_4cca60_thiscall3(u32, u32, u32) __asm__("ext_4cca60");
extern "C" u32 THISCALL ext_4d5440_thiscall1(u32) __asm__("ext_4d5440");
extern "C" u32 THISCALL ext_4db7e0_thiscall1(u32) __asm__("ext_4db7e0");
extern "C" u32 THISCALL ext_4ff920_thiscall1(u32) __asm__("ext_4ff920");
extern "C" u32 THISCALL ext_603430_thiscall3(u32, u32, u32) __asm__("ext_603430");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");
extern "C" u32 ext_4cc1d0_cdecl1(...) __asm__("ext_4cc1d0");
extern "C" u32 ext_634273_cdecl2(...) __asm__("ext_634273");
extern "C" u32 ext_634d10_cdecl3(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_434bf0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x6657bf);  // @h_434bf0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @0_434bf0
  eax = ext_41e290_cdecl1((u32)(111));  // @1_434bf0
  ecx = edx = 0;  // @2_434bf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }  // @3_434bf0
  reg.state = (s32)((u32)(0));  // @4_434bf0
  if ((eax & eax) == 0) goto L434c3e;  // @5_434bf0
  ecx = eax;  // @6_434bf0
  eax = ext_4d5440_thiscall1(ecx);  // @7_434bf0
  ecx = edx = 0;  // @8_434bf0
  ebx = eax;  // @9_434bf0
  goto L434c40;  // @10_434bf0
  L434c3e:;
  ebx = 0;  // @12_434bf0
  L434c40:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @14_434bf0
  ecx = esi;  // @15_434bf0
  reg.state = (s32)((u32)(4294967295));  // @16_434bf0
  edx = (u32)(ecx + 1);  // @17_434bf0
  L434c50:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; })) & 0xff);  // @19_434bf0
  ecx = (ecx + 1);  // @20_434bf0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L434c50;  // @21_434bf0
  ecx = (ecx - edx);  // @22_434bf0
  eax = (u32)(ecx + 1);  // @23_434bf0
  PS[0] = eax;  // @24_434bf0
  eax = ext_41e290_cdecl1((u32)(PS[0]));  // @25_434bf0
  ecx = edx = 0;  // @26_434bf0
  edi = eax;  // @27_434bf0
  edx = esi;  // @28_434bf0
  esi = edi;  // @29_434bf0
  esi = (esi - edx);  // @30_434bf0
  L434c70:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; })) & 0xff);  // @32_434bf0
  edx = (u32)(edx + 1);  // @33_434bf0
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(esi + edx - 1), &v, sizeof v); }  // @34_434bf0
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L434c70;  // @35_434bf0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(6775384), sizeof v); (u32)v; });  // @36_434bf0
  PS[1] = edi;  // @37_434bf0
  eax = ((u32( *)(u32, u32))(esi))((u32)(PS[1]), (u32)(92));  // @38_434bf0
  ecx = edx = 0;  // @39_434bf0
  if ((eax & eax) != 0) goto L434c9b;  // @40_434bf0
  PS[1] = edi;  // @41_434bf0
  eax = ((u32( *)(u32, u32))(esi))((u32)(PS[1]), (u32)(47));  // @42_434bf0
  ecx = edx = 0;  // @43_434bf0
  if ((eax & eax) == 0) goto L434ca7;  // @44_434bf0
  L434c9b:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @46_434bf0
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @47_434bf0
  PS[0] = edi;  // @48_434bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @49_434bf0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(PS[0]));  // @50_434bf0
  ecx = edx = 0;  // @51_434bf0
  L434ca7:;
  PS[1] = edi;  // @53_434bf0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(1));  // @54_434bf0
  ecx = edx = 0;  // @55_434bf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @56_434bf0
  ecx = ebx;  // @57_434bf0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 52)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), (u32)(1));  // @58_434bf0
  ecx = edx = 0;  // @59_434bf0
  eax = ebx;  // @60_434bf0
  SEH_LEAVE();  // @61_434bf0
  return eax;  // @62_434bf0
}
PCREG(434bf0, lifted_434bf0);

extern "C" u32 THISCALL lifted_441e40(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665e4f);  // @h_441e40
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_441e40
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; }) != (u32)(0)) goto L441ecd;  // @1_441e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7338344), sizeof v); (u32)v; });  // @2_441e40
  if ((ecx & ecx) != 0) goto L441eb0;  // @3_441e40
  eax = ext_41e290_cdecl1((u32)(40));  // @4_441e40
  ecx = edx = 0;  // @5_441e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @6_441e40
  reg.state = (s32)((u32)(0));  // @7_441e40
  if ((eax & eax) == 0) goto L441ea1;  // @8_441e40
  ecx = eax;  // @9_441e40
  eax = ext_4cca60_thiscall3(ecx, (u32)(1), (u32)(288));  // @10_441e40
  ecx = edx = 0;  // @11_441e40
  ecx = eax;  // @12_441e40
  goto L441ea3;  // @13_441e40
  L441ea1:;
  ecx = 0;  // @15_441e40
  L441ea3:;
  reg.state = (s32)((u32)(4294967295));  // @17_441e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7338344), &v, sizeof v); }  // @18_441e40
  L441eb0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @20_441e40
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, (u32)(0));  // @21_441e40
  ecx = edx = 0;  // @22_441e40
  eax = (eax + (u32)(-4));  // @23_441e40
  PS[2] = eax;  // @24_441e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 123), &v, sizeof v); }  // @25_441e40
  eax = ext_634d10_cdecl3((u32)(PS[2]), (u32)(0), (u32)(1156));  // @26_441e40
  ecx = edx = 0;  // @27_441e40
  L441ecd:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @29_441e40
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @30_441e40
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2), sizeof v); (u32)v; });  // @31_441e40
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(ecx + eax*4 + 1028), &v, sizeof v); }  // @32_441e40
  ecx = esi;  // @33_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 123), sizeof v); (u32)v; });  // @34_441e40
  { u16 v = (u16)((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(eax + 2), &v, sizeof v); }  // @35_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @36_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 784), sizeof v); (u32)v; });  // @37_441e40
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @38_441e40
  ecx = edx = 0;  // @39_441e40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L441f2b;  // @40_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @41_441e40
  ecx = esi;  // @42_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 780), sizeof v); (u32)v; });  // @43_441e40
  eax = ((u32(THISCALL *)(u32))(eax))(ecx);  // @44_441e40
  ecx = edx = 0;  // @45_441e40
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L441f2b;  // @46_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @47_441e40
  ecx = esi;  // @48_441e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @49_441e40
  ecx = edx = 0;  // @50_441e40
  if ((eax & eax) == 0) goto L441f2b;  // @51_441e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @52_441e40
  ecx = esi;  // @53_441e40
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @54_441e40
  ecx = edx = 0;  // @55_441e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @56_441e40
  eax = ext_4db7e0_thiscall1(ecx);  // @57_441e40
  ecx = edx = 0;  // @58_441e40
  if ((eax & eax) == 0) goto L441f2b;  // @59_441e40
  PS[0] = edi;  // @60_441e40
  ecx = eax;  // @61_441e40
  eax = ext_441e40_thiscall2(ecx, (u32)(PS[0]));  // @62_441e40
  ecx = edx = 0;  // @63_441e40
  L441f2b:;
  SEH_LEAVE();  // @65_441e40
  return eax;  // @66_441e40
}
PCREG(441e40, lifted_441e40);

extern "C" u32 THISCALL lifted_434ad0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x664256);  // @h_434ad0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;  // @0_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @1_434ad0
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_434ad0
  if ((ecx & ecx) == 0) goto L434bd2;  // @3_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @4_434ad0
  edx = (u32)(EBP - 284);  // @5_434ad0
  PS[0] = edx;  // @6_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 76)))(ecx, (u32)(PS[0]));  // @7_434ad0
  ecx = edx = 0;  // @8_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @9_434ad0
  edx = (u32)(EBP - 284);  // @10_434ad0
  PS[0] = edx;  // @11_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @13_434ad0
  ecx = edx = 0;  // @14_434ad0
  esi = eax;  // @15_434ad0
  if ((esi & esi) == 0) goto L434bd2;  // @16_434ad0
  L434b33:;
  ecx = (u32)(EBP - 144);  // @18_434ad0
  eax = ext_4cbeb0_thiscall1(ecx);  // @19_434ad0
  ecx = edx = 0;  // @20_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @21_434ad0
  ecx = (u32)(EBP - 272);  // @22_434ad0
  reg.state = (s32)((u32)(0));  // @23_434ad0
  eax = ext_4cbe80_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13), sizeof v); (u32)v; }));  // @24_434ad0
  ecx = edx = 0;  // @25_434ad0
  eax = (u32)(EBP - 272);  // @26_434ad0
  reg.state = (s32)((u32)(1));  // @27_434ad0
  PS[0] = eax;  // @28_434ad0
  ecx = (u32)(EBP - 144);  // @29_434ad0
  eax = ext_4cbee0_thiscall2(ecx, (u32)(PS[0]));  // @30_434ad0
  ecx = edx = 0;  // @31_434ad0
  ecx = (u32)(EBP - 272);  // @32_434ad0
  reg.state = (s32)((u32)(0));  // @33_434ad0
  eax = ext_4cbec0_thiscall1(ecx);  // @34_434ad0
  ecx = edx = 0;  // @35_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @36_434ad0
  ecx = (u32)(EBP - 144);  // @37_434ad0
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @38_434ad0
  eax = ext_4cc1d0_cdecl1((u32)(0));  // @39_434ad0
  ecx = edx = 0;  // @40_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @41_434ad0
  PS[0] = eax;  // @42_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(esi + 48)))(ecx, (u32)(PS[0]));  // @43_434ad0
  ecx = edx = 0;  // @44_434ad0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @45_434ad0
  ecx = 0;  // @46_434ad0
  if ((s32)(eax & eax) < 0) eax = ecx;  // @47_434ad0
  ecx = ebx;  // @48_434ad0
  PS[0] = eax;  // @49_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 4)))(ecx, (u32)(PS[0]));  // @50_434ad0
  ecx = edx = 0;  // @51_434ad0
  ecx = (u32)(EBP - 144);  // @52_434ad0
  reg.state = (s32)((u32)(4294967295));  // @53_434ad0
  eax = ext_4cbec0_thiscall1(ecx);  // @54_434ad0
  ecx = edx = 0;  // @55_434ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 4), sizeof v); (u32)v; });  // @56_434ad0
  edx = (u32)(EBP - 284);  // @57_434ad0
  PS[0] = edx;  // @58_434ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @59_434ad0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 100)))(ecx, (u32)(PS[0]));  // @60_434ad0
  ecx = edx = 0;  // @61_434ad0
  esi = eax;  // @62_434ad0
  if ((esi & esi) != 0) goto L434b33;  // @63_434ad0
  L434bd2:;
  SEH_LEAVE();  // @65_434ad0
  ext_633654(G(u32, 0x6f5630));  // @66_434ad0
  return eax;  // @67_434ad0
}
PCREG(434ad0, lifted_434ad0);

extern "C" u32 THISCALL lifted_6041e0(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66dd06);  // @h_6041e0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
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

extern "C" u32 THISCALL lifted_4ff9d0(u32 ecx_in) {
  SEH_ENTER(0x669bc6);  // @h_4ff9d0
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0, PS[16], CF = 0;
  ebx = ecx;  // @0_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @1_4ff9d0
  edi = 0;  // @2_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @3_4ff9d0
  eax = (eax - ecx);  // @4_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @5_4ff9d0
  if ((eax & eax) == 0) goto L4ffa30;  // @6_4ff9d0
  L4ffa08:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + edi*4), sizeof v); (u32)v; });  // @8_4ff9d0
  if ((esi & esi) == 0) goto L4ffa21;  // @9_4ff9d0
  ecx = esi;  // @10_4ff9d0
  eax = ext_4ff920_thiscall1(ecx);  // @11_4ff9d0
  ecx = edx = 0;  // @12_4ff9d0
  PS[1] = esi;  // @13_4ff9d0
  eax = ext_634273_cdecl2((u32)(PS[1]), (u32)(72));  // @14_4ff9d0
  ecx = edx = 0;  // @15_4ff9d0
  L4ffa21:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @17_4ff9d0
  edi = (edi + 1);  // @18_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @19_4ff9d0
  eax = (eax - ecx);  // @20_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @21_4ff9d0
  if (edi < eax) goto L4ffa08;  // @22_4ff9d0
  L4ffa30:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; });  // @24_4ff9d0
  edx = esi;  // @25_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @26_4ff9d0
  edx = (edx - esi);  // @27_4ff9d0
  edx = (u32)((s32)edx >> (u32)(2));  // @28_4ff9d0
  ecx = eax;  // @29_4ff9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @30_4ff9d0
  if ((s32)(edx & edx) <= 0) goto L4ffa61;  // @31_4ff9d0
  edi = esi;  // @32_4ff9d0
  edi = (edi - eax);  // @33_4ff9d0
  L4ffa50:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + ecx), sizeof v); (u32)v; });  // @35_4ff9d0
  ecx = (u32)(ecx + 4);  // @36_4ff9d0
  edx = (edx - 1);  // @37_4ff9d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx - 4), &v, sizeof v); }  // @38_4ff9d0
  if ((s32)(edx & edx) > 0) goto L4ffa50;  // @39_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; });  // @40_4ff9d0
  L4ffa61:;
  esi = (esi - eax);  // @42_4ff9d0
  esi = (u32)((s32)esi >> (u32)(2));  // @43_4ff9d0
  CF = (esi != 0); esi = (u32)(0 - esi);  // @44_4ff9d0
  esi = (esi << (u32)(2));  // @45_4ff9d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 4), sizeof v); (u32)v; }) + esi)); __builtin_memcpy((void *)(u32)(ebx + 4), &v, sizeof v); }  // @46_4ff9d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @47_4ff9d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; });  // @48_4ff9d0
  eax = (eax - ecx);  // @49_4ff9d0
  eax = (u32)((s32)eax >> (u32)(2));  // @50_4ff9d0
  reg.state = (s32)((u32)(0));  // @51_4ff9d0
  if ((eax & eax) == 0) goto L4ffa8f;  // @52_4ff9d0
  eax = (eax << (u32)(2));  // @53_4ff9d0
  PS[0] = eax;  // @54_4ff9d0
  PS[1] = ecx;  // @55_4ff9d0
  ecx = ebx;  // @56_4ff9d0
  eax = ext_54f870_stdcall2((u32)(PS[1]), (u32)(PS[0]));  // @57_4ff9d0
  ecx = edx = 0;  // @58_4ff9d0
  L4ffa8f:;
  SEH_LEAVE();  // @60_4ff9d0
  return eax;  // @61_4ff9d0
}
PCREG(4ff9d0, lifted_4ff9d0);

