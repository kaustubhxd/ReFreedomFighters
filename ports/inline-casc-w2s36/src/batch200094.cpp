// batch200094.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 FASTCALL ext_65f690_fastcall3(u32, u32, u32) __asm__("ext_65f690");
extern "C" u32 STDCALL ext_661b40_stdcall8(u32, u32, u32, u32, u32, u32, u32, u32) __asm__("ext_661b40");
extern "C" u32 THISCALL ext_5adea0_thiscall1(u32) __asm__("ext_5adea0");
extern "C" u32 THISCALL ext_5ae5a0_thiscall3(u32, u32, u32) __asm__("ext_5ae5a0");
extern "C" u32 THISCALL ext_5ae900_thiscall2(u32, u32) __asm__("ext_5ae900");
extern "C" u32 THISCALL ext_6604c0_thiscall4(u32, u32, u32, u32) __asm__("ext_6604c0");
extern "C" u32 THISCALL ext_662750_thiscall1(u32) __asm__("ext_662750");
extern "C" u32 THISCALL ext_663610_thiscall2(u32, u32) __asm__("ext_663610");
extern "C" u32 THISCALL ext_663680_thiscall1(u32) __asm__("ext_663680");
extern "C" u32 THISCALL ext_663770_thiscall2(u32, u32) __asm__("ext_663770");
extern "C" u32 THISCALL ext_6638c0_thiscall2(u32, u32) __asm__("ext_6638c0");
extern "C" u32 THISCALL ext_663b60_thiscall3(u32, u32, u32) __asm__("ext_663b60");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 lifted_671670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238040), sizeof v); (u32)v; });  // @0_671670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238044), sizeof v); (u32)v; });  // @1_671670
  if ((ecx & ecx) == 0) goto L67168f;  // @2_671670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238044), sizeof v); (u32)v; });  // @4_671670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238040), sizeof v); (u32)v; });  // @5_671670
  goto L671694;  // @6_671670
  L67168f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671670
  L671694:;
  if ((eax & eax) == 0) goto L67169d;  // @10_671670
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671670
  goto L6716a3;  // @12_671670
  L67169d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671670
  L6716a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238040), &v, sizeof v); }  // @16_671670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238044), &v, sizeof v); }  // @17_671670
  return eax;  // @18_671670
}
PCREG(671670, lifted_671670);

extern "C" u32 lifted_6716c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237312), sizeof v); (u32)v; });  // @0_6716c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237316), sizeof v); (u32)v; });  // @1_6716c0
  if ((ecx & ecx) == 0) goto L6716df;  // @2_6716c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6716c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237316), sizeof v); (u32)v; });  // @4_6716c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237312), sizeof v); (u32)v; });  // @5_6716c0
  goto L6716e4;  // @6_6716c0
  L6716df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6716c0
  L6716e4:;
  if ((eax & eax) == 0) goto L6716ed;  // @10_6716c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6716c0
  goto L6716f3;  // @12_6716c0
  L6716ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6716c0
  L6716f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237312), &v, sizeof v); }  // @16_6716c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237316), &v, sizeof v); }  // @17_6716c0
  return eax;  // @18_6716c0
}
PCREG(6716c0, lifted_6716c0);

extern "C" u32 lifted_671710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237648), sizeof v); (u32)v; });  // @0_671710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237652), sizeof v); (u32)v; });  // @1_671710
  if ((ecx & ecx) == 0) goto L67172f;  // @2_671710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237652), sizeof v); (u32)v; });  // @4_671710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237648), sizeof v); (u32)v; });  // @5_671710
  goto L671734;  // @6_671710
  L67172f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671710
  L671734:;
  if ((eax & eax) == 0) goto L67173d;  // @10_671710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671710
  goto L671743;  // @12_671710
  L67173d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671710
  L671743:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237648), &v, sizeof v); }  // @16_671710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237652), &v, sizeof v); }  // @17_671710
  return eax;  // @18_671710
}
PCREG(671710, lifted_671710);

extern "C" u32 lifted_671760(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238096), sizeof v); (u32)v; });  // @0_671760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238100), sizeof v); (u32)v; });  // @1_671760
  if ((ecx & ecx) == 0) goto L67177f;  // @2_671760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238100), sizeof v); (u32)v; });  // @4_671760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238096), sizeof v); (u32)v; });  // @5_671760
  goto L671784;  // @6_671760
  L67177f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671760
  L671784:;
  if ((eax & eax) == 0) goto L67178d;  // @10_671760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671760
  goto L671793;  // @12_671760
  L67178d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671760
  L671793:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238096), &v, sizeof v); }  // @16_671760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238100), &v, sizeof v); }  // @17_671760
  return eax;  // @18_671760
}
PCREG(671760, lifted_671760);

extern "C" u32 lifted_6717b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237816), sizeof v); (u32)v; });  // @0_6717b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237820), sizeof v); (u32)v; });  // @1_6717b0
  if ((ecx & ecx) == 0) goto L6717cf;  // @2_6717b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6717b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237820), sizeof v); (u32)v; });  // @4_6717b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237816), sizeof v); (u32)v; });  // @5_6717b0
  goto L6717d4;  // @6_6717b0
  L6717cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6717b0
  L6717d4:;
  if ((eax & eax) == 0) goto L6717dd;  // @10_6717b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6717b0
  goto L6717e3;  // @12_6717b0
  L6717dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6717b0
  L6717e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237816), &v, sizeof v); }  // @16_6717b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237820), &v, sizeof v); }  // @17_6717b0
  return eax;  // @18_6717b0
}
PCREG(6717b0, lifted_6717b0);

extern "C" u32 lifted_671800(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238208), sizeof v); (u32)v; });  // @0_671800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238212), sizeof v); (u32)v; });  // @1_671800
  if ((ecx & ecx) == 0) goto L67181f;  // @2_671800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238212), sizeof v); (u32)v; });  // @4_671800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238208), sizeof v); (u32)v; });  // @5_671800
  goto L671824;  // @6_671800
  L67181f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671800
  L671824:;
  if ((eax & eax) == 0) goto L67182d;  // @10_671800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671800
  goto L671833;  // @12_671800
  L67182d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671800
  L671833:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238208), &v, sizeof v); }  // @16_671800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238212), &v, sizeof v); }  // @17_671800
  return eax;  // @18_671800
}
PCREG(671800, lifted_671800);

extern "C" u32 lifted_671850(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238152), sizeof v); (u32)v; });  // @0_671850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238156), sizeof v); (u32)v; });  // @1_671850
  if ((ecx & ecx) == 0) goto L67186f;  // @2_671850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238156), sizeof v); (u32)v; });  // @4_671850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238152), sizeof v); (u32)v; });  // @5_671850
  goto L671874;  // @6_671850
  L67186f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671850
  L671874:;
  if ((eax & eax) == 0) goto L67187d;  // @10_671850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671850
  goto L671883;  // @12_671850
  L67187d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671850
  L671883:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238152), &v, sizeof v); }  // @16_671850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238156), &v, sizeof v); }  // @17_671850
  return eax;  // @18_671850
}
PCREG(671850, lifted_671850);

extern "C" u32 lifted_6718a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237704), sizeof v); (u32)v; });  // @0_6718a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237708), sizeof v); (u32)v; });  // @1_6718a0
  if ((ecx & ecx) == 0) goto L6718bf;  // @2_6718a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6718a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237708), sizeof v); (u32)v; });  // @4_6718a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237704), sizeof v); (u32)v; });  // @5_6718a0
  goto L6718c4;  // @6_6718a0
  L6718bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6718a0
  L6718c4:;
  if ((eax & eax) == 0) goto L6718cd;  // @10_6718a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6718a0
  goto L6718d3;  // @12_6718a0
  L6718cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6718a0
  L6718d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237704), &v, sizeof v); }  // @16_6718a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237708), &v, sizeof v); }  // @17_6718a0
  return eax;  // @18_6718a0
}
PCREG(6718a0, lifted_6718a0);

extern "C" u32 lifted_6718f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237200), sizeof v); (u32)v; });  // @0_6718f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237204), sizeof v); (u32)v; });  // @1_6718f0
  if ((ecx & ecx) == 0) goto L67190f;  // @2_6718f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6718f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237204), sizeof v); (u32)v; });  // @4_6718f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237200), sizeof v); (u32)v; });  // @5_6718f0
  goto L671914;  // @6_6718f0
  L67190f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6718f0
  L671914:;
  if ((eax & eax) == 0) goto L67191d;  // @10_6718f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6718f0
  goto L671923;  // @12_6718f0
  L67191d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6718f0
  L671923:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237200), &v, sizeof v); }  // @16_6718f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237204), &v, sizeof v); }  // @17_6718f0
  return eax;  // @18_6718f0
}
PCREG(6718f0, lifted_6718f0);

extern "C" u32 lifted_671940(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237480), sizeof v); (u32)v; });  // @0_671940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237484), sizeof v); (u32)v; });  // @1_671940
  if ((ecx & ecx) == 0) goto L67195f;  // @2_671940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237484), sizeof v); (u32)v; });  // @4_671940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237480), sizeof v); (u32)v; });  // @5_671940
  goto L671964;  // @6_671940
  L67195f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671940
  L671964:;
  if ((eax & eax) == 0) goto L67196d;  // @10_671940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671940
  goto L671973;  // @12_671940
  L67196d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671940
  L671973:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237480), &v, sizeof v); }  // @16_671940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237484), &v, sizeof v); }  // @17_671940
  return eax;  // @18_671940
}
PCREG(671940, lifted_671940);

extern "C" u32 lifted_671990(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237928), sizeof v); (u32)v; });  // @0_671990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237932), sizeof v); (u32)v; });  // @1_671990
  if ((ecx & ecx) == 0) goto L6719af;  // @2_671990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237932), sizeof v); (u32)v; });  // @4_671990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237928), sizeof v); (u32)v; });  // @5_671990
  goto L6719b4;  // @6_671990
  L6719af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671990
  L6719b4:;
  if ((eax & eax) == 0) goto L6719bd;  // @10_671990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671990
  goto L6719c3;  // @12_671990
  L6719bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671990
  L6719c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237928), &v, sizeof v); }  // @16_671990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237932), &v, sizeof v); }  // @17_671990
  return eax;  // @18_671990
}
PCREG(671990, lifted_671990);

extern "C" u32 lifted_6719e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237984), sizeof v); (u32)v; });  // @0_6719e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237988), sizeof v); (u32)v; });  // @1_6719e0
  if ((ecx & ecx) == 0) goto L6719ff;  // @2_6719e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6719e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237988), sizeof v); (u32)v; });  // @4_6719e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237984), sizeof v); (u32)v; });  // @5_6719e0
  goto L671a04;  // @6_6719e0
  L6719ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6719e0
  L671a04:;
  if ((eax & eax) == 0) goto L671a0d;  // @10_6719e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6719e0
  goto L671a13;  // @12_6719e0
  L671a0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6719e0
  L671a13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237984), &v, sizeof v); }  // @16_6719e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237988), &v, sizeof v); }  // @17_6719e0
  return eax;  // @18_6719e0
}
PCREG(6719e0, lifted_6719e0);

extern "C" u32 lifted_671a30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237872), sizeof v); (u32)v; });  // @0_671a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237876), sizeof v); (u32)v; });  // @1_671a30
  if ((ecx & ecx) == 0) goto L671a4f;  // @2_671a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237876), sizeof v); (u32)v; });  // @4_671a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237872), sizeof v); (u32)v; });  // @5_671a30
  goto L671a54;  // @6_671a30
  L671a4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671a30
  L671a54:;
  if ((eax & eax) == 0) goto L671a5d;  // @10_671a30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671a30
  goto L671a63;  // @12_671a30
  L671a5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671a30
  L671a63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237872), &v, sizeof v); }  // @16_671a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237876), &v, sizeof v); }  // @17_671a30
  return eax;  // @18_671a30
}
PCREG(671a30, lifted_671a30);

extern "C" u32 lifted_671a80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237592), sizeof v); (u32)v; });  // @0_671a80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237596), sizeof v); (u32)v; });  // @1_671a80
  if ((ecx & ecx) == 0) goto L671a9f;  // @2_671a80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671a80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237596), sizeof v); (u32)v; });  // @4_671a80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237592), sizeof v); (u32)v; });  // @5_671a80
  goto L671aa4;  // @6_671a80
  L671a9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671a80
  L671aa4:;
  if ((eax & eax) == 0) goto L671aad;  // @10_671a80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671a80
  goto L671ab3;  // @12_671a80
  L671aad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671a80
  L671ab3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237592), &v, sizeof v); }  // @16_671a80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237596), &v, sizeof v); }  // @17_671a80
  return eax;  // @18_671a80
}
PCREG(671a80, lifted_671a80);

extern "C" u32 lifted_671ad0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237760), sizeof v); (u32)v; });  // @0_671ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237764), sizeof v); (u32)v; });  // @1_671ad0
  if ((ecx & ecx) == 0) goto L671aef;  // @2_671ad0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237764), sizeof v); (u32)v; });  // @4_671ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237760), sizeof v); (u32)v; });  // @5_671ad0
  goto L671af4;  // @6_671ad0
  L671aef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671ad0
  L671af4:;
  if ((eax & eax) == 0) goto L671afd;  // @10_671ad0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671ad0
  goto L671b03;  // @12_671ad0
  L671afd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671ad0
  L671b03:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237760), &v, sizeof v); }  // @16_671ad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237764), &v, sizeof v); }  // @17_671ad0
  return eax;  // @18_671ad0
}
PCREG(671ad0, lifted_671ad0);

extern "C" u32 lifted_671b20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237536), sizeof v); (u32)v; });  // @0_671b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237540), sizeof v); (u32)v; });  // @1_671b20
  if ((ecx & ecx) == 0) goto L671b3f;  // @2_671b20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237540), sizeof v); (u32)v; });  // @4_671b20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7237536), sizeof v); (u32)v; });  // @5_671b20
  goto L671b44;  // @6_671b20
  L671b3f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671b20
  L671b44:;
  if ((eax & eax) == 0) goto L671b4d;  // @10_671b20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671b20
  goto L671b53;  // @12_671b20
  L671b4d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671b20
  L671b53:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237536), &v, sizeof v); }  // @16_671b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7237540), &v, sizeof v); }  // @17_671b20
  return eax;  // @18_671b20
}
PCREG(671b20, lifted_671b20);

extern "C" u32 lifted_671b70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238320), sizeof v); (u32)v; });  // @0_671b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238324), sizeof v); (u32)v; });  // @1_671b70
  if ((ecx & ecx) == 0) goto L671b8f;  // @2_671b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238324), sizeof v); (u32)v; });  // @4_671b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238320), sizeof v); (u32)v; });  // @5_671b70
  goto L671b94;  // @6_671b70
  L671b8f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671b70
  L671b94:;
  if ((eax & eax) == 0) goto L671b9d;  // @10_671b70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671b70
  goto L671ba3;  // @12_671b70
  L671b9d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671b70
  L671ba3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238320), &v, sizeof v); }  // @16_671b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238324), &v, sizeof v); }  // @17_671b70
  return eax;  // @18_671b70
}
PCREG(671b70, lifted_671b70);

