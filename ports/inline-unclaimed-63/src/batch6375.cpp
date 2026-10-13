// batch6375.cpp - unclaimed-63 gap-band batch 75: 0x4d9bf0 and 0x4dc840 (parked SEH rows; no GC names). SEH frame not reproduced,
// and the 0x633654 cookie check at the end of both is not reproduced (tagged).
//   0x4d9bf0: thiscall, no stack arguments, plain ret. If this[+0x3c] & 0x4000: 0x4d9f90(this) (thiscall, plain ret) and return.
//     For c = this[+0x50]; c; c = c[+0x50]: for e = c[+0x54] ? [c[+0x54]+0xc] : 0; e; e = e[+0xc]: if e[+0x23] == 0x100021:
//     0x4d95f0(this, c[+0x54], 0.0f) (thiscall, ret 8) and return.
//     Not found: log = [0x700390]->vtbl[+0x20](0x696e24, 0x8c4); r = 0x4da2f0(this, &buf, 1) (thiscall, ret 8; buf is a 0x80-byte local);
//     name = 0x4cc1d0(r) (thiscall, no arguments); log->vtbl[+0x2c](log, 0x696ef0, name) (cdecl, caller cleans 12); 0x4cbec0(&buf).
//   0x4dc840: thiscall, one stack argument b, ret 4. If this != b: if this[+0x3c] & 0x40000: log = [0x700390]->vtbl[+0x20](0x696e24, 0x270);
//     r = 0x4da2f0(this, &buf, 1); s = b[+0x54] and its [+4] non-zero ? that : 0x67c8e8; name = 0x4cc1d0(r);
//     log->vtbl[+0x2c](log, 0x696e88, name, s) (cdecl, caller cleans 16); 0x4cbec0(&buf); h = [0x7003b0]; if h: h() else int3.
//     Then this[+0x3c] |= 0x40000000; 0x4dc970(this, b) (thiscall, ret 4).
//     List part (also when this == b): L = this[+0x54]; f = L ? [[L+0xc]+0x23] : 0x200002; if f & 0x100000: for n = L[+0x50]; n;
//     n = n[+0x60]: 0x4dc840(n, b) (the recursion runs the original).
//   Helpers 0x4d9f90 (parked), 0x4d95f0 (claim in this area, original here), 0x4da2f0, 0x4cc1d0, 0x4cbec0, 0x4dc970: hooks in the spec.
#include "ff.h"

extern "C" void THISCALL ext_4d9f90(void *self);                  // thiscall, no arguments, plain ret (parked; hooked)
extern "C" void THISCALL ext_4d95f0(void *self, u32 x, float f);  // thiscall, ret 8 (hooked)
extern "C" u32 THISCALL ext_4da2f0(void *self, void *buf, u32 a); // thiscall, ret 8, returns an object (hooked)
extern "C" u32 THISCALL ext_4cc1d0(void *self);                   // thiscall, no arguments, returns a string (hooked)
extern "C" void THISCALL ext_4cbec0(void *self);                  // thiscall, no arguments, the local's destructor (hooked)
extern "C" void THISCALL ext_4dc970(void *self, u32 b);           // thiscall, ret 4 (hooked)
extern "C" void THISCALL ext_4dc840(void *self, u32 b);           // this function (the recursion runs the original)

typedef u32(THISCALL * log20_fn)(void *, u32, u32);
typedef void (*printf3_fn)(u32, u32, u32);
typedef void (*printf4_fn)(u32, u32, u32, u32);
typedef void (*hook_fn)(void);

// 0x4d9bf0 (C-set; SEH frame not reproduced).
static void THISCALL unnamed4d9bf0(u8 *self) {
  if (*(u32 *)(self + 0x3c) & 0x4000u) {
    ext_4d9f90((void *)self);
    return;
  }
  for (u32 c = *(u32 *)(self + 0x50); c != 0; c = *(u32 *)(c + 0x50)) {
    u32 e = *(u32 *)(c + 0x54);
    if (e == 0)
      continue;
    for (e = *(u32 *)(e + 0xc); e != 0; e = *(u32 *)(e + 0xc)) {
      if (*(u32 *)(e + 0x23) == 0x100021u) {
        ext_4d95f0((void *)self, *(u32 *)(c + 0x54), 0.0f);
        return;
      }
    }
  }
  u32 lg = G(u32, 0x700390);
  u32 log = ((log20_fn)(*(u32 *)(*(u32 *)lg + 0x20)))((void *)lg, 0x696e24u, 0x8c4u);
  u8 buf[0x80];
  u32 r = ext_4da2f0((void *)self, buf, 1u);
  u32 name = ext_4cc1d0((void *)r);
  ((printf3_fn)(*(u32 *)(*(u32 *)log + 0x2c)))(log, 0x696ef0u, name);
  ext_4cbec0(buf);
}
PCREG(4d9bf0, unnamed4d9bf0);

// 0x4dc840 (C-set; SEH frame not reproduced).
static void THISCALL unnamed4dc840(u8 *self, u32 b) {
  if ((u32)self != b) {
    if (*(u32 *)(self + 0x3c) & 0x40000u) {
      u32 lg = G(u32, 0x700390);
      u32 log = ((log20_fn)(*(u32 *)(*(u32 *)lg + 0x20)))((void *)lg, 0x696e24u, 0x270u);
      u8 buf[0x80];
      u32 r = ext_4da2f0((void *)self, buf, 1u);
      u32 s = 0x67c8e8u;
      u32 p = *(u32 *)(b + 0x54);
      if (p != 0 && *(u32 *)(p + 4) != 0)
        s = *(u32 *)(p + 4);
      u32 name = ext_4cc1d0((void *)r);
      ((printf4_fn)(*(u32 *)(*(u32 *)log + 0x2c)))(log, 0x696e88u, name, s);
      ext_4cbec0(buf);
      u32 h = G(u32, 0x7003b0);
      if (h != 0)
        ((hook_fn)h)();
      else
        __builtin_debugtrap();
    }
    *(u32 *)(self + 0x3c) |= 0x40000000u;
    ext_4dc970((void *)self, b);
  }
  u32 L = *(u32 *)(self + 0x54);
  u32 f = (L != 0) ? *(u32 *)(*(u32 *)(L + 0xc) + 0x23) : 0x200002u;
  if (f & 0x100000u) {
    for (u32 n = *(u32 *)(L + 0x50); n != 0; n = *(u32 *)(n + 0x60))
      ext_4dc840((void *)n, b);
  }
}
PCREG(4dc840, unnamed4dc840);
