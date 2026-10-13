"""specs_s344.py - decomp area 64 (docs/20-unclaimed-64.md): 0x45d1f0 refresh loop; exe 0x4dc630 and 0x4da3a0 are stubbed; node and global slots are logging stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _refresh(c):
    e = c.emu
    # 0x4dc630 (cdecl-free thiscall, two words) and 0x4da3a0 (returns al): stubs on both sides. The first records its two
    # words and bumps a counter (so a missing or extra call shows); the second returns a per-case al.
    cell = e.alloc(16, 4)
    e.wbytes(cell, bytes(16))
    al = 1 if c.rng.random() < 0.8 else 0
    ss.patch(c, 0x4dc630, ss.code(c, b'\xff\x05' + ss.P(cell)                              # inc [cell]
                                  + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell + 4)     # [cell+4] = a
                                  + b'\x8b\x54\x24\x08' + b'\x89\x15' + ss.P(cell + 8)     # [cell+8] = b
                                  + b'\xc2\x08\x00'))                                       # ret 8
    ss.patch(c, 0x4da3a0, ss.code(c, b'\xb8' + ss.P(al) + b'\xc3'))

    # Node N: slots 0x4c and 0x5c take one word (the local's address) and write the local through it. Slot 0x5c clears the
    # local after a random number of calls (so the loop ends).
    lim = c.rng.randrange(0, 4)
    state = {'n5c': 0, 'lim': lim}
    first = 1 if c.rng.random() < 0.7 else 0

    def w4c(em, a):
        em.w32(a[0], first)
        return (0, None)

    def w5c(em, a):
        state['n5c'] += 1
        val = 1 if state['n5c'] <= state['lim'] else 0
        em.w32(a[0], val)
        return (state['n5c'] * 0x101, None)

    N_vt = e.logging_vtable('node45d1', 0x80, argwords={0x4c: 1, 0x5c: 1}, impl={0x4c: w4c, 0x5c: w5c})
    N = _rnd(c, 0x40)
    e.w32(N, N_vt)

    # Global G2 (0x70038c): slot 0xcc takes one word and returns a pointer p (a p object or 0).
    pobjs = []
    for _ in range(3):
        p = _rnd(c, 0x20)
        pobjs.append(p)
    seq = [0 if c.rng.random() < 0.3 else c.rng.choice(pobjs) for _ in range(4)]
    gi = {'i': 0}

    def wcc(em, a):
        v = seq[gi['i'] % len(seq)]
        gi['i'] += 1
        return (v, None)

    G2_vt = e.logging_vtable('g2_45d1', 0x400, argwords={0xcc: 1}, impl={0xcc: wcc})
    G2 = _rnd(c, 0x40)
    e.w32(G2, G2_vt)
    e.w32(0x70038c, G2)

    # p objects: a flag byte at +4 and at +0x14 (random bits), so both tests run.
    for p in pobjs:
        e.wbytes(p + 0x14, bytes([c.rng.getrandbits(8)]))
        e.wbytes(p + 0x4, bytes([c.rng.getrandbits(8)]))

    hold = _rnd(c, 0x40)
    e.w32(hold + 0x8, N if c.rng.random() < 0.9 else 0)
    O = _rnd(c, 0x40)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x8, O)
    e.w32(self_ + 0x10, hold)
    return [self_]


S(0x45d1f0, 'refreshLoop (GUESS)', 'thiscall', None, ret=None, gen=_refresh,
  note='batch344; no stack words; exe 0x4dc630 and 0x4da3a0 stubbed; node slots 0x4c, 0x5c; global slot 0xcc')
