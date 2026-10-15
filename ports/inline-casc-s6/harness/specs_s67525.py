"""specs_s67525.py - cascade s6 batch 67525 (0x443670, thiscall(on) ret 4). The table object's +0xadc usually equals this; the flag byte +0x76 changes or not; this slots 0x310 (bool),
0x20 (record with +8 member), 0x334; 0x4db7e0 / 0x441e40 / 0x443b40 are hooks (the first returns an object or 0); the list at +0x7b (unaligned pointer) has a count word at +2 and
entries from +0x404."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g443670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    pool = [rnd(c, 0x20) for _ in range(2)]
    hook_rec(c, 0x4db7e0, 0, this=True, ret=lambda em, k: r.choice(pool + [0]))
    hook_rec(c, 0x441e40, 1, this=True)
    hook_rec(c, 0x443b40, 1, this=True)
    rec = rnd(c, 0x20)
    _w(c, rec + 8, rnd(c, 0x20))
    lst = e.alloc(0x440, 4)
    e.wbytes(lst, bytes(r.getrandbits(8) for _ in range(0x440)))
    _w(c, lst + 2, r.choice([0, 1, 2, 3, 5]), 2)
    t = obj(c, 0x90, {0x310: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100])), 0x20: pystub(c, 0, this=True, ret=lambda em, k: rec if r.random() < 0.9 else 0),
                      0x334: pystub(c, 0, this=True)})
    _w(c, t + 0x7b, lst if r.random() < 0.9 else 0)
    cur = r.choice([0, 1])
    e.wbytes(t + 0x76, bytes([cur]))
    _w(c, tab + 0xadc, t if r.random() < 0.9 else r.getrandbits(32))
    return [t, r.choice([0, 1, 1, 0x100, 0x101, 2])]


S(0x443670, 'GUESS toggle_highlight', 'thiscall', None, ret=None, gen=_g443670, note='batch67525')
