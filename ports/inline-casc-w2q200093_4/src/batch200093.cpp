// batch200093.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4eb350_thiscall2(u32, u32) __asm__("ext_4eb350");
extern "C" u32 ext_41e2c0_cdecl1(...) __asm__("ext_41e2c0");
extern "C" u32 ext_549de0_cdecl1(...) __asm__("ext_549de0");
extern "C" u32 ext_633ed4_cdecl1(...) __asm__("ext_633ed4");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_634811(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(16384);  // @0_634811
  return eax;  // @1_634811
}
PCREG(634811, lifted_634811);

extern "C" u32 lifted_63486d(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(8471112);  // @0_63486d
  return eax;  // @1_63486d
}
PCREG(63486d, lifted_63486d);

extern "C" u32 lifted_634861(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = 0;  // @0_634861
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7296624), sizeof v); (u32)v; }) == eax)) & 0xff);  // @1_634861
  return eax;  // @2_634861
}
PCREG(634861, lifted_634861);

extern "C" u32 lifted_634cb5(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = 0;  // @0_634cb5
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7299884), sizeof v); (u32)v; }) != eax)) & 0xff);  // @1_634cb5
  return eax;  // @2_634cb5
}
PCREG(634cb5, lifted_634cb5);

extern "C" u32 THISCALL lifted_662fb0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_662fb0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 69), sizeof v); (u32)v; });  // @1_662fb0
  edx = (edx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 65), sizeof v); (u32)v; }));  // @2_662fb0
  eax = (eax & 0xffffff00u) | (((u32)((s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; }) >= (s32)edx)) & 0xff);  // @3_662fb0
  return eax;  // @4_662fb0
}
PCREG(662fb0, lifted_662fb0);

extern "C" u32 lifted_634273(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ext_41e2c0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @0_634273
  ecx = edx = 0;  // @1_634273
  return eax;  // @2_634273
}
PCREG(634273, lifted_634273);

extern "C" u32 THISCALL lifted_660cc0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(7096588)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @0_660cc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 24), sizeof v); (u32)v; });  // @1_660cc0
  if ((ecx & ecx) == 0) goto L660cd3;  // @2_660cc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_660cc0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));  // @4_660cc0
  ecx = edx = 0;  // @5_660cc0
  L660cd3:;
  return eax;  // @7_660cc0
}
PCREG(660cc0, lifted_660cc0);

extern "C" u32 lifted_633170(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_633170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 36), sizeof v); (u32)v; });  // @1_633170
  eax = ((u32( *)(u32, u32))(eax))(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 40), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_633170
  ecx = edx = 0;  // @3_633170
  return eax;  // @4_633170
}
PCREG(633170, lifted_633170);

extern "C" u32 lifted_633f0f(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ext_633ed4_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @0_633f0f
  ecx = edx = 0;  // @1_633f0f
  eax = (0u - eax);  // @2_633f0f
  eax = 0;  // @3_633f0f
  eax = (0u - eax);  // @4_633f0f
  eax = (eax - 1);  // @5_633f0f
  return eax;  // @6_633f0f
}
PCREG(633f0f, lifted_633f0f);

extern "C" u32 THISCALL lifted_660c80(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(7096588)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @0_660c80
  eax = ecx;  // @1_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 24), &v, sizeof v); }  // @2_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @4_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 28), &v, sizeof v); }  // @5_660c80
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 32), &v, sizeof v); }  // @6_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @7_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @8_660c80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @9_660c80
  return eax;  // @10_660c80
}
PCREG(660c80, lifted_660c80);

extern "C" u32 THISCALL lifted_661310(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + (-4), &ecx, 4);
  esi = ecx;  // @0_661310
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_661310
  eax = ext_4eb350_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @2_661310
  ecx = edx = 0;  // @3_661310
  { u32 v = (u32)((u32)(7096832)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @4_661310
  eax = esi;  // @5_661310
  return eax;  // @6_661310
}
PCREG(661310, lifted_661310);

extern "C" u32 lifted_633eac(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(7492784), sizeof v); (u32)v; }) == (u32)(0)) goto L633ebe;  // @0_633eac
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }) != (u32)(0)) goto L633ed0;  // @1_633eac
  L633ebe:;
  eax = ext_549de0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @3_633eac
  ecx = edx = 0;  // @4_633eac
  eax = ext_549de0_cdecl1(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));  // @5_633eac
  ecx = edx = 0;  // @6_633eac
  L633ed0:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @8_633eac
  return eax;  // @9_633eac
}
PCREG(633eac, lifted_633eac);

extern "C" u32 lifted_66ee90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229216), sizeof v); (u32)v; });  // @0_66ee90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229220), sizeof v); (u32)v; });  // @1_66ee90
  if ((ecx & ecx) == 0) goto L66eeaf;  // @2_66ee90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66ee90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229220), sizeof v); (u32)v; });  // @4_66ee90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229216), sizeof v); (u32)v; });  // @5_66ee90
  goto L66eeb4;  // @6_66ee90
  L66eeaf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66ee90
  L66eeb4:;
  if ((eax & eax) == 0) goto L66eebd;  // @10_66ee90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66ee90
  goto L66eec3;  // @12_66ee90
  L66eebd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66ee90
  L66eec3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229216), &v, sizeof v); }  // @16_66ee90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229220), &v, sizeof v); }  // @17_66ee90
  return eax;  // @18_66ee90
}
PCREG(66ee90, lifted_66ee90);

extern "C" u32 lifted_66eee0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229268), sizeof v); (u32)v; });  // @0_66eee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229272), sizeof v); (u32)v; });  // @1_66eee0
  if ((ecx & ecx) == 0) goto L66eeff;  // @2_66eee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66eee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229272), sizeof v); (u32)v; });  // @4_66eee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229268), sizeof v); (u32)v; });  // @5_66eee0
  goto L66ef04;  // @6_66eee0
  L66eeff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66eee0
  L66ef04:;
  if ((eax & eax) == 0) goto L66ef0d;  // @10_66eee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66eee0
  goto L66ef13;  // @12_66eee0
  L66ef0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66eee0
  L66ef13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229268), &v, sizeof v); }  // @16_66eee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229272), &v, sizeof v); }  // @17_66eee0
  return eax;  // @18_66eee0
}
PCREG(66eee0, lifted_66eee0);

extern "C" u32 lifted_66ef80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229380), sizeof v); (u32)v; });  // @0_66ef80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229384), sizeof v); (u32)v; });  // @1_66ef80
  if ((ecx & ecx) == 0) goto L66ef9f;  // @2_66ef80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66ef80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229384), sizeof v); (u32)v; });  // @4_66ef80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229380), sizeof v); (u32)v; });  // @5_66ef80
  goto L66efa4;  // @6_66ef80
  L66ef9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66ef80
  L66efa4:;
  if ((eax & eax) == 0) goto L66efad;  // @10_66ef80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66ef80
  goto L66efb3;  // @12_66ef80
  L66efad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66ef80
  L66efb3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229380), &v, sizeof v); }  // @16_66ef80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229384), &v, sizeof v); }  // @17_66ef80
  return eax;  // @18_66ef80
}
PCREG(66ef80, lifted_66ef80);

extern "C" u32 lifted_66efe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229436), sizeof v); (u32)v; });  // @0_66efe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229440), sizeof v); (u32)v; });  // @1_66efe0
  if ((ecx & ecx) == 0) goto L66efff;  // @2_66efe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66efe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229440), sizeof v); (u32)v; });  // @4_66efe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229436), sizeof v); (u32)v; });  // @5_66efe0
  goto L66f004;  // @6_66efe0
  L66efff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66efe0
  L66f004:;
  if ((eax & eax) == 0) goto L66f00d;  // @10_66efe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66efe0
  goto L66f013;  // @12_66efe0
  L66f00d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66efe0
  L66f013:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229436), &v, sizeof v); }  // @16_66efe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229440), &v, sizeof v); }  // @17_66efe0
  return eax;  // @18_66efe0
}
PCREG(66efe0, lifted_66efe0);

extern "C" u32 lifted_66f030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229492), sizeof v); (u32)v; });  // @0_66f030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229496), sizeof v); (u32)v; });  // @1_66f030
  if ((ecx & ecx) == 0) goto L66f04f;  // @2_66f030
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229496), sizeof v); (u32)v; });  // @4_66f030
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229492), sizeof v); (u32)v; });  // @5_66f030
  goto L66f054;  // @6_66f030
  L66f04f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f030
  L66f054:;
  if ((eax & eax) == 0) goto L66f05d;  // @10_66f030
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f030
  goto L66f063;  // @12_66f030
  L66f05d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f030
  L66f063:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229492), &v, sizeof v); }  // @16_66f030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229496), &v, sizeof v); }  // @17_66f030
  return eax;  // @18_66f030
}
PCREG(66f030, lifted_66f030);

extern "C" u32 lifted_66f120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229880), sizeof v); (u32)v; });  // @0_66f120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229884), sizeof v); (u32)v; });  // @1_66f120
  if ((ecx & ecx) == 0) goto L66f13f;  // @2_66f120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229884), sizeof v); (u32)v; });  // @4_66f120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229880), sizeof v); (u32)v; });  // @5_66f120
  goto L66f144;  // @6_66f120
  L66f13f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f120
  L66f144:;
  if ((eax & eax) == 0) goto L66f14d;  // @10_66f120
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f120
  goto L66f153;  // @12_66f120
  L66f14d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f120
  L66f153:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229880), &v, sizeof v); }  // @16_66f120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229884), &v, sizeof v); }  // @17_66f120
  return eax;  // @18_66f120
}
PCREG(66f120, lifted_66f120);

