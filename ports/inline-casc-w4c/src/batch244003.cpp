// batch244003.cpp - Sonnet-w2, mechanically lifted ports (lift.py) with automatically generated specs (autospec.py).
#include "ff.h"


#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_656160(u32 ecx_in, u32 a0) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @0_656160
  esi = ecx;  // @1_656160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6819), sizeof v); (u32)v; });  // @2_656160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_656160
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 32), sizeof v); (u32)v; });  // @4_656160
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @5_656160
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 12)))(ecx, PV[0]);  // @6_656160
  ecx = edx = 0;  // @7_656160
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @8_656160
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @9_656160
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + ecx*4), sizeof v); (u32)v; });  // @10_656160
  ecx = esi;  // @11_656160
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 108)))(ecx, PV[1], (u32)(0));  // @12_656160
  ecx = edx = 0;  // @13_656160
  return eax;  // @14_656160
}
PCREG(656160, lifted_656160);

extern "C" u32 STDCALL lifted_6563e0(u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = 0, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_6563e0
  esi = (u32)(eax + eax*4);  // @1_6563e0
  esi = (esi << (u32)(3));  // @2_6563e0
  FL[3] = esi;  // @3_6563e0
  FL[2] = (esi & esi);  // @4_6563e0
  if (FL[2] == 0) goto L65640c;  // @5_6563e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });  // @6_6563e0
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 6415), sizeof v); (u32)v; });  // @7_6563e0
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });  // @8_6563e0
  eax = ((u32(THISCALL *)(u32))(*(u32 *)(eax + 32)))(ecx);  // @9_6563e0
  ecx = edx = 0;  // @10_6563e0
  PV[0] = (u32)(esi);  // @11_6563e0
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @12_6563e0
  ecx = eax;  // @13_6563e0
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });  // @14_6563e0
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(edx + 24)))(ecx, PV[1], PV[0]);  // @15_6563e0
  ecx = edx = 0;  // @16_6563e0
  L65640c:;
  return eax;  // @18_6563e0
}
PCREG(6563e0, lifted_6563e0);

extern "C" u32 THISCALL lifted_656730(u32 ecx_in, u32 a0, u32 a1) {
  u8 F[0x400] __attribute__((aligned(4)));
  u32 EBP = (u32)(F + 0x300);
  u32 PV[64], FL[4] = {0, 0, 0, 0}; u32 ecx_zero = 0, edx_zero = 0;
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  PV[0] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; });  // @0_656730
  esi = ecx;  // @1_656730
  PV[1] = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });  // @2_656730
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @3_656730
  eax = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(eax + 232)))(ecx, PV[1], PV[0]);  // @4_656730
  ecx = edx = 0;  // @5_656730
  ecx = eax;  // @6_656730
  FL[2] = (ecx & ecx);  // @7_656730
  if (FL[2] != 0) goto L65674f;  // @8_656730
  return eax;  // @9_656730
  L65674f:;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });  // @11_656730
  PV[2] = (u32)(ecx);  // @12_656730
  ecx = esi;  // @13_656730
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 12)))(ecx, PV[2]);  // @14_656730
  ecx = edx = 0;  // @15_656730
  eax = ({ u16 v; __builtin_memcpy(&v, (void *)(u32)(eax + 4), sizeof v); (u32)v; });  // @16_656730
  return eax;  // @17_656730
}
PCREG(656730, lifted_656730);


// ---- hand ports (lifter rejects these bodies). GUESS names.
struct W4c_u32 { u32 v; } __attribute__((packed));
extern "C" void ext_42ab62(const char *msg);   // cdecl, 1 arg (error/log)
typedef void(THISCALL *w4c_v0_t)(void *);

// 0x54e3f0: reset [this+0x1c5] (signed count) 107-byte records starting at this+0x1c: dword +0 = index, ptr (+0x40 from the dword) = this, bytes cleared; then byte [this+0x1c9] = 0.
// The count is re-read on every iteration (records may overlap the count field).
static void THISCALL fn54e3f0(u8 *self) {
  s32 i = 0;
  if (*(volatile s32 *)(self + 0x1c5) > 0) {
    u8 *p = self + 0x5b;
    do {
      ((W4c_u32 *)(p - 0x3f))->v = (u32)i;
      p += 0x6b;
      p[-0x5e] = 0;
      i++;
      ((W4c_u32 *)(p - 0x6b))->v = (u32)self;
      p[-0x84] = 0;
    } while (i < *(volatile s32 *)(self + 0x1c5));
  }
  self[0x1c9] = 0;
}
PCREG(54e3f0, fn54e3f0);

// 0x63b940: for each of [this+0xec] objects stored at this+0xf0.., call their vtable slot 0x6c (thiscall, no args). The count is re-read every iteration.
static void THISCALL fn63b940(u8 *self) {
  if (*(volatile u32 *)(self + 0xec) != 0) {
    u32 i = 0;
    u8 *e = self + 0xf0;
    do {
      void *o = *(void **)e;
      (*(w4c_v0_t **)o)[0x6c / 4](o);
      i++;
      e += 4;
    } while (i != *(volatile u32 *)(self + 0xec));
  }
}
PCREG(63b940, fn63b940);

// 0x6078a0: Steam startup check: true when SteamAPI_Init succeeds and the app need not restart; logs 0x6b9ee4 when Init fails.
static u8 STDCALL fn6078a0() {
  u8 r = (*(u8(**)(u32))0x67649c)(0x1490c4);
  if (r) return 0;
  r = (*(u8(**)())0x6764a4)();
  if (r) return 1;
  ext_42ab62((const char *)0x6b9ee4);
  return 0;
}
PCREG(6078a0, fn6078a0);
