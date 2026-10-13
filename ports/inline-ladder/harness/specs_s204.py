"""specs_s204.py - ladder thread batch 204: 0x5e7f20 ZFFHeroMovementGuide::WantControl (grab test)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _wc(c):
    e, r = c.emu, c.rng
    g = K.rnd(c, 0x600)
    e.w32(g + 0x550, 0 if r.random() < 0.9 else r.getrandbits(32) | 1)
    hA = K.rnd(c, 0x480)
    e.wf32(hA + 0x43d, f32(r.uniform(0, 100)))
    e.w32(g + 4, hA)
    hero = K.rnd(c, 0xa00)
    e.w32(hero + 0x9d3, 0x10 if r.random() < 0.5 else r.randint(0, 0x20))
    e.w8(hero + 0x66c, r.choice([0, 1, 1]))
    e.w32(g + 0x36d, hero)

    def sua(e2, res):
        a = (e2.arg32(0), e2.arg32(1), K.nostack(e2.arg32(2)))
        e2.calllog.append(('SetUseAction', e2.reg('ecx'), a))
        if r.random() < 0.6:
            e2.w32(hero + 0x9d3, 0x10)
        e2.ret(argbytes=12)
    e.hook(0x5950c0, sua)
    pos = c.fbuf(3, lambda cc: cc.fv(-300.0, 300.0))
    dirv = c.fbuf(3, lambda cc: cc.fv(-1.0, 1.0))
    eng = K.engine(c)
    res = {}
    K.resource_manager(c, eng, res)
    q = [e.rf32(pos), e.rf32(pos + 4) - e.rf32(hA + 0x43d) + 110.0, e.rf32(pos + 8)]
    nitems = r.choice([0, 1, 1, 2, 2, 3])
    shapes = [K.make_shape(c, res, 0x40 + k, q, spread=r.choice([20.0, 60.0, 120.0])) for k in range(nitems)]
    sm = K.rnd(c, 0x20)
    e.w32(eng + 0x9b, sm)
    e.w32(sm, K.vt(c, 'shapemgr', {0x58: (1, lambda e2, a: (shapes[a[0] - 0x100] if 0x100 <= a[0] < 0x100 + nitems else 0, None, None))}))
    state = {'i': 0}

    def begin(e2, a):
        state['i'] = 0
        e2.w32(a[0], 0xdead)
        return 0, None, None

    def nxt(e2, a):
        i = state['i']
        state['i'] = i + 1
        e2.w32(a[0], 1 if i < nitems else 0)
        return (0x100 + i if i < nitems else 0), None, None
    itr = K.rnd(c, 0x20)
    e.w32(itr, K.vt(c, 'ladderlist', {0x4c: (1, begin), 0x5c: (1, nxt)}))
    lst = K.rnd(c, 0x40)
    e.w32(lst + 0x18, itr if r.random() < 0.95 else 0)
    e.w32(g + 0x54c, lst if r.random() < 0.95 else 0)
    unused = K.rnd(c, 0x10)
    return [g, dirv, pos, unused]


S(0x5e7f20, 'ZFFHeroMovementGuide::WantControl', 'thiscall', None, ret='al', gen=_wc,
  note='batch204; ladder grab test: shapes, ends within 50, facing test, SetUseAction(0x10)')
