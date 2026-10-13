// fb0909.cpp - fresh slice 17, batch 9.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                                         // __builtin_new
extern "C" u32 THISCALL ext_600f20(void *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_5f4630(void *vec);                                 // grow
extern "C" u32 THISCALL ext_5193c0(void *self, void *owner);
extern "C" u32 THISCALL ext_51ace0(void *self);
extern "C" u32 THISCALL ext_51f170(void *self);
extern "C" u32 THISCALL ext_64f6a0(u8 *self, void *cam);                       // ZRender::AddCameraToView
extern "C" u32 THISCALL ext_433ec0(void *self);
extern "C" u32 THISCALL ext_4cca60(void *self, u32 a, u32 b);                  // LINKREFTAB::LINKREFTAB(int, int)
extern "C" void *ext_45c4f0(u32 size, u32 arg);
extern "C" void *ext_45c4b0(u32 size);
extern "C" u32 THISCALL ext_43e190(void *self, u32 info, u32 name, u32 geom); // ZHELPER::ZHELPER

typedef void (*logfn)(void *, const char *, ...);

// 0x602090 CSdlDataExchange::setExportSymbol(const char*, void*, const char*): a 4-byte symbol object (0x600f20 builds it
// from the three arguments; null allocation -> 0) is appended to the pointer vector at this+4 (count +0xc, capacity +8,
// 0x5f4630 grows it). SEH frame not reproduced.
static void THISCALL setExportSymbol602090(u8 *self, u32 name, u32 ptr, u32 type) {
  void *p = ext_41e290(4);
  u32 e = p ? ext_600f20(p, name, ptr, type) : 0;
  if (*(u32 *)(self + 0xc) >= *(u32 *)(self + 8))
    ext_5f4630(self + 4);
  (*(u32 **)(self + 4))[*(u32 *)(self + 0xc)] = e;
  *(u32 *)(self + 0xc) += 1;
}
PCREG(602090, setExportSymbol602090);

// 0x51add0 / 0x51f290 (GUESS factories of 0x1c-byte objects owned by `this`): base ctor 0x5193c0(p, this), vtable,
// +0x18 = this; when the global (0x701730 / 0x7018d8) is still 0, 0x51ace0 / 0x51f170 runs on the new object.
// Returns the object (0 when the allocation fails). SEH frame not reproduced.
static u8 *THISCALL create51add0(u8 *self) {
  u8 *p = (u8 *)ext_41e290(0x1c);
  if (!p)
    return 0;
  ext_5193c0(p, self);
  *(u32 *)p = 0x69f364;
  *(u8 **)(p + 0x18) = self;
  if (G(u32, 0x701730) == 0)
    ext_51ace0(p);
  return p;
}
PCREG(51add0, create51add0);
static u8 *THISCALL create51f290(u8 *self) {
  u8 *p = (u8 *)ext_41e290(0x1c);
  if (!p)
    return 0;
  ext_5193c0(p, self);
  *(u32 *)p = 0x69fa64;
  *(u8 **)(p + 0x18) = self;
  if (G(u32, 0x7018d8) == 0)
    ext_51f170(p);
  return p;
}
PCREG(51f290, create51f290);

// 0x42f290 ZSysInterface::ReadIniFileToMem(char* buf, const char* name): size = fs(0x700394)->slot +0x30(name, 0); size < 1
// -> logs 0x679e00 (log object slot +0x34, cdecl) and false. Reads with fs->slot +0x60(name, buf, size, 0, 0); a short read
// logs (0x6799ac line 0x396, text 0x679e14) and returns false; else buf[size] = 0 and true.
static u32 THISCALL readIniFileToMem42f290(u8 *, char *buf, const char *name) {
  void *fs = G(void *, 0x700394);
  s32 size = vcall<s32>(fs, 0x30, name, 0u);
  if (size < 1) {
    void *log = G(void *, 0x700390);
    (*(logfn *)(*(u8 **)log + 0x34))(log, (const char *)0x679e00, name);
    return 0;
  }
  if (vcall<s32>(G(void *, 0x700394), 0x60, name, buf, size, 0u, 0u) != size) {
    void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x6799acu, 0x396u);
    (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x679e14, name);
    return 0;
  }
  buf[size] = 0;
  return 1;
}
PCREG(42f290, readIniFileToMem42f290);

