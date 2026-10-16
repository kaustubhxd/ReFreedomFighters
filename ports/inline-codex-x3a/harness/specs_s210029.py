"""specs_s210029.py - Sonnet-w3a: field reads, tree search, serializer chain, stack-buffer iterators; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g46cee0(c):
    clear_hooks(c)
    hook_rec(c, 0x43f900, 1, ret=_r(c), this=True)
    hook_rec(c, 0x4e11e0, 2, ret=_r(c), this=True)
    hook_rec(c, 0x4e12e0, 2, ret=_r(c), this=True)
    hook_rec(c, 0x4e1600, 0, ret=c.rng.choice([0xb, 0xb, 0, 0x10b, 0xc, _r(c)]), this=True)
    hook_rec(c, 0x4e1b30, 0, ret=_r(c), this=True)
    return [rnd(c, 0x80), rnd(c, 0x20)]


def g4daff0(c):
    clear_hooks(c)
    n = c.rng.choice([1, 2, 3, 4])
    chain = []
    for i in range(n):
        chain.append({'p': None})
    # build objects from the end so each can return the next in slot 0x20
    nxt = 0
    for i in reversed(range(n)):
        o = obj(c, 0x70, {0x1e0: pystub(c, 1, ret=c.rng.choice([0, 1, 1, 0x100]), this=True),
                          0x30c: pystub(c, 0, ret=c.rng.choice([0, 0, 1]), this=True),
                          0x310: pystub(c, 0, ret=c.rng.choice([0, 0, 1]), this=True),
                          0x20: pystub(c, 0, ret=nxt, this=True)}, nslots=0xc5)
        nxt = o
    first = nxt
    t = rnd(c, 0x60)
    r = c.rng.random()
    inner = rnd(c, 0x20)
    if r < 0.5:
        m = rnd(c, 0x20); _ub(c, inner + 0x23, c.rng.choice([0x100000, 0x300000, 0x100001])); c.emu.w32(m + 0xc, inner)
        c.emu.w32(t + 0x54, first if False else m)
        # the object whose slots are walked is [this+0x54] itself in this branch: make m the first object instead
        c.emu.w32(t + 0x54, first)
        _ub(c, c.emu.r32(first + 0xc) if False else first + 0, c.emu.r32(first))
        c.emu.w32(first + 0xc, inner)
    elif r < 0.9:
        c.emu.w32(t + 0x54, 0)
        w = rnd(c, 0x60); c.emu.w32(w + 0x54, first); c.emu.w32(t + 0x50, w)
    else:
        c.emu.w32(t + 0x54, 0)
        c.emu.w32(t + 0x50, 0)
    return [t]


def g5626d0(c):
    clear_hooks(c)

    def side(emu, k):
        v = c.rng.getrandbits(32)
        emu.w32(emu.arg32(0), v)
        emu.calllog.append(('out', k, v))
    r4 = obj(c, 0x40, {0x68: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x20)
    r3 = obj(c, 0x40, {0x68: pystub(c, 1, ret=r4, this=True)}, nslots=0x20)
    r2 = obj(c, 0x40, {0x68: pystub(c, 1, ret=r3, this=True)}, nslots=0x20)
    r1 = obj(c, 0x40, {0x50: pystub(c, 1, ret=r2, this=True)}, nslots=0x20)
    a = obj(c, 0x40, {0x40: pystub(c, 1, ret=r1, this=True),
                      0x48: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=side)}, nslots=0x20)
    return [rnd(c, 0x100), a]


def _walk(word_flag):
    def g(c):
        clear_hooks(c)
        cnt = c.rng.choice([0, 1, 2, 3])
        c.emu.wbytes(0x71434c, (_r(c) & 0xffff).to_bytes(2, 'little'))
        c.emu.wbytes(0x714348, (_r(c) & 0xffff).to_bytes(2, 'little'))

        def side4c(emu, k):
            p = emu.arg32(0)
            vals = [c.rng.getrandbits(32) for _ in range(3)]
            for i, v in enumerate(vals): emu.w32(p + 4 * i, v)
            emu.calllog.append(('buf', tuple(vals)))

        def side5c(emu, k):
            p = emu.arg32(0)
            emu.w32(p, (c.rng.getrandbits(32) | 1) if k + 1 < cnt else 0)
            emu.calllog.append(('buf0', emu.r32(p)))
        m = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=side4c),
                          0x5c: pystub(c, 1, ret=lambda e, k: rnd(c, 8), this=True, stackmark=(0,), side=side5c)}, nslots=0x20)
        a = rnd(c, 0x40); c.emu.w32(a + 0x10, 0 if c.rng.random() < 0.2 else m)
        c.emu.wbytes(a + 0x2c, bytes([word_flag if c.rng.random() < 0.7 else 1 - word_flag]))
        ent = obj(c, 0x40, {0x12c: pystub(c, 3, ret=_r(c), this=True)}, nslots=0x60)
        t = rnd(c, 0x50); c.emu.w32(t + 0x44, ent)
        return [t, a]
    return g


S(0x46cee0, 'read_fields_conditional', 'thiscall', None, ret='eax', gen=g46cee0, note='batch210029')
S(0x4daff0, 'find_matching_object', 'thiscall', None, ret='eax', gen=g4daff0, note='batch210029')
S(0x5626d0, 'serialize_chain_outparams', 'thiscall', None, ret='eax', gen=g5626d0, note='batch210029')
S(0x5c7980, 'walk_list_set_flag', 'thiscall', None, ret=None, gen=_walk(0), note='batch210029')
S(0x5c7a40, 'walk_list_clear_flag', 'thiscall', None, ret=None, gen=_walk(1), note='batch210029')
