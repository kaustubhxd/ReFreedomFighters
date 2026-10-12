"""specs_s1007.py - unclaimed-04 batch 7 (docs/20-unclaimed-04.md): CEntityTracker::GetEntityNear (0x5c0330, high name).
thiscall, four stack arguments (ret 0x10): pos, radius (float), index (int *, in and out), mask.
The tracker is 0x1000 random bytes with count (+0x54) 0 to 8, a record pool at +0x50 (records of 0x17 bytes; the key is
the float at +4, the vector is +4..+0x10), and an array of record numbers at +0x4c, sorted by key in half the cases.
Each record's first dword is a fake entity: vtable slot 0x20 returns X, X+8 is Y, Y+0x3c is a random flag dword, and
the entity's +0x54 points to a type record whose +4 is a shift count (0..40). The index starts at -1 in half the cases,
else at a small value. The distance helper 0x4e0830 and the function 0x43e920 under it are original code."""
import struct

from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fv(c, lo, hi):
    return c.rng.uniform(lo, hi)


def _entity(c):
    ent = c.emu.alloc(0x60, 4)
    typ = c.emu.alloc(0x10, 4)
    c.emu.w32(typ + 4, c.rng.randrange(0, 41))
    c.emu.w32(ent + 0x54, typ)
    x = c.emu.alloc(0x10, 4)
    y = c.emu.alloc(0x40, 4)
    c.emu.w32(y + 0x3c, c.rng.getrandbits(32))
    c.emu.w32(x + 8, y)
    vt = c.emu.logging_vtable('entity', 0x24 // 4 + 1, impl={0x20: lambda em, a: (x, None)}, argwords={0x20: 0})
    c.emu.w32(ent, vt)
    return ent


def _args(c):
    n = c.rng.choice([0, 1, 2, 3, 5, 8])
    tracker = _rnd(c, 0x1000)
    c.emu.w32(tracker + 0x54, n)
    c.emu.wbytes(tracker + 0x60, struct.pack('<f', _fv(c, -10.0, 10.0)))

    pool = c.emu.alloc(0x17 * max(n, 1) + 0x20, 4)
    keys = []
    for i in range(n):
        rec = pool + 0x17 * i
        key = _fv(c, -50.0, 50.0)
        keys.append(key)
        c.emu.w32(rec, _entity(c))
        c.emu.wbytes(rec + 4, struct.pack('<fff', key, _fv(c, -50.0, 50.0), _fv(c, -50.0, 50.0)))
        c.emu.wbytes(rec + 0x10, bytes(7))
    order = list(range(n))
    if c.rng.random() < 0.5:
        order.sort(key=lambda i: keys[i])
    arr = c.emu.alloc(4 * max(n, 1), 4)
    for k, i in enumerate(order):
        c.emu.w32(arr + 4 * k, i)
    c.emu.w32(tracker + 0x4c, arr)
    c.emu.w32(tracker + 0x50, pool)

    pos = c.emu.alloc(12, 4)
    c.emu.wbytes(pos, struct.pack('<fff', _fv(c, -50.0, 50.0), _fv(c, -50.0, 50.0), _fv(c, -50.0, 50.0)))
    radius = _fv(c, 0.0, 50.0)

    index = c.emu.alloc(4, 4)
    # callers pass -1 (start of search) or a record number from the last search; -2 and beyond are out of the domain
    start = c.rng.choice([-1, -1, 0, 1, max(n - 1, 0), c.rng.randrange(0, max(n, 1))])
    c.emu.w32(index, start & 0xffffffff)

    mask = c.rng.choice([0xffffffff, c.rng.getrandbits(32), 1 << c.rng.randrange(0, 32)])
    return [tracker, pos, F(radius), index, mask]


S(0x5c0330, 'CEntityTracker::GetEntityNear (high) thiscall', 'thiscall', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 7; entity vtable slot 0x20 is a logging stub; 0x4e0830 is original code')
