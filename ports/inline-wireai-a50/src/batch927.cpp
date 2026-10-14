// batch927.cpp - 0x62add0 [cdecl, four args (object, s, end, out), returns s32]. Body read in full
// (2026-10-12): the object's class table at +0x4c (one byte per character), the class map at 0x62aef0 (27 entries) and the jump table at
// 0x62aed8. Scanner of a '-' option: returns -1 at the end of the input, 0 with *out = s when the first character is not '-' (or at a
// terminal class), 0xd with *out = s+1 for "->", -2 when a handler needs more characters than remain. Class 1 calls the object's function
// pointer at +0x164 (cdecl: obj, s), class 2 the one at +0x168 with three characters, class 3 the one at +0x16c with four. Those three are
// stood in. The `end` argument is the 4th. The stack cookie is not part of this function.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))

typedef s32(*handler_t)(void *, const u8 *);

// 0x62add0 (name in the map: none).
s32 Scan62add0(u8 *obj, const u8 *s, const u8 *end, const u8 **out) {
  if (s == end) return -1;
  if (*s != '-') {
    *out = s;
    return 0;
  }
  s++;
  if (s == end) return -1;
  for (;;) {
    u8 v = U8(obj, 0x4c + *s);
    u32 idx;
    if (v > 0x1b) {
      idx = 5;
    } else {
      static const u8 map[28] = {0, 0, 5, 5, 5, 1, 2, 3, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4};
      idx = map[v];
    }
    switch (idx) {
      case 0:
        *out = s;
        return 0;
      case 1: {
        if (end - s < 2) return -2;
        handler_t fn = *(handler_t *)(obj + 0x164);
        if (fn(obj, s) != 0) {
          *out = s;
          return 0;
        }
        s += 2;
        break;
      }
      case 2: {
        if (end - s < 3) return -2;
        handler_t fn = *(handler_t *)(obj + 0x168);
        if (fn(obj, s) != 0) {
          *out = s;
          return 0;
        }
        s += 3;
        break;
      }
      case 3: {
        if (end - s < 4) return -2;
        handler_t fn = *(handler_t *)(obj + 0x16c);
        if (fn(obj, s) != 0) {
          *out = s;
          return 0;
        }
        s += 4;
        break;
      }
      case 4: {
        s++;
        if (s == end) return -1;
        if (*s != '-') break;
        s++;
        if (s == end) return -1;
        if (*s == '>') {
          *out = s + 1;
          return 0xd;
        }
        *out = s;
        return 0;
      }
      default:
        s++;
        break;
    }
    if (s == end) return -1;
  }
}
PCREG(62add0, Scan62add0);
