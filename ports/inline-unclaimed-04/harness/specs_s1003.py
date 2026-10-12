"""specs_s1003.py - unclaimed-04 batch 3 (docs/20-unclaimed-04.md): ZActor::GetMoveSetId (0x478db0), thiscall with one
stack argument (ret 4); this is unused. The exe calls _stricmp (IAT 0x676414) and atol (IAT 0x6762e0), both cdecl,
and the original code at 0x4cc850 (fastcall, left as original code by the port).
The imports get Python versions with C-locale behaviour (ASCII case folding for _stricmp, the usual atol rules).
Both runs use the same versions, so the test checks the exe's own logic around them."""
from pilot import S

_WORDS = [b'Walk', b'walk', b'WALK', b'wAlK', b'Run', b'run', b'RUN', b'User*', b'user*', b'User', b'Walk5',
          b'Run-3', b'  12', b'+7', b'-4', b'Walkk', b'Ru', b'']
_ALPHA = b'WalkRunUser*0123456789 +-xX'


def _low(b):
    return b + 32 if 65 <= b <= 90 else b


def _rd(e, a, n=None):
    out = bytearray()
    while n is None or len(out) < n:
        b = e.mu.mem_read(a + len(out), 1)[0]
        if n is None and b == 0:
            break
        out.append(b)
    return bytes(out)


def _stricmp(e, r):
    a, b = _rd(e, e.arg32(0)), _rd(e, e.arg32(1))
    res = 0
    for i in range(max(len(a), len(b)) + 1):
        x = _low(a[i]) if i < len(a) else 0
        y = _low(b[i]) if i < len(b) else 0
        if x != y or x == 0:
            res = (x - y) & 0xffffffff
            break
    e.ret(eax=res, argbytes=0)


def _atol(e, r):
    s = _rd(e, e.arg32(0))
    i = 0
    while i < len(s) and s[i] in b' \t\n\v\f\r':
        i += 1
    sign = 1
    if i < len(s) and s[i] in b'+-':
        sign = -1 if s[i] == 0x2d else 1
        i += 1
    v = 0
    while i < len(s) and 48 <= s[i] <= 57:
        v = v * 10 + (s[i] - 48)
        i += 1
    e.ret(eax=(sign * v) & 0xffffffff, argbytes=0)


def _strchr(e, r):
    s, ch = e.arg32(0), e.arg32(1) & 0xff
    i = 0
    while True:
        b = e.mu.mem_read(s + i, 1)[0]
        if b == ch:
            e.ret(eax=s + i, argbytes=0)
            return
        if b == 0:
            e.ret(eax=0, argbytes=0)
            return
        i += 1


def _memicmp(e, r):
    a, b, n = _rd(e, e.arg32(0), e.arg32(2)), _rd(e, e.arg32(1), e.arg32(2)), e.arg32(2)
    res = 0
    for i in range(n):
        x, y = _low(a[i]), _low(b[i])
        if x != y:
            res = (x - y) & 0xffffffff
            break
    e.ret(eax=res, argbytes=0)


def _setup(c):
    # the 0x4cc850 wildcard matcher (original code) calls strchr and _memicmp, so they need stubs too
    c.emu.stub_import('strchr', _strchr)
    c.emu.stub_import('_memicmp', _memicmp)
    c.emu.stub_import('_stricmp', _stricmp)
    c.emu.stub_import('atol', _atol)


def _name(c):
    x = c.rng.random()
    if x < 0.35:
        # "User" plus a numeric tail: the 0x4cc850 check passes these and the atol path runs (the common route)
        s = (c.rng.choice([b'User', b'user', b'USER']) + bytes(c.rng.choice(b' +-0123456789x*') for _ in range(c.rng.randrange(0, 7))))
    elif x < 0.6:
        s = c.rng.choice(_WORDS)
    else:
        s = bytes(c.rng.choice(_ALPHA) for _ in range(c.rng.randrange(0, 12)))
    buf = c.emu.alloc(32, 4)
    c.emu.wbytes(buf, s + b'\0' + bytes(32 - len(s) - 1))
    return buf


def _args(c):
    obj = c.emu.alloc(0x100, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [obj, _name(c)]


S(0x478db0, 'ZActor::GetMoveSetId (medium) thiscall', 'thiscall', None, ret='eax', gen=_args, setup=_setup,
  note='unclaimed-04 batch 3; name matches Walk (1), Run (2), 0x4cc850 check (0), else atol(name+4)+3')
