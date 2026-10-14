// batch38084.cpp - cascade s8 batch 38084: 0x493c20 (release 21 owned objects: tell the engine, then delete each one).
#include "ff.h"

typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static const u32 OFFS[21] = {0x5d49, 0x5d4d, 0x5d51, 0x5d55, 0x5d59, 0x5d5d, 0x5d61, 0x5d65, 0x5d69, 0x5d6d, 0x5d71,
                             0x5d75, 0x5d79, 0x5d7d, 0x5d85, 0x5d89, 0x5d8d, 0x5d91, 0x5d95, 0x5d99, 0x5d9d};

// 0x493c20, thiscall(void). For every pointer field in order: engine slot 0x1a8(pointer) (also for null), then, when non-null, the object's deleting destructor (slot 0, argument 1).
static void THISCALL fn493c20(u8 *self) {
  for (int i = 0; i < 21; i++) {
    u8 *sys = G(u8 *, 0x70039c);
    SLOT(sys, 0x1a8, v1_t)(sys, UN32(self, OFFS[i]));
    u8 *o = (u8 *)UN32(self, OFFS[i]);
    if (o) SLOT(o, 0, v1_t)(o, 1);
  }
}
PCREG(493c20, fn493c20);
