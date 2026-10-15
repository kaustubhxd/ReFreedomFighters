// batch 78002: 0x50f850
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *, u32);
extern "C" void THISCALL ext_4db2c0(void *, void *, void *);
extern "C" void FASTCALL ext_4dfd10(void *, void *);
extern "C" void FASTCALL ext_4de420(void *, void *);
extern "C" void FASTCALL ext_4de480(void *, void *);
extern "C" void FASTCALL ext_4419f0(void *, void *);
extern "C" void FASTCALL ext_43e960(void *, void *);

static void STDCALL fn50f850(u8 *self) {
  u8 *store = *(u8 **)(self + 4);
  u8 *a = ext_5003d0(store, 0);
  u8 *sys = *(u8 **)(*(u8 **)(0x70039c) + 0x9b);
  u8 *obj0 = (u8 *)vcall<u32>(sys, 0x58, *(u32 *)a);
  u8 *b = ext_5003d0(store, 2);
  u8 *obj2 = (u8 *)vcall<u32>(sys, 0x58, *(u32 *)b);
  u8 *c = ext_5003d0(store, 1);
  u8 *obj1 = (u8 *)vcall<u32>(sys, 0x58, *(u32 *)c);
  if (!obj0 || !obj1 || !obj2) return;

  u8 local94[0x94];
  u8 local70[0x24];
  u8 local4c[0x24];
  u8 local28[0x18];
  u8 local1c[0x0c];
  u8 local10[0x0c];
  u32 local8;
  vcall<void>(obj1, 0x80, local94, local1c);
  local8 = *(u32 *)(local1c + 8);
  *(u32 *)(local10 + 0) = *(u32 *)(local1c + 0);
  *(u32 *)(local10 + 4) = *(u32 *)(local1c + 4);
  *(u32 *)(local10 + 8) = *(u32 *)(local1c + 8);
  ext_4db2c0(obj2 + 8, local4c, local28);
  ext_4dfd10(local70, local4c);
  ext_4de420(local4c, local94);
  ext_4de480(local70, local4c);
  ext_4419f0(local28, local70);
  ext_43e960(local10, local28);
  vcall<void>(obj0, 0x74, local70, local10);
}
PCREG(50f850, fn50f850);
