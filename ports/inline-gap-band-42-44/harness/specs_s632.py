"""specs_s632.py - band 0x421000-0x441000, batch 632 (see src/batch632.cpp).
0x422b00: the three globals 0x700394, 0x70038c and 0x70039c hold fake objects whose slots are recorded; the sound object at
[0x70039c]+0x1a9f is 0 one time in five. Result not compared (void).
0x43d310: a 0x40-byte self with random floats (pilot fv: edges, random bit patterns, NaN included) and random flag bytes at 0x1c
and 0x39 (zero half the time); 15% of cases make one sum -0.0 (four -0.0 floats) to test the +0/-0 tie. The st0 result is compared.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _rec(name, off):
    def h(e, rr):
        e.calllog.append((name, off, e.reg('ecx'), ()))
        e.ret(eax=0x1234 + off, argbytes=0)
    return h


def _block(c, size):
    a = c.emu.alloc(size, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a


def _gen_pump(c):
    r = c.rng
    self_ = _block(c, 0x80)
    c.emu.wbytes(self_ + 0x60, bytes([0 if r.random() < 0.6 else r.randint(1, 255)]))
    c.emu.w32(0x700394, c.emu.fake_object('g394', 0x40, nslots=0x10, slots={4: _rec('g394.4', 4)}))
    c.emu.w32(0x70038c, c.emu.fake_object('g38c', 0x40, nslots=0x40, slots={0x78: _rec('g38c.78', 0x78)}))
    snd = c.emu.fake_object('snd', 0x40, nslots=0x20, slots={0x38: _rec('snd.38', 0x38)}) if r.random() < 0.8 else 0
    sys_ = _block(c, 0x2000)
    c.emu.w32(sys_ + 0x1a9f, snd)
    c.emu.w32(0x70039c, sys_)
    flag = r.choice((0, 0, 1, r.getrandbits(32), r.getrandbits(32) & ~0xff))
    return [self_, flag]


def _gen_sums(c):
    r = c.rng
    self_ = _block(c, 0x40)
    for off in (0, 4, 8, 0xc, 0x1d, 0x21, 0x25, 0x29):
        c.emu.wf32(self_ + off, c.fv())
    # signed-zero ties: one sum made of four -0.0 (sum -0.0) against the other side's +0.0, so maxss's tie rule shows
    if r.random() < 0.15:
        for off in ((0, 4, 8, 0xc) if r.random() < 0.5 else (0x1d, 0x21, 0x25, 0x29)):
            c.emu.wf32(self_ + off, -0.0)
    for off in (0x1c, 0x39):
        c.emu.wbytes(self_ + off, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
    return [self_]


S(0x422b00, 'slot 4 of [0x700394]; byte +0x60; slot 0x78 of [0x70038c]; flag; slot 0x38 of the sound object', 'thiscall', None,
  ret=None, gen=_gen_pump)
S(0x43d310, 'max of two guarded four-float sums (maxss), returned in st0', 'thiscall', None, ret='st0', gen=_gen_sums)
