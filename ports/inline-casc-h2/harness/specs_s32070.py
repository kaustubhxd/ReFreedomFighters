"""specs_s32070.py - h2 (Sonnet) batch 32070: 0x562af0, 0x4361a0, 0x45b2f0. Callees hooked as recorders; /GS check 0x633654 recorder without args."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def g562af0(c):
    clear_hooks(c)
    hook_rec(c, 0x562b50, 1, this=True, deref={0: -5})
    hook_rec(c, 0x633654, 0, pop=0)
    r = c.rng
    n = r.choice([0, 9, 10, 99, 100, 255, 256, r.getrandbits(8), r.getrandbits(32), r.randrange(0, 100)])
    return [rnd(c, 0x40), n]


def g4361a0(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x200)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, r.choice([0, rnd(c, 8), r.getrandbits(32)]))
    ln = r.choice([0, 1, 2, r.randrange(0, 100)])
    s = rnd(c, 0x80)
    c.emu.wbytes(s, bytes(r.randrange(1, 256) for _ in range(ln)) + b'\0')
    return [me, s]


def g45b2f0(c):
    clear_hooks(c)
    hook_rec(c, 0x43de40, 3, this=True, pop=12)
    r = c.rng
    return [rnd(c, 0x420), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x562af0, 'GUESS format code C0 + two digits, pass to 0x562b50', 'thiscall', None, ret=None, gen=g562af0, note='batch32070')
S(0x4361a0, 'GUESS replace owned string copy', 'thiscall', None, ret='eax', gen=g4361a0, note='batch32070')
S(0x45b2f0, 'GUESS init object fields', 'thiscall', None, ret='eax', gen=g45b2f0, note='batch32070')
