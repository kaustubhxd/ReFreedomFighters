"""specs_s246.py - ladder thread batch 246: ZFFHERO::OperateObject with the fake hand/item kit (ops_kit.py)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K
import ops_kit as O


def _oo(c):
    r = c.rng
    self_ = O.hero(c)
    O.g2(c, self_)
    x = O.item(c, r.choice([0, 1]))
    obj = O.item(c, r.choice([0, 1]), x=x)
    step = r.choice([0, 1, 2, 3, 0, 1, 4, 5, 0xffffffff])
    a = O.action(c, obj, step)
    if r.random() < 0.05:
        self_ = 0
    return [self_, a]


S(0x593af0, 'ZFFHERO::OperateObject', 'thiscall', None, ret=None, gen=_oo, note='batch246')
