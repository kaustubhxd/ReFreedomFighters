"""specs_s1001.py - unclaimed-02 batch 1 (docs/20-unclaimed-02.md): ZBombDamageList::Command (0x5dbe30) and
ZFFFlak::Command (0x5dc880). The command word is compared against a global word the gen writes (0x714384 for the bomb
list, 0x714394 for the flak), so about half the cases take the store path. Output cells and objects are random heap
bytes so every store lands inside memory the harness compares."""
import struct
from pilot import S


def _cmd(c, glob):
    v = c.rng.getrandbits(16)
    c.emu.w16(glob, v)
    # half the cases match the global word on the low 16 bits; the high half is random (ax is compared only)
    lo = v if c.rng.random() < 0.5 else c.rng.getrandbits(16)
    return lo | (c.rng.getrandbits(16) << 16)


def _obj(c):
    a = c.emu.alloc(0x800, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return a


def _bomb(c):
    self_ = _obj(c)
    cmd = _cmd(c, 0x714384)
    out = c.emu.alloc(8, 4)
    c.emu.w32(out, c.rng.getrandbits(32))
    c.emu.w32(out + 4, c.rng.getrandbits(32))
    if c.rng.random() < 0.1:
        out = c.rng.choice([0, 0x1234])      # null or wild out pointer: both sides must fault alike
    return [self_, cmd, out]


def _flak(c):
    self_ = _obj(c)
    cmd = _cmd(c, 0x714394)
    return [self_, cmd, c.rng.getrandbits(32)]


S(0x5dbe30, 'ZBombDamageList::Command(unsigned short, void*) thiscall', 'thiscall', None, ret='eax', gen=_bomb,
  note='unclaimed-02 batch 1; stores this through arg2 when (u16)arg1 == word at 0x714384, returns 0')
S(0x5dc880, 'ZFFFlak::Command(unsigned short, void*) thiscall', 'thiscall', None, ret='eax', gen=_flak,
  note='unclaimed-02 batch 1; stores arg2 at this+0x58 when (u16)arg1 == word at 0x714394, returns 0')
