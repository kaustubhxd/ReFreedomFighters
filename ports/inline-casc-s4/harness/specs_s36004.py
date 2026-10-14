"""specs_s36004.py - cascade s4 batch 36004: 0x4e7f70 (tree rebalance step), 0x4e86f0 (tree lookup), 0x4f0c10 (release buffers), 0x51f880 (write fields to stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _assert(c):
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def _g4e7f70(c):
    clear_hooks(c)
    _assert(c)
    r = c.rng
    e = c.emu
    sent = rnd(c, 0x10)
    me = obj(c, 0x20, {0x20: pystub(c, 1, this=True)})
    e.w32(me + 8, sent)
    n = rnd(c, 0x10)

    def link(off):
        ch = r.random()
        if ch < 0.2:
            return sent
        blk = rnd(c, 0x10)
        e.w32(blk, n if r.random() < 0.7 else r.getrandbits(32))
        return blk
    e.w32(n + 4, link(4))
    e.w32(n + 8, link(8))
    mode = r.random()
    if mode < 0.15:
        e.w32(me + 4, 0)
        e.w32(me + 8, 0)
        return [me, 0]
    if mode < 0.25:
        return [me, sent]
    if mode < 0.55:
        e.w32(me + 4, n)
        return [me, 0]
    return [me, n]


def _g4e86f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    key = r.randint(-3, 3) & 0xffffffff
    sent = rnd(c, 0x20)

    def mk():
        n = rnd(c, 0x20)
        e.w32(n + 0xc, r.randint(-3, 3) & 0xffffffff)
        return n
    rr = [mk() if r.random() < 0.7 else 0 for _ in range(2)]
    me = obj(c, 0x20, {0xc: pystub(c, 2, this=True, ret=lambda em, k: rr[min(k, 1)])})
    n = mk()
    e.w32(n + 4, 0 if r.random() < 0.25 else rnd(c, 0x10))
    e.w32(n + 8, 0 if r.random() < 0.25 else rnd(c, 0x10))
    root = n if r.random() < 0.3 else mk()
    e.w32(me + 4, 0 if r.random() < 0.2 else root)
    e.w32(me + 8, n if r.random() < 0.3 else sent)
    return [me, key, 0 if r.random() < 0.25 else n]


def _g4f0c10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    h = obj(c, 0x20, {0x40: pystub(c, 2, this=True), 0x48: pystub(c, 2, this=True), 0x4c: pystub(c, 2, this=True)})
    o = obj(c, 0x20, {})
    holder = rnd(c, 0x30)
    e.w32(holder + 0x18, h)
    e.wbytes(so + 0x1aa3, holder.to_bytes(4, 'little'))
    hook_rec(c, 0x4f00f0, 0, ret=lambda em, k: r.choice([0, 1, 5]))
    n = r.choice([0, 1, 2, 4, r.randint(0, 6)])
    arr = rnd(c, 0x20)
    me = obj(c, 0xa0, {0x21c: pystub(c, 1, this=True)})
    e.wbytes(me + 0x2a, bytes(r.getrandbits(8) for _ in range(0x68)))
    for off, v in ((0x2a, r.choice([0, rnd(c, 4)])), (0x36, r.choice([0, arr])), (0x3a, r.choice([0, rnd(c, 4)])), (0x32, n)):
        e.wbytes(me + off, v.to_bytes(4, 'little'))
    e.wbytes(me + 0x91, bytes([r.choice([0, 0, 1])]))
    return [me]


def _g51f880(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5184f0, 1, this=True, ret=(0 if r.random() < 0.2 else 1 + (r.getrandbits(8) << 8)))
    hook_rec(c, 0x5274f0, 1, this=True)
    hook_rec(c, 0x513f50, 1, this=True)
    me = e.alloc(0x1700, 4)
    e.wbytes(me + 0x1650, bytes(r.getrandbits(8) for _ in range(0xb0)))
    s = obj(c, 0x20, {0x3c: pystub(c, 1, this=True), 0x64: pystub(c, 1, this=True), 0x44: pystub(c, 1, this=True),
                      0x68: pystub(c, 1, this=True, deref={0: 3})})
    return [me, s]


S(0x4e7f70, 'GUESS tree node fixup step', 'thiscall', None, ret=None, gen=_g4e7f70, note='batch36004')
S(0x4e86f0, 'GUESS tree lookup by key', 'thiscall', None, ret='eax', gen=_g4e86f0, note='batch36004')
S(0x4f0c10, 'GUESS release owned buffers', 'thiscall', None, ret=None, gen=_g4f0c10, note='batch36004')
S(0x51f880, 'GUESS serialize fields to stream', 'thiscall', None, ret='al', gen=_g51f880, note='batch36004')
