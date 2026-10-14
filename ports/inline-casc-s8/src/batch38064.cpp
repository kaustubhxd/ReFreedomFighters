// batch38064.cpp - cascade s8 batch 38064: 0x428fe0 (stream loader: open child object, check/configure it, clamp two fields, finish).
#include "ff.h"

extern "C" u32 THISCALL ext_436060(u8 *self, u32 stream);  // ret 4
extern "C" u32 THISCALL ext_428960(u8 *self);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
typedef u32(STDCALL *s2_t)(void *, u32);
typedef u32(STDCALL *s3_t)(void *, u32, u32);
typedef u32(STDCALL *s4_t)(void *, u32, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static void logline(u32 line, u32 msg) {
  u8 *lg = G(u8 *, 0x700390);
  void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x678f5c, line);
  (*(log2_t **)st)[0x2c / 4](st, msg);
}

// 0x428fe0, thiscall(stream) ret 4. Returns bool (al).
static u8 THISCALL fn428fe0(u8 *self, u8 *stream) {
  ext_436060(self, (u32)stream);
  u8 *pobj = self + 0x71;
  UN32(self, 0x71) = 0;
  if ((int)SLOT(stream, 0xc, s4_t)(stream, (u32)(self + 0xa1), (u32)pobj, 0) < 0) { logline(0x520, 0x679384); return 0; }
  u8 *o = (u8 *)UN32(self, 0x71);
  if (!o) { logline(0x527, 0x6793a4); return 0; }
  if ((int)SLOT(o, 0x2c, s2_t)(o, 0x6be178) < 0) { logline(0x534, 0x6793d8); return 0; }
  o = (u8 *)UN32(self, 0x71);
  u8 *sys = G(u8 *, 0x70039c);
  if ((int)SLOT(o, 0x34, s3_t)(o, UN32(sys, 0x9db), 5) < 0) { logline(0x53e, 0x6793fc); return 0; }
  o = (u8 *)UN32(self, 0x71);
  UN32(self, 0x75) = 0x2c;
  SLOT(o, 0xc, s2_t)(o, (u32)(self + 0x75));
  int v = (int)(UN32(self, 0x81) >> 1);
  UN32(self, 0x5d) = v;
  if (v > 2) { UN32(self, 0x5d) = 2; logline(0x54c, 0x679428); }
  o = (u8 *)UN32(self, 0x71);
  if ((int)SLOT(o, 0x10, s4_t)(o, 0x428af0, (u32)o, 3) < 0) { logline(0x556, 0x679478); return 0; }
  v = (int)UN32(self, 0x85);
  UN32(self, 0x61) = v;
  if (v > 0x10) { UN32(self, 0x61) = 0x10; logline(0x55e, 0x679498); }
  if (ext_428960(self) != 0) { logline(0x566, 0x6794ec); return 0; }
  self[0xc] = 1;
  return 1;
}
PCREG(428fe0, fn428fe0);
