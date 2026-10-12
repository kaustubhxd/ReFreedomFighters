// batch6209.cpp - unclaimed-62 claim 4 (slice 1): 0x4d9190 (no name in the name map) [thiscall, ret 8: name, len]. len 0 means strlen(name).
// key = 0x4d8db0(this, name, len) (exe); entry = (member)->slot 8 (key, 0); if entry and its dword +0x11 is non-zero, found = 0x4d8ef0(this,
// that dword, name, len) (exe); if found and this+4 is zero, the dword at found is freed (sized free, size 0); then the dword's object gets
// slot 0x20 (found), its slot 0x14 is asked and, if zero, slot 0 is called with 1 (delete); last the member's slot 4 gets the entry.
#include "ff.h"

extern "C" u32 THISCALL ext_4d8db0(u8 *self, const char *name, u32 len);             // exe (ret 8)
extern "C" u32 THISCALL ext_4d8ef0(u8 *self, u32 key, const char *name, u32 len);     // exe (ret 0xc)
extern "C" void ext_634273(void *p, u32 size);                                        // sized free

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL nameLookupRemove(u8 *self, const char *name, u32 len) {
  if (len == 0) {
    const char *q = name;
    while (*q) q++;
    len = (u32)(q - name);
  }
  u32 key = ext_4d8db0(self, name, len);
  u8 *member = rdp(self);
  u8 *entry = (u8 *)vcall<u32>(member, 0x8, key, (u32)0);
  if (!entry) return;
  u32 edi = rd32u(entry + 0x11);
  if (!edi) return;
  u32 found = ext_4d8ef0(self, edi, name, len);
  if (!found) return;
  if (self[4] == 0) ext_634273((void *)rd32u((const u8 *)found), 0);
  u8 *obj = (u8 *)edi;
  vcall<void>(obj, 0x20, (u32)found);
  u32 r = vcall<u32>(obj, 0x14);
  if (r == 0) vcall<void>(obj, 0x0, (u32)1);
  vcall<void>(rdp(self), 0x4, (u32)entry);
}
PCREG(4d9190, nameLookupRemove);
