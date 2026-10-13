// batch634.cpp - band 0x421000-0x441000, batch 634: one function.
//   0x4272e0 (stdcall, one const char* path; ret 8, u64): calls IAT[0x676114] with path and three
//     local variable pointers; if successful (eax != 0), returns edx:eax (two output params);
//     otherwise returns 0:0.
#include "ff.h"

typedef u32(STDCALL *ext_676114_t)(const char *path, u32 *out1, u32 *out2, u32 *out3);

static u64 STDCALL loadDllExports(const char *path) {
  u32 local_out1, local_out2, local_out3;

  ext_676114_t ext_fn = (ext_676114_t)G(void *, 0x676114);
  u32 result = ext_fn(path, &local_out1, &local_out2, &local_out3);

  if (result != 0) {
    // Success: return (local_out2, local_out1) in (edx, eax)
    return ((u64)local_out2 << 32) | local_out1;
  }
  // Failure: return 0
  return 0;
}
PCREG(4272e0, loadDllExports);
