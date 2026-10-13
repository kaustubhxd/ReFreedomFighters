// batch13015.cpp - fresh slice 13, batch 15 (docs/20-fresh-13.md), 2026-10-12.
// 0x4fe410 CNewDialogCamera::Command(unsigned short, void*) (name map medium): thiscall, ret 8, returns 0 always.
// The command id is compared against six u16 message ids stored in the object (packed layout):
//  +0x4d: *(float*)data = camera on (+0x67) ? 6000.0f : 0 (stored as bits 0 then 0x45bb8000).
//  +0x51: copy the two actor ids data[0], data[1] to +0x5f / +0x63 (and +0x5f to +0x70); look both up in the engine
//         db (slot 0x58); when both exist and both answer vtbl[+0x1e0](0x200027): +0x67 = 1, find the object of class
//         string 0x688f80 under db[+0x138]() (0x48aad0, run as exe code), and send it message u16 +0x5b through the
//         +0x44 object's slot 0x12c (target, msg, db[+0x4c](+0x44 object)). Then CalcCameraPoses 0x4fefe0 and
//         this->vtbl[+0x3c]() in every case.
//  +0x55: swap +0x5f and +0x63.
//  +0x53: +0x67 = 0; db[+0x138]()->vtbl[+0x88](0x688f80, &target) (the find inlined) and the same send with +0x5d.
//  +0x57 / +0x59: +0xe4 = data (only +0x57), +0x48 = 1 / 0; find class 0x68be98; when found, RegisterZMsg (db slot
//         0x114: name 0x692308 / 0x6923d8, 0, file 0x69c624, line 0xa6 / 0xb2) and send (target, (u16)id, 0) - the 0 is
//         the fifth word pushed before RegisterZMsg (MSVC stack-word sharing); then sys+0x1907 object slot 0x74 / 0x70
//         with 0x69c690; this->vtbl[+0x3c]() only for +0x57.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_48aad0[], ext_4fefe0[];
typedef u32(THISCALL *Find)(u32 *q);
typedef void(THISCALL *P0)(void *self);
typedef u32(THISCALL *R0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef u8(THISCALL *B1)(void *self, u32 a);
typedef void(THISCALL *P2)(void *self, u32 a, u32 *b);
typedef void(THISCALL *Send)(void *self, u32 target, u32 msg, u32 data);
typedef u16(THISCALL *Reg)(void *self, u32 name, u32 z, u32 file, u32 line);

static inline u8 *db() { return AT(u8 *, G(u8 *, 0x70039c), 0x9b); }

static u32 find(u32 cls) {
  u32 q[2];
  q[0] = ((R0)VT(db(), 0x138))(db());
  q[1] = cls;
  return ((Find)(void *)ext_48aad0)(q);
}

static void open_close(u8 *self, u32 name, u32 line) {
  u32 t = find(0x68be98);
  if (t) {
    u8 *o = AT(u8 *, self, 0x44);
    u16 id = ((Reg)VT(db(), 0x114))(db(), name, 0, 0x69c624, line);
    ((Send)VT(o, 0x12c))(o, t, id, 0);
  }
}

static u32 THISCALL fn4fe410(u8 *self, u32 cmdw, u32 *data) {
  u16 cmd = (u16)cmdw;  // only the low word is read (mov ax, [ebp+8])
  if (cmd == AT(u16, self, 0x4d)) {
    data[0] = 0;
    if (AT(u8, self, 0x67))
      data[0] = 0x45bb8000;
    return 0;
  }
  if (cmd == AT(u16, self, 0x51)) {
    AT(u32, self, 0x5f) = data[0];
    AT(u32, self, 0x63) = data[1];
    u8 *a = (u8 *)((R1)VT(db(), 0x58))(db(), AT(u32, self, 0x5f));
    u8 *b = (u8 *)((R1)VT(db(), 0x58))(db(), AT(u32, self, 0x63));
    AT(u32, self, 0x70) = AT(u32, self, 0x5f);
    if (a && b && ((B1)VT(a, 0x1e0))(a, 0x200027) && ((B1)VT(b, 0x1e0))(b, 0x200027)) {
      AT(u8, self, 0x67) = 1;
      u32 t = find(0x688f80);
      u8 *o = AT(u8 *, self, 0x44);
      u32 d = ((R1)VT(db(), 0x4c))(db(), (u32)o);
      ((Send)VT(o, 0x12c))(AT(u8 *, self, 0x44), t, AT(u16, self, 0x5b), d);
    }
    ((P0)(void *)ext_4fefe0)(self);
    ((P0)VT(self, 0x3c))(self);
    return 0;
  }
  if (cmd == AT(u16, self, 0x55)) {
    u32 x = AT(u32, self, 0x5f);
    AT(u32, self, 0x5f) = AT(u32, self, 0x63);
    AT(u32, self, 0x63) = x;
    return 0;
  }
  if (cmd == AT(u16, self, 0x53)) {
    AT(u8, self, 0x67) = 0;
    u8 *x = (u8 *)((R0)VT(db(), 0x138))(db());
    u32 t = 0;
    ((P2)VT(x, 0x88))(x, 0x688f80, &t);
    u8 *o = AT(u8 *, self, 0x44);
    u32 d = ((R1)VT(db(), 0x4c))(db(), (u32)o);
    ((Send)VT(o, 0x12c))(AT(u8 *, self, 0x44), t, AT(u16, self, 0x5d), d);
    return 0;
  }
  if (cmd == AT(u16, self, 0x57)) {
    AT(u32, self, 0xe4) = (u32)data;
    AT(u8, self, 0x48) = 1;
    open_close(self, 0x692308, 0xa6);
    u8 *m = AT(u8 *, G(u8 *, 0x70039c), 0x1907);
    ((R1)VT(m, 0x74))(m, 0x69c690);
    ((P0)VT(self, 0x3c))(self);
    return 0;
  }
  if (cmd == AT(u16, self, 0x59)) {
    AT(u8, self, 0x48) = 0;
    open_close(self, 0x6923d8, 0xb2);
    u8 *m = AT(u8 *, G(u8 *, 0x70039c), 0x1907);
    ((R1)VT(m, 0x70))(m, 0x69c690);
  }
  return 0;
}
PCREG(4fe410, fn4fe410);
