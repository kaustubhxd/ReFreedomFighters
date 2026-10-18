"""specs_s213046.py - name scanners over wide characters (exe bitmap tables), LE and BE pairs, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks

PAL = {0x41: 29, 0x42: 22, 0x43: 24, 0x44: 5, 0x45: 6, 0x46: 7, 0x47: 8, 0x48: 9, 0x49: 21, 0x4a: 23, 0x4b: 26, 0x4c: 27,
       0x4d: 29, 0x4e: 30, 0x4f: 32, 0x50: 36, 0x51: 20, 0x52: 10, 0x53: 11, 0x54: 25, 0x55: 13, 0x56: 28, 0x57: 14, 0x58: 31, 0x59: 12, 0x5a: 18, 0x5b: 18}


def _mk(le):
    def pair(ch, lead=0):
        return bytes([ch, lead]) if le else bytes([lead, ch])

    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        base = rnd(c, 0x4c + 0x100 + 4)
        tab = [r.choice([8, 8, 23, 20, 3, 4]) for _ in range(256)]
        tab[0] = 8
        for ch, k in PAL.items():
            tab[ch] = k
        for ch in range(0x60, 0x70):
            tab[ch] = 29                      # bitmap decided characters
        for ch in list(range(0x30, 0x3a)) + list(range(0x78, 0x80)) + [0x2d, 0x2e, 0x5f]:
            tab[ch] = 29
        for ch in range(0x70, 0x78):
            tab[ch] = r.choice([22, 24, 26, 27, 9, 21])
        for k in range(3, 34):
            tab[0x80 + k] = k          # one character for every class
        e.wbytes(base + 0x4c, bytes(tab))
        out = bytearray()
        starts = [0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x4d] + list(range(0x60, 0x70)) + list(range(0x30, 0x3a)) + [0x2d, 0x2e, 0x5f] + list(PAL) + list(range(0x41, 0x5b)) + list(range(0x61, 0x7b))
        if r.random() < 0.45:
            out += pair(0x80 + r.randint(3, 33))
        elif r.random() < 0.9:
            out += pair(r.choice(starts))
        else:
            out += pair(r.randint(0x30, 0x7f))
        for _ in range(r.randint(0, 8)):
            x = r.random()
            if x < 0.55:
                out += pair(r.choice([0x42, 0x43, 0x4b, 0x4c, 0x54, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77]))
            elif x < 0.75:
                out += pair(r.choice(list(range(0x60, 0x70)) + [0x41, 0x4d] + list(range(0x30, 0x3a)) + [0x2d, 0x2e, 0x5f, 0x78, 0x79]))
            elif x < 0.85:
                out += pair(r.choice(list(PAL)))
            elif x < 0.95:
                out += pair(r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)]), r.choice([0xd8, 0xd9, 0xdb, 0xdc, 0xe0, r.randint(0xd8, 0xff), 0x01, 0x03]))
            else:
                out += bytes(r.getrandbits(8) for _ in range(r.choice([1, 2, 3])))
        if r.random() < 0.3:
            out += pair(r.choice([0x44, 0x45, 0x46]))
            if r.random() < 0.5:
                out += bytes([r.getrandbits(8)])
        mode = r.random()
        if mode < 0.3:
            out = bytearray(pair(r.choice([0x41, 0x42, 0x43, 0x4d, 0x60])))
            out += pair(r.choice([0x42, 0x43, 0x4b, 0x4c, 0x70])) * r.randint(0, 1)
            out += pair(r.choice(list(PAL)) if r.random() < 0.4 else 0x80 + r.randint(3, 33))
            out += bytes(r.getrandbits(8) for _ in range(r.randint(0, 4)))
        elif mode < 0.45:
            out = bytearray(pair(r.choice([0x44, 0x45, 0x46])))
            out += bytes(r.getrandbits(8) for _ in range(r.randint(0, 3)))
        n = len(out)
        cut = r.choice([n, n, n, max(0, n - 1), max(0, n - 2), max(0, n - 3), 2 if r.random() < 0.2 else n])
        if 0.3 <= mode < 0.45:
            cut = r.choice([2, 3, 4, 5, n])
        data = bytes(out) + bytes(40)
        p = rnd(c, len(data) + 8)
        e.wbytes(p, data)
        return [base, p, p + cut, rnd(c, 8)]
    return g


S(0x627fd0, 'scan_name2_be', 'cdecl', None, ret='eax', gen=_mk(False))
S(0x62a030, 'scan_name2_le', 'cdecl', None, ret='eax', gen=_mk(True))
