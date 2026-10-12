// batch605.cpp - area 49, batch 605: CEnemyFlag::ReadInput(DBREAD &) (0x5c1dc0).
// thiscall, ret 4. The SEH frame is not reproduced (no effect on the result). Callees stay the exe's code (ext_ bindings):
// 0x4e5ea0 (name read, thiscall, no args, returns char *), 0x4e5e60 (u32 read, thiscall, no args), 0x4dc110 (node name,
// thiscall, no args), 0x4cc850 (fastcall: name in ecx, pattern in edx). The CRT strncpy is the import at 0x67642c (cdecl).
// Virtual calls, in exe order: DBREAD object slot 0x20 (no args, returns the object) when [[obj+0xc]+0x23] lacks 0x100000;
// object slot 0x25c (name, default) for 0x6b3b58, 0x6b3b68, 0x6b3b78, 0x6b3b90, 0x6b3ba8; render manager slot 0x4c (one
// arg) for the two found values; the chosen object's slot 0x84 (one arg, &self+0x7c); the debug log at [0x700390]
// slot 0x20 (file, line) and then the printf-like slot 0x2c (cdecl: stream, fmt, s) when the name is longer than 10.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vGet)(void *self, u32 name, u32 def);             // slot 0x25c: two arguments
typedef u32(THISCALL *vOne)(void *self, u32 a);                         // slots 0x4c and 0x84: one argument
typedef void *(THISCALL *vNone)(void *self);                            // slot 0x20 of the DBREAD object: none
typedef void *(THISCALL *vLog)(void *self, u32 file, u32 line);         // slot 0x20 of the logger: two arguments
typedef int (*vPrintf)(void *stream, const char *fmt, const char *s);   // slot 0x2c: cdecl
typedef void *(*vStrncpy)(void *dst, const char *src, u32 n);          // IAT 0x67642c (cdecl)
extern "C" const char *THISCALL ext_4e5ea0(void *dbr);                  // name read (thiscall, no args)
extern "C" u32 THISCALL ext_4e5e60(void *dbr);                          // u32 read (thiscall, no args)
extern "C" const char *THISCALL ext_4dc110(void *node);                 // node name (thiscall, no args)
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);     // wildcard match (fastcall)

// 0x5c1dc0 CEnemyFlag::ReadInput(DBREAD &dbr): thiscall, ret 4
static void THISCALL readInput(u8 *self, u8 *dbr) {
  const char *s = ext_4e5ea0(dbr);
  u32 n = 0;
  while (s[n])
    n++;                                                                  // strlen(s)
  if (n > 0xa) {
    u8 *lg = G(u8 *, 0x700390);
    void *stream = ((vLog)VT(lg, 0x20))(lg, 0x6b3a74, 0x70);
    ((vPrintf)VT(stream, 0x2c))(stream, (const char *)0x6b3b10, s);
  }
  ((vStrncpy)(u32)G(u32, 0x67642c))(self + 0x70, s, 0xb);           // strncpy(this+0x70, name, 11)
  self[0x7b] = 0;
  u32 v = ext_4e5e60(dbr);
  *(u32 *)(self + 0x48) = v;
  *(u32 *)(self + 0x4c) = v;
  ext_4e5e60(dbr);
  ext_4e5e60(dbr);
  u32 flag = ext_4e5e60(dbr);                                             // the fourth read gives the flag
  u8 *obj = *(u8 **)(self + 0x44);
  self[0x10c] = flag != 0;
  if (!(*(u32 *)(*(u8 **)(obj + 0xc) + 0x23) & 0x100000))
    obj = (u8 *)((vNone)VT(obj, 0x20))(obj);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *rm = *(u8 **)(sys + 0x9b);
  u32 e = ((vGet)VT(obj, 0x25c))(obj, 0x6b3b58, 0);
  if (!e)
    e = ((vGet)VT(obj, 0x25c))(obj, 0x6b3b68, e);
  if (e) {
    *(u32 *)(self + 0x111) = ((vOne)VT(rm, 0x4c))(rm, e);
    u32 e2 = ((vGet)VT(obj, 0x25c))(obj, 0x6b3b78, 0);
    if (!e2) {
      e2 = ((vGet)VT(obj, 0x25c))(obj, 0x6b3b90, e2);
      if (e2)
        self[0x106] = 1;
    }
    *(u32 *)(self + 0x115) = ((vOne)VT(rm, 0x4c))(rm, e2);
  }
  u32 e3 = ((vGet)VT(obj, 0x25c))(obj, 0x6b3ba8, 0);
  u32 *tmp = (u32 *)(self + 0x7c);
  tmp[0] = 0;
  tmp[1] = 0;
  tmp[2] = 0;
  u8 *t = (u8 *)e3;
  if (!t)
    t = *(u8 **)(self + 0x30);
  ((vOne)VT(t, 0x84))(t, (u32)tmp);
  u8 *node = *(u8 **)(obj + 0x50);
  while (node) {
    const char *nm = ext_4dc110(node);
    if (ext_4cc850(nm, (const char *)0x6b3bb4) == 0)
      *(u32 *)(self + 0x119) = *(u32 *)(node + 0x54);
    node = *(u8 **)(node + 0x60);
  }
}
PCREG(5c1dc0, readInput);
