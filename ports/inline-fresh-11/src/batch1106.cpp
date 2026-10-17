// batch1106.cpp - fresh-11 batch 6: slice-11 functions of 126 to 137 bytes. Names from the GC name map; GUESS otherwise.
// SEH frames and /GS cookies are not reproduced (stack and fs:[0] only, restored before return).
#include "ff.h"

static inline u8 *Eng9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
extern "C" void *ext_41e290(u32 n);          // __builtin_new, cdecl
typedef void (*cb_t)();

// 0x57f130 GUESS refresh entries (bool b): for i < list(+0x23c)->slot +0x14() (re-read): o = [0x70038c]->slot +0xcc(
// list->slot +0x30(i)); when o: if b { o+0xe0 = 0x57d500(o+0x2c, 0); o+0xdf = 0; 0x57ee90() } then 0x57ee90() again.
extern "C" u32 THISCALL ext_57d500(void *self, void *p, u32 z);
extern "C" void THISCALL ext_57ee90(void *self);
static s32 THISCALL Refresh57f130(u8 *self, u32 b) {
  void *l = self + 0x23c;
  s32 n = vcall<s32>(l, 0x14);
  if (n <= 0) return n;
  s32 i = 0;
  do {
    u32 x = vcall<u32>(l, 0x30, (u32)i);
    u8 *o = vcall<u8 *>(G(void *, 0x70038c), 0xcc, x);
    if (o) {
      if ((u8)b) {
        u8 r = (u8)ext_57d500(o, o + 0x2c, 0);
        o[0xe0] = r;
        o[0xdf] = 0;
        ext_57ee90(o);
      }
      ext_57ee90(o);
    }
    i++;
    n = vcall<s32>(l, 0x14);
  } while (i < n);
  return n;
}
PCREG(57f130, Refresh57f130);

// 0x42d6b0 GUESS create sub-object: slot +0xc8(); +0x1907 = new(0x134c) constructed by 0x436bd0 (0 when new fails).
extern "C" u32 THISCALL ext_436bd0(void *self);
static u32 THISCALL Create42d6b0(u8 *self) {
  vcall<void>(self, 0xc8);
  void *p = ext_41e290(0x134c);
  u32 r = p ? ext_436bd0(p) : 0;
  *(u32 *)(self + 0x1907) = r;
  return r;
}
PCREG(42d6b0, Create42d6b0);

// 0x45c5f0 ZGEOM::~ZGEOM() [medium] (deleting): body 0x45c3e0; flag 1: flag 4 -> 0x4690b0(this, 0x18), else the pool
// ([eng9b+8]) slot +0x14(this).
extern "C" void THISCALL ext_45c3e0(void *self);
extern "C" void ext_4690b0(void *p, u32 n);
static u8 *THISCALL GEOM_DelDtor(u8 *self, u32 flags) {
  ext_45c3e0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x18);
    else vcall<void>(*(void **)(Eng9b() + 8), 0x14, self);
  }
  return self;
}
PCREG(45c5f0, GEOM_DelDtor);

// 0x4c96f0 ZSpin::Load(ZLoadGame*) [high]: clear flag 0x40; load +0x4c (+0x6c), +0x58/+0x59/+0x5a (+0x68), +0x48/+0x4a
// (+0x44), +0x5b (+0x58), +0x5f/+0x6b/+0x77 (+0x6c); true.
static bool THISCALL Spin_Load(u8 *self, void *ld) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(ld, 0x6c, self + 0x4c);
  vcall<void>(ld, 0x68, self + 0x58);
  vcall<void>(ld, 0x68, self + 0x59);
  vcall<void>(ld, 0x68, self + 0x5a);
  vcall<void>(ld, 0x44, self + 0x48);
  vcall<void>(ld, 0x44, self + 0x4a);
  vcall<void>(ld, 0x58, self + 0x5b);
  vcall<void>(ld, 0x6c, self + 0x5f);
  vcall<void>(ld, 0x6c, self + 0x6b);
  vcall<void>(ld, 0x6c, self + 0x77);
  return true;
}
PCREG(4c96f0, Spin_Load);

