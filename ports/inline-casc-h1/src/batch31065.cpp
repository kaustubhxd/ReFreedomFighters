// batch31065.cpp - Sonnet h1: byte flush, swap-remove, tag matcher, message handler, bit scan, copy+tail, list remove, string hash.
#include "ff.h"

extern "C" void ext_45d5b0(void);

// 0x454d30 thiscall ret 4 (arg: source object): if [[arg+0xc]+0x23] == 0x2000f0 copy 12 fields from arg to this, then tail-call 0x45d5b0.
asm(
    ".text\n"
    ".globl thunk454d30\nthunk454d30:\n"
    "  movl 4(%esp), %edx\n  movl 0xc(%edx), %eax\n  cmpl $0x2000f0, 0x23(%eax)\n  jne 1f\n"
    "  .irp off,0x18,0x1c,0x20,0x34,0x28,0x30,0x2c,0x24,0x3c,0x40,0x44,0x48\n"
    "  movl \\off(%edx), %eax\n  movl %eax, \\off(%ecx)\n"
    "  .endr\n"
    "1:\n  jmp ext_45d5b0\n");
extern "C" void thunk454d30(void);
PCREG(454d30, thunk454d30);

// 0x6301a0 cdecl (s): flush up to two pending bytes at s+0x16b0 (count dword at +0x16b4) to the buffer at s+8 / position s+0x14.
extern "C" u32 fn6301a0(u8 *s) {
  int n = *(int *)(s + 0x16b4);
  u8 *buf = *(u8 **)(s + 8);
  if (n > 8) {
    buf[*(u32 *)(s + 0x14)] = s[0x16b0];
    (*(u32 *)(s + 0x14))++;
    buf[*(u32 *)(s + 0x14)] = s[0x16b1];
    (*(u32 *)(s + 0x14))++;
  } else if (n > 0) {
    buf[*(u32 *)(s + 0x14)] = s[0x16b0];
    (*(u32 *)(s + 0x14))++;
  }
  *(u16 *)(s + 0x16b0) = 0;
  *(u32 *)(s + 0x16b4) = 0;
  return 0;
}
PCREG(6301a0, fn6301a0);

// 0x5af260 thiscall ret 4: swap-remove v from the dword list (count at this[0], elements from this+4); no-op for v == 0.
THISCALL void fn5af260(u32 *self, u32 v) {
  if (!v) return;
  u32 n = self[0];
  for (u32 i = 0; i < n; i++) {
    if (self[1 + i] == v) {
      self[0] = n - 1;
      self[1 + i] = self[1 + (n - 1)];
      return;
    }
  }
}
PCREG(5af260, fn5af260);

// 0x58a360 thiscall ret 4, bool: swap-remove v from the same kind of list, returns whether it was found.
THISCALL u8 fn58a360(u32 *self, u32 v) {
  u32 n = self[0];
  for (u32 i = 0; i < n; i++) {
    if (self[1 + i] == v) {
      self[1 + i] = self[n];   // last element is at this + 4*n
      self[0] = n - 1;
      return 1;
    }
  }
  return 0;
}
PCREG(58a360, fn58a360);

// 0x629480 cdecl (unused, start, end, out): like 0x62ad10 but the 6-byte tag at 0x6bfe60 is matched as wide chars (byte, 0).
extern "C" int fn629480(u32, u8 *start, u8 *end, u8 **out) {
  if (end - start < 12) return -1;
  int i = 0;
  do {
    if (start[1] != 0 || start[0] != *(u8 *)(0x6bfe60 + i)) { *out = start; return 0; }
    i++; start += 2;
  } while (i < 6);
  *out = start;
  return 8;
}
PCREG(629480, fn629480);

// 0x62cce0 cdecl (obj, code) message handler.
extern "C" int fn62cce0(u32 *obj, int code) {
  if (code == 0xf) return 0;
  if (code == 0x15) { obj[0] = 0x62cc90; return 0; }
  if (code == 0x18) { obj[0] = 0x62cd30; return 0; }
  if (obj[3] == 0 && code == 0x1c) return 0x34;
  obj[0] = 0x51f230;
  return -1;
}
PCREG(62cce0, fn62cce0);

// 0x4d06a0 stdcall ret 4 (p): for each of 4 dwords p[i]: p[4+i] = trailing zero count, p[8+i] = 8 - bit length of the value shifted down.
STDCALL void fn4d06a0(u32 *p) {
  for (int i = 0; i < 4; i++) {
    u32 v = p[i];
    p[4 + i] = 0;
    p[8 + i] = 8;
    if (!v) continue;
    while (!(v & 1)) { p[4 + i]++; v >>= 1; }
    u32 e = 8;
    do { e--; v >>= 1; } while (v);
    p[8 + i] = e;
  }
}
PCREG(4d06a0, fn4d06a0);

// 0x4e6880 fastcall ret 4 (self -> char*, out1, out2): two rotate-xor hashes over the C string.
FASTCALL void fn4e6880(u8 **self, u32 *out1, u32 *out2) {
  const char *s = (const char *)*self;
  u32 len = 0;
  while (s[len]) len++;
  *out2 = 0;
  *out1 = 0;
  for (u32 i = 0; i < len; i++) {
    u32 c = (u32)(int)(signed char)s[i];
    u32 x = c ^ *out1;
    *out1 = (x << 8) | (x >> 24);
    u32 y = c ^ *out2;
    *out2 = (y << 9) | (y >> 23);
  }
}
PCREG(4e6880, fn4e6880);
