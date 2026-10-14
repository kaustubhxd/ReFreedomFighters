// batch37034.cpp - cascade s6 batch 37034: 0x573000.
#include "ff.h"

typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))

static bool sameStr(const u8 *a, const u8 *b) {
  for (;;) {
    if (*a != *b) return false;
    if (!*a) return true;
    a++;
    b++;
  }
}
#define S318(o, x) ((u8 *)(*(v1_t **)(o))[0x318 / 4]((o), (x)))
#define S31C(o, x, y) ((*(v2_t **)(o))[0x31c / 4]((o), (u32)(x), (u32)(y)))

// 0x573000, thiscall(flag) ret 4: sets this+0x180, scans the list at this+0x44 (slot 0x50 iterates from +8) for the last node object (node+0x54) whose name at +4
// (default string 0x67c8e8) equals the string at 0x6a8c14 and that answers slot 0x1e0(0x100033). When found, links its child objects (slot 0x318 by index 3 / 4, slot 0x31c to
// set a link) in one of two patterns chosen by flag (flag set: three links, clear: only when child 4 exists), then calls its slot 0xbc with (flag == 0).
static void THISCALL fn573000(u8 *self, u32 flagw) {
  u8 flag = (u8)flagw;
  u8 *T = 0;
  *(u8 *)(self + 0x180) = 1;
  u8 *node = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  if (node) {
    do {
      u8 *esi = *(u8 **)(node + 0x54);
      const u8 *nm = *(const u8 **)(esi + 4);
      if (!nm) nm = (const u8 *)0x67c8e8;
      if (sameStr(nm, (const u8 *)0x6a8c14)) {
        if ((u8)(*(v1_t **)esi)[0x1e0 / 4](esi, 0x100033)) T = esi;
      }
      u8 *l = *(u8 **)(self + 0x44);
      u32 var = (u32)node;
      (*(v1_t **)l)[0x50 / 4](l, (u32)&var);
      node = (u8 *)var;
    } while (node);
  }
  if (!T) return;
  if (flag) {
    u8 *x1 = S318(T, 3);
    u8 *x2 = S318(x1, 4);
    S31C(T, x2, 4);
    u8 *x3 = S318(T, 3);
    u8 *x4 = S318(x3, 4);
    S31C(x4, T, 3);
    u8 *x5 = S318(T, 3);
    S31C(x5, T, 4);
  } else {
    if (S318(T, 4)) {
      u8 *b = S318(T, 3);
      u8 *c = S318(T, 4);
      S31C(b, c, 4);
      u8 *d = S318(T, 4);
      u8 *e = S318(T, 3);
      S31C(d, e, 3);
    }
  }
  (*(v1_t **)T)[0xbc / 4](T, flag == 0);
}
PCREG(573000, fn573000);
