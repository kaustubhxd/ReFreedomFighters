// batch244011.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_63f610(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63f610
  edi = ecx;  // @1_63f610
  PV[0] = (u32)(esi);  // @2_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_63f610
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @4_63f610
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @5_63f610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[0]);  // @6_63f610
  ecx = edx = 0;  // @7_63f610
  edx = eax;  // @8_63f610
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; })) & 0xffff);  // @9_63f610
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @10_63f610
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @11_63f610
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @12_63f610
  esi = (esi - edx);  // @13_63f610
  FL[3] = esi;  // @14_63f610
  esi = (esi - (u32)(16));  // @15_63f610
  FL[3] = esi;  // @16_63f610
  esi = (u32)((s32)esi >> (u32)(12));  // @17_63f610
  FL[3] = esi;  // @18_63f610
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @19_63f610
  { u16 v = (u16)((esi & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 2), &v, sizeof v); }  // @20_63f610
  if (FL[0] != FL[1]) goto L63f671;  // @21_63f610
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = edx;  // @22_63f610
  if (FL[0] != FL[1]) goto L63f651;  // @23_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @24_63f610
  ecx = 0;  // @25_63f610
  FL[3] = ecx;  // @26_63f610
  FL[0] = eax; FL[1] = edx;  // @27_63f610
  if (FL[0] == FL[1]) eax = ecx;  // @28_63f610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @29_63f610
  L63f651:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @31_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @32_63f610
  PV[1] = (u32)(edx);  // @33_63f610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @34_63f610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @35_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @36_63f610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @37_63f610
  ecx = edi;  // @38_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @39_63f610
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[1]);  // @40_63f610
  ecx = edx = 0;  // @41_63f610
  return eax;  // @42_63f610
  L63f671:;
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @44_63f610
  if (FL[0] == FL[1]) goto L63f69d;  // @45_63f610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @46_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @47_63f610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @48_63f610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @49_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @50_63f610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @51_63f610
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @52_63f610
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @53_63f610
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @54_63f610
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @55_63f610
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @56_63f610
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @57_63f610
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @58_63f610
  L63f69d:;
  return eax;  // @60_63f610
}
PCREG(63f610, lifted_63f610);

extern "C" u32 THISCALL lifted_63f760(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @0_63f760
  edi = ecx;  // @1_63f760
  PV[0] = (u32)(esi);  // @2_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @3_63f760
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edi + 12), &v, sizeof v); }  // @4_63f760
  FL[3] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 12), sizeof v); (u32)v; });  // @5_63f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 44)))(ecx, PV[0]);  // @6_63f760
  ecx = edx = 0;  // @7_63f760
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; }) & (u32)(253))); __builtin_memcpy((void *)(u32)(esi + 5), &v, sizeof v); }  // @8_63f760
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(esi + 5), sizeof v); (u32)v; });  // @9_63f760
  edx = eax;  // @10_63f760
  ecx = (ecx & 0xffff0000u) | ((({ u16 v; __builtin_memcpy(&v, (void *)(u32)(edx + 2), sizeof v); (u32)v; })) & 0xffff);  // @11_63f760
  { u8 v = (u8)((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }) - 1)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }  // @12_63f760
  FL[3] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; });  // @13_63f760
  { u16 v = (u16)((ecx & 0xffff)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }  // @14_63f760
  esi = (esi - edx);  // @15_63f760
  FL[3] = esi;  // @16_63f760
  esi = (esi - (u32)(16));  // @17_63f760
  FL[3] = esi;  // @18_63f760
  esi = (u32)((s32)esi >> (u32)(4));  // @19_63f760
  FL[3] = esi;  // @20_63f760
  FL[0] = ({ u8 v; __builtin_memcpy(&v, (void *)(u32)(edx), sizeof v); (u32)v; }); FL[1] = (u32)(0);  // @21_63f760
  { u16 v = (u16)((esi & 0xffff)); __builtin_memcpy((void *)(u32)(edx + 2), &v, sizeof v); }  // @22_63f760
  if (FL[0] != FL[1]) goto L63f7c5;  // @23_63f760
  FL[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; }); FL[1] = edx;  // @24_63f760
  if (FL[0] != FL[1]) goto L63f7a5;  // @25_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @26_63f760
  ecx = 0;  // @27_63f760
  FL[3] = ecx;  // @28_63f760
  FL[0] = eax; FL[1] = edx;  // @29_63f760
  if (FL[0] == FL[1]) eax = ecx;  // @30_63f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @31_63f760
  L63f7a5:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @33_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @34_63f760
  PV[1] = (u32)(edx);  // @35_63f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @36_63f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @37_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @38_63f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @39_63f760
  ecx = edi;  // @40_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi), sizeof v); (u32)v; });  // @41_63f760
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, PV[1]);  // @42_63f760
  ecx = edx = 0;  // @43_63f760
  return eax;  // @44_63f760
  L63f7c5:;
  FL[0] = edx; FL[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @46_63f760
  if (FL[0] == FL[1]) goto L63f7f1;  // @47_63f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @48_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @49_63f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @50_63f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 12), sizeof v); (u32)v; });  // @51_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edx + 8), sizeof v); (u32)v; });  // @52_63f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(ecx + 8), &v, sizeof v); }  // @53_63f760
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 8), sizeof v); (u32)v; });  // @54_63f760
  { u32 v = (u32)(ecx); __builtin_memcpy((void *)(u32)(edx + 8), &v, sizeof v); }  // @55_63f760
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 12), sizeof v); (u32)v; });  // @56_63f760
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(edx + 12), &v, sizeof v); }  // @57_63f760
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(eax + 8), &v, sizeof v); }  // @58_63f760
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(ecx + 12), &v, sizeof v); }  // @59_63f760
  { u32 v = (u32)(edx); __builtin_memcpy((void *)(u32)(edi + 8), &v, sizeof v); }  // @60_63f760
  L63f7f1:;
  return eax;  // @62_63f760
}
PCREG(63f760, lifted_63f760);


