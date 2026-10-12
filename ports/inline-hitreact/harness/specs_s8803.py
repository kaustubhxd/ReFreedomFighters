"""specs_s8803.py - hitreact batch 8803: ZActorIf::DieByForce (0x506a80), the script native. 0x5003d0 runs as exe code; the
actor's slot 0x668 is a stub that records both vectors' contents, the strength bits and the killer."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from specs_s8802 import _argobj


def _die_stub(c):
    rec = c.emu.alloc(4 * 9, 4)
    code = b''
    for ai in (0, 1):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * ai])
        for j in range(3):
            code += b'\x8b\x50' + bytes([4 * j]) + b'\x89\x15' + struct.pack('<I', rec + 4 * (3 * ai + j))
    code += b'\x8b\x44\x24\x0c\xa3' + struct.pack('<I', rec + 24)
    code += b'\x8b\x44\x24\x10\xa3' + struct.pack('<I', rec + 28)
    code += b'\xff\x05' + struct.pack('<I', rec + 32)
    code += b'\xc2\x10\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _gen(c):
    r = c.rng
    emu = c.emu
    emu.w32(0x7003b0, stub(c, 0, cdecl=True))
    actor = obj(c, 0x700, {0x668: _die_stub(c)})
    self = rnd(c, 0x40)
    emu.w32(self + 0x18, actor)
    vals = [r.choice((r.uniform(-2000, 2000), 0.0, fedge(c))) for _ in range(7)]
    args = _argobj(c, vals + [0.0])
    base = emu.r32(emu.r32(args))
    emu.w32(base + 8 * 7, r.getrandbits(32))      # arg 7: the killer handle, a dword
    call = rnd(c, 16)
    emu.w32(call + 4, args)
    emu.mu.ctl_flush_tb()
    return [self, call]


S(0x506a80, 'ZActorIf::DieByForce', 'thiscall', ret=None, gen=_gen)