extern "C" u32 lifted_671bc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238264), sizeof v); (u32)v; });  // @0_671bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238268), sizeof v); (u32)v; });  // @1_671bc0
  if ((ecx & ecx) == 0) goto L671bdf;  // @2_671bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238268), sizeof v); (u32)v; });  // @4_671bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238264), sizeof v); (u32)v; });  // @5_671bc0
  goto L671be4;  // @6_671bc0
  L671bdf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671bc0
  L671be4:;
  if ((eax & eax) == 0) goto L671bed;  // @10_671bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671bc0
  goto L671bf3;  // @12_671bc0
  L671bed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671bc0
  L671bf3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238264), &v, sizeof v); }  // @16_671bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238268), &v, sizeof v); }  // @17_671bc0
  return eax;  // @18_671bc0
}
PCREG(671bc0, lifted_671bc0);

extern "C" u32 lifted_671c10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238432), sizeof v); (u32)v; });  // @0_671c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238436), sizeof v); (u32)v; });  // @1_671c10
  if ((ecx & ecx) == 0) goto L671c2f;  // @2_671c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238436), sizeof v); (u32)v; });  // @4_671c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238432), sizeof v); (u32)v; });  // @5_671c10
  goto L671c34;  // @6_671c10
  L671c2f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671c10
  L671c34:;
  if ((eax & eax) == 0) goto L671c3d;  // @10_671c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671c10
  goto L671c43;  // @12_671c10
  L671c3d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671c10
  L671c43:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238432), &v, sizeof v); }  // @16_671c10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238436), &v, sizeof v); }  // @17_671c10
  return eax;  // @18_671c10
}
PCREG(671c10, lifted_671c10);

extern "C" u32 lifted_671c60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238376), sizeof v); (u32)v; });  // @0_671c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238380), sizeof v); (u32)v; });  // @1_671c60
  if ((ecx & ecx) == 0) goto L671c7f;  // @2_671c60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238380), sizeof v); (u32)v; });  // @4_671c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238376), sizeof v); (u32)v; });  // @5_671c60
  goto L671c84;  // @6_671c60
  L671c7f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671c60
  L671c84:;
  if ((eax & eax) == 0) goto L671c8d;  // @10_671c60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671c60
  goto L671c93;  // @12_671c60
  L671c8d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671c60
  L671c93:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238376), &v, sizeof v); }  // @16_671c60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238380), &v, sizeof v); }  // @17_671c60
  return eax;  // @18_671c60
}
PCREG(671c60, lifted_671c60);

extern "C" u32 lifted_671cb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238488), sizeof v); (u32)v; });  // @0_671cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238492), sizeof v); (u32)v; });  // @1_671cb0
  if ((ecx & ecx) == 0) goto L671ccf;  // @2_671cb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238492), sizeof v); (u32)v; });  // @4_671cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238488), sizeof v); (u32)v; });  // @5_671cb0
  goto L671cd4;  // @6_671cb0
  L671ccf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671cb0
  L671cd4:;
  if ((eax & eax) == 0) goto L671cdd;  // @10_671cb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671cb0
  goto L671ce3;  // @12_671cb0
  L671cdd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671cb0
  L671ce3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238488), &v, sizeof v); }  // @16_671cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238492), &v, sizeof v); }  // @17_671cb0
  return eax;  // @18_671cb0
}
PCREG(671cb0, lifted_671cb0);

extern "C" u32 lifted_671d00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238544), sizeof v); (u32)v; });  // @0_671d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238548), sizeof v); (u32)v; });  // @1_671d00
  if ((ecx & ecx) == 0) goto L671d1f;  // @2_671d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238548), sizeof v); (u32)v; });  // @4_671d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238544), sizeof v); (u32)v; });  // @5_671d00
  goto L671d24;  // @6_671d00
  L671d1f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671d00
  L671d24:;
  if ((eax & eax) == 0) goto L671d2d;  // @10_671d00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671d00
  goto L671d33;  // @12_671d00
  L671d2d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671d00
  L671d33:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238544), &v, sizeof v); }  // @16_671d00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238548), &v, sizeof v); }  // @17_671d00
  return eax;  // @18_671d00
}
PCREG(671d00, lifted_671d00);

extern "C" u32 lifted_671d50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239112), sizeof v); (u32)v; });  // @0_671d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239116), sizeof v); (u32)v; });  // @1_671d50
  if ((ecx & ecx) == 0) goto L671d6f;  // @2_671d50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239116), sizeof v); (u32)v; });  // @4_671d50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239112), sizeof v); (u32)v; });  // @5_671d50
  goto L671d74;  // @6_671d50
  L671d6f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671d50
  L671d74:;
  if ((eax & eax) == 0) goto L671d7d;  // @10_671d50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671d50
  goto L671d83;  // @12_671d50
  L671d7d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671d50
  L671d83:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239112), &v, sizeof v); }  // @16_671d50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239116), &v, sizeof v); }  // @17_671d50
  return eax;  // @18_671d50
}
PCREG(671d50, lifted_671d50);

extern "C" u32 lifted_671da0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239000), sizeof v); (u32)v; });  // @0_671da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239004), sizeof v); (u32)v; });  // @1_671da0
  if ((ecx & ecx) == 0) goto L671dbf;  // @2_671da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239004), sizeof v); (u32)v; });  // @4_671da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239000), sizeof v); (u32)v; });  // @5_671da0
  goto L671dc4;  // @6_671da0
  L671dbf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671da0
  L671dc4:;
  if ((eax & eax) == 0) goto L671dcd;  // @10_671da0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671da0
  goto L671dd3;  // @12_671da0
  L671dcd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671da0
  L671dd3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239000), &v, sizeof v); }  // @16_671da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239004), &v, sizeof v); }  // @17_671da0
  return eax;  // @18_671da0
}
PCREG(671da0, lifted_671da0);

extern "C" u32 lifted_671df0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238944), sizeof v); (u32)v; });  // @0_671df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238948), sizeof v); (u32)v; });  // @1_671df0
  if ((ecx & ecx) == 0) goto L671e0f;  // @2_671df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238948), sizeof v); (u32)v; });  // @4_671df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7238944), sizeof v); (u32)v; });  // @5_671df0
  goto L671e14;  // @6_671df0
  L671e0f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671df0
  L671e14:;
  if ((eax & eax) == 0) goto L671e1d;  // @10_671df0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671df0
  goto L671e23;  // @12_671df0
  L671e1d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671df0
  L671e23:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238944), &v, sizeof v); }  // @16_671df0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7238948), &v, sizeof v); }  // @17_671df0
  return eax;  // @18_671df0
}
PCREG(671df0, lifted_671df0);

extern "C" u32 lifted_671e40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239396), sizeof v); (u32)v; });  // @0_671e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239400), sizeof v); (u32)v; });  // @1_671e40
  if ((ecx & ecx) == 0) goto L671e5f;  // @2_671e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239400), sizeof v); (u32)v; });  // @4_671e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239396), sizeof v); (u32)v; });  // @5_671e40
  goto L671e64;  // @6_671e40
  L671e5f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671e40
  L671e64:;
  if ((eax & eax) == 0) goto L671e6d;  // @10_671e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671e40
  goto L671e73;  // @12_671e40
  L671e6d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671e40
  L671e73:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239396), &v, sizeof v); }  // @16_671e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239400), &v, sizeof v); }  // @17_671e40
  return eax;  // @18_671e40
}
PCREG(671e40, lifted_671e40);

extern "C" u32 lifted_671e90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239452), sizeof v); (u32)v; });  // @0_671e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239456), sizeof v); (u32)v; });  // @1_671e90
  if ((ecx & ecx) == 0) goto L671eaf;  // @2_671e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239456), sizeof v); (u32)v; });  // @4_671e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239452), sizeof v); (u32)v; });  // @5_671e90
  goto L671eb4;  // @6_671e90
  L671eaf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671e90
  L671eb4:;
  if ((eax & eax) == 0) goto L671ebd;  // @10_671e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671e90
  goto L671ec3;  // @12_671e90
  L671ebd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671e90
  L671ec3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239452), &v, sizeof v); }  // @16_671e90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239456), &v, sizeof v); }  // @17_671e90
  return eax;  // @18_671e90
}
PCREG(671e90, lifted_671e90);

extern "C" u32 lifted_671ee0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239340), sizeof v); (u32)v; });  // @0_671ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239344), sizeof v); (u32)v; });  // @1_671ee0
  if ((ecx & ecx) == 0) goto L671eff;  // @2_671ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239344), sizeof v); (u32)v; });  // @4_671ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239340), sizeof v); (u32)v; });  // @5_671ee0
  goto L671f04;  // @6_671ee0
  L671eff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671ee0
  L671f04:;
  if ((eax & eax) == 0) goto L671f0d;  // @10_671ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671ee0
  goto L671f13;  // @12_671ee0
  L671f0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671ee0
  L671f13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239340), &v, sizeof v); }  // @16_671ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239344), &v, sizeof v); }  // @17_671ee0
  return eax;  // @18_671ee0
}
PCREG(671ee0, lifted_671ee0);

extern "C" u32 lifted_671f30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239284), sizeof v); (u32)v; });  // @0_671f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239288), sizeof v); (u32)v; });  // @1_671f30
  if ((ecx & ecx) == 0) goto L671f4f;  // @2_671f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239288), sizeof v); (u32)v; });  // @4_671f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239284), sizeof v); (u32)v; });  // @5_671f30
  goto L671f54;  // @6_671f30
  L671f4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671f30
  L671f54:;
  if ((eax & eax) == 0) goto L671f5d;  // @10_671f30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671f30
  goto L671f63;  // @12_671f30
  L671f5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671f30
  L671f63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239284), &v, sizeof v); }  // @16_671f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239288), &v, sizeof v); }  // @17_671f30
  return eax;  // @18_671f30
}
PCREG(671f30, lifted_671f30);

extern "C" u32 lifted_671f80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239172), sizeof v); (u32)v; });  // @0_671f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239176), sizeof v); (u32)v; });  // @1_671f80
  if ((ecx & ecx) == 0) goto L671f9f;  // @2_671f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239176), sizeof v); (u32)v; });  // @4_671f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239172), sizeof v); (u32)v; });  // @5_671f80
  goto L671fa4;  // @6_671f80
  L671f9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671f80
  L671fa4:;
  if ((eax & eax) == 0) goto L671fad;  // @10_671f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671f80
  goto L671fb3;  // @12_671f80
  L671fad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671f80
  L671fb3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239172), &v, sizeof v); }  // @16_671f80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239176), &v, sizeof v); }  // @17_671f80
  return eax;  // @18_671f80
}
PCREG(671f80, lifted_671f80);

extern "C" u32 lifted_671fe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239056), sizeof v); (u32)v; });  // @0_671fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239060), sizeof v); (u32)v; });  // @1_671fe0
  if ((ecx & ecx) == 0) goto L671fff;  // @2_671fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_671fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239060), sizeof v); (u32)v; });  // @4_671fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7239056), sizeof v); (u32)v; });  // @5_671fe0
  goto L672004;  // @6_671fe0
  L671fff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_671fe0
  L672004:;
  if ((eax & eax) == 0) goto L67200d;  // @10_671fe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_671fe0
  goto L672013;  // @12_671fe0
  L67200d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_671fe0
  L672013:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239056), &v, sizeof v); }  // @16_671fe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7239060), &v, sizeof v); }  // @17_671fe0
  return eax;  // @18_671fe0
}
PCREG(671fe0, lifted_671fe0);

extern "C" u32 lifted_673030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259512), sizeof v); (u32)v; });  // @0_673030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259516), sizeof v); (u32)v; });  // @1_673030
  if ((ecx & ecx) == 0) goto L67304f;  // @2_673030
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259516), sizeof v); (u32)v; });  // @4_673030
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259512), sizeof v); (u32)v; });  // @5_673030
  goto L673054;  // @6_673030
  L67304f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673030
  L673054:;
  if ((eax & eax) == 0) goto L67305d;  // @10_673030
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673030
  goto L673063;  // @12_673030
  L67305d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673030
  L673063:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259512), &v, sizeof v); }  // @16_673030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259516), &v, sizeof v); }  // @17_673030
  return eax;  // @18_673030
}
PCREG(673030, lifted_673030);

extern "C" u32 lifted_673080(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259568), sizeof v); (u32)v; });  // @0_673080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259572), sizeof v); (u32)v; });  // @1_673080
  if ((ecx & ecx) == 0) goto L67309f;  // @2_673080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259572), sizeof v); (u32)v; });  // @4_673080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259568), sizeof v); (u32)v; });  // @5_673080
  goto L6730a4;  // @6_673080
  L67309f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673080
  L6730a4:;
  if ((eax & eax) == 0) goto L6730ad;  // @10_673080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673080
  goto L6730b3;  // @12_673080
  L6730ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673080
  L6730b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259568), &v, sizeof v); }  // @16_673080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259572), &v, sizeof v); }  // @17_673080
  return eax;  // @18_673080
}
PCREG(673080, lifted_673080);

extern "C" u32 lifted_6730d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259624), sizeof v); (u32)v; });  // @0_6730d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259628), sizeof v); (u32)v; });  // @1_6730d0
  if ((ecx & ecx) == 0) goto L6730ef;  // @2_6730d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6730d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259628), sizeof v); (u32)v; });  // @4_6730d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259624), sizeof v); (u32)v; });  // @5_6730d0
  goto L6730f4;  // @6_6730d0
  L6730ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6730d0
  L6730f4:;
  if ((eax & eax) == 0) goto L6730fd;  // @10_6730d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6730d0
  goto L673103;  // @12_6730d0
  L6730fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6730d0
  L673103:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259624), &v, sizeof v); }  // @16_6730d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259628), &v, sizeof v); }  // @17_6730d0
  return eax;  // @18_6730d0
}
PCREG(6730d0, lifted_6730d0);

extern "C" u32 lifted_673120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259680), sizeof v); (u32)v; });  // @0_673120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259684), sizeof v); (u32)v; });  // @1_673120
  if ((ecx & ecx) == 0) goto L67313f;  // @2_673120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259684), sizeof v); (u32)v; });  // @4_673120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259680), sizeof v); (u32)v; });  // @5_673120
  goto L673144;  // @6_673120
  L67313f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673120
  L673144:;
  if ((eax & eax) == 0) goto L67314d;  // @10_673120
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673120
  goto L673153;  // @12_673120
  L67314d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673120
  L673153:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259680), &v, sizeof v); }  // @16_673120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259684), &v, sizeof v); }  // @17_673120
  return eax;  // @18_673120
}
PCREG(673120, lifted_673120);

