"""specs_s35013.py - 0x5fe880 (stdcall(out, id, node), returns eax). Chain of 0..3 nodes (0xd4 base <= id so that the original never loops on the assert hook, 0xd8 count 0..8, 0x9c next, 0xe8 table of
8 small offsets, 0x100 data block); id in 0x100..0x140 and hit in a node or past the chain end (assert hook called, its random EAX returned). Output buffer random, written at unaligned offsets."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g5fe880(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    id_ = r.randint(0x100, 0x140)
    nxt = 0
    for _ in range(r.choice([0, 1, 2, 3, 3])):
        nd = rnd(c, 0x110)
        e.w32(nd + 0xd4, r.randint(0, id_) if r.random() < 0.7 else id_ - r.randint(0, 3))
        e.w32(nd + 0xd8, r.randint(0, 8))
        e.w32(nd + 0x9c, nxt)
        tbl = rnd(c, 0x20)
        for i in range(8):
            e.w32(tbl + 4 * i, r.randint(0, 0x40))
        e.w32(nd + 0xe8, tbl)
        e.w32(nd + 0x100, rnd(c, 0x100))
        nxt = nd
    return [rnd(c, 0x20), id_, nxt]


S(0x5fe880, 'GUESS find record by id in chained table', 'stdcall', None, ret='eax', gen=_g5fe880, note='batch35013')
