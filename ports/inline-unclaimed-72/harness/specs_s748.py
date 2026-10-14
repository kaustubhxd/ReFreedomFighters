"""specs_s748.py - area 72 gap list round 2. One spec per address; virtual calls get a logging stub on the vtable slot."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk

def _self(c, e, slots=None):
    s = _rnd(c, 0x800)
    if slots:
        e.w32(s, e.fake_vtable("obj", 0x100, slots))
    return s

def _g_4d23c0(c):
    return [_self(c, c.emu)]

def _g_4d5570(c):
    return [_self(c, c.emu)]

def _g_5422a0(c):
    return [_self(c, c.emu)]

def _g_54cd00(c):
    return [_self(c, c.emu)]

def _g_5ab4b0(c):
    return [_self(c, c.emu)]

def _g_4f22b0(c):
    return [_self(c, c.emu)]

def _g_4f4cb0(c):
    return [_self(c, c.emu)]

def _g_4f4d20(c):
    return [_self(c, c.emu)]

def _g_4f9f40(c):
    return [_self(c, c.emu)]

def _g_5333e0(c):
    return [_self(c, c.emu)]

def _g_5334f0(c):
    return [_self(c, c.emu)]

def _g_54ba10(c):
    return [_self(c, c.emu)]

def _g_59b3b0(c):
    return [_self(c, c.emu)]

def _g_59c610(c):
    return [_self(c, c.emu)]

def _g_59ca40(c):
    return [_self(c, c.emu)]

def _g_4f4cc0(c):
    return [_self(c, c.emu)]

def _g_54df90(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    def stub(em, r):
        log('vobj', 0x24, tuple(em.arg32(k) for k in range(0)))
        em.ret(eax=1, argbytes=0)
    return [_self(c, e, {0x24: stub})]

def _g_54e080(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    def stub(em, r):
        log('vobj', 0x2c, tuple(em.arg32(k) for k in range(1)))
        em.ret(eax=1, argbytes=4)
    return [_self(c, e, {0x2c: stub})]

def _g_4ce510(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    def stub(em, r):
        log('vobj', 0x8, tuple(em.arg32(k) for k in range(1)))
        em.ret(eax=1, argbytes=4)
    return [_self(c, e, {0x8: stub})]

S(0x4d23c0, 'vt_696168', 'thiscall', None, ret=None, gen=_g_4d23c0, note='b748/749 area 72 gap list round 2')
S(0x4d5570, 'vt_6967bc', 'thiscall', None, ret=None, gen=_g_4d5570, note='b748/749 area 72 gap list round 2')
S(0x5422a0, 'vt_6a2e08', 'thiscall', None, ret=None, gen=_g_5422a0, note='b748/749 area 72 gap list round 2')
S(0x54cd00, 'vt_6a3e14', 'thiscall', None, ret=None, gen=_g_54cd00, note='b748/749 area 72 gap list round 2')
S(0x5ab4b0, 'vt_6b01dc', 'thiscall', None, ret=None, gen=_g_5ab4b0, note='b748/749 area 72 gap list round 2')
S(0x4f22b0, 'u32_1db', 'thiscall', None, ret='eax', gen=_g_4f22b0, note='b748/749 area 72 gap list round 2')
S(0x4f4cb0, 'u32_8b', 'thiscall', None, ret='eax', gen=_g_4f4cb0, note='b748/749 area 72 gap list round 2')
S(0x4f4d20, 'u8_88', 'thiscall', None, ret='al', gen=_g_4f4d20, note='b748/749 area 72 gap list round 2')
S(0x4f9f40, 'u32_8f', 'thiscall', None, ret='eax', gen=_g_4f9f40, note='b748/749 area 72 gap list round 2')
S(0x5333e0, 'u32_546e', 'thiscall', None, ret='eax', gen=_g_5333e0, note='b748/749 area 72 gap list round 2')
S(0x5334f0, 'u32_548a', 'thiscall', None, ret='eax', gen=_g_5334f0, note='b748/749 area 72 gap list round 2')
S(0x54ba10, 'u8_a273', 'thiscall', None, ret='al', gen=_g_54ba10, note='b748/749 area 72 gap list round 2')
S(0x59b3b0, 'ptr_121b0', 'thiscall', None, ret='eax', gen=_g_59b3b0, note='b748/749 area 72 gap list round 2')
S(0x59c610, 'ptr_12108', 'thiscall', None, ret='eax', gen=_g_59c610, note='b748/749 area 72 gap list round 2')
S(0x59ca40, 'ptr_1210c', 'thiscall', None, ret='eax', gen=_g_59ca40, note='b748/749 area 72 gap list round 2')
S(0x4f4cc0, 'bit4_70', 'thiscall', None, ret='al', gen=_g_4f4cc0, note='b748/749 area 72 gap list round 2')
S(0x54df90, 'vc24_true', 'thiscall', None, ret='al', gen=_g_54df90, note='b748/749 area 72 gap list round 2')
S(0x54e080, 'vc2c_zero', 'thiscall', None, ret=None, gen=_g_54e080, note='b748/749 area 72 gap list round 2')
S(0x4ce510, 'vc8_zero', 'thiscall', None, ret=None, gen=_g_4ce510, note='b748/749 area 72 gap list round 2')