extern "C" u32 lifted_673170(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259736), sizeof v); (u32)v; });  // @0_673170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259740), sizeof v); (u32)v; });  // @1_673170
  if ((ecx & ecx) == 0) goto L67318f;  // @2_673170
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259740), sizeof v); (u32)v; });  // @4_673170
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259736), sizeof v); (u32)v; });  // @5_673170
  goto L673194;  // @6_673170
  L67318f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673170
  L673194:;
  if ((eax & eax) == 0) goto L67319d;  // @10_673170
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673170
  goto L6731a3;  // @12_673170
  L67319d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673170
  L6731a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259736), &v, sizeof v); }  // @16_673170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259740), &v, sizeof v); }  // @17_673170
  return eax;  // @18_673170
}
PCREG(673170, lifted_673170);

extern "C" u32 lifted_6731c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259852), sizeof v); (u32)v; });  // @0_6731c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259856), sizeof v); (u32)v; });  // @1_6731c0
  if ((ecx & ecx) == 0) goto L6731df;  // @2_6731c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6731c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259856), sizeof v); (u32)v; });  // @4_6731c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259852), sizeof v); (u32)v; });  // @5_6731c0
  goto L6731e4;  // @6_6731c0
  L6731df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6731c0
  L6731e4:;
  if ((eax & eax) == 0) goto L6731ed;  // @10_6731c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6731c0
  goto L6731f3;  // @12_6731c0
  L6731ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6731c0
  L6731f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259852), &v, sizeof v); }  // @16_6731c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259856), &v, sizeof v); }  // @17_6731c0
  return eax;  // @18_6731c0
}
PCREG(6731c0, lifted_6731c0);

extern "C" u32 lifted_673210(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259912), sizeof v); (u32)v; });  // @0_673210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259916), sizeof v); (u32)v; });  // @1_673210
  if ((ecx & ecx) == 0) goto L67322f;  // @2_673210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259916), sizeof v); (u32)v; });  // @4_673210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259912), sizeof v); (u32)v; });  // @5_673210
  goto L673234;  // @6_673210
  L67322f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673210
  L673234:;
  if ((eax & eax) == 0) goto L67323d;  // @10_673210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673210
  goto L673243;  // @12_673210
  L67323d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673210
  L673243:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259912), &v, sizeof v); }  // @16_673210
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259916), &v, sizeof v); }  // @17_673210
  return eax;  // @18_673210
}
PCREG(673210, lifted_673210);

extern "C" u32 lifted_673260(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259968), sizeof v); (u32)v; });  // @0_673260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259972), sizeof v); (u32)v; });  // @1_673260
  if ((ecx & ecx) == 0) goto L67327f;  // @2_673260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259972), sizeof v); (u32)v; });  // @4_673260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7259968), sizeof v); (u32)v; });  // @5_673260
  goto L673284;  // @6_673260
  L67327f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673260
  L673284:;
  if ((eax & eax) == 0) goto L67328d;  // @10_673260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673260
  goto L673293;  // @12_673260
  L67328d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673260
  L673293:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259968), &v, sizeof v); }  // @16_673260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7259972), &v, sizeof v); }  // @17_673260
  return eax;  // @18_673260
}
PCREG(673260, lifted_673260);

extern "C" u32 lifted_6732b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260364), sizeof v); (u32)v; });  // @0_6732b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260368), sizeof v); (u32)v; });  // @1_6732b0
  if ((ecx & ecx) == 0) goto L6732cf;  // @2_6732b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6732b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260368), sizeof v); (u32)v; });  // @4_6732b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260364), sizeof v); (u32)v; });  // @5_6732b0
  goto L6732d4;  // @6_6732b0
  L6732cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6732b0
  L6732d4:;
  if ((eax & eax) == 0) goto L6732dd;  // @10_6732b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6732b0
  goto L6732e3;  // @12_6732b0
  L6732dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6732b0
  L6732e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260364), &v, sizeof v); }  // @16_6732b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260368), &v, sizeof v); }  // @17_6732b0
  return eax;  // @18_6732b0
}
PCREG(6732b0, lifted_6732b0);

extern "C" u32 lifted_673300(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260424), sizeof v); (u32)v; });  // @0_673300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260428), sizeof v); (u32)v; });  // @1_673300
  if ((ecx & ecx) == 0) goto L67331f;  // @2_673300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260428), sizeof v); (u32)v; });  // @4_673300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260424), sizeof v); (u32)v; });  // @5_673300
  goto L673324;  // @6_673300
  L67331f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673300
  L673324:;
  if ((eax & eax) == 0) goto L67332d;  // @10_673300
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673300
  goto L673333;  // @12_673300
  L67332d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673300
  L673333:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260424), &v, sizeof v); }  // @16_673300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260428), &v, sizeof v); }  // @17_673300
  return eax;  // @18_673300
}
PCREG(673300, lifted_673300);

extern "C" u32 lifted_673350(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260480), sizeof v); (u32)v; });  // @0_673350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260484), sizeof v); (u32)v; });  // @1_673350
  if ((ecx & ecx) == 0) goto L67336f;  // @2_673350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260484), sizeof v); (u32)v; });  // @4_673350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260480), sizeof v); (u32)v; });  // @5_673350
  goto L673374;  // @6_673350
  L67336f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673350
  L673374:;
  if ((eax & eax) == 0) goto L67337d;  // @10_673350
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673350
  goto L673383;  // @12_673350
  L67337d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673350
  L673383:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260480), &v, sizeof v); }  // @16_673350
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260484), &v, sizeof v); }  // @17_673350
  return eax;  // @18_673350
}
PCREG(673350, lifted_673350);

extern "C" u32 lifted_6733a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260536), sizeof v); (u32)v; });  // @0_6733a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260540), sizeof v); (u32)v; });  // @1_6733a0
  if ((ecx & ecx) == 0) goto L6733bf;  // @2_6733a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6733a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260540), sizeof v); (u32)v; });  // @4_6733a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260536), sizeof v); (u32)v; });  // @5_6733a0
  goto L6733c4;  // @6_6733a0
  L6733bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6733a0
  L6733c4:;
  if ((eax & eax) == 0) goto L6733cd;  // @10_6733a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6733a0
  goto L6733d3;  // @12_6733a0
  L6733cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6733a0
  L6733d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260536), &v, sizeof v); }  // @16_6733a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260540), &v, sizeof v); }  // @17_6733a0
  return eax;  // @18_6733a0
}
PCREG(6733a0, lifted_6733a0);

extern "C" u32 lifted_6733f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260592), sizeof v); (u32)v; });  // @0_6733f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260596), sizeof v); (u32)v; });  // @1_6733f0
  if ((ecx & ecx) == 0) goto L67340f;  // @2_6733f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6733f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260596), sizeof v); (u32)v; });  // @4_6733f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260592), sizeof v); (u32)v; });  // @5_6733f0
  goto L673414;  // @6_6733f0
  L67340f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6733f0
  L673414:;
  if ((eax & eax) == 0) goto L67341d;  // @10_6733f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6733f0
  goto L673423;  // @12_6733f0
  L67341d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6733f0
  L673423:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260592), &v, sizeof v); }  // @16_6733f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260596), &v, sizeof v); }  // @17_6733f0
  return eax;  // @18_6733f0
}
PCREG(6733f0, lifted_6733f0);

extern "C" u32 lifted_673440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260648), sizeof v); (u32)v; });  // @0_673440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260652), sizeof v); (u32)v; });  // @1_673440
  if ((ecx & ecx) == 0) goto L67345f;  // @2_673440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260652), sizeof v); (u32)v; });  // @4_673440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260648), sizeof v); (u32)v; });  // @5_673440
  goto L673464;  // @6_673440
  L67345f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673440
  L673464:;
  if ((eax & eax) == 0) goto L67346d;  // @10_673440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673440
  goto L673473;  // @12_673440
  L67346d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673440
  L673473:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260648), &v, sizeof v); }  // @16_673440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260652), &v, sizeof v); }  // @17_673440
  return eax;  // @18_673440
}
PCREG(673440, lifted_673440);

extern "C" u32 lifted_673490(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260704), sizeof v); (u32)v; });  // @0_673490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260708), sizeof v); (u32)v; });  // @1_673490
  if ((ecx & ecx) == 0) goto L6734af;  // @2_673490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260708), sizeof v); (u32)v; });  // @4_673490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260704), sizeof v); (u32)v; });  // @5_673490
  goto L6734b4;  // @6_673490
  L6734af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673490
  L6734b4:;
  if ((eax & eax) == 0) goto L6734bd;  // @10_673490
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673490
  goto L6734c3;  // @12_673490
  L6734bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673490
  L6734c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260704), &v, sizeof v); }  // @16_673490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260708), &v, sizeof v); }  // @17_673490
  return eax;  // @18_673490
}
PCREG(673490, lifted_673490);

extern "C" u32 lifted_6734e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260760), sizeof v); (u32)v; });  // @0_6734e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260764), sizeof v); (u32)v; });  // @1_6734e0
  if ((ecx & ecx) == 0) goto L6734ff;  // @2_6734e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6734e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260764), sizeof v); (u32)v; });  // @4_6734e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260760), sizeof v); (u32)v; });  // @5_6734e0
  goto L673504;  // @6_6734e0
  L6734ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6734e0
  L673504:;
  if ((eax & eax) == 0) goto L67350d;  // @10_6734e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6734e0
  goto L673513;  // @12_6734e0
  L67350d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6734e0
  L673513:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260760), &v, sizeof v); }  // @16_6734e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260764), &v, sizeof v); }  // @17_6734e0
  return eax;  // @18_6734e0
}
PCREG(6734e0, lifted_6734e0);

extern "C" u32 lifted_673530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260812), sizeof v); (u32)v; });  // @0_673530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260816), sizeof v); (u32)v; });  // @1_673530
  if ((ecx & ecx) == 0) goto L67354f;  // @2_673530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260816), sizeof v); (u32)v; });  // @4_673530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260812), sizeof v); (u32)v; });  // @5_673530
  goto L673554;  // @6_673530
  L67354f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673530
  L673554:;
  if ((eax & eax) == 0) goto L67355d;  // @10_673530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673530
  goto L673563;  // @12_673530
  L67355d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673530
  L673563:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260812), &v, sizeof v); }  // @16_673530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260816), &v, sizeof v); }  // @17_673530
  return eax;  // @18_673530
}
PCREG(673530, lifted_673530);

extern "C" u32 lifted_673580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260868), sizeof v); (u32)v; });  // @0_673580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260872), sizeof v); (u32)v; });  // @1_673580
  if ((ecx & ecx) == 0) goto L67359f;  // @2_673580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260872), sizeof v); (u32)v; });  // @4_673580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260868), sizeof v); (u32)v; });  // @5_673580
  goto L6735a4;  // @6_673580
  L67359f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673580
  L6735a4:;
  if ((eax & eax) == 0) goto L6735ad;  // @10_673580
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673580
  goto L6735b3;  // @12_673580
  L6735ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673580
  L6735b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260868), &v, sizeof v); }  // @16_673580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260872), &v, sizeof v); }  // @17_673580
  return eax;  // @18_673580
}
PCREG(673580, lifted_673580);

extern "C" u32 lifted_6735d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260924), sizeof v); (u32)v; });  // @0_6735d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260928), sizeof v); (u32)v; });  // @1_6735d0
  if ((ecx & ecx) == 0) goto L6735ef;  // @2_6735d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6735d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260928), sizeof v); (u32)v; });  // @4_6735d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260924), sizeof v); (u32)v; });  // @5_6735d0
  goto L6735f4;  // @6_6735d0
  L6735ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6735d0
  L6735f4:;
  if ((eax & eax) == 0) goto L6735fd;  // @10_6735d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6735d0
  goto L673603;  // @12_6735d0
  L6735fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6735d0
  L673603:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260924), &v, sizeof v); }  // @16_6735d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260928), &v, sizeof v); }  // @17_6735d0
  return eax;  // @18_6735d0
}
PCREG(6735d0, lifted_6735d0);

extern "C" u32 lifted_673620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260980), sizeof v); (u32)v; });  // @0_673620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260984), sizeof v); (u32)v; });  // @1_673620
  if ((ecx & ecx) == 0) goto L67363f;  // @2_673620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260984), sizeof v); (u32)v; });  // @4_673620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7260980), sizeof v); (u32)v; });  // @5_673620
  goto L673644;  // @6_673620
  L67363f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673620
  L673644:;
  if ((eax & eax) == 0) goto L67364d;  // @10_673620
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673620
  goto L673653;  // @12_673620
  L67364d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673620
  L673653:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260980), &v, sizeof v); }  // @16_673620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7260984), &v, sizeof v); }  // @17_673620
  return eax;  // @18_673620
}
PCREG(673620, lifted_673620);

extern "C" u32 lifted_673670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261036), sizeof v); (u32)v; });  // @0_673670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261040), sizeof v); (u32)v; });  // @1_673670
  if ((ecx & ecx) == 0) goto L67368f;  // @2_673670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261040), sizeof v); (u32)v; });  // @4_673670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261036), sizeof v); (u32)v; });  // @5_673670
  goto L673694;  // @6_673670
  L67368f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673670
  L673694:;
  if ((eax & eax) == 0) goto L67369d;  // @10_673670
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673670
  goto L6736a3;  // @12_673670
  L67369d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673670
  L6736a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261036), &v, sizeof v); }  // @16_673670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261040), &v, sizeof v); }  // @17_673670
  return eax;  // @18_673670
}
PCREG(673670, lifted_673670);

extern "C" u32 lifted_6736c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261092), sizeof v); (u32)v; });  // @0_6736c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261096), sizeof v); (u32)v; });  // @1_6736c0
  if ((ecx & ecx) == 0) goto L6736df;  // @2_6736c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6736c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261096), sizeof v); (u32)v; });  // @4_6736c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261092), sizeof v); (u32)v; });  // @5_6736c0
  goto L6736e4;  // @6_6736c0
  L6736df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6736c0
  L6736e4:;
  if ((eax & eax) == 0) goto L6736ed;  // @10_6736c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6736c0
  goto L6736f3;  // @12_6736c0
  L6736ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6736c0
  L6736f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261092), &v, sizeof v); }  // @16_6736c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261096), &v, sizeof v); }  // @17_6736c0
  return eax;  // @18_6736c0
}
PCREG(6736c0, lifted_6736c0);

extern "C" u32 lifted_673710(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261148), sizeof v); (u32)v; });  // @0_673710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261152), sizeof v); (u32)v; });  // @1_673710
  if ((ecx & ecx) == 0) goto L67372f;  // @2_673710
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673710
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261152), sizeof v); (u32)v; });  // @4_673710
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261148), sizeof v); (u32)v; });  // @5_673710
  goto L673734;  // @6_673710
  L67372f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673710
  L673734:;
  if ((eax & eax) == 0) goto L67373d;  // @10_673710
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673710
  goto L673743;  // @12_673710
  L67373d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673710
  L673743:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261148), &v, sizeof v); }  // @16_673710
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261152), &v, sizeof v); }  // @17_673710
  return eax;  // @18_673710
}
PCREG(673710, lifted_673710);

