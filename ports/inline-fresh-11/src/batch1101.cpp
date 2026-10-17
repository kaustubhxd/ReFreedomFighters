// batch1101.cpp - fresh-11 batch 1: smallest slice-11 functions (getters, wrappers, deleting dtors).
// Names from the GC name map ([confidence]); GUESS where it has none. Exe callees stay as ext_<hex> (hooked in the spec).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // __builtin_delete (sized), cdecl

// 0x606db0 SDLEventIds::GetSize() [low]
static u32 THISCALL SDLEventIds_GetSize(u8 *self) { return *(u32 *)(self + 0x2f); }
PCREG(606db0, SDLEventIds_GetSize);

// 0x626a70 GUESS: returns the address of the global at 0x6be898.
static u32 Get6be898() { return 0x6be898; }
PCREG(626a70, Get6be898);

// 0x63db30 ZDrawArray<ZTextureViewEntry,...>::EntrySize() const [low]
static u32 THISCALL TexViewEntrySize(u8 *) { return 0x10; }
PCREG(63db30, TexViewEntrySize);

// 0x64c770 ZDrawArray<ZRoomViewEntry,...>::GetNrEntriesPerBlock() const [low]
static u32 THISCALL RoomViewEntriesPerBlock(u8 *) { return 0x71; }
PCREG(64c770, RoomViewEntriesPerBlock);

// 0x64fbf0 ZRender::GetLetterSizeY() const [high]: this+0xb9 * [0x685280], x87 (float*float is exact in 53 bits).
static long double THISCALL GetLetterSizeY(u8 *self) {
  return (long double)*(float *)(self + 0xb9) * (long double)G(float, 0x685280);
}
PCREG(64fbf0, GetLetterSizeY);

// 0x4cb4f0 ZViewNotifyCheckBox::Load(ZLoadGame*) [high]: clear flag 0x40, load slot +0x48 into this+0x4c, true.
static bool THISCALL ViewNotifyCheckBox_Load(u8 *self, void *ld) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(ld, 0x48, self + 0x4c);
  return true;
}
PCREG(4cb4f0, ViewNotifyCheckBox_Load);

// 0x65c030 ZViewGC::BeginCamera(ZCameraViewEntry*) [medium]: base BeginCamera, then cam->vt[0](this).
extern "C" void THISCALL ext_6493d0(void *self, void *cam);
static u32 THISCALL ViewGC_BeginCamera(u8 *self, void *cam) {
  ext_6493d0(self, cam);
  return vcall<u32>(cam, 0, self);
}
PCREG(65c030, ViewGC_BeginCamera);

// 0x4d8bf0 CConsoleCommandList::Find(const char*) [medium]: list at this+4, slot +0x84; result+4 or 0.
static u32 THISCALL ConsoleCommandList_Find(u8 *self, const char *name) {
  u32 r = vcall<u32>(*(void **)(self + 4), 0x84, name);
  return r ? r + 4 : 0;
}
PCREG(4d8bf0, ConsoleCommandList_Find);

// 0x4c31b0 ZWindElement::Command(unsigned short, void*) [high]: on 0x401, UpdateWindElement([this+0x44]+8).
extern "C" void THISCALL ext_4c3740(void *ctl, u32 geom);
static u32 THISCALL WindElement_Command(u8 *self, u32 cmd, void *) {
  if ((u16)cmd == 0x401) ext_4c3740(*(void **)(self + 0x4c), *(u32 *)(*(u8 **)(self + 0x44) + 8));
  return 0;
}
PCREG(4c31b0, WindElement_Command);

// 0x636470 GUESS scalar deleting dtor: body 0x6363a0, delete(this, 0x2d) when flag bit 0.
extern "C" void THISCALL ext_6363a0(void *self);
static u8 *THISCALL DelDtor636470(u8 *self, u32 flags) {
  ext_6363a0(self);
  if (flags & 1) ext_634273(self, 0x2d);
  return self;
}
PCREG(636470, DelDtor636470);

// 0x5f9570 GUESS size: [this+8] - [this+4] + 5 + size(this+0x10) + size(this+0x2c) (0x605b90 each).
extern "C" u32 THISCALL ext_605b90(void *self);
static u32 THISCALL Size5f9570(u8 *self) {
  u32 n = *(u32 *)(self + 8) - *(u32 *)(self + 4) + 5;
  n += ext_605b90(self + 0x10);
  return ext_605b90(self + 0x2c) + n;
}
PCREG(5f9570, Size5f9570);

// 0x6392b0 GUESS: slot +0x58(d, b*c*4, b, c, a, 1).
static u32 THISCALL Fwd6392b0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  return vcall<u32>(self, 0x58, d, b * c * 4, b, c, a, 1u);
}
PCREG(6392b0, Fwd6392b0);

