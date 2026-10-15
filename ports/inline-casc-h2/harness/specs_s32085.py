"""specs_s32085.py - h2 (Sonnet) batch 32085: eight tier C wrappers. Callees hooked as recorders; slots are recorder stubs.
Slots whose arguments stay on the stack for the next callee (0x467230 slot 0x20, 0x5f0d80 slot 0x2c4) are stubs with pop=0."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g4f2cc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    me = rnd(c, 0x200)
    vt = c.emu.alloc(0x80, 4)
    e.w32(vt + 0x40, pystub(c, 1, ret=r.getrandbits(32), this=True))
    e.wbytes(me + 0x1a7, vt.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def g51eb50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    buf = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=buf)
    me = rnd(c, 0x40)
    e.w32(me + 0x18, obj(c, 0x20, {0x398: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x398 // 4 + 1))
    a = rnd(c, 0x20)
    return [me, a]


def g52b3f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45f3a0, 0, this=True, pop=0)
    hook_rec(c, 0x52b9d0, 0, this=True, pop=0, ret=r.getrandbits(32))
    sysobj(c, table_slots={0x114: pystub(c, 4, ret=r.getrandbits(32), this=True)}, table_size=0x120)
    return [rnd(c, 0xa0)]


def g5c3c30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e5e60, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x60)
    e.w32(me + 0x44, obj(c, 0x20, {0xbc: pystub(c, 1, ret=r.getrandbits(32), this=True)}))
    return [me, r.getrandbits(32), rnd(c, 0x10)]


def g5f0d80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f2f60, 1, this=True, pop=4, ret=r.getrandbits(32))
    r2 = obj(c, 0x20, {0x2c4: pystub(c, 1, ret=0, this=True, pop=0)}, nslots=0x2c4 // 4 + 1)
    # slot 0x2c4 returns the next object (ret is fixed per call; give it its own recorder returning a heap object)
    nxt = rnd(c, 0x40)
    vt = c.emu.r32(r2)
    c.emu.w32(vt + 0x2c4, pystub(c, 1, ret=nxt, this=True, pop=0))
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r2, this=True)})
    return [rnd(c, 0x20), r.getrandbits(32)]


def g467230(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    res = rnd(c, 0x20)
    hook_rec(c, 0x43ec00, 6, this=True, pop=0x18, ret=r.getrandbits(32))
    me = obj(c, 0x40, {0x20: pystub(c, 6, ret=res, this=True, pop=0)}, nslots=0x20 // 4 + 1)
    e.w32(me + 8, rnd(c, 0x40))
    return [me, r.getrandbits(32)]


def g475a80(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x10: pystub(c, 0, ret=r.choice([0, 1, r.getrandbits(32)]), this=True),
                       8: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    return [me, r.getrandbits(32)]


def g47fc10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x10: pystub(c, 0, ret=r.choice([0, 0x100, 1, r.getrandbits(32)]), this=True)})
    me = obj(c, 0x40, {0x14: pystub(c, 0, ret=r.getrandbits(32), this=True)})
    e.w32(me + 4, o)
    return [me]


S(0x4f2cc0, 'GUESS table slot 0x4c then embedded object slot 0x40', 'thiscall', None, ret='eax', gen=g4f2cc0, note='batch32085')
S(0x51eb50, 'GUESS 5003d0 then slot 0x398([r])', 'thiscall', None, ret='eax', gen=g51eb50, note='batch32085')
S(0x52b3f0, 'GUESS init word from table slot 0x114, tail 52b9d0', 'thiscall', None, ret='eax', gen=g52b3f0, note='batch32085')
S(0x5c3c30, 'GUESS store 4e5e60 result, slot 0xbc(1)', 'thiscall', None, ret='eax', gen=g5c3c30, note='batch32085')
S(0x5f0d80, 'GUESS table slot 0x58(edx), slot 0x2c4(this), 4f2f60', 'fastcall', None, ret='eax', gen=g5f0d80, note='batch32085')
S(0x467230, 'GUESS slot 0x20 with six args then 43ec00', 'thiscall', None, ret='eax', gen=g467230, note='batch32085')
S(0x475a80, 'GUESS conditional slot 8(a,0)', 'thiscall', None, ret='eax', gen=g475a80, note='batch32085')
S(0x47fc10, 'GUESS conditional tail slot 0x14', 'thiscall', None, ret='eax', gen=g47fc10, note='batch32085')
