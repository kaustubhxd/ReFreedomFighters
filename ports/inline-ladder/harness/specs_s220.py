"""specs_s220.py - ladder thread batch 220: ZFFActionSwingBat::CallBack (bat hit test over TrackLinkObjects)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _sb(c):
    e, r = c.emu, c.rng
    hero = K.rnd(c, 0x100)
    hp = [f32(r.uniform(-500, 500)) for _ in range(3)]
    m = [c.fv(-1.0, 1.0) for _ in range(9)]

    def matpos(e2, a):
        for i in range(9):
            e2.wf32(a[0] + 4 * i, m[i])
        K.wv3(e2, a[1], hp)
        return 0, None, None
    e.w32(hero, K.vt(c, 'hero', {0x80: (2, matpos), 0x1e0: (1, lambda e2, a: (1, None, None))}, nslots=0x100))
    n = r.choice([0, 1, 2, 3, 4, 5])
    objs = []
    for k in range(n):
        o = K.rnd(c, 0x40)
        off = [f32(h + r.uniform(-250, 250)) for h in hp]
        cls = r.getrandbits(32) & (0xffffff00 if r.random() < 0.25 else 0xffffffff)

        def w(e2, a, off=off):
            before = K.bits3(e2, a[0])
            K.wv3(e2, a[0], [f32(x + y) for x, y in zip(K.rv3(e2, a[0]), off)])
            return 0, None, before

        def cmd(e2, a, o=o):
            d = a[1]
            fields = tuple(e2.r32(d + 4 * i) for i in (0, 1, 4, 5, 6, 7, 8, 9, 10))
            return 0, None, fields
        e.w32(o, K.vt(c, 'obj%d' % k, {0x1e0: (1, lambda e2, a, cls=cls: (cls, None, None)), 0x84: (1, w),
                                         0x128: (3, cmd)}, nslots=0x100))
        objs.append(o)
    if n and r.random() < 0.2:
        objs[r.randrange(n)] = hero
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    msgid = r.getrandbits(32)
    e.w32(d, K.vt(c, 'database', {0x58: (1, lambda e2, a: (objs[a[0] - 0x100], None, None)),
                                  0x4c: (1, lambda e2, a: ((a[0] * 3 + 5) & 0xffffffff, None, None)),
                                  0x114: (4, lambda e2, a: (msgid, None, None))}, nslots=0x50))
    state = {'i': 0}

    def begin(e2, a):
        state['i'] = 0
        return 0, None, None

    def nxt(e2, a):
        i = state['i']
        state['i'] = i + 1
        e2.w32(a[0], 1 if i < n else 0)
        return (0x100 + i if i < n else 0), None, None
    itr = K.rnd(c, 0x10)
    e.w32(itr, K.vt(c, 'iter', {0x4c: (1, begin), 0x5c: (1, nxt)}))
    lst = K.rnd(c, 0x40)
    e.w32(lst + 0x18, itr)
    holder = K.rnd(c, 0x10)
    e.w32(holder, K.vt(c, 'lists', {0x25c: (2, lambda e2, a: (lst, None, None))}, nslots=0xb0))
    e.w32(d + 0xadc, holder)
    s = K.rnd(c, 0x20)
    e.w32(s + 8, hero)
    return [s]


S(0x5dfaa0, 'ZFFActionSwingBat::CallBack', 'thiscall', None, ret='al', gen=_sb, note='batch220')
S(0x5dfea0, 'ZFFActionUseKnife::CallBack', 'thiscall', None, ret='al', gen=_sb, note='batch221')
