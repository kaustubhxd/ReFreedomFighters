"""specs_s19.py - inline session batch 19 (Haiku, overnight): 0x42f840, 0x42c130, 0x430cd0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


TEXT = b'ab \t\r\na b'


def _text(c, buf, size, maxlen):
    """Writes a NUL-terminated string of text bytes into buf; the rest of the buffer is random."""
    r = c.rng
    n = r.randint(0, maxlen)
    body = bytes(r.choice(TEXT) for _ in range(n)) + b'\0'
    c.emu.wbytes(buf, body + bytes(r.getrandbits(8) for _ in range(size - len(body))))


# 0x42f840 fastcall: string in ECX.
def _trim(c):
    buf = c.emu.alloc(48, 4)
    _text(c, buf, 48, 30)
    return [buf]


S(0x42f840, 'trimTail (unknown) fastcall', 'fastcall', None, ret=None, gen=_trim,
  note='batch19; strips trailing space, tab, CR, LF; never examines the first byte')


# 0x42c130 fastcall: dst ECX, src EDX. Returns the stop position.
def _token(c):
    dst = c.emu.alloc(64, 4)
    c.emu.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(64)))
    src = c.emu.alloc(48, 4)
    _text(c, src, 48, 30)
    return [dst, src]


S(0x42c130, 'copyToken (unknown) fastcall', 'fastcall', None, ret='eax', gen=_token,
  note='batch19; skips leading white space, copies to the next white space or NUL, returns the stop position')


# 0x430cd0 thiscall: this holds [begin, end). Stack args: ch (only the low byte is used) and start.
def _find(c):
    r = c.rng
    buf = c.emu.alloc(64, 4)
    n = r.randint(0, 40)
    c.emu.wbytes(buf, bytes(r.choice(TEXT) for _ in range(n)) + bytes(64 - n))
    obj = _rnd(c, 16)
    c.emu.w32(obj, buf)
    c.emu.w32(obj + 4, buf + n)
    ch = r.getrandbits(32) if r.random() < 0.3 else r.choice(b'ab \t')
    start = r.getrandbits(32) if r.random() < 0.1 else r.randint(0, 50)
    return [obj, ch, start]


S(0x430cd0, 'findByteFrom (unknown) thiscall', 'thiscall', None, ret='eax', gen=_find,
  note='batch19; bounds by end - begin (unsigned), returns offset or -1; ch keeps only its low byte')
