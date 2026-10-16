"""specs_s210022.py - Sonnet-w3a: embedded-object slots, path normalise, record search, list append, lookup chain; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _eng(c, mgr_obj, slots=None):
    eng = obj(c, 0x100, slots or {}, nslots=0x40)
    _ub(c, eng + 0x9b, mgr_obj)
    c.emu.w32(0x70039c, eng)


def g432c50(c):
    clear_hooks(c)
    t = rnd(c, 0x100)
    vt1 = c.emu.r32(obj(c, 0x40, {0x88: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x30))
    q = 0 if c.rng.random() < 0.3 else rnd(c, 0x20)
    p = 0 if c.rng.random() < 0.25 else rnd(c, 0x10)
    if p: c.emu.w32(p + 4, q)
    vt2 = c.emu.r32(obj(c, 0x40, {0x84: pystub(c, 1, ret=p, this=True), 0x90: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x40))
    c.emu.w32(t + 0xc8, vt1); c.emu.w32(t + 0xac, vt2)
    hook_rec(c, 0x4cbec0, 0, ret=_r(c), this=True)
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    eng = obj(c, 0x100, {0x64: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x40)
    c.emu.w32(0x70039c, eng)
    return [t, _r(c)]


def g49e260(c):
    clear_hooks(c)
    L = c.rng.randrange(0, 9)
    s = bytes(c.rng.choice([0x2f, 0x2f, 0x61, 0x62]) for _ in range(L)) + b'\x00' * 24
    src = rnd(c, 0x40); c.emu.wbytes(src, s)
    return [rnd(c, 0x130), src]


def g45e420(c):
    clear_hooks(c)
    t = rnd(c, 0x200)
    big = c.rng.random() < 0.85
    flags = (0x80000000 if big else 0) | (0x40000000 if c.rng.random() < 0.5 else 0) | (c.rng.getrandbits(30) & 0x3fffffff & ~0x40000000)
    if not big and c.rng.random() < 0.6: flags = 0
    c.emu.w32(t + 4, flags)
    k = c.rng.choice([0, 1, 2, 3, 4, 0xfffffffe])
    c.emu.w32(t + 0xc, k if k != 0xfffffffe else (c.rng.choice([2, 3]) if not big else k))
    c.emu.w32(t + 0x10, c.rng.choice([0, 1, 2]))
    base = t + (c.emu.r32(t + 0x10) + 5) * 4 if (flags & 0x40000000) else t + 0x10
    pos = base; keys = [c.rng.choice([1, 2, 3, 4]) for _ in range(5)]
    for kk in keys:
        sz = c.rng.choice([8, 12, 16])
        if pos + sz > t + 0x1f0: break
        c.emu.w32(pos, kk); c.emu.w32(pos + 4, sz | (c.rng.getrandbits(2) << 30))
        pos += sz
    return [t, c.rng.choice([1, 2, 3, 4, 5])]


def g4cd540(c):
    clear_hooks(c)
    t = rnd(c, 0x40)
    newn = rnd(c, 0x80)
    mode = c.rng.choice(['empty', 'full', 'room'])
    cap = c.rng.choice([2, 3, 4])
    c.emu.w32(t + 0x10, cap); c.emu.w32(t + 0x18, c.rng.choice([0, 1, 2])); c.emu.w32(t + 0x14, c.rng.randrange(0, 5))
    if mode == 'empty':
        c.emu.w32(t + 4, 0)
    else:
        node = rnd(c, 0x80)
        c.emu.w32(node + 8, cap if mode == 'full' else c.rng.choice([0, 1]))
        c.emu.w32(t + 4, node); c.emu.w32(t + 8, node)
    vt = c.emu.r32(obj(c, 0x40, {0x80: pystub(c, 0, ret=newn, this=True)}, nslots=0x40))
    c.emu.w32(t, vt)
    return [t, _r(c)]


def g5538f0(c):
    clear_hooks(c)
    a = rnd(c, 0x10); c.emu.w32(a + 8, rnd(c, 0x20))

    def side(emu, k):
        emu.w32(emu.arg32(1), c.rng.getrandbits(32))
    g = obj(c, 0x40, {0x88: pystub(c, 2, ret=_r(c), this=True, deref={1: 1}, side=side)}, nslots=0x40)
    o = 0 if c.rng.random() < 0.25 else rnd(c, 0x860)
    if o: _ub(c, o + 0x852, 0 if c.rng.random() < 0.3 else rnd(c, 0x20))
    _eng(c, obj(c, 0x40, {0x138: pystub(c, 0, ret=g, this=True), 0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x60))
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: rnd(c, 8), this=True)
    hook_rec(c, 0x5002f0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x596cf0, 0, ret=_r(c), this=True)
    return [a]


S(0x432c50, 'release_embedded_objects', 'thiscall', None, ret='eax', gen=g432c50, note='batch210022')
S(0x49e260, 'normalise_path_slashes', 'thiscall', None, ret='eax', gen=g49e260, note='batch210022')
S(0x45e420, 'find_record_by_key', 'thiscall', None, ret='eax', gen=g45e420, note='batch210022')
S(0x4cd540, 'list_append_slot80', 'thiscall', None, ret='eax', gen=g4cd540, note='batch210022')
S(0x5538f0, 'lookup_chain_5538f0', 'stdcall', None, ret='eax', gen=g5538f0, note='batch210022')
