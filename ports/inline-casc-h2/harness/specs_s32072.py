"""specs_s32072.py - h2 (Sonnet) batch 32072: 0x65f4d0, 0x4d4f70. Callees hooked (0x64b2f0 returns a spec record or 0; 0x4de420 runs the real exe code;
0x4d4de0 returns a record with the sign bit set; 0x634d22 is a cdecl recorder)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def g65f4d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x40)
    inner = rnd(c, 0x60)
    e.w32(rec + 0xc, inner)
    hook_rec(c, 0x64b2f0, 3, this=True, ret=(rec if r.random() < 0.8 else 0))
    me = rnd(c, 0x20)
    e.w32(me + 0xc, rnd(c, 0x20))
    p = rnd(c, 0x10)
    if r.random() < 0.25:
        e.w32(p, 0)
    elif r.random() < 0.5:
        e.w32(p, 1)
    return [me, r.getrandbits(32), p, rnd(c, 0x30), rnd(c, 0x10), r.getrandbits(32), r.getrandbits(32)]


def g4d4f70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    x = rnd(c, 0x100)
    flags = (r.getrandbits(32) | 0x80000000)
    if r.random() < 0.5:
        flags |= 0x40000000
    else:
        flags &= ~0x40000000
    e.w32(x + 4, flags)
    e.w32(x + 0x10, r.randrange(0, 4))
    for qoff in (0x10, 0x10 + (0) , ):
        pass
    # payload headers at x+0x10 and at x+(k+5)*4 for k in 0..3
    for k in range(4):
        q = x + (k + 5) * 4
        e.w32(q + 4, (r.choice([0, 1, 2, 3]) << 30) | r.getrandbits(30))
        e.w32(q + 8, r.randrange(0, 0x40))
    e.w32(x + 0x14, (r.choice([0, 1, 2, 3]) << 30) | r.getrandbits(30))
    e.w32(x + 0x18, r.randrange(0, 0x40))
    hook_rec(c, 0x4d4de0, 1, ret=(x if r.random() < 0.9 else 0))
    hook_rec(c, 0x634d22, 3, pop=0)
    return [r.getrandbits(32), rnd(c, 0x20), r.getrandbits(32), r.randrange(0, 0x20)]


S(0x65f4d0, 'GUESS create record, copy block and vector', 'thiscall', None, ret='eax', gen=g65f4d0, note='batch32072')
S(0x4d4f70, 'GUESS copy out of record payload', 'stdcall', None, ret='eax', gen=g4d4f70, note='batch32072')
