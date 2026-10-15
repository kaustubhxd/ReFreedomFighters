"""specs_s32082.py - h2 (Sonnet) batch 32082: eight tier C vtable-slot wrappers. Slots are recorder stubs returning random eax."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g46e740(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    me = rnd(c, 0x80)
    if r.random() < 0.3:
        c.emu.w32(me + 0x64, 0)
    return [me]


def g4c62f0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x3c: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x60), o]


def g52cf40(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, slots={0x1c8: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x20)]


def g5fa4d0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0xc: pystub(c, 3, ret=r.getrandbits(32), pop=0)})
    hook_rec(c, 0x5fa630, 0, ret=o, pop=0)
    return [r.getrandbits(32)]


def g4610f0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x228: pystub(c, 5, ret=r.getrandbits(32), this=True)}, nslots=0x228 // 4 + 1)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def g46a5c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43ea20, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x80)
    if r.random() < 0.75:
        c.emu.w32(me + 0x70, obj(c, 0x20, {0: pystub(c, 1, this=True)}))
    else:
        c.emu.w32(me + 0x70, 0)
    return [me]


def g47a4d0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.wbytes(0x6ffa44, r.getrandbits(16).to_bytes(2, 'little'))
    return [obj(c, 0x6d0, {0x128: pystub(c, 3, this=True)}, nslots=0x128 // 4 + 1)]


def g4cb4f0(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x48: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x60), o]


S(0x46e740, 'GUESS table slot 0x58([this+0x64]) when set', 'thiscall', None, ret='eax', gen=g46e740, note='batch32082')
S(0x4c62f0, 'GUESS clear bit 6, slot 0x3c(unaligned field), true', 'thiscall', None, ret='al', gen=g4c62f0, note='batch32082')
S(0x52cf40, 'GUESS store engine slot 0x1c8 result', 'thiscall', None, ret=None, gen=g52cf40, note='batch32082')
S(0x5fa4d0, 'GUESS cdecl slot 0xc of 0x5fa630 object', 'stdcall', None, ret='eax', gen=g5fa4d0, note='batch32082')
S(0x4610f0, 'GUESS slot 0x228(a,b,0,-1,1)', 'thiscall', None, ret='eax', gen=g4610f0, note='batch32082')
S(0x46a5c0, 'GUESS dtor: release owned object then tail to base', 'thiscall', None, ret='eax', gen=g46a5c0, note='batch32082')
S(0x47a4d0, 'GUESS slot 0x128(word,0,0), clear fields', 'thiscall', None, ret=None, gen=g47a4d0, note='batch32082')
S(0x4cb4f0, 'GUESS clear bit 6, slot 0x48(this+0x4c), true', 'thiscall', None, ret='al', gen=g4cb4f0, note='batch32082')
