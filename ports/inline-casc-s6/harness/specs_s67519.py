"""specs_s67519.py - cascade s6 batch 67519 (0x56cfd0, thiscall(key) ret 4, returns eax). this slot 0xd8 (bool), 0x84 -> object (slot 0x2c4 -> object, slot 0x2f0 -> value q);
q equals this+0x180, equals the table object of +0x184 (slot 0x58), or neither; keys 0x102 / 0x103 / others; flag byte +0x1b5; 0x563d20 / 0x563d40 (3 args) , 0x56d750, 0x56d840,
0x562d90 (returns a random value) are recording hooks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g56cfd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    primary = r.getrandbits(32)
    other = r.getrandbits(32)
    pick = r.choice(['primary', 'table', 'none', 'primary'])
    q = {'primary': primary, 'table': other, 'none': r.getrandbits(32) | 1}[pick]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=other)}, table_size=0x60)
    p = obj(c, 0x20, {0x2f0: pystub(c, 0, this=True, ret=q)})
    o = obj(c, 0x20, {0x2c4: pystub(c, 0, this=True, ret=p)})
    refuse = r.random() < 0.1
    for a in (0x563d20, 0x563d40):
        hook_rec(c, a, 3, this=True)
    hook_rec(c, 0x56d750, 0, this=True)
    hook_rec(c, 0x56d840, 0, this=True)
    hook_rec(c, 0x562d90, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)]))
    t = obj(c, 0x200, {0xd8: pystub(c, 0, this=True, ret=1 if refuse else r.choice([0, 0])), 0x84: pystub(c, 0, this=True, ret=o)})
    _w(c, t + 0x180, primary)
    _w(c, t + 0x184, r.getrandbits(32))
    _w(c, t + 0x1b5, r.choice([0, 1, 1]), 1)
    return [t, r.choice([0x102, 0x103, 0x102, 0x103, 0x101, 0x104, r.getrandbits(32)])]


S(0x56cfd0, 'GUESS handle_key', 'thiscall', None, ret='eax', gen=_g56cfd0, note='batch67519')
