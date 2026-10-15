"""specs_s67530.py - cascade s6 batch 67530 (0x572090, thiscall(key, arg) ret 8, returns 0). sys[0x9b] table slot 0x58 maps the key to one of three entry objects (pool), the object has
three entry slots at +0x180 drawn from the same pool; sys slots 0xbc (object with slots 0x80 / 0x88 / 0x90) and 0x190 (logger whose vtable slot 0x198 is a cdecl formatter, a custom stub that
fills the stack buffer and logs its arguments); table slot 0x134 returns the logging object with slot 0x60 (3 args)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g572090(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [obj(c, 0x20, {0x378: pystub(c, 1, this=True, stackmark=(0,), side=lambda em, k: em.calllog.append(('str', em.rbytes(em.arg32(0), 17))))}) for _ in range(3)]
    state = {'n': 0}

    def fmt(em, res_):
        state['n'] += 1
        a = [em.arg32(i) for i in range(4)]
        buf = a[1]
        em.wbytes(buf, bytes((state['n'] * 17 + i) & 0xff for i in range(16)) + b'\0')
        em.calllog.append(('fmt', a[0], a[2], a[3]))
        em.ret(eax=0, argbytes=0)
    lg = obj(c, 0x20, {0x198: e.stub_fn('recorder', fmt)})
    bobj = obj(c, 0x20, {0x80: pystub(c, 1, this=True), 0x88: pystub(c, 1, this=True), 0x90: pystub(c, 1, this=True)})
    xobj = obj(c, 0x20, {0x60: pystub(c, 3, this=True)})
    rets = [r.choice(pool) for _ in range(3)]
    sysobj(c, slots={0xbc: pystub(c, 0, this=True, ret=bobj), 0x190: pystub(c, 0, this=True, ret=lg)},
           table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: rets[k % 3]), 0x134: pystub(c, 0, this=True, ret=xobj)})
    t = rnd(c, 0x1a0)
    for i in range(3):
        _w(c, t + 0x180 + 4 * i, r.choice(rets) if r.random() < 0.7 else r.choice(pool))
    return [t, r.getrandbits(32), r.getrandbits(32)]


S(0x572090, 'GUESS dispatch_entries_by_key', 'thiscall', None, ret='al', gen=_g572090, note='batch67530')
