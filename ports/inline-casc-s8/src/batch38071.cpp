// batch38071.cpp - cascade s8 batch 38071: 0x5fed20 (replay a list of ids: resolve each to an object and store its value into the next free slot of a tagged vector).
#include "ff.h"

extern "C" u32 THISCALL ext_5ffb00(u8 *child, u32 id);   // ret 4
extern "C" u8 *STDCALL ext_602d30(u32 v);                // ret 4
extern "C" u8 *THISCALL ext_602ff0(u8 *o);
extern "C" u8 *THISCALL ext_602d70(u8 *o);
extern "C" void THISCALL ext_5f52f0(u8 *vec, u32 *p);    // ret 4
extern "C" void THISCALL ext_5f5250(u8 *vec, u32 *p);    // ret 4
extern "C" void ext_42ab62(u32 msg);                     // cdecl
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(*log3_t)(void *, u32, u32);
typedef u32 (*hook_t)();
typedef int (*stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
// stores the value of `o` (slot 0x24) into the next entry of the tagged vector {+0 entries of 8 bytes (value, tag byte), +4 capacity, +8 size}; an entry tagged 4 is released first (slot 0x28 of its value); then o's slot 0x28
static void store(u8 *vec, u8 *o) {
  if (!(W(vec, 8) < W(vec, 4))) {
    ext_42ab62(0x6b89b4);
    assert_hook();
  }
  u32 idx = W(vec, 8);
  u8 *arr = *(u8 **)vec;
  W(vec, 8) = idx + 1;
  u8 tag = arr[idx * 8 + 4];
  if (tag == 0 || tag == 4) {
    if (tag == 4) {
      u8 *old = *(u8 **)(arr + idx * 8);
      SLOT(old, 0x28, v0_t)(old);
    }
    *(u32 *)(arr + idx * 8) = SLOT(o, 0x24, v0_t)(o);
    arr[idx * 8 + 4] = 4;
  }
  SLOT(o, 0x28, v0_t)(o);
}

// 0x5fed20, stdcall(X, node, ids, vec) ret 0x10. ids = {u16 count, unaligned dword -> u16 id array}. node: +0x9c child, +0xa0 base id, +0xa8 count, +0xac table, +0xb0 addend.
// The stale values the original reads from its own frame (ebx kept across iterations; the last in-range table value) are carried in locals.
static void STDCALL fn5fed20(u8 *X, u8 *node, u8 *ids, u8 *vec) {
  u32 ebx = 0, last8 = 0;
  if (0 < *(u16 *)ids) {
    u32 i = 0;
    do {
      u32 id = ((u16 *)UN32(ids, 2))[i];
      if (W(node, 0xa8) != 0 && !(W(node, 0xa0) > id)) {
        u32 cx = (u16)((u16)id - *(u16 *)(node + 0xa0));
        if (cx < W(node, 0xa8)) {
          last8 = ((u32 *)W(node, 0xac))[cx] + W(node, 0xb0);
          ebx = last8;
        } else {
          u8 *lg = G(u8 *, 0x700390);
          void *st = (void *)SLOT(lg, 0x20, v2_t)(lg, 0x6b9420, 0x137);
          (*(log3_t **)st)[0x2c / 4](st, 0x69c6b0, 0x6b9474);
          assert_hook();
          ebx = last8;
        }
      } else {
        u8 *child = (u8 *)W(node, 0x9c);
        if (child) ebx = ext_5ffb00(child, id);
        else assert_hook();
      }
      u8 *s = ext_602ff0(ext_602d30(ebx));
      if (s) {
        if (W(s, 0x1c)) {
          u8 *o = (u8 *)SLOT(X, 0, v2_t)(X, ebx, 0);
          store(vec, o);
        } else {
          u32 z = 0;
          if (ext_602d70(s) && imp_stricmp((const char *)ext_602d70(s), (const char *)0x6b9044) == 0) ext_5f52f0(vec, &z);
          else ext_5f5250(vec, &z);
        }
      } else {
        u8 *o = (u8 *)SLOT(X, 0x30, v1_t)(X, ebx);
        if (!o) assert_hook();
        store(vec, o);
      }
      i++;
    } while (i < *(u16 *)ids);
  }
}
PCREG(5fed20, fn5fed20);
