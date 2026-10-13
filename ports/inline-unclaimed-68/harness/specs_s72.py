"""specs_s72.py - unclaimed-68 batch 72 (slice 7). Names GUESS (FUN_addr). Callee 0x5b9250 (ret 0, thiscall) is hooked and logged."""
from pilot import S
from engine_stubs import zero_obj
from serial_stubs import patch, code, rec


def _setup_5b9250(c):
    patch(c, 0x5b9250, rec(c, 0, ret=0, log=False))


def _o(c, size=0x100):
    o = zero_obj(c, size)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


def _g537a70(c):
    return [_o(c, 0x5400), c.rng.getrandbits(32)]


def _g64fbb0(c):
    out = c.emu.alloc(8, 4)
    c.emu.wbytes(out, bytes(8))
    return [_o(c), out]


def _g4b0570(c):
    obj = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('ObjB0570', 0x90, impl={}, argwords={0x44: 1})
    c.emu.w32(obj, vt)
    return [_o(c), obj]


def _vt2(c, name, offs):
    o = zero_obj(c, 0x100)
    impl = {off: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32)) for off, _ in offs}
    vt = c.emu.logging_vtable(name, 0x200, impl=impl, argwords={off: n for off, n in offs})
    c.emu.w32(o, vt)
    return o


def _g64fcf0(c):
    inner = _vt2(c, 'Inner64fcf0', [(4, 2)])
    o = zero_obj(c, 0x100)
    c.emu.w32(o + 0x14, inner)
    return [o, c.rng.getrandbits(32)]


def _g5372f0(c):
    o = _vt2(c, 'Self5372f0', [(0x54, 1), (0x1e8, 1)])
    return [o, c.rng.getrandbits(32)]


def _g5b8530(c):
    o = _o(c)
    c.emu.wbytes(o + 0xdb, bytes([c.rng.randrange(4), c.rng.randrange(4)]))
    w = c.rng.randrange(4) if c.rng.random() < 0.5 else (int.from_bytes(bytes(c.emu.rbytes(o + 0xdb, 2)), 'little'))
    return [o, w, c.rng.getrandbits(32)]


S(0x537a70, 'FUN_537a70 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_g537a70,
  note='unclaimed-68 batch 72: dword this+0x5302 = arg; returns 1')
S(0x64fbb0, 'FUN_64fbb0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g64fbb0,
  note='unclaimed-68 batch 72: copies this+0xb5 and +0xb9 to the out pointer')
S(0x4b0570, 'FUN_4b0570 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_g4b0570,
  note='unclaimed-68 batch 72: clears this+4 bit 0x40; obj slot +0x44([this+0x48]); returns 1')
S(0x64fcf0, 'FUN_64fcf0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g64fcf0,
  note='unclaimed-68 batch 72: [this+0x14] slot +4 (arg, 0)')
S(0x5372f0, 'FUN_5372f0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g5372f0,
  note='unclaimed-68 batch 72: this slot +0x54(arg) then slot +0x1e8')
S(0x5b8530, 'FUN_5b8530 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g5b8530, setup=_setup_5b9250,
  note='unclaimed-68 batch 72: word compare with this+0xdb; callee 0x5b9250 stubbed (GUESS)')
