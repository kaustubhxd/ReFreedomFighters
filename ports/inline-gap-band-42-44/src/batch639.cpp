// batch639.cpp - band 0x421000-0x441000, batch 639: one function.
//   0x434d10 (thiscall, one arg, returns eax): loops through vtable slots 0x4c, 0x64, 0x14.
//     Tests arg, loops while slot[0x64] returns non-null and slot[0x14] returns false.
#include "ff.h"

typedef void(THISCALL *vslot_4c_t)(void *obj, void *local);
typedef void *(THISCALL *vslot_64_t)(void *obj, void *local);
typedef u8(THISCALL *vslot_14_t)(void *obj, u32 arg);

static void *THISCALL func_434d10(u8 *self, u32 arg1) {
  u8 local_area[0xc];
  void *member, *result_obj;

  // Test arg1
  if (!arg1) {
    return 0;
  }

  // Load member from [self+0x4]
  member = *(void **)(self + 0x4);
  if (!member) {
    return 0;
  }

  // Call vtable[0x4c] on member with &local_area
  void **vtable = *(void ***)member;
  ((vslot_4c_t)vtable[0x4c / 4])(member, local_area);

  // Call vtable[0x64] on member with &local_area
  result_obj = ((vslot_64_t)vtable[0x64 / 4])(member, local_area);

  // Loop while result_obj is non-null
  while (result_obj) {
    // Load vtable from result_obj
    void **result_vt = *(void ***)result_obj;

    // Call vtable[0x14] with arg1
    u8 call_result = ((vslot_14_t)result_vt[0x14 / 4])(result_obj, arg1);

    // If call_result is non-zero, return the object
    if (call_result) {
      return result_obj;
    }

    // Call vtable[0x64] again to get next item
    vtable = *(void ***)member;
    result_obj = ((vslot_64_t)vtable[0x64 / 4])(member, local_area);
  }

  // Return null (eax = 0)
  return 0;
}
PCREG(434d10, func_434d10);
