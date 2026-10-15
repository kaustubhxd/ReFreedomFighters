#include "ff.h"

typedef u32 (*logfn5)(u32, u32, u32, u32, u32);

static void THISCALL fn4d0c00(u8 *self) {
  u8 *logger = G(u8 *, 0x700390);
  u8 *msg = vcall<u8 *>(logger, 0x20, 0x695dc0u, 0x172u);
  logfn5 first = (logfn5)G(u32, G(u32, msg) + 0x2c);
  first((u32)msg, 0x695e54u, 0x695e44u, G(u32, self + 0xd628), G(u32, self + 0xd62c));
  logger = G(u8 *, 0x700390);
  msg = vcall<u8 *>(logger, 0x20, 0x695dc0u, 0x173u);
  logfn5 second = (logfn5)G(u32, G(u32, msg) + 0x2c);
  second((u32)msg, 0x695e54u, 0x695e68u, G(u32, self + 0x12130), G(u32, self + 0x12134));
}

PCREG(4d0c00, fn4d0c00);
