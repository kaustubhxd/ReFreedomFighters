// batch811.cpp - animation layer thread, batch 811: ZBoneAnim (one running clip on a ZLNKOBJ) and its event
// callbacks. ZBoneAnim (PC, offsets of the object; the pool hands out object + 4):
//   +0..+0x20 state (cleared by Create), +0x24 last callback time (-1 = none), +0x28/+0x30/+0x34 segment values,
//   +0x44 state (-2 = waiting to start, see EndMatBoneMotion), +0x48 anim id from the scene, +0x4c clip name (copied),
//   +0x6c callback list (LINKSORTREFTAB(0x20, 3), sorted by time), +0x70 AnimHeader*, +0x74 owner ZLNKOBJ*.
// Callback list node (as written by AddCallBack, node = data - 4): +0 flags, +4 0 (MSVC member-pointer adjust), +8
// function bool (ZLNKOBJ::*)(ZBoneAnim*, float key, float now, unsigned flags), called on the owner.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

typedef bool(THISCALL *animcb_t)(void *owner, void *ba, float key, float now, u32 flags);

// ZBoneAnim::Create(ZLNKOBJ* owner, const char* name) [low map confidence, GC 8017f5f0; body fits]. The name is the
// AnimHeader itself (ActivateAnimSegment passes the header; the clip name is its first field).
static void THISCALL ZBoneAnim_Create(u8 *ba, void *owner, const char *name) {
  F32(ba, 0x14) = 0; F32(ba, 0) = 0; F32(ba, 4) = 0; F32(ba, 8) = 0;
  F32(ba, 0x18) = 0; F32(ba, 0xc) = 0; F32(ba, 0x20) = 0; F32(ba, 0x1c) = 0;
  F32(ba, 0x48) = vcall<u32>(FP(G(u8 *, 0x70039c), 0x9b), 0x18);
  F32(ba, 0x24) = 0xbf800000;   // -1.0f
  F32(ba, 0x6c) = 0;
  FP(ba, 0x74) = owner;
  F32(ba, 0x44) = 0;
  F32(ba, 0x70) = 0;
  char *d = (char *)ba + 0x4c;
  char ch;
  do { ch = *name++; *d++ = ch; } while (ch);
  F32(ba, 0x38) = 0; F32(ba, 0x3c) = 0; F32(ba, 0x40) = 0;
}
PCREG(462460, ZBoneAnim_Create);

// ZBoneAnim::AddCallBack(float time, callback, unsigned flags) [high, GC 8017f9f4]. thiscall ret 0xc.
extern "C" void *ext_41e290(u32 size);                           // operator new (cdecl)
extern "C" void *THISCALL ext_4ccad0(void *p, u32 a, u32 b);     // LINKSORTREFTAB::LINKSORTREFTAB
static void THISCALL ZBoneAnim_AddCallBack(u8 *ba, float time, u32 cb, u32 flags) {
  if (!FP(ba, 0x6c)) {
    void *p = ext_41e290(0x2c);
    FP(ba, 0x6c) = p ? ext_4ccad0(p, 0x20, 3) : 0;
  }
  u32 *e = vcall<u32 *>(FP(ba, 0x6c), 0x98, 0, time, 0);
  e[-1] = flags;
  e[0] = 0;
  e[1] = cb;
}
PCREG(4614d0, ZBoneAnim_AddCallBack);

// ZBoneAnim::Destroy(bool fire) [medium, GC 8017fb34]: with fire, every pending callback is called with (key, -1, 0);
// then the list is deleted (vt 0, deleting destructor). List vtable: 0x4c begin(it), 0x64 next(it) -> node,
// 0x9c key(node) (x87 float), 0x44 remove current(it), 0xa0 reinsert(node, key), 0x14 count.
static void THISCALL ZBoneAnim_Destroy(u8 *ba, u8 fire) {
  if (!FP(ba, 0x6c)) return;
  if (fire) {
    u8 it[12];
    vcall<void>(FP(ba, 0x6c), 0x4c, it);
    u32 *e = vcall<u32 *>(FP(ba, 0x6c), 0x64, it);
    while (e) {
      float k = vcall<float>(FP(ba, 0x6c), 0x9c, e);
      if (e[1]) ((animcb_t)e[2])(FP(ba, 0x74), ba, k, -1.0f, 0);
      e = vcall<u32 *>(FP(ba, 0x6c), 0x64, it);
    }
  }
  if (FP(ba, 0x6c)) vcall<void>(FP(ba, 0x6c), 0, 1);
  FP(ba, 0x6c) = 0;
}
PCREG(462510, ZBoneAnim_Destroy);

// ZBoneAnim::UpdateCallBacks(float now) [medium, GC 8017fc9c]: fires, in time order, every callback whose key is
// <= now (once per distinct now). A callback that returns false is reported to the assert hook at [0x7003b0]
// (int3 when none) and re-queued one clip length later (key = frame count +0xc + now). An empty list is deleted.
static void THISCALL ZBoneAnim_UpdateCallBacks(u8 *ba, float now) {
  if (!FP(ba, 0x6c)) return;
  if (FF(ba, 0x24) == now) return;
  FF(ba, 0x24) = now;
  if (vcall<u32>(FP(ba, 0x6c), 0x14)) {
    do {
      if (FP(ba, 0x6c)) {
        u8 it[16];
        vcall<void>(FP(ba, 0x6c), 0x4c, it);
        u32 *e = vcall<u32 *>(FP(ba, 0x6c), 0x64, it);
        while (e) {
          float k = vcall<float>(FP(ba, 0x6c), 0x9c, e);
          if (k > now) return;
          vcall<void>(FP(ba, 0x6c), 0x44, it);
          if (!((animcb_t)e[2])(FP(ba, 0x74), ba, k, now, e[0])) {
            typedef void (*hook_t)();
            hook_t fp = G(hook_t, 0x7003b0);
            if (fp) fp();
            else __builtin_debugtrap();
            vcall<void>(FP(ba, 0x6c), 0xa0, e, (float)*(s32 *)(ba + 0xc) + now);
            break;
          }
          if (!FP(ba, 0x6c)) return;
          e = vcall<u32 *>(FP(ba, 0x6c), 0x64, it);
        }
      }
    } while (vcall<u32>(FP(ba, 0x6c), 0x14));
  }
  if (!vcall<u32>(FP(ba, 0x6c), 0x14)) {
    if (FP(ba, 0x6c)) vcall<void>(FP(ba, 0x6c), 0, 1);
    FP(ba, 0x6c) = 0;
  }
}
PCREG(465330, ZBoneAnim_UpdateCallBacks);
