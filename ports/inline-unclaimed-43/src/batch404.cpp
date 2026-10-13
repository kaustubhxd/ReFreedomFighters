// batch404.cpp - 0x410f20 (gap band, parked row). A jump thunk through IAT slot 0x67645c, the import Direct3DCreate8 (d3d8.dll):
// stdcall, one argument (the SDK version), returns the interface pointer in eax.
#include "ff.h"

typedef u32(STDCALL *Direct3DCreate8Fn)(u32 sdkVersion);

static u32 STDCALL direct3DCreate8Thunk(u32 sdkVersion) {
  Direct3DCreate8Fn fn = (Direct3DCreate8Fn)(unsigned long)(*(u32 *)0x67645cu);
  return fn(sdkVersion);
}
PCREG(410f20, direct3DCreate8Thunk);
