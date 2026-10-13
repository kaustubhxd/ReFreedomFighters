"""specs_f16b008.py - fresh slice 16 batch 8 (see src/f16b008.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt, reporter, fval


def _64b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x64d5f0, 1, this=True, pop=True)
    k = r.getrandbits(16)
    t = rnd(c, 8)
    c.emu.w16(t + 6, k)
    a = rnd(c, 0x14)
    c.emu.w32(a + 8, t)
    p = rnd(c, 0x14)
    c.emu.w32(p + 0x10, a)
    e = rnd(c, 0x20)
    c.emu.w32(e + 8, p)
    chain = [rnd(c, 0x20) for _ in range(r.randint(0, 4))]
    if r.random() < 0.75:
        chain.insert(r.randint(0, len(chain)), e)
    for i, x in enumerate(chain):
        c.emu.w32(x + 0x18, chain[i + 1] if i + 1 < len(chain) else 0)
    b = rnd(c, 0x14)
    c.emu.w32(b + 0x10, chain[0] if chain else 0)
    tab = c.emu.alloc(0x4000, 4)
    c.emu.w32(tab + 4 * (k & 0xfff), b)
    me = c.emu.alloc(0x10080, 4)
    c.emu.w32(me + 0x10071, tab)
    return [me, e]


def _4a3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    room = rnd(c, 0x10)
    phook(c, seq, 0x4db3b0, 0, ret=room, this=True)
    vals = bytes(r.getrandbits(8) for _ in range(0x30))

    def fill(e, a):
        e.wbytes(a[0], vals[:0x24])
        e.wbytes(a[1], vals[0x24:])
    rec = c.emu.alloc(0x30, 4)

    def grab(e, a):
        e.wbytes(rec, bytes(e.rbytes(a[0], 0x24)) + bytes(e.rbytes(a[1], 0xc)))
    phook(c, seq, 0x43ec00, 6, ret=r.getrandbits(32), this=True, pop=True, act=grab)
    f80 = codeaddr(c)
    phook(c, seq, f80, 2, this=True, pop=True, act=fill)
    vt = c.emu.alloc(0x84, 4)
    c.emu.w32(vt + 0x80, f80)
    s = rnd(c, 0x10)
    c.emu.w32(s, vt)
    c.emu.w32(s + 8, rnd(c, 0x10))
    me = obj(c, 0x60, {0x64: stub(c, seq, 1)})
    c.emu.w32(me + 0x44, s)
    c.emu.w8(me + 0x4c, r.choice([0, 1, 1, 1]))
    c.emu.w8(me + 0x4f, r.choice([0, 1]))
    return [me]


def _tree(c, n):
    """SGI-style red-black tree shape (colors ignored): header +1 root, +5 leftmost, +9 rightmost. Returns (header, nodes in order)."""
    r = c.rng
    hdr = rnd(c, 0x14, 1)
    nodes = [rnd(c, 0x14, 1) for _ in range(n)]

    def build(lo, hi, parent):
        if lo >= hi:
            return 0
        m = r.randint(lo, hi - 1)
        x = nodes[m]
        c.emu.w32(x + 1, parent)
        c.emu.w32(x + 5, build(lo, m, x))
        c.emu.w32(x + 9, build(m + 1, hi, x))
        return x
    root = build(0, n, hdr)
    c.emu.w32(hdr + 1, root)
    c.emu.w32(hdr + 5, nodes[0] if n else hdr)
    c.emu.w32(hdr + 9, nodes[-1] if n else hdr)
    return hdr, nodes


def _600(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x6006e0, 2, this=True, pop=True)
    n = r.randint(1, 9)
    hdr, nodes = _tree(c, n)
    i = r.randint(0, n - 1)
    j = r.randint(i, n)
    first = nodes[i]
    last = nodes[j] if j < n else hdr
    if r.random() < 0.1:
        first = last
    return [rnd(c, 0x10), first, last]


def _4b8(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    db = obj(c, 0x60, {0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=db)
    sg = obj(c, 0x70, {0x3c: stub(c, seq, 1), 0x40: stub(c, seq, 1), 0x60: stub(c, seq, 1)})
    return [rnd(c, 0x60), sg]


def _4d5(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    for a in (0x4d6880, 0x4ccf60, 0x4d8d50):
        phook(c, seq, a, 0, this=True)
    phook(c, seq, 0x634273, 2)
    return [rnd(c, 0xc0), r.choice([0, 1, 2, 3, r.getrandbits(32)])]


S(0x64b3c0, 'FUN_64b3c0 (unlink prim instance)', 'thiscall', None, ret=None, gen=_64b, note='f16b008')
S(0x4a3040, 'ZPlaySound::CreateSound', 'thiscall', None, ret=None, gen=_4a3, note='f16b008; AddSound3d records both buffers; cookie not reproduced')
S(0x600780, 'FUN_600780 (tree range walk)', 'thiscall', None, ret=None, gen=_600, note='f16b008')
S(0x4b8e40, 'ZAttachGeomToBone::Save', 'thiscall', None, ret='al', gen=_4b8, note='f16b008; ZSaveGame slots 0x3c/0x40/0x60 pop 4 (vtable 0x68e948)')
S(0x4d5680, 'CFastLookupFileCache_t::~CFastLookupFileCache_t', 'thiscall', None, ret='eax', gen=_4d5, note='f16b008; SEH not reproduced')
