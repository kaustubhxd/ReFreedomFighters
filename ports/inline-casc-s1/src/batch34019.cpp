// batch34019.cpp - cascade tier E, batch 34019: 0x5f9450 (apply a helper to each 8-byte entry of an array) and 0x604460 (dispatch a record id
// through a table of handlers).
#include "ff.h"

extern "C" void THISCALL ext_605a10(void *entry, void *a, u32 b, void *ctx);   // thiscall ret 0xc
extern "C" bool THISCALL ext_5fb550(void *self, void *a);                      // thiscall ret 4, bool in al
extern "C" void THISCALL ext_5f4600(void *a, u32 r);                           // thiscall ret 4
extern "C" void THISCALL ext_5f4ac0(void *a);                                  // thiscall, plain ret
typedef u32 (*hook_t)();

// 0x5f9450, thiscall(a, b, c) ret 0xc: a->slot0x2c(c[2]); for each of the c[2] entries (8 bytes each, base c[0]): 0x605a10(entry, a, b, this).
static void THISCALL fn5f9450(u8 *self, u8 *a, u32 b, u32 *c) {
  vcall<void>(a, 0x2c, c[2]);
  u32 n = c[2];
  if (n == 0) return;
  u32 i = 0;
  do {
    ext_605a10((u8 *)c[0] + i * 8, a, b, self);
    n = c[2];
    i++;
  } while (i < n);
}
PCREG(5f9450, fn5f9450);

// 0x604460, thiscall(a, b, c) ret 0xc: when 0x5fb550([this+4], a) fails: the assert hook (int3 when null) and return; else the handler h = [[this+8] + (u16)b*4];
// when h: r = h->slot0(a, (u16)b, c); when r: 0x5f4600(a, r), 0x5f4ac0(a).
static void THISCALL fn604460(u8 *self, u8 *a, u32 b, u32 c) {
  if (!ext_5fb550(*(void **)(self + 4), a)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    return;
  }
  u32 idx = (u16)b;
  u8 *hnd = (*(u8 ***)(self + 8))[idx];
  if (hnd) {
    u32 r = vcall<u32>(hnd, 0, (u32)a, idx, c);
    if (r) {
      ext_5f4600(a, r);
      ext_5f4ac0(a);
    }
  }
}
PCREG(604460, fn604460);
