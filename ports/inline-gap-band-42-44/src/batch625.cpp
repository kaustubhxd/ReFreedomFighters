// batch625.cpp - band 0x421000-0x441000, batch 625: two functions.
//   0x427f40 ZSysFileGC::WriteTo(void*, void*, long) (stdcall, four arguments, all unused; ret 0x10): logger = [0x700390];
//     stream = slot 0x20 of logger (file 0x6789ac, line 0x153); slot 0x2c of stream as cdecl (stream, fmt 0x678be8); returns 0.
//   0x432250 CConfiguration::ExtractKeyNameFromNode(int) (thiscall, ret 4): p = slot 0xc of this with the int; returns
//     (p == 0 ? 0x677a44 : dword [p]).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void *(THISCALL *vLog)(void *self, u32 file, u32 line);
typedef int (*vPrintf2)(void *stream, const char *fmt);                // cdecl, two arguments
typedef u32(THISCALL *vOne)(void *self, u32 a);

static u32 STDCALL writeTo(u32 a, u32 b, u32 c, u32 d) {
  (void)a;
  (void)b;
  (void)c;
  (void)d;
  u8 *lg = G(u8 *, 0x700390);
  void *stream = ((vLog)VT(lg, 0x20))(lg, 0x6789ac, 0x153);
  ((vPrintf2)VT(stream, 0x2c))(stream, (const char *)0x678be8);
  return 0;
}
PCREG(427f40, writeTo);

static u32 THISCALL extractKeyName(u8 *self, u32 key) {
  u32 p = ((vOne)VT(self, 0xc))(self, key);
  if (p == 0)
    return 0x677a44;
  return *(u32 *)p;
}
PCREG(432250, extractKeyName);
