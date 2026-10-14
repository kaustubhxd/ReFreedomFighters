// batch34086.cpp - escalation batch 34086: 0x53aa10 (circular list search), 0x65a540 (MMX multiply-add), 0x651db0 (engine state sync), 0x54a170 (field copy), 0x5b1250 (name lookup).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x53aa10, thiscall(start, want) ret 8: start defaults to the unaligned head [this+0xe]; 0 when there is none. Walks the circular list through +0xc (a null link wraps to the head) and returns the first node whose class
// ([[[node+4]+8]+0x3c]: no 0x800 and 0x1000 set) equals the low byte of want != 0; 0 when it comes back to the start.
static u32 THISCALL fn53aa10(u8 *self, u8 *start, u32 want) {
  u8 *a = start;
  if (!a) a = (u8 *)rd32(self + 0xe);
  if (!a) return 0;
  u8 *cur = a;
  u8 bl = want;
  for (;;) {
    cur = *(u8 **)(cur + 0xc);
    if (!cur) cur = (u8 *)rd32(self + 0xe);
    u32 f = *(u32 *)(*(u8 **)(*(u8 **)(cur + 4) + 8) + 0x3c);
    u8 dl = 0;
    if (!(f & 0x800) && (f & 0x1000)) dl = 1;
    if (bl ? dl : !dl) return (u32)cur;
    if (cur == a) return 0;
  }
}
PCREG(53aa10, fn53aa10);

// 0x65a540, register ABI (ecx = dst, edx = src) plus stack (mul, n) ret 8: for (n + 3) >> 2 rounds: four qwords of 16-bit lanes: dst += (pmulhw(*mul lane, src lane) << 4) lane-wise (wrapping), src and dst advance by 0x20.
static void FASTCALL fn65a540(u16 *dst, u16 *src, u16 *mul, u32 n) {
  u32 count = (n + 3) >> 2;
  do {
    for (int j = 0; j < 4; j++)
      for (int l = 0; l < 4; l++) {
        s32 prod = (s32)(s16)mul[l] * (s32)(s16)src[j * 4 + l];
        u16 hi = (u16)(prod >> 16);
        u16 v = (u16)(hi << 4);
        dst[j * 4 + l] = (u16)(dst[j * 4 + l] + v);
      }
    dst += 16;
    src += 16;
    count--;
  } while (count != 0);
}
PCREG(65a540, fn65a540);

// 0x651db0, stdcall(a) ret 4: mirrors a[0], a[1], a[2] and (a[3] != 0) into the engine object's state: for each pair (engine +0x6f/+0x73/+0x7f vs a) a changed value goes to +0x77/+0x7b/+0x83 and sets byte +0x1a97 = 1, an
// unchanged one copies the engine value; byte +0x63 vs (a[3] != 0) goes to +0x1e8f the same way (all unaligned).
static void STDCALL fn651db0(u32 *a) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 old = rd32(sys + 0x6f);
  u32 v = a[0];
  if (old != v) { wr32(sys + 0x77, v); G(u8 *, 0x70039c)[0x1a97] = 1; } else wr32(sys + 0x77, old);
  sys = G(u8 *, 0x70039c);
  old = rd32(sys + 0x73);
  v = a[1];
  if (old != v) { wr32(sys + 0x7b, v); G(u8 *, 0x70039c)[0x1a97] = 1; } else wr32(sys + 0x7b, old);
  sys = G(u8 *, 0x70039c);
  old = rd32(sys + 0x7f);
  v = a[2];
  if (old != v) { wr32(sys + 0x83, v); G(u8 *, 0x70039c)[0x1a97] = 1; } else wr32(sys + 0x83, old);
  u8 z = a[3] != 0;
  sys = G(u8 *, 0x70039c);
  u8 cl = sys[0x63];
  if (cl != z) { sys[0x1e8f] = z; G(u8 *, 0x70039c)[0x1a97] = 1; } else sys[0x1e8f] = cl;
}
PCREG(651db0, fn651db0);

// 0x54a170, stdcall(dst, src) ret 8, returns the last dword read ([src+0x6c]): copies src dwords 0..0x28, 0x38, 0x3c, 0x4c..0x6c to dst at 8..0x30, 0x34, 0x38, 0x3c..0x5c.
static u32 STDCALL fn54a170(u32 *dst, u32 *src) {
  static const u8 to[] = {0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c};
  static const u8 from[] = {0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x38, 0x3c, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c};
  u32 v = 0;
  for (unsigned i = 0; i < sizeof to; i++) {
    v = *(u32 *)((u8 *)src + from[i]);
    *(u32 *)((u8 *)dst + to[i]) = v;
  }
  return v;
}
PCREG(54a170, fn54a170);

// 0x5b1250, thiscall(key) ret 4: n = [this+0x5b8] (signed); the first i < n whose name pointer [this+8+4i] equals the string key gets dword [this+0x5c0+4i] = 4.
static void THISCALL fn5b1250(u8 *self, const u8 *key) {
  s32 n = *(s32 *)(self + 0x5b8);
  for (s32 i = 0; i < n; i++) {
    const u8 *a = key;
    const u8 *b = *(const u8 **)(self + 8 + 4 * i);
    while (*a == *b && *a) { a++; b++; }
    if (*a == *b) {
      *(u32 *)(self + i * 4 + 0x5c0) = 4;
      return;
    }
  }
}
PCREG(5b1250, fn5b1250);
