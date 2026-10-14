// batch853.cpp - area 50 (residue-9 candidate): 0x4e5a10 [312 instr, thiscall, four stack args, ret 0x10, returns bool;
// no name in the map: GUESS "FindNamedField", a lookup of a node's field pointers and of a named entry in its list].
// Part 1 stores the field pointers for keys 4,5,6,7,8,0xb,0xd,0xf at this+8..+0x28 (each is child + offset, where the
// offset is the child's dword at +8 when its flag kind is 0x4/0x8/0xc and 8 otherwise), clears this+0x24, and looks up
// key 0xe. If that child exists, its element array (count from its size) is searched for the key argument; on a match the
// list of the node (from 0x4e5140) is walked past (n) entries marked 0xa, the entry there is tested with the name pattern
// (0x4cc780, zero means found), and a found entry sets *out and this+4. Part 2 scans the node's children for an entry
// marked 0xa whose name matches (zero means found; this+4 is set). Lookups 0x45e420 / 0x4e5140 and the name match 0x4cc780
// run as exe code; the logger reports a failed element search.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_45e420(void *node, u32 key);                 // child lookup by key (exe code)
extern "C" u8 *THISCALL ext_4e5140(void *node);                           // node data start (exe code)
extern "C" s32 FASTCALL ext_4cc780(const char *pattern, const char *name); // name match (exe code)

// the field offset rule of the exe: kind 0x4/0x8/0xc takes the dword at +8, other kinds use 8
static inline u32 FieldOff(const u8 *c) {
  u32 kind = U32(c, 4) & 0xc0000000u;
  return (kind == 0x40000000u || kind == 0x80000000u || kind == 0xc0000000u) ? U32(c, 8) : 8u;
}
static inline u8 *FieldPtr(u8 *c) { return c + FieldOff(c); }

// 0x4e5a10 (name GUESS).
static bool THISCALL FindNamedField(u8 *self, u32 *out, const char *pattern, u32 key, u8 *node) {
  *out = 0;
  // part 1: field pointers (the exe stores each one before the next lookup)
  u8 *p = FieldPtr(ext_45e420(node, 4));
  U32(self, 0x08) = (u32)p;
  p = FieldPtr(ext_45e420(node, 5));
  U32(self, 0x0c) = (u32)p;
  p = FieldPtr(ext_45e420(node, 6));
  U32(self, 0x10) = (u32)p;
  p = FieldPtr(ext_45e420(node, 7));
  U32(self, 0x14) = (u32)p;
  p = FieldPtr(ext_45e420(node, 8));
  U32(self, 0x18) = (u32)p;
  p = FieldPtr(ext_45e420(node, 0xb));
  U32(self, 0x1c) = (u32)p;
  p = FieldPtr(ext_45e420(node, 0xd));
  U32(self, 0x20) = (u32)p;
  u8 *cf = ext_45e420(node, 0xf);
  if (cf) {
    U32(self, 0x28) = (u32)FieldPtr(ext_45e420(node, 0xf));
  }
  U32(self, 0x24) = 0;
  u8 *ce = ext_45e420(node, 0xe);
  if (ce) {
    u32 raw = U32(ce, 4);
    u32 kind = raw & 0xc0000000u;
    u32 size;
    if (kind == 0x40000000u || kind == 0x80000000u || kind == 0xc0000000u)
      size = (raw & 0x3fffffffu) - U32(ce, 8);
    else
      size = raw - 8;
    u32 cnt = size / 12u;
    u8 *el = FieldPtr(ce);                       // element array (the same offset rule)
    u32 i = 0;
    if (cnt != 0) {
      do {
        if (U32(el, 4) == key) {
          // matched element: skip n entries marked 0xa in the node's list, then test that entry's name
          u32 nskip = U32(el, 0);
          u8 *ed = ext_4e5140(node);
          while (nskip != 0) {
            u32 nxt = (U32(ed, 0) == 0xa) ? nskip - 1 : nskip;
            ed += U32(ed, 4) & 0x3fffffffu;
            nskip = nxt;
          }
          s32 r = ext_4cc780(pattern, (const char *)FieldPtr(ed));
          if (r == 0) {
            // found: *out = the element's +8 value (plus the count from this+0x28), this+4 = the entry
            if (U32(self, 0x28) != 0) {
              u32 v = U32(el, 8);
              if (v != 0) {
                v += U32(self, 0x28) - 1;
                *out = v;
              }
            }
            U32(self, 4) = (u32)ed;
            return true;
          }
        }
        i++;
        el += 0x0c;
      } while (i != cnt);
    }
    // the element search failed: report it through the engine logger (file 0x6973e4, line 0x5a7)
    u8 *lg = G(u8 *, 0x700390);
    u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x6973e4, 0x5a7u);
    typedef void (*printf_t)(void *, const char *, const char *);
    (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x697410, pattern);
  }

  // part 2: the children of the node, from its data start, for an entry marked 0xa whose name matches
  s32 flags = (s32)U32(node, 4);
  if (flags >= 0) return false;
  u32 cnt2 = U32(node, 0x0c);
  u8 *q = node + 0x10;
  if (flags & 0x40000000) q = node + U32(node, 0x10) * 4 + 0x14;   // the exe's other data start
  if (cnt2 == 0) return false;
  do {
    if (U32(q, 0) == 0xa) {
      s32 r = ext_4cc780(pattern, (const char *)FieldPtr(q));
      if (r == 0) {
        U32(self, 4) = (u32)q;
        return true;
      }
    }
    q += U32(q, 4) & 0x3fffffffu;
    cnt2--;
  } while (cnt2 != 0);
  return false;
}
PCREG(4e5a10, FindNamedField);
