"""specs_s1649.py - residue 13 batch 1649: CMsgForward::Init. The flag byte at +4 decides; the source object at +0x44
has slot 0x20 (returns an id); the manager (sys+0x9b) has slot 0x4c (returns the forwarded value)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    mgr = obj(c, 0x100, {0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    sysobj(c, db=mgr)
    src = obj(c, 0x80, {0x20: stub(c, seq, 0, ret=r.getrandbits(32))})
    me = obj(c, 0x100, {})
    flag = r.choice([0x02, 0x03, 0x06, 0x00, 0x01, 0xfd, r.getrandbits(8)])
    c.emu.w8(me + 4, flag)
    c.emu.w32(me + 0x44, src)
    return [me]


S(0x49ef10, 'CMsgForward::Init', 'thiscall', None, ret=None, gen=_gen,
  note='batch1649; flag bit 2 at +4; word cleared at +0x4c')
