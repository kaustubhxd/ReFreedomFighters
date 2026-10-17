// batch244007.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"
extern "C" u32 THISCALL ext_4ce180_thiscall2(u32, u32) __asm__("ext_4ce180");
extern "C" u32 THISCALL ext_4d0f30_thiscall4(u32, u32, u32, u32) __asm__("ext_4d0f30");
extern "C" u32 THISCALL ext_607f60_thiscall4(u32, u32, u32, u32) __asm__("ext_607f60");
extern "C" u32 ext_41e290_cdecl1(...) __asm__("ext_41e290");

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_63ead0(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  eax = ecx;  // @0_63ead0
  ebx = 0;  // @1_63ead0
  FL[3] = ebx;  // @2_63ead0
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @3_63ead0
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13320), sizeof v); (u32)v; }); FL[1] = ebx;  // @4_63ead0
  if (FL[0] == FL[1]) goto L63eb37;  // @5_63ead0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @6_63ead0
  L63eaf0:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ebx*4), sizeof v); (u32)v; });  // @8_63ead0
  FL[2] = (esi & esi);  // @9_63ead0
  if (FL[2] == 0) goto L63eb2c;  // @10_63ead0
  L63eaf7:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @12_63ead0
  ecx = edi;  // @13_63ead0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 24)))(ecx);  // @14_63ead0
  ecx = edx = 0;  // @15_63ead0
  FL[0] = eax; FL[1] = (u32)(1);  // @16_63ead0
  ecx = edi;  // @17_63ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @18_63ead0
  if (FL[0] != FL[1]) goto L63eb18;  // @19_63ead0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_63ead0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[0]);  // @21_63ead0
  ecx = edx = 0;  // @22_63ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @23_63ead0
  ecx = edi;  // @24_63ead0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @25_63ead0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[1]);  // @26_63ead0
  ecx = edx = 0;  // @27_63ead0
  goto L63eb22;  // @28_63ead0
  L63eb18:;
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; });  // @30_63ead0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 4)))(ecx, PV[2]);  // @31_63ead0
  ecx = edx = 0;  // @32_63ead0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @33_63ead0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(eax), &v, sizeof v); }  // @34_63ead0
  L63eb22:;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });  // @36_63ead0
  FL[2] = (esi & esi);  // @37_63ead0
  if (FL[2] != 0) goto L63eaf7;  // @38_63ead0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @39_63ead0
  L63eb2c:;
  ebx = (ebx + 1);  // @41_63ead0
  FL[3] = ebx;  // @42_63ead0
  FL[0] = ebx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 13320), sizeof v); (u32)v; });  // @43_63ead0
  if (FL[0] != FL[1]) goto L63eaf0;  // @44_63ead0
  L63eb37:;
  return eax;  // @46_63ead0
}
PCREG(63ead0, lifted_63ead0);

extern "C" u32 THISCALL lifted_63f570(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x4, &ecx_in, 4);   // prologue push ecx
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63f570
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 4), &v, sizeof v); }  // @1_63f570
  ebx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 16), sizeof v); (u32)v; });  // @2_63f570
  FL[2] = (ebx & ebx);  // @3_63f570
  if (FL[2] == 0) goto L63f5dd;  // @4_63f570
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @5_63f570
  if (FL[0] != FL[1]) goto L63f5dd;  // @6_63f570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_63f570
  PV[0] = (u32)(ebx);  // @8_63f570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 152)))(ecx, PV[0]);  // @9_63f570
  ecx = edx = 0;  // @10_63f570
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ebx + 8), sizeof v); (u32)v; });  // @11_63f570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @12_63f570
  edx = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(esi + 6), sizeof v); (u32)v; });  // @13_63f570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 104), sizeof v); (u32)v; });  // @14_63f570
  ecx = edx;  // @15_63f570
  ecx = (ecx & (u32)(4095));  // @16_63f570
  FL[3] = ecx;  // @17_63f570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*4), &v, sizeof v); }  // @18_63f570
  eax = (u32)(edx - 1);  // @19_63f570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @20_63f570
  PV[1] = (u32)(eax);  // @21_63f570
  ecx = (u32)(ecx + 47504);  // @22_63f570
  eax = ext_4ce180_thiscall2(ecx, PV[1]);  // @23_63f570
  ecx = edx = 0;  // @24_63f570
  eax = 0;  // @25_63f570
  FL[3] = eax;  // @26_63f570
  { u16 v = (u16)((eax & 0xffff)); __builtin_memcpy((void *)(u32)(esi + 6), &v, sizeof v); }  // @27_63f570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 4), sizeof v); (u32)v; });  // @28_63f570
  PV[2] = (u32)(ebx);  // @29_63f570
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 552), sizeof v); (u32)v; });  // @30_63f570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @31_63f570
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[2]);  // @32_63f570
  ecx = edx = 0;  // @33_63f570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edi + 16), &v, sizeof v); }  // @34_63f570
  L63f5dd:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @36_63f570
  FL[2] = (eax & eax);  // @37_63f570
  if (FL[2] == 0) goto L63f5f2;  // @38_63f570
  ecx = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @39_63f570
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 64), sizeof v); (u32)v; });  // @40_63f570
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(eax + ecx*8), &v, sizeof v); }  // @41_63f570
  L63f5f2:;
  return eax;  // @43_63f570
}
PCREG(63f570, lifted_63f570);

