"""specs_s31135.py - h1 tier B batch 31135: 0x531810, 0x63ace0 (Sonnet verified), 0x496ce0 (h1 attempt)."""
from pe_emu import REGS
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def clob(c):
    j = r32(c)
    return lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)


def g531810(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x531740, 2, ret=r.choice([0, 1, 0x10000, 0x10001, r32(c)]), pop=8, this=True, deref={0: 2}, side=clob(c))
    hook_rec(c, 0x530890, 3, ret=r32(c), pop=12, this=True)
    P = rnd(c, 0x100)
    e.w32(P + 0x38, r.choice([1, 2, 5, r32(c)]))
    recs = rnd(c, 0x60)        # 12-byte records, index (this[0x16]) 1..3
    e.w32(P + 0x5a, recs)
    tab = rnd(c, 0x60)         # byte table at P[0x78], addressed by word*10
    e.w32(P + 0x78, tab)
    e.w32(P + 0x6c, r32(c))
    for i in range(4):
        e.w32(recs + 12 * i, r.choice([0, 1, 2, 3]))      # word index into the byte table (kept small)
    me = rnd(c, 0x30)
    e.w32(me, P)
    e.w32(me + 0x16, r.choice([0, 1, 2, 3, 0x10000, r32(c) & 0x3]))   # only the low word is tested
    arg = rnd(c, 0x10)
    return [me, arg]


def g63ace0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3])
    nodes = [rnd(c, 0x400) for _ in range(n)]
    for i, nd in enumerate(nodes):
        full = r.random() < 0.5
        e.w32(nd + 0, r32(c))
        w = 0xffff if full else r.randrange(0, 6)
        e.w32(nd + 2, w | (r.getrandbits(16) << 16) if False else (e.r32(nd + 2) & 0xffff0000) | w)
        e.w32(nd + 8, nodes[i + 1] if i + 1 < n else (nodes[0] if r.random() < 0.3 else 0))
    new = rnd(c, 0x400)
    e.w32(new + 2, (e.r32(new + 2) & 0xffff0000) | r.choice([0xffff, 0, 1, 3]))
    e.w32(new + 8, 0)
    me = rnd(c, 0x20)
    e.w32(me + 8, nodes[0] if nodes else 0)

    def side(em, k):
        if r.random() < 0.85:
            em.w32(me + 8, new)
    hook_rec(c, 0x63b240, 0, ret=r.choice([0, 1, 1, 0x100, r32(c)]), pop=0, this=True, side=side)
    return [me]


def g496ce0(c):
    clear_hooks(c)
    r = c.rng
    # Simple: 0x440ce0 is called once to get a range, then return 0 or 1 based on arg
    hook_rec(c, 0x440ce0, 1, ret=0, pop=4, this=False)
    arg = r.randint(0, 100)
    return [arg]


S(0x531810, 'GUESS look up record via 531740, bit length of table byte, pack arg words, call 530890', 'thiscall', None, ret='eax', gen=g531810, note='batch31135')
S(0x63ace0, 'GUESS take a free slot from the chained pool (0xffff = full), else grow via 63b240', 'thiscall', None, ret='eax', gen=g63ace0, note='batch31135')
# Superseded by the valid stdcall spec in specs_s31136.py.
