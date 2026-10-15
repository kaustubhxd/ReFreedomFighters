"""specs_c101.py - climb thread batch 101: 0x4ddcb0 LoadRotationAxisAngle, 0x5b15d0 ZSewerControl::GetSewerInfo."""
import struct
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _lra(c):
    r = c.rng
    m = c.fbuf(9, pad=4)
    k = r.random()
    if k < 0.3:   # unit axes, the common case
        ax = [0.0, 0.0, 0.0]; ax[r.randint(0, 2)] = r.choice([1.0, -1.0])
        a = c.emu.alloc(16, 4)
        for i, v in enumerate(ax):
            c.emu.wf32(a + 4 * i, v)
    else:
        a = c.fbuf(3, pad=2)
    ang = c.fv(-7.0, 7.0)
    return [m, a, F(ang)]


S(0x4ddcb0, 'LoadRotationAxisAngle', 'fastcall', None, ret=None, gen=_lra,
  note='c101; cos/sin are the harness CRT stubs on both sides')

_NAMES = [b'C01A_Sewer01', b'C01A_Sewer02', b'C02A_Lid', b'C03B', b'C03B_2', b'Sewer', b'sewer', b'', b'C05A_Sewer_Main']


def _gsi(c):
    r = c.rng
    e = c.emu
    obj = _rnd(c, 8 + 0x12 * 19 + 16)
    names = []
    for i in range(19):
        nm = r.choice(_NAMES) + (bytes([0x30 + r.randint(0, 9)]) if r.random() < 0.5 else b'')
        names.append(nm)
        s = e.alloc(len(nm) + 1, 1)
        e.wbytes(s, nm + b'\0')
        e.w32(obj + 8 + 0x12 * i, s)
        if r.random() < 0.5:   # sane heading and position values half the time
            for j in range(3):
                e.mu.mem_write(obj + 8 + 0x12 * i + 5 + 4 * j, struct.pack('<f', c.fv(-2000, 2000)))
    k = r.random()
    if k < 0.6:
        q = r.choice(names)
    elif k < 0.8:
        q = r.choice(names)[:-1] if r.random() < 0.5 else r.choice(names) + b'x'
    else:
        q = r.choice(_NAMES)
    qs = e.alloc(len(q) + 1, 1)
    e.wbytes(qs, q + b'\0')
    lid = _rnd(c, 8)
    pos = c.fbuf(3, pad=2)
    mat = c.fbuf(9, pad=2)
    return [obj, qs, lid, pos, mat]


S(0x5b15d0, 'ZSewerControl::GetSewerInfo', 'thiscall', None, ret=None, gen=_gsi,
  note='c101; LoadRotationAxisAngle runs as original code')
