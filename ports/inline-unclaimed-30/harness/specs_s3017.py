"""specs_s3017.py - unclaimed-30 batch 17 (docs/20-unclaimed-30.md, claim 1): 0x47aad0 (no name in the name map). Records (obj, id) at
this+8k, count at +0x50. Objects have a logged slot 0x20 that returns a name holder (+4 = a name string or 0). The reporter is
pfspec's (logged with its arguments; the exe's variadic call passes the same words as the port's)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, reporter


def _name_obj(c, with_name):
    e = c.emu
    holder = e.alloc(16)
    if with_name:
        s = e.alloc(16)
        e.wbytes(s, b'actor%d\x00' % c.rng.randint(0, 9))
        e.w32(holder + 4, s)
    return holder


def _obj_with_name(c, with_name):
    e = c.emu
    holder = _name_obj(c, with_name)
    o = e.alloc(0x40)
    e.w32(o, vtable(c, 'named', 0x20, impl={0x20: (lambda h: (lambda em, a: h))(holder)}))
    return o


def _pw(c):
    e = c.emu
    r = c.rng
    reporter(c, 0.0)
    count = r.randint(0, 3)
    self_ = rnd(c, 0x100)
    objs = [_obj_with_name(c, r.random() < 0.6) for _ in range(count)]
    ids = [r.getrandbits(16) | 1 for _ in range(count)]
    for k in range(count):
        e.w32(self_ + 8 * k, objs[k])
        e.w32(self_ + 8 * k + 4, ids[k])
    e.w32(self_ + 0x50, count)
    mode = r.random()
    if count and mode < 0.4:
        k = r.randrange(count)
        return [self_, ids[k], objs[k]]           # found, same object: removal
    if count and mode < 0.7:
        k = r.randrange(count)
        return [self_, ids[k], _obj_with_name(c, r.random() < 0.5)]   # found, other object: report 0x50
    return [self_, r.getrandbits(16) | 0x8000, _obj_with_name(c, r.random() < 0.5)]   # not found: report 0x56


S(0x47aad0, 'unnamed 0x47aad0', 'thiscall', None, gen=_pw, n=300)
