#include "ff.h"
extern "C" void THISCALL ext_4e6330(u8 *parser, u32 *cursor);
static u32 THISCALL fn4bb7c0(u8 *self, u8 *parser) {
  ext_4e6330(parser, (u32 *)(self + 0x48));
  ext_4e6330(parser, (u32 *)(self + 0xf4));
  u8 *table = (u8 *)*(u32 *)(*(u32 *)0x70039c + 0x9b);
  u8 *receiver = (u8 *)vcall<u32>(table, 0x138);
  u32 handle = vcall<u32>(table, 0x4c, *(u32 *)(self + 0x44), 0x10);
  return vcall<u32>(receiver, 0x60, 0x692dec, handle);
}
PCREG(4bb7c0, fn4bb7c0);
