// batch0102.cpp - fresh-01 batch 2 (docs/20-fresh-01.md): small wrappers, loaders and savers from slice residue 01.
#include "ff.h"

extern "C" void THISCALL ext_610100(u8 *self, u32 a);        // empty `ret 4` shared body (name map says ZRenderGC::Init)
extern "C" u32 THISCALL ext_4e5e60(u32 dbread);               // DBREAD::operator unsigned int()
extern "C" void THISCALL ext_4cd050(u8 *self);                // STATICREFTAB destructor body
extern "C" void ext_634273(void *p, u32 size);                // operator delete(void*, size) (cdecl)
extern "C" void ext_42ac56(void *dst, u32 fmt, u32 arg);      // cdecl string helper (3 args)
extern "C" void THISCALL ext_644820(u32 ragdolls);            // ZRagdollContainer::Load2()
extern "C" void *ext_634d10(void *dst, int v, u32 n);         // memset (CRT)

// 0x57ad10, ZFFSetStartZone::CopyEventDataBlock(DBREAD&): calls 0x610100(this, db) (an empty body in this build), then
// this+0x180 = (unsigned int)db.
static void THISCALL setStartZoneCopyEventDataBlock(u8 *self, u32 db) {
  ext_610100(self, db);
  *(u32 *)(self + 0x180) = ext_4e5e60(db);
}
PCREG(57ad10, setStartZoneCopyEventDataBlock);

// 0x4cd390, STATICREFTAB scalar deleting destructor: destructor body 0x4cd050, then delete(this, 0x20) when bit 0 of the
// flags is set. Returns this.
static u8 *THISCALL staticRefTabScalarDelete(u8 *self, u32 flags) {
  ext_4cd050(self);
  if (flags & 1) ext_634273(self, 0x20);
  return self;
}
PCREG(4cd390, staticRefTabScalarDelete);

// 0x54c2d0 (unnamed): if the object at this+0x50 is null, false; else its vtable slot 0x1c(float) (bool in AL).
static u8 THISCALL forward54c2d0(u8 *self, u32 f) {
  u8 *o = *(u8 **)(self + 0x50);
  if (!o) return 0;
  return vcall<u8>(o, 0x1c, f);
}
PCREG(54c2d0, forward54c2d0);

// 0x650cd0, ZRenderGC::Save(ZSaveGame*): slot 0x64 of the object at this+0xbd, then save->slot 0x78(this+0x8c dword);
// returns true.
static u8 THISCALL renderGcSave(u8 *self, u8 *save) {
  vcall<void>(*(u8 **)(self + 0xbd), 0x64);
  vcall<void>(save, 0x78, *(u32 *)(self + 0x8c));
  return 1;
}
PCREG(650cd0, renderGcSave);

// 0x4d42d0 (unnamed): 0x42ac56(this+0x1007, 0x6965c4, arg) (cdecl string helper), then own vtable slot 0x1c; returns
// what slot 0x1c returns.
static u32 THISCALL setText4d42d0(u8 *self, u32 arg) {
  ext_42ac56(self + 0x1007, 0x6965c4, arg);
  return vcall<u32>(self, 0x1c);
}
PCREG(4d42d0, setText4d42d0);

// 0x656e50, ZPrimControlGC::CopyPrimDrawMode(unsigned int dst, unsigned int src): d = slot 0xc(dst), s = slot 0xc(src)
// (prim lookup); d+0x20 = s+0x20 (dword) and d+4 = s+4 (word).
static void THISCALL primCopyDrawMode(u8 *self, u32 dst, u32 src) {
  u8 *d = vcall<u8 *>(self, 0xc, dst);
  u8 *s = vcall<u8 *>(self, 0xc, src);
  *(u32 *)(d + 0x20) = *(u32 *)(s + 0x20);
  *(u16 *)(d + 4) = *(u16 *)(s + 4);
}
PCREG(656e50, primCopyDrawMode);

