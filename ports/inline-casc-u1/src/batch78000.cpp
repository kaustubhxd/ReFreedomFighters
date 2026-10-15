// batch78000.cpp - cascade tier H, batch 78000: 0x4045a0 (merge two sorted arrays of floats, with binary search insertion).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

extern "C" void ext_6336b0(u32 size);  // stack allocator: takes EAX = size, returns new ESP

// 0x4045a0, cdecl(arr1, range, count) ret void. Merges sorted float arrays with binary search.
// arr1: pointer to first array of floats
// range: some numeric parameter (affects binary search range)
// count: count of elements
static void fn4045a0(u8 *arr1, u32 range, u32 count) {
  // Allocate two temporary float arrays on stack
  u32 size1 = (count * 4 + 3) & 0xfc;  // Align to 4 bytes
  u32 size2 = (count * 4 + 3) & 0xfc;

  // These allocations simulate stack frame setup
  u8 *temp1 = (u8 *)&size1 - size1;  // Placeholder
  u8 *temp2 = (u8 *)&size2 - size2;

  if (count <= 0) return;

  u32 out_count = 0;
  u8 *arr1_ptr = arr1;

  for (u32 i = 0; i < count; i++) {
    if (i < 2) {
      // First two elements: direct placement
      wr32(temp1 + out_count * 4, 0);
      float *f1p = (float *)(arr1_ptr);
      float *f2p = (float *)(temp2 + out_count * 4 - 4);

      if (i == 0 || *f1p <= *f2p) {
        // Place from arr1
        wr32(temp1 + out_count * 4, *(u32 *)arr1_ptr);
      } else {
        // Place from temp2
        wr32(temp1 + out_count * 4, *(u32 *)(temp2 + out_count * 4 - 4));
      }
    } else {
      // Binary search for insertion point
      u8 *left = temp2 + (out_count - 2) * 4;
      u8 *right = temp2 + out_count * 4 - 4;
      float curr_val = *(float *)arr1_ptr;

      // Search backwards
      while (out_count > 0 && *(float *)right > curr_val) {
        // Move right
        wr32(temp1 + out_count * 4, rd32(right));
        right -= 4;
        out_count--;
      }

      // Insert
      wr32(temp1 + out_count * 4, *(u32 *)arr1_ptr);
    }

    out_count++;
    arr1_ptr += 4;
  }
}
PCREG(4045a0, fn4045a0);