extern "C" u32 lifted_673760(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261204), sizeof v); (u32)v; });  // @0_673760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261208), sizeof v); (u32)v; });  // @1_673760
  if ((ecx & ecx) == 0) goto L67377f;  // @2_673760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261208), sizeof v); (u32)v; });  // @4_673760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261204), sizeof v); (u32)v; });  // @5_673760
  goto L673784;  // @6_673760
  L67377f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673760
  L673784:;
  if ((eax & eax) == 0) goto L67378d;  // @10_673760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673760
  goto L673793;  // @12_673760
  L67378d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673760
  L673793:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261204), &v, sizeof v); }  // @16_673760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261208), &v, sizeof v); }  // @17_673760
  return eax;  // @18_673760
}
PCREG(673760, lifted_673760);

extern "C" u32 lifted_6737b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261260), sizeof v); (u32)v; });  // @0_6737b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261264), sizeof v); (u32)v; });  // @1_6737b0
  if ((ecx & ecx) == 0) goto L6737cf;  // @2_6737b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6737b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261264), sizeof v); (u32)v; });  // @4_6737b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261260), sizeof v); (u32)v; });  // @5_6737b0
  goto L6737d4;  // @6_6737b0
  L6737cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6737b0
  L6737d4:;
  if ((eax & eax) == 0) goto L6737dd;  // @10_6737b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6737b0
  goto L6737e3;  // @12_6737b0
  L6737dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6737b0
  L6737e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261260), &v, sizeof v); }  // @16_6737b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261264), &v, sizeof v); }  // @17_6737b0
  return eax;  // @18_6737b0
}
PCREG(6737b0, lifted_6737b0);

extern "C" u32 lifted_673800(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261332), sizeof v); (u32)v; });  // @0_673800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261336), sizeof v); (u32)v; });  // @1_673800
  if ((ecx & ecx) == 0) goto L67381f;  // @2_673800
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673800
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261336), sizeof v); (u32)v; });  // @4_673800
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261332), sizeof v); (u32)v; });  // @5_673800
  goto L673824;  // @6_673800
  L67381f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673800
  L673824:;
  if ((eax & eax) == 0) goto L67382d;  // @10_673800
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673800
  goto L673833;  // @12_673800
  L67382d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673800
  L673833:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261332), &v, sizeof v); }  // @16_673800
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261336), &v, sizeof v); }  // @17_673800
  return eax;  // @18_673800
}
PCREG(673800, lifted_673800);

extern "C" u32 lifted_673850(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261424), sizeof v); (u32)v; });  // @0_673850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261428), sizeof v); (u32)v; });  // @1_673850
  if ((ecx & ecx) == 0) goto L67386f;  // @2_673850
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673850
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261428), sizeof v); (u32)v; });  // @4_673850
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261424), sizeof v); (u32)v; });  // @5_673850
  goto L673874;  // @6_673850
  L67386f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673850
  L673874:;
  if ((eax & eax) == 0) goto L67387d;  // @10_673850
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673850
  goto L673883;  // @12_673850
  L67387d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673850
  L673883:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261424), &v, sizeof v); }  // @16_673850
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261428), &v, sizeof v); }  // @17_673850
  return eax;  // @18_673850
}
PCREG(673850, lifted_673850);

extern "C" u32 lifted_6738a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261480), sizeof v); (u32)v; });  // @0_6738a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261484), sizeof v); (u32)v; });  // @1_6738a0
  if ((ecx & ecx) == 0) goto L6738bf;  // @2_6738a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6738a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261484), sizeof v); (u32)v; });  // @4_6738a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261480), sizeof v); (u32)v; });  // @5_6738a0
  goto L6738c4;  // @6_6738a0
  L6738bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6738a0
  L6738c4:;
  if ((eax & eax) == 0) goto L6738cd;  // @10_6738a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6738a0
  goto L6738d3;  // @12_6738a0
  L6738cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6738a0
  L6738d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261480), &v, sizeof v); }  // @16_6738a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261484), &v, sizeof v); }  // @17_6738a0
  return eax;  // @18_6738a0
}
PCREG(6738a0, lifted_6738a0);

extern "C" u32 lifted_6738f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261536), sizeof v); (u32)v; });  // @0_6738f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261540), sizeof v); (u32)v; });  // @1_6738f0
  if ((ecx & ecx) == 0) goto L67390f;  // @2_6738f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6738f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261540), sizeof v); (u32)v; });  // @4_6738f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261536), sizeof v); (u32)v; });  // @5_6738f0
  goto L673914;  // @6_6738f0
  L67390f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6738f0
  L673914:;
  if ((eax & eax) == 0) goto L67391d;  // @10_6738f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6738f0
  goto L673923;  // @12_6738f0
  L67391d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6738f0
  L673923:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261536), &v, sizeof v); }  // @16_6738f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261540), &v, sizeof v); }  // @17_6738f0
  return eax;  // @18_6738f0
}
PCREG(6738f0, lifted_6738f0);

extern "C" u32 lifted_673940(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261592), sizeof v); (u32)v; });  // @0_673940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261596), sizeof v); (u32)v; });  // @1_673940
  if ((ecx & ecx) == 0) goto L67395f;  // @2_673940
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261596), sizeof v); (u32)v; });  // @4_673940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261592), sizeof v); (u32)v; });  // @5_673940
  goto L673964;  // @6_673940
  L67395f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673940
  L673964:;
  if ((eax & eax) == 0) goto L67396d;  // @10_673940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673940
  goto L673973;  // @12_673940
  L67396d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673940
  L673973:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261592), &v, sizeof v); }  // @16_673940
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261596), &v, sizeof v); }  // @17_673940
  return eax;  // @18_673940
}
PCREG(673940, lifted_673940);

extern "C" u32 lifted_673990(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261740), sizeof v); (u32)v; });  // @0_673990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261744), sizeof v); (u32)v; });  // @1_673990
  if ((ecx & ecx) == 0) goto L6739af;  // @2_673990
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673990
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261744), sizeof v); (u32)v; });  // @4_673990
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261740), sizeof v); (u32)v; });  // @5_673990
  goto L6739b4;  // @6_673990
  L6739af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673990
  L6739b4:;
  if ((eax & eax) == 0) goto L6739bd;  // @10_673990
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673990
  goto L6739c3;  // @12_673990
  L6739bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673990
  L6739c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261740), &v, sizeof v); }  // @16_673990
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261744), &v, sizeof v); }  // @17_673990
  return eax;  // @18_673990
}
PCREG(673990, lifted_673990);

extern "C" u32 lifted_6739e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261800), sizeof v); (u32)v; });  // @0_6739e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261804), sizeof v); (u32)v; });  // @1_6739e0
  if ((ecx & ecx) == 0) goto L6739ff;  // @2_6739e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6739e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261804), sizeof v); (u32)v; });  // @4_6739e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261800), sizeof v); (u32)v; });  // @5_6739e0
  goto L673a04;  // @6_6739e0
  L6739ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6739e0
  L673a04:;
  if ((eax & eax) == 0) goto L673a0d;  // @10_6739e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6739e0
  goto L673a13;  // @12_6739e0
  L673a0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6739e0
  L673a13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261800), &v, sizeof v); }  // @16_6739e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261804), &v, sizeof v); }  // @17_6739e0
  return eax;  // @18_6739e0
}
PCREG(6739e0, lifted_6739e0);

extern "C" u32 lifted_673a30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261912), sizeof v); (u32)v; });  // @0_673a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261916), sizeof v); (u32)v; });  // @1_673a30
  if ((ecx & ecx) == 0) goto L673a4f;  // @2_673a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261916), sizeof v); (u32)v; });  // @4_673a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261912), sizeof v); (u32)v; });  // @5_673a30
  goto L673a54;  // @6_673a30
  L673a4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673a30
  L673a54:;
  if ((eax & eax) == 0) goto L673a5d;  // @10_673a30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673a30
  goto L673a63;  // @12_673a30
  L673a5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673a30
  L673a63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261912), &v, sizeof v); }  // @16_673a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261916), &v, sizeof v); }  // @17_673a30
  return eax;  // @18_673a30
}
PCREG(673a30, lifted_673a30);

extern "C" u32 lifted_673a80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262024), sizeof v); (u32)v; });  // @0_673a80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262028), sizeof v); (u32)v; });  // @1_673a80
  if ((ecx & ecx) == 0) goto L673a9f;  // @2_673a80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673a80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262028), sizeof v); (u32)v; });  // @4_673a80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262024), sizeof v); (u32)v; });  // @5_673a80
  goto L673aa4;  // @6_673a80
  L673a9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673a80
  L673aa4:;
  if ((eax & eax) == 0) goto L673aad;  // @10_673a80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673a80
  goto L673ab3;  // @12_673a80
  L673aad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673a80
  L673ab3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262024), &v, sizeof v); }  // @16_673a80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262028), &v, sizeof v); }  // @17_673a80
  return eax;  // @18_673a80
}
PCREG(673a80, lifted_673a80);

extern "C" u32 lifted_673ad0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261968), sizeof v); (u32)v; });  // @0_673ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261972), sizeof v); (u32)v; });  // @1_673ad0
  if ((ecx & ecx) == 0) goto L673aef;  // @2_673ad0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673ad0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261972), sizeof v); (u32)v; });  // @4_673ad0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261968), sizeof v); (u32)v; });  // @5_673ad0
  goto L673af4;  // @6_673ad0
  L673aef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673ad0
  L673af4:;
  if ((eax & eax) == 0) goto L673afd;  // @10_673ad0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673ad0
  goto L673b03;  // @12_673ad0
  L673afd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673ad0
  L673b03:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261968), &v, sizeof v); }  // @16_673ad0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261972), &v, sizeof v); }  // @17_673ad0
  return eax;  // @18_673ad0
}
PCREG(673ad0, lifted_673ad0);

extern "C" u32 lifted_673b20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261856), sizeof v); (u32)v; });  // @0_673b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261860), sizeof v); (u32)v; });  // @1_673b20
  if ((ecx & ecx) == 0) goto L673b3f;  // @2_673b20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261860), sizeof v); (u32)v; });  // @4_673b20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7261856), sizeof v); (u32)v; });  // @5_673b20
  goto L673b44;  // @6_673b20
  L673b3f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673b20
  L673b44:;
  if ((eax & eax) == 0) goto L673b4d;  // @10_673b20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673b20
  goto L673b53;  // @12_673b20
  L673b4d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673b20
  L673b53:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261856), &v, sizeof v); }  // @16_673b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7261860), &v, sizeof v); }  // @17_673b20
  return eax;  // @18_673b20
}
PCREG(673b20, lifted_673b20);

extern "C" u32 lifted_673b70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262092), sizeof v); (u32)v; });  // @0_673b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262096), sizeof v); (u32)v; });  // @1_673b70
  if ((ecx & ecx) == 0) goto L673b8f;  // @2_673b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262096), sizeof v); (u32)v; });  // @4_673b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262092), sizeof v); (u32)v; });  // @5_673b70
  goto L673b94;  // @6_673b70
  L673b8f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673b70
  L673b94:;
  if ((eax & eax) == 0) goto L673b9d;  // @10_673b70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673b70
  goto L673ba3;  // @12_673b70
  L673b9d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673b70
  L673ba3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262092), &v, sizeof v); }  // @16_673b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262096), &v, sizeof v); }  // @17_673b70
  return eax;  // @18_673b70
}
PCREG(673b70, lifted_673b70);

extern "C" u32 lifted_673bc0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262152), sizeof v); (u32)v; });  // @0_673bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262156), sizeof v); (u32)v; });  // @1_673bc0
  if ((ecx & ecx) == 0) goto L673bdf;  // @2_673bc0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673bc0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262156), sizeof v); (u32)v; });  // @4_673bc0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262152), sizeof v); (u32)v; });  // @5_673bc0
  goto L673be4;  // @6_673bc0
  L673bdf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673bc0
  L673be4:;
  if ((eax & eax) == 0) goto L673bed;  // @10_673bc0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673bc0
  goto L673bf3;  // @12_673bc0
  L673bed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673bc0
  L673bf3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262152), &v, sizeof v); }  // @16_673bc0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262156), &v, sizeof v); }  // @17_673bc0
  return eax;  // @18_673bc0
}
PCREG(673bc0, lifted_673bc0);

extern "C" u32 lifted_673c10(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262204), sizeof v); (u32)v; });  // @0_673c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262208), sizeof v); (u32)v; });  // @1_673c10
  if ((ecx & ecx) == 0) goto L673c2f;  // @2_673c10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673c10
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262208), sizeof v); (u32)v; });  // @4_673c10
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262204), sizeof v); (u32)v; });  // @5_673c10
  goto L673c34;  // @6_673c10
  L673c2f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673c10
  L673c34:;
  if ((eax & eax) == 0) goto L673c3d;  // @10_673c10
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673c10
  goto L673c43;  // @12_673c10
  L673c3d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673c10
  L673c43:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262204), &v, sizeof v); }  // @16_673c10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262208), &v, sizeof v); }  // @17_673c10
  return eax;  // @18_673c10
}
PCREG(673c10, lifted_673c10);

extern "C" u32 lifted_673c60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262320), sizeof v); (u32)v; });  // @0_673c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262324), sizeof v); (u32)v; });  // @1_673c60
  if ((ecx & ecx) == 0) goto L673c7f;  // @2_673c60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262324), sizeof v); (u32)v; });  // @4_673c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262320), sizeof v); (u32)v; });  // @5_673c60
  goto L673c84;  // @6_673c60
  L673c7f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673c60
  L673c84:;
  if ((eax & eax) == 0) goto L673c8d;  // @10_673c60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673c60
  goto L673c93;  // @12_673c60
  L673c8d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673c60
  L673c93:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262320), &v, sizeof v); }  // @16_673c60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262324), &v, sizeof v); }  // @17_673c60
  return eax;  // @18_673c60
}
PCREG(673c60, lifted_673c60);

extern "C" u32 lifted_673cb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262380), sizeof v); (u32)v; });  // @0_673cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262384), sizeof v); (u32)v; });  // @1_673cb0
  if ((ecx & ecx) == 0) goto L673ccf;  // @2_673cb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262384), sizeof v); (u32)v; });  // @4_673cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262380), sizeof v); (u32)v; });  // @5_673cb0
  goto L673cd4;  // @6_673cb0
  L673ccf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673cb0
  L673cd4:;
  if ((eax & eax) == 0) goto L673cdd;  // @10_673cb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673cb0
  goto L673ce3;  // @12_673cb0
  L673cdd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673cb0
  L673ce3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262380), &v, sizeof v); }  // @16_673cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262384), &v, sizeof v); }  // @17_673cb0
  return eax;  // @18_673cb0
}
PCREG(673cb0, lifted_673cb0);

extern "C" u32 lifted_673d00(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262736), sizeof v); (u32)v; });  // @0_673d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262740), sizeof v); (u32)v; });  // @1_673d00
  if ((ecx & ecx) == 0) goto L673d1f;  // @2_673d00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673d00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262740), sizeof v); (u32)v; });  // @4_673d00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262736), sizeof v); (u32)v; });  // @5_673d00
  goto L673d24;  // @6_673d00
  L673d1f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673d00
  L673d24:;
  if ((eax & eax) == 0) goto L673d2d;  // @10_673d00
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673d00
  goto L673d33;  // @12_673d00
  L673d2d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673d00
  L673d33:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262736), &v, sizeof v); }  // @16_673d00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262740), &v, sizeof v); }  // @17_673d00
  return eax;  // @18_673d00
}
PCREG(673d00, lifted_673d00);

