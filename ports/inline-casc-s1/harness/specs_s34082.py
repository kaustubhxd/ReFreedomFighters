"""specs_s34082.py - six queue items. 0x627420: the exe table at 0x6be5b0 is read in the spec so the pairs match in a half of the cases."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _filt(ids):
    def g(c):
        clear_hooks(c)
        r = c.rng
        a = rnd(c, 0x20)
        c.emu.w32(a + 0xc, r.choice([0, 0, 1, r.getrandbits(32)]))
        return [a, r.choice(ids + [0xf, 0x1c, 0x1c, 0, 0x1d, r.getrandbits(32), 0xffffffff])]
    return g


def _g531220(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x80)
    c.emu.wbytes(me + 0x58, r.choice([0, 1, 2, 4, 5]).to_bytes(2, 'little'))
    c.emu.wbytes(me + 0x52, r.choice([0, 1, 3, 5]).to_bytes(2, 'little'))
    c.emu.wbytes(me + 0x5a, rnd(c, 0x100).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x54, rnd(c, 0x100).to_bytes(4, 'little'))
    return [me]


def _g6228a0(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x10)
    n = r.choice([0, 1, 2, 5])
    sb = bytes(r.randrange(1, 255) for _ in range(n)) + b'\0'
    c.emu.wbytes(s, sb)
    p = rnd(c, 0x20)
    mode = r.choice(['match', 'match', 'short', 'long', 'diff', 'rand'])
    body = bytearray(sb[:-1])
    if mode == 'diff' and body:
        body[r.randrange(len(body))] ^= 0x10
    if mode != 'rand':
        c.emu.wbytes(p, bytes(body))
    end = p + len(body) + {'match': 0, 'short': -1, 'long': 1, 'diff': 0, 'rand': r.randrange(0, 4)}[mode]
    return [r.getrandbits(32), p, end & 0xffffffff, s]


def _g54e630(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x80)
    c.emu.wbytes(me + 0x37, r.choice([0, 1, 2, 3, 4, 5, 8, 0xffffffff, 0x80000000]).to_bytes(4, 'little'))
    c.emu.wbytes(me + 0x3b, r.choice([0, 1, 2, 5, 9, 0xfffffffe]).to_bytes(4, 'little'))
    return [me, r.choice([0, 1, 1, 2, 2, 3, r.getrandbits(32)])]


def _g627420(c):
    clear_hooks(c)
    r = c.rng
    tab = bytes(c.emu.rbytes(0x6be5b0, 6))
    p = rnd(c, 0x40)
    good = bytearray()
    for i in range(6):
        good += bytes([0, tab[i]])
    k = r.choice([6, 6, 6, 5, 3, 0, 1])
    data = bytes(good[:2 * k]) + bytes(r.getrandbits(8) for _ in range(12 - 2 * k))
    if r.random() < 0.15:
        data = bytes(r.getrandbits(8) for _ in range(12))
    c.emu.wbytes(p, data)
    ln = r.choice([12, 12, 13, 16, 11, 5, 0, 0x30])
    out = rnd(c, 0x10)
    return [r.getrandbits(32), p, p + ln, out]


S(0x62cf90, 'GUESS event filter E', 'cdecl', None, ret='eax', gen=_filt([0x11, 0x11]), note='batch34082')
S(0x62d510, 'GUESS event filter F', 'cdecl', None, ret='eax', gen=_filt([0x12, 0x29]), note='batch34082')
S(0x531220, 'GUESS zero two record lists', 'thiscall', None, ret=None, gen=_g531220, note='batch34082')
S(0x6228a0, 'GUESS exact string match in range', 'cdecl', None, ret='eax', gen=_g6228a0, note='batch34082')
S(0x54e630, 'GUESS switch mode and clear slots', 'thiscall', None, ret=None, gen=_g54e630, note='batch34082')
S(0x627420, 'GUESS check six-pair header', 'cdecl', None, ret='eax', gen=_g627420, note='batch34082')
