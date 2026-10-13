"""specs_s13010.py - fresh-13 batch 10: 0x655110 (thiscall, 3 args forwarded to vtbl+0x230, a logged stub popping 0xc;
system object *(0x70039c) random with ticks +0x40 and +0xa11 chosen so the 256-tick test lands on both sides, including
huge / NaN floats for the truncation) and 0x656b50 (stdcall dst, src; src floats random, with +0x24 == +0x28 in 20%
of cases, +0x18 on both sides of +0x1c - 1, NaN sometimes). Heap words are floats (nan_heap)."""
from pilot import S
from fr13 import Log, logstub, vobj, rnd, clear_hooks, flush


def _g1(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=4)
    me = vobj(c, 0x40, {0x230: logstub(c, log, 3, 1)})
    sysobj = rnd(c, 0x1410)
    t = r.getrandbits(32) if r.random() < 0.3 else r.randint(0, 1 << 20)
    c.emu.w32(sysobj + 0x40, t)
    k = r.random()
    if k < 0.6:
        kk = r.choice([255, 256, 257, r.randint(-300, 600)])
        f = ((t if t < 0x80000000 else t - (1 << 32)) - kk + r.choice([0.0, 0.0, 0.3, 0.7, -0.6])) / 1024.0
    elif k < 0.8:
        f = r.choice([float('nan'), 3e9, -3e9, 0.0, 1e30])
    else:
        f = r.uniform(-1e6, 1e6)
    c.emu.wf32(sysobj + 0xa11, f)
    c.emu.w32(0x70039c, sysobj)
    flush(c)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g2(c):
    r = c.rng
    clear_hooks(c)
    src = rnd(c, 0x40)
    dst = rnd(c, 0x40)
    e = r.uniform(-10, 100)
    c.emu.wf32(src + 0x1c, e)
    c.emu.wf32(src + 0x18, e - 1 + r.choice([-2.0, -0.5, 0.0, 0.5, 3.0]) if r.random() < 0.8 else float('nan'))
    a = r.uniform(-3.2, 3.2)
    c.emu.wf32(src + 0x24, a)
    c.emu.wf32(src + 0x28, a if r.random() < 0.2 else r.choice([r.uniform(-3.2, 3.2), -a, float('nan')]))
    return [dst, src]


S(0x655110, 'GUESS FUN_655110 (vtbl+0x230 then system flag bits)', 'thiscall', None, ret=None, gen=_g1, nan_heap=True,
  note='fresh13 batch13010; vtbl+0x230 logged')
S(0x656b50, 'GUESS FUN_656b50 (cone/range record copy)', 'stdcall', None, ret=None, gen=_g2, nan_heap=True,
  note='fresh13 batch13010; CRT cos default stub')
