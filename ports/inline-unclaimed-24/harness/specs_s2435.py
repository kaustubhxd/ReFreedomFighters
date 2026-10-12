"""specs_s2435.py - decomp area 24, batch 2435 (slice 11 leaves; the residue-03 list is exhausted).
0x5ab0f0 ZOnScreenDisplay::StatsIncShotsFiredHero(), thiscall, plain ret: the dword at +0x8bf is incremented unless the dword
at +0x300 equals 0x10000000.
0x445170 ZROOM::SetEnvironment(ZBaseGeom*), thiscall, ret 4: the argument is stored at +0xb0.
0x65f5f0 ZDrawBuffer::PixelAspectXY() const, thiscall, plain ret, float on st0: tail jump through slot 0xe8 of the object at
+0x10 (recorder returning a float on st0).
0x5650f0 CFileWindow::Save(ZSaveGame*), thiscall, ret 4: tail jump to CBaseWindow::Save (0x563490, recorder).
0x5c30b0 CLightToggle::CopyEventDataBlock(DBREAD&), thiscall, ret 4: tail jump to CLightToggle::ReadInput (0x5c34a0, recorder)."""
from pilot import S, F
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _stats(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x900)
    e.w32(o + 0x300, 0x10000000 if r.random() < 0.4 else r.getrandbits(32))
    return [o]


def _env(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x100)
    return [o, rnd(c, 0x40)]


def _aspect(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    tgt = obj(c, 0x100, {0xe8: pystub(c, 0, st0=F(r.uniform(-5.0, 5.0)))})
    e.w32(o + 0x10, tgt)
    return [o]


def _forward(addr):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, addr, 1, this=True)
        return [rnd(c, 0x80), rnd(c, 0x40)]
    return gen


S(0x5ab0f0, 'ZOnScreenDisplay::StatsIncShotsFiredHero', 'thiscall', None, ret=None, gen=_stats, note='batch2435')
S(0x445170, 'ZROOM::SetEnvironment', 'thiscall', None, ret=None, gen=_env, note='batch2435')
S(0x65f5f0, 'ZDrawBuffer::PixelAspectXY', 'thiscall', None, ret='st0', gen=_aspect, note='batch2435')
S(0x5650f0, 'CFileWindow::Save', 'thiscall', None, ret='eax', gen=_forward(0x563490), note='batch2435')
S(0x5c30b0, 'CLightToggle::CopyEventDataBlock', 'thiscall', None, ret='eax', gen=_forward(0x5c34a0), note='batch2435')
