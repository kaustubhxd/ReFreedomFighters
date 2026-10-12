"""specs_s193.py - unclaimed area 19 (docs/20-unclaimed-19.md): two thiscall functions with vtable-slot calls."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flag(c):
    self_ = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x10, 0)
        obj = _rnd(c, 0x40)

        def set_child(em, a, self_=self_, obj=obj):
            em.w32(self_ + 0x10, obj)
            return (0, None)
        vt = c.emu.logging_vtable('self45d1', 17, impl={0x40: set_child})
        c.emu.w32(self_, vt)
    else:
        obj = _rnd(c, 0x40)
        c.emu.w32(self_ + 0x10, obj)
        vt = c.emu.logging_vtable('self45d1', 17)
        c.emu.w32(self_, vt)
    flag = c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(32)])
    return [self_, flag]


def _keyed(c):
    self_ = _rnd(c, 0x400)
    word = c.rng.getrandbits(16)
    c.emu.w16(self_ + 0x207, word)
    vt = c.emu.logging_vtable('self51be', 0xe6, impl={0x394: lambda em, a: (0, None)}, argwords={0x394: 1})
    c.emu.w32(self_, vt)
    key = word if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [self_, key, c.rng.getrandbits(32)]


S(0x45d1a0, 'setFlag (GUESS)', 'thiscall', None, ret=None, gen=_flag, note='batch193; stack byte flag, ret 4')
# 0x51be20 (keyedCall) is held out: the logged slot is 364 (0x16c), not 0x394, so the stub does not line up; see docs/20-unclaimed-19.md
