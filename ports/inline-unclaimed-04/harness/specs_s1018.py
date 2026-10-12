"""specs_s1018.py - unclaimed-04 batch 19 (docs/20-unclaimed-04.md): three slice-3 leaves (GUESS labels).
0x61c630 is cdecl with two stack arguments (store arg2 at arg1+0x5c). 0x4f45f0 returns (float) of the signed dword at
this+0xb0 in st0. 0x658270 returns the float at ((global 0x70039c)+0x1aa3 pointer)+0x91 in st0; the spec makes that chain
valid."""
import struct

from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _store(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _int_obj(c):
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0xb0, c.rng.choice([0, 1, -1, 0x7fffffff, -0x80000000, c.rng.randrange(-100000, 100000)]) & 0xffffffff)
    return [o]


def _chain(c):
    G = _rnd(c, 0x2000)
    P = _rnd(c, 0x100)
    c.emu.wbytes(P + 0x91, struct.pack('<f', c.rng.uniform(-1000.0, 1000.0)))
    c.emu.w32(G + 0x1aa3, P)
    c.emu.w32(0x70039c, G)
    return [_rnd(c, 0x100)]


S(0x61c630, 'unknown::store_5c (unknown) cdecl', 'cdecl', None, ret=None, gen=_store,
  note='unclaimed-04 batch 19; dword at arg1+0x5c = arg2')
S(0x4f45f0, 'unknown::signed_b0_to_float (unknown) thiscall', 'thiscall', None, ret='st0', gen=_int_obj,
  note='unclaimed-04 batch 19; st0 = (float) of the signed dword at +0xb0')
S(0x658270, 'unknown::float_chain_91 (unknown) thiscall', 'thiscall', None, ret='st0', gen=_chain,
  note='unclaimed-04 batch 19; st0 = float at ((global 0x70039c)+0x1aa3)+0x91')
