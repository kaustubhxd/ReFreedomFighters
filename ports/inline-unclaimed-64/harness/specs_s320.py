"""specs_s320.py - decomp area 64 (docs/20-unclaimed-64.md): 0x5738f0 broadcasts to four child vtbl slots 0xf8."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _bcast(c):
    e = c.emu
    self_ = _rnd(c, 0x40)
    for i in range(4):
        if c.rng.random() < 0.2:
            e.w32(self_ + 0x18 + 4 * i, 0)          # null child: skipped
            continue
        # Each child's slot 0xf8 pops its two stack words (the exe callers are thiscall).
        vt = e.logging_vtable('child5738_%d' % i, 0x80, argwords={0xf8: 2})
        child = _rnd(c, 0x40)
        e.w32(child, vt)
        e.w32(self_ + 0x18 + 4 * i, child)
    e.w32(self_ + 0x28, c.rng.getrandbits(32))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5738f0, 'broadcast (GUESS)', 'thiscall', None, ret='al', gen=_bcast,
  note='batch320; stack words unused and a; ret 8; four children, vtbl 0xf8 with 2 args')
