"""specs_s213048.py - UTF-16 pair to UTF-8 converters (LE 0x623080, BE 0x623940), Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _mk(le):
    def pair(hi, lo):
        return bytes([lo, hi]) if le else bytes([hi, lo])

    def g(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        inb = bytearray()
        for _ in range(r.randint(0, 7)):
            x = r.random()
            if x < 0.3:
                inb += pair(0, r.randint(0, 0x7f))
            elif x < 0.45:
                inb += pair(0, r.randint(0x80, 0xff))
            elif x < 0.6:
                inb += pair(r.randint(1, 7), r.getrandbits(8))
            elif x < 0.75:
                inb += pair(r.choice([8, 9, 0x20, 0x4e, 0xd7, r.randint(8, 0xd7)]), r.getrandbits(8))
            elif x < 0.88:
                inb += pair(r.randint(0xd8, 0xdb), r.getrandbits(8)) + pair(r.randint(0xdc, 0xdf), r.getrandbits(8))
            else:
                inb += pair(r.choice([0xdc, 0xe0, 0xff, r.randint(0xdc, 0xff)]), r.getrandbits(8))
        if r.random() < 0.12:
            inb += pair(r.randint(0xd8, 0xdb), r.getrandbits(8))   # a high surrogate as the last pair: the loop test must be != , not <
        data = bytes(inb) + bytes(64)
        ip = rnd(c, len(data) + 8)
        e.wbytes(ip, data)
        in_end = ip + len(inb)
        cap = r.choice([r.randint(0, 6), r.randint(0, 30), 40, 40])
        ob = rnd(c, 48)
        out_end = ob + cap
        pin = rnd(c, 8)
        e.w32(pin, ip)
        pout = rnd(c, 8)
        e.w32(pout, ob)
        return [r.getrandbits(32), pin, in_end, pout, out_end]
    return g


S(0x623080, 'utf16le_to_utf8', 'cdecl', None, ret=None, gen=_mk(True))
S(0x623940, 'utf16be_to_utf8', 'cdecl', None, ret=None, gen=_mk(False))
