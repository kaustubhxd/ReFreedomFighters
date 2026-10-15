#include "ff.h"
extern "C" void THISCALL ext_641b60(void *self, u32 value);
static u32 THISCALL fn6472c0(u8 *self, u8 *arg) {
  u8 *nested = (u8 *)G(u32, arg + 8);
  u32 id = G(u32, nested + 0x6c);
  u8 *sys = (u8 *)g_pSysInterface;
  u8 *table = (u8 *)G(u32, sys + 0x1aa3);
  u8 *owner = (u8 *)G(u32, table + 0x18);
  u32 result = vcall<u32>(owner, 0xb0, id);
  G(u32, self + 0x11) = result;
  u32 flag = G(u32, self + 0x291);
  if (flag) {
    ext_641b60((void *)G(u32, self + 0x28d), flag);
    G(u32, self + 0x291) = 0;
    return vcall<u32>(self, 0x30, (u32)arg, 1u, 1u, 0u);
  }
  return flag;
}
PCREG(6472c0, fn6472c0);
