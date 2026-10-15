"""specs_s403.py - batch 403: ZFFHERO::ControlBody, ZPlayer::CalcBonesFromMotion, ZTARGET::CallBackAndRemove,
ZTARGET::CallBackIfTime (inference), camera focus blend 0x5cebc0."""
import math
from pilot import S, F
import fu_kit as K


def _hcb(c):
    K.hooks(c, {0x5cdb70: ('ZCamHelper::ControlBody', 0)})
    self = K.rnd(c, 0x900)
    c.emu.w32(self + 0x85a, K.rnd(c, 0x10))
    return [self]


def _cbm(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    so = K.rnd(c, 0x50)
    e.w32(0x70039c, so)
    anims = [K.rnd(c, 0x80) for _ in range(2)]
    self_ = [0]
    x = r.random()
    choice = 0 if x < 0.3 else anims[0]
    w = c.fv(-1, 2)

    def pick(e, a):
        e.w32(a[0], choice)
    ctl = K.obj(c, 0x40, {0x24: K.fn(c, 'ctl.pick', 5, body=pick, sizes={0: 4}, st0=w),
                          0x30: K.fn(c, 'ctl.BlendInSpeed', 1, st0=c.fv(-1, 2)),
                          0x28: K.fn(c, 'ctl.28', 0, ret=K.bool8(c, 0.5))}, 'ctl')
    self = K.obj(c, 0x700, {0x324: K.fn(c, 'slot324', 1, ret=K.bool8(c, 0.5)),
                            0x320: K.fn(c, 'slot320', 1, ret=r.getrandbits(32)),
                            0x268: K.fn(c, 'slot268', 2), 0x244: K.fn(c, 'SetBoneFrameBlend', 5),
                            0x5f8: K.fn(c, 'slot5f8', 1), 0x3e0: K.fn(c, 'slot3e0', 0)}, 'player')
    e.w32(self + 0x455, ctl)
    e.w32(self + 0x6c, K.rnd(c, 0x260))
    e.wf32(self + 0x612, c.fv(-1, 2) if r.random() < 0.8 else w)
    e.w32(self + 0x424, r.choice([0, anims[0], anims[1]]))
    if r.random() < 0.7:
        e.w32(self + 0x417, e.r32(self + 0x417) & ~0x40000)
    args = [self] + [K.vec(c, 9, -2, 2) for _ in range(4)]
    return args


def _pmf(c, t, name, again=None):
    """Put a callback in t+0x3d: a stub function; adjustment small. again: a second callback the first one installs."""
    r = c.rng
    e = c.emu
    state = {'n': 0}

    def body(e, a):
        state['n'] += 1
        if again is not None and state['n'] == 1:
            for i, w in enumerate(again):
                e.w32(t + 0x3d + 4 * i, w)
    f = K.fn(c, name, 0, body=body)
    return [f, r.choice([0, 4, 8, 0x10]), r.getrandbits(32), r.choice([0xffffffff, r.getrandbits(32)])]


def _cbr(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    t = K.rnd(c, 0x60)
    again = None
    if r.random() < 0.3:
        again = _pmf(c, t, 'cb2')
    pm = _pmf(c, t, 'cb1', again)
    if r.random() < 0.2:
        pm[0] = 0
    for i, w in enumerate(pm):
        e.w32(t + 0x3d + 4 * i, w)
    return [t, K.rnd(c, 0x20)]


def _cbt(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    so = K.rnd(c, 0x50)
    now = r.randint(0, 1 << 22) if r.random() < 0.9 else r.getrandbits(32)
    e.w32(so + 0x40, now)
    e.w32(0x70039c, so)
    t = K.rnd(c, 0x60)
    x = r.random()
    d = 0.0 if x < 0.1 else (float(r.randint(1, 8)) / 4 if x < 0.6 else (c.fv(0, 5) if x < 0.9 else r.choice([float('nan'), float('inf'), -1.0])))
    e.wf32(t + 0x31, d)
    y = r.random()
    if y < 0.35 and math.isfinite(d) and 0 <= d < 1e4:       # exactly at the end of the fade: p hits 1 or 0
        st = (now - int(round(d * 1024))) / 1024.0
    elif y < 0.5:   # exactly at the start: elapsed 0
        st = now / 1024.0
    elif y < 0.9:
        st = (now - r.randint(0, 6000)) / 1024.0
    else:
        st = r.choice([0.0, -0.0, float('nan'), 1e30, r.uniform(0, 5000)])
    if r.random() < 0.45:
        st = -st
    e.wf32(t + 0x35, st)
    pm = _pmf(c, t, 'cb')
    if r.random() < 0.15:
        pm[0] = 0
    for i, w in enumerate(pm):
        e.w32(t + 0x3d + 4 * i, w)
    return [t, K.rnd(c, 0x20)]


def _blend(c):
    r = c.rng
    e = c.emu

    def step(off, lo, hi):
        vals = [r.uniform(lo, hi) for _ in range(3)]
        return lambda e, a: K.wfloats(e, a[0], vals)
    K.hooks(c, {0x662c50: ('smoothPoint', 1, r.getrandbits(32), step(0, -1000, 1000), {}),
                0x662f40: ('smoothAngles', 1, r.getrandbits(32), step(0, -3.2, 3.2), {})})
    cam = K.rnd(c, 0xf00)
    for off, name in ((0xd36, 'sm1'), (0xd87, 'sm2')):
        vt = c.emu.alloc(4, 4)
        e.w32(vt, K.fn(c, name + '.done', 0, ret=K.bool8(c, 0.4)))
        e.w32(cam + off, vt)
    return [cam]


S(0x58eb40, 'ZFFHERO::ControlBody', 'thiscall', None, ret=None, gen=_hcb, note='batch403')
S(0x481570, 'ZPlayer::CalcBonesFromMotion', 'thiscall', None, ret=None, gen=_cbm, note='batch403')
S(0x4658d0, 'ZTARGET::CallBackAndRemove', 'thiscall', None, ret=None, gen=_cbr, note='batch403')
S(0x465930, 'ZTARGET::CallBackIfTime (inference)', 'thiscall', None, ret=None, gen=_cbt, note='batch403')
S(0x5cebc0, 'camera focus blend', 'thiscall', None, ret=None, gen=_blend, note='batch403; createmat, mcpy as exe code')