// 0x5538f0 GUESS script native (stdcall, args at p+8): result 0 = -1; id = 0 then o = eng9b->slot +0x138();
// o->slot +0x88(0x681320, &id); g = eng9b->slot +0x58(id); when g and g+0x852: result 0 = CharismaGetRecruitable().
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" u32 THISCALL ext_5002f0(void *v, u32 x);
extern "C" u32 THISCALL ext_596cf0(void *self);
static u32 STDCALL Native5538f0(u8 *p) {
  ext_5002f0(ext_5003d0(*(void **)(p + 8), 0), 0xffffffff);
  void *o = vcall<void *>(Eng9b(), 0x138);
  u32 id = 0;
  vcall<void>(o, 0x88, 0x681320u, &id);
  u8 *g = vcall<u8 *>(Eng9b(), 0x58, id);
  if (!g) return 0;
  void *osd = *(void **)(g + 0x852);
  if (!osd) return (u32)g;
  u32 r = ext_596cf0(osd);
  return ext_5002f0(ext_5003d0(*(void **)(p + 8), 0), r);
}
PCREG(5538f0, Native5538f0);

// 0x4b6d70 CCutSequenceList::RegisterInstance(unsigned int) [medium]: id 0 (re)creates the shared table at 0x700334
// (callback [0x7003b0] when one already exists; new(0x28) + LINKREFTAB(4, 2)); then +0x48 = id.
extern "C" u32 THISCALL ext_4cca60(void *self, u32 a, u32 b);
static void THISCALL CutSequenceList_RegisterInstance(u8 *self, u32 id) {
  if (!id) {
    if (G(u32, 0x700334)) {
      cb_t f = G(cb_t, 0x7003b0);
      if (!f) __builtin_trap();
      f();
    }
    void *p = ext_41e290(0x28);
    G(u32, 0x700334) = p ? ext_4cca60(p, 4, 2) : 0;
  }
  *(u32 *)(self + 0x48) = id;
}
PCREG(4b6d70, CutSequenceList_RegisterInstance);

// 0x509430 GUESS one-time registration: when [0x701048] == 0: a local list {0, 0, 0, owns = 1} reserved for 0x32
// (0x59a9b0), passed to slot +0x1c, then destroyed (0x4ff9d0).
struct __attribute__((packed)) List13 {
  u32 a, b, c;
  u8 owns;
};
extern "C" void THISCALL ext_59a9b0(void *l, u32 n);
extern "C" void THISCALL ext_4ff9d0(void *l);
static void THISCALL Register509430(u8 *self) {
  if (G(u32, 0x701048)) return;
  List13 l;
  l.a = 0;
  l.b = 0;
  l.c = 0;
  l.owns = 1;
  ext_59a9b0(&l, 0x32);
  vcall<void>(self, 0x1c, &l);
  ext_4ff9d0(&l);
}
PCREG(509430, Register509430);

// 0x5fb370 GUESS free a tree: for each node in the chain (next +5): recurse into +9, free the node's buffer
// (0x54f870 on the vector at +0xd: (begin, capacity end +0x15 - begin) when both are set), then free the node
// (0x54f870(node, 0x1d) on this).
extern "C" void THISCALL ext_54f870(void *self, u32 p, u32 n);
static void THISCALL FreeTree5fb370(u8 *self, u8 *node) {
  while (node) {
    FreeTree5fb370(self, *(u8 **)(node + 9));
    u8 *next = *(u8 **)(node + 5);
    u32 b = *(u32 *)(node + 0xd);
    u32 n = *(u32 *)(node + 0x15) - b;
    if (b && n) ext_54f870(node + 0xd, b, n);
    ext_54f870(self, (u32)node, 0x1d);
    node = next;
  }
}
PCREG(5fb370, FreeTree5fb370);

// 0x57dfb0 GUESS select target (unused a, id): list (+0x264)->slot +0x2c(id) == 0 -> +0x344 = id, +0x349 = 0; else
// +0x349 = 1, +0x340 = id and ZBaseGeom::GetPos into a local for eng9b->slot +0x58(id)+8. Returns false (AL = 0).
extern "C" u32 THISCALL ext_4db500(void *geom, float *out);
static u32 THISCALL Select57dfb0(u8 *self, u32, u32 id) {
  u32 r = vcall<u32>(self + 0x264, 0x2c, id);
  if (!r) {
    *(u32 *)(self + 0x344) = id;
    self[0x349] = 0;
    return 0;
  }
  self[0x349] = 1;
  *(u32 *)(self + 0x340) = id;
  u8 *g = vcall<u8 *>(Eng9b(), 0x58, id);
  float pos[3];
  return ext_4db500(*(void **)(g + 8), pos) & 0xffffff00;
}
PCREG(57dfb0, Select57dfb0);