extern "C" u32 lifted_673d50(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262796), sizeof v); (u32)v; });  // @0_673d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262800), sizeof v); (u32)v; });  // @1_673d50
  if ((ecx & ecx) == 0) goto L673d6f;  // @2_673d50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673d50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262800), sizeof v); (u32)v; });  // @4_673d50
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262796), sizeof v); (u32)v; });  // @5_673d50
  goto L673d74;  // @6_673d50
  L673d6f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673d50
  L673d74:;
  if ((eax & eax) == 0) goto L673d7d;  // @10_673d50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673d50
  goto L673d83;  // @12_673d50
  L673d7d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673d50
  L673d83:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262796), &v, sizeof v); }  // @16_673d50
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262800), &v, sizeof v); }  // @17_673d50
  return eax;  // @18_673d50
}
PCREG(673d50, lifted_673d50);

extern "C" u32 lifted_673da0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262852), sizeof v); (u32)v; });  // @0_673da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262856), sizeof v); (u32)v; });  // @1_673da0
  if ((ecx & ecx) == 0) goto L673dbf;  // @2_673da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262856), sizeof v); (u32)v; });  // @4_673da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262852), sizeof v); (u32)v; });  // @5_673da0
  goto L673dc4;  // @6_673da0
  L673dbf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673da0
  L673dc4:;
  if ((eax & eax) == 0) goto L673dcd;  // @10_673da0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673da0
  goto L673dd3;  // @12_673da0
  L673dcd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673da0
  L673dd3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262852), &v, sizeof v); }  // @16_673da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262856), &v, sizeof v); }  // @17_673da0
  return eax;  // @18_673da0
}
PCREG(673da0, lifted_673da0);

extern "C" u32 lifted_673df0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262904), sizeof v); (u32)v; });  // @0_673df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262908), sizeof v); (u32)v; });  // @1_673df0
  if ((ecx & ecx) == 0) goto L673e0f;  // @2_673df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262908), sizeof v); (u32)v; });  // @4_673df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262904), sizeof v); (u32)v; });  // @5_673df0
  goto L673e14;  // @6_673df0
  L673e0f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673df0
  L673e14:;
  if ((eax & eax) == 0) goto L673e1d;  // @10_673df0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673df0
  goto L673e23;  // @12_673df0
  L673e1d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673df0
  L673e23:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262904), &v, sizeof v); }  // @16_673df0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262908), &v, sizeof v); }  // @17_673df0
  return eax;  // @18_673df0
}
PCREG(673df0, lifted_673df0);

extern "C" u32 lifted_673e40(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262960), sizeof v); (u32)v; });  // @0_673e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262964), sizeof v); (u32)v; });  // @1_673e40
  if ((ecx & ecx) == 0) goto L673e5f;  // @2_673e40
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673e40
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262964), sizeof v); (u32)v; });  // @4_673e40
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7262960), sizeof v); (u32)v; });  // @5_673e40
  goto L673e64;  // @6_673e40
  L673e5f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673e40
  L673e64:;
  if ((eax & eax) == 0) goto L673e6d;  // @10_673e40
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673e40
  goto L673e73;  // @12_673e40
  L673e6d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673e40
  L673e73:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262960), &v, sizeof v); }  // @16_673e40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7262964), &v, sizeof v); }  // @17_673e40
  return eax;  // @18_673e40
}
PCREG(673e40, lifted_673e40);

extern "C" u32 lifted_673e90(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7263012), sizeof v); (u32)v; });  // @0_673e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7263016), sizeof v); (u32)v; });  // @1_673e90
  if ((ecx & ecx) == 0) goto L673eaf;  // @2_673e90
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673e90
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7263016), sizeof v); (u32)v; });  // @4_673e90
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7263012), sizeof v); (u32)v; });  // @5_673e90
  goto L673eb4;  // @6_673e90
  L673eaf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673e90
  L673eb4:;
  if ((eax & eax) == 0) goto L673ebd;  // @10_673e90
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673e90
  goto L673ec3;  // @12_673e90
  L673ebd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673e90
  L673ec3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7263012), &v, sizeof v); }  // @16_673e90
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7263016), &v, sizeof v); }  // @17_673e90
  return eax;  // @18_673e90
}
PCREG(673e90, lifted_673e90);

extern "C" u32 lifted_673ee0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7268808), sizeof v); (u32)v; });  // @0_673ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7268812), sizeof v); (u32)v; });  // @1_673ee0
  if ((ecx & ecx) == 0) goto L673eff;  // @2_673ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7268812), sizeof v); (u32)v; });  // @4_673ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7268808), sizeof v); (u32)v; });  // @5_673ee0
  goto L673f04;  // @6_673ee0
  L673eff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673ee0
  L673f04:;
  if ((eax & eax) == 0) goto L673f0d;  // @10_673ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673ee0
  goto L673f13;  // @12_673ee0
  L673f0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673ee0
  L673f13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7268808), &v, sizeof v); }  // @16_673ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7268812), &v, sizeof v); }  // @17_673ee0
  return eax;  // @18_673ee0
}
PCREG(673ee0, lifted_673ee0);

extern "C" u32 lifted_673f30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269032), sizeof v); (u32)v; });  // @0_673f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269036), sizeof v); (u32)v; });  // @1_673f30
  if ((ecx & ecx) == 0) goto L673f4f;  // @2_673f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269036), sizeof v); (u32)v; });  // @4_673f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269032), sizeof v); (u32)v; });  // @5_673f30
  goto L673f54;  // @6_673f30
  L673f4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673f30
  L673f54:;
  if ((eax & eax) == 0) goto L673f5d;  // @10_673f30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673f30
  goto L673f63;  // @12_673f30
  L673f5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673f30
  L673f63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269032), &v, sizeof v); }  // @16_673f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269036), &v, sizeof v); }  // @17_673f30
  return eax;  // @18_673f30
}
PCREG(673f30, lifted_673f30);

extern "C" u32 lifted_673f80(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269088), sizeof v); (u32)v; });  // @0_673f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269092), sizeof v); (u32)v; });  // @1_673f80
  if ((ecx & ecx) == 0) goto L673f9f;  // @2_673f80
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673f80
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269092), sizeof v); (u32)v; });  // @4_673f80
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269088), sizeof v); (u32)v; });  // @5_673f80
  goto L673fa4;  // @6_673f80
  L673f9f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673f80
  L673fa4:;
  if ((eax & eax) == 0) goto L673fad;  // @10_673f80
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673f80
  goto L673fb3;  // @12_673f80
  L673fad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673f80
  L673fb3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269088), &v, sizeof v); }  // @16_673f80
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269092), &v, sizeof v); }  // @17_673f80
  return eax;  // @18_673f80
}
PCREG(673f80, lifted_673f80);

extern "C" u32 lifted_673fe0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269144), sizeof v); (u32)v; });  // @0_673fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269148), sizeof v); (u32)v; });  // @1_673fe0
  if ((ecx & ecx) == 0) goto L673fff;  // @2_673fe0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_673fe0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269148), sizeof v); (u32)v; });  // @4_673fe0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269144), sizeof v); (u32)v; });  // @5_673fe0
  goto L674004;  // @6_673fe0
  L673fff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_673fe0
  L674004:;
  if ((eax & eax) == 0) goto L67400d;  // @10_673fe0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_673fe0
  goto L674013;  // @12_673fe0
  L67400d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_673fe0
  L674013:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269144), &v, sizeof v); }  // @16_673fe0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269148), &v, sizeof v); }  // @17_673fe0
  return eax;  // @18_673fe0
}
PCREG(673fe0, lifted_673fe0);

extern "C" u32 lifted_674030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269200), sizeof v); (u32)v; });  // @0_674030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269204), sizeof v); (u32)v; });  // @1_674030
  if ((ecx & ecx) == 0) goto L67404f;  // @2_674030
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269204), sizeof v); (u32)v; });  // @4_674030
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269200), sizeof v); (u32)v; });  // @5_674030
  goto L674054;  // @6_674030
  L67404f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674030
  L674054:;
  if ((eax & eax) == 0) goto L67405d;  // @10_674030
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674030
  goto L674063;  // @12_674030
  L67405d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674030
  L674063:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269200), &v, sizeof v); }  // @16_674030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269204), &v, sizeof v); }  // @17_674030
  return eax;  // @18_674030
}
PCREG(674030, lifted_674030);

extern "C" u32 lifted_674120(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269368), sizeof v); (u32)v; });  // @0_674120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269372), sizeof v); (u32)v; });  // @1_674120
  if ((ecx & ecx) == 0) goto L67413f;  // @2_674120
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674120
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269372), sizeof v); (u32)v; });  // @4_674120
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269368), sizeof v); (u32)v; });  // @5_674120
  goto L674144;  // @6_674120
  L67413f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674120
  L674144:;
  if ((eax & eax) == 0) goto L67414d;  // @10_674120
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674120
  goto L674153;  // @12_674120
  L67414d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674120
  L674153:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269368), &v, sizeof v); }  // @16_674120
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269372), &v, sizeof v); }  // @17_674120
  return eax;  // @18_674120
}
PCREG(674120, lifted_674120);

extern "C" u32 lifted_674170(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269424), sizeof v); (u32)v; });  // @0_674170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269428), sizeof v); (u32)v; });  // @1_674170
  if ((ecx & ecx) == 0) goto L67418f;  // @2_674170
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269428), sizeof v); (u32)v; });  // @4_674170
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269424), sizeof v); (u32)v; });  // @5_674170
  goto L674194;  // @6_674170
  L67418f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674170
  L674194:;
  if ((eax & eax) == 0) goto L67419d;  // @10_674170
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674170
  goto L6741a3;  // @12_674170
  L67419d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674170
  L6741a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269424), &v, sizeof v); }  // @16_674170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269428), &v, sizeof v); }  // @17_674170
  return eax;  // @18_674170
}
PCREG(674170, lifted_674170);

extern "C" u32 lifted_674260(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269592), sizeof v); (u32)v; });  // @0_674260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269596), sizeof v); (u32)v; });  // @1_674260
  if ((ecx & ecx) == 0) goto L67427f;  // @2_674260
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674260
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269596), sizeof v); (u32)v; });  // @4_674260
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269592), sizeof v); (u32)v; });  // @5_674260
  goto L674284;  // @6_674260
  L67427f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674260
  L674284:;
  if ((eax & eax) == 0) goto L67428d;  // @10_674260
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674260
  goto L674293;  // @12_674260
  L67428d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674260
  L674293:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269592), &v, sizeof v); }  // @16_674260
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269596), &v, sizeof v); }  // @17_674260
  return eax;  // @18_674260
}
PCREG(674260, lifted_674260);

extern "C" u32 lifted_6742b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269648), sizeof v); (u32)v; });  // @0_6742b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269652), sizeof v); (u32)v; });  // @1_6742b0
  if ((ecx & ecx) == 0) goto L6742cf;  // @2_6742b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6742b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269652), sizeof v); (u32)v; });  // @4_6742b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269648), sizeof v); (u32)v; });  // @5_6742b0
  goto L6742d4;  // @6_6742b0
  L6742cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6742b0
  L6742d4:;
  if ((eax & eax) == 0) goto L6742dd;  // @10_6742b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6742b0
  goto L6742e3;  // @12_6742b0
  L6742dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6742b0
  L6742e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269648), &v, sizeof v); }  // @16_6742b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269652), &v, sizeof v); }  // @17_6742b0
  return eax;  // @18_6742b0
}
PCREG(6742b0, lifted_6742b0);

extern "C" u32 lifted_6743a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269816), sizeof v); (u32)v; });  // @0_6743a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269820), sizeof v); (u32)v; });  // @1_6743a0
  if ((ecx & ecx) == 0) goto L6743bf;  // @2_6743a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6743a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269820), sizeof v); (u32)v; });  // @4_6743a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269816), sizeof v); (u32)v; });  // @5_6743a0
  goto L6743c4;  // @6_6743a0
  L6743bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6743a0
  L6743c4:;
  if ((eax & eax) == 0) goto L6743cd;  // @10_6743a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6743a0
  goto L6743d3;  // @12_6743a0
  L6743cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6743a0
  L6743d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269816), &v, sizeof v); }  // @16_6743a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269820), &v, sizeof v); }  // @17_6743a0
  return eax;  // @18_6743a0
}
PCREG(6743a0, lifted_6743a0);

extern "C" u32 lifted_6743f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269872), sizeof v); (u32)v; });  // @0_6743f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269876), sizeof v); (u32)v; });  // @1_6743f0
  if ((ecx & ecx) == 0) goto L67440f;  // @2_6743f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6743f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269876), sizeof v); (u32)v; });  // @4_6743f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7269872), sizeof v); (u32)v; });  // @5_6743f0
  goto L674414;  // @6_6743f0
  L67440f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6743f0
  L674414:;
  if ((eax & eax) == 0) goto L67441d;  // @10_6743f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6743f0
  goto L674423;  // @12_6743f0
  L67441d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6743f0
  L674423:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269872), &v, sizeof v); }  // @16_6743f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7269876), &v, sizeof v); }  // @17_6743f0
  return eax;  // @18_6743f0
}
PCREG(6743f0, lifted_6743f0);

extern "C" u32 lifted_6744e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270040), sizeof v); (u32)v; });  // @0_6744e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270044), sizeof v); (u32)v; });  // @1_6744e0
  if ((ecx & ecx) == 0) goto L6744ff;  // @2_6744e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6744e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270044), sizeof v); (u32)v; });  // @4_6744e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270040), sizeof v); (u32)v; });  // @5_6744e0
  goto L674504;  // @6_6744e0
  L6744ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6744e0
  L674504:;
  if ((eax & eax) == 0) goto L67450d;  // @10_6744e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6744e0
  goto L674513;  // @12_6744e0
  L67450d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6744e0
  L674513:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270040), &v, sizeof v); }  // @16_6744e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270044), &v, sizeof v); }  // @17_6744e0
  return eax;  // @18_6744e0
}
PCREG(6744e0, lifted_6744e0);

extern "C" u32 lifted_674530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270096), sizeof v); (u32)v; });  // @0_674530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270100), sizeof v); (u32)v; });  // @1_674530
  if ((ecx & ecx) == 0) goto L67454f;  // @2_674530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270100), sizeof v); (u32)v; });  // @4_674530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270096), sizeof v); (u32)v; });  // @5_674530
  goto L674554;  // @6_674530
  L67454f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674530
  L674554:;
  if ((eax & eax) == 0) goto L67455d;  // @10_674530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674530
  goto L674563;  // @12_674530
  L67455d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674530
  L674563:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270096), &v, sizeof v); }  // @16_674530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270100), &v, sizeof v); }  // @17_674530
  return eax;  // @18_674530
}
PCREG(674530, lifted_674530);

