#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32(THISCALL *V4)(void *, u32, u32, u32, u32);
typedef u32(THISCALL *V8)(void *, u32, u32, u32, u32, u32, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" void THISCALL ext_466c10(void *self, void *a, void *b, float f);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x595250: thiscall() with no defined return value (/GS protected; edi is only saved): updates the pointer ray of an actor. Nothing happens when this slot 0x254() or the object B = this[0x6c]'s
// slots 0x34() / 0x38() are set. Otherwise this slot 0x84(&pos) with pos preset to (0, 200, 0); the picker D = [[[0x70039c]+0x1aa3]+0x1c] slot 0x30(&hit(1.0f), 0, &pos, &(0,-2000,0), 0, 4, 1, 0)
// (a hit marks the cursor object: [C slot 0x94()+0x10] = 1 and [... +0x11] = hit.float(+8)); the cursor object's float [+4] = 0.5f; B slot 0x30(this, 1, 1, 1) decides (nonzero) whether to continue:
// when this[0x9e7] == 0 it asserts (hook [0x7003b0]) if B refused, otherwise a second B slot 0x30(this, 1, 1, 0) is tried and if that also refuses the object this slot 0x21c(0x6acf84)
// is selected (this slot 0x230(obj, 1)) and this[0x81b] = float((obj[0x64] - obj[0x60]) / obj[0x6c]) and nothing else happens. On the other paths this slot 0x220(0) and 0x466c10(this, &this[0x9fa], &this[0xa06], this[0xa12]) run.
extern "C" void THISCALL fn_595250(u8 *self) {
  u32 hit[18];
  u32 pos[3] = {0, 0x43480000, 0};
  u32 v2[3] = {0, 0xc4fa0000, 0};
  if ((u8)(*(V0 *)(vt(self) + 0x254))(self)) goto out;
  {
    void *B = (void *)rd32u(self + 0x6c);
    if ((u8)(*(V0 *)(vt(B) + 0x34))(B)) goto out;
    B = (void *)rd32u(self + 0x6c);
    if ((u8)(*(V0 *)(vt(B) + 0x38))(B)) goto out;
  }
  (*(V1 *)(vt(self) + 0x84))(self, (u32)pos);
  hit[0] = 0x3f800000;
  {
    u8 *C = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3);
    void *D = (void *)rd32u(C + 0x1c);
    u32 ok = (*(V8 *)(vt(D) + 0x30))(D, (u32)hit, 0, (u32)pos, (u32)v2, 0, 4, 1, 0);
    if ((u8)ok) {
      C = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3);
      u8 *e1 = (u8 *)(*(V0 *)(vt(C) + 0x94))(C);
      e1[0x10] = 1;
      u32 f = hit[2];
      C = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3);
      u8 *e2 = (u8 *)(*(V0 *)(vt(C) + 0x94))(C);
      wr32u(e2 + 0x11, f);
    }
  }
  {
    u8 *C = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x1aa3);
    u8 *e3 = (u8 *)(*(V0 *)(vt(C) + 0x94))(C);
    wr32u(e3 + 4, 0x3f000000);
  }
  {
    void *B = (void *)rd32u(self + 0x6c);
    bool ok = (*(V4 *)(vt(B) + 0x30))(B, (u32)self, 1, 1, 1) != 0;
    if (self[0x9e7] == 0) {
      if (!ok) {
        typedef u32 (*Hook)();
        Hook h = G(Hook, 0x7003b0);
        if (!h) __builtin_trap();
        h();
      }
    } else if (!ok) {
      B = (void *)rd32u(self + 0x6c);
      bool ok2 = (*(V4 *)(vt(B) + 0x30))(B, (u32)self, 1, 1, 0) != 0;
      if (!ok2) {
        u8 *x = (u8 *)(*(V1 *)(vt(self) + 0x21c))(self, 0x6acf84);
        if (!x) goto out;
        (*(V2 *)(vt(self) + 0x230))(self, (u32)x, 1);
        s32 q = (s32)(rd32u(x + 0x64) - rd32u(x + 0x60)) / (s32)rd32u(x + 0x6c);
        float fq = (float)q;
        __builtin_memcpy(self + 0x81b, &fq, 4);
        goto out;
      }
    }
  }
  (*(V1 *)(vt(self) + 0x220))(self, 0);
  {
    float f;
    __builtin_memcpy(&f, self + 0xa12, 4);
    ext_466c10(self, self + 0x9fa, self + 0xa06, f);
  }
out:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(595250, fn_595250);
