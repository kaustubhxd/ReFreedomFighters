"""specs_s2614.py - wider batch 2614: fourteen small unclaimed functions. Every callee and vtable slot is a recorder (arities from the exes `ret` immediates)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def rl(r, n, f):
    v = [f() for _ in range(n)]
    return lambda em, k: v[k % n]


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def g42b290(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x6014a0, 1, this=True, ret=lambda em, k: em.alloc(0x20, 4))
    return [rnd(c, 0x20), c.rng.getrandbits(32)]


def g452ad0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dc600, 1, this=True, deref={0: 3})
    hook_rec(c, 0x4dd060, 1, this=True, deref={0: 3}, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x4dce50, 1, this=True)
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, rnd(c, 0x40))
    return [me]


def g483570(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x114: pystub(c, 6, this=True, ret=rl(r, 6, lambda: r.getrandbits(32)))})
    o = obj(c, 0x40, {0x128: pystub(c, 1, this=True, ret=rl(r, 4, lambda: r.getrandbits(32)))})
    me = rnd(c, 0x120)
    c.emu.w32(me + 0x104, o)
    return [me, r.getrandbits(32)]


def g48ab00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4e6810, 0, this=True)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, r.getrandbits(32))
    return [me, r.choice([0, 1, 2, 3, 0x100, r.getrandbits(32)])]


def g48f480(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4958e0, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0xb00)
    c.emu.w32(me + 0xadc, obj(c, 0x20, {0x210: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0)
    c.emu.w32(me + 8, rnd(c, 0x20) if r.random() < 0.7 else 0)
    return [me]


def g48fa10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, slots={0xfc: pystub(c, 1, this=True)})
    me = rnd(c, 0x1c80)
    for i in range(0x402):
        if r.random() < 0.3:
            e.wbytes(me + 0xc4d + 4 * i, r.getrandbits(32).to_bytes(4, 'little'))
        else:
            e.wbytes(me + 0xc4d + 4 * i, bytes(4))
    o = obj(c, 0x20, {4: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0
    e.wbytes(me + 0x1c55, o.to_bytes(4, 'little'))
    return [me]


def g4927c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: em.alloc(0x40, 4))
    v = rl(r, 4, lambda: r.choice([0, 0xffffffff, r.getrandbits(32) | 1, 7]))
    me = obj(c, 0xb00, {0x210: pystub(c, 0, this=True, ret=v), 0x214: pystub(c, 2, this=True)})
    e.w32(me + 0xaf0, r.choice([0, 0, 5, r.getrandbits(32) | 1]))
    e.w32(me + 0xaf4, r.choice([0, 0, r.getrandbits(32)]))
    return [me]


def g497930(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: em.alloc(0x4000, 4))
    e.w32(0x70038c, obj(c, 0x20, {0x24: pystub(c, 2, this=True)}) if r.random() < 0.7 else 0)
    return [rnd(c, 0x80)]


def g49b680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x4e6b40, 0, this=True)
    me = rnd(c, 0x80)
    e.wbytes(me + 0x35, (rnd(c, 8) if r.random() < 0.7 else 0).to_bytes(4, 'little'))
    e.wbytes(me + 0x2d, (rnd(c, 8) if r.random() < 0.6 else 0).to_bytes(4, 'little'))
    e.wbytes(me + 0x1d, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


def g49b6d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, nargs=2, slot=0x30)
    blk = rnd(c, 0x40)
    hook_rec(c, 0x4e6bc0, 0, this=True, ret=blk if r.random() < 0.6 else 0)
    me = rnd(c, 0x80)
    e.wbytes(me + 0x2d, rnd(c, 8).to_bytes(4, 'little'))
    e.wbytes(me + 0x1d, r.getrandbits(32).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def g4a3600(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x120, {0x3c: pystub(c, 0, this=True)})
    e.w32(me + 0x54, r.choice([0, 5, 0x80000000, 0xffffffff, r.getrandbits(32)]))
    s = bytes(r.choice(b'abcXYZ019 _') for _ in range(r.randint(0, 40))) + b'\0'
    p = e.alloc(len(s) + 4, 1)
    e.wbytes(p, s)
    return [me, p]


def g4a4380(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4a44d0, 0, this=True)
    gg = rnd(c, 0x60)
    e.w32(gg + 8, r.choice([0, 1, 1, 2, r.getrandbits(32)]))
    o = obj(c, 0x40, {0x104: pystub(c, 1, this=True, ret=rl(r, 4, lambda: r.getrandbits(32)))})
    e.w32(o + 0x18, gg)
    me = rnd(c, 0x80)
    e.w32(me + 0x44, o)
    return [me]


def g4aff50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    R = r.getrandbits(32)
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=R)})
    me = rnd(c, 0x80)
    p = rnd(c, 8)
    if r.random() < 0.5:
        e.w32(p, e.r32(me + 0x48))
    a = (R & 0xffff) | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0) if r.random() < 0.6 else r.getrandbits(32)
    return [me, a, p]


def g4b0590(c):
    clear_hooks(c)
    r = c.rng
    _assert_hook(c)
    me = obj(c, 0x80, {0x98: pystub(c, 1, this=True)})
    p = obj(c, 0x20, {0x48: pystub(c, 1, this=True)})
    return [me, p]


S(0x42b290, 'GUESS block init (alloc 8)', 'thiscall', None, ret='eax', gen=g42b290, note='batch2614')
S(0x452ad0, 'GUESS three calls on member (cookie)', 'thiscall', None, ret=None, gen=g452ad0, note='batch2614')
S(0x483570, 'GUESS engine word lookup then slot 0x128', 'thiscall', None, ret='eax', gen=g483570, note='batch2614')
S(0x48ab00, 'GUESS scalar deleting dtor (size 0x20)', 'thiscall', None, ret='eax', gen=g48ab00, note='batch2614')
S(0x48f480, 'GUESS release two members', 'thiscall', None, ret=None, gen=g48f480, note='batch2614')
S(0x48fa10, 'GUESS release pointer table', 'thiscall', None, ret=None, gen=g48fa10, note='batch2614')
S(0x4927c0, 'GUESS lazy size and buffer', 'thiscall', None, ret=None, gen=g4927c0, note='batch2614')
S(0x497930, 'GUESS alloc two blocks, fill words', 'thiscall', None, ret=None, gen=g497930, note='batch2614')
S(0x49b680, 'GUESS dtor with tail call', 'thiscall', None, ret=None, gen=g49b680, note='batch2614')
S(0x49b6d0, 'GUESS slot index', 'thiscall', None, ret='eax', gen=g49b6d0, note='batch2614')
S(0x4a3600, 'GUESS set name string', 'thiscall', None, ret='eax', gen=g4a3600, note='batch2614')
S(0x4a4380, 'GUESS init four lookups', 'thiscall', None, ret=None, gen=g4a4380, note='batch2614')
S(0x4aff50, 'GUESS conditional replace', 'thiscall', None, ret='eax', gen=g4aff50, note='batch2614')
S(0x4b0590, 'GUESS assert hook then two vcalls', 'thiscall', None, ret='al', gen=g4b0590, note='batch2614')