extern "C" u32 lifted_66f170(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230036), sizeof v); (u32)v; });  // @0_66f170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230040), sizeof v); (u32)v; });  // @1_66f170
  if ((ecx & ecx) == 0) goto L66f18f;  // @2_66f170
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230040), sizeof v); (u32)v; });  // @4_66f170
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230036), sizeof v); (u32)v; });  // @5_66f170
  goto L66f194;  // @6_66f170
  L66f18f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f170
  L66f194:;
  if ((eax & eax) == 0) goto L66f19d;  // @10_66f170
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f170
  goto L66f1a3;  // @12_66f170
  L66f19d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f170
  L66f1a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230036), &v, sizeof v); }  // @16_66f170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230040), &v, sizeof v); }  // @17_66f170
  return eax;  // @18_66f170
}
PCREG(66f170, lifted_66f170);

extern "C" u32 lifted_66f260(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229568), sizeof v); (u32)v; });  // @0_66f260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229572), sizeof v); (u32)v; });  // @1_66f260
  if ((ecx & ecx) == 0) goto L66f27f;  // @2_66f260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229572), sizeof v); (u32)v; });  // @4_66f260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229568), sizeof v); (u32)v; });  // @5_66f260
  goto L66f284;  // @6_66f260
  L66f27f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f260
  L66f284:;
  if ((eax & eax) == 0) goto L66f28d;  // @10_66f260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f260
  goto L66f293;  // @12_66f260
  L66f28d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f260
  L66f293:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229568), &v, sizeof v); }  // @16_66f260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229572), &v, sizeof v); }  // @17_66f260
  return eax;  // @18_66f260
}
PCREG(66f260, lifted_66f260);

extern "C" u32 lifted_66f2b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229724), sizeof v); (u32)v; });  // @0_66f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229728), sizeof v); (u32)v; });  // @1_66f2b0
  if ((ecx & ecx) == 0) goto L66f2cf;  // @2_66f2b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f2b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229728), sizeof v); (u32)v; });  // @4_66f2b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229724), sizeof v); (u32)v; });  // @5_66f2b0
  goto L66f2d4;  // @6_66f2b0
  L66f2cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f2b0
  L66f2d4:;
  if ((eax & eax) == 0) goto L66f2dd;  // @10_66f2b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f2b0
  goto L66f2e3;  // @12_66f2b0
  L66f2dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f2b0
  L66f2e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229724), &v, sizeof v); }  // @16_66f2b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229728), &v, sizeof v); }  // @17_66f2b0
  return eax;  // @18_66f2b0
}
PCREG(66f2b0, lifted_66f2b0);

extern "C" u32 lifted_66f3a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229776), sizeof v); (u32)v; });  // @0_66f3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229780), sizeof v); (u32)v; });  // @1_66f3a0
  if ((ecx & ecx) == 0) goto L66f3bf;  // @2_66f3a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f3a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229780), sizeof v); (u32)v; });  // @4_66f3a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7229776), sizeof v); (u32)v; });  // @5_66f3a0
  goto L66f3c4;  // @6_66f3a0
  L66f3bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f3a0
  L66f3c4:;
  if ((eax & eax) == 0) goto L66f3cd;  // @10_66f3a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f3a0
  goto L66f3d3;  // @12_66f3a0
  L66f3cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f3a0
  L66f3d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229776), &v, sizeof v); }  // @16_66f3a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7229780), &v, sizeof v); }  // @17_66f3a0
  return eax;  // @18_66f3a0
}
PCREG(66f3a0, lifted_66f3a0);

extern "C" u32 lifted_66f3f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230140), sizeof v); (u32)v; });  // @0_66f3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230144), sizeof v); (u32)v; });  // @1_66f3f0
  if ((ecx & ecx) == 0) goto L66f40f;  // @2_66f3f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f3f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230144), sizeof v); (u32)v; });  // @4_66f3f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230140), sizeof v); (u32)v; });  // @5_66f3f0
  goto L66f414;  // @6_66f3f0
  L66f40f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f3f0
  L66f414:;
  if ((eax & eax) == 0) goto L66f41d;  // @10_66f3f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f3f0
  goto L66f423;  // @12_66f3f0
  L66f41d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f3f0
  L66f423:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230140), &v, sizeof v); }  // @16_66f3f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230144), &v, sizeof v); }  // @17_66f3f0
  return eax;  // @18_66f3f0
}
PCREG(66f3f0, lifted_66f3f0);

extern "C" u32 lifted_66f4e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230300), sizeof v); (u32)v; });  // @0_66f4e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230304), sizeof v); (u32)v; });  // @1_66f4e0
  if ((ecx & ecx) == 0) goto L66f4ff;  // @2_66f4e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f4e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230304), sizeof v); (u32)v; });  // @4_66f4e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230300), sizeof v); (u32)v; });  // @5_66f4e0
  goto L66f504;  // @6_66f4e0
  L66f4ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f4e0
  L66f504:;
  if ((eax & eax) == 0) goto L66f50d;  // @10_66f4e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f4e0
  goto L66f513;  // @12_66f4e0
  L66f50d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f4e0
  L66f513:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230300), &v, sizeof v); }  // @16_66f4e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230304), &v, sizeof v); }  // @17_66f4e0
  return eax;  // @18_66f4e0
}
PCREG(66f4e0, lifted_66f4e0);

extern "C" u32 lifted_66f530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230416), sizeof v); (u32)v; });  // @0_66f530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230420), sizeof v); (u32)v; });  // @1_66f530
  if ((ecx & ecx) == 0) goto L66f54f;  // @2_66f530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230420), sizeof v); (u32)v; });  // @4_66f530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230416), sizeof v); (u32)v; });  // @5_66f530
  goto L66f554;  // @6_66f530
  L66f54f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f530
  L66f554:;
  if ((eax & eax) == 0) goto L66f55d;  // @10_66f530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f530
  goto L66f563;  // @12_66f530
  L66f55d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f530
  L66f563:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230416), &v, sizeof v); }  // @16_66f530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230420), &v, sizeof v); }  // @17_66f530
  return eax;  // @18_66f530
}
PCREG(66f530, lifted_66f530);

extern "C" u32 lifted_66f620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230520), sizeof v); (u32)v; });  // @0_66f620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230524), sizeof v); (u32)v; });  // @1_66f620
  if ((ecx & ecx) == 0) goto L66f63f;  // @2_66f620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230524), sizeof v); (u32)v; });  // @4_66f620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230520), sizeof v); (u32)v; });  // @5_66f620
  goto L66f644;  // @6_66f620
  L66f63f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f620
  L66f644:;
  if ((eax & eax) == 0) goto L66f64d;  // @10_66f620
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f620
  goto L66f653;  // @12_66f620
  L66f64d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f620
  L66f653:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230520), &v, sizeof v); }  // @16_66f620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230524), &v, sizeof v); }  // @17_66f620
  return eax;  // @18_66f620
}
PCREG(66f620, lifted_66f620);

extern "C" u32 lifted_66f670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230572), sizeof v); (u32)v; });  // @0_66f670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230576), sizeof v); (u32)v; });  // @1_66f670
  if ((ecx & ecx) == 0) goto L66f68f;  // @2_66f670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230576), sizeof v); (u32)v; });  // @4_66f670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230572), sizeof v); (u32)v; });  // @5_66f670
  goto L66f694;  // @6_66f670
  L66f68f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f670
  L66f694:;
  if ((eax & eax) == 0) goto L66f69d;  // @10_66f670
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f670
  goto L66f6a3;  // @12_66f670
  L66f69d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f670
  L66f6a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230572), &v, sizeof v); }  // @16_66f670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230576), &v, sizeof v); }  // @17_66f670
  return eax;  // @18_66f670
}
PCREG(66f670, lifted_66f670);

extern "C" u32 lifted_66f760(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230736), sizeof v); (u32)v; });  // @0_66f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230740), sizeof v); (u32)v; });  // @1_66f760
  if ((ecx & ecx) == 0) goto L66f77f;  // @2_66f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230740), sizeof v); (u32)v; });  // @4_66f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230736), sizeof v); (u32)v; });  // @5_66f760
  goto L66f784;  // @6_66f760
  L66f77f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f760
  L66f784:;
  if ((eax & eax) == 0) goto L66f78d;  // @10_66f760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f760
  goto L66f793;  // @12_66f760
  L66f78d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f760
  L66f793:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230736), &v, sizeof v); }  // @16_66f760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230740), &v, sizeof v); }  // @17_66f760
  return eax;  // @18_66f760
}
PCREG(66f760, lifted_66f760);

extern "C" u32 lifted_66f7b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230792), sizeof v); (u32)v; });  // @0_66f7b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230796), sizeof v); (u32)v; });  // @1_66f7b0
  if ((ecx & ecx) == 0) goto L66f7cf;  // @2_66f7b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f7b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230796), sizeof v); (u32)v; });  // @4_66f7b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230792), sizeof v); (u32)v; });  // @5_66f7b0
  goto L66f7d4;  // @6_66f7b0
  L66f7cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f7b0
  L66f7d4:;
  if ((eax & eax) == 0) goto L66f7dd;  // @10_66f7b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f7b0
  goto L66f7e3;  // @12_66f7b0
  L66f7dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f7b0
  L66f7e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230792), &v, sizeof v); }  // @16_66f7b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230796), &v, sizeof v); }  // @17_66f7b0
  return eax;  // @18_66f7b0
}
PCREG(66f7b0, lifted_66f7b0);

