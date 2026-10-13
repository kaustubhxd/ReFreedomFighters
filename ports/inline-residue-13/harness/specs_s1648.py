"""specs_s1648.py - residue 13 batch 1648: ZInputActions::CheckActionCheat(name, unused). The system object (0x70039c)
has the cheat-enable byte at +0x9b9; the actions object's slot 0x58 maps the name to an action id and slot 0x2c returns
the result (its eax is compared through al)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    flag = r.choice([0, 1, 0x100, 0xff, 0x1000000])
    sysobj(c, extra={0x9b9: flag})
    self_ = obj(c, 0x100, {
        0x58: stub(c, seq, 1, ret=r.getrandbits(32)),
        0x2c: stub(c, seq, 2, ret=r.getrandbits(32)),
    })
    return [self_, rnd(c, 0x20), r.getrandbits(32)]


S(0x4380d0, 'ZInputActions::CheckActionCheat', 'thiscall', None, ret='al', gen=_gen,
  note='batch1648; cheat byte at sys+0x9b9 (low byte only); callee results through al')
