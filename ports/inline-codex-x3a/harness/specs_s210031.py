"""specs_s210031.py - Sonnet-w3a: class scanner with tail call, reverse search with register-arg compare, message handler; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ecxdx(emu, k): emu.calllog.append(('cdl', emu.reg('ecx') & 0xff, emu.reg('edx') & 0xff))


def g62ad60(c):
    clear_hooks(c)
    base = rnd(c, 0x180)
    tab = bytes(c.rng.choice([0x19, 0x19, 0x19, 0x12, 0x00, 0x18, 0x1a]) for _ in range(256))
    c.emu.wbytes(base + 0x4c, tab)
    L = c.rng.choice([0, 1, 2, 3, 5, 8])
    buf = rnd(c, 0x20)
    first = c.rng.choice([0x78, 0x78, None])
    data = bytes(c.rng.randrange(0, 256) for _ in range(0x20))
    if first is not None: data = bytes([first]) + data[1:]
    c.emu.wbytes(buf, data)
    hook_rec(c, 0x62b290, 4, ret=_r(c), pop=0)
    return [base, buf, buf + L, rnd(c, 8)]


def g5f1050(c):
    clear_hooks(c)
    hook_rec(c, 0x4cc4b0, 0, ret=lambda e, k: c.rng.choice([0, 0, 0, 1, 0x100]), side=_ecxdx)
    s = rnd(c, 0x20); end = s + c.rng.choice([0, 1, 2, 3])
    buf = rnd(c, 0x20)
    pend = buf + 2
    p = pend + c.rng.choice([0, 1, 2, 3, 4])
    return [rnd(c, 8), s, p, pend, end, _r(c)]


def g562d90(c):
    clear_hooks(c)
    o = obj(c, 0x40, {0x300: pystub(c, 0, ret=_r(c), this=True)}, nslots=0xc1)
    t = obj(c, 0x100, {0xd8: pystub(c, 0, ret=c.rng.choice([0, 0, 1, 0x100, _r(c)]), this=True),
                       0xe0: pystub(c, 0, ret=_r(c), this=True), 0xd0: pystub(c, 1, ret=_r(c), this=True),
                       0x84: pystub(c, 0, ret=o, this=True), 0xdc: pystub(c, 0, ret=_r(c), this=True)}, nslots=0x40)
    c.emu.wbytes(t + 0x87, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(t + 0x4c, c.rng.choice([0, 1])); c.emu.w32(t + 0x50, c.rng.choice([0, 1]))
    hook_rec(c, 0x4f9680, 1, ret=_r(c), this=True)
    return [t, c.rng.choice([0x105, 0x105, 0x106, 0x104, 0, _r(c)])]


S(0x62ad60, 'class_scanner_tail_62b290', 'cdecl', None, ret='eax', gen=g62ad60, note='batch210031')
S(0x5f1050, 'reverse_search_case_insensitive', 'fastcall', None, ret='eax', gen=g5f1050, note='batch210031')
S(0x562d90, 'message_handler_105_106', 'thiscall', None, ret='eax', gen=g562d90, note='batch210031')
