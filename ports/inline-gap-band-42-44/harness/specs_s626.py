"""specs_s626.py - band 0x421000-0x441000, batch 626 (see src/batch626.cpp). Member objects are fake objects; their slots are
recorded with (name, slot, ecx, args). Slot 0x1c answers from a sequence fixed per run (the loop repeats on the two HRESULT
codes 0x8007001e and 0x8007000c and stops on any other value).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _rec(name, off, nargs, ret):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), tuple(e.arg32(k) for k in range(nargs))))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _member(c, name, slots):
    return c.emu.fake_object(name, 0x40, nslots=0x40, slots=slots)


def _gen_release(off):
    def gen(c):
        r = c.rng
        self_ = c.emu.alloc(0x200, 16)
        c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
        mem = _member(c, 'rel', {0x20: _rec('rel.20', 0x20, 1, 0), 8: _rec('rel.8', 8, 1, 0)}) \
            if r.random() < 0.8 else 0
        c.emu.w32(self_ + off, mem)
        return [self_]
    return gen


def _gen_retry(off):
    def gen(c):
        r = c.rng
        self_ = c.emu.alloc(0x200, 16)
        c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
        seq = [r.choice((0x8007001e, 0x8007000c, 0x12, 0)) for _ in range(6)]
        state = {'i': 0}

        def h1c(e, rr):
            e.calllog.append(('mem.1c', 0x1c, e.reg('ecx'), (e.arg32(0),)))
            v = seq[state['i']] if state['i'] < len(seq) else 0x12
            state['i'] += 1
            e.ret(eax=v, argbytes=4)
        mem = _member(c, 'retry', {0x1c: h1c}) if r.random() < 0.8 else 0
        c.emu.w32(self_ + off, mem)
        return [self_]
    return gen


S(0x429a50, 'release member +0x71 (slot 0x20, slot 8), return 1', 'thiscall', None, ret='al', gen=_gen_release(0x71))
S(0x429a80, 'release member +0xd (slot 0x20, slot 8), return 1', 'thiscall', None, ret='al', gen=_gen_release(0xd))
S(0x428830, 'retry slot 0x1c of member +0xd via its vtable; byte +0x1b1 = 1', 'thiscall', None, ret='al', gen=_gen_retry(0xd))
S(0x4288c0, 'retry slot 0x1c of member +0xd via its vtable; byte +0x45 = 1', 'thiscall', None, ret='al', gen=_gen_retry(0xd))
