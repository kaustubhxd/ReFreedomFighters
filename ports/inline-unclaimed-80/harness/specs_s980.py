"""specs_s980.py - unclaimed-80 residue-19 batch 58 (docs/20-unclaimed-80.md), see src/batch980.cpp. self: +4 = array of n dwords, +8 = object o (null 15%),
+0xc = n (1..15, or 0 about 10%), +0x10 = mask 0x0f. o has a logging vtable: slot 0x4c writes a flag to its out-pointer; slot 0x5c returns idx[k] (a
per-case list of 1..n values whose low nibble is in 1..n and whose high bits are random, so the masked index stays inside
the buffer; a masked index of 0 would store to buf[-1], which in the exe is the pushed &local argument) and writes local = (k < len-1), k = a call counter in o's memory.
p (the argument) is null 20% of the time, else a logging object whose slot +4 (one argument) returns 0. The memset 0x634d10 is hooked by address with a
recording cdecl stub that really writes the bytes (so the stack buffer starts zeroed in both runs)."""
from pilot import S

RET_MASK = 0x0f


def _rd(e, a):
    return int.from_bytes(bytes(e.rbytes(a, 4)), 'little')


def _gen(c):
    def hmemset(em, r):
        dst, val, nn = em.arg32(0), em.arg32(1), em.arg32(2)
        c.emu.calllog.append(('memset', None, None, (nn,)))
        c.emu.wbytes(dst, bytes([val & 0xff]) * nn)
        em.ret(eax=dst, argbytes=0)

    c.emu.hook(0x634d10, hmemset)
    n = 0 if c.rng.random() < 0.1 else c.rng.randint(1, 15)
    self_o = c.emu.alloc(0x20, 4)
    c.emu.wbytes(self_o, bytes(0x20))
    arr = c.emu.alloc(0x40, 4)
    c.emu.wbytes(arr, bytes(0x40))
    for i in range(16):
        c.emu.w32(arr + 4 * i, c.rng.getrandbits(32))
    c.emu.w32(self_o + 4, arr)
    c.emu.w32(self_o + 0xc, n)
    c.emu.w32(self_o + 0x10, RET_MASK)
    if c.rng.random() < 0.85:
        o = c.emu.alloc(0x80, 4)
        c.emu.wbytes(o, bytes(0x80))
        L = c.rng.randint(1, max(1, n)) if n else 1
        idxs = [(c.rng.getrandbits(28) << 4) | c.rng.randint(1, max(1, n)) for _ in range(L)] if n else [1]
        def impl4c(e, a, o=o):
            e.w32(o + 0x60, 0)     # reset the per-run call counter (both runs start with this call)
            e.w32(a[0], 0)
            return (0, None)

        def impl5c(e, a, o=o, idxs=idxs):
            k = _rd(e, o + 0x60)
            e.w32(o + 0x60, k + 1)
            flag = 1 if k < len(idxs) - 1 else 0
            e.w32(a[0], flag)
            return (idxs[k] if k < len(idxs) else 0, None)

        vt = c.emu.logging_vtable('ZGroupE', 0x18, impl={0x4c: impl4c, 0x5c: impl5c}, argwords={0x4c: 1, 0x5c: 1})
        c.emu.w32(o, vt)
        c.emu.w32(o + 0x60, 0)
        c.emu.w32(self_o + 8, o)
    else:
        c.emu.w32(self_o + 8, 0)
    if c.rng.random() < 0.2:
        p = 0
    else:
        p = c.emu.alloc(0x20, 4)
        c.emu.wbytes(p, bytes(0x20))
        c.emu.w32(p, c.emu.logging_vtable('ZGroupP', 0x6, argwords={4: 1}))
    return [self_o, p]


S(0x4ce3b0, 'stack buffer walk with vslot calls (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-80 residue-19; memset 0x634d10 hooked (writes bytes); cookie 0x633654 omitted; one stack argument, ret 4')
