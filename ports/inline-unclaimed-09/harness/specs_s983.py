"""specs_s983.py - area 56 band, claim A49 (0x536750): a search loop with a register-argument call.

this is a 0x5400-byte object of random bytes whose field at +0x5302 is random and non-zero (zero in about one case in eight). The
exe reads its array at base + field, so the spec allocates the array at arr and passes base = arr - field; arr holds count dwords,
each (entry - field), so arr[i] + field is a heap entry (0x20 random bytes). count is 1 to 4; a is random. 0x4cc850 is hooked (GUESS:
register arguments ecx and edx; plain ret; returns zero in about half the cases, else a random dword). ret='eax'."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h(e2, r):
        e2.calllog.append(('H4cc850', e2.reg('ecx'), e2.reg('edx')))
        e2.ret(eax=rv, argbytes=0)

    rv = 0 if rng.random() < 0.5 else (rng.getrandbits(32) | 1)
    e.hook(0x4cc850, h)
    this = e.alloc(0x5400, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x5400)))
    field = 0 if rng.random() < 0.125 else (rng.getrandbits(32) | 1)
    e.w32(this + 0x5302, field)
    count = rng.randint(1, 4)
    arr = e.alloc(4 * count + 4, 4)
    for i in range(count):
        entry = e.alloc(0x20, 4)
        e.wbytes(entry, bytes(rng.getrandbits(8) for _ in range(0x20)))
        e.w32(arr + 4 * i, (entry - field) & 0xffffffff)
    base = (arr - field) & 0xffffffff
    a = rng.getrandbits(32)
    return [this, base, count, a]


S(0x536750, 'unnamed 0x536750 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A49; 0x4cc850 hooked (GUESS stub, register arguments)')
