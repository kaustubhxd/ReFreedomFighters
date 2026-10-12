"""specs_s916.py - unclaimed-01 claim 15 (docs/20-unclaimed-01.md): CExplodeMolotov::ReadInput (0x584bc0). The DBREAD
operators (0x4e5e60 dword, 0x4e5e40 word) are patched with per-run sequences by the shared serial_stubs (dbread_patch).
The DBREAD object's first dword points at a 0x40-byte buffer whose first byte is 0xff (25%), 0x03-like (low six bits 3,
25%) or random. The global's sub-object has a logging fake vtable: slot +0x114 (four arguments) returns a per-case value."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _readinput(c):
    buf = _rnd(c, 0x40)
    r = c.rng.random()
    if r < 0.25:
        c.emu.wbytes(buf, b'\xff')
    elif r < 0.5:
        c.emu.wbytes(buf, bytes([(c.rng.getrandbits(8) & 0xc0) | 0x03]))
    dbr = _rnd(c, 0x40)
    c.emu.w32(dbr, buf)
    ss.dbread_patch(c, [c.rng.getrandbits(32) for _ in range(8)],
                    [c.rng.getrandbits(16) for _ in range(8)], [0])
    v114 = c.rng.getrandbits(32)
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, c.emu.logging_vtable('ZRenderMgr', 0x48, impl={0x114: (lambda e, a, v=v114: (v, None))},
                                       argwords={0x114: 4}))
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, sub)
    c.emu.w32(0x70039c, g)
    return [_rnd(c, 0x100), dbr]


S(0x584bc0, 'CExplodeMolotov::ReadInput (unknown) thiscall', 'thiscall', None, ret=None, gen=_readinput,
  note='unclaimed-01 claim 15; DBREAD operators stubbed by serial_stubs; slot +0x114 logged')
