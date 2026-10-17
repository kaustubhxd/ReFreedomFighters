// batch0616.cpp - fresh-06 batch 16 (docs/20-fresh-06.md): functions that call imports through the IAT (stubbed with
// pe_emu stub_import in the specs). Callee pop counts from tools/rets.py.
#include "ff.h"

// 0x6078a0 (no map name; GUESS: Steam start-up check, cdecl, returns bool): SteamAPI_RestartAppIfNecessary(0x1490c4)
// true -> false (the game restarts through Steam); else SteamAPI_Init: true -> true, false -> message 0x6b9ee4
// through 0x42ab62 (cdecl) and false.
typedef u8 (*restartFn)(u32);
typedef u8 (*initFn)();
extern "C" void ext_42ab62(u32 msg);
static u8 steamStartup() {
  if (G(restartFn, 0x67649c)(0x1490c4)) return 0;
  if (G(initFn, 0x6764a4)()) return 1;
  ext_42ab62(0x6b9ee4);
  return 0;
}
PCREG(6078a0, steamStartup);

// 0x6528a0 (no map name; GUESS: pick a free window class name, thiscall with hInstance in ECX): once (flag 0x7f6410),
// the 24-byte base name at 0x6c3a18 is copied to 0x7f5a10; then for i = 0..999 the number is formatted (sprintf
// 0x42ac56 at 0x7f5a1c with format 0x6c3a30) until GetClassInfoExA(hInstance, name, &wc) fails (wc.cbSize = 0x30, the
// rest unset).
typedef s32 (STDCALL *gciFn)(u32, const char *, void *);
extern "C" void ext_42ac56(char *buf, u32 fmt, u32 i);
static void THISCALL freeWindowClassName(u32 hinst) {
  u32 wc[12];
  wc[0] = 0x30;
  if (G(u32, 0x7f6410)) return;
  for (u32 k = 0; k < 4; ++k) G(u32, 0x7f5a10 + 4 * k) = G(u32, 0x6c3a18 + 4 * k);
  G(u32, 0x7f6410) = 1;
  G(u32, 0x7f5a20) = G(u32, 0x6c3a28);
  G(u32, 0x7f5a24) = G(u32, 0x6c3a2c);
  gciFn gci = G(gciFn, 0x67618c);
  for (u32 i = 0; i != 1000; ++i) {
    ext_42ac56((char *)0x7f5a1c, 0x6c3a30, i);
    if (!gci(hinst, (const char *)0x7f5a10, wc)) break;
  }
}
PCREG(6528a0, freeWindowClassName);

// 0x4cfbe0 (no map name; GUESS: get a 2 MB block, thiscall): the used size (+4) grows by 0x200000; a free block from
// the stack at +8 (count +0x1c8) is reused, else (unless +0x207 already counts 10000 or more: 0) a new one is
// malloc'd (0x200020 bytes, aligned up to 16 with the raw pointer kept just below), handed to the next descriptor
// (+0xc628 array, index +0xd628, block at +0xc) and to the tracker at +0x1ea (slot 0). Either way the block goes
// through 0x4cfb30(block, 0x200000), whose EAX is returned.
typedef void *(*mallocFn)(u32);
extern "C" void *THISCALL ext_4cfb30(void *self, void *blk, u32 size);
static void *THISCALL bigBlockGet(u8 *self) {
  *(u32 *)(self + 4) += 0x200000;
  u32 n = *(u32 *)(self + 0x1c8);
  if (n) {
    --n;
    *(u32 *)(self + 0x1c8) = n;
    return ext_4cfb30(self, *(void **)(self + 8 + n * 4), 0x200000);
  }
  if (*(u32 *)(self + 0x207) >= 10000) return 0;
  u8 *raw = (u8 *)G(mallocFn, 0x6762f0)(0x200020);
  u8 *p = (u8 *)((u32)(raw + 0x13) & 0xfffffff0u);
  *(u8 **)(p - 4) = raw;
  u32 k = *(u32 *)(self + 0xd628);
  u8 *d = *(u8 **)(self + 0xc628 + k * 4);
  *(u32 *)(self + 0xd628) = k + 1;
  *(u8 **)(d + 0xc) = p;
  vcall<void>(self + 0x1ea, 0, d);
  return ext_4cfb30(self, p, 0x200000);
}
PCREG(4cfbe0, bigBlockGet);