extern "C" u32 lifted_66f8a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230896), sizeof v); (u32)v; });  // @0_66f8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230900), sizeof v); (u32)v; });  // @1_66f8a0
  if ((ecx & ecx) == 0) goto L66f8bf;  // @2_66f8a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f8a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230900), sizeof v); (u32)v; });  // @4_66f8a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7230896), sizeof v); (u32)v; });  // @5_66f8a0
  goto L66f8c4;  // @6_66f8a0
  L66f8bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f8a0
  L66f8c4:;
  if ((eax & eax) == 0) goto L66f8cd;  // @10_66f8a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f8a0
  goto L66f8d3;  // @12_66f8a0
  L66f8cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f8a0
  L66f8d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230896), &v, sizeof v); }  // @16_66f8a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7230900), &v, sizeof v); }  // @17_66f8a0
  return eax;  // @18_66f8a0
}
PCREG(66f8a0, lifted_66f8a0);

extern "C" u32 lifted_66f8f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231052), sizeof v); (u32)v; });  // @0_66f8f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231056), sizeof v); (u32)v; });  // @1_66f8f0
  if ((ecx & ecx) == 0) goto L66f90f;  // @2_66f8f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f8f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231056), sizeof v); (u32)v; });  // @4_66f8f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231052), sizeof v); (u32)v; });  // @5_66f8f0
  goto L66f914;  // @6_66f8f0
  L66f90f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f8f0
  L66f914:;
  if ((eax & eax) == 0) goto L66f91d;  // @10_66f8f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f8f0
  goto L66f923;  // @12_66f8f0
  L66f91d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f8f0
  L66f923:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231052), &v, sizeof v); }  // @16_66f8f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231056), &v, sizeof v); }  // @17_66f8f0
  return eax;  // @18_66f8f0
}
PCREG(66f8f0, lifted_66f8f0);

extern "C" u32 lifted_66f9e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231104), sizeof v); (u32)v; });  // @0_66f9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231108), sizeof v); (u32)v; });  // @1_66f9e0
  if ((ecx & ecx) == 0) goto L66f9ff;  // @2_66f9e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66f9e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231108), sizeof v); (u32)v; });  // @4_66f9e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231104), sizeof v); (u32)v; });  // @5_66f9e0
  goto L66fa04;  // @6_66f9e0
  L66f9ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66f9e0
  L66fa04:;
  if ((eax & eax) == 0) goto L66fa0d;  // @10_66f9e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66f9e0
  goto L66fa13;  // @12_66f9e0
  L66fa0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66f9e0
  L66fa13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231104), &v, sizeof v); }  // @16_66f9e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231108), &v, sizeof v); }  // @17_66f9e0
  return eax;  // @18_66f9e0
}
PCREG(66f9e0, lifted_66f9e0);

extern "C" u32 lifted_66fa30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231324), sizeof v); (u32)v; });  // @0_66fa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231328), sizeof v); (u32)v; });  // @1_66fa30
  if ((ecx & ecx) == 0) goto L66fa4f;  // @2_66fa30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fa30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231328), sizeof v); (u32)v; });  // @4_66fa30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231324), sizeof v); (u32)v; });  // @5_66fa30
  goto L66fa54;  // @6_66fa30
  L66fa4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fa30
  L66fa54:;
  if ((eax & eax) == 0) goto L66fa5d;  // @10_66fa30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fa30
  goto L66fa63;  // @12_66fa30
  L66fa5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fa30
  L66fa63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231324), &v, sizeof v); }  // @16_66fa30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231328), &v, sizeof v); }  // @17_66fa30
  return eax;  // @18_66fa30
}
PCREG(66fa30, lifted_66fa30);

extern "C" u32 lifted_66fb20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231376), sizeof v); (u32)v; });  // @0_66fb20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231380), sizeof v); (u32)v; });  // @1_66fb20
  if ((ecx & ecx) == 0) goto L66fb3f;  // @2_66fb20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fb20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231380), sizeof v); (u32)v; });  // @4_66fb20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231376), sizeof v); (u32)v; });  // @5_66fb20
  goto L66fb44;  // @6_66fb20
  L66fb3f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fb20
  L66fb44:;
  if ((eax & eax) == 0) goto L66fb4d;  // @10_66fb20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fb20
  goto L66fb53;  // @12_66fb20
  L66fb4d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fb20
  L66fb53:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231376), &v, sizeof v); }  // @16_66fb20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231380), &v, sizeof v); }  // @17_66fb20
  return eax;  // @18_66fb20
}
PCREG(66fb20, lifted_66fb20);

extern "C" u32 lifted_66fb70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231432), sizeof v); (u32)v; });  // @0_66fb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231436), sizeof v); (u32)v; });  // @1_66fb70
  if ((ecx & ecx) == 0) goto L66fb8f;  // @2_66fb70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fb70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231436), sizeof v); (u32)v; });  // @4_66fb70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231432), sizeof v); (u32)v; });  // @5_66fb70
  goto L66fb94;  // @6_66fb70
  L66fb8f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fb70
  L66fb94:;
  if ((eax & eax) == 0) goto L66fb9d;  // @10_66fb70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fb70
  goto L66fba3;  // @12_66fb70
  L66fb9d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fb70
  L66fba3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231432), &v, sizeof v); }  // @16_66fb70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231436), &v, sizeof v); }  // @17_66fb70
  return eax;  // @18_66fb70
}
PCREG(66fb70, lifted_66fb70);

extern "C" u32 lifted_66fc60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231660), sizeof v); (u32)v; });  // @0_66fc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231664), sizeof v); (u32)v; });  // @1_66fc60
  if ((ecx & ecx) == 0) goto L66fc7f;  // @2_66fc60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fc60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231664), sizeof v); (u32)v; });  // @4_66fc60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231660), sizeof v); (u32)v; });  // @5_66fc60
  goto L66fc84;  // @6_66fc60
  L66fc7f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fc60
  L66fc84:;
  if ((eax & eax) == 0) goto L66fc8d;  // @10_66fc60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fc60
  goto L66fc93;  // @12_66fc60
  L66fc8d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fc60
  L66fc93:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231660), &v, sizeof v); }  // @16_66fc60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231664), &v, sizeof v); }  // @17_66fc60
  return eax;  // @18_66fc60
}
PCREG(66fc60, lifted_66fc60);

extern "C" u32 lifted_66fcb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231712), sizeof v); (u32)v; });  // @0_66fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231716), sizeof v); (u32)v; });  // @1_66fcb0
  if ((ecx & ecx) == 0) goto L66fccf;  // @2_66fcb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fcb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231716), sizeof v); (u32)v; });  // @4_66fcb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231712), sizeof v); (u32)v; });  // @5_66fcb0
  goto L66fcd4;  // @6_66fcb0
  L66fccf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fcb0
  L66fcd4:;
  if ((eax & eax) == 0) goto L66fcdd;  // @10_66fcb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fcb0
  goto L66fce3;  // @12_66fcb0
  L66fcdd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fcb0
  L66fce3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231712), &v, sizeof v); }  // @16_66fcb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231716), &v, sizeof v); }  // @17_66fcb0
  return eax;  // @18_66fcb0
}
PCREG(66fcb0, lifted_66fcb0);

extern "C" u32 lifted_66fda0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231820), sizeof v); (u32)v; });  // @0_66fda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231824), sizeof v); (u32)v; });  // @1_66fda0
  if ((ecx & ecx) == 0) goto L66fdbf;  // @2_66fda0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fda0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231824), sizeof v); (u32)v; });  // @4_66fda0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231820), sizeof v); (u32)v; });  // @5_66fda0
  goto L66fdc4;  // @6_66fda0
  L66fdbf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fda0
  L66fdc4:;
  if ((eax & eax) == 0) goto L66fdcd;  // @10_66fda0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fda0
  goto L66fdd3;  // @12_66fda0
  L66fdcd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fda0
  L66fdd3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231820), &v, sizeof v); }  // @16_66fda0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231824), &v, sizeof v); }  // @17_66fda0
  return eax;  // @18_66fda0
}
PCREG(66fda0, lifted_66fda0);

extern "C" u32 lifted_66fdf0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231872), sizeof v); (u32)v; });  // @0_66fdf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231876), sizeof v); (u32)v; });  // @1_66fdf0
  if ((ecx & ecx) == 0) goto L66fe0f;  // @2_66fdf0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fdf0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231876), sizeof v); (u32)v; });  // @4_66fdf0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7231872), sizeof v); (u32)v; });  // @5_66fdf0
  goto L66fe14;  // @6_66fdf0
  L66fe0f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fdf0
  L66fe14:;
  if ((eax & eax) == 0) goto L66fe1d;  // @10_66fdf0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fdf0
  goto L66fe23;  // @12_66fdf0
  L66fe1d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fdf0
  L66fe23:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231872), &v, sizeof v); }  // @16_66fdf0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7231876), &v, sizeof v); }  // @17_66fdf0
  return eax;  // @18_66fdf0
}
PCREG(66fdf0, lifted_66fdf0);

extern "C" u32 lifted_66fee0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232732), sizeof v); (u32)v; });  // @0_66fee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232736), sizeof v); (u32)v; });  // @1_66fee0
  if ((ecx & ecx) == 0) goto L66feff;  // @2_66fee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66fee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232736), sizeof v); (u32)v; });  // @4_66fee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232732), sizeof v); (u32)v; });  // @5_66fee0
  goto L66ff04;  // @6_66fee0
  L66feff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66fee0
  L66ff04:;
  if ((eax & eax) == 0) goto L66ff0d;  // @10_66fee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66fee0
  goto L66ff13;  // @12_66fee0
  L66ff0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66fee0
  L66ff13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232732), &v, sizeof v); }  // @16_66fee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232736), &v, sizeof v); }  // @17_66fee0
  return eax;  // @18_66fee0
}
PCREG(66fee0, lifted_66fee0);

