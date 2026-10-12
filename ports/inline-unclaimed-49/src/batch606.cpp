// batch606.cpp - area 49, batch 606: CAction::FindAction(const char *name, int, int id, int flag) (0x4a07c0).
// thiscall, ret 0x10 (four stack arguments; the second is never read). The SEH frame is not reproduced (no effect on the
// result). Callees stay the exe's code (ext_ bindings): 0x4cc850 (fastcall: name in ecx, pattern in edx). The CRT
// _stricmp is the import at 0x676414 (cdecl). Virtual calls, in exe order: the action object (this+0x44) slot 0x128 with
// three arguments (word [0x7002ac], &this+0x102, the object) when this+0x102 is empty; the object's [+0x10]->[+8] slots
// 0x4c and 0x5c (one argument, a pointer into the frame); the sound/manager at [0x70038c] slot 0xcc (one argument); each
// candidate's slot 0x14 (no arguments, twice).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vS3)(void *self, u32 a, u32 b, u32 c);           // slot 0x128: three arguments
typedef u32(THISCALL *vOne)(void *self, u32 a);                         // slots 0x4c, 0x5c, 0xcc: one argument
typedef u32(THISCALL *vNone)(void *self);                               // slot 0x14: no arguments
typedef int (*vStricmp)(const char *a, const char *b);                  // IAT 0x676414 (cdecl)
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);     // wildcard match (fastcall)

static bool nameIs(const char *name, u32 entryName) {                  // _stricmp(name, entry+0x76) == 0
  return ((vStricmp)(u32)G(u32, 0x676414))(name, (const char *)entryName) == 0;
}

// the candidate test of the object-manager loop (0x4a08a0 .. 0x4a0929)
static bool matchCandidate(u8 *s, const char *name, s32 id, u32 flag) {
  if (!((vNone)VT(s, 0x14))(s))
    return false;
  u32 q = ((vNone)VT(s, 0x14))(s);
  if (ext_4cc850((const char *)q, (const char *)0x67a110) != 0)
    return false;
  if (name && !nameIs(name, *(u32 *)(s + 0x76)))
    return false;
  if (id != -1 && *(s32 *)(s + 0x48) != id)
    return false;
  if (flag == 0)
    return true;
  return *(u32 *)(s + 0x106) == flag;
}

// 0x4a07c0 CAction::FindAction(name, unused, id, flag): thiscall, ret 0x10
static u8 *THISCALL findAction(u8 *self, const char *name, u32 unused, s32 id, u32 flag) {
  (void)unused;
  if (!self[0x63]) {                                                    // 0x4a0865 path: walk the manager
    u8 *x = *(u8 **)(self + 0x44);
    u8 *y = *(u8 **)(*(u8 **)(x + 0x10) + 8);
    if (!y)
      return nullptr;
    u32 tmp = 0;
    ((vOne)VT(y, 0x4c))(y, (u32)&tmp);
    x = *(u8 **)(self + 0x44);
    y = *(u8 **)(*(u8 **)(x + 0x10) + 8);
    u32 cur = ((vOne)VT(y, 0x5c))(y, (u32)&tmp);
    if (!tmp)
      return nullptr;
    for (;;) {                                                          // 0x4a08a0
      u8 *m = G(u8 *, 0x70038c);
      u8 *s = (u8 *)((vOne)VT(m, 0xcc))(m, cur);
      if (matchCandidate(s, name, id, flag))
        return s;
      x = *(u8 **)(self + 0x44);
      y = *(u8 **)(*(u8 **)(x + 0x10) + 8);
      cur = ((vOne)VT(y, 0x5c))(y, (u32)&tmp);
      if (!tmp)
        return nullptr;
    }
  }
  u8 *x = *(u8 **)(self + 0x44);
  u32 *slot = (u32 *)(self + 0x102);
  if (!*slot) {
    ((vS3)VT(x, 0x128))(x, (u32)(u16)G(u16, 0x7002ac), (u32)slot, (u32)x);
    if (!*slot) {
      self[0x5e] = 1;
      *slot = (u32)(self + 0x7e);
    }
  }
  u8 *list = (u8 *)*slot;
  for (u32 i = 0; i < *(u32 *)list; i++) {                              // the list: count, then entries
    u8 *e = *(u8 **)(list + 4 + i * 4);
    if (name && !nameIs(name, *(u32 *)(e + 0x76)))
      continue;
    if (id != -1 && *(s32 *)(e + 0x48) != id)
      continue;
    if (flag != 0 && *(u32 *)(e + 0x106) != flag)
      continue;
    return e;
  }
  return nullptr;
}
PCREG(4a07c0, findAction);
