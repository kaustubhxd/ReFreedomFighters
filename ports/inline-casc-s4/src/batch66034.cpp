// batch66034.cpp - cascade s4 batch 66034: 0x426c50 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(STDCALL *ffirst_t)(const char *, void *);
typedef s32(STDCALL *fnext_t)(u32, void *);
typedef s32(STDCALL *fclose_t)(u32);

extern "C" u32 THISCALL ext_4cc1d0(void *self);   // mov eax, [ecx]; ret

// 0x426c50, thiscall(a, b, c) ret 0xc (this = t): s = *(char **)(sys + 0x123) (0x4cc1d0); path = s + the 10 bytes at 0x678ce8; t->slot 0x13 (0x4c)(path); path += the 2 bytes at 0x678d04.
// h = FindFirstFileA(path, &fd); h == -1 -> done. Do: name = fd.cFileName (+0x2c); names other than "." and ".." -> c->slot 0x22 (0x88)(name); while FindNextFileA(h, &fd). FindClose(h).
static void THISCALL fn426c50(u8 *t, u32 a, u32 b, u8 *c) {
  char path[0x108];
  u8 fd[0x140];
  u8 *sys = G(u8 *, 0x70039c);
  const char *s = (const char *)ext_4cc1d0(sys + 0x123);
  u32 n = 0;
  do {
    path[n] = s[n];
  } while (s[n++]);
  n--;
  *(u32 *)(path + n) = G(u32, 0x678ce8);
  *(u32 *)(path + n + 4) = G(u32, 0x678cec);
  *(u16 *)(path + n + 8) = G(u16, 0x678cf0);
  (*(v1_t **)t)[0x4c / 4](t, (u32)path);
  n = 0;
  while (path[n]) n++;
  *(u16 *)(path + n) = G(u16, 0x678d04);
  u32 h = G(ffirst_t, 0x67610c)(path, fd);
  if (h == 0xffffffffu) return;
  do {
    const char *nm = (const char *)(fd + 0x2c);
    if (nm[0] == '.' && (nm[1] == 0 || (nm[1] == '.' && nm[2] == 0))) continue;
    (*(v1_t **)c)[0x88 / 4](c, (u32)nm);
  } while (G(fnext_t, 0x676110)(h, fd));
  G(fclose_t, 0x676108)(h);
}
PCREG(426c50, fn426c50);
