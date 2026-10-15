"""specs_s67504.py - cascade s6 batch 67504 (0x4f28e0, thiscall(), plain ret). The embedded iterator at +0xcb has slots 0x54 / 0x44 (out count pointers) and 0x6c (key, writes the
count: scripted runs of non-zero counts then zero); table slot 0x58 returns objects or null per key, slot 0x4c (3 args) handles; this slot 0x2dc (2 args). Every call is logged."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g4f28e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4, 6])
    keys = [r.getrandbits(32) for _ in range(n + 2)]
    counts = [1] * n + [0]
    state = {'k': 0}

    def mark(v):
        return v if 0x20000000 <= v < 0x30000000 else 1

    def s54(em, k):
        em.calllog.append(('s54', mark(em.arg32(0))))

    def s44(em, k):
        em.calllog.append(('s44', mark(em.arg32(0))))
        state['k'] += 1

    def s6c(em, k):
        em.calllog.append(('s6c', state['k']))
        em.w32(em.arg32(0), counts[min(state['k'], len(counts) - 1)])
        return keys[state['k'] % len(keys)]
    objs = [rnd(c, 0x20) for _ in range(4)]
    present = [r.random() < 0.7 for _ in range(len(keys))]
    it_vt = e.alloc(0x80, 4)
    e.w32(it_vt + 0x54, pystub(c, 1, this=True, stackmark=(0,), side=s54))
    e.w32(it_vt + 0x44, pystub(c, 1, this=True, stackmark=(0,), side=s44))
    e.w32(it_vt + 0x6c, pystub(c, 1, this=True, stackmark=(0,), side=lambda em, k: s6c(em, k), ret=lambda em, k: keys[state['k'] % len(keys)]))
    t = rnd(c, 0x650)
    e.w32(t + 0xcb, it_vt)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[k % 4] if present[k % len(present)] else 0),
                           0x4c: pystub(c, 3, this=True, ret=lambda em, k: 0x1000 + k)}, table_size=0x60)
    # this slot 0x2dc: vtable at [t]
    vt = e.alloc(0x300, 4)
    e.w32(vt + 0x2dc, pystub(c, 2, this=True))
    e.w32(t, vt)
    return [t]


S(0x4f28e0, 'GUESS pick_two_handles', 'thiscall', None, ret=None, gen=_g4f28e0, note='batch67504')
