// batch37063.cpp - cascade s6 batch 37063: 0x461d60.
#include "ff.h"

extern "C" void THISCALL ext_4dc440(u8 *self, u32 f);               // ret 4
extern "C" void THISCALL ext_4db2c0(u8 *self, u32 *a, u32 *b);      // ret 8
extern "C" void FASTCALL ext_4419f0(u32 *dst, u32 *src);            // ecx / edx, plain ret
extern "C" void FASTCALL ext_4de480(u32 *a, u32 *b);                // ecx / edx, plain ret
extern "C" void FASTCALL ext_441940(u32 *a, u32 *b);                // ecx / edx, plain ret
extern "C" void THISCALL ext_4de7a0(u32 *m);                        // plain ret (original code)
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define OWNER(self) ((u8 *)(*(v0_t **)(self))[0x20 / 4]((self)))
#define SLOT0(o, off) ((*(v0_t **)(o))[(off) / 4]((o)))

// 0x461d60, thiscall, no args: re-binds the entry's transform to its owner. Unless this+0xc is the object class 0x200027 it asks the owner (slot 0x20) twice about flags
// (+0x3c bits 0x4000 / 0x40000) and calls 0x4dc440(owner+8, 1); tells the manager at [[engine+0x1aa3]+0x18] (slot 0xc) the +0x6c of this+8; copies the owner's name (default
// 0x67c8e8) to +0x58; builds the two 36-byte frames of this+8 and of the owner's +8 with 0x4db2c0, combines them (0x4419f0, 0x4de480, 0x441940), resets one to identity (0x4de7a0),
// applies the frames to this and to the owner (slot 0x74), runs slots 0x110(0x10, 0) and 0x214, then temporarily sets the byte +0xd0 of the object at [[table]+0x5d31] while it
// handles the owner's +8 (slot 0) and finally runs slot 0x260.
static void THISCALL fn461d60(u8 *self) {
  u32 v64[9], v40[9], v1c[3], v10[3];
  u8 *own = *(u8 **)(self + 0xc);
  if (D32(own, 0x23) != 0x200027) {
    u8 *a = OWNER(self);
    if (!(D32(*(u8 **)(a + 8), 0x3c) & 0x4000)) {
      u8 *b = OWNER(self);
      if (D32(*(u8 **)(b + 8), 0x3c) & 0x40000) {
        u8 *c = OWNER(self);
        ext_4dc440(*(u8 **)(c + 8), 1);
      }
    }
  }
  u8 *m = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x1aa3) + 0x18);
  (*(v1_t **)m)[0xc / 4](m, D32(*(u8 **)(self + 8), 0x6c));
  u8 *o = OWNER(self);
  u32 name = D32(o, 4);
  if (!name) name = 0x67c8e8;
  D32(self, 0x58) = name;
  ext_4db2c0(*(u8 **)(self + 8), v40, v10);
  u8 *o2 = OWNER(self);
  ext_4db2c0(*(u8 **)(o2 + 8), v64, v1c);
  ext_4419f0(v10, v64);
  ext_4de480(v64, v40);
  ext_441940(v1c, v10);
  ext_4de7a0(v40);
  v10[0] = 0;
  v10[1] = 0;
  v10[2] = 0;
  (*(v2_t **)self)[0x74 / 4](self, (u32)v40, (u32)v10);
  u8 *o3 = OWNER(self);
  (*(v2_t **)o3)[0x74 / 4](o3, (u32)v64, (u32)v1c);
  (*(v2_t **)self)[0x110 / 4](self, 0x10, 0);
  SLOT0(self, 0x214);
  u8 *t = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0x5d31);
  u8 bl = *(u8 *)(t + 0xd0);
  *(u8 *)(t + 0xd0) = 1;
  u8 *esi = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0x5d31);
  u8 *o4 = OWNER(self);
  (*(v1_t **)esi)[0](esi, D32(o4, 8));
  u8 *t2 = *(u8 **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 0x5d31);
  *(u8 *)(t2 + 0xd0) = bl;
  SLOT0(self, 0x260);
}
PCREG(461d60, fn461d60);
