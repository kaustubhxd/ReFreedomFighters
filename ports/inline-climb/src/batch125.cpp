// batch125.cpp - ZOnScreenDisplay::MessageAdd(text, flags) (climb thread, batch 125). GC map (medium): MessageAdd.
#include "ff.h"

// 0x5aaa30, THISCALL with two stack args (ret 8). When the byte at +0x658 is set, nothing. Otherwise the message is passed
// on to the object at +0x638 (its slot 0x14, same two arguments: the exe tail-jumps there, so that callee pops them).
static void THISCALL messageAdd(u8 *self, const char *text, u32 flags) {
  if (self[0x658])
    return;
  void *obj = *(void **)(self + 0x638);
  vcall<void>(obj, 0x14, text, flags);
}
PCREG(5aaa30, messageAdd);
