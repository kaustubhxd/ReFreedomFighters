"""specs_s37057.py - cascade s6 batch 37057 (0x4ab9e0): fourteen table lookups by name. Table slot 0x114 (4 args) is a recording stub with a random result per call (so the order and
the names/lines of the calls are compared and the low 16 bits land in the right fields)."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, pystub


def _g4ab9e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    so = sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32), side=lambda em, k: em.calllog.append(('look', tuple(em.arg32(i) for i in range(4)))))}, table_size=0x130)
    me = rnd(c, 0x80)
    return [me]


S(0x4ab9e0, 'GUESS load ids by name', 'thiscall', None, ret=None, gen=_g4ab9e0, note='batch37057')
