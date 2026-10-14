// batch37105.cpp - cascade s6 batch 37105: 0x427c10.
#include "ff.h"

typedef char *(*strchr_t)(const char *, int);           // cdecl, through the IAT
typedef u32(STDCALL *i0_t)();
typedef u32(STDCALL *i2_t)(u32, u32);
typedef u32(STDCALL *i7_t)(u32, u32, u32, u32, u32, u32, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);
typedef void (*cd4_t)(void *, u32, u32, u32);
#define IAT(T, a) (*(T *)(a))

static void *logger(u32 line) {
  u8 *lg = *(u8 **)0x700390;
  return (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x6789ac, line);
}

// 0x427c10, thiscall(path) ret 4: creates the directory `path` (and its parents, through slot 0x4c) unless the object already knows it (slot 0x34). Paths longer than 0x104 bytes
// are ignored; backslashes are turned into '/'. Each attempt is logged (0x174), CreateDirectory is called and a failure logs the formatted system error (0x179).
static void THISCALL fn427c10(u8 *self, const char *path) {
  char buf[0x108];
  u32 len = 0;
  while (path[len]) len++;
  if (len > 0x104) return;
  for (u32 i = 0; i <= len; i++) buf[i] = path[i];
  char *p;
  while ((p = IAT(strchr_t, 0x676254)(buf, 0x5c))) *p = '/';
  if ((u8)vcall<u32>(self, 0x34, (u32)buf, 0u)) return;
  char *q = IAT(strchr_t, 0x676258)(buf, 0x2f);
  if (q) {
    *q = 0;
    vcall<void>(self, 0x4c, (u32)buf);
    *q = '/';
  }
  void *L = logger(0x174);
  (*(cd3_t **)L)[0x2c / 4](L, 0x678c50, (u32)buf);
  if (IAT(i2_t, 0x6760d4)((u32)buf, 0)) return;
  char msg[0x100];
  u32 err = IAT(i0_t, 0x67609c)();
  IAT(i7_t, 0x6760ec)(0x1000, 0, err, 0, (u32)msg, 0x100, 0);
  L = logger(0x179);
  (*(cd4_t **)L)[0x2c / 4](L, 0x678c68, (u32)path, (u32)msg);
}
PCREG(427c10, fn427c10);
