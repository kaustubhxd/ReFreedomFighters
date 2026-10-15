// batch38092.cpp - cascade s8 batch 38092: 0x6579a0 (copy a stream of vertex attributes into an interleaved vertex buffer).
#include "ff.h"

typedef u8 *(THISCALL *v1_t)(void *, u32);
typedef u32 (*hook_t)();
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define U(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x6579a0, thiscall(id, mode, src, n) ret 0x10, void. Slot 0xc resolves a buffer descriptor from the id, and the descriptor's +0x14 from there to the vertex data (0x24-byte vertices). The descriptor is
// skipped when its word +2 is set. mode 1: 3 dwords at +0 (position), 2: 1 dword at +0x18 (colour), 4: 3 dwords at +0xc (normal), otherwise 2 dwords at +0x1c (texture coordinates).
static void THISCALL fn6579a0(u8 *self, u32 id, u32 mode, u32 *src, u32 n) {
  u8 *B = SLOT(self, 0xc, v1_t)(self, id);
  if (*(u16 *)(B + 2) != 0) return;
  u8 *V = SLOT(self, 0xc, v1_t)(self, U(B, 0x14));
  u32 cap = (u32)*(u16 *)(B + 0xe) * U(B, 0x50);
  if (!(cap >= n)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  if (mode == 1) {
    for (u32 i = 0; i < n; i++) {
      U(V, i * 0x24) = src[3 * i];
      U(V, i * 0x24 + 4) = src[3 * i + 1];
      U(V, i * 0x24 + 8) = src[3 * i + 2];
    }
  } else if (mode == 2) {
    for (u32 i = 0; i < n; i++) U(V, i * 0x24 + 0x18) = src[i];
  } else if (mode == 4) {
    for (u32 i = 0; i < n; i++) {
      U(V, i * 0x24 + 0xc) = src[3 * i];
      U(V, i * 0x24 + 0x10) = src[3 * i + 1];
      U(V, i * 0x24 + 0x14) = src[3 * i + 2];
    }
  } else {
    for (u32 i = 0; i < n; i++) {
      U(V, i * 0x24 + 0x1c) = src[2 * i];
      U(V, i * 0x24 + 0x20) = src[2 * i + 1];
    }
  }
}
PCREG(6579a0, fn6579a0);
