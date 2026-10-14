"""specs_s38018.py - cascade s8 batch 38018: 0x464a20. Owner object with recording slots 0x270, 0x264 (returns a child-holder or 0, sequence random), name providers at +0x5c / +0x60 (0x4e5330 hooked, returns
a heap string whose first byte is 0 about 30% of the time), keys at +0x11a / +0x11e (zero 30%), flags drawn from the bits 0x80 / 0x20 / 0x10. The holder's slots 0x20 (6 args) and 0x1bc return a child (or 0);
0x4db3b0 returns a helper (or 0); the table's slot 0x4c returns a random handle."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g464a20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    child = obj(c, 0x40, {0x2c: pystub(c, 0, this=True), 0x138: pystub(c, 3, this=True)})
    pc = r.choice([0.3, 0.8, 1.0])
    holder = obj(c, 0x40, {0x20: pystub(c, 6, this=True, ret=lambda em, k: r.getrandbits(32)),
                           0x1bc: pystub(c, 1, this=True, ret=lambda em, k: child if r.random() < pc else 0)})
    ph = r.choice([0.2, 0.5, 0.8])
    helper = obj(c, 0x20, {0x288: pystub(c, 3, this=True)})
    so = sysobj(c, {}, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    me = obj(c, 0x200, {0x270: pystub(c, 2, this=True),
                        0x264: pystub(c, 3, this=True, ret=lambda em, k: holder if r.random() < ph else 0)})

    def mkname():
        p = rnd(c, 8)
        if r.random() < 0.3:
            e.wbytes(p, b'\0')
        else:
            e.wbytes(p, b'A')
        return p
    names = [mkname(), mkname()]
    objs = [rnd(c, 0x20), rnd(c, 0x20)]
    m = {objs[0]: names[0], objs[1]: names[1]}

    def n5330(em, res_):
        em.calllog.append(('n5330', em.reg('ecx')))
        em.ret(eax=m[em.reg('ecx')], argbytes=0)
    e.hook(0x4e5330, n5330)
    for off, o in ((0x5c, objs[0]), (0x60, objs[1])):
        e.w32(me + off, o if r.random() < 0.75 else 0)
    for off in (0x11a, 0x11e):
        e.wbytes(me + off, struct.pack('<I', 0 if r.random() < 0.3 else r.getrandbits(32) | 1))
    e.wbytes(me + 0x126, struct.pack('<H', r.getrandbits(16)))
    e.w32(me + 8, rnd(c, 0x20))
    hook_rec(c, 0x4db3b0, 0, this=True, ret=lambda em, k: helper if r.random() < 0.8 else 0)
    flags = r.choice([0, 0x80, 0x80, 0x80, 0xa0, 0x90, 0xb0, 0x80 | r.getrandbits(8), r.getrandbits(32)])
    return [me, r.getrandbits(32), flags]


S(0x464a20, 'GUESS attach named child object', 'thiscall', None, ret=None, gen=_g464a20, note='batch38018')
