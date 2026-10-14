"""specs_s35162.py - 0x4d7ba0 (thiscall, no args, ret=None). this: 0x80 random bytes with unaligned [+0x15] = writer object and [+0x11] random; writer slot 0x18 (3 args recorded; arg 0 recorded as the dword it points to; per call returns the requested size n, or n - 1 / 0 / random in a quarter of the calls)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4d7ba0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sizes = [4, 0x12, 4, 0x12]
    rets = [n if r.random() < 0.75 else r.choice([n - 1, 0, r.getrandbits(32), n + 1]) for n in sizes]
    w = obj(c, 0x20, {0x18: pystub(c, 3, this=True, deref={0: 1}, ret=lambda em, k: rets[min(k, 3)])}, nslots=0x10)
    me = rnd(c, 0x80)
    e.wbytes(me + 0x15, w.to_bytes(4, 'little'))
    e.wbytes(me + 0x11, r.getrandbits(32).to_bytes(4, 'little'))
    return [me]


S(0x4d7ba0, 'GUESS write header magics and records with short-write flag', 'thiscall', None, ret=None, gen=_g4d7ba0, note='batch35162')
