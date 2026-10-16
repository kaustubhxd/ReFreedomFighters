// batch389.cpp - area 76, residue 17 (out/functions.jsonl).
// 0x6404d0 (thiscall, no arguments, plain ret; GUESS): iterates through elements via an iterator at this+0x1f0.
#include "ff.h"

static void THISCALL f6404d0(u8 *selfp) {
  u32 self = (u32)selfp;
  u32 iter_ptr = *(u32 *)(self + 0x1f0u);

  struct local_t {
    void *elem;
    int idx;
    void *arr;
  } local = {};

  // Call iter[0xc](self+0x1f0, &local) to initialize
  typedef void (THISCALL *init_fn)(u32, u32);
  init_fn init = (init_fn)(*(u32 *)((u32)iter_ptr + 0xcu));
  init(self + 0x1f0u, (u32)&local);

  while (local.elem) {
    u32 elem = (u32)local.elem;
    u32 elem_vt = *(u32 *)elem;
    u32 vt_check = *(u32 *)(elem_vt + 0x38u);
    u8 byte_check = *(u8 *)(elem + 5u);

    if (!vt_check && (byte_check & 1u)) {
      int idx = local.idx++;
      u32 arr = (u32)local.arr;
      int count = *(int *)arr;

      if (idx != count) {
        local.elem = (void *)(arr + 0x10u + (u32)idx * 4u);
      } else {
        u32 next_arr = *(u32 *)(arr + 4u);
        if (next_arr) {
          local.arr = (void *)next_arr;
          local.idx = 0;
          local.elem = (void *)(next_arr + 0x10u);
        } else {
          local.elem = 0;
        }
      }

      if (local.elem) {
        typedef void (THISCALL *callback_fn)(u32, u32);
        callback_fn cb = (callback_fn)(*(u32 *)((u32)(*(u32 *)self) + 0x80u));
        cb(self, elem_vt);
      }
    } else {
      typedef void (THISCALL *next_fn)(u32, u32);
      next_fn next = (next_fn)(*(u32 *)((u32)iter_ptr + 0x10u));
      next(self + 0x1f0u, (u32)&local);
    }
  }
}
PCREG(6404d0, f6404d0);
