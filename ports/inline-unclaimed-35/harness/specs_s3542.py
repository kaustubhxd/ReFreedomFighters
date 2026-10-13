"""specs_s3542.py - gap band claim 42: 0x563710 and 0x5678e0 (GUESS names). Stubs: 0x563650 (thiscall, two args, logged),
0x5af130 (thiscall, one arg, logs the arg and returns a per-call value from a sequence), 0x5aedf0 (thiscall, one arg, logged),
arg0's vtable +0x1e0 (thiscall, one arg, returns al)."""
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


def _thiscall_log(c, nargs, ret):
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _seq1(c, tab):
    """thiscall, one arg: logs this (ecx) and the arg per call, indexed by the call count; returns tab[count]; count += 1.
    edx holds the index (it is caller-saved in a thiscall), so ecx is logged before anything else uses it."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in tab))
    args = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(args, bytes(4 * len(tab)))
    thisv = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(thisv, bytes(4 * len(tab)))
    code = (b'\x8b\x15' + ss.P(cnt)                             # mov edx, [cnt]
            + b'\x89\x0c\x95' + ss.P(thisv)                     # mov [thisv + edx*4], ecx
            + b'\x8b\x44\x24\x04'                              # mov eax, [esp+4]
            + b'\x89\x04\x95' + ss.P(args)                      # mov [args + edx*4], eax
            + b'\x8b\x04\x95' + ss.P(tb)                        # mov eax, [tb + edx*4]
            + b'\xff\x05' + ss.P(cnt)                            # inc dword [cnt]
            + b'\xc2\x04\x00')
    return ss.code(c, code)


def _gen_563710(c):
    ss.patch(c, 0x563650, _thiscall_log(c, 2, 0))
    arg0 = _rnd(c, 0x100)
    vt = c.emu.fake_vtable('ZGapA563710', 0x1e8, {0x1e0: _thiscall_log(c, 1, c.rng.choice([0, 1]))})
    c.emu.w32(arg0, vt)
    a0 = arg0 if c.rng.random() < 0.85 else 0
    return [_rnd(c, 0x200), a0, c.rng.getrandbits(32)]


def _gen_5678e0(c):
    ss.patch(c, 0x5af130, _seq1(c, [c.rng.choice([0, 0, 7]), c.rng.choice([0, 9])]))
    ss.patch(c, 0x5aedf0, _thiscall_log(c, 1, 0))
    a1 = _rnd(c, 0x200)
    self_obj = _rnd(c, 0x200)
    a0 = c.rng.getrandbits(32) | 1 if c.rng.random() < 0.85 else 0
    return [self_obj, a0, a1]


S(0x563710, 'GUESS method 0x563710 thiscall', 'thiscall', None, ret=None, gen=_gen_563710,
  note='gap band claim 42; 0x563650 stubbed (logged); arg0 vtable +0x1e0')
S(0x5678e0, 'GUESS method 0x5678e0 thiscall', 'thiscall', None, ret='eax', gen=_gen_5678e0,
  note='gap band claim 42; 0x5af130 (sequence) and 0x5aedf0 stubbed (logged)')
