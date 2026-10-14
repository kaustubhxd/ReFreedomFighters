// batch38070.cpp - cascade s8 batch 38070: 0x4a8230 (keep a list cursor on an entry whose object accepts flag 0x80200014; step it with the keys; push the selection to the list's objects).
#include "ff.h"

extern "C" void THISCALL ext_4a85a0(u8 *self, int a);   // ret 4
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
typedef u8(THISCALL *b1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define SYS G(u8 *, 0x70039c)

static u8 *tblget(u32 id) {
  u8 *t = *(u8 **)(SYS + 0x9b);
  return (u8 *)SLOT(t, 0x58, v1_t)(t, id);
}
static u8 *listp(u8 *self) { return (u8 *)W(W(self, 0x44), 0x18); }

// 0x4a8230, thiscall(this) void. this+0x44 -> holder whose +0x18 is the list object (slots 0x4c begin / 0x5c next / 0x30 id at index / 0x14 count); this+0x4e = current index (unaligned),
// this+0x54 = current key, this+0x48 = id of the owner object, this+0x4c = word.
static void THISCALL fn4a8230(u8 *self) {
  u32 it[3];
  if (UN32(self, 0x54) == 0) {
    u8 *L = listp(self);
    u32 edi = 0;
    if (L) {
      SLOT(L, 0x4c, v1_t)(L, (u32)it);
      L = listp(self);
      u32 id = SLOT(L, 0x5c, v1_t)(L, (u32)it);
      if (it[0] != 0) {
        for (;;) {
          u8 *o = tblget(id);
          if (o) {
            if (SLOT(o, 0x1e0, b1_t)(o, 0x80200014)) { UN32(self, 0x4e) = edi; break; }
            edi++;
          }
          L = listp(self);
          id = SLOT(L, 0x5c, v1_t)(L, (u32)it);
          if (it[0] == 0) break;
        }
      }
    }
  }
  if (SLOT(SYS, 0xe8, b1_t)(SYS, 0x48)) {
    u8 *L = listp(self);
    u8 *o = tblget(SLOT(L, 0x30, v1_t)(L, UN32(self, 0x4e)));
    if (o && !SLOT(o, 0x1e0, b1_t)(o, 0x80200014)) {
      ext_4a85a0(self, 1);
      L = listp(self);
      u32 edi = SLOT(L, 0x30, v1_t)(L, UN32(self, 0x4e));
      if (edi != W(self, 0x54)) {
        do {
          ext_4a85a0(self, 1);
          L = listp(self);
          o = tblget(SLOT(L, 0x30, v1_t)(L, UN32(self, 0x4e)));
          if (SLOT(o, 0x1e0, b1_t)(o, 0x80200014)) break;
        } while (edi != W(self, 0x54));
      }
    }
  }
  u8 *L = listp(self);
  if ((int)SLOT(L, 0x14, v0_t)(L) > 1) {
    if (SLOT(SYS, 0xe8, b1_t)(SYS, 9)) {
      u8 al = SLOT(SYS, 0xe4, b1_t)(SYS, 0x10);
      ext_4a85a0(self, al ? -1 : 1);
    }
  }
  L = listp(self);
  u32 ebx = SLOT(L, 0x30, v1_t)(L, UN32(self, 0x4e));
  if (ebx != W(self, 0x54)) {
    u8 *owner = tblget(W(self, 0x48));
    if (owner) {
      u8 *L2 = (u8 *)W(owner, 0x18);
      if (L2) {
        SLOT(L2, 0x4c, v1_t)(L2, (u32)it);
        u32 id = SLOT(L2, 0x5c, v1_t)((u8 *)W(owner, 0x18), (u32)it);
        if (it[0] != 0) {
          do {
            u8 *o = tblget(id);
            SLOT(o, 0x124, v4_t)(o, 0x20, ebx, *(u16 *)(self + 0x4c), 0);
            L2 = (u8 *)W(owner, 0x18);
            id = SLOT(L2, 0x5c, v1_t)(L2, (u32)it);
          } while (it[0] != 0);
        }
      }
      W(self, 0x54) = ebx;
    }
  }
}
PCREG(4a8230, fn4a8230);