extern "C" u32 lifted_674620(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270304), sizeof v); (u32)v; });  // @0_674620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270308), sizeof v); (u32)v; });  // @1_674620
  if ((ecx & ecx) == 0) goto L67463f;  // @2_674620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270308), sizeof v); (u32)v; });  // @4_674620
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270304), sizeof v); (u32)v; });  // @5_674620
  goto L674644;  // @6_674620
  L67463f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674620
  L674644:;
  if ((eax & eax) == 0) goto L67464d;  // @10_674620
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674620
  goto L674653;  // @12_674620
  L67464d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674620
  L674653:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270304), &v, sizeof v); }  // @16_674620
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270308), &v, sizeof v); }  // @17_674620
  return eax;  // @18_674620
}
PCREG(674620, lifted_674620);

extern "C" u32 lifted_674670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270360), sizeof v); (u32)v; });  // @0_674670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270364), sizeof v); (u32)v; });  // @1_674670
  if ((ecx & ecx) == 0) goto L67468f;  // @2_674670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270364), sizeof v); (u32)v; });  // @4_674670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270360), sizeof v); (u32)v; });  // @5_674670
  goto L674694;  // @6_674670
  L67468f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674670
  L674694:;
  if ((eax & eax) == 0) goto L67469d;  // @10_674670
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674670
  goto L6746a3;  // @12_674670
  L67469d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674670
  L6746a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270360), &v, sizeof v); }  // @16_674670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270364), &v, sizeof v); }  // @17_674670
  return eax;  // @18_674670
}
PCREG(674670, lifted_674670);

extern "C" u32 lifted_674760(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270528), sizeof v); (u32)v; });  // @0_674760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270532), sizeof v); (u32)v; });  // @1_674760
  if ((ecx & ecx) == 0) goto L67477f;  // @2_674760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270532), sizeof v); (u32)v; });  // @4_674760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270528), sizeof v); (u32)v; });  // @5_674760
  goto L674784;  // @6_674760
  L67477f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674760
  L674784:;
  if ((eax & eax) == 0) goto L67478d;  // @10_674760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674760
  goto L674793;  // @12_674760
  L67478d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674760
  L674793:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270528), &v, sizeof v); }  // @16_674760
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270532), &v, sizeof v); }  // @17_674760
  return eax;  // @18_674760
}
PCREG(674760, lifted_674760);

extern "C" u32 lifted_6747b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270584), sizeof v); (u32)v; });  // @0_6747b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270588), sizeof v); (u32)v; });  // @1_6747b0
  if ((ecx & ecx) == 0) goto L6747cf;  // @2_6747b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6747b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270588), sizeof v); (u32)v; });  // @4_6747b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270584), sizeof v); (u32)v; });  // @5_6747b0
  goto L6747d4;  // @6_6747b0
  L6747cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6747b0
  L6747d4:;
  if ((eax & eax) == 0) goto L6747dd;  // @10_6747b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6747b0
  goto L6747e3;  // @12_6747b0
  L6747dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6747b0
  L6747e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270584), &v, sizeof v); }  // @16_6747b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270588), &v, sizeof v); }  // @17_6747b0
  return eax;  // @18_6747b0
}
PCREG(6747b0, lifted_6747b0);

extern "C" u32 lifted_6748a0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270752), sizeof v); (u32)v; });  // @0_6748a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270756), sizeof v); (u32)v; });  // @1_6748a0
  if ((ecx & ecx) == 0) goto L6748bf;  // @2_6748a0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6748a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270756), sizeof v); (u32)v; });  // @4_6748a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270752), sizeof v); (u32)v; });  // @5_6748a0
  goto L6748c4;  // @6_6748a0
  L6748bf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6748a0
  L6748c4:;
  if ((eax & eax) == 0) goto L6748cd;  // @10_6748a0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6748a0
  goto L6748d3;  // @12_6748a0
  L6748cd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6748a0
  L6748d3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270752), &v, sizeof v); }  // @16_6748a0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270756), &v, sizeof v); }  // @17_6748a0
  return eax;  // @18_6748a0
}
PCREG(6748a0, lifted_6748a0);

extern "C" u32 lifted_6748f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270808), sizeof v); (u32)v; });  // @0_6748f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270812), sizeof v); (u32)v; });  // @1_6748f0
  if ((ecx & ecx) == 0) goto L67490f;  // @2_6748f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6748f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270812), sizeof v); (u32)v; });  // @4_6748f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270808), sizeof v); (u32)v; });  // @5_6748f0
  goto L674914;  // @6_6748f0
  L67490f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6748f0
  L674914:;
  if ((eax & eax) == 0) goto L67491d;  // @10_6748f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6748f0
  goto L674923;  // @12_6748f0
  L67491d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6748f0
  L674923:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270808), &v, sizeof v); }  // @16_6748f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270812), &v, sizeof v); }  // @17_6748f0
  return eax;  // @18_6748f0
}
PCREG(6748f0, lifted_6748f0);

extern "C" u32 lifted_6749e0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270976), sizeof v); (u32)v; });  // @0_6749e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270980), sizeof v); (u32)v; });  // @1_6749e0
  if ((ecx & ecx) == 0) goto L6749ff;  // @2_6749e0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6749e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270980), sizeof v); (u32)v; });  // @4_6749e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7270976), sizeof v); (u32)v; });  // @5_6749e0
  goto L674a04;  // @6_6749e0
  L6749ff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6749e0
  L674a04:;
  if ((eax & eax) == 0) goto L674a0d;  // @10_6749e0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6749e0
  goto L674a13;  // @12_6749e0
  L674a0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6749e0
  L674a13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270976), &v, sizeof v); }  // @16_6749e0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7270980), &v, sizeof v); }  // @17_6749e0
  return eax;  // @18_6749e0
}
PCREG(6749e0, lifted_6749e0);

extern "C" u32 lifted_674a30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271032), sizeof v); (u32)v; });  // @0_674a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271036), sizeof v); (u32)v; });  // @1_674a30
  if ((ecx & ecx) == 0) goto L674a4f;  // @2_674a30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674a30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271036), sizeof v); (u32)v; });  // @4_674a30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271032), sizeof v); (u32)v; });  // @5_674a30
  goto L674a54;  // @6_674a30
  L674a4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674a30
  L674a54:;
  if ((eax & eax) == 0) goto L674a5d;  // @10_674a30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674a30
  goto L674a63;  // @12_674a30
  L674a5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674a30
  L674a63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271032), &v, sizeof v); }  // @16_674a30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271036), &v, sizeof v); }  // @17_674a30
  return eax;  // @18_674a30
}
PCREG(674a30, lifted_674a30);

extern "C" u32 lifted_674b20(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271212), sizeof v); (u32)v; });  // @0_674b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271216), sizeof v); (u32)v; });  // @1_674b20
  if ((ecx & ecx) == 0) goto L674b3f;  // @2_674b20
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674b20
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271216), sizeof v); (u32)v; });  // @4_674b20
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271212), sizeof v); (u32)v; });  // @5_674b20
  goto L674b44;  // @6_674b20
  L674b3f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674b20
  L674b44:;
  if ((eax & eax) == 0) goto L674b4d;  // @10_674b20
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674b20
  goto L674b53;  // @12_674b20
  L674b4d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674b20
  L674b53:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271212), &v, sizeof v); }  // @16_674b20
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271216), &v, sizeof v); }  // @17_674b20
  return eax;  // @18_674b20
}
PCREG(674b20, lifted_674b20);

extern "C" u32 lifted_674b70(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271268), sizeof v); (u32)v; });  // @0_674b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271272), sizeof v); (u32)v; });  // @1_674b70
  if ((ecx & ecx) == 0) goto L674b8f;  // @2_674b70
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674b70
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271272), sizeof v); (u32)v; });  // @4_674b70
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271268), sizeof v); (u32)v; });  // @5_674b70
  goto L674b94;  // @6_674b70
  L674b8f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674b70
  L674b94:;
  if ((eax & eax) == 0) goto L674b9d;  // @10_674b70
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674b70
  goto L674ba3;  // @12_674b70
  L674b9d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674b70
  L674ba3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271268), &v, sizeof v); }  // @16_674b70
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271272), &v, sizeof v); }  // @17_674b70
  return eax;  // @18_674b70
}
PCREG(674b70, lifted_674b70);

extern "C" u32 lifted_674c60(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271436), sizeof v); (u32)v; });  // @0_674c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271440), sizeof v); (u32)v; });  // @1_674c60
  if ((ecx & ecx) == 0) goto L674c7f;  // @2_674c60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674c60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271440), sizeof v); (u32)v; });  // @4_674c60
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271436), sizeof v); (u32)v; });  // @5_674c60
  goto L674c84;  // @6_674c60
  L674c7f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674c60
  L674c84:;
  if ((eax & eax) == 0) goto L674c8d;  // @10_674c60
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674c60
  goto L674c93;  // @12_674c60
  L674c8d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674c60
  L674c93:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271436), &v, sizeof v); }  // @16_674c60
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271440), &v, sizeof v); }  // @17_674c60
  return eax;  // @18_674c60
}
PCREG(674c60, lifted_674c60);

extern "C" u32 lifted_674cb0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271492), sizeof v); (u32)v; });  // @0_674cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271496), sizeof v); (u32)v; });  // @1_674cb0
  if ((ecx & ecx) == 0) goto L674ccf;  // @2_674cb0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674cb0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271496), sizeof v); (u32)v; });  // @4_674cb0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271492), sizeof v); (u32)v; });  // @5_674cb0
  goto L674cd4;  // @6_674cb0
  L674ccf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674cb0
  L674cd4:;
  if ((eax & eax) == 0) goto L674cdd;  // @10_674cb0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674cb0
  goto L674ce3;  // @12_674cb0
  L674cdd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674cb0
  L674ce3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271492), &v, sizeof v); }  // @16_674cb0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271496), &v, sizeof v); }  // @17_674cb0
  return eax;  // @18_674cb0
}
PCREG(674cb0, lifted_674cb0);

extern "C" u32 lifted_674da0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271660), sizeof v); (u32)v; });  // @0_674da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271664), sizeof v); (u32)v; });  // @1_674da0
  if ((ecx & ecx) == 0) goto L674dbf;  // @2_674da0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674da0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271664), sizeof v); (u32)v; });  // @4_674da0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271660), sizeof v); (u32)v; });  // @5_674da0
  goto L674dc4;  // @6_674da0
  L674dbf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674da0
  L674dc4:;
  if ((eax & eax) == 0) goto L674dcd;  // @10_674da0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674da0
  goto L674dd3;  // @12_674da0
  L674dcd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674da0
  L674dd3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271660), &v, sizeof v); }  // @16_674da0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271664), &v, sizeof v); }  // @17_674da0
  return eax;  // @18_674da0
}
PCREG(674da0, lifted_674da0);

extern "C" u32 lifted_674df0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271716), sizeof v); (u32)v; });  // @0_674df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271720), sizeof v); (u32)v; });  // @1_674df0
  if ((ecx & ecx) == 0) goto L674e0f;  // @2_674df0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674df0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271720), sizeof v); (u32)v; });  // @4_674df0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271716), sizeof v); (u32)v; });  // @5_674df0
  goto L674e14;  // @6_674df0
  L674e0f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674df0
  L674e14:;
  if ((eax & eax) == 0) goto L674e1d;  // @10_674df0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674df0
  goto L674e23;  // @12_674df0
  L674e1d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674df0
  L674e23:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271716), &v, sizeof v); }  // @16_674df0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271720), &v, sizeof v); }  // @17_674df0
  return eax;  // @18_674df0
}
PCREG(674df0, lifted_674df0);

extern "C" u32 lifted_674ee0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271880), sizeof v); (u32)v; });  // @0_674ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271884), sizeof v); (u32)v; });  // @1_674ee0
  if ((ecx & ecx) == 0) goto L674eff;  // @2_674ee0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674ee0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271884), sizeof v); (u32)v; });  // @4_674ee0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271880), sizeof v); (u32)v; });  // @5_674ee0
  goto L674f04;  // @6_674ee0
  L674eff:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674ee0
  L674f04:;
  if ((eax & eax) == 0) goto L674f0d;  // @10_674ee0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674ee0
  goto L674f13;  // @12_674ee0
  L674f0d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674ee0
  L674f13:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271880), &v, sizeof v); }  // @16_674ee0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271884), &v, sizeof v); }  // @17_674ee0
  return eax;  // @18_674ee0
}
PCREG(674ee0, lifted_674ee0);

extern "C" u32 lifted_674f30(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271936), sizeof v); (u32)v; });  // @0_674f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271940), sizeof v); (u32)v; });  // @1_674f30
  if ((ecx & ecx) == 0) goto L674f4f;  // @2_674f30
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_674f30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271940), sizeof v); (u32)v; });  // @4_674f30
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7271936), sizeof v); (u32)v; });  // @5_674f30
  goto L674f54;  // @6_674f30
  L674f4f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_674f30
  L674f54:;
  if ((eax & eax) == 0) goto L674f5d;  // @10_674f30
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_674f30
  goto L674f63;  // @12_674f30
  L674f5d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_674f30
  L674f63:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271936), &v, sizeof v); }  // @16_674f30
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7271940), &v, sizeof v); }  // @17_674f30
  return eax;  // @18_674f30
}
PCREG(674f30, lifted_674f30);

extern "C" u32 lifted_675030(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272256), sizeof v); (u32)v; });  // @0_675030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272260), sizeof v); (u32)v; });  // @1_675030
  if ((ecx & ecx) == 0) goto L67504f;  // @2_675030
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675030
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272260), sizeof v); (u32)v; });  // @4_675030
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272256), sizeof v); (u32)v; });  // @5_675030
  goto L675054;  // @6_675030
  L67504f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675030
  L675054:;
  if ((eax & eax) == 0) goto L67505d;  // @10_675030
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675030
  goto L675063;  // @12_675030
  L67505d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675030
  L675063:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272256), &v, sizeof v); }  // @16_675030
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272260), &v, sizeof v); }  // @17_675030
  return eax;  // @18_675030
}
PCREG(675030, lifted_675030);

extern "C" u32 lifted_675080(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272312), sizeof v); (u32)v; });  // @0_675080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272316), sizeof v); (u32)v; });  // @1_675080
  if ((ecx & ecx) == 0) goto L67509f;  // @2_675080
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675080
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272316), sizeof v); (u32)v; });  // @4_675080
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272312), sizeof v); (u32)v; });  // @5_675080
  goto L6750a4;  // @6_675080
  L67509f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675080
  L6750a4:;
  if ((eax & eax) == 0) goto L6750ad;  // @10_675080
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675080
  goto L6750b3;  // @12_675080
  L6750ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675080
  L6750b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272312), &v, sizeof v); }  // @16_675080
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272316), &v, sizeof v); }  // @17_675080
  return eax;  // @18_675080
}
PCREG(675080, lifted_675080);

