"""specs_s3522.py - area 35 claim 22 (docs/20-unclaimed-35.md): 0x5dcea0, ZFFFlak::ReadInput(DBREAD&) (residue name).

Stubbed: 0x4e5e60 (int reader: three values in sequence, logs ecx), 0x4e5e80 (float reader: two finite floats, returns st0,
logs ecx), 0x4e5ea0 (string reader: four heap strings in sequence, logs ecx), 0x41e290 (cdecl alloc: logs its size and returns
one of four per-case buffers in sequence). The reader object is a heap object (only its address is passed through)."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _seq(c, tab, kind):
    """Reader stub: logs ecx, returns tab[cnt] (kind 'u32' or 'ptr': eax; 'f32': st0), cnt += 1."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in tab))
    cells = c.emu.alloc(4, 4)
    c.emu.wbytes(cells, bytes(4))
    code = b'\x89\x0d' + ss.P(cells)                                 # mov [cells], ecx
    code += b'\xa1' + ss.P(cnt)                                      # mov eax, [cnt]
    if kind == 'f32':
        code += b'\xd9\x04\x85' + ss.P(tb)                           # fld dword [tb + eax*4]
    else:
        code += b'\x8b\x04\x85' + ss.P(tb)                           # mov eax, [tb + eax*4]
    code += b'\xff\x05' + ss.P(cnt) + b'\xc3'                        # inc dword [cnt]; ret
    return ss.code(c, code)


def _alloc_stub(c, bufs):
    """cdecl alloc: logs its size argument, returns bufs[cnt] (eax), cnt += 1."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(bufs), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in bufs))
    cells = c.emu.alloc(4, 4)
    c.emu.wbytes(cells, bytes(4))
    code = b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)               # mov eax, [esp+4]; mov [cells], eax
    code += b'\xa1' + ss.P(cnt) + b'\x8b\x04\x85' + ss.P(tb)         # mov eax, [cnt]; mov eax, [tb + eax*4]
    code += b'\xff\x05' + ss.P(cnt) + b'\xc3'                        # inc dword [cnt]; ret
    return ss.code(c, code)


def _flak(c):
    self_obj = _rnd(c, 0x200)
    R = _rnd(c, 0x100)
    ints = [c.rng.getrandbits(32) for _ in range(3)]
    floats = [struct.unpack('<I', struct.pack('<f', c.rng.uniform(-1000.0, 1000.0)))[0] for _ in range(2)]
    strs = []
    for _ in range(4):
        n = c.rng.randrange(0, 25)
        b = bytes(c.rng.randrange(65, 123) for _ in range(n)) + b'\x00'
        p = c.emu.alloc(len(b), 4)
        c.emu.wbytes(p, b)
        strs.append(p)
    bufs = [_rnd(c, 0x40) for _ in range(4)]
    ss.patch(c, 0x4e5e60, _seq(c, ints, 'u32'))
    ss.patch(c, 0x4e5e80, _seq(c, floats, 'f32'))
    ss.patch(c, 0x4e5ea0, _seq(c, strs, 'ptr'))
    ss.patch(c, 0x41e290, _alloc_stub(c, bufs))
    return [self_obj, R]


S(0x5dcea0, 'ZFFFlak::ReadInput(DBREAD&) (residue name) thiscall', 'thiscall', None, ret=None, gen=_flak,
  note='area 35 claim 22; readers and 0x41e290 stubbed (logged); string buffers per case')
