// batch67570.cpp - cascade s6 batch 67570: 0x6000b0.
#include "ff.h"

extern "C" void THISCALL ext_5fefb0(u8 *self);                 // plain ret
extern "C" u32 THISCALL ext_5ffb00(u8 *p, u32 id);             // ret 4
extern "C" u32 THISCALL ext_5ffe20(u8 *self, u32 v);           // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define G8(a) (*(volatile u8 *)(a))
typedef u32 (__cdecl *cmp_t)(u32, u32);
typedef void (__cdecl *log_t)(u8 *, u32, u32);
typedef void (*hook_t)();

// 0x6000b0, thiscall(key) ret 4, returns eax (0 when nothing matched; recursion result; the 0x5ffe20 result on a match): looks key up among the id / value pairs of this[0xc8] (this[0xc4] pairs of
// two words). Each pair's id is mapped to an entry: through the table (this[0xa8] entries at this[0xac], offset base this[0xb0], id base this[0xa0]) or, when the id is below the base or there is
// no table, through the parent object this[0x9c] (0x5ffb00); an out-of-range id logs (0x137) and reuses the previous entry address (the original's uninitialised local, initially `this`); a missing
// parent runs the assert hook and keeps the previous entry. The entry is compared with the key through the function at 0x676414; on a match 0x5ffe20(value) is the result. When no pair
// matches, the parent object is searched the same way. 0x5fefb0 runs first when the flag byte at 0x724690 is set.
static u32 THISCALL fn6000b0(u8 *self, u32 key) {
  u32 v4 = (u32)self;
  if (G8(0x724690)) ext_5fefb0(self);
  u32 edi = 0;
  u32 eax = 0;
  if (D32(self, 0xc4) != 0) {
    u32 ebx = key;
    for (;;) {
      u8 *arr = *(u8 **)(self + 0xc8);
      u32 ecx = *(u16 *)(arr + edi * 4);
      bool viaParent = D32(self, 0xa8) == 0 || D32(self, 0xa0) > ecx;
      if (!viaParent) {
        u32 idx = (u16)(ecx - *(u16 *)(self + 0xa0));
        if (idx < D32(self, 0xa8)) {
          v4 = D32(*(u8 **)(self + 0xac), idx * 4) + D32(self, 0xb0);
        } else {
          u8 *lg = *(u8 **)0x700390;
          u8 *x = vcall<u8 *>(lg, 0x20, 0x6b9420u, 0x137u);
          (*(log_t *)(*(u8 **)x + 0x2c))(x, 0x69c6b0u, 0x6b9474u);
          hook_t h = *(hook_t *)0x7003b0;
          if (h) h(); else __asm__ volatile("int3");
        }
        ebx = v4;
      } else {
        u8 *p = *(u8 **)(self + 0x9c);
        if (p) {
          ebx = ext_5ffb00(p, ecx);
        } else {
          hook_t h = *(hook_t *)0x7003b0;
          if (h) h(); else __asm__ volatile("int3");
        }
      }
      if ((*(cmp_t *)0x676414)(ebx, key) == 0) {
        arr = *(u8 **)(self + 0xc8);
        return ext_5ffe20(self, *(u16 *)(arr + edi * 4 + 2));
      }
      edi++;
      if (!(edi < D32(self, 0xc4))) break;
    }
  }
  if (!(edi < D32(self, 0xc4))) {
    u8 *p = *(u8 **)(self + 0x9c);
    if (p) return fn6000b0(p, key);
  }
  return eax;
}
PCREG(6000b0, fn6000b0);