extern "C" u32 lifted_66ff30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232676), sizeof v); (u32)v; });  // @0_66ff30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232680), sizeof v); (u32)v; });  // @1_66ff30
  if ((ecx & ecx) == 0) goto L66ff4f;  // @2_66ff30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_66ff30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232680), sizeof v); (u32)v; });  // @4_66ff30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232676), sizeof v); (u32)v; });  // @5_66ff30
  goto L66ff54;  // @6_66ff30
  L66ff4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_66ff30
  L66ff54:;
  if ((eax & eax) == 0) goto L66ff5d;  // @10_66ff30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_66ff30
  goto L66ff63;  // @12_66ff30
  L66ff5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_66ff30
  L66ff63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232676), &v, sizeof v); }  // @16_66ff30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232680), &v, sizeof v); }  // @17_66ff30
  return eax;  // @18_66ff30
}
PCREG(66ff30, lifted_66ff30);

extern "C" u32 lifted_670030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232516), sizeof v); (u32)v; });  // @0_670030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232520), sizeof v); (u32)v; });  // @1_670030
  if ((ecx & ecx) == 0) goto L67004f;  // @2_670030
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232520), sizeof v); (u32)v; });  // @4_670030
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232516), sizeof v); (u32)v; });  // @5_670030
  goto L670054;  // @6_670030
  L67004f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670030
  L670054:;
  if ((eax & eax) == 0) goto L67005d;  // @10_670030
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670030
  goto L670063;  // @12_670030
  L67005d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670030
  L670063:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232516), &v, sizeof v); }  // @16_670030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232520), &v, sizeof v); }  // @17_670030
  return eax;  // @18_670030
}
PCREG(670030, lifted_670030);

extern "C" u32 lifted_670080(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232464), sizeof v); (u32)v; });  // @0_670080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232468), sizeof v); (u32)v; });  // @1_670080
  if ((ecx & ecx) == 0) goto L67009f;  // @2_670080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232468), sizeof v); (u32)v; });  // @4_670080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232464), sizeof v); (u32)v; });  // @5_670080
  goto L6700a4;  // @6_670080
  L67009f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670080
  L6700a4:;
  if ((eax & eax) == 0) goto L6700ad;  // @10_670080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670080
  goto L6700b3;  // @12_670080
  L6700ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670080
  L6700b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232464), &v, sizeof v); }  // @16_670080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232468), &v, sizeof v); }  // @17_670080
  return eax;  // @18_670080
}
PCREG(670080, lifted_670080);

extern "C" u32 lifted_6700d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232568), sizeof v); (u32)v; });  // @0_6700d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232572), sizeof v); (u32)v; });  // @1_6700d0
  if ((ecx & ecx) == 0) goto L6700ef;  // @2_6700d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6700d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232572), sizeof v); (u32)v; });  // @4_6700d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232568), sizeof v); (u32)v; });  // @5_6700d0
  goto L6700f4;  // @6_6700d0
  L6700ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6700d0
  L6700f4:;
  if ((eax & eax) == 0) goto L6700fd;  // @10_6700d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6700d0
  goto L670103;  // @12_6700d0
  L6700fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6700d0
  L670103:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232568), &v, sizeof v); }  // @16_6700d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232572), &v, sizeof v); }  // @17_6700d0
  return eax;  // @18_6700d0
}
PCREG(6700d0, lifted_6700d0);

extern "C" u32 lifted_670170(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232308), sizeof v); (u32)v; });  // @0_670170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232312), sizeof v); (u32)v; });  // @1_670170
  if ((ecx & ecx) == 0) goto L67018f;  // @2_670170
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232312), sizeof v); (u32)v; });  // @4_670170
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232308), sizeof v); (u32)v; });  // @5_670170
  goto L670194;  // @6_670170
  L67018f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670170
  L670194:;
  if ((eax & eax) == 0) goto L67019d;  // @10_670170
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670170
  goto L6701a3;  // @12_670170
  L67019d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670170
  L6701a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232308), &v, sizeof v); }  // @16_670170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232312), &v, sizeof v); }  // @17_670170
  return eax;  // @18_670170
}
PCREG(670170, lifted_670170);

extern "C" u32 lifted_6701c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232204), sizeof v); (u32)v; });  // @0_6701c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232208), sizeof v); (u32)v; });  // @1_6701c0
  if ((ecx & ecx) == 0) goto L6701df;  // @2_6701c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6701c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232208), sizeof v); (u32)v; });  // @4_6701c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232204), sizeof v); (u32)v; });  // @5_6701c0
  goto L6701e4;  // @6_6701c0
  L6701df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6701c0
  L6701e4:;
  if ((eax & eax) == 0) goto L6701ed;  // @10_6701c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6701c0
  goto L6701f3;  // @12_6701c0
  L6701ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6701c0
  L6701f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232204), &v, sizeof v); }  // @16_6701c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232208), &v, sizeof v); }  // @17_6701c0
  return eax;  // @18_6701c0
}
PCREG(6701c0, lifted_6701c0);

extern "C" u32 lifted_670210(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232152), sizeof v); (u32)v; });  // @0_670210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232156), sizeof v); (u32)v; });  // @1_670210
  if ((ecx & ecx) == 0) goto L67022f;  // @2_670210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232156), sizeof v); (u32)v; });  // @4_670210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232152), sizeof v); (u32)v; });  // @5_670210
  goto L670234;  // @6_670210
  L67022f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670210
  L670234:;
  if ((eax & eax) == 0) goto L67023d;  // @10_670210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670210
  goto L670243;  // @12_670210
  L67023d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670210
  L670243:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232152), &v, sizeof v); }  // @16_670210
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232156), &v, sizeof v); }  // @17_670210
  return eax;  // @18_670210
}
PCREG(670210, lifted_670210);

extern "C" u32 lifted_6702b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232360), sizeof v); (u32)v; });  // @0_6702b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232364), sizeof v); (u32)v; });  // @1_6702b0
  if ((ecx & ecx) == 0) goto L6702cf;  // @2_6702b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6702b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232364), sizeof v); (u32)v; });  // @4_6702b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232360), sizeof v); (u32)v; });  // @5_6702b0
  goto L6702d4;  // @6_6702b0
  L6702cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6702b0
  L6702d4:;
  if ((eax & eax) == 0) goto L6702dd;  // @10_6702b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6702b0
  goto L6702e3;  // @12_6702b0
  L6702dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6702b0
  L6702e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232360), &v, sizeof v); }  // @16_6702b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232364), &v, sizeof v); }  // @17_6702b0
  return eax;  // @18_6702b0
}
PCREG(6702b0, lifted_6702b0);

extern "C" u32 lifted_670300(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232904), sizeof v); (u32)v; });  // @0_670300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232908), sizeof v); (u32)v; });  // @1_670300
  if ((ecx & ecx) == 0) goto L67031f;  // @2_670300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232908), sizeof v); (u32)v; });  // @4_670300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232904), sizeof v); (u32)v; });  // @5_670300
  goto L670324;  // @6_670300
  L67031f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670300
  L670324:;
  if ((eax & eax) == 0) goto L67032d;  // @10_670300
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670300
  goto L670333;  // @12_670300
  L67032d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670300
  L670333:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232904), &v, sizeof v); }  // @16_670300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232908), &v, sizeof v); }  // @17_670300
  return eax;  // @18_670300
}
PCREG(670300, lifted_670300);

extern "C" u32 lifted_670350(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232956), sizeof v); (u32)v; });  // @0_670350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232960), sizeof v); (u32)v; });  // @1_670350
  if ((ecx & ecx) == 0) goto L67036f;  // @2_670350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232960), sizeof v); (u32)v; });  // @4_670350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7232956), sizeof v); (u32)v; });  // @5_670350
  goto L670374;  // @6_670350
  L67036f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670350
  L670374:;
  if ((eax & eax) == 0) goto L67037d;  // @10_670350
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670350
  goto L670383;  // @12_670350
  L67037d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670350
  L670383:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232956), &v, sizeof v); }  // @16_670350
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7232960), &v, sizeof v); }  // @17_670350
  return eax;  // @18_670350
}
PCREG(670350, lifted_670350);

extern "C" u32 lifted_6703f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233128), sizeof v); (u32)v; });  // @0_6703f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233132), sizeof v); (u32)v; });  // @1_6703f0
  if ((ecx & ecx) == 0) goto L67040f;  // @2_6703f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6703f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233132), sizeof v); (u32)v; });  // @4_6703f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233128), sizeof v); (u32)v; });  // @5_6703f0
  goto L670414;  // @6_6703f0
  L67040f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6703f0
  L670414:;
  if ((eax & eax) == 0) goto L67041d;  // @10_6703f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6703f0
  goto L670423;  // @12_6703f0
  L67041d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6703f0
  L670423:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233128), &v, sizeof v); }  // @16_6703f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233132), &v, sizeof v); }  // @17_6703f0
  return eax;  // @18_6703f0
}
PCREG(6703f0, lifted_6703f0);

extern "C" u32 lifted_670440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233180), sizeof v); (u32)v; });  // @0_670440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233184), sizeof v); (u32)v; });  // @1_670440
  if ((ecx & ecx) == 0) goto L67045f;  // @2_670440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233184), sizeof v); (u32)v; });  // @4_670440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233180), sizeof v); (u32)v; });  // @5_670440
  goto L670464;  // @6_670440
  L67045f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670440
  L670464:;
  if ((eax & eax) == 0) goto L67046d;  // @10_670440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670440
  goto L670473;  // @12_670440
  L67046d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670440
  L670473:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233180), &v, sizeof v); }  // @16_670440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233184), &v, sizeof v); }  // @17_670440
  return eax;  // @18_670440
}
PCREG(670440, lifted_670440);

