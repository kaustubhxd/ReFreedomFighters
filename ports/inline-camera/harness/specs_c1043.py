"""specs_c1043.py - camera batch 1043: ZCAMERA::Init."""
from pilot import S
from camgen import rnd, Log


def _init(c):
    log = Log(c)
    r = c.rng
    v = {0xd8: r.randint(-100000, 100000), 0xdc: r.randint(-100000, 100000)}

    def mk(slot):
        def h(e, res):
            log.put(slot)
            e.ret(eax=v[slot], argbytes=0)
        return h

    a1 = rnd(c, 0x40)
    c.emu.w32(a1, c.emu.fake_vtable('src', 0xe0 // 4, {0xd8: mk(0xd8), 0xdc: mk(0xdc)}))
    cam = rnd(c, 0x100)
    return [cam, a1]


S(0x445ff0, 'ZCAMERA::Init', 'thiscall', gen=_init)
