"""specs_s1215.py - fresh slice 12, batch 15."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global
from helpers12 import rand_obj, hk, done


def g_42c900(c):
    head = c.rng.getrandbits(32)
    found = c.rng.random() < 0.5
    node = c.rng.getrandbits(32) if found else head

    def find(em, r):
        out, key = em.arg32(0), em.arg32(1)
        em.calllog.append(('find', 0, em.reg('ecx'), (key,)))   # out is a stack local: write it, do not log it
        em.w32(out, node)
        em.ret(eax=out, argbytes=8)
    c.emu.hook(0x430b70, find)
    ntok = c.rng.randrange(0, 8)
    toks = c.emu.alloc(12 * ntok + 12, 4)
    for i in range(ntok):
        k = c.rng.randrange(4)
        s = [b' ', b'  ', b'x', b''][k] if c.rng.random() < 0.8 else bytes([c.rng.choice(b' a')])
        p = c.emu.alloc(len(s) + 1, 1)
        c.emu.wbytes(p, s + b'\0')
        c.emu.w32(toks + 12 * i, p)
        c.emu.w32(toks + 12 * i + 4, p + len(s))
        c.emu.w32(toks + 12 * i + 8, c.rng.getrandbits(32))
    lst = zero_obj(c, 0x10)
    c.emu.w32(lst + 4, toks + 12 * ntok)
    mp = zero_obj(c, 0x10)
    c.emu.w32(mp, head)
    self_ = rand_obj(c, 0x1b80)
    c.emu.w32(self_ + 0x1b6d, lst)
    c.emu.w32(self_ + 0x1b65, mp)
    it = c.emu.alloc(4, 4)
    c.emu.w32(it, toks + 12 * c.rng.randrange(0, ntok + 1))
    return done(c, [self_, it])


def g_538600(c):
    a = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    rec = c.rng.choice([0, rand_obj(c, 0x10)])
    if rec and c.rng.random() < 0.5:
        c.emu.w32(rec + 4, 0xc)
    ret = lambda v: (lambda e, ar: (v, None))
    self_ = rand_obj(c, 0x5400)
    c.emu.w32(self_ + 0x53b2, c.emu.logging_vtable('A', 0x20, impl={0x28: ret(a), 0x3c: ret(0x3c3c)}, argwords={0x28: 1, 0x3c: 1}))
    c.emu.w32(self_ + 0x5306, c.emu.logging_vtable('B', 0x8, impl={4: ret(0x4b4b)}, argwords={4: 1}))
    e = logged_obj(c, 'Eng', 0x20, impl={0x60: ret(rec)}, argwords={0x60: 1})
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x9b, e)
    set_global(c, 0x70039c, eng)
    return done(c, [self_, c.rng.getrandbits(32)])


def g_41c780(c):
    for g, slot in ((0x7003a0, 0), (0x70039c, 0x18), (0x700394, 0xcc), (0x70038c, 0)):
        o = c.rng.choice([0, logged_obj(c, 'G%x' % g, 0x40, argwords={slot: 1})])
        c.emu.w32(g, o)
    c.emu.w32(0x700390, logged_obj(c, 'G390', 0x10, argwords={4: 1}))
    return done(c, [])


S(0x42c900, 'FUN_0042c900 token reader step (skip spaces, map find)', 'thiscall', None, ret='eax', gen=g_42c900)
S(0x538600, 'FUN_00538600 move item between lists (state 3 / 0xc)', 'thiscall', None, ret='eax', gen=g_538600)
S(0x41c780, 'FUN_0041c780 engine shutdown (delete globals)', 'cdecl', None, ret=None, gen=g_41c780)
