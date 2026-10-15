"""specs_s67551.py - cascade s6 batch 67551 (0x6553a0, thiscall() plain ret, return value unused). sys slots 0xe4 / 0xe8 (1 arg each, bool recorders with random answers, call order logged)
answer the key queries; the latches 0x7f6414 / 0x7f6415 are random bytes; sys[0x1aa3][0x79] is a random byte; this[0x1157] a random dword."""
from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g6553a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ch = lambda em, k: r.choice([0, 1, 1, 0x100, 0x101])
    so = sysobj(c, slots={0xe4: pystub(c, 1, this=True, ret=ch), 0xe8: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100]))})
    p = rnd(c, 0x90)
    _w(c, p + 0x79, r.choice([0, 1, 2]), 1)
    _w(c, so + 0x1aa3, p)
    e.wbytes(0x7f6414, bytes([r.choice([0, 1, 2]), r.choice([0, 1, 5])]))
    t = rnd(c, 0x1200)
    return [t]


S(0x6553a0, 'GUESS debug_key_handler', 'thiscall', None, ret=None, gen=_g6553a0, note='batch67551')
