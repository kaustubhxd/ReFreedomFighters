"""specs_s334.py - decomp area 64 (docs/20-unclaimed-64.md): 0x43fab0 calls child slot 8 (4 words), then self slot 0x28c (3 words)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rec(c):
    e = c.emu
    # Record cell: slot 8 writes its four arguments, slot 0x28c writes its three; a per-case result record R.
    cell = _rnd(c, 0x20)
    R = _rnd(c, 0x80)
    rv = 0 if c.rng.random() < 0.3 else R

    def rec8(em, a):
        for i in range(4):
            em.w32(cell + 4 * i, a[i])
        return (rv, None)

    def rec28c(em, a):
        for i in range(3):
            em.w32(cell + 0x10 + 4 * i, a[i])
        return (0, None)

    # C: the child at sys[+0x9b][+8]. C's slot 8 takes four words and returns rv.
    c_vt = e.logging_vtable('C43fab', 0x40, argwords={0x8: 4}, impl={0x8: rec8})
    C = _rnd(c, 0x40)
    e.w32(C, c_vt)
    ch = _rnd(c, 0x20)
    e.w32(ch + 0x8, C)
    sys_ = _rnd(c, 0x100)
    e.w32(sys_ + 0x9b, ch)
    e.w32(0x70039c, sys_)

    # self: its slot 0x28c takes three words.
    self_vt = e.logging_vtable('self43fab', 0x200, argwords={0x28c: 3}, impl={0x28c: rec28c})
    self_ = _rnd(c, 0x40)
    e.w32(self_, self_vt)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x43fab0, 'requestRecord (GUESS)', 'thiscall', None, ret='eax', gen=_rec,
  note='batch334; four stack words; ret 0x10; C slot 8 (4 words), self slot 0x28c (3 words)')