// ---- hand port (lifter: callee 0x4293e0 ends in a tail jump, return size ambiguous). GUESS name.
extern "C" void THISCALL ext_435ae0(u8 *self);
extern "C" void THISCALL ext_428990(u8 *self);
extern "C" void THISCALL ext_4293e0(u8 *self);
extern "C" s32 STDCALL ext_61ba16(u32 hinst, u32 version, u32 iid, u32 *out, u32 outer);   // thunk to DINPUT8!DirectInput8Create
typedef u32(STDCALL *w4c_s1u_t)(void *);
typedef u32(STDCALL *w4c_s5_t)(void *, u32, u32, void *, u32);

// 0x4285f0: input manager constructor (SEH frame, state 0 once the base is built): base ctor 0x435ae0, vtable 0x678d2c, global 0x7003a0 = this,
// DirectInput8Create(engine hinst [+0x9cf], 0x800, IID 0x6be1c0, &this[0x7c], 0); failure releases a created interface; when one exists
// slot 0x10(0, 0x428b60, this, 0) is called and 0x428990 runs; then 0x4293e0, byte [this+0x8e] = 0; returns this.
static u8 *THISCALL fn4285f0(u8 *self) {
  SEH_ENTER(0x664788);
  ext_435ae0(self);
  *(u32 *)self = 0x678d2c;
  u32 *pif = (u32 *)(self + 0x7c);
  G(u8 *, 0x7003a0) = self;
  *pif = 0;
  u32 hinst = *(u32 *)(*(u8 **)0x70039c + 0x9cf);
  reg.state = 0;
  s32 hr = ext_61ba16(hinst, 0x800, 0x6be1c0, pif, 0);
  if (hr < 0) {
    void *o = (void *)*pif;
    if (o) {
      (*(w4c_s1u_t **)o)[8 / 4](o);
      *pif = 0;
    }
  }
  void *o = (void *)*pif;
  if (o) {
    (*(w4c_s5_t **)o)[0x10 / 4](o, 0, 0x428b60, self, 0);
    ext_428990(self);
  }
  ext_4293e0(self);
  self[0x8e] = 0;
  SEH_LEAVE();
  return self;
}
PCREG(4285f0, fn4285f0);
