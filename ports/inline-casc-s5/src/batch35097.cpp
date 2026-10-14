// batch35097.cpp - cascade s5 batch 35097: 0x4a03b0 (GUESS enable or disable every child whose name matches).
#include "ff.h"

typedef int (*stricmp_t)(const char *, const char *);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4a03b0, thiscall(name, on) ret 8 (only the low byte of `on` is tested). The unaligned dword slot at this+0x102 holds the pointer to a child array {count, child pointers...}. When it is zero it is filled by
// [this+0x44] slot 0x128(word [0x7002ac], &slot, [this+0x44]) and, when still zero, with this + 0x7e (and byte +0x5e = 1). For each child e of the array (count re-read): when name is non-null and not empty, it only
// counts when _stricmp(name, [e+0x76]) (IAT 0x676414, [e+0x76] an unaligned string pointer) is 0. A counted child gets bit 4 of [e+0x5a] cleared (on) or set (off).
static void THISCALL fn4a03b0(u8 *self, const char *name, u32 on) {
  u8 *slot = self + 0x102;
  if (rd32u(slot) == 0) {
    u8 *o = *(u8 **)(self + 0x44);
    u32 w = *(u16 *)0x7002ac;
    typedef void(THISCALL * f3_t)(void *, u32, u8 *, void *);
    (*(f3_t **)o)[0x128 / 4](o, w, slot, o);
    if (rd32u(slot) == 0) {
      self[0x5e] = 1;
      wr32u(slot, (u32)(self + 0x7e));
    }
  }
  u8 *arr = (u8 *)rd32u(slot);
  u32 i = 0;
  if (*(u32 *)arr == i) return;
  do {
    u8 *e = *(u8 **)(arr + i * 4 + 4);
    bool count = true;
    if (name && name[0]) count = G(stricmp_t, 0x676414)(name, (const char *)rd32u(e + 0x76)) == 0;
    if (count) {
      if ((u8)on) *(u32 *)(e + 0x5a) &= 0xfffffffb;
      else *(u32 *)(e + 0x5a) |= 4;
    }
    i++;
  } while (i != *(u32 *)arr);
}
PCREG(4a03b0, fn4a03b0);
