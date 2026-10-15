// batch32076.cpp - cascade h2 (Sonnet): 0x42f6e0 (append a token to a growing buffer), 0x5367c0 (find the first table entry the matcher accepts).
#include "ff.h"

extern "C" void THISCALL ext_5f2d60(u8 *self, u32 a, u32 b);      // thiscall ret 8
extern "C" void THISCALL ext_431270(u8 *self, u32 cap);           // thiscall ret 4
extern "C" u32 FASTCALL ext_4cc850(u8 *ecx, const u8 *edx);       // fastcall-style (ecx, edx), plain ret

// 0x42f6e0, stdcall(buf, pp, end) ret 0xc: 0x5f2d60(buf, 0x677b5a, 0x677b5a); while *pp != end: ch = **pp, stop at space, tab, CR, LF or '$';
// when [buf+4]+1 == [buf+8] grow via 0x431270(buf, cap) with cap = d + (max(d,1) - [buf]) where d = [buf+4]-[buf] (computed exactly as the exe);
// byte [[buf+4]+1] = 0; *[buf+4] = ch; [buf+4]++; (*pp)++.
static void STDCALL fn42f6e0(u8 *buf, u8 **pp, u8 *end) {
  ext_5f2d60(buf, 0x677b5a, 0x677b5a);
  if (*pp == end) return;
  while (true) {
    u8 ch = **pp;
    if (ch == 0x20 || ch == 9 || ch == 0xd || ch == 0xa || ch == 0x24) return;
    u32 edx = *(u32 *)(buf + 4);
    if (edx + 1 == *(u32 *)(buf + 8)) {
      u32 base = *(u32 *)buf;
      u32 ecx = edx - base;
      if (ecx < 1) ecx = 1;
      ext_431270(buf, ecx - base + edx);
    }
    u8 *p = *(u8 **)(buf + 4);
    p[1] = 0;
    **(u8 **)(buf + 4) = ch;
    *(u32 *)(buf + 4) += 1;
    *pp += 1;
    if (*pp == end) return;
  }
}
PCREG(42f6e0, fn42f6e0);

// 0x5367c0, thiscall(base, count, str) ret 0xc: off = u32 at this+0x5302 (unaligned); off == 0 or str empty/null -> 0; arr = base + off;
// for i < count: 0x4cc850(ecx = [arr[i] + off + 4] + off, edx = str) == 0 -> return arr[i]; none -> 0.
static u32 THISCALL fn5367c0(u8 *self, u32 base, u32 count, const u8 *str) {
  u8 *f = self + 0x5302;
  u32 off = f[0] | (f[1] << 8) | (f[2] << 16) | ((u32)f[3] << 24);
  if (!off) return 0;
  if (!str || !*str) return 0;
  u32 *arr = (u32 *)(base + off);
  for (u32 i = 0; i < count; i++) {
    u32 o2 = f[0] | (f[1] << 8) | (f[2] << 16) | ((u32)f[3] << 24);
    u32 e = arr[i];
    u32 v = *(u32 *)(e + o2 + 4);
    if (ext_4cc850((u8 *)(v + o2), str) == 0) return arr[i];
  }
  return 0;
}
PCREG(5367c0, fn5367c0);
