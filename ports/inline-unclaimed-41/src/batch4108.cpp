// batch4108.cpp - unclaimed-41 batch 8 (slice 13): 0x557c90 (name not in the map; GUESS).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *table, u32 index);                      // array accessor, original code
extern "C" u32 THISCALL ext_59dae0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5); // five stack args, ret 0x14; checksum stub
extern "C" void THISCALL ext_5002f0(u8 *self, u32 a1);                          // one stack argument; checksum stub

// 0x557c90 (GUESS name): thiscall, one stack argument x (ret 4). With s = [x+4]:
//   ebx = [acc(s,0)], edi = [acc(s,1)], esi = [acc(s,2)], d = [acc(s,3)]  (acc = 0x5003d0)
//   r = ext_59dae0(ecx = [this+0x1c], ebx, edi, esi, 0, d)   (five stack arguments)
//   p = acc([x+8], 0);  ext_5002f0(p, r)                (the pushed r is the one argument)
static void THISCALL fn557c90(u8 *self, u8 *x) {
  u8 *s = *(u8 **)(x + 4);
  u32 ebx = *(u32 *)ext_5003d0(s, 0);
  u32 edi = *(u32 *)ext_5003d0(s, 1);
  u32 esi = *(u32 *)ext_5003d0(s, 2);
  u32 d = *(u32 *)ext_5003d0(*(u8 **)(x + 4), 3);
  u32 r = ext_59dae0(*(u8 **)(self + 0x1c), ebx, edi, esi, 0u, d);   // ecx = the pointer stored at this+0x1c (mov ecx,[ecx+0x1c])
  u8 *p = ext_5003d0(*(u8 **)(x + 8), 0);
  ext_5002f0(p, r);
}
PCREG(557c90, fn557c90);
