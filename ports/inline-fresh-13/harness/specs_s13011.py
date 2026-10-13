"""specs_s13011.py - fresh-13 batch 11: 0x498750 ZBaseGeomLists::RemoveBaseGeoms(list, lo, hi, type). Thiscall, 4 args
(ret 0x10), returns eax. Lists of 1..3 blocks (null list in 5%), each with a next pointer (all but the last) and 0..4
(a, b) ranges: a/b are multiples of 8 plus a random type 0..7, a <= b, 0x70 apart in places. The request is built
from one of the ranges (exact, lo-edge, hi-edge, interior split, non-matching type, outside) so every branch runs. The
memmove import is a real memmove; 0x4ce1c0 (2 args), 0x495950 (5 args, random result), *(0x70038c)->vtbl+0x30 (3 args;
null in 20%), *(0x700390)->vtbl+0x20 (2 args, returns a log object) and its vtbl+0x2c (cdecl, 2 args), and the hook at
0x7003b0 are all logged in one call log."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, crt_memmove


def _gen(c):
    r = c.rng
    clear_hooks(c)
    crt_memmove(c)
    log = Log(c, cap=16, width=8)
    loghook(c, log, 0x4ce1c0, 2, 1)
    loghook(c, log, 0x495950, 5, 2, ret=r.getrandbits(32))
    c.emu.w32(0x70038c, vobj(c, 0x40, {0x30: logstub(c, log, 3, 3)}) if r.random() < 0.7 else 0)
    lg = vobj(c, 0x40, {0x2c: logstub(c, log, 2, 5, this=False, pop=False)})
    c.emu.w32(0x700390, vobj(c, 0x40, {0x20: logstub(c, log, 2, 4, ret=lg)}))
    c.emu.w32(0x7003b0, logstub(c, log, 0, 6, this=False))
    me = rnd(c, 0x20)
    base = rnd(c, 0x10)
    c.emu.w32(me + 4, base)
    solo = r.random() < 0.3   # every block holds one range: removing it empties the block (the free path)
    nb = r.choice([1, 1, 2, 3])
    blocks, ranges = [], []
    for i in range(nb):
        npairs = 1 if solo else r.choice([0, 1, 1, 2, 3, 4])
        has_next = i + 1 < nb
        n = int(has_next) + 2 * npairs
        b = rnd(c, 0xc + 4 * max(n, 1) + 8)
        c.emu.w8(b + 8, n)
        blocks.append((b, has_next, npairs))
    for i, (b, has_next, npairs) in enumerate(blocks):
        p = b + 0xc
        if has_next:
            c.emu.w32(p, blocks[i + 1][0])
            p += 4
        for k in range(npairs):
            t = r.randint(0, 7) if r.random() < 0.5 else 3
            a0 = r.randint(0, 1 << 20) * 8
            span = r.choice([0, 0x70, 0xe0, 0x150, r.randint(0, 1 << 10) * 8])
            c.emu.w32(p, a0 | t)
            c.emu.w32(p + 4, (a0 + span) | t)
            ranges.append((a0, a0 + span, t))
            p += 8
    k = r.random()
    if ranges and k < 0.85:
        a0, b0, t = r.choice(ranges)
        mode = 'exact' if solo else r.choice(['exact', 'exact', 'lo', 'hi', 'mid', 'out', 'type'])
        lo, hi = {'exact': (a0, b0), 'lo': (a0, a0 + r.choice([0, 0x70])), 'hi': (b0 - r.choice([0, 0x70]), b0),
                  'mid': (a0 + 0x70, b0 - 0x70), 'out': (a0 - 8, b0 + 8), 'type': (a0, b0)}[mode]
        lo &= 0xffffffff
        hi &= 0xffffffff
        if mode == 'type':
            t = (t + 1) & 7
    else:
        lo, hi, t = r.getrandbits(32) & ~7, r.getrandbits(32) & ~7, r.randint(0, 7)
    lst = 0 if r.random() < 0.05 else blocks[0][0]
    flush(c)
    return [me, lst, lo, hi, t]


S(0x498750, 'ZBaseGeomLists::RemoveBaseGeoms', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13011; block lists; all callees logged; memmove import real')
