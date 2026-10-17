"""specs_s0616.py - fresh-06 batch 16 (docs/20-fresh-06.md): IAT imports stubbed with stub_import."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def imp(c, name, nargs, ret, pop=0):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, args))
        v = ret(e, args) if callable(ret) else ret
        e.ret(eax=v, argbytes=pop)
    c.emu.stub_import(name, h)


def _steam(c):
    imp(c, 'SteamAPI_RestartAppIfNecessary', 1, c.rng.choice([0, 0, 1, 0x100, 0xffffff00]))
    imp(c, 'SteamAPI_Init', 0, c.rng.choice([0, 1, 0x100, 0xffffff01]))
    hk(c, 0x42ab62, 1, pop=0)
    return []


def _wcls(c):
    c.emu.w32(0x7f6410, c.rng.choice([0, 0, 1]))
    k = c.rng.randrange(0, 5)
    st = [0]

    def gci(e, a):
        e.calllog.append(('name', e.rbytes(a[1], 24), e.r32(a[2])))
        st[0] += 1
        return 1 if st[0] <= k else 0
    imp(c, 'GetClassInfoExA', 3, gci, pop=12)
    hk(c, 0x42ac56, 3, pop=0, fn=lambda e, a: e.wbytes(a[0], b'%05x\0' % a[2]))
    return [c.rng.getrandbits(32)]


def _blk(c):
    imp(c, 'malloc', 1, lambda e, a: rnd(c, 0x40) + c.rng.randrange(0, 16))
    hk(c, 0x4cfb30, 2, ecx=True, ret=c.rng.getrandbits(32))
    this = obj(c, 0xd630)
    n = c.rng.choice([0, 0, 1, 3])
    c.emu.w32(this + 0x1c8, n)
    for i in range(n):
        c.emu.w32(this + 8 + 4 * i, c.rng.getrandbits(32))
    c.emu.w32(this + 0x207, c.rng.choice([0, 9999, 10000, 0xffffffff, 5]))
    k = c.rng.randrange(0, 4)
    c.emu.w32(this + 0xd628, k)
    c.emu.w32(this + 0xc628 + 4 * k, rnd(c, 0x10))
    c.emu.w32(this + 0x1ea, vt(c, 'trk', {0: (1, 0)}))
    return [this]


S(0x6078a0, 'Steam start-up check (GUESS) cdecl', 'cdecl', None, ret='al', gen=_steam)
S(0x6528a0, 'free window class name (GUESS) thiscall', 'thiscall', None, gen=_wcls)
S(0x4cfbe0, '2 MB block get (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_blk)
