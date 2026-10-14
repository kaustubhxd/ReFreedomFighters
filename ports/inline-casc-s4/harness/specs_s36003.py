"""specs_s36003.py - cascade s4 batch 36003: 0x4cfb30 (init a pool block and link it), 0x4d0c70 (unlink a block, recycle node)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memset


def _node(c, linked=None):
    """0x40-byte node whose unaligned dword at +0x11 is 0 or a pointer to a block (valid for the writes at +0x10/+0x14)."""
    r = c.rng
    nd = rnd(c, 0x40)
    v = 0 if (linked is False or (linked is None and r.random() < 0.4)) else rnd(c, 0x40)
    c.emu.wbytes(nd + 0x11, v.to_bytes(4, 'little'))
    return nd


def _setpool(c, E, slots):
    o = obj(c, 0x10, slots)
    c.emu.w32(E + 0x1cc, c.emu.r32(o))


def _g4cfb30(c):
    clear_hooks(c)
    r = c.rng
    stub_memset(c)
    E = rnd(c, 0x240)
    size = r.choice([0x30, 0x34, 0x40, 0x100, r.randint(0x30, 0x120)])
    blk = rnd(c, size + 0x10)
    n1 = _node(c)
    n2 = _node(c)
    ret1 = 0 if r.random() < 0.35 else n1
    _setpool(c, E, {0: pystub(c, 1, this=True), 8: pystub(c, 2, this=True, ret=ret1)})
    hook_rec(c, 0x4d0630, 0, ret=n2, this=True)
    return [E, blk, size]


def _g4d0c70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x4d0950, 1, this=True)
    E = e.alloc(0x12200, 4)
    e.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x200)))
    cnt = 0x64 if r.random() < 0.3 else r.randint(0, 0x63)
    e.w32(E + 0x1c4, cnt)
    e.w32(E + 0x12130, r.randint(1, 0x40))
    a = rnd(c, 0x20)
    e.w32(a + 8, r.choice([0, 0, 0xffffffff, r.getrandbits(32), r.getrandbits(31), r.getrandbits(31)]))
    prev = rnd(c, 0x20) if r.random() < 0.6 else 0
    nxt = rnd(c, 0x20) if r.random() < 0.6 else 0
    e.w32(a + 0x10, prev)
    e.w32(a + 0x14, nxt)
    node = _node(c, linked=(r.random() < 0.5))
    x = rnd(c, 0x10)
    _setpool(c, E, {8: pystub(c, 2, this=True, ret=node), 4: pystub(c, 1, this=True, ret=x)})
    b = 0 if r.random() < 0.4 else node
    return [E, a, b]


S(0x4cfb30, 'GUESS init pool block and link it', 'thiscall', None, ret='eax', gen=_g4cfb30, note='batch36003')
S(0x4d0c70, 'GUESS unlink block, recycle node', 'thiscall', None, ret=None, gen=_g4d0c70, note='batch36003')