// 0x5493f0 GUESS scalar deleting dtor: vtable 0x6a3298, delete(this, 0x2326).
static u8 *THISCALL DelDtor5493f0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a3298;
  if (flags & 1) ext_634273(self, 0x2326);
  return self;
}
PCREG(5493f0, DelDtor5493f0);

// 0x54cd70 ZSynth::~ZSynth() [medium] (scalar deleting): vtable 0x6a3e14, delete(this, 0xa269).
static u8 *THISCALL ZSynth_DelDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a3e14;
  if (flags & 1) ext_634273(self, 0xa269);
  return self;
}
PCREG(54cd70, ZSynth_DelDtor);

// 0x5fef70 GUESS remove: 0x5fe560(p), free(p+0x9e) through 0x41e2c0 (cdecl), count at this+4 down by one.
extern "C" void THISCALL ext_5fe560(void *self, void *p);
extern "C" u32 ext_41e2c0(u32 a);
static u32 THISCALL Remove5fef70(u8 *self, u8 *p) {
  ext_5fe560(self, p);
  u32 r = ext_41e2c0(*(u32 *)(p + 0x9e));
  *(u32 *)(self + 4) -= 1;
  return r;
}
PCREG(5fef70, Remove5fef70);

// 0x6568b0 ZPrimControlBase::GetTextureFromPrim(unsigned int) [high]: prim = slot +0xc(i); tail call
// slot +0x80(prim->word +4) of the object at [[0x70039c]+0x1aa3].
static u32 THISCALL GetTextureFromPrim(u8 *self, u32 i) {
  u8 *prim = vcall<u8 *>(self, 0xc, i);
  void *o = *(void **)(G(u8 *, 0x70039c) + 0x1aa3);
  return vcall<u32>(o, 0x80, (u32) * (u16 *)(prim + 4));
}
PCREG(6568b0, GetTextureFromPrim);

// 0x55ffb0 GUESS: flag byte +0x5c of [[0x7003b8]+0x2c21] = (*0x5003d0(arg+4 list, 0) != 0). ECX unused, ret 4.
extern "C" u32 *THISCALL ext_5003d0(void *arr, u32 i);
static u32 STDCALL SetFlag55ffb0(u8 *p) {
  u32 *e = ext_5003d0(*(void **)(p + 4), 0);
  bool nz = *e != 0;
  u8 *o = *(u8 **)(G(u8 *, 0x7003b8) + 0x2c21);
  o[0x5c] = nz;
  return (u32)o;
}
PCREG(55ffb0, SetFlag55ffb0);

// 0x607cb0 GUESS scalar deleting dtor: vtable 0x6b9fc4, body 0x656e10, delete(this, 4).
extern "C" void THISCALL ext_656e10(void *self);
static u8 *THISCALL DelDtor607cb0(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b9fc4;
  ext_656e10(self);
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(607cb0, DelDtor607cb0);

// 0x4286b0 GUESS scalar deleting dtor: vtable 0x678df4, body 0x435b50, delete(this, 0xb2).
extern "C" void THISCALL ext_435b50(void *self);
static u8 *THISCALL DelDtor4286b0(u8 *self, u32 flags) {
  *(u32 *)self = 0x678df4;
  ext_435b50(self);
  if (flags & 1) ext_634273(self, 0xb2);
  return self;
}
PCREG(4286b0, DelDtor4286b0);

// 0x65ca30 GUESS buffer set: +0x400 = p, +0x410 = 0, +0x41c = p+4, +0x420 = p+n.
static u32 THISCALL SetBuf65ca30(u8 *self, u32 p, u32 n) {
  *(u32 *)(self + 0x400) = p;
  *(u32 *)(self + 0x410) = 0;
  *(u32 *)(self + 0x41c) = p + 4;
  *(u32 *)(self + 0x420) = n + p;
  return n + p;
}
PCREG(65ca30, SetBuf65ca30);

// 0x4c5870 ZHideGroupObjects::Init(ZGROUP*, DBREAD&) [high]: hide every geom of the group (first = g+8,
// next = g->vt[0x50](&cur)).
extern "C" void THISCALL ext_4db860(void *geom, u32 hide);
static u32 THISCALL HideGroupObjects_Init(u8 *, u8 *g, void *) {
  u32 cur = *(u32 *)(g + 8);
  while (cur) {
    ext_4db860((void *)cur, 1);
    vcall<void>(g, 0x50, &cur);
  }
  return cur;
}
PCREG(4c5870, HideGroupObjects_Init);
