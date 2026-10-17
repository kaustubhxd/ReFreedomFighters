// batch742.cpp - ZFFHERO::Save(ZSaveGame* save) (0x5947b0) [high], area 72 (residue 11), 2026-10-12.
// A straight sequence of writes to the save object: slot 0x60 takes a byte, 0x44 / 0x3c / 0x64 / 0x54 a dword, 0x4c a float,
// 0x5c a c_str of the MYSTR at +0x698, 0x68 / 0x70 a pointer into the hero. Some writes chain on the object returned by the
// previous write (the exe reuses eax as ecx), which is tracked explicitly here. Before the writes: ZPlayer::Save (0x484d20)
// on the hero with the save object; after: GameEntity::Save (0x59d3f0) on the hero's +0x54 object, and two helper saves
// (0x58aa40 at +0xa16 and 0x58aaf0 at +0xd4a, fastcall). The last write is a signed value: (+0x64f - gl - 0xd91) / 100 with
// the exe's 64-bit multiply (0x4325c53f) and the round-towards-zero fix-up. Returns true.
#include "ff.h"

typedef long long s64;

extern "C" void THISCALL ext_484d20(void *hero, void *save);                    // ZPlayer::Save
extern "C" void THISCALL ext_59d3f0(void *entity, void *save);                  // GameEntity::Save
extern "C" void FASTCALL ext_58aa40(void *save, void *p);                       // helper save (edx = pointer)
extern "C" void FASTCALL ext_58aaf0(void *save, void *p);                       // helper save (edx = pointer)
extern "C" const char *THISCALL ext_4cc1d0(void *mystr);                        // MYSTR::c_str

#define BY(o) ((u32)self[(o)])
#define DW(o) (*(u32 *)(self + (o)))
#define FL(o) (*(float *)(self + (o)))
#define PT(o) ((u32)(self + (o)))

// 0x5947b0 ZFFHERO::Save(ZSaveGame* save) [high].
static bool THISCALL hero_Save(u8 *self, u8 *save) {
  ext_484d20(self, save);
  vcall<void>(save, 0x60, BY(0x653));
  vcall<void>(save, 0x44, DW(0x64b));
  vcall<void>(save, 0x3c, DW(0x654));
  vcall<void>(save, 0x64, DW(0x658));
  vcall<void>(save, 0x60, BY(0x65c));
  vcall<void>(save, 0x3c, DW(0x67b));
  vcall<void>(save, 0x44, DW(0x680));
  vcall<void>(save, 0x64, DW(0x68c));
  vcall<void>(save, 0x54, DW(0x690));
  vcall<void>(save, 0x54, DW(0x694));
  vcall<void>(save, 0x5c, ext_4cc1d0(self + 0x698));
  vcall<void>(save, 0x4c, FL(0x7ec));
  vcall<void>(save, 0x60, BY(0x7f0));
  vcall<void>(save, 0x60, BY(0x7f1));
  vcall<void>(save, 0x60, BY(0x7f2));
  vcall<void>(save, 0x44, DW(0x7f3));
  vcall<void>(save, 0x44, DW(0x7f7));
  void *cur = vcall<void *>(save, 0x4c, FL(0x7fb));
  vcall<void>(cur, 0x4c, FL(0x7ff));
  vcall<void>(save, 0x4c, FL(0x803));
  vcall<void>(save, 0x4c, FL(0x807));
  vcall<void>(save, 0x4c, FL(0x80b));
  vcall<void>(save, 0x4c, FL(0x80f));
  vcall<void>(save, 0x4c, FL(0x813));
  vcall<void>(save, 0x4c, FL(0x817));
  vcall<void>(save, 0x4c, FL(0x81b));
  vcall<void>(save, 0x3c, DW(0x842));
  vcall<void>(save, 0x3c, DW(0x846));
  vcall<void>(save, 0x64, DW(0x84e));
  vcall<void>(save, 0x70, PT(0x862));
  vcall<void>(save, 0x68, PT(0x886));
  vcall<void>(save, 0x70, PT(0x892));
  vcall<void>(save, 0x68, PT(0x8b6));
  vcall<void>(save, 0x4c, FL(0x9e3));
  vcall<void>(save, 0x3c, DW(0x83e));
  vcall<void>(save, 0x60, BY(0x66f));
  vcall<void>(save, 0x64, DW(0xeee));
  vcall<void>(save, 0x68, PT(0x65d));
  cur = vcall<void *>(save, 0x60, BY(0x669));
  cur = vcall<void *>(cur, 0x60, BY(0x66a));
  vcall<void>(cur, 0x60, BY(0x66c));
  cur = vcall<void *>(save, 0x60, BY(0x66d));
  vcall<void>(cur, 0x60, BY(0x66e));
  vcall<void>(save, 0x3c, DW(0x676));
  vcall<void>(save, 0x60, BY(0x67f));
  vcall<void>(save, 0x44, DW(0x684));
  vcall<void>(save, 0x68, PT(0x42d));
  vcall<void>(save, 0x3c, DW(0x83e));
  vcall<void>(save, 0x68, PT(0x439));
  vcall<void>(save, 0x4c, FL(0x451));
  vcall<void>(save, 0x60, BY(0x831));
  vcall<void>(save, 0x4c, FL(0x81f));
  vcall<void>(save, 0x4c, FL(0x823));
  vcall<void>(save, 0x60, BY(0x9f4));
  vcall<void>(save, 0x60, BY(0x9f5));
  ext_58aa40(save, self + 0xa16);
  ext_58aaf0(save, self + 0xd4a);
  vcall<void>(save, 0x68, PT(0xeb3));
  vcall<void>(save, 0x68, PT(0xebf));
  vcall<void>(save, 0x64, DW(0xecb));
  vcall<void>(save, 0x4c, FL(0xed3));
  vcall<void>(save, 0x4c, FL(0xed7));
  vcall<void>(save, 0x4c, FL(0xedb));
  vcall<void>(save, 0x44, DW(0xedf));
  vcall<void>(save, 0x60, BY(0xeec));
  vcall<void>(save, 0x60, BY(0xeed));
  vcall<void>(save, 0x44, DW(0xf5e));
  ext_59d3f0(*(void **)(self + 0x54), save);

  // (+0x64f - gl - 0xd91) / 100, signed, as the exe computes it with a 64-bit multiply.
  u32 x = DW(0x64f) - *(u32 *)0x7003b8 - 0xd91u;
  s64 p = (s64)(s32)x * (s64)(s32)0x4325c53f;
  s32 t = (s32)(p >> 32) >> 6;
  s32 q = t + (s32)((u32)t >> 31);
  vcall<void>(save, 0x44, (u32)q);
  return true;
}
PCREG(5947b0, hero_Save);
