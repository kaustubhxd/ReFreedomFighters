"""specs_s404.py - batch 404: EaseInEaseOut and the Pos/Vang smoothers (camera focus blend)."""
import math
from pilot import S, F
import fu_kit as K


def _sys(c):
    r = c.rng
    so = K.rnd(c, 0x50)
    now = r.randint(0, 1 << 20) if r.random() < 0.9 else r.getrandbits(32)
    c.emu.w32(so + 0x40, now)
    c.emu.w32(0x70039c, so)
    return now


def _easer(c, at, now):
    """Fill an EaseInEaseOut at `at` with a mostly sane state around `now`."""
    r = c.rng
    e = c.emu
    for off in (0, 4, 8):
        e.wf32(at + off, c.fv(-50, 50))
    K.setbyte(c, at + 0xc, 0.7)
    dur = r.choice([r.randint(1, 4096), r.randint(1, 4096), 1024, 0, -r.randint(1, 100), r.getrandbits(32)])
    x = r.random()
    if x < 0.6:
        st = now - r.randint(-200, (dur & 0xffff) + 200)
    elif x < 0.7:
        st = now - dur // 2          # exactly half way (x == 0.5)
    elif x < 0.8:
        st = now - dur               # exactly at the end
    else:
        st = r.getrandbits(32)
    if dur == 0:
        st = now - r.randint(0, 50)  # duration 0 only when already over: the exe divides by it otherwise (crash)
    e.w32(at + 0xd, st & 0xffffffff)
    e.w32(at + 0x11, dur & 0xffffffff)
    e.w32(at + 0x15, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 12, r.getrandbits(32)]))
    e.wf32(at + 0x19, r.choice([0.0, c.fv(0, 5), c.fv(0, 100), 1e-3]))


def _pp(c):
    r = c.rng
    K.hooks(c, {})
    K.install_pow(c.emu)
    e = K.rnd(c, 0x40)
    c.emu.w32(e + 0x15, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 0xffffffff, r.getrandbits(32)]))
    t = c.fv(0, 1, 0.1) if r.random() < 0.8 else c.fv(-2, 2)
    return [e, F(t)]


def _val(c):
    K.hooks(c, {})
    K.install_pow(c.emu)
    now = _sys(c)
    e = K.rnd(c, 0x40)
    _easer(c, e, now)
    r = c.rng
    if r.random() < 0.3:   # power 2 in the ease-out half: 1 - 2t^2 is rounded once on the x87, not twice
        dur = r.randint(1000, 1 << 20)
        c.emu.w32(e + 0x11, dur)
        c.emu.w32(e + 0x15, 2)
        c.emu.w32(e + 0xd, (now - r.randint(dur // 2 + 1, dur - 1)) & 0xffffffff)
    return [e]


def _frm(c):
    r = c.rng
    K.hooks(c, {})
    K.install_pow(c.emu)
    now = _sys(c)
    e = K.rnd(c, 0x40)
    _easer(c, e, now)
    v = K.vec(c, 1, -50, 50)
    if r.random() < 0.4:
        c.emu.w32(v, c.emu.r32(e))   # v == cur
    elif r.random() < 0.3:
        c.emu.wf32(v, c.emu.rf32(e) + r.uniform(-0.01, 0.01))
    if r.random() < 0.03:
        c.emu.w32(0x70039c, e + 0xd - 0x40)   # the tick field is the clock itself (self-assignment check)
    return [e, v]


def _scv(c, dst=False):
    r = c.rng
    K.hooks(c, {})
    now = _sys(c)
    e = K.rnd(c, 0x40)
    _easer(c, e, now)
    base = c.emu.rf32(e + (4 if dst else 0))
    thr = c.emu.rf32(e + 0x19)
    x = r.random()
    if x < 0.3 and math.isfinite(base) and math.isfinite(thr):
        v = K.f32(base + r.choice([thr, -thr]))     # exactly on the threshold
    elif x < 0.6 and math.isfinite(base):
        v = K.f32(base + r.uniform(-5, 5))
    else:
        v = c.fv(-50, 50)
    return [e, F(v)]


def _smoother(c, now, kind):
    r = c.rng
    e = c.emu
    p = K.rnd(c, 0x60)
    for off in (4, 0x10, 0x1c, 0x28):
        for i in range(3):
            e.wf32(p + off + 4 * i, r.uniform(-1, 1) if kind == 'vang' else r.uniform(-500, 500))
    _easer(c, p + 0x34, now)
    if r.random() < 0.15:      # target equals current: zero direction
        for i in range(3):
            e.w32(p + 0x10 + 4 * i, e.r32(p + 4 + 4 * i))
    return p


def _rp(c):
    K.hooks(c, {})
    now = _sys(c)
    return [_smoother(c, now, 'pos')]


def _pfu(c):
    r = c.rng
    K.hooks(c, {})
    K.install_pow(c.emu)
    now = _sys(c)
    p = _smoother(c, now, 'pos')
    v = K.vec(c, 3, -500, 500)
    if r.random() < 0.4:   # within 0.1 (squared) of the current position: no restart
        for i in range(3):
            c.emu.wf32(v + 4 * i, c.emu.rf32(p + 4 + 4 * i) + r.uniform(-0.3, 0.3))
    return [p, v]


def _vsd(c):
    r = c.rng
    K.hooks(c, {})
    now = _sys(c)
    p = _smoother(c, now, 'vang')
    v = K.vec(c, 3, -1, 1)
    if r.random() < 0.4:
        for i in range(3):
            c.emu.wf32(v + 4 * i, c.emu.rf32(p + 4 + 4 * i) + r.uniform(-0.2, 0.2))
    return [p, v]


def _vfu(c):
    K.install_pow(c.emu)
    return _vsd(c)


S(0x662940, 'EaseInEaseOut::PolyPow (inference)', 'thiscall', None, ret='st0', gen=_pp, note='batch404; pow stub')
S(0x662870, 'EaseInEaseOut value (inference)', 'thiscall', None, ret='st0', gen=_val, note='batch404; __alldiv, PolyPow as exe code')
S(0x6627c0, 'EaseInEaseOut::FrmUpd', 'thiscall', None, ret='al', gen=_frm, note='batch404')
S(0x662ab0, 'EaseInEaseOut::SetCurVal (inference)', 'thiscall', None, ret='al', gen=_scv, note='batch404')
S(0x662b00, 'EaseInEaseOut::SetDstVal', 'thiscall', None, ret=None, gen=lambda c: _scv(c, True), note='batch404')
S(0x662cf0, 'PosEaseInEaseOut::RestartPull (inference)', 'thiscall', None, ret=None, gen=_rp, note='batch404; x87 sqrt')
S(0x662c50, 'PosEaseInEaseOut::FrmUpd (inference)', 'thiscall', None, ret='al', gen=_pfu, note='batch404')
S(0x662fd0, 'VangEaseInEaseOut::SetDstDir (inference)', 'thiscall', None, ret=None, gen=_vsd, note='batch404; vangle as exe code')
S(0x662f40, 'VangEaseInEaseOut::FrmUpd (inference)', 'thiscall', None, ret='al', gen=_vfu, note='batch404; vangpul as exe code')
