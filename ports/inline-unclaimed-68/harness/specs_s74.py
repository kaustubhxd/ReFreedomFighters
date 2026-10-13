"""specs_s74.py - unclaimed-68 batch 74 (slice 7). Names GUESS (FUN_addr). Callees are slot calls on logged objects."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _f(c):
    return struct.unpack('<f', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0]


def _o(c, size=0x100):
    o = zero_obj(c, size)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


def _g526ef0(c):
    return [_o(c)]


def _g42d2b0(c):
    o = zero_obj(c, 0x1c00)
    p1 = zero_obj(c, 0x40)
    p2 = zero_obj(c, 0x40)
    c.emu.w32(p1 + 4, c.rng.getrandbits(32))
    c.emu.w32(p2 + 4, c.rng.getrandbits(32))
    c.emu.w32(o + 0x1b61, p1)
    c.emu.w32(o + 0x1b6d, p2)
    arg = zero_obj(c, 0x20)
    # the cursor either equals the end pointer (no advance) or does not
    c.emu.w32(arg, c.emu.r32(p2 + 4) if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o, arg]


def _g5db3f0(c):
    eng = zero_obj(c, 0x2000)
    mgr = zero_obj(c, 0x1000)
    obj = logged_obj(c, 'ZObj5db3f0', 0x300, impl={0x25c: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))},
                     argwords={0x25c: 2})
    c.emu.w32(mgr + 0xadc, obj)
    c.emu.w32(eng + 0x9b, mgr)
    set_global(c, 0x70039c, eng)
    return [_o(c)]


def _g63e630(c):
    o = _o(c, 0x100)
    c.emu.w32(o + 0x18, c.rng.getrandbits(32))
    c.emu.w32(o + 0x1c, c.rng.randrange(0, 16))
    obj = logged_obj(c, 'ZObj63e630', 0x200, impl={0x4: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))},
                     argwords={0x4: 2})
    c.emu.w32(o + 0x14, obj)
    arg = zero_obj(c, 0x20)
    c.emu.w32(arg + 4, c.rng.getrandbits(32))
    return [o, arg]


def _g527030(c):
    o = _o(c)
    c.emu.w32(o + 4, struct.unpack('<I', struct.pack('<f', _f(c)))[0])
    c.emu.w32(o + 8, struct.unpack('<I', struct.pack('<f', _f(c)))[0])
    return [o]


S(0x526ef0, 'FUN_526ef0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g526ef0,
  note='unclaimed-68 batch 74: constructor body; returns this')
S(0x42d2b0, 'FUN_42d2b0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g42d2b0,
  note='unclaimed-68 batch 74: dword [p1+4] -= 4; cursor advance when not at [p2+4]')
S(0x5db3f0, 'FUN_5db3f0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g5db3f0,
  note='unclaimed-68 batch 74: [this+0x48] = [[mgr+0xadc]] slot +0x25c(0x685f44, 0)')
S(0x63e630, 'FUN_63e630 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_g63e630,
  note='unclaimed-68 batch 74: slot +4 of [this+0x14] with ((this+0x1c)<<12)+0x1010 and [arg+4]')
S(0x527030, 'FUN_527030 (GUESS) thiscall', 'thiscall', None, ret='st0', gen=_g527030,
  note='unclaimed-68 batch 74: |[this+8] - [this+4]| via the double abs mask at 0x67cd50')
