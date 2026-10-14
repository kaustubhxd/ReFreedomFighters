"""specs_s34010.py - cascade escalation batch 34010: 0x48f460 (engine +0x1a9f object, slot 0x94, null in half the cases), 0x512f80 (engine +0x1a9f
zero/non-zero selects [this+0x12f] or 0; the dword is unaligned), 0x537090 (dword at this+idx*9+0x515e, idx 0..40) and 0x4646f0 (two-argument setter)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g48f460(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    o = 0 if r.random() < 0.5 else obj(c, 0x40, {0x94: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    c.emu.wbytes(so + 0x1a9f, o.to_bytes(4, 'little'))
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def _g512f80(c):
    clear_hooks(c)
    r = c.rng
    so = sysobj(c)
    v = 0 if r.random() < 0.5 else (r.getrandbits(32) or 1)
    c.emu.wbytes(so + 0x1a9f, v.to_bytes(4, 'little'))
    return [rnd(c, 0x200)]


def _g537090(c):
    clear_hooks(c)
    return [rnd(c, 0x5400), c.rng.choice([0, 1, 2, 3, 7, 40, c.rng.randint(0, 40)])]


def _g4646f0(c):
    clear_hooks(c)
    return [rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x48f460, 'GUESS engine +0x1a9f slot 0x94 forward', 'thiscall', None, ret='eax', gen=_g48f460, note='batch34010')
S(0x512f80, 'GUESS engine-gated read +0x12f', 'thiscall', None, ret='eax', gen=_g512f80, note='batch34010')
S(0x537090, 'GUESS indexed read idx*9+0x515e', 'thiscall', None, ret='eax', gen=_g537090, note='batch34010')
S(0x4646f0, 'GUESS set +0x68 = b, +0x60 = a', 'thiscall', None, ret=None, gen=_g4646f0, note='batch34010')
