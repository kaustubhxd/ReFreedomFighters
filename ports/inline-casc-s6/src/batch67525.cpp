// batch67525.cpp - cascade s6 batch 67525: 0x443670.
#include "ff.h"

extern "C" u8 *THISCALL ext_4db7e0(u8 *member);          // plain ret: returns the object for a member
extern "C" void THISCALL ext_441e40(u8 *obj, u8 *x);     // ret 4
extern "C" void THISCALL ext_443b40(u8 *obj, u8 *x);     // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x443670, thiscall(on) ret 4: switches this object's highlight state. Only for the object currently registered in the table object at +0xadc and only when the flag byte at +0x76
// changes. Turning on sets the byte, unless slot 0x310 says otherwise looks up the object of the slot-0x20 record's +8 member (0x4db7e0), registers this with it (0x441e40) and runs
// 0x443b40 for every entry of the list at +0x7b (count word +2, entries from +0x404). Turning off clears the byte, calls slot 0x334 first and does the same with the two helpers swapped.
static void THISCALL fn443670(u8 *self, u8 on) {
  if (self != *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xadc)) return;
  if (self[0x76] == on) return;
  if (on) {
    self[0x76] = 1;
    if ((u8)vcall<u32>(self, 0x310)) return;
    if (!vcall<u32>(self, 0x20)) return;
    u8 *rec = (u8 *)vcall<u32>(self, 0x20);
    u8 *obj = ext_4db7e0(*(u8 **)(rec + 8));
    if (!obj) return;
    ext_441e40(obj, self);
    u8 *list = *(u8 **)(self + 0x7b);
    if (!list) return;
    u32 n = 0;
    if (W16(list, 2) == 0) return;
    do {
      list = *(u8 **)(self + 0x7b);
      ext_443b40(obj, *(u8 **)(list + 0x404 + n * 4));
      list = *(u8 **)(self + 0x7b);
      n++;
    } while (n != W16(list, 2));
    return;
  }
  self[0x76] = 0;
  vcall<void>(self, 0x334);
  if ((u8)vcall<u32>(self, 0x310)) return;
  if (!vcall<u32>(self, 0x20)) return;
  u8 *rec = (u8 *)vcall<u32>(self, 0x20);
  u8 *obj = ext_4db7e0(*(u8 **)(rec + 8));
  if (!obj) return;
  ext_443b40(obj, self);
  u8 *list = *(u8 **)(self + 0x7b);
  if (!list) return;
  u32 n = 0;
  if (W16(list, 2) == 0) return;
  do {
    list = *(u8 **)(self + 0x7b);
    ext_441e40(obj, *(u8 **)(list + 0x404 + n * 4));
    list = *(u8 **)(self + 0x7b);
    n++;
  } while (n != W16(list, 2));
}
PCREG(443670, fn443670);
