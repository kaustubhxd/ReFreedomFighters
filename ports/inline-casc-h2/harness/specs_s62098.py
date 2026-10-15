from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    assert_fn = e.stub_fn('assert hook', lambda emu, res: emu.ret(eax=r.getrandbits(32)))
    e.w32(0x7003b0, assert_fn)
    self = rnd(c, 0x200)
    for off in (0x1d2, 0x1d6, 0x1da):
        e.w32(self + off, r.getrandbits(32))
    values = {off: r.getrandbits(32) for off in (0x18, 0x40, 0x50)}
    def write_at(off):
        return lambda emu, k: emu.w32(emu.arg32(0), values[off])
    source = obj(c, 0x60, {
        0x18: pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32)),
        0x40: pystub(c, 1, this=True, pop=4, side=write_at(0x40)),
        0x50: pystub(c, 1, this=True, pop=4, side=write_at(0x50)),
    })
    accepted = r.choice([0, 1, 0x100, 0x101])
    hook_rec(c, 0x466dc0, 1, this=True, pop=4, ret=accepted)
    return [self, source]


S(0x468220, 'GUESS validate then fill three object fields', 'thiscall', None,
  ret='al', gen=gen, note='batch62098')
