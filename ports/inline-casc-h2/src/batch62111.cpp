#include "ff.h"
extern "C" void THISCALL ext_5a9e20(u8 *logger, u32 message);
extern "C" void THISCALL ext_5aa060(u8 *logger, u32 message);
extern "C" void THISCALL ext_5b0010(u8 *self, u8 *resource);
static void THISCALL fn5b0220(u8 *self) {
  u8 *manager = (u8 *)*(u32 *)(self + 0x1d0b);
  u8 *resource = (u8 *)vcall<u32>(manager, 0x504);
  u8 *logger = (u8 *)*(u32 *)(self + 0x1d0f);
  if (!resource) {
    ext_5a9e20(logger, 0);
    if (logger) ext_5aa060(logger, 0x677b5a);
    return;
  }
  u8 *description = (u8 *)vcall<u32>(resource, 0x2e8);
  u32 message = description ? *(u32 *)(description + 4) : 0;
  if (!message) message = 0x67c8e8;
  ext_5a9e20(logger, message);
  ext_5b0010(self, resource);
}
PCREG(5b0220, fn5b0220);
