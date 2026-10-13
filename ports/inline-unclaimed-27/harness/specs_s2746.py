"""specs_s2745.py - unclaimed-27 batch 48: CareTaker function 0x5bbfe0 (GUESS name). thiscall, one stack arg, ret 4.
HOOKED (stubs, NOT verified): 0x4e5e60 returns a chosen eax per case; the global 0x70039c points at a fake object whose
+0x9b member is g9 (vtable slots 0x138 -> res1, 0x4c). res1's vtable slot 0x60. Stubs record this and args into rec."""
from pilot import S
import struct


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _rec2(rec, off, retval):
    # records ecx at rec+off, stack args 0/1 at rec+off+4/+8, returns retval (eax), ret 8
    p = lambda v: struct.pack('<I', v)
    return (b'\x89\x0d' + p(rec + off) + b'\x8b\x44\x24\x04\xa3' + p(rec + off + 4) +
            b'\x8b\x44\x24\x08\xa3' + p(rec + off + 8) + b'\xb8' + p(retval) + b'\xc2\x08\x00')


def _gen(c):
    rec = c.emu.alloc(0x40, 4)
    seq = [c.rng.getrandbits(32) for _ in range(3)]
    idx = [0]

    def h4e(e, r, rec=rec, seq=seq, idx=idx):
        e.w32(rec + 0x30, (e.r32(rec + 0x30) + 1) & 0xffffffff)
        e.w32(rec + 0x34, e.reg('ecx'))
        v = seq[idx[0] % 3]
        idx[0] += 1
        e.ret(eax=v, argbytes=0)

    c.emu.hook(0x4e5e60, h4e)
    res1_vt = _rnd(c, 0x800)
    res1 = _rnd(c, 0x40)
    c.emu.w32(res1, res1_vt)
    c.emu.w32(res1_vt + 0x60, _stub(c, _rec2(rec, 0x10, c.rng.getrandbits(32))))
    g9_vt = _rnd(c, 0x800)
    g9 = _rnd(c, 0x40)
    c.emu.w32(g9, g9_vt)
    c.emu.w32(g9_vt + 0x138, _stub(c, b'\xb8' + struct.pack('<I', res1) + b'\xc3'))
    c.emu.w32(g9_vt + 0x4c, _stub(c, _rec2(rec, 0x0, c.rng.getrandbits(32))))
    g = _rnd(c, 0x400)
    c.emu.wbytes(g + 0x9b, struct.pack('<I', g9))
    c.emu.w32(0x70039c, g)
    obj = _rnd(c, 0x200)
    arg = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [obj, arg]


S(0x5bbfe0, 'CareTaker::CareTaker5bbfe0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-27 batch 48; 0x4e5e60 and the vtable calls on the 0x70039c object are hooks (stubs)')
