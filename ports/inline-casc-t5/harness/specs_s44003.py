"""specs_s44003.py - t5 (Sonnet) batch 44003: 0x55bad0."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def _assert_hook(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g55bad0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    p = rnd(c, 0x10)
    q = rnd(c, 0x10)
    e.wbytes(q + 4, bytes([r.choice([0, 2, 1, 3, 0xff, 0x80])]))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: p if k == 0 else q)
    tgt = rnd(c, 0x80)
    e.w32(tgt + 0x70, r.choice([0x3f800000, NAN, 0, 0x80000000, r.getrandbits(32)]))
    t = r.choice([tgt, tgt, 0])
    so = sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=t)})
    inner = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, side=_log('log2'))})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    me = rnd(c, 0x30)
    e.w32(me + 0x1c, obj(c, 0x20, {0x6e8: pystub(c, 3, this=True, ret=r.getrandbits(32))}, nslots=0x6ec // 4))
    a = rnd(c, 0x10)
    e.w32(a + 4, rnd(c, 0x10))
    e.w32(a + 8, rnd(c, 0x10))
    return [me, a]


S(0x55bad0, 'GUESS copy value into slot and mark done', 'thiscall', None, ret='eax', gen=g55bad0, nan_heap=True, note='batch44003')
