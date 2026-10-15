// batch37113.cpp - cascade s6 batch 37113: 0x4d6400.
#include "ff.h"

typedef u32 (*hook_t)();

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x4d6400, thiscall(), returns the central directory position or -1: searches the stream object at +0x15 (handle at +0x11; slot 0x10 = seek(h, off, whence), 0xc = tell(h),
// 0x14 = read(buf, size, h)) backwards from 0x16 bytes before the end for the zip end-of-central-directory signature 0x6054b50. A 0x52756e65 marker is followed by an 0x12-byte
// read into +0x34 (a short read asserts) and skipped; any other dword just moves the window back by one byte (net seek -5 after the 4-byte read). The signature stores tell() in +0x19
// and reads the 0x12-byte record into +0x22 (short read asserts); the position is returned. Running out of candidates returns -1.
static u32 THISCALL fn4d6400(u8 *self) {
  void *ms = *(void **)(self + 0x15);
  u32 h = D32(self, 0x11);
  vcall<u32>(ms, 0x10, h, 0u, 2u);
  s32 edi = (s32)vcall<u32>(*(void **)(self + 0x15), 0xc, D32(self, 0x11)) - 0x16;
  vcall<u32>(*(void **)(self + 0x15), 0x10, D32(self, 0x11), (u32)edi, 0u);
  if (edi < 0) return 0xffffffffu;
  do {
    u32 sig;
    if (vcall<u32>(*(void **)(self + 0x15), 0x14, (u32)&sig, 4u, D32(self, 0x11)) != 4) assertHook();
    if (sig == 0x52756e65u) {
      if (vcall<u32>(*(void **)(self + 0x15), 0x14, (u32)(self + 0x34), 0x12u, D32(self, 0x11)) != 0x12) {
        assertHook();
        vcall<u32>(*(void **)(self + 0x15), 0x10, D32(self, 0x11), 0xffffffeeu, 1u);
      } else {
        vcall<u32>(*(void **)(self + 0x15), 0x10, D32(self, 0x11), 0xffffffeeu, 1u);
      }
    } else if (sig == 0x6054b50u) {
      D32(self, 0x19) = vcall<u32>(*(void **)(self + 0x15), 0xc, D32(self, 0x11));
      if (vcall<u32>(*(void **)(self + 0x15), 0x14, (u32)(self + 0x22), 0x12u, D32(self, 0x11)) != 0x12) assertHook();
      return D32(self, 0x19);
    }
    vcall<u32>(*(void **)(self + 0x15), 0x10, D32(self, 0x11), 0xfffffffbu, 1u);
    edi--;
  } while (edi >= 0);
  return 0xffffffffu;
}
PCREG(4d6400, fn4d6400);
