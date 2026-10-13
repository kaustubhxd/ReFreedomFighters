// fb0303.cpp - fresh slice 17, batch 3.
#include "ff.h"

extern "C" u32 THISCALL ext_613c20(u8 *self);
extern "C" u32 THISCALL ext_613ae0(void *block);
extern "C" u32 THISCALL ext_564460(u8 *self);
extern "C" u32 THISCALL ext_561cb0(u8 *self, u32 cmd, void *data);
extern "C" u32 THISCALL ext_4cc1d0(u8 *self);
extern "C" u32 THISCALL ext_43e0f0(u8 *self);

typedef void (*logfn)(void *, const char *, ...);
typedef u32 (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

// 0x427e50 ZSysFileGC::OpenForRandomAccess(char*): CreateFileA(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING,
// FILE_FLAG_RANDOM_ACCESS | FILE_ATTRIBUTE_NORMAL, 0). On INVALID_HANDLE_VALUE logs (file 0x6789ac, line 0x3d, text
// 0x6789f8, name) and returns 0; otherwise the handle.
typedef u32(STDCALL *createfile_t)(const char *, u32, u32, void *, u32, u32, u32);
static u32 THISCALL openForRandomAccess427e50(u8 *, const char *name) {
  u32 h = (*(createfile_t *)0x676068)(name, 0x80000000u, 1, 0, 3, 0x10000080u, 0);
  if (h != 0xffffffffu)
    return h;
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x6789acu, 0x3du);
  (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x6789f8, name);
  return 0;
}
PCREG(427e50, openForRandomAccess427e50);

// 0x6139d0 ZDrawArray<ZPrimDrawEntryGC, ZPrimDrawEntry, ZArrayBlock>::Add(): walks the circular block list from this+8
// (next at block+8) for a block whose free-head word (+2) is not 0xffff, moving this+8 along; when it wraps or hits null,
// 0x613c20(this) adds a block (false -> return 0). Counts this+0xc and tail-calls 0x613ae0(block).
static u32 THISCALL drawArrayAdd6139d0(u8 *self) {
  u8 *start = *(u8 **)(self + 8);
  if (start) {
    u8 *b = start;
    for (;;) {
      if (*(u16 *)(b + 2) != 0xffff) {
        *(u32 *)(self + 0xc) += 1;
        return ext_613ae0(b);
      }
      b = *(u8 **)(b + 8);
      *(u8 **)(self + 8) = b;
      if (start == b || !b)
        break;
    }
  }
  if (!(u8)ext_613c20(self))
    return 0;
  *(u32 *)(self + 0xc) += 1;
  return ext_613ae0(*(void **)(self + 8));
}
PCREG(6139d0, drawArrayAdd6139d0);

// 0x56b2d0 (GUESS constructor of a CFileWindow-derived dialog): base ctor 0x564460, vtables 0x6a7930 / 0x6a7a3c (second
// base at +0x180), fields +0xce2 = +0xce6 = 0, +0xc9e = +0xcee = 1. Returns this.
static u8 *THISCALL ctor56b2d0(u8 *self) {
  ext_564460(self);
  *(u32 *)self = 0x6a7930;
  *(u32 *)(self + 0x180) = 0x6a7a3c;
  *(u32 *)(self + 0xce2) = 0;
  *(u32 *)(self + 0xce6) = 0;
  *(u32 *)(self + 0xc9e) = 1;
  *(u32 *)(self + 0xcee) = 1;
  return self;
}
PCREG(56b2d0, ctor56b2d0);

// 0x56ca90 CMultiplayerKOTH::Command(unsigned short, void*): id = RegisterZMsg on the engine's +0x9b object (slot +0x114,
// 4 words: name 0x6a6ffc, 0, file 0x6a8040, line 0x163). Matching command: this+0x1be = *(u32*)data, returns 1. Otherwise
// CFileWindow::Command(this, cmd, data) (the full argument dword is passed on).
static u32 THISCALL command56ca90(u8 *self, u32 cmd, u32 *data) {
  void *db = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  u32 id = vcall<u32>(db, 0x114, 0x6a6ffcu, 0u, 0x6a8040u, 0x163u);
  if ((u16)cmd == (u16)id) {
    *(u32 *)(self + 0x1be) = *data;
    return 1;
  }
  return ext_561cb0(self, cmd, data);
}
PCREG(56ca90, command56ca90);

// 0x499f50 ZSaveGame::AddRefTabRaw(LINKSORTREFTAB*): writes the count (tab slot +0x14) with this slot +0xc, then iterates
// the table (slot +0x4c starts a 12-byte iterator, slot +0x5c returns the next value) and writes each value while the
// iterator's first word is non-zero.
static void THISCALL addRefTabRaw499f50(u8 *self, void *tab) {
  u32 it[3];
  vcall<u32>(self, 0x0c, vcall<u32>(tab, 0x14));
  vcall<u32>(tab, 0x4c, (void *)it);
  u32 v = vcall<u32>(tab, 0x5c, (void *)it);
  while (it[0] != 0) {
    vcall<u32>(self, 0x0c, v);
    v = vcall<u32>(tab, 0x5c, (void *)it);
  }
}
PCREG(499f50, addRefTabRaw499f50);

// 0x422f90 ZSysInterfaceGC::ReloadDLLs(): slot +0x1d0(*0x7003a4); engine db (+0x9b) slot +0x16c(); when the object at
// 0x7003a4 exists: its slot +0x10(), then this slot +0x4c(it) and the global is cleared. 0x4cc1d0(this+0x1f91), then
// tail-calls the assert hook at 0x7003b0 (int3 when none).
static u32 THISCALL reloadDLLs422f90(u8 *self) {
  vcall<u32>(self, 0x1d0, G(u32, 0x7003a4));
  vcall<u32>(*(void **)(self + 0x9b), 0x16c);
  void *g = G(void *, 0x7003a4);
  if (g) {
    vcall<u32>(g, 0x10);
    vcall<u32>(self, 0x4c, G(u32, 0x7003a4));
    G(u32, 0x7003a4) = 0;
  }
  ext_4cc1d0(self + 0x1f91);
  if (!g_pAssertHook)
    __builtin_debugtrap();
  return g_pAssertHook();
}
PCREG(422f90, reloadDLLs422f90);

// 0x45b9d0 ZBulletMarks::ClassInit(): r = db->slot +0x138(); s = db->slot +0x4c(this) (GeomBasePtrToRef-style, ret 4);
// r->slot +0x60(0x684c5c, s, 4) through r's vtable as read before the +0x4c call (the 4 is pushed before the +0x4c call:
// MSVC shared the stack word); this slot +0x110(0x10, 0); ZSTDOBJ::ClassInit(); tail this slot +0x214().
// db is the engine's +0x9b object, re-read from 0x70039c for each call. (Corrected in batch 9: the first version
// passed (this, 4) to slot +0x4c, which the harness could not tell apart.)
static u32 THISCALL classInit45b9d0(u8 *self) {
  void *r = (void *)vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
  u8 *rvt = *(u8 **)r;
  u32 s = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, self);
  typedef u32(THISCALL * f3)(void *, u32, u32, u32);
  (*(f3 *)(rvt + 0x60))(r, 0x684c5cu, s, 4u);
  vcall<u32>(self, 0x110, 0x10u, 0u);
  ext_43e0f0(self);
  return vcall<u32>(self, 0x214);
}
PCREG(45b9d0, classInit45b9d0);
