"""specs_s213027.py - batch 213027: kind-driven field select with log, and a bit finder over a polled mask, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _log_env(c, slot):
    r = c.rng
    m = obj(c, 0x20, {slot: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=m, this=True)}, nslots=0x10)
    c.emu.w32(0x700390, lg)


def g486aa0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.randint(0, 14) if r.random() < 0.92 else r.getrandbits(32)
    a = obj(c, 0x20, {0x330: pystub(c, 0, ret=k, this=True)}, nslots=0xcd)
    if r.random() < 0.4:
        e.w32(a + 4, 0)
    this = rnd(c, 0x50)
    for off in (0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28):
        if r.random() < 0.3:
            e.w32(this + off, 0)
    _log_env(c, 0x2c)
    return [this, a]


def g470b00(c):
    clear_hooks(c)
    r = c.rng
    x = r.choice([0, 1, 2, 3, 0, 1, 2, 3, 4, 4, 5, r.randint(4, 40), r.getrandbits(32)])
    m0 = r.choice([0, 0, 1, 2, 0xf, r.getrandbits(32)])
    need = (1 << (x & 31)) if x > 3 else r.choice([1, 2, 4, 8, 0xf, 3, 5, 9])
    vals = [m0] + [r.getrandbits(32) & ~need if r.random() < 0.6 else r.getrandbits(32) for _ in range(r.randint(0, 3))]
    vals.append(need | r.getrandbits(32) if x > 3 else need)
    if x <= 3:
        vals = [v if i == len(vals) - 1 else v & ~0xf | (v & r.getrandbits(4)) for i, v in enumerate(vals)]
        vals[-1] = need
    if m0 == 0:
        vals = [0, 1]
    this = obj(c, 0x20, {0x334: pystub(c, 0, ret=lambda emu, k, vals=vals: vals[min(k, len(vals) - 1)], this=True)}, nslots=0xce)
    if r.random() < 0.4:
        c.emu.w32(this + 4, 0)
    _log_env(c, 0x30)
    return [this, x]


S(0x486aa0, 'field_by_kind_log2', 'thiscall', None, ret='eax', gen=g486aa0)
S(0x470b00, 'find_set_bit_polled', 'thiscall', None, ret='eax', gen=g470b00)
