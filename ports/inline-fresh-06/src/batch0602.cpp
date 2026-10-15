// batch0602.cpp - fresh-06 batch 2 (docs/20-fresh-06.md): loaders, destructors, small wrappers.
// Callee pop counts are from each callee's `ret N` (tools/rets.py). Names from the GC name map (GUESS where none).
#include "ff.h"

extern "C" void THISCALL ext_4e6330(void *db, void *reftab);   // DBREAD::GetRefTab(REFTAB*)
extern "C" u32 THISCALL ext_4e5e60(void *db);                  // DBREAD::operator unsigned int()
extern "C" u16 THISCALL ext_4e5e40(void *db);                  // DBREAD::operator unsigned short()
extern "C" void THISCALL ext_610100(void *self, void *db);     // base CopyEventDataBlock / CopyDataBlock (map: ZRenderGC::Init, wrong)
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" void THISCALL ext_5002f0(void *v, u32 x);
extern "C" void THISCALL ext_500360(void *v, u32 fbits_);
extern "C" void ext_634273(void *p, u32 size);                 // __builtin_delete (cdecl)
extern "C" void *ext_634d10(void *p, int c, u32 n);            // memset (cdecl)

// 0x4b16e0, CCutSequenceMove::LoadInit(DBREAD&): the ref table at this+0x4a, then a dword to +0xf6 and a word to +0x48.
static void THISCALL cutSeqMoveLoadInit(u8 *self, void *db) {
  ext_4e6330(db, self + 0x4a);
  *(u32 *)(self + 0xf6) = ext_4e5e60(db);
  *(u16 *)(self + 0x48) = ext_4e5e40(db);
}
PCREG(4b16e0, cutSeqMoveLoadInit);

// 0x4a7960 (no map name; GUESS: constructor of a class with vtable 0x690114): base ctor 0x469870, flag 0x20 or-ed into
// +4, +0x44/+0x72/+0x76 cleared, vtable set. Returns this.
extern "C" void THISCALL ext_469870(void *self);
static void *THISCALL ctor690114(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x690114;
  *(u32 *)(self + 0x72) = 0;
  *(u32 *)(self + 0x76) = 0;
  return self;
}
PCREG(4a7960, ctor690114);

// 0x5ef520, CMessageDialog::InvalidateView(): slot 8 of the views at +0xa9, +0xa1, +0xa5, then of +0xb1 when set.
static void THISCALL msgDialogInvalidateView(u8 *self) {
  vcall<void>(*(void **)(self + 0xa9), 8);
  vcall<void>(*(void **)(self + 0xa1), 8);
  vcall<void>(*(void **)(self + 0xa5), 8);
  void *o = *(void **)(self + 0xb1);
  if (o) vcall<void>(o, 8);
}
PCREG(5ef520, msgDialogInvalidateView);

// 0x5516e0, Signature_i_EventTranslator_t::handleEventTranslation(ScriptEventFactory_t*, unsigned, void*) (stdcall,
// ECX unused): the factory's slot 0x18 makes the event for the id; when there is one, its slot 0x4c gives the argument
// array, element 0 (0x5003d0) gets the int at *data (0x5002f0). Returns the event (or 0).
static void *STDCALL evtTranslateInt(void *factory, u32 id, u32 *data) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *arr = vcall<void *>(ev, 0x4c);
  u32 v = *data;
  ext_5002f0(ext_5003d0(arr, 0), v);
  return ev;
}
PCREG(5516e0, evtTranslateInt);

// 0x5510a0, Signature_f_EventTranslator_t::handleEventTranslation: as 0x5516e0 with a float (bits copied by movss)
// set through 0x500360.
static void *STDCALL evtTranslateFloat(void *factory, u32 id, u32 *data) {
  void *ev = vcall<void *>(factory, 0x18, id);
  if (!ev) return 0;
  void *arr = vcall<void *>(ev, 0x4c);
  u32 v = *data;
  ext_500360(ext_5003d0(arr, 0), v);
  return ev;
}
PCREG(5510a0, evtTranslateFloat);

