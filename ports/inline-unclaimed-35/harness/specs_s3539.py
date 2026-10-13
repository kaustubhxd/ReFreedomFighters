"""specs_s3539.py - claim 39: 0x5094c0 ZActorIf::calcPositionInBox(ZGEOM*, float*, float*). Stdcall, three args.
Stubs: the manager's vtable +0x1c0 (thiscall, two args, returns floats from a per-case sequence) and 0x451890 (fastcall,
float stack arg; logs ecx, edx and the float; writes GUESS through the pointers)."""
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


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _seq_f32(c, tab):
    """thiscall, two args: logs both args per call (indexed by the call count), returns tab[cnt] in st0, cnt += 1."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in tab))
    args = c.emu.alloc(8 * len(tab), 4)
    c.emu.wbytes(args, bytes(8 * len(tab)))
    code = (b'\x8b\x0d' + ss.P(cnt)                             # mov ecx, [cnt]
            + b'\x8b\x44\x24\x04' + b'\x89\x04\xcd' + ss.P(args)          # arg0 -> args[cnt*2]
            + b'\x8b\x44\x24\x08' + b'\x89\x04\xcd' + ss.P(args + 4)      # arg1 -> args[cnt*2+1]
            + b'\xd9\x04\x8d' + ss.P(tb)                          # fld dword [tb + ecx*4]
            + b'\xff\x05' + ss.P(cnt)                              # inc dword [cnt]
            + b'\xc2\x08\x00')
    return ss.code(c, code)


def _h451890(c):
    """fastcall (ecx, edx, float stack arg): logs the float per call, indexed by the call count (edx is a stack address)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    flog = c.emu.alloc(4 * 8, 4)
    c.emu.wbytes(flog, bytes(32))
    code = (b'\x8b\x0d' + ss.P(cnt)                             # mov ecx, [cnt]
            + b'\x8b\x44\x24\x04'                            # mov eax, [esp+4]  (the float)
            + b'\x89\x04\x8d' + ss.P(flog)                    # mov [flog + ecx*4], eax
            + b'\xff\x05' + ss.P(cnt)                          # inc dword [cnt]
            + b'\xc2\x04\x00')
    return ss.code(c, code)


def _gen(c):
    t1 = _fl(c, -2.0, 4.0)
    t2 = _fl(c, -2.0, 4.0)
    ss.patch(c, 0x451890, _h451890(c))
    mgr = _rnd(c, 0x2000)
    c.emu.w32(0x70039c, mgr)
    mvt = c.emu.fake_vtable('ZGapMgr5094', 0x1c8, {0x1c0: _seq_f32(c, [t1, t2])})
    c.emu.w32(mgr, mvt)
    A = _rnd(c, 0x100)
    B = _rnd(c, 0x100)
    c.emu.w32(A + 8, B)
    C = _rnd(c, 0x100)
    P = _rnd(c, 0x100)
    for base, offs in ((B, (0x40, 0x48)), (C, (0, 4, 8, 0x18, 0x1c, 0x20))):
        for off in offs:
            c.emu.wbytes(base + off, struct.pack('<I', _fl(c, -4.0, 4.0)))
    return [A, C, P]


S(0x5094c0, 'ZActorIf::calcPositionInBox(ZGEOM*, float*, float*) stdcall', 'stdcall', None, ret=None, gen=_gen,
  note='claim 39; manager vtable +0x1c0 (sequence) and 0x451890 (logged) stubbed')
