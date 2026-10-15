"""specs_s519.py - weapons batch 519: ZLNKWHANDS::UpdateAimTarget and the ZTARGET weight."""
from pilot import S
from wkit import rnd, stub, obj, b, sysobj, vec, fedge
from specs_s504 import _tgt


def _fmod_stub(c):
    # _CIfmod: x in ST1, y in ST0 -> fmod(x, y) in ST0 (fprem loop), the other popped
    code = bytes.fromhex('d9c9' 'd9f8' 'dfe0' '9e' '7af9' 'ddd9' 'c3')
    a = c.emu.alloc(0x20, 16)
    c.emu.wbytes(a, code)
    c.emu.w32(0x676358, a)


def _timing(c, t, now):
    r = c.rng
    el = r.choice((0, 1, 100, 1024, r.randint(0, 3000)))
    st = (now - el) / 1024.0
    c.emu.wf32(t + 0x35, st if r.random() < 0.6 else -st)
    c.emu.wf32(t + 0x31, r.choice((0.0, el / 1024.0, 0.25, 1.0, r.uniform(0, 3))))


def _weight(c):
    r = c.rng
    sysobj(c, {})
    so = c.emu.r32(0x70039c)
    now = r.randint(0, 1 << 20)
    c.emu.w32(so + 0x40, now)
    t = rnd(c, 0x80)
    if r.random() < 0.8:
        _timing(c, t, now)
    else:
        c.emu.wf32(t + 0x35, fedge(c))
        c.emu.wf32(t + 0x31, fedge(c))
    return [t]


def _uat(c):
    r = c.rng
    _fmod_stub(c)
    mat = vec(c, 9, -1, 1)
    go = rnd(c, 0x20)
    c.emu.w32(go + 8, mat)
    bm, bp = vec(c, 9, -1, 1), vec(c, 3, -50, 50)
    g = obj(c, 0x400, {0x20: stub(c, 0, ret=go), 0x1e0: stub(c, 1, ret=b(c, 0.5)), 0x2b4: stub(c, 1, ret=r.randint(0, 20)),
                       0x390: stub(c, 3, skip=(1, 2), ofills=((1, 0, bm, 9), (2, 0, bp, 3)), ret=b(c, 0.5)),
                       0x2ac: stub(c, 2, skip=(0, 1), ofills=((0, 0, bm, 9), (1, 0, bp, 3))),
                       0x98: stub(c, 2, skip=(0, 1), lcopy=((0, 9), (1, 3))),
                       0x84: stub(c, 1, skip=(0,), adds=((0, vec(c, 3, -20, 20), 3),))})
    sysobj(c, {0x58: stub(c, 1, ret=g if r.random() < 0.85 else 0)})
    so = c.emu.r32(0x70039c)
    now = r.randint(0, 1 << 20)
    c.emu.w32(so + 0x40, now)
    tm = obj(c, 0x40, {0x320: stub(c, 0, fldv=r.choice((0.0, 0.3, 0.9, float('nan'), fedge(c))))})
    w = obj(c, 0x40, {0x350: stub(c, 0, ret=tm)})
    hero_p = vec(c, 3, -100, 100)
    self = obj(c, 0x600, {0x8c: stub(c, 1, skip=(0,), lcopy=((0, 3),), adds=((0, vec(c, 3, -10, 10), 3),)),
                          0x84: stub(c, 1, skip=(0,), lcopy=((0, 3),), fills=((0, hero_p, 3),)),
                          0x50c: stub(c, 0, ret=w if r.random() < 0.8 else 0)})
    _tgt(c, self, 0x26a)
    t = self + 0x26a
    c.emu.w8(t, 0 if r.random() < 0.1 else 1)
    for j in range(3):
        c.emu.wf32(t + 0x25 + 4 * j, r.uniform(-100, 100))
    _timing(c, t, now)
    c.emu.w32(t + 0x3d, 0)
    c.emu.w32(t + 0x39, 0 if r.random() < 0.15 else r.getrandbits(32))
    c.emu.w32(self + 0x136, r.getrandbits(32) & ~0x400000 if r.random() < 0.8 else 0x400000)
    for o in range(0x3bc, 0x3e0, 4):
        c.emu.wf32(self + o, r.uniform(-100, 100))
    c.emu.wf32(self + 0x3e0, (now - r.choice((0, 16, 33, 500))) / 1024.0)
    c.emu.wf32(self + 0x3e4, r.choice((300.0, 10000.0, 0.0, r.uniform(100, 3000))))
    c.emu.wf32(self + 0x1e2, r.choice((0.0, 1.0, 0.15, 0.5)))
    c.emu.w8(self + 0x70, 0 if r.random() < 0.7 else 1)
    c.emu.w32(self + 0x6c, rnd(c, 0x300))
    return [self]


S(0x466b70, 'ZTARGET weight (no GC name)', 'thiscall', None, ret='st0', gen=_weight)
S(0x475ae0, 'ZLNKWHANDS::UpdateAimTarget', 'thiscall', None, ret='al', gen=_uat)