// 0x6565e0, ZPrimControlBase::GetLightSpotData(SPrimLightSpot*, const SPrimLightSpot*) const: own slot 0x14c with
// (dst, src), then the dwords at +0x24..+0x34 are copied from src to dst.
static void THISCALL primGetLightSpotData(void *self, u8 *dst, const u8 *src) {
  vcall<void>(self, 0x14c, dst, src);
  for (int o = 0x24; o <= 0x34; o += 4) *(u32 *)(dst + o) = *(const u32 *)(src + o);
}
PCREG(6565e0, primGetLightSpotData);

// 0x4faca0, ZWINPIC deleting destructor: ~ZWINOBJ (0x4ee4e0); flags bit 0 set: bit 2 set -> 0x4690b0(this, 0x93)
// (cdecl, map name ZRenderGC::SetState is a COMDAT alias; GUESS: sized pool free), else ZGEOM::operator delete.
extern "C" void THISCALL ext_4ee4e0(void *self);
extern "C" void ext_45c510(void *p);
extern "C" void ext_4690b0(void *p, u32 sz);
static void *THISCALL zwinpicDelDtor(u8 *self, u32 flags) {
  ext_4ee4e0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x93);
    else ext_45c510(self);
  }
  return self;
}
PCREG(4faca0, zwinpicDelDtor);

// 0x560320, CFFMPGameControl_if::consume(OpaqueType_t*) (stdcall, argument unused): 0xc8 bytes at 0x7141a0 cleared,
// 0x714198 = 0, the object at 0x71419c deleted (slot 0 with 1) when set, then 0x71419c = 0.
static void STDCALL mpGameControlConsume(void *) {
  ext_634d10((void *)0x7141a0, 0, 0xc8);
  void *o = G(void *, 0x71419c);
  G(u32, 0x714198) = 0;
  if (o) vcall<void>(o, 0, 1u);
  G(u32, 0x71419c) = 0;
}
PCREG(560320, mpGameControlConsume);

// 0x498960, ZGeomBuffer::RemoveGeoms(unsigned, ZBaseGeom*, ZBaseGeom*): the list type comes from
// GetBaseGeomListType(fastcall: flags, geom+0x3c) where flags = [[geom+0x54]+0xc]+0x23, or 0x200002 without +0x54;
// then ZBaseGeomLists::RemoveBaseGeoms on [this+0x1c]. Returns that call's EAX.
extern "C" u32 FASTCALL ext_4daf20(u32 flags, u32 kind);
extern "C" u32 THISCALL ext_498750(void *lists, u32 a, void *g, void *g2, u32 type);
static u32 THISCALL geomBufRemoveGeoms(u8 *self, u32 a, u8 *g, void *g2) {
  u32 p = *(u32 *)(g + 0x54);
  u32 fl = p ? *(u32 *)(*(u8 **)(p + 0xc) + 0x23) : 0x200002;
  u32 t = ext_4daf20(fl, *(u32 *)(g + 0x3c));
  return ext_498750(*(void **)(self + 0x1c), a, g, g2, t);
}
PCREG(498960, geomBufRemoveGeoms);

// 0x566ea0, CController::CopyEventDataBlock(DBREAD&): base (0x610100), then dwords to +0x18c, +0x190, +0x188.
static void THISCALL controllerCopyEvent(u8 *self, void *db) {
  ext_610100(self, db);
  *(u32 *)(self + 0x18c) = ext_4e5e60(db);
  *(u32 *)(self + 0x190) = ext_4e5e60(db);
  *(u32 *)(self + 0x188) = ext_4e5e60(db);
}
PCREG(566ea0, controllerCopyEvent);

// 0x4f75a0, ZScrollArea::SetDimensions(float*): two dwords to +0x9b/+0x9f; own slot 0x36c with the camera at +0x93
// when set; then own slot 0x370.
static void THISCALL scrollSetDimensions(u8 *self, const u32 *d) {
  void *cam = *(void **)(self + 0x93);
  *(u32 *)(self + 0x9b) = d[0];
  *(u32 *)(self + 0x9f) = d[1];
  if (cam) vcall<void>(self, 0x36c, cam);
  vcall<void>(self, 0x370);
}
PCREG(4f75a0, scrollSetDimensions);

