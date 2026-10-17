// batch200144.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4cbec0_thiscall1(u32) __asm__("ext_4cbec0");
extern "C" u32 THISCALL ext_613b30_thiscall1(u32) __asm__("ext_613b30");
extern "C" u32 THISCALL ext_613c20_thiscall1(u32) __asm__("ext_613c20");
extern "C" u32 THISCALL ext_613ca0_thiscall1(u32) __asm__("ext_613ca0");
extern "C" u32 THISCALL ext_615500_thiscall1(u32) __asm__("ext_615500");
extern "C" u32 THISCALL ext_6155d0_thiscall1(u32) __asm__("ext_6155d0");
extern "C" u32 THISCALL ext_63b160_thiscall1(u32) __asm__("ext_63b160");
extern "C" u32 THISCALL ext_6487a0_thiscall1(u32) __asm__("ext_6487a0");
extern "C" u32 THISCALL ext_648dd0_thiscall1(u32) __asm__("ext_648dd0");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_613a20(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_613a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_613a20
  if ((ecx & ecx) == 0) goto L613a47;  // @2_613a20
  edx = (u32)(65535);  // @3_613a20
  L613a30:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_613a20
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) != (edx & 0xffff)) goto L613a56;  // @6_613a20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_613a20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_613a20
  if (ecx == eax) goto L613a47;  // @9_613a20
  if ((eax & eax) != 0) goto L613a30;  // @10_613a20
  L613a47:;
  ecx = esi;  // @12_613a20
  eax = ext_613ca0_thiscall1(ecx);  // @13_613a20
  ecx = edx = 0;  // @14_613a20
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L613a61;  // @15_613a20
  eax = 0;  // @16_613a20
  return eax;  // @17_613a20
  L613a56:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_613a20
  ecx = eax;  // @20_613a20
  eax = ext_613b30_thiscall1(ecx);  // @21_613a20
  ecx = edx = 0;  // @22_613a20
  return eax;  // @23_613a20
  L613a61:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @25_613a20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @26_613a20
  eax = ext_613b30_thiscall1(ecx);  // @27_613a20
  ecx = edx = 0;  // @28_613a20
  return eax;  // @29_613a20
}
PCREG(613a20, lifted_613a20);

extern "C" u32 THISCALL lifted_63aed0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_63aed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_63aed0
  if ((ecx & ecx) == 0) goto L63aef7;  // @2_63aed0
  edx = (u32)(65535);  // @3_63aed0
  L63aee0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_63aed0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) != (edx & 0xffff)) goto L63af06;  // @6_63aed0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_63aed0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_63aed0
  if (ecx == eax) goto L63aef7;  // @9_63aed0
  if ((eax & eax) != 0) goto L63aee0;  // @10_63aed0
  L63aef7:;
  ecx = esi;  // @12_63aed0
  eax = ext_613c20_thiscall1(ecx);  // @13_63aed0
  ecx = edx = 0;  // @14_63aed0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L63af11;  // @15_63aed0
  eax = 0;  // @16_63aed0
  return eax;  // @17_63aed0
  L63af06:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_63aed0
  ecx = eax;  // @20_63aed0
  eax = ext_63b160_thiscall1(ecx);  // @21_63aed0
  ecx = edx = 0;  // @22_63aed0
  return eax;  // @23_63aed0
  L63af11:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @25_63aed0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @26_63aed0
  eax = ext_63b160_thiscall1(ecx);  // @27_63aed0
  ecx = edx = 0;  // @28_63aed0
  return eax;  // @29_63aed0
}
PCREG(63aed0, lifted_63aed0);

extern "C" u32 THISCALL lifted_6484d0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_6484d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_6484d0
  if ((ecx & ecx) == 0) goto L6484f7;  // @2_6484d0
  edx = (u32)(65535);  // @3_6484d0
  L6484e0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_6484d0
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) != (edx & 0xffff)) goto L648506;  // @6_6484d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_6484d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_6484d0
  if (ecx == eax) goto L6484f7;  // @9_6484d0
  if ((eax & eax) != 0) goto L6484e0;  // @10_6484d0
  L6484f7:;
  ecx = esi;  // @12_6484d0
  eax = ext_648dd0_thiscall1(ecx);  // @13_6484d0
  ecx = edx = 0;  // @14_6484d0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L648511;  // @15_6484d0
  eax = 0;  // @16_6484d0
  return eax;  // @17_6484d0
  L648506:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_6484d0
  ecx = eax;  // @20_6484d0
  eax = ext_6487a0_thiscall1(ecx);  // @21_6484d0
  ecx = edx = 0;  // @22_6484d0
  return eax;  // @23_6484d0
  L648511:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @25_6484d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @26_6484d0
  eax = ext_6487a0_thiscall1(ecx);  // @27_6484d0
  ecx = edx = 0;  // @28_6484d0
  return eax;  // @29_6484d0
}
PCREG(6484d0, lifted_6484d0);

extern "C" u32 THISCALL lifted_615460(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_615460
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_615460
  if ((ecx & ecx) == 0) goto L615487;  // @2_615460
  edx = (u32)(65535);  // @3_615460
  L615470:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @5_615460
  if (({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2), sizeof v); (u32)v; }) != (edx & 0xffff)) goto L615496;  // @6_615460
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_615460
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @8_615460
  if (ecx == eax) goto L615487;  // @9_615460
  if ((eax & eax) != 0) goto L615470;  // @10_615460
  L615487:;
  ecx = esi;  // @12_615460
  eax = ext_6155d0_thiscall1(ecx);  // @13_615460
  ecx = edx = 0;  // @14_615460
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6154a1;  // @15_615460
  eax = 0;  // @16_615460
  return eax;  // @17_615460
  L615496:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @19_615460
  ecx = eax;  // @20_615460
  eax = ext_615500_thiscall1(ecx);  // @21_615460
  ecx = edx = 0;  // @22_615460
  return eax;  // @23_615460
  L6154a1:;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @25_615460
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @26_615460
  eax = ext_615500_thiscall1(ecx);  // @27_615460
  ecx = edx = 0;  // @28_615460
  return eax;  // @29_615460
}
PCREG(615460, lifted_615460);

extern "C" u32 lifted_6666fb(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP; __asm__ volatile("mov %%ebp, %0" : "=r"(EBP));
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; });  // @0_6666fb
  eax = (eax & (u32)(1));  // @1_6666fb
  if (eax == 0) goto L66671c;  // @2_6666fb
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 452), sizeof v); (u32)v; }) & (u32)(4294967294))); __builtin_memcpy((void *)(u32)(EBP - 452), &v, sizeof v); }  // @3_6666fb
  ecx = (u32)(EBP - 144);  // @4_6666fb
  eax = ext_4cbec0_thiscall1(ecx);  // @5_6666fb
  ecx = edx = 0;  // @6_6666fb
  return eax;  // @7_6666fb
  L66671c:;
  return eax;  // @9_6666fb
}
PCREG(6666fb, lifted_6666fb);

