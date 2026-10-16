// batch638.cpp - band 0x421000-0x441000, batch 638: one function.
//   0x425310 (thiscall, no args, void): complex loop through vtable slots (0x4c, 0x64, 0xcc, 0x18, 0x0c).
//     Reads global at 0x70038c; loops while slot[0x64] returns non-null.
#include "ff.h"

typedef u32(THISCALL *vslot_4c_t)(void *obj, void *local);
typedef void *(THISCALL *vslot_64_t)(void *obj, void *local);
typedef u32(THISCALL *vslot_cc_t)(void *gobj, u32 arg);
typedef void(THISCALL *vslot_18_t)(void *self, u32 arg1, void *obj, u32 arg2);
typedef void(THISCALL *vslot_0c_t)(void *obj);

static void THISCALL func_425310(u8 *self) {
  u8 local_area[0xc];
  void *obj, *gobj;
  u32 result;

  // Load obj from self[0xc]
  obj = *(void **)(self + 0xc);
  if (!obj) {
    // Check [self+0x11] flag
    if (*(u8 *)(self + 0x11)) {
      void **vtable = *(void ***)self;
      ((vslot_18_t)vtable[0x18 / 4])(self, 0x16, 0, 0);
      *(u32 *)(self + 0x11) = 0;
    }
    *(u32 *)(self + 0xc) = 0;
    return;
  }

  // First call: vtable[0x4c] on obj with &local_area[0xc]
  void **vtable = *(void ***)obj;
  ((vslot_4c_t)vtable[0x4c / 4])(obj, local_area);

  // First call: vtable[0x64] on obj with &local_area[0xc]
  void *result_obj = ((vslot_64_t)vtable[0x64 / 4])(obj, local_area);

  // Loop while result_obj != NULL
  while (result_obj) {
    u32 val_at_c = *(u32 *)((u8 *)result_obj + 0xc);
    if (val_at_c) {
      // Load global at 0x70038c
      gobj = *(void **)0x70038c;
      void **gvtable = *(void ***)gobj;

      // Call global vtable[0xcc] with val_at_c
      result = ((vslot_cc_t)gvtable[0xcc / 4])(gobj, val_at_c);

      if (result) {
        // Write to [result+0x34]
        *(u32 *)((u8 *)result + 0x34) = 0;
      }

      // Call self's vtable[0x18] with args (self, 0x15, val_at_c, 0)
      void **self_vt = *(void ***)self;
      ((vslot_18_t)self_vt[0x18 / 4])(self, 0x15, (u8 *)result_obj + 0xc, 0);
    }

    // Call vtable[0x64] again
    vtable = *(void ***)obj;
    result_obj = ((vslot_64_t)vtable[0x64 / 4])(obj, local_area);
  }

  // After loop: call vtable[0x0c] on obj
  vtable = *(void ***)obj;
  ((vslot_0c_t)vtable[0x0c / 4])(obj);

  // Clear [self+0xc]
  *(u32 *)(self + 0xc) = 0;

  // Check [self+0x11] flag again
  if (*(u8 *)(self + 0x11)) {
    void **self_vt = *(void ***)self;
    ((vslot_18_t)self_vt[0x18 / 4])(self, 0x16, 0, 0);
    *(u8 *)(self + 0x11) = 0;
  }
}
PCREG(425310, func_425310);