extern "C" u32 THISCALL lifted_41f0d0(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x664012);  // @h_41f0d0
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;  // @0_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @1_41f0d0
  edi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_41f0d0
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(esi + eax*4 + 61), &v, sizeof v); }  // @3_41f0d0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340940), sizeof v); (u32)v; });  // @4_41f0d0
  FL[2] = (ecx & ecx);  // @5_41f0d0
  if (FL[2] == 0) goto L41f116;  // @6_41f0d0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @7_41f0d0
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 8)))(ecx, (u32)(140));  // @8_41f0d0
  ecx = edx = 0;  // @9_41f0d0
  goto L41f11f;  // @10_41f0d0
  L41f116:;
  eax = ((u32( *)(u32))(*(u32 *)0x6762f0))((u32)(140));  // @12_41f0d0
  ecx = edx = 0;  // @13_41f0d0
  L41f11f:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP + 8), &v, sizeof v); }  // @15_41f0d0
  reg.state = (s32)((u32)(0));  // @16_41f0d0
  FL[2] = (eax & eax);  // @17_41f0d0
  if (FL[2] == 0) goto L41f13f;  // @18_41f0d0
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; });  // @19_41f0d0
  ecx = eax;  // @20_41f0d0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @21_41f0d0
  PV[2] = (u32)(edi);  // @22_41f0d0
  eax = ext_4d0f30_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @23_41f0d0
  ecx = edx = 0;  // @24_41f0d0
  ecx = eax;  // @25_41f0d0
  goto L41f141;  // @26_41f0d0
  L41f13f:;
  ecx = 0;  // @28_41f0d0
  FL[3] = ecx;  // @29_41f0d0
  L41f141:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @31_41f0d0
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(esi + eax*4 + 53), &v, sizeof v); }  // @32_41f0d0
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; }) + 1)); __builtin_memcpy((void *)(u32)(esi + 69), &v, sizeof v); }  // @33_41f0d0
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 69), sizeof v); (u32)v; });  // @34_41f0d0
  SEH_LEAVE();  // @35_41f0d0
  return eax;  // @36_41f0d0
}
PCREG(41f0d0, lifted_41f0d0);

extern "C" u32 THISCALL lifted_607b50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66e0b2);  // @h_607b50
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 - 0x10, &ecx_in, 4);   // prologue push ecx
  edi = ecx;  // @0_607b50
  eax = ext_41e290_cdecl1((u32)(5366));  // @1_607b50
  ecx = edx = 0;  // @2_607b50
  ecx = eax;  // @3_607b50
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }  // @4_607b50
  reg.state = (s32)((u32)(0));  // @5_607b50
  FL[2] = (ecx & ecx);  // @6_607b50
  if (FL[2] == 0) goto L607bae;  // @7_607b50
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 20), sizeof v); (u32)v; });  // @8_607b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @9_607b50
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @10_607b50
  PV[2] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 2511), sizeof v); (u32)v; });  // @11_607b50
  eax = ext_607f60_thiscall4(ecx, PV[2], PV[1], PV[0]);  // @12_607b50
  ecx = edx = 0;  // @13_607b50
  esi = eax;  // @14_607b50
  goto L607bb0;  // @15_607b50
  L607bae:;
  esi = 0;  // @17_607b50
  FL[3] = esi;  // @18_607b50
  L607bb0:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @20_607b50
  ecx = esi;  // @21_607b50
  PV[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @22_607b50
  reg.state = (s32)((u32)(4294967295));  // @23_607b50
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 648)))(ecx, PV[3]);  // @24_607b50
  ecx = edx = 0;  // @25_607b50
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @26_607b50
  ecx = esi;  // @27_607b50
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 656)))(ecx);  // @28_607b50
  ecx = edx = 0;  // @29_607b50
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 20), &v, sizeof v); }  // @30_607b50
  eax = 0;  // @31_607b50
  FL[3] = eax;  // @32_607b50
  SEH_LEAVE();  // @33_607b50
  return eax;  // @34_607b50
}
PCREG(607b50, lifted_607b50);


// ---- hand port (lifter rejects the push ebx/esi/edi prologue). GUESS name.
typedef void(THISCALL *w4c_t0)(void *);
// 0x429b50: three arrays of objects: [this+0xc] entries at this+4 (slot 0x2c), [this+0x1c] entries at this+0x10 (slot 0x2c), [this+0x60] entries at this+0x20 (slot 0x54); each count is re-read every pass.
static void THISCALL fn429b50(u8 *self) {
  for (u32 i = 0; i < *(volatile u32 *)(self + 0xc); i++) { void *o = *(void **)(self + 4 + 4 * i); (*(w4c_t0 **)o)[0x2c / 4](o); }
  for (u32 i = 0; i < *(volatile u32 *)(self + 0x1c); i++) { void *o = *(void **)(self + 0x10 + 4 * i); (*(w4c_t0 **)o)[0x2c / 4](o); }
  for (u32 i = 0; i < *(volatile u32 *)(self + 0x60); i++) { void *o = *(void **)(self + 0x20 + 4 * i); (*(w4c_t0 **)o)[0x54 / 4](o); }
}
PCREG(429b50, fn429b50);
