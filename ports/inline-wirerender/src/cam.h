// cam.h - field access helpers for the camera thread. The PC build is packed (/Zp1), so camera fields sit at odd
// offsets (0x465, 0x471); these helpers read and write a type at a byte offset without assuming alignment.
#pragma once
#include "ff.h"

template <class T>
static inline T &at(const void *p, u32 off) {
  return *(T *)((u8 *)p + off);
}
static inline u8 *ptr(const void *p, u32 off) { return at<u8 *>(p, off); }
#define SYS9B (*(u8 **)(G(u8 *, 0x70039c) + 0x9b))  // ZSysInterface +0x9b: the geometry/handle manager
