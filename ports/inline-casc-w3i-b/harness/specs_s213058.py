"""specs_s213058.py - compressed stream read with an inflate step, window shifting and log lines, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g4d7350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    X = obj(c, 0x20, {0x10: pystub(c, 3, ret=r.getrandbits(32), this=True),
                      0x14: pystub(c, 3, ret=lambda emu, k: r.choice([0, 5, 0x100, 0x3ff, r.getrandbits(32)]), this=True),
                      0xc: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x10)
    this = rnd(c, 0x40)
    e.w32(this + 0x15, X)
    e.w32(this + 0x11, r.getrandbits(32))
    s = rnd(c, 0x440)
    rec = rnd(c, 0x20)
    e.w32(s + 0x26, rec)
    mode = r.choice([0, 8, 8, 8, 8, 8, 1, 7, 0x108, 0x10, r.getrandbits(16)])
    e.wbytes(s + 8, mode.to_bytes(2, 'little'))
    state = r.choice([0, 0, 0, 0, 1, 2, 0xffffffff])
    e.w32(s + 0x42e, state)
    e.w32(rec + 4, r.choice([0, 0x10, 0x200, 0x400, r.randint(0, 0x400)]))
    e.w32(s + 0x12, r.choice([0, 0x100, 0x1000, 0x400, r.getrandbits(32)]))
    e.w32(s + 0x1e, r.choice([0, 0x10, 0x400, r.getrandbits(32)]))
    seq = []
    for _ in range(r.randint(1, 3)):
        seq.append((0, r.randint(1, 100)))
    seq.append((r.choice([-3, -2, -1, -3, -2, -1, 2, 3, -4, 7, 1, r.randint(-8, 8)]), r.randint(1, 100)))
    if r.random() < 0.25:
        seq[-1] = (r.choice([0, 1]), 0)

    if seq[-1][0] == 0:
        seq[-1] = (0, 0)       # a zero result must end the loop through an empty record, or it never ends

    def infl_ret(emu, k):
        return seq[min(k, len(seq) - 1)][0] & 0xffffffff

    def infl_side(emu, k):
        emu.w32(rec + 0x10, seq[min(k, len(seq) - 1)][1])
    hook_rec(c, 0x62f5d0, 2, ret=infl_ret, side=infl_side)

    def copy(emu, k):
        d, s_, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        if 0 < n <= 0x400:
            emu.wbytes(d, emu.rbytes(s_, n))
    hook_rec(c, 0x634d22, 3, ret=lambda emu, k: emu.arg32(0), pop=0, side=copy)
    M = obj(c, 0x20, {0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)
    dst = rnd(c, 0x400)
    return [this, s, dst, r.choice([0, 1, 0x10, 0x100, r.randint(0, 0x500)])]


S(0x4d7350, 'read_stream_inflate', 'thiscall', None, ret='eax', gen=g4d7350)
