// batch1006.cpp - unclaimed-07 batch 6 (docs/20-unclaimed-07.md, slice 6): CCheckInsideByType::Init2Wrapper.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x5bd8e0, CCheckInsideByType::Init2Wrapper() (high): sys = g_sys (0x70039c); a = sys+0x9b; b = a+0xadc.
// r = b slot +0x25c(0x685f44, 0). v = r slot +0x100(0x6a5cf0). The dword at this+0x81 is v.
// When v is 0: the engine log (global 0x700390) gives a stream through slot +0x20(0x6b3438, 0x3d); the stream's cdecl
// slot +0x2c gets (stream, 0x6b3470); then this slot +0x68(0x10, 0). When v is not 0: the dword at this+0x6c is
// the result of slot +0x14 on the object at r+0x18. Plain ret.
static void THISCALL checkInsideByTypeInit2Wrapper(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *a = *(u8 **)(sys + 0x9b);
  void *b = *(void **)(a + 0xadc);
  u8 *r = (u8 *)vcall<u32>(b, 0x25c, 0x685f44u, 0u);
  u32 v = vcall<u32>((void *)r, 0x100, 0x6a5cf0u);
  *(u32 *)(self + 0x81) = v;
  if (v == 0) {
    void *log = vcall<void *>(*(void **)0x700390, 0x20, (const char *)0x6b3438, 0x3du);
    typedef void(__attribute__((cdecl)) * printf_t)(void *, const char *);
    (*(printf_t *)(*(u8 **)log + 0x2c))(log, (const char *)0x6b3470);
    vcall<void>(self, 0x68, 0x10u, 0u);
    return;
  }
  void *o = *(void **)(r + 0x18);
  *(u32 *)(self + 0x6c) = vcall<u32>(o, 0x14);
}
PCREG(5bd8e0, checkInsideByTypeInit2Wrapper);