// 0x427210, ZSysFileGC::GetFileTime(const char*, _FILETIME*, bool): calls own slot 0x20(name, &local, flag) and
// returns the 64-bit local FILETIME when it returns true, else 0. (The second argument is not used.)
static u64 THISCALL sysFileGetFileTime(u8 *self, u32 name, u32 flag) {
  u64 t;
  if (vcall<u8>(self, 0x20, name, (u64 *)&t, flag)) return t;
  return 0;
}
PCREG(427210, sysFileGetFileTime);

// 0x64ff10, ZRenderBaseDll::Load2(ZLoadGame*): ragdoll container (this+0x38) Load2; load->slot 0xc(0x13);
// then engine([0x70039c])+0x190f object slot 0x1b0(load); returns that call's EAX.
static u32 THISCALL renderBaseLoad2(u8 *self, u8 *load) {
  ext_644820(*(u32 *)(self + 0x38));
  vcall<void>(load, 0xc, 0x13u);
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
  return vcall<u32>(o, 0x1b0, load);
}
PCREG(64ff10, renderBaseLoad2);

// 0x634994, __scrt_get_show_window_mode (CRT): zeroes a STARTUPINFOW (0x44 bytes), GetStartupInfoW, and returns
// wShowWindow when STARTF_USESHOWWINDOW (bit 0 of dwFlags) is set, else SW_SHOWDEFAULT (10).
typedef void(STDCALL *getStartupInfoFn)(void *);
static u32 scrtGetShowWindowMode() {
  u8 si[0x44];
  ext_634d10(si, 0, 0x44);
  (*(getStartupInfoFn *)0x676050)(si);
  if (si[0x2c] & 1) return *(u16 *)(si + 0x30);
  return 10;
}
PCREG(634994, scrtGetShowWindowMode);

// 0x65c990 (unnamed): ring of 0x80 dwords at this+0x200 with count at this+0x414: store, count++, and clamp the count
// to 0x7f once it reaches 0x80 (signed compare).
static void THISCALL push65c990(u8 *self, u32 v) {
  s32 n = *(s32 *)(self + 0x414);
  *(u32 *)(self + n * 4 + 0x200) = v;
  n = ++*(s32 *)(self + 0x414);
  if (n >= 0x80) *(s32 *)(self + 0x414) = 0x7f;
}
PCREG(65c990, push65c990);

// 0x4bb2d0, ZSoundNotify::Load(ZLoadGame*): clears bit 0x40 of this+4, then load slots 0x40(this+0x48),
// 0x44(this+0x4c), 0x50(this+0x4e); returns true.
static u8 THISCALL soundNotifyLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(load, 0x40, self + 0x48);
  vcall<void>(load, 0x44, self + 0x4c);
  vcall<void>(load, 0x50, self + 0x4e);
  return 1;
}
PCREG(4bb2d0, soundNotifyLoad);

// 0x5f17d0, ZScriptDll::DumpCurrentScriptCallStack(int): o = [0x700390] slot 0x20(0x6b8738, 0x2b9); then o's slot 0x2c
// called cdecl with (o, 0x69c6b0, 0x6b88c8) (a printf-style log); then the handler at [0x7003b0] is called when set,
// else int3. The int argument is not used.
typedef u32(THISCALL *s20Fn)(void *, u32, u32);
typedef void (*logFn)(void *, u32, u32);
typedef void (*handlerFn)();
static void STDCALL scriptDumpCallStack(u32 unused) {
  u8 *mgr = G(u8 *, 0x700390);
  u8 *o = (u8 *)(*(s20Fn *)(*(u8 **)mgr + 0x20))(mgr, 0x6b8738, 0x2b9);
  (*(logFn *)(*(u8 **)o + 0x2c))(o, 0x69c6b0, 0x6b88c8);
  handlerFn h = G(handlerFn, 0x7003b0);
  if (h) { h(); return; }
  __builtin_debugtrap();
}
PCREG(5f17d0, scriptDumpCallStack);
