"""specs_s614.py - damage batch 614: ZKillBox FrameUpdate/Command (Kill and RemoveWeapons patched to stubs),
the close-combat info test 0x5a0ad0, ZFFActor::SetHPMultiplierForHeadShot (SetDamageMultForBone runs real)."""
import struct
from pilot import S
from wkit import rnd, stub, fedge
from dkit import patch_jmp


def _kb(c):
    r = c.rng
    patch_jmp(c, 0x5b1ce0, stub(c, 0))
    patch_jmp(c, 0x5b1f80, stub(c, 0))
    kb = rnd(c, 0x100)
    c.emu.w8(kb + 0x82, r.getrandbits(1))
    return kb


def _cmd(c):
    r = c.rng
    kb = _kb(c)
    own = r.getrandbits(16)
    off = r.getrandbits(16)
    c.emu.wbytes(kb + 0x48, struct.pack('<H', own))
    c.emu.wbytes(0x714304, struct.pack('<H', off))
    return [kb, r.choice((own, off, own, off, r.getrandbits(16))) | (r.getrandbits(16) << 16), r.getrandbits(32)]


def _info(c):
    a = rnd(c, 0x30)
    c.emu.w32(a + 8, c.rng.choice((0, 1, 2, 3, 4, 5, 6, 0xffffffff)))
    return [a]


def _hs(c):
    a = rnd(c, 0x500)
    return [a, struct.unpack('<I', struct.pack('<f', fedge(c)))[0]]


S(0x5b1c90, 'ZKillBox::FrameUpdate', 'thiscall', ret=None, gen=lambda c: [_kb(c)])
S(0x5b1b30, 'ZKillBox::Command', 'thiscall', ret='eax', gen=_cmd)
S(0x5a0ad0, 'SDamageInfo close-combat test', 'thiscall', ret='al', gen=_info)
S(0x5a2d20, 'ZFFActor::SetHPMultiplierForHeadShot', 'thiscall', ret=None, gen=_hs)
