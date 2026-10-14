"""ops_kit.py - reusable fake objects for OperateObject-style code (batch 246+ of the ladder thread).

Everything here is fake heap memory with fake vtables. Every stub logs (name, slot, this, args) into emu.calllog, so the
original and the port are compared on what they asked for. Pattern follows ladder_kit.py.

    hero(c)    the ZFFHERO-like object `self`, with 4 writable bytes before it (the code reads self[-4]).
    g2(c)      the global object at 0x70038c (slot 0x20 bool, slot 0xac, slot 0xcc, fn pointer at +8, bounds +0xc / +0x10).
    action(c)  a CAction-like object: slot 0x94, +0x44 object, +0x48 step, +0x106 dword.
    item(c, flag, x=None)  an item/hand object: slot 0x1e0 (class test, returns flag), slot 0x20 (returns x).
"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ladder_kit as K
from pe_emu import f32

G2_ADDR = 0x70038c


def _log(e, name, slot, args):
    e.calllog.append((name, slot, e.reg('ecx'), tuple(K.nostack(x) for x in args)))


def hero(c, rng=None):
    e, r = c.emu, rng or c.rng
    base = K.rnd(c, 0x900)
    self_ = base + 8                      # self[-4] is inside the allocation
    e.w32(self_ - 4, r.choice([0, 0, 0x1234, r.getrandbits(32)]))
    e.w16(self_ + 0x7c8, r.getrandbits(16))
    e.w16(self_ + 0x7ca, r.getrandbits(16))

    def mk(name, n, ret=0):
        def h(e2, res):
            args = [e2.arg32(i) for i in range(n)]
            _log(e2, name, name, args)
            e2.ret(eax=ret, argbytes=4 * n)
        return h
    e.w32(self_, K.vt(c, 'hero', {0x4e4: (1, lambda e2, a: (_log(e2, 'hero', 0x4e4, a) or 0, None, None)),
                                  0x4e8: (1, lambda e2, a: (_log(e2, 'hero', 0x4e8, a) or 0, None, None)),
                                  0x130: (3, lambda e2, a: (_log(e2, 'hero', 0x130, a) or 0, None, None))},
                      nslots=0x200))
    return self_


def g2(c, self_=None, rng=None):
    e, r = c.emu, rng or c.rng
    g = K.rnd(c, 0x40)
    e.w32(G2_ADDR, g)
    flag20 = r.choice([0, 0, 1])
    e.w32(g, K.vt(c, 'G2', {0x20: (1, lambda e2, a: (_log(e2, 'G2', 0x20, a) or flag20, None, None)),
                            0xac: (1, lambda e2, a: (_log(e2, 'G2', 0xac, a) or 0, None, None)),
                            0xcc: (1, lambda e2, a: (_log(e2, 'G2', 0xcc, a) or 0, None, None))},
                  nslots=0x100))
    fnval = r.getrandbits(32)

    def fnh(e2, res):
        e2.calllog.append(('G2fn', e2.reg('ecx')))
        e2.ret(eax=fnval)
    fn = e.stub_fn('G2fn', fnh)
    e.w32(g + 8, fn if r.random() < 0.8 else 0)
    lo, hi = (r.getrandbits(32), r.getrandbits(32))
    if r.random() < 0.6 and self_ is not None:    # the usual case: the hero lies inside the bounds
        lo, hi = (self_ - r.randint(0, 64), self_ + r.randint(1, 64))
        k = r.random()
        if k < 0.15:
            hi = self_                    # exact upper bound (exclusive)
        elif k < 0.3:
            lo = self_                    # exact lower bound (inclusive)
    e.w32(g + 0xc, lo & 0xffffffff)
    e.w32(g + 0x10, hi & 0xffffffff)
    return g


def item(c, flag, x=None, rng=None):
    e = c.emu
    o = K.rnd(c, 0x80)
    e.w32(o, K.vt(c, 'item', {0x1e0: (1, lambda e2, a, f=flag: (_log(e2, 'item', 0x1e0, a) or f, None, None)),
                              0x20: (0, lambda e2, a: (_log(e2, 'item', 0x20, a) or (x or 0), None, None))},
                  nslots=0x100))
    return o


def action(c, obj, step, rng=None):
    e, r = c.emu, rng or c.rng
    a = K.rnd(c, 0x200)
    e.w32(a, K.vt(c, 'action', {0x94: (1, lambda e2, a_: (_log(e2, 'action', 0x94, a_) or 0, None, None))}, nslots=0x100))
    e.w32(a + 0x44, obj)
    e.w32(a + 0x48, step)
    e.w32(a + 0x106, r.getrandbits(32))
    return a
