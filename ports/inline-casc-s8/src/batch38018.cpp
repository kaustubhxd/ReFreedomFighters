// batch38018.cpp - cascade s8 batch 38018: 0x464a20 (find and attach the named child object when flag 0x80 is set).
#include "ff.h"

extern "C" const char *THISCALL ext_4e5330(u8 *p);
extern "C" u8 *THISCALL ext_4db3b0(u8 *p);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v6_t)(void *, u32, u32, u32, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

// 0x464a20, thiscall(a, flags) ret 8. Slot 0x270(a, flags) first; with flag 0x80 two names are taken from the objects at +0x5c / +0x60 (default string 0x677b5a), and slot 0x264(name,
// a, key) is tried with name2 then name1 for key +0x11a, then +0x11e, until it returns an object. That object's slot 0x20 / 0x1bc yields a child, which is bound through the
// owner's helper (0x4db3b0 of +8, slot 0x288), refreshed (slot 0x2c / 0x138 with the word at +0x126), and its handle from the table's slot 0x4c stored at +0x12a (flag 0x20),
// +0x12e (0x10) or +0x132.
static void THISCALL fn464a20(u8 *self, u32 a, u32 flags) {
  SLOT(self, 0x270, v2_t)(self, a, flags);
  if (!(flags & 0x80)) return;
  const char *D = (const char *)0x677b5a;
  const char *s1 = D, *s2 = D;
  u8 *p = *(u8 **)(self + 0x5c);
  if (p) s1 = ext_4e5330(p);
  u8 *q = *(u8 **)(self + 0x60);
  if (q) s2 = ext_4e5330(q);
  u32 k1 = *(u32 *)(self + 0x11a);
  u32 k2 = *(u32 *)(self + 0x11e);
  u8 *ob;
  if (k1 && *s2) {
    ob = (u8 *)SLOT(self, 0x264, v3_t)(self, (u32)s2, a, k1);
    if (ob) goto found;
  }
  k1 = *(u32 *)(self + 0x11a);
  if (k1 && *s1) {
    ob = (u8 *)SLOT(self, 0x264, v3_t)(self, (u32)s1, a, k1);
    if (ob) goto found;
  }
  k2 = *(u32 *)(self + 0x11e);
  if (k2 && *s2) {
    ob = (u8 *)SLOT(self, 0x264, v3_t)(self, (u32)s2, a, k2);
    if (ob) goto found;
  }
  k2 = *(u32 *)(self + 0x11e);
  if (!k2 || !*s1) return;
  ob = (u8 *)SLOT(self, 0x264, v3_t)(self, (u32)s1, a, k2);
  if (!ob) return;
found:
  {
    u32 r = SLOT(ob, 0x20, v6_t)(ob, 0, 0, 0, 0, 0, 1);
    u8 *child = (u8 *)SLOT(ob, 0x1bc, v1_t)(ob, r);
    if (!child) return;
    u8 *h = ext_4db3b0(*(u8 **)(self + 8));
    if (!h) return;
    SLOT(h, 0x288, v3_t)(h, (u32)child, 0, 1);
    SLOT(child, 0x2c, v0_t)(child);
    SLOT(child, 0x138, v3_t)(child, *(u16 *)(self + 0x126), 0, 0);
    u8 *t = *(u8 **)(ENG + 0x9b);
    u32 v = SLOT(t, 0x4c, v1_t)(t, (u32)child);
    if (flags & 0x20) *(u32 *)(self + 0x12a) = v;
    else if (flags & 0x10) *(u32 *)(self + 0x12e) = v;
    else *(u32 *)(self + 0x132) = v;
  }
}
PCREG(464a20, fn464a20);
