"""specs_s34102.py - seven call wrappers; callees are recorders (this recorded). 0x42ac96: the hooked callee logs four dwords starting at the pointer it is given, i.e. the caller's argument slots."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4e49d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e49f0, 2, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x20)
    return [me, r.getrandbits(32)]


def _g5d3480(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5d3780, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x60)
    w = r.getrandbits(16)
    c.emu.wbytes(me + 0x52, w.to_bytes(2, 'little'))
    a = w if r.random() < 0.5 else r.getrandbits(32)
    if r.random() < 0.4:
        a = (a & 0xffff) | (r.getrandbits(16) << 16)
    return [me, a, r.getrandbits(32)]


def _g4681d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x584cc0, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x1f0)
    c.emu.wbytes(me + 0x1de, (0 if r.random() < 0.3 else rnd(c, 0x20)).to_bytes(4, 'little'))
    return [me]


def _g4d3af0(c):
    clear_hooks(c)
    r = c.rng

    def side(em, k):
        if r.random() < 0.5:
            em.w32(em.arg32(3), r.getrandbits(32))
    hook_rec(c, 0x4d24e0, 4, this=True, ret=r.getrandbits(32), deref={2: 1}, side=side)
    return [rnd(c, 0x20), r.getrandbits(32), r.getrandbits(32)]


def _g59a7e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x597c40, 0, this=True, pop=0, ret=r.getrandbits(32))
    hook_rec(c, 0x597d30, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0x20), r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])]


def _g5de230(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5de090, 1, this=True, ret=r.getrandbits(32))
    w = r.getrandbits(16)
    c.emu.wbytes(0x7143a0, w.to_bytes(2, 'little'))
    a = w if r.random() < 0.5 else r.getrandbits(32)
    if r.random() < 0.4:
        a = (a & 0xffff) | (r.getrandbits(16) << 16)
    return [rnd(c, 0x20), a, r.getrandbits(32)]


def _g42ac96(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x42ac71, 4, pop=0, ret=r.getrandbits(32), deref={3: 3})
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4e49d0, 'GUESS forward with member pointer', 'thiscall', None, ret='eax', gen=_g4e49d0, note='batch34102')
S(0x5d3480, 'GUESS call when word matches', 'thiscall', None, ret='eax', gen=_g5d3480, note='batch34102')
S(0x4681d0, 'GUESS release member and clear', 'thiscall', None, ret=None, gen=_g4681d0, note='batch34102')
S(0x4d3af0, 'GUESS forward with constants and slot address', 'thiscall', None, ret='eax', gen=_g4d3af0, note='batch34102')
S(0x59a7e0, 'GUESS pick one of two calls', 'thiscall', None, ret='eax', gen=_g59a7e0, note='batch34102')
S(0x5de230, 'GUESS call when global word matches', 'thiscall', None, ret='eax', gen=_g5de230, note='batch34102')
S(0x42ac96, 'GUESS varargs forwarder', 'cdecl', None, ret='eax', gen=_g42ac96, note='batch34102')