extern "C" u32 lifted_6750d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272368), sizeof v); (u32)v; });  // @0_6750d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272372), sizeof v); (u32)v; });  // @1_6750d0
  if ((ecx & ecx) == 0) goto L6750ef;  // @2_6750d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6750d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272372), sizeof v); (u32)v; });  // @4_6750d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272368), sizeof v); (u32)v; });  // @5_6750d0
  goto L6750f4;  // @6_6750d0
  L6750ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6750d0
  L6750f4:;
  if ((eax & eax) == 0) goto L6750fd;  // @10_6750d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6750d0
  goto L675103;  // @12_6750d0
  L6750fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6750d0
  L675103:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272368), &v, sizeof v); }  // @16_6750d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272372), &v, sizeof v); }  // @17_6750d0
  return eax;  // @18_6750d0
}
PCREG(6750d0, lifted_6750d0);

extern "C" u32 lifted_675170(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272508), sizeof v); (u32)v; });  // @0_675170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272512), sizeof v); (u32)v; });  // @1_675170
  if ((ecx & ecx) == 0) goto L67518f;  // @2_675170
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675170
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272512), sizeof v); (u32)v; });  // @4_675170
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272508), sizeof v); (u32)v; });  // @5_675170
  goto L675194;  // @6_675170
  L67518f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675170
  L675194:;
  if ((eax & eax) == 0) goto L67519d;  // @10_675170
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675170
  goto L6751a3;  // @12_675170
  L67519d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675170
  L6751a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272508), &v, sizeof v); }  // @16_675170
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272512), &v, sizeof v); }  // @17_675170
  return eax;  // @18_675170
}
PCREG(675170, lifted_675170);

extern "C" u32 lifted_6751c0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272564), sizeof v); (u32)v; });  // @0_6751c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272568), sizeof v); (u32)v; });  // @1_6751c0
  if ((ecx & ecx) == 0) goto L6751df;  // @2_6751c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6751c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272568), sizeof v); (u32)v; });  // @4_6751c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272564), sizeof v); (u32)v; });  // @5_6751c0
  goto L6751e4;  // @6_6751c0
  L6751df:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6751c0
  L6751e4:;
  if ((eax & eax) == 0) goto L6751ed;  // @10_6751c0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6751c0
  goto L6751f3;  // @12_6751c0
  L6751ed:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6751c0
  L6751f3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272564), &v, sizeof v); }  // @16_6751c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272568), &v, sizeof v); }  // @17_6751c0
  return eax;  // @18_6751c0
}
PCREG(6751c0, lifted_6751c0);

extern "C" u32 lifted_675210(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272620), sizeof v); (u32)v; });  // @0_675210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272624), sizeof v); (u32)v; });  // @1_675210
  if ((ecx & ecx) == 0) goto L67522f;  // @2_675210
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675210
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272624), sizeof v); (u32)v; });  // @4_675210
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272620), sizeof v); (u32)v; });  // @5_675210
  goto L675234;  // @6_675210
  L67522f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675210
  L675234:;
  if ((eax & eax) == 0) goto L67523d;  // @10_675210
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675210
  goto L675243;  // @12_675210
  L67523d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675210
  L675243:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272620), &v, sizeof v); }  // @16_675210
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272624), &v, sizeof v); }  // @17_675210
  return eax;  // @18_675210
}
PCREG(675210, lifted_675210);

extern "C" u32 lifted_6752b0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272732), sizeof v); (u32)v; });  // @0_6752b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272736), sizeof v); (u32)v; });  // @1_6752b0
  if ((ecx & ecx) == 0) goto L6752cf;  // @2_6752b0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6752b0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272736), sizeof v); (u32)v; });  // @4_6752b0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272732), sizeof v); (u32)v; });  // @5_6752b0
  goto L6752d4;  // @6_6752b0
  L6752cf:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6752b0
  L6752d4:;
  if ((eax & eax) == 0) goto L6752dd;  // @10_6752b0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6752b0
  goto L6752e3;  // @12_6752b0
  L6752dd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6752b0
  L6752e3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272732), &v, sizeof v); }  // @16_6752b0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272736), &v, sizeof v); }  // @17_6752b0
  return eax;  // @18_6752b0
}
PCREG(6752b0, lifted_6752b0);

extern "C" u32 lifted_675300(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272844), sizeof v); (u32)v; });  // @0_675300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272848), sizeof v); (u32)v; });  // @1_675300
  if ((ecx & ecx) == 0) goto L67531f;  // @2_675300
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675300
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272848), sizeof v); (u32)v; });  // @4_675300
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272844), sizeof v); (u32)v; });  // @5_675300
  goto L675324;  // @6_675300
  L67531f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675300
  L675324:;
  if ((eax & eax) == 0) goto L67532d;  // @10_675300
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675300
  goto L675333;  // @12_675300
  L67532d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675300
  L675333:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272844), &v, sizeof v); }  // @16_675300
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272848), &v, sizeof v); }  // @17_675300
  return eax;  // @18_675300
}
PCREG(675300, lifted_675300);

extern "C" u32 lifted_675350(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272788), sizeof v); (u32)v; });  // @0_675350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272792), sizeof v); (u32)v; });  // @1_675350
  if ((ecx & ecx) == 0) goto L67536f;  // @2_675350
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675350
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272792), sizeof v); (u32)v; });  // @4_675350
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272788), sizeof v); (u32)v; });  // @5_675350
  goto L675374;  // @6_675350
  L67536f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675350
  L675374:;
  if ((eax & eax) == 0) goto L67537d;  // @10_675350
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675350
  goto L675383;  // @12_675350
  L67537d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675350
  L675383:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272788), &v, sizeof v); }  // @16_675350
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272792), &v, sizeof v); }  // @17_675350
  return eax;  // @18_675350
}
PCREG(675350, lifted_675350);

extern "C" u32 lifted_6753f0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272956), sizeof v); (u32)v; });  // @0_6753f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272960), sizeof v); (u32)v; });  // @1_6753f0
  if ((ecx & ecx) == 0) goto L67540f;  // @2_6753f0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6753f0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272960), sizeof v); (u32)v; });  // @4_6753f0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7272956), sizeof v); (u32)v; });  // @5_6753f0
  goto L675414;  // @6_6753f0
  L67540f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6753f0
  L675414:;
  if ((eax & eax) == 0) goto L67541d;  // @10_6753f0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6753f0
  goto L675423;  // @12_6753f0
  L67541d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6753f0
  L675423:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272956), &v, sizeof v); }  // @16_6753f0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7272960), &v, sizeof v); }  // @17_6753f0
  return eax;  // @18_6753f0
}
PCREG(6753f0, lifted_6753f0);

extern "C" u32 lifted_675440(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273012), sizeof v); (u32)v; });  // @0_675440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273016), sizeof v); (u32)v; });  // @1_675440
  if ((ecx & ecx) == 0) goto L67545f;  // @2_675440
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675440
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273016), sizeof v); (u32)v; });  // @4_675440
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273012), sizeof v); (u32)v; });  // @5_675440
  goto L675464;  // @6_675440
  L67545f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675440
  L675464:;
  if ((eax & eax) == 0) goto L67546d;  // @10_675440
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675440
  goto L675473;  // @12_675440
  L67546d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675440
  L675473:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273012), &v, sizeof v); }  // @16_675440
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273016), &v, sizeof v); }  // @17_675440
  return eax;  // @18_675440
}
PCREG(675440, lifted_675440);

extern "C" u32 lifted_675490(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273068), sizeof v); (u32)v; });  // @0_675490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273072), sizeof v); (u32)v; });  // @1_675490
  if ((ecx & ecx) == 0) goto L6754af;  // @2_675490
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675490
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273072), sizeof v); (u32)v; });  // @4_675490
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273068), sizeof v); (u32)v; });  // @5_675490
  goto L6754b4;  // @6_675490
  L6754af:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675490
  L6754b4:;
  if ((eax & eax) == 0) goto L6754bd;  // @10_675490
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675490
  goto L6754c3;  // @12_675490
  L6754bd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675490
  L6754c3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273068), &v, sizeof v); }  // @16_675490
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273072), &v, sizeof v); }  // @17_675490
  return eax;  // @18_675490
}
PCREG(675490, lifted_675490);

extern "C" u32 lifted_675530(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273180), sizeof v); (u32)v; });  // @0_675530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273184), sizeof v); (u32)v; });  // @1_675530
  if ((ecx & ecx) == 0) goto L67554f;  // @2_675530
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675530
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273184), sizeof v); (u32)v; });  // @4_675530
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273180), sizeof v); (u32)v; });  // @5_675530
  goto L675554;  // @6_675530
  L67554f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675530
  L675554:;
  if ((eax & eax) == 0) goto L67555d;  // @10_675530
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675530
  goto L675563;  // @12_675530
  L67555d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675530
  L675563:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273180), &v, sizeof v); }  // @16_675530
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273184), &v, sizeof v); }  // @17_675530
  return eax;  // @18_675530
}
PCREG(675530, lifted_675530);

extern "C" u32 lifted_675580(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273236), sizeof v); (u32)v; });  // @0_675580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273240), sizeof v); (u32)v; });  // @1_675580
  if ((ecx & ecx) == 0) goto L67559f;  // @2_675580
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675580
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273240), sizeof v); (u32)v; });  // @4_675580
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273236), sizeof v); (u32)v; });  // @5_675580
  goto L6755a4;  // @6_675580
  L67559f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675580
  L6755a4:;
  if ((eax & eax) == 0) goto L6755ad;  // @10_675580
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675580
  goto L6755b3;  // @12_675580
  L6755ad:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675580
  L6755b3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273236), &v, sizeof v); }  // @16_675580
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273240), &v, sizeof v); }  // @17_675580
  return eax;  // @18_675580
}
PCREG(675580, lifted_675580);

extern "C" u32 lifted_6755d0(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273292), sizeof v); (u32)v; });  // @0_6755d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273296), sizeof v); (u32)v; });  // @1_6755d0
  if ((ecx & ecx) == 0) goto L6755ef;  // @2_6755d0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_6755d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273296), sizeof v); (u32)v; });  // @4_6755d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273292), sizeof v); (u32)v; });  // @5_6755d0
  goto L6755f4;  // @6_6755d0
  L6755ef:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_6755d0
  L6755f4:;
  if ((eax & eax) == 0) goto L6755fd;  // @10_6755d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_6755d0
  goto L675603;  // @12_6755d0
  L6755fd:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_6755d0
  L675603:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273292), &v, sizeof v); }  // @16_6755d0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273296), &v, sizeof v); }  // @17_6755d0
  return eax;  // @18_6755d0
}
PCREG(6755d0, lifted_6755d0);

extern "C" u32 lifted_675670(void) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273404), sizeof v); (u32)v; });  // @0_675670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273408), sizeof v); (u32)v; });  // @1_675670
  if ((ecx & ecx) == 0) goto L67568f;  // @2_675670
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @3_675670
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273408), sizeof v); (u32)v; });  // @4_675670
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7273404), sizeof v); (u32)v; });  // @5_675670
  goto L675694;  // @6_675670
  L67568f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(7340988), &v, sizeof v); }  // @8_675670
  L675694:;
  if ((eax & eax) == 0) goto L67569d;  // @10_675670
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax + 16), &v, sizeof v); }  // @11_675670
  goto L6756a3;  // @12_675670
  L67569d:;
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(7340992), &v, sizeof v); }  // @14_675670
  L6756a3:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273404), &v, sizeof v); }  // @16_675670
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(7273408), &v, sizeof v); }  // @17_675670
  return eax;  // @18_675670
}
PCREG(675670, lifted_675670);

extern "C" u32 THISCALL lifted_662be0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_662be0
  ecx = (u32)(esi + 52);  // @1_662be0
  { u32 v = (u32)((u32)(7096988)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_662be0
  eax = ext_662750_thiscall1(ecx);  // @3_662be0
  ecx = edx = 0;  // @4_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @5_662be0
  eax = esi;  // @6_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @7_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @8_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @9_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @10_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @11_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @12_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @13_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @14_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @15_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @16_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @17_662be0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @18_662be0
  return eax;  // @19_662be0
}
PCREG(662be0, lifted_662be0);

extern "C" u32 THISCALL lifted_662ed0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;  // @0_662ed0
  ecx = (u32)(esi + 52);  // @1_662ed0
  { u32 v = (u32)((u32)(7096996)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @2_662ed0
  eax = ext_662750_thiscall1(ecx);  // @3_662ed0
  ecx = edx = 0;  // @4_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @5_662ed0
  eax = esi;  // @6_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }  // @7_662ed0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }  // @8_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }  // @9_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 20), &v, sizeof v); }  // @10_662ed0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }  // @11_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }  // @12_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }  // @13_662ed0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 36), &v, sizeof v); }  // @14_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 40), &v, sizeof v); }  // @15_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 44), &v, sizeof v); }  // @16_662ed0
  { u32 v = (u32)((u32)(1065353216)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }  // @17_662ed0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 60), &v, sizeof v); }  // @18_662ed0
  return eax;  // @19_662ed0
}
PCREG(662ed0, lifted_662ed0);

extern "C" u32 STDCALL lifted_663200(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_663200
  eax = (eax - (u32)(1));  // @1_663200
  if (eax == 0) goto L66323c;  // @2_663200
  eax = (eax - (u32)(4));  // @3_663200
  if (eax == 0) goto L663230;  // @4_663200
  eax = (eax - (u32)(3));  // @5_663200
  if (eax == 0) goto L663224;  // @6_663200
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @7_663200
  { u32 v = (u32)((u32)(25)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_663200
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @9_663200
  return eax;  // @10_663200
  L663224:;
  eax = ext_663770_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @12_663200
  ecx = edx = 0;  // @13_663200
  return eax;  // @14_663200
  L663230:;
  eax = ext_6638c0_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @16_663200
  ecx = edx = 0;  // @17_663200
  return eax;  // @18_663200
  L66323c:;
  eax = ext_663610_thiscall2(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));  // @20_663200
  ecx = edx = 0;  // @21_663200
  return eax;  // @22_663200
}
PCREG(663200, lifted_663200);

extern "C" u32 THISCALL lifted_662750(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 13), &v, sizeof v); }  // @0_662750
  edx = (u32)(ecx + 13);  // @1_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 17), &v, sizeof v); }  // @2_662750
  eax = (u32)(ecx + 17);  // @3_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @4_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @5_662750
  esi = (u32)(EBP - 4);  // @6_662750
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @7_662750
  if (edx == esi) goto L66278d;  // @8_662750
  { u32 v = (u32)((u32)(4294966272)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @9_662750
  L66278d:;
  edx = (u32)(EBP - 8);  // @11_662750
  if (eax == edx) goto L66279a;  // @12_662750
  { u32 v = (u32)((u32)(2048)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @13_662750
  L66279a:;
  { u32 v = (u32)((u32)(2)); __builtin_memcpy((void *)(u32)(ecx + 21), &v, sizeof v); }  // @15_662750
  eax = ecx;  // @16_662750
  { u32 v = (u32)((u32)(981668463)); __builtin_memcpy((void *)(u32)(ecx + 25), &v, sizeof v); }  // @17_662750
  { u8 v = (u8)((u32)(1)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @18_662750
  return eax;  // @19_662750
}
PCREG(662750, lifted_662750);

extern "C" u32 lifted_633cbc(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_633cbc
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 60), sizeof v); (u32)v; });  // @1_633cbc
  ecx = (ecx + eax);  // @2_633cbc
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @3_633cbc
  edx = (u32)(ecx + 24);  // @4_633cbc
  edx = (edx + eax);  // @5_633cbc
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 6), sizeof v); (u32)v; });  // @6_633cbc
  esi = (u32)((s32)eax * (s32)(u32)(40));  // @7_633cbc
  esi = (esi + edx);  // @8_633cbc
  if (edx == esi) goto L633cf7;  // @9_633cbc
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @10_633cbc
  L633ce1:;
  if (ecx < ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; })) goto L633cf0;  // @12_633cbc
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @13_633cbc
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; }));  // @14_633cbc
  if (ecx < eax) goto L633cfc;  // @15_633cbc
  L633cf0:;
  edx = (edx + (u32)(40));  // @17_633cbc
  if (edx != esi) goto L633ce1;  // @18_633cbc
  L633cf7:;
  eax = 0;  // @20_633cbc
  L633cf9:;
  return eax;  // @22_633cbc
  L633cfc:;
  eax = edx;  // @24_633cbc
  goto L633cf9;  // @25_633cbc
}
PCREG(633cbc, lifted_633cbc);

