// batch33019.cpp - h3 batch 33019: field readers, tail-jumps, and stdcall setter
#include "ff.h"

extern "C" void THISCALL ext_5cdb70(u8 *self);
extern "C" void THISCALL ext_5fb920(u8 *self);

// 0x58eb40, thiscall: read offset 0x85a, tail-jump to 0x5cdb70
static void THISCALL fn58eb40(u8 *self) {
  u8 *obj = *(u8 **)(self + 0x85a);
  ext_5cdb70(obj);
}
PCREG(58eb40, fn58eb40);

// 0x5f18d0, thiscall: double deref (0xc then 4), tail-jump to 0x5fb920
static void THISCALL fn5f18d0(u8 *self) {
  u8 *obj = *(u8 **)(self + 0xc);
  u8 *obj2 = *(u8 **)(obj + 4);
  ext_5fb920(obj2);
}
PCREG(5f18d0, fn5f18d0);

// 0x410100, cdecl: get arg from esp+4, deref it, read byte at +4, return in al
static u8 fn410100(u8 *obj) {
  u8 *p = *(u8 **)obj;
  return p[4];
}
PCREG(410100, fn410100);

// 0x446d70, thiscall with arg from stack: read [ebp+8], store at ecx+0x192
static void THISCALL fn446d70(u8 *self, u32 val) {
  *(u32 *)(self + 0x192) = val;
}
PCREG(446d70, fn446d70);
