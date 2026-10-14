// batch34020.cpp - cascade tier E, batch 34020: 0x639d80 (set an optional owned copy of a float/dword array), 0x654c10 (forward a key event or clear
// key-state bits), 0x455020 (rebuild a list from a stream), 0x456e60 (find or insert a key in a 256-slot table), 0x48f9a0 (lay out a 3-column grid).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);                    // cdecl free(ptr, size)
extern "C" u32 ext_41e290(u32 size);                           // cdecl alloc
extern "C" void ext_634d22(void *dst, const void *src, u32 n); // cdecl memcpy
extern "C" void THISCALL ext_440e10(void *self, void *s);      // thiscall ret 4
typedef u32 (*hook_t)();

// 0x639d80, thiscall(src, n, copy) ret 0xc: release an owned buffer (+0x2d, flag byte +0x31); store n at +0x32 (unaligned); when copy: own a fresh
// copy of n dwords (allocation size saturates at 0xffffffff), flag = 1; else just point +0x2d at src.
static void THISCALL fn639d80(u8 *self, u8 *src, u32 n, u8 copy) {
  u8 *p;
  if (self[0x31]) {
    p = *(u8 **)(self + 0x2d);
    ext_634273(p, 4);
    *(u32 *)(self + 0x2d) = 0;
    self[0x31] = 0;
  }
  u8 *q = self + 0x32;
  q[0] = n; q[1] = n >> 8; q[2] = n >> 16; q[3] = n >> 24;
  if (copy) {
    u64 m = (u64)n * 4;
    u32 size = (m >> 32) ? 0xffffffffu : (u32)m;
    u8 *buf = (u8 *)ext_41e290(size);
    u32 cnt = q[0] | q[1] << 8 | q[2] << 16 | (u32)q[3] << 24;
    *(u8 **)(self + 0x2d) = buf;
    ext_634d22(buf, src, cnt << 2);
    self[0x31] = 1;
  } else {
    *(u8 **)(self + 0x2d) = src;
  }
}
PCREG(639d80, fn639d80);

// 0x654c10, stdcall(a, b) ret 8: s = engine->slot0x1b0(); when s && s->slot0xc(): return s->slot0x14(a, b). Otherwise for a < 0x100 (signed):
// engine byte [a*5 + 0xa0b] &= 0x7f, and (when engine byte +0x6e is zero) engine byte [((b >> 16) & 0x1ff)*5 + 0xf0b] &= 0x7f.
static u32 STDCALL fn654c10(s32 a, s32 b) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *s = vcall<u8 *>(eng, 0x1b0);
  if (s && vcall<bool>(s, 0xc)) return vcall<u32>(s, 0x14, (u32)a, (u32)b);
  if (a < 0x100) {
    u32 idx = (u8)a;
    u32 hi = ((u32)(b >> 16)) & 0x1ff;
    eng = G(u8 *, 0x70039c);
    eng[idx * 5 + 0xa0b] &= 0x7f;
    eng = G(u8 *, 0x70039c);
    if (eng[0x6e] == 0) eng[hi * 5 + 0xf0b] &= 0x7f;
  }
  return 0;
}
PCREG(654c10, fn654c10);

// 0x455020, thiscall(s) ret 4: 0x440e10(this, s); s->slot0x48(&count); for count (signed) times: s->slot0x40(&id), obj = engine table slot 0x58(id),
// [this+0x5c]->slot4(obj); returns true.
static bool THISCALL fn455020(u8 *self, u8 *s) {
  ext_440e10(self, s);
  s32 count;
  vcall<void>(s, 0x48, (u32)&count);
  for (s32 i = 0; i < count; i++) {
    u32 id;
    vcall<void>(s, 0x40, (u32)&id);
    u8 *eng = G(u8 *, 0x70039c);
    u32 obj = vcall<u32>(*(u8 **)(eng + 0x9b), 0x58, id);
    vcall<void>(*(u8 **)(self + 0x5c), 4, obj);
  }
  return true;
}
PCREG(455020, fn455020);

// 0x456e60, thiscall(x) ret 4: table of 256 8-byte entries at this+0x1d (key = first dword): return index+1 of the entry equal to x, else claim the first
// empty one (store x, return index+1); a full table logs through the object at 0x700390 (slot 0x20(0x682d18, 0x1f8)->slot 0x2c(.., 0x682e50)), the assert hook, returns 0.
static u32 THISCALL fn456e60(u8 *self, u32 x) {
  u32 i = 0;
  u8 *e = self + 0x1d;
  for (;;) {
    u32 k = *(u32 *)e;
    if (k == 0) {
      *(u32 *)(self + i * 8 + 0x1d) = x;
      return i + 1;
    }
    i++;
    if (k == x) return i;
    e += 8;
    if (i >= 0x100) break;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x682d18u, 0x1f8u);
  {
    // slot 0x2c is a caller-cleans stub: called thiscall with two stack args, the caller pops them
    u32 slot = (*(u32 **)r)[0x2c / 4];
    u32 a1 = (u32)r, a2 = 0x682e50;
    asm volatile("push %[a2]\n\tpush %[a1]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(*(u32 *)r), [a1] "r"(a1), [a2] "r"(a2), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(456e60, fn456e60);

// 0x48f9a0, thiscall, no args: for i in 0 .. [this+4]-1: o = engine->slot0x190(); call o's slot 0x184 with ECX = i % 3 and four caller-cleaned
// stack arguments (o, (i % 3) * 0x2d, i / 3 + 5, 0x679e6c).
static void THISCALL fn48f9a0(u8 *self) {
  if (*(u32 *)(self + 4) == 0) return;
  u32 i = 0;
  do {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *o = vcall<u8 *>(eng, 0x190);
    u32 q = i / 3;
    u32 a1 = (i - q * 3) * 0x2d, a2 = q + 5;
    u32 slot = (*(u32 **)o)[0x184 / 4];
    asm volatile("push $0x679e6c\n\tpush %[a2]\n\tpush %[a1]\n\tpush %[o]\n\tcall *%[fn]\n\tadd $16, %%esp" : : "c"(i - q * 3), [o] "r"(o), [a1] "r"(a1), [a2] "r"(a2), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    i++;
  } while (i != *(u32 *)(self + 4));
}
PCREG(48f9a0, fn48f9a0);
