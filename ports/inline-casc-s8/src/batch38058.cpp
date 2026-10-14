// batch38058.cpp - cascade s8 batch 38058: 0x606ee0 (std::vector<u32>::insert(pos, n, value)).
#include "ff.h"

extern "C" void FASTCALL ext_606a30(u32 *src, u32 *dst, u32 *end);        // uninitialized copy helper, ret 4
extern "C" void FASTCALL ext_6069f0(u32 *first, u32 *last, u32 *valp);    // fill helper, ret 4
extern "C" u32 *THISCALL ext_6014a0(u32 *vec, u32 bytes);                 // allocate, ret 4
extern "C" void THISCALL ext_54f870(u32 *vec, u32 *p, u32 bytes);         // free, ret 8

// 0x606ee0, thiscall(pos, n, valptr) ret 0xc. v = {+0 first, +4 last, +8 capacity end} of u32. n == 0 does nothing. With room for n more elements: when the tail after pos is longer than n the last
// n elements are copied up (0x606a30), the rest shifted up and [pos, pos + n) filled (0x6069f0); otherwise n - tail copies of the value are appended, the tail is copied behind them and [pos, old
// last) is filled. Without room a buffer of size + max(size, n) elements is allocated (0x6014a0), prefix / n copies of the value / suffix are copied, the old buffer is freed (0x54f870) and the
// three fields replaced. (The in-place case passes the value by address of a local copy, the reallocating one by the caller's pointer.)
static void THISCALL fn606ee0(u32 *v, u32 *pos, u32 n, u32 *valptr) {
  if (n == 0) return;
  u32 freeel = (v[2] - v[1]) >> 2;
  if (freeel >= n) {
    u32 value = *valptr;
    u32 tail = (u32)((s32)(v[1] - (u32)pos) >> 2);
    u32 *last = (u32 *)v[1];
    if (tail > n) {
      u32 *src = last - n;
      ext_606a30(src, last, last);
      v[1] += n * 4;
      s32 cnt = (s32)((u32)src - (u32)pos) >> 2;
      u32 *d = last;
      u32 *s = src;
      for (; cnt > 0; cnt--) {
        s--;
        d--;
        *d = *s;
      }
      ext_6069f0(pos, pos + n, &value);
      return;
    }
    u32 extra = n - tail;
    u32 *p = last;
    for (u32 k = extra; k != 0; k--) {
      if (p) *p = value;
      p++;
    }
    v[1] += extra * 4;
    ext_606a30(pos, last, (u32 *)v[1]);
    v[1] += tail * 4;
    ext_6069f0(pos, last, &value);
    return;
  }
  u32 size = (u32)((s32)(v[1] - v[0]) >> 2);
  u32 cap = (size < n ? n : size) + size;
  u32 *nb = cap == 0 ? 0 : ext_6014a0(v, cap * 4);
  u32 *first = (u32 *)v[0];
  u32 *d = nb;
  u32 before = (u32)((u32)pos - (u32)first + 3) >> 2;
  if (first > pos) before = 0;
  u32 *s = first;
  for (u32 k = 0; k != before; k++) {
    if (d) *d = *s;
    d++;
    s++;
  }
  for (u32 k = n; k != 0; k--) {
    if (d) *d = *valptr;
    d++;
  }
  u32 after = (u32)(v[1] - (u32)pos + 3) >> 2;
  if (pos > (u32 *)v[1]) after = 0;
  u32 *ps = pos;
  for (u32 k = 0; k != after; k++) {
    if (d) *d = *ps;
    d++;
    ps++;
  }
  u32 oldn = (u32)((s32)(v[2] - v[0]) >> 2);
  if (oldn) ext_54f870(v, (u32 *)v[0], oldn * 4);
  v[1] = (u32)d;
  v[0] = (u32)nb;
  v[2] = (u32)(nb + cap);
}
PCREG(606ee0, fn606ee0);
