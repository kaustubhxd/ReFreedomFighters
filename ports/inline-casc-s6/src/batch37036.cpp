// batch37036.cpp - cascade s6 batch 37036: 0x4d3090.
#include "ff.h"

extern "C" u8 *THISCALL ext_4d2b40(u8 *self, u8 *p, u32 n);     // ret 8
extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);            // memcpy thunk, cdecl
typedef void *(*memmove_t)(void *, const void *, u32);
typedef u32 (*hook_t)();
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v2b_t)(void *, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define F32(o) (*(u32 *)(self + (o)))

// 0x4d3090, thiscall(stream) ret 4: packs the records of a stream into a byte arena. this: +8 arena, +0xc used, +4 capacity. Each record is {u32 len; len bytes} read through
// slot 0x18 of the stream until len == -1 (slot 0x40 gives its type); the stored entry {u32 size, u8 valid, data[size-5]} has size = rec[2] + 0x11 + rec[0]; an entry
// found by 0x4d2b40 with the same size is overwritten in place, otherwise it is invalidated and the record is appended; when the arena would overflow, the valid
// entries are compacted first (memmove through the CRT import 0x676278) and error 0x33b / the assert hook are used when it still does not fit. Slot 0xc of this starts.
static void THISCALL fn4d3090(u8 *self, void *S) {
  (*(v0_t **)self)[0xc / 4](self);
  u32 len;
  (*(v2_t **)S)[0x18 / 4](S, (u32)&len, 4);
  while (len != 0xffffffffu) {
    u8 *buf = (u8 *)__builtin_alloca(len);
    (*(v2_t **)S)[0x18 / 4](S, (u32)buf, len);
    u32 type;
    (*(v1_t **)S)[0x40 / 4](S, (u32)&type);
    u32 b0 = *(u32 *)buf;
    u32 total = *(u32 *)(buf + 8) + 0x11 + b0;
    *(u32 *)(buf + 4) = 0x6e7a30 + type * 20;
    u8 *ent = ext_4d2b40(self, buf + 0xc, b0);
    bool store = true;
    if (ent && *(u32 *)ent == total) {
      // overwrite in place
    } else {
      if (ent) ent[4] = 0;
      if (F32(0xc) + total > F32(4)) {
        u32 dst = 0, src = 0;
        if (F32(0xc) > 0) {
          do {
            u8 *e = (u8 *)F32(8) + src;
            u32 sz = *(u32 *)e;
            src += sz;
            if (e[4] != 0) {
              u8 *d = (u8 *)F32(8) + dst;
              dst += sz;
              if (src != dst) G(memmove_t, 0x676278)(d, e, sz);
            }
          } while (src < F32(0xc));
        }
        F32(0xc) = dst;
        if (total + dst > F32(4)) {
          u8 *lg = *(u8 **)0x700390;
          void *L = (void *)(*(v2b_t **)lg)[0x20 / 4](lg, 0x696418, 0x33b);
          (*(cdl_t **)L)[0x2c / 4](L, 0x696530);
          hook_t h = G(hook_t, 0x7003b0);
          if (!h) __asm__ volatile("int3");
          h();
          store = false;
        }
      }
      if (store) {
        ent = (u8 *)F32(8) + F32(0xc);
        F32(0xc) += total;
        *(u32 *)ent = total;
        ent[4] = 1;
      }
    }
    if (store) ext_634d22(ent + 5, buf, total - 5);
    (*(v2_t **)S)[0x18 / 4](S, (u32)&len, 4);
  }
}
PCREG(4d3090, fn4d3090);
