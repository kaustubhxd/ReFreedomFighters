"""specs_s223000.py - controlled reader/engine state for 0x5aa250."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj, pystub, rnd, sysobj


def g5aa250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self = rnd(c, 0xa40)

    def zero32(emu, k):
        p = emu.arg32(0)
        if p:
            emu.w32(p, 0)

    def zero_block(emu, k):
        p, n = emu.arg32(0), emu.arg32(1)
        if p:
            emu.wbytes(p, bytes(min(n, 0x400)))

    reader = obj(c, 0x20, {
        0x18: pystub(c, 2, ret=0, this=True, side=zero_block),
        0x40: pystub(c, 1, ret=0, this=True, stackmark=(0,), side=zero32),
        0x48: pystub(c, 1, ret=0, this=True, stackmark=(0,), side=zero32),
        0x50: pystub(c, 1, ret=0, this=True, stackmark=(0,), side=zero32),
        0x68: pystub(c, 1, ret=0, this=True, stackmark=(0,), side=zero32),
    }, nslots=0x1b)

    table_slot = pystub(c, 1, ret=0, this=True)
    sys = sysobj(c, table_slots={0x58: table_slot}, table_size=0x20)
    clock = obj(c, 0x20, {
        0x0c: pystub(c, 1, ret=0, this=True),
        0xd8: pystub(c, 0, ret=0, this=True),
        0xdc: pystub(c, 0, ret=0, this=True),
    }, nslots=0x38)
    e.w32(sys + 0x190f, clock)

    # Exercise both the short and full paths during every strict run.
    gate = r.choice([0, 1, 1, 1])
    hook_rec(c, 0x45f3c0, 1, ret=gate, this=True)

    def init_vectors(emu, k):
        p = emu.reg('ecx')
        for off in (0x659, 0x65d, 0x665, 0x669, 0x671, 0x675):
            emu.w32(p + off, 0)

    hook_rec(c, 0x5a6980, 0, ret=0, this=True, side=init_vectors)
    hook_rec(c, 0x5aa190, 1, ret=0, this=True)
    return [self, reader]


S(0x5aa250, 'reader_initializer', 'thiscall', None, ret='al', gen=g5aa250, reg_values=True)
