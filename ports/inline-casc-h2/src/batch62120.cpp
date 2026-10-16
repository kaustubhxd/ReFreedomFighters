#include "ff.h"
static u16 THISCALL fn5f2a80(u8 *self, u32 gate, u32 key, u8 *input) {
  if (!gate) return 0;
  u32 index = (u16)key;
  u8 *records = input;
  if ((u16)key == G(u16, 0x7143b0)) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *table = G(u8 *, sys + 0x9b);
    index = vcall<u32>(table, 0x114, G(u32, records), 0u, 0x6b8738u, 0x305u) & 0xffff;
    records += 4;
  }
  u16 item = G(u16, self + 0x10 + index * 2);
  if (!item) return (u16)index;
  u8 *collection = (u8 *)G(u32, self + 0xc);
  u8 *dispatch = collection + 8;
  typedef u32 (THISCALL *dispatch_t)(u8 *, u32, u32, u32);
  u32 interface = G(u32, dispatch);
  u32 fn = G(u32, interface);
  return (u16)((dispatch_t)fn)(dispatch, gate, item, (u32)records);
}
PCREG(5f2a80, fn5f2a80);
