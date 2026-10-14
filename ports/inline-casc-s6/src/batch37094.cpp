// batch37094.cpp - cascade s6 batch 37094: 0x5f2230.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5f2230, thiscall(), plain ret: registers the object's properties with its own vtable: seven slot-0xb0 calls (name, group, two type strings, then 3/4/1/0 style flags; the last
// two take the value at [[this+0xc]+0xa8] and that value + 4) and five slot-0xb4 calls (name, type, alias strings). All arguments are string / constant addresses of the exe.
static void THISCALL fn5f2230(u8 *t) {
  vcall<void>(t, 0xb0, 0x6b8774u, 0x6b876cu, 0x677b5au, 0x677b5au, 3u, 4u, 1u, 0u);
  vcall<void>(t, 0xb0, 0x6b8698u, 0x6b876cu, 0x677b5au, 0x6b877cu, 3u, 4u, 1u, 0u);
  vcall<void>(t, 0xb0, 0x6b869cu, 0x6b878cu, 0x677b5au, 0x6b8788u, 3u, 4u, 1u, 0u);
  vcall<void>(t, 0xb0, 0x6b8794u, 0x6b878cu, 0x677b5au, 0x677b5au, 3u, 4u, 1u, 0u);
  vcall<void>(t, 0xb0, 0x6b879cu, 0u, 0u, 0u, 3u, 4u, 1u, 0u);
  vcall<void>(t, 0xb0, 0x67a14cu, 0x6b87a8u, 0x677b5au, 0x677b5au, 4u, 4u, 1u, D32(*(u8 **)(t + 0xc), 0xa8));
  vcall<void>(t, 0xb0, 0x6b87b0u, 0u, 0u, 0u, 4u, 0u, 1u, D32(*(u8 **)(t + 0xc), 0xa8) + 4);
  vcall<void>(t, 0xb4, 0x6b87bcu, 0x677b5au, 0x69c7f4u, 0x6b8698u, 0x677b5au);
  vcall<void>(t, 0xb4, 0x6b87c8u, 0x6b87bcu, 0x69c7f4u, 0x6b8698u, 0x6b87bcu);
  vcall<void>(t, 0xb4, 0x6b87dcu, 0x677b5au, 0x6b87d4u, 0u, 0u);
  vcall<void>(t, 0xb4, 0x6b87f4u, 0x677b5au, 0x6b87e8u, 0u, 0u);
  vcall<void>(t, 0xb4, 0x6b8800u, 0x677b5au, 0x69c7f4u, 0u, 0u);
}
PCREG(5f2230, fn5f2230);
