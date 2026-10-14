// batch37030.cpp - cascade s6 batch 37030: 0x4d5c50.
#include "ff.h"

typedef u32 (*hook_t)();
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define F32(o) (*(u32 *)(self + (o)))

static void assertHook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x4d5c50, thiscall(handler) ret 4: reads the central directory of a zip-like archive through the stream object at this+0x15 (slot 0x10 seek, 0x1c eof, 0x14 read(buf, n, h),
// 0xc tell, handle at this+0x11). For every 0x2014b50 record it reads the 0x2a-byte header and the name (length word at +0x18), and calls slot 0x8c of the handler with the
// name unless the record's offset is already in the table at this+0x66 (count this+0x62). The end signatures 0x6054b50 / 0x52756e65 stop the scan, any other signature
// logs error 0x3d8 and the assert hook. Short reads call the assert hook.
static void THISCALL fn4d5c50(u8 *self, u8 *handler) {
  u8 name[0x10004];
  u32 sig;
  u8 hdr[0x2a + 6];
  void *S = *(void **)(self + 0x15);
  (*(v3_t **)S)[0x10 / 4](S, F32(0x11), F32(0x3c) ? F32(0x40) : F32(0x2e), 0);
  S = *(void **)(self + 0x15);
  if ((*(v1_t **)S)[0x1c / 4](S, F32(0x11))) return;
  for (;;) {
    S = *(void **)(self + 0x15);
    if ((*(v3_t **)S)[0x14 / 4](S, (u32)&sig, 4, F32(0x11)) != 4) assertHook();
    if (sig == 0x2014b50) {
      S = *(void **)(self + 0x15);
      u32 pos = (*(v1_t **)S)[0xc / 4](S, F32(0x11));
      S = *(void **)(self + 0x15);
      if ((*(v3_t **)S)[0x14 / 4](S, (u32)hdr, 0x2a, F32(0x11)) != 0x2a) assertHook();
      u16 nl = *(u16 *)(hdr + 0x18);
      if (nl) {
        S = *(void **)(self + 0x15);
        if ((*(v3_t **)S)[0x14 / 4](S, (u32)name, nl, F32(0x11)) != nl) assertHook();
        name[nl] = 0;
        bool known = false;
        u32 cnt = F32(0x62);
        if (cnt) {
          u32 *arr = (u32 *)F32(0x66);
          for (u32 i = 0; i < cnt; i++)
            if (pos == arr[i]) { known = true; break; }
        }
        if (!known) (*(v1_t **)handler)[0x8c / 4](handler, (u32)name);
      }
    } else if (sig == 0x6054b50 || sig == 0x52756e65) {
      return;
    } else {
      u8 *lg = *(u8 **)0x700390;
      void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x696924, 0x3d8);
      (*(cdl_t **)L)[0x2c / 4](L, 0x6969dc);
      assertHook();
    }
    S = *(void **)(self + 0x15);
    if ((*(v1_t **)S)[0x1c / 4](S, F32(0x11))) return;
  }
}
PCREG(4d5c50, fn4d5c50);
