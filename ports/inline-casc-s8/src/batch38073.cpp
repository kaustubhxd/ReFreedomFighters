// batch38073.cpp - cascade s8 batch 38073: 0x496db0 (destroy / release everything an object owns).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);   // cdecl free(ptr, size)
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define PTR(p, off) ((u8 *)UN32(p, off))

static void del(u8 *o) { SLOT(o, 0, v1_t)(o, 1); }   // deleting destructor

// a small record {+0 object, +4 buffer, +0x10 object}: free the buffer, delete the objects, free the record (0x14 bytes)
static void drop_record(u8 *self, u32 off) {
  u8 *r = PTR(self, off);
  if (!r) return;
  if (PTR(r, 4)) ext_634273(PTR(r, 4), 1);
  if (PTR(r, 0)) del(PTR(r, 0));
  if (PTR(r, 0x10)) del(PTR(r, 0x10));
  ext_634273(r, 0x14);
  UN32(self, off) = 0;
}
static void drop_buf(u8 *self, u32 off, u32 size) {
  if (PTR(self, off)) {
    ext_634273(PTR(self, off), size);
    UN32(self, off) = 0;
  }
}

// 0x496db0, thiscall(this) void.
static void THISCALL fn496db0(u8 *self) {
  drop_record(self, 0x14);
  drop_record(self, 0x1c);
  if (PTR(self, 8)) {
    del(PTR(self, 8));
    UN32(self, 8) = 0;
  }
  drop_buf(self, 0xc, 4);
  drop_record(self, 0x18);
  drop_buf(self, 0x40, 0xc);
  drop_buf(self, 0x44, 8);
  drop_buf(self, 0x51, 0x20);
  drop_buf(self, 0x55, 2);
  drop_buf(self, 0x5d, 4);
  UN32(self, 0x59) = 0;
  u8 *g = G(u8 *, 0x70038c);
  SLOT(g, 0xdc, v0_t)(g);
  drop_buf(self, 0x30, 1);
  if (PTR(self, 0x2c)) {
    del(PTR(self, 0x2c));
    UN32(self, 0x2c) = 0;
  }
  u8 *l = PTR(self, 4);
  UN32(self, 0x34) = 0;
  UN32(self, 0x38) = 0;
  if (l) {
    u32 it[3];
    SLOT(l, 0x4c, v1_t)(l, (u32)it);
    l = PTR(self, 4);
    u32 p = SLOT(l, 0x5c, v1_t)(l, (u32)it);
    if (it[0] != 0) {
      do {
        ext_634273((void *)p, 1);
        l = PTR(self, 4);
        p = SLOT(l, 0x5c, v1_t)(l, (u32)it);
      } while (it[0] != 0);
    }
  }
  l = PTR(self, 4);
  if (l) del(l);
  UN32(self, 4) = 0;
}
PCREG(496db0, fn496db0);