extern "C" u32 lifted_670490(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233236), sizeof v); (u32)v; });  // @0_670490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233240), sizeof v); (u32)v; });  // @1_670490
  if ((ecx & ecx) == 0) goto L6704af;  // @2_670490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233240), sizeof v); (u32)v; });  // @4_670490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233236), sizeof v); (u32)v; });  // @5_670490
  goto L6704b4;  // @6_670490
  L6704af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670490
  L6704b4:;
  if ((eax & eax) == 0) goto L6704bd;  // @10_670490
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670490
  goto L6704c3;  // @12_670490
  L6704bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670490
  L6704c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233236), &v, sizeof v); }  // @16_670490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233240), &v, sizeof v); }  // @17_670490
  return eax;  // @18_670490
}
PCREG(670490, lifted_670490);

extern "C" u32 lifted_670530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233520), sizeof v); (u32)v; });  // @0_670530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233524), sizeof v); (u32)v; });  // @1_670530
  if ((ecx & ecx) == 0) goto L67054f;  // @2_670530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233524), sizeof v); (u32)v; });  // @4_670530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233520), sizeof v); (u32)v; });  // @5_670530
  goto L670554;  // @6_670530
  L67054f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670530
  L670554:;
  if ((eax & eax) == 0) goto L67055d;  // @10_670530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670530
  goto L670563;  // @12_670530
  L67055d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670530
  L670563:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233520), &v, sizeof v); }  // @16_670530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233524), &v, sizeof v); }  // @17_670530
  return eax;  // @18_670530
}
PCREG(670530, lifted_670530);

extern "C" u32 lifted_670580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233628), sizeof v); (u32)v; });  // @0_670580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233632), sizeof v); (u32)v; });  // @1_670580
  if ((ecx & ecx) == 0) goto L67059f;  // @2_670580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233632), sizeof v); (u32)v; });  // @4_670580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233628), sizeof v); (u32)v; });  // @5_670580
  goto L6705a4;  // @6_670580
  L67059f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670580
  L6705a4:;
  if ((eax & eax) == 0) goto L6705ad;  // @10_670580
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670580
  goto L6705b3;  // @12_670580
  L6705ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670580
  L6705b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233628), &v, sizeof v); }  // @16_670580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233632), &v, sizeof v); }  // @17_670580
  return eax;  // @18_670580
}
PCREG(670580, lifted_670580);

extern "C" u32 lifted_6705d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233684), sizeof v); (u32)v; });  // @0_6705d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233688), sizeof v); (u32)v; });  // @1_6705d0
  if ((ecx & ecx) == 0) goto L6705ef;  // @2_6705d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6705d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233688), sizeof v); (u32)v; });  // @4_6705d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7233684), sizeof v); (u32)v; });  // @5_6705d0
  goto L6705f4;  // @6_6705d0
  L6705ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6705d0
  L6705f4:;
  if ((eax & eax) == 0) goto L6705fd;  // @10_6705d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6705d0
  goto L670603;  // @12_6705d0
  L6705fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6705d0
  L670603:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233684), &v, sizeof v); }  // @16_6705d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7233688), &v, sizeof v); }  // @17_6705d0
  return eax;  // @18_6705d0
}
PCREG(6705d0, lifted_6705d0);

extern "C" u32 lifted_670670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234264), sizeof v); (u32)v; });  // @0_670670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234268), sizeof v); (u32)v; });  // @1_670670
  if ((ecx & ecx) == 0) goto L67068f;  // @2_670670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234268), sizeof v); (u32)v; });  // @4_670670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234264), sizeof v); (u32)v; });  // @5_670670
  goto L670694;  // @6_670670
  L67068f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670670
  L670694:;
  if ((eax & eax) == 0) goto L67069d;  // @10_670670
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670670
  goto L6706a3;  // @12_670670
  L67069d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670670
  L6706a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234264), &v, sizeof v); }  // @16_670670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234268), &v, sizeof v); }  // @17_670670
  return eax;  // @18_670670
}
PCREG(670670, lifted_670670);

extern "C" u32 lifted_6706c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234152), sizeof v); (u32)v; });  // @0_6706c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234156), sizeof v); (u32)v; });  // @1_6706c0
  if ((ecx & ecx) == 0) goto L6706df;  // @2_6706c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6706c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234156), sizeof v); (u32)v; });  // @4_6706c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234152), sizeof v); (u32)v; });  // @5_6706c0
  goto L6706e4;  // @6_6706c0
  L6706df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6706c0
  L6706e4:;
  if ((eax & eax) == 0) goto L6706ed;  // @10_6706c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6706c0
  goto L6706f3;  // @12_6706c0
  L6706ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6706c0
  L6706f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234152), &v, sizeof v); }  // @16_6706c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234156), &v, sizeof v); }  // @17_6706c0
  return eax;  // @18_6706c0
}
PCREG(6706c0, lifted_6706c0);

extern "C" u32 lifted_670710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234096), sizeof v); (u32)v; });  // @0_670710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234100), sizeof v); (u32)v; });  // @1_670710
  if ((ecx & ecx) == 0) goto L67072f;  // @2_670710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234100), sizeof v); (u32)v; });  // @4_670710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234096), sizeof v); (u32)v; });  // @5_670710
  goto L670734;  // @6_670710
  L67072f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670710
  L670734:;
  if ((eax & eax) == 0) goto L67073d;  // @10_670710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670710
  goto L670743;  // @12_670710
  L67073d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670710
  L670743:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234096), &v, sizeof v); }  // @16_670710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234100), &v, sizeof v); }  // @17_670710
  return eax;  // @18_670710
}
PCREG(670710, lifted_670710);

extern "C" u32 lifted_6707b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234320), sizeof v); (u32)v; });  // @0_6707b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234324), sizeof v); (u32)v; });  // @1_6707b0
  if ((ecx & ecx) == 0) goto L6707cf;  // @2_6707b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6707b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234324), sizeof v); (u32)v; });  // @4_6707b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234320), sizeof v); (u32)v; });  // @5_6707b0
  goto L6707d4;  // @6_6707b0
  L6707cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6707b0
  L6707d4:;
  if ((eax & eax) == 0) goto L6707dd;  // @10_6707b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6707b0
  goto L6707e3;  // @12_6707b0
  L6707dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6707b0
  L6707e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234320), &v, sizeof v); }  // @16_6707b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234324), &v, sizeof v); }  // @17_6707b0
  return eax;  // @18_6707b0
}
PCREG(6707b0, lifted_6707b0);

extern "C" u32 lifted_670800(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234396), sizeof v); (u32)v; });  // @0_670800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234400), sizeof v); (u32)v; });  // @1_670800
  if ((ecx & ecx) == 0) goto L67081f;  // @2_670800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234400), sizeof v); (u32)v; });  // @4_670800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234396), sizeof v); (u32)v; });  // @5_670800
  goto L670824;  // @6_670800
  L67081f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670800
  L670824:;
  if ((eax & eax) == 0) goto L67082d;  // @10_670800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670800
  goto L670833;  // @12_670800
  L67082d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670800
  L670833:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234396), &v, sizeof v); }  // @16_670800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234400), &v, sizeof v); }  // @17_670800
  return eax;  // @18_670800
}
PCREG(670800, lifted_670800);

extern "C" u32 lifted_670850(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234452), sizeof v); (u32)v; });  // @0_670850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234456), sizeof v); (u32)v; });  // @1_670850
  if ((ecx & ecx) == 0) goto L67086f;  // @2_670850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234456), sizeof v); (u32)v; });  // @4_670850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234452), sizeof v); (u32)v; });  // @5_670850
  goto L670874;  // @6_670850
  L67086f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670850
  L670874:;
  if ((eax & eax) == 0) goto L67087d;  // @10_670850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670850
  goto L670883;  // @12_670850
  L67087d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670850
  L670883:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234452), &v, sizeof v); }  // @16_670850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234456), &v, sizeof v); }  // @17_670850
  return eax;  // @18_670850
}
PCREG(670850, lifted_670850);

extern "C" u32 lifted_6708f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234564), sizeof v); (u32)v; });  // @0_6708f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234568), sizeof v); (u32)v; });  // @1_6708f0
  if ((ecx & ecx) == 0) goto L67090f;  // @2_6708f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6708f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234568), sizeof v); (u32)v; });  // @4_6708f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234564), sizeof v); (u32)v; });  // @5_6708f0
  goto L670914;  // @6_6708f0
  L67090f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6708f0
  L670914:;
  if ((eax & eax) == 0) goto L67091d;  // @10_6708f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6708f0
  goto L670923;  // @12_6708f0
  L67091d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6708f0
  L670923:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234564), &v, sizeof v); }  // @16_6708f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234568), &v, sizeof v); }  // @17_6708f0
  return eax;  // @18_6708f0
}
PCREG(6708f0, lifted_6708f0);

extern "C" u32 lifted_670940(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234620), sizeof v); (u32)v; });  // @0_670940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234624), sizeof v); (u32)v; });  // @1_670940
  if ((ecx & ecx) == 0) goto L67095f;  // @2_670940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234624), sizeof v); (u32)v; });  // @4_670940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234620), sizeof v); (u32)v; });  // @5_670940
  goto L670964;  // @6_670940
  L67095f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670940
  L670964:;
  if ((eax & eax) == 0) goto L67096d;  // @10_670940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670940
  goto L670973;  // @12_670940
  L67096d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670940
  L670973:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234620), &v, sizeof v); }  // @16_670940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234624), &v, sizeof v); }  // @17_670940
  return eax;  // @18_670940
}
PCREG(670940, lifted_670940);

