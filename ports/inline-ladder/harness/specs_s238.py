"""specs_s238.py - ladder thread batch 238: ZLNKWHANDS::GetAnimNameFromCollision (0x474070)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
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
    m = max(len(a), len(b))
    e.ret(eax=_cmp(a.ljust(m, b'\0'), b.ljust(m, b'\0'), m))


def _imports(c):
    # The exe's striwcmp calls strchr, _memicmp and _stricmp through its import table (batch 54's stand-ins, same code).
    for nm, h in (('strchr', _strchr), ('_memicmp', _memicmp), ('_stricmp', _stricmp)):
        c.emu.stub_import(nm, h)
import ladder_kit as K


def _ganc(c):
    e, r = c.emu, c.rng
    _imports(c)
    self_ = K.rnd(c, 0x400)
    e.w32(self_, K.vt(c, 'hands', {0x1e0: (1, lambda e2, a: (r.choice([0, 1, 0x100, r.getrandbits(32)]), None, None)),
                                   0x21c: (1, lambda e2, a: (r.choice([0, 1]), None, None))}, nslots=0x240))
    coli = K.rnd(c, 0x10)
    e.w8(coli, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10, 0xff]))
    e.w8(coli + 1, r.choice([0, 1, 0x7f]))
    item = 0
    if r.random() < 0.85:
        item = K.rnd(c, 0x40)
        kind = r.choice([8, 9, 2, 0xb, r.randint(0, 12)])
        e.w32(item, K.vt(c, 'item', {0x330: (0, lambda e2, a: (kind, None, None))}, nslots=0x100))
        if r.random() < 0.8:
            e.w32(item + 4, e.cstr(r.choice(['Poison', 'Carrot', 'Gun', 'Knife'])))
    return [self_, coli, r.getrandbits(32), item]


S(0x474070, 'ZLNKWHANDS::GetAnimNameFromCollision', 'thiscall', None, ret='eax', gen=_ganc, note='batch238')
