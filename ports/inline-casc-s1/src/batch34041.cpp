// batch34041.cpp - cascade tier E, batch 34041: 0x54e6a0 (claim a free slot of a 0x6b-byte-entry pool), 0x552200 (resolve a value by entry kind and hand it
// to two helper objects), 0x562c20 (log a key and map two keys to commands).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 i);                    // thiscall ret 4: entry lookup
extern "C" u32 THISCALL ext_589c20(void *self, u32 a);                    // thiscall ret 4: table lookup by (signed) byte
extern "C" u32 THISCALL ext_59a580(void *self, u32 a, s32 b, u32 c);      // thiscall ret 0xc
extern "C" void THISCALL ext_562d90(void *self, u32 cmd);                 // thiscall ret 4
typedef u32 (*hook_t)();

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x54e6a0, thiscall(a, b, c, d) ret 0x10, returns the claimed entry's embedded object or 0: needs byte [this+0x1bc] and a pool of n = [this+0x1c5] (signed, unaligned) entries of 0x6b bytes
// starting at this (usage byte at +0x68 of each); takes the first entry whose usage byte is zero: its embedded object at +0x10 gets slot 4(), then +0x57 = +0x24 = d, +0x4f = b,
// +0x43 = +0x53 = c, byte +0x2c = 0, +0x4b = 0 and the usage byte = 1; returns the address of the embedded object.
static u32 THISCALL fn54e6a0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  (void)a;
  if (self[0x1bc] == 0) return 0;
  s32 n = (s32)rd32u(self + 0x1c5);
  if (n <= 0) return 0;
  s32 i = 0;
  u8 *e = self + 0x68;
  for (;;) {
    if (*e == 0) break;
    i++;
    e += 0x6b;
    if (!(i < n)) return 0;
  }
  u8 *base = self + (u32)i * 0x6b;
  vcall<void>(base + 0x10, 4);
  wr32u(base + 0x57, d);
  wr32u(base + 0x24, d);
  wr32u(base + 0x4f, b);
  wr32u(base + 0x43, c);
  wr32u(base + 0x53, c);
  base[0x2c] = 0;
  wr32u(base + 0x4b, 0);
  base[0x68] = 1;
  return (u32)(base + 0x10);
}
PCREG(54e6a0, fn54e6a0);

// 0x552200, stdcall(a) (ecx unused): e = 0x5003d0([a+4], 0); by the kind byte [e+4]: 3 -> x = [e]; 4 -> x = [e]->slot0x34(); otherwise log through the object at 0x700390 (slot 0x20(0x69c8e0, 0x111),
// its slot 0x2c with (r, 0x69c6b0, 0x69c9b0), caller-popped), the assert hook (int3 when null) and x = 0. Then t = 0x589c20([0x7003b8], 0) and the result of 0x59a580(t, x, -1, 0).
static u32 STDCALL fn552200(u8 *a) {
  u8 *e = (u8 *)ext_5003d0(*(u8 **)(a + 4), 0);
  u32 x;
  u32 kind = e[4];
  if (kind == 3) {
    x = *(u32 *)e;
  } else if (kind == 4) {
    x = vcall<u32>(*(void **)e, 0x34);
  } else {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x69c8e0u, 0x111u);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x69c9b0\n\tpush $0x69c6b0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    x = 0;
  }
  void *g = G(void *, 0x7003b8);
  u32 t = ext_589c20(g, 0);
  return ext_59a580((void *)t, x, -1, 0);
}
PCREG(552200, fn552200);

// 0x562c20, thiscall(k) ret 4, returns bool: logs k through the object at 0x700390 (slot 0x20(0x6a64b4, 0xd3), then its slot 0x2c with (r, 0x6a653c, k), caller-popped); key 0x1388 ->
// 0x562d90(this, 0x106), key 0x2b67 -> 0x562d90(this, 0x105) and true; any other key false.
static bool THISCALL fn562c20(u8 *self, u32 k) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x6a64b4u, 0xd3u);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[k]\n\tpush $0x6a653c\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [k] "r"(k), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  if (k == 0x1388) {
    ext_562d90(self, 0x106);
    return true;
  }
  if (k == 0x2b67) {
    ext_562d90(self, 0x105);
    return true;
  }
  return false;
}
PCREG(562c20, fn562c20);
