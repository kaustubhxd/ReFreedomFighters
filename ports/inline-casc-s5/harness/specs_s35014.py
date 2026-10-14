"""specs_s35014.py - 0x5a1ac0 (thiscall(a, b, c) ret 0xc). Object with unaligned [+0x93a] (effect object, null in 1/5) and [+0x936] (table of 256 dwords), [+0x54] -> record; vtable slots 0x6ec (3 args) and
0x684 (2 args, leaves them on the stack: pop=0, returns a random value); hooked 0x5da860 (thiscall, 2 args, AL true in 2/3), 0x5dabe0 and 0x467000 (thiscall, 4 args). c includes values whose low byte is 0."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5a1ac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0xa00, {0x6ec: pystub(c, 3, this=True), 0x684: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x1c0)
    fx = 0 if r.random() < 0.2 else rnd(c, 0x10)
    e.wbytes(me + 0x93a, fx.to_bytes(4, 'little'))
    tbl = rnd(c, 0x400)
    e.wbytes(me + 0x936, tbl.to_bytes(4, 'little'))
    e.w32(me + 0x54, rnd(c, 0x10))
    hook_rec(c, 0x5da860, 2, this=True, ret=(r.getrandbits(32) | 1) if r.random() < 2 / 3 else (r.getrandbits(32) & ~0xff))
    hook_rec(c, 0x5dabe0, 4, this=True)
    hook_rec(c, 0x467000, 4, this=True)
    return [me, r.getrandbits(32), r.choice([0, 0, 1, r.getrandbits(32)]), r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])]


S(0x5a1ac0, 'GUESS dispatch indexed entry', 'thiscall', None, ret=None, gen=_g5a1ac0, note='batch35014')
