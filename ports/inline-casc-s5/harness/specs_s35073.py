"""specs_s35073.py - 0x4f3ee0 (thiscall(f) ret 4). f includes values whose low byte is 0; this: slots 0x2e0 (returns an object or 0), 0x2c4 (returns p); p: slots 0x2ec (1 arg), 0x2f0 (returns the head of a chain or 0), 0x2f4
(2 args); chain nodes have slot 0x20 returning the next node; the chain ends at this (3/5) or at 0; the head may be this itself; 0x45f070 hooked (thiscall, 1 arg)."""
from pilot import S
from recruits_util import obj, clear_hooks, hook_rec, pystub


def _g4f3ee0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45f070, 1, this=True)
    n = r.choice([0, 1, 2, 3])
    ends_at_me = r.random() < 0.6
    p_holder = {}
    me = obj(c, 0x20, {}, nslots=1)
    nodes = []
    nxt = me if ends_at_me else 0
    for _ in range(n):
        nd = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=nxt)}, nslots=0x10)
        nxt = nd
        nodes.append(nd)
    head = nxt
    if r.random() < 0.15:
        head = 0
    p = obj(c, 0x20, {0x2ec: pystub(c, 1, this=True), 0x2f0: pystub(c, 0, this=True, ret=head), 0x2f4: pystub(c, 2, this=True)}, nslots=0xbe)
    ev = 0 if r.random() < 0.25 else obj(c, 0x10, {}, nslots=1)
    vt = e.alloc(0x2f8, 4)
    e.w32(vt + 0x2e0, pystub(c, 0, this=True, ret=ev))
    e.w32(vt + 0x2c4, pystub(c, 0, this=True, ret=p))
    e.w32(me, vt)
    return [me, r.choice([0, 0, 1, 0x100, 0x101, r.getrandbits(32)])]


S(0x4f3ee0, 'GUESS attach or detach through parent link', 'thiscall', None, ret=None, gen=_g4f3ee0, note='batch35073')
