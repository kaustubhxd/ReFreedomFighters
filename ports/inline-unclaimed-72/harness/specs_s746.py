"""specs_s746.py - area 72 whole-exe gap list (trivial accessors / constants). One spec per address; args given where the
function pops stack arguments. Globals in .data are random dwords per case."""
import struct
from pilot import S
from specs_s701 import _rnd

def _gen_self(c):
    e = c.emu
    s = _rnd(c, 0x800)
    return s

def _gen_glob(c, addr):
    e = c.emu
    e.w32(addr, c.rng.getrandbits(32))

def _g_51ad70(c):
    return [_gen_self(c), c.rng.getrandbits(32), c.rng.getrandbits(32)]

def _g_51f230(c):
    return [_gen_self(c)]

def _g_4b00c0(c):
    return [_gen_self(c)]

def _g_4d4520(c):
    return [_gen_self(c)]

def _g_4d4530(c):
    return [_gen_self(c)]

def _g_4d6970(c):
    return [_gen_self(c)]

def _g_4f0030(c):
    return [_gen_self(c)]

def _g_4f22d0(c):
    return [_gen_self(c)]

def _g_54bbb0(c):
    return [_gen_self(c)]

def _g_54bc00(c):
    return [_gen_self(c)]

def _g_54bc10(c):
    return [_gen_self(c)]

def _g_54e1e0(c):
    return [_gen_self(c)]

def _g_5acff0(c):
    return [_gen_self(c)]

def _g_4d76f0(c):
    return [_gen_self(c)]

def _g_53cca0(c):
    return [_gen_self(c)] + [c.rng.getrandbits(32) for _ in range(6)]

def _g_4f1840(c):
    _gen_glob(c, 0x6e7ca8)
    return [_gen_self(c)]

def _g_4f1850(c):
    _gen_glob(c, 0x6e7cac)
    return [_gen_self(c)]

def _g_4f1870(c):
    _gen_glob(c, 0x6e7f8c)
    return [_gen_self(c)]

def _g_504550(c):
    return [_gen_self(c)]

def _g_50a430(c):
    return [_gen_self(c)]

def _g_50b5b0(c):
    return [_gen_self(c)]

def _g_510ec0(c):
    return [_gen_self(c)]

def _g_51ff30(c):
    return [_gen_self(c)]

def _g_54bb80(c):
    return [_gen_self(c)]

def _g_5578c0(c):
    return [_gen_self(c)]

def _g_560370(c):
    return [_gen_self(c)]

def _g_5b2510(c):
    _gen_glob(c, 0x6ed354)
    return [_gen_self(c)]

def _g_5b2530(c):
    _gen_glob(c, 0x6edacc)
    return [_gen_self(c)]

def _g_5b2540(c):
    _gen_glob(c, 0x6ee240)
    return [_gen_self(c)]

def _g_4d0580(c):
    return [_gen_self(c)]

S(0x51ad70, 'stub_ret8', 'thiscall', None, ret=None, gen=_g_51ad70, note='b746/747 area 72 gap list')
S(0x51f230, 'zero0', 'thiscall', None, ret='eax', gen=_g_51f230, note='b746/747 area 72 gap list')
S(0x4b00c0, 'u32_48', 'thiscall', None, ret='eax', gen=_g_4b00c0, note='b746/747 area 72 gap list')
S(0x4d4520, 'f32_7', 'thiscall', None, ret='st0', gen=_g_4d4520, note='b746/747 area 72 gap list')
S(0x4d4530, 'u8_6', 'thiscall', None, ret='al', gen=_g_4d4530, note='b746/747 area 72 gap list')
S(0x4d6970, 'u8_6e', 'thiscall', None, ret='al', gen=_g_4d6970, note='b746/747 area 72 gap list')
S(0x4f0030, 'ptr_3e', 'thiscall', None, ret='eax', gen=_g_4f0030, note='b746/747 area 72 gap list')
S(0x4f22d0, 'u32_73', 'thiscall', None, ret='eax', gen=_g_4f22d0, note='b746/747 area 72 gap list')
S(0x54bbb0, 'ptr_14', 'thiscall', None, ret='eax', gen=_g_54bbb0, note='b746/747 area 72 gap list')
S(0x54bc00, 'ptr_38', 'thiscall', None, ret='eax', gen=_g_54bc00, note='b746/747 area 72 gap list')
S(0x54bc10, 'ptr_20', 'thiscall', None, ret='eax', gen=_g_54bc10, note='b746/747 area 72 gap list')
S(0x54e1e0, 'u8_59', 'thiscall', None, ret='al', gen=_g_54e1e0, note='b746/747 area 72 gap list')
S(0x5acff0, 'ptr_48', 'thiscall', None, ret='eax', gen=_g_5acff0, note='b746/747 area 72 gap list')
S(0x4d76f0, 'clr_21', 'thiscall', None, ret=None, gen=_g_4d76f0, note='b746/747 area 72 gap list')
S(0x53cca0, 'true6', 'thiscall', None, ret='al', gen=_g_53cca0, note='b746/747 area 72 gap list')
S(0x4f1840, 'glob_6e7ca8', 'thiscall', None, ret='eax', gen=_g_4f1840, note='b746/747 area 72 gap list')
S(0x4f1850, 'glob_6e7cac', 'thiscall', None, ret='eax', gen=_g_4f1850, note='b746/747 area 72 gap list')
S(0x4f1870, 'glob_6e7f8c', 'thiscall', None, ret='eax', gen=_g_4f1870, note='b746/747 area 72 gap list')
S(0x504550, 'cstr_685230', 'thiscall', None, ret='eax', gen=_g_504550, note='b746/747 area 72 gap list')
S(0x50a430, 'cstr_69c768', 'thiscall', None, ret='eax', gen=_g_50a430, note='b746/747 area 72 gap list')
S(0x50b5b0, 'cstr_69c770', 'thiscall', None, ret='eax', gen=_g_50b5b0, note='b746/747 area 72 gap list')
S(0x510ec0, 'cstr_69c784', 'thiscall', None, ret='eax', gen=_g_510ec0, note='b746/747 area 72 gap list')
S(0x51ff30, 'cstr_6a003c', 'thiscall', None, ret='eax', gen=_g_51ff30, note='b746/747 area 72 gap list')
S(0x54bb80, 'cstr_713d30', 'thiscall', None, ret='eax', gen=_g_54bb80, note='b746/747 area 72 gap list')
S(0x5578c0, 'cstr_6a4b68', 'thiscall', None, ret='eax', gen=_g_5578c0, note='b746/747 area 72 gap list')
S(0x560370, 'cstr_6a4b8c', 'thiscall', None, ret='eax', gen=_g_560370, note='b746/747 area 72 gap list')
S(0x5b2510, 'glob_6ed354', 'thiscall', None, ret='eax', gen=_g_5b2510, note='b746/747 area 72 gap list')
S(0x5b2530, 'glob_6edacc', 'thiscall', None, ret='eax', gen=_g_5b2530, note='b746/747 area 72 gap list')
S(0x5b2540, 'glob_6ee240', 'thiscall', None, ret='eax', gen=_g_5b2540, note='b746/747 area 72 gap list')
S(0x4d0580, 'u32_213', 'thiscall', None, ret='eax', gen=_g_4d0580, note='b746/747 area 72 gap list')
