"""specs_f16b017.py - fresh slice 16 batch 17 (see src/f16b017.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _607(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    ib = obj(c, 0x10, {0x34: stub(c, seq, 2, skip=(1,))})
    out = ib if r.random() < 0.7 else 0
    ca = codeaddr(c)
    phook(c, seq, ca, 6, ret=r.getrandbits(32), pop=True, act=lambda e, a: e.w32(a[5], out))
    dev = obj(c, 0x80, {0x60: ca})
    ln = rnd(c, 4)
    return [rnd(c, 0x30), dev, ln, r.getrandbits(32)]


def _454(c):
    seq = Seq(c)
    clear_hooks(c)
    phook(c, seq, 0x45f3c0, 1, this=True, pop=True, ret=c.rng.getrandbits(32))
    lg = obj(c, 0x80, {0x40: stub(c, seq, 1), 0x48: stub(c, seq, 1), 0x50: stub(c, seq, 1)})
    return [rnd(c, 0x60), lg]


def _481(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    m = obj(c, 0x20, {0x14: stub(c, seq, 1)}) if r.random() < 0.7 else 0
    sysobj(c, extra={0x1907: m})
    phook(c, seq, 0x480ff0, 0, this=True)
    phook(c, seq, 0x4690b0, 2)
    phook(c, seq, 0x45c510, 1)
    return [rnd(c, 0x40), r.choice([0, 1, 4, 5, 3, 7, r.getrandbits(32)])]


def _5c3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x469870, 0, this=True)
    db = obj(c, 0x200, {0x114: stub(c, seq, 4, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    return [rnd(c, 0x50) if r.random() < 0.9 else 0]


def _geomflags(c, n):
    """+0x54 = 0 or a child whose [[+0xc]+0x23] holds random flags (bit 0x100000 likely)."""
    r = c.rng
    if r.random() < 0.15:
        c.emu.w32(n + 0x54, 0)
        return
    k = rnd(c, 0x40)
    c.emu.w32(k + 0x23, r.getrandbits(32) | (0x100000 if r.random() < 0.8 else 0))
    ch = obj(c, 0x60, {0x310: stub(c, Seq(c), 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    c.emu.w32(ch + 0xc, k)
    c.emu.w32(n + 0x54, ch)


def _tg(slot_tg, slot_me):
    def g(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        tg = obj(c, 0x40, {slot_tg: stub(c, seq, 1)}) if r.random() < 0.85 else 0
        phook(c, seq, 0x4db7e0, 0, this=True, ret=tg)
        phook(c, seq, 0x4db9a0, 1, this=True, pop=True, ret=r.getrandbits(32) & ~0xff | r.choice([0, 1, 0x80]))
        me = obj(c, 0x40, {slot_me: stub(c, seq, 1)})
        geom = rnd(c, 0x70)
        _geomflags(c, geom)
        ch = c.emu.r32(geom + 0x54)
        if ch:
            nxt = 0
            for _ in range(r.randrange(0, 5)):
                n = rnd(c, 0x70)
                _geomflags(c, n)
                c.emu.w32(n + 0x60, nxt)
                nxt = n
            c.emu.w32(ch + 0x50, nxt)
        return [me, geom]
    return g


S(0x607d00, 'FUN_607d00 (index buffer holder ctor)', 'thiscall', None, ret='eax', gen=_607, note='f16b017; cookie not reproduced; D3D8 names GUESS')
S(0x454f80, 'ZMaterialDesc::Load', 'thiscall', None, ret='al', gen=_454, note='f16b017')
S(0x4811c0, 'ZPlayerTest scalar deleting dtor', 'thiscall', None, ret='eax', gen=_481, note='f16b017; SEH not reproduced')
S(0x5c3740, 'FUN_5c3740 (ctor vtable 0x6b3de4)', 'thiscall', None, ret='eax', gen=_5c3, note='f16b017; SEH not reproduced')
S(0x442380, 'ZTreeGroup::AttachTreeGroupChilds', 'thiscall', None, ret=None, gen=_tg(0x2c8, 0x2f8), note='f16b017')
S(0x442ec0, 'ZTreeGroup::DetachTreeGroupChilds', 'thiscall', None, ret=None, gen=_tg(0x2cc, 0x2fc), note='f16b017')
