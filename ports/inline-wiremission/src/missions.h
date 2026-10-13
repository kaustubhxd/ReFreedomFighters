// missions.h - shared layouts and helpers for the missions decomp thread (batches 1400-1499).
#pragma once
#include "ff.h"

struct CSaveMissions {
  void *vtbl;
  u32 f4;
  const char *name[116];
  const char *text[116];
  u32 pad3a8[8];
  s32 value[116];
  s32 unk598[8];
  s32 count;
  s32 pad5bc;
  s32 type[116];
  s32 icon[116];
};
static_assert(sizeof(CSaveMissions) == 0x960, "layout");
static_assert(__builtin_offsetof(CSaveMissions, count) == 0x5b8, "count");
static_assert(__builtin_offsetof(CSaveMissions, type) == 0x5c0, "type");

// MSVC's inline strcmp, only tested for zero.
static inline bool same(const u8 *a, const u8 *b) {
  for (;;) {
    if (a[0] != b[0]) return false;
    if (a[0] == 0) return true;
    if (a[1] != b[1]) return false;
    if (a[1] == 0) return true;
    a += 2;
    b += 2;
  }
}

// First n bytes equal (no stop at NUL): the level/zone prefix test.
static inline bool prefix(const char *a, const char *b, int n) {
  for (int i = 0; i < n; i++)
    if (a[i] != b[i]) return false;
  return true;
}

// The debug log: [0x700390]->slot 0x20(file, line) gives a printer whose slot 0x2c is a cdecl printf.
typedef void *(THISCALL *logOpen)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *pr, const char *fmt, ...);
static inline void *logOpenAt(const char *file, u32 line) {
  void *lg = G(void *, 0x700390);
  return ((logOpen)(*(void ***)lg)[0x20 / 4])(lg, file, line);
}
#define LOGF(file, line, ...)                                    \
  do {                                                           \
    void *pr_ = logOpenAt((const char *)(file), line);           \
    ((logPrintf)(*(void ***)pr_)[0x2c / 4])(pr_, __VA_ARGS__);   \
  } while (0)
#define SAVEMISSIONS_CPP 0x6b1204u   // "..\\..\\freedomfighter\\FFBackground\\SaveMissions.cpp"

// Ports defined in one batch file and called from another.
extern "C" bool THISCALL m_5b1000(CSaveMissions *s, const char *level);   // CSaveMissions::LevelCompleted



// CBuffer (save-game byte buffer): +0 capacity, +4 position, +8 data, +0xc error flag (set when a read or write
// would pass the capacity).
struct CBuffer {
  u32 cap;
  u32 pos;
  u8 *data;
  u8 err;
};
extern "C" u8 THISCALL ext_5f0190(CBuffer *b, s8 v);    // CBuffer::Add(char), lifted elsewhere
extern "C" u8 THISCALL m_5f01c0(CBuffer *b, u32 v);     // CBuffer::Add(unsigned int)
extern "C" u8 THISCALL m_5f0280(CBuffer *b, u8 *out);   // CBuffer::Get(unsigned int*)
extern "C" u8 THISCALL m_5f02f0(CBuffer *b, s8 *out);   // CBuffer::Get(char*)

// COMISS a, b; true when a >= b (ordered). Unlike the UCOMISS clang emits for C comparisons, COMISS raises the
// invalid flag in MXCSR for a quiet NaN; that sticky flag is visible to later CRT conversions (0x633910), so ports
// use this where the original uses COMISS.
static inline bool comiss_ge(float a, float b) {
  bool r;
  asm volatile("comiss %2, %1\n\tsetae %0" : "=q"(r) : "x"(a), "x"(b) : "cc");
  return r;
}
static inline bool comiss_gt(float a, float b) {   // COMISS a, b; true when a > b (ordered)
  bool r;
  asm volatile("comiss %2, %1\n\tseta %0" : "=q"(r) : "x"(a), "x"(b) : "cc");
  return r;
}

// The MSVC deleting-destructor wrapper used by every ZEventBase subclass here: run the body, then with flag 1 free
// the memory, through the no-op sized delete (0x4690b0, cdecl) with flag 4, else through the engine's free hook
// [0x7003b0] (int3 when unset). Returns this.
extern "C" void ext_4690b0(u8 *p, u32 size);
static inline u8 *deletingDtor(u8 *self, u32 flags, u32 size) {
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, size);
    } else {
      typedef void (*freeHook)();
      freeHook fr = G(freeHook, 0x7003b0);
      if (!fr)
        asm volatile("int3");
      fr();
    }
  }
  return self;
}
