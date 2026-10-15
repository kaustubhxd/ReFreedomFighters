"""specs_s8825.py - hitreact batch 8825: ZCollisionBox::GetStrips (0x4ea300). The collision base's slot 0x84 is a recording stub (8
arguments, ret 0x20) returning a bool from the case; the logger is [0x700390] slot 0x20 -> an object with a cdecl slot 0x2c."""
from pilot import S
from wkit import rnd, stub, obj


def _gen(c):
    r = c.rng
    emu = c.emu
    ret = r.choice((0, 1, 2, 0x80, 0x100, 0xffffff01, 0xffffff00))
    cb = obj(c, 0x40, {0x84: stub(c, 8, ret=ret)})
    a = rnd(c, 0x40)
    emu.w32(a + 0x1c, cb)
    eng = rnd(c, 0x1b00)
    emu.w32(eng + 0x1aa3, a)
    emu.w32(0x70039c, eng)
    out = obj(c, 0x40, {0x2c: stub(c, 3, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x40, {0x20: stub(c, 2, ret=out)}))
    box = rnd(c, 0x60)
    emu.mu.ctl_flush_tb()
    return [box, r.choice((0x20, 0, 0xffffffff, r.getrandbits(32)))]


S(0x4ea300, 'ZCollisionBox::GetStrips', 'thiscall', ret='al', gen=_gen)
