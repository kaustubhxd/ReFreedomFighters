"""specs_s38010.py - cascade s8 batch 38010: 0x579590. Engine slot 0x190 returns an object whose slot 0x198 (cdecl, 4 args) fills the text buffer with random bytes; the table
object (engine +0x9b) slot 0x134 returns a helper whose slot 0x90 (buf, &flag) records the text and writes a random flag byte, and whose slot 0x68 (buf, flag, 0) is a custom
recorder (only the low byte of the flag argument is defined: the original pushes a dword whose upper bytes are stack garbage); 0x579a60 / 0x579bd0 / 0x579b20 likewise record
the low byte only. 0x5626c0 / 0x563510 / 0x563610 hooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g579590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fill(em, k):
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0x20)))

    def flagw(em, k):
        em.wbytes(em.arg32(1), bytes([r.choice([0, 1, r.getrandbits(8)])]))
    A = obj(c, 0x20, {0x198: pystub(c, 4, pop=0, stackmark=(1,), side=fill)})

    def s68(em, res_):
        em.calllog.append(('s68', em.reg('ecx'), em.rbytes(em.arg32(0), 0x20), em.arg32(1) & 0xff, em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    X = obj(c, 0x80, {0x90: pystub(c, 2, this=True, deref={0: -0x20}, stackmark=(1,), side=flagw), 0x68: e.stub_fn('s68', s68)})
    so = sysobj(c, {0x190: pystub(c, 0, this=True, ret=A)},
                table_slots={0x134: pystub(c, 0, this=True, ret=X), 0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    me = rnd(c, 0x200)
    e.w32(me + 0x94, rnd(c, 0x13300))

    def low(addr):
        def h(em, res_):
            em.calllog.append(('lo', addr, em.reg('ecx'), em.arg32(0) & 0xff))
            em.ret(eax=r.getrandbits(32), argbytes=4)
        e.hook(addr, h)
    for a in (0x579a60, 0x579bd0, 0x579b20):
        low(a)
    hook_rec(c, 0x5626c0, 0, this=True)
    hook_rec(c, 0x563510, 1, this=True, pop=4)
    hook_rec(c, 0x563610, 1, this=True, pop=4)
    return [me]


S(0x579590, 'GUESS look up four named settings and apply', 'thiscall', None, ret=None, gen=_g579590, note='batch38010')
