// batch37071.cpp - cascade s6 batch 37071: 0x57e040.
#include "ff.h"

extern "C" void *__attribute__((cdecl)) ext_634d22(void *dst, const void *src, u32 n);   // memcpy thunk
extern "C" void *__attribute__((cdecl)) ext_634d10(void *dst, u32 v, u32 n);             // memset thunk
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(o) (*(u32 *)(self + (o)))

// 0x57e040, thiscall(msg) ret 4, returns bool: an input-capture buffer (self+0x330, length +0x338, reference copy at +0x32c). While capture is active (+0x33c != 0): messages
// 0x2710 / 0x2711 clear the buffer and set byte 5 / 6 of the engine's page (+0x190b -> +0x10) to 0x7f, anything else copies the engine's current block (+0x1907 -> +0x131c) in;
// the changed flag (+0x34a) is set when a non-zero byte differs from the reference. The message is forwarded to the sub-object at +0x190 (slot 4); returns true. Otherwise only
// message 9 does anything: it swaps a handle between the table object's slots and passes it to the owner's slot 0x2ec, returning false.
static u8 THISCALL fn57e040(u8 *self, u32 msg) {
  u8 *eng = *(u8 **)0x70039c;
  if (F32(0x33c)) {
    if (self[0x34a] == 0) {
      u32 n = F32(0x338);
      if (msg == 0x2710) {
        ext_634d10((void *)F32(0x330), 0, n);
        *(u8 *)(D32(*(u8 **)(eng + 0x190b), 0x10) + F32(0x330) + 5) = 0x7f;
      } else if (msg == 0x2711) {
        ext_634d10((void *)F32(0x330), 0, n);
        *(u8 *)(D32(*(u8 **)(eng + 0x190b), 0x10) + F32(0x330) + 6) = 0x7f;
      } else {
        ext_634d22((void *)F32(0x330), (void *)D32(*(u8 **)(eng + 0x1907), 0x131c), n);
      }
      u32 edi = F32(0x338);
      for (u32 i = 0; edi != 0 && i < edi; i++) {
        u8 dl = ((u8 *)F32(0x330))[i];
        if (dl != 0 && ((u8 *)F32(0x32c))[i] != dl) self[0x34a] = 1;
      }
    }
    vcall<void>(self + 0x190, 4, msg);
    return 1;
  }
  if (msg == 9) {
    u32 h = 0;
    void *o = (void *)vcall<u32>(self, 0x84);
    u32 ebx = vcall<u32>(o, 0x2f0);
    void *tab = *(void **)(*(u8 **)0x70039c + 0x9b);
    if (ebx) h = vcall<u32>(tab, 0x4c, ebx);
    u32 r;
    if (self[0x349]) {
      if (vcall<u32>(self + 0x264, 0x2c, h)) F32(0x340) = h;
      tab = *(void **)(*(u8 **)0x70039c + 0x9b);
      r = vcall<u32>(tab, 0x58, F32(0x344));
      self[0x349] = 0;
    } else {
      tab = *(void **)(*(u8 **)0x70039c + 0x9b);
      r = vcall<u32>(tab, 0x58, h);
      if (h != 0 && h == F32(0x344)) F32(0x344) = h;
      tab = *(void **)(*(u8 **)0x70039c + 0x9b);
      r = vcall<u32>(tab, 0x58, F32(0x340));
      self[0x349] = 1;
    }
    o = (void *)vcall<u32>(self, 0x84);
    vcall<void>(o, 0x2ec, r);
  }
  return 0;
}
PCREG(57e040, fn57e040);
