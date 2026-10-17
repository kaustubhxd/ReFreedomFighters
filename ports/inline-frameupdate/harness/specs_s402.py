"""specs_s402.py - batch 402: vaddscalar (4 args), ZPlayer::SetGroupPos, ZCamHelper::UpdateFocusSystem,
ZLNKOBJ::ClassFrameUpdate, ZTARGET::Remove (inference)."""
import math
import struct
from pilot import S, F
import fu_kit as K


def _vas(c):
    r = c.rng
    K.hooks(c, {})
    a = K.vec(c, 3, -1000, 1000)
    b = K.vec(c, 3, -2, 2)
    out = K.vec(c, 3)
    x = r.random()
    if x < 0.15:
        out = a        # in place on a
    elif x < 0.25:
        out = b        # in place on b
    s = c.fv(-500, 500)
    if r.random() < 0.2 and math.isfinite(s) and abs(s) < 1e20:   # lanes where the product and a nearly cancel, so float-vs-double rounding shows
        for i in range(3):
            v = r.uniform(1e6, 1e7)
            c.emu.wf32(b + 4 * i, v)
            c.emu.wf32(a + 4 * i, -K.f32(v * float(s)))
    return [out, a, b, F(s)]


def _sgp(c):
    r = c.rng
    K.hooks(c, {})
    g = K.obj(c, 0x40, {0x7c: K.fn(c, 'g.SetRootTM', 2, sizes={1: 12})}, 'g')
    self = K.obj(c, 0x500, {0x20: K.fn(c, 'slot20', 0, ret=g)}, 'player')
    c.emu.wf32(self + 0x451, c.fv(-200, 200))
    return [self, K.vec(c, 9, -1, 1), K.vec(c, 3, -1000, 1000)]


def _ufs(c):
    r = c.rng
    K.hooks(c, {0x5cebc0: ('cam5cebc0', 0), 0x5d1ea0: ('SetFocusSystemMouse', 0), 0x5d2080: ('SetFocusSystemOni', 0)})
    cam = K.rnd(c, 0xf00)
    K.setbyte(c, cam + 0xd35, 0.7)
    K.setbyte(c, cam + 0xdd8, 0.6)
    c.emu.w32(cam + 0xe1c, r.choice([0, 1, 2, 3, 4, 0xffffffff, r.getrandbits(32)]))
    return [cam]


def _lnk(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    g2 = K.obj(c, 0x40, {0x98: K.fn(c, 'g2.slot98', 2, sizes={0: 36, 1: 12})}, 'g2')
    base = K.vec(c, 12, -2, 2, pad=0)   # ZBaseGeom: matrix at +0, position at +0x24
    for i in range(3):
        e.wf32(base + 0x24 + 4 * i, r.uniform(-1000, 1000))
    g = K.obj(c, 0x40, {0x20: K.fn(c, 'g.slot20', 0, ret=g2), 0x74: K.fn(c, 'g.SetMatPos', 2, sizes={0: 36, 1: 12})}, 'g')
    e.w32(g + 8, base)
    self = K.obj(c, 0x100, {0x348: K.fn(c, 'UpdateAnimationsAndGroundLink', 0, ret=K.bool8(c, 0.3)),
                            0x20: K.fn(c, 'slot20', 0, ret=g),
                            0x1e0: K.fn(c, 'IsDerivedFrom', 1, ret=K.bool8(c, 0.5)),
                            0x7c: K.fn(c, 'SetRootTM', 2, sizes={0: 36, 1: 12})}, 'lnk')
    for i in range(9):
        e.wf32(self + 0x24 + 4 * i, r.uniform(-2, 2))
    for i in range(3):
        e.wf32(self + 0x48 + 4 * i, r.uniform(-100, 100))
    link = K.rnd(c, 0x260)
    e.w32(self + 0x6c, link)
    return [self]


def _rem(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {0x4658d0: ('CallBackAndRemove', 1), 0x465930: ('t.465930', 1)})
    so = K.rnd(c, 0x50)
    now = r.choice([r.randint(0, 1 << 22), r.getrandbits(32)])
    e.w32(so + 0x40, now)
    e.w32(0x70039c, so)
    t = K.rnd(c, 0x60)
    x = r.random()
    d = 0.0 if x < 0.1 else (c.fv(0, 5) if x < 0.9 else r.choice([float('nan'), float('inf'), -1.0]))
    e.wf32(t + 0x31, d)
    # start time: a recent time (positive or negative), so the elapsed time lands around the fade time
    el = r.uniform(-1, 6)
    st = ((now & 0xffffffff) / 1024.0 - el) if now < (1 << 22) else r.uniform(0, 4e6)
    if r.random() < 0.4:
        st = -st
    if r.random() < 0.1:
        st = r.choice([0.0, -0.0, float('nan'), 1e30])
    if r.random() < 0.1 and math.isfinite(d) and abs(d) < 1e6:   # exactly at the end of the fade
        st = (now - int(d * 1024)) / 1024.0 if now < (1 << 22) else st
    e.wf32(t + 0x35, st)
    fade = 0.0 if r.random() < 0.45 else r.choice([-0.0, c.fv(0, 3), c.fv(0, 3), float('nan')])
    obj = K.rnd(c, 0x10)
    return [t, obj, F(fade), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x443ef0, 'vaddscalar (out, a, b, s)', 'fastcall', None, ret=None, gen=_vas, note='batch402; x87')
S(0x484ff0, 'ZPlayer::SetGroupPos', 'thiscall', None, ret=None, gen=_sgp, note='batch402; vaddscalar as exe code')
S(0x5d2e60, 'ZCamHelper::UpdateFocusSystem', 'thiscall', None, ret=None, gen=_ufs, note='batch402')
S(0x461c40, 'ZLNKOBJ::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_lnk, note='batch402; math callees as exe code')
S(0x467410, 'ZTARGET::Remove (inference)', 'thiscall', None, ret=None, gen=_rem, note='batch402')
