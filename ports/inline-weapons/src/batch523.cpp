// batch523.cpp - weapons thread, batch 523: hand requests sent to the owner as script commands. Each builds a CCom
// (a 16 KB command block on the stack) with named values and sends it through the owner's ClassCommand (slot 0x168)
// with a registered message id kept in a global: DropItem 0x6ff9a4, PickupItem 0x6ff9ac, PushButton 0x6ff9a0
// ("rItem" = the object's handle), UseItem 0x6ff9a8 ("lItems" = a one-entry REFTAB32 with the item's handle or 0,
// "lItemType" = the int argument).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_4d2280(void *com);                           // CCom::CCom
extern "C" void THISCALL ext_4d3ab0(void *com, const char *name, u32 v);   // CSharedCom::SetVal(const char*, int)
extern "C" void THISCALL ext_4d2330(void *com);                           // CCom::~CCom
extern "C" void THISCALL ext_4ccba0(void *t);                             // REFTAB32::REFTAB32
extern "C" void THISCALL ext_4cd540(void *t, u32 h);                      // REFTAB::Add
extern "C" void THISCALL ext_4ccf60(void *t);                             // REFTAB32::~REFTAB32

static inline u32 handleOf(u32 o) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vUU)VT(rm, 0x4c))(rm, o);
}
static inline void sendItem(u8 *s, u32 obj, u32 msgGlobal) {
  alignas(4) u8 com[0x40c4];
  ext_4d2280(com);
  ext_4d3ab0(com, (const char *)0x688a30, handleOf(obj));   // "rItem"
  ((vUUU)VT(s, 0x168))(s, *(u16 *)msgGlobal, (u32)com);
  ext_4d2330(com);
}
static void THISCALL dropItem(u8 *s, u32 item) { sendItem(s, item, 0x6ff9a4); }
PCREG(473a70, dropItem);
static void THISCALL pickupItem(u8 *s, u32 item) { sendItem(s, item, 0x6ff9ac); }
PCREG(474e00, pickupItem);
static void THISCALL pushButton(u8 *s, u32 geom) { sendItem(s, geom, 0x6ff9a0); }
PCREG(474f60, pushButton);

static void THISCALL useItem(u8 *s, u32 item, u32 type) {
  alignas(4) u8 com[0x40c4];
  alignas(4) u8 tab[0xb0];
  ext_4d2280(com);
  ext_4ccba0(tab);
  ext_4cd540(tab, item ? handleOf(item) : 0);
  ext_4d3ab0(com, (const char *)0x68983c, (u32)tab);   // "lItems"
  ext_4d3ab0(com, (const char *)0x689844, type);       // "lItemType"
  ((vUUU)VT(s, 0x168))(s, *(u16 *)0x6ff9a8, (u32)com);
  ext_4ccf60(tab);
  ext_4d2330(com);
}
PCREG(476100, useItem);
