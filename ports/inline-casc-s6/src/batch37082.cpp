// batch37082.cpp - cascade s6 batch 37082: 0x57a1e0.
#include "ff.h"

typedef void (*fmt_t)(void *, u8 *, u32, u32);   // cdecl, called through the vtable with the object as first argument

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u8 *eng() { return *(u8 **)0x70039c; }

static void fmtTo(u8 *buf, u32 fmt, u32 arg) {
  void *L = (void *)vcall<u32>(eng(), 0x190);
  (*(fmt_t *)(*(u8 **)L + 0x198))(L, buf, fmt, arg);
}

// 0x57a1e0, thiscall(), plain ret: resolves the three handles named by +0x48 / +0x4c / +0x50 through the table object (stored at +0x54 / +0x58 / +0x5c), reads three engine
// strings (names 0x6a9bdc, 0x6a9bec, 0x6a9bf8, with defaults when missing), formats each into a 0x400-byte buffer with its own format string and passes the text to the
// matching handle's slot 0x284, then calls slot 0xbc(1) on each handle.
static void THISCALL fn57a1e0(u8 *self) {
  u8 buf[0x400];
  u32 v1 = 0, v2 = 0, v3 = 0;
  D32(self, 0x54) = vcall<u32>(tabObj(), 0x58, D32(self, 0x48));
  D32(self, 0x58) = vcall<u32>(tabObj(), 0x58, D32(self, 0x4c));
  D32(self, 0x5c) = vcall<u32>(tabObj(), 0x58, D32(self, 0x50));
  vcall<void>(eng(), 0x5c, 0x6a9bdcu, (u32)&v1);
  vcall<void>(eng(), 0x5c, 0x6a9becu, (u32)&v2);
  vcall<void>(eng(), 0x5c, 0x6a9bf8u, (u32)&v3);
  u32 s1 = v1 ? v1 : 0x6a9c04u;
  u32 s3 = v3 ? v3 : 0x6a9c10u;
  u32 s2 = v2 ? v2 : 0x6852b8u;
  fmtTo(buf, 0x6a9c1c, s1);
  vcall<void>((void *)D32(self, 0x54), 0x284, (u32)buf);
  fmtTo(buf, 0x6a9c30, s2);
  vcall<void>((void *)D32(self, 0x58), 0x284, (u32)buf);
  fmtTo(buf, 0x6a9c44, s3);
  vcall<void>((void *)D32(self, 0x5c), 0x284, (u32)buf);
  vcall<void>((void *)D32(self, 0x54), 0xbc, 1u);
  vcall<void>((void *)D32(self, 0x58), 0xbc, 1u);
  vcall<void>((void *)D32(self, 0x5c), 0xbc, 1u);
}
PCREG(57a1e0, fn57a1e0);
