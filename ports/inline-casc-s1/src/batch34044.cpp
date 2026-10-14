// batch34044.cpp - cascade tier E, batch 34044: 0x427ea0 (checked ReadFile with an error dialog), 0x453130 / 0x45a3f0 (walk an id list and poke each object).
#include "ff.h"

typedef int(STDCALL *readfile_t)(u32 h, void *buf, u32 n, u32 *got, void *ov);
typedef u32(STDCALL *getlasterror_t)(void);
typedef u32(STDCALL *formatmessage_t)(u32 flags, const void *src, u32 err, u32 lang, void *out, u32 size, void *args);
typedef int(STDCALL *messagebox_t)(void *hwnd, const void *text, const void *caption, u32 flags);
typedef void *(STDCALL *localfree_t)(void *p);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x427ea0, stdcall(h, buf, n) ret 0xc: ReadFile(h, buf, n, &got, 0) (KERNEL32 import 0x676094); when it succeeds returns got. Otherwise: GetLastError() (result unused), err = GetLastError(),
// FormatMessageA(0x1300, 0, err, 0x400, &msg, 0, 0) (msg takes the place of the third argument), MessageBoxA(0, msg, 0x678bb8, 0x40040), a log line through the object at 0x700390 (slot
// 0x20(0x6789ac, 0x14b), then its slot 0x2c with (r, 0x678bc0, msg), caller-popped), LocalFree(msg); returns got (as left by ReadFile).
static u32 STDCALL fn427ea0(u32 h, void *buf, u32 n) {
  u32 got;
  u32 msg = n;
  if (G(readfile_t, 0x676094)(h, buf, n, &got, 0)) return got;
  G(getlasterror_t, 0x67609c)();
  u32 err = G(getlasterror_t, 0x67609c)();
  G(formatmessage_t, 0x6760ec)(0x1300, 0, err, 0x400, &msg, 0, 0);
  G(messagebox_t, 0x6761bc)(0, (void *)msg, (void *)0x678bb8, 0x40040);
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(lg, 0x20, 0x6789acu, 0x14bu);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[m]\n\tpush $0x678bc0\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [m] "r"(msg), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  G(localfree_t, 0x676128)((void *)msg);
  return got;
}
PCREG(427ea0, fn427ea0);

// 0x453130, thiscall, no args: nothing when byte [this+0x5a] is zero; otherwise clears it, sets byte [this+0x21] = 1 and, with the iterator object at [this+0x52] (slot 0x4c begin,
// slot 0x5c next, stack iterator), calls slot 0x228() on every object found through engine table slot 0x58.
static void THISCALL fn453130(u8 *self) {
  u32 it[3];
  if (!self[0x5a]) return;
  u8 *m = (u8 *)rd32u(self + 0x52);
  self[0x5a] = 0;
  self[0x21] = 1;
  if (!m) return;
  vcall<void>(m, 0x4c, (u32)it);
  u32 id = vcall<u32>((void *)rd32u(self + 0x52), 0x5c, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *obj = vcall<u8 *>(tbl, 0x58, id);
    if (obj) vcall<void>(obj, 0x228);
    id = vcall<u32>((void *)rd32u(self + 0x52), 0x5c, (u32)it);
  } while (it[0] != 0);
}
PCREG(453130, fn453130);

// 0x45a3f0, thiscall, no args: with the iterator object at [this+0x5c] (non-null; slot 0x4c begin, slot 0x5c next, stack iterator) calls slot 0x210(1) on every object found through engine
// table slot 0x58, then [this+0x5c]->slot0xc().
static void THISCALL fn45a3f0(u8 *self) {
  u32 it[3];
  u8 *m = *(u8 **)(self + 0x5c);
  if (m) {
    vcall<void>(m, 0x4c, (u32)it);
    u32 id = vcall<u32>(*(u8 **)(self + 0x5c), 0x5c, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        u8 *obj = vcall<u8 *>(tbl, 0x58, id);
        if (obj) vcall<void>(obj, 0x210, 1u);
        id = vcall<u32>(*(u8 **)(self + 0x5c), 0x5c, (u32)it);
      } while (it[0] != 0);
    }
  }
  vcall<void>(*(u8 **)(self + 0x5c), 0xc);
}
PCREG(45a3f0, fn45a3f0);
