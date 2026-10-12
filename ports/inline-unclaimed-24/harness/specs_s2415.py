"""specs_s2415.py - decomp area 24, batch 2415: small setters and one indexed getter.
0x4850b0 ZPlayer::SetSoundSet(u32): stores the argument at +0x60e (thiscall, void).
0x59cbb0 (GUESS owner, unnamed): stores the argument at +0x12104 (thiscall, void).
0x54ba30 (unnamed): stores the low byte of the argument at +0xa27c (thiscall, void).
0x443070 ZTreeGroup::GetGlobalTreePtr(eGlobalTreeType) const: the dword at this + 0x5d + 4*type (thiscall, eax).
The indexed getter's type is 0..7 (in range of the object); the setters take random values."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _set(off_size):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        o = rnd(c, off_size)
        return [o, r.getrandbits(32)]
    return gen


def _tree(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x100)
    return [o, r.randint(0, 7)]


S(0x4850b0, 'ZPlayer::SetSoundSet', 'thiscall', None, ret=None, gen=_set(0x700), note='batch2415')
S(0x59cbb0, 'GUESS: setter at +0x12104 (0x59cbb0)', 'thiscall', None, ret=None, gen=_set(0x12200), note='batch2415')
S(0x54ba30, 'GUESS: byte setter at +0xa27c (0x54ba30)', 'thiscall', None, ret=None, gen=_set(0xa300), note='batch2415')
S(0x443070, 'ZTreeGroup::GetGlobalTreePtr', 'thiscall', None, ret='eax', gen=_tree, note='batch2415')
