"""specs_s36007.py - cascade s4 batch 36007: 0x63f950 (release a slot in a pooled block list), 0x64f6a0 (forward a record to a sub-object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g63f950(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [rnd(c, 0x20) for _ in range(3)]
    p = rnd(c, 0x20)
    b = rnd(c, 0x20)
    if r.random() < 0.5:
        p, b = b, p
    # b: header byte count, ring links at +8/+0xc
    e.wbytes(b, bytes([r.choice([1, 1, 2, 3, 0])]))
    other = blocks[0]
    a = b if r.random() < 0.2 else blocks[1]
    d = b if r.random() < 0.2 else blocks[2]
    e.w32(b + 8, a)
    e.w32(b + 0xc, d)
    head = b if r.random() < 0.3 else other
    e.w32(other + 0xc, blocks[1] if r.random() < 0.5 else blocks[2])
    me = obj(c, 0x20, {0x2c: pystub(c, 1, this=True, ret=b), 0x34: pystub(c, 1, this=True)})
    e.w32(me + 8, head)
    return [me, p]


def _g64f6a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    h = obj(c, 0x20, {0xd8: pystub(c, 0, this=True, ret=r.getrandbits(32)), 0xdc: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.wbytes(so + 0x190f, h.to_bytes(4, 'little'))
    hook_rec(c, 0x648e50, 1, this=True)
    hook_rec(c, 0x64dde0, 1, this=True, deref={0: 4})
    q = rnd(c, 0x10)
    rr = 0 if r.random() < 0.5 else rnd(c, 0x10)
    me = obj(c, 0x20, {0xa4: pystub(c, 1, this=True, ret=rr), 0xa0: pystub(c, 1, this=True, ret=q)})
    return [me, r.getrandbits(32)]


S(0x63f950, 'GUESS release block slot, relink ring', 'thiscall', None, ret=None, gen=_g63f950, note='batch36007')
S(0x64f6a0, 'GUESS forward record to sub-object', 'thiscall', None, ret=None, gen=_g64f6a0, note='batch36007')
