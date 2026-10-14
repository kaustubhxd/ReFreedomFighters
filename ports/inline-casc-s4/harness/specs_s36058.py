"""specs_s36058.py - cascade s4 batch 36058: 0x4f3290 (switch the current target and notify)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4f3290(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4f2240, 2)
    hook_rec(c, 0x4f9680, 1, this=True)

    def find(em, rr):
        em.calllog.append(('tab.slot4c', em.arg32(0)))
        em.ret(0x9000 + (em.arg32(0) & 0xfff), 4)
    sysobj(c, table_slots={0x4c: e.stub_fn('find', find)})
    s = obj(c, 0x80, {0x2dc: pystub(c, 4, this=True)})
    old = r.getrandbits(32)
    e.w32(s + 0x64, old)
    e.wbytes(s + 0x6a, bytes([r.choice([0, 1, 1, 0x80])]))
    e.wbytes(s + 0x68, bytes([r.getrandbits(8)]))
    a = old if r.random() < 0.2 else r.getrandbits(32)
    return [s, a]


S(0x4f3290, 'GUESS switch the current target and notify', 'thiscall', None, ret=None, gen=_g4f3290, note='batch36058')
