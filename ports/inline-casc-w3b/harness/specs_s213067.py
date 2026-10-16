"""specs_s213066.py - batch 213067: little-endian pair tokenizer with name / value records, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks

CH = {'s5': 0x41, 's22': 0x42, 's24': 0x43, 's29': 0x44, 'c6': 0x45, 'c7': 0x46, 'sp9': 0x47, 'sp10': 0x48, 'k12': 0x49, 'k13': 0x4a,
      'c21': 0x4b, 'c3': 0x4c, 'end11': 0x4d, 'end17': 0x4e}
CLS = {'s5': 5, 's22': 22, 's24': 24, 's29': 29, 'c6': 6, 'c7': 7, 'sp9': 9, 'sp10': 10, 'k12': 12, 'k13': 13, 'c21': 21, 'c3': 3, 'end11': 11, 'end17': 17}


def g6246e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = rnd(c, 0x4c + 0x100 + 4)
    tab = [r.choice([4, 8, 14, 15, 16, 18, 19, 20, 23, 25, 26, 27, 28, 0, 1, 2]) for _ in range(256)]
    for k, ch in CH.items():
        tab[ch] = CLS[k]
    tab[0x20] = 21 if r.random() < 0.8 else r.choice([9, 10, 5, 12, 13, 3])
    tab[0x22] = 12
    tab[0x27] = 13
    e.wbytes(base + 0x4c, bytes(tab))

    def P(lead, ch):
        return bytes([ch, lead])

    def pair(k):
        return P(0, CH[k] if isinstance(k, str) else k)
    out = bytearray(bytes(r.getrandbits(8) for _ in range(2)))
    names = ['s5', 's22', 's24', 's29']
    for _ in range(r.randint(3, 30)):
        x = r.random()
        if x < 0.2:
            out += pair(r.choice(names))
        elif x < 0.38:
            out += pair('c21') if r.random() < 0.6 else P(0, 0x20)
        elif x < 0.5:
            out += pair('k12') if r.random() < 0.5 else P(0, 0x22)
        elif x < 0.62:
            out += pair('k13') if r.random() < 0.5 else P(0, 0x27)
        elif x < 0.7:
            out += pair(r.choice(['sp9', 'sp10']))
        elif x < 0.74:
            out += pair('c6') + bytes(r.getrandbits(8) for _ in range(1))
        elif x < 0.78:
            out += pair('c7') + bytes(r.getrandbits(8) for _ in range(2))
        elif x < 0.81:
            out += pair('c3')
        elif x < 0.85:
            out += pair(r.choice(['end11', 'end17']))
        elif x < 0.93:
            out += P(0, 0x20) + r.choice([pair('k12'), pair('k13'), P(0, 0x20), pair('s29'), P(0xd8, 0x41) + P(0, 0), P(0xe0, 0x30),
                                              P(0, r.choice([0x41, 0x4b, 0x30, 0x7f, 0x61, 0x49])), P(r.getrandbits(8), 0x20)])
        elif x < 0.96:
            out += P(r.choice([0xd8, 0xd9, 0xda, 0xdb]), r.getrandbits(8)) + bytes(r.getrandbits(8) for _ in range(2))
        else:
            lead = r.choice([0xdc, 0xe0, 0xf0, 0xff, r.getrandbits(8) | 1])
            out += P(lead, r.getrandbits(8)) + (bytes(2) if 0xd8 <= lead <= 0xdb else b'')
    for k in ('k12', 'end11', 'k13', 'end11', 'k12', 'end11'):
        out += pair(k)
    out += bytes(8)
    p = rnd(c, len(out) + 8)
    e.wbytes(p, bytes(out))
    import os
    if os.environ.get('DBGS'): print('STREAM', bytes(out).hex(), 'tab20', tab[0x20], flush=True)
    mx = r.choice([0, 1, 2, 3, 4, 6, 6, 20])
    o = rnd(c, 0x10 * (mx + 2))
    return [base, p, mx, o]


S(0x6246e0, 'le_pair_value_tokenizer', 'cdecl', None, ret='eax', gen=g6246e0)
