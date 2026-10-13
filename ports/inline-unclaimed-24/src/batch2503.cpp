// batch2503.cpp - decomp area 24, batch 2503. 0x50af30 (GUESS registry handler filler):
// thiscall, ret 4. Fills a 50-element registry array with 19 different handler function pointers.
// Stores different handlers in each iteration while a flag byte at param+0xc is non-zero.
// When the registry is full (counter >= 0x32), calls overflow handler via vtable slot 0x44.
#include "ff.h"

extern "C" void ext_7003b0(const char *msg);    // logger, cdecl

extern "C" u32 THISCALL f24_50af30(u8 *self, void *param) {
  // Handlers in order (extracted from disassembly at each iteration)
  static const void *const handlers[] = {
    (void*)0x50aac0, (void*)0x50aa30, (void*)0x50acb0, (void*)0x50ac10,
    (void*)0x50a770, (void*)0x50a670, (void*)0x50a860, (void*)0x50ae00,
    (void*)0x50aee0, (void*)0x50ad50, (void*)0x50a940, (void*)0x50b510,
    (void*)0x50b510, (void*)0x50b510, (void*)0x50b510, (void*)0x50b540,
    (void*)0x50b570, (void*)0x6368b0, (void*)0x50b780
  };

  u32 *counter_ptr = (u32 *)0x7011f8;
  void **registry = (void **)0x701200;
  u8 *param_bytes = (u8 *)param;

  // Loop while param->flag[0xc] != 0
  for (u32 handler_idx = 0; handler_idx < 19 && param_bytes[0xc] != 0; handler_idx++) {
    u32 cnt = *counter_ptr;

    if (cnt < 0x32) {
      // Add handler to registry
      registry[cnt] = (void *)handlers[handler_idx];
      (*counter_ptr)++;
    } else {
      // Call overflow handler via vtable at +0x44
      void (**vt)(void) = (void (**)(void))self;
      vt[0x44 / sizeof(void*)]();

      // Call logger if not null
      void (*logger_fn)(const char*) = *(void (**)(const char*))(0x7003b0);
      if (logger_fn) {
        logger_fn((const char *)0x69d334);
      }
    }
  }

  // Return the final counter value
  return *counter_ptr;
}
PCREG(50af30, f24_50af30);
