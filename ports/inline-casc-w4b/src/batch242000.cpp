// batch242000.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4db860_thiscall2(u32, u32) __asm__("ext_4db860");
extern "C" u32 THISCALL ext_4e5e60_thiscall1(u32) __asm__("ext_4e5e60");
extern "C" u32 THISCALL ext_4e5ea0_thiscall1(u32) __asm__("ext_4e5ea0");
extern "C" u32 THISCALL ext_6352f0_thiscall2(u32, u32) __asm__("ext_6352f0");
extern "C" void FASTCALL ext_633654(u32 cookie);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_4c3280(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c3280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 72), &v, sizeof v); }  // @1_4c3280
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @2_4c3280
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 76), &v, sizeof v); }  // @3_4c3280
  return eax;  // @4_4c3280
}
PCREG(4c3280, lifted_4c3280);

extern "C" u32 STDCALL lifted_471a10(u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_471a10
  FL[2] = (eax & eax);  // @1_471a10
  if (FL[2] != 0) goto L471a20;  // @2_471a10
  eax = (eax & 0xffffff00u) | ((0) & 0xff);  // @3_471a10
  FL[3] = (eax & 0xff);  // @4_471a10
  return eax;  // @5_471a10
  L471a20:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 12), sizeof v); (u32)v; });  // @7_471a10
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 35), sizeof v); (u32)v; }); FL[1] = (u32)(1050579);  // @8_471a10
  eax = (eax & 0xffffff00u) | ((((FL[0] == FL[1]) ? 1 : 0)) & 0xff);  // @9_471a10
  return eax;  // @10_471a10
}
PCREG(471a10, lifted_471a10);

extern "C" u32 STDCALL lifted_4c5870(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_4c5870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @1_4c5870
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @2_4c5870
  FL[2] = (eax & eax);  // @3_4c5870
  if (FL[2] == 0) goto L4c589c;  // @4_4c5870
  L4c5881:;
  ecx = eax;  // @6_4c5870
  eax = ext_4db860_thiscall2(ecx, (u32)(1));  // @7_4c5870
  ecx = edx = 0;  // @8_4c5870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_4c5870
  ecx = (u32)(EBP + 8);  // @10_4c5870
  PV[0] = (u32)(ecx);  // @11_4c5870
  ecx = esi;  // @12_4c5870
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 80)))(ecx, PV[0]);  // @13_4c5870
  ecx = edx = 0;  // @14_4c5870
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @15_4c5870
  FL[2] = (eax & eax);  // @16_4c5870
  if (FL[2] != 0) goto L4c5881;  // @17_4c5870
  L4c589c:;
  return eax;  // @19_4c5870
}
PCREG(4c5870, lifted_4c5870);

extern "C" u32 THISCALL lifted_4b5ca0(u32 ecx_in) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_4b5ca0
  esi = ecx;  // @1_4b5ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @2_4b5ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @3_4b5ca0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 312)))(ecx);  // @4_4b5ca0
  ecx = edx = 0;  // @5_4b5ca0
  ecx = (u32)(EBP - 4);  // @6_4b5ca0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @7_4b5ca0
  PV[0] = (u32)(ecx);  // @8_4b5ca0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @9_4b5ca0
  ecx = eax;  // @10_4b5ca0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 136)))(ecx, (u32)(6889580), PV[0]);  // @11_4b5ca0
  ecx = edx = 0;  // @12_4b5ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @13_4b5ca0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @14_4b5ca0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });  // @15_4b5ca0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @16_4b5ca0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 88)))(ecx, PV[1]);  // @17_4b5ca0
  ecx = edx = 0;  // @18_4b5ca0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 298), &v, sizeof v); }  // @19_4b5ca0
  return eax;  // @20_4b5ca0
}
PCREG(4b5ca0, lifted_4b5ca0);

