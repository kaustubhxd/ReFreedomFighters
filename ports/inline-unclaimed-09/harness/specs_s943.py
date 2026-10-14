"""specs_s943.py - area 56 residue 15, claim A2: 0x439270 (GetInputList) and 0x46a730 (unnamed).

0x439270: the table at 0x6e48c0 is written into the exe image before each run (host writes; the image is restored per run):
the first dword is zero in about one case in five (the early return); otherwise up to four entries with non-zero first
dwords, then a zero entry, so the walk terminates. idx is random in [-1, 5] so both the found and the not-found paths run.
0x46a730: the object is 0x100 random bytes; the flags are random, so bit 0 and bit 2 both occur. Its callees are GUESS
recording stubs: 0x46a4f0 (logs its object), 0x4690b0 (logs its two arguments, plain ret), 0x45c510 (logs its argument)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_getinput(c):
    e = c.emu
    rng = c.rng
    base = 0x6e48c0
    if rng.random() < 0.2:
        e.w32(base, 0)
    else:
        n = rng.randint(1, 4)
        for i in range(n):
            e.w32(base + 16 * i, rng.randint(1, 0xffffffff))
            for k in range(1, 4):
                e.w32(base + 16 * i + 4 * k, rng.getrandbits(32))
        e.w32(base + 16 * n, 0)
    return [rng.randint(-1, 5) & 0xffffffff]


def _hook(name):
    def h(e2, r):
        e2.calllog.append((name, e2.reg('ecx')))
        e2.ret(eax=0, argbytes=0)
    return h


def _free(e2, r):
    e2.calllog.append(('Free4690b0', e2.arg32(0), e2.arg32(1)))
    e2.ret(argbytes=0)


def _c510(e2, r):
    e2.calllog.append(('C45c510', e2.arg32(0)))
    e2.ret(argbytes=0)


def _gen_unnamed(c):
    c.emu.hook(0x46a4f0, _hook('Base46a4f0'))
    c.emu.hook(0x4690b0, _free)
    c.emu.hook(0x45c510, _c510)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x439270, 'ZInputActions::GetInputList (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen_getinput,
  note='unclaimed-56 A2; table at 0x6e48c0 written per case')
S(0x46a730, 'unnamed 0x46a730 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_unnamed,
  note='unclaimed-56 A2; GUESS name; callees stubbed (unverified)')
