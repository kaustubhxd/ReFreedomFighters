#include "ff.h"

extern "C" u32 THISCALL ext_4cc1d0(u32 self);
extern "C" u32 FASTCALL ext_4cc850(u32 edi, u32 esi);

typedef char *( * strchr_fn)(const char *, int);
typedef int (* strnicmp_fn)(const char *, const char *, u32);

static u32 THISCALL fn4351c0(u8 *self, char *path) {
  if (*(u32 *)(self + 8)) {
    vcall<void>(self, 0x6c, 1u);
    u32 dot = (u32)(*(strchr_fn *)0x676258)(path, 0x2e);
    if (!dot) return 0;
    u32 nested = *(u32 *)(self + 8);
    u32 out = 0;
    vcall<void>((void *)nested, 0x4c, (u32)&out);
    u32 cur = vcall<u32>((void *)nested, 0x5c, (u32)&out);
    if (out) {
      do {
        if ((*(strchr_fn *)0x676254)((const char *)cur, 0x2a)) {
          if (!ext_4cc850((u32)path, cur)) return 0;
        } else {
          if (!(*(int (**)(const char *, const char *))0x676414)((const char *)dot, (const char *)cur)) {
            vcall<void>(self, 0x6c, 0u);
            return 0;
          }
        }
        nested = *(u32 *)(self + 8);
        cur = vcall<u32>((void *)nested, 0x5c, (u32)&out);
      } while (out);
    }
  }

  u32 base = ext_4cc1d0(*(u32 *)0x70039c + 0x123);
  if (!base || !*(u8 *)base) return (u32)path;
  u32 blen = 0, plen = 0;
  while (*(u8 *)(base + blen)) ++blen;
  while (*(u8 *)(u32(path) + plen)) ++plen;
  if (blen <= plen && !(*(strnicmp_fn *)0x67640c)((char *)base, path, blen) && *(u8 *)(u32(path) + blen) == '\\')
    path += blen + 1;
  return (u32)path;
}

PCREG(4351c0, fn4351c0);
