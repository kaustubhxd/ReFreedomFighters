// batch34087.cpp - escalation batch 34087: 0x63a2e0 (min/max of 4-dword vectors), 0x4d2c00 (longest table prefix match), 0x44bcf0 (field copy), 0x56a080 / 0x576320 (call then tail thunks).
#include "ff.h"

extern "C" void thunk56a080(void);
extern "C" void thunk576320(void);
asm(
    ".text\n"
    ".globl thunk56a080\n"
    "thunk56a080:\n"          // ext_562440(this), then tail jump to 0x56a140 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_562440\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_56a140\n"
    ".globl thunk576320\n"
    "thunk576320:\n"          // ext_573db0(this), then tail jump to 0x576330 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  call ext_573db0\n"
    "  mov %esi, %ecx\n"
    "  pop %esi\n"
    "  jmp ext_576330\n");
PCREG(56a080, thunk56a080);
PCREG(576320, thunk576320);

// 0x63a2e0, register ABI (ecx = n, edx = data) plus stack (mn, mx) ret 8: mn[0..3] = 0xff, mx[0..3] = 0; for each component k of the n 16-byte vectors at data: mn[k] = min, mx[k] = max (signed).
static void FASTCALL fn63a2e0(s32 n, s32 *data, s32 *mn, s32 *mx) {
  mn[0] = 0xff; mn[1] = 0xff; mn[2] = 0xff; mn[3] = 0xff;
  mx[0] = 0; mx[1] = 0; mx[2] = 0; mx[3] = 0;
  for (int k = 0; k < 4; k++) {
    if (n <= 0) continue;
    s32 *p = data + k;
    for (s32 i = 0; i < n; i++, p += 4) {
      if (*p < mn[k]) mn[k] = *p;
      if (*p > mx[k]) mx[k] = *p;
    }
  }
}
PCREG(63a2e0, fn63a2e0);

// 0x4d2c00, stdcall(s) ret 4: table of 18 entries (20 bytes, base 0x6e7a30): dword +4 = length L, the prefix is compared reversed (s[i] against the byte at entry+3-i). Returns the entry with the longest
// non-zero fully matching prefix (the first such), or 0.
static u32 STDCALL fn4d2c00(const u8 *s) {
  if (!s) return 0;
  s32 best = 0, bestidx = -1;
  for (s32 e = 0; e < 18; e++) {
    u8 *base = (u8 *)(0x6e7a30 + 20 * e);
    s32 L = *(s32 *)(base + 4);
    s32 i = 0;
    if (L != 0) {
      const u8 *t = base + 3;
      do {
        if (s[i] != *t) break;
        i++;
        t--;
      } while (i != L);
    }
    if (i == L && best < i) {
      best = i;
      bestidx = e;
    }
  }
  if (bestidx == -1) return 0;
  return 0x6e7a30 + 20 * bestidx;
}
PCREG(4d2c00, fn4d2c00);

// 0x44bcf0, thiscall(src) ret 4, returns [src+0x38]: copies the dwords at 0x60 0x64 0x54 0x58 0x5c 0x44 0x48 0x4c 0x50 8 0xc (and 0x6c when this != src) 0x70 0x74 0x7c 0x80 0x88 0x84 0x40 0x2c 0x68 0x30 0x34 0x38 from src to this,
// then the unaligned dword [this+0xf9] = 0.
static u32 THISCALL fn44bcf0(u8 *self, u8 *src) {
  static const u8 offs[] = {0x60, 0x64, 0x54, 0x58, 0x5c, 0x44, 0x48, 0x4c, 0x50, 0x08, 0x0c};
  static const u8 offs2[] = {0x70, 0x74, 0x7c, 0x80, 0x88, 0x84, 0x40, 0x2c, 0x68, 0x30, 0x34, 0x38};
  u32 v = 0;
  for (unsigned i = 0; i < sizeof offs; i++) *(u32 *)(self + offs[i]) = *(u32 *)(src + offs[i]);
  if (self + 0x6c != src + 0x6c) *(u32 *)(self + 0x6c) = *(u32 *)(src + 0x6c);
  for (unsigned i = 0; i < sizeof offs2; i++) {
    v = *(u32 *)(src + offs2[i]);
    *(u32 *)(self + offs2[i]) = v;
  }
  self[0xf9] = 0; self[0xfa] = 0; self[0xfb] = 0; self[0xfc] = 0;
  return v;
}
PCREG(44bcf0, fn44bcf0);
