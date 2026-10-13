"""specs_s13009.py - fresh-13 batch 9: 0x65e210 ZGeometryDecal::Add, thiscall, 7 args (ret 0x1c), returns eax. Object
0x36e0 random bytes; free head (+0x36d2) is 0xffff (10%) or a random index 0..127 whose element's first word is a random
next index; list count (+0xcc) 0..0x80 (0x80 runs the hook at 0x7003b0, a logged stub; the overflowing store lands in
the object); pos/dir/col are random 3/3/4-float heap arrays (raw bits, NaN patterns included)."""
from pilot import S
from fr13 import Log, logstub, rnd, clear_hooks, flush


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=4)
    c.emu.w32(0x7003b0, logstub(c, log, 0, 1, this=False))
    me = rnd(c, 0x36e0)
    idx = 0xffff if r.random() < 0.1 else r.randint(0, 127)
    c.emu.wbytes(me + 0x36d2, idx.to_bytes(2, 'little'))
    if idx != 0xffff:
        c.emu.wbytes(me + 0x2d0 + idx * 0x68, r.choice([0xffff, r.randint(0, 127)]).to_bytes(2, 'little'))
    c.emu.w32(me + 0xcc, r.choice([0, 1, 0x7f, 0x80, r.randint(0, 0x80)]))
    flush(c)
    return [me, rnd(c, 12), rnd(c, 12), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), rnd(c, 16)]


S(0x65e210, 'ZGeometryDecal::Add', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13009; pool free list; hook 0x7003b0 logged')
