#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 index);
extern "C" u8 *THISCALL ext_5002f0(u8 *self, u32 value);

// 0x5516e0: find a nested collection, resolve one indexed element, and pass
// the element through the two helper calls when the collection is present.
static u8 *STDCALL fn5516e0(u8 *source, u32 index, u32 *value) {
  u8 *collection = vcall<u8 *>(source, 0x18, index);
  if (!collection) return nullptr;
  u8 *cursor = vcall<u8 *>(collection, 0x4c);
  u8 *element = ext_5003d0(cursor, 0);
  ext_5002f0(element, *value);
  return collection;
}

PCREG(5516e0, fn5516e0);