// 0x4c5820, ZMarkTextureObjGroup::Init(ZGROUP*, DBREAD&) (both arguments unused): the render manager (engine +0x9b)
// slot 0x138 gives a table; the table's vtable is read before the render manager's slot 0x4c([this+0x44], 0x10) runs;
// then table slot 0x60(0x694d00, that result). Returns that call's EAX.
static u32 THISCALL markTexGroupInit(u8 *self, void *, void *) {
  void *rm = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  void *tab = vcall<void *>(rm, 0x138);
  void **tvt = *(void ***)tab;
  void *rm2 = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(rm2, 0x4c, *(u32 *)(self + 0x44), 0x10u);
  typedef u32(THISCALL * f60)(void *, u32, u32);
  return ((f60)tvt[0x60 / 4])(tab, 0x694d00u, v);
}
PCREG(4c5820, markTexGroupInit);

// 0x5f2ea0, SerialInfo_t::loaduint32(unsigned&): when cursor (+8) + 4 passes the end (+0xc), the overflow handler at
// 0x7003b0 is called (int3 when there is none) and the read goes ahead anyway. Reads the dword, cursor += 4.
static void THISCALL serialLoadU32(u8 *self, u32 *out) {
  if (*(u32 *)(self + 8) + 4 > *(u32 *)(self + 0xc)) {
    typedef void (*hfn)();
    hfn h = G(hfn, 0x7003b0);
    if (!h) asm volatile("int3");
    h();
  }
  *out = **(u32 **)(self + 8);
  *(u32 *)(self + 8) += 4;
}
PCREG(5f2ea0, serialLoadU32);

// 0x4f70a0, ZScrollArea::DisableCamera(): with a camera at +0x93: +0xa7 = 0, engine +0x190f object slot 0xb8(camera),
// own slot 0x2c4 gives an object whose slot 0x330 gets the camera (re-read).
static void THISCALL scrollDisableCamera(u8 *self) {
  void *cam = *(void **)(self + 0x93);
  if (!cam) return;
  self[0xa7] = 0;
  vcall<void>(*(void **)(G(u8 *, 0x70039c) + 0x190f), 0xb8, cam);
  void *o = vcall<void *>(self, 0x2c4);
  vcall<void>(o, 0x330, *(void **)(self + 0x93));
}
PCREG(4f70a0, scrollDisableCamera);

// 0x65bfe0 (no map name; GUESS: constructor, vtable 0x6c4714, 64 KB buffer at +0x28): base ctor 0x647fd0 with the
// four arguments, vtable set, memset(this+0x28, 0, 0x10000), +0x20 = 0. Returns this.
extern "C" void THISCALL ext_647fd0(void *self, u32 a, u32 b, u32 c, u32 d);
static void *THISCALL ctor6c4714(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  ext_647fd0(self, a, b, c, d);
  *(u32 *)self = 0x6c4714;
  ext_634d10(self + 0x28, 0, 0x10000);
  *(u32 *)(self + 0x20) = 0;
  return self;
}
PCREG(65bfe0, ctor6c4714);

// 0x45ba60, ZProjectMarks::CopyDataBlock(DBLK*): base (0x610100), two floats (+0x28, +0x2c) with DBLK::Get(float*,1),
// [this+0x1c] dwords to +0x48 with DBLK::Get(unsigned*, n), then DBLK::NextBlock().
extern "C" void THISCALL ext_4e12f0(void *b, void *dst, int n);
extern "C" void THISCALL ext_4e12e0(void *b, void *dst, int n);
extern "C" void THISCALL ext_4e1b30(void *b);
static void THISCALL projMarksCopyData(u8 *self, void *b) {
  ext_610100(self, b);
  ext_4e12f0(b, self + 0x28, 1);
  ext_4e12f0(b, self + 0x2c, 1);
  ext_4e12e0(b, self + 0x48, *(int *)(self + 0x1c));
  ext_4e1b30(b);
}
PCREG(45ba60, projMarksCopyData);

// 0x4b4160, CCutSequenceList::End(): engine +0x1907 object (when set) slot 0x14(0x692054); then the buffers at +0x90
// and +0x94 are freed with __builtin_delete(p, 1) when set (the fields are not cleared).
static void THISCALL cutSeqListEnd(u8 *self) {
  void *o = *(void **)(G(u8 *, 0x70039c) + 0x1907);
  if (o) vcall<void>(o, 0x14, 0x692054u);
  void *p = *(void **)(self + 0x90);
  if (p) ext_634273(p, 1);
  p = *(void **)(self + 0x94);
  if (p) ext_634273(p, 1);
}
PCREG(4b4160, cutSeqListEnd);
