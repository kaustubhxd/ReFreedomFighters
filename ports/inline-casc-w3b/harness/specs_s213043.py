"""specs_s213043.py - batch 213043: nested <![ ]]> section scanners, little- and big-endian pairs, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _mk(le):
    def pair(ch):
        return bytes([ch, 0]) if le else bytes([0, ch])

    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        base = rnd(c, 0x4c + 0x100 + 4)
        tab = [r.choice([3, 3, 3, 9, 10, 11, 14, 5, 6, 7]) for _ in range(256)]
        tab[0] = 0       # zero padding stops the scan
        tab[0x3c] = 2    # <
        tab[0x21] = 3    # !
        tab[0x5b] = 3    # [
        tab[0x5d] = 4    # ]
        tab[0x3e] = 3    # >
        tab[0x41] = 5
        tab[0x42] = 6
        tab[0x43] = 7
        tab[0x44] = 1
        tab[0x45] = 8
        e.wbytes(base + 0x4c, bytes(tab))
        out = bytearray()
        for _ in range(r.randint(0, 9)):
            x = r.random()
            if x < 0.25:
                out += pair(0x3c) + pair(0x21) + pair(0x5b)
            elif x < 0.5:
                out += pair(0x5d) + pair(0x5d) + pair(0x3e)
            elif x < 0.6:
                out += pair(0x3c) + pair(r.choice([0x21, 0x22])) + pair(r.choice([0x5b, 0x5c]))
            elif x < 0.7:
                out += pair(0x5d) + pair(r.choice([0x5d, 0x5e])) + pair(r.choice([0x3e, 0x3f]))
            elif x < 0.85:
                out += pair(r.choice([0x61, 0x62, 0x20, 0x41, 0x42, 0x43, 0x44, 0x45]))
            elif x < 0.93:
                out += (bytes([r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)]), r.randint(0xd8, 0xff)]) if le
                        else bytes([r.randint(0xd8, 0xff), r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)])]))
            else:
                out += bytes(r.getrandbits(8) for _ in range(r.choice([1, 2, 3])))
        if r.random() < 0.5:
            out += pair(0x5d) + pair(0x5d) + pair(0x3e)
        if r.random() < 0.2:
            out += pair(r.choice([0x41, 0x42, 0x43]))
        odd = r.random() < 0.12
        if odd:
            out += pair(0x42) + bytes([r.getrandbits(8)]) + pair(0x43) + bytes([r.getrandbits(8)])
        n = len(out)
        cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3), max(0, n - 4)])
        if odd:
            cut = n
        data = bytes(out) + bytes(40)
        p = rnd(c, len(data) + 8)
        e.wbytes(p, data)
        return [base, p, p + cut, rnd(c, 8)]
    return g


S(0x624350, 'cdata_section_end_le', 'cdecl', None, ret='eax', gen=_mk(True))
S(0x626500, 'cdata_section_end_be', 'cdecl', None, ret='eax', gen=_mk(False))