extern "C" u32 THISCALL lifted_663190(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  ebx = ecx;  // @0_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 74124), sizeof v); (u32)v; });  // @1_663190
  edi = (u32)(ebx + 74124);  // @2_663190
  ecx = edi;  // @3_663190
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi));  // @4_663190
  ecx = edx = 0;  // @5_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @6_663190
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @7_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @8_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @9_663190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @10_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @11_663190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @12_663190
  ecx = edx = 0;  // @13_663190
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @14_663190
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 308)))(ecx, (u32)(edi), (u32)(eax));  // @15_663190
  ecx = edx = 0;  // @16_663190
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @17_663190
  ecx = edi;  // @18_663190
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @19_663190
  ecx = edx = 0;  // @20_663190
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ebx + 74152), &v, sizeof v); }  // @21_663190
  eax = (eax & 0xffffff00u) | (((u32)((s32)eax < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 74156), sizeof v); (u32)v; }))) & 0xff);  // @22_663190
  return eax;  // @23_663190
}
PCREG(663190, lifted_663190);

extern "C" u32 THISCALL lifted_663610(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 74124), sizeof v); (u32)v; });  // @0_663610
  edi = (u32)(ecx + 74124);  // @1_663610
  ecx = edi;  // @2_663610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi), (u32)(esi));  // @3_663610
  ecx = edx = 0;  // @4_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @5_663610
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @6_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @7_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @8_663610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @9_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @10_663610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @11_663610
  ecx = edx = 0;  // @12_663610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @13_663610
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(esi + 308)))(ecx, (u32)(edi), (u32)(eax));  // @14_663610
  ecx = edx = 0;  // @15_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_663610
  ecx = edi;  // @17_663610
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @18_663610
  ecx = edx = 0;  // @19_663610
  if ((eax & eax) != 0) goto L663676;  // @20_663610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @21_663610
  { u32 v = (u32)((u32)(15)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @22_663610
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @23_663610
  return eax;  // @24_663610
  L663676:;
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @26_663610
  return eax;  // @27_663610
}
PCREG(663610, lifted_663610);

extern "C" u32 THISCALL lifted_663b60(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_663b60
  edi = ecx;  // @1_663b60
  if ((s32)esi >= (s32)(u32)(64)) goto L663bbb;  // @2_663b60
  eax = esi;  // @3_663b60
  eax = (eax << (u32)(10));  // @4_663b60
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @5_663b60
  eax = (eax + (u32)(8448));  // @6_663b60
  eax = (eax + edi);  // @7_663b60
  ecx = ebx;  // @8_663b60
  eax = ext_5ae5a0_thiscall3(ecx, (u32)(eax), (u32)(0));  // @9_663b60
  ecx = edx = 0;  // @10_663b60
  ecx = ebx;  // @11_663b60
  eax = ext_5adea0_thiscall1(ecx);  // @12_663b60
  ecx = edx = 0;  // @13_663b60
  edx = esi;  // @14_663b60
  edx = (edx << (u32)(7));  // @15_663b60
  edx = (edx + edi);  // @16_663b60
  edx = (edx - eax);  // @17_663b60
  L663ba0:;
  ecx = (ecx & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; })) & 0xff);  // @19_663b60
  eax = (u32)(eax + 1);  // @20_663b60
  { u8 v = (u8)((ecx & 0xff)); __builtin_memcpy((void *)(u32)(edx + eax - 1), &v, sizeof v); }  // @21_663b60
  if (((ecx & 0xff) & (ecx & 0xff)) != 0) goto L663ba0;  // @22_663b60
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 134), sizeof v); (u32)v; });  // @23_663b60
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + esi*4 + 8192), &v, sizeof v); }  // @24_663b60
  L663bbb:;
  return eax;  // @26_663b60
}
PCREG(663b60, lifted_663b60);

extern "C" u32 FASTCALL lifted_660c00(u32 ecx_in, u32 edx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  __builtin_memcpy(F + 0x300 + 28, &a5, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @0_660c00
  ebx = ecx;  // @1_660c00
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_660c00
  edi = edx;  // @3_660c00
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @4_660c00
  eax = ext_6604c0_thiscall4(ecx, (u32)(esi), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 28), sizeof v); (u32)v; }));  // @5_660c00
  ecx = edx = 0;  // @6_660c00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; });  // @7_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @8_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + 4), &v, sizeof v); }  // @9_660c00
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(8471088), &v, sizeof v); }  // @10_660c00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(8471092), &v, sizeof v); }  // @11_660c00
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(8471096), &v, sizeof v); }  // @12_660c00
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(8471100), &v, sizeof v); }  // @13_660c00
  if ((s32)(edi & edi) <= 0) goto L660c79;  // @14_660c00
  ecx = (u32)(83);  // @15_660c00
  L660c57:;
  esi = edi;  // @17_660c00
  edx = ebx;  // @18_660c00
  if ((s32)edi > (s32)(u32)(83)) esi = ecx;  // @19_660c00
  ecx = eax;  // @20_660c00
  eax = ext_65f690_fastcall3(ecx, edx, (u32)(esi));  // @21_660c00
  ecx = edx = 0;  // @22_660c00
  edi = (edi - esi);  // @23_660c00
  ecx = (u32)(83);  // @24_660c00
  esi = (esi << (u32)(6));  // @25_660c00
  ebx = (ebx + esi);  // @26_660c00
  if ((s32)(edi & edi) > 0) goto L660c57;  // @27_660c00
  L660c79:;
  return eax;  // @29_660c00
}
PCREG(660c00, lifted_660c00);

extern "C" u32 STDCALL lifted_6639a0(u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @0_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 228)))(ecx, (u32)(1));  // @2_6639a0
  ecx = edx = 0;  // @3_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @4_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @5_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @6_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 28), sizeof v); (u32)v; });  // @7_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(eax))(ecx, (u32)(1));  // @8_6639a0
  ecx = edx = 0;  // @9_6639a0
  if (((eax & 0xff) & (eax & 0xff)) != 0) goto L6639f4;  // @10_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @11_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @12_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @13_6639a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @14_6639a0
  ecx = edx = 0;  // @15_6639a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @16_6639a0
  ecx = eax;  // @17_6639a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6973164), (u32)(1), (u32)(2));  // @18_6639a0
  ecx = edx = 0;  // @19_6639a0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @20_6639a0
  return eax;  // @21_6639a0
  L6639f4:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @23_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @24_6639a0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 228)))(ecx, (u32)(1));  // @25_6639a0
  ecx = edx = 0;  // @26_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @27_6639a0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @28_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @29_6639a0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 308)))(ecx);  // @30_6639a0
  ecx = edx = 0;  // @31_6639a0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @32_6639a0
  ecx = eax;  // @33_6639a0
  eax = ((u32(THISCALL *)(u32, u32, u32, u32))(*(u32 *)(edx + 92)))(ecx, (u32)(6973164), (u32)(0), (u32)(2));  // @34_6639a0
  ecx = edx = 0;  // @35_6639a0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @36_6639a0
  { u32 v = (u32)((u32)(9)); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @37_6639a0
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @38_6639a0
  return eax;  // @39_6639a0
}
PCREG(6639a0, lifted_6639a0);

extern "C" u32 THISCALL lifted_661940(u32 ecx_in, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  __builtin_memcpy(F + 0x300 + 20, &a3, 4);
  __builtin_memcpy(F + 0x300 + 24, &a4, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_661940
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @1_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @2_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 8), &v, sizeof v); }  // @3_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @4_661940
  edi = edx;  // @5_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @6_661940
  eax = edx;  // @7_661940
  ebx = (edx & 0xffff);  // @8_661940
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @9_661940
  eax = (eax >> (u32)(31));  // @10_661940
  edx = (edx + ecx);  // @11_661940
  edi = (edi >> (u32)(16));  // @12_661940
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @13_661940
  edi = (edi & (u32)(32767));  // @14_661940
  { u8 v = (u8)((eax & 0xff)); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_661940
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 24), sizeof v); (u32)v; });  // @16_661940
  ebx = (ebx + edi);  // @17_661940
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @18_661940
  if ((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 44), sizeof v); (u32)v; }) & eax) != 0) goto L661994;  // @19_661940
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @20_661940
  return eax;  // @21_661940
  L661994:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 60), sizeof v); (u32)v; });  // @23_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 20), sizeof v); (u32)v; });  // @24_661940
  ecx = (ecx + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @25_661940
  eax = (u32)(eax + edi*2);  // @26_661940
  eax = (eax + ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; }));  // @27_661940
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 8), sizeof v); (u32)v; });  // @28_661940
  eax = ext_661b40_stdcall8((u32)(ecx), (u32)(eax), (u32)(edi), (u32)(ebx), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 20), sizeof v); (u32)v; }));  // @29_661940
  ecx = edx = 0;  // @30_661940
  return eax;  // @31_661940
}
PCREG(661940, lifted_661940);

extern "C" u32 THISCALL lifted_663520(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;  // @0_663520
  if (({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) == (u32)(0)) goto L663573;  // @1_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @2_663520
  ebx = (u32)(esi + 74124);  // @3_663520
  ecx = ebx;  // @4_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 12)))(ecx, (u32)(edi), (u32)(esi));  // @5_663520
  ecx = edx = 0;  // @6_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @7_663520
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @8_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @10_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2788), sizeof v); (u32)v; });  // @11_663520
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @12_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(6973416), (u32)(7097000));  // @13_663520
  ecx = edx = 0;  // @14_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340948), sizeof v); (u32)v; });  // @15_663520
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edi + 308)))(ecx, (u32)(ebx), (u32)(eax));  // @16_663520
  ecx = edx = 0;  // @17_663520
  L663573:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @19_663520
  ecx = (u32)(esi + 74124);  // @20_663520
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @21_663520
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 20)))(ecx);  // @22_663520
  ecx = edx = 0;  // @23_663520
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @24_663520
  if ((s32)(eax & eax) <= 0) goto L6635e7;  // @25_663520
  edi = 0;  // @26_663520
  if ((s32)(eax & eax) <= 0) goto L6635e7;  // @27_663520
  L6635a0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74124), sizeof v); (u32)v; });  // @29_663520
  ecx = (u32)(esi + 74124);  // @30_663520
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 48)))(ecx, (u32)(edi));  // @31_663520
  ecx = edx = 0;  // @32_663520
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; });  // @33_663520
  eax = ext_5ae900_thiscall2(ecx, (u32)(eax));  // @34_663520
  ecx = edx = 0;  // @35_663520
  ecx = esi;  // @36_663520
  eax = ext_663680_thiscall1(ecx);  // @37_663520
  ecx = edx = 0;  // @38_663520
  if (((eax & 0xff) & (eax & 0xff)) == 0) goto L6635f8;  // @39_663520
  ecx = (u32)(esi + 4);  // @40_663520
  eax = ext_663b60_thiscall3(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 73988), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }));  // @41_663520
  ecx = edx = 0;  // @42_663520
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 74152), &v, sizeof v); }  // @43_663520
  edi = (edi + 1);  // @44_663520
  if ((s32)edi < (s32)({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; })) goto L6635a0;  // @45_663520
  L6635e7:;
  eax = (eax & 0xffffff00u) | (((u32)(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 74152), sizeof v); (u32)v; }) != (u32)(0))) & 0xff);  // @47_663520
  return eax;  // @48_663520
  L6635f8:;
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @50_663520
  return eax;  // @51_663520
}
PCREG(663520, lifted_663520);

extern "C" u32 THISCALL lifted_6625c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_6625c0
  esi = ecx;  // @1_6625c0
  ecx = edi;  // @2_6625c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, (u32)(esi));  // @4_6625c0
  ecx = edx = 0;  // @5_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @6_6625c0
  eax = (u32)(esi + 4);  // @7_6625c0
  ecx = edi;  // @8_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @9_6625c0
  ecx = edx = 0;  // @10_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @11_6625c0
  eax = (u32)(esi + 8);  // @12_6625c0
  ecx = edi;  // @13_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @14_6625c0
  ecx = edx = 0;  // @15_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @16_6625c0
  eax = (u32)(esi + 12);  // @17_6625c0
  ecx = edi;  // @18_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @19_6625c0
  ecx = edx = 0;  // @20_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @21_6625c0
  eax = (u32)(esi + 16);  // @22_6625c0
  ecx = edi;  // @23_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, (u32)(eax));  // @24_6625c0
  ecx = edx = 0;  // @25_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @26_6625c0
  eax = (u32)(esi + 17);  // @27_6625c0
  ecx = edi;  // @28_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @29_6625c0
  ecx = edx = 0;  // @30_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @31_6625c0
  eax = (u32)(esi + 21);  // @32_6625c0
  ecx = edi;  // @33_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @34_6625c0
  ecx = edx = 0;  // @35_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @36_6625c0
  eax = (u32)(esi + 25);  // @37_6625c0
  ecx = edi;  // @38_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @39_6625c0
  ecx = edx = 0;  // @40_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_6625c0
  eax = (u32)(esi + 29);  // @42_6625c0
  ecx = edi;  // @43_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @44_6625c0
  ecx = edx = 0;  // @45_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @46_6625c0
  eax = (u32)(esi + 33);  // @47_6625c0
  ecx = edi;  // @48_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @49_6625c0
  ecx = edx = 0;  // @50_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @51_6625c0
  eax = (u32)(esi + 37);  // @52_6625c0
  ecx = edi;  // @53_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @54_6625c0
  ecx = edx = 0;  // @55_6625c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @56_6625c0
  eax = (u32)(esi + 41);  // @57_6625c0
  ecx = edi;  // @58_6625c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 80)))(ecx, (u32)(eax));  // @59_6625c0
  ecx = edx = 0;  // @60_6625c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @61_6625c0
  return eax;  // @62_6625c0
}
PCREG(6625c0, lifted_6625c0);