extern "C" u32 lifted_670990(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234676), sizeof v); (u32)v; });  // @0_670990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234680), sizeof v); (u32)v; });  // @1_670990
  if ((ecx & ecx) == 0) goto L6709af;  // @2_670990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234680), sizeof v); (u32)v; });  // @4_670990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234676), sizeof v); (u32)v; });  // @5_670990
  goto L6709b4;  // @6_670990
  L6709af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670990
  L6709b4:;
  if ((eax & eax) == 0) goto L6709bd;  // @10_670990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670990
  goto L6709c3;  // @12_670990
  L6709bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670990
  L6709c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234676), &v, sizeof v); }  // @16_670990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234680), &v, sizeof v); }  // @17_670990
  return eax;  // @18_670990
}
PCREG(670990, lifted_670990);

extern "C" u32 lifted_670a30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234732), sizeof v); (u32)v; });  // @0_670a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234736), sizeof v); (u32)v; });  // @1_670a30
  if ((ecx & ecx) == 0) goto L670a4f;  // @2_670a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234736), sizeof v); (u32)v; });  // @4_670a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234732), sizeof v); (u32)v; });  // @5_670a30
  goto L670a54;  // @6_670a30
  L670a4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670a30
  L670a54:;
  if ((eax & eax) == 0) goto L670a5d;  // @10_670a30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670a30
  goto L670a63;  // @12_670a30
  L670a5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670a30
  L670a63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234732), &v, sizeof v); }  // @16_670a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234736), &v, sizeof v); }  // @17_670a30
  return eax;  // @18_670a30
}
PCREG(670a30, lifted_670a30);

extern "C" u32 lifted_670a80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234844), sizeof v); (u32)v; });  // @0_670a80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234848), sizeof v); (u32)v; });  // @1_670a80
  if ((ecx & ecx) == 0) goto L670a9f;  // @2_670a80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670a80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234848), sizeof v); (u32)v; });  // @4_670a80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234844), sizeof v); (u32)v; });  // @5_670a80
  goto L670aa4;  // @6_670a80
  L670a9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670a80
  L670aa4:;
  if ((eax & eax) == 0) goto L670aad;  // @10_670a80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670a80
  goto L670ab3;  // @12_670a80
  L670aad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670a80
  L670ab3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234844), &v, sizeof v); }  // @16_670a80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234848), &v, sizeof v); }  // @17_670a80
  return eax;  // @18_670a80
}
PCREG(670a80, lifted_670a80);

extern "C" u32 lifted_670ad0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234900), sizeof v); (u32)v; });  // @0_670ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234904), sizeof v); (u32)v; });  // @1_670ad0
  if ((ecx & ecx) == 0) goto L670aef;  // @2_670ad0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234904), sizeof v); (u32)v; });  // @4_670ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7234900), sizeof v); (u32)v; });  // @5_670ad0
  goto L670af4;  // @6_670ad0
  L670aef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670ad0
  L670af4:;
  if ((eax & eax) == 0) goto L670afd;  // @10_670ad0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670ad0
  goto L670b03;  // @12_670ad0
  L670afd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670ad0
  L670b03:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234900), &v, sizeof v); }  // @16_670ad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7234904), &v, sizeof v); }  // @17_670ad0
  return eax;  // @18_670ad0
}
PCREG(670ad0, lifted_670ad0);

extern "C" u32 lifted_670b70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235168), sizeof v); (u32)v; });  // @0_670b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235172), sizeof v); (u32)v; });  // @1_670b70
  if ((ecx & ecx) == 0) goto L670b8f;  // @2_670b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235172), sizeof v); (u32)v; });  // @4_670b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235168), sizeof v); (u32)v; });  // @5_670b70
  goto L670b94;  // @6_670b70
  L670b8f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670b70
  L670b94:;
  if ((eax & eax) == 0) goto L670b9d;  // @10_670b70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670b70
  goto L670ba3;  // @12_670b70
  L670b9d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670b70
  L670ba3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235168), &v, sizeof v); }  // @16_670b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235172), &v, sizeof v); }  // @17_670b70
  return eax;  // @18_670b70
}
PCREG(670b70, lifted_670b70);

extern "C" u32 lifted_670bc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235224), sizeof v); (u32)v; });  // @0_670bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235228), sizeof v); (u32)v; });  // @1_670bc0
  if ((ecx & ecx) == 0) goto L670bdf;  // @2_670bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235228), sizeof v); (u32)v; });  // @4_670bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235224), sizeof v); (u32)v; });  // @5_670bc0
  goto L670be4;  // @6_670bc0
  L670bdf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670bc0
  L670be4:;
  if ((eax & eax) == 0) goto L670bed;  // @10_670bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670bc0
  goto L670bf3;  // @12_670bc0
  L670bed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670bc0
  L670bf3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235224), &v, sizeof v); }  // @16_670bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235228), &v, sizeof v); }  // @17_670bc0
  return eax;  // @18_670bc0
}
PCREG(670bc0, lifted_670bc0);

extern "C" u32 lifted_670c10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235280), sizeof v); (u32)v; });  // @0_670c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235284), sizeof v); (u32)v; });  // @1_670c10
  if ((ecx & ecx) == 0) goto L670c2f;  // @2_670c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235284), sizeof v); (u32)v; });  // @4_670c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235280), sizeof v); (u32)v; });  // @5_670c10
  goto L670c34;  // @6_670c10
  L670c2f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670c10
  L670c34:;
  if ((eax & eax) == 0) goto L670c3d;  // @10_670c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670c10
  goto L670c43;  // @12_670c10
  L670c3d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670c10
  L670c43:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235280), &v, sizeof v); }  // @16_670c10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235284), &v, sizeof v); }  // @17_670c10
  return eax;  // @18_670c10
}
PCREG(670c10, lifted_670c10);

extern "C" u32 lifted_670cb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236580), sizeof v); (u32)v; });  // @0_670cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236584), sizeof v); (u32)v; });  // @1_670cb0
  if ((ecx & ecx) == 0) goto L670ccf;  // @2_670cb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236584), sizeof v); (u32)v; });  // @4_670cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236580), sizeof v); (u32)v; });  // @5_670cb0
  goto L670cd4;  // @6_670cb0
  L670ccf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670cb0
  L670cd4:;
  if ((eax & eax) == 0) goto L670cdd;  // @10_670cb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670cb0
  goto L670ce3;  // @12_670cb0
  L670cdd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670cb0
  L670ce3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236580), &v, sizeof v); }  // @16_670cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236584), &v, sizeof v); }  // @17_670cb0
  return eax;  // @18_670cb0
}
PCREG(670cb0, lifted_670cb0);

extern "C" u32 lifted_670d00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236468), sizeof v); (u32)v; });  // @0_670d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236472), sizeof v); (u32)v; });  // @1_670d00
  if ((ecx & ecx) == 0) goto L670d1f;  // @2_670d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236472), sizeof v); (u32)v; });  // @4_670d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236468), sizeof v); (u32)v; });  // @5_670d00
  goto L670d24;  // @6_670d00
  L670d1f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670d00
  L670d24:;
  if ((eax & eax) == 0) goto L670d2d;  // @10_670d00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670d00
  goto L670d33;  // @12_670d00
  L670d2d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670d00
  L670d33:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236468), &v, sizeof v); }  // @16_670d00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236472), &v, sizeof v); }  // @17_670d00
  return eax;  // @18_670d00
}
PCREG(670d00, lifted_670d00);

extern "C" u32 lifted_670d50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236412), sizeof v); (u32)v; });  // @0_670d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236416), sizeof v); (u32)v; });  // @1_670d50
  if ((ecx & ecx) == 0) goto L670d6f;  // @2_670d50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236416), sizeof v); (u32)v; });  // @4_670d50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236412), sizeof v); (u32)v; });  // @5_670d50
  goto L670d74;  // @6_670d50
  L670d6f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670d50
  L670d74:;
  if ((eax & eax) == 0) goto L670d7d;  // @10_670d50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670d50
  goto L670d83;  // @12_670d50
  L670d7d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670d50
  L670d83:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236412), &v, sizeof v); }  // @16_670d50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236416), &v, sizeof v); }  // @17_670d50
  return eax;  // @18_670d50
}
PCREG(670d50, lifted_670d50);

extern "C" u32 lifted_670df0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236356), sizeof v); (u32)v; });  // @0_670df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236360), sizeof v); (u32)v; });  // @1_670df0
  if ((ecx & ecx) == 0) goto L670e0f;  // @2_670df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236360), sizeof v); (u32)v; });  // @4_670df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236356), sizeof v); (u32)v; });  // @5_670df0
  goto L670e14;  // @6_670df0
  L670e0f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670df0
  L670e14:;
  if ((eax & eax) == 0) goto L670e1d;  // @10_670df0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670df0
  goto L670e23;  // @12_670df0
  L670e1d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670df0
  L670e23:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236356), &v, sizeof v); }  // @16_670df0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236360), &v, sizeof v); }  // @17_670df0
  return eax;  // @18_670df0
}
PCREG(670df0, lifted_670df0);

extern "C" u32 lifted_670e40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236132), sizeof v); (u32)v; });  // @0_670e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236136), sizeof v); (u32)v; });  // @1_670e40
  if ((ecx & ecx) == 0) goto L670e5f;  // @2_670e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236136), sizeof v); (u32)v; });  // @4_670e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236132), sizeof v); (u32)v; });  // @5_670e40
  goto L670e64;  // @6_670e40
  L670e5f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670e40
  L670e64:;
  if ((eax & eax) == 0) goto L670e6d;  // @10_670e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670e40
  goto L670e73;  // @12_670e40
  L670e6d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670e40
  L670e73:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236132), &v, sizeof v); }  // @16_670e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236136), &v, sizeof v); }  // @17_670e40
  return eax;  // @18_670e40
}
PCREG(670e40, lifted_670e40);

