"""specs_s225.py - unclaimed area 22, batch225 (src/batch225.cpp): 0x5bd750, a DBREAD reader.

DBREAD::operator unsigned int (0x4e5e60) and operator unsigned short (0x4e5e40) are stubbed with a three-value
sequence stub. Each call stores its ecx (the DBREAD object) in a heap table, so a wrong object shows in the compare.
Both stubs keep the eax result, so the high bits of eax (the port keeps only the low word for the u16 reads) are
random and checked.
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, jmp_patch


def _seq_stub(c, vals):
    """Returns vals[i] on call i (wraps after three) and stores ecx in ecx_tab[i] (one slot per call), so the object
    passed to each read is compared. Thiscall, no stack args."""
    ecx_tab = c.emu.alloc(12, 4)
    idx = c.emu.alloc(4, 4)
    tab = c.emu.alloc(12, 4)
    c.emu.wbytes(ecx_tab, bytes(12))
    c.emu.w32(idx, 0)
    for i, v in enumerate(vals[:3]):
        c.emu.w32(tab + 4 * i, v)
    code = (b'\xa1' + ss.P(idx)                  # mov eax, [idx]
            + b'\x89\x0c\x85' + ss.P(ecx_tab)   # mov [ecx_tab + eax*4], ecx
            + b'\x8b\x14\x85' + ss.P(tab)       # mov edx, [tab + eax*4]
            + b'\x40'                            # inc eax
            + b'\x83\xf8\x03'                    # cmp eax, 3
            + b'\x7c\x02'                         # jl +2
            + b'\x31\xc0'                         # xor eax, eax
            + b'\xa3' + ss.P(idx)                 # mov [idx], eax
            + b'\x89\xd0'                         # mov eax, edx
            + b'\xc3')                            # ret
    return ss.code(c, code)


def _g_5bd750(c):
    self_ = _rnd(c, 0x100)
    d = _rnd(c, 0x40)
    u32s = [c.rng.getrandbits(32) for _ in range(3)]
    u16s = [c.rng.getrandbits(32) for _ in range(3)]   # the full eax: only ax is used
    if c.rng.random() < 0.3:
        u32s[1] = 0                                     # the flag read is zero sometimes
    jmp_patch(c, 0x4e5e60, _seq_stub(c, u32s))
    jmp_patch(c, 0x4e5e40, _seq_stub(c, u16s))
    _flush_heap_code(c)
    return [self_, d]


S(0x5bd750, 'readBitsDB (GUESS)', 'thiscall', None, ret=None, gen=_g_5bd750,
  note='batch225; DBREAD u32/u16 reads (stubbed sequences), bit set at esi mod 32')
