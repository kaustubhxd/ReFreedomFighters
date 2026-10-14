"""specs_s32081.py - h2 () batch 32081: eight tier C vtable-slot wrappers. Slots are recorder stubs returning random eax."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g63ea90(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x10)
    return [obj(c, 0x40, {0x2c: pystub(c, 1, ret=buf, this=True)}), r.getrandbits(32)]


def g462d60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    t = obj(c, 0x20, {0xc4: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    o = rnd(c, 0x40)
    e.w32(o + 0x18, t)
    e.wbytes(so + 0x1aa3, o.to_bytes(4, 'little'))
    inner = rnd(c, 0x80)
    me = rnd(c, 0x20)
    e.w32(me + 8, inner)
    return [me]


def g4415d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4690b0, 0, this=True, pop=0, ret=r.getrandbits(32))
    res = rnd(c, 0x10) if r.random() < 0.7 else 0
    tbl = obj(c, 0x40, {0x58: pystub(c, 1, ret=res, this=True)})
    sysobj(c)
    c.emu.w32(0x70039c, c.emu.r32(0x70039c))
    so = c.emu.r32(0x70039c)
    c.emu.w32(so + 0x9b, tbl)
    return []


def g46d6e0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x31c: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x31c // 4 + 1)
    return [obj(c, 0x40, {0x350: pystub(c, 0, ret=o, this=True)})]


def g474710(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x466d90, 0, this=True, pop=0)
    return [obj(c, 0x300, {0x104: pystub(c, 1, ret=r.getrandbits(32), this=True)})]


def g5331d0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x114: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [me, 0 if r.random() < 0.3 else rnd(c, 0x20)]


def g651360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x24: pystub(c, 2, this=True)})
    me = rnd(c, 0xd0)
    e.wbytes(me + 0xbd, o.to_bytes(4, 'little'))
    return [me]


def g462430(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    inner = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0)})
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True)})
    e.w32(0x700390, g)
    return [r.getrandbits(32)]


S(0x63ea90, 'GUESS byte [slot2c(a)+1]', 'thiscall', None, ret='al', gen=g63ea90, note='batch32081')
S(0x462d60, 'GUESS engine object slot 0xc4([[this+8]+0x6c])', 'thiscall', None, ret='eax', gen=g462d60, note='batch32081')
S(0x4415d0, 'GUESS table lookup then tail call', 'cdecl', None, ret='eax', gen=g4415d0, note='batch32081')
S(0x46d6e0, 'GUESS slot350 then slot31c(this)', 'thiscall', None, ret='eax', gen=g46d6e0, note='batch32081')
S(0x474710, 'GUESS base init then store slot104 result', 'thiscall', None, ret=None, gen=g474710, note='batch32081')
S(0x5331d0, 'GUESS slot114([p+0x10]) when p', 'thiscall', None, ret=None, gen=g5331d0, note='batch32081')
S(0x651360, 'GUESS slot24(a,b) then clear a', 'thiscall', None, ret=None, gen=g651360, note='batch32081')
S(0x462430, 'GUESS global slot20 then cdecl slot2c', 'stdcall', None, ret='eax', gen=g462430, note='batch32081')
