"""specs_s358.py - area 76, batch 358: 0x61fd60 (cdecl, three arguments (obj, key, nsize), eax result; GUESS; parked row).

The object: +0 table, +4 size, +8 count, +0xc capacity, +0x10 the allocator's function table (slot 0 alloc, slot 8 free; plain cdecl
stubs). Allocation comes from a per-run pool (the stubs advance a closure counter that gen resets), so the node addresses match on both
sides. The memset import (0x676260) is a stub that fills bytes. 0x61fce0 (the hash of the first table) runs as exe code. Some cases
start with no table (size 0); others have a populated table with keys drawn from a fixed list (so found, probe and not-found all run),
and capacity equal to count (so the grow path runs about a third of the time)."""
import struct
from pilot import S

KEYS = ['alpha', 'beta', 'gamma', 'xmlns', 'xmlns:a', 'zz', '', 'a:b', 'abc', 'xmlns:']


def _gen(c):
    e = c.emu
    rng = c.rng

    pool = e.alloc(0x4000, 16)
    off = [0]

    def h_alloc(em, r):
        n = em.arg32(0)
        p = pool + off[0]
        off[0] += (max(n, 1) + 15) & ~15
        if off[0] > 0x4000:
            p = 0
        em.calllog.append(('h_alloc', 0, None, (n,)))
        em.ret(eax=p, argbytes=0)

    def h_free(em, r):
        em.calllog.append(('h_free', 8, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    VT = e.fake_vtable('alloc61fd60', 4, {0: h_alloc, 8: h_free})

    def _memset(em, r):
        dst, val, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n:
            em.mu.mem_write(dst, bytes([val & 0xff]) * n)
        em.ret(eax=dst, argbytes=0)

    e.stub_import('memset', _memset)

    strs = {k: e.cstr(k) for k in KEYS}

    O = e.alloc(0x40, 4)
    e.wbytes(O, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(O + 0x10, VT)
    if rng.random() < 0.2:
        e.w32(O + 0, 0)
        e.w32(O + 4, 0)
        e.w32(O + 8, 0)
        e.w32(O + 0xc, rng.choice([0, 0x20]))
    else:
        size = rng.choice([4, 8, 16])
        tbl = e.alloc(size * 4, 4)
        e.wbytes(tbl, bytes(size * 4))
        count = rng.randint(0, size // 2)
        placed = 0
        for _ in range(count):
            node = e.alloc(16, 4)
            e.wbytes(node, bytes(16))
            e.w32(node, strs[rng.choice(KEYS)])
            slot = rng.randrange(size)
            while e.mu.mem_read(tbl + slot * 4, 1)[0] or any(e.mu.mem_read(tbl + slot * 4 + k, 1)[0] for k in range(4)):
                slot = (slot + 1) % size
            e.w32(tbl + slot * 4, node)
            placed += 1
        e.w32(O, tbl)
        e.w32(O + 4, size)
        e.w32(O + 8, placed)
        e.w32(O + 0xc, placed if rng.random() < 0.35 else size // 2 + rng.randint(0, 2))

    key = strs[rng.choice(KEYS)]
    nsize = rng.choice([0, 8, 12, 12])
    return [O, key, nsize]


S(0x61fd60, 'pe_61fd60 (GUESS)', 'cdecl', None, ret='eax', gen=_gen,
  note='area 76 batch 358; parked row; memset import stubbed; 0x61fce0 runs as exe code')
