// batch35065.cpp - cascade s5 batch 35065: 0x64d360 (GUESS take references on the objects a node's resources point at).
#include "ff.h"

extern "C" void THISCALL ext_63da80(u32 self, u32 a);   // thiscall, ret 4
extern "C" u32 THISCALL ext_658f50(u32 self);           // plain ret, returns a count
extern "C" u8 *THISCALL ext_658f10(u32 self, u32 i);    // thiscall, ret 4

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x64d360, thiscall(a) ret 4. 0x63da80(L, a) with L = unaligned dword [this+0x1005d]. src = [a+8]; n = 0x658f50(src); for i < n: r = 0x658f10(src, i); when r is non-null: e = table([this+0x10071] unaligned)[word [r+0x40] & 0xfff];
// count [e+0xc]++; the first reference (old count 0): s = [e+8], byte [s+8]++ (when it was 0 also 0x63da80(L, s)), then 0x63da80(L, e).
static void THISCALL fn64d360(u8 *self, u32 a) {
  u32 L = rd32u(self + 0x1005d);
  ext_63da80(L, a);
  u32 src = *(u32 *)(a + 8);
  u32 n = ext_658f50(src);
  for (u32 i = 0; i != n && n != 0; i++) {
    u8 *r = ext_658f10(src, i);
    if (!r) continue;
    u32 idx = *(u16 *)(r + 0x40) & 0xfff;
    u8 *e = (u8 *)((u32 *)rd32u(self + 0x10071))[idx];
    u32 c = *(u32 *)(e + 0xc);
    *(u32 *)(e + 0xc) = c + 1;
    if (c == 0) {
      u8 *s = *(u8 **)(e + 8);
      u8 old = s[8];
      s[8] = old + 1;
      if (old == 0) ext_63da80(rd32u(self + 0x1005d), (u32)s);
      ext_63da80(rd32u(self + 0x1005d), (u32)e);
    }
  }
}
PCREG(64d360, fn64d360);
