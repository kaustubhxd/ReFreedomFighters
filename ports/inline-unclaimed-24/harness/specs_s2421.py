"""specs_s2421.py - decomp area 24, batch 2421: GUESS unique-append array (0x5fa440) and its forwarder (0x5f9db0).
The array struct: data pointer (+0), capacity (+4), count (+8). Values are searched; a hit returns the index, a miss
with room stores at count, a full array grows: operator new (0x41e290, cdecl, recorder returning fresh heap memory of
the requested size), copy of the old capacity elements, operator delete (0x41e2c0, cdecl, recorder). Capacity is 1..8
(a zero capacity would write past a zero-byte block)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _array(c, obj):
    r = c.rng
    e = c.emu
    cap = r.randint(1, 8)
    cnt = r.randint(0, cap)
    data = e.alloc(cap * 4 + 4, 4)
    for i in range(cap):
        e.w32(data + 4 * i, r.choice([r.randint(0, 6), r.getrandbits(32)]))
    e.w32(obj + 0, data)
    e.w32(obj + 4, cap)
    e.w32(obj + 8, cnt)


def _hooks(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda emu, k: e.alloc(max(emu.arg32(0), 4), 4))
    hook_rec(c, 0x41e2c0, 1, pop=0)


def _gen(c):
    _hooks(c)
    r = c.rng
    obj = rnd(c, 0x20)
    _array(c, obj)
    return [obj, r.choice([r.randint(0, 6), r.getrandbits(32)])]


def _gen_fwd(c):
    _hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    arr = rnd(c, 0x20)
    _array(c, arr)
    c.emu.w32(o + 4, arr)
    return [o, r.choice([r.randint(0, 6), r.getrandbits(32)])]


S(0x5fa440, 'GUESS: unique-append array (0x5fa440)', 'thiscall', None, ret='eax', gen=_gen, note='batch2421')
S(0x5f9db0, 'GUESS: forwarder to unique-append (0x5f9db0)', 'thiscall', None, ret='eax', gen=_gen_fwd, note='batch2421')
