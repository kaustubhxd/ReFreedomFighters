"""specs_s252.py - ladder thread batch 252: ZFFHERO::CanOperateObject, cases 0 and 1 (a+0x48 drawn from {0, 1}).
CalcObjectsMatPos (0x58c150) is a logging hook with random outputs (verified in batch 249). The vector and matrix values
are drawn near the test boundaries (-200, 200, 5625) so each compare is exercised."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _c0(c):
    e, r = c.emu, c.rng
    hero = K.rnd(c, 0x900)
    for off in (0x886, 0x892):
        for i in range(12):
            e.wf32(hero + off + 4 * i, c.fv(-1.0, 1.0) if off == 0x892 else f32(r.choice([0.0, 1.0, -1.0, r.uniform(-300, 300)])))
    # bias the subtraction so that y lands near -200, 200, and the x/z sum near 5625
    if r.random() < 0.5:
        for i in range(3):
            e.wf32(hero + 0x886 + 4 * i, f32(r.choice([0.0, 0.0, r.uniform(-400, 400)])))
    act = K.rnd(c, 0x200)
    step = r.choice([0, 1])
    obj = K.rnd(c, 0x200)
    e.w32(act + 0x44, obj)
    e.w32(act + 0x48, step)
    last = {}

    def h_obj80(e2, a):
        v = [f32(r.uniform(-300, 300)) for _ in range(3)]
        K.wv3(e2, a[0], v)
        w = [f32(r.uniform(-300, 300)) for _ in range(3)]
        K.wv3(e2, a[1], w)
        last['B'] = w
        e2.calllog.append(('obj80', K.nostack(a[0]), K.nostack(a[1])))
        return 0, None, None

    def h_hero80(e2, a):
        v = [f32(r.uniform(-300, 300)) for _ in range(3)]
        K.wv3(e2, a[0], v)
        if 'B' in last and r.random() < 0.3:
            c_ = [f32(last['B'][0] + 100.0), last['B'][1], last['B'][2]]
        else:
            c_ = [f32(r.uniform(-300, 300)) for _ in range(3)]
        K.wv3(e2, a[1], c_)
        e2.calllog.append(('hero80', K.nostack(a[0]), K.nostack(a[1])))
        return 0, None, None
    e.w32(obj, K.vt(c, 'obj', {0x80: (2, h_obj80)}, nslots=0x200))
    e.w32(hero, K.vt(c, 'hero', {0x80: (2, h_hero80), 0x0: (0, lambda e2, a: (0, None, None))}, nslots=0x200))
    e.w32(act + 0x106, r.getrandbits(32))
    p12 = K.rnd(c, 0x40)
    for i in range(9):
        e.wf32(p12 + 4 * i, c.fv(-1.0, 1.0))
    p10 = K.rnd(c, 0x20)
    for i in range(3):
        e.wf32(p10 + 4 * i, f32(r.choice([0.0, r.uniform(-300, 300), r.uniform(-150, 150)])))
    f14 = r.choice([0, 1, 0x80])
    if r.random() < 0.5:          # exact boundary case: identity matrix, zero offset, P10 = (75, y, 0) with y on the bounds
        for i in range(12):
            e.wf32(hero + 0x886 + 4 * i, 0.0)
        for i in range(12):
            e.wf32(hero + 0x892 + 4 * i, 1.0 if i in (0, 4, 8) else 0.0)
        k = r.random()
        if k < 0.5:   # y on a bound with a small x (so the sum test cannot decide the result)
            y = r.choice([-200.0, 200.0])
            x = 10.0
        else:         # sum exactly 5625 (x = 75, z = 0) with y inside the bounds
            y = r.choice([0.0, 199.99998, -199.99998])
            x = 75.0
        e.wf32(p10, x); e.wf32(p10 + 4, y); e.wf32(p10 + 8, 0.0)
        f14 = 1

    def h_c150(e2, res):
        mat, pos = e2.arg32(1), e2.arg32(2)
        if r.random() < 0.3:
            K.wv3(e2, pos, [r.choice([10.0, 75.0]), r.choice([-200.0, 200.0, 0.0]), 0.0])
        else:
            K.wv3(e2, pos, [f32(r.choice([0.0, r.uniform(-260, 260)])) for _ in range(3)])
        for i in range(8):
            e2.wf32(mat + 4 * i, c.fv(-1.0, 1.0))
        e2.calllog.append(('CalcObjectsMatPos', K.nostack(e2.reg('ecx')), e2.arg32(0), K.nostack(mat), K.nostack(pos)))
        e2.ret(eax=r.choice([0, 1]), argbytes=12)
    e.hook(0x58c150, h_c150)
    return [hero, act, p12, p10, f14]


S(0x58c450, 'ZFFHERO::CanOperateObject (cases 0 and 1)', 'thiscall', None, ret='al', gen=_c0, note='batch252')
