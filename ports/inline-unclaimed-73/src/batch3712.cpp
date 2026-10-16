// batch3712.cpp - area 73 batch 12 (residue 12, heavy item 2): CAction::End() (0x4a0440, docs/20-unclaimed-73.md).
// Branch groups: (A) the owner-list removal and logger; (B) this+0x5e clear: the flag-clear walk; (C) this+0x5e set and
// this+0x7e non-zero: copy the lists into the action and walk the owner chain; (D) this+0x5e set and this+0x7e zero:
// the 0x12c loop over this+0x6e, then the holder path (0x25c on the holder, 0x4c/0x28/0x224 on the render control and the
// holder's sub-object, 0x4dc630 unless this+0x65). The tail (this+0x7a, this+0x76 through g_sys slot +0xfc) runs after B, C
// and the D path, but not when the holder is null (the original jumps past the tail there).
#include "ff.h"

// 0x4a1630: thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_4a1630(u8 *controller, u8 *self);
// 0x49f8a0: CActionController::Add, thiscall, one argument (original code, hooked in the spec).
extern "C" void THISCALL ext_49f8a0(u8 *controller, u32 action);
// 0x4dc630: thiscall, two arguments (original code, hooked in the spec).
extern "C" void THISCALL ext_4dc630(u8 *obj, u32 p0, u32 p1);

// The 2-byte-unrolled compare of the original: 0 when the two NUL-terminated strings are equal, nonzero otherwise.
static u32 sameString(const u8 *a, const u8 *b) {
  for (;;) {
    if (*a != *b)
      return 1;
    if (*a == 0)
      return 0;
    a++;
    b++;
  }
}

// (B) this+0x5e clear: the first owner entry with its byte at +0x5e set gets +0x66 = 3.
static void flagClearWalk(u8 *self) {
  u32 *l2 = *(u32 **)(self + 0x102);
  if (!l2)
    return;
  u32 i = 0;
  while (i != l2[0]) {
    u8 *item = (u8 *)l2[i + 1];
    if (*(u8 *)(item + 0x5e) != 0) {
      *(u32 *)(item + 0x66) = 3;
      return;
    }
    i++;
  }
}

// (C) this+0x5e set and this+0x7e non-zero.
static void copyAndWalk(u8 *self, u32 y) {
  u8 *act = *(u8 **)(self + 0x82);
  *(u8 *)(act + 0x5e) = 1;
  if (*(u32 *)(self + 0x6a) != 0 && y != 0)
    ext_49f8a0((u8 *)y, (u32)act);
  u32 n6a = *(u32 *)(self + 0x6a);
  *(u32 *)(act + 0x6a) = n6a;
  for (u32 i = 0; i < n6a; i++)
    *(u32 *)(act + 0x6e + 4 * i) = *(u32 *)(self + 0x6e + 4 * i);
  *(u32 *)(act + 0x66) = 3;
  u32 n7e = *(u32 *)(self + 0x7e);
  *(u32 *)(act + 0x7e) = n7e;
  for (u32 i = 0; i < n7e; i++)
    *(u32 *)(act + 0x82 + 4 * i) = *(u32 *)(self + 0x82 + 4 * i);

  u8 *s44 = *(u8 **)(self + 0x44);
  u8 *q = *(u8 **)(*(u8 **)(s44 + 0x10) + 8);
  if (!q)
    return;
  u32 l18 = 0;
  vcall<void>(q, 0x4c, (u32)&l18);
  u32 item = vcall<u32>(*(void **)(*(u8 **)(*(u8 **)(self + 0x44) + 0x10) + 8), 0x5c, (u32)&l18);
  if (l18 == 0)
    return;
  do {
    void *ctrl = G(void *, 0x70038c);
    u32 r = vcall<u32>(ctrl, 0xcc, item);
    if (r && vcall<u32>((void *)r, 0x14)) {
      u32 str = vcall<u32>((void *)r, 0x14);
      if (sameString((const u8 *)str, (const u8 *)0x67a110) == 0)
        *(u32 *)(r + 0x102) = (u32)act + 0x7e;
    }
    item = vcall<u32>(*(void **)(*(u8 **)(*(u8 **)(self + 0x44) + 0x10) + 8), 0x5c, (u32)&l18);
  } while (l18 != 0);
}

