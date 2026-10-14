"""specs_s36008.py - cascade s4 batch 36008: 0x4422e0 (child walk + flag check), 0x469130 (collect nodes), 0x482ac0 (release objects, reset slots), 0x49a3e0 (drain a container, delete)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memset


def _defblock(c, bit):
    """Block whose unaligned dword at +0x23 has 0x100000 set (bit True) or clear."""
    r = c.rng
    d = rnd(c, 0x30)
    v = r.getrandbits(32)
    v = (v | 0x100000) if bit else (v & ~0x100000)
    c.emu.wbytes(d + 0x23, (v & 0xffffffff).to_bytes(4, 'little'))
    w = rnd(c, 0x20)
    c.emu.w32(w + 0xc, d)
    return w


def _al(c):
    return c.rng.choice([0, 1, 0x100, 0x101, 0x80])


def _chain(c, n, off=0x60):
    prev = 0
    for _ in range(n):
        node = rnd(c, 0x70)
        c.emu.w32(node + off, prev)
        prev = node
    return prev


def _g4422e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4db9a0, 1, this=True, ret=_al(c))
    hook_rec(c, 0x4d9ce0, 0, this=True)
    E = obj(c, 0x20, {0x2f0: pystub(c, 1, this=True)})
    a = rnd(c, 0x70)
    e.w32(E + 8, a if r.random() < 0.3 else rnd(c, 0x10))
    if r.random() < 0.15:
        e.w32(a + 0x54, 0)
    else:
        n = obj(c, 0x70, {0x310: pystub(c, 0, this=True, ret=_al(c)), 0x30c: pystub(c, 0, this=True, ret=_al(c))})
        w = _defblock(c, r.random() < 0.85)
        e.w32(n + 0xc, e.r32(w + 0xc))
        e.w32(n + 0x50, _chain(c, r.choice([0, 1, 2, 3])))
        e.w32(a + 0x54, n)
    e.w32(a + 0x3c, r.getrandbits(32))
    return [E, a]


def _g469130(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    t = rnd(c, 0x70)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=t)})
    if r.random() < 0.7:
        o = obj(c, 0x20, {0xc: pystub(c, 3, this=True)})
        e.wbytes(so + 0x1907, o.to_bytes(4, 'little'))
    else:
        e.wbytes(so + 0x1907, bytes(4))
    hook_rec(c, 0x4e5e60, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x46d5f0, 0, this=True)
    prev = 0
    for i in range(r.choice([0, 1, 2, 4, 6])):
        node = rnd(c, 0x70)
        if r.random() < 0.1:
            e.w32(node + 0x54, 0)
        else:
            n = obj(c, 0x70, {0x1e0: pystub(c, 1, this=True, ret=_al(c))})
            w = _defblock(c, r.random() < 0.85)
            e.w32(n + 0xc, e.r32(w + 0xc))
            e.w32(node + 0x54, n)
        e.w32(node + 0x60, prev)
        prev = node
    e.w32(t + 0x50, prev)
    E = rnd(c, 0x380)
    return [E, r.getrandbits(32), r.getrandbits(32)]


def _g482ac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    slots = {0x624: pystub(c, 1, this=True), 0x644: pystub(c, 1, this=True)}
    for off in (0x63c, 0x62c, 0x630, 0x634, 0x638):
        slots[off] = pystub(c, 0, this=True, ret=r.getrandbits(32))
    E = obj(c, 0x4f0, slots)
    st = pystub(c, 1, this=True)
    n = r.choice([0, 1, 2, 3, 6])
    e.wbytes(E + 0x459, n.to_bytes(4, 'little'))
    for i in range(32):
        if i < 8 and r.random() < 0.75:
            v = obj(c, 0x10, {4: st})
        else:
            v = r.getrandbits(32) if i >= n else 0
        e.wbytes(E + 0x45d + 4 * i, v.to_bytes(4, 'little'))
    return [E]


def _g49a3e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4ce1c0, 2)
    hook_rec(c, 0x634273, 2, pop=0)
    E = rnd(c, 0x20)
    seq = []
    for _ in range(r.choice([0, 1, 2, 3])):
        node = rnd(c, 0x30)
        blk = rnd(c, 0x20) + 4
        e.w32(node + 4, 0 if r.random() < 0.2 else blk)
        r2 = rnd(c, 0x10)
        e.w32(r2 + 4, 0 if r.random() < 0.5 else r.getrandbits(32) | 1)
        e.w32(node + 0x10, r2)
        seq.append(node)
    seq.append(0)
    if r.random() < 0.85:
        a = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)), 0: pystub(c, 1, this=True),
                          0x64: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[min(k, len(seq) - 1)])})
        e.w32(E + 8, a)
    else:
        e.w32(E + 8, 0)
    e.w32(E + 4, 0 if r.random() < 0.3 else obj(c, 0x10, {0: pystub(c, 1, this=True)}))
    return [E]


S(0x4422e0, 'GUESS visit children and release node', 'thiscall', None, ret=None, gen=_g4422e0, note='batch36008')
S(0x469130, 'GUESS collect usable nodes into list', 'thiscall', None, ret=None, gen=_g469130, note='batch36008')
S(0x482ac0, 'GUESS release objects, reset slots', 'thiscall', None, ret=None, gen=_g482ac0, note='batch36008')
S(0x49a3e0, 'GUESS drain container, delete', 'thiscall', None, ret=None, gen=_g49a3e0, note='batch36008')
