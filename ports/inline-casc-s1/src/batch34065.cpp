// batch34065.cpp - cascade tier E, batch 34065: 0x4f4220 (read a record from a stream and flip a flag), 0x530fd0 (allocate and initialise a table of 0x15-byte entries), 0x533110 (re-issue a stored
// string with two fields saved and restored).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);                  // cdecl alloc
extern "C" void FASTCALL ext_633654(u32 cookie);      // /GS check

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4f4220, thiscall(s) ret 4: s slot 0x40 into this+0x2e and this+0x32; three values from s slot 0x30() into +0x2a, +0x36 and +0x3a (all unaligned); old = [this+0x18]; [this+0x18] = old ^ 1;
// this slot 0x248(old); this slot 0x23c([this+0x1c], byte [this+0x8e]); byte [this+0x90] = 1.
static void THISCALL fn4f4220(u8 *self, u8 *s) {
  vcall<void>(s, 0x40, (u32)(self + 0x2e));
  vcall<void>(s, 0x40, (u32)(self + 0x32));
  wr32u(self + 0x2a, vcall<u32>(s, 0x30));
  wr32u(self + 0x36, vcall<u32>(s, 0x30));
  wr32u(self + 0x3a, vcall<u32>(s, 0x30));
  u32 old = *(u32 *)(self + 0x18);
  *(u32 *)(self + 0x18) = old ^ 1;
  vcall<void>(self, 0x248, old);
  vcall<void>(self, 0x23c, *(u32 *)(self + 0x1c), (u32)self[0x8e]);
  self[0x90] = 1;
}
PCREG(4f4220, fn4f4220);

// 0x530fd0, thiscall(n) ret 4: a value above 0xffff (signed compare) logs through the object at 0x700390 (slot 0x20(0x6a1438, 0x12b), then its slot 0x2c with (r, 0x6a146c), caller-popped) and becomes
// 0xffff; word [this+0x50] = n; p = alloc(n * 0x15) stored at [this+0x98]; each of the n entries: word +0 = 0, dword +0xa = 100000.0f, word +0xe = 0, dword +0x10 = 0, byte +0x14 = 0.
static void THISCALL fn530fd0(u8 *self, s32 n) {
  if (n > 0xffff) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x6a1438u, 0x12bu);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x6a146c\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    n = 0xffff;
  }
  u16 cnt = (u16)n;
  *(u16 *)(self + 0x50) = cnt;
  u8 *p = (u8 *)ext_41e290((u32)cnt * 0x15);
  *(u8 **)(self + 0x98) = p;
  u32 c = *(u16 *)(self + 0x50);
  for (u32 i = 0; i < c; i++) {
    u8 *e = p + i * 0x15;
    e[0] = 0;
    e[1] = 0;
    wr32u(e + 0xa, 0x47c35000);
    e[0xe] = 0;
    e[0xf] = 0;
    wr32u(e + 0x10, 0);
    e[0x14] = 0;
  }
}
PCREG(530fd0, fn530fd0);

// 0x533110, thiscall, no args: o = [this+0x548a] (unaligned); saves and clears the unaligned dwords [o+0x8031] and [o+0xa269]; copies the string at [o+0x802d] into a 0x104-byte local; this slot 0x1f8();
// restores both dwords; o->slot0x68(0, local string); the /GS check.
static void THISCALL fn533110(u8 *self) {
  char buf[0x104];
  u8 *o = (u8 *)rd32u(self + 0x548a);
  u32 a = rd32u(o + 0x8031);
  wr32u(o + 0x8031, 0);
  o = (u8 *)rd32u(self + 0x548a);
  u32 b = rd32u(o + 0xa269);
  wr32u(o + 0xa269, 0);
  o = (u8 *)rd32u(self + 0x548a);
  const char *src = (const char *)rd32u(o + 0x802d);
  char *d = buf;
  char ch;
  do {
    ch = *src++;
    *d++ = ch;
  } while (ch);
  vcall<void>(self, 0x1f8);
  o = (u8 *)rd32u(self + 0x548a);
  wr32u(o + 0x8031, a);
  o = (u8 *)rd32u(self + 0x548a);
  wr32u(o + 0xa269, b);
  o = (u8 *)rd32u(self + 0x548a);
  vcall<void>(o, 0x68, 0u, (u32)buf);
  ext_633654(0);
}
PCREG(533110, fn533110);
