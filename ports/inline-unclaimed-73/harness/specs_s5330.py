"""specs_s5330.py - area 73 batch 53 (gap band, GUESS names). FUN_4e6bc0 is the inverse of FUN_4e6bf0 (batch 48): when
this+0x10 equals this+8 it returns 0; otherwise it reads word[this+0x10] from the array at this+4, advances this+0x10, and
returns this+0xc * word + this[0]. FUN_4e42a0 pushes a node onto the list at this+0xc. FUN_4f2190 and FUN_4f21c0 call vtable
slots +0x6c / +0x68 on the object at g_sys+0x1907, guarded by the byte at this+0x5f9."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4e6bc0(c):
    e = c.emu
    o = _rnd(c, 0x20)
    e.w32(o, c.rng.getrandbits(32))
    e.w32(o + 0xc, c.rng.getrandbits(32))
    arr = _rnd(c, 0x100)
    e.w32(o + 4, arr)
    lim = c.rng.randint(0, 0x10)
    e.w32(o + 8, lim)
    e.w32(o + 0x10, c.rng.randint(0, 0x10) if c.rng.random() < 0.8 else lim)
    return [o]


def _gen_4e42a0(c):
    e = c.emu
    o = _rnd(c, 0x20)
    head = 0 if c.rng.random() < 0.4 else _rnd(c, 0x40)
    e.w32(o + 0xc, head)
    node = _rnd(c, 0x40)
    return [o, node]


def _sys_with_obj(c, slot, slot_idx):
    e = c.emu
    obj = _rnd(c, 0x100)
    e.w32(obj, e.logging_vtable('ctl', 0x80 // 4, impl={slot: lambda em, a: (0, None)}, argwords={slot: 0}))
    sys = _rnd(c, 0x2000)
    e.w32(sys + 0x1907, obj)
    e.w32(0x70039c, sys)


def _gen_4f2190(c):
    o = _rnd(c, 0x600)
    e = c.emu
    e.wbytes(o + 0x5f9, bytes([c.rng.choice([0, 1, c.rng.getrandbits(8)])]))
    _sys_with_obj(c, 0x6c, 0)
    return [o]


def _gen_4f21c0(c):
    o = _rnd(c, 0x600)
    e = c.emu
    e.wbytes(o + 0x5f9, bytes([c.rng.choice([0, 1, c.rng.getrandbits(8)])]))
    _sys_with_obj(c, 0x68, 0)
    return [o]


S(0x4e6bc0, 'GUESS FUN_4e6bc0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4e6bc0,
  note='area 73 batch 53; inverse of FUN_4e6bf0; returns this+0xc*word+this[0], or 0 at the end of the array')
S(0x4e42a0, 'GUESS FUN_4e42a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4e42a0,
  note='area 73 batch 53; pushes node onto the list at this+0xc, node+0x18 = this')
S(0x4f2190, 'GUESS FUN_4f2190 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f2190,
  note='area 73 batch 53; if byte +0x5f9: obj(g_sys+0x1907) vt+0x6c(), byte = 0')
S(0x4f21c0, 'GUESS FUN_4f21c0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f21c0,
  note='area 73 batch 53; if byte +0x5f9 == 0: obj(g_sys+0x1907) vt+0x68(), byte = 1')
