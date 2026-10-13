"""specs_s80.py - inline session batch 80: ZShotActivate::Init (0x4c8df0) and ZFFSimpleTrain2::Command (0x5b8530).
Stop (0x5b9250) is patched per run with a recorder of ecx. The command word is compared low word only, so the high
half of the stack argument is random."""
import struct
from pilot import S
import specs_s53 as k53
import specs_s73 as k73

_rnd = k53._rnd
_ecx, _patch = k73._ecx, k73._patch


def _sa(c):
    s = _rnd(c, 0x80)
    c.emu.mu.ctl_flush_tb()
    return [s]


def _train(c):
    r = c.rng
    s = _rnd(c, 0x100)
    word = r.getrandbits(16)
    c.emu.wbytes(s + 0xdb, struct.pack('<H', word))
    cmd = word if r.random() < 0.5 else r.getrandbits(16)
    _patch(c, 0x5b9250, _ecx(c, 0))
    c.emu.mu.ctl_flush_tb()
    return [s, (cmd | (r.getrandbits(16) << 16)) & 0xffffffff, r.getrandbits(32)]


S(0x4c8df0, 'ZShotActivate::Init', 'thiscall', None, ret=None, gen=_sa, note='batch80')
S(0x5b8530, 'ZFFSimpleTrain2::Command', 'thiscall', None, ret='eax', gen=_train, note='batch80; Stop patched')
