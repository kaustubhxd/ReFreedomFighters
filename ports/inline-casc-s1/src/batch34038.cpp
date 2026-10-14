// batch34038.cpp - cascade tier E, batch 34038: 0x4d6980 / 0x4d6a10 (reset an array object and allocate n elements of 4 / 42 bytes) and 0x4f4610 (read two fields
// from a stream and free an empty string).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);   // cdecl alloc
extern "C" void ext_41e2c0(void *p);   // cdecl free
extern "C" void ext_634273(void *p, u32 n);                    // cdecl free(ptr, size)
extern "C" bool THISCALL ext_4f04e0(void *self, void *s);      // thiscall ret 4, bool in al

// Shared body: release the old block ([this+8]), allocate n elements of `elem` bytes (size saturates on overflow; a failed allocation logs through the object at 0x700390:
// slot 0x20(0x696770, 0x140), then its slot 0x2c with (r, 0x696bc0), caller-popped), then [this] = n, [this+4] = 0.
static inline void alloc_array(u8 *self, u32 n, u32 elem) {
  if (*(u32 *)(self + 8)) {
    ext_41e2c0(*(void **)(self + 8));
    *(u32 *)(self + 8) = 0;
    *(u32 *)(self + 4) = 0;
    *(u32 *)self = 0;
  }
  u64 m = (u64)n * elem;
  u32 size = (m >> 32) ? 0xffffffffu : (u32)m;
  u32 p = ext_41e290(size);
  *(u32 *)(self + 8) = p;
  if (!p) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = vcall<u8 *>(lg, 0x20, 0x696770u, 0x140u);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x696bc0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  }
  *(u32 *)self = n;
  *(u32 *)(self + 4) = 0;
}

// 0x4d6980, thiscall(n) ret 4: array of n 4-byte elements.
static void THISCALL fn4d6980(u8 *self, u32 n) { alloc_array(self, n, 4); }
PCREG(4d6980, fn4d6980);

// 0x4d6a10, thiscall(n) ret 4: array of n 42-byte elements.
static void THISCALL fn4d6a10(u8 *self, u32 n) { alloc_array(self, n, 0x2a); }
PCREG(4d6a10, fn4d6a10);

// 0x4f4610, thiscall(s) ret 4, returns the stored flag r: s->slot0x48(this+0xb0); r = 0x4f04e0(this, s); when r: s->slot0x60(this+0xac); then when the string at [this+0xac]
// is empty (first byte zero): free(string, 1) and [this+0xac] = 0. Returns r.
static bool THISCALL fn4f4610(u8 *self, u8 *s) {
  vcall<void>(s, 0x48, (u32)(self + 0xb0));
  bool r = ext_4f04e0(self, s);
  if (r) vcall<void>(s, 0x60, (u32)(self + 0xac));
  u8 *p = *(u8 **)(self + 0xac);
  if (*p == 0) {
    ext_634273(p, 1);
    *(u32 *)(self + 0xac) = 0;
    return r;
  }
  return r;
}
PCREG(4f4610, fn4f4610);
