"""specs_s2424.py - decomp area 24, batch 2424: three small leaves.
0x4dffb0 v2scalar(float*, float): the two floats at the pointer are multiplied by the argument (thiscall, ret 4).
0x4cc4b0 (unnamed): equality of two bytes after folding 'A'..'Z' to lower case (fastcall, eax = 0 or 1; only the low
bytes of the two arguments matter).
0x4bcd30 ZSoundVolumetricSource::Load(ZLoadGame*): clears flag 0x40, copies the dword at (this+0x44)+0x18 -> +8 into
+0xa8 and clears the dword at (that object)+0x84. Returns AL = 1 (thiscall, ret 4)."""
from pilot import S, F
from recruits_util import rnd, clear_hooks


def _v2(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    return [o, F(r.uniform(-4.0, 4.0))]


def _ch(c):
    clear_hooks(c)
    r = c.rng
    pool = [0x41, 0x5a, 0x61, 0x7a, 0x40, 0x5b, 0x60, 0x7b, 0x20]
    a = r.choice(pool) if r.random() < 0.6 else r.getrandbits(8)
    b = r.choice(pool) if r.random() < 0.6 else r.getrandbits(8)
    if r.random() < 0.3:
        b = (a ^ 0x20) & 0xff
    return [a, b]


def _load(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x100)
    o2 = rnd(c, 0x40)
    o3 = rnd(c, 0x100)
    e.w32(self_ + 0x44, o2)
    e.w32(o2 + 0x18, o3)
    return [self_]


S(0x4dffb0, 'v2scalar', 'thiscall', None, ret=None, gen=_v2, note='batch2424')
S(0x4cc4b0, 'GUESS: case-folded byte equality (0x4cc4b0)', 'fastcall', None, ret='al', gen=_ch, note='batch2424')
S(0x4bcd30, 'ZSoundVolumetricSource::Load', 'thiscall', None, ret='al', gen=_load, note='batch2424')
