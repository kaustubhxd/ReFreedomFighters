"""specs_s34103.py - seven call wrappers; callees are recorders (this recorded). The address-of-parameter callee 0x4d2700 logs the pointed-to dword and may rewrite it."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
from unicorn.x86_const import UC_X86_REG_ECX


def _g4d3a40(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        if r.random() < 0.5:
            em.w32(em.arg32(3), r.getrandbits(32))
    hook_rec(c, 0x4d2700, 5, this=True, ret=r.getrandbits(32), deref={3: 1}, side=side)
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g4d3d70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4d24e0, 4, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 0x3fffffff, 0x40000000, 0x80000001, r.getrandbits(32)])]


def _g549820(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x54cec0, 0, this=True, pop=0, ret=r.getrandbits(32), side=lambda em, k: em.mu.reg_write(UC_X86_REG_ECX, r.getrandbits(32)))
    me = obj(c, 0xa280, {0x9c: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0xa0 // 4)
    c.emu.wbytes(me + 0xa26d, bytes([r.choice([0, 1, 7])]))
    return [me, r.getrandbits(32)]


def _g4b1ab0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4b1130, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0xe0), rnd(c, 0x20)]


def _g5dd690(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x47bde0, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x50)
    c.emu.w32(me + 0x44, rnd(c, 0x20))
    return [me, rnd(c, 0x20)]


def _g64fe60(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x40)
    if r.random() < 0.3:
        c.emu.w32(me + 0x2c, 0)
    return [me]


def _g55b0f0(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    hook_rec(c, 0x5002f0, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x30)
    mid = rnd(c, 0x60)
    o = rnd(c, 0x10)
    c.emu.w32(mid + 0x54, o)
    c.emu.w32(me + 0x1c, mid)
    a = rnd(c, 0x20)
    return [me, a]


S(0x4d3a40, 'GUESS forward with slot address', 'thiscall', None, ret='eax', gen=_g4d3a40, note='batch34103')
S(0x4d3d70, 'GUESS forward with scaled count', 'thiscall', None, ret='eax', gen=_g4d3d70, note='batch34103')
S(0x549820, 'GUESS call then optional slot 0x9c', 'thiscall', None, ret='eax', gen=_g549820, note='batch34103')
S(0x4b1ab0, 'GUESS init and store lookup', 'thiscall', None, ret='eax', gen=_g4b1ab0, note='batch34103')
S(0x5dd690, 'GUESS lookup then forward', 'thiscall', None, ret='eax', gen=_g5dd690, note='batch34103')
S(0x64fe60, 'GUESS release buffer and clear', 'thiscall', None, ret=None, gen=_g64fe60, note='batch34103')
S(0x55b0f0, 'GUESS copy value through cell', 'thiscall', None, ret='eax', gen=_g55b0f0, note='batch34103')
