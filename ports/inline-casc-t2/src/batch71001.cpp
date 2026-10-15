// batch71001.cpp - cascade t2 (Haiku): tier H float functions 0x526360.
#include "ff.h"

extern "C" void STDCALL ext_516620(u8 *dest, const u8 *src);  // copy function, ret 4

// 0x526360, thiscall, no args, uses GS cookie:
// Two loops over structures. Each loop:
// - Loads three floats from structure
// - Calls engine vtable slot 0x84 with the floats
// - Calls ext_516620 to copy the floats
// - Advances pointers and counts

static void THISCALL fn526360(u8 *self) {
  u32 engine_addr = *(u32 *)0x70039c;
  u8 *table = *(u8 **)(engine_addr + 0x9b);

  typedef void(THISCALL *vcall_t)(u8 *, u8 *);
  vcall_t vcall_fn = (vcall_t)(*(u32 *)table + 0x84);

  // First loop (count at self+0x8c)
  s32 count1 = *(s32 *)(self + 0x8c);
  if (count1 > 0) {
    u8 *base_ptr1 = self + 0xbd;
    u8 *cur_ptr1 = self + 0x7d1;

    for (int i = 0; i < count1; i++) {
      // Load three floats from cur_ptr1 - 8, cur_ptr1 - 4, cur_ptr1
      u8 local_floats[12];
      *(float *)&local_floats[0] = *(float *)(cur_ptr1 - 8);
      *(float *)&local_floats[4] = *(float *)(cur_ptr1 - 4);
      *(float *)&local_floats[8] = *(float *)cur_ptr1;

      // Call vcall_fn
      vcall_fn(table, local_floats);

      // Call ext_516620
      ext_516620(base_ptr1, local_floats);

      // Advance
      base_ptr1 += 0xde;
      cur_ptr1 += 0x163;
    }
  }

  // Second loop (count at self+0x90)
  s32 count2 = *(s32 *)(self + 0x90);
  if (count2 > 0) {
    u8 *base_ptr2 = self + 0x435;
    u8 *cur_ptr2 = self + 0xd5d;

    for (int i = 0; i < count2; i++) {
      // Load three floats
      u8 local_floats[12];
      *(float *)&local_floats[0] = *(float *)(cur_ptr2 - 8);
      *(float *)&local_floats[4] = *(float *)(cur_ptr2 - 4);
      *(float *)&local_floats[8] = *(float *)cur_ptr2;

      // Call vcall_fn
      vcall_fn(table, local_floats);

      // Call ext_516620
      ext_516620(base_ptr2, local_floats);

      // Advance
      base_ptr2 += 0xde;
      cur_ptr2 += 0x133;
    }
  }
}
PCREG(526360, fn526360);
