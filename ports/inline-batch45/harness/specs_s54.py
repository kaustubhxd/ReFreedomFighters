"""specs_s54.py - inline session batch 54: striwcmp and stricmpend.
The exe calls strchr, _memicmp and _stricmp through its import table. These have no code in the exe, so the spec
gives them Python versions with the C-locale behaviour (ASCII case folding; results are differences of the folded
bytes). Both runs use the same versions, so the test checks the exe's own logic around them."""
from pilot import S


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


def _strchr(e, r):
    s, ch = e.arg32(0), e.arg32(1) & 0xff
    i = 0
    while True:
        b = e.mu.mem_read(s + i, 1)[0]
        if b == ch:
            e.ret(eax=s + i)
            return
        if b == 0:
            e.ret(eax=0)
            return
        i += 1


def _cmp(a, b, n):
    for i in range(n):
        x, y = _low(a[i]), _low(b[i])
        if x != y or x == 0:
            return (x - y) & 0xffffffff
    return 0


def _memicmp(e, r):
    n = e.arg32(2)
    e.ret(eax=_cmp(_rd(e, e.arg32(0), n), _rd(e, e.arg32(1), n), n) if n else 0)


def _stricmp(e, r):
    a, b = _rd(e, e.arg32(0)) + b'\0', _rd(e, e.arg32(1)) + b'\0'
    e.ret(eax=_cmp(a, b, max(len(a), len(b))) if len(a) == len(b) else _cmp(a.ljust(max(len(a), len(b)), b'\0'),
                                                                            b.ljust(max(len(a), len(b)), b'\0'),
                                                                            max(len(a), len(b))))


def _setup(c):
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        c.emu.stub_import(nm, h)


WORDS = [b'WaterWalk', b'WaterSwim', b'waterwalk01', b'WATERSWIM', b'Water', b'Walk', b'FirstAid_Large', b'Grenade',
         b'Molotov', b'', b'a', b'ab', b'Swim', b'WaterWalkSwim']
PATS = [b'WaterWalk*', b'WaterSwim*', b'*Swim', b'*Swim*', b'Water*Walk', b'*', b'**', b'', b'*a*b*', b'W*',
        b'*walk', b'FirstAid_Large', b'Grenade*', b'*Aid*', b'a*', b'*ter*im', b'Water*Swim*', b'x*']


def _str(c, s):
    a = c.emu.alloc(len(s) + 8, 4)
    c.emu.wbytes(a, s + b'\0')
    return a


def _mutate(r, s):
    s = bytearray(s)
    if s and r.random() < 0.3:
        i = r.randrange(len(s))
        s[i] = s[i] ^ 0x20 if 65 <= (s[i] | 0x20) <= 122 else s[i]
    if r.random() < 0.15:
        s += bytes([r.choice(b'aZ_*1')])
    return bytes(s)


def _sw(c):
    r = c.rng
    return [_str(c, _mutate(r, r.choice(WORDS))), _str(c, _mutate(r, r.choice(PATS)) if r.random() < 0.8
                                                       else bytes(r.choice(b'ab*') for _ in range(r.randint(0, 6))))]


def _se(c):
    r = c.rng
    return [_str(c, _mutate(r, r.choice(WORDS))), _str(c, _mutate(r, r.choice(WORDS + [b'Walk', b'swim', b'K'])))]


S(0x4cc780, 'stricmpend', 'fastcall', None, ret='eax', setup=_setup, gen=_se, note='batch54; CRT imports as Python')
S(0x4cc850, 'striwcmp', 'fastcall', None, ret='eax', setup=_setup, gen=_sw, note='batch54; CRT imports as Python')