// (D) the 0x12c loop and the holder path. Returns false when the original skips the tail (holder null).
static bool zeroSecondListPath(u8 *self) {
  u32 n6a = *(u32 *)(self + 0x6a);
  *(u8 *)(self + 0x5e) = 0;
  *(u32 *)(self + 0x102) = 0;
  for (u32 i = 0; i < n6a; i++) {
    u32 esi_v = *(u32 *)(self + 0x6e + 4 * i);
    u8 *sys = G(u8 *, 0x70039c);
    u8 *ctl = *(u8 **)(sys + 0x9b);
    u8 *s44 = *(u8 **)(self + 0x44);
    u32 w = vcall<u32>(ctl, 0x4c, (u32)s44);
    vcall<void>(s44, 0x12c, esi_v, (u32)*(u16 *)0x7002c4, w);
  }
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  u8 *holder = *(u8 **)(ctl + 0xadc);
  if (!holder)
    return false;
  u32 esi_obj = vcall<u32>(holder, 0x25c, 0x68f8f8u, 0u);
  if (esi_obj) {
    u32 w = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, *(u32 *)(self + 0x44));
    u8 *sub = *(u8 **)(esi_obj + 0x18);
    u32 r2 = vcall<u32>(sub, 0x28, w);
    if (r2)
      vcall<void>((void *)esi_obj, 0x224, w);
  }
  if (*(u8 *)(self + 0x65) == 0)
    ext_4dc630(*(u8 **)(*(u8 **)(self + 0x44) + 8), 0u, 2u);
  return true;
}

// Tail: this+0x7a and this+0x76 each get g_sys slot +0xfc, then both are zeroed.
static void endTail(u8 *self) {
  u32 v7a = *(u32 *)(self + 0x7a);
  u8 *sysobj = G(u8 *, 0x70039c);
  if (v7a)
    vcall<void>(sysobj, 0xfc, v7a);
  u32 v76 = *(u32 *)(self + 0x76);
  if (v76)
    vcall<void>(sysobj, 0xfc, v76);
  *(u32 *)(self + 0x7a) = 0;
  *(u32 *)(self + 0x76) = 0;
}

// 0x4a0440, CAction::End() (high), thiscall, plain ret.
static void THISCALL actionEnd(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  u8 *x = (u8 *)vcall<u32>(ctl, 0x138);
  u32 local4 = 0;
  vcall<void>(x, 0x88, 0x68f724u, (u32)&local4);
  u32 y = 0;
  if (local4 != 0) {
    void *ctrl = G(void *, 0x70038c);
    y = vcall<u32>(ctrl, 0xcc, local4);
    if (y)
      ext_4a1630((u8 *)y, self);
  }

  // (A) remove this from the owner list at +0x102 (the last entry takes its slot), or log 0x4cb when there is no list.
  u32 *lst = *(u32 **)(self + 0x102);
  if (lst) {
    u32 cnt = lst[0];
    u32 i = 0;
    bool found = false;
    while (i != cnt) {
      if (lst[i + 1] == (u32)self) {
        found = true;
        break;
      }
      i++;
    }
    if (found) {
      lst[0] -= 1;
      lst[i + 1] = lst[lst[0] + 1];
    }
  } else {
    void *log = vcall<void *>(G(void *, 0x700390), 0x20, 0x68f6b4u, 0x4cbu);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x68f8d0);
  }

  if (*(u8 *)(self + 0x5e) == 0) {
    flagClearWalk(self);
    endTail(self);
    return;
  }
  if (*(u32 *)(self + 0x7e) != 0) {
    copyAndWalk(self, y);
    endTail(self);
    return;
  }
  if (zeroSecondListPath(self))
    endTail(self);
}
PCREG(4a0440, actionEnd);
