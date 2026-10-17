// batch248000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_465930_thiscall2(u32, u32) __asm__("ext_465930");
extern "C" u32 THISCALL ext_5138f0_thiscall2(u32, u32) __asm__("ext_5138f0");


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_467cd0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_467cd0
  if (FL[0] == FL[1]) goto L467cde;  // @1_467cd0
  return ext_465930_thiscall2(ecx, a0);  // @2_467cd0
  L467cde:;
  return eax;  // @4_467cd0
}
PCREG(467cd0, lifted_467cd0);

extern "C" u32 THISCALL lifted_4619c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4619c0
  edx = (u32)(eax + eax*2);  // @1_4619c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 28), sizeof v); (u32)v; });  // @2_4619c0
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(eax + edx*8 + 4), sizeof v); (u32)v; })) & 0xff);  // @3_4619c0
  eax = (eax & 0xffffff00u) | ((((eax & 0xff) & (u32)(1))) & 0xff);  // @4_4619c0
  FL[3] = (eax & 0xff);  // @5_4619c0
  return eax;  // @6_4619c0
}
PCREG(4619c0, lifted_4619c0);

extern "C" u32 THISCALL lifted_47fb10(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_47fb10
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @1_47fb10
  eax = ecx;  // @2_47fb10
  { u32 v = (u32)((u32)(6861156)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @3_47fb10
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @4_47fb10
  return eax;  // @5_47fb10
}
PCREG(47fb10, lifted_47fb10);

extern "C" u32 THISCALL lifted_516620(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_516620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @1_516620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @2_516620
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @3_516620
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @4_516620
  return eax;  // @5_516620
}
PCREG(516620, lifted_516620);

extern "C" u32 THISCALL lifted_514480(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_514480
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_514480
  if (FL[0] == FL[1]) goto L514493;  // @2_514480
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @3_514480
  return ext_5138f0_thiscall2(ecx, a0);  // @4_514480
  L514493:;
  return eax;  // @6_514480
}
PCREG(514480, lifted_514480);

extern "C" u32 THISCALL lifted_5af0d0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_5af0d0
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @1_5af0d0
  if (FL[0] >= FL[1]) goto L5af0e2;  // @2_5af0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*4 + 4), sizeof v); (u32)v; });  // @3_5af0d0
  return eax;  // @4_5af0d0
  L5af0e2:;
  eax = 0;  // @6_5af0d0
  FL[3] = eax;  // @7_5af0d0
  return eax;  // @8_5af0d0
}
PCREG(5af0d0, lifted_5af0d0);

extern "C" u32 THISCALL lifted_4cf1c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4cf1c0
  { u32 v = (u32)((u32)(4294967295)); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @1_4cf1c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @2_4cf1c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @3_4cf1c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });  // @4_4cf1c0
  FL[2] = (eax & eax);  // @5_4cf1c0
  if (FL[2] == 0) goto L4cf1df;  // @6_4cf1c0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 8), sizeof v); (u32)v; });  // @7_4cf1c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 4), &v, sizeof v); }  // @8_4cf1c0
  L4cf1df:;
  return eax;  // @10_4cf1c0
}
PCREG(4cf1c0, lifted_4cf1c0);

extern "C" u32 THISCALL lifted_589fd0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_589fd0
  FL[0] = eax; FL[1] = (u32)(-1);  // @1_589fd0
  if (FL[0] != FL[1]) goto L589fe1;  // @2_589fd0
  eax = 0;  // @3_589fd0
  FL[3] = eax;  // @4_589fd0
  return eax;  // @5_589fd0
  L589fe1:;
  eax = (u32)((s32)eax * (s32)(u32)(244));  // @7_589fd0
  eax = (eax + (u32)(3473));  // @8_589fd0
  FL[3] = eax;  // @9_589fd0
  eax = (eax + ecx);  // @10_589fd0
  FL[3] = eax;  // @11_589fd0
  return eax;  // @12_589fd0
}
PCREG(589fd0, lifted_589fd0);

extern "C" u32 THISCALL lifted_591d30(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_591d30
  FL[0] = eax; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 2582), sizeof v); (u32)v; });  // @1_591d30
  if (FL[0] >= FL[1]) goto L591d4e;  // @2_591d30
  eax = (u32)(eax + eax*2);  // @3_591d30
  eax = (eax + eax);  // @4_591d30
  FL[3] = eax;  // @5_591d30
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + eax*8 + 2586), sizeof v); (u32)v; });  // @6_591d30
  return eax;  // @7_591d30
  L591d4e:;
  eax = 0;  // @9_591d30
  FL[3] = eax;  // @10_591d30
  return eax;  // @11_591d30
}
PCREG(591d30, lifted_591d30);

extern "C" u32 THISCALL lifted_5eec40(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @0_5eec40
  eax = ecx;  // @1_5eec40
  { u32 v = (u32)((u32)(7045520)); __builtin_memcpy((void *)(u32)(ecx), &v, sizeof v); }  // @2_5eec40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 4), &v, sizeof v); }  // @3_5eec40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @4_5eec40
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @5_5eec40
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(ecx + 16), &v, sizeof v); }  // @6_5eec40
  return eax;  // @7_5eec40
}
PCREG(5eec40, lifted_5eec40);

extern "C" u32 THISCALL lifted_4e5310(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4e5310
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 76), sizeof v); (u32)v; });  // @1_4e5310
  FL[2] = (edx & edx);  // @2_4e5310
  if (FL[2] != 0) goto L4e5323;  // @3_4e5310
  eax = 0;  // @4_4e5310
  FL[3] = eax;  // @5_4e5310
  return eax;  // @6_4e5310
  L4e5323:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 36), sizeof v); (u32)v; });  // @8_4e5310
  eax = (eax - 1);  // @9_4e5310
  FL[3] = eax;  // @10_4e5310
  eax = (eax + edx);  // @11_4e5310
  FL[3] = eax;  // @12_4e5310
  return eax;  // @13_4e5310
}
PCREG(4e5310, lifted_4e5310);

extern "C" u32 THISCALL lifted_45fa00(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @0_45fa00
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 20), sizeof v); (u32)v; });  // @1_45fa00
  if (FL[0] == FL[1]) goto L45fa1a;  // @2_45fa00
  FL[2] = ((eax & 0xff) & (u32)(8));  // @3_45fa00
  if (FL[2] != 0) goto L45fa24;  // @4_45fa00
  eax = (eax | (u32)(9));  // @5_45fa00
  FL[3] = eax;  // @6_45fa00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @7_45fa00
  return eax;  // @8_45fa00
  L45fa1a:;
  FL[2] = ((eax & 0xff) & (u32)(8));  // @10_45fa00
  if (FL[2] == 0) goto L45fa24;  // @11_45fa00
  eax = (eax & (u32)(4294967287));  // @12_45fa00
  FL[3] = eax;  // @13_45fa00
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 20), &v, sizeof v); }  // @14_45fa00
  L45fa24:;
  return eax;  // @16_45fa00
}
PCREG(45fa00, lifted_45fa00);

