// batch34021.cpp - cascade tier E, batch 34021: 0x60efb0 (store a mode and read the display frequency through EnumDisplaySettingsA), 0x494ac0 (timer-delta
// layout row), 0x4a8460 (read four settings), 0x4b10c0 (resolve an entry by id or by name and push its numbers to a sink).
#include "ff.h"

extern "C" u32 THISCALL ext_4cc5f0(void *p);                 // strlen of the C string at [p]
extern "C" u32 THISCALL ext_4cc1d0(void *p);                 // returns [p]
extern "C" void THISCALL ext_6519a0(void *self, u32 name);   // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);             // /GS check
typedef int(STDCALL *enum_disp_t)(u32 name, s32 mode, void *dm);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static inline void wr32u(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x60efb0, thiscall(a) ret 4: [this+0x133] = a (unaligned); name = the string at engine+0x923 when it is non-empty, else the literal at 0x6983ac;
// 0x6519a0(this, name); this->slot0x268(); EnumDisplaySettingsA(0, -1, &devmode{dmSize = 0x9c}); [this+0x1a] = devmode.dmDisplayFrequency; /GS check.
static void THISCALL fn60efb0(u8 *self, u32 a) {
  u8 dm[0xa0];
  wr32u(self + 0x133, a);
  u8 *sp = G(u8 *, 0x70039c) + 0x923;
  u32 name = ext_4cc5f0(sp) ? ext_4cc1d0(sp) : 0x6983ac;
  ext_6519a0(self, name);
  vcall<void>(self, 0x268);
  dm[0x24] = 0x9c; dm[0x25] = 0; dm[0x26] = 0; dm[0x27] = 0;   // dmSize (u16 at 0x24, with the following word as left on the stack)
  G(enum_disp_t, 0x6761d8)(0, -1, dm);
  *(u32 *)(self + 0x1a) = *(u32 *)(dm + 0x78);
  ext_633654(0);
}
PCREG(60efb0, fn60efb0);

// 0x494ac0, thiscall(a) ret 4: t = engine->slot0x1c8(0x68d798, 0x1475) (64-bit); the 64-bit value at +8 becomes t - old; o = engine->slot0x190();
// o's slot 0x184 with ECX = o's vtable and six caller-popped stack args (o, (n%3)*0x2d, n/3+5, 0x68e26c, low32, a) where n = [this+4]; then [this+4]++.
static void THISCALL fn494ac0(u8 *self, u32 a) {
  u8 *eng = G(u8 *, 0x70039c);
  u64 t = vcall<u64>(eng, 0x1c8, 0x68d798u, 0x1475u);
  u64 d = t - *(u64 *)(self + 8);
  *(u64 *)(self + 8) = d;
  u32 esi = (u32)d;
  u8 *o = vcall<u8 *>(G(u8 *, 0x70039c), 0x190);
  u32 n = *(u32 *)(self + 4);
  u32 q = n / 3, r = n % 3;
  u32 vt = *(u32 *)o;
  u32 slot = ((u32 *)vt)[0x184 / 4];
  u32 av[6] = {(u32)o, r * 0x2d, q + 5, 0x68e26c, esi, a};
  asm volatile("push 20(%[av])\n\tpush 16(%[av])\n\tpush 12(%[av])\n\tpush 8(%[av])\n\tpush 4(%[av])\n\tpush 0(%[av])\n\tcall *%[fn]\n\tadd $24, %%esp"
               : : "c"(vt), [av] "r"(av), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  *(u32 *)(self + 4) += 1;
}
PCREG(494ac0, fn494ac0);

// 0x4a8460, thiscall, no args: t = table->slot0x138(); tmp = 0; t->slot0x88(0x690234, &tmp); [this+0x48] = tmp; word [this+0x4c] =
// table->slot0x114(0x690278, 0, 0x690248, 0x19); dword [this+0x4e] = 100000; word [this+0x52] = table->slot0x114(0x690288, 0, 0x690248, 0x1b); dword [this+0x54] = 0.
static void THISCALL fn4a8460(u8 *self) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = vcall<u8 *>(tbl, 0x138);
  u32 tmp = 0;
  vcall<void>(t, 0x88, 0x690234u, (u32)&tmp);
  *(u32 *)(self + 0x48) = tmp;
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x114, 0x690278u, 0u, 0x690248u, 0x19u);
  self[0x4c] = v; self[0x4d] = v >> 8;
  wr32u(self + 0x4e, 100000);
  tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  v = vcall<u32>(tbl, 0x114, 0x690288u, 0u, 0x690248u, 0x1bu);
  self[0x52] = v; self[0x53] = v >> 8;
  wr32u(self + 0x54, 0);
}
PCREG(4a8460, fn4a8460);

// 0x4b10c0, thiscall(a, b) ret 8: when the unaligned dword [this+0x52] is non-zero, r = this->slot0x94(a, it); else when the string at [this+0x56] is
// non-empty r = this->slot0x90(a, b, string), else return. When r: [this+0x44]->slot0x130([r+0x54], word [this+0x50], [this+0xd6]).
static void THISCALL fn4b10c0(u8 *self, u32 a, u32 b) {
  u32 r;
  u32 k = rd32u(self + 0x52);
  if (k) {
    r = vcall<u32>(self, 0x94, a, k);
  } else {
    if (!ext_4cc5f0(self + 0x56)) return;
    u32 s = ext_4cc1d0(self + 0x56);
    r = vcall<u32>(self, 0x90, a, b, s);
  }
  if (r) {
    u8 *sink = *(u8 **)(self + 0x44);
    vcall<void>(sink, 0x130, *(u32 *)(r + 0x54), (u32)(self[0x50] | self[0x51] << 8), *(u32 *)(self + 0xd6));
  }
}
PCREG(4b10c0, fn4b10c0);
