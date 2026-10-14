"""specs_s34042.py - cascade tier E, batch 34042.
0x567110: this slot 0xd8 (returns 0/1 per call: first and second call independent); a is 1 in half the cases; hooked 0x566f10 (returns x), 0x563d40 (three args, the pointed dword recorded), 0x5672c0, 0x567510
and the verified 0x562c20 (a recorder here).
0x56f7c0: the snapshot builder 0x5ad790 and the five helpers are recorders (stack pointers recorded as markers); [this+0x94] block random; /GS check 0x633654 a zero-argument recorder.
0x5708a0: byte +0x1a3 zero or not; hooked 0x562440; engine table slots 0x138 (returns an object with slot 0x60) and 0x4c (two args) are recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g567110(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x566f10, 0, ret=r.getrandbits(32), this=True, pop=0)
    hook_rec(c, 0x563d40, 3, this=True, deref={1: 1})
    hook_rec(c, 0x5672c0, 1, this=True)
    hook_rec(c, 0x567510, 0, this=True, pop=0)
    hook_rec(c, 0x562c20, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)
    me = obj(c, 0x40, {0xd8: pystub(c, 0, ret=lambda em, k: r.choice([0, 0, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0xe0 // 4)
    return [me, r.choice([1, 1, 0, 2, r.getrandbits(32)])]


def _g56f7c0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ad790, 0, this='mark', pop=0)
    hook_rec(c, 0x56e9d0, 1, this=True, stackmark=(0,))
    for a in (0x5ad230, 0x5ad2b0, 0x59ca50):
        hook_rec(c, a, 1, this=True)
    hook_rec(c, 0x5ae710, 1, this=True)
    hook_rec(c, 0x633654, 0, pop=0)
    me = rnd(c, 0x4c0)
    c.emu.w32(me + 0x94, rnd(c, 0x420))
    return [me]


def _g5708a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562440, 0, this=True, pop=0)
    s = obj(c, 0x20, {0x60: pystub(c, 2, this=True)}, nslots=0x70 // 4)
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=s, this=True), 0x4c: pystub(c, 2, ret=lambda em, k: r.getrandbits(32), this=True)})
    me = rnd(c, 0x1b0)
    c.emu.wbytes(me + 0x1a3, bytes([r.choice([0, 1, r.getrandbits(8)])]))
    return [me]


S(0x567110, 'GUESS command gate', 'thiscall', None, ret='al', gen=_g567110, note='batch34042')
S(0x56f7c0, 'GUESS copy snapshot into the attached object', 'thiscall', None, ret=None, gen=_g56f7c0, note='batch34042')
S(0x5708a0, 'GUESS publish table value under one of two names', 'thiscall', None, ret=None, gen=_g5708a0, note='batch34042')
