// batch288.cpp - area 22, residue-1 slice (docs/20-unclaimed-22.md, "Residue 1, batch288"): eleven small functions from
// the coordinator's floor(addr/16) mod 20 == 1 list. Names from the GameCube/Ghidra name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" void THISCALL ext_64f760(u8 *self);                         // ZRenderGC base AllocateDrawBuffers (GUESS: hooked)
extern "C" void *ext_41e290(u32 n);                                     // operator new (verified elsewhere; hooked)
extern "C" void THISCALL ext_610100(u8 *self, u8 *db);                  // base CopyEventDataBlock (GUESS: hooked)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);                             // DBREAD read word (GUESS: hooked)
extern "C" void THISCALL ext_4cd050(u8 *self);                          // STATICREFTAB destructor body (GUESS: hooked)
extern "C" void ext_634273(void *p, u32 n);                             // sized operator delete (hooked)
extern "C" int ext_42ac56(char *dst, const char *fmt, ...);             // sprintf (CRT, hooked)
extern "C" void THISCALL ext_644820(u8 *self);                          // (GUESS: hooked)

// 0x658110 ZRenderGC::AllocateDrawBuffers: the base call 0x64f760, then +0x1186 = new(0x4800).
void THISCALL renderAllocDrawBuffers_658110(u8 *self) {
  ext_64f760(self);
  *(void **)(self + 0x1186) = ext_41e290(0x4800);
}
PCREG(658110, renderAllocDrawBuffers_658110);

// 0x5ffb50 VMImageInfo_t::getDataSegSize: [+0x64] - [+0x60], plus the same for the chained image +0x9c (recursive).
u32 THISCALL vmGetDataSegSize_5ffb50(u8 *self) {
  u32 n = *(u32 *)(self + 0x64) - *(u32 *)(self + 0x60);
  u8 *next = *(u8 **)(self + 0x9c);
  if (next) return vmGetDataSegSize_5ffb50(next) + n;
  return n;
}
PCREG(5ffb50, vmGetDataSegSize_5ffb50);

// 0x57ad10 ZFFSetStartZone::CopyEventDataBlock(DBREAD &db) (ret 4): the base 0x610100(db), then +0x180 = db.0x4e5e60().
void THISCALL setStartZoneCopy_57ad10(u8 *self, u8 *db) {
  ext_610100(self, db);
  *(u32 *)(self + 0x180) = ext_4e5e60(db);
}
PCREG(57ad10, setStartZoneCopy_57ad10);

// 0x4cd390 STATICREFTAB scalar deleting destructor (ret 4): body 0x4cd050; flag bit 0: delete(this, 0x20); returns this.
u8 *THISCALL staticRefTabDelete_4cd390(u8 *self, u32 flags) {
  ext_4cd050(self);
  if (flags & 1) ext_634273(self, 0x20);
  return self;
}
PCREG(4cd390, staticRefTabDelete_4cd390);

// 0x54c2d0 (float f) (ret 4): c = [this+0x50]; false when c is 0, else c->vt 0x1c(f) (al passed through).
u8 THISCALL forward1c_54c2d0(u8 *self, float f) {
  u8 *c = *(u8 **)(self + 0x50);
  if (!c) return 0;
  return vcall<u8>(c, 0x1c, f);
}
PCREG(54c2d0, forward1c_54c2d0);

// 0x650cd0 ZRenderGC::Save(ZSaveGame *sg) (ret 4): [this+0xbd]->vt 0x64(), sg->vt 0x78([this+0x8c]); true.
u8 THISCALL renderSave_650cd0(u8 *self, u8 *sg) {
  vcall<void>(*(u8 **)(self + 0xbd), 0x64);
  vcall<void>(sg, 0x78, *(u32 *)(self + 0x8c));
  return 1;
}
PCREG(650cd0, renderSave_650cd0);

// 0x4d42d0 (arg) (ret 4): sprintf(this+0x1007, (const char *)0x6965c4, arg), then this->vt 0x1c().
void THISCALL formatName_4d42d0(u8 *self, u32 arg) {
  ext_42ac56((char *)(self + 0x1007), (const char *)0x6965c4, arg);
  vcall<void>(self, 0x1c);
}
PCREG(4d42d0, formatName_4d42d0);

// 0x656e50 ZPrimControlGC::CopyPrimDrawMode(dst, src) (ret 8): d = vt 0xc(dst), s = vt 0xc(src); d+0x20 = s+0x20 and
// the word d+4 = s+4.
void THISCALL copyPrimDrawMode_656e50(u8 *self, u32 dst, u32 src) {
  u8 *d = vcall<u8 *>(self, 0xc, dst);
  u8 *s = vcall<u8 *>(self, 0xc, src);
  *(u32 *)(d + 0x20) = *(u32 *)(s + 0x20);
  *(u16 *)(d + 4) = *(u16 *)(s + 4);
}
PCREG(656e50, copyPrimDrawMode_656e50);

// 0x64ff10 ZRenderBaseDll::Load2(ZLoadGame *lg) (ret 4): 0x644820([this+0x38]); lg->vt 0xc(0x13); returns
// ([[0x70039c]+0x190f])->vt 0x1b0(lg).
u32 THISCALL renderDllLoad2_64ff10(u8 *self, u8 *lg) {
  ext_644820(*(u8 **)(self + 0x38));
  vcall<void>(lg, 0xc, 0x13u);
  u8 *rm = G(u8 *, 0x70039c);
  return vcall<u32>(*(u8 **)(rm + 0x190f), 0x1b0, (u32)lg);
}
PCREG(64ff10, renderDllLoad2_64ff10);

// 0x65c990 (v) (ret 4): ring of 0x80 words at +0x200, index +0x414 (signed): store, index + 1, held at 0x7f once it
// reaches 0x80.
void THISCALL push_65c990(u8 *self, u32 v) {
  int i = *(int *)(self + 0x414);
  *(u32 *)(self + i * 4 + 0x200) = v;
  *(int *)(self + 0x414) = i + 1;
  if (*(int *)(self + 0x414) >= 0x80) *(int *)(self + 0x414) = 0x7f;
}
PCREG(65c990, push_65c990);

// 0x495e90 ZGeomBuffer::AllocGeom(a, name, c, d) (ret 0x10): x = ([[0x70039c]+0x9b])->vt 0x154(name, 0); returns
// this->vt 4(a, x, c, d).
u32 THISCALL geomBufferAllocGeom_495e90(u8 *self, u32 a, u32 name, u32 c, u32 d) {
  u8 *rm = G(u8 *, 0x70039c);
  u32 x = vcall<u32>(*(u8 **)(rm + 0x9b), 0x154, name, 0u);
  return vcall<u32>(self, 4, a, x, c, d);
}
PCREG(495e90, geomBufferAllocGeom_495e90);
