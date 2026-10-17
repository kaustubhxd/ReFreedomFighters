"""specs_s1616.py - soundtimers batch 1616: ZDllSound::AddNewPlayBuffer (resolver 0x537500 hooked)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook


def _apb(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x537500, 1, ret=r.getrandbits(32) if r.random() < 0.9 else 0)
    rec = rnd(c, 0x20)
    c.emu.w32(rec, r.choice([1, 2, 2, 3]))
    c.emu.wf32(rec + 0xc, r.uniform(0, 30))
    c.emu.wf32(rec + 0x10, r.choice([0.0, 1.0, r.uniform(0, 1.5)]))
    f = c.emu.alloc(4, 4)
    c.emu.wf32(f, r.uniform(0, 10))
    d = obj(c, 0x5500, {0x74: stub(c, seq, 1, fld=f), 0x54: stub(c, seq, 1, ret=rec if r.random() < 0.9 else 0),
                        0x1dc: stub(c, seq, 1, ret=rnd(c, 8) if r.random() < 0.9 else 0)})
    c.emu.w8(d + 0x50a9, r.choice([0, 1]))
    c.emu.wbytes(d + 0x515d, bytes(0x60))   # per-category flags: one set
    c.emu.w8(d + 0x515d + 9 * r.randint(0, 8), 1)
    pl = d + 0x53b2
    vt = c.emu.alloc(8, 4)
    c.emu.w32(vt + 4, stub(c, seq, 1))
    c.emu.w32(pl, vt)
    t = r.randint(0, 1 << 20)
    s = sysobj(c, extra={0x1c: t})
    c.emu.w32(d + 0x50b6, t if r.random() < 0.5 else t + 1)
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 2, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    o = rnd(c, 0x100)
    c.emu.w32(o + 4, 3 if r.random() < 0.9 else 2)
    c.emu.w32(o + 0x2c, r.randint(0, 8))
    return [d, o]


S(0x534e60, 'ZDllSound::AddNewPlayBuffer', 'thiscall', None, ret='al', gen=_apb, note='batch1616')


def _resolve(c):
    """Data: header at 0x20; waves 0x40, sound 0x80, reference 0x100 (-> 0x80 / 0x40 / set), empty set 0x140,
    sets at 0x200 (top) and 0x280 (nested), member tables at 0x400 / 0x480. The DLL's mask table +0x50c7 holds
    1 << i."""
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    d = rnd(c, 0x5500)
    for i in range(32):
        c.emu.w32(d + 0x50c7 + 4 * i, 1 << i)
    b = rnd(c, 0x800, 16)
    c.emu.w32(d + 0x5302, b if r.random() < 0.95 else 0)
    c.emu.w32(b, 0x20)
    c.emu.w32(b + 0x20, 1)
    c.emu.w32(b + 0x24, r.choice([0, 1]))
    c.emu.w32(b + 0x40, 1)
    c.emu.w32(b + 0x80, 2)
    c.emu.w32(b + 0x100, 5)
    c.emu.w32(b + 0x108, r.choice([0x40, 0x80, 0x200, 0x140]))
    c.emu.w32(b + 0x140, 3)
    c.emu.w16(b + 0x148, 0)
    for st, tab, leaf in ((0x200, 0x400, False), (0x280, 0x480, True)):
        n = r.randint(1, 12)
        c.emu.w32(b + st, 3)
        c.emu.w16(b + st + 8, n)
        c.emu.w16(b + st + 0xa, r.choice([0, 1, 2, 2, 3]))
        c.emu.w32(b + st + 0x10, tab)
        k = r.random()
        c.emu.w32(b + st + 0x14, r.randint(0, n) if k < 0.5 else (r.getrandbits(n) if k < 0.8 else (1 << n) - 1))
        for i in range(n):
            ch = [0x40, 0x80, 0x140, 0] if leaf else [0x40, 0x80, 0x280, 0x140]
            c.emu.w32(b + tab + 4 * i, r.choice(ch))
    f = c.emu.alloc(4, 4)
    c.emu.wf32(f, r.choice([0.0, 0.99999, r.random()]))
    s = obj(c, 0x100, {0x1c0: stub(c, seq, 2, fld=f)})
    c.emu.w32(0x70039c, s)
    return [d, r.choice([0, 0x40, 0x80, 0x100, 0x140, 0x200, 0x200, 0x200, 0x280, 0x180])]


S(0x537500, 'ZDllSound resolve play id (guessed name)', 'thiscall', None, ret='eax', gen=_resolve, note='batch1616')
