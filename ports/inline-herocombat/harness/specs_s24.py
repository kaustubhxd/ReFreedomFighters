"""specs_s24.py - inline session batch 24 (Haiku, overnight): 0x4cc4d0, 0x4ba310, 0x493140."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x4cc4d0 fastcall: p in ECX, n in EDX. The buffer has 16 padding bytes before the text, so the walk back stays inside.
BYTES = bytes([0x41, 0xc3, 0xa9, 0x80, 0xbf, 0xe2, 0x82, 0x7f, 0x40, 0x00, 0xff, 0x20])


def _utf8(c):
    r = c.rng
    buf = c.emu.alloc(64, 4)
    c.emu.wbytes(buf, bytes(r.choice(BYTES) for _ in range(64)))
    idx = r.randint(0, 40)
    p = buf + 16 + idx
    n = r.randint(-2, 12)
    return [p, n & 0xffffffff]


S(0x4cc4d0, 'utf8Back (unknown) fastcall', 'fastcall', None, ret='eax', gen=_utf8,
  note='batch24; steps back over continuation bytes (0x80 to 0xbf style) to a lead byte; limit p - n')


# 0x4ba310 thiscall, no args. The global pointer at 0x70039c points to an object with two ints at +0x40 and +0x44.
def _init(c):
    r = c.rng
    obj = _rnd(c, 0x100)
    g = _rnd(c, 0x60)
    c.emu.w32(g + 0x40, r.getrandbits(32))
    c.emu.w32(g + 0x44, r.getrandbits(32))
    c.emu.w32(0x70039c, g)
    return [obj]


S(0x4ba310, 'initScales (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='batch24; writes constants and two int-times-1/1024 floats from the global object')


# 0x493140 thiscall, one stack arg (node). The head at this+0x5d29 is null or a node that takes a back link at +0x24.
def _push(c):
    r = c.rng
    obj = _rnd(c, 0x5e00)
    c.emu.w32(obj + 0x10, r.getrandbits(32))
    c.emu.w32(obj + 0x5d2d, r.getrandbits(32))
    c.emu.wbytes(obj + 0xbc2, bytes([r.choice([0, 1])]))
    if r.random() < 0.6:
        head = _rnd(c, 0x40)
        c.emu.w32(obj + 0x5d29, head)
    else:
        c.emu.w32(obj + 0x5d29, 0)
    node = _rnd(c, 0x40)
    return [obj, node]


S(0x493140, 'pushNode (unknown) thiscall', 'thiscall', None, ret=None, gen=_push,
  note='batch24; list push with a counter, a back link and an or of 0x10 when the flag byte is set')
