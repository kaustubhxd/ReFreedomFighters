#include "ff.h"

typedef u32(THISCALL *V3)(void *, u32, u32, u32);

extern "C" void THISCALL ext_5613a0(void *t, u32 a, u32 b);
extern "C" void THISCALL ext_563510(void *t, u32 a);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static inline u8 *TBL() { return (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 lookup(u32 x) { void *T = TBL(); return vcall<u32>(T, 0x4c, x); }
static inline u32 widget(u32 parent, u32 name) { return vcall<u32>((void *)parent, 0x25c, name, 0); }

// R = table slot 0x138(); R's vtable (read before the lookup) slot 0x60(name, table slot 0x4c(this[0x44]), 0x10)
static void set_name(u8 *self, u32 name) {
  u8 *R = vcall<u8 *>(TBL(), 0x138);
  u32 vtp = *(u32 *)R;
  u32 q = lookup(rd32u(self + 0x44));
  (*(V3 *)(vtp + 0x60))(R, name, q, 0x10);
}

// 0x56bd90: thiscall(), no stack args. By this[0xcee] (0..5; others none) sets the mode pair [0xc9e] / [0xca2] and names the table entry (0x6a7a40 / 0x6a7a50 / 0x6a7754),
// (states 3 and 4 also call this[0xc5e] slot 0x44), then looks the child widgets of this[0xc7e] up by name (slot 0x25c) into this[0xcda] ... this[0xcc2], links pairs of them with 0x5613a0 through table slot 0x4c, and finally
// shows this[0xc7e] (slot 0xbc(1)) in states 0 and 3.
extern "C" void THISCALL fn_56bd90(u8 *self);
extern "C" void THISCALL fn_56bd90(u8 *self) {
  switch (rd32u(self + 0xcee)) {
    case 0:
      wr32u(self + 0xc9e, 8);
      wr32u(self + 0xca2, 8);
      set_name(self, 0x6a7a40);
      break;
    case 1:
    case 2:
      wr32u(self + 0xc9e, 0xa);
      wr32u(self + 0xca2, 1);
      break;
    case 3:
      wr32u(self + 0xc9e, 0);
      wr32u(self + 0xca2, 0);
      set_name(self, 0x6a7a40);
      vcall<void>((void *)rd32u(self + 0xc5e), 0x44);
      break;
    case 4:
      wr32u(self + 0xc9e, 4);
      set_name(self, 0x6a7a50);
      vcall<void>((void *)rd32u(self + 0xc5e), 0x44);
      break;
    case 5:
      wr32u(self + 0xc9e, 5);
      set_name(self, 0x6a7754);
      break;
    default: break;
  }
  wr32u(self + 0xcda, widget(rd32u(self + 0xc7e), 0x6a7a60));
  wr32u(self + 0xcde, widget(rd32u(self + 0xc7e), 0x6a7590));
  wr32u(self + 0xcb6, widget(rd32u(self + 0xcda), 0x6a7a68));
  wr32u(self + 0xcbe, widget(rd32u(self + 0xcda), 0x6a7a74));
  wr32u(self + 0xcba, widget(rd32u(self + 0xcda), 0x6a7a84));
  wr32u(self + 0xcc6, widget(rd32u(self + 0xcda), 0x6a7a94));
  wr32u(self + 0xcca, widget(rd32u(self + 0xcda), 0x6a7aa0));
  wr32u(self + 0xcce, widget(rd32u(self + 0xcda), 0x6a7ab0));
  u32 w = widget(rd32u(self + 0xcda), 0x6a7ac4);
  {
    u32 a = lookup(rd32u(self + 0xcb6));
    u32 b = lookup(rd32u(self + 0xcc6));
    ext_5613a0(self, b, a);
  }
  {
    u32 a = lookup(rd32u(self + 0xcbe));
    u32 b = lookup(w);
    ext_5613a0(self, b, a);
  }
  {
    u32 a = lookup(rd32u(self + 0xcba));
    u32 b = lookup(rd32u(self + 0xcca));
    ext_5613a0(self, b, a);
  }
  u32 s = widget(rd32u(self + 0xcde), 0x6a7a60);
  wr32u(self + 0xcae, widget(s, 0x6a7a60));
  wr32u(self + 0xcb2, widget(rd32u(self + 0xcde), 0x6a7ad4));
  wr32u(self + 0xcd6, widget(s, 0x6a7ae4));
  wr32u(self + 0xcd2, widget(s, 0x6a7af0));
  {
    u32 a = lookup(rd32u(self + 0xcd2));
    u32 b = lookup(rd32u(self + 0xcae));
    ext_5613a0(self, b, a);
  }
  vcall<void>((void *)rd32u(self + 0xcb6), 0x284, 0x679e6c);
  vcall<void>((void *)rd32u(self + 0xcbe), 0x284, 0x679e6c);
  vcall<void>((void *)rd32u(self + 0xcba), 0x284, 0x679e6c);
  ext_563510(self, 0x6a6850);
  wr32u(self + 0xcc2, widget(rd32u(self + 0xc7e), 0x6a7afc));
  u32 k = rd32u(self + 0xcee);
  if (k == 0 || k == 3) vcall<void>((void *)rd32u(self + 0xc7e), 0xbc, 1);
}
PCREG(56bd90, fn_56bd90);
