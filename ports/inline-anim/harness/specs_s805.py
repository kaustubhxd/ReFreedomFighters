"""specs_s805.py - animation layer thread, batch 805: ZTARGET."""
from pilot import S, F
from anim_common import only_hooks, rnd


def _tgt(c):
    e, r = c.emu, c.rng
    t = rnd(c, 0x60)
    e.wf32(t + 0x31, r.choice([0.0, c.fv(0, 2), r.uniform(0.01, 1)]))
    e.wf32(t + 0x35, r.choice([0.0, c.fv(-100, 100), r.uniform(-3000, 3000), -r.uniform(0, 3000)]))
    return t


def _clock(c, t=None):
    e, r = c.emu, c.rng
    g = rnd(c, 0x60)
    clk = r.choice([r.randint(0, 1 << 22), r.getrandbits(32)])
    if t is not None and r.random() < 0.6:
        s = e.rf32(t + 0x35)
        if s == s and abs(s) < 1e6:
            clk = int(abs(s) * 1024) + r.randint(0, 3000)
    e.w32(g + 0x40, clk)
    e.w32(0x70039c, g)


def _clear(c):
    only_hooks(c, {})
    return [_tgt(c)]


def _enable(c):
    only_hooks(c, {})
    return [_tgt(c), c.rng.getrandbits(32)]


def _smpg(c):
    only_hooks(c, {})
    r = c.rng
    m = 0 if r.random() < 0.3 else c.fbuf(9)
    p = 0 if r.random() < 0.3 else c.fbuf(3)
    return [_tgt(c), m, p, r.getrandbits(32)]


def _setcb(c):
    only_hooks(c, {})
    r = c.rng
    return [_tgt(c)] + [r.getrandbits(32) for _ in range(4)]


def _cbr(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    t = _tgt(c)
    chain = [r.randint(0, 3)]

    def cb(e, res):
        e.calllog.append(('callback', e.reg('ecx'), e.rbytes(t + 0x3d, 16)))
        if chain[0] > 0:
            chain[0] -= 1
            e.w32(t + 0x3d, fn)
            e.w32(t + 0x41, r2.getrandbits(8))
            e.w32(t + 0x49, r2.getrandbits(32))
        e.ret(eax=0)
    r2 = __import__('random').Random(r.getrandbits(32))
    fn = e.stub_fn('callback', cb)
    e.w32(t + 0x3d, 0 if r.random() < 0.2 else fn)
    e.w32(t + 0x41, r.getrandbits(8))
    return [t, rnd(c, 0x40)]


def _settime(c):
    only_hooks(c, {})
    r = c.rng
    t = _tgt(c)
    _clock(c, t)
    return [t, F(r.choice([0.0, c.fv(0, 2), r.uniform(0.05, 1.5)])), r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x466220, 'ZTARGET::Clear', 'thiscall', None, gen=_clear, note='batch805')
S(0x466600, 'ZTARGET::Enable', 'thiscall', None, ret='al', gen=_enable, note='batch805')
S(0x467aa0, 'ZTARGET::SetMatPosGeom', 'thiscall', None, gen=_smpg, note='batch805')
S(0x4678e0, 'ZTARGET::SetCallBack', 'thiscall', None, gen=_setcb, note='batch805')
S(0x4658d0, 'ZTARGET::CallBackAndRemove', 'thiscall', None, gen=_cbr, note='batch805')
S(0x467b00, 'ZTARGET::SetTime', 'thiscall', None, gen=_settime, note='batch805')
