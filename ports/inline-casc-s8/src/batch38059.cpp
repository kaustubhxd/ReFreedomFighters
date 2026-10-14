// batch38059.cpp - cascade s8 batch 38059: 0x571cc0 (load / save the three volume settings).
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define ENG G(u8 *, 0x70039c)

static u8 *helper() {
  u8 *t = *(u8 **)(ENG + 0x9b);
  return (u8 *)SLOT(t, 0x134, v0_t)(t);
}
static u32 read_setting(u32 name) {
  u8 *h = helper();
  u32 l = 0;
  SLOT(h, 0x88, v2_t)(h, name, (u32)&l);
  return l;
}

// 0x571cc0, cdecl, no args. Asks the settings helper (table slot 0x134, slot 0x88(name, &out)) whether the key 0x6a891c is stored. When it is, the three values 0x6a8930 / 0x6a8938 / 0x6a8940 are
// read and applied to the settings object (engine slot 0xbc) through its setters 0x88 / 0x90 / 0x80 (a value above 100 is replaced by 75 / 80 / 100). When it is not, the current values of that object
// (getters 0x84 / 0x8c / 0x7c) are range checked (outside 0..100 -> the same defaults) and written back through helper slot 0x5c(name, value, 2), followed by the marker 0x6a891c = 1.
static void fn571cc0() {
  u32 flag = read_setting(0x6a891c);
  u8 *s = (u8 *)SLOT(ENG, 0xbc, v0_t)(ENG);
  if (flag != 0) {
    u32 a = read_setting(0x6a8930);
    SLOT(s, 0x88, v1_t)(s, a > 0x64 ? 0x4b : a);
    u32 b = read_setting(0x6a8938);
    SLOT(s, 0x90, v1_t)(s, b > 0x64 ? 0x50 : b);
    u32 c = read_setting(0x6a8940);
    SLOT(s, 0x80, v1_t)(s, c > 0x64 ? 0x64 : c);
    return;
  }
  s32 v = (s32)SLOT(s, 0x84, v0_t)(s);
  if (v < 0 || v > 0x64) SLOT(s, 0x88, v1_t)(s, 0x4b);
  v = (s32)SLOT(s, 0x8c, v0_t)(s);
  if (v < 0 || v > 0x64) SLOT(s, 0x90, v1_t)(s, 0x50);
  v = (s32)SLOT(s, 0x7c, v0_t)(s);
  if (v < 0 || v > 0x64) SLOT(s, 0x80, v1_t)(s, 0x64);
  u8 *h = helper();
  u32 g = SLOT(s, 0x84, v0_t)(s);
  SLOT(h, 0x5c, v3_t)(h, 0x6a8930, g, 2);
  h = helper();
  g = SLOT(s, 0x8c, v0_t)(s);
  SLOT(h, 0x5c, v3_t)(h, 0x6a8938, g, 2);
  h = helper();
  g = SLOT(s, 0x7c, v0_t)(s);
  SLOT(h, 0x5c, v3_t)(h, 0x6a8940, g, 2);
  h = helper();
  SLOT(h, 0x5c, v3_t)(h, 0x6a891c, 1, 2);
}
PCREG(571cc0, fn571cc0);
