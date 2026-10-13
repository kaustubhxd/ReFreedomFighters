// batch2513.cpp - decomp area 24, batch 2513. 0x491630 (GUESS DBREAD property-list reader), stdcall(names, block), ret 8, SEH frame
// (plain C++: the frame pushes EAX (cookie slot) after EBX/ESI/EDI, so the epilogue restores the callee-saved registers).
// `names` is a comma separated list of property names (split in place with strchr through the IAT, 0x676254). `block` + 4 is a
// tagged data stream. For each name the tag byte at the cursor (low 6 bits, 0xff kept) selects a reader (exe 0x4e5ea0, 0x4e5e60,
// 0x4e6250, 0x4e6180, 0x4e6050, 0x4e6330, 0x4e6420: they take the cursor's address in ECX and advance it) and a call into the database
// object returned by slot 0x138 of the object at system+0x9b (slots 0x30, 0x34, 0x3c, 0x40, 0x44, 0x60). Tag 6 stops; an unknown tag
// logs through [0x700390] (slot 0x20 (file, line), then slot 0x2c cdecl (obj, fmt, tag)) and stops.
// Stack cookie check (0x633654) and the SEH registration are not reproduced (no observable effect).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5ea0(u8 **cur);
extern "C" u32 THISCALL ext_4e5e60(u8 **cur);
extern "C" s32 THISCALL ext_4e6250(u8 **cur, double *buf);
extern "C" s32 THISCALL ext_4e6180(u8 **cur, double *buf);
extern "C" s32 THISCALL ext_4e6050(u8 **cur, double *buf);
extern "C" void THISCALL ext_4e6330(u8 **cur, void *obj);
extern "C" void THISCALL ext_4e6420(u8 **cur);
extern "C" void THISCALL ext_4ccbe0(void *obj, u32 a, u32 b);
extern "C" void THISCALL ext_4ccfe0(void *obj);

typedef char *(__attribute__((cdecl)) * strchr_t)(const char *, s32);
typedef void *(THISCALL *vfdb)(void *);
typedef void(THISCALL *vf3)(void *, const void *, u32, u32);
typedef void(THISCALL *vf4)(void *, const void *, const void *, u32, u32);
typedef void *(THISCALL *vflog)(void *, const void *, u32);
typedef void(__attribute__((cdecl)) * vflog2)(void *, const void *, u32);

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])

static void *getDb() {
  void *t = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  return VT(t, vfdb, 0x138)(t);
}

static void STDCALL dbRead(char *name, u8 *block) {
  u8 *cursor = block + 4;
  if (!name) return;
  for (;;) {
    char *p = G(strchr_t, 0x676254)(name, 0x2c);
    char *next = p;
    if (p) {
      *p = 0;
      next = p + 1;
    }
    u8 tag = *cursor;
    u8 bl = (tag == 0xff) ? 0xff : (tag & 0x3f);
    u32 idx = (u32)bl - 1u;
    if (idx > 0xb) {
      void *lg = G(void *, 0x700390);
      void *o = VT(lg, vflog, 0x20)(lg, (void *)0x68d798, 0xc74);
      VT(o, vflog2, 0x2c)(o, (void *)0x68d990, bl);
      return;
    }
    double dbl[64];
    s32 n;
    switch (idx) {
      case 0: {
        float arr[64];
        n = ext_4e6250(&cursor, dbl);
        for (s32 i = 0; i < n; i++) arr[i] = (float)dbl[i];
        void *db = getDb();
        VT(db, vf4, 0x30)(db, name, arr, n, 3);
        break;
      }
      case 1: {
        n = ext_4e6180(&cursor, dbl);
        void *db = getDb();
        VT(db, vf4, 0x30)(db, name, dbl, n, 3);
        break;
      }
      case 2: {
        n = ext_4e6050(&cursor, dbl);
        void *db = getDb();
        VT(db, vf4, 0x34)(db, name, dbl, n, 2);
        break;
      }
      case 3: {
        u32 s = ext_4e5ea0(&cursor);
        void *db = getDb();
        VT(db, vf3, 0x40)(db, name, s, 0xc);
        break;
      }
      case 4: {
        u32 s = ext_4e5ea0(&cursor);
        void *db = getDb();
        VT(db, vf3, 0x40)(db, name, s, 0xe);
        break;
      }
      case 5:
        return;
      case 6:
      case 11: {
        void *db = getDb();
        VT(db, vf3, 0x3c)(db, name, (u32)(cursor + 1), 0xf);
        ext_4e6420(&cursor);
        break;
      }
      case 7: {
        u32 s = ext_4e5e60(&cursor);
        void *db = getDb();
        VT(db, vf3, 0x60)(db, name, s, 0x10);
        break;
      }
      case 8: {
        u8 obj[0x20];
        ext_4ccbe0(obj, 0x20, 0);
        ext_4e6330(&cursor, obj);
        void *db = getDb();
        VT(db, vf3, 0x44)(db, name, (u32)obj, 0xf);
        ext_4ccfe0(obj);
        break;
      }
      case 9: {
        u32 s = ext_4e5e60(&cursor);
        void *db = getDb();
        VT(db, vf3, 0x60)(db, name, s, 0x12);
        break;
      }
      case 10: {
        u32 s = ext_4e5e60(&cursor);
        void *db = getDb();
        VT(db, vf3, 0x60)(db, name, s, 0x13);
        break;
      }
    }
    name = next;
    if (!next) return;
  }
}
PCREG(491630, dbRead);
