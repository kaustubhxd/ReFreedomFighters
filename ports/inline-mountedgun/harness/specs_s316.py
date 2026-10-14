"""specs_s316.py - mounted gun batch 316: ZTankIf::InitTankPosDir wrapper. ZTank::InitTankPosDir (0x520f20) is
hooked: both sides call the same Python hook, which logs its this and bool argument."""
from pilot import S
from mg_helpers import _rnd, flush, make_block


def _gen(c):
    r = c.rng

    def h(e, rr):
        e.calllog.append(('InitTankPosDir', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    c.emu.hook(0x520f20, h)
    s = _rnd(c, 0x40)
    tank = _rnd(c, 0x40)
    c.emu.w32(s + 0x1c, tank)
    inb, _ = make_block(c, [(r.choice([0, 1, r.getrandbits(32)]), r.choice([0, 1]))], first=r.randint(0, 2))
    par = _rnd(c, 0x10)
    c.emu.w32(par + 4, inb)
    flush(c)
    return [s, par]


S(0x522820, 'ZTankIf::InitTankPosDir', 'thiscall', None, gen=_gen, note='batch316; callee hooked')
