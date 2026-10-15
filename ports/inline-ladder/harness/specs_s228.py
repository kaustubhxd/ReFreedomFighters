"""specs_s228.py - ladder thread batch 228: ZIKLNKOBJ::RemoveFacingTarget (ZTARGET blend-out timing)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from pe_emu import f32
import ladder_kit as K


def _rf(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    e.w8(s + 0x158, 0 if r.random() < 0.85 else r.randint(1, 255))
    e.w32(s, K.vt(c, 'self', {0x408: (0, lambda e2, a: (0, None, None))}, nslots=0x110))

    def h(e2, res):
        e2.calllog.append(('CallBackAndRemove', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)
    e.hook(0x4658d0, h)
    eng = K.engine(c)
    now = r.randint(0, 1 << 24)
    e.w32(eng + 0x40, now)
    t = s + 0x16d
    st = f32(now / 1024.0 - r.uniform(0, 3))
    k = r.random()
    if k < 0.45:
        e.wf32(t + 0x35, st)
    elif k < 0.9:
        e.wf32(t + 0x35, -st)
    else:
        e.wf32(t + 0x35, c.fv())
    e.wf32(t + 0x31, r.choice([0.0, 0.25, 0.5, 1.0, f32(r.uniform(0, 3)), c.fv()]))
    return [s, F(c.fv())] + [r.getrandbits(32) for _ in range(4)]


S(0x4675e0, 'ZIKLNKOBJ::RemoveFacingTarget', 'thiscall', None, ret=None, gen=_rf, note='batch228')
