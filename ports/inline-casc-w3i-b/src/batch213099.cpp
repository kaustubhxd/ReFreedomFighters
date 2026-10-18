#include "ff.h"

// 0x6309a0: cdecl(s, desc) -> void: zlib's gen_bitlen (deflate trees.c). s fields: bl_count ush[16] at +0xb34, heap int[573] at +0xb54, heap_max at +0x144c,
// opt_len at +0x16a0, static_len at +0x16a4. desc = {dyn_tree, max_code, stat_desc}; stat_desc = {static_tree, extra_bits, extra_base, elems, max_length}.
// ct_data is 4 bytes: ush Freq at +0, ush Dad/Len at +2. Computes each code length under max_length, counting overflows, repairs the length counts and reassigns lengths.
struct ct_data {
  u16 Freq;
  u16 Len;
};

extern "C" void fn_6309a0(u8 *s, u32 *desc) {
  ct_data *tree = (ct_data *)desc[0];
  int max_code = (int)desc[1];
  u32 *sd = (u32 *)desc[2];
  const ct_data *stree = (const ct_data *)sd[0];
  const int *extra = (const int *)sd[1];
  int base = (int)sd[2];
  int max_length = (int)sd[4];
  u16 *bl_count = (u16 *)(s + 0xb34);
  int *heap = (int *)(s + 0xb54);
  int h, n, m, bits, xbits;
  u16 f;
  int overflow = 0;
  for (int i = 0; i < 16; i++) bl_count[i] = 0;
  tree[heap[*(int *)(s + 0x144c)]].Len = 0;
  for (h = *(int *)(s + 0x144c) + 1; h < 573; h++) {
    n = heap[h];
    bits = tree[tree[n].Len].Len + 1;
    if (bits > max_length) {
      bits = max_length;
      overflow++;
    }
    tree[n].Len = (u16)bits;
    if (n > max_code) continue;
    bl_count[bits]++;
    xbits = 0;
    if (n >= base) xbits = extra[n - base];
    f = tree[n].Freq;
    *(u32 *)(s + 0x16a0) += (u32)f * (u32)(bits + xbits);
    if (stree) *(u32 *)(s + 0x16a4) += (u32)f * (u32)(stree[n].Len + xbits);
  }
  if (overflow == 0) return;
  do {
    bits = max_length - 1;
    while (bl_count[bits] == 0) bits--;
    bl_count[bits]--;
    bl_count[bits + 1] += 2;
    bl_count[max_length]--;
    overflow -= 2;
  } while (overflow > 0);
  for (bits = max_length; bits != 0; bits--) {
    n = bl_count[bits];
    while (n != 0) {
      m = heap[--h];
      if (m > max_code) continue;
      if ((unsigned)tree[m].Len != (unsigned)bits) {
        *(u32 *)(s + 0x16a0) += ((u32)bits - tree[m].Len) * tree[m].Freq;
        tree[m].Len = (u16)bits;
      }
      n--;
    }
  }
}
PCREG(6309a0, fn_6309a0);