// 0x64f610 ZRender::AddCamera(ZCAMERA*, float): ref = db->slot +0x4c(cam) (ret 4). Unless the camera list (this+0x8c)
// already has it (slot +0x28(ref)), adds it with slot +0x98(ref, f, 0), notifies this slot +0xb0(cam) and, when the
// current view (this+0xbd) is active (byte +5), AddCameraToView(cam). Each list call goes through the vtable read before
// the db call.
static void THISCALL addCamera64f610(u8 *self, void *cam, float f) {
  u8 *vt = **(u8 ***)(self + 0x8c);
  u32 ref = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, cam);
  typedef u32(THISCALL * f1)(void *, u32);
  if ((*(f1 *)(vt + 0x28))(*(void **)(self + 0x8c), ref))
    return;
  vt = **(u8 ***)(self + 0x8c);
  ref = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, cam);
  typedef u32(THISCALL * f3)(void *, u32, float, u32);
  (*(f3 *)(vt + 0x98))(*(void **)(self + 0x8c), ref, f, 0);
  vcall<u32>(self, 0xb0, cam);
  u8 *view = *(u8 **)(self + 0xbd);
  if (view && view[5])
    ext_64f6a0(self, cam);
}
PCREG(64f610, addCamera64f610);

// 0x5f2b90 ZScriptDll::UpdateMsgToEventId(): the first time (count +0x1010 == 0) clears the 0x800-word table at +0x10;
// then for every new message index i (count+1 .. n, n = msgs->slot +0xc(), msgs = this+0xc -> +4 -> +0x3c), registers
// the name (msgs->slot +8(i)) as a ZMsg (RegisterZMsg, 0x6b8738 line 0x2f5) and stores table[id] = i. count = n.
static void THISCALL updateMsgToEventId5f2b90(u8 *self) {
  if (*(u32 *)(self + 0x1010) == 0) {
    u32 *d = (u32 *)(self + 0x10);
    u32 n = 0x400, z = 0;
    asm volatile("rep stosl" : "+D"(d), "+c"(n) : "a"(z) : "memory");
  }
  void *msgs = *(void **)(*(u8 **)(*(u8 **)(self + 0xc) + 4) + 0x3c);
  u32 n = vcall<u32>(msgs, 0x0c);
  for (u32 i = *(u32 *)(self + 0x1010) + 1; i <= n; i++) {
    u32 w = (u16)i;
    void *m = *(void **)(*(u8 **)(*(u8 **)(self + 0xc) + 4) + 0x3c);
    u32 name = vcall<u32>(m, 0x08, w);
    u16 id = (u16)vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x114, name, 0u, 0x6b8738u, 0x2f5u);
    ((u16 *)(self + 0x10))[id] = (u16)w;
  }
  *(u32 *)(self + 0x1010) = n;
}
PCREG(5f2b90, updateMsgToEventId5f2b90);

// 0x426410 (GUESS ZSysFileGC constructor): base 0x433ec0, vtable 0x678864, +0x10c = new LINKREFTAB(0x20, 4) (0 when the
// allocation fails), registers itself as the file system (0x700394), +0x110 = +0x114 = 0. SEH frame not reproduced.
static u8 *THISCALL ctor426410(u8 *self) {
  ext_433ec0(self);
  *(u32 *)self = 0x678864;
  void *p = ext_41e290(0x28);
  u32 t = p ? ext_4cca60(p, 0x20, 4) : 0;
  *(u32 *)(self + 0x10c) = t;
  G(u8 *, 0x700394) = self;
  *(u32 *)(self + 0x110) = 0;
  *(u32 *)(self + 0x114) = 0;
  return self;
}
PCREG(426410, ctor426410);

// 0x43e290 (GUESS ZHELPER factory, fastcall (info, name) + stack (geom, pool)): 0x48 bytes from 0x45c4f0(0x48, pool) or,
// without a pool, 0x45c4b0(0x48); null -> 0; else ZHELPER::ZHELPER(p, geom, info, name). SEH frame not reproduced.
static u32 FASTCALL createHelper43e290(u32 info, u32 name, u32 geom, u32 pool) {
  void *p = pool ? ext_45c4f0(0x48, pool) : ext_45c4b0(0x48);
  if (!p)
    return 0;
  return ext_43e190(p, geom, info, name);
}
PCREG(43e290, createHelper43e290);
