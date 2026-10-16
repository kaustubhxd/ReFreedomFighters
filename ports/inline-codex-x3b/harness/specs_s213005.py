"""specs_s213005.py - batch 213005: engine-object lookup by selector, and a class-table scanner, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g592350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def outw(emu, k):
        emu.w32(emu.arg32(1), r.getrandbits(32))
    o2 = obj(c, 0x40, {0x88: pystub(c, 2, ret=r.getrandbits(32), this=True, nullflag=(1,), side=outw)}, nslots=0x40)
    t = obj(c, 0x40, {0x138: pystub(c, 0, ret=o2, this=True)}, nslots=0x4e)
    eng = rnd(c, 0x1b00)
    e.w32(0x70039c, eng)
    e.w32(eng + 0x9b, t)
    sel = r.randint(1, 8) if r.random() < 0.9 else r.getrandbits(32)
    return [sel]


def g622bb0(c):
    clear_hooks(c)
    r = c.rng
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1d, 8, 0x14, 7, 8]
    tab = bytearray((r.choice(hot) if r.random() < 0.7 else r.getrandbits(8)) for _ in range(256))
    tab[0xaa] = 0x30
    c.emu.wbytes(base + 0x4c, bytes(tab))
    n = 0x200
    buf = bytearray(r.getrandbits(8) for _ in range(n))
    for i in range(0, n - 8):
        x = r.random()
        if x < 0.25:
            buf[i] = 0
        elif x < 0.5:
            buf[i] = r.randint(0xd8, 0xff)
        elif x < 0.6:
            buf[i] = 0xff
            buf[i + 1] = r.choice([0xfc, 0xfd, 0xfe, 0xff])
    for i in range(n - 8, n, 2):
        buf[i] = 0
        buf[i + 1] = 0xaa
    p = rnd(c, n + 8)
    c.emu.wbytes(p, bytes(buf))
    return [base, p]


S(0x592350, 'engine_lookup_by_sel', 'stdcall', None, ret='eax', gen=g592350)
S(0x622bb0, 'scan_class_run_b', 'cdecl', None, ret='eax', gen=g622bb0)
