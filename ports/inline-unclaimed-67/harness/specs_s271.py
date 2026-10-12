"""specs_s271.py - unclaimed area 67: 0x4d4960 (cursor search). The IAT _strnicmp (0x676408) is stubbed by name:
case-insensitive compare of the first n bytes, cdecl, returns 0 when equal."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 1)
    c.emu.wbytes(a, s.encode() + b'\x00')
    return a


def _install(c):
    e = c.emu

    def strnicmp(e, r):
        a, b, n = e.arg32(0), e.arg32(1), e.arg32(2)
        x = bytes(e.rbytes(a, n)) if n else b''
        y = bytes(e.rbytes(b, n)) if n else b''
        xa = x.lower()
        ya = y.lower()
        e.ret(eax=0 if xa == ya else 1, argbytes=0)
    e.stub_import('_strnicmp', strnicmp)


def _case(c):
    _install(c)
    words = ['Move', 'Fire', 'Jump', 'Use']
    arr = _rnd(c, 0x20)
    ptrs = []
    for w in words:
        ptrs.append(_cstr(c, w))
    for k, p in enumerate(ptrs):
        c.emu.w32(arr + 4 * k, p)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 4, arr)
    want = c.rng.choice(words + ['move', 'Nope', ''])
    c.emu.w32(o + 0xc, _cstr(c, want) if c.rng.random() < 0.9 else 0)
    c.emu.w32(o + 0x10, c.rng.choice([0, 1, 2, 3, 4]))   # counts within the array (the original indexes arr[n-1])
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x4d4960, 'GUESS FUN_4d4960 (cursorSearch)', 'thiscall', None, ret='eax', gen=_case,
  note='batch271; _strnicmp stubbed by name (case-insensitive)')
