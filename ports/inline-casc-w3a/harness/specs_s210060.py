"""specs_s210060.py - Sonnet-w3a: 0x5db420. Stream slot 0x40 (pointer arg: id, count, record head) and 0x50 (value arg) write tags chosen by call index; the allocator is hooked; manager slot 0x58 returns objects by id; list sink at this+0x84 slot 4 records the records."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g5db420(c):
    clear_hooks(c)
    e = c.emu
    count = c.rng.choice([0, 1, 2, 3, 4])
    idv = _r(c)
    tag40 = [idv, count] + [_r(c) for _ in range(6)]
    tag50 = [_r(c) for _ in range(10)]

    def s40(emu, k):
        v = tag40[min(k, 7)]
        emu.w32(emu.arg32(0), v)
        emu.calllog.append(('s40', k, v))

    def s50(emu, k):
        v = tag50[min(k, 9)]
        emu.wbytes(emu.arg32(0), v.to_bytes(4, 'little'))
        emu.calllog.append(('s50', k, v))
    st = obj(c, 0x40, {0x40: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=s40),
                       0x50: pystub(c, 1, ret=_r(c), this=True, side=s50)}, nslots=0x20)
    cap = [c.rng.choice([0, 1, 0x100, 0x201]) for _ in range(6)]
    objs = [obj(c, 0x40, {0x1e0: pystub(c, 1, ret=cap[i], this=True)}, nslots=0x90) for i in range(6)]
    mg = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda emu, k: objs[min(k, 5)], this=True)}, nslots=0x30)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x20), pop=0)
    sink = obj(c, 0x40, {4: pystub(c, 1, ret=_r(c), this=True, deref={0: 4})}, nslots=0x10)
    self_ = rnd(c, 0x90)
    e.w32(self_ + 0x84, sink)
    return [self_, st]


S(0x5db420, 'load_counted_records', 'thiscall', None, ret='al', gen=g5db420, note='batch210060')
