"""specs_s38059.py - cascade s8 batch 38059. The settings helper (table slot 0x134 -> object whose slot 0x88 writes a value through its out pointer, slot 0x5c (3 args) is logged) returns the stored flag
(0 about 40% of the time) and values 0, small, > 100 or random; the settings object (engine slot 0xbc) has recording setters 0x88 / 0x90 / 0x80 and getters 0x84 / 0x8c / 0x7c returning values in and out of
0..100 (negative included). Every helper call is logged with its name pointer in order (custom stubs, since the getters / setters are called with several argument counts)."""
from pilot import S
from recruits_util import obj, sysobj, clear_hooks, pystub


def _g571cc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def val():
        return r.choice([0, 1, 50, 100, 101, 0xffffffff, 0x80000000, r.getrandbits(32)])

    def s88(em, res_):
        name, out = em.arg32(0), em.arg32(1)
        v = val() if name != 0x6a891c else r.choice([0, 0, 1, 2])
        em.calllog.append(('s88', em.reg('ecx') != 0, name, v))
        em.w32(out, v)
        em.ret(eax=0, argbytes=8)

    def s5c(em, res_):
        em.calllog.append(('s5c', em.reg('ecx') != 0, em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    helper = obj(c, 0x40, {0x88: e.stub_fn('s88', s88), 0x5c: e.stub_fn('s5c', s5c)})

    def getter(n):
        return pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 30, 100, 101, 0xffffffff, 0x80000000, r.getrandbits(32)]))
    sett = obj(c, 0x40, {0x88: pystub(c, 1, this=True), 0x90: pystub(c, 1, this=True), 0x80: pystub(c, 1, this=True),
                         0x84: getter(0), 0x8c: getter(1), 0x7c: getter(2)})
    sysobj(c, {0xbc: pystub(c, 0, this=True, ret=sett)}, table_slots={0x134: pystub(c, 0, this=True, ret=helper)})
    return []


S(0x571cc0, 'GUESS load or save volume settings', 'cdecl', None, ret=None, gen=_g571cc0, note='batch38059')
