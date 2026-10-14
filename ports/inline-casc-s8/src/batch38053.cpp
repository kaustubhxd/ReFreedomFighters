// batch38053.cpp - cascade s8 batch 38053: 0x56f860 (key / command dispatch of a text-input control).
#include "ff.h"

extern "C" void THISCALL ext_562c20(u8 *self, u32 key);        // ret 4
extern "C" void THISCALL ext_56fc20(u8 *self);
extern "C" void THISCALL ext_56ef50(u8 *self, u32 arg);        // ret 4 (value, or pointer to a word for key 0x32)
extern "C" void THISCALL ext_56f7c0(u8 *self);
extern "C" void THISCALL ext_563500(u8 *self);
extern "C" u32 THISCALL ext_561be0(u8 *self);
extern "C" void THISCALL ext_59cb60(u8 *obj, const char *s);   // ret 4
extern "C" u32 THISCALL ext_48aad0(u32 *loc);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

// 0x56f860, thiscall(key) ret 4, returns bool (false when slot 0xd8 says the control is busy). Dispatch: 0x31 -> 0x56fc20; 0x32 -> 0x56ef50 with a pointer to the word 0x20; 0x7d0 -> slot 0x9c(0x103);
// 0xfa0 -> nothing; 0x2b67 -> 0x562c20(0x2b67); 0x3e8 -> the text object this[0x5e2] slot 0x35c is copied (31 characters at most) to this+0x1c9 and, when not empty, 0x56f7c0 runs, 0x59cb60 gets
// the string at this+0x1e9 (or the constant 0x6a8500 when it equals the one at 0x6a7808), then 0x563500 / 0x561be0 and slot 0xd0 with this[0x1c1] (or a value from the text helper 0x48aad0); any other
// key passes this[0x2ee + 4 * key] to 0x56ef50. 0x562c20(key) runs first for every key.
static bool THISCALL fn56f860(u8 *self, u32 key) {
  if ((u8)SLOT(self, 0xd8, v0_t)(self)) return false;
  ext_562c20(self, key);
  if (key > 0x7d0) {
    if (key == 0xfa0) return true;
    if (key == 0x2b67) {
      ext_562c20(self, 0x2b67);
      return true;
    }
    ext_56ef50(self, *(u32 *)(self + key * 4 + 0x2ee));
    return true;
  }
  if (key == 0x7d0) {
    SLOT(self, 0x9c, v1_t)(self, 0x103);
    return true;
  }
  if (key == 0x31) {
    ext_56fc20(self);
    return true;
  }
  if (key == 0x32) {
    u32 loc = (key & 0xffff0000) | 0x20;
    ext_56ef50(self, (u32)&loc);
    return true;
  }
  if (key == 0x3e8) {
    u8 *txt = *(u8 **)(self + 0x5e2);
    const char *p = (const char *)SLOT(txt, 0x35c, v0_t)(txt);
    u8 *buf = self + 0x1c9;
    u32 len = 0;
    while (p[len]) len++;
    if (len < 0x20) {
      const char *q = p;
      u8 *d = buf;
      u8 ch;
      do {
        ch = (u8)*q++;
        *d++ = ch;
      } while (ch);
    } else {
      for (int i = 0; i < 0x1f; i++) buf[i] = (u8)p[i];
    }
    self[0x1e8] = 0;
    u32 blen = 0;
    while (buf[blen]) blen++;
    if (blen == 0) return true;
    ext_56f7c0(self);
    const u8 *a = self + 0x1e9;
    const u8 *b = (const u8 *)0x6a7808;
    bool eq = true;
    for (u32 i = 0;; i++) {
      if (a[i] != b[i]) {
        eq = false;
        break;
      }
      if (a[i] == 0) break;
    }
    ext_59cb60(*(u8 **)(self + 0x94), eq ? (const char *)0x6a8500 : (const char *)a);
    ext_563500(self);
    if ((u8)ext_561be0(self)) {
      SLOT(self, 0xd0, v1_t)(self, *(u32 *)(self + 0x1c1));
      return true;
    }
    u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 x = SLOT(t, 0x138, v0_t)(t);
    u32 loc[2] = {x, 0x6a7b5c};
    u32 r = ext_48aad0(loc);
    SLOT(self, 0xd0, v1_t)(self, r);
    return true;
  }
  ext_56ef50(self, *(u32 *)(self + key * 4 + 0x2ee));
  return true;
}
PCREG(56f860, fn56f860);
