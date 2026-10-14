"""specs_s348.py - gap band, batch 348: 0x6200d0 (cdecl, one argument: a string, normalized in place). Strings mix letters, CR, LF, NUL-free
bytes; a CR is sometimes followed by LF, sometimes not, and sometimes ends the string. The buffer is writable and has room for the input."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    alphabet = b'abcXYZ019 \r\n\r\r\n'
    body = bytes(rng.choice(alphabet) for _ in range(rng.randrange(0, 24)))
    if rng.random() < 0.2:
        body = body + b'\r'
    buf = e.alloc(len(body) + 16, 4)
    e.wbytes(buf, body + b'\0' + rng.randbytes(15))
    return [buf]


S(0x6200d0, 'normalizeNl6200d0 (GUESS)', 'cdecl', None, ret=None, gen=_gen, note='batch348; plain ret')
