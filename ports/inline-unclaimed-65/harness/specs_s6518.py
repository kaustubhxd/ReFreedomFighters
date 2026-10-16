"""specs_s6518.py - unclaimed-65 batch 18 (docs/20-unclaimed-65.md, claim 18, final): ZMovementBaseMove::GetActiveAnim. The _CIfmod thunk
0x634dc4 is the area 35 fprem stub (a model; the fmod semantics are a GUESS). The sqrt thunk 0x634d7c is the harness math handler.
0x43e920 and 0x441a60 are exe code. this's slot +0x44 logs its two float arguments and writes a per-case float into this+0xc."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402
from pilot import S   # noqa: E402


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fv(c):
    r = c.rng.random()
    if r < 0.2:
        return 0.0
    if r < 0.3:
        return -0.0
    return c.fv(-10.0, 10.0)


def _setup(c):
    ss.patch(c, 0x634dc4, ss.code(c, b'\xd9\xc9' + b'\xd9\xf8' + b'\xdf\xe0' + b'\xf6\xc4\x04' + b'\x75\xf7' + b'\xdd\xd9' + b'\xc3'))
    _flush_code(c)


def _gen(c):
    P = _rnd(c, 0x40)
    c.emu.wf32(P + 0xc, _fv(c))
    c.emu.wf32(P + 0x14, _fv(c))
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x21, 0 if c.rng.random() < 0.15 else P)
    c.emu.wf32(self_ + 0xc, _fv(c))
    fill = _fv(c)

    def s44(e, r):
        a = struct.unpack('<f', struct.pack('<I', e.arg32(0)))[0]
        b = struct.unpack('<f', struct.pack('<I', e.arg32(1)))[0]
        e.calllog.append(('this-44', e.reg('ecx') == self_, (round(a, 6) if a == a else 'nan', round(b, 6) if b == b else 'nan')))
        e.wf32(self_ + 0xc, fill)
        e.ret(eax=0, argbytes=8)
    vt = c.emu.fake_vtable('movebase', 0x50, {0x44: s44})
    c.emu.w32(self_, vt)
    out = _rnd(c, 0x10)
    a2 = _rnd(c, 0x20)
    a3 = _rnd(c, 0x20)
    a4 = _rnd(c, 0x20)
    for base in (a2, a3, a4):
        for i in range(3):
            c.emu.wf32(base + 4 * i, _fv(c))
    _flush_code(c)
    return [self_, out, c.rng.getrandbits(32), a2, a3, a4]


S(0x4884b0, 'ZMovementBaseMove::GetActiveAnim (unknown) thiscall', 'thiscall', None, ret='st0', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 18 (residue 15); x87 normalisation; sqrt thunk; fmod thunk stub (area 35 model); 43e920 out at E+0x1c')
