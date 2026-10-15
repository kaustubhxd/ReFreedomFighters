// batch358.cpp - area 76 (docs/20-unclaimed-76.md, parked row 0x61fd60): cdecl, three arguments (obj, key, nsize), eax result (GUESS).
// A string-keyed open-addressed table in the object: +0 table (node pointers), +4 size (a power of two; 0 means not created),
// +8 count, +0xc capacity, +0x10 the allocator's function table (slot 0 = alloc(size), slot 8 = free(p); plain cdecl calls).
// A node is the allocation of nsize bytes; its first dword is the key string. The hash is h = h * 33 + c (the same as 0x61fce0).
// Lookup walks backwards from h & (size - 1) until an empty slot. Found: return the node. Not found and nsize == 0: return 0.
// Otherwise: insert (when count < capacity), or grow to twice the size (rehash every node backwards, free the old table, capacity =
// size / 2) and insert. The memset helper 0x634d10 (import thunk) and 0x61fce0 (the hash, for the first table) are exe code.
#include "ff.h"

extern "C" u32 __attribute__((cdecl)) ext_61fce0(u32 key);
extern "C" void __attribute__((cdecl)) ext_634d10(u32 dst, u32 val, u32 n);

typedef u32(__attribute__((cdecl)) * alloc_t)(u32);
typedef void(__attribute__((cdecl)) * free_t)(u32);

#define RU(a) (*(u32 *)(u32)(a))

static u32 hashStr(u32 s) {
    u32 h = 0u;
    for (const u8 *p = (const u8 *)s; *p != 0u; p++) h = h * 33u + *p;
    return h;
}
static bool strEq(u32 a, u32 b) {
    for (u32 i = 0u;; i++) {
        u8 x = *(u8 *)(a + i);
        u8 y = *(u8 *)(b + i);
        if (x != y) return false;
        if (x == 0u) return true;
    }
}
static u32 allocN(u32 O, u32 size) {
    u32 fn = RU(RU(O + 0x10u));
    return ((alloc_t)fn)(size);
}
static void freeP(u32 O, u32 p) {
    u32 fn = RU(RU(O + 0x10u) + 8u);
    ((free_t)fn)(p);
}

// 61ff50: the node of nsize bytes goes into slot idx; the key is its first dword; count++; returns the node
static u32 insertAt(u32 O, u32 key, u32 nsize, u32 idx) {
    u32 node = allocN(O, nsize);
    RU(RU(O) + idx * 4u) = node;
    if (node == 0u) return 0u;
    ext_634d10(node, 0u, nsize);
    RU(node) = key;
    RU(O + 8u) += 1u;
    return RU(RU(O) + idx * 4u);
}

static u32 __attribute__((cdecl)) f61fd60(u32 O, u32 key, u32 nsize) {
    if (RU(O + 4u) == 0u) {
        if (nsize == 0u) return 0u;
        u32 tbl = allocN(O, 0x100u);
        RU(O) = tbl;
        if (tbl == 0u) return 0u;
        ext_634d10(tbl, 0u, 0x100u);
        RU(O + 4u) = 0x40u;
        RU(O + 0xcu) = 0x20u;
        u32 idx0 = ext_61fce0(key) & 0x3fu;
        return insertAt(O, key, nsize, idx0);
    }
    u32 h = hashStr(key);
    u32 size = RU(O + 4u);
    u32 mask = size - 1u;
    u32 idx = h & mask;
    u32 table = RU(O);
    u32 slot = idx;
    u8 c0 = *(u8 *)key;
    if (RU(table + idx * 4u) != 0u) {
        for (;;) {
            u32 node = RU(RU(O) + slot * 4u);
            u32 S = RU(node);
            if (c0 == *(u8 *)S && strEq(key, S)) return node;
            slot = (slot == 0u) ? mask : slot - 1u;
            if (RU(RU(O) + slot * 4u) == 0u) break;
        }
    }
    if (nsize == 0u) return 0u;
    if (RU(O + 8u) != RU(O + 0xcu)) return insertAt(O, key, nsize, slot);

    // grow: the new size is twice the old size; every node is rehashed backwards into the new table
    u32 newsize = size * 2u;
    u32 nt = allocN(O, newsize * 4u);
    if (nt == 0u) return 0u;
    ext_634d10(nt, 0u, newsize * 4u);
    for (u32 i = 0u; i < size; i++) {
        u32 node = RU(RU(O) + i * 4u);
        if (node == 0u) continue;
        u32 h2 = hashStr(RU(node));
        u32 s2 = h2 & (newsize - 1u);
        if (RU(nt + s2 * 4u) != 0u) {
            for (;;) {
                s2 = (s2 == 0u) ? (newsize - 1u) : s2 - 1u;
                if (RU(nt + s2 * 4u) == 0u) break;
            }
        }
        RU(nt + s2 * 4u) = node;
    }
    freeP(O, RU(O));
    RU(O + 4u) = newsize;
    RU(O) = nt;
    RU(O + 0xcu) = newsize / 2u;
    u32 idx2 = h & (newsize - 1u);
    if (RU(nt + idx2 * 4u) != 0u) {
        for (;;) {
            idx2 = (idx2 == 0u) ? (newsize - 1u) : idx2 - 1u;
            if (RU(nt + idx2 * 4u) == 0u) break;
        }
    }
    return insertAt(O, key, nsize, idx2);
}
PCREG(61fd60, f61fd60);
