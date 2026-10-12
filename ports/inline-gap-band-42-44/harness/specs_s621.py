"""specs_s621.py - band 0x421000-0x441000, batch 621: 0x4cc1e0 (concat helper) and 0x42fa90 (ScenesPath).
The MYSTR objects are 0x40-byte blocks whose first word is a char * (short heap strings, under 40 characters so the
long-string allocation path is not reached). The exe's assign (0x4cc630) and concat step (0x4cc2c0) run natively; the
free (0x634273) is hooked by address and recorded (cdecl, the caller pops).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402

FREE = 0x634273


def _cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\x00')
    return a


def _rand_text(c, lo, hi):
    r = c.rng
    return bytes(r.randint(0x21, 0x7e) for _ in range(r.randint(lo, hi)))


def _hook_free(c):
    def h(e, rr):
        e.calllog.append(('free', FREE, 0, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)   # cdecl: the caller pops
    c.emu.hook(FREE, h)


def _mystr(c, text):
    obj = c.emu.alloc(0x40, 16)
    c.emu.wbytes(obj, b'\x00' * 0x40)
    if text is not None:
        c.emu.w32(obj, _cstr(c, text))
    return obj


def _gen_concat(c):
    r = c.rng
    _hook_free(c)
    first = _mystr(c, _rand_text(c, 0, 30) if r.random() < 0.85 else None)
    # the second string always holds a valid char * (possibly empty): a null char * there reads uninitialised stack in the exe
    second = first if r.random() < 0.15 else _mystr(c, _rand_text(c, 0, 30))
    out = _mystr(c, None)
    return [first, out, second]


def _gen_scenes(c):
    r = c.rng
    _hook_free(c)
    self_ = c.emu.alloc(0x400, 16)
    c.emu.wbytes(self_, b'\x00' * 0x400)
    c.emu.w32(self_ + 0x123, _cstr(c, _rand_text(c, 0, 30)) if r.random() < 0.9 else 0)
    # the second string is always a valid (possibly empty) char *: a null one is outside the contract (see docs/20-gap-band-42-44.md)
    c.emu.w32(self_ + 0x1a3, _cstr(c, _rand_text(c, 0, 30)))
    dest = _mystr(c, None)
    return [self_, dest]


S(0x4cc1e0, 'string concat helper (first, out, second)', 'thiscall', None, ret='eax', gen=_gen_concat)
S(0x42fa90, 'ZSysInterface::ScenesPath(dest)', 'thiscall', None, ret='eax', gen=_gen_scenes)
