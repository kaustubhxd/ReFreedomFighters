"""specs_s210077.py - Sonnet-w3a: 0x4d2b40. Records {size dword, flag byte, packed length dword, ..., data at +0x11} in a buffer at this+8 (total bytes at this+0xc); the import at IAT 0x67640c is a memcmp-behaving stub (returns the real comparison of the bytes) that records its arguments."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g4d2b40(c):
    clear_hooks(c)
    e = c.emu
    name = bytes(c.rng.choice(b'abc') for _ in range(c.rng.choice([0, 1, 2, 4]))) + b'\0'
    st = rnd(c, 0x20); e.wbytes(st, name)
    explicit = c.rng.random() < 0.4
    ln = c.rng.choice([len(name), len(name), 1, 3, 5]) if explicit else 0
    want = ln if ln else len(name)

    def cmpfn(emu, k):
        n = emu.arg32(2)
        a = emu.rbytes(emu.arg32(0), n)
        b = emu.rbytes(emu.arg32(1), n)
        return 0 if a == b else 1
    e.w32(0x67640c, pystub(c, 3, ret=cmpfn, pop=0))
    nrec = c.rng.choice([0, 1, 2, 3, 4])
    buf = rnd(c, 0x200)
    off = 0
    for _ in range(nrec):
        size = c.rng.choice([0x15, 0x18, 0x20, 0x30])
        e.w32(buf + off, size)
        e.wbytes(buf + off + 4, bytes([c.rng.choice([0, 1, 1, 0x80])]))
        _ub(c, buf + off + 5, want if c.rng.random() < 0.6 else c.rng.choice([want + 1, 0, _r(c)]))
        data = name if c.rng.random() < 0.5 else bytes(c.rng.choice(b'abc') for _ in range(len(name)))
        e.wbytes(buf + off + 0x11, data + bytes(8))
        off += size
    if nrec == 0:  # a matching record exists but the declared total is 0
        e.w32(buf, 0x15); e.wbytes(buf + 4, b'\x01'); _ub(c, buf + 5, want); e.wbytes(buf + 0x11, name + bytes(8))
    s = rnd(c, 0x20)
    e.w32(s + 8, buf)
    e.w32(s + 0xc, off if (c.rng.random() < 0.8 or off == 0) else off - 1)
    return [s, st, ln]


S(0x4d2b40, 'find_record_by_name', 'thiscall', None, ret='eax', gen=g4d2b40, note='batch210077')
