// batch38007.cpp - cascade s8 batch 38007: 0x49a990 (drain a record iterator, logging the highest-priority record each pass).
#include "ff.h"

typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(*log2_t)(void *, u32);
typedef u32(*log5_t)(void *, u32, u32, u32, u32);
#define LOGGER G(u8 *, 0x700390)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

static void *log_stream(u32 line) { return (void *)SLOT(LOGGER, 0x20, v2_t)(LOGGER, 0x68ea50, line); }
static void log_str(u32 line, u32 fmt) {
  void *st = log_stream(line);
  (*(log2_t **)st)[0x2c / 4](st, fmt);
}
static void log_rec(u32 line, u32 fmt, u8 *rec, u8 *obj) {
  void *st = log_stream(line);
  (*(log5_t **)st)[0x2c / 4](st, fmt, *(u32 *)(rec + 4), *(u32 *)(rec + 8), *(u32 *)obj);
}

// 0x49a990, thiscall, no args, plain ret. Logs three lines, then (when this+0x138 holds an iterator object) repeats: scans its records (slot 0x4c to start, slot 0x64 to
// advance, with a stack cursor) for the one with the largest +4 key, logs it by its type ([record]+4 == 1 or 0) and releases it (slot 0x20), until slot 0x14 reports no more;
// then deletes the iterator (slot 0, flag 1). Ends with three more log lines.
static void THISCALL fn49a990(u8 *self) {
  log_str(0x25a, 0x68ea7c);
  log_str(0x25b, 0x68eabc);
  log_str(0x25c, 0x68ea7c);
  u8 *it = *(u8 **)(self + 0x138);
  if (it) {
    if (SLOT(it, 0x14, v0_t)(it)) {
      u8 *cur;
      do {
        cur = *(u8 **)(self + 0x138);
        u8 *best = 0;
        s32 bestKey = -1;
        u32 cursor[3];
        if (cur) {
          SLOT(cur, 0x4c, v1_t)(cur, (u32)cursor);
          cur = *(u8 **)(self + 0x138);
          u8 *r = (u8 *)SLOT(cur, 0x64, v1_t)(cur, (u32)cursor);
          if (r) {
            do {
              s32 key = *(s32 *)(r + 4);
              if (bestKey < key) {
                bestKey = key;
                best = r;
              }
              cur = *(u8 **)(self + 0x138);
              r = (u8 *)SLOT(cur, 0x64, v1_t)(cur, (u32)cursor);
            } while (r);
            if (best) {
              u8 *obj = *(u8 **)best;
              u32 type = *(u32 *)(obj + 4);
              if (type == 1) log_rec(0x272, 0x68eafc, best, obj);
              else if (type == 0) log_rec(0x277, 0x68eb34, best, obj);
              cur = *(u8 **)(self + 0x138);
              SLOT(cur, 0x20, v1_t)(cur, (u32)best);
            }
          }
        }
        cur = *(u8 **)(self + 0x138);
      } while (SLOT(cur, 0x14, v0_t)(cur));
    }
    it = *(u8 **)(self + 0x138);
    if (it) SLOT(it, 0, v1_t)(it, 1);
  }
  log_str(0x284, 0x68ea7c);
  log_str(0x285, 0x68eb6c);
  log_str(0x286, 0x68ea7c);
}
PCREG(49a990, fn49a990);
