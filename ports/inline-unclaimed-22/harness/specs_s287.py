"""specs_s287.py - area 22, batch287 (src/batch287.cpp): ten small residue-1 functions. Callees 0x5fa630, 0x6054b0
(GUESS), 0x5630f0 and 0x565100 (GUESS) are hooked by address and log their registers and arguments; vtable slots are
Python vtables that log ecx and the argument."""
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


S(0x60db10, 'ZRenderGC::GetRenderName', 'thiscall', 0, ret='u32', gen=lambda c: [_rnd(c, 8)], note='batch287')
S(0x500a10, 'vtable set 0x69c968', 'thiscall', 0, ret=None, gen=lambda c: [_rnd(c, 8)], note='batch287; void')
S(0x563610, 'set +0x58', 'thiscall', 1, ret=None, gen=lambda c: [_rnd(c, 0x60), _r(c)], note='batch287; void')


def _g_5f5510(c):
    e = c.emu
    o = _rnd(c, 8)

    def slot(em, r):
        em.calllog.append(('vt50', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=_r(c), argbytes=4)
    e.w32(o, _pyvt(c, {0x50: slot}))

    def get(em, r):
        em.calllog.append(('5fa630', 0x5fa630, em.reg('ecx'), ()))
        em.ret(eax=o, argbytes=0)
    e.hook(0x5fa630, get)
    return [_rnd(c, 8), _r(c)]


S(0x5f5510, 'Process_t::recycle', 'thiscall', 1, ret='u32', gen=_g_5f5510, note='batch287; 0x5fa630 hooked')
S(0x605b90, 'size +0x10 + 4*[+8] - [+0xc] + 9', 'thiscall', 0, ret='u32', gen=lambda c: [_rnd(c, 0x14)],
  note='batch287')


def _g_605550(c):
    def f(em, r):
        em.calllog.append(('6054b0', 0x6054b0, None, (em.reg('ecx'), em.reg('edx'))))
        em.ret(eax=_r(c), argbytes=0)
    c.emu.hook(0x6054b0, f)
    return [_r(c), _r(c), _r(c)]


S(0x605550, 'create via 0x6054b0', 'stdcall', 3, ret='u32', gen=_g_605550, note='batch287; 0x6054b0 hooked GUESS')


def _g_4dc110(c):
    e = c.emu
    s = _rnd(c, 0x58)
    k = c.rng.random()
    if k < 0.25:
        e.w32(s + 0x54, 0)
    else:
        o = _rnd(c, 8)
        e.w32(o + 4, 0 if k < 0.5 else _r(c))
        e.w32(s + 0x54, o)
    return [s]


S(0x4dc110, 'name or empty string', 'thiscall', 0, ret='u32', gen=_g_4dc110, note='batch287')


def _g_57bd50(c):
    e = c.emu

    def a(em, r):
        em.calllog.append(('5630f0', 0x5630f0, em.reg('ecx'), ()))
        em.ret(eax=_r(c), argbytes=0)

    def b(em, r):
        em.calllog.append(('565100', 0x565100, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=_r(c), argbytes=4)
    e.hook(0x5630f0, a)
    e.hook(0x565100, b)
    return [_rnd(c, 0xcc0)]


S(0x57bd50, 'ZFFLoadError::OnWindowOpen2', 'thiscall', 0, ret=None, gen=_g_57bd50,
  note='batch287; void; 0x5630f0 and 0x565100 hooked')
S(0x656950, 'copy +0x10/+0x14', 'stdcall', 2, ret='u32', gen=lambda c: [_rnd(c, 0x18), _rnd(c, 0x18)],
  note='batch287')


def _g_5f3210(c):
    e = c.emu
    o = _rnd(c, 8)

    def slot(em, r):
        em.calllog.append(('vt4c', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=_r(c), argbytes=4)
    e.w32(o, _pyvt(c, {0x4c: slot}))
    s = _rnd(c, 0x20)
    e.w32(s + 0x15, o)
    return [s, _r(c)]


S(0x5f3210, 'savefloat', 'thiscall', 1, ret='u32', gen=_g_5f3210, note='batch287; vt 0x4c Python vtable')
