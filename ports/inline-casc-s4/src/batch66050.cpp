// batch66050.cpp - cascade s4 batch 66050: 0x600540, 0x600610 (tier F rows: map insert-with-hint for u16 / u32 keys).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline u32 rh(u8 *p) { return *(u16 *)p; }

extern "C" void THISCALL ext_5fe240(void *t, u32 out, u32 hint, u32 pos, void *key);   // ret 0x10
extern "C" u32 *THISCALL ext_6004a0(void *t, u32 *tmp, void *key);                       // ret 8
extern "C" void THISCALL ext_5fe300(void *t, u32 out, u32 hint, u32 pos, void *key);   // ret 0x10
extern "C" u32 *THISCALL ext_6006e0(void *t, u32 *tmp, void *key);                       // ret 8
extern "C" void THISCALL ext_42ffc0(void *iter);                                         // plain ret

// 0x600540, thiscall(out, hint, key) ret 0xc, returns out (this = t; head = *t, head[5] = first node, head[9] = last node, t[4] = size; node key (u16) at +0xd, right child +9): insert with a position hint in a map keyed by u16.
// hint == first: size != 0 and key < hint.key -> 0x5fe240(out, hint, hint, key). hint == head: last.key < key -> 0x5fe240(out, 0, last, key). Otherwise pred = previous(hint); pred.key < key < hint.key -> 0x5fe240(out, hint, hint, key) when pred.right != 0 else 0x5fe240(out, 0, pred, key).
// Anything else: *out = *0x6004a0(t, &tmp, key) (plain insert).
static u32 THISCALL fn600540(u8 *t, u32 *out, u8 *hint, u8 *key) {
  u8 *head = *(u8 **)t;
  u32 pos_hint = 0, pos = 0;
  bool fast = false;
  if (hint == *(u8 **)(head + 5)) {
    if (rd(t + 4) != 0 && rh(key) < rh(hint + 0xd)) {
      pos_hint = (u32)hint;
      pos = (u32)hint;
      fast = true;
    }
  } else if (hint == head) {
    u8 *last = *(u8 **)(head + 9);
    if (rh(last + 0xd) < rh(key)) {
      pos_hint = 0;
      pos = (u32)last;
      fast = true;
    }
  } else {
    u32 tmp = (u32)hint;
    ext_42ffc0(&tmp);
    u8 *pred = (u8 *)tmp;
    u32 k = rh(key);
    if (rh(pred + 0xd) < k && k < rh(hint + 0xd)) {
      fast = true;
      if (rd(pred + 9) != 0) {
        pos_hint = (u32)hint;
        pos = (u32)hint;
      } else {
        pos_hint = 0;
        pos = (u32)pred;
      }
    }
  }
  if (fast) {
    ext_5fe240(t, (u32)out, pos_hint, pos, key);
    return (u32)out;
  }
  u32 tmp2;
  u32 *res = ext_6004a0(t, &tmp2, key);
  *out = *res;
  return (u32)out;
}
PCREG(600540, fn600540);

// 0x600610, thiscall(out, hint, key) ret 0xc, returns out: the same with u32 keys (callees 0x5fe300 and 0x6006e0).
static u32 THISCALL fn600610(u8 *t, u32 *out, u8 *hint, u8 *key) {
  u8 *head = *(u8 **)t;
  u32 pos_hint = 0, pos = 0;
  bool fast = false;
  if (hint == *(u8 **)(head + 5)) {
    if (rd(t + 4) != 0 && rd(key) < rd(hint + 0xd)) {
      pos_hint = (u32)hint;
      pos = (u32)hint;
      fast = true;
    }
  } else if (hint == head) {
    u8 *last = *(u8 **)(head + 9);
    if (rd(last + 0xd) < rd(key)) {
      pos_hint = 0;
      pos = (u32)last;
      fast = true;
    }
  } else {
    u32 tmp = (u32)hint;
    ext_42ffc0(&tmp);
    u8 *pred = (u8 *)tmp;
    u32 k = rd(key);
    if (rd(pred + 0xd) < k && k < rd(hint + 0xd)) {
      fast = true;
      if (rd(pred + 9) != 0) {
        pos_hint = (u32)hint;
        pos = (u32)hint;
      } else {
        pos_hint = 0;
        pos = (u32)pred;
      }
    }
  }
  if (fast) {
    ext_5fe300(t, (u32)out, pos_hint, pos, key);
    return (u32)out;
  }
  u32 tmp2;
  u32 *res = ext_6006e0(t, &tmp2, key);
  *out = *res;
  return (u32)out;
}
PCREG(600610, fn600610);
