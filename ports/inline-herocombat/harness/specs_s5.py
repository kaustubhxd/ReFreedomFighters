"""specs_s5.py - inline session batch 5 (Haiku, 2026-10-09 evening): 0x4cf290, 0x4cf470, 0x534050, 0x5f0190, 0x5eade0."""
from pilot import S


def _rnd_obj(c, size):
    o = c.emu.alloc(size, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return o


# 0x4cf290 / 0x4cf470 thiscall: (this, u32* p). Node chain: random nodes, 40% p->NULL. this+0x18 small, +0x1c/+0x20 random nodes.
def _step(c):
    e, r = c.emu, c.rng
    self_ = _rnd_obj(c, 0x30)
    nodes = [_rnd_obj(c, 0x10) for _ in range(3)]
    for n in nodes:
        e.w32(n, r.getrandbits(32) if r.random() < 0.5 else 0)
        e.w32(n + 4, r.choice(nodes + [0]))
    e.w32(self_ + 0x18, r.choice([0, 1, 2, 3, r.getrandbits(32)]))
    e.w32(self_ + 0x1c, r.choice(nodes + [0]))
    e.w32(self_ + 0x20, r.choice(nodes + [0]))
    p = e.alloc(8, 4)
    e.w32(p, 0 if r.random() < 0.4 else r.choice(nodes))
    return [self_, p]


S(0x4cf290, 'stepNodeA (class unknown) thiscall', 'thiscall', None, ret='eax', gen=_step,
  note='batch5; list step via +4')
S(0x4cf470, 'stepNodeB (class unknown) thiscall', 'thiscall', None, ret='eax', gen=_step,
  note='batch5; list step via +0 and this+0x20')


# 0x534050 thiscall: (this, idx). 8 entries at this+0xc. A random chain through the entries ends at 0x80000000.
def _release(c):
    e, r = c.emu, c.rng
    o = _rnd_obj(c, 0xc + 8 * 8 + 16)
    e.w32(o, r.randint(0, 9))
    e.w32(o + 4, r.getrandbits(32))
    perm = list(range(8))
    r.shuffle(perm)
    k = r.randint(1, 8)          # length of the chain actually linked
    chain = perm[:k]
    for i in range(8):
        e.w32(o + 0xc + 8 * i, r.getrandbits(32))
        e.w32(o + 0xc + 8 * i + 4, r.getrandbits(32))
    for i, idx in enumerate(chain):
        nxt = chain[i + 1] if i + 1 < k else 0x80000000
        e.w32(o + 0xc + 8 * idx, nxt)
    arg = 0x80000000 if r.random() < 0.1 else chain[0]
    return [o, arg]


S(0x534050, 'releaseChain (guessed) thiscall', 'thiscall', None, ret=None, gen=_release,
  note='batch5; sentinel 0x80000000; chain built with random links')


# 0x5f0190 thiscall: (this, byte value). Capacity 0..12, count may exceed capacity (error path).
def _push(c):
    e, r = c.emu, c.rng
    o = _rnd_obj(c, 0x10)
    cap = r.randint(0, 12)
    e.w32(o, cap)
    e.w32(o + 4, r.randint(0, cap + 2))
    buf = _rnd_obj(c, 16)
    e.w32(o + 8, buf)
    e.w8(o + 0xc, r.getrandbits(8))
    return [o, r.getrandbits(32)]


S(0x5f0190, 'pushByte (guessed) thiscall', 'thiscall', None, ret='al', gen=_push,
  note='batch5; error path when count+1 > capacity')


# 0x5eade0 thiscall: (this, a, b, c, w, s), ret 0x14. Output dword at +0xc is compared through heap bytes.
def _cell(c):
    e = c.emu
    o = _rnd_obj(c, 0x10)
    r = c.rng
    return [o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x5eade0, 'initCell (guessed) thiscall', 'thiscall', None, ret='eax', gen=_cell,
  note='batch5; w zero-extended, s sign-extended into the high half')
