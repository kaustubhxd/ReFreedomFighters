// batch34136.cpp - cascade tier E, batch 34136: 0x513090 (prune and pick from a child list), 0x513c80 (create an object and announce it).
#include "ff.h"

extern "C" u32 THISCALL ext_513340(void *self, u32 child);                                     // ret 4, low byte = remove
extern "C" u32 THISCALL ext_43ec00(void *self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);   // ret 0x18
extern "C" void THISCALL ext_44b8b0(void *self, u32 a);                                         // ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x513090, thiscall plain: walks the unaligned child array at this+0xde (count: unaligned dword at +0xda, end re-read each step). Per child c: when ext_513340(this, c) low byte is set the child is removed
// (when not at the end: slot = last element, count--; the cursor stays); otherwise the first child becomes the pick, and later ones replace it when c->slot0x1e0(0x80200014) low byte is set; the cursor advances.
// Finally [[0x70039c]+0x9b]->slot0x4c(pick).
static void THISCALL fn513090(u8 *self) {
  u32 pick = 0;
  u8 *s = self + 0xde;
  while (s != self + 0xde + 4 * rd32(self + 0xda)) {
    u32 c = rd32(s);
    if ((u8)ext_513340(self, c)) {
      u32 n = rd32(self + 0xda);
      u8 *end = self + 4 * n + 0xde;
      if (s != end) {
        wr32(s, rd32(self + 4 * n + 0xda));
        wr32(self + 0xda, n - 1);
      }
      continue;
    }
    if (!pick || (u8)vcall<u32>((void *)rd32(s), 0x1e0, 0x80200014u)) pick = rd32(s);
    s += 4;
  }
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vcall<void>(t, 0x4c, pick);
}
PCREG(513090, fn513090);

// 0x513c80, thiscall(a) ret 4: s = ext_43ec00(this, [this+8], [this+8]+0x30, a, 0, 0, 0); b = [[0x70039c]+0x9b]->slot0x60(s); when b: g = [[0x70039c]+0x9b]->slot0x4c(this); ext_44b8b0(b, g);
// [b+0x40] &= ~4; when [b+0x40] & 8 and the object at unaligned [this+0x1ed] has slot0x14() < 7 (signed) its slot 0x4(s) runs. Returns s.
static u32 THISCALL fn513c80(u8 *self, u32 a) {
  u8 *d = *(u8 **)(self + 8);
  u32 s = ext_43ec00(self, (u32)d, (u32)d + 0x30, a, 0, 0, 0);
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *b = vcall<u8 *>(t, 0x60, s);
  if (b) {
    t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 g = vcall<u32>(t, 0x4c, (u32)self);
    ext_44b8b0(b, g);
    *(u32 *)(b + 0x40) &= 0xfffffffb;
    if (*(u32 *)(b + 0x40) & 8) {
      u8 *o = (u8 *)rd32(self + 0x1ed);
      if ((int)vcall<u32>(o, 0x14) < 7) vcall<void>((u8 *)rd32(self + 0x1ed), 0x4, s);
    }
  }
  return s;
}
PCREG(513c80, fn513c80);
