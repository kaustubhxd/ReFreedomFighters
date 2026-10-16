"""specs_s210026.py - Sonnet-w3a: class-table scanner, buffer double, lookup chain, byte-to-word converter; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj):
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g62b290(c):
    clear_hooks(c)
    base = rnd(c, 0x180)
    tab = bytes(c.rng.choice([0x18, 0x19, 0x18, 0x19, 0x12, 0x00, 0x20, 0x1a, 0x17, 0x11, 0x13]) for _ in range(256))
    c.emu.wbytes(base + 0x4c, tab)
    L = c.rng.choice([0, 1, 2, 3, 5, 8])
    buf = rnd(c, 0x20)
    c.emu.wbytes(buf, bytes(c.rng.randrange(0, 256) for _ in range(0x20)))
    out = rnd(c, 8)
    return [base, buf, buf + L, out]


def g4d61e0(c):
    clear_hooks(c)
    n = c.rng.choice([0, 1, 2, 3, 4])
    t = rnd(c, 0x10); c.emu.w32(t, n); c.emu.w32(t + 8, rnd(c, 0x40))
    hook_rec(c, 0x41e290, 1, ret=0 if c.rng.random() < 0.3 else rnd(c, 0x40), pop=0)
    hook_rec(c, 0x634d22, 3, ret=_r(c), pop=0)
    hook_rec(c, 0x41e2c0, 1, ret=_r(c), pop=0)
    o = obj(c, 0x40, {0x2c: pystub(c, 2, ret=_r(c), pop=0)}, nslots=0x20)
    g = obj(c, 0x40, {0x20: pystub(c, 2, ret=o, this=True)}, nslots=0x20)
    c.emu.w32(0x700390, g)
    return [t]


def g50dad0(c):
    clear_hooks(c)
    a = rnd(c, 0x10); c.emu.w32(a + 4, rnd(c, 0x20))
    o1 = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x1e0: pystub(c, 1, ret=c.rng.choice([0, 1, 0x100, _r(c)]), this=True),
                                                    0x288: pystub(c, 3, ret=_r(c), this=True)}, nslots=0xa5)
    o2 = 0 if c.rng.random() < 0.2 else rnd(c, 0x20)
    vals = [o1, o2]
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda e, k: vals[k % 2], this=True)}, nslots=0x20)
    _eng(c, mg)
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: rnd(c, 8), this=True)
    return [a]


def g62c7f0(c):
    clear_hooks(c)
    ctx = rnd(c, 0x400)
    for ch in range(8):
        c.emu.wbytes(ctx + 0x178 + ch * 2, (0 if c.rng.random() < 0.5 else c.rng.randrange(1, 0x10000)).to_bytes(2, 'little'))
        c.emu.wbytes(ctx + 0x4c + ch, bytes([c.rng.choice([3, 4, 5])]))
    c.emu.w32(ctx + 0x174, _r(c))
    c.emu.w32(ctx + 0x170, pystub(c, 2, ret=lambda e, k: c.rng.getrandbits(16), pop=0))
    src = rnd(c, 0x40); c.emu.wbytes(src, bytes(c.rng.randrange(0, 8) for _ in range(0x40)))
    P = rnd(c, 8); c.emu.w32(P, src)
    L = c.rng.choice([0, 1, 2, 4, 7])
    dst = rnd(c, 0x40); D = rnd(c, 8); c.emu.w32(D, dst)
    K = c.rng.choice([1, 2, 3, 6, 10])
    return [ctx, P, src + L, D, dst + 2 * K]


S(0x62b290, 'scan_char_classes', 'cdecl', None, ret='eax', gen=g62b290, note='batch210026')
S(0x4d61e0, 'grow_dword_buffer', 'thiscall', None, ret='eax', gen=g4d61e0, note='batch210026')
S(0x50dad0, 'lookup_two_objects_call_288', 'stdcall', None, ret='eax', gen=g50dad0, note='batch210026')
S(0x62c7f0, 'bytes_to_words_callback', 'cdecl', None, ret=None, gen=g62c7f0, note='batch210026')
