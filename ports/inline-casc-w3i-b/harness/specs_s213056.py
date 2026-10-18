"""specs_s213056.py - ]]> section end scanners over wide characters (BE 0x622080, LE 0x624980), Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _mk(le):
    def pair(ch, lead=0):
        return bytes([ch, lead]) if le else bytes([lead, ch])

    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        base = rnd(c, 0x4c + 0x100 + 4)
        tab = [r.choice([2, 3, 12, 20, 11]) for _ in range(256)]
        tab[0] = 0
        for k in range(0, 13):
            tab[0x41 + k] = k          # one character for classes 0..12
        tab[0x5d] = 4
        tab[0x3e] = 3
        tab[0x0d] = 9
        tab[0x0a] = 10
        e.wbytes(base + 0x4c, bytes(tab))
        out = bytearray()
        first = r.choice([0x41 + r.randint(0, 12), 0x5d, 0x0d, 0x0a, 0x41 + r.randint(0, 12)])
        out += pair(first)
        if first == 0x5d:
            x = r.random()
            if x < 0.6:
                out += pair(0x5d)
                out += pair(r.choice([0x3e, 0x3e, 0x3f]))
            elif x < 0.8:
                out += pair(0x5d) + pair(0x41 + r.randint(0, 12))
        if first == 0x0d and r.random() < 0.6:
            out += pair(r.choice([0x0a, 0x0a, 0x41]))
        for _ in range(r.randint(0, 6)):
            x = r.random()
            if x < 0.6:
                out += pair(0x41 + r.randint(0, 12))
            elif x < 0.75:
                out += pair(r.choice([0x41 + r.randint(2, 7), 0x5d, 0x0d, 0x0a]))
            elif x < 0.9:
                out += pair(r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)]), r.choice([0xd8, 0xd9, 0xdb, 0xdc, r.randint(0xd8, 0xff)]))
            else:
                out += bytes(r.getrandbits(8) for _ in range(r.choice([1, 2, 3])))
        if r.random() < 0.15:
            out += pair(0x41 + r.choice([5, 6, 7])) + bytes(r.getrandbits(8) for _ in range(r.choice([0, 1, 2])))
        odd = r.random() < 0.1
        if odd:
            out = bytearray(pair(0x41 + r.choice([2, 3, 5]))) + pair(0x41 + 6) + bytes([r.getrandbits(8)]) + pair(0x41 + 7) + bytes([r.getrandbits(8)])
        odd2 = (not odd) and r.random() < 0.08
        if odd2:
            out = bytearray(pair(0x41 + r.choice([2, 3]))) + pair(0x41 + 6) + bytes([r.getrandbits(8), 0x41 + 5])
        n = len(out)
        cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3), 1, 2, 3])
        cut = min(cut, n)
        if r.random() < 0.03:
            cut = 0
        if odd or odd2:
            cut = n
        data = bytes(out) + bytes(40)
        p = rnd(c, len(data) + 8)
        e.wbytes(p, data)
        return [base, p, p + cut, rnd(c, 8)]
    return g


S(0x622080, 'cdata_end_be', 'cdecl', None, ret='eax', gen=_mk(False))
S(0x624980, 'cdata_end_le', 'cdecl', None, ret='eax', gen=_mk(True))
