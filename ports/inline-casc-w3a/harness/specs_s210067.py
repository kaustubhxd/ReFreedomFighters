"""specs_s210067.py - Sonnet-w3a: 0x63d2f0. Record table (this+0x68) indexed by id & 0xfff, entry table of 8-byte {ptr, key} with one key equal to sub[0x20] + b; owners at this+0xf0 each with a pointer table at +0x10071 (non-null at the id slot or not) and a hooked 0x64c7e0 returning a pending-node chain; allocation slots 0x20 / 0x24 and memcpy 0x634d22 are recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g63d2f0(c):
    clear_hooks(c)
    e = c.emu
    id_ = c.rng.choice([0, 1, 2, 3, 5, 0x1003, 0xffff, 0x7fff])
    idx4 = (id_ & 0xfff) << 2
    K = _r(c) & 0xffff
    b = c.rng.choice([0, 1, 7, _r(c) & 0xff])
    key = (K + b) & 0xffffffff
    cnt = c.rng.choice([0, 1, 2, 3, 4])
    ents = rnd(c, 0x40)
    ptrs = []
    for i in range(cnt):
        p = 0 if c.rng.random() < 0.15 else rnd(c, 0x20)
        ptrs.append(p)
        e.w32(ents + 8 * i, p)
        e.w32(ents + 8 * i + 4, c.rng.choice([_r(c), key if c.rng.random() < 0.35 else _r(c) | 1]))
    rec = rnd(c, 0x60)
    e.w32(rec + 0x40, ents)
    e.wbytes(rec + 0x3d, bytes([cnt]))
    tbl = rnd(c, 0x4000 + 8)
    e.w32(tbl + idx4, rec)
    sub = rnd(c, 0x40); e.w32(sub + 0x20, K)
    eng = rnd(c, 0x2000); _ub(c, eng + 0x1aa3, sub)
    e.w32(0x70039c, eng)
    # pending-node chain served by 0x64c7e0
    nodes = []
    for _ in range(c.rng.choice([0, 1, 2, 3])):
        nd = rnd(c, 0x30); x = rnd(c, 0x30); y = rnd(c, 0x20)
        e.w32(nd + 8, x); e.w32(x + 0x10, y)
        e.w32(y + 8, key if c.rng.random() < 0.3 else _r(c))
        e.wbytes(nd + 5, bytes([c.rng.choice([0, 1, 3])]))
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        e.w32(nd + 0x1c, nodes[i + 1] if i + 1 < len(nodes) else 0)
    tobj = rnd(c, 0x40)
    e.w32(tobj + 0x1c, nodes[0] if nodes else 0)
    hook_rec(c, 0x64c7e0, 1, ret=lambda emu, k: tobj, this=True)
    hook_rec(c, 0x64d5f0, 1, ret=_r(c), this=True)
    hook_rec(c, 0x634d22, 3, ret=_r(c), pop=0)
    newarr = rnd(c, 0x40)
    s = obj(c, 0x100, {0x20: pystub(c, 1, ret=newarr, this=True), 0x24: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x20)
    e.w32(s + 0x68, tbl)
    n2 = c.rng.choice([0, 1, 2])
    e.w32(s + 0xec, n2)
    for j in range(n2):
        o = rnd(c, 0x10090)
        blk = rnd(c, 0x4000 + 8)
        e.w32(blk + idx4, c.rng.choice([0, _r(c) | 1]))
        _ub(c, o + 0x10071, blk)
        _ub(c, o + 0x10059, _r(c))
        e.w32(s + 0xf0 + 4 * j, o)
    a = rnd(c, 0x80)
    e.wbytes(a + 0x5a, (id_).to_bytes(2, 'little'))
    return [s, a, b]


S(0x63d2f0, 'drop_key_entry', 'thiscall', None, ret=None, gen=g63d2f0, note='batch210067')
