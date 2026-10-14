// batch35013.cpp - cascade s5 batch 35013: 0x5fe880 (GUESS find a record by id in a chained table and fill a view of it).
#include "ff.h"

typedef u32 (*hook_t)();
static inline u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5fe880, stdcall(out, id, node) ret 0xc, returns EAX. Walk the chain node -> [node+0x9c]: base = [node+0xd4]; id < base calls the assert hook 0x7003b0 and retries the same node
// (int3 when the hook is null); id - base < [node+0xd8] selects the record edi = [node+0xe8][id - base] + [node+0x100]: out[0xe] = node, out dword 0 = *edi, out word 4 = word edi[4],
// out[6] = edi + 6, out[0xa] = edi + 2 * (n + 3 + (~n & 1)) with n = word out[4]; EAX = that pointer. End of the chain: the assert hook is called and its EAX is returned.
static u32 STDCALL fn5fe880(u8 *out, u32 id, u8 *node) {
  while (node) {
    u32 base = *(u32 *)(node + 0xd4);
    if (id < base) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
      continue;
    }
    if (id - base < *(u32 *)(node + 0xd8)) {
      u8 *edi = (u8 *)(((u32 *)*(u8 **)(node + 0xe8))[id - base] + *(u32 *)(node + 0x100));
      wr32(out + 0xe, (u32)node);
      *(u32 *)out = *(u32 *)edi;
      *(u16 *)(out + 4) = *(u16 *)(edi + 4);
      wr32(out + 6, (u32)(edi + 6));
      u32 n = *(u16 *)(out + 4);
      u32 r = (u32)edi + (n + 3 + (~n & 1)) * 2;
      wr32(out + 0xa, r);
      return r;
    }
    node = *(u8 **)(node + 0x9c);
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(5fe880, fn5fe880);
