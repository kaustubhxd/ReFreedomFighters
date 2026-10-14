"""specs_s34011.py - cascade escalation batch 34011: 0x5398d0 (store v at this+idx*9+0x515e, idx 0..40, block filled with random bytes) and 0x593fd0
(bit 0x400 of the dword at +0x417 set -> return 0, else tail jump to 0x4670b0, hooked as a recorder with one popped argument)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5398d0(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x5400), r.choice([0, 1, 2, 3, 7, 40, r.randint(0, 40)]), r.getrandbits(32)]


def _g593fd0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4670b0, 1, ret=r.getrandbits(32), this=True)
    me = rnd(c, 0x500)
    w = r.getrandbits(32)
    w = (w | 0x400) if r.random() < 0.5 else (w & ~0x400)
    c.emu.wbytes(me + 0x417, w.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x5398d0, 'GUESS indexed store idx*9+0x515e', 'thiscall', None, ret=None, gen=_g5398d0, note='batch34011')
S(0x593fd0, 'GUESS flag 0x400 gate, tail 0x4670b0', 'thiscall', None, ret='eax', gen=_g593fd0, note='batch34011')
