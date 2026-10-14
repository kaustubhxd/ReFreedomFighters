"""specs_s34016.py - cascade tier E, batch 34016: 0x499de0 (chunk is null in half the cases; pool [[this+0xc]+4] null in a quarter of those; hooks 0x4cd9b0, 0x41e290
(return a fresh buffer or 0), 0x499e60), 0x4f5860 (hooked 0x4f05d0 returns 0/1; stream and self slots are recorders) and 0x4eb080 (fastcall helpers hooked, ECX, EDX and
the stack argument recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fc(c, addr, nstack):
    hook_rec(c, addr, nstack, ret=0, this=True,
             side=lambda em, k: em.calllog.append((hex(addr), 'edx', em.reg('edx'))))


def _g499de0(c):
    clear_hooks(c)
    r = c.rng
    buf = rnd(c, 0x20)
    hook_rec(c, 0x4cd9b0, 2, ret=buf, this=True)
    hook_rec(c, 0x41e290, 1, ret=(0 if r.random() < 0.3 else buf), pop=0)
    hook_rec(c, 0x499e60, 3, this=True)
    me = rnd(c, 0x40)
    owner = rnd(c, 0x20)
    c.emu.w32(owner + 4, 0 if r.random() < 0.3 else (r.getrandbits(32) | 0x10000000))
    c.emu.w32(me + 0xc, owner)
    c.emu.w32(me, 0 if r.random() < 0.6 else rnd(c, 0x20))
    c.emu.w32(me + 8, r.choice([0, 5, 0x100, r.getrandbits(31)]))
    c.emu.w32(me + 4, r.choice([0, 5, 0x100, 0x7fffffff, r.getrandbits(32)]))
    return [me, r.getrandbits(32), r.choice([0, 1, 4, 0x10, r.getrandbits(16)])]


def _g4f5860(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f05d0, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True, nullflag=())
    stream = obj(c, 0x40, {0x48: pystub(c, 1, this=True), 0x18: pystub(c, 2, this=True)}, nslots=0x20)
    me = obj(c, 0x100, {0x244: pystub(c, 0, this=True), 0x27c: pystub(c, 0, this=True)}, nslots=0x20)
    return [me, stream]


def _g4eb080(c):
    clear_hooks(c)
    r = c.rng
    _fc(c, 0x43e920, 1)
    _fc(c, 0x441a60, 0)
    _fc(c, 0x459fc0, 1)
    me = rnd(c, 0xc0)
    a = rnd(c, 0x40)
    cc = rnd(c, 0x10)
    return [me, a, r.getrandbits(32), cc]


S(0x499de0, 'GUESS lazy chunk alloc + append', 'thiscall', None, ret='eax', gen=_g499de0, note='batch34016')
S(0x4f5860, 'GUESS validate + read via stream', 'thiscall', None, ret='al', gen=_g4f5860, note='batch34016')
S(0x4eb080, 'GUESS copy floats + three fastcall helpers', 'thiscall', None, ret=None, gen=_g4eb080, note='batch34016')
