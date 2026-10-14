// batch35145.cpp - cascade s5 batch 35145: 0x534480 (GUESS read n values from a stream into an indexed pool, linking them into a circular list).
#include "ff.h"

typedef void(THISCALL *v1p_t)(void *, u32 *);

// 0x534480, thiscall(s) ret 4, returns the list head (0 when n is zero). Pool: [0] = used count, [4] = free-list head index, 8-byte entries at +8 + 8i (value, link). n = s slot 0x48 read into a local; for each of the n values (s slot 0x48 into a local, zeroed first):
// idx = [4]; count++; [4] = link(idx) & 0x7fffffff; link(idx) = 0xfffffffe; value(idx) = v; when head is 0 or 0x80000000 the entry becomes a single-element ring (link 0x80000000, head = idx), otherwise it is spliced in
// after the head (link(idx) = link(head), link(head) = idx).
static u32 THISCALL fn534480(u8 *self, u8 *s) {
  u32 n, v;
  u32 head = 0;
  (*(v1p_t **)s)[0x48 / 4](s, &n);
  if (n == 0) return head;
  do {
    v = 0;
    (*(v1p_t **)s)[0x48 / 4](s, &v);
    u32 idx = *(u32 *)(self + 4);
    u32 *e = (u32 *)(self + idx * 8);
    u32 link = e[3];
    *(u32 *)self += 1;
    *(u32 *)(self + 4) = link & 0x7fffffff;
    e[3] = 0xfffffffe;
    *(u32 *)(self + idx * 8 + 8) = v;
    if (head == 0x80000000u || head == 0) {
      *(u32 *)(self + idx * 8 + 0xc) = 0x80000000;
      head = idx;
    } else {
      *(u32 *)(self + idx * 8 + 0xc) = *(u32 *)(self + head * 8 + 0xc);
      *(u32 *)(self + head * 8 + 0xc) = idx;
    }
    n -= 1;
  } while (n != 0);
  return head;
}
PCREG(534480, fn534480);
