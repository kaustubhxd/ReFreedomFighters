// f16b019.cpp - fresh slice 16, batch 19 (2026-10-12).
// 0x436a80 (thiscall a, src) ctor: +0 = 2, +8 = a ? a + 4 : 0, +4/+0xd/+0x11/+0x16 = 0, byte +0x15 = 0; s = 0x4cc1d0(src)
//           (name getter, called 3 times as in the exe): s -> +4 = new(strlen(s) + 1), strcpy. Then 0x439c20(this;
//           [src+0xa7]). Returns this. Ret 8.
// 0x4b1000 / 0x4b2180 CCutSequenceSoundFXAttenuation / CTimeOutDelete scalar deleting dtors: +0x44 = +0x30 = 0, vtable
//           0x686874, db slot 0x34(this); flags & 1: flags & 4 -> 0x4690b0(this, 0x6d / 0x57), else the assert handler
//           [0x7003b0]() (int3 when null; generators always set it). SEH not reproduced.
// 0x5fa380 OpaqueObjectSerialBuffer_t::produceOpaqueFromSerial(name, info): t = lookupType(getInstance(), name) (the push
//           before getInstance is lookupType's argument): t -> [t+0x1c] slot 0x14(name, info, this). Else _stricmp(name,
//           0x6b91c8) == 0 -> 0x5fa630() slot 0x40(info, this); _stricmp(name, 0x694c6c) == 0 -> slot 0x44(info, this);
//           else assert handler, return 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4cc1d0[], ext_41e290[], ext_439c20[], ext_4690b0[], ext_602d30[], ext_602ff0[], ext_5fa630[];

typedef const char *(THISCALL *NameFn)(void *);

extern "C" u8 *THISCALL f16_436a80(u8 *self, u32 a, u8 *src) {
  AT(u32, self, 0) = 2;
  AT(u32, self, 0x16) = 0;
  AT(u32, self, 8) = a ? a + 4 : 0;
  AT(u32, self, 0xd) = 0;
  AT(u32, self, 4) = 0;
  AT(u32, self, 0x11) = 0;
  AT(u8, self, 0x15) = 0;
  AT(u32, self, 0x16) = 0;
  if (((NameFn)(void *)ext_4cc1d0)(src)) {
    const char *s = ((NameFn)(void *)ext_4cc1d0)(src);
    u32 n = 0;
    while (s[n]) n++;
    AT(char *, self, 4) = ((char *(*)(u32))(void *)ext_41e290)(n + 1);
    s = ((NameFn)(void *)ext_4cc1d0)(src);
    char *d = AT(char *, self, 4);
    char ch;
    do {
      ch = *s++;
      *d++ = ch;
    } while (ch);
  }
  ((void(THISCALL *)(void *, u32))(void *)ext_439c20)(self, AT(u32, src, 0xa7));
  return self;
}

typedef void (*Hfn)();

static inline void *cutdtor(u8 *self, u32 flags, u32 tag) {
  AT(u32, self, 0x44) = 0;
  AT(u32, self, 0x30) = 0;
  AT(u32, self, 0) = 0x686874u;
  vcall<void>(AT(void *, G(u8 *, 0x70039c), 0x9b), 0x34, (void *)self);
  if (flags & 1) {
    if (flags & 4)
      ((void (*)(void *, u32))(void *)ext_4690b0)(self, tag);
    else
      G(Hfn, 0x7003b0)();
  }
  return self;
}

extern "C" void *THISCALL f16_4b1000(u8 *self, u32 flags) { return cutdtor(self, flags, 0x6d); }
extern "C" void *THISCALL f16_4b2180(u8 *self, u32 flags) { return cutdtor(self, flags, 0x57); }

extern "C" u32 THISCALL f16_5fa380(void *self, const char *name, void *info) {
  void *lib = ((void *(*)())(void *)ext_602d30)();
  u8 *t = ((u8 * (THISCALL *)(void *, const char *))(void *)ext_602ff0)(lib, name);
  if (t) return vcall<u32>(AT(void *, t, 0x1c), 0x14, name, info, self);
  typedef int (*Cmp)(const char *, const char *);
  if (G(Cmp, 0x676414)(name, (const char *)0x6b91c8) == 0)
    return vcall<u32>(((void *(*)())(void *)ext_5fa630)(), 0x40, info, self);
  if (G(Cmp, 0x676414)(name, (const char *)0x694c6c) == 0)
    return vcall<u32>(((void *(*)())(void *)ext_5fa630)(), 0x44, info, self);
  G(Hfn, 0x7003b0)();
  return 0;
}

PCREG(436a80, f16_436a80);
PCREG(4b1000, f16_4b1000);
PCREG(4b2180, f16_4b2180);
PCREG(5fa380, f16_5fa380);
