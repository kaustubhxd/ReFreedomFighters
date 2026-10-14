"""specs_s989.py - area 56 claim A55 (0x5a0290, InitHitAnims, area 09 hit-reaction leaf).

The table is a global record at [0x7003b8]+0xb55 (begin, end, capacity). Each case: the entries are 0 to 3 blocks of 0x40 bytes at a
heap buffer (random bytes, so each entry's first two dwords are random names for the import); end = begin + n*0x40 and capacity is end
(the growth path, one case in four) or end + 0x40*k (copy path). The import slot 0x676414 is written to a GUESS recording stub (cdecl,
two arguments; returns zero in about one case in three, else a random dword). Helper 0x4e5330 is hooked (GUESS; returns a random dword).
Slots 0x2c0 and 0x2c4 (thiscall, no arguments) return a random non-null pointer in about 4 cases in 5, else zero; slot 0x21c (thiscall,
one argument) returns a random dword. 0x5a3550 is hooked (GUESS; stdcall, two arguments). this is a 0x1000-byte object. ret=None (void).
"""
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    imp_rv = 0 if rng.random() < 1 / 3 else (rng.getrandbits(32) | 1)
    imp_rv2 = 0 if rng.random() < 1 / 3 else (rng.getrandbits(32) | 1)
    calls = {'n': 0}

    def imp(e2, r):
        calls['n'] += 1
        e2.calllog.append(('IMP', e2.arg32(0), e2.arg32(1)))
        e2.ret(eax=imp_rv if calls['n'] % 2 else imp_rv2, argbytes=0)

    imp_stub = e._new_stub('imp676414', imp)
    e.w32(0x676414, imp_stub)

    def hname(e2, r):
        e2.calllog.append(('H4e5330', e2.reg('ecx')))
        e2.ret(eax=rng.getrandbits(32), argbytes=0)

    e.hook(0x4e5330, hname)

    def hgrow(e2, r):
        e2.calllog.append(('G5a3550', e2.arg32(0), e2.rbytes(e2.arg32(1), 64)))
        e2.ret(argbytes=8)

    e.hook(0x5a3550, hgrow)

    def vtcall(name, nargs_):
        def h(e2, r):
            if nargs_ == 0:
                e2.calllog.append((name, e2.reg('ecx')))
            else:
                e2.calllog.append((name, e2.reg('ecx'), e2.arg32(0)))
            if nargs_ == 0:
                p = 0 if rng.random() < 0.2 else (rng.getrandbits(32) | 1)
                e2.ret(eax=p, argbytes=0)
            else:
                e2.ret(eax=rng.getrandbits(32), argbytes=4)
        return h

    vt = e.fake_vtable('vt5a0290', 0x800, {0x2c0: vtcall('V2c0', 0), 0x2c4: vtcall('V2c4', 0), 0x21c: vtcall('V21c', 1)})
    this = e.alloc(0x1000, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x1000)))
    e.w32(this, vt)

    n = rng.randint(0, 3)
    buf = _rnd(c, 0x40 * (n + 4))
    begin = buf
    end = begin + n * 0x40
    if rng.random() < 0.25:
        cap = end
    else:
        cap = end + 0x40 * rng.randint(1, 3)
    cfg = e.alloc(0x1000, 4)
    e.wbytes(cfg, bytes(0x1000))
    base = 0x7003b8
    e.w32(base, cfg)
    e.w32(cfg + 0xb55, begin)
    e.w32(cfg + 0xb59, end)
    e.w32(cfg + 0xb5d, cap)
    return [this]


S(0x5a0290, 'unnamed 0x5a0290 (InitHitAnims) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A55; area 09 hit-reaction leaf; import/helper/vtable/growth are GUESS stubs')
