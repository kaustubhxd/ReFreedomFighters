#include "ff.h"
static void THISCALL resolve_local_record(u8* self) {
  u8* table = G(u8*,(u8*)g_pSysInterface + 0x9b);
  u8* lookup = (u8*)vcall<u32>(table,0x58,G(u32,self+0x48));
  if (!lookup) return;
  u32 local[3] = {0,0,0};
  vcall<u32>(lookup,0x84,(u32)local);
  u32 id = vcall<u32>(G(u8*,self+0x44),0x218,(u32)local,0);
  u8* format = (u8*)vcall<u32>(table,0x138);
  u32 high = (id >> 16) & 0xff;
  u32 low = id & 0xff;
  float hi_value = (float)high * G(float,0x682eb8);
  float lo_value = (float)low * G(float,0x682eb8);
  vcall<void>(format,0x58,0x6954e8,hi_value,3u);
  vcall<void>(format,0x58,0x6954f8,lo_value,3u);
}
PCREG(4c91c0,resolve_local_record);