extern "C" u32 THISCALL lifted_5c71c0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  esi = ecx;  // @0_5c71c0
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_5c71c0
  eax = (u32)(EBP - 4);  // @2_5c71c0
  PV[0] = (u32)(eax);  // @3_5c71c0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) & (u32)(4294967231))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }  // @4_5c71c0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @5_5c71c0
  eax = ext_6352f0_thiscall2(ecx, PV[0]);  // @6_5c71c0
  ecx = edx = 0;  // @7_5c71c0
  ecx = (u32)(EBP - 4);  // @8_5c71c0
  eax = ext_4e5e60_thiscall1(ecx);  // @9_5c71c0
  ecx = edx = 0;  // @10_5c71c0
  ecx = (u32)(EBP - 4);  // @11_5c71c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 72), &v, sizeof v); }  // @12_5c71c0
  eax = ext_4e5e60_thiscall1(ecx);  // @13_5c71c0
  ecx = edx = 0;  // @14_5c71c0
  ecx = (u32)(EBP - 4);  // @15_5c71c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 76), &v, sizeof v); }  // @16_5c71c0
  eax = ext_4e5ea0_thiscall1(ecx);  // @17_5c71c0
  ecx = edx = 0;  // @18_5c71c0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @19_5c71c0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 80), &v, sizeof v); }  // @20_5c71c0
  eax = (u32)(esi + 84);  // @21_5c71c0
  PV[1] = (u32)(eax);  // @22_5c71c0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @23_5c71c0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 104)))(ecx, PV[1]);  // @24_5c71c0
  ecx = edx = 0;  // @25_5c71c0
  eax = (eax & 0xffffff00u) | (((u32)(1)) & 0xff);  // @26_5c71c0
  return eax;  // @27_5c71c0
}
PCREG(5c71c0, lifted_5c71c0);

extern "C" u32 lifted_41e020(u32 fmt, u32 v0, u32 v1, u32 v2, u32 v3) {   // hand fix: cdecl varargs (printf-like), args live at EBP+8.. so &v0 is the va_list
  u8 F[0x990] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x890);
  __builtin_memcpy(F + 0x890 + 8, &fmt, 4); __builtin_memcpy(F + 0x890 + 12, &v0, 4); __builtin_memcpy(F + 0x890 + 16, &v1, 4); __builtin_memcpy(F + 0x890 + 20, &v2, 4); __builtin_memcpy(F + 0x890 + 24, &v3, 4);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = (u32)(EBP + 12);  // @0_41e020
  PV[0] = (u32)(eax);  // @1_41e020
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_41e020
  eax = (u32)(EBP - 2052);  // @3_41e020
  PV[2] = (u32)(eax);  // @4_41e020
  eax = ((u32(STDCALL *)(u32, u32, u32))(*(u32 *)0x6761e8))(PV[2], PV[1], PV[0]);  // @5_41e020
  ecx = edx = 0;  // @6_41e020
  edi = (u32)(EBP - 2052);  // @7_41e020
  edi = (edi - 1);  // @8_41e020
  FL[3] = edi;  // @9_41e020
  L41e050:;
  eax = (eax & 0xffffff00u) | ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 1), sizeof v); (u32)v; })) & 0xff);  // @11_41e020
  edi = (u32)(edi + 1);  // @12_41e020
  FL[2] = ((eax & 0xff) & (eax & 0xff));  // @13_41e020
  if (FL[2] != 0) goto L41e050;  // @14_41e020
  eax = (eax & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(6777860), sizeof v); (u32)v; })) & 0xffff);  // @15_41e020
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }  // @16_41e020
  eax = (u32)(EBP - 2052);  // @17_41e020
  PV[3] = (u32)(eax);  // @18_41e020
  eax = ((u32(STDCALL *)(u32))(*(u32 *)0x676098))(PV[3]);  // @19_41e020
  ecx = edx = 0;  // @20_41e020
  ext_633654(G(u32, 0x6f5630));  // @21_41e020
  return eax;  // @22_41e020
}
PCREG(41e020, lifted_41e020);

