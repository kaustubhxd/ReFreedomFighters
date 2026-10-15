"""specs_s41002.py - t2 (Sonnet) batch 41002: 0x58a9b0. Slots 0x48, 0x6c, 0x68, 0x50 are recorders that write to the caller's local; 0x633654 (/GS) is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g58a9b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8, -1 & 0xffffffff, 0x80000000, 0xffffff00])
    vec = [bytes(r.getrandbits(8) for _ in range(12)) for _ in range(10)]
    b68 = [r.getrandbits(8) for _ in range(10)]
    d50 = [bytes(r.getrandbits(8) for _ in range(4)) for _ in range(10)]

    def s48(emu, k):
        emu.w32(emu.arg32(0), n)
    def s6c(emu, k):
        emu.wbytes(emu.arg32(0), vec[k % 10])
    def s68(emu, k):
        emu.wbytes(emu.arg32(0), bytes([b68[k % 10]]))
    def s50(emu, k):
        emu.wbytes(emu.arg32(0), d50[k % 10])
    me = obj(c, 0x80, {0x48: pystub(c, 1, this=True, nullflag=(0,), side=s48),
                       0x6c: pystub(c, 1, this=True, nullflag=(0,), side=s6c),
                       0x68: pystub(c, 1, this=True, nullflag=(0,), side=s68),
                       0x50: pystub(c, 1, this=True, nullflag=(0,), side=s50)}, nslots=0x70 // 4)
    hook_rec(c, 0x633654, 0, pop=0, ret=me, side=_log('gs'))   # the real /GS check leaves EAX alone
    out = rnd(c, 0x300)
    c0 = r.choice([0, 1, 2, 5, 7])
    e.w32(out, c0)
    c.mask = [(out + 4 + 21 * (c0 + i), 4) for i in range(n if 0 < n <= 8 else 0)]   # first dword of each element is a stale stack word (nothing writes it)
    return [me, out]


S(0x58a9b0, 'GUESS append records to list', 'fastcall', None, ret='eax', gen=g58a9b0, heap_mask=lambda c: c.mask, note='batch41002')
