// batch38063.cpp - cascade s8 batch 38063: 0x440590 (find a named child object by path).
#include "ff.h"

extern "C" u32 FASTCALL ext_4cc850(const char *name, const char *path);   // 0 = the name matches
typedef int (*stricmp_t)(const char *, const char *);
typedef char *(*strchr_t)(const char *, int);
typedef int (*strnicmp_t)(const char *, const char *, u32);
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define imp_stricmp G(stricmp_t, 0x676414)
#define imp_strrchr G(strchr_t, 0x676258)
#define imp_strchr G(strchr_t, 0x676254)
#define imp_strnicmp G(strnicmp_t, 0x67640c)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define DEFNAME ((const char *)0x67c8e8)

static u32 flags_of(u8 *o) { return o ? *(u32 *)(*(u8 **)(o + 0xc) + 0x23) : 0x200002; }
static const char *name_of(u8 *o) { return *(u32 *)(o + 4) ? *(const char **)(o + 4) : DEFNAME; }
static u32 slen(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x440590, thiscall(path, ctx) ret 8 -> the matching object or 0. A path equal to the root marker 0x67cd1c on a node whose slot 0x20 is 0 returns this. With ctx the chain ctx[0x60]
// is searched for an entry (not flagged 0x802 when its object has bit 0x100000) whose object name (default string when null) matches the last backslash component of the path through 0x4cc850.
// Without ctx a leading "ROOT\\" is skipped and the path is split at the first backslash: the children of this[0x50] are walked (stopping at the first one lacking bit 0x100000) for a name of the
// same length equal (strnicmp) to the head, and the child's slot 0x25c(rest, 0) result is returned when non-null; without a backslash the children are matched with 0x4cc850.
static u8 *THISCALL fn440590(u8 *self, const char *path, u8 *ctx) {
  if ((u32)SLOT(self, 0x20, v0_t)(self) == 0 && imp_stricmp(path, (const char *)0x67cd1c) == 0) return self;
  if (ctx) {
    const char *e = imp_strrchr(path, 0x5c);
    if (e) path = e + 1;
    for (u8 *n = *(u8 **)(ctx + 0x60); n; n = *(u8 **)(n + 0x60)) {
      u8 *o = *(u8 **)(n + 0x54);
      u32 fl = flags_of(o);
      bool cand = !(fl & 0x100000) || !(*(u32 *)(n + 0x30) & 0x802);
      if (cand && o) {
        if (ext_4cc850(name_of(o), path) == 0) return o;
      }
    }
    return 0;
  }
  u32 len = slen(path);
  if (len > 5 && *(u32 *)path == 0x544f4f52 && path[4] == 0x5c) path += 5;
  char *p2 = imp_strchr(path, 0x5c);
  if (p2) {
    u32 n = (u32)(p2 - path);
    for (u8 *c = *(u8 **)(self + 0x50); c; c = *(u8 **)(c + 0x60)) {
      u8 *o = *(u8 **)(c + 0x54);
      if (!(flags_of(o) & 0x100000)) return 0;
      if (*(u32 *)(o + 0x30) & 0x802) continue;
      const char *nm = name_of(o);
      if (slen(nm) != n) continue;
      if (imp_strnicmp(nm, path, n) == 0) {
        u8 *r = (u8 *)SLOT(o, 0x25c, v2_t)(o, (u32)(p2 + 1), 0);
        if (r) return r;
      }
    }
    return 0;
  }
  for (u8 *c = *(u8 **)(self + 0x50); c; c = *(u8 **)(c + 0x60)) {
    u8 *o = *(u8 **)(c + 0x54);
    u32 fl = flags_of(o);
    bool skip = (fl & 0x100000) && o && (*(u32 *)(o + 0x30) & 0x802);
    if (skip) continue;
    if (o && ext_4cc850(name_of(o), path) == 0) return o;
  }
  return 0;
}
PCREG(440590, fn440590);
