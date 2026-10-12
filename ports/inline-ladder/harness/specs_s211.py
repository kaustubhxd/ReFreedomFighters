"""specs_s211.py - ladder thread batches 211 (five ZAction* constructors) and 212 (ZLNKWHANDS::CreateLnkAction)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, u32
import ladder_kit as K


def _o(c):
    return K.rnd(c, 0x40)


for addr, name, n in [(0x485d00, 'ZActionDropItem::ctor', 4), (0x485d70, 'ZActionPickupItem::ctor', 4),
                      (0x485db0, 'ZActionPushButton::ctor', 4), (0x485df0, 'ZActionPutItem::ctor', 5),
                      (0x485e90, 'ZActionSwapItems::ctor', 5)]:
    S(addr, name, 'thiscall', [_o] + [u32()] * n, ret='eax', note='batch211')


def _create(c):
    e, r = c.emu, c.rng
    hands = K.rnd(c, 0x400)
    if 0x4733d0 in e.hooks:      # batch 208's spec hooks this function; here it must run as itself
        e.unhook(0x4733d0)

    def new(e2, res):
        n = e2.arg32(0)
        p = 0 if r.random() < 0.08 else K.rnd(c, max(n, 4))
        e2.calllog.append(('new', n, p))
        e2.ret(eax=p)
    e.hook(0x41e290, new)
    k = r.random()
    i = r.randint(0, 0x10) if k < 0.85 else r.getrandbits(32)
    return [hands, i]


S(0x4733d0, 'ZLNKWHANDS::CreateLnkAction', 'thiscall', None, ret='eax', gen=_create,
  note='batch212; ids 1..0xf, two hands at +0x2e7 / +0x34f; constructors run as original code')