extern "C" u32 lifted_670e90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236188), sizeof v); (u32)v; });  // @0_670e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236192), sizeof v); (u32)v; });  // @1_670e90
  if ((ecx & ecx) == 0) goto L670eaf;  // @2_670e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236192), sizeof v); (u32)v; });  // @4_670e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236188), sizeof v); (u32)v; });  // @5_670e90
  goto L670eb4;  // @6_670e90
  L670eaf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670e90
  L670eb4:;
  if ((eax & eax) == 0) goto L670ebd;  // @10_670e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670e90
  goto L670ec3;  // @12_670e90
  L670ebd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670e90
  L670ec3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236188), &v, sizeof v); }  // @16_670e90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236192), &v, sizeof v); }  // @17_670e90
  return eax;  // @18_670e90
}
PCREG(670e90, lifted_670e90);

extern "C" u32 lifted_670f30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235684), sizeof v); (u32)v; });  // @0_670f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235688), sizeof v); (u32)v; });  // @1_670f30
  if ((ecx & ecx) == 0) goto L670f4f;  // @2_670f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235688), sizeof v); (u32)v; });  // @4_670f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235684), sizeof v); (u32)v; });  // @5_670f30
  goto L670f54;  // @6_670f30
  L670f4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670f30
  L670f54:;
  if ((eax & eax) == 0) goto L670f5d;  // @10_670f30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670f30
  goto L670f63;  // @12_670f30
  L670f5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670f30
  L670f63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235684), &v, sizeof v); }  // @16_670f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235688), &v, sizeof v); }  // @17_670f30
  return eax;  // @18_670f30
}
PCREG(670f30, lifted_670f30);

extern "C" u32 lifted_670f80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235796), sizeof v); (u32)v; });  // @0_670f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235800), sizeof v); (u32)v; });  // @1_670f80
  if ((ecx & ecx) == 0) goto L670f9f;  // @2_670f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235800), sizeof v); (u32)v; });  // @4_670f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235796), sizeof v); (u32)v; });  // @5_670f80
  goto L670fa4;  // @6_670f80
  L670f9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670f80
  L670fa4:;
  if ((eax & eax) == 0) goto L670fad;  // @10_670f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670f80
  goto L670fb3;  // @12_670f80
  L670fad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670f80
  L670fb3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235796), &v, sizeof v); }  // @16_670f80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235800), &v, sizeof v); }  // @17_670f80
  return eax;  // @18_670f80
}
PCREG(670f80, lifted_670f80);

extern "C" u32 lifted_670fe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236244), sizeof v); (u32)v; });  // @0_670fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236248), sizeof v); (u32)v; });  // @1_670fe0
  if ((ecx & ecx) == 0) goto L670fff;  // @2_670fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_670fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236248), sizeof v); (u32)v; });  // @4_670fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236244), sizeof v); (u32)v; });  // @5_670fe0
  goto L671004;  // @6_670fe0
  L670fff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_670fe0
  L671004:;
  if ((eax & eax) == 0) goto L67100d;  // @10_670fe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_670fe0
  goto L671013;  // @12_670fe0
  L67100d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_670fe0
  L671013:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236244), &v, sizeof v); }  // @16_670fe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236248), &v, sizeof v); }  // @17_670fe0
  return eax;  // @18_670fe0
}
PCREG(670fe0, lifted_670fe0);

extern "C" u32 lifted_671030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236300), sizeof v); (u32)v; });  // @0_671030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236304), sizeof v); (u32)v; });  // @1_671030
  if ((ecx & ecx) == 0) goto L67104f;  // @2_671030
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236304), sizeof v); (u32)v; });  // @4_671030
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236300), sizeof v); (u32)v; });  // @5_671030
  goto L671054;  // @6_671030
  L67104f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671030
  L671054:;
  if ((eax & eax) == 0) goto L67105d;  // @10_671030
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671030
  goto L671063;  // @12_671030
  L67105d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671030
  L671063:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236300), &v, sizeof v); }  // @16_671030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236304), &v, sizeof v); }  // @17_671030
  return eax;  // @18_671030
}
PCREG(671030, lifted_671030);

extern "C" u32 lifted_671080(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236020), sizeof v); (u32)v; });  // @0_671080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236024), sizeof v); (u32)v; });  // @1_671080
  if ((ecx & ecx) == 0) goto L67109f;  // @2_671080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236024), sizeof v); (u32)v; });  // @4_671080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236020), sizeof v); (u32)v; });  // @5_671080
  goto L6710a4;  // @6_671080
  L67109f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671080
  L6710a4:;
  if ((eax & eax) == 0) goto L6710ad;  // @10_671080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671080
  goto L6710b3;  // @12_671080
  L6710ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671080
  L6710b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236020), &v, sizeof v); }  // @16_671080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236024), &v, sizeof v); }  // @17_671080
  return eax;  // @18_671080
}
PCREG(671080, lifted_671080);

extern "C" u32 lifted_6710d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236076), sizeof v); (u32)v; });  // @0_6710d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236080), sizeof v); (u32)v; });  // @1_6710d0
  if ((ecx & ecx) == 0) goto L6710ef;  // @2_6710d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6710d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236080), sizeof v); (u32)v; });  // @4_6710d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236076), sizeof v); (u32)v; });  // @5_6710d0
  goto L6710f4;  // @6_6710d0
  L6710ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6710d0
  L6710f4:;
  if ((eax & eax) == 0) goto L6710fd;  // @10_6710d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6710d0
  goto L671103;  // @12_6710d0
  L6710fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6710d0
  L671103:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236076), &v, sizeof v); }  // @16_6710d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236080), &v, sizeof v); }  // @17_6710d0
  return eax;  // @18_6710d0
}
PCREG(6710d0, lifted_6710d0);

extern "C" u32 lifted_671120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235908), sizeof v); (u32)v; });  // @0_671120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235912), sizeof v); (u32)v; });  // @1_671120
  if ((ecx & ecx) == 0) goto L67113f;  // @2_671120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235912), sizeof v); (u32)v; });  // @4_671120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235908), sizeof v); (u32)v; });  // @5_671120
  goto L671144;  // @6_671120
  L67113f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671120
  L671144:;
  if ((eax & eax) == 0) goto L67114d;  // @10_671120
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671120
  goto L671153;  // @12_671120
  L67114d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671120
  L671153:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235908), &v, sizeof v); }  // @16_671120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235912), &v, sizeof v); }  // @17_671120
  return eax;  // @18_671120
}
PCREG(671120, lifted_671120);

extern "C" u32 lifted_671170(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235964), sizeof v); (u32)v; });  // @0_671170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235968), sizeof v); (u32)v; });  // @1_671170
  if ((ecx & ecx) == 0) goto L67118f;  // @2_671170
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235968), sizeof v); (u32)v; });  // @4_671170
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235964), sizeof v); (u32)v; });  // @5_671170
  goto L671194;  // @6_671170
  L67118f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671170
  L671194:;
  if ((eax & eax) == 0) goto L67119d;  // @10_671170
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671170
  goto L6711a3;  // @12_671170
  L67119d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671170
  L6711a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235964), &v, sizeof v); }  // @16_671170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235968), &v, sizeof v); }  // @17_671170
  return eax;  // @18_671170
}
PCREG(671170, lifted_671170);

extern "C" u32 lifted_6711c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235852), sizeof v); (u32)v; });  // @0_6711c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235856), sizeof v); (u32)v; });  // @1_6711c0
  if ((ecx & ecx) == 0) goto L6711df;  // @2_6711c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6711c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235856), sizeof v); (u32)v; });  // @4_6711c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235852), sizeof v); (u32)v; });  // @5_6711c0
  goto L6711e4;  // @6_6711c0
  L6711df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6711c0
  L6711e4:;
  if ((eax & eax) == 0) goto L6711ed;  // @10_6711c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6711c0
  goto L6711f3;  // @12_6711c0
  L6711ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6711c0
  L6711f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235852), &v, sizeof v); }  // @16_6711c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235856), &v, sizeof v); }  // @17_6711c0
  return eax;  // @18_6711c0
}
PCREG(6711c0, lifted_6711c0);

extern "C" u32 lifted_671210(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235624), sizeof v); (u32)v; });  // @0_671210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235628), sizeof v); (u32)v; });  // @1_671210
  if ((ecx & ecx) == 0) goto L67122f;  // @2_671210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235628), sizeof v); (u32)v; });  // @4_671210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7235624), sizeof v); (u32)v; });  // @5_671210
  goto L671234;  // @6_671210
  L67122f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671210
  L671234:;
  if ((eax & eax) == 0) goto L67123d;  // @10_671210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671210
  goto L671243;  // @12_671210
  L67123d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671210
  L671243:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235624), &v, sizeof v); }  // @16_671210
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7235628), &v, sizeof v); }  // @17_671210
  return eax;  // @18_671210
}
PCREG(671210, lifted_671210);

extern "C" u32 lifted_671260(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236524), sizeof v); (u32)v; });  // @0_671260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236528), sizeof v); (u32)v; });  // @1_671260
  if ((ecx & ecx) == 0) goto L67127f;  // @2_671260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236528), sizeof v); (u32)v; });  // @4_671260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236524), sizeof v); (u32)v; });  // @5_671260
  goto L671284;  // @6_671260
  L67127f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671260
  L671284:;
  if ((eax & eax) == 0) goto L67128d;  // @10_671260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671260
  goto L671293;  // @12_671260
  L67128d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671260
  L671293:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236524), &v, sizeof v); }  // @16_671260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236528), &v, sizeof v); }  // @17_671260
  return eax;  // @18_671260
}
PCREG(671260, lifted_671260);

