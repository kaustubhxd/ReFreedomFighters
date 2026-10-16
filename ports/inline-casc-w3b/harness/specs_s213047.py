"""specs_s213047.py - wide pair tokenizers (LE 0x623e40, BE 0x626050) with a hooked nested scanner, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _mk(le):
    def pair(ch, lead=0):
        return bytes([ch, lead]) if le else bytes([lead, ch])

    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        base = rnd(c, 0x4c + 0x100 + 4)
        hot = [2, 3, 4, 5, 6, 7, 8, 9, 10, 21, 4, 4, 5, 6, 7, 4, 9, 10, 21, 3, 11, 14, 0x15]
        tab = [(r.choice(hot) if r.random() < 0.9 else r.getrandbits(8)) for _ in range(256)]
        tab[0] = 2          # zero padding stops the scan
        tab[0x20] = 4
        tab[0x0a] = 10
        tab[0x0d] = 9
        tab[0x30] = 3
        tab[0x31] = 21
        tab[0x41] = 5
        tab[0x42] = 6
        tab[0x43] = 7
        tab[0x32] = 20
        tab[0x33] = 22
        e.wbytes(base + 0x4c, bytes(tab))
        out = bytearray()
        if r.random() < 0.5:
            ch = r.choice([0x0d, 0x0a, 0x30, 0x31, 0x41, 0x42, 0x43, 0x0d, 0x0a, 0x32, 0x33])
            out += pair(ch)
            if ch == 0x0d and r.random() < 0.5:
                out += pair(0x0a)
        for _ in range(r.randint(0, 8)):
            x = r.random()
            if x < 0.4:
                out += pair(r.choice([0x20, 0x61, 0x62, 0x20, r.randint(1, 255)]))
            elif x < 0.8:
                out += pair(r.choice([0x0d, 0x0a, 0x30, 0x31, 0x41, 0x42, 0x43, 0x32, 0x33]))
            elif x < 0.93:
                out += pair(r.choice([0xfd, 0xfe, 0xff, 0x41, r.getrandbits(8)]), r.choice([0xd8, 0xd9, 0xdb, 0xdc, 0xdf, r.randint(0xd8, 0xff), 0xff]))
            else:
                out += pair(0x02) if r.random() < 0.5 else pair(0x00)
        n = len(out)
        cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3)]) if n else 0
        if n and r.random() < 0.15:
            cut = 2
        data = bytes(out) + bytes(40)
        p = rnd(c, len(data) + 8)
        e.wbytes(p, data)
        outp = rnd(c, 8)
        hook_rec(c, 0x62a690, 4, ret=r.getrandbits(32), pop=0)
        hook_rec(c, 0x628630, 4, ret=r.getrandbits(32), pop=0)
        return [base, p, p + cut, outp]
    return g


S(0x623e40, 'tokenize_pairs_le', 'cdecl', None, ret='eax', gen=_mk(True))
S(0x626050, 'tokenize_pairs_be', 'cdecl', None, ret='eax', gen=_mk(False))
