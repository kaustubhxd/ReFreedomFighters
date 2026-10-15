// batch35200.cpp - cascade s5 batch 35200 (tier H): 0x5d00e0 (GUESS initialise a vehicle HUD record from its owner and the engine tables).
#include "ff.h"

extern "C" u32 THISCALL ext_591ae0(u8 *self);                        // plain ret
extern "C" void THISCALL ext_5922c0(u8 *self, u8 *out);              // ret 4
extern "C" void THISCALL ext_4de7a0(float *m);                       // identity into 0x24 bytes
typedef u8 *(THISCALL *o0_t)(void *);
typedef u8 *(THISCALL *o1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, void *);
typedef void(THISCALL *w2_t)(void *, u8 *, u8 *);
typedef void(THISCALL *p1_t)(void *, float *);
typedef u8 *(THISCALL *l2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5d00e0, thiscall, no args, no return value (stack cookie not reproduced). edi = this[0x44]; O1 = tab slot 0x134(); flag byte = 0; O1 slot 0x90(0x68a9d4, &flag); this[0xe17] = flag != 0; unaligned [+0xc6d] = unaligned [edi+0x676]; [+0xb54] = 0x591ae0(edi);
// 0x5922c0(edi, this+0xd22); identity matrix (0x4de7a0, unused); unaligned [+0xb15] = 0x43fa0000; O2 = tab slot 0x138(); out = 0; O2 slot 0x88(name, &out) with name = 0x6b4ed4 (mode [edi+0x684] == 2), 0x6b4ee0 (3), 0x6b4eec (4), else 0x690418; unaligned [+0xae1] = out;
// when byte [engine+0x6c] == 0: [+0xe1c] = 3; P = tab slot 0x58(unaligned [+0xc6d]); null: logger (0x700390) slot 0x20(0x6b4e78, 0x136) then slot 0x2c(r, 0x6b4ef8) with ECX = the vtable, caller-popped, and return. Otherwise P slot 0x80(this+0xcb9, this+0xcad); V from edi slot 0x378(V) then edi slot 0x84(V);
// unaligned floats [+0xc71], [+0xc75], [+0xc79] = V.
static void THISCALL fn5d00e0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *edi = *(u8 **)(self + 0x44);
  u8 *O1 = (*(o0_t **)tab)[0x134 / 4](tab);
  u8 flag = 0;
  (*(v2_t **)O1)[0x90 / 4](O1, 0x68a9d4, &flag);
  self[0xe17] = flag != 0;
  wr32u(self + 0xc6d, rd32u(edi + 0x676));
  *(u32 *)(self + 0xb54) = ext_591ae0(edi);
  ext_5922c0(edi, self + 0xd22);
  float M[9];
  ext_4de7a0(M);
  wr32u(self + 0xb15, 0x43fa0000);
  u32 mode = *(u32 *)(edi + 0x684);
  u32 name = mode == 2 ? 0x6b4ed4 : mode == 3 ? 0x6b4ee0 : mode == 4 ? 0x6b4eec : 0x690418;
  eng = G(u8 *, 0x70039c);
  tab = *(u8 **)(eng + 0x9b);
  u8 *O2 = (*(o0_t **)tab)[0x138 / 4](tab);
  u32 out = 0;
  (*(v2_t **)O2)[0x88 / 4](O2, name, &out);
  wr32u(self + 0xae1, out);
  eng = G(u8 *, 0x70039c);
  if (eng[0x6c] == 0) {
    *(u32 *)(self + 0xe1c) = 3;
    eng = G(u8 *, 0x70039c);
  }
  tab = *(u8 **)(eng + 0x9b);
  u8 *P = (*(o1_t **)tab)[0x58 / 4](tab, rd32u(self + 0xc6d));
  if (!P) {
    u8 *lg = G(u8 *, 0x700390);
    u8 *r = (*(l2_t **)lg)[0x20 / 4](lg, 0x6b4e78, 0x136);
    u32 vt = *(u32 *)r;
    u32 slot = ((u32 *)vt)[0x2c / 4];
    asm volatile("push $0x6b4ef8\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    return;
  }
  (*(w2_t **)P)[0x80 / 4](P, self + 0xcb9, self + 0xcad);
  float V[3];
  (*(p1_t **)edi)[0x378 / 4](edi, V);
  (*(p1_t **)edi)[0x84 / 4](edi, V);
  wr32u(self + 0xc71, fbits(V[0]));
  wr32u(self + 0xc75, fbits(V[1]));
  wr32u(self + 0xc79, fbits(V[2]));
}
PCREG(5d00e0, fn5d00e0);
