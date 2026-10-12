// batch1005.cpp - unclaimed-04 batch 5 (docs/20-unclaimed-04.md): ZActor::RemovePath (0x47abb0, high name).
// thiscall, three stack arguments (ret 0xc). The release helpers 0x41e2c0 (cdecl, one argument) and 0x634273 (cdecl,
// pointer and size) are original code here; the spec hooks them with logging stubs (GUESS: they release memory).
#include "ff.h"

typedef u32(THISCALL *vfn0_t)(void *self);
typedef void(THISCALL *vfn1_t)(void *self, u32 a);
typedef void(THISCALL *vfn3_t)(void *self, u32 a, u32 b, u32 c);

static inline u32 vslot(void *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

extern "C" void ext_41e2c0(void *p);         // original code (release helper)
extern "C" void ext_634273(void *p, u32 n);  // original code (delete with size)

// 0x47abb0. self = this, a1 = unsigned int, reason = PATH_CANCEL_REASONS, flag = bool (low byte tested).
static void THISCALL actorRemovePath(u8 *self, u32 a1, u32 reason, u32 flag) {
  if ((u8)flag == 0) *(u32 *)(self + 0x691) = 0;
  *(u32 *)(self + 0x727) = a1;
  *(u32 *)(self + 0x72b) = reason;

  u8 *path = *(u8 **)(self + 0x695);
  if (path) {
    u32 q = *(u32 *)(path + 0xc);
    if (q) ext_41e2c0((void *)q);
    q = *(u32 *)(path + 0x10);
    if (q) ext_634273((void *)q, 4);
    q = *(u32 *)(path + 0x14);
    if (q) ext_634273((void *)q, 4);
    ext_634273(path, 0x18);
    *(u32 *)(self + 0x695) = 0;
    if (*(u32 *)(self + 0x727) != 1) self[0x699] = 0;
    // vtable slot 0x620 with (&this+0x660, 1, 0): the arguments are pushed in the order 0, 1, &this+0x660
    ((vfn3_t)vslot(self, 0x620))(self, (u32)(self + 0x660), 1, 0);
  }

  // skipped only when byte +0x726 is nonzero and the dword at +0x64c is not 0xb
  if (self[0x726] == 0 || *(u32 *)(self + 0x64c) == 0xb) {
    u32 alive = ((vfn0_t)vslot(self, 0x588))(self);  // vtable slot 0x588, no arguments (what it is: not identified)
    ((vfn1_t)vslot(self, 0x62c))(self, alive != 0);
  }
}
PCREG(47abb0, actorRemovePath);
