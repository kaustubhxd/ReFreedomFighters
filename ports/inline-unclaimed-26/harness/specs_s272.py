"""specs_s272.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x45fc90, engine slot 0x130, pool range check against
o+0x1c5d (header at block-8), else copy the string into a new block from exe allocator 0x41e290 (stubbed here)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _str(c, e):
    n = c.rng.randrange(0, 40)
    s = _rnd(c, 64)
    body = bytes(c.rng.choice(b'abcdefgh') for _ in range(n)) + b'\x00'
    e.wbytes(s, body)
    return s


def _rng(c):
    e = c.emu
    o_vt = e.logging_vtable('eng45fc', 0x4d, impl={}, argwords={0x130: 1})
    o = _rnd(c, 0x2000)
    e.w32(o, o_vt)
    size = c.rng.choice([0x40, 0x100, 0x7f])
    blk = _rnd(c, size + 0x20) + 0x10            # header at blk-8: low 29 bits are the size
    e.w32(blk - 8, size | (c.rng.getrandbits(3) << 29))
    if c.rng.random() < 0.15:
        e.w32(o + 0x1c5d, 0)
        fast_ok = False
    else:
        e.w32(o + 0x1c5d, blk)
        fast_ok = True
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)

    def alloc_fill(em, r):
        n = max(em.arg32(0), 1)
        p = em.alloc(n, 4)
        em.wbytes(p, b'\xa5' * n)            # not zero, so a missing NUL copy shows up
        em.ret(eax=p, argbytes=0)
    e.hook(0x41e290, alloc_fill)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 4, c.rng.getrandbits(32))
    if fast_ok and c.rng.random() < 0.6:
        arg = blk + c.rng.randrange(-4, size + 4)
    else:
        arg = _str(c, e)
    return [self_, arg & 0xffffffff]


S(0x45fc90, 'internStr (GUESS)', 'thiscall', None, ret=None, gen=_rng, note='batch272; exe 0x41e290 stubbed; ret 4')
