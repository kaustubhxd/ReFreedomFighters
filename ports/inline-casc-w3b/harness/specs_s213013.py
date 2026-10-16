"""specs_s213013.py - batch 213013: parser step, line/column scanner with 0x62c640 classes, kind-driven field select, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def g62d690(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(o + 0xc, 0)
    c.emu.w32(o + 4, r.choice([1, 1, 2, 0, r.getrandbits(32)]))
    b = r.randint(0xd, 0x28) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.1:
        b = 0x1c
    return [o, b]


def _c640(a, b):
    a &= 0xff
    b &= 0xff
    i = a - 0xd8
    if i < 0 or i > 0x27:
        return 0x1d
    if i < 4:
        return 7
    if i < 8:
        return 8
    if i < 39:
        return 0x1d
    return 0x1d if b < 0xfe else 0


def _cls(tab, buf, p):
    if buf[p] == 0:
        return tab[buf[p + 1]]
    return _c640(buf[p], buf[p + 1])


def _walk(tab, buf, k):
    """positions at the end of each loop iteration (max k iterations), mirroring 0x622ef0 (n >= 1 start)."""
    p = 0
    ends = []
    while len(ends) < k:
        x = (_cls(tab, buf, p) - 5) & 0xffffffff
        if x > 5 or x in (0, 3):
            p += 2
        elif x == 1:
            p += 3
        elif x == 2:
            p += 4
        elif x == 4:
            p += 2
            ends.append(('mid', p))
            if True:
                if _cls(tab, buf, p) == 0xa:
                    p += 2
        else:
            p += 2
        ends.append(('end', p))
    return ends


def g622ef0(c):
    clear_hooks(c)
    r = c.rng
    base = rnd(c, 0x4c + 0x100 + 4)
    hot = [5, 6, 7, 8, 9, 0xa, 0xa, 0x20, 0xb, 0x10, 0x1d, 9, 10]
    tab = [(r.choice(hot) if r.random() < 0.7 else r.getrandbits(8)) for _ in range(256)]
    c.emu.wbytes(base + 0x4c, bytes(tab))
    n = 0x80
    buf = bytearray(r.getrandbits(8) for _ in range(n))
    for i in range(0, n - 8, 2):
        x = r.random()
        if x < 0.5:
            buf[i] = 0
        elif x < 0.7:
            buf[i] = r.randint(0xd8, 0xff)
            buf[i + 1] = r.choice([0xfd, 0xfe, 0xff, r.getrandbits(8)])
    if True:
        # simulate to find a reachable end: the loop stops when p == end after an iteration
        # (the line-break branch may step past an `end` placed mid-way, so use only final positions)
        iters = []
        p = 0
        for _ in range(r.randint(1, 12)):
            x = (_cls(tab, buf, p) - 5) & 0xffffffff
            if x > 5 or x in (0, 3):
                p += 2
            elif x == 1:
                p += 3
            elif x == 2:
                p += 4
            elif x == 4:
                p += 2
                if _cls(tab, buf, p) == 0xa:
                    p += 2
            else:
                p += 2
            iters.append(p)
        endpos = iters[-1]
        # a position can be visited earlier: the loop would stop at its first visit, which is fine
        # (the original and the port stop at the same place); mid-branch p == end is checked by the callee only once
    p0 = rnd(c, n + 8)
    c.emu.wbytes(p0, bytes(buf))
    st = rnd(c, 8)
    if r.random() < 0.5:
        c.emu.w32(st + 4, r.randint(0, 20))
    return [base, p0, p0 + endpos, st]


def _kobj(c, k):
    return obj(c, 0x20, {0x330: pystub(c, 0, ret=k, this=True)}, nslots=0xcd)


def g473e50(c):
    clear_hooks(c)
    r = c.rng
    k1 = r.randint(0, 13) if r.random() < 0.9 else r.getrandbits(32)
    k2 = r.choice([k1, k1, r.randint(0, 13)])
    kA = _kobj(c, k1)
    kB = _kobj(c, k2)
    s = obj(c, 0x20, {0x350: pystub(c, 0, ret=kA, this=True)}, nslots=0xd5) if r.random() < 0.95 else 0
    p = obj(c, 0x20, {0x350: pystub(c, 0, ret=kB, this=True)}, nslots=0xd5)
    pp = p if r.random() < 0.9 else 0
    slots = {0x50c: pystub(c, 0, ret=s, this=True), 0x508: pystub(c, 0, ret=pp, this=True)}
    this = obj(c, 0x300, slots, nslots=0x144)
    return [this]


S(0x62d690, 'parser_step_f', 'cdecl', None, ret='eax', gen=g62d690)
S(0x622ef0, 'scan_lines_cols_b', 'cdecl', None, ret='eax', gen=g622ef0)
S(0x473e50, 'field_by_kind_cmp', 'thiscall', None, ret='eax', gen=g473e50)
