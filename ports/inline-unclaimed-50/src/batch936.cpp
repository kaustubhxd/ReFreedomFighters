// batch936.cpp - 0x47ade0 ZActor::Save(ZSaveGame*) [thiscall (ECX = this), one stack arg (the stream st), ret 4, returns al = 1]. Body read
// in full (2026-10-12; 61 steps, most of them vtable calls through the stream or through the object the previous call returned, which the exe
// keeps in EAX). Stood in: 0x4753c0 (thiscall: this, stream; its result is unused). The stack cookie is not part of the body.
// Notation: S = the stream; cur = EAX (the last call's result). A call on S uses 'mov eax,[st]' (or 'mov ecx,st'); a call on cur uses EAX as it is.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4753c0(void *self, void *st);   // stood in

// 0x47ade0 (name in the map: ZActor::Save(ZSaveGame*)).
static u8 THISCALL Save47ade0(u8 *self, u8 *st) {
  void *cur;
  ext_4753c0(self, st);
  cur = vcall<void *>(st, 0x3c, U32(self, 0x5ce));
  vcall<void *>(cur, 0x4c, F32(self, 0x624));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x640));
  vcall<void *>(cur, 0x4c, F32(self, 0x644));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x64c));
  cur = vcall<void *>(cur, 0x3c, U32(self, 0x650));
  cur = vcall<void *>(cur, 0x3c, U32(self, 0x654));
  cur = vcall<void *>(cur, 0x3c, U32(self, 0x658));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x65c));
  cur = vcall<void *>(st, 0x68, (void *)(self + 0x660));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x678));
  cur = vcall<void *>(cur, 0x68, (void *)(self + 0x67c));
  u8 *mgr = (u8 *)FP(G(u8 *, 0x70039c), 0x9b);
  u32 v = vcall<u32>(mgr, 0x4c, U32(self, 0x5b2));
  cur = vcall<void *>(st, 0x3c, v);
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x690));
  u32 esi = U32(self, 0x695);
  cur = vcall<void *>(st, 0x60, (u32)(esi != 0));
  if (esi != 0) {
    vcall<void *>(st, 0x10, (void *)(esi + 8), 4u);
    vcall<void *>(st, 0x4c, F32((u8 *)esi, 4));
    vcall<void *>(st, 0x10, U32((u8 *)esi, 0xc), U32((u8 *)esi, 8) << 4);
    vcall<void *>(st, 0x10, U32((u8 *)esi, 0x10), U32((u8 *)esi, 8) << 2);
  }
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x699));
  cur = vcall<void *>(cur, 0x68, (void *)(self + 0x69a));
  cur = vcall<void *>(cur, 0x68, (void *)(self + 0x6a6));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x6b2));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x6b6));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x6bf));
  cur = vcall<void *>(cur, 0x60, (u32)U8(self, 0x6c5));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x6ba));
  cur = vcall<void *>(cur, 0x60, (u32)U8(self, 0x6c4));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x6ca));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x688));
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x6fe));
  cur = vcall<void *>(cur, 0x3c, U32(self, 0x6ff));
  cur = vcall<void *>(cur, 0x60, (u32)U8(self, 0x703));
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x704));
  cur = vcall<void *>(cur, 0x60, (u32)U8(self, 0x705));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x706));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x70a));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x70e));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x712));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x716));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x71a));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x71e));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x722));
  cur = vcall<void *>(cur, 0x60, (u32)U8(self, 0x726));
  cur = vcall<void *>(cur, 0x3c, U32(self, 0x727));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x736));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x73a));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x732));
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x72f));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x68c));
  cur = vcall<void *>(st, 0x3c, U32(self, 0x648));
  u8 *esiP = self + 0x4b6;
  for (u32 n = 0x10; n != 0; n--) {
    cur = vcall<void *>(st, 0x3c, U32(esiP, -4));
    cur = vcall<void *>(cur, 0x3c, U32(esiP, 0));
    cur = vcall<void *>(cur, 0x3c, U32(esiP, 4));
    cur = vcall<void *>(cur, 0x3c, U32(esiP, 8));
    esiP += 0x10;
  }
  cur = vcall<void *>(st, 0x3c, U32(self, 0x4ae));
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x754));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x755));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x759));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x75d));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x765));
  cur = vcall<void *>(st, 0x4c, F32(self, 0x769));
  cur = vcall<void *>(cur, 0x4c, F32(self, 0x76d));
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x771));
  cur = vcall<void *>(st, 0x24, U32(self, 0x74f));
  cur = vcall<void *>(st, 0x60, (u32)U8(self, 0x5d2));
  cur = vcall<void *>(st, 0x44, U32(self, 0x72b));
  return 1;
}
PCREG(47ade0, Save47ade0);
