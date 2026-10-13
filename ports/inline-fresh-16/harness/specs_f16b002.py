"""specs_f16b002.py - fresh slice 16 batch 2 (see src/f16b002.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, crt


def _none(c):
    clear_hooks(c)
    return []


def _659(c):
    seq = Seq(c)
    clear_hooks(c)
    crt(c)
    e = rnd(c, 0x80)
    phook(c, seq, 0x63ce50, 2, this=True, pop=True)
    phook(c, seq, 0x658db0, 0, ret=e, this=True)
    return [rnd(c, 0x40), rnd(c, 0x40), c.rng.getrandbits(32)]


def _635(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    db = obj(c, 0x80, {0x58: stub(c, seq, 1)})
    sysobj(c, db=db)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x30, r.choice([0, 0, 1, r.getrandbits(32)]))
    c.emu.w32(me + 0x1c, r.choice([0, r.getrandbits(32), r.getrandbits(32)]))
    return [me, r.getrandbits(32)]


def _tree(c, depth):
    r = c.rng
    if depth > 3 or r.random() < 0.3:
        return 0
    head = 0
    nodes = [rnd(c, 0x10, 1) for _ in range(r.randint(1, 3))]
    for i, n in enumerate(nodes):
        c.emu.w32(n + 5, nodes[i + 1] if i + 1 < len(nodes) else 0)
        c.emu.w32(n + 9, _tree(c, depth + 1))
    return nodes[0]


def _5fe(c):
    seq = Seq(c)
    clear_hooks(c)
    phook(c, seq, 0x54f870, 2, this=True, pop=True)
    return [rnd(c, 0x20), _tree(c, 0)]


def _61b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    phook(c, seq, 0x61c3d0, 1)
    phook(c, seq, 0x634273, 2)
    me = rnd(c, 0x10)
    c.emu.w32(me + 4, r.choice([0, r.getrandbits(32)]))
    return [me, r.choice([0, 1, 2, 3, r.getrandbits(32)])]


def _63b(c):
    seq = Seq(c)
    clear_hooks(c)
    phook(c, seq, 0x65e210, 7, this=True, pop=True)
    return [rnd(c, 0x8300)] + [c.rng.getrandbits(32) for _ in range(7)]


def _5f3(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = codeaddr(c)
    phook(c, seq, h, 0)
    c.emu.w32(0x7003b0, h)
    buf = rnd(c, 0x10)
    c.emu.w32(buf + 8, r.choice([r.randint(0, 0x100), r.getrandbits(32)]))
    k = r.random()
    off = r.randint(0, 0x100) if k < 0.7 else r.getrandbits(32)
    ln = r.randint(0, 0x100) if k < 0.7 else r.getrandbits(32)
    return [rnd(c, 0x10), buf, off, ln]


def _620(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    p = rnd(c, 0x100)
    enc = rnd(c, 0x40)
    f = codeaddr(c)
    c.emu.w32(enc, f)
    c.emu.w32(p + 0x8c, enc)
    nv = r.getrandbits(32)
    w = r.random() < 0.7

    def act(e, a):
        if w:
            e.w32(a[3], nv)
    phook(c, seq, f, 4, ret=r.getrandbits(32), act=act)
    phook(c, seq, 0x61dcd0, 7, ret=r.getrandbits(32))
    return [p, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _4fe(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    vals = [r.getrandbits(32) for _ in range(4)]
    cnt = [0]

    def nxt(e):
        v = vals[cnt[0] % 4]
        cnt[0] += 1
        return v
    phook(c, seq, 0x4e5e40, 0, ret=nxt, this=True)
    return [rnd(c, 0x60), rnd(c, 0x20)]


def _62c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    enc = rnd(c, 0x40)
    f = codeaddr(c)
    c.emu.w32(enc + 0x3c, f)
    k = r.random()
    b = r.getrandbits(8)
    adv = r.randint(0, 4)

    def act(e, a):
        e.w32(a[1], (e.r32(a[1]) + adv) & 0xffffffff)
        if k < 0.75:
            pp = e.r32(a[3])
            e.w8(pp, b)
            e.w32(a[3], pp + 1)
    phook(c, seq, f, 5, act=act)
    return [enc, r.getrandbits(32), r.getrandbits(32)]


S(0x634a83, 'FUN_634a83 (empty init table walk)', 'cdecl', None, ret=None, gen=_none, note='f16b002')
S(0x659380, 'FUN_659380 (remove geom, clear lights)', 'thiscall', None, ret='eax', gen=_659, note='f16b002')
S(0x635340, 'ZEventBase::SetTimerInterval', 'thiscall', None, ret=None, gen=_635, note='f16b002')
S(0x5fe200, 'FUN_5fe200 (recursive list free)', 'thiscall', None, ret=None, gen=_5fe, note='f16b002')
S(0x61ba80, 'expatpp::~expatpp', 'thiscall', None, ret='eax', gen=_61b, note='f16b002')
S(0x63b4c0, 'FUN_63b4c0 (decal Add forwarder)', 'thiscall', None, ret=None, gen=_63b, note='f16b002')
S(0x5f3440, 'FUN_5f3440 (span init + bound check)', 'thiscall', None, ret='eax', gen=_5f3, note='f16b002; null handler path (int3) not run')
S(0x620bc0, 'FUN_620bc0 (expat prolog step)', 'cdecl', None, ret='eax', gen=_620, note='f16b002')
S(0x4fe080, 'CNewDialogCamera::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_4fe, note='f16b002')
S(0x62c600, 'toAscii', 'cdecl', None, ret='eax', gen=_62c, note='f16b002')
