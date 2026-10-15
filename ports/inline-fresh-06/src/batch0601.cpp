// batch0601.cpp - fresh-06 batch 1 (docs/20-fresh-06.md): small leaves and one-call wrappers.
// Names are from the GC name map (naming only; GUESS where there is no map entry). Bodies follow the PC bytes.
#include "ff.h"

// 0x65c9e0 (no map name; GUESS: pointer iterator post-increment by 8): returns the dword at this+4, then adds 8 to it.
static u32 THISCALL iterPostInc8(u8 *self) {
  u32 v = *(u32 *)(self + 4);
  *(u32 *)(self + 4) = v + 8;
  return v;
}
PCREG(65c9e0, iterPostInc8);

// 0x5f1460, SaveSerialInfo_t scalar deleting destructor: SerialInfo_t::~SerialInfo_t (0x602240) on this, then when
// bit 0 of the flags is set, __builtin_delete(this, 0x19) (0x634273, cdecl). Returns this.
extern "C" void THISCALL ext_602240(void *self);
extern "C" void ext_634273(void *p, u32 size);
static void *THISCALL saveSerialInfoDelDtor(u8 *self, u32 flags) {
  ext_602240(self);
  if (flags & 1) ext_634273(self, 0x19);
  return self;
}
PCREG(5f1460, saveSerialInfoDelDtor);

// 0x5f0420, CModeControl_IngameOptions::Update(): the engine object (0x70039c) holds an object at +0x1907; its vtable
// slot 0x2c is called with (this+0xc dword, 0). When it returns true (AL), Activate() (0x5f0380) runs as a tail call.
extern "C" void THISCALL ext_5f0380(void *self);
static void THISCALL ingameOptionsUpdate(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  void *o = *(void **)(eng + 0x1907);
  if (vcall<u8>(o, 0x2c, *(u32 *)(self + 0xc), 0u)) ext_5f0380(self);
}
PCREG(5f0420, ingameOptionsUpdate);

// 0x4f8c20, ZEditControl::CopyData(const ZGEOM*): ZCONTROL::CopyData (0x4f9c60) first, then the dwords at +0x1c3 and
// +0x1c7 are copied from the source.
extern "C" void THISCALL ext_4f9c60(void *self, const void *src);
static void THISCALL editControlCopyData(u8 *self, const u8 *src) {
  ext_4f9c60(self, src);
  *(u32 *)(self + 0x1c3) = *(const u32 *)(src + 0x1c3);
  *(u32 *)(self + 0x1c7) = *(const u32 *)(src + 0x1c7);
}
PCREG(4f8c20, editControlCopyData);

// 0x4d5c20, FsZip_t::Exists(const char*): findFile (0x4d6520) with a local 0x1c-byte IOZip_LocalFileHeader_t and a
// null offset pointer; returns findFile's EAX. (The /GS cookie check of the original has no visible effect.)
extern "C" u32 THISCALL ext_4d6520(void *self, const char *name, void *hdr, s32 *off);
static u32 THISCALL fsZipExists(void *self, const char *name) {
  u8 hdr[0x1c];
  return ext_4d6520(self, name, hdr, 0);
}
PCREG(4d5c20, fsZipExists);

// 0x606d60, SDLEventIds::GetEventId(const char*): the map at this+4 is searched (0x607200, thiscall, writes the found
// node to its first argument, takes a pointer to the key argument). Found: the word at node+8 (the upper half of EAX
// keeps the node pointer's upper half, as the original's `mov ax`). Not found: 0.
extern "C" void THISCALL ext_607200(void *map, u32 *out, const char **key);
static u32 THISCALL sdlGetEventId(u8 *self, const char *name) {
  u32 res[2];
  ext_607200(self + 4, res, &name);
  u32 node = res[0];
  if (!node) return 0;
  u32 r = node;
  // `mov ax, [eax+8]`: only the low word of EAX changes (clang -O2 folded a C++ form of this to movzwl).
  asm("movw 8(%1), %w0" : "+r"(r) : "r"(node) : "memory");
  return r;
}
PCREG(606d60, sdlGetEventId);

// 0x42d3e0, ZSysInterface::HandleNormalToken(string&, string*&): the token (*pp, begin/end at +0/+4) is appended to the
// string (0x5f2c60); then *pp moves on by 0xc unless it equals the end pointer at [this+0x1b6d]+4.
extern "C" void THISCALL ext_5f2c60(void *str, const char *b, const char *e);
static void THISCALL sysHandleNormalToken(u8 *self, void *str, u8 **pp) {
  ext_5f2c60(str, *(const char **)(*pp), *(const char **)(*pp + 4));
  u8 *lst = *(u8 **)(self + 0x1b6d);
  if (*pp != *(u8 **)(lst + 4)) *pp += 0xc;
}
PCREG(42d3e0, sysHandleNormalToken);

// 0x656360 (no map name; GUESS: free an array of 24-byte elements, stdcall (ptr, count)): when count*24 != 0, the
// engine object's +0x190f object's slot 0x20 gives an allocator whose slot 0x18 gets (ptr, count*24).
static void STDCALL freeArray24(void *p, u32 n) {
  u32 sz = n * 24;
  if (!sz) return;
  u8 *eng = G(u8 *, 0x70039c);
  void *o = *(void **)(eng + 0x190f);
  void *al = vcall<void *>(o, 0x20);
  vcall<void>(al, 0x18, p, sz);
}
PCREG(656360, freeArray24);
