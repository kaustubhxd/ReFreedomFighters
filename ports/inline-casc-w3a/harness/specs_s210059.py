"""specs_s210059.py - Sonnet-w3a: 0x53a910. Container (this+4, null sometimes) slot 0x4c fills a stack iterator, slot 0x64 yields elements in order then 0; slot 4 returns node+4 for a fresh node; key slot 0x1e0; list head at this+0xe (unaligned) with a chain through +0xc. Return value EAX is incidental (not compared)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g53a910(c):
    clear_hooks(c)
    e = c.emu
    key = None
    cap = c.rng.choice([0, 1, 0x100, 0x201])
    key = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=cap, this=True)}, nslots=0x90)
    ne = c.rng.choice([0, 0, 1, 2, 3])
    elems = []
    for i in range(ne):
        el = rnd(c, 0x20)
        _ub(c, el + 4, _r(c))
        elems.append(el)
    if elems and c.rng.random() < 0.5:
        _ub(c, c.rng.choice(elems) + 4, key)
    # engine node alias case: slot 4 returns eng+0x38+4 sometimes
    so = rnd(c, 0x200)
    e.w32(0x70039c, so)
    alias = c.rng.random() < 0.15
    node = (so + 0x38) if alias else rnd(c, 0x30)
    seq = elems + [0]
    cont = obj(c, 0x40, {0x4c: pystub(c, 1, ret=_r(c), pop=None, stackmark=(0,), this=True),
                         0x64: pystub(c, 1, ret=lambda emu, k: seq[min(k, len(seq) - 1)], stackmark=(0,), this=True),
                         4: pystub(c, 1, ret=node + 4, this=True)}, nslots=0x30)
    s = rnd(c, 0x40)
    _ub(c, s + 4, 0 if False else cont)
    if c.rng.random() < 0.5:
        _ub(c, s + 0xe, 0)
    else:
        n = c.rng.choice([1, 2, 3])
        chain = [rnd(c, 0x20) for _ in range(n)]
        for i, ch in enumerate(chain):
            _ub(c, ch + 0xc, chain[i + 1] if i + 1 < n else 0)
        _ub(c, s + 0xe, chain[0])
    return [s, key]


S(0x53a910, 'find_or_append_entry', 'thiscall', None, ret=None, gen=g53a910, note='batch210059')
