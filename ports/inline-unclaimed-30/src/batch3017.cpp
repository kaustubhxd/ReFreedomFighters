// batch3017.cpp - unclaimed-30: batch 17 (docs/20-unclaimed-30.md, claim 1). Unnamed in the name map: 0x47aad0 [thiscall, ret 8,
// (id, obj)]. Records are (obj, id) pairs of 8 bytes at this+8k; the count is at this+0x50. A record whose id is id is searched.
// Found with obj equal to the record's object: the last record is moved into its place and the count drops (no report). Found with
// another object: report line 0x50 (format 0x68a7f0 with the record object's name and obj's name, and id). Not found: report line 0x56
// (format 0x68a830 with obj's name and id). An object's name is its vtable slot 0x20 object's +4 string, or "<NONAME>".
#include "ff.h"

typedef void (*reportVarFn)(void *, const char *, ...);

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static const char *objName(u8 *o) {
  u8 *n = vcall<u8 *>(o, 0x20);
  u32 s = rd32u(n + 4);
  return s ? (const char *)s : (const char *)0x67c8e8;
}

static void THISCALL unnamed47aad0(u8 *self, u32 id, u8 *obj) {
  u32 count = rd32u(self + 0x50);
  u32 k = 0;
  if (count) {
    for (; k < count; k++)
      if (rd32u(self + 8 * k + 4) == id) break;
  }
  if (k != count) {
    u8 *rec = self + 8 * k;
    if (rd32u(rec) == (u32)obj) {
      u32 nc = count - 1;
      wr32u(self + 0x50, nc);
      wr32u(rec, rd32u(self + 8 * nc));
      wr32u(rec + 4, rd32u(self + 8 * nc + 4));
      return;
    }
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x68a7c4, 0x50);
    u8 *o1 = vcall<u8 *>((u8 *)rd32u(rec), 0x20);   // the record object's name holder (vtable slot 0x20)
    const char *name1 = rd32u(o1 + 4) ? (const char *)rd32u(o1 + 4) : (const char *)0x67c8e8;
    const char *name2 = objName(obj);
    (*(reportVarFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68a7f0, name2, id, name1);
    return;
  }
  void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x68a7c4, 0x56);
  (*(reportVarFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x68a830, objName(obj), id);
}
PCREG(47aad0, unnamed47aad0);
