// batch220007.cpp - Codex-x3a hand port of 0x6206e0.
// A cdecl grow operation for a chained output-buffer chunk.  Chunks have
// {next, capacity, data...}; the owner keeps {current, free, end, mark,
// cursor, allocator}.  The allocator table contains cdecl {alloc, realloc}.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_634d22(u32 dst, u32 src, u32 n);

static inline u32 load32_6206e0(u32 p) {
  u32 v;
  __builtin_memcpy(&v, (const void *)(u32)p, sizeof v);
  return v;
}

static inline void store32_6206e0(u32 p, u32 v) {
  __builtin_memcpy((void *)(u32)p, &v, sizeof v);
}

typedef u32 (__attribute__((cdecl)) *alloc_6206e0)(u32 n);
typedef u32 (__attribute__((cdecl)) *realloc_6206e0)(u32 old_chunk, u32 n);

extern "C" u32 __attribute__((cdecl)) lifted_6206e0(u32 s) {
  u32 free_chunk = load32_6206e0(s + 4);
  if (free_chunk != 0) {
    u32 cursor = load32_6206e0(s + 0x10);
    if (cursor == 0) {
      store32_6206e0(s, free_chunk);
      const u32 next = load32_6206e0(free_chunk);
      store32_6206e0(s + 4, next);
      store32_6206e0(free_chunk, 0);
      cursor = free_chunk + 8;
      store32_6206e0(s + 0x10, cursor);
      store32_6206e0(s + 0x0c, cursor);
      store32_6206e0(s + 8, cursor + load32_6206e0(free_chunk + 4));
      return 1;
    }

    const u32 available = load32_6206e0(s + 8) - cursor;
    if ((s32)available < (s32)load32_6206e0(free_chunk + 4)) {
      const u32 next = load32_6206e0(free_chunk);
      const u32 old_chunk = load32_6206e0(s);
      store32_6206e0(free_chunk, old_chunk);
      store32_6206e0(s, free_chunk);
      store32_6206e0(s + 4, next);
      ext_634d22(free_chunk + 8, cursor, available);
      store32_6206e0(s + 0x0c,
                      load32_6206e0(s + 0x0c) + free_chunk - cursor + 8);
      cursor = free_chunk + 8;
      store32_6206e0(s + 0x10, cursor);
      store32_6206e0(s + 8, cursor + load32_6206e0(free_chunk + 4));
      return 1;
    }
  }

  const u32 old_chunk = load32_6206e0(s);
  u32 cursor = load32_6206e0(s + 0x10);
  if (old_chunk != 0 && cursor == old_chunk + 8) {
    const u32 capacity = load32_6206e0(s + 8) - cursor;
    const u32 allocator = load32_6206e0(s + 0x14);
    const u32 grown = (*(realloc_6206e0)load32_6206e0(allocator + 4))
        (old_chunk, capacity + capacity + 8);
    store32_6206e0(s, grown);
    if (grown == 0) return 0;
    const u32 new_capacity = capacity + capacity;
    store32_6206e0(grown + 4, new_capacity);
    store32_6206e0(s + 0x0c,
                    load32_6206e0(s + 0x0c) + grown - cursor + 8);
    cursor = grown + 8;
    store32_6206e0(s + 0x10, cursor);
    store32_6206e0(s + 8, cursor + new_capacity);
    return 1;
  }

  const u32 available = load32_6206e0(s + 8) - cursor;
  const u32 capacity = (s32)available < 0x400 ? 0x400u : available + available;
  const u32 allocator = load32_6206e0(s + 0x14);
  const u32 fresh = (*(alloc_6206e0)load32_6206e0(allocator))(capacity + 8);
  if (fresh == 0) return 0;
  store32_6206e0(fresh + 4, capacity);
  store32_6206e0(fresh, old_chunk);
  const u32 mark = load32_6206e0(s + 0x0c);
  cursor = load32_6206e0(s + 0x10);
  store32_6206e0(s, fresh);
  if (mark != cursor) ext_634d22(fresh + 8, cursor, mark - cursor);
  store32_6206e0(s + 0x0c, mark + fresh - cursor + 8);
  cursor = fresh + 8;
  store32_6206e0(s + 0x10, cursor);
  store32_6206e0(s + 8, cursor + capacity);
  return 1;
}
PCREG(6206e0, lifted_6206e0);
