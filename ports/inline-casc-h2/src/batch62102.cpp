#include "ff.h"
extern "C" u32 THISCALL ext_5003d0(u8 *cursor, u32 index);
static void STDCALL fn50bef0(u8 *param) {
  u8 *table = (u8 *)*(u32 *)(*(u32 *)0x70039c + 0x9b);
  u8 *factory = (u8 *)*(u32 *)(table + 0xadc);
  u8 *resource = (u8 *)vcall<u32>(factory, 0x25c, 0x685f44, 0);
  u8 *cursor = (u8 *)*(u32 *)(param + 4);
  u32 *entry = (u32 *)ext_5003d0(cursor, 0);
  u32 id = (u16)vcall<u32>(table, 0x114, 0x690464, 0, 0x69d420, 0x93, *entry);
  vcall<void>(resource, 0x130, resource, id);
}
PCREG(50bef0, fn50bef0);
