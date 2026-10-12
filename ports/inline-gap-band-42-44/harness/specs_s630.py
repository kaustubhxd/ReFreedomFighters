"""specs_s630.py - band 0x421000-0x441000, batch 630 (see src/batch630.cpp).
0x4309b0 and 0x54f870 are exe code: hooked by address with recording stubs (the exe's stack convention: stdcall, the callee
pops). The span object is 12 bytes of begin / end / limit pointers, pointing into a heap buffer.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\x00')
    return a


def _gen_cmp(c):
    r = c.rng
    text = bytes(r.randint(0x21, 0x7e) for _ in range(r.randint(0, 20)))
    s = _cstr(c, text)
    buf = c.emu.alloc(0x40, 16)
    begin = buf
    end = buf + (len(text) if r.random() < 0.5 else r.randint(0, 30))
    span = c.emu.alloc(0x20, 16)
    c.emu.w32(span, begin)
    c.emu.w32(span + 4, end)
    c.emu.w32(span + 8, end + 4)

    return [span, s]


def _gen_rel(c):
    r = c.rng
    buf = c.emu.alloc(0x40, 16)
    span = c.emu.alloc(0x20, 16)
    kind = r.choice(('zero', 'empty', 'full'))
    if kind == 'zero':
        c.emu.w32(span, 0)
        c.emu.w32(span + 8, 0)
    elif kind == 'empty':
        c.emu.w32(span, buf)
        c.emu.w32(span + 8, buf)
    else:
        c.emu.w32(span, buf)
        c.emu.w32(span + 8, buf + r.randint(1, 30))
    return [span]


def _hook_54f870(c):
    def h(e, rr):
        e.calllog.append(('ext.54f870', 0x54f870, 0, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)
    c.emu.hook(0x54f870, h)


def _hook_4309b0(c, value):
    def h(e, rr):
        e.calllog.append(('ext.4309b0', 0x4309b0, 0, (e.arg32(0),)))
        e.ret(eax=value, argbytes=4)
    c.emu.hook(0x4309b0, h)


def _gen_cmp2(c):
    _hook_4309b0(c, c.rng.choice((0, 0, 1)))   # the exe's answer, fixed for this run (0 = equal)
    return _gen_cmp(c)


def _gen_rel2(c):
    _hook_54f870(c)
    return _gen_rel(c)


S(0x42adc0, 'span length compare, then ext 0x4309b0 (stdcall)', 'fastcall', None, ret='al', gen=_gen_cmp2)
S(0x42b9c0, 'release span via ext 0x54f870 (stdcall)', 'thiscall', None, ret=None, gen=_gen_rel2)