extern "C" u32 lifted_6712b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236696), sizeof v); (u32)v; });  // @0_6712b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236700), sizeof v); (u32)v; });  // @1_6712b0
  if ((ecx & ecx) == 0) goto L6712cf;  // @2_6712b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6712b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236700), sizeof v); (u32)v; });  // @4_6712b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236696), sizeof v); (u32)v; });  // @5_6712b0
  goto L6712d4;  // @6_6712b0
  L6712cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6712b0
  L6712d4:;
  if ((eax & eax) == 0) goto L6712dd;  // @10_6712b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6712b0
  goto L6712e3;  // @12_6712b0
  L6712dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6712b0
  L6712e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236696), &v, sizeof v); }  // @16_6712b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236700), &v, sizeof v); }  // @17_6712b0
  return eax;  // @18_6712b0
}
PCREG(6712b0, lifted_6712b0);

extern "C" u32 lifted_671300(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236808), sizeof v); (u32)v; });  // @0_671300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236812), sizeof v); (u32)v; });  // @1_671300
  if ((ecx & ecx) == 0) goto L67131f;  // @2_671300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236812), sizeof v); (u32)v; });  // @4_671300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236808), sizeof v); (u32)v; });  // @5_671300
  goto L671324;  // @6_671300
  L67131f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671300
  L671324:;
  if ((eax & eax) == 0) goto L67132d;  // @10_671300
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671300
  goto L671333;  // @12_671300
  L67132d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671300
  L671333:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236808), &v, sizeof v); }  // @16_671300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236812), &v, sizeof v); }  // @17_671300
  return eax;  // @18_671300
}
PCREG(671300, lifted_671300);

extern "C" u32 lifted_671350(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236752), sizeof v); (u32)v; });  // @0_671350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236756), sizeof v); (u32)v; });  // @1_671350
  if ((ecx & ecx) == 0) goto L67136f;  // @2_671350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236756), sizeof v); (u32)v; });  // @4_671350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236752), sizeof v); (u32)v; });  // @5_671350
  goto L671374;  // @6_671350
  L67136f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671350
  L671374:;
  if ((eax & eax) == 0) goto L67137d;  // @10_671350
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671350
  goto L671383;  // @12_671350
  L67137d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671350
  L671383:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236752), &v, sizeof v); }  // @16_671350
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236756), &v, sizeof v); }  // @17_671350
  return eax;  // @18_671350
}
PCREG(671350, lifted_671350);

extern "C" u32 lifted_6713a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236864), sizeof v); (u32)v; });  // @0_6713a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236868), sizeof v); (u32)v; });  // @1_6713a0
  if ((ecx & ecx) == 0) goto L6713bf;  // @2_6713a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6713a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236868), sizeof v); (u32)v; });  // @4_6713a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236864), sizeof v); (u32)v; });  // @5_6713a0
  goto L6713c4;  // @6_6713a0
  L6713bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6713a0
  L6713c4:;
  if ((eax & eax) == 0) goto L6713cd;  // @10_6713a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6713a0
  goto L6713d3;  // @12_6713a0
  L6713cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6713a0
  L6713d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236864), &v, sizeof v); }  // @16_6713a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236868), &v, sizeof v); }  // @17_6713a0
  return eax;  // @18_6713a0
}
PCREG(6713a0, lifted_6713a0);

extern "C" u32 lifted_6713f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236920), sizeof v); (u32)v; });  // @0_6713f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236924), sizeof v); (u32)v; });  // @1_6713f0
  if ((ecx & ecx) == 0) goto L67140f;  // @2_6713f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6713f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236924), sizeof v); (u32)v; });  // @4_6713f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236920), sizeof v); (u32)v; });  // @5_6713f0
  goto L671414;  // @6_6713f0
  L67140f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6713f0
  L671414:;
  if ((eax & eax) == 0) goto L67141d;  // @10_6713f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6713f0
  goto L671423;  // @12_6713f0
  L67141d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6713f0
  L671423:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236920), &v, sizeof v); }  // @16_6713f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236924), &v, sizeof v); }  // @17_6713f0
  return eax;  // @18_6713f0
}
PCREG(6713f0, lifted_6713f0);

extern "C" u32 lifted_671440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236976), sizeof v); (u32)v; });  // @0_671440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236980), sizeof v); (u32)v; });  // @1_671440
  if ((ecx & ecx) == 0) goto L67145f;  // @2_671440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236980), sizeof v); (u32)v; });  // @4_671440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7236976), sizeof v); (u32)v; });  // @5_671440
  goto L671464;  // @6_671440
  L67145f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671440
  L671464:;
  if ((eax & eax) == 0) goto L67146d;  // @10_671440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671440
  goto L671473;  // @12_671440
  L67146d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671440
  L671473:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236976), &v, sizeof v); }  // @16_671440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7236980), &v, sizeof v); }  // @17_671440
  return eax;  // @18_671440
}
PCREG(671440, lifted_671440);

extern "C" u32 lifted_671490(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237032), sizeof v); (u32)v; });  // @0_671490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237036), sizeof v); (u32)v; });  // @1_671490
  if ((ecx & ecx) == 0) goto L6714af;  // @2_671490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237036), sizeof v); (u32)v; });  // @4_671490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237032), sizeof v); (u32)v; });  // @5_671490
  goto L6714b4;  // @6_671490
  L6714af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671490
  L6714b4:;
  if ((eax & eax) == 0) goto L6714bd;  // @10_671490
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671490
  goto L6714c3;  // @12_671490
  L6714bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671490
  L6714c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237032), &v, sizeof v); }  // @16_671490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237036), &v, sizeof v); }  // @17_671490
  return eax;  // @18_671490
}
PCREG(671490, lifted_671490);

extern "C" u32 lifted_6714e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237088), sizeof v); (u32)v; });  // @0_6714e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237092), sizeof v); (u32)v; });  // @1_6714e0
  if ((ecx & ecx) == 0) goto L6714ff;  // @2_6714e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6714e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237092), sizeof v); (u32)v; });  // @4_6714e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237088), sizeof v); (u32)v; });  // @5_6714e0
  goto L671504;  // @6_6714e0
  L6714ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6714e0
  L671504:;
  if ((eax & eax) == 0) goto L67150d;  // @10_6714e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6714e0
  goto L671513;  // @12_6714e0
  L67150d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6714e0
  L671513:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237088), &v, sizeof v); }  // @16_6714e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237092), &v, sizeof v); }  // @17_6714e0
  return eax;  // @18_6714e0
}
PCREG(6714e0, lifted_6714e0);

extern "C" u32 lifted_671530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237144), sizeof v); (u32)v; });  // @0_671530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237148), sizeof v); (u32)v; });  // @1_671530
  if ((ecx & ecx) == 0) goto L67154f;  // @2_671530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237148), sizeof v); (u32)v; });  // @4_671530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237144), sizeof v); (u32)v; });  // @5_671530
  goto L671554;  // @6_671530
  L67154f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671530
  L671554:;
  if ((eax & eax) == 0) goto L67155d;  // @10_671530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671530
  goto L671563;  // @12_671530
  L67155d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671530
  L671563:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237144), &v, sizeof v); }  // @16_671530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237148), &v, sizeof v); }  // @17_671530
  return eax;  // @18_671530
}
PCREG(671530, lifted_671530);

extern "C" u32 lifted_671580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237256), sizeof v); (u32)v; });  // @0_671580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237260), sizeof v); (u32)v; });  // @1_671580
  if ((ecx & ecx) == 0) goto L67159f;  // @2_671580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237260), sizeof v); (u32)v; });  // @4_671580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237256), sizeof v); (u32)v; });  // @5_671580
  goto L6715a4;  // @6_671580
  L67159f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671580
  L6715a4:;
  if ((eax & eax) == 0) goto L6715ad;  // @10_671580
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671580
  goto L6715b3;  // @12_671580
  L6715ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671580
  L6715b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237256), &v, sizeof v); }  // @16_671580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237260), &v, sizeof v); }  // @17_671580
  return eax;  // @18_671580
}
PCREG(671580, lifted_671580);

extern "C" u32 lifted_6715d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237424), sizeof v); (u32)v; });  // @0_6715d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237428), sizeof v); (u32)v; });  // @1_6715d0
  if ((ecx & ecx) == 0) goto L6715ef;  // @2_6715d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6715d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237428), sizeof v); (u32)v; });  // @4_6715d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237424), sizeof v); (u32)v; });  // @5_6715d0
  goto L6715f4;  // @6_6715d0
  L6715ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6715d0
  L6715f4:;
  if ((eax & eax) == 0) goto L6715fd;  // @10_6715d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6715d0
  goto L671603;  // @12_6715d0
  L6715fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6715d0
  L671603:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237424), &v, sizeof v); }  // @16_6715d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237428), &v, sizeof v); }  // @17_6715d0
  return eax;  // @18_6715d0
}
PCREG(6715d0, lifted_6715d0);

extern "C" u32 lifted_671620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237368), sizeof v); (u32)v; });  // @0_671620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237372), sizeof v); (u32)v; });  // @1_671620
  if ((ecx & ecx) == 0) goto L67163f;  // @2_671620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237372), sizeof v); (u32)v; });  // @4_671620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237368), sizeof v); (u32)v; });  // @5_671620
  goto L671644;  // @6_671620
  L67163f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671620
  L671644:;
  if ((eax & eax) == 0) goto L67164d;  // @10_671620
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671620
  goto L671653;  // @12_671620
  L67164d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671620
  L671653:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237368), &v, sizeof v); }  // @16_671620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237372), &v, sizeof v); }  // @17_671620
  return eax;  // @18_671620
}
PCREG(671620, lifted_671620);

