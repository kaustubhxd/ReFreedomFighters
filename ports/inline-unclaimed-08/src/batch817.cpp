// batch817.cpp - unclaimed-08 batch 17: CRigidBody::InitCentroid() (high; residue 7, ragdoll; coordinator's instruction).
// Thiscall, no arguments, ret. Two paths decided by the rigid body's vtable +0x1e0 (flag 0x200002):
//  - true: the accumulator at this+0x111 is zeroed, every 12-byte element of the array at this+0x14e (count at +0x152) is
//    added to it (0x441940, original code, fastcall), then the accumulator is scaled by 1.0f / count (0x4e0d00, original).
//  - false: a second +0x1e0 test (0x200002) ends the function if true; otherwise: if the object at this+0x44 + 0xc has
//    flag 0x100000 in its dword at +0x23 the accumulator is filled by vtable +0x2bc(acc, &local, 1); else it is copied
//    from the object at +8 (+0x30..+0x38).
// Both paths then copy the accumulator to this+0x11d, +0x121, +0x125 and call vtable +0x84(acc).
// The accumulator's float constant is 1.0f (0x678858).
#include "ff.h"

extern "C" void FASTCALL ext_441940(void *dst, const void *src);
extern "C" void THISCALL ext_4e0d00(void *self, float s);

// 0x53f630, CRigidBody::InitCentroid() (high).
static void THISCALL rigidBodyInitCentroid(u8 *self) {
  u8 *rb = *(u8 **)(self + 0x44);
  u8 *acc = self + 0x111;
  if (vcall<u8>(rb, 0x1e0, (u32)0x200002)) {
    *(u32 *)(acc + 0) = 0;
    *(u32 *)(acc + 4) = 0;
    *(u32 *)(acc + 8) = 0;
    s32 n = *(s32 *)(self + 0x152);
    for (s32 i = 0; i < n; i++) ext_441940(acc, *(u8 **)(self + 0x14e) + 12 * i);
    float count = (float)*(s32 *)(self + 0x152);
    ext_4e0d00(acc, 1.0f / count);
  } else {
    if (vcall<u8>(rb, 0x1e0, (u32)0x200002)) return;
    u8 *c = *(u8 **)(rb + 0xc);
    if (!(*(u32 *)(c + 0x23) & 0x100000)) {
      u8 *obj = *(u8 **)(rb + 8);
      *(u32 *)(acc + 0) = *(u32 *)(obj + 0x30);
      *(u32 *)(acc + 4) = *(u32 *)(obj + 0x34);
      *(u32 *)(acc + 8) = *(u32 *)(obj + 0x38);
    } else {
      u8 local[0x10];
      vcall<void>(rb, 0x2bc, (void *)acc, (void *)local, (u32)1);
    }
  }
  *(u32 *)(self + 0x11d) = *(u32 *)(acc + 0);
  *(u32 *)(self + 0x121) = *(u32 *)(acc + 4);
  *(u32 *)(self + 0x125) = *(u32 *)(acc + 8);
  vcall<void>(rb, 0x84, (void *)acc);
}
PCREG(53f630, rigidBodyInitCentroid);
