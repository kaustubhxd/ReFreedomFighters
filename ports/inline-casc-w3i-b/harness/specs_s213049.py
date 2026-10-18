"""specs_s213049.py - single-byte nested section scanner with callbacks; parser step with four callbacks, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def g6261b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x200)
    tab = [r.choice([3, 3, 3, 3, 9, 10]) for _ in range(256)]
    tab[0] = 0
    tab[0x3c] = 2
    tab[0x5d] = 4
    tab[0x41] = 5
    tab[0x42] = 6
    tab[0x43] = 7
    tab[0x44] = 1
    tab[0x45] = 8
    e.wbytes(base + 0x4c, bytes(tab))
    seqs = {}
    for off in (0x164, 0x168, 0x16c):
        seq = r.choice([[0], [0], [1], [0, 1], [0, 0, 1], [r.getrandbits(32)]])
        e.w32(base + off, pystub(c, 2, ret=lambda emu, k, seq=seq: seq[min(k, len(seq) - 1)], pop=0))
    out = bytearray()
    for _ in range(r.randint(0, 10)):
        x = r.random()
        if x < 0.2:
            out += b'<![' if r.random() < 0.8 else r.choice([b'<x', b'<!x', b'<'])
        elif x < 0.4:
            out += b']]>' if r.random() < 0.8 else r.choice([b']x', b']]x', b']'])
        elif x < 0.6:
            out.append(r.choice([0x41, 0x42, 0x43, 0x41, 0x42, 0x43]))
            out += bytes(r.getrandbits(8) for _ in range(r.randint(0, 3)))
        elif x < 0.7:
            out.append(r.choice([0x44, 0x45]))
        else:
            out.append(r.choice([0x61, 0x62, 0x20, r.randint(1, 255)]))
    if r.random() < 0.5:
        out += b']]>'
    n = len(out)
    cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3)])
    data = bytes(out) + bytes(40)
    p = rnd(c, len(data) + 8)
    e.wbytes(p, data)
    return [base, p, p + cut, rnd(c, 8)]


def g62dc60(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    ev = rnd(c, 0x60)
    seq = r.choice([[0], [1], [0, 1], [0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 0], [r.getrandbits(32)]])
    c.emu.w32(ev + 0x1c, pystub(c, 4, ret=lambda emu, k: seq[min(k, len(seq) - 1)], pop=0))
    b = r.choice([0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x1a, 0x1b, 0x1c, 0x1d, r.randint(8, 0x20), 0x1c, 0x10, 0x10, r.getrandbits(32)])
    return [o, b, r.getrandbits(32), r.getrandbits(32), ev]


S(0x6261b0, 'cdata_end_bytes', 'cdecl', None, ret='eax', gen=g6261b0)
S(0x62dc60, 'parser_step_4cb', 'cdecl', None, ret='eax', gen=g62dc60)
